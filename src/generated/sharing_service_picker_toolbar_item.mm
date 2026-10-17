#include "generated/sharing_service_picker_toolbar_item.h"
#include "internal.h"

@interface AKSharingServicePickerToolbarItemDelegate : NSObject <NSSharingServicePickerToolbarItemDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKSharingServicePickerToolbarItemDelegate

- (NSArray<NSSharingService*>*)sharingServicePicker:(NSSharingServicePicker*)sharingServicePicker sharingServicesForItems:(NSArray*)items proposedSharingServices:(NSArray<NSSharingService*>*)proposedServices
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SharingServicePickerToolbarItem, std::vector<cocoon::SharingService>(std::vector<cocoon::Object>, std::vector<cocoon::SharingService>)>::emit((__bridge void*)strongHost, "sharing_services_for_items_proposed_sharing_services", cocoon::internal::from_array<cocoon::Object>(items, [](id e) -> cocoon::Object
                                                                                                                                                                                                                                                                                                                     {
                                                                                                                                                                                                                                                                                                                         return cocoon::internal::wrap<cocoon::Object>(e);
                                                                                                                                                                                                                                                                                                                     }),
                                                                                                                                                                                    cocoon::internal::from_array<cocoon::SharingService>(proposedServices, [](id e) -> cocoon::SharingService
                                                                                                                                                                                                                                         {
                                                                                                                                                                                                                                             return cocoon::internal::wrap<cocoon::SharingService>((::NSSharingService*)e);
                                                                                                                                                                                                                                         }));
    return cocoon::internal::to_array(__r, [](const cocoon::SharingService& e) -> id
                                      {
                                          return cocoon::internal::native<::NSSharingService>(e);
                                      });
}

- (id<NSSharingServiceDelegate>)sharingServicePicker:(NSSharingServicePicker*)sharingServicePicker delegateForSharingService:(NSSharingService*)sharingService
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SharingServicePickerToolbarItem, cocoon::Object(cocoon::SharingService)>::emit((__bridge void*)strongHost, "delegate_for_sharing_service", cocoon::internal::wrap<cocoon::SharingService>(sharingService));
    return cocoon::internal::native_id(__r);
}

- (void)sharingServicePicker:(NSSharingServicePicker*)sharingServicePicker didChooseSharingService:(NSSharingService*)service
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SharingServicePickerToolbarItem, void(cocoon::SharingService)>::emit((__bridge void*)strongHost, "did_choose_sharing_service", cocoon::internal::wrap<cocoon::SharingService>(service));
}

- (NSArray<NSSharingCollaborationModeRestriction*>*)sharingServicePickerCollaborationModeRestrictions:(NSSharingServicePicker*)sharingServicePicker
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SharingServicePickerToolbarItem, std::vector<cocoon::SharingCollaborationModeRestriction>()>::emit((__bridge void*)strongHost, "collaboration_mode_restrictions");
    return cocoon::internal::to_array(__r, [](const cocoon::SharingCollaborationModeRestriction& e) -> id
                                      {
                                          return cocoon::internal::native<::NSSharingCollaborationModeRestriction>(e);
                                      });
}

- (NSArray*)itemsForSharingServicePickerToolbarItem:(NSSharingServicePickerToolbarItem*)pickerToolbarItem
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SharingServicePickerToolbarItem, std::vector<cocoon::Object>()>::emit((__bridge void*)strongHost, "items_for_sharing_service_picker_toolbar_item");
    return cocoon::internal::to_array(__r, [](const cocoon::Object& e) -> id
                                      {
                                          return cocoon::internal::native_id(e);
                                      });
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(sharingServicePicker:sharingServicesForItems:proposedSharingServices:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingServicePickerToolbarItem, std::vector<cocoon::SharingService>(std::vector<cocoon::Object>, std::vector<cocoon::SharingService>)>::connected((__bridge void*)strongHost, "sharing_services_for_items_proposed_sharing_services");
    }
    if (selector == @selector(sharingServicePicker:delegateForSharingService:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingServicePickerToolbarItem, cocoon::Object(cocoon::SharingService)>::connected((__bridge void*)strongHost, "delegate_for_sharing_service");
    }
    if (selector == @selector(sharingServicePicker:didChooseSharingService:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingServicePickerToolbarItem, void(cocoon::SharingService)>::connected((__bridge void*)strongHost, "did_choose_sharing_service");
    }
    if (selector == @selector(sharingServicePickerCollaborationModeRestrictions:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingServicePickerToolbarItem, std::vector<cocoon::SharingCollaborationModeRestriction>()>::connected((__bridge void*)strongHost, "collaboration_mode_restrictions");
    }
    if (selector == @selector(itemsForSharingServicePickerToolbarItem:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingServicePickerToolbarItem, std::vector<cocoon::Object>()>::connected((__bridge void*)strongHost, "items_for_sharing_service_picker_toolbar_item");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    SharingServicePickerToolbarItem::SharingServicePickerToolbarItem() : SharingServicePickerToolbarItem(Adopt{cocoon::internal::retain([[::NSSharingServicePickerToolbarItem alloc] init])})
    {
        ToolbarItem::bind_action_(handle());
        SharingServicePickerToolbarItem::install_delegate_delegate_(handle());
    }

    SharingServicePickerToolbarItem::SharingServicePickerToolbarItem(std::nullptr_t) : ToolbarItem(nullptr)
    {
    }

    SharingServicePickerToolbarItem::SharingServicePickerToolbarItem(Adopt adopt) : ToolbarItem(adopt)
    {
    }

    void SharingServicePickerToolbarItem::install_delegate_delegate_(void* native)
    {
        ::NSSharingServicePickerToolbarItem* host = (__bridge ::NSSharingServicePickerToolbarItem*)native;
        AKSharingServicePickerToolbarItemDelegate* delegate = [[AKSharingServicePickerToolbarItemDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSSharingServicePickerToolbarItem* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSSharingServicePickerToolbarItem* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
