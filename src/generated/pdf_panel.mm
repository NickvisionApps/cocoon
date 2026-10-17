#include "generated/pdf_panel.h"
#include "internal.h"

namespace cocoon
{
    PDFPanel::PDFPanel() : PDFPanel(Adopt{cocoon::internal::retain([[::NSPDFPanel alloc] init])})
    {
    }

    PDFPanel::PDFPanel(std::nullptr_t) : Object(nullptr)
    {
    }

    PDFPanel::PDFPanel(Adopt adopt) : Object(adopt)
    {
    }

    void PDFPanel::begin_sheet_with_pdf_info(const PDFInfo& pdf_info, const Window& doc_window, std::function<void(std::int64_t)> completion_handler) const
    {
        [cocoon::internal::ns<::NSPDFPanel>(this) beginSheetWithPDFInfo:cocoon::internal::native<::NSPDFInfo>(pdf_info) modalForWindow:cocoon::internal::native<::NSWindow>(doc_window) completionHandler:(completion_handler ? (void (^)(::NSInteger)) ^ void(::NSInteger a65_0) { completion_handler(static_cast<std::int64_t>(a65_0)); } : (void (^)(::NSInteger))nil)];
    }

    PDFPanel PDFPanel::panel()
    {
        return cocoon::internal::wrap<PDFPanel>([::NSPDFPanel panel]);
    }

    ViewController PDFPanel::accessory_controller() const
    {
        return cocoon::internal::wrap<ViewController>([cocoon::internal::ns<::NSPDFPanel>(this) accessoryController]);
    }

    void PDFPanel::set_accessory_controller(const ViewController& value) const
    {
        [cocoon::internal::ns<::NSPDFPanel>(this) setAccessoryController:cocoon::internal::native<::NSViewController>(value)];
    }

    std::string PDFPanel::default_file_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPDFPanel>(this) defaultFileName]);
    }

    void PDFPanel::set_default_file_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPDFPanel>(this) setDefaultFileName:cocoon::internal::to(value)];
    }

    PDFPanelOptions PDFPanel::options() const
    {
        return static_cast<PDFPanelOptions>([cocoon::internal::ns<::NSPDFPanel>(this) options]);
    }

    void PDFPanel::set_options(PDFPanelOptions value) const
    {
        [cocoon::internal::ns<::NSPDFPanel>(this) setOptions:static_cast<::NSPDFPanelOptions>(value)];
    }
}
