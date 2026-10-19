#pragma once

#include <functional>
#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Button;
    class Error;
    class Image;
    class View;
    class Window;

    /**
     * @brief A modal alert (NSAlert).
     * @details A modal dialog or sheet attached to a document window. The 'NSAlert' class is not designed for subclassing.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * cocoon::Alert alert("Delete file?", "This cannot be undone.", cocoon::AlertStyle::Warning);
     * alert.add_button_with_title("Delete");
     * alert.add_button_with_title("Cancel");
     * int pressed = alert.exec();
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Alert alert{"text", "text", cocoon::AlertStyle::Warning};
     * alert.set_accessory_view(cocoon::View());
     * auto accessory_view = alert.accessory_view();
     * alert.set_alert_style(cocoon::AlertStyle::Warning);
     * auto alert_style = alert.alert_style();
     * alert.set_help_anchor("text");
     * auto help_anchor = alert.help_anchor();
     * auto made_0 = cocoon::Alert::alert_with_error(cocoon::Error());
     * alert.add_button_with_title("text");
     * alert.layout();
     * alert.run_modal();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsalert
     */
    class Alert : public Object
    {
    public:
        /// @brief Creates a new `NSAlert` instance and returns a handle to it.
        explicit Alert(const std::string& message = "", const std::string& informative_text = "", AlertStyle style = AlertStyle::Informational);
        /// @brief Creates a null handle that refers to no native object.
        Alert(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Alert(Adopt adopt);
        /**
     * @brief Calls `-[NSAlert addButtonWithTitle:]`.
     * @details Adds a button with a given title to the alert. Buttons should be added from most-to-least prominent. The exact visual arrangement of the buttons is determined by 'NSAlert' internally. In general, they are arranged from trailing-to-leading edge when laid out horizontally, and top-to-bottom when laid out vertically, with some exceptions for buttons like “Cancel”. The first three buttons are identified by the order in which they are added (not the order in which they may appear visually) as 'NSAlertFirstButtonReturn', 'NSAlertSecondButtonReturn', 'NSAlertThirdButtonReturn' in the return-code parameter. Subsequent buttons are identified as 'NSAlertThirdButtonReturn' + n, where n is an integer. By default, the first button has a key equivalent of Return, any button with a title of “Cancel” has a key equivalent of Escape, and any button with the title “Don’t Save” has a key equivalent of Command-D (but only if it’s not the first button). You can also assign different key equivalents for the buttons using the 'keyEquivalent' method of the 'NSButton' class. In addition, you can use the 'tag' property of the 'NSButton' class to set the alert presentation’s return-code. The framework reserves the use of the button’s 'target' and 'action'. - Parameter title: Title of the button to add to the alert. - Returns: The button that was added to the alert.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Button add_button_with_title(const std::string& title) const;
        /**
     * @brief Calls `+[NSAlert alertWithError:]`.
     * @details Returns an alert initialized from information in an error object. - Parameter error: Error information to display. - Returns: An initialized alert. - Note: The 'NSAlert' class extracts the localized error description, recovery suggestion, and recovery options from the error parameter and uses them as the alert’s message text, informative text, and button titles, respectively.
     * @param error Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Alert alert_with_error(const Error& error);
        /**
     * @brief Calls `-[NSAlert beginSheetModalForWindow:completionHandler:]`.
     * @details Runs the alert modally as a sheet attached to the specified window. - Parameters: - sheetWindow: The window on which to display the sheet. - handler: The completion handler that gets called when the sheet’s modal session ends. This method uses the 'NSWindow' sheet methods to display the alert. If the alert has an alert style of 'NSCriticalAlertStyle', it is presented as a critical sheet, which means that it can display on top of other sheets that might already be attached to the window. Otherwise, it is presented--or queued for presentation--as a standard sheet. Note that '-orderOut:' no longer needs to be called in the completion handler. If the alert isn’t don’t dismiss the alert, it will be done for you after the completion handler finishes.
     * @param sheet_window Argument converted to the Objective-C parameter of the same role.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     */
        void begin_sheet_modal_for_window(const Window& sheet_window, std::function<void(std::int64_t)> handler) const;
        /**
     * @brief Calls `-[NSAlert layout]`.
     * @details Specifies that the alert must do immediate layout instead of lazily just before display. Used to indicate that the alert panel should do immediate layout, overriding the default behavior of laying out lazily just before showing panel. Only call this method if wanting to do custom layout after it returns. Call this method only after the alert’s other customization, including setting message and informative text, and adding buttons and an accessory view if needed. Layout changes can be made after this method returns, in particular to adjust the frame of an accessory view. Note that the standard layout of the alert may change in the future, so layout customization should be done with caution.
     */
        void layout() const;
        /**
     * @brief Calls `-[NSAlert runModal]`.
     * @details Runs the alert as an app-modal dialog and returns the constant that identifies the button clicked.
     * @return The converted Objective-C result.
     */
        std::int64_t run_modal() const;
        /**
     * @brief Returns the `accessoryView` property of `NSAlert`.
     * @details The accessory view displayed in the alert, placed between the informative text or suppression checkbox (if present) and the response buttons. Before changing the location of the accessory view, first call the '-layout' method.
     * @return The converted Objective-C result.
     */
        View accessory_view() const;
        /**
     * @brief Sets the `accessoryView` property of `NSAlert`.
     * @details The accessory view displayed in the alert, placed between the informative text or suppression checkbox (if present) and the response buttons. Before changing the location of the accessory view, first call the '-layout' method.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_accessory_view(const View& value) const;
        /**
     * @brief Returns the `alertStyle` property of `NSAlert`.
     * @details Indicates the alert’s severity level. See the 'NSAlertStyle' enumeration for the list of alert style constants.
     * @return The converted Objective-C result.
     */
        AlertStyle alert_style() const;
        /**
     * @brief Sets the `alertStyle` property of `NSAlert`.
     * @details Indicates the alert’s severity level. See the 'NSAlertStyle' enumeration for the list of alert style constants.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_alert_style(AlertStyle value) const;
        /**
     * @brief Returns the `buttons` property of `NSAlert`.
     * @details The array of response buttons for the alert. The buttons are in the order in which they were added, and do not necessarily reflect the order they are arranged visually. The array does not include the default “OK” button that is shown in an alert presented without any buttons added with '-addButtonWithTitle:'.
     * @return The converted Objective-C result.
     */
        std::vector<Button> buttons() const;
        /**
     * @brief Returns the `helpAnchor` property of `NSAlert`.
     * @details The alert’s HTML help anchor used when the user clicks the alert’s help button
     * @return The converted Objective-C result.
     */
        std::string help_anchor() const;
        /**
     * @brief Sets the `helpAnchor` property of `NSAlert`.
     * @details The alert’s HTML help anchor used when the user clicks the alert’s help button
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_help_anchor(const std::string& value) const;
        /**
     * @brief Returns the `icon` property of `NSAlert`.
     * @details The custom icon displayed in the alert. By default, the image used in an alert is the app icon. If you set this property’s value, your specified custom image is used in place of the app icon. If you’ve set a custom alert icon, you can clear it by setting this property’s value to 'nil', which restores use of the app icon for the alert. - Note: AppKit may omit the icon from the alert if it’s the app icon and the alert’s context is clear, such as being presented as a sheet on an app window.
     * @return The converted Objective-C result.
     */
        Image icon() const;
        /**
     * @brief Sets the `icon` property of `NSAlert`.
     * @details The custom icon displayed in the alert. By default, the image used in an alert is the app icon. If you set this property’s value, your specified custom image is used in place of the app icon. If you’ve set a custom alert icon, you can clear it by setting this property’s value to 'nil', which restores use of the app icon for the alert. - Note: AppKit may omit the icon from the alert if it’s the app icon and the alert’s context is clear, such as being presented as a sheet on an app window.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_icon(const Image& value) const;
        /**
     * @brief Returns the `informativeText` property of `NSAlert`.
     * @details The descriptive text that provides more details about the reason for the alert. - Note: The informative text string is displayed below the message text and is less prominent. Use this string to provide additional context about the reason for the alert or about the actions that the user might take.
     * @return The converted Objective-C result.
     */
        std::string informative_text() const;
        /**
     * @brief Sets the `informativeText` property of `NSAlert`.
     * @details The descriptive text that provides more details about the reason for the alert. - Note: The informative text string is displayed below the message text and is less prominent. Use this string to provide additional context about the reason for the alert or about the actions that the user might take.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_informative_text(const std::string& value) const;
        /**
     * @brief Returns the `messageText` property of `NSAlert`.
     * @details The text that is displayed prominently in the alert. - Note: Use this string to get the user’s attention and communicate the reason for displaying the alert.
     * @return The converted Objective-C result.
     */
        std::string message_text() const;
        /**
     * @brief Sets the `messageText` property of `NSAlert`.
     * @details The text that is displayed prominently in the alert. - Note: Use this string to get the user’s attention and communicate the reason for displaying the alert.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_message_text(const std::string& value) const;
        /**
     * @brief Returns the `showsHelp` property of `NSAlert`.
     * @details Specifies whether the alert has a help button. Set this property’s value to 'YES' to specify that the alert has a help button, or 'NO' to specify it does not. When a user clicks an alert’s help button, the alert delegate ('delegate') receives an 'alertShowHelp:' message. The delegate is responsible for displaying the help information related to this particular alert. Clicking an alert’s help button can alternately cause the '-openHelpAnchor:inBook:' message to be sent to the app’s help manager with a 'nil' book and the anchor specified by the 'helpAnchor' property, if any of the following conditions are true: - There is no alert delegate. - The alert delegate does not implement '-alertShowHelp:'. - The alert delegate implements '-alertShowHelp:' but returns 'NO'. When this is the case, an exception is raised if no help anchor is set.
     * @return The converted Objective-C result.
     */
        bool shows_help() const;
        /**
     * @brief Sets the `showsHelp` property of `NSAlert`.
     * @details Specifies whether the alert has a help button. Set this property’s value to 'YES' to specify that the alert has a help button, or 'NO' to specify it does not. When a user clicks an alert’s help button, the alert delegate ('delegate') receives an 'alertShowHelp:' message. The delegate is responsible for displaying the help information related to this particular alert. Clicking an alert’s help button can alternately cause the '-openHelpAnchor:inBook:' message to be sent to the app’s help manager with a 'nil' book and the anchor specified by the 'helpAnchor' property, if any of the following conditions are true: - There is no alert delegate. - The alert delegate does not implement '-alertShowHelp:'. - The alert delegate implements '-alertShowHelp:' but returns 'NO'. When this is the case, an exception is raised if no help anchor is set.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_help(bool value) const;
        /**
     * @brief Returns the `showsSuppressionButton` property of `NSAlert`.
     * @details Specifies whether the alert includes a suppression checkbox, which can be employed to allow a user to opt out of seeing the alert again. The default value of this property is 'NO', which specifies the absence of a suppression checkbox in the alert. Set the value to 'YES' to show a suppression checkbox in the alert. By default, a suppression checkbox has the title, “Do not show this message again.” In macOS 11.0 and later, if the alert displays multiple buttons that prompt the user to make a choice, the title is “Do not ask again.” To customize it, use the checkbox’s title property, as follows: myAlert.suppressionButton.title = \@"Do not show this warning again"; To create an alert that responds to the selection state of the suppression checkbox, check 'myAlert.suppressionButton.state'.
     * @return The converted Objective-C result.
     */
        bool shows_suppression_button() const;
        /**
     * @brief Sets the `showsSuppressionButton` property of `NSAlert`.
     * @details Specifies whether the alert includes a suppression checkbox, which can be employed to allow a user to opt out of seeing the alert again. The default value of this property is 'NO', which specifies the absence of a suppression checkbox in the alert. Set the value to 'YES' to show a suppression checkbox in the alert. By default, a suppression checkbox has the title, “Do not show this message again.” In macOS 11.0 and later, if the alert displays multiple buttons that prompt the user to make a choice, the title is “Do not ask again.” To customize it, use the checkbox’s title property, as follows: myAlert.suppressionButton.title = \@"Do not show this warning again"; To create an alert that responds to the selection state of the suppression checkbox, check 'myAlert.suppressionButton.state'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_suppression_button(bool value) const;
        /**
     * @brief Returns the `suppressionButton` property of `NSAlert`.
     * @details The alert’s suppression checkbox. The checkbox may be customized, including the title and the initial state. Additionally, use this method to get the state of the button after the alert is dismissed, which may be stored in user defaults and checked before showing the alert again. In order to show the suppression button in the alert panel, you must set 'showsSuppressionButton' to 'YES'.
     * @return The converted Objective-C result.
     */
        Button suppression_button() const;
        /**
     * @brief Returns the `window` property of `NSAlert`.
     * @details The app-modal panel or document-modal sheet that corresponds to the alert
     * @return The converted Objective-C result.
     */
        Window window() const;
        /// @brief Convenience helper `exec` provided by cocoon.
        int exec() const;
        /// @brief Convenience helper `begin_sheet` provided by cocoon.
        void begin_sheet(const Window& window, std::function<void(int)> on_finished = {}) const;
        /// @brief Signal for the delegate/data-source method behind `show_help`; connect a callback with `show_help().connect(...)`.
        Signal<Alert, bool()> show_help() const
        {
            return Signal<Alert, bool()>(handle(), "show_help");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
