#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view_controller.h"
#include "types.h"

namespace cocoon
{
    class SplitView;
    class SplitViewItem;
    class View;
    class ViewController;

    /**
     * @brief A split view controller that supports sidebars, content and inspectors with Liquid Glass sidebars (NSSplitViewController).
     * @details NSSplitViewController is a container view controller that manages side-by-side (horizontal or vertical) children view controllers. Views are lazily loaded. For instance, adding a collapsed SplitViewItem will not load the associated ViewController's view until it is uncollapsed. The NSSplitViewController is set as the delegate of its managed NSSplitView. Any overrides of NSSplitViewDelegate methods must call super. Only the \\c -vertical, \\c -autosaveName, and divider properties should be manipulated on the managed NSSplitView. Changing other properties (such as delegate, manipulating subviews, holding priorities) will cause an exception to be thrown. Autolayout must be used with NSSplitViewController to properly control the layout of the child views and the animations of collapses and reveals. e.g., Constraints can be used to setup whether a window should grow/shrink or stay the same size when showing and hiding a sidebar. NSViewController's methods \\c -addChildViewController:, \\c -insertViewController:atIndex:, and \\c -removeChildViewControllerAtIndex: can all be used as convience methods to add children; default SplitViewItems will be appropriately created or destroyed.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ViewController.
     *
     * @par Example
     * @code
     * cocoon::SplitViewController split;
     * cocoon::SidebarList sidebar;
     * cocoon::VStack content;
     * split.add_sidebar(sidebar);
     * split.add_content(content);
     * cocoon::Window window("Split", {900, 600});
     * window.set_content(split);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SplitViewController split_view_controller{};
     * split_view_controller.set_minimum_thickness_for_inline_sidebars(1);
     * auto minimum_thickness_for_inline_sidebars = split_view_controller.minimum_thickness_for_inline_sidebars();
     * split_view_controller.set_split_view(cocoon::SplitView());
     * auto split_view = split_view_controller.split_view();
     * split_view_controller.add_split_view_item(cocoon::SplitViewItem());
     * split_view_controller.insert_split_view_item(cocoon::SplitViewItem(), 1);
     * split_view_controller.remove_split_view_item(cocoon::SplitViewItem());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssplitviewcontroller
     */
    class SplitViewController : public ViewController
    {
    public:
        /// @brief Creates a new `NSSplitViewController` instance and returns a handle to it.
        explicit SplitViewController();
        /// @brief Creates a null handle that refers to no native object.
        SplitViewController(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SplitViewController(Adopt adopt);
        using ViewController::view_did_load;
        /**
     * @brief Calls `-[NSSplitViewController addSplitViewItem:]`.
     * @details Adds a SplitViewItem to the end of the SplitViewController. If the receiver's view is loaded and the SplitViewItem is not collapsed, the SplitViewItem's viewController's view will be loaded and added to the splitView. This calls through to -insertSplitViewItem:atIndex:. \\param splitViewItem The SplitViewItem to add. It must have a viewController set by the time it is added or an exception will be thrown. An exception will also be thrown if splitViewItem is nil.
     * @param split_view_item Argument converted to the Objective-C parameter of the same role.
     */
        void add_split_view_item(const SplitViewItem& split_view_item) const;
        /**
     * @brief Calls `-[NSSplitViewController insertSplitViewItem:atIndex:]`.
     * @details Adds a SplitViewItem to a given index in the SplitViewController. If the receiver's view is loaded and the SplitViewItem is not collapsed, the SplitViewItem's viewController's view will be loaded and added to the \\c splitView. Subclasses must call through \\c -insertSplitViewItem:atIndex: to add a SplitViewItem. \\param splitViewItem The SplitViewItem to add. It must have a \\c viewController set by the time it is added or an exception will be thrown. An exception will also be thrown if splitViewItem is nil. \\param index The index to add the SplitViewItem at. Will throw an exception if \\c index \< 0 or \\c index > \\c splitViewItems.count
     * @param split_view_item Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_split_view_item(const SplitViewItem& split_view_item, std::int64_t index) const;
        /**
     * @brief Calls `-[NSSplitViewController removeSplitViewItem:]`.
     * @details Removes a SplitViewItem from the receiver. The layout of the \\c splitView will be adjusted for its removal. Subclasses must call through \\c -removeSplitViewItem: to remove a SplitViewItem. \\param splitViewItem The SplitViewItem to remove. An exception will be thrown if \\c splitViewItem is not in the SplitViewController or if it is nil.
     * @param split_view_item Argument converted to the Objective-C parameter of the same role.
     */
        void remove_split_view_item(const SplitViewItem& split_view_item) const;
        /**
     * @brief Calls `-[NSSplitViewController splitView:additionalEffectiveRectOfDividerAtIndex:]`.
     * @param split_view Argument converted to the Objective-C parameter of the same role.
     * @param divider_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect split_view(const SplitView& split_view, std::int64_t divider_index) const;
        /**
     * @brief Calls `-[NSSplitViewController splitView:canCollapseSubview:]`.
     * @details Implemented methods from NSSplitViewDelegate. These require a call to super if overriden by a subclass
     * @param split_view Argument converted to the Objective-C parameter of the same role.
     * @param subview Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool split_view(const SplitView& split_view, const View& subview) const;
        /**
     * @brief Calls `-[NSSplitViewController splitView:effectiveRect:forDrawnRect:ofDividerAtIndex:]`.
     * @param split_view Argument converted to the Objective-C parameter of the same role.
     * @param proposed_effective_rect Argument converted to the Objective-C parameter of the same role.
     * @param drawn_rect Argument converted to the Objective-C parameter of the same role.
     * @param divider_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect split_view(const SplitView& split_view, const Rect& proposed_effective_rect, const Rect& drawn_rect, std::int64_t divider_index) const;
        /**
     * @brief Calls `-[NSSplitViewController splitViewItemForViewController:]`.
     * @details Returns the corresponding SplitViewItem for a given child ViewController. \\param viewController The ViewController to look up. \\return The corresponding SplitViewItem. Returns nil if \\c viewController is not a child of the SplitViewController.
     * @param view_controller Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        SplitViewItem split_view_item_for_view_controller(const ViewController& view_controller) const;
        /**
     * @brief Calls `-[NSSplitViewController toggleInspector:]`.
     * @details Collapses or expands the first inspector in the split view controller using an animation. If the split view controller doesn't contain an inspector, calling this method does nothing.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void toggle_inspector(const Object& sender) const;
        /**
     * @brief Calls `-[NSSplitViewController toggleSidebar:]`.
     * @details Collapses or expands the first sidebar in the split view controller using an animation. If the split view controller doesn't contain a sidebar, calling this method does nothing.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void toggle_sidebar(const Object& sender) const;
        /**
     * @brief Calls `-[NSSplitViewController validateUserInterfaceItem:]`.
     * @details Validates items with an action of 'toggleSidebar:' to reflect the status of the sidebar item contained within the receiver.
     * @param item Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool validate_user_interface_item(const Object& item) const;
        /**
     * @brief Calls `-[NSSplitViewController viewDidLoad]`.
     * @details Overridden methods from NSViewController. These require a call to super if overriden by a subclass
     */
        void view_did_load() const;
        /**
     * @brief Returns the `minimumThicknessForInlineSidebars` property of `NSSplitViewController`.
     * @details The minimum thickness in the primary axis of split view (width for "vertical", height otherwise) before sidebar items will automatically collapse. If reshown in fullscreen, they will overlay over the other split items. Auto-collapsed sidebars will automatically uncollapse if the thickness is increased back to or past the minimum thickness. Defaults to \\c NSSplitViewControllerAutomaticDimension, which will use the effective minimum sizes of the split view item views as described by constraints in the window to determine the minimum size for inline sidebars. Once constraints establishing the minimum size can't be satisfied for all non-collapsed split panes, all sidebars will auto-collapse. When fullscreen, if a sidebar tries to uncollapse in this state, it will overlay.
     * @return The converted Objective-C result.
     */
        double minimum_thickness_for_inline_sidebars() const;
        /**
     * @brief Sets the `minimumThicknessForInlineSidebars` property of `NSSplitViewController`.
     * @details The minimum thickness in the primary axis of split view (width for "vertical", height otherwise) before sidebar items will automatically collapse. If reshown in fullscreen, they will overlay over the other split items. Auto-collapsed sidebars will automatically uncollapse if the thickness is increased back to or past the minimum thickness. Defaults to \\c NSSplitViewControllerAutomaticDimension, which will use the effective minimum sizes of the split view item views as described by constraints in the window to determine the minimum size for inline sidebars. Once constraints establishing the minimum size can't be satisfied for all non-collapsed split panes, all sidebars will auto-collapse. When fullscreen, if a sidebar tries to uncollapse in this state, it will overlay.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_thickness_for_inline_sidebars(double value) const;
        /**
     * @brief Returns the `splitView` property of `NSSplitViewController`.
     * @details The split view managed by the SplitViewController. This can be used to customize view properties such as the dividerStyle, vertical, and autosaveName. It is not guaranteed to be the same view as the receivers 'view' property. The default created splitView is vertical with a dividerStyle of \\c NSSplitViewDividerStyleThin. To provide a custom NSSplitView, set the splitView property anytime before self.viewLoaded is YES.
     * @return The converted Objective-C result.
     */
        SplitView split_view() const;
        /**
     * @brief Sets the `splitView` property of `NSSplitViewController`.
     * @details The split view managed by the SplitViewController. This can be used to customize view properties such as the dividerStyle, vertical, and autosaveName. It is not guaranteed to be the same view as the receivers 'view' property. The default created splitView is vertical with a dividerStyle of \\c NSSplitViewDividerStyleThin. To provide a custom NSSplitView, set the splitView property anytime before self.viewLoaded is YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_split_view(const SplitView& value) const;
        /**
     * @brief Returns the `splitViewItems` property of `NSSplitViewController`.
     * @details The array of SplitViewItems that correspond to the current child view controllers. After a child view controller is added to the receiving splitViewController, a NSSplitViewItem with the default values will be created for it. Once the child is removed, its corresponding splitViewItem will be removed from the splitViewItems array. Setting this will call through to \\c -insertSplitViewItem:atIndex and \\c -removeSplitViewItem: for items that are new or need removal.
     * @return The converted Objective-C result.
     */
        std::vector<SplitViewItem> split_view_items() const;
        /**
     * @brief Sets the `splitViewItems` property of `NSSplitViewController`.
     * @details The array of SplitViewItems that correspond to the current child view controllers. After a child view controller is added to the receiving splitViewController, a NSSplitViewItem with the default values will be created for it. Once the child is removed, its corresponding splitViewItem will be removed from the splitViewItems array. Setting this will call through to \\c -insertSplitViewItem:atIndex and \\c -removeSplitViewItem: for items that are new or need removal.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_split_view_items(const std::vector<SplitViewItem>& value) const;
        /// @brief Convenience helper `add_sidebar` provided by cocoon.
        SplitViewItem add_sidebar(const ViewController& controller, double minimum_width = 200, double maximum_width = 320) const;
        /// @brief Convenience helper `add_content` provided by cocoon.
        SplitViewItem add_content(const ViewController& controller, double minimum_width = 300) const;
        /// @brief Convenience helper `add_inspector` provided by cocoon.
        SplitViewItem add_inspector(const ViewController& controller, double minimum_width = 240, double maximum_width = 400) const;
    };
}
