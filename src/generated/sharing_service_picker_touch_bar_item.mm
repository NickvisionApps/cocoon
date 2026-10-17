#include "generated/sharing_service_picker_touch_bar_item.h"
#include "internal.h"

@interface AKSharingServicePickerTouchBarItemDelegate : NSObject <NSSharingServicePickerTouchBarItemDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKSharingServicePickerTouchBarItemDelegate

- (NSArray<NSSharingService*>*)sharingServicePicker:(NSSharingServicePicker*)sharingServicePicker sharingServicesForItems:(NSArray*)items proposedSharingServices:(NSArray<NSSharingService*>*)proposedServices
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SharingServicePickerTouchBarItem, std::vector<cocoon::SharingService>(std::vector<cocoon::Object>, std::vector<cocoon::SharingService>)>::emit((__bridge void*)strongHost, "sharing_services_for_items_proposed_sharing_services", cocoon::internal::from_array<cocoon::Object>(items, [](id e) -> cocoon::Object
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
    auto __r = cocoon::Signal<cocoon::SharingServicePickerTouchBarItem, cocoon::Object(cocoon::SharingService)>::emit((__bridge void*)strongHost, "delegate_for_sharing_service", cocoon::internal::wrap<cocoon::SharingService>(sharingService));
    return cocoon::internal::native_id(__r);
}

- (void)sharingServicePicker:(NSSharingServicePicker*)sharingServicePicker didChooseSharingService:(NSSharingService*)service
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SharingServicePickerTouchBarItem, void(cocoon::SharingService)>::emit((__bridge void*)strongHost, "did_choose_sharing_service", cocoon::internal::wrap<cocoon::SharingService>(service));
}

- (NSArray<NSSharingCollaborationModeRestriction*>*)sharingServicePickerCollaborationModeRestrictions:(NSSharingServicePicker*)sharingServicePicker
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SharingServicePickerTouchBarItem, std::vector<cocoon::SharingCollaborationModeRestriction>()>::emit((__bridge void*)strongHost, "collaboration_mode_restrictions");
    return cocoon::internal::to_array(__r, [](const cocoon::SharingCollaborationModeRestriction& e) -> id
                        {
                            return cocoon::internal::native<::NSSharingCollaborationModeRestriction>(e);
                        });
}

- (NSArray*)itemsForSharingServicePickerTouchBarItem:(NSSharingServicePickerTouchBarItem*)pickerTouchBarItem
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SharingServicePickerTouchBarItem, std::vector<cocoon::Object>()>::emit((__bridge void*)strongHost, "items_for_sharing_service_picker_touch_bar_item");
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
        return strongHost && cocoon::Signal<cocoon::SharingServicePickerTouchBarItem, std::vector<cocoon::SharingService>(std::vector<cocoon::Object>, std::vector<cocoon::SharingService>)>::connected((__bridge void*)strongHost, "sharing_services_for_items_proposed_sharing_services");
    }
    if (selector == @selector(sharingServicePicker:delegateForSharingService:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingServicePickerTouchBarItem, cocoon::Object(cocoon::SharingService)>::connected((__bridge void*)strongHost, "delegate_for_sharing_service");
    }
    if (selector == @selector(sharingServicePicker:didChooseSharingService:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingServicePickerTouchBarItem, void(cocoon::SharingService)>::connected((__bridge void*)strongHost, "did_choose_sharing_service");
    }
    if (selector == @selector(sharingServicePickerCollaborationModeRestrictions:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingServicePickerTouchBarItem, std::vector<cocoon::SharingCollaborationModeRestriction>()>::connected((__bridge void*)strongHost, "collaboration_mode_restrictions");
    }
    if (selector == @selector(itemsForSharingServicePickerTouchBarItem:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingServicePickerTouchBarItem, std::vector<cocoon::Object>()>::connected((__bridge void*)strongHost, "items_for_sharing_service_picker_touch_bar_item");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    SharingServicePickerTouchBarItem::SharingServicePickerTouchBarItem() : TouchBarItem(nullptr)
    {
    }

    SharingServicePickerTouchBarItem::SharingServicePickerTouchBarItem(std::nullptr_t) : TouchBarItem(nullptr)
    {
    }

    SharingServicePickerTouchBarItem::SharingServicePickerTouchBarItem(Adopt adopt) : TouchBarItem(adopt)
    {
    }

    Image SharingServicePickerTouchBarItem::button_image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSSharingServicePickerTouchBarItem>(this) buttonImage]);
    }

    void SharingServicePickerTouchBarItem::set_button_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSSharingServicePickerTouchBarItem>(this) setButtonImage:cocoon::internal::native<::NSImage>(value)];
    }

    std::string SharingServicePickerTouchBarItem::button_title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSharingServicePickerTouchBarItem>(this) buttonTitle]);
    }

    void SharingServicePickerTouchBarItem::set_button_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSSharingServicePickerTouchBarItem>(this) setButtonTitle:cocoon::internal::to(value)];
    }

    bool SharingServicePickerTouchBarItem::is_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSharingServicePickerTouchBarItem>(this) isEnabled]);
    }

    void SharingServicePickerTouchBarItem::set_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSSharingServicePickerTouchBarItem>(this) setEnabled:static_cast<::BOOL>(value)];
    }

    void SharingServicePickerTouchBarItem::install_delegate_delegate_(void* native)
    {
        ::NSSharingServicePickerTouchBarItem* host = (__bridge ::NSSharingServicePickerTouchBarItem*)native;
        AKSharingServicePickerTouchBarItemDelegate* delegate = [[AKSharingServicePickerTouchBarItemDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSSharingServicePickerTouchBarItem* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSSharingServicePickerTouchBarItem* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
