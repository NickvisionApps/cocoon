#include "generated/alert.h"
#include "internal.h"

@interface AKAlertDelegate : NSObject <NSAlertDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKAlertDelegate

- (BOOL)alertShowHelp:(NSAlert*)alert
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Alert, bool()>::emit((__bridge void*)strongHost, "show_help");
    return static_cast<::BOOL>(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(alertShowHelp:))
    {
        return strongHost && cocoon::Signal<cocoon::Alert, bool()>::connected((__bridge void*)strongHost, "show_help");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    Alert::Alert(const std::string& message, const std::string& informative_text, AlertStyle style) : Alert(Adopt{cocoon::internal::retain(cocoon::internal::make_alert(message, informative_text, style))})
    {
        Alert::install_delegate_delegate_(handle());
    }

    Alert::Alert(std::nullptr_t) : Object(nullptr)
    {
    }

    Alert::Alert(Adopt adopt) : Object(adopt)
    {
    }

    Button Alert::add_button_with_title(const std::string& title) const
    {
        return cocoon::internal::wrap<Button>([cocoon::internal::ns<::NSAlert>(this) addButtonWithTitle:cocoon::internal::to(title)]);
    }

    Alert Alert::alert_with_error(const Error& error)
    {
        return cocoon::internal::wrap<Alert>([::NSAlert alertWithError:cocoon::internal::native<::NSError>(error)]);
    }

    void Alert::begin_sheet_modal_for_window(const Window& sheet_window, std::function<void(std::int64_t)> handler) const
    {
        [cocoon::internal::ns<::NSAlert>(this) beginSheetModalForWindow:cocoon::internal::native<::NSWindow>(sheet_window) completionHandler:(handler ? (void (^)(::NSModalResponse)) ^ void(::NSModalResponse a1_0) { handler(static_cast<std::int64_t>(a1_0)); } : (void (^)(::NSModalResponse))nil)];
    }

    void Alert::layout() const
    {
        [cocoon::internal::ns<::NSAlert>(this) layout];
    }

    std::int64_t Alert::run_modal() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSAlert>(this) runModal]);
    }

    View Alert::accessory_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSAlert>(this) accessoryView]);
    }

    void Alert::set_accessory_view(const View& value) const
    {
        [cocoon::internal::ns<::NSAlert>(this) setAccessoryView:cocoon::internal::native<::NSView>(value)];
    }

    AlertStyle Alert::alert_style() const
    {
        return static_cast<AlertStyle>([cocoon::internal::ns<::NSAlert>(this) alertStyle]);
    }

    void Alert::set_alert_style(AlertStyle value) const
    {
        [cocoon::internal::ns<::NSAlert>(this) setAlertStyle:static_cast<::NSAlertStyle>(value)];
    }

    std::vector<Button> Alert::buttons() const
    {
        return cocoon::internal::from_array<Button>([cocoon::internal::ns<::NSAlert>(this) buttons], [](id e) -> Button
                                                    {
                                                        return cocoon::internal::wrap<Button>((::NSButton*)e);
                                                    });
    }

    std::string Alert::help_anchor() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAlert>(this) helpAnchor]);
    }

    void Alert::set_help_anchor(const std::string& value) const
    {
        [cocoon::internal::ns<::NSAlert>(this) setHelpAnchor:cocoon::internal::to(value)];
    }

    Image Alert::icon() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSAlert>(this) icon]);
    }

    void Alert::set_icon(const Image& value) const
    {
        [cocoon::internal::ns<::NSAlert>(this) setIcon:cocoon::internal::native<::NSImage>(value)];
    }

    std::string Alert::informative_text() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAlert>(this) informativeText]);
    }

    void Alert::set_informative_text(const std::string& value) const
    {
        [cocoon::internal::ns<::NSAlert>(this) setInformativeText:cocoon::internal::to(value)];
    }

    std::string Alert::message_text() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAlert>(this) messageText]);
    }

    void Alert::set_message_text(const std::string& value) const
    {
        [cocoon::internal::ns<::NSAlert>(this) setMessageText:cocoon::internal::to(value)];
    }

    bool Alert::shows_help() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSAlert>(this) showsHelp]);
    }

    void Alert::set_shows_help(bool value) const
    {
        [cocoon::internal::ns<::NSAlert>(this) setShowsHelp:static_cast<::BOOL>(value)];
    }

    bool Alert::shows_suppression_button() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSAlert>(this) showsSuppressionButton]);
    }

    void Alert::set_shows_suppression_button(bool value) const
    {
        [cocoon::internal::ns<::NSAlert>(this) setShowsSuppressionButton:static_cast<::BOOL>(value)];
    }

    Button Alert::suppression_button() const
    {
        return cocoon::internal::wrap<Button>([cocoon::internal::ns<::NSAlert>(this) suppressionButton]);
    }

    Window Alert::window() const
    {
        return cocoon::internal::wrap<Window>([cocoon::internal::ns<::NSAlert>(this) window]);
    }

    int Alert::exec() const
    {
        return static_cast<int>([cocoon::internal::ns<NSAlert>(this) runModal] - NSAlertFirstButtonReturn);
    }

    void Alert::begin_sheet(const Window& window, std::function<void(int)> on_finished) const
    {
        [cocoon::internal::ns<NSAlert>(this) beginSheetModalForWindow:cocoon::internal::native<NSWindow>(window)
                                                    completionHandler:^(NSModalResponse response) {
                                                        if (on_finished)
                                                        {
                                                            on_finished(static_cast<int>(response - NSAlertFirstButtonReturn));
                                                        }
                                                    }];
    }

    void Alert::install_delegate_delegate_(void* native)
    {
        ::NSAlert* host = (__bridge ::NSAlert*)native;
        AKAlertDelegate* delegate = [[AKAlertDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSAlert* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSAlert* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
