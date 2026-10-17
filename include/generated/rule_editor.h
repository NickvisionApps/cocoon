#pragma once

#include "generated/availability.h"
#include "generated/control.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class IndexSet;
    class Notification;
    class Predicate;

    /**
     * @brief C++ handle for the Objective-C class `NSRuleEditor` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Control.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::RuleEditor rule_editor;
     * rule_editor.set_can_remove_all_rows(true);
     * rule_editor.rows_did_change().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::RuleEditor rule_editor{};
     * rule_editor.set_can_remove_all_rows(true);
     * auto can_remove_all_rows = rule_editor.can_remove_all_rows();
     * rule_editor.set_criteria_key_path("text");
     * auto criteria_key_path = rule_editor.criteria_key_path();
     * rule_editor.set_display_values_key_path("text");
     * auto display_values_key_path = rule_editor.display_values_key_path();
     * rule_editor.criteria_for_row(1);
     * rule_editor.display_values_for_row(1);
     * rule_editor.insert_row_at_index(1, cocoon::RuleEditorRowType::Simple, 1, true);
     * rule_editor.rows_did_change().connect([](cocoon::Notification a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsruleeditor
     */
    class RuleEditor : public Control
    {
    public:
        /// @brief Creates a new `NSRuleEditor` instance and returns a handle to it.
        explicit RuleEditor();
        /// @brief Creates a null handle that refers to no native object.
        RuleEditor(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit RuleEditor(Adopt adopt);
        /**
     * @brief Calls `-[NSRuleEditor addRow:]`.
     * @details Adds "initial" rows, or a row to the end - useful as the target for the outside + button
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void add_row(const Object& sender) const;
        /**
     * @brief Calls `-[NSRuleEditor criteriaForRow:]`.
     * @details Clients call this to obtain all of the currently chosen items for the given row. These are the same items that are returned from the delegate method - ruleEditor: child: forCriterion: withRowType:
     * @param row Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<Object> criteria_for_row(std::int64_t row) const;
        /**
     * @brief Calls `-[NSRuleEditor displayValuesForRow:]`.
     * @details Clients call this to obtain all of the chosen values (strings, views, or menu items) for row. These are the same values that are returned from the delegate method - ruleEditor: valueForItem: inRow:
     * @param row Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<Object> display_values_for_row(std::int64_t row) const;
        /**
     * @brief Calls `-[NSRuleEditor insertRowAtIndex:withType:asSubrowOfRow:animate:]`.
     * @details Clients call this to add a new row at the given index with the given type as a subrow of the parent row. Pass -1 to indicate that it should be a root row. If parentRow >= rowIndex, or if rowIndex would fall amongst the children of some other parent, or if the nesting mode forbids this configuration, an NSInvalidArgumentException is raised.
     * @param row_index Argument converted to the Objective-C parameter of the same role.
     * @param row_type Argument converted to the Objective-C parameter of the same role.
     * @param parent_row Argument converted to the Objective-C parameter of the same role.
     * @param should_animate Argument converted to the Objective-C parameter of the same role.
     */
        void insert_row_at_index(std::int64_t row_index, RuleEditorRowType row_type, std::int64_t parent_row, bool should_animate) const;
        /**
     * @brief Calls `-[NSRuleEditor parentRowForRow:]`.
     * @details Clients call this to determine the parent row of rowIndex. If rowIndex is a root row, this returns -1. If rowIndex is less than 0 or greater than or equal to the number of rows, this raises an NSRangeException
     * @param row_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t parent_row_for_row(std::int64_t row_index) const;
        /**
     * @brief Calls `-[NSRuleEditor predicateForRow:]`.
     * @details This method returns the predicate for a given row. Clients should rarely have a need to call this directly, but it can be overridden to perform specialized predicate handling for certain criteria or display values.
     * @param row Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Predicate predicate_for_row(std::int64_t row) const;
        /**
     * @brief Calls `-[NSRuleEditor reloadCriteria]`.
     * @details Clients can call this to indicate that the available criteria may have changed and should be refetched from the delegate, and the popups recalculated. If any item in a given row is "orphaned" (no longer reported as a child of its previous parent), those rows have their critieria and display values set to valid choices.
     */
        void reload_criteria() const;
        /**
     * @brief Calls `-[NSRuleEditor reloadPredicate]`.
     * @details Clients can call this to indicates that the predicate should be generated again from the delegate (by invoking the corresponding delegate method), typically because something has changed (for example, a view's value).
     */
        void reload_predicate() const;
        /**
     * @brief Calls `-[NSRuleEditor removeRowAtIndex:]`.
     * @details Clients call this to remove the row at the given index. Any subrows of the deleted row are adopted by the parent of the deleted row, or are made root rows. Raises NSRangeException if rowIndex is equal to or larger than the number of rows, or less than 0.
     * @param row_index Argument converted to the Objective-C parameter of the same role.
     */
        void remove_row_at_index(std::int64_t row_index) const;
        /**
     * @brief Calls `-[NSRuleEditor removeRowsAtIndexes:includeSubrows:]`.
     * @details Clients call this to delete rows at the given indexes. If includeSubrows is YES, then the subrows of the deleted rows will be deleted as well; if includeSubrows is NO, then each subrow will be adopted by its first non-deleted ancestor, or will become a root row. Raises NSRangeException if any index in rowIndexes is equal to or larger than the number of rows, or less than 0.
     * @param row_indexes Argument converted to the Objective-C parameter of the same role.
     * @param include_subrows Argument converted to the Objective-C parameter of the same role.
     */
        void remove_rows_at_indexes(const IndexSet& row_indexes, bool include_subrows) const;
        /**
     * @brief Calls `-[NSRuleEditor rowForDisplayValue:]`.
     * @details Clients call this to map from a display value (string, view, or menu item) back to a row. This method searches each row via pointer equality for the given display value, which may be present as an alternative in a popup menu for that row. It returns the index of the row containing the given value, or NSNotFound. Raises NSInvalidArgumentException if displayValue is nil.
     * @param display_value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t row_for_display_value(const Object& display_value) const;
        /**
     * @brief Calls `-[NSRuleEditor rowTypeForRow:]`.
     * @details Clients call this to determine the type of the row. If rowIndex is less than 0 or greater than or equal to the number of rows, this raises an NSRangeException
     * @param row_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        RuleEditorRowType row_type_for_row(std::int64_t row_index) const;
        /**
     * @brief Calls `-[NSRuleEditor selectRowIndexes:byExtendingSelection:]`.
     * @details Clients call this to modify the selected row indexes. Raises NSRangeException if any index in rowIndexes is equal to or larger than the number of rows, or less than 0.
     * @param indexes Argument converted to the Objective-C parameter of the same role.
     * @param extend Argument converted to the Objective-C parameter of the same role.
     */
        void select_row_indexes(const IndexSet& indexes, bool extend) const;
        /**
     * @brief Calls `-[NSRuleEditor setCriteria:andDisplayValues:forRowAtIndex:]`.
     * @details Clients call this to modify the row at a given index to contain the passed-in items and values. It is your responsibility to ensure that each item in the array is a child of the previous item, and that the first item is a root item for the row type. If the last item has child items, then the items array will be extended by querying the delegate for child items until a childless item is reached. If the values array contains fewer objects than the (possibly extended) criteria array, then the delegate will be queried to construct the remaining display values. If you want the delegate to be queried for all the criteria or all the display values, pass empty arrays; do not pass nil. Raises NSRangeException if rowIndex is equal to or larger than the number of rows, or less than 0. Raises an NSInvalidArgumentException if criteria or values is nil.
     * @param criteria Argument converted to the Objective-C parameter of the same role.
     * @param values Argument converted to the Objective-C parameter of the same role.
     * @param row_index Argument converted to the Objective-C parameter of the same role.
     */
        void set_criteria(const std::vector<Object>& criteria, const std::vector<Object>& values, std::int64_t row_index) const;
        /**
     * @brief Calls `-[NSRuleEditor subrowIndexesForRow:]`.
     * @details Clients can call this to determine the immediate subrows of the given row. Pass -1 to get the top-level rows. Rows are numbered starting at 0. If rowIndex is less than -1 or greater than or equal to the number of rows, this raises an NSRangeException.
     * @param row_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        IndexSet subrow_indexes_for_row(std::int64_t row_index) const;
        /**
     * @brief Returns the `canRemoveAllRows` property of `NSRuleEditor`.
     * @details Rule editors that have the canRemoveAllRows property set to NO prevent the user from emptying the rule editor by deleting all the rows. The rule editor can still be emptied programatically. The default is YES.
     * @return The converted Objective-C result.
     */
        bool can_remove_all_rows() const;
        /**
     * @brief Sets the `canRemoveAllRows` property of `NSRuleEditor`.
     * @details Rule editors that have the canRemoveAllRows property set to NO prevent the user from emptying the rule editor by deleting all the rows. The rule editor can still be emptied programatically. The default is YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_can_remove_all_rows(bool value) const;
        /**
     * @brief Returns the `criteriaKeyPath` property of `NSRuleEditor`.
     * @details Set and get the criteria key path, which determines the criteria for a row in the "rows" binding. (The criteria objects are what the delegate returns from - ruleEditor: child: forCriterion: withRowType:). The criteria property is an ordered to-many relationship. The default is \@"criteria".
     * @return The converted Objective-C result.
     */
        std::string criteria_key_path() const;
        /**
     * @brief Sets the `criteriaKeyPath` property of `NSRuleEditor`.
     * @details Set and get the criteria key path, which determines the criteria for a row in the "rows" binding. (The criteria objects are what the delegate returns from - ruleEditor: child: forCriterion: withRowType:). The criteria property is an ordered to-many relationship. The default is \@"criteria".
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_criteria_key_path(const std::string& value) const;
        /**
     * @brief Returns the `displayValuesKeyPath` property of `NSRuleEditor`.
     * @details Set and get the display values key path, which determines the display values for a row (the display values are what the delegate returns from - ruleEditor: displayValueForCriterion: inRow:). The criteria property is an ordered to-many relationship. The default is \@"displayValues".
     * @return The converted Objective-C result.
     */
        std::string display_values_key_path() const;
        /**
     * @brief Sets the `displayValuesKeyPath` property of `NSRuleEditor`.
     * @details Set and get the display values key path, which determines the display values for a row (the display values are what the delegate returns from - ruleEditor: displayValueForCriterion: inRow:). The criteria property is an ordered to-many relationship. The default is \@"displayValues".
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_display_values_key_path(const std::string& value) const;
        /**
     * @brief Returns the `editable` property of `NSRuleEditor`.
     * @details Clients call this to set the editable property of the control. Users can only interact with editable NSRuleEditors. The default is YES.
     * @return The converted Objective-C result.
     */
        bool is_editable() const;
        /**
     * @brief Sets the `editable` property of `NSRuleEditor`.
     * @details Clients call this to set the editable property of the control. Users can only interact with editable NSRuleEditors. The default is YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_editable(bool value) const;
        /**
     * @brief Returns the `formattingDictionary` property of `NSRuleEditor`.
     * @details Clients can call this to set (and get) a formatting dictionary on the NSRuleEditor. The formatting dictionary should have NSString keys and NSString values. The syntax of the keys and values is the same as the syntax for strings files.
     * @return The converted Objective-C result.
     */
        std::map<std::string, std::string> formatting_dictionary() const;
        /**
     * @brief Sets the `formattingDictionary` property of `NSRuleEditor`.
     * @details Clients can call this to set (and get) a formatting dictionary on the NSRuleEditor. The formatting dictionary should have NSString keys and NSString values. The syntax of the keys and values is the same as the syntax for strings files.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_formatting_dictionary(const std::map<std::string, std::string>& value) const;
        /**
     * @brief Returns the `formattingStringsFilename` property of `NSRuleEditor`.
     * @details Clients can call this to automatically set a formatting dictionary based on the strings file with the given name. Setting a formatting strings file searches the main bundle, and the bundle containing this nib, for a (possibly localized) strings file resource with the given name, loads it, and sets it as the formatting dictionary. The resulting dictionary can be obtained with -[NSRuleEditor formattingDictionary]. If you set the formatting dictionary explicitly with -[NSRuleEditor setFormattingDictionary:], then it sets the current formattingStringsFilename to nil
     * @return The converted Objective-C result.
     */
        std::string formatting_strings_filename() const;
        /**
     * @brief Sets the `formattingStringsFilename` property of `NSRuleEditor`.
     * @details Clients can call this to automatically set a formatting dictionary based on the strings file with the given name. Setting a formatting strings file searches the main bundle, and the bundle containing this nib, for a (possibly localized) strings file resource with the given name, loads it, and sets it as the formatting dictionary. The resulting dictionary can be obtained with -[NSRuleEditor formattingDictionary]. If you set the formatting dictionary explicitly with -[NSRuleEditor setFormattingDictionary:], then it sets the current formattingStringsFilename to nil
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_formatting_strings_filename(const std::string& value) const;
        /**
     * @brief Returns the `nestingMode` property of `NSRuleEditor`.
     * @details Clients call this to set and get the nesting mode for the NSRuleEditor. This is generally set at view creation time and not modified after. The default is NSRuleEditorNestingModeCompound.
     * @return The converted Objective-C result.
     */
        RuleEditorNestingMode nesting_mode() const;
        /**
     * @brief Sets the `nestingMode` property of `NSRuleEditor`.
     * @details Clients call this to set and get the nesting mode for the NSRuleEditor. This is generally set at view creation time and not modified after. The default is NSRuleEditorNestingModeCompound.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_nesting_mode(RuleEditorNestingMode value) const;
        /**
     * @brief Returns the `numberOfRows` property of `NSRuleEditor`.
     * @details Clients can call this to determine the number of rows
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_rows() const;
        /**
     * @brief Returns the `predicate` property of `NSRuleEditor`.
     * @details Clients can call this to obtain the predicate for the view if the delegate implements - ruleEditor: predicatePartsForItem: withValue: inRow:row: . If the delegate does not, or if the delegate does not return enough parts to construct a full predicate, this method returns nil.
     * @return The converted Objective-C result.
     */
        Predicate predicate() const;
        /**
     * @brief Returns the `rowClass` property of `NSRuleEditor`.
     * @details Sets the class used when creating a new row in the "rows" binding; this class should be KVC and KVO compliant for the key paths listed below. By default this is NSMutableDictionary
     * @return The converted Objective-C result.
     */
        std::string row_class() const;
        /**
     * @brief Sets the `rowClass` property of `NSRuleEditor`.
     * @details Sets the class used when creating a new row in the "rows" binding; this class should be KVC and KVO compliant for the key paths listed below. By default this is NSMutableDictionary
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_row_class(const std::string& value) const;
        /**
     * @brief Returns the `rowHeight` property of `NSRuleEditor`.
     * @details Clients call this to set and get the height of each row. This method changes the receiver's frame and marks it for redisplay.
     * @return The converted Objective-C result.
     */
        double row_height() const;
        /**
     * @brief Sets the `rowHeight` property of `NSRuleEditor`.
     * @details Clients call this to set and get the height of each row. This method changes the receiver's frame and marks it for redisplay.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_row_height(double value) const;
        /**
     * @brief Returns the `rowTypeKeyPath` property of `NSRuleEditor`.
     * @details Set and get the key path for the row type, which is used to get the row type in the "rows" binding. The row type is a value property of type NSRuleEditorRowType. The default is \@"rowType".
     * @return The converted Objective-C result.
     */
        std::string row_type_key_path() const;
        /**
     * @brief Sets the `rowTypeKeyPath` property of `NSRuleEditor`.
     * @details Set and get the key path for the row type, which is used to get the row type in the "rows" binding. The row type is a value property of type NSRuleEditorRowType. The default is \@"rowType".
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_row_type_key_path(const std::string& value) const;
        /**
     * @brief Returns the `selectedRowIndexes` property of `NSRuleEditor`.
     * @details Clients call this to determine the indexes of the selected rows.
     * @return The converted Objective-C result.
     */
        IndexSet selected_row_indexes() const;
        /**
     * @brief Returns the `subrowsKeyPath` property of `NSRuleEditor`.
     * @details Set and get the key path for the subrows, which is used to determined nested rows in the "rows" binding. The subrows property is an ordered to-many relationship containing additional bound row objects. The default is \@"subrows".
     * @return The converted Objective-C result.
     */
        std::string subrows_key_path() const;
        /**
     * @brief Sets the `subrowsKeyPath` property of `NSRuleEditor`.
     * @details Set and get the key path for the subrows, which is used to determined nested rows in the "rows" binding. The subrows property is an ordered to-many relationship containing additional bound row objects. The default is \@"subrows".
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_subrows_key_path(const std::string& value) const;
        /// @brief Signal for the delegate/data-source method behind `number_of_children_for_criterion_with_row_type`; connect a callback with `number_of_children_for_criterion_with_row_type().connect(...)`.
        Signal<RuleEditor, std::int64_t(Object, RuleEditorRowType)> number_of_children_for_criterion_with_row_type() const
        {
            return Signal<RuleEditor, std::int64_t(Object, RuleEditorRowType)>(handle(), "number_of_children_for_criterion_with_row_type");
        }
        /// @brief Signal for the delegate/data-source method behind `child_for_criterion_with_row_type`; connect a callback with `child_for_criterion_with_row_type().connect(...)`.
        Signal<RuleEditor, Object(std::int64_t, Object, RuleEditorRowType)> child_for_criterion_with_row_type() const
        {
            return Signal<RuleEditor, Object(std::int64_t, Object, RuleEditorRowType)>(handle(), "child_for_criterion_with_row_type");
        }
        /// @brief Signal for the delegate/data-source method behind `display_value_for_criterion_in_row`; connect a callback with `display_value_for_criterion_in_row().connect(...)`.
        Signal<RuleEditor, Object(Object, std::int64_t)> display_value_for_criterion_in_row() const
        {
            return Signal<RuleEditor, Object(Object, std::int64_t)>(handle(), "display_value_for_criterion_in_row");
        }
        /// @brief Signal for the delegate/data-source method behind `predicate_parts_for_criterion_with_display_value_in_row`; connect a callback with `predicate_parts_for_criterion_with_display_value_in_row().connect(...)`.
        Signal<RuleEditor, std::map<std::string, Object>(Object, Object, std::int64_t)> predicate_parts_for_criterion_with_display_value_in_row() const
        {
            return Signal<RuleEditor, std::map<std::string, Object>(Object, Object, std::int64_t)>(handle(), "predicate_parts_for_criterion_with_display_value_in_row");
        }
        /// @brief Signal for the delegate/data-source method behind `rows_did_change`; connect a callback with `rows_did_change().connect(...)`.
        Signal<RuleEditor, void(Notification)> rows_did_change() const
        {
            return Signal<RuleEditor, void(Notification)>(handle(), "rows_did_change");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
