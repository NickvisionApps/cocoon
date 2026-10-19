#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/panel.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class URL;
    class View;
    class Window;

    /**
     * @brief C++ handle for the Objective-C class `NSSavePanel` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Panel.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SavePanel save_panel;
     * save_panel.set_accessory_view(cocoon::View());
     * save_panel.panel_did_change_to_directory_url().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SavePanel save_panel{};
     * save_panel.set_accessory_view(cocoon::View());
     * auto accessory_view = save_panel.accessory_view();
     * save_panel.set_allows_other_file_types(true);
     * auto allows_other_file_types = save_panel.allows_other_file_types();
     * save_panel.set_can_create_directories(true);
     * auto can_create_directories = save_panel.can_create_directories();
     * auto made_0 = cocoon::SavePanel::save_panel();
     * save_panel.run_modal();
     * save_panel.validate_visible_columns();
     * save_panel.panel_did_change_to_directory_url().connect([](cocoon::URL a0) {});
     * save_panel.panel_will_expand().connect([](bool a0) {});
     * save_panel.panel_selection_did_change().connect([]() {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssavepanel
     */
    class SavePanel : public Panel
    {
    public:
        /// @brief Creates a new `NSSavePanel` instance and returns a handle to it.
        explicit SavePanel();
        /// @brief Creates a null handle that refers to no native object.
        SavePanel(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SavePanel(Adopt adopt);
        using Window::set_title;
        using Window::title;
        /**
     * @brief Calls `-[NSSavePanel beginSheetModalForWindow:completionHandler:]`.
     * @details 'NSSavePanel'/'NSOpenPanel': Presents the panel as a sheet modal to 'window' and returns immediately. Configure the panel before calling this method. The completion handler block will be called after the user has closed the panel, however, the open/save panel sheet may still be on screen. If you require the sheet to be offscreen (for example, to show an alert), first call '[savePanel orderOut:nil]' to close it. The 'result' will be 'NSModalResponseOK', 'NSModalResponseCancel', or if the panel fails to display, 'NSModalResponseAbort'.
     * @param window Argument converted to the Objective-C parameter of the same role.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     */
        void begin_sheet_modal_for_window(const Window& window, std::function<void(std::int64_t)> handler) const;
        /**
     * @brief Calls `-[NSSavePanel beginWithCompletionHandler:]`.
     * @details 'NSSavePanel'/'NSOpenPanel': Presents the panel as a modeless window and returns immediately. Configure the panel before calling this method. The completion handler block will be called after the user has closed the panel. The 'result' will be 'NSModalResponseOK', 'NSModalResponseCancel', or if the panel fails to display, 'NSModalResponseAbort'.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     */
        void begin_with_completion_handler(std::function<void(std::int64_t)> handler) const;
        /**
     * @brief Calls `-[NSSavePanel cancel:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void cancel(const Object& sender) const;
        /**
     * @brief Calls `-[NSSavePanel ok:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void ok(const Object& sender) const;
        /**
     * @brief Calls `-[NSSavePanel runModal]`.
     * @details 'NSSavePanel'/'NSOpenPanel': Presents the panel as an application modal window. Returns after the user has closed the panel. - Returns: 'NSModalResponseOK', 'NSModalResponseCancel' or if the panel fails to display, 'NSModalResponseAbort'.
     * @return The converted Objective-C result.
     */
        std::int64_t run_modal() const;
        /**
     * @brief Calls `+[NSSavePanel savePanel]`.
     * @details Creates a new instance of the NSSavePanel. This class is not a singleton.
     * @return The converted Objective-C result.
     */
        static SavePanel save_panel();
        /**
     * @brief Calls `-[NSSavePanel validateVisibleColumns]`.
     * @details Refreshes the open or save panel's contents.
     */
        void validate_visible_columns() const;
        /**
     * @brief Returns the `URL` property of `NSSavePanel`.
     * @details 'NSSavePanel': Returns the URL to save the file at. A file may already exist at 'url' if the user choose to overwrite it. 'NSOpenPanel': Returns the single filename selected by the user. Note: if -allowsMultipleSelection is set, you should use the -URLs on NSOpenPanel instead.
     * @return The converted Objective-C result.
     */
        URL url() const;
        /**
     * @brief Returns the `accessoryView` property of `NSSavePanel`.
     * @details Sets and returns the accessory view shown in the panel. For applications that link on 10.6 and later, the accessoryView's frame will be observed, and any changes the programmer makes to the frame will automatically be reflected in the panel (including animated changes to the frame height). For applications that link on 26.0 and later and use the Liquid Glass design, the accessoryView's control metrics will be the larger Liquid Glass metrics.
     * @return The converted Objective-C result.
     */
        View accessory_view() const;
        /**
     * @brief Sets the `accessoryView` property of `NSSavePanel`.
     * @details Sets and returns the accessory view shown in the panel. For applications that link on 10.6 and later, the accessoryView's frame will be observed, and any changes the programmer makes to the frame will automatically be reflected in the panel (including animated changes to the frame height). For applications that link on 26.0 and later and use the Liquid Glass design, the accessoryView's control metrics will be the larger Liquid Glass metrics.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_accessory_view(const View& value) const;
        /**
     * @brief Returns the `allowedContentTypes` property of `NSSavePanel`.
     * @details 'NSSavePanel': An array of UTTypes specifying the file types the user can save the file as. Set to '\@[]' to specify that any file type can be used. If no extension is given by the user, the first preferred extension from the array will be used as the extension for the save panel. If the user specifies a type not in the array, and 'allowsOtherFileTypes' is 'YES', they will be presented with another dialog when prompted to save. The default value is the empty array. 'NSOpenPanel': This property determines which files should be enabled in the open panel. Using the deprecated methods to show the open panel (the ones that take a "types:" parameter) will overwrite this value, and should not be used. 'allowedContentTypes' can be changed while the panel is running (ie: from an accessory view). This is also known as the "enabled file types". Set to '\@[]' to specify that all files should be enabled.
     * @return The converted Objective-C result.
     */
        std::vector<Object> allowed_content_types() const;
        /**
     * @brief Sets the `allowedContentTypes` property of `NSSavePanel`.
     * @details 'NSSavePanel': An array of UTTypes specifying the file types the user can save the file as. Set to '\@[]' to specify that any file type can be used. If no extension is given by the user, the first preferred extension from the array will be used as the extension for the save panel. If the user specifies a type not in the array, and 'allowsOtherFileTypes' is 'YES', they will be presented with another dialog when prompted to save. The default value is the empty array. 'NSOpenPanel': This property determines which files should be enabled in the open panel. Using the deprecated methods to show the open panel (the ones that take a "types:" parameter) will overwrite this value, and should not be used. 'allowedContentTypes' can be changed while the panel is running (ie: from an accessory view). This is also known as the "enabled file types". Set to '\@[]' to specify that all files should be enabled.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allowed_content_types(const std::vector<Object>& value) const;
        /**
     * @brief Returns the `allowsOtherFileTypes` property of `NSSavePanel`.
     * @details 'NSSavePanel': Returns a BOOL value that indicates whether the panel allows the user to save files with an extension that is not in the list of 'allowedFileTypes'. 'NSOpenPanel': Not used.
     * @return The converted Objective-C result.
     */
        bool allows_other_file_types() const;
        /**
     * @brief Sets the `allowsOtherFileTypes` property of `NSSavePanel`.
     * @details 'NSSavePanel': Returns a BOOL value that indicates whether the panel allows the user to save files with an extension that is not in the list of 'allowedFileTypes'. 'NSOpenPanel': Not used.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_other_file_types(bool value) const;
        /**
     * @brief Returns the `canCreateDirectories` property of `NSSavePanel`.
     * @details 'NSSavePanel'/'NSOpenPanel': Set to 'YES' to show the "New Folder" button. Default is 'YES'.
     * @return The converted Objective-C result.
     */
        bool can_create_directories() const;
        /**
     * @brief Sets the `canCreateDirectories` property of `NSSavePanel`.
     * @details 'NSSavePanel'/'NSOpenPanel': Set to 'YES' to show the "New Folder" button. Default is 'YES'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_can_create_directories(bool value) const;
        /**
     * @brief Returns the `canSelectHiddenExtension` property of `NSSavePanel`.
     * @details 'NSSavePanel': Set to 'YES' to show the "Hide Extension" menu item. 'NSOpenPanel': Not used.
     * @return The converted Objective-C result.
     */
        bool can_select_hidden_extension() const;
        /**
     * @brief Sets the `canSelectHiddenExtension` property of `NSSavePanel`.
     * @details 'NSSavePanel': Set to 'YES' to show the "Hide Extension" menu item. 'NSOpenPanel': Not used.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_can_select_hidden_extension(bool value) const;
        /**
     * @brief Returns the `currentContentType` property of `NSSavePanel`.
     * @details 'NSSavePanel':The current type. If set to 'nil', resets to the first allowed content type. Returns 'nil' if 'allowedContentTypes' is empty. 'NSOpenPanel': Not used. - Note: Asserts that 'currentContentType' conforms to 'UTTypeData' or 'UTTypeDirectory'.
     * @return The converted Objective-C result.
     */
        Object current_content_type() const;
        /**
     * @brief Sets the `currentContentType` property of `NSSavePanel`.
     * @details 'NSSavePanel':The current type. If set to 'nil', resets to the first allowed content type. Returns 'nil' if 'allowedContentTypes' is empty. 'NSOpenPanel': Not used. - Note: Asserts that 'currentContentType' conforms to 'UTTypeData' or 'UTTypeDirectory'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_current_content_type(const Object& value) const;
        /**
     * @brief Returns the `directoryURL` property of `NSSavePanel`.
     * @details 'NSSavePanel'/'NSOpenPanel': Sets and returns the directory that is displayed. Set to 'nil' to display the default directory. This method will not block to resolve the URL, and the directory will asynchronously be set, if required. - Note: Can only be set during the configuration phase.
     * @return The converted Objective-C result.
     */
        URL directory_url() const;
        /**
     * @brief Sets the `directoryURL` property of `NSSavePanel`.
     * @details 'NSSavePanel'/'NSOpenPanel': Sets and returns the directory that is displayed. Set to 'nil' to display the default directory. This method will not block to resolve the URL, and the directory will asynchronously be set, if required. - Note: Can only be set during the configuration phase.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_directory_url(const URL& value) const;
        /**
     * @brief Returns the `expanded` property of `NSSavePanel`.
     * @details 'NSSavePanel': Returns 'YES' if the panel is expanded. Defaults to 'NO'. Persists in the user defaults. 'NSOpenPanel': Not used.
     * @return The converted Objective-C result.
     */
        bool is_expanded() const;
        /**
     * @brief Returns the `extensionHidden` property of `NSSavePanel`.
     * @details 'NSSavePanel': Set to 'YES' if the filename extension should be hidden. Otherwise, 'NO' if the filename extension should be shown. Default is 'YES'. - Note: Can only be set during the configuration phase. 'NSOpenPanel': Not used.
     * @return The converted Objective-C result.
     */
        bool is_extension_hidden() const;
        /**
     * @brief Sets the `extensionHidden` property of `NSSavePanel`.
     * @details 'NSSavePanel': Set to 'YES' if the filename extension should be hidden. Otherwise, 'NO' if the filename extension should be shown. Default is 'YES'. - Note: Can only be set during the configuration phase. 'NSOpenPanel': Not used.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_extension_hidden(bool value) const;
        /**
     * @brief Returns the `identifier` property of `NSSavePanel`.
     * @details Sets and returns the identifier. The panel's current state such as the root directory and the current directory are saved and restored relative to the identifier. - Note: When the identifier is changed, the properties that depend on the identifier are updated from user defaults. Properties that have a null value in user defaults are not changed (and keep their existing value). - Note: Can only be set during the configuration phase.
     * @return The converted Objective-C result.
     */
        std::string identifier() const;
        /**
     * @brief Sets the `identifier` property of `NSSavePanel`.
     * @details Sets and returns the identifier. The panel's current state such as the root directory and the current directory are saved and restored relative to the identifier. - Note: When the identifier is changed, the properties that depend on the identifier are updated from user defaults. Properties that have a null value in user defaults are not changed (and keep their existing value). - Note: Can only be set during the configuration phase.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_identifier(const std::string& value) const;
        /**
     * @brief Returns the `message` property of `NSSavePanel`.
     * @details 'NSSavePanel'/'NSOpenPanel': Sets and returns the message shown under title of the panel.
     * @return The converted Objective-C result.
     */
        std::string message() const;
        /**
     * @brief Sets the `message` property of `NSSavePanel`.
     * @details 'NSSavePanel'/'NSOpenPanel': Sets and returns the message shown under title of the panel.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_message(const std::string& value) const;
        /**
     * @brief Returns the `nameFieldLabel` property of `NSSavePanel`.
     * @details 'NSSavePanel': Sets and returns the text shown to the left of the "name field". Default value is a localized "Save As:" string. 'NSOpenPanel': Not used.
     * @return The converted Objective-C result.
     */
        std::string name_field_label() const;
        /**
     * @brief Sets the `nameFieldLabel` property of `NSSavePanel`.
     * @details 'NSSavePanel': Sets and returns the text shown to the left of the "name field". Default value is a localized "Save As:" string. 'NSOpenPanel': Not used.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_name_field_label(const std::string& value) const;
        /**
     * @brief Returns the `nameFieldStringValue` property of `NSSavePanel`.
     * @details 'NSSavePanel': Sets and returns the user-editable file name shown in the name field. - Note: Calling the deprecated methods that take a "name:" parameter will overwrite any values set before the panel is shown. - Note: If '[panel isExtensionHidden]' is set to 'YES', the extension will be hidden. - Note: Can only be set during the configuration phase. 'NSOpenPanel': Not used.
     * @return The converted Objective-C result.
     */
        std::string name_field_string_value() const;
        /**
     * @brief Sets the `nameFieldStringValue` property of `NSSavePanel`.
     * @details 'NSSavePanel': Sets and returns the user-editable file name shown in the name field. - Note: Calling the deprecated methods that take a "name:" parameter will overwrite any values set before the panel is shown. - Note: If '[panel isExtensionHidden]' is set to 'YES', the extension will be hidden. - Note: Can only be set during the configuration phase. 'NSOpenPanel': Not used.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_name_field_string_value(const std::string& value) const;
        /**
     * @brief Returns the `prompt` property of `NSSavePanel`.
     * @details 'NSSavePanel'/'NSOpenPanel': Sets the text shown on the Open or Save button. If set to an empty string, it will show a localized "Open" for the NSOpenPanel and "Save" for the NSSavePanel. The default value will be the correct localized prompt for the open or save panel, as appropriate.
     * @return The converted Objective-C result.
     */
        std::string prompt() const;
        /**
     * @brief Sets the `prompt` property of `NSSavePanel`.
     * @details 'NSSavePanel'/'NSOpenPanel': Sets the text shown on the Open or Save button. If set to an empty string, it will show a localized "Open" for the NSOpenPanel and "Save" for the NSSavePanel. The default value will be the correct localized prompt for the open or save panel, as appropriate.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_prompt(const std::string& value) const;
        /**
     * @brief Returns the `showsContentTypes` property of `NSSavePanel`.
     * @details 'NSSavePanel': Whether or not to show a control for selecting the type of the saved file. The control shows the types in 'allowedContentTypes'. Default is 'NO'. 'NSOpenPanel': Not used. - Note: If 'allowedContentTypes' is empty, the control is not displayed.
     * @return The converted Objective-C result.
     */
        bool shows_content_types() const;
        /**
     * @brief Sets the `showsContentTypes` property of `NSSavePanel`.
     * @details 'NSSavePanel': Whether or not to show a control for selecting the type of the saved file. The control shows the types in 'allowedContentTypes'. Default is 'NO'. 'NSOpenPanel': Not used. - Note: If 'allowedContentTypes' is empty, the control is not displayed.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_content_types(bool value) const;
        /**
     * @brief Returns the `showsHiddenFiles` property of `NSSavePanel`.
     * @details 'NSSavePanel'/'NSOpenPanel': If 'showsHiddenFiles' is set to 'YES', files that are normally hidden from the user are displayed. This method was published in Mac OS 10.6, but has existed since Mac OS 10.4. This property is KVO compliant. The user may invoke the keyboard shortcut (cmd-shift-.) to show or hide hidden files. Any user interface shown in an an accessory view should be updated by using key value observing (KVO) to watch for changes of this property. Alternatively, the user interface can be directly bound to this property. The default value is 'NO'.
     * @return The converted Objective-C result.
     */
        bool shows_hidden_files() const;
        /**
     * @brief Sets the `showsHiddenFiles` property of `NSSavePanel`.
     * @details 'NSSavePanel'/'NSOpenPanel': If 'showsHiddenFiles' is set to 'YES', files that are normally hidden from the user are displayed. This method was published in Mac OS 10.6, but has existed since Mac OS 10.4. This property is KVO compliant. The user may invoke the keyboard shortcut (cmd-shift-.) to show or hide hidden files. Any user interface shown in an an accessory view should be updated by using key value observing (KVO) to watch for changes of this property. Alternatively, the user interface can be directly bound to this property. The default value is 'NO'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_hidden_files(bool value) const;
        /**
     * @brief Returns the `showsTagField` property of `NSSavePanel`.
     * @details 'NSSavePanel': Shows or hides the "Tags" field in the receiver. By passing 'YES', you become responsible for setting Tag names on the resulting file after saving is complete. Default is 'YES'. 'NSOpenPanel': Not used.
     * @return The converted Objective-C result.
     */
        bool shows_tag_field() const;
        /**
     * @brief Sets the `showsTagField` property of `NSSavePanel`.
     * @details 'NSSavePanel': Shows or hides the "Tags" field in the receiver. By passing 'YES', you become responsible for setting Tag names on the resulting file after saving is complete. Default is 'YES'. 'NSOpenPanel': Not used.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_tag_field(bool value) const;
        /**
     * @brief Returns the `tagNames` property of `NSSavePanel`.
     * @details 'NSSavePanel': When -showsTagField returns YES, set any initial Tag names to be displayed, if necessary, prior to displaying the receiver. Also, if the user clicks "Save", take the result of -tagNames, and set them on the resulting file after saving is complete. Tag names are NSStrings, arrays of which can be used directly with the NSURLTagNamesKey API for getting and setting tags on files. Passing 'nil' or an empty array to -setTagNames: will result in no initial Tag names appearing in the receiver. When -showsTagField returns YES, -tagNames always returns a non-nil array, and when NO, -tagNames always returns 'nil'. 'NSOpenPanel': Not used.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> tag_names() const;
        /**
     * @brief Sets the `tagNames` property of `NSSavePanel`.
     * @details 'NSSavePanel': When -showsTagField returns YES, set any initial Tag names to be displayed, if necessary, prior to displaying the receiver. Also, if the user clicks "Save", take the result of -tagNames, and set them on the resulting file after saving is complete. Tag names are NSStrings, arrays of which can be used directly with the NSURLTagNamesKey API for getting and setting tags on files. Passing 'nil' or an empty array to -setTagNames: will result in no initial Tag names appearing in the receiver. When -showsTagField returns YES, -tagNames always returns a non-nil array, and when NO, -tagNames always returns 'nil'. 'NSOpenPanel': Not used.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tag_names(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `title` property of `NSSavePanel`.
     * @details 'NSSavePanel'/'NSOpenPanel': Sets and returns the title for the panel shown at the top of the window. - Note: The open and save panel does not currently have a titlebar. So the title is not displayed.
     * @return The converted Objective-C result.
     */
        std::string title() const;
        /**
     * @brief Sets the `title` property of `NSSavePanel`.
     * @details 'NSSavePanel'/'NSOpenPanel': Sets and returns the title for the panel shown at the top of the window. - Note: The open and save panel does not currently have a titlebar. So the title is not displayed.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title(const std::string& value) const;
        /**
     * @brief Returns the `treatsFilePackagesAsDirectories` property of `NSSavePanel`.
     * @details 'NSSavePanel'/'NSOpenPanel': If set to 'YES', the user can navigate into file packages as if they were directories. Default is 'NO'.
     * @return The converted Objective-C result.
     */
        bool treats_file_packages_as_directories() const;
        /**
     * @brief Sets the `treatsFilePackagesAsDirectories` property of `NSSavePanel`.
     * @details 'NSSavePanel'/'NSOpenPanel': If set to 'YES', the user can navigate into file packages as if they were directories. Default is 'NO'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_treats_file_packages_as_directories(bool value) const;
        /// @brief Signal for the delegate/data-source method behind `panel_should_enable_url`; connect a callback with `panel_should_enable_url().connect(...)`.
        Signal<SavePanel, bool(URL)> panel_should_enable_url() const
        {
            return Signal<SavePanel, bool(URL)>(handle(), "panel_should_enable_url");
        }
        /// @brief Signal for the delegate/data-source method behind `panel_did_change_to_directory_url`; connect a callback with `panel_did_change_to_directory_url().connect(...)`.
        Signal<SavePanel, void(URL)> panel_did_change_to_directory_url() const
        {
            return Signal<SavePanel, void(URL)>(handle(), "panel_did_change_to_directory_url");
        }
        /// @brief Signal for the delegate/data-source method behind `panel_user_entered_filename_confirmed`; connect a callback with `panel_user_entered_filename_confirmed().connect(...)`.
        Signal<SavePanel, std::string(std::string, bool)> panel_user_entered_filename_confirmed() const
        {
            return Signal<SavePanel, std::string(std::string, bool)>(handle(), "panel_user_entered_filename_confirmed");
        }
        /// @brief Signal for the delegate/data-source method behind `panel_will_expand`; connect a callback with `panel_will_expand().connect(...)`.
        Signal<SavePanel, void(bool)> panel_will_expand() const
        {
            return Signal<SavePanel, void(bool)>(handle(), "panel_will_expand");
        }
        /// @brief Signal for the delegate/data-source method behind `panel_selection_did_change`; connect a callback with `panel_selection_did_change().connect(...)`.
        Signal<SavePanel, void()> panel_selection_did_change() const
        {
            return Signal<SavePanel, void()>(handle(), "panel_selection_did_change");
        }
        /// @brief Signal for the delegate/data-source method behind `panel_display_name_for_type`; connect a callback with `panel_display_name_for_type().connect(...)`.
        Signal<SavePanel, std::string(Object)> panel_display_name_for_type() const
        {
            return Signal<SavePanel, std::string(Object)>(handle(), "panel_display_name_for_type");
        }
        /// @brief Signal for the delegate/data-source method behind `panel_did_select_type`; connect a callback with `panel_did_select_type().connect(...)`.
        Signal<SavePanel, void(Object)> panel_did_select_type() const
        {
            return Signal<SavePanel, void(Object)>(handle(), "panel_did_select_type");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
