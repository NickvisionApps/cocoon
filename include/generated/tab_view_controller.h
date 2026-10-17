#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view_controller.h"
#include "types.h"

namespace cocoon
{
    class TabView;
    class TabViewItem;
    class Toolbar;
    class ToolbarItem;
    class ViewController;

    /**
     * @brief C++ handle for the Objective-C class `NSTabViewController` (AppKit).
     * @details NSTabViewController is a container view controller that displays a single child view controller at a time from its \\c childViewControllers. It provides standard tab-style UI for user selection of tabs, or allows custom UI to be easily created by providing targets for bindings. ChildViewControllers’ views are lazily loaded; they are only loaded once their tab is selected and visible. The NSTabViewController is set as the delegate of its managed NSTabView. Any overrides of NSTabViewDelegate methods must call super. Properties of the TabView such as the tabStyle can be directly manipulated, but calling methods that add and remove tabViewItems or changing the delegate is not allowed. NSViewController's methods \\c -addChildViewController:, \\c -insertViewController:atIndex:, and \\c -removeChildViewControllerAtIndex: can all be used as convience methods to add children; default TabViewItems will be appropriately created or destroyed. The default NSTabViewItem created with with +[NSTabViewItem tabViewItemForViewController:].
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ViewController.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TabViewController tab_view_controller;
     * tab_view_controller.set_can_propagate_selected_child_view_controller_title(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TabViewController tab_view_controller{};
     * tab_view_controller.set_can_propagate_selected_child_view_controller_title(true);
     * auto can_propagate_selected_child_view_controller_title = tab_view_controller.can_propagate_selected_child_view_controller_title();
     * tab_view_controller.set_selected_tab_view_item_index(1);
     * auto selected_tab_view_item_index = tab_view_controller.selected_tab_view_item_index();
     * tab_view_controller.set_tab_style(cocoon::TabViewControllerTabStyle::SegmentedControlOnTop);
     * auto tab_style = tab_view_controller.tab_style();
     * tab_view_controller.add_tab_view_item(cocoon::TabViewItem());
     * tab_view_controller.insert_tab_view_item(cocoon::TabViewItem(), 1);
     * tab_view_controller.remove_tab_view_item(cocoon::TabViewItem());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstabviewcontroller
     */
    class TabViewController : public ViewController
    {
    public:
        /// @brief Creates a new `NSTabViewController` instance and returns a handle to it.
        explicit TabViewController();
        /// @brief Creates a null handle that refers to no native object.
        TabViewController(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TabViewController(Adopt adopt);
        using ViewController::view_did_load;
        /**
     * @brief Calls `-[NSTabViewController addTabViewItem:]`.
     * @details Adds a TabViewItem to the end of the TabViewController. The tabViewItem’s viewController’s view will only be loaded once its tab is selected. \\param tabViewItem The TabViewItem to add. It must have a \\c viewController set by the time it is added or an exception will be thrown. An exception will also be thrown if tabViewItem is nil.
     * @param tab_view_item Argument converted to the Objective-C parameter of the same role.
     */
        void add_tab_view_item(const TabViewItem& tab_view_item) const;
        /**
     * @brief Calls `-[NSTabViewController insertTabViewItem:atIndex:]`.
     * @details Adds a TabViewItem to a given index in the TabViewController. The tabViewItem’s viewController’s view will only be loaded once its tab is selected. \\c -selectedTabViewItemIndex will be adjusted if the insertion index is before it. Subclasses must call through \\c -insertTabViewItem:atIndex: to add a TabViewItem. \\param tabViewItem The TabViewItem to add. It must have a \\c viewController set by the time it is added or an exception will be thrown. An exception will also be thrown if tabViewItem is nil. \\param index The index to add the TabViewItem at. Will throw an exception if \\c index \< 0 or \\c index > \\c tabViewItems.count
     * @param tab_view_item Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_tab_view_item(const TabViewItem& tab_view_item, std::int64_t index) const;
        /**
     * @brief Calls `-[NSTabViewController removeTabViewItem:]`.
     * @details Removes a TabViewItem from the receiver. If the removed tabViewItem currently selected, the next (or previous, if there is no next) tabViewItem will become selected. If this is the only tabViewItem in the TabViewController, the selectedTabViewItemIndex will become \\c -1. Subclasses must call through \\c -removeTabViewItem: to remove a TabViewItem. \\param tabViewItem The TabViewItem to remove. An exception will be thrown if \\c tabViewItem is not in the NSTabViewController or if it is nil.
     * @param tab_view_item Argument converted to the Objective-C parameter of the same role.
     */
        void remove_tab_view_item(const TabViewItem& tab_view_item) const;
        /**
     * @brief Calls `-[NSTabViewController tabView:didSelectTabViewItem:]`.
     * @param tab_view Argument converted to the Objective-C parameter of the same role.
     * @param tab_view_item Argument converted to the Objective-C parameter of the same role.
     */
        void tab_view(const TabView& tab_view, const TabViewItem& tab_view_item) const;
        /**
     * @brief Calls `-[NSTabViewController tabViewItemForViewController:]`.
     * @details Convenience method for getting the associated tab view item for a particular childViewController. \\param viewController The ViewController to look up. \\return The corresponding TabViewItem. Returns nil if \\c viewController is not a child of the TabViewController.
     * @param view_controller Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        TabViewItem tab_view_item_for_view_controller(const ViewController& view_controller) const;
        /**
     * @brief Calls `-[NSTabViewController toolbar:itemForItemIdentifier:willBeInsertedIntoToolbar:]`.
     * @details NSTabViewController will create a toolbar item for each of its tabViewItems. The toolbar item's identifier will be the same as the tab view item's; similarly, the toolbar item's label, image, and toolTip are bound to those of the corresponding tab view item.
     * @param toolbar Argument converted to the Objective-C parameter of the same role.
     * @param item_identifier Argument converted to the Objective-C parameter of the same role.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ToolbarItem toolbar(const Toolbar& toolbar, const std::string& item_identifier, bool flag) const;
        /**
     * @brief Calls `-[NSTabViewController toolbarAllowedItemIdentifiers:]`.
     * @param toolbar Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> toolbar_allowed_item_identifiers(const Toolbar& toolbar) const;
        /**
     * @brief Calls `-[NSTabViewController toolbarDefaultItemIdentifiers:]`.
     * @details NSTabViewController returns the identifiers for the toolbar items corresponding to its tabViewItems. Overriding these allows additional items to be added to the toolbar. For example, adding NSToolbarFlexibleSpaceItemIdentifier to the beginning and end will center the TabViewController's toolbar items. If a subclass adds custom identifiers, -toolbar:itemForItemIdentifier:willBeInsertedIntoToolbar: must be overridden to return a toolbar item for that identifer.
     * @param toolbar Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> toolbar_default_item_identifiers(const Toolbar& toolbar) const;
        /**
     * @brief Calls `-[NSTabViewController toolbarSelectableItemIdentifiers:]`.
     * @details NSTabViewController returns all toolbar item identifiers corresponding to its tabViewItems.
     * @param toolbar Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> toolbar_selectable_item_identifiers(const Toolbar& toolbar) const;
        /**
     * @brief Calls `-[NSTabViewController viewDidLoad]`.
     * @details Overridden methods from NSViewController. These require a call to super if overriden by a subclass. Override this to set the tabView before calling super.
     */
        void view_did_load() const;
        /**
     * @brief Returns the `canPropagateSelectedChildViewControllerTitle` property of `NSTabViewController`.
     * @details If YES and the receiving NSTabViewController has a nil title, \\c -title will return its selected child ViewController's title. If NO, it will continue to return nil. The default value is \\c YES.
     * @return The converted Objective-C result.
     */
        bool can_propagate_selected_child_view_controller_title() const;
        /**
     * @brief Sets the `canPropagateSelectedChildViewControllerTitle` property of `NSTabViewController`.
     * @details If YES and the receiving NSTabViewController has a nil title, \\c -title will return its selected child ViewController's title. If NO, it will continue to return nil. The default value is \\c YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_can_propagate_selected_child_view_controller_title(bool value) const;
        /**
     * @brief Returns the `selectedTabViewItemIndex` property of `NSTabViewController`.
     * @details Read and write the current selected TabViewItem that is being shown. This value is KVC compliant and can be the target of a binding. For instance, a NSSegmentedControl's selection can be bound to this value with: \\code [segmentedControl bind:NSSelectedIndexBinding toObject:tabViewController withKeyPath:\@“selectedTabViewItemIndex" options:nil];
     * @return The converted Objective-C result.
     */
        std::int64_t selected_tab_view_item_index() const;
        /**
     * @brief Sets the `selectedTabViewItemIndex` property of `NSTabViewController`.
     * @details Read and write the current selected TabViewItem that is being shown. This value is KVC compliant and can be the target of a binding. For instance, a NSSegmentedControl's selection can be bound to this value with: \\code [segmentedControl bind:NSSelectedIndexBinding toObject:tabViewController withKeyPath:\@“selectedTabViewItemIndex" options:nil];
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selected_tab_view_item_index(std::int64_t value) const;
        /**
     * @brief Returns the `tabStyle` property of `NSTabViewController`.
     * @details The style that this NSTabViewController displays its UI as. Defaults to \\c NSTabViewControllerTabStyleSegmentedControlOnTop.
     * @return The converted Objective-C result.
     */
        TabViewControllerTabStyle tab_style() const;
        /**
     * @brief Sets the `tabStyle` property of `NSTabViewController`.
     * @details The style that this NSTabViewController displays its UI as. Defaults to \\c NSTabViewControllerTabStyleSegmentedControlOnTop.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tab_style(TabViewControllerTabStyle value) const;
        /**
     * @brief Returns the `tabView` property of `NSTabViewController`.
     * @details Access to the tab view that the controller is controlling. To provide a custom NSTabView, assign the value anytime before \\c self.viewLoaded is \\c YES. Querying the value will create it on-demand, if needed. Check \\c self.viewLoaded before querying the value to avoid prematurely creating the view. Note that the \\c -tabView may not be equal to the \\c viewController.view. Properties such as the tabStyle can be directly manipulated, but calling methods that add and remove tabViewItems or changing the delegate is not allowed. The NSTabViewController will be made the delegate of the NSTabView. Internally, the NSTabView is always used to switch between displayed childViewControllers, regardless of the style displayed.
     * @return The converted Objective-C result.
     */
        TabView tab_view() const;
        /**
     * @brief Sets the `tabView` property of `NSTabViewController`.
     * @details Access to the tab view that the controller is controlling. To provide a custom NSTabView, assign the value anytime before \\c self.viewLoaded is \\c YES. Querying the value will create it on-demand, if needed. Check \\c self.viewLoaded before querying the value to avoid prematurely creating the view. Note that the \\c -tabView may not be equal to the \\c viewController.view. Properties such as the tabStyle can be directly manipulated, but calling methods that add and remove tabViewItems or changing the delegate is not allowed. The NSTabViewController will be made the delegate of the NSTabView. Internally, the NSTabView is always used to switch between displayed childViewControllers, regardless of the style displayed.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tab_view(const TabView& value) const;
        /**
     * @brief Returns the `tabViewItems` property of `NSTabViewController`.
     * @details The array of tab view items that correspond to the current child view controllers. After a child view controller is added to the receiving TabViewController, a NSTabViewItem with the default values will be created for it. Once the child is removed, its corresponding tabViewItem will be removed from the tabViewItems array.
     * @return The converted Objective-C result.
     */
        std::vector<TabViewItem> tab_view_items() const;
        /**
     * @brief Sets the `tabViewItems` property of `NSTabViewController`.
     * @details The array of tab view items that correspond to the current child view controllers. After a child view controller is added to the receiving TabViewController, a NSTabViewItem with the default values will be created for it. Once the child is removed, its corresponding tabViewItem will be removed from the tabViewItems array.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tab_view_items(const std::vector<TabViewItem>& value) const;
        /**
     * @brief Returns the `transitionOptions` property of `NSTabViewController`.
     * @details This defines how NSTabViewController transitions from one view to another. Transitions go through [self transitionFromViewController:toViewController:options:completionHandler:]. The default value is \\c NSViewControllerTransitionCrossfade|NSViewControllerTransitionAllowUserInteraction.
     * @return The converted Objective-C result.
     */
        ViewControllerTransitionOptions transition_options() const;
        /**
     * @brief Sets the `transitionOptions` property of `NSTabViewController`.
     * @details This defines how NSTabViewController transitions from one view to another. Transitions go through [self transitionFromViewController:toViewController:options:completionHandler:]. The default value is \\c NSViewControllerTransitionCrossfade|NSViewControllerTransitionAllowUserInteraction.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_transition_options(ViewControllerTransitionOptions value) const;
    };
}
