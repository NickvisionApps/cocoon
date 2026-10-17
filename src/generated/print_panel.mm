#include "generated/print_panel.h"
#include "internal.h"

namespace cocoon
{
    PrintPanel::PrintPanel() : PrintPanel(Adopt{cocoon::internal::retain([[::NSPrintPanel alloc] init])})
    {
    }

    PrintPanel::PrintPanel(std::nullptr_t) : Object(nullptr)
    {
    }

    PrintPanel::PrintPanel(Adopt adopt) : Object(adopt)
    {
    }

    void PrintPanel::add_accessory_controller(const ViewController& accessory_controller) const
    {
        [cocoon::internal::ns<::NSPrintPanel>(this) addAccessoryController:cocoon::internal::native<::NSViewController>(accessory_controller)];
    }

    void PrintPanel::begin_sheet_using_print_info(const PrintInfo& print_info, const Window& parent_window, std::function<void(PrintPanelResult)> handler) const
    {
        [cocoon::internal::ns<::NSPrintPanel>(this) beginSheetUsingPrintInfo:cocoon::internal::native<::NSPrintInfo>(print_info) onWindow:cocoon::internal::native<::NSWindow>(parent_window) completionHandler:(handler ? (void (^)(::NSPrintPanelResult)) ^ void(::NSPrintPanelResult a73_0) { handler(static_cast<PrintPanelResult>(a73_0)); } : (void (^)(::NSPrintPanelResult))nil)];
    }

    void PrintPanel::begin_sheet_with_print_info(const PrintInfo& print_info, const Window& doc_window, const Object& delegate, const std::string& did_end_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSPrintPanel>(this) beginSheetWithPrintInfo:cocoon::internal::native<::NSPrintInfo>(print_info) modalForWindow:cocoon::internal::native<::NSWindow>(doc_window) delegate:cocoon::internal::native_id(delegate) didEndSelector:NSSelectorFromString(cocoon::internal::to(did_end_selector)) contextInfo:context_info];
    }

    std::string PrintPanel::default_button_title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPrintPanel>(this) defaultButtonTitle]);
    }

    PrintPanel PrintPanel::print_panel()
    {
        return cocoon::internal::wrap<PrintPanel>([::NSPrintPanel printPanel]);
    }

    void PrintPanel::remove_accessory_controller(const ViewController& accessory_controller) const
    {
        [cocoon::internal::ns<::NSPrintPanel>(this) removeAccessoryController:cocoon::internal::native<::NSViewController>(accessory_controller)];
    }

    std::int64_t PrintPanel::run_modal() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPrintPanel>(this) runModal]);
    }

    std::int64_t PrintPanel::run_modal_with_print_info(const PrintInfo& print_info) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPrintPanel>(this) runModalWithPrintInfo:cocoon::internal::native<::NSPrintInfo>(print_info)]);
    }

    void PrintPanel::set_default_button_title(const std::string& default_button_title) const
    {
        [cocoon::internal::ns<::NSPrintPanel>(this) setDefaultButtonTitle:cocoon::internal::to(default_button_title)];
    }

    std::vector<ViewController> PrintPanel::accessory_controllers() const
    {
        return cocoon::internal::from_array<ViewController>([cocoon::internal::ns<::NSPrintPanel>(this) accessoryControllers], [](id e) -> ViewController
                                              {
                                                  return cocoon::internal::wrap<ViewController>((::NSViewController*)e);
                                              });
    }

    std::string PrintPanel::help_anchor() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPrintPanel>(this) helpAnchor]);
    }

    void PrintPanel::set_help_anchor(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPrintPanel>(this) setHelpAnchor:cocoon::internal::to(value)];
    }

    std::string PrintPanel::job_style_hint() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPrintPanel>(this) jobStyleHint]);
    }

    void PrintPanel::set_job_style_hint(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPrintPanel>(this) setJobStyleHint:cocoon::internal::to(value)];
    }

    PrintPanelOptions PrintPanel::options() const
    {
        return static_cast<PrintPanelOptions>([cocoon::internal::ns<::NSPrintPanel>(this) options]);
    }

    void PrintPanel::set_options(PrintPanelOptions value) const
    {
        [cocoon::internal::ns<::NSPrintPanel>(this) setOptions:static_cast<::NSPrintPanelOptions>(value)];
    }

    PrintInfo PrintPanel::print_info() const
    {
        return cocoon::internal::wrap<PrintInfo>([cocoon::internal::ns<::NSPrintPanel>(this) printInfo]);
    }
}
