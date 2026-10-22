#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/text_field.h"
#include "types.h"

namespace cocoon
{
    class Notification;
    class Text;
    class TextCheckingResult;
    class TextView;

    /**
     * @brief A text field with a drop-down list.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TextField.
     *
     * @par Example
     * @code
     * cocoon::ComboBox combo;
     * combo.add_item("First");
     * combo.add_item("Second");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ComboBox combo_box{};
     * combo_box.set_button_bordered(true);
     * auto button_bordered = combo_box.is_button_bordered();
     * combo_box.set_completes(true);
     * auto completes = combo_box.completes();
     * combo_box.set_has_vertical_scroller(true);
     * auto has_vertical_scroller = combo_box.has_vertical_scroller();
     * combo_box.deselect_item_at_index(1);
     * combo_box.item_object_value_at_index(1);
     * combo_box.note_number_of_items_changed();
     * combo_box.selection_changed().connect([](std::int64_t a0) {});
     * combo_box.will_pop_up().connect([](cocoon::Notification a0) {});
     * combo_box.will_dismiss().connect([](cocoon::Notification a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscombobox
     */
    class ComboBox : public TextField
    {
    public:
        /// @brief Creates a new `NSComboBox` instance and returns a handle to it.
        explicit ComboBox();
        /// @brief Creates a null handle that refers to no native object.
        ComboBox(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ComboBox(Adopt adopt);
        /**
         * @brief Calls `-[NSComboBox addItemWithObjectValue:]`.
         * @details These methods can only be used when usesDataSource is NO
         * @param object Argument converted to the Objective-C parameter of the same role.
         */
        void add_item_with_object_value(const Object& object) const;
        /**
         * @brief Calls `-[NSComboBox addItemsWithObjectValues:]`.
         * @param objects Argument converted to the Objective-C parameter of the same role.
         */
        void add_items_with_object_values(const std::vector<Object>& objects) const;
        /**
         * @brief Calls `-[NSComboBox deselectItemAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void deselect_item_at_index(std::int64_t index) const;
        /**
         * @brief Calls `-[NSComboBox indexOfItemWithObjectValue:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t index_of_item_with_object_value(const Object& object) const;
        /**
         * @brief Calls `-[NSComboBox insertItemWithObjectValue:atIndex:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void insert_item_with_object_value(const Object& object, std::int64_t index) const;
        /**
         * @brief Calls `-[NSComboBox itemObjectValueAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object item_object_value_at_index(std::int64_t index) const;
        /**
         * @brief Calls `-[NSComboBox noteNumberOfItemsChanged]`.
         */
        void note_number_of_items_changed() const;
        /**
         * @brief Calls `-[NSComboBox reloadData]`.
         */
        void reload_data() const;
        /**
         * @brief Calls `-[NSComboBox removeAllItems]`.
         */
        void remove_all_items() const;
        /**
         * @brief Calls `-[NSComboBox removeItemAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void remove_item_at_index(std::int64_t index) const;
        /**
         * @brief Calls `-[NSComboBox removeItemWithObjectValue:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         */
        void remove_item_with_object_value(const Object& object) const;
        /**
         * @brief Calls `-[NSComboBox scrollItemAtIndexToTop:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void scroll_item_at_index_to_top(std::int64_t index) const;
        /**
         * @brief Calls `-[NSComboBox scrollItemAtIndexToVisible:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void scroll_item_at_index_to_visible(std::int64_t index) const;
        /**
         * @brief Calls `-[NSComboBox selectItemAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void select_item_at_index(std::int64_t index) const;
        /**
         * @brief Calls `-[NSComboBox selectItemWithObjectValue:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         */
        void select_item_with_object_value(const Object& object) const;
        /**
         * @brief Returns the `buttonBordered` property of `NSComboBox`.
         * @return The converted Objective-C result.
         */
        bool is_button_bordered() const;
        /**
         * @brief Sets the `buttonBordered` property of `NSComboBox`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_button_bordered(bool value) const;
        /**
         * @brief Returns the `completes` property of `NSComboBox`.
         * @return The converted Objective-C result.
         */
        bool completes() const;
        /**
         * @brief Sets the `completes` property of `NSComboBox`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_completes(bool value) const;
        /**
         * @brief Returns the `hasVerticalScroller` property of `NSComboBox`.
         * @return The converted Objective-C result.
         */
        bool has_vertical_scroller() const;
        /**
         * @brief Sets the `hasVerticalScroller` property of `NSComboBox`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_has_vertical_scroller(bool value) const;
        /**
         * @brief Returns the `indexOfSelectedItem` property of `NSComboBox`.
         * @return The converted Objective-C result.
         */
        std::int64_t index_of_selected_item() const;
        /**
         * @brief Returns the `intercellSpacing` property of `NSComboBox`.
         * @return The converted Objective-C result.
         */
        Size intercell_spacing() const;
        /**
         * @brief Sets the `intercellSpacing` property of `NSComboBox`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_intercell_spacing(const Size& value) const;
        /**
         * @brief Returns the `itemHeight` property of `NSComboBox`.
         * @return The converted Objective-C result.
         */
        double item_height() const;
        /**
         * @brief Sets the `itemHeight` property of `NSComboBox`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_item_height(double value) const;
        /**
         * @brief Returns the `numberOfItems` property of `NSComboBox`.
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_items() const;
        /**
         * @brief Returns the `numberOfVisibleItems` property of `NSComboBox`.
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_visible_items() const;
        /**
         * @brief Sets the `numberOfVisibleItems` property of `NSComboBox`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_number_of_visible_items(std::int64_t value) const;
        /**
         * @brief Returns the `objectValueOfSelectedItem` property of `NSComboBox`.
         * @return The converted Objective-C result.
         */
        Object object_value_of_selected_item() const;
        /**
         * @brief Returns the `objectValues` property of `NSComboBox`.
         * @return The converted Objective-C result.
         */
        std::vector<Object> object_values() const;
        /**
         * @brief Returns the `usesDataSource` property of `NSComboBox`.
         * @return The converted Objective-C result.
         */
        bool uses_data_source() const;
        /**
         * @brief Sets the `usesDataSource` property of `NSComboBox`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_uses_data_source(bool value) const;
        /// @brief Convenience helper `add_item` provided by cocoon.
        void add_item(const std::string& item) const;
        /// @brief Signal `selection_changed`: connect a callback with `selection_changed().connect(...)`.
        Signal<ComboBox, void(std::int64_t)> selection_changed() const
        {
            return Signal<ComboBox, void(std::int64_t)>(handle(), "selection_changed");
        }
        /// @brief Signal for the delegate/data-source method behind `number_of_items_in_combo_box`; connect a callback with `number_of_items_in_combo_box().connect(...)`.
        Signal<ComboBox, std::int64_t()> number_of_items_in_combo_box() const
        {
            return Signal<ComboBox, std::int64_t()>(handle(), "number_of_items_in_combo_box");
        }
        /// @brief Signal for the delegate/data-source method behind `object_value_for_item_at_index`; connect a callback with `object_value_for_item_at_index().connect(...)`.
        Signal<ComboBox, Object(std::int64_t)> object_value_for_item_at_index() const
        {
            return Signal<ComboBox, Object(std::int64_t)>(handle(), "object_value_for_item_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `index_of_item_with_string_value`; connect a callback with `index_of_item_with_string_value().connect(...)`.
        Signal<ComboBox, std::uint64_t(std::string)> index_of_item_with_string_value() const
        {
            return Signal<ComboBox, std::uint64_t(std::string)>(handle(), "index_of_item_with_string_value");
        }
        /// @brief Signal for the delegate/data-source method behind `completed_string`; connect a callback with `completed_string().connect(...)`.
        Signal<ComboBox, std::string(std::string)> completed_string() const
        {
            return Signal<ComboBox, std::string(std::string)>(handle(), "completed_string");
        }
        /// @brief Signal for the delegate/data-source method behind `will_pop_up`; connect a callback with `will_pop_up().connect(...)`.
        Signal<ComboBox, void(Notification)> will_pop_up() const
        {
            return Signal<ComboBox, void(Notification)>(handle(), "will_pop_up");
        }
        /// @brief Signal for the delegate/data-source method behind `will_dismiss`; connect a callback with `will_dismiss().connect(...)`.
        Signal<ComboBox, void(Notification)> will_dismiss() const
        {
            return Signal<ComboBox, void(Notification)>(handle(), "will_dismiss");
        }
        /// @brief Signal for the delegate/data-source method behind `selection_did_change`; connect a callback with `selection_did_change().connect(...)`.
        Signal<ComboBox, void(Notification)> selection_did_change() const
        {
            return Signal<ComboBox, void(Notification)>(handle(), "selection_did_change");
        }
        /// @brief Signal for the delegate/data-source method behind `selection_is_changing`; connect a callback with `selection_is_changing().connect(...)`.
        Signal<ComboBox, void(Notification)> selection_is_changing() const
        {
            return Signal<ComboBox, void(Notification)>(handle(), "selection_is_changing");
        }

    protected:
        static void bind_others_(void* native);
        static void install_data_source_delegate_(void* native);
        static void install_delegate_delegate_(void* native);
    };
}
