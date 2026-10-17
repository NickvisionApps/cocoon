#include "generated/page_controller.h"
#include "internal.h"

@interface AKPageControllerDelegate : NSObject <NSPageControllerDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKPageControllerDelegate

- (NSPageControllerObjectIdentifier)pageController:(NSPageController*)pageController identifierForObject:(id)object
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::PageController, std::string(cocoon::Object)>::emit((__bridge void*)strongHost, "identifier_for_object", cocoon::internal::wrap<cocoon::Object>(object));
    return cocoon::internal::to(__r);
}

- (NSViewController*)pageController:(NSPageController*)pageController viewControllerForIdentifier:(NSPageControllerObjectIdentifier)identifier
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::PageController, cocoon::ViewController(std::string)>::emit((__bridge void*)strongHost, "view_controller_for_identifier", cocoon::internal::from(identifier));
    return cocoon::internal::native<::NSViewController>(__r);
}

- (NSRect)pageController:(NSPageController*)pageController frameForObject:(id)object
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::PageController, cocoon::Rect(cocoon::Object)>::emit((__bridge void*)strongHost, "frame_for_object", cocoon::internal::wrap<cocoon::Object>(object));
    return cocoon::internal::to(__r);
}

- (void)pageController:(NSPageController*)pageController prepareViewController:(NSViewController*)viewController withObject:(id)object
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::PageController, void(cocoon::ViewController, cocoon::Object)>::emit((__bridge void*)strongHost, "prepare_view_controller_with_object", cocoon::internal::wrap<cocoon::ViewController>(viewController), cocoon::internal::wrap<cocoon::Object>(object));
}

- (void)pageController:(NSPageController*)pageController didTransitionToObject:(id)object
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::PageController, void(cocoon::Object)>::emit((__bridge void*)strongHost, "did_transition_to_object", cocoon::internal::wrap<cocoon::Object>(object));
}

- (void)pageControllerWillStartLiveTransition:(NSPageController*)pageController
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::PageController, void()>::emit((__bridge void*)strongHost, "will_start_live_transition");
}

- (void)pageControllerDidEndLiveTransition:(NSPageController*)pageController
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::PageController, void()>::emit((__bridge void*)strongHost, "did_end_live_transition");
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(pageController:identifierForObject:))
    {
        return strongHost && cocoon::Signal<cocoon::PageController, std::string(cocoon::Object)>::connected((__bridge void*)strongHost, "identifier_for_object");
    }
    if (selector == @selector(pageController:viewControllerForIdentifier:))
    {
        return strongHost && cocoon::Signal<cocoon::PageController, cocoon::ViewController(std::string)>::connected((__bridge void*)strongHost, "view_controller_for_identifier");
    }
    if (selector == @selector(pageController:frameForObject:))
    {
        return strongHost && cocoon::Signal<cocoon::PageController, cocoon::Rect(cocoon::Object)>::connected((__bridge void*)strongHost, "frame_for_object");
    }
    if (selector == @selector(pageController:prepareViewController:withObject:))
    {
        return strongHost && cocoon::Signal<cocoon::PageController, void(cocoon::ViewController, cocoon::Object)>::connected((__bridge void*)strongHost, "prepare_view_controller_with_object");
    }
    if (selector == @selector(pageController:didTransitionToObject:))
    {
        return strongHost && cocoon::Signal<cocoon::PageController, void(cocoon::Object)>::connected((__bridge void*)strongHost, "did_transition_to_object");
    }
    if (selector == @selector(pageControllerWillStartLiveTransition:))
    {
        return strongHost && cocoon::Signal<cocoon::PageController, void()>::connected((__bridge void*)strongHost, "will_start_live_transition");
    }
    if (selector == @selector(pageControllerDidEndLiveTransition:))
    {
        return strongHost && cocoon::Signal<cocoon::PageController, void()>::connected((__bridge void*)strongHost, "did_end_live_transition");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    PageController::PageController() : PageController(Adopt{cocoon::internal::retain([[::NSPageController alloc] init])})
    {
        PageController::install_delegate_delegate_(handle());
    }

    PageController::PageController(std::nullptr_t) : ViewController(nullptr)
    {
    }

    PageController::PageController(Adopt adopt) : ViewController(adopt)
    {
    }

    void PageController::complete_transition() const
    {
        [cocoon::internal::ns<::NSPageController>(this) completeTransition];
    }

    void PageController::navigate_back(const Object& sender) const
    {
        [cocoon::internal::ns<::NSPageController>(this) navigateBack:cocoon::internal::native_id(sender)];
    }

    void PageController::navigate_forward(const Object& sender) const
    {
        [cocoon::internal::ns<::NSPageController>(this) navigateForward:cocoon::internal::native_id(sender)];
    }

    void PageController::navigate_forward_to_object(const Object& object) const
    {
        [cocoon::internal::ns<::NSPageController>(this) navigateForwardToObject:cocoon::internal::native_id(object)];
    }

    void PageController::take_selected_index_from(const Object& sender) const
    {
        [cocoon::internal::ns<::NSPageController>(this) takeSelectedIndexFrom:cocoon::internal::native_id(sender)];
    }

    std::vector<Object> PageController::arranged_objects() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSPageController>(this) arrangedObjects], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    void PageController::set_arranged_objects(const std::vector<Object>& value) const
    {
        [cocoon::internal::ns<::NSPageController>(this) setArrangedObjects:cocoon::internal::to_array(value, [](const Object& e) -> id
                                                                          {
                                                                              return cocoon::internal::native_id(e);
                                                                          })];
    }

    std::int64_t PageController::selected_index() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPageController>(this) selectedIndex]);
    }

    void PageController::set_selected_index(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSPageController>(this) setSelectedIndex:static_cast<::NSInteger>(value)];
    }

    ViewController PageController::selected_view_controller() const
    {
        return cocoon::internal::wrap<ViewController>([cocoon::internal::ns<::NSPageController>(this) selectedViewController]);
    }

    PageControllerTransitionStyle PageController::transition_style() const
    {
        return static_cast<PageControllerTransitionStyle>([cocoon::internal::ns<::NSPageController>(this) transitionStyle]);
    }

    void PageController::set_transition_style(PageControllerTransitionStyle value) const
    {
        [cocoon::internal::ns<::NSPageController>(this) setTransitionStyle:static_cast<::NSPageControllerTransitionStyle>(value)];
    }

    void PageController::install_delegate_delegate_(void* native)
    {
        ::NSPageController* host = (__bridge ::NSPageController*)native;
        AKPageControllerDelegate* delegate = [[AKPageControllerDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSPageController* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSPageController* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
