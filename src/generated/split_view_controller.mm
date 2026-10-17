#include "generated/split_view_controller.h"
#include "internal.h"

namespace cocoon
{
    SplitViewController::SplitViewController() : SplitViewController(Adopt{cocoon::internal::retain(cocoon::internal::make_split_view_controller())})
    {
    }

    SplitViewController::SplitViewController(std::nullptr_t) : ViewController(nullptr)
    {
    }

    SplitViewController::SplitViewController(Adopt adopt) : ViewController(adopt)
    {
    }

    void SplitViewController::add_split_view_item(const SplitViewItem& split_view_item) const
    {
        [cocoon::internal::ns<::NSSplitViewController>(this) addSplitViewItem:cocoon::internal::native<::NSSplitViewItem>(split_view_item)];
    }

    void SplitViewController::insert_split_view_item(const SplitViewItem& split_view_item, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSSplitViewController>(this) insertSplitViewItem:cocoon::internal::native<::NSSplitViewItem>(split_view_item) atIndex:static_cast<::NSInteger>(index)];
    }

    void SplitViewController::remove_split_view_item(const SplitViewItem& split_view_item) const
    {
        [cocoon::internal::ns<::NSSplitViewController>(this) removeSplitViewItem:cocoon::internal::native<::NSSplitViewItem>(split_view_item)];
    }

    Rect SplitViewController::split_view(const SplitView& split_view, std::int64_t divider_index) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSplitViewController>(this) splitView:cocoon::internal::native<::NSSplitView>(split_view) additionalEffectiveRectOfDividerAtIndex:static_cast<::NSInteger>(divider_index)]);
    }

    bool SplitViewController::split_view(const SplitView& split_view, const View& subview) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSplitViewController>(this) splitView:cocoon::internal::native<::NSSplitView>(split_view) canCollapseSubview:cocoon::internal::native<::NSView>(subview)]);
    }

    Rect SplitViewController::split_view(const SplitView& split_view, const Rect& proposed_effective_rect, const Rect& drawn_rect, std::int64_t divider_index) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSplitViewController>(this) splitView:cocoon::internal::native<::NSSplitView>(split_view) effectiveRect:cocoon::internal::to(proposed_effective_rect) forDrawnRect:cocoon::internal::to(drawn_rect) ofDividerAtIndex:static_cast<::NSInteger>(divider_index)]);
    }

    SplitViewItem SplitViewController::split_view_item_for_view_controller(const ViewController& view_controller) const
    {
        return cocoon::internal::wrap<SplitViewItem>([cocoon::internal::ns<::NSSplitViewController>(this) splitViewItemForViewController:cocoon::internal::native<::NSViewController>(view_controller)]);
    }

    void SplitViewController::toggle_inspector(const Object& sender) const
    {
        [cocoon::internal::ns<::NSSplitViewController>(this) toggleInspector:cocoon::internal::native_id(sender)];
    }

    void SplitViewController::toggle_sidebar(const Object& sender) const
    {
        [cocoon::internal::ns<::NSSplitViewController>(this) toggleSidebar:cocoon::internal::native_id(sender)];
    }

    bool SplitViewController::validate_user_interface_item(const Object& item) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSplitViewController>(this) validateUserInterfaceItem:cocoon::internal::native_id(item)]);
    }

    void SplitViewController::view_did_load() const
    {
        [cocoon::internal::ns<::NSSplitViewController>(this) viewDidLoad];
    }

    double SplitViewController::minimum_thickness_for_inline_sidebars() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSplitViewController>(this) minimumThicknessForInlineSidebars]);
    }

    void SplitViewController::set_minimum_thickness_for_inline_sidebars(double value) const
    {
        [cocoon::internal::ns<::NSSplitViewController>(this) setMinimumThicknessForInlineSidebars:static_cast<::CGFloat>(value)];
    }

    SplitView SplitViewController::split_view() const
    {
        return cocoon::internal::wrap<SplitView>([cocoon::internal::ns<::NSSplitViewController>(this) splitView]);
    }

    void SplitViewController::set_split_view(const SplitView& value) const
    {
        [cocoon::internal::ns<::NSSplitViewController>(this) setSplitView:cocoon::internal::native<::NSSplitView>(value)];
    }

    std::vector<SplitViewItem> SplitViewController::split_view_items() const
    {
        return cocoon::internal::from_array<SplitViewItem>([cocoon::internal::ns<::NSSplitViewController>(this) splitViewItems], [](id e) -> SplitViewItem
                                                           {
                                                               return cocoon::internal::wrap<SplitViewItem>((::NSSplitViewItem*)e);
                                                           });
    }

    void SplitViewController::set_split_view_items(const std::vector<SplitViewItem>& value) const
    {
        [cocoon::internal::ns<::NSSplitViewController>(this) setSplitViewItems:cocoon::internal::to_array(value, [](const SplitViewItem& e) -> id
                                                                                                          {
                                                                                                              return cocoon::internal::native<::NSSplitViewItem>(e);
                                                                                                          })];
    }

    SplitViewItem SplitViewController::add_sidebar(const ViewController& controller, double minimum_width, double maximum_width) const
    {
        SplitViewItem item = SplitViewItem::sidebar(controller);
        item.set_minimum_thickness(minimum_width);
        item.set_maximum_thickness(maximum_width);
        add_split_view_item(item);
        return item;
    }

    SplitViewItem SplitViewController::add_content(const ViewController& controller, double minimum_width) const
    {
        SplitViewItem item(controller);
        item.set_minimum_thickness(minimum_width);
        add_split_view_item(item);
        return item;
    }

    SplitViewItem SplitViewController::add_inspector(const ViewController& controller, double minimum_width, double maximum_width) const
    {
        SplitViewItem item = SplitViewItem::inspector(controller);
        item.set_minimum_thickness(minimum_width);
        item.set_maximum_thickness(maximum_width);
        add_split_view_item(item);
        return item;
    }
}
