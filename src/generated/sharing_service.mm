#include "generated/sharing_service.h"
#include "internal.h"

@interface AKSharingServiceDelegate : NSObject <NSSharingServiceDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKSharingServiceDelegate

- (void)sharingService:(NSSharingService*)sharingService willShareItems:(NSArray*)items
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SharingService, void(std::vector<cocoon::Object>)>::emit((__bridge void*)strongHost, "will_share_items", cocoon::internal::from_array<cocoon::Object>(items, [](id e) -> cocoon::Object
                                                                                                                                                                                 {
                                                                                                                                                                                     return cocoon::internal::wrap<cocoon::Object>(e);
                                                                                                                                                                                 }));
}

- (void)sharingService:(NSSharingService*)sharingService didFailToShareItems:(NSArray*)items error:(NSError*)error
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SharingService, void(std::vector<cocoon::Object>, cocoon::Error)>::emit((__bridge void*)strongHost, "did_fail_to_share_items_error", cocoon::internal::from_array<cocoon::Object>(items, [](id e) -> cocoon::Object
                                                                                                                                                                                                             {
                                                                                                                                                                                                                 return cocoon::internal::wrap<cocoon::Object>(e);
                                                                                                                                                                                                             }),
                                                                                                   cocoon::internal::wrap<cocoon::Error>(error));
}

- (void)sharingService:(NSSharingService*)sharingService didShareItems:(NSArray*)items
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SharingService, void(std::vector<cocoon::Object>)>::emit((__bridge void*)strongHost, "did_share_items", cocoon::internal::from_array<cocoon::Object>(items, [](id e) -> cocoon::Object
                                                                                                                                                                                {
                                                                                                                                                                                    return cocoon::internal::wrap<cocoon::Object>(e);
                                                                                                                                                                                }));
}

- (NSRect)sharingService:(NSSharingService*)sharingService sourceFrameOnScreenForShareItem:(id)item
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SharingService, cocoon::Rect(cocoon::Object)>::emit((__bridge void*)strongHost, "source_frame_on_screen_for_share_item", cocoon::internal::wrap<cocoon::Object>(item));
    return cocoon::internal::to(__r);
}

- (NSImage*)sharingService:(NSSharingService*)sharingService transitionImageForShareItem:(id)item contentRect:(NSRect*)contentRect
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SharingService, cocoon::Image(cocoon::Object, cocoon::Rect*)>::emit((__bridge void*)strongHost, "transition_image_for_share_item_content_rect", cocoon::internal::wrap<cocoon::Object>(item), (cocoon::Rect*)(contentRect));
    return cocoon::internal::native<::NSImage>(__r);
}

- (NSWindow*)sharingService:(NSSharingService*)sharingService sourceWindowForShareItems:(NSArray*)items sharingContentScope:(NSSharingContentScope*)sharingContentScope
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SharingService, cocoon::Window(std::vector<cocoon::Object>, cocoon::SharingContentScope*)>::emit((__bridge void*)strongHost, "source_window_for_share_items_sharing_content_scope", cocoon::internal::from_array<cocoon::Object>(items, [](id e) -> cocoon::Object
                                                                                                                                                                                                                                                                       {
                                                                                                                                                                                                                                                                           return cocoon::internal::wrap<cocoon::Object>(e);
                                                                                                                                                                                                                                                                       }),
                                                                                                                                       (cocoon::SharingContentScope*)(sharingContentScope));
    return cocoon::internal::native<::NSWindow>(__r);
}

- (NSView*)anchoringViewForSharingService:(NSSharingService*)sharingService showRelativeToRect:(NSRect*)positioningRect preferredEdge:(NSRectEdge*)preferredEdge
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SharingService, cocoon::View(cocoon::Rect*, cocoon::RectEdge*)>::emit((__bridge void*)strongHost, "anchoring_view_for_sharing_service_show_relative_to_rect_preferred_edge", (cocoon::Rect*)(positioningRect), (cocoon::RectEdge*)(preferredEdge));
    return cocoon::internal::native<::NSView>(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(sharingService:willShareItems:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingService, void(std::vector<cocoon::Object>)>::connected((__bridge void*)strongHost, "will_share_items");
    }
    if (selector == @selector(sharingService:didFailToShareItems:error:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingService, void(std::vector<cocoon::Object>, cocoon::Error)>::connected((__bridge void*)strongHost, "did_fail_to_share_items_error");
    }
    if (selector == @selector(sharingService:didShareItems:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingService, void(std::vector<cocoon::Object>)>::connected((__bridge void*)strongHost, "did_share_items");
    }
    if (selector == @selector(sharingService:sourceFrameOnScreenForShareItem:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingService, cocoon::Rect(cocoon::Object)>::connected((__bridge void*)strongHost, "source_frame_on_screen_for_share_item");
    }
    if (selector == @selector(sharingService:transitionImageForShareItem:contentRect:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingService, cocoon::Image(cocoon::Object, cocoon::Rect*)>::connected((__bridge void*)strongHost, "transition_image_for_share_item_content_rect");
    }
    if (selector == @selector(sharingService:sourceWindowForShareItems:sharingContentScope:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingService, cocoon::Window(std::vector<cocoon::Object>, cocoon::SharingContentScope*)>::connected((__bridge void*)strongHost, "source_window_for_share_items_sharing_content_scope");
    }
    if (selector == @selector(anchoringViewForSharingService:showRelativeToRect:preferredEdge:))
    {
        return strongHost && cocoon::Signal<cocoon::SharingService, cocoon::View(cocoon::Rect*, cocoon::RectEdge*)>::connected((__bridge void*)strongHost, "anchoring_view_for_sharing_service_show_relative_to_rect_preferred_edge");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    SharingService::SharingService(const std::string& title, const Image& image, const Image& alternate_image, std::function<void()> block) : SharingService(Adopt{cocoon::internal::retain([[::NSSharingService alloc] initWithTitle:cocoon::internal::to(title) image:cocoon::internal::native<::NSImage>(image) alternateImage:cocoon::internal::native<::NSImage>(alternate_image) handler:(block ? (void (^)(void)) ^ void() { block(); } : (void (^)(void))nil)])})
    {
        SharingService::install_delegate_delegate_(handle());
    }

    SharingService::SharingService() : Object(nullptr)
    {
    }

    SharingService::SharingService(std::nullptr_t) : Object(nullptr)
    {
    }

    SharingService::SharingService(Adopt adopt) : Object(adopt)
    {
    }

    bool SharingService::can_perform_with_items(const std::vector<Object>& items) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSharingService>(this) canPerformWithItems:cocoon::internal::to_array(items, [](const Object& e) -> id
                                                                                                                                {
                                                                                                                                    return cocoon::internal::native_id(e);
                                                                                                                                })]);
    }

    void SharingService::perform_with_items(const std::vector<Object>& items) const
    {
        [cocoon::internal::ns<::NSSharingService>(this) performWithItems:cocoon::internal::to_array(items, [](const Object& e) -> id
                                                                                                    {
                                                                                                        return cocoon::internal::native_id(e);
                                                                                                    })];
    }

    SharingService SharingService::sharing_service_named(const std::string& service_name)
    {
        return cocoon::internal::wrap<SharingService>([::NSSharingService sharingServiceNamed:cocoon::internal::to(service_name)]);
    }

    std::string SharingService::account_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSharingService>(this) accountName]);
    }

    Image SharingService::alternate_image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSSharingService>(this) alternateImage]);
    }

    std::vector<URL> SharingService::attachment_file_urls() const
    {
        return cocoon::internal::from_array<URL>([cocoon::internal::ns<::NSSharingService>(this) attachmentFileURLs], [](id e) -> URL
                                                 {
                                                     return cocoon::internal::wrap<URL>((::NSURL*)e);
                                                 });
    }

    Image SharingService::image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSSharingService>(this) image]);
    }

    std::string SharingService::menu_item_title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSharingService>(this) menuItemTitle]);
    }

    void SharingService::set_menu_item_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSSharingService>(this) setMenuItemTitle:cocoon::internal::to(value)];
    }

    std::string SharingService::message_body() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSharingService>(this) messageBody]);
    }

    URL SharingService::permanent_link() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSSharingService>(this) permanentLink]);
    }

    std::vector<std::string> SharingService::recipients() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSSharingService>(this) recipients], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void SharingService::set_recipients(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSSharingService>(this) setRecipients:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                 {
                                                                                                     return cocoon::internal::to(e);
                                                                                                 })];
    }

    std::string SharingService::subject() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSharingService>(this) subject]);
    }

    void SharingService::set_subject(const std::string& value) const
    {
        [cocoon::internal::ns<::NSSharingService>(this) setSubject:cocoon::internal::to(value)];
    }

    std::string SharingService::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSharingService>(this) title]);
    }

    void SharingService::install_delegate_delegate_(void* native)
    {
        ::NSSharingService* host = (__bridge ::NSSharingService*)native;
        AKSharingServiceDelegate* delegate = [[AKSharingServiceDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSSharingService* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSSharingService* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
