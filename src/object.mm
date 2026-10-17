#include <objc/runtime.h>
#include "internal.h"
#include "object.h"
#include "weak_ref.h"

static char slotsKey;
static char actionKey;
static char bindingsKey;
static char delegatesKey;
static char refreshKey;

@interface AKSlot : NSObject
{
@public
    std::shared_ptr<void> slot;
}
@end

@implementation AKSlot
@end

@interface AKWeakBox : NSObject
{
@public
    __weak id object;
}
@end

@implementation AKWeakBox
@end

@interface AKBinding : NSObject
{
@public
    __weak id host;
    cocoon::internal::Handler handler;
}
@property(nonatomic, strong) id observerToken;
- (void)fire:(id)sender;
@end

@implementation AKBinding

- (void)fire:(id)sender
{
    id strongHost = host;
    if (strongHost && handler)
    {
        handler(strongHost, sender);
    }
}

- (BOOL)validateMenuItem:(NSMenuItem*)menuItem
{
    return ![menuItem.representedObject isEqual:@NO];
}

- (void)dealloc
{
    if (_observerToken)
    {
        [NSNotificationCenter.defaultCenter removeObserver:_observerToken];
    }
}

@end

namespace cocoon::internal
{
    void* retain(id object)
    {
        return (void*)CFBridgingRetain(object);
    }

    void bind_action(id target, id host, Handler handler)
    {
        AKBinding* binding = [[AKBinding alloc] init];
        binding->host = host;
        binding->handler = std::move(handler);
        objc_setAssociatedObject(target, &actionKey, binding, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        [target setTarget:binding];
        [target setAction:@selector(fire:)];
    }

    void observe(id host, id object, NSNotificationName name, Handler handler)
    {
        AKBinding* binding = [[AKBinding alloc] init];
        binding->host = host;
        binding->handler = std::move(handler);
        __weak AKBinding* weak = binding;
        binding.observerToken = [NSNotificationCenter.defaultCenter addObserverForName:name
                                                                                object:object
                                                                                 queue:nil
                                                                            usingBlock:^(NSNotification* note) {
                                                                                [weak fire:note];
                                                                            }];
        NSMutableArray* bindings = objc_getAssociatedObject(host, &bindingsKey);
        if (!bindings)
        {
            bindings = [NSMutableArray array];
            objc_setAssociatedObject(host, &bindingsKey, bindings, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        }
        [bindings addObject:binding];
    }

    void keep_delegate(id host, id delegate, void (^refresh)(void))
    {
        NSMutableArray* delegates = objc_getAssociatedObject(host, &delegatesKey);
        if (!delegates)
        {
            delegates = [NSMutableArray array];
            objc_setAssociatedObject(host, &delegatesKey, delegates, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        }
        [delegates addObject:delegate];
        NSMutableArray* refreshers = objc_getAssociatedObject(host, &refreshKey);
        if (!refreshers)
        {
            refreshers = [NSMutableArray array];
            objc_setAssociatedObject(host, &refreshKey, refreshers, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        }
        [refreshers addObject:[refresh copy]];
    }
}

namespace cocoon::detail
{
    void* retain_native(void* native)
    {
        return const_cast<void*>(CFRetain(native));
    }

    void release_native(void* native)
    {
        CFRelease(native);
    }

    void set_slot(void* native, const char* name, std::shared_ptr<void> slot)
    {
        id host = (__bridge id)native;
        if (!host)
        {
            return;
        }
        NSMutableDictionary<NSString*, AKSlot*>* slots = objc_getAssociatedObject(host, &slotsKey);
        if (!slots)
        {
            slots = [NSMutableDictionary dictionary];
            objc_setAssociatedObject(host, &slotsKey, slots, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        }
        NSString* key = [NSString stringWithUTF8String:name];
        if (!slot)
        {
            [slots removeObjectForKey:key];
            return;
        }
        AKSlot* box = [[AKSlot alloc] init];
        box->slot = std::move(slot);
        slots[key] = box;
        NSArray<void (^)(void)>* refreshers = objc_getAssociatedObject(host, &refreshKey);
        for (void (^refresh)(void) in refreshers)
        {
            refresh();
        }
    }

    std::shared_ptr<void> slot(void* native, const char* name)
    {
        id host = (__bridge id)native;
        if (!host)
        {
            return nullptr;
        }
        NSMutableDictionary<NSString*, AKSlot*>* slots = objc_getAssociatedObject(host, &slotsKey);
        AKSlot* box = slots[[NSString stringWithUTF8String:name]];
        return box ? box->slot : nullptr;
    }

    void* make_weak(void* native)
    {
        AKWeakBox* box = [[AKWeakBox alloc] init];
        box->object = (__bridge id)native;
        return (void*)CFBridgingRetain(box);
    }

    void* lock_weak(void* weak)
    {
        id object = ((__bridge AKWeakBox*)weak)->object;
        return object ? (void*)CFBridgingRetain(object) : nullptr;
    }
}
