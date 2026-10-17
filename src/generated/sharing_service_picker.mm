#include "generated/sharing_service_picker.h"
#include "internal.h"

@interface AKSharingServicePickerDelegate : NSObject <NSSharingServicePickerDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKSharingServicePickerDelegate

- (NSArray<NSSharingService*>*)sharingServicePicker:(NSSharingServicePicker*)sharingServicePicker sharingServicesForItems:(NSArray*)items proposedSharingServices:(NSArray<NSSharingService*>*)proposedServices
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SharingServicePicker, std::vector<cocoon::SharingService>(std::vector<cocoon::Object>, std::vector<cocoon::SharingService>)>::emit((__bridge void*)strongHost, "sharing_services_for_items_proposed_sharing_services", cocoon::internal::from_array<cocoon::Object>(items, [](id e) -> cocoon::Object
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
    auto __r = cocoon::Signal<cocoon::SharingServicePicker, cocoon::Object(cocoon::SharingService)>::emit((__bridge void*)strongHost, "delegate_for_sharing_service", cocoon::internal::wrap<cocoon::SharingService>(sharingService));
    return cocoon::internal::native_id(__r);
}

- (void)sharingServicePicker:(NSSharingServicePicker*)sharingServicePicker didChooseSharingService:(NSSharingService*)service
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SharingServicePicker, void(cocoon::SharingService)>::emit((__bridge void*)strongHost, "did_choose_sharing_service", cocoon::internal::wrap<cocoon::SharingService>(service));
}

- (NSArray<NSSharingCollaborationModeRestriction*>*)sharingServicePickerCollaborationModeRestrictions:(NSSharingServicePicker*)sharingServicePicker
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SharingServicePicker, std::vector<cocoon::SharingCollaborationModeRestriction>()>::emit((__bridge void*)strongHost, "collaboration_mode_restrictions");
    return cocoon::internal::to_array(__r, [](const cocoon::SharingCollaborationModeRestriction& e) -> id
                                      {
                                          return cocoon::internal::native<::NSSharingCollaborationModeRestriction>(e);
                                      });
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(sharingServicePicker:sharingServicesForItems:proposedSharingServices:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingServicePicker, std::vector<cocoon::SharingService>(std::vector<cocoon::Object>, std::vector<cocoon::SharingService>)>::connected((__bridge void*)strongHost, "sharing_services_for_items_proposed_sharing_services");
    }
    if (selector == @selector(sharingServicePicker:delegateForSharingService:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingServicePicker, cocoon::Object(cocoon::SharingService)>::connected((__bridge void*)strongHost, "delegate_for_sharing_service");
    }
    if (selector == @selector(sharingServicePicker:didChooseSharingService:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingServicePicker, void(cocoon::SharingService)>::connected((__bridge void*)strongHost, "did_choose_sharing_service");
    }
    if (selector == @selector(sharingServicePickerCollaborationModeRestrictions:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingServicePicker, std::vector<cocoon::SharingCollaborationModeRestriction>()>::connected((__bridge void*)strongHost, "collaboration_mode_restrictions");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    SharingServicePicker::SharingServicePicker(const std::vector<Object>& items) : SharingServicePicker(Adopt{cocoon::internal::retain([[::NSSharingServicePicker alloc] initWithItems:cocoon::internal::to_array(items, [](const Object& e) -> id
                                                                                                                                                                                                                  {
                                                                                                                                                                                                                      return cocoon::internal::native_id(e);
                                                                                                                                                                                                                  })])})
    {
        SharingServicePicker::install_delegate_delegate_(handle());
    }

    SharingServicePicker::SharingServicePicker() : Object(nullptr)
    {
    }

    SharingServicePicker::SharingServicePicker(std::nullptr_t) : Object(nullptr)
    {
    }

    SharingServicePicker::SharingServicePicker(Adopt adopt) : Object(adopt)
    {
    }

    void SharingServicePicker::close() const
    {
        [cocoon::internal::ns<::NSSharingServicePicker>(this) close];
    }

    void SharingServicePicker::show_relative_to_rect(const Rect& rect, const View& view, RectEdge preferred_edge) const
    {
        [cocoon::internal::ns<::NSSharingServicePicker>(this) showRelativeToRect:cocoon::internal::to(rect) ofView:cocoon::internal::native<::NSView>(view) preferredEdge:static_cast<::NSRectEdge>(preferred_edge)];
    }

    MenuItem SharingServicePicker::standard_share_menu_item() const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSSharingServicePicker>(this) standardShareMenuItem]);
    }

    void SharingServicePicker::install_delegate_delegate_(void* native)
    {
        ::NSSharingServicePicker* host = (__bridge ::NSSharingServicePicker*)native;
        AKSharingServicePickerDelegate* delegate = [[AKSharingServicePickerDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSSharingServicePicker* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSSharingServicePicker* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
