#include "generated/print_info.h"
#include "internal.h"

namespace cocoon
{
    PrintInfo::PrintInfo(const std::map<std::string, Object>& attributes) : PrintInfo(Adopt{cocoon::internal::retain([[::NSPrintInfo alloc] initWithDictionary:cocoon::internal::to_dictionary(attributes, [](const std::string& k) -> id
                                                                                                                                                                   {
                                                                                                                                                                       return cocoon::internal::to(k);
                                                                                                                                                                   },
                                                                                                                                                                   [](const Object& v) -> id
                                                                                                                                                                   {
                                                                                                                                                                       return cocoon::internal::native_id(v);
                                                                                                                                                                   })])})
    {
    }

    PrintInfo::PrintInfo() : PrintInfo(Adopt{cocoon::internal::retain([[::NSPrintInfo alloc] init])})
    {
    }

    PrintInfo::PrintInfo(std::nullptr_t) : Object(nullptr)
    {
    }

    PrintInfo::PrintInfo(Adopt adopt) : Object(adopt)
    {
    }

    void* PrintInfo::pm_page_format() const
    {
        return [cocoon::internal::ns<::NSPrintInfo>(this) PMPageFormat];
    }

    void* PrintInfo::pm_print_session() const
    {
        return [cocoon::internal::ns<::NSPrintInfo>(this) PMPrintSession];
    }

    void* PrintInfo::pm_print_settings() const
    {
        return [cocoon::internal::ns<::NSPrintInfo>(this) PMPrintSettings];
    }

    std::map<std::string, Object> PrintInfo::dictionary() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSPrintInfo>(this) dictionary], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    void PrintInfo::set_up_print_operation_default_values() const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) setUpPrintOperationDefaultValues];
    }

    void PrintInfo::take_settings_from_pdf_info(const PDFInfo& in_pdf_info) const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) takeSettingsFromPDFInfo:cocoon::internal::native<::NSPDFInfo>(in_pdf_info)];
    }

    void PrintInfo::update_from_pm_page_format() const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) updateFromPMPageFormat];
    }

    void PrintInfo::update_from_pm_print_settings() const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) updateFromPMPrintSettings];
    }

    double PrintInfo::bottom_margin() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSPrintInfo>(this) bottomMargin]);
    }

    void PrintInfo::set_bottom_margin(double value) const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) setBottomMargin:static_cast<::CGFloat>(value)];
    }

    Printer PrintInfo::default_printer()
    {
        return cocoon::internal::wrap<Printer>([::NSPrintInfo defaultPrinter]);
    }

    PrintingPaginationMode PrintInfo::horizontal_pagination() const
    {
        return static_cast<PrintingPaginationMode>([cocoon::internal::ns<::NSPrintInfo>(this) horizontalPagination]);
    }

    void PrintInfo::set_horizontal_pagination(PrintingPaginationMode value) const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) setHorizontalPagination:static_cast<::NSPrintingPaginationMode>(value)];
    }

    bool PrintInfo::is_horizontally_centered() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPrintInfo>(this) isHorizontallyCentered]);
    }

    void PrintInfo::set_horizontally_centered(bool value) const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) setHorizontallyCentered:static_cast<::BOOL>(value)];
    }

    Rect PrintInfo::imageable_page_bounds() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPrintInfo>(this) imageablePageBounds]);
    }

    std::string PrintInfo::job_disposition() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPrintInfo>(this) jobDisposition]);
    }

    void PrintInfo::set_job_disposition(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) setJobDisposition:cocoon::internal::to(value)];
    }

    double PrintInfo::left_margin() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSPrintInfo>(this) leftMargin]);
    }

    void PrintInfo::set_left_margin(double value) const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) setLeftMargin:static_cast<::CGFloat>(value)];
    }

    std::string PrintInfo::localized_paper_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPrintInfo>(this) localizedPaperName]);
    }

    PaperOrientation PrintInfo::orientation() const
    {
        return static_cast<PaperOrientation>([cocoon::internal::ns<::NSPrintInfo>(this) orientation]);
    }

    void PrintInfo::set_orientation(PaperOrientation value) const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) setOrientation:static_cast<::NSPaperOrientation>(value)];
    }

    std::string PrintInfo::paper_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPrintInfo>(this) paperName]);
    }

    void PrintInfo::set_paper_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) setPaperName:cocoon::internal::to(value)];
    }

    Size PrintInfo::paper_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPrintInfo>(this) paperSize]);
    }

    void PrintInfo::set_paper_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) setPaperSize:cocoon::internal::to(value)];
    }

    std::map<std::string, Object> PrintInfo::print_settings() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSPrintInfo>(this) printSettings], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    Printer PrintInfo::printer() const
    {
        return cocoon::internal::wrap<Printer>([cocoon::internal::ns<::NSPrintInfo>(this) printer]);
    }

    void PrintInfo::set_printer(const Printer& value) const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) setPrinter:cocoon::internal::native<::NSPrinter>(value)];
    }

    double PrintInfo::right_margin() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSPrintInfo>(this) rightMargin]);
    }

    void PrintInfo::set_right_margin(double value) const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) setRightMargin:static_cast<::CGFloat>(value)];
    }

    double PrintInfo::scaling_factor() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSPrintInfo>(this) scalingFactor]);
    }

    void PrintInfo::set_scaling_factor(double value) const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) setScalingFactor:static_cast<::CGFloat>(value)];
    }

    bool PrintInfo::is_selection_only() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPrintInfo>(this) isSelectionOnly]);
    }

    void PrintInfo::set_selection_only(bool value) const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) setSelectionOnly:static_cast<::BOOL>(value)];
    }

    PrintInfo PrintInfo::shared_print_info()
    {
        return cocoon::internal::wrap<PrintInfo>([::NSPrintInfo sharedPrintInfo]);
    }

    void PrintInfo::set_shared_print_info(const PrintInfo& value)
    {
        [::NSPrintInfo setSharedPrintInfo:cocoon::internal::native<::NSPrintInfo>(value)];
    }

    double PrintInfo::top_margin() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSPrintInfo>(this) topMargin]);
    }

    void PrintInfo::set_top_margin(double value) const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) setTopMargin:static_cast<::CGFloat>(value)];
    }

    PrintingPaginationMode PrintInfo::vertical_pagination() const
    {
        return static_cast<PrintingPaginationMode>([cocoon::internal::ns<::NSPrintInfo>(this) verticalPagination]);
    }

    void PrintInfo::set_vertical_pagination(PrintingPaginationMode value) const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) setVerticalPagination:static_cast<::NSPrintingPaginationMode>(value)];
    }

    bool PrintInfo::is_vertically_centered() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPrintInfo>(this) isVerticallyCentered]);
    }

    void PrintInfo::set_vertically_centered(bool value) const
    {
        [cocoon::internal::ns<::NSPrintInfo>(this) setVerticallyCentered:static_cast<::BOOL>(value)];
    }
}
