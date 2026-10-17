#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class GraphicsContext;
    class PDFPanel;
    class PrintInfo;
    class PrintPanel;
    class View;
    class Window;

    /**
     * @brief C++ handle for the Objective-C class `NSPrintOperation` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PrintOperation print_operation;
     * print_operation.set_pdf_panel(cocoon::PDFPanel());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PrintOperation print_operation{};
     * print_operation.set_pdf_panel(cocoon::PDFPanel());
     * auto pdf_panel = print_operation.pdf_panel();
     * print_operation.set_can_spawn_separate_thread(true);
     * auto can_spawn_separate_thread = print_operation.can_spawn_separate_thread();
     * print_operation.set_current_operation(cocoon::PrintOperation());
     * auto current_operation = print_operation.current_operation();
     * auto made_0 = cocoon::PrintOperation::eps_operation_with_view(cocoon::View(), {{0, 0}, {100, 100}}, "text", cocoon::PrintInfo());
     * auto made_1 = cocoon::PrintOperation::pdf_operation_with_view(cocoon::View(), {{0, 0}, {100, 100}}, "text", cocoon::PrintInfo());
     * print_operation.clean_up_operation();
     * print_operation.create_context();
     * print_operation.deliver_result();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsprintoperation
     */
    class PrintOperation : public Object
    {
    public:
        /// @brief Creates a new `NSPrintOperation` instance and returns a handle to it.
        explicit PrintOperation();
        /// @brief Creates a null handle that refers to no native object.
        PrintOperation(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PrintOperation(Adopt adopt);
        /**
     * @brief Calls `+[NSPrintOperation EPSOperationWithView:insideRect:toData:]`.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PrintOperation eps_operation_with_view(const View& view, const Rect& rect, const std::vector<std::uint8_t>& data);
        /**
     * @brief Calls `+[NSPrintOperation EPSOperationWithView:insideRect:toData:printInfo:]`.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @param print_info Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PrintOperation eps_operation_with_view(const View& view, const Rect& rect, const std::vector<std::uint8_t>& data, const PrintInfo& print_info);
        /**
     * @brief Calls `+[NSPrintOperation EPSOperationWithView:insideRect:toPath:printInfo:]`.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param print_info Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PrintOperation eps_operation_with_view(const View& view, const Rect& rect, const std::string& path, const PrintInfo& print_info);
        /**
     * @brief Calls `+[NSPrintOperation PDFOperationWithView:insideRect:toData:]`.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PrintOperation pdf_operation_with_view(const View& view, const Rect& rect, const std::vector<std::uint8_t>& data);
        /**
     * @brief Calls `+[NSPrintOperation PDFOperationWithView:insideRect:toData:printInfo:]`.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @param print_info Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PrintOperation pdf_operation_with_view(const View& view, const Rect& rect, const std::vector<std::uint8_t>& data, const PrintInfo& print_info);
        /**
     * @brief Calls `+[NSPrintOperation PDFOperationWithView:insideRect:toPath:printInfo:]`.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param print_info Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PrintOperation pdf_operation_with_view(const View& view, const Rect& rect, const std::string& path, const PrintInfo& print_info);
        /**
     * @brief Calls `-[NSPrintOperation cleanUpOperation]`.
     */
        void clean_up_operation() const;
        /**
     * @brief Calls `-[NSPrintOperation createContext]`.
     * @details Methods that are invoked by the print operation itself as it proceeds. You should not invoke them.
     * @return The converted Objective-C result.
     */
        GraphicsContext create_context() const;
        /**
     * @brief Calls `-[NSPrintOperation deliverResult]`.
     * @return The converted Objective-C result.
     */
        bool deliver_result() const;
        /**
     * @brief Calls `-[NSPrintOperation destroyContext]`.
     */
        void destroy_context() const;
        /**
     * @brief Calls `+[NSPrintOperation printOperationWithView:]`.
     * @details Slight conveniences, for use when the application's global NSPrintInfo is appropriate. Each of these methods invokes [NSPrintInfo sharedPrintInfo] and then invokes the like-named method listed above.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PrintOperation print_operation_with_view(const View& view);
        /**
     * @brief Calls `+[NSPrintOperation printOperationWithView:printInfo:]`.
     * @details Factory methods that create a new NSPrintOperation for printing, copying to Portable Document Format, or copying to Encapsulated PostScript. The passed-in NSPrintInfo is copied, and the copy is retained by the new NSPrintOperation. (So, no need to copy the NSPrintInfo you pass to these.) You can get the copy with -printInfo.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param print_info Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PrintOperation print_operation_with_view(const View& view, const PrintInfo& print_info);
        /**
     * @brief Calls `-[NSPrintOperation runOperation]`.
     * @details Do the print operation, with application-modal panels. Return YES if the operation completed successfully, NO if there was an error or the user cancelled the operation. This can only be invoked once. Create a new NSPrintOperation instance for each operation. When this method completes, the object is removed from being the current operation if it is the current operation.
     * @return The converted Objective-C result.
     */
        bool run_operation() const;
        /**
     * @brief Calls `-[NSPrintOperation runOperationModalForWindow:delegate:didRunSelector:contextInfo:]`.
     * @details Do the print operation, with panels that are document-modal to a specific window. When the operation has been completed, send the message selected by didRunSelector to the delegate, with the contextInfo as the last argument. The method selected by didRunSelector must have the same signature as: - (void)printOperationDidRun:(NSPrintOperation )printOperation success:(BOOL)success contextInfo:(void )contextInfo; This can only be invoked once. Create a new NSPrintOperation instance for each operation. When this method completes, the object is removed from being the current operation if it is the current operation.
     * @param doc_window Argument converted to the Objective-C parameter of the same role.
     * @param delegate Argument converted to the Objective-C parameter of the same role.
     * @param did_run_selector Argument converted to the Objective-C parameter of the same role.
     * @param context_info Argument converted to the Objective-C parameter of the same role.
     */
        void run_operation_modal_for_window(const Window& doc_window, const Object& delegate, const std::string& did_run_selector, void* context_info) const;
        /**
     * @brief Returns the `PDFPanel` property of `NSPrintOperation`.
     * @details The panel to be presented by the operation when it is run, if [[self printInfo] jobDisposition] is NSPrintSaveJob and [[[self printInfo] dictionary] objectForKey:NSPrintJobSavingURL] is nil. -PDFPanel will create a new NSPDFPanel if one hasn't been set yet. NSPrintOperation will throw an exception if panel.options contains NSPDFPanelRequestsParentDirectory when it attempts to display the panel.
     * @return The converted Objective-C result.
     */
        PDFPanel pdf_panel() const;
        /**
     * @brief Sets the `PDFPanel` property of `NSPrintOperation`.
     * @details The panel to be presented by the operation when it is run, if [[self printInfo] jobDisposition] is NSPrintSaveJob and [[[self printInfo] dictionary] objectForKey:NSPrintJobSavingURL] is nil. -PDFPanel will create a new NSPDFPanel if one hasn't been set yet. NSPrintOperation will throw an exception if panel.options contains NSPDFPanelRequestsParentDirectory when it attempts to display the panel.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_pdf_panel(const PDFPanel& value) const;
        /**
     * @brief Returns the `canSpawnSeparateThread` property of `NSPrintOperation`.
     * @details Whether the print operation should spawn a separate thread in which to run itself.
     * @return The converted Objective-C result.
     */
        bool can_spawn_separate_thread() const;
        /**
     * @brief Sets the `canSpawnSeparateThread` property of `NSPrintOperation`.
     * @details Whether the print operation should spawn a separate thread in which to run itself.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_can_spawn_separate_thread(bool value) const;
        /**
     * @brief Returns the `context` property of `NSPrintOperation`.
     * @details The context for the output of this operation.
     * @return The converted Objective-C result.
     */
        GraphicsContext context() const;
        /**
     * @brief Returns the `copyingOperation` property of `NSPrintOperation`.
     * @details Return YES if the operation for copying to PDF or EPS, NO if it's for printing.
     * @return The converted Objective-C result.
     */
        bool is_copying_operation() const;
        /**
     * @brief Returns the `currentOperation` property of `NSPrintOperation`.
     * @details The current print operation for this thread. If this is nil, there is no current operation for the current thread.
     * @return The converted Objective-C result.
     */
        static PrintOperation current_operation();
        /**
     * @brief Sets the `currentOperation` property of `NSPrintOperation`.
     * @details The current print operation for this thread. If this is nil, there is no current operation for the current thread.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_current_operation(const PrintOperation& value);
        /**
     * @brief Returns the `currentPage` property of `NSPrintOperation`.
     * @details The current one-based page number of the operation as it's being previewed or printed.
     * @return The converted Objective-C result.
     */
        std::int64_t current_page() const;
        /**
     * @brief Returns the `jobTitle` property of `NSPrintOperation`.
     * @details The title of the print job. If a job title is set it overrides anything that might be gotten by sending the printed view an [NSView(NSPrinting) printJobTitle] message.
     * @return The converted Objective-C result.
     */
        std::string job_title() const;
        /**
     * @brief Sets the `jobTitle` property of `NSPrintOperation`.
     * @details The title of the print job. If a job title is set it overrides anything that might be gotten by sending the printed view an [NSView(NSPrinting) printJobTitle] message.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_job_title(const std::string& value) const;
        /**
     * @brief Returns the `pageOrder` property of `NSPrintOperation`.
     * @details The page order that will be used to generate the pages in this job. This is the physical page order of the pages. It depends on the stacking order of the printer, the capability of the app to reverse page order, etc.
     * @return The converted Objective-C result.
     */
        PrintingPageOrder page_order() const;
        /**
     * @brief Sets the `pageOrder` property of `NSPrintOperation`.
     * @details The page order that will be used to generate the pages in this job. This is the physical page order of the pages. It depends on the stacking order of the printer, the capability of the app to reverse page order, etc.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_page_order(PrintingPageOrder value) const;
        /**
     * @brief Returns the `pageRange` property of `NSPrintOperation`.
     * @details The first through last one-based page numbers of the operation as it's being previewed or printed. The first page number might not be 1, and the page count might be NSIntegerMax to indicate that the number of pages is not known, depending on what the printed view returned when sent an [NSView(NSPrinting) knowsPageRange:] message.
     * @return The converted Objective-C result.
     */
        Range page_range() const;
        /**
     * @brief Returns the `preferredRenderingQuality` property of `NSPrintOperation`.
     * @details If the print sheet is unresponsive or sluggish due to the time is takes you to fully render a page, you can check this method in drawRect and other printing methods such as beginDocument and knowsPageRage: to determine if the print operation prefers speed over fidelity. Please see the comments for NSPrintRenderingQuality. Most applications render each page fast enough and do not need to call this method.
     * @return The converted Objective-C result.
     */
        PrintRenderingQuality preferred_rendering_quality() const;
        /**
     * @brief Returns the `printInfo` property of `NSPrintOperation`.
     * @details The print info of the operation. -printInfo always returns a copy of the NSPrintInfo passed into the factory method used to create the print operation, unless -setPrintInfo: has been invoked, in which case it returns the exact same object passed into -setPrintInfo:. So, the factory methods listed above copy the passed-in NSPrintInfo, but -setPrintInfo: doesn't.
     * @return The converted Objective-C result.
     */
        PrintInfo print_info() const;
        /**
     * @brief Sets the `printInfo` property of `NSPrintOperation`.
     * @details The print info of the operation. -printInfo always returns a copy of the NSPrintInfo passed into the factory method used to create the print operation, unless -setPrintInfo: has been invoked, in which case it returns the exact same object passed into -setPrintInfo:. So, the factory methods listed above copy the passed-in NSPrintInfo, but -setPrintInfo: doesn't.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_print_info(const PrintInfo& value) const;
        /**
     * @brief Returns the `printPanel` property of `NSPrintOperation`.
     * @details The print panel to be presented by the operation when it is run, if showsProgressPanel is YES and isCopyingOperation is NO. -printPanel will create a new NSPrintPanel if one hasn't been set yet.
     * @return The converted Objective-C result.
     */
        PrintPanel print_panel() const;
        /**
     * @brief Sets the `printPanel` property of `NSPrintOperation`.
     * @details The print panel to be presented by the operation when it is run, if showsProgressPanel is YES and isCopyingOperation is NO. -printPanel will create a new NSPrintPanel if one hasn't been set yet.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_print_panel(const PrintPanel& value) const;
        /**
     * @brief Returns the `showsPrintPanel` property of `NSPrintOperation`.
     * @details Whether the print and progress panels are shown during the operation.
     * @return The converted Objective-C result.
     */
        bool shows_print_panel() const;
        /**
     * @brief Sets the `showsPrintPanel` property of `NSPrintOperation`.
     * @details Whether the print and progress panels are shown during the operation.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_print_panel(bool value) const;
        /**
     * @brief Returns the `showsProgressPanel` property of `NSPrintOperation`.
     * @return The converted Objective-C result.
     */
        bool shows_progress_panel() const;
        /**
     * @brief Sets the `showsProgressPanel` property of `NSPrintOperation`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_progress_panel(bool value) const;
        /**
     * @brief Returns the `view` property of `NSPrintOperation`.
     * @details The view being printed.
     * @return The converted Objective-C result.
     */
        View view() const;
    };
}
