#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/text_field_cell.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSComboBoxCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TextFieldCell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ComboBoxCell combo_box_cell;
     * combo_box_cell.set_button_bordered(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ComboBoxCell combo_box_cell{};
     * combo_box_cell.set_button_bordered(true);
     * auto button_bordered = combo_box_cell.is_button_bordered();
     * combo_box_cell.set_completes(true);
     * auto completes = combo_box_cell.completes();
     * combo_box_cell.set_has_vertical_scroller(true);
     * auto has_vertical_scroller = combo_box_cell.has_vertical_scroller();
     * combo_box_cell.completed_string("text");
     * combo_box_cell.deselect_item_at_index(1);
     * combo_box_cell.item_object_value_at_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscomboboxcell
     */
    class ComboBoxCell : public TextFieldCell
    {
    public:
        /// @brief Creates a new `NSComboBoxCell` instance and returns a handle to it.
        explicit ComboBoxCell();
        /// @brief Creates a null handle that refers to no native object.
        ComboBoxCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ComboBoxCell(Adopt adopt);
        /**
     * @brief Calls `-[NSComboBoxCell addItemWithObjectValue:]`.
     * @details These methods can only be used when usesDataSource is NO
     * @param object Argument converted to the Objective-C parameter of the same role.
     */
        void add_item_with_object_value(const Object& object) const;
        /**
     * @brief Calls `-[NSComboBoxCell addItemsWithObjectValues:]`.
     * @param objects Argument converted to the Objective-C parameter of the same role.
     */
        void add_items_with_object_values(const std::vector<Object>& objects) const;
        /**
     * @brief Calls `-[NSComboBoxCell completedString:]`.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string completed_string(const std::string& string) const;
        /**
     * @brief Calls `-[NSComboBoxCell deselectItemAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void deselect_item_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSComboBoxCell indexOfItemWithObjectValue:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_item_with_object_value(const Object& object) const;
        /**
     * @brief Calls `-[NSComboBoxCell insertItemWithObjectValue:atIndex:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_item_with_object_value(const Object& object, std::int64_t index) const;
        /**
     * @brief Calls `-[NSComboBoxCell itemObjectValueAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object item_object_value_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSComboBoxCell noteNumberOfItemsChanged]`.
     */
        void note_number_of_items_changed() const;
        /**
     * @brief Calls `-[NSComboBoxCell reloadData]`.
     */
        void reload_data() const;
        /**
     * @brief Calls `-[NSComboBoxCell removeAllItems]`.
     */
        void remove_all_items() const;
        /**
     * @brief Calls `-[NSComboBoxCell removeItemAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void remove_item_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSComboBoxCell removeItemWithObjectValue:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     */
        void remove_item_with_object_value(const Object& object) const;
        /**
     * @brief Calls `-[NSComboBoxCell scrollItemAtIndexToTop:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void scroll_item_at_index_to_top(std::int64_t index) const;
        /**
     * @brief Calls `-[NSComboBoxCell scrollItemAtIndexToVisible:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void scroll_item_at_index_to_visible(std::int64_t index) const;
        /**
     * @brief Calls `-[NSComboBoxCell selectItemAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void select_item_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSComboBoxCell selectItemWithObjectValue:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     */
        void select_item_with_object_value(const Object& object) const;
        /**
     * @brief Returns the `buttonBordered` property of `NSComboBoxCell`.
     * @return The converted Objective-C result.
     */
        bool is_button_bordered() const;
        /**
     * @brief Sets the `buttonBordered` property of `NSComboBoxCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_button_bordered(bool value) const;
        /**
     * @brief Returns the `completes` property of `NSComboBoxCell`.
     * @return The converted Objective-C result.
     */
        bool completes() const;
        /**
     * @brief Sets the `completes` property of `NSComboBoxCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_completes(bool value) const;
        /**
     * @brief Returns the `hasVerticalScroller` property of `NSComboBoxCell`.
     * @return The converted Objective-C result.
     */
        bool has_vertical_scroller() const;
        /**
     * @brief Sets the `hasVerticalScroller` property of `NSComboBoxCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_has_vertical_scroller(bool value) const;
        /**
     * @brief Returns the `indexOfSelectedItem` property of `NSComboBoxCell`.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_selected_item() const;
        /**
     * @brief Returns the `intercellSpacing` property of `NSComboBoxCell`.
     * @return The converted Objective-C result.
     */
        Size intercell_spacing() const;
        /**
     * @brief Sets the `intercellSpacing` property of `NSComboBoxCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_intercell_spacing(const Size& value) const;
        /**
     * @brief Returns the `itemHeight` property of `NSComboBoxCell`.
     * @return The converted Objective-C result.
     */
        double item_height() const;
        /**
     * @brief Sets the `itemHeight` property of `NSComboBoxCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_item_height(double value) const;
        /**
     * @brief Returns the `numberOfItems` property of `NSComboBoxCell`.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_items() const;
        /**
     * @brief Returns the `numberOfVisibleItems` property of `NSComboBoxCell`.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_visible_items() const;
        /**
     * @brief Sets the `numberOfVisibleItems` property of `NSComboBoxCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_number_of_visible_items(std::int64_t value) const;
        /**
     * @brief Returns the `objectValueOfSelectedItem` property of `NSComboBoxCell`.
     * @return The converted Objective-C result.
     */
        Object object_value_of_selected_item() const;
        /**
     * @brief Returns the `objectValues` property of `NSComboBoxCell`.
     * @return The converted Objective-C result.
     */
        std::vector<Object> object_values() const;
        /**
     * @brief Returns the `usesDataSource` property of `NSComboBoxCell`.
     * @return The converted Objective-C result.
     */
        bool uses_data_source() const;
        /**
     * @brief Sets the `usesDataSource` property of `NSComboBoxCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_data_source(bool value) const;
        /// @brief Signal for the delegate/data-source method behind `number_of_items_in_combo_box_cell`; connect a callback with `number_of_items_in_combo_box_cell().connect(...)`.
        Signal<ComboBoxCell, std::int64_t()> number_of_items_in_combo_box_cell() const
        {
            return Signal<ComboBoxCell, std::int64_t()>(handle(), "number_of_items_in_combo_box_cell");
        }
        /// @brief Signal for the delegate/data-source method behind `object_value_for_item_at_index`; connect a callback with `object_value_for_item_at_index().connect(...)`.
        Signal<ComboBoxCell, Object(std::int64_t)> object_value_for_item_at_index() const
        {
            return Signal<ComboBoxCell, Object(std::int64_t)>(handle(), "object_value_for_item_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `index_of_item_with_string_value`; connect a callback with `index_of_item_with_string_value().connect(...)`.
        Signal<ComboBoxCell, std::uint64_t(std::string)> index_of_item_with_string_value() const
        {
            return Signal<ComboBoxCell, std::uint64_t(std::string)>(handle(), "index_of_item_with_string_value");
        }
        /// @brief Signal for the delegate/data-source method behind `combo_box_cell_completed_string`; connect a callback with `combo_box_cell_completed_string().connect(...)`.
        Signal<ComboBoxCell, std::string(std::string)> combo_box_cell_completed_string() const
        {
            return Signal<ComboBoxCell, std::string(std::string)>(handle(), "combo_box_cell_completed_string");
        }

    protected:
        static void install_data_source_delegate_(void* native);
    };
}
