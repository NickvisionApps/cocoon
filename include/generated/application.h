#pragma once

#include <functional>
#include "generated/enums.h"
#include "generated/responder.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Appearance;
    class Coder;
    class Date;
    class DockTile;
    class Document;
    class Error;
    class Event;
    class Exception;
    class Image;
    class Menu;
    class ModalSession;
    class Notification;
    class RunningApplication;
    class URL;
    class UserActivity;
    class Window;

    /**
     * @brief The running application (NSApplication): owns the event loop, the main menu and application level signals.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Responder.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * int main(int argc, char** argv)
     * {
     *     cocoon::Application app(argc, argv);
     *     app.set_name("Demo");
     *     cocoon::Window window("Demo", {640, 480});
     *     window.show();
     *     return app.exec();
     * }
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Application application{};
     * application.set_appearance(cocoon::Appearance());
     * auto appearance = application.appearance();
     * application.set_application_icon_image(cocoon::Image());
     * auto application_icon_image = application.application_icon_image();
     * application.set_automatic_customize_touch_bar_menu_item_enabled(true);
     * auto automatic_customize_touch_bar_menu_item_enabled = application.is_automatic_customize_touch_bar_menu_item_enabled();
     * application.abort_modal();
     * application.activate_ignoring_other_apps(true);
     * application.activation_policy();
     * application.open_urls().connect([](std::vector<cocoon::URL> a0) {});
     * application.open_files().connect([](std::vector<std::string> a0) {});
     * application.did_register_for_remote_notifications_with_device_token().connect([](std::vector<std::uint8_t> a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsapplication
     */
    class Application : public Responder
    {
    public:
        /// @brief Creates a new `NSApplication` instance and returns a handle to it.
        explicit Application(int argc, char** argv);
        /// @brief Creates a new `NSApplication` instance and returns a handle to it.
        explicit Application();
        /// @brief Creates a null handle that refers to no native object.
        Application(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Application(Adopt adopt);
        using Responder::try_to_perform;
        using Responder::valid_requestor_for_send_type;
        /**
     * @brief Calls `-[NSApplication abortModal]`.
     */
        void abort_modal() const;
        /**
     * @brief Calls `-[NSApplication activateContextHelpMode:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void activate_context_help_mode(const Object& sender) const;
        /**
     * @brief Calls `-[NSApplication activateIgnoringOtherApps:]`.
     * @details Makes the receiver the active app. - Parameter ignoreOtherApps: If 'NO', the app is activated only if no other app is currently active. If 'YES', the app activates regardless.
     * @param ignore_other_apps Argument converted to the Objective-C parameter of the same role.
     */
        void activate_ignoring_other_apps(bool ignore_other_apps) const;
        /**
     * @brief Calls `-[NSApplication activationPolicy]`.
     * @details \@return The activation policy of the application.
     * @return The converted Objective-C result.
     */
        ActivationPolicy activation_policy() const;
        /**
     * @brief Calls `-[NSApplication addWindowsItem:title:filename:]`.
     * @param win Argument converted to the Objective-C parameter of the same role.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @param is_filename Argument converted to the Objective-C parameter of the same role.
     */
        void add_windows_item(const Window& win, const std::string& string, bool is_filename) const;
        /**
     * @brief Calls `-[NSApplication arrangeInFront:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void arrange_in_front(const Object& sender) const;
        /**
     * @brief Calls `-[NSApplication beginModalSessionForWindow:]`.
     * @param window Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ModalSession begin_modal_session_for_window(const Window& window) const;
        /**
     * @brief Calls `-[NSApplication cancelUserAttentionRequest:]`.
     * @param request Argument converted to the Objective-C parameter of the same role.
     */
        void cancel_user_attention_request(std::int64_t request) const;
        /**
     * @brief Calls `-[NSApplication changeWindowsItem:title:filename:]`.
     * @param win Argument converted to the Objective-C parameter of the same role.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @param is_filename Argument converted to the Objective-C parameter of the same role.
     */
        void change_windows_item(const Window& win, const std::string& string, bool is_filename) const;
        /**
     * @brief Calls `-[NSApplication completeStateRestoration]`.
     */
        void complete_state_restoration() const;
        /**
     * @brief Calls `-[NSApplication deactivate]`.
     */
        void deactivate() const;
        /**
     * @brief Calls `+[NSApplication detachDrawingThread:toTarget:withObject:]`.
     * @param selector Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param argument Argument converted to the Objective-C parameter of the same role.
     */
        static void detach_drawing_thread(const std::string& selector, const Object& target, const Object& argument);
        /**
     * @brief Calls `-[NSApplication disableRelaunchOnLogin]`.
     * @details Disable or reenable relaunching this app on login, if the app was running at the time the user logged out. These methods increment and decrement a counter respectively; if the counter is 0 at the time the user logs out, then the app may be relaunched when the user logs back in. The counter is initially zero, so by default apps are relaunched. If your app should not be relaunched because it launches via some other mechanism (e.g. launchd), then the recommended usage is to call '-[NSApp disableRelaunchOnLogin]' once, and never pair it with an -enable call. If your app should not be relaunched because it triggers a restart (e.g. an installer), then the recommended usage is to call '-[NSApp disableRelaunchOnLogin]' immediately before you attempt to trigger a restart, and '-[NSApp enableRelaunchOnLogin]' immediately after. This is because the user may cancel restarting; if the user later restarts for another reason, then your app should be brought back. These methods are thread safe.
     */
        void disable_relaunch_on_login() const;
        /**
     * @brief Calls `-[NSApplication discardEventsMatchingMask:beforeEvent:]`.
     * @param mask Argument converted to the Objective-C parameter of the same role.
     * @param last_event Argument converted to the Objective-C parameter of the same role.
     */
        void discard_events_matching_mask(EventMask mask, const Event& last_event) const;
        /**
     * @brief Calls `-[NSApplication enableRelaunchOnLogin]`.
     */
        void enable_relaunch_on_login() const;
        /**
     * @brief Calls `-[NSApplication endModalSession:]`.
     * @param session Argument converted to the Objective-C parameter of the same role.
     */
        void end_modal_session(const ModalSession& session) const;
        /**
     * @brief Calls `-[NSApplication enumerateWindowsWithOptions:usingBlock:]`.
     * @details Execute a block for each of the app's windows. Set 'stop = YES' if desired, to halt the enumeration early.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_windows_with_options(WindowListOptions options, std::function<void(Window, bool&)> block) const;
        /**
     * @brief Calls `-[NSApplication extendStateRestoration]`.
     */
        void extend_state_restoration() const;
        /**
     * @brief Calls `-[NSApplication finishLaunching]`.
     */
        void finish_launching() const;
        /**
     * @brief Calls `-[NSApplication hide:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void hide(const Object& sender) const;
        /**
     * @brief Calls `-[NSApplication hideOtherApplications:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void hide_other_applications(const Object& sender) const;
        /**
     * @brief Calls `-[NSApplication miniaturizeAll:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void miniaturize_all(const Object& sender) const;
        /**
     * @brief Calls `-[NSApplication nextEventMatchingMask:untilDate:inMode:dequeue:]`.
     * @param mask Argument converted to the Objective-C parameter of the same role.
     * @param expiration Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     * @param deq_flag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Event next_event_matching_mask(EventMask mask, const Date& expiration, const std::string& mode, bool deq_flag) const;
        /**
     * @brief Calls `-[NSApplication orderFrontCharacterPalette:]`.
     * @details Opens the character palette.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void order_front_character_palette(const Object& sender) const;
        /**
     * @brief Calls `-[NSApplication orderFrontColorPanel:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void order_front_color_panel(const Object& sender) const;
        /**
     * @brief Calls `-[NSApplication orderFrontStandardAboutPanel:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void order_front_standard_about_panel(const Object& sender) const;
        /**
     * @brief Calls `-[NSApplication orderFrontStandardAboutPanelWithOptions:]`.
     * @param options_dictionary Argument converted to the Objective-C parameter of the same role.
     */
        void order_front_standard_about_panel_with_options(const std::map<std::string, Object>& options_dictionary) const;
        /**
     * @brief Calls `-[NSApplication postEvent:atStart:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @param at_start Argument converted to the Objective-C parameter of the same role.
     */
        void post_event(const Event& event, bool at_start) const;
        /**
     * @brief Calls `-[NSApplication preventWindowOrdering]`.
     */
        void prevent_window_ordering() const;
        /**
     * @brief Calls `-[NSApplication registerForRemoteNotificationTypes:]`.
     * @details The following are soft deprecated. Please use the '-registerForRemoteNotifications' above and '-requestAuthorizationWithOptions:' from 'UserNotifications.framework'.
     * @param types Argument converted to the Objective-C parameter of the same role.
     */
        void register_for_remote_notification_types(RemoteNotificationType types) const;
        /**
     * @brief Calls `-[NSApplication registerForRemoteNotifications]`.
     */
        void register_for_remote_notifications() const;
        /**
     * @brief Calls `-[NSApplication registerServicesMenuSendTypes:returnTypes:]`.
     * @param send_types Argument converted to the Objective-C parameter of the same role.
     * @param return_types Argument converted to the Objective-C parameter of the same role.
     */
        void register_services_menu_send_types(const std::vector<std::string>& send_types, const std::vector<std::string>& return_types) const;
        /**
     * @brief Calls `-[NSApplication registerUserInterfaceItemSearchHandler:]`.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     */
        void register_user_interface_item_search_handler(const Object& handler) const;
        /**
     * @brief Calls `-[NSApplication removeWindowsItem:]`.
     * @param win Argument converted to the Objective-C parameter of the same role.
     */
        void remove_windows_item(const Window& win) const;
        /**
     * @brief Calls `-[NSApplication replyToApplicationShouldTerminate:]`.
     * @details If an application delegate returns NSTerminateLater from -applicationShouldTerminate:, -replyToApplicationShouldTerminate: must be called with YES or NO once the application decides if it can terminate.
     * @param should_terminate Argument converted to the Objective-C parameter of the same role.
     */
        void reply_to_application_should_terminate(bool should_terminate) const;
        /**
     * @brief Calls `-[NSApplication replyToOpenOrPrint:]`.
     * @details If an application delegate encounters an error while handling '-application:openFiles:' or' -application:printFiles:', '-replyToOpenOrPrint:' should be called with \@c NSApplicationDelegateReplyFailure. If the user cancels the operation, \@c NSApplicationDelegateReplyCancel should be used, and if the operation succeeds, \@c NSApplicationDelegateReplySuccess should be used .
     * @param reply Argument converted to the Objective-C parameter of the same role.
     */
        void reply_to_open_or_print(ApplicationDelegateReply reply) const;
        /**
     * @brief Calls `-[NSApplication reportException:]`.
     * @param exception Argument converted to the Objective-C parameter of the same role.
     */
        void report_exception(const Exception& exception) const;
        /**
     * @brief Calls `-[NSApplication requestUserAttention:]`.
     * @details Inform the user that this application needs attention - call this method only if your application is not already active.
     * @param request_type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t request_user_attention(RequestUserAttentionType request_type) const;
        /**
     * @brief Calls `-[NSApplication restoreWindowWithIdentifier:state:completionHandler:]`.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @param state Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool restore_window_with_identifier(const std::string& identifier, const Coder& state, std::function<void(Window, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSApplication run]`.
     */
        void run() const;
        /**
     * @brief Calls `-[NSApplication runModalForWindow:]`.
     * @param window Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t run_modal_for_window(const Window& window) const;
        /**
     * @brief Calls `-[NSApplication runModalSession:]`.
     * @param session Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t run_modal_session(const ModalSession& session) const;
        /**
     * @brief Calls `-[NSApplication runPageLayout:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void run_page_layout(const Object& sender) const;
        /**
     * @brief Calls `-[NSApplication searchString:inUserInterfaceItemString:searchRange:foundRange:]`.
     * @param search_string Argument converted to the Objective-C parameter of the same role.
     * @param string_to_search Argument converted to the Objective-C parameter of the same role.
     * @param search_range Argument converted to the Objective-C parameter of the same role.
     * @param found_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool search_string(const std::string& search_string, const std::string& string_to_search, const Range& search_range, Range* found_range) const;
        /**
     * @brief Calls `-[NSApplication sendAction:to:from:]`.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool send_action(const std::string& action, const Object& target, const Object& sender) const;
        /**
     * @brief Calls `-[NSApplication sendEvent:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void send_event(const Event& event) const;
        /**
     * @brief Calls `-[NSApplication setActivationPolicy:]`.
     * @details Attempts to modify the application's activation policy. In OS X 10.9, any policy may be set; prior to 10.9, the activation policy may be changed to \@c NSApplicationActivationPolicyProhibited or \@c NSApplicationActivationPolicyRegular, but may not be changed to \@c NSApplicationActivationPolicyAccessory. This returns \@c YES if setting the activation policy is successful, and \@c NO if not.
     * @param activation_policy Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_activation_policy(ActivationPolicy activation_policy) const;
        /**
     * @brief Calls `-[NSApplication setWindowsNeedUpdate:]`.
     * @param need_update Argument converted to the Objective-C parameter of the same role.
     */
        void set_windows_need_update(bool need_update) const;
        /**
     * @brief Calls `-[NSApplication showHelp:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void show_help(const Object& sender) const;
        /**
     * @brief Calls `-[NSApplication stop:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void stop(const Object& sender) const;
        /**
     * @brief Calls `-[NSApplication stopModal]`.
     */
        void stop_modal() const;
        /**
     * @brief Calls `-[NSApplication stopModalWithCode:]`.
     * @param return_code Argument converted to the Objective-C parameter of the same role.
     */
        void stop_modal_with_code(std::int64_t return_code) const;
        /**
     * @brief Calls `-[NSApplication targetForAction:]`.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object target_for_action(const std::string& action) const;
        /**
     * @brief Calls `-[NSApplication targetForAction:to:from:]`.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object target_for_action(const std::string& action, const Object& target, const Object& sender) const;
        /**
     * @brief Calls `-[NSApplication terminate:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void terminate(const Object& sender) const;
        /**
     * @brief Calls `-[NSApplication toggleTouchBarCustomizationPalette:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void toggle_touch_bar_customization_palette(const Object& sender) const;
        /**
     * @brief Calls `-[NSApplication tryToPerform:with:]`.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool try_to_perform(const std::string& action, const Object& object) const;
        /**
     * @brief Calls `-[NSApplication unhide:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void unhide(const Object& sender) const;
        /**
     * @brief Calls `-[NSApplication unhideAllApplications:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void unhide_all_applications(const Object& sender) const;
        /**
     * @brief Calls `-[NSApplication unhideWithoutActivation]`.
     */
        void unhide_without_activation() const;
        /**
     * @brief Calls `-[NSApplication unregisterForRemoteNotifications]`.
     */
        void unregister_for_remote_notifications() const;
        /**
     * @brief Calls `-[NSApplication unregisterUserInterfaceItemSearchHandler:]`.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     */
        void unregister_user_interface_item_search_handler(const Object& handler) const;
        /**
     * @brief Calls `-[NSApplication updateWindows]`.
     */
        void update_windows() const;
        /**
     * @brief Calls `-[NSApplication updateWindowsItem:]`.
     * @param win Argument converted to the Objective-C parameter of the same role.
     */
        void update_windows_item(const Window& win) const;
        /**
     * @brief Calls `-[NSApplication validRequestorForSendType:returnType:]`.
     * @param send_type Argument converted to the Objective-C parameter of the same role.
     * @param return_type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object valid_requestor_for_send_type(const std::string& send_type, const std::string& return_type) const;
        /**
     * @brief Calls `-[NSApplication windowWithWindowNumber:]`.
     * @param window_num Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Window window_with_window_number(std::int64_t window_num) const;
        /**
     * @brief Calls `-[NSApplication yieldActivationToApplication:]`.
     * @details Explicitly allows another application to make itself active. Calling this method will not deactivate the current app, nor will it activate the other app. For cooperative or coordinated activation, the other app should request to be activated at some point in the future by calling 'activate' or equivalent.
     * @param application Argument converted to the Objective-C parameter of the same role.
     */
        void yield_activation_to_application(const RunningApplication& application) const;
        /**
     * @brief Calls `-[NSApplication yieldActivationToApplicationWithBundleIdentifier:]`.
     * @details Same as '-yieldActivationToApplication:', but the provided bundle identifier does not have to correspond to a currently running application. This method should be used to yield activation to apps that may not be running at the time of invoking it. If it is known that the target application is currently running, use '-yieldActivationToApplication:' instead.
     * @param bundle_identifier Argument converted to the Objective-C parameter of the same role.
     */
        void yield_activation_to_application_with_bundle_identifier(const std::string& bundle_identifier) const;
        /**
     * @brief Returns the `active` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        bool is_active() const;
        /**
     * @brief Returns the `appearance` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        Appearance appearance() const;
        /**
     * @brief Sets the `appearance` property of `NSApplication`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_appearance(const Appearance& value) const;
        /**
     * @brief Returns the `applicationIconImage` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        Image application_icon_image() const;
        /**
     * @brief Sets the `applicationIconImage` property of `NSApplication`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_application_icon_image(const Image& value) const;
        /**
     * @brief Returns the `applicationShouldSuppressHighDynamicRangeContent` property of `NSApplication`.
     * @details A boolean value indicating whether your application should suppress HDR content based on established policy. Built-in AppKit components such as NSImageView will automatically behave correctly with HDR content. You should use this value in conjunction with notifications ('NSApplicationShouldBeginSuppressingHighDynamicRangeContentNotification' and 'NSApplicationShouldEndSuppressingHighDynamicRangeContentNotification') to suppress HDR content in your application when signaled to do so.
     * @return The converted Objective-C result.
     */
        bool application_should_suppress_high_dynamic_range_content() const;
        /**
     * @brief Returns the `automaticCustomizeTouchBarMenuItemEnabled` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        bool is_automatic_customize_touch_bar_menu_item_enabled() const;
        /**
     * @brief Sets the `automaticCustomizeTouchBarMenuItemEnabled` property of `NSApplication`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_automatic_customize_touch_bar_menu_item_enabled(bool value) const;
        /**
     * @brief Returns the `currentEvent` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        Event current_event() const;
        /**
     * @brief Returns the `currentSystemPresentationOptions` property of `NSApplication`.
     * @details \@return The set of application presentation options that are currently in effect for the system. These are the presentation options that have been put into effect by the currently active application.
     * @return The converted Objective-C result.
     */
        ApplicationPresentationOptions current_system_presentation_options() const;
        /**
     * @brief Returns the `dockTile` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        DockTile dock_tile() const;
        /**
     * @brief Returns the `effectiveAppearance` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        Appearance effective_appearance() const;
        /**
     * @brief Returns the `enabledRemoteNotificationTypes` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        RemoteNotificationType enabled_remote_notification_types() const;
        /**
     * @brief Returns the `fullKeyboardAccessEnabled` property of `NSApplication`.
     * @details A Boolean value indicating whether keyboard navigation is enabled in System Settings > Keyboard. - Note: The value of this property is 'YES' if keyboard navigation is enabled or 'NO' if it’s not. You might use this value to implement your own key loop or to implement in-control tabbing behavior similar to 'NSTableView'. Because of the nature of the preference storage, you won’t be notified of changes to this property if you attempt to observe it through key-value observing; however, accessing this property is fairly inexpensive, so you can access it directly rather than caching it. - Note: This property’s value isn’t necessarily reflective of the separate accessibility setting named “Full Keyboard Access” in System Settings > Accessibility > Keyboard.
     * @return The converted Objective-C result.
     */
        bool is_full_keyboard_access_enabled() const;
        /**
     * @brief Returns the `helpMenu` property of `NSApplication`.
     * @details Set or get the Help menu for the app. If a non-nil menu is set as the Help menu, Spotlight for Help will be installed in it; otherwise AppKit will install Spotlight for Help into a menu of its choosing (and that menu is not returned from '-helpMenu'). If you wish to completely suppress Spotlight for Help, you can set a menu that does not appear in the menu bar. \@c NSApplication retains its Help menu and releases it when a different menu is set.
     * @return The converted Objective-C result.
     */
        Menu help_menu() const;
        /**
     * @brief Sets the `helpMenu` property of `NSApplication`.
     * @details Set or get the Help menu for the app. If a non-nil menu is set as the Help menu, Spotlight for Help will be installed in it; otherwise AppKit will install Spotlight for Help into a menu of its choosing (and that menu is not returned from '-helpMenu'). If you wish to completely suppress Spotlight for Help, you can set a menu that does not appear in the menu bar. \@c NSApplication retains its Help menu and releases it when a different menu is set.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_help_menu(const Menu& value) const;
        /**
     * @brief Returns the `hidden` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        bool is_hidden() const;
        /**
     * @brief Returns the `keyWindow` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        Window key_window() const;
        /**
     * @brief Returns the `mainMenu` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        Menu main_menu() const;
        /**
     * @brief Sets the `mainMenu` property of `NSApplication`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_main_menu(const Menu& value) const;
        /**
     * @brief Returns the `mainWindow` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        Window main_window() const;
        /**
     * @brief Returns the `modalWindow` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        Window modal_window() const;
        /**
     * @brief Returns the `occlusionState` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        ApplicationOcclusionState occlusion_state() const;
        /**
     * @brief Returns the `orderedDocuments` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        std::vector<Document> ordered_documents() const;
        /**
     * @brief Returns the `orderedWindows` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        std::vector<Window> ordered_windows() const;
        /**
     * @brief Returns the `presentationOptions` property of `NSApplication`.
     * @details Gets or sets the \@c presentationOptions that should be in effect for the system when this application is the active application. Only certain combinations of \@c NSApplicationPresentationOptions flags are allowed, as detailed in the AppKit Release Notes and the reference documentation for '-setPresentationOptions:'. When given an invalid combination of option flags, '-setPresentationOptions:' raises an exception.
     * @return The converted Objective-C result.
     */
        ApplicationPresentationOptions presentation_options() const;
        /**
     * @brief Sets the `presentationOptions` property of `NSApplication`.
     * @details Gets or sets the \@c presentationOptions that should be in effect for the system when this application is the active application. Only certain combinations of \@c NSApplicationPresentationOptions flags are allowed, as detailed in the AppKit Release Notes and the reference documentation for '-setPresentationOptions:'. When given an invalid combination of option flags, '-setPresentationOptions:' raises an exception.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_presentation_options(ApplicationPresentationOptions value) const;
        /**
     * @brief Returns the `protectedDataAvailable` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        bool is_protected_data_available() const;
        /**
     * @brief Returns the `registeredForRemoteNotifications` property of `NSApplication`.
     * @details \@return \@c YES if the application is currently registered for remote notifications, taking into account any systemwide settings; doesn't relate to connectivity.
     * @return The converted Objective-C result.
     */
        bool is_registered_for_remote_notifications() const;
        /**
     * @brief Returns the `running` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        bool is_running() const;
        /**
     * @brief Returns the `servicesMenu` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        Menu services_menu() const;
        /**
     * @brief Sets the `servicesMenu` property of `NSApplication`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_services_menu(const Menu& value) const;
        /**
     * @brief Returns the `servicesProvider` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        Object services_provider() const;
        /**
     * @brief Sets the `servicesProvider` property of `NSApplication`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_services_provider(const Object& value) const;
        /**
     * @brief Returns the `sharedApplication` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        static Application shared_application();
        /**
     * @brief Returns the `userInterfaceLayoutDirection` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        UserInterfaceLayoutDirection user_interface_layout_direction() const;
        /**
     * @brief Returns the `windows` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        std::vector<Window> windows() const;
        /**
     * @brief Returns the `windowsMenu` property of `NSApplication`.
     * @return The converted Objective-C result.
     */
        Menu windows_menu() const;
        /**
     * @brief Sets the `windowsMenu` property of `NSApplication`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_windows_menu(const Menu& value) const;
        /// @brief Convenience helper `instance` provided by cocoon.
        static Application instance();
        /// @brief Convenience helper `exec` provided by cocoon.
        int exec() const;
        /// @brief Convenience helper `quit` provided by cocoon.
        void quit() const;
        /// @brief Convenience helper `activate` provided by cocoon.
        void activate() const;
        /// @brief Convenience helper `hide` provided by cocoon.
        void hide() const;
        /// @brief Convenience helper `set_name` provided by cocoon.
        void set_name(const std::string& name) const;
        /// @brief Convenience helper `set_dock_badge` provided by cocoon.
        void set_dock_badge(const std::string& badge) const;
        /// @brief Convenience helper `set_menu_bar` provided by cocoon.
        void set_menu_bar(const Menu& menu) const;
        /// @brief Convenience helper `post_to_main_thread` provided by cocoon.
        static void post_to_main_thread(std::function<void()> function);
        /// @brief Convenience helper `single_shot` provided by cocoon.
        static void single_shot(double seconds, std::function<void()> function);
        /// @brief Signal for the delegate/data-source method behind `should_terminate`; connect a callback with `should_terminate().connect(...)`.
        Signal<Application, ApplicationTerminateReply()> should_terminate() const
        {
            return Signal<Application, ApplicationTerminateReply()>(handle(), "should_terminate");
        }
        /// @brief Signal for the delegate/data-source method behind `open_urls`; connect a callback with `open_urls().connect(...)`.
        Signal<Application, void(std::vector<URL>)> open_urls() const
        {
            return Signal<Application, void(std::vector<URL>)>(handle(), "open_urls");
        }
        /// @brief Signal for the delegate/data-source method behind `open_file`; connect a callback with `open_file().connect(...)`.
        Signal<Application, bool(std::string)> open_file() const
        {
            return Signal<Application, bool(std::string)>(handle(), "open_file");
        }
        /// @brief Signal for the delegate/data-source method behind `open_files`; connect a callback with `open_files().connect(...)`.
        Signal<Application, void(std::vector<std::string>)> open_files() const
        {
            return Signal<Application, void(std::vector<std::string>)>(handle(), "open_files");
        }
        /// @brief Signal for the delegate/data-source method behind `open_temp_file`; connect a callback with `open_temp_file().connect(...)`.
        Signal<Application, bool(std::string)> open_temp_file() const
        {
            return Signal<Application, bool(std::string)>(handle(), "open_temp_file");
        }
        /// @brief Signal for the delegate/data-source method behind `should_open_untitled_file`; connect a callback with `should_open_untitled_file().connect(...)`.
        Signal<Application, bool()> should_open_untitled_file() const
        {
            return Signal<Application, bool()>(handle(), "should_open_untitled_file");
        }
        /// @brief Signal for the delegate/data-source method behind `open_untitled_file`; connect a callback with `open_untitled_file().connect(...)`.
        Signal<Application, bool()> open_untitled_file() const
        {
            return Signal<Application, bool()>(handle(), "open_untitled_file");
        }
        /// @brief Signal for the delegate/data-source method behind `application_open_file_without_ui`; connect a callback with `application_open_file_without_ui().connect(...)`.
        Signal<Application, bool(std::string)> application_open_file_without_ui() const
        {
            return Signal<Application, bool(std::string)>(handle(), "application_open_file_without_ui");
        }
        /// @brief Signal for the delegate/data-source method behind `print_file`; connect a callback with `print_file().connect(...)`.
        Signal<Application, bool(std::string)> print_file() const
        {
            return Signal<Application, bool(std::string)>(handle(), "print_file");
        }
        /// @brief Signal for the delegate/data-source method behind `print_files_with_settings_show_print_panels`; connect a callback with `print_files_with_settings_show_print_panels().connect(...)`.
        Signal<Application, ApplicationPrintReply(std::vector<std::string>, std::map<std::string, Object>, bool)> print_files_with_settings_show_print_panels() const
        {
            return Signal<Application, ApplicationPrintReply(std::vector<std::string>, std::map<std::string, Object>, bool)>(handle(), "print_files_with_settings_show_print_panels");
        }
        /// @brief Signal for the delegate/data-source method behind `should_terminate_after_last_window_closed`; connect a callback with `should_terminate_after_last_window_closed().connect(...)`.
        Signal<Application, bool()> should_terminate_after_last_window_closed() const
        {
            return Signal<Application, bool()>(handle(), "should_terminate_after_last_window_closed");
        }
        /// @brief Signal for the delegate/data-source method behind `should_handle_reopen_has_visible_windows`; connect a callback with `should_handle_reopen_has_visible_windows().connect(...)`.
        Signal<Application, bool(bool)> should_handle_reopen_has_visible_windows() const
        {
            return Signal<Application, bool(bool)>(handle(), "should_handle_reopen_has_visible_windows");
        }
        /// @brief Signal for the delegate/data-source method behind `dock_menu`; connect a callback with `dock_menu().connect(...)`.
        Signal<Application, Menu()> dock_menu() const
        {
            return Signal<Application, Menu()>(handle(), "dock_menu");
        }
        /// @brief Signal for the delegate/data-source method behind `application_will_present_error`; connect a callback with `application_will_present_error().connect(...)`.
        Signal<Application, Error(Error)> application_will_present_error() const
        {
            return Signal<Application, Error(Error)>(handle(), "application_will_present_error");
        }
        /// @brief Signal for the delegate/data-source method behind `did_register_for_remote_notifications_with_device_token`; connect a callback with `did_register_for_remote_notifications_with_device_token().connect(...)`.
        Signal<Application, void(std::vector<std::uint8_t>)> did_register_for_remote_notifications_with_device_token() const
        {
            return Signal<Application, void(std::vector<std::uint8_t>)>(handle(), "did_register_for_remote_notifications_with_device_token");
        }
        /// @brief Signal for the delegate/data-source method behind `did_fail_to_register_for_remote_notifications_with_error`; connect a callback with `did_fail_to_register_for_remote_notifications_with_error().connect(...)`.
        Signal<Application, void(Error)> did_fail_to_register_for_remote_notifications_with_error() const
        {
            return Signal<Application, void(Error)>(handle(), "did_fail_to_register_for_remote_notifications_with_error");
        }
        /// @brief Signal for the delegate/data-source method behind `did_receive_remote_notification`; connect a callback with `did_receive_remote_notification().connect(...)`.
        Signal<Application, void(std::map<std::string, Object>)> did_receive_remote_notification() const
        {
            return Signal<Application, void(std::map<std::string, Object>)>(handle(), "did_receive_remote_notification");
        }
        /// @brief Signal for the delegate/data-source method behind `supports_secure_restorable_state`; connect a callback with `supports_secure_restorable_state().connect(...)`.
        Signal<Application, bool()> supports_secure_restorable_state() const
        {
            return Signal<Application, bool()>(handle(), "supports_secure_restorable_state");
        }
        /// @brief Signal for the delegate/data-source method behind `handler_for_intent`; connect a callback with `handler_for_intent().connect(...)`.
        Signal<Application, Object(Object)> handler_for_intent() const
        {
            return Signal<Application, Object(Object)>(handle(), "handler_for_intent");
        }
        /// @brief Signal for the delegate/data-source method behind `will_encode_restorable_state`; connect a callback with `will_encode_restorable_state().connect(...)`.
        Signal<Application, void(Coder)> will_encode_restorable_state() const
        {
            return Signal<Application, void(Coder)>(handle(), "will_encode_restorable_state");
        }
        /// @brief Signal for the delegate/data-source method behind `did_decode_restorable_state`; connect a callback with `did_decode_restorable_state().connect(...)`.
        Signal<Application, void(Coder)> did_decode_restorable_state() const
        {
            return Signal<Application, void(Coder)>(handle(), "did_decode_restorable_state");
        }
        /// @brief Signal for the delegate/data-source method behind `will_continue_user_activity_with_type`; connect a callback with `will_continue_user_activity_with_type().connect(...)`.
        Signal<Application, bool(std::string)> will_continue_user_activity_with_type() const
        {
            return Signal<Application, bool(std::string)>(handle(), "will_continue_user_activity_with_type");
        }
        /// @brief Signal for the delegate/data-source method behind `continue_user_activity_restoration_handler`; connect a callback with `continue_user_activity_restoration_handler().connect(...)`.
        Signal<Application, bool(UserActivity, std::function<void(std::vector<Object>)>)> continue_user_activity_restoration_handler() const
        {
            return Signal<Application, bool(UserActivity, std::function<void(std::vector<Object>)>)>(handle(), "continue_user_activity_restoration_handler");
        }
        /// @brief Signal for the delegate/data-source method behind `did_fail_to_continue_user_activity_with_type_error`; connect a callback with `did_fail_to_continue_user_activity_with_type_error().connect(...)`.
        Signal<Application, void(std::string, Error)> did_fail_to_continue_user_activity_with_type_error() const
        {
            return Signal<Application, void(std::string, Error)>(handle(), "did_fail_to_continue_user_activity_with_type_error");
        }
        /// @brief Signal for the delegate/data-source method behind `did_update_user_activity`; connect a callback with `did_update_user_activity().connect(...)`.
        Signal<Application, void(UserActivity)> did_update_user_activity() const
        {
            return Signal<Application, void(UserActivity)>(handle(), "did_update_user_activity");
        }
        /// @brief Signal for the delegate/data-source method behind `user_did_accept_cloud_kit_share_with_metadata`; connect a callback with `user_did_accept_cloud_kit_share_with_metadata().connect(...)`.
        Signal<Application, void(Object)> user_did_accept_cloud_kit_share_with_metadata() const
        {
            return Signal<Application, void(Object)>(handle(), "user_did_accept_cloud_kit_share_with_metadata");
        }
        /// @brief Signal for the delegate/data-source method behind `delegate_handles_key`; connect a callback with `delegate_handles_key().connect(...)`.
        Signal<Application, bool(std::string)> delegate_handles_key() const
        {
            return Signal<Application, bool(std::string)>(handle(), "delegate_handles_key");
        }
        /// @brief Signal for the delegate/data-source method behind `should_automatically_localize_key_equivalents`; connect a callback with `should_automatically_localize_key_equivalents().connect(...)`.
        Signal<Application, bool()> should_automatically_localize_key_equivalents() const
        {
            return Signal<Application, bool()>(handle(), "should_automatically_localize_key_equivalents");
        }
        /// @brief Signal for the delegate/data-source method behind `will_finish_launching`; connect a callback with `will_finish_launching().connect(...)`.
        Signal<Application, void(Notification)> will_finish_launching() const
        {
            return Signal<Application, void(Notification)>(handle(), "will_finish_launching");
        }
        /// @brief Signal for the delegate/data-source method behind `did_finish_launching`; connect a callback with `did_finish_launching().connect(...)`.
        Signal<Application, void(Notification)> did_finish_launching() const
        {
            return Signal<Application, void(Notification)>(handle(), "did_finish_launching");
        }
        /// @brief Signal for the delegate/data-source method behind `will_hide`; connect a callback with `will_hide().connect(...)`.
        Signal<Application, void(Notification)> will_hide() const
        {
            return Signal<Application, void(Notification)>(handle(), "will_hide");
        }
        /// @brief Signal for the delegate/data-source method behind `did_hide`; connect a callback with `did_hide().connect(...)`.
        Signal<Application, void(Notification)> did_hide() const
        {
            return Signal<Application, void(Notification)>(handle(), "did_hide");
        }
        /// @brief Signal for the delegate/data-source method behind `will_unhide`; connect a callback with `will_unhide().connect(...)`.
        Signal<Application, void(Notification)> will_unhide() const
        {
            return Signal<Application, void(Notification)>(handle(), "will_unhide");
        }
        /// @brief Signal for the delegate/data-source method behind `did_unhide`; connect a callback with `did_unhide().connect(...)`.
        Signal<Application, void(Notification)> did_unhide() const
        {
            return Signal<Application, void(Notification)>(handle(), "did_unhide");
        }
        /// @brief Signal for the delegate/data-source method behind `will_become_active`; connect a callback with `will_become_active().connect(...)`.
        Signal<Application, void(Notification)> will_become_active() const
        {
            return Signal<Application, void(Notification)>(handle(), "will_become_active");
        }
        /// @brief Signal for the delegate/data-source method behind `did_become_active`; connect a callback with `did_become_active().connect(...)`.
        Signal<Application, void(Notification)> did_become_active() const
        {
            return Signal<Application, void(Notification)>(handle(), "did_become_active");
        }
        /// @brief Signal for the delegate/data-source method behind `will_resign_active`; connect a callback with `will_resign_active().connect(...)`.
        Signal<Application, void(Notification)> will_resign_active() const
        {
            return Signal<Application, void(Notification)>(handle(), "will_resign_active");
        }
        /// @brief Signal for the delegate/data-source method behind `did_resign_active`; connect a callback with `did_resign_active().connect(...)`.
        Signal<Application, void(Notification)> did_resign_active() const
        {
            return Signal<Application, void(Notification)>(handle(), "did_resign_active");
        }
        /// @brief Signal for the delegate/data-source method behind `will_update`; connect a callback with `will_update().connect(...)`.
        Signal<Application, void(Notification)> will_update() const
        {
            return Signal<Application, void(Notification)>(handle(), "will_update");
        }
        /// @brief Signal for the delegate/data-source method behind `did_update`; connect a callback with `did_update().connect(...)`.
        Signal<Application, void(Notification)> did_update() const
        {
            return Signal<Application, void(Notification)>(handle(), "did_update");
        }
        /// @brief Signal for the delegate/data-source method behind `will_terminate`; connect a callback with `will_terminate().connect(...)`.
        Signal<Application, void(Notification)> will_terminate() const
        {
            return Signal<Application, void(Notification)>(handle(), "will_terminate");
        }
        /// @brief Signal for the delegate/data-source method behind `did_change_screen_parameters`; connect a callback with `did_change_screen_parameters().connect(...)`.
        Signal<Application, void(Notification)> did_change_screen_parameters() const
        {
            return Signal<Application, void(Notification)>(handle(), "did_change_screen_parameters");
        }
        /// @brief Signal for the delegate/data-source method behind `did_change_occlusion_state`; connect a callback with `did_change_occlusion_state().connect(...)`.
        Signal<Application, void(Notification)> did_change_occlusion_state() const
        {
            return Signal<Application, void(Notification)>(handle(), "did_change_occlusion_state");
        }
        /// @brief Signal for the delegate/data-source method behind `protected_data_will_become_unavailable`; connect a callback with `protected_data_will_become_unavailable().connect(...)`.
        Signal<Application, void(Notification)> protected_data_will_become_unavailable() const
        {
            return Signal<Application, void(Notification)>(handle(), "protected_data_will_become_unavailable");
        }
        /// @brief Signal for the delegate/data-source method behind `protected_data_did_become_available`; connect a callback with `protected_data_did_become_available().connect(...)`.
        Signal<Application, void(Notification)> protected_data_did_become_available() const
        {
            return Signal<Application, void(Notification)>(handle(), "protected_data_did_become_available");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
