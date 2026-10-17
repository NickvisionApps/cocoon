#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/menu_item_cell.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Menu;
    class MenuItem;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSPopUpButtonCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref MenuItemCell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PopUpButtonCell pop_up_button_cell;
     * pop_up_button_cell.set_alters_state_of_selected_item(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PopUpButtonCell pop_up_button_cell{};
     * pop_up_button_cell.set_alters_state_of_selected_item(true);
     * auto alters_state_of_selected_item = pop_up_button_cell.alters_state_of_selected_item();
     * pop_up_button_cell.set_arrow_position(cocoon::PopUpArrowPosition::NoArrow);
     * auto arrow_position = pop_up_button_cell.arrow_position();
     * pop_up_button_cell.set_autoenables_items(true);
     * auto autoenables_items = pop_up_button_cell.autoenables_items();
     * pop_up_button_cell.add_item_with_title("text");
     * pop_up_button_cell.add_items_with_titles({"a", "b"});
     * pop_up_button_cell.attach_pop_up_with_frame({{0, 0}, {100, 100}}, cocoon::View());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspopupbuttoncell
     */
    class PopUpButtonCell : public MenuItemCell
    {
    public:
        /// @brief Creates a new `NSPopUpButtonCell` instance and returns a handle to it.
        explicit PopUpButtonCell(const std::string& string_value, bool pull_down);
        /// @brief Creates a new `NSPopUpButtonCell` instance and returns a handle to it.
        explicit PopUpButtonCell();
        /// @brief Creates a null handle that refers to no native object.
        PopUpButtonCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PopUpButtonCell(Adopt adopt);
        using ButtonCell::set_title;
        using Cell::menu;
        using Cell::set_menu;
        /**
     * @brief Calls `-[NSPopUpButtonCell addItemWithTitle:]`.
     * @param title Argument converted to the Objective-C parameter of the same role.
     */
        void add_item_with_title(const std::string& title) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell addItemsWithTitles:]`.
     * @param item_titles Argument converted to the Objective-C parameter of the same role.
     */
        void add_items_with_titles(const std::vector<std::string>& item_titles) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell attachPopUpWithFrame:inView:]`.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     */
        void attach_pop_up_with_frame(const Rect& cell_frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell dismissPopUp]`.
     */
        void dismiss_pop_up() const;
        /**
     * @brief Calls `-[NSPopUpButtonCell indexOfItem:]`.
     * @param item Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_item(const MenuItem& item) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell indexOfItemWithRepresentedObject:]`.
     * @param obj Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_item_with_represented_object(const Object& obj) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell indexOfItemWithTag:]`.
     * @param tag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_item_with_tag(std::int64_t tag) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell indexOfItemWithTarget:andAction:]`.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param action_selector Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_item_with_target(const Object& target, const std::string& action_selector) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell indexOfItemWithTitle:]`.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_item_with_title(const std::string& title) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell insertItemWithTitle:atIndex:]`.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_item_with_title(const std::string& title, std::int64_t index) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell itemAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        MenuItem item_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell itemTitleAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string item_title_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell itemWithTitle:]`.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        MenuItem item_with_title(const std::string& title) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell performClickWithFrame:inView:]`.
     * @param frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     */
        void perform_click_with_frame(const Rect& frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell removeAllItems]`.
     */
        void remove_all_items() const;
        /**
     * @brief Calls `-[NSPopUpButtonCell removeItemAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void remove_item_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell removeItemWithTitle:]`.
     * @param title Argument converted to the Objective-C parameter of the same role.
     */
        void remove_item_with_title(const std::string& title) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell selectItem:]`.
     * @param item Argument converted to the Objective-C parameter of the same role.
     */
        void select_item(const MenuItem& item) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell selectItemAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void select_item_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell selectItemWithTag:]`.
     * @param tag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool select_item_with_tag(std::int64_t tag) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell selectItemWithTitle:]`.
     * @param title Argument converted to the Objective-C parameter of the same role.
     */
        void select_item_with_title(const std::string& title) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell setTitle:]`.
     * @param string Argument converted to the Objective-C parameter of the same role.
     */
        void set_title(const std::string& string) const;
        /**
     * @brief Calls `-[NSPopUpButtonCell synchronizeTitleAndSelectedItem]`.
     */
        void synchronize_title_and_selected_item() const;
        /**
     * @brief Returns the `altersStateOfSelectedItem` property of `NSPopUpButtonCell`.
     * @return The converted Objective-C result.
     */
        bool alters_state_of_selected_item() const;
        /**
     * @brief Sets the `altersStateOfSelectedItem` property of `NSPopUpButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_alters_state_of_selected_item(bool value) const;
        /**
     * @brief Returns the `arrowPosition` property of `NSPopUpButtonCell`.
     * @return The converted Objective-C result.
     */
        PopUpArrowPosition arrow_position() const;
        /**
     * @brief Sets the `arrowPosition` property of `NSPopUpButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_arrow_position(PopUpArrowPosition value) const;
        /**
     * @brief Returns the `autoenablesItems` property of `NSPopUpButtonCell`.
     * @return The converted Objective-C result.
     */
        bool autoenables_items() const;
        /**
     * @brief Sets the `autoenablesItems` property of `NSPopUpButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_autoenables_items(bool value) const;
        /**
     * @brief Returns the `indexOfSelectedItem` property of `NSPopUpButtonCell`.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_selected_item() const;
        /**
     * @brief Returns the `itemArray` property of `NSPopUpButtonCell`.
     * @return The converted Objective-C result.
     */
        std::vector<MenuItem> item_array() const;
        /**
     * @brief Returns the `itemTitles` property of `NSPopUpButtonCell`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> item_titles() const;
        /**
     * @brief Returns the `lastItem` property of `NSPopUpButtonCell`.
     * @return The converted Objective-C result.
     */
        MenuItem last_item() const;
        /**
     * @brief Returns the `menu` property of `NSPopUpButtonCell`.
     * @return The converted Objective-C result.
     */
        Menu menu() const;
        /**
     * @brief Sets the `menu` property of `NSPopUpButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_menu(const Menu& value) const;
        /**
     * @brief Returns the `numberOfItems` property of `NSPopUpButtonCell`.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_items() const;
        /**
     * @brief Returns the `preferredEdge` property of `NSPopUpButtonCell`.
     * @return The converted Objective-C result.
     */
        RectEdge preferred_edge() const;
        /**
     * @brief Sets the `preferredEdge` property of `NSPopUpButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preferred_edge(RectEdge value) const;
        /**
     * @brief Returns the `pullsDown` property of `NSPopUpButtonCell`.
     * @return The converted Objective-C result.
     */
        bool pulls_down() const;
        /**
     * @brief Sets the `pullsDown` property of `NSPopUpButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_pulls_down(bool value) const;
        /**
     * @brief Returns the `selectedItem` property of `NSPopUpButtonCell`.
     * @return The converted Objective-C result.
     */
        MenuItem selected_item() const;
        /**
     * @brief Returns the `titleOfSelectedItem` property of `NSPopUpButtonCell`.
     * @return The converted Objective-C result.
     */
        std::string title_of_selected_item() const;
        /**
     * @brief Returns the `usesItemFromMenu` property of `NSPopUpButtonCell`.
     * @return The converted Objective-C result.
     */
        bool uses_item_from_menu() const;
        /**
     * @brief Sets the `usesItemFromMenu` property of `NSPopUpButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_item_from_menu(bool value) const;
    };
}
