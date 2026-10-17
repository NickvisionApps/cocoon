#include "generated/status_item.h"
#include "internal.h"

@interface AKStatusItemExpandedInterfaceDelegateDelegate : NSObject <NSStatusItemExpandedInterfaceDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKStatusItemExpandedInterfaceDelegateDelegate

- (void)statusItem:(NSStatusItem*)statusItem didBeginExpandedInterfaceSession:(NSStatusItemExpandedInterfaceSession*)expandedInterfaceSession
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::StatusItem, void(cocoon::StatusItemExpandedInterfaceSession)>::emit((__bridge void*)strongHost, "did_begin_expanded_interface_session", cocoon::internal::wrap<cocoon::StatusItemExpandedInterfaceSession>(expandedInterfaceSession));
}

- (void)statusItemDidEndExpandedInterfaceSession:(NSStatusItem*)statusItem animated:(BOOL)animated
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::StatusItem, void(bool)>::emit((__bridge void*)strongHost, "did_end_expanded_interface_session_animated", static_cast<bool>(animated));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(statusItem:didBeginExpandedInterfaceSession:))
    {
        return strongHost && cocoon::Signal<cocoon::StatusItem, void(cocoon::StatusItemExpandedInterfaceSession)>::connected((__bridge void*)strongHost, "did_begin_expanded_interface_session");
    }
    if (selector == @selector(statusItemDidEndExpandedInterfaceSession:animated:))
    {
        return strongHost && cocoon::Signal<cocoon::StatusItem, void(bool)>::connected((__bridge void*)strongHost, "did_end_expanded_interface_session_animated");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    StatusItem::StatusItem() : StatusItem(Adopt{cocoon::internal::retain([[::NSStatusItem alloc] init])})
    {
        StatusItem::install_expanded_interface_delegate_delegate_(handle());
    }

    StatusItem::StatusItem(std::nullptr_t) : Object(nullptr)
    {
    }

    StatusItem::StatusItem(Adopt adopt) : Object(adopt)
    {
    }

    std::string StatusItem::action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSStatusItem>(this) action]));
    }

    void StatusItem::set_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSStatusItem>(this) setAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    std::string StatusItem::autosave_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSStatusItem>(this) autosaveName]);
    }

    void StatusItem::set_autosave_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSStatusItem>(this) setAutosaveName:cocoon::internal::to(value)];
    }

    StatusItemBehavior StatusItem::behavior() const
    {
        return static_cast<StatusItemBehavior>([cocoon::internal::ns<::NSStatusItem>(this) behavior]);
    }

    void StatusItem::set_behavior(StatusItemBehavior value) const
    {
        [cocoon::internal::ns<::NSStatusItem>(this) setBehavior:static_cast<::NSStatusItemBehavior>(value)];
    }

    StatusBarButton StatusItem::button() const
    {
        return cocoon::internal::wrap<StatusBarButton>([cocoon::internal::ns<::NSStatusItem>(this) button]);
    }

#ifdef COCOON_MACOS_27
    StatusItemExpandedInterfaceSession StatusItem::expanded_interface_session() const
    {
        if (@available(macOS 27.0, *))
        {
            return cocoon::internal::wrap<StatusItemExpandedInterfaceSession>([cocoon::internal::ns<::NSStatusItem>(this) expandedInterfaceSession]);
        }
        return StatusItemExpandedInterfaceSession(nullptr);
    }

#endif
    double StatusItem::length() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSStatusItem>(this) length]);
    }

    void StatusItem::set_length(double value) const
    {
        [cocoon::internal::ns<::NSStatusItem>(this) setLength:static_cast<::CGFloat>(value)];
    }

    Menu StatusItem::menu() const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSStatusItem>(this) menu]);
    }

    void StatusItem::set_menu(const Menu& value) const
    {
        [cocoon::internal::ns<::NSStatusItem>(this) setMenu:cocoon::internal::native<::NSMenu>(value)];
    }

    StatusBar StatusItem::status_bar() const
    {
        return cocoon::internal::wrap<StatusBar>([cocoon::internal::ns<::NSStatusItem>(this) statusBar]);
    }

    Object StatusItem::target() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSStatusItem>(this) target]);
    }

    void StatusItem::set_target(const Object& value) const
    {
        [cocoon::internal::ns<::NSStatusItem>(this) setTarget:cocoon::internal::native_id(value)];
    }

    View StatusItem::view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSStatusItem>(this) view]);
    }

    void StatusItem::set_view(const View& value) const
    {
        [cocoon::internal::ns<::NSStatusItem>(this) setView:cocoon::internal::native<::NSView>(value)];
    }

    bool StatusItem::is_visible() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSStatusItem>(this) isVisible]);
    }

    void StatusItem::set_visible(bool value) const
    {
        [cocoon::internal::ns<::NSStatusItem>(this) setVisible:static_cast<::BOOL>(value)];
    }

    void StatusItem::install_expanded_interface_delegate_delegate_(void* native)
    {
        ::NSStatusItem* host = (__bridge ::NSStatusItem*)native;
        AKStatusItemExpandedInterfaceDelegateDelegate* delegate = [[AKStatusItemExpandedInterfaceDelegateDelegate alloc] init];
        delegate->host = host;
        host.expandedInterfaceDelegate = delegate;
        __weak::NSStatusItem* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSStatusItem* strongHost = weakHost;
            strongHost.expandedInterfaceDelegate = nil;
            strongHost.expandedInterfaceDelegate = delegate;
        });
    }
}
