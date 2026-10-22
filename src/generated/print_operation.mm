#include "generated/print_operation.h"
#include "internal.h"

namespace cocoon
{
    PrintOperation::PrintOperation(const View& view) : PrintOperation(Adopt{cocoon::internal::retain([::NSPrintOperation printOperationWithView:cocoon::internal::native<::NSView>(view)])})
    {
    }

    PrintOperation::PrintOperation(const View& view, const PrintInfo& print_info) : PrintOperation(Adopt{cocoon::internal::retain([::NSPrintOperation printOperationWithView:cocoon::internal::native<::NSView>(view) printInfo:cocoon::internal::native<::NSPrintInfo>(print_info)])})
    {
    }

    PrintOperation::PrintOperation() : PrintOperation(Adopt{cocoon::internal::retain([[::NSPrintOperation alloc] init])})
    {
    }

    PrintOperation::PrintOperation(std::nullptr_t) : Object(nullptr)
    {
    }

    PrintOperation::PrintOperation(Adopt adopt) : Object(adopt)
    {
    }

    PrintOperation PrintOperation::eps_operation_with_view(const View& view, const Rect& rect, const std::vector<std::uint8_t>& data)
    {
        return cocoon::internal::wrap<PrintOperation>([::NSPrintOperation EPSOperationWithView:cocoon::internal::native<::NSView>(view) insideRect:cocoon::internal::to(rect) toData:cocoon::internal::to_mutable_data(data)]);
    }

    PrintOperation PrintOperation::eps_operation_with_view(const View& view, const Rect& rect, const std::vector<std::uint8_t>& data, const PrintInfo& print_info)
    {
        return cocoon::internal::wrap<PrintOperation>([::NSPrintOperation EPSOperationWithView:cocoon::internal::native<::NSView>(view) insideRect:cocoon::internal::to(rect) toData:cocoon::internal::to_mutable_data(data) printInfo:cocoon::internal::native<::NSPrintInfo>(print_info)]);
    }

    PrintOperation PrintOperation::eps_operation_with_view(const View& view, const Rect& rect, const std::string& path, const PrintInfo& print_info)
    {
        return cocoon::internal::wrap<PrintOperation>([::NSPrintOperation EPSOperationWithView:cocoon::internal::native<::NSView>(view) insideRect:cocoon::internal::to(rect) toPath:cocoon::internal::to(path) printInfo:cocoon::internal::native<::NSPrintInfo>(print_info)]);
    }

    PrintOperation PrintOperation::pdf_operation_with_view(const View& view, const Rect& rect, const std::vector<std::uint8_t>& data)
    {
        return cocoon::internal::wrap<PrintOperation>([::NSPrintOperation PDFOperationWithView:cocoon::internal::native<::NSView>(view) insideRect:cocoon::internal::to(rect) toData:cocoon::internal::to_mutable_data(data)]);
    }

    PrintOperation PrintOperation::pdf_operation_with_view(const View& view, const Rect& rect, const std::vector<std::uint8_t>& data, const PrintInfo& print_info)
    {
        return cocoon::internal::wrap<PrintOperation>([::NSPrintOperation PDFOperationWithView:cocoon::internal::native<::NSView>(view) insideRect:cocoon::internal::to(rect) toData:cocoon::internal::to_mutable_data(data) printInfo:cocoon::internal::native<::NSPrintInfo>(print_info)]);
    }

    PrintOperation PrintOperation::pdf_operation_with_view(const View& view, const Rect& rect, const std::string& path, const PrintInfo& print_info)
    {
        return cocoon::internal::wrap<PrintOperation>([::NSPrintOperation PDFOperationWithView:cocoon::internal::native<::NSView>(view) insideRect:cocoon::internal::to(rect) toPath:cocoon::internal::to(path) printInfo:cocoon::internal::native<::NSPrintInfo>(print_info)]);
    }

    void PrintOperation::clean_up_operation() const
    {
        [cocoon::internal::ns<::NSPrintOperation>(this) cleanUpOperation];
    }

    GraphicsContext PrintOperation::create_context() const
    {
        return cocoon::internal::wrap<GraphicsContext>([cocoon::internal::ns<::NSPrintOperation>(this) createContext]);
    }

    bool PrintOperation::deliver_result() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPrintOperation>(this) deliverResult]);
    }

    void PrintOperation::destroy_context() const
    {
        [cocoon::internal::ns<::NSPrintOperation>(this) destroyContext];
    }

    bool PrintOperation::run_operation() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPrintOperation>(this) runOperation]);
    }

    void PrintOperation::run_operation_modal_for_window(const Window& doc_window, const Object& delegate, const std::string& did_run_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSPrintOperation>(this) runOperationModalForWindow:cocoon::internal::native<::NSWindow>(doc_window) delegate:cocoon::internal::native_id(delegate) didRunSelector:NSSelectorFromString(cocoon::internal::to(did_run_selector)) contextInfo:context_info];
    }

    PDFPanel PrintOperation::pdf_panel() const
    {
        return cocoon::internal::wrap<PDFPanel>([cocoon::internal::ns<::NSPrintOperation>(this) PDFPanel]);
    }

    void PrintOperation::set_pdf_panel(const PDFPanel& value) const
    {
        [cocoon::internal::ns<::NSPrintOperation>(this) setPDFPanel:cocoon::internal::native<::NSPDFPanel>(value)];
    }

    bool PrintOperation::can_spawn_separate_thread() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPrintOperation>(this) canSpawnSeparateThread]);
    }

    void PrintOperation::set_can_spawn_separate_thread(bool value) const
    {
        [cocoon::internal::ns<::NSPrintOperation>(this) setCanSpawnSeparateThread:static_cast<::BOOL>(value)];
    }

    GraphicsContext PrintOperation::context() const
    {
        return cocoon::internal::wrap<GraphicsContext>([cocoon::internal::ns<::NSPrintOperation>(this) context]);
    }

    bool PrintOperation::is_copying_operation() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPrintOperation>(this) isCopyingOperation]);
    }

    PrintOperation PrintOperation::current_operation()
    {
        return cocoon::internal::wrap<PrintOperation>([::NSPrintOperation currentOperation]);
    }

    void PrintOperation::set_current_operation(const PrintOperation& value)
    {
        [::NSPrintOperation setCurrentOperation:cocoon::internal::native<::NSPrintOperation>(value)];
    }

    std::int64_t PrintOperation::current_page() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPrintOperation>(this) currentPage]);
    }

    std::string PrintOperation::job_title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPrintOperation>(this) jobTitle]);
    }

    void PrintOperation::set_job_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPrintOperation>(this) setJobTitle:cocoon::internal::to(value)];
    }

    PrintingPageOrder PrintOperation::page_order() const
    {
        return static_cast<PrintingPageOrder>([cocoon::internal::ns<::NSPrintOperation>(this) pageOrder]);
    }

    void PrintOperation::set_page_order(PrintingPageOrder value) const
    {
        [cocoon::internal::ns<::NSPrintOperation>(this) setPageOrder:static_cast<::NSPrintingPageOrder>(value)];
    }

    Range PrintOperation::page_range() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPrintOperation>(this) pageRange]);
    }

    PrintRenderingQuality PrintOperation::preferred_rendering_quality() const
    {
        return static_cast<PrintRenderingQuality>([cocoon::internal::ns<::NSPrintOperation>(this) preferredRenderingQuality]);
    }

    PrintInfo PrintOperation::print_info() const
    {
        return cocoon::internal::wrap<PrintInfo>([cocoon::internal::ns<::NSPrintOperation>(this) printInfo]);
    }

    void PrintOperation::set_print_info(const PrintInfo& value) const
    {
        [cocoon::internal::ns<::NSPrintOperation>(this) setPrintInfo:cocoon::internal::native<::NSPrintInfo>(value)];
    }

    PrintPanel PrintOperation::print_panel() const
    {
        return cocoon::internal::wrap<PrintPanel>([cocoon::internal::ns<::NSPrintOperation>(this) printPanel]);
    }

    void PrintOperation::set_print_panel(const PrintPanel& value) const
    {
        [cocoon::internal::ns<::NSPrintOperation>(this) setPrintPanel:cocoon::internal::native<::NSPrintPanel>(value)];
    }

    bool PrintOperation::shows_print_panel() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPrintOperation>(this) showsPrintPanel]);
    }

    void PrintOperation::set_shows_print_panel(bool value) const
    {
        [cocoon::internal::ns<::NSPrintOperation>(this) setShowsPrintPanel:static_cast<::BOOL>(value)];
    }

    bool PrintOperation::shows_progress_panel() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPrintOperation>(this) showsProgressPanel]);
    }

    void PrintOperation::set_shows_progress_panel(bool value) const
    {
        [cocoon::internal::ns<::NSPrintOperation>(this) setShowsProgressPanel:static_cast<::BOOL>(value)];
    }

    View PrintOperation::view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSPrintOperation>(this) view]);
    }
}
