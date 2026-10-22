#include "generated/page_layout.h"
#include "internal.h"

namespace cocoon
{
    PageLayout::PageLayout() : PageLayout(Adopt{cocoon::internal::retain([::NSPageLayout pageLayout])})
    {
    }

    PageLayout::PageLayout(std::nullptr_t) : Object(nullptr)
    {
    }

    PageLayout::PageLayout(Adopt adopt) : Object(adopt)
    {
    }

    void PageLayout::add_accessory_controller(const ViewController& accessory_controller) const
    {
        [cocoon::internal::ns<::NSPageLayout>(this) addAccessoryController:cocoon::internal::native<::NSViewController>(accessory_controller)];
    }

    void PageLayout::begin_sheet_using_print_info(const PrintInfo& print_info, const Window& parent_window, std::function<void(PageLayoutResult)> handler) const
    {
        [cocoon::internal::ns<::NSPageLayout>(this) beginSheetUsingPrintInfo:cocoon::internal::native<::NSPrintInfo>(print_info) onWindow:cocoon::internal::native<::NSWindow>(parent_window) completionHandler:(handler ? (void (^)(::NSPageLayoutResult)) ^ void(::NSPageLayoutResult a66_0) { handler(static_cast<PageLayoutResult>(a66_0)); } : (void (^)(::NSPageLayoutResult))nil)];
    }

    void PageLayout::begin_sheet_with_print_info(const PrintInfo& print_info, const Window& doc_window, const Object& delegate, const std::string& did_end_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSPageLayout>(this) beginSheetWithPrintInfo:cocoon::internal::native<::NSPrintInfo>(print_info) modalForWindow:cocoon::internal::native<::NSWindow>(doc_window) delegate:cocoon::internal::native_id(delegate) didEndSelector:NSSelectorFromString(cocoon::internal::to(did_end_selector)) contextInfo:context_info];
    }

    void PageLayout::remove_accessory_controller(const ViewController& accessory_controller) const
    {
        [cocoon::internal::ns<::NSPageLayout>(this) removeAccessoryController:cocoon::internal::native<::NSViewController>(accessory_controller)];
    }

    std::int64_t PageLayout::run_modal() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPageLayout>(this) runModal]);
    }

    std::int64_t PageLayout::run_modal_with_print_info(const PrintInfo& print_info) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPageLayout>(this) runModalWithPrintInfo:cocoon::internal::native<::NSPrintInfo>(print_info)]);
    }

    std::vector<ViewController> PageLayout::accessory_controllers() const
    {
        return cocoon::internal::from_array<ViewController>([cocoon::internal::ns<::NSPageLayout>(this) accessoryControllers], [](id e) -> ViewController
                                                            {
                                                                return cocoon::internal::wrap<ViewController>((::NSViewController*)e);
                                                            });
    }

    PrintInfo PageLayout::print_info() const
    {
        return cocoon::internal::wrap<PrintInfo>([cocoon::internal::ns<::NSPageLayout>(this) printInfo]);
    }
}
