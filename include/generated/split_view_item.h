#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class SplitViewItemAccessoryViewController;
    class ViewController;

    /**
     * @brief One pane of a SplitViewController.
     * @details NSSplitViewItem implements the items used in an NSSplitViewController. The item describes a child ViewController's state in a SplitViewController, e.g. its collapsibility, holding priority and other metrics, and collapsed state.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * cocoon::SplitViewController split;
     * cocoon::View content;
     * cocoon::SplitViewItem item = split.add_content(content);
     * item.set_minimum_thickness(300);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SplitViewItem split_view_item{};
     * split_view_item.set_allows_full_height_layout(true);
     * auto allows_full_height_layout = split_view_item.allows_full_height_layout();
     * split_view_item.set_automatic_maximum_thickness(1);
     * auto automatic_maximum_thickness = split_view_item.automatic_maximum_thickness();
     * split_view_item.set_automatically_adjusts_safe_area_insets(true);
     * auto automatically_adjusts_safe_area_insets = split_view_item.automatically_adjusts_safe_area_insets();
     * auto made_0 = cocoon::SplitViewItem::content_list_with_view_controller(cocoon::ViewController());
     * auto made_1 = cocoon::SplitViewItem::inspector_with_view_controller(cocoon::ViewController());
     * split_view_item.add_bottom_aligned_accessory_view_controller(cocoon::SplitViewItemAccessoryViewController());
     * split_view_item.add_top_aligned_accessory_view_controller(cocoon::SplitViewItemAccessoryViewController());
     * split_view_item.insert_bottom_aligned_accessory_view_controller(cocoon::SplitViewItemAccessoryViewController(), 1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssplitviewitem
     */
    class SplitViewItem : public Object
    {
    public:
        /// @brief Creates a new `NSSplitViewItem` instance and returns a handle to it.
        explicit SplitViewItem(const ViewController& controller);
        /// @brief Creates a new `NSSplitViewItem` instance and returns a handle to it.
        explicit SplitViewItem();
        /// @brief Creates a null handle that refers to no native object.
        SplitViewItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SplitViewItem(Adopt adopt);
        /**
     * @brief Calls `-[NSSplitViewItem addBottomAlignedAccessoryViewController:]`.
     * @param child_view_controller Argument converted to the Objective-C parameter of the same role.
     */
        void add_bottom_aligned_accessory_view_controller(const SplitViewItemAccessoryViewController& child_view_controller) const;
        /**
     * @brief Calls `-[NSSplitViewItem addTopAlignedAccessoryViewController:]`.
     * @param child_view_controller Argument converted to the Objective-C parameter of the same role.
     */
        void add_top_aligned_accessory_view_controller(const SplitViewItemAccessoryViewController& child_view_controller) const;
        /**
     * @brief Calls `+[NSSplitViewItem contentListWithViewController:]`.
     * @details Creates a split view item representing a content list for the provided ViewController, akin to Mail's message list, Note's note list. Content lists have system standard defaults, specifically: - minimumThickness and maximumThickness are set to the system standard for content lists - automaticMaximumThickness is set to the system standard for content lists - preferredThicknessFraction is set to the standard fraction for content lists (0.28 when a neighbor sidebar is visible, 0.33 if not) \\param viewController The view controller used to set the viewController property \\return An autoreleased SplitViewItem that acts as a content list.
     * @param view_controller Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static SplitViewItem content_list_with_view_controller(const ViewController& view_controller);
        /**
     * @brief Calls `-[NSSplitViewItem insertBottomAlignedAccessoryViewController:atIndex:]`.
     * @param child_view_controller Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_bottom_aligned_accessory_view_controller(const SplitViewItemAccessoryViewController& child_view_controller, std::int64_t index) const;
        /**
     * @brief Calls `-[NSSplitViewItem insertTopAlignedAccessoryViewController:atIndex:]`.
     * @param child_view_controller Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_top_aligned_accessory_view_controller(const SplitViewItemAccessoryViewController& child_view_controller, std::int64_t index) const;
        /**
     * @brief Calls `+[NSSplitViewItem inspectorWithViewController:]`.
     * @details Creates a split view item representing an inspector for the provided ViewController. On macOS 14.0 and above inspectors have the following standard system behavior: - canCollapse is set to YES - minimumThickness and maximumThickness are set to the standard inspector size (270) and are not resizable by default \\param viewController The view controller used to set the viewController property \\return An autoreleased SplitViewItem that acts as an inspector.
     * @param view_controller Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static SplitViewItem inspector_with_view_controller(const ViewController& view_controller);
        /**
     * @brief Calls `-[NSSplitViewItem removeBottomAlignedAccessoryViewControllerAtIndex:]`.
     * @details NOTE: you can use this method, or '-removeFromParentViewController:', whichever is easier.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void remove_bottom_aligned_accessory_view_controller_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSSplitViewItem removeTopAlignedAccessoryViewControllerAtIndex:]`.
     * @details NOTE: you can use this method, or '-removeFromParentViewController:', whichever is easier.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void remove_top_aligned_accessory_view_controller_at_index(std::int64_t index) const;
        /**
     * @brief Calls `+[NSSplitViewItem sidebarWithViewController:]`.
     * @details Creates a split view item representing a sidebar for the provided ViewController. Sidebars have standard system behavior, specifically: - Translucent material background - The ability to collapse/uncollapse on split view size changes - The ability to overlay at small split view sizes when in fullscreen - canCollapse is set to YES - minimumThickness and maximumThickness are set to the standard minimum and maximum sidebar size - preferredThicknessFraction is set to the standard fraction for sidebars (0.15) - springLoaded is set to YES \\param viewController The view controller used to set the viewController property \\return An autoreleased SplitViewItem that acts as a sidebar.
     * @param view_controller Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static SplitViewItem sidebar_with_view_controller(const ViewController& view_controller);
        /**
     * @brief Calls `+[NSSplitViewItem splitViewItemWithViewController:]`.
     * @details Creates an autoreleased SplitViewItem that represents the provided ViewController. All other properties are left at their default. \\param viewController The view controller used to set the viewController property \\return An autoreleased SplitViewItem.
     * @param view_controller Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static SplitViewItem split_view_item_with_view_controller(const ViewController& view_controller);
        /**
     * @brief Returns the `allowsFullHeightLayout` property of `NSSplitViewItem`.
     * @details Whether or not a sidebar or inspector is allowed to be full height in the window when the 'NSFullSizeContentViewWindowMask' style mask is also set. Only applies to NSSplitViewItemBehaviorSidebar and NSSplitViewItemBehaviorInspector. Defaults to YES.
     * @return The converted Objective-C result.
     */
        bool allows_full_height_layout() const;
        /**
     * @brief Sets the `allowsFullHeightLayout` property of `NSSplitViewItem`.
     * @details Whether or not a sidebar or inspector is allowed to be full height in the window when the 'NSFullSizeContentViewWindowMask' style mask is also set. Only applies to NSSplitViewItemBehaviorSidebar and NSSplitViewItemBehaviorInspector. Defaults to YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_full_height_layout(bool value) const;
        /**
     * @brief Returns the `automaticMaximumThickness` property of `NSSplitViewItem`.
     * @details The maximum thickness of the split view item when resizing due to automatic sizing, such as entering fullscreen with a set preferredThicknessFraction or proportional sizing. The user can still resize up to the absolute maximum size by dragging the divider or otherwise. If NSSplitViewItemUnspecifiedDimension, no automatic maximum is enforced. Defaults to NSSplitViewItemUnspecifiedDimension.
     * @return The converted Objective-C result.
     */
        double automatic_maximum_thickness() const;
        /**
     * @brief Sets the `automaticMaximumThickness` property of `NSSplitViewItem`.
     * @details The maximum thickness of the split view item when resizing due to automatic sizing, such as entering fullscreen with a set preferredThicknessFraction or proportional sizing. The user can still resize up to the absolute maximum size by dragging the divider or otherwise. If NSSplitViewItemUnspecifiedDimension, no automatic maximum is enforced. Defaults to NSSplitViewItemUnspecifiedDimension.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_automatic_maximum_thickness(double value) const;
        /**
     * @brief Returns the `automaticallyAdjustsSafeAreaInsets` property of `NSSplitViewItem`.
     * @details When YES, other items such as sidebars or inspectors may appear overlaid on top of this item's 'viewController' and this item's 'safeAreaInsets' will be adjusted with respect to overlaid content. Defaults to 'NO'.
     * @return The converted Objective-C result.
     */
        bool automatically_adjusts_safe_area_insets() const;
        /**
     * @brief Sets the `automaticallyAdjustsSafeAreaInsets` property of `NSSplitViewItem`.
     * @details When YES, other items such as sidebars or inspectors may appear overlaid on top of this item's 'viewController' and this item's 'safeAreaInsets' will be adjusted with respect to overlaid content. Defaults to 'NO'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_automatically_adjusts_safe_area_insets(bool value) const;
        /**
     * @brief Returns the `behavior` property of `NSSplitViewItem`.
     * @details The standard behavior type of the receiver. See initializers for descriptions of each behavior.
     * @return The converted Objective-C result.
     */
        SplitViewItemBehavior behavior() const;
        /**
     * @brief Returns the `bottomAlignedAccessoryViewControllers` property of `NSSplitViewItem`.
     * @return The converted Objective-C result.
     */
        std::vector<SplitViewItemAccessoryViewController> bottom_aligned_accessory_view_controllers() const;
        /**
     * @brief Sets the `bottomAlignedAccessoryViewControllers` property of `NSSplitViewItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bottom_aligned_accessory_view_controllers(const std::vector<SplitViewItemAccessoryViewController>& value) const;
        /**
     * @brief Returns the `canCollapse` property of `NSSplitViewItem`.
     * @details Whether or not the child view controller is collapsible from user interaction - whether by dragging or double clicking a divider. The default is \\c NO.
     * @return The converted Objective-C result.
     */
        bool can_collapse() const;
        /**
     * @brief Sets the `canCollapse` property of `NSSplitViewItem`.
     * @details Whether or not the child view controller is collapsible from user interaction - whether by dragging or double clicking a divider. The default is \\c NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_can_collapse(bool value) const;
        /**
     * @brief Returns the `canCollapseFromWindowResize` property of `NSSplitViewItem`.
     * @details If YES, the item can be collapsed from a window resize. This can differ from 'canCollapse', to allow divider collapsing but not window resize collapsing or vice versa. Defaults to YES for Sidebars and NO for Inspectors. - Note: Setting 'canCollapse' for sidebars will reset this value to that new value.
     * @return The converted Objective-C result.
     */
        bool can_collapse_from_window_resize() const;
        /**
     * @brief Sets the `canCollapseFromWindowResize` property of `NSSplitViewItem`.
     * @details If YES, the item can be collapsed from a window resize. This can differ from 'canCollapse', to allow divider collapsing but not window resize collapsing or vice versa. Defaults to YES for Sidebars and NO for Inspectors. - Note: Setting 'canCollapse' for sidebars will reset this value to that new value.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_can_collapse_from_window_resize(bool value) const;
        /**
     * @brief Returns the `collapseBehavior` property of `NSSplitViewItem`.
     * @details The resize behavior when the receiver toggles its 'collapsed' state programmatically, both animatedly and not. Defaults to '.Default'.
     * @return The converted Objective-C result.
     */
        SplitViewItemCollapseBehavior collapse_behavior() const;
        /**
     * @brief Sets the `collapseBehavior` property of `NSSplitViewItem`.
     * @details The resize behavior when the receiver toggles its 'collapsed' state programmatically, both animatedly and not. Defaults to '.Default'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_collapse_behavior(SplitViewItemCollapseBehavior value) const;
        /**
     * @brief Returns the `collapsed` property of `NSSplitViewItem`.
     * @details Whether or not the child ViewController corresponding to the SplitViewItem is collapsed in the SplitViewController. The default is \\c NO. This can be set with the animator proxy to animate the collapse or uncollapse. The exact animation used can be customized by setting it in the -animations dictionary with a key of "collapsed". If this is set to YES before it is added to the SplitViewController, it will be initially collapsed and the SplitViewController will not cause the view to be loaded until it is uncollapsed. This is KVC/KVO compliant and will be updated if the value changes from user interaction.
     * @return The converted Objective-C result.
     */
        bool is_collapsed() const;
        /**
     * @brief Sets the `collapsed` property of `NSSplitViewItem`.
     * @details Whether or not the child ViewController corresponding to the SplitViewItem is collapsed in the SplitViewController. The default is \\c NO. This can be set with the animator proxy to animate the collapse or uncollapse. The exact animation used can be customized by setting it in the -animations dictionary with a key of "collapsed". If this is set to YES before it is added to the SplitViewController, it will be initially collapsed and the SplitViewController will not cause the view to be loaded until it is uncollapsed. This is KVC/KVO compliant and will be updated if the value changes from user interaction.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_collapsed(bool value) const;
        /**
     * @brief Returns the `holdingPriority` property of `NSSplitViewItem`.
     * @details Sets the priority under which a SplitViewItem will hold its width (for a vertical split view) or height (for a horizontal split view). The view with the lowest priority will be the first to take on additional width if the split view grows or shrinks. The default is \\c NSLayoutPriorityDefaultLow.
     * @return The converted Objective-C result.
     */
        float holding_priority() const;
        /**
     * @brief Sets the `holdingPriority` property of `NSSplitViewItem`.
     * @details Sets the priority under which a SplitViewItem will hold its width (for a vertical split view) or height (for a horizontal split view). The view with the lowest priority will be the first to take on additional width if the split view grows or shrinks. The default is \\c NSLayoutPriorityDefaultLow.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_holding_priority(float value) const;
        /**
     * @brief Returns the `maximumThickness` property of `NSSplitViewItem`.
     * @details A convenience to set the maximum thickness of the split view item -- width for "vertical" split views, height otherwise. If NSSplitViewItemUnspecifiedDimension, no maximum size is enforced by the SplitViewItem, although constraints in the contained view hierarchy might have constraints specify some maximum size on their own. Defaults to NSSplitViewItemUnspecifiedDimension.
     * @return The converted Objective-C result.
     */
        double maximum_thickness() const;
        /**
     * @brief Sets the `maximumThickness` property of `NSSplitViewItem`.
     * @details A convenience to set the maximum thickness of the split view item -- width for "vertical" split views, height otherwise. If NSSplitViewItemUnspecifiedDimension, no maximum size is enforced by the SplitViewItem, although constraints in the contained view hierarchy might have constraints specify some maximum size on their own. Defaults to NSSplitViewItemUnspecifiedDimension.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_thickness(double value) const;
        /**
     * @brief Returns the `minimumThickness` property of `NSSplitViewItem`.
     * @details A convenience to set the minimum thickness of the split view item -- width for "vertical" split views, height otherwise. If NSSplitViewItemUnspecifiedDimension, no minimum size is enforced by the SplitViewItem, although constraints in the contained view hierarchy might have constraints specify some minimum size on their own. Defaults to NSSplitViewItemUnspecifiedDimension.
     * @return The converted Objective-C result.
     */
        double minimum_thickness() const;
        /**
     * @brief Sets the `minimumThickness` property of `NSSplitViewItem`.
     * @details A convenience to set the minimum thickness of the split view item -- width for "vertical" split views, height otherwise. If NSSplitViewItemUnspecifiedDimension, no minimum size is enforced by the SplitViewItem, although constraints in the contained view hierarchy might have constraints specify some minimum size on their own. Defaults to NSSplitViewItemUnspecifiedDimension.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_thickness(double value) const;
        /**
     * @brief Returns the `preferredThicknessFraction` property of `NSSplitViewItem`.
     * @details The percentage of the contained NSSplitView that the NSSplitViewItem prefers to encompass. This is used when double-clicking on a neighbor divider to return to that standard ratio. As well as after entering fullscreen to determine the initial size of the receiver. Defaults to NSSplitViewItemUnspecifiedDimension, which means no resize will occur on double-clicks, and the absolute size is preserved when entering fullscreen.
     * @return The converted Objective-C result.
     */
        double preferred_thickness_fraction() const;
        /**
     * @brief Sets the `preferredThicknessFraction` property of `NSSplitViewItem`.
     * @details The percentage of the contained NSSplitView that the NSSplitViewItem prefers to encompass. This is used when double-clicking on a neighbor divider to return to that standard ratio. As well as after entering fullscreen to determine the initial size of the receiver. Defaults to NSSplitViewItemUnspecifiedDimension, which means no resize will occur on double-clicks, and the absolute size is preserved when entering fullscreen.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preferred_thickness_fraction(double value) const;
        /**
     * @brief Returns the `springLoaded` property of `NSSplitViewItem`.
     * @details If YES, the split view item can be temporarily uncollapsed during a drag by hovering or deep clicking on its neighboring divider. Defaults to NO.
     * @return The converted Objective-C result.
     */
        bool is_spring_loaded() const;
        /**
     * @brief Sets the `springLoaded` property of `NSSplitViewItem`.
     * @details If YES, the split view item can be temporarily uncollapsed during a drag by hovering or deep clicking on its neighboring divider. Defaults to NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_spring_loaded(bool value) const;
        /**
     * @brief Returns the `titlebarSeparatorStyle` property of `NSSplitViewItem`.
     * @details Specifies a preference for the style of separator displayed between the titlebar and the content of the split view item. For this value to be applicable, the item's view must be associated with its own titlebar section (see 'NSTrackingSeparatorToolbarItem' for more info). The default value is NSTitlebarSeparatorStyleAutomatic. This value is subject to the containing window's preference and can be overridden.
     * @return The converted Objective-C result.
     */
        TitlebarSeparatorStyle titlebar_separator_style() const;
        /**
     * @brief Sets the `titlebarSeparatorStyle` property of `NSSplitViewItem`.
     * @details Specifies a preference for the style of separator displayed between the titlebar and the content of the split view item. For this value to be applicable, the item's view must be associated with its own titlebar section (see 'NSTrackingSeparatorToolbarItem' for more info). The default value is NSTitlebarSeparatorStyleAutomatic. This value is subject to the containing window's preference and can be overridden.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_titlebar_separator_style(TitlebarSeparatorStyle value) const;
        /**
     * @brief Returns the `topAlignedAccessoryViewControllers` property of `NSSplitViewItem`.
     * @details The following methods allow you to add accessory views to the top/bottom of this splitViewItem. See 'NSSplitViewItemAccessoryViewController' for more details.
     * @return The converted Objective-C result.
     */
        std::vector<SplitViewItemAccessoryViewController> top_aligned_accessory_view_controllers() const;
        /**
     * @brief Sets the `topAlignedAccessoryViewControllers` property of `NSSplitViewItem`.
     * @details The following methods allow you to add accessory views to the top/bottom of this splitViewItem. See 'NSSplitViewItemAccessoryViewController' for more details.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_top_aligned_accessory_view_controllers(const std::vector<SplitViewItemAccessoryViewController>& value) const;
        /**
     * @brief Returns the `viewController` property of `NSSplitViewItem`.
     * @details The view controller represented by the SplitViewItem. An exception will be thrown if a new viewController is set while the receiving SplitViewItem is added to a SplitViewController.
     * @return The converted Objective-C result.
     */
        ViewController view_controller() const;
        /**
     * @brief Sets the `viewController` property of `NSSplitViewItem`.
     * @details The view controller represented by the SplitViewItem. An exception will be thrown if a new viewController is set while the receiving SplitViewItem is added to a SplitViewController.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_view_controller(const ViewController& value) const;
        /// @brief Convenience helper `sidebar` provided by cocoon.
        static SplitViewItem sidebar(const ViewController& controller);
        /// @brief Convenience helper `inspector` provided by cocoon.
        static SplitViewItem inspector(const ViewController& controller);
        /// @brief Convenience helper `set_collapsed_animated` provided by cocoon.
        void set_collapsed_animated(bool collapsed) const;
    };
}
