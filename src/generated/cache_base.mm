#include "generated/cache_base.h"
#include "internal.h"

@interface AKCacheBaseDelegate : NSObject <NSCacheDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKCacheBaseDelegate

- (void)cache:(NSCache*)cache willEvictObject:(id)obj
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CacheBase, void(cocoon::Object)>::emit((__bridge void*)strongHost, "will_evict_object", cocoon::internal::wrap<cocoon::Object>(obj));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(cache:willEvictObject:))
    {
        return strongHost && cocoon::Signal<cocoon::CacheBase, void(cocoon::Object)>::connected((__bridge void*)strongHost, "will_evict_object");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    CacheBase::CacheBase() : CacheBase(Adopt{cocoon::internal::retain([[::NSCache alloc] init])})
    {
        CacheBase::install_delegate_delegate_(handle());
    }

    CacheBase::CacheBase(std::nullptr_t) : Object(nullptr)
    {
    }

    CacheBase::CacheBase(Adopt adopt) : Object(adopt)
    {
    }

    Object CacheBase::object_for_key(const Object& key) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSCache>(this) objectForKey:cocoon::internal::native_id(key)]);
    }

    void CacheBase::remove_all_objects() const
    {
        [cocoon::internal::ns<::NSCache>(this) removeAllObjects];
    }

    void CacheBase::remove_object_for_key(const Object& key) const
    {
        [cocoon::internal::ns<::NSCache>(this) removeObjectForKey:cocoon::internal::native_id(key)];
    }

    void CacheBase::set_object(const Object& obj, const Object& key) const
    {
        [cocoon::internal::ns<::NSCache>(this) setObject:cocoon::internal::native_id(obj) forKey:cocoon::internal::native_id(key)];
    }

    void CacheBase::set_object(const Object& obj, const Object& key, std::uint64_t g) const
    {
        [cocoon::internal::ns<::NSCache>(this) setObject:cocoon::internal::native_id(obj) forKey:cocoon::internal::native_id(key) cost:static_cast<::NSUInteger>(g)];
    }

    std::uint64_t CacheBase::count_limit() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSCache>(this) countLimit]);
    }

    void CacheBase::set_count_limit(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSCache>(this) setCountLimit:static_cast<::NSUInteger>(value)];
    }

    bool CacheBase::evicts_objects_with_discarded_content() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCache>(this) evictsObjectsWithDiscardedContent]);
    }

    void CacheBase::set_evicts_objects_with_discarded_content(bool value) const
    {
        [cocoon::internal::ns<::NSCache>(this) setEvictsObjectsWithDiscardedContent:static_cast<::BOOL>(value)];
    }

    std::string CacheBase::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCache>(this) name]);
    }

    void CacheBase::set_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSCache>(this) setName:cocoon::internal::to(value)];
    }

    std::uint64_t CacheBase::total_cost_limit() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSCache>(this) totalCostLimit]);
    }

    void CacheBase::set_total_cost_limit(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSCache>(this) setTotalCostLimit:static_cast<::NSUInteger>(value)];
    }

    void CacheBase::install_delegate_delegate_(void* native)
    {
        ::NSCache* host = (__bridge ::NSCache*)native;
        AKCacheBaseDelegate* delegate = [[AKCacheBaseDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSCache* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSCache* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
