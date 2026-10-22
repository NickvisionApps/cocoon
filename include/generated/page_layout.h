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
     * @brief C++ handle for the Objective-C class `NSPageLayout` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PageLayout page_layout;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PageLayout page_layout{};
     * page_layout.add_accessory_controller(cocoon::ViewController());
     * page_layout.remove_accessory_controller(cocoon::ViewController());
     * page_layout.run_modal();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspagelayout
     */
    class PageLayout : public Object
    {
    public:
        /// @brief Creates a new `NSPageLayout` instance and returns a handle to it.
        explicit PageLayout();
        /// @brief Creates a null handle that refers to no native object.
        PageLayout(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PageLayout(Adopt adopt);
        /**
         * @brief Calls `-[NSPageLayout addAccessoryController:]`.
         * @details Controllers for the accessory views that will be presented in the page setup panel by the methods below. When the page setup panel is presented to the user each controller is automatically sent a -setRepresentedObject: message with this object's NSPrintInfo. Because NSViewControllers are KVC and KVO compliant for "representedObject," you can use one as the file's owner of an accessory view's nib and bind controls to the file's owner using key paths that start with "representedObject." to take advantage of NSPrintInfo's KVC and KVO compliance. Each controller is also automatically sent a -title message. If that returns nil the application's short name is used in the popup menu that lets the user choose an accessory view.
         * @param accessory_controller Argument converted to the Objective-C parameter of the same role.
         */
        void add_accessory_controller(const ViewController& accessory_controller) const;
        /**
         * @brief Calls `-[NSPageLayout beginSheetUsingPrintInfo:onWindow:completionHandler:]`.
         * @details Displays a page layout panel as a sheet on a window. This method returns immediately. When the page layout panel is dismissed, calls the completion handler with NSPageLayoutResult as the argument.
         * @param print_info Argument converted to the Objective-C parameter of the same role.
         * @param parent_window Argument converted to the Objective-C parameter of the same role.
         * @param handler Argument converted to the Objective-C parameter of the same role.
         */
        void begin_sheet_using_print_info(const PrintInfo& print_info, const Window& parent_window, std::function<void(PageLayoutResult)> handler) const;
        /**
         * @brief Calls `-[NSPageLayout beginSheetWithPrintInfo:modalForWindow:delegate:didEndSelector:contextInfo:]`.
         * @details Present a page setup panel to the user, document-modally. When the user has dismissed it, send the message selected by didEndSelector to the delegate, with the contextInfo as the last argument. The method selected by didEndSelector must have the same signature as: - (void)pageLayoutDidEnd:(NSPageLayout )pageLayout returnCode:(NSInteger)returnCode contextInfo:(void )contextInfo;
         * @param print_info Argument converted to the Objective-C parameter of the same role.
         * @param doc_window Argument converted to the Objective-C parameter of the same role.
         * @param delegate Argument converted to the Objective-C parameter of the same role.
         * @param did_end_selector Argument converted to the Objective-C parameter of the same role.
         * @param context_info Argument converted to the Objective-C parameter of the same role.
         */
        void begin_sheet_with_print_info(const PrintInfo& print_info, const Window& doc_window, const Object& delegate, const std::string& did_end_selector, void* context_info) const;
        /**
         * @brief Calls `-[NSPageLayout removeAccessoryController:]`.
         * @param accessory_controller Argument converted to the Objective-C parameter of the same role.
         */
        void remove_accessory_controller(const ViewController& accessory_controller) const;
        /**
         * @brief Calls `-[NSPageLayout runModal]`.
         * @return The converted Objective-C result.
         */
        std::int64_t run_modal() const;
        /**
         * @brief Calls `-[NSPageLayout runModalWithPrintInfo:]`.
         * @details Present a page setup panel to the user, application-modally, and return either NSOKButton or NSCancelButton. The default implementation of -runModal just invokes [self runModalWithPrintInfo:[NSPrintInfo sharedPrintInfo]].
         * @param print_info Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t run_modal_with_print_info(const PrintInfo& print_info) const;
        /**
         * @brief Returns the `accessoryControllers` property of `NSPageLayout`.
         * @return The converted Objective-C result.
         */
        std::vector<ViewController> accessory_controllers() const;
        /**
         * @brief Returns the `printInfo` property of `NSPageLayout`.
         * @details Returns the printInfo passed to 'beginSheetUsingPrintInfo:onWindow:completionHandler:'.
         * @return The converted Objective-C result.
         */
        PrintInfo print_info() const;
    };
}
