#include "generated/split_view_item.h"
#include "internal.h"

namespace cocoon
{
    SplitViewItem::SplitViewItem(const ViewController& controller) : SplitViewItem(Adopt{cocoon::internal::retain([NSSplitViewItem splitViewItemWithViewController:cocoon::internal::native<NSViewController>(controller)])})
    {
    }

    SplitViewItem::SplitViewItem() : SplitViewItem(Adopt{cocoon::internal::retain([[::NSSplitViewItem alloc] init])})
    {
    }

    SplitViewItem::SplitViewItem(std::nullptr_t) : Object(nullptr)
    {
    }

    SplitViewItem::SplitViewItem(Adopt adopt) : Object(adopt)
    {
    }

    void SplitViewItem::add_bottom_aligned_accessory_view_controller(const SplitViewItemAccessoryViewController& child_view_controller) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) addBottomAlignedAccessoryViewController:cocoon::internal::native<::NSSplitViewItemAccessoryViewController>(child_view_controller)];
    }

    void SplitViewItem::add_top_aligned_accessory_view_controller(const SplitViewItemAccessoryViewController& child_view_controller) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) addTopAlignedAccessoryViewController:cocoon::internal::native<::NSSplitViewItemAccessoryViewController>(child_view_controller)];
    }

    SplitViewItem SplitViewItem::content_list_with_view_controller(const ViewController& view_controller)
    {
        return cocoon::internal::wrap<SplitViewItem>([::NSSplitViewItem contentListWithViewController:cocoon::internal::native<::NSViewController>(view_controller)]);
    }

    void SplitViewItem::insert_bottom_aligned_accessory_view_controller(const SplitViewItemAccessoryViewController& child_view_controller, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) insertBottomAlignedAccessoryViewController:cocoon::internal::native<::NSSplitViewItemAccessoryViewController>(child_view_controller) atIndex:static_cast<::NSInteger>(index)];
    }

    void SplitViewItem::insert_top_aligned_accessory_view_controller(const SplitViewItemAccessoryViewController& child_view_controller, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) insertTopAlignedAccessoryViewController:cocoon::internal::native<::NSSplitViewItemAccessoryViewController>(child_view_controller) atIndex:static_cast<::NSInteger>(index)];
    }

    SplitViewItem SplitViewItem::inspector_with_view_controller(const ViewController& view_controller)
    {
        return cocoon::internal::wrap<SplitViewItem>([::NSSplitViewItem inspectorWithViewController:cocoon::internal::native<::NSViewController>(view_controller)]);
    }

    void SplitViewItem::remove_bottom_aligned_accessory_view_controller_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) removeBottomAlignedAccessoryViewControllerAtIndex:static_cast<::NSInteger>(index)];
    }

    void SplitViewItem::remove_top_aligned_accessory_view_controller_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) removeTopAlignedAccessoryViewControllerAtIndex:static_cast<::NSInteger>(index)];
    }

    SplitViewItem SplitViewItem::sidebar_with_view_controller(const ViewController& view_controller)
    {
        return cocoon::internal::wrap<SplitViewItem>([::NSSplitViewItem sidebarWithViewController:cocoon::internal::native<::NSViewController>(view_controller)]);
    }

    SplitViewItem SplitViewItem::split_view_item_with_view_controller(const ViewController& view_controller)
    {
        return cocoon::internal::wrap<SplitViewItem>([::NSSplitViewItem splitViewItemWithViewController:cocoon::internal::native<::NSViewController>(view_controller)]);
    }

    bool SplitViewItem::allows_full_height_layout() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSplitViewItem>(this) allowsFullHeightLayout]);
    }

    void SplitViewItem::set_allows_full_height_layout(bool value) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) setAllowsFullHeightLayout:static_cast<::BOOL>(value)];
    }

    double SplitViewItem::automatic_maximum_thickness() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSplitViewItem>(this) automaticMaximumThickness]);
    }

    void SplitViewItem::set_automatic_maximum_thickness(double value) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) setAutomaticMaximumThickness:static_cast<::CGFloat>(value)];
    }

    bool SplitViewItem::automatically_adjusts_safe_area_insets() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSplitViewItem>(this) automaticallyAdjustsSafeAreaInsets]);
    }

    void SplitViewItem::set_automatically_adjusts_safe_area_insets(bool value) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) setAutomaticallyAdjustsSafeAreaInsets:static_cast<::BOOL>(value)];
    }

    SplitViewItemBehavior SplitViewItem::behavior() const
    {
        return static_cast<SplitViewItemBehavior>([cocoon::internal::ns<::NSSplitViewItem>(this) behavior]);
    }

    std::vector<SplitViewItemAccessoryViewController> SplitViewItem::bottom_aligned_accessory_view_controllers() const
    {
        return cocoon::internal::from_array<SplitViewItemAccessoryViewController>([cocoon::internal::ns<::NSSplitViewItem>(this) bottomAlignedAccessoryViewControllers], [](id e) -> SplitViewItemAccessoryViewController
                                                                    {
                                                                        return cocoon::internal::wrap<SplitViewItemAccessoryViewController>((::NSSplitViewItemAccessoryViewController*)e);
                                                                    });
    }

    void SplitViewItem::set_bottom_aligned_accessory_view_controllers(const std::vector<SplitViewItemAccessoryViewController>& value) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) setBottomAlignedAccessoryViewControllers:cocoon::internal::to_array(value, [](const SplitViewItemAccessoryViewController& e) -> id
                                                                                               {
                                                                                                   return cocoon::internal::native<::NSSplitViewItemAccessoryViewController>(e);
                                                                                               })];
    }

    bool SplitViewItem::can_collapse() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSplitViewItem>(this) canCollapse]);
    }

    void SplitViewItem::set_can_collapse(bool value) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) setCanCollapse:static_cast<::BOOL>(value)];
    }

    bool SplitViewItem::can_collapse_from_window_resize() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSplitViewItem>(this) canCollapseFromWindowResize]);
    }

    void SplitViewItem::set_can_collapse_from_window_resize(bool value) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) setCanCollapseFromWindowResize:static_cast<::BOOL>(value)];
    }

    SplitViewItemCollapseBehavior SplitViewItem::collapse_behavior() const
    {
        return static_cast<SplitViewItemCollapseBehavior>([cocoon::internal::ns<::NSSplitViewItem>(this) collapseBehavior]);
    }

    void SplitViewItem::set_collapse_behavior(SplitViewItemCollapseBehavior value) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) setCollapseBehavior:static_cast<::NSSplitViewItemCollapseBehavior>(value)];
    }

    bool SplitViewItem::is_collapsed() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSplitViewItem>(this) isCollapsed]);
    }

    void SplitViewItem::set_collapsed(bool value) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) setCollapsed:static_cast<::BOOL>(value)];
    }

    float SplitViewItem::holding_priority() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSSplitViewItem>(this) holdingPriority]);
    }

    void SplitViewItem::set_holding_priority(float value) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) setHoldingPriority:static_cast<::NSLayoutPriority>(value)];
    }

    double SplitViewItem::maximum_thickness() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSplitViewItem>(this) maximumThickness]);
    }

    void SplitViewItem::set_maximum_thickness(double value) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) setMaximumThickness:static_cast<::CGFloat>(value)];
    }

    double SplitViewItem::minimum_thickness() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSplitViewItem>(this) minimumThickness]);
    }

    void SplitViewItem::set_minimum_thickness(double value) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) setMinimumThickness:static_cast<::CGFloat>(value)];
    }

    double SplitViewItem::preferred_thickness_fraction() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSplitViewItem>(this) preferredThicknessFraction]);
    }

    void SplitViewItem::set_preferred_thickness_fraction(double value) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) setPreferredThicknessFraction:static_cast<::CGFloat>(value)];
    }

    bool SplitViewItem::is_spring_loaded() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSplitViewItem>(this) isSpringLoaded]);
    }

    void SplitViewItem::set_spring_loaded(bool value) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) setSpringLoaded:static_cast<::BOOL>(value)];
    }

    TitlebarSeparatorStyle SplitViewItem::titlebar_separator_style() const
    {
        return static_cast<TitlebarSeparatorStyle>([cocoon::internal::ns<::NSSplitViewItem>(this) titlebarSeparatorStyle]);
    }

    void SplitViewItem::set_titlebar_separator_style(TitlebarSeparatorStyle value) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) setTitlebarSeparatorStyle:static_cast<::NSTitlebarSeparatorStyle>(value)];
    }

    std::vector<SplitViewItemAccessoryViewController> SplitViewItem::top_aligned_accessory_view_controllers() const
    {
        return cocoon::internal::from_array<SplitViewItemAccessoryViewController>([cocoon::internal::ns<::NSSplitViewItem>(this) topAlignedAccessoryViewControllers], [](id e) -> SplitViewItemAccessoryViewController
                                                                    {
                                                                        return cocoon::internal::wrap<SplitViewItemAccessoryViewController>((::NSSplitViewItemAccessoryViewController*)e);
                                                                    });
    }

    void SplitViewItem::set_top_aligned_accessory_view_controllers(const std::vector<SplitViewItemAccessoryViewController>& value) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) setTopAlignedAccessoryViewControllers:cocoon::internal::to_array(value, [](const SplitViewItemAccessoryViewController& e) -> id
                                                                                            {
                                                                                                return cocoon::internal::native<::NSSplitViewItemAccessoryViewController>(e);
                                                                                            })];
    }

    ViewController SplitViewItem::view_controller() const
    {
        return cocoon::internal::wrap<ViewController>([cocoon::internal::ns<::NSSplitViewItem>(this) viewController]);
    }

    void SplitViewItem::set_view_controller(const ViewController& value) const
    {
        [cocoon::internal::ns<::NSSplitViewItem>(this) setViewController:cocoon::internal::native<::NSViewController>(value)];
    }

    SplitViewItem SplitViewItem::sidebar(const ViewController& controller)
    {
        return cocoon::internal::wrap<SplitViewItem>([NSSplitViewItem sidebarWithViewController:cocoon::internal::native<NSViewController>(controller)]);
    }

    SplitViewItem SplitViewItem::inspector(const ViewController& controller)
    {
        return cocoon::internal::wrap<SplitViewItem>([NSSplitViewItem inspectorWithViewController:cocoon::internal::native<NSViewController>(controller)]);
    }

    void SplitViewItem::set_collapsed_animated(bool collapsed) const
    {
        cocoon::internal::ns<NSSplitViewItem>(this).animator.collapsed = collapsed;
    }
}
