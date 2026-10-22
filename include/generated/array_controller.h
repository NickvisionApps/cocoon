#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/object_controller.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class IndexSet;
    class Predicate;
    class SortDescriptor;

    /**
     * @brief C++ handle for the Objective-C class `NSArrayController` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ObjectController.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ArrayController array_controller;
     * array_controller.set_always_uses_multiple_values_marker(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ArrayController array_controller{};
     * array_controller.set_always_uses_multiple_values_marker(true);
     * auto always_uses_multiple_values_marker = array_controller.always_uses_multiple_values_marker();
     * array_controller.set_automatically_rearranges_objects(true);
     * auto automatically_rearranges_objects = array_controller.automatically_rearranges_objects();
     * array_controller.set_avoids_empty_selection(true);
     * auto avoids_empty_selection = array_controller.avoids_empty_selection();
     * array_controller.add_selection_indexes(cocoon::IndexSet());
     * array_controller.did_change_arrangement_criteria();
     * array_controller.rearrange_objects();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsarraycontroller
     */
    class ArrayController : public ObjectController
    {
    public:
        /// @brief Creates a new `NSArrayController` instance and returns a handle to it.
        explicit ArrayController();
        /// @brief Creates a null handle that refers to no native object.
        ArrayController(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ArrayController(Adopt adopt);
        using ObjectController::add;
        using ObjectController::add_object;
        using ObjectController::remove;
        using ObjectController::remove_object;
        using ObjectController::selected_objects;
        /**
         * @brief Calls `-[NSArrayController add:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void add(const Object& sender) const;
        /**
         * @brief Calls `-[NSArrayController addObject:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         */
        void add_object(const Object& object) const;
        /**
         * @brief Calls `-[NSArrayController addObjects:]`.
         * @param objects Argument converted to the Objective-C parameter of the same role.
         */
        void add_objects(const std::vector<Object>& objects) const;
        /**
         * @brief Calls `-[NSArrayController addSelectedObjects:]`.
         * @param objects Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool add_selected_objects(const std::vector<Object>& objects) const;
        /**
         * @brief Calls `-[NSArrayController addSelectionIndexes:]`.
         * @param indexes Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool add_selection_indexes(const IndexSet& indexes) const;
        /**
         * @brief Calls `-[NSArrayController arrangeObjects:]`.
         * @param objects Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<Object> arrange_objects(const std::vector<Object>& objects) const;
        /**
         * @brief Calls `-[NSArrayController didChangeArrangementCriteria]`.
         */
        void did_change_arrangement_criteria() const;
        /**
         * @brief Calls `-[NSArrayController insert:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void insert(const Object& sender) const;
        /**
         * @brief Calls `-[NSArrayController insertObject:atArrangedObjectIndex:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void insert_object(const Object& object, std::uint64_t index) const;
        /**
         * @brief Calls `-[NSArrayController insertObjects:atArrangedObjectIndexes:]`.
         * @param objects Argument converted to the Objective-C parameter of the same role.
         * @param indexes Argument converted to the Objective-C parameter of the same role.
         */
        void insert_objects(const std::vector<Object>& objects, const IndexSet& indexes) const;
        /**
         * @brief Calls `-[NSArrayController rearrangeObjects]`.
         */
        void rearrange_objects() const;
        /**
         * @brief Calls `-[NSArrayController remove:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void remove(const Object& sender) const;
        /**
         * @brief Calls `-[NSArrayController removeObject:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         */
        void remove_object(const Object& object) const;
        /**
         * @brief Calls `-[NSArrayController removeObjectAtArrangedObjectIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void remove_object_at_arranged_object_index(std::uint64_t index) const;
        /**
         * @brief Calls `-[NSArrayController removeObjects:]`.
         * @param objects Argument converted to the Objective-C parameter of the same role.
         */
        void remove_objects(const std::vector<Object>& objects) const;
        /**
         * @brief Calls `-[NSArrayController removeObjectsAtArrangedObjectIndexes:]`.
         * @param indexes Argument converted to the Objective-C parameter of the same role.
         */
        void remove_objects_at_arranged_object_indexes(const IndexSet& indexes) const;
        /**
         * @brief Calls `-[NSArrayController removeSelectedObjects:]`.
         * @param objects Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool remove_selected_objects(const std::vector<Object>& objects) const;
        /**
         * @brief Calls `-[NSArrayController removeSelectionIndexes:]`.
         * @param indexes Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool remove_selection_indexes(const IndexSet& indexes) const;
        /**
         * @brief Calls `-[NSArrayController selectNext:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void select_next(const Object& sender) const;
        /**
         * @brief Calls `-[NSArrayController selectPrevious:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void select_previous(const Object& sender) const;
        /**
         * @brief Calls `-[NSArrayController setSelectedObjects:]`.
         * @param objects Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool set_selected_objects(const std::vector<Object>& objects) const;
        /**
         * @brief Calls `-[NSArrayController setSelectionIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool set_selection_index(std::uint64_t index) const;
        /**
         * @brief Calls `-[NSArrayController setSelectionIndexes:]`.
         * @details All selection modification methods returning a BOOL indicate through that flag whether changing the selection was successful (changing the selection might trigger an commitEditing call which fails and thus deny's the selection change).
         * @param indexes Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool set_selection_indexes(const IndexSet& indexes) const;
        /**
         * @brief Returns the `alwaysUsesMultipleValuesMarker` property of `NSArrayController`.
         * @details Indicates whether the controller should indicate all multiple selections through the NSMultipleValuesMarker, whether the selected values are equal or not (by default, the controller will only use the NSMultipleValuesMarker if the selected objects actually have different values) - this may act as a performance enhancement in certain applications.
         * @return The converted Objective-C result.
         */
        bool always_uses_multiple_values_marker() const;
        /**
         * @brief Sets the `alwaysUsesMultipleValuesMarker` property of `NSArrayController`.
         * @details Indicates whether the controller should indicate all multiple selections through the NSMultipleValuesMarker, whether the selected values are equal or not (by default, the controller will only use the NSMultipleValuesMarker if the selected objects actually have different values) - this may act as a performance enhancement in certain applications.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_always_uses_multiple_values_marker(bool value) const;
        /**
         * @brief Returns the `arrangedObjects` property of `NSArrayController`.
         * @return The converted Objective-C result.
         */
        Object arranged_objects() const;
        /**
         * @brief Returns the `automaticRearrangementKeyPaths` property of `NSArrayController`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> automatic_rearrangement_key_paths() const;
        /**
         * @brief Returns the `automaticallyRearrangesObjects` property of `NSArrayController`.
         * @return The converted Objective-C result.
         */
        bool automatically_rearranges_objects() const;
        /**
         * @brief Sets the `automaticallyRearrangesObjects` property of `NSArrayController`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_automatically_rearranges_objects(bool value) const;
        /**
         * @brief Returns the `avoidsEmptySelection` property of `NSArrayController`.
         * @return The converted Objective-C result.
         */
        bool avoids_empty_selection() const;
        /**
         * @brief Sets the `avoidsEmptySelection` property of `NSArrayController`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_avoids_empty_selection(bool value) const;
        /**
         * @brief Returns the `canInsert` property of `NSArrayController`.
         * @return The converted Objective-C result.
         */
        bool can_insert() const;
        /**
         * @brief Returns the `canSelectNext` property of `NSArrayController`.
         * @return The converted Objective-C result.
         */
        bool can_select_next() const;
        /**
         * @brief Returns the `canSelectPrevious` property of `NSArrayController`.
         * @return The converted Objective-C result.
         */
        bool can_select_previous() const;
        /**
         * @brief Returns the `clearsFilterPredicateOnInsertion` property of `NSArrayController`.
         * @details Indicates whether the controller should nil out its filter predicate before inserting (or adding) new objects. When set to yes, this eliminates the problem of inserting a new object into the array that would otherwise immediately be filtered out of the array of arranged objects.
         * @return The converted Objective-C result.
         */
        bool clears_filter_predicate_on_insertion() const;
        /**
         * @brief Sets the `clearsFilterPredicateOnInsertion` property of `NSArrayController`.
         * @details Indicates whether the controller should nil out its filter predicate before inserting (or adding) new objects. When set to yes, this eliminates the problem of inserting a new object into the array that would otherwise immediately be filtered out of the array of arranged objects.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_clears_filter_predicate_on_insertion(bool value) const;
        /**
         * @brief Returns the `filterPredicate` property of `NSArrayController`.
         * @return The converted Objective-C result.
         */
        Predicate filter_predicate() const;
        /**
         * @brief Sets the `filterPredicate` property of `NSArrayController`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_filter_predicate(const Predicate& value) const;
        /**
         * @brief Returns the `preservesSelection` property of `NSArrayController`.
         * @return The converted Objective-C result.
         */
        bool preserves_selection() const;
        /**
         * @brief Sets the `preservesSelection` property of `NSArrayController`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_preserves_selection(bool value) const;
        /**
         * @brief Returns the `selectedObjects` property of `NSArrayController`.
         * @return The converted Objective-C result.
         */
        std::vector<Object> selected_objects() const;
        /**
         * @brief Returns the `selectionIndex` property of `NSArrayController`.
         * @return The converted Objective-C result.
         */
        std::uint64_t selection_index() const;
        /**
         * @brief Returns the `selectionIndexes` property of `NSArrayController`.
         * @return The converted Objective-C result.
         */
        IndexSet selection_indexes() const;
        /**
         * @brief Returns the `selectsInsertedObjects` property of `NSArrayController`.
         * @return The converted Objective-C result.
         */
        bool selects_inserted_objects() const;
        /**
         * @brief Sets the `selectsInsertedObjects` property of `NSArrayController`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_selects_inserted_objects(bool value) const;
        /**
         * @brief Returns the `sortDescriptors` property of `NSArrayController`.
         * @return The converted Objective-C result.
         */
        std::vector<SortDescriptor> sort_descriptors() const;
        /**
         * @brief Sets the `sortDescriptors` property of `NSArrayController`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_sort_descriptors(const std::vector<SortDescriptor>& value) const;
    };
}
