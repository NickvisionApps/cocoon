#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class PDFInfo;
    class ViewController;
    class Window;

    /**
     * @brief C++ handle for the Objective-C class `NSPDFPanel` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PDFPanel pdf_panel;
     * pdf_panel.set_accessory_controller(cocoon::ViewController());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PDFPanel pdf_panel{};
     * pdf_panel.set_accessory_controller(cocoon::ViewController());
     * auto accessory_controller = pdf_panel.accessory_controller();
     * pdf_panel.set_default_file_name("text");
     * auto default_file_name = pdf_panel.default_file_name();
     * pdf_panel.set_options(cocoon::PDFPanelOptions::ShowsPaperSize);
     * auto options = pdf_panel.options();
     * auto made_0 = cocoon::PDFPanel::panel();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspdfpanel
     */
    class PDFPanel : public Object
    {
    public:
        /// @brief Creates a new `NSPDFPanel` instance and returns a handle to it.
        explicit PDFPanel();
        /// @brief Creates a null handle that refers to no native object.
        PDFPanel(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PDFPanel(Adopt adopt);
        /**
         * @brief Calls `-[NSPDFPanel beginSheetWithPDFInfo:modalForWindow:completionHandler:]`.
         * @details Present a print panel to the user, document-modally. When the user has dismissed it, invoke the completionHandler block. If the user didn't click the 'Cancel' button, the given NSPDFInfo will be modified to reflect the user's chosen settings, if any.
         * @param pdf_info Argument converted to the Objective-C parameter of the same role.
         * @param doc_window Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void begin_sheet_with_pdf_info(const PDFInfo& pdf_info, const Window& doc_window, std::function<void(std::int64_t)> completion_handler) const;
        /**
         * @brief Calls `+[NSPDFPanel panel]`.
         * @details Create a new NSPDFPanel.
         * @return The converted Objective-C result.
         */
        static PDFPanel panel();
        /**
         * @brief Returns the `accessoryController` property of `NSPDFPanel`.
         * @details Controller for the accessory views that will be presented in the panel by the methods below. When the panel is presented to the user the controller is automatically sent a -setRepresentedObject: message with an NSPDFInfo equivalent to those one passed to -beginSheetWithPDFInfo:modalForWindow:completionHandler:.
         * @return The converted Objective-C result.
         */
        ViewController accessory_controller() const;
        /**
         * @brief Sets the `accessoryController` property of `NSPDFPanel`.
         * @details Controller for the accessory views that will be presented in the panel by the methods below. When the panel is presented to the user the controller is automatically sent a -setRepresentedObject: message with an NSPDFInfo equivalent to those one passed to -beginSheetWithPDFInfo:modalForWindow:completionHandler:.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_accessory_controller(const ViewController& value) const;
        /**
         * @brief Returns the `defaultFileName` property of `NSPDFPanel`.
         * @details The user-editable file name shown in the name field. The default value is the equivalent of 'Untitled' for the current locale. Note that this string should never include a file extension.
         * @return The converted Objective-C result.
         */
        std::string default_file_name() const;
        /**
         * @brief Sets the `defaultFileName` property of `NSPDFPanel`.
         * @details The user-editable file name shown in the name field. The default value is the equivalent of 'Untitled' for the current locale. Note that this string should never include a file extension.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_default_file_name(const std::string& value) const;
        /**
         * @brief Returns the `options` property of `NSPDFPanel`.
         * @details The options described above. The default value is 0. To allow your application to take advantage of controls that may be added by default in future versions OS X, get the options from the panel you've just created, turn on and off the flags you care about, and then set the options.
         * @return The converted Objective-C result.
         */
        PDFPanelOptions options() const;
        /**
         * @brief Sets the `options` property of `NSPDFPanel`.
         * @details The options described above. The default value is 0. To allow your application to take advantage of controls that may be added by default in future versions OS X, get the options from the panel you've just created, turn on and off the flags you care about, and then set the options.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_options(PDFPanelOptions value) const;
    };
}
