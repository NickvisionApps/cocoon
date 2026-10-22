#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class PrintInfo;
    class ViewController;
    class Window;

    /**
     * @brief C++ handle for the Objective-C class `NSPrintPanel` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PrintPanel print_panel;
     * print_panel.set_help_anchor("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PrintPanel print_panel{};
     * print_panel.set_help_anchor("text");
     * auto help_anchor = print_panel.help_anchor();
     * print_panel.set_job_style_hint("text");
     * auto job_style_hint = print_panel.job_style_hint();
     * print_panel.set_options(cocoon::PrintPanelOptions::Copies);
     * auto options = print_panel.options();
     * print_panel.add_accessory_controller(cocoon::ViewController());
     * print_panel.default_button_title();
     * print_panel.remove_accessory_controller(cocoon::ViewController());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsprintpanel
     */
    class PrintPanel : public Object
    {
    public:
        /// @brief Creates a new `NSPrintPanel` instance and returns a handle to it.
        explicit PrintPanel();
        /// @brief Creates a null handle that refers to no native object.
        PrintPanel(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PrintPanel(Adopt adopt);
        /**
     * @brief Calls `-[NSPrintPanel addAccessoryController:]`.
     * @details Controllers for the accessory views that will be presented in the print panel by the methods below. When the print panel is presented to the user each controller is automatically sent a -setRepresentedObject: message with this object's NSPrintInfo. Because NSViewControllers are KVC and KVO compliant for "representedObject," you can use one as the file's owner of an accessory view's nib and bind controls to the file's owner using key paths that start with "representedObject." to take advantage of NSPrintInfo's KVC and KVO compliance. Each controller is also automatically sent a -title message. If that returns nil the application's short name is used in the popup menu that lets the user choose an accessory view.
     * @param accessory_controller Argument converted to the Objective-C parameter of the same role.
     */
        void add_accessory_controller(const ViewController& accessory_controller) const;
        /**
     * @brief Calls `-[NSPrintPanel beginSheetUsingPrintInfo:onWindow:completionHandler:]`.
     * @details Displays the print panel as a sheet on a window. This method returns immediately. When the print panel is dismissed, calls the completion handler with NSPrintPanelResult as the argument.
     * @param print_info Argument converted to the Objective-C parameter of the same role.
     * @param parent_window Argument converted to the Objective-C parameter of the same role.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     */
        void begin_sheet_using_print_info(const PrintInfo& print_info, const Window& parent_window, std::function<void(PrintPanelResult)> handler) const;
        /**
     * @brief Calls `-[NSPrintPanel beginSheetWithPrintInfo:modalForWindow:delegate:didEndSelector:contextInfo:]`.
     * @details Present a print panel to the user, document-modally. When the user has dismissed it, send the message selected by didEndSelector to the delegate, with the contextInfo as the last argument. The method selected by didEndSelector must have the same signature as: - (void)printPanelDidEnd:(NSPrintPanel )printPanel returnCode:(NSInteger)returnCode contextInfo:(void )contextInfo;
     * @param print_info Argument converted to the Objective-C parameter of the same role.
     * @param doc_window Argument converted to the Objective-C parameter of the same role.
     * @param delegate Argument converted to the Objective-C parameter of the same role.
     * @param did_end_selector Argument converted to the Objective-C parameter of the same role.
     * @param context_info Argument converted to the Objective-C parameter of the same role.
     */
        void begin_sheet_with_print_info(const PrintInfo& print_info, const Window& doc_window, const Object& delegate, const std::string& did_end_selector, void* context_info) const;
        /**
     * @brief Calls `-[NSPrintPanel defaultButtonTitle]`.
     * @return The converted Objective-C result.
     */
        std::string default_button_title() const;
        /**
     * @brief Calls `-[NSPrintPanel removeAccessoryController:]`.
     * @param accessory_controller Argument converted to the Objective-C parameter of the same role.
     */
        void remove_accessory_controller(const ViewController& accessory_controller) const;
        /**
     * @brief Calls `-[NSPrintPanel runModal]`.
     * @return The converted Objective-C result.
     */
        std::int64_t run_modal() const;
        /**
     * @brief Calls `-[NSPrintPanel runModalWithPrintInfo:]`.
     * @details Present a print panel to the user, application-modally, and return either NSOKButton or NSCancelButton. The default implementation of -runModal just invokes [self runModalWithPrintInfo:[[NSPrintOperation currentOperation] printInfo]].
     * @param print_info Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t run_modal_with_print_info(const PrintInfo& print_info) const;
        /**
     * @brief Calls `-[NSPrintPanel setDefaultButtonTitle:]`.
     * @details The title of the default button in the print panel. You can override the standard button title, "Print," when you're using an NSPrintPanel in such a way that printing isn't actually going to happen when the user presses that button.
     * @param default_button_title Argument converted to the Objective-C parameter of the same role.
     */
        void set_default_button_title(const std::string& default_button_title) const;
        /**
     * @brief Returns the `accessoryControllers` property of `NSPrintPanel`.
     * @return The converted Objective-C result.
     */
        std::vector<ViewController> accessory_controllers() const;
        /**
     * @brief Returns the `helpAnchor` property of `NSPrintPanel`.
     * @details The HTML help anchor for the print panel. You can override the standard anchor of the print panel's help button.
     * @return The converted Objective-C result.
     */
        std::string help_anchor() const;
        /**
     * @brief Sets the `helpAnchor` property of `NSPrintPanel`.
     * @details The HTML help anchor for the print panel. You can override the standard anchor of the print panel's help button.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_help_anchor(const std::string& value) const;
        /**
     * @brief Returns the `jobStyleHint` property of `NSPrintPanel`.
     * @return The converted Objective-C result.
     */
        std::string job_style_hint() const;
        /**
     * @brief Sets the `jobStyleHint` property of `NSPrintPanel`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_job_style_hint(const std::string& value) const;
        /**
     * @brief Returns the `options` property of `NSPrintPanel`.
     * @details The options described above. In Mac OS 10.5 an -options message sent to a freshly-created NSPrintPanel will return (NSPrintPanelShowsCopies | NSPrintPanelShowsPageRange) unless it was created by an NSPrintOperation, in which case it will also return NSPrintPanelShowsPreview. (See the release notes for backward binary compatibility information though.) To allow your application to take advantage of controls that may be added by default in future versions of Mac OS X, get the options from the print panel you've just created, turn on and off the flags you care about, and then set the options.
     * @return The converted Objective-C result.
     */
        PrintPanelOptions options() const;
        /**
     * @brief Sets the `options` property of `NSPrintPanel`.
     * @details The options described above. In Mac OS 10.5 an -options message sent to a freshly-created NSPrintPanel will return (NSPrintPanelShowsCopies | NSPrintPanelShowsPageRange) unless it was created by an NSPrintOperation, in which case it will also return NSPrintPanelShowsPreview. (See the release notes for backward binary compatibility information though.) To allow your application to take advantage of controls that may be added by default in future versions of Mac OS X, get the options from the print panel you've just created, turn on and off the flags you care about, and then set the options.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_options(PrintPanelOptions value) const;
        /**
     * @brief Returns the `printInfo` property of `NSPrintPanel`.
     * @details Returns the printInfo passed to 'beginSheetUsingPrintInfo:onWindow:completionHandler:'.
     * @return The converted Objective-C result.
     */
        PrintInfo print_info() const;
    };
}
