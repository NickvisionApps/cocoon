#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/index_set.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class IndexSet;

    /**
     * @brief C++ handle for the Objective-C class `NSMutableIndexSet` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref IndexSet.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MutableIndexSet mutable_index_set;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MutableIndexSet mutable_index_set{};
     * mutable_index_set.add_index(1);
     * mutable_index_set.add_indexes(cocoon::IndexSet());
     * mutable_index_set.remove_all_indexes();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmutableindexset
     */
    class MutableIndexSet : public IndexSet
    {
    public:
        /// @brief Creates a new `NSMutableIndexSet` instance and returns a handle to it.
        explicit MutableIndexSet();
        /// @brief Creates a null handle that refers to no native object.
        MutableIndexSet(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MutableIndexSet(Adopt adopt);
        /**
     * @brief Calls `-[NSMutableIndexSet addIndex:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void add_index(std::uint64_t value) const;
        /**
     * @brief Calls `-[NSMutableIndexSet addIndexes:]`.
     * @param index_set Argument converted to the Objective-C parameter of the same role.
     */
        void add_indexes(const IndexSet& index_set) const;
        /**
     * @brief Calls `-[NSMutableIndexSet addIndexesInRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void add_indexes_in_range(const Range& range) const;
        /**
     * @brief Calls `-[NSMutableIndexSet removeAllIndexes]`.
     */
        void remove_all_indexes() const;
        /**
     * @brief Calls `-[NSMutableIndexSet removeIndex:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void remove_index(std::uint64_t value) const;
        /**
     * @brief Calls `-[NSMutableIndexSet removeIndexes:]`.
     * @param index_set Argument converted to the Objective-C parameter of the same role.
     */
        void remove_indexes(const IndexSet& index_set) const;
        /**
     * @brief Calls `-[NSMutableIndexSet removeIndexesInRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void remove_indexes_in_range(const Range& range) const;
        /**
     * @brief Calls `-[NSMutableIndexSet shiftIndexesStartingAtIndex:by:]`.
     * @details For a positive delta, shifts the indexes in [index, INT_MAX] to the right, thereby inserting an "empty space" [index, delta], for a negative delta, shifts the indexes in [index, INT_MAX] to the left, thereby deleting the indexes in the range [index - delta, delta].
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @param delta Argument converted to the Objective-C parameter of the same role.
     */
        void shift_indexes_starting_at_index(std::uint64_t index, std::int64_t delta) const;
    };
}
