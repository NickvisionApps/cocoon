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
     * @details A mutable collection of unique integer values that represent indexes in another collection. In Swift, this type bridges to ''IndexSet''; use ''NSMutableIndexSet'' when you need reference semantics or other Foundation-specific behavior. The ''NSMutableIndexSet'' class represents a mutable collection of unique unsigned integers, known as indexes because of the way they are used. This collection is referred to as a mutable index set. The inclusive range of valid indexes is '0...(NSNotFound - 1)'; trying to use indexes outside this range is invalid. The values in a mutable index set are always sorted, so the order in which values are added is irrelevant. Do not subclass the ''NSMutableIndexSet'' class. > Important: > The Swift overlay to the Foundation framework provides the ''IndexSet'' structure, which bridges to the ''NSMutableIndexSet'' class and its immutable superclass, ''NSIndexSet''. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>.
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
         * @details Adds an index to the receiver. - Parameter value: Index to add. Must be in the range '0 .. NSNotFound - 1'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void add_index(std::uint64_t value) const;
        /**
         * @brief Calls `-[NSMutableIndexSet addIndexes:]`.
         * @details Adds the indexes in an index set to the receiver. - Parameter indexSet: Index set to add.
         * @param index_set Argument converted to the Objective-C parameter of the same role.
         */
        void add_indexes(const IndexSet& index_set) const;
        /**
         * @brief Calls `-[NSMutableIndexSet addIndexesInRange:]`.
         * @details Adds the indexes in an index range to the receiver. This method raises an 'NSRangeException' when 'range' would add an index that exceeds the maximum allowed value for unsigned integers. - Parameter range: Index range to add. Must be in the range '0 .. NSNotFound - 1'.
         * @param range Argument converted to the Objective-C parameter of the same role.
         */
        void add_indexes_in_range(const Range& range) const;
        /**
         * @brief Calls `-[NSMutableIndexSet removeAllIndexes]`.
         * @details Removes the receiver's indexes.
         */
        void remove_all_indexes() const;
        /**
         * @brief Calls `-[NSMutableIndexSet removeIndex:]`.
         * @details Removes an index from the receiver. - Parameter value: Index to remove.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void remove_index(std::uint64_t value) const;
        /**
         * @brief Calls `-[NSMutableIndexSet removeIndexes:]`.
         * @details Removes the indexes in an index set from the receiver. - Parameter indexSet: Index set to remove.
         * @param index_set Argument converted to the Objective-C parameter of the same role.
         */
        void remove_indexes(const IndexSet& index_set) const;
        /**
         * @brief Calls `-[NSMutableIndexSet removeIndexesInRange:]`.
         * @details Removes the indexes in an index range from the receiver. - Parameter range: Index range to remove.
         * @param range Argument converted to the Objective-C parameter of the same role.
         */
        void remove_indexes_in_range(const Range& range) const;
        /**
         * @brief Calls `-[NSMutableIndexSet shiftIndexesStartingAtIndex:by:]`.
         * @details Shifts a group of indexes to the left or the right within the receiver. The group of indexes shifted is made up by 'index' and the indexes that follow it in the set. A left shift deletes the indexes in a range the length of 'delta' preceding 'index' from the set. A right shift inserts empty space in the range '(index, delta)' in the receiver. The resulting indexes must all be in the range '0 .. NSNotFound - 1'. - Parameters: - index: Head of the group of indexes to shift. - delta: Amount and direction of the shift. Positive integers shift the indexes to the right. Negative integers shift the indexes to the left.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @param delta Argument converted to the Objective-C parameter of the same role.
         */
        void shift_indexes_starting_at_index(std::uint64_t index, std::int64_t delta) const;
    };
}
