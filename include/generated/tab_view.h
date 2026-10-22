#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class Font;
    class TabViewItem;
    class View;

    /**
     * @brief A tabbed container (NSTabView).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * cocoon::TabView tabs;
     * cocoon::VStack general;
     * tabs.add_tab("General", general);
     * tabs.selection_changed().connect([](int index) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TabView tab_view{};
     * tab_view.set_allows_truncated_labels(true);
     * auto allows_truncated_labels = tab_view.allows_truncated_labels();
     * tab_view.set_control_size(cocoon::ControlSize::Regular);
     * auto control_size = tab_view.control_size();
     * tab_view.set_draws_background(true);
     * auto draws_background = tab_view.draws_background();
     * tab_view.add_tab_view_item(cocoon::TabViewItem());
     * tab_view.index_of_tab_view_item(cocoon::TabViewItem());
     * tab_view.insert_tab_view_item(cocoon::TabViewItem(), 1);
     * tab_view.will_select_tab_view_item().connect([](cocoon::TabViewItem a0) {});
     * tab_view.selection_changed().connect([](int a0) {});
     * tab_view.did_change_number_of_tab_view_items().connect([]() {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstabview
     */
    class TabView : public View
    {
    public:
        /// @brief Creates a new `NSTabView` instance and returns a handle to it.
        explicit TabView();
        /// @brief Creates a null handle that refers to no native object.
        TabView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TabView(Adopt adopt);
        /**
         * @brief Calls `-[NSTabView addTabViewItem:]`.
         * @details Add/Remove tabs
         * @param tab_view_item Argument converted to the Objective-C parameter of the same role.
         */
        void add_tab_view_item(const TabViewItem& tab_view_item) const;
        /**
         * @brief Calls `-[NSTabView indexOfTabViewItem:]`.
         * @param tab_view_item Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t index_of_tab_view_item(const TabViewItem& tab_view_item) const;
        /**
         * @brief Calls `-[NSTabView indexOfTabViewItemWithIdentifier:]`.
         * @param identifier Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t index_of_tab_view_item_with_identifier(const Object& identifier) const;
        /**
         * @brief Calls `-[NSTabView insertTabViewItem:atIndex:]`.
         * @param tab_view_item Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void insert_tab_view_item(const TabViewItem& tab_view_item, std::int64_t index) const;
        /**
         * @brief Calls `-[NSTabView removeTabViewItem:]`.
         * @param tab_view_item Argument converted to the Objective-C parameter of the same role.
         */
        void remove_tab_view_item(const TabViewItem& tab_view_item) const;
        /**
         * @brief Calls `-[NSTabView selectFirstTabViewItem:]`.
         * @details Navigation
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void select_first_tab_view_item(const Object& sender) const;
        /**
         * @brief Calls `-[NSTabView selectLastTabViewItem:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void select_last_tab_view_item(const Object& sender) const;
        /**
         * @brief Calls `-[NSTabView selectNextTabViewItem:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void select_next_tab_view_item(const Object& sender) const;
        /**
         * @brief Calls `-[NSTabView selectPreviousTabViewItem:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void select_previous_tab_view_item(const Object& sender) const;
        /**
         * @brief Calls `-[NSTabView selectTabViewItem:]`.
         * @details Select
         * @param tab_view_item Argument converted to the Objective-C parameter of the same role.
         */
        void select_tab_view_item(const TabViewItem& tab_view_item) const;
        /**
         * @brief Calls `-[NSTabView selectTabViewItemAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void select_tab_view_item_at_index(std::int64_t index) const;
        /**
         * @brief Calls `-[NSTabView selectTabViewItemWithIdentifier:]`.
         * @param identifier Argument converted to the Objective-C parameter of the same role.
         */
        void select_tab_view_item_with_identifier(const Object& identifier) const;
        /**
         * @brief Calls `-[NSTabView tabViewItemAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TabViewItem tab_view_item_at_index(std::int64_t index) const;
        /**
         * @brief Calls `-[NSTabView tabViewItemAtPoint:]`.
         * @details Hit testing
         * @param point Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TabViewItem tab_view_item_at_point(const Point& point) const;
        /**
         * @brief Calls `-[NSTabView takeSelectedTabViewItemFromSender:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void take_selected_tab_view_item_from_sender(const Object& sender) const;
        /**
         * @brief Returns the `allowsTruncatedLabels` property of `NSTabView`.
         * @return The converted Objective-C result.
         */
        bool allows_truncated_labels() const;
        /**
         * @brief Sets the `allowsTruncatedLabels` property of `NSTabView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_truncated_labels(bool value) const;
        /**
         * @brief Returns the `contentRect` property of `NSTabView`.
         * @details Geometry
         * @return The converted Objective-C result.
         */
        Rect content_rect() const;
        /**
         * @brief Returns the `controlSize` property of `NSTabView`.
         * @return The converted Objective-C result.
         */
        ControlSize control_size() const;
        /**
         * @brief Sets the `controlSize` property of `NSTabView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_control_size(ControlSize value) const;
        /**
         * @brief Returns the `drawsBackground` property of `NSTabView`.
         * @return The converted Objective-C result.
         */
        bool draws_background() const;
        /**
         * @brief Sets the `drawsBackground` property of `NSTabView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_draws_background(bool value) const;
        /**
         * @brief Returns the `font` property of `NSTabView`.
         * @return The converted Objective-C result.
         */
        Font font() const;
        /**
         * @brief Sets the `font` property of `NSTabView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_font(const Font& value) const;
        /**
         * @brief Returns the `minimumSize` property of `NSTabView`.
         * @return The converted Objective-C result.
         */
        Size minimum_size() const;
        /**
         * @brief Returns the `numberOfTabViewItems` property of `NSTabView`.
         * @details Query
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_tab_view_items() const;
        /**
         * @brief Returns the `selectedTabViewItem` property of `NSTabView`.
         * @details Getters
         * @return The converted Objective-C result.
         */
        TabViewItem selected_tab_view_item() const;
        /**
         * @brief Returns the `tabPosition` property of `NSTabView`.
         * @return The converted Objective-C result.
         */
        TabPosition tab_position() const;
        /**
         * @brief Sets the `tabPosition` property of `NSTabView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tab_position(TabPosition value) const;
        /**
         * @brief Returns the `tabViewBorderType` property of `NSTabView`.
         * @return The converted Objective-C result.
         */
        TabViewBorderType tab_view_border_type() const;
        /**
         * @brief Sets the `tabViewBorderType` property of `NSTabView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tab_view_border_type(TabViewBorderType value) const;
        /**
         * @brief Returns the `tabViewItems` property of `NSTabView`.
         * @return The converted Objective-C result.
         */
        std::vector<TabViewItem> tab_view_items() const;
        /**
         * @brief Sets the `tabViewItems` property of `NSTabView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tab_view_items(const std::vector<TabViewItem>& value) const;
        /**
         * @brief Returns the `tabViewType` property of `NSTabView`.
         * @return The converted Objective-C result.
         */
        TabViewType tab_view_type() const;
        /**
         * @brief Sets the `tabViewType` property of `NSTabView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tab_view_type(TabViewType value) const;
        /// @brief Convenience helper `add_tab` provided by cocoon.
        int add_tab(const std::string& label, const View& content) const;
        /// @brief Convenience helper `current_index` provided by cocoon.
        int current_index() const;
        /// @brief Convenience helper `set_current_index` provided by cocoon.
        void set_current_index(int index) const;
        /// @brief Signal for the delegate/data-source method behind `should_select_tab_view_item`; connect a callback with `should_select_tab_view_item().connect(...)`.
        Signal<TabView, bool(TabViewItem)> should_select_tab_view_item() const
        {
            return Signal<TabView, bool(TabViewItem)>(handle(), "should_select_tab_view_item");
        }
        /// @brief Signal for the delegate/data-source method behind `will_select_tab_view_item`; connect a callback with `will_select_tab_view_item().connect(...)`.
        Signal<TabView, void(TabViewItem)> will_select_tab_view_item() const
        {
            return Signal<TabView, void(TabViewItem)>(handle(), "will_select_tab_view_item");
        }
        /// @brief Signal for the delegate/data-source method behind `selection_changed`; connect a callback with `selection_changed().connect(...)`.
        Signal<TabView, void(int)> selection_changed() const
        {
            return Signal<TabView, void(int)>(handle(), "selection_changed");
        }
        /// @brief Signal for the delegate/data-source method behind `did_change_number_of_tab_view_items`; connect a callback with `did_change_number_of_tab_view_items().connect(...)`.
        Signal<TabView, void()> did_change_number_of_tab_view_items() const
        {
            return Signal<TabView, void()>(handle(), "did_change_number_of_tab_view_items");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
