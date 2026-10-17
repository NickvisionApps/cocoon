#include "generated/popover.h"
#include "internal.h"

@interface AKPopoverDelegate : NSObject <NSPopoverDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKPopoverDelegate

- (BOOL)popoverShouldClose:(NSPopover*)popover
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Popover, bool()>::emit((__bridge void*)strongHost, "should_close");
    return static_cast<::BOOL>(__r);
}

- (BOOL)popoverShouldDetach:(NSPopover*)popover
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Popover, bool()>::emit((__bridge void*)strongHost, "should_detach");
    return static_cast<::BOOL>(__r);
}

- (void)popoverDidDetach:(NSPopover*)popover
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Popover, void()>::emit((__bridge void*)strongHost, "did_detach");
}

- (NSWindow*)detachableWindowForPopover:(NSPopover*)popover
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Popover, cocoon::Window()>::emit((__bridge void*)strongHost, "detachable_window_for_popover");
    return cocoon::internal::native<::NSWindow>(__r);
}

- (void)popoverWillShow:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Popover, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_show", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)popoverDidShow:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Popover, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_show", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)popoverWillClose:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Popover, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_close", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)popoverDidClose:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Popover, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_close", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(popoverShouldClose:))
    {
        return strongHost && cocoon::Signal<cocoon::Popover, bool()>::connected((__bridge void*)strongHost, "should_close");
    }
    if (selector == @selector(popoverShouldDetach:))
    {
        return strongHost && cocoon::Signal<cocoon::Popover, bool()>::connected((__bridge void*)strongHost, "should_detach");
    }
    if (selector == @selector(popoverDidDetach:))
    {
        return strongHost && cocoon::Signal<cocoon::Popover, void()>::connected((__bridge void*)strongHost, "did_detach");
    }
    if (selector == @selector(detachableWindowForPopover:))
    {
        return strongHost && cocoon::Signal<cocoon::Popover, cocoon::Window()>::connected((__bridge void*)strongHost, "detachable_window_for_popover");
    }
    if (selector == @selector(popoverWillShow:))
    {
        return strongHost && cocoon::Signal<cocoon::Popover, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_show");
    }
    if (selector == @selector(popoverDidShow:))
    {
        return strongHost && cocoon::Signal<cocoon::Popover, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_show");
    }
    if (selector == @selector(popoverWillClose:))
    {
        return strongHost && cocoon::Signal<cocoon::Popover, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_close");
    }
    if (selector == @selector(popoverDidClose:))
    {
        return strongHost && cocoon::Signal<cocoon::Popover, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_close");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    Popover::Popover() : Popover(Adopt{cocoon::internal::retain([[::NSPopover alloc] init])})
    {
        Popover::install_delegate_delegate_(handle());
    }

    Popover::Popover(std::nullptr_t) : Responder(nullptr)
    {
    }

    Popover::Popover(Adopt adopt) : Responder(adopt)
    {
    }

    void Popover::close() const
    {
        [cocoon::internal::ns<::NSPopover>(this) close];
    }

    void Popover::perform_close(const Object& sender) const
    {
        [cocoon::internal::ns<::NSPopover>(this) performClose:cocoon::internal::native_id(sender)];
    }

    void Popover::show_relative_to_rect(const Rect& positioning_rect, const View& positioning_view, RectEdge preferred_edge) const
    {
        [cocoon::internal::ns<::NSPopover>(this) showRelativeToRect:cocoon::internal::to(positioning_rect) ofView:cocoon::internal::native<::NSView>(positioning_view) preferredEdge:static_cast<::NSRectEdge>(preferred_edge)];
    }

    void Popover::show_relative_to_toolbar_item(const ToolbarItem& toolbar_item) const
    {
        [cocoon::internal::ns<::NSPopover>(this) showRelativeToToolbarItem:cocoon::internal::native<::NSToolbarItem>(toolbar_item)];
    }

    bool Popover::animates() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPopover>(this) animates]);
    }

    void Popover::set_animates(bool value) const
    {
        [cocoon::internal::ns<::NSPopover>(this) setAnimates:static_cast<::BOOL>(value)];
    }

    Appearance Popover::appearance() const
    {
        return cocoon::internal::wrap<Appearance>([cocoon::internal::ns<::NSPopover>(this) appearance]);
    }

    void Popover::set_appearance(const Appearance& value) const
    {
        [cocoon::internal::ns<::NSPopover>(this) setAppearance:cocoon::internal::native<::NSAppearance>(value)];
    }

    PopoverBehavior Popover::behavior() const
    {
        return static_cast<PopoverBehavior>([cocoon::internal::ns<::NSPopover>(this) behavior]);
    }

    void Popover::set_behavior(PopoverBehavior value) const
    {
        [cocoon::internal::ns<::NSPopover>(this) setBehavior:static_cast<::NSPopoverBehavior>(value)];
    }

    Size Popover::content_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPopover>(this) contentSize]);
    }

    void Popover::set_content_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSPopover>(this) setContentSize:cocoon::internal::to(value)];
    }

    ViewController Popover::content_view_controller() const
    {
        return cocoon::internal::wrap<ViewController>([cocoon::internal::ns<::NSPopover>(this) contentViewController]);
    }

    void Popover::set_content_view_controller(const ViewController& value) const
    {
        [cocoon::internal::ns<::NSPopover>(this) setContentViewController:cocoon::internal::native<::NSViewController>(value)];
    }

    bool Popover::is_detached() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPopover>(this) isDetached]);
    }

    Appearance Popover::effective_appearance() const
    {
        return cocoon::internal::wrap<Appearance>([cocoon::internal::ns<::NSPopover>(this) effectiveAppearance]);
    }

    bool Popover::has_full_size_content() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPopover>(this) hasFullSizeContent]);
    }

    void Popover::set_has_full_size_content(bool value) const
    {
        [cocoon::internal::ns<::NSPopover>(this) setHasFullSizeContent:static_cast<::BOOL>(value)];
    }

    Rect Popover::positioning_rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPopover>(this) positioningRect]);
    }

    void Popover::set_positioning_rect(const Rect& value) const
    {
        [cocoon::internal::ns<::NSPopover>(this) setPositioningRect:cocoon::internal::to(value)];
    }

    bool Popover::is_shown() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPopover>(this) isShown]);
    }

    void Popover::install_delegate_delegate_(void* native)
    {
        ::NSPopover* host = (__bridge ::NSPopover*)native;
        AKPopoverDelegate* delegate = [[AKPopoverDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSPopover* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSPopover* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
