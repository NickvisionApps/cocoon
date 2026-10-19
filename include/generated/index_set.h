#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSIndexSet` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::IndexSet index_set;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::IndexSet index_set{};
     * auto made_0 = cocoon::IndexSet::index_set();
     * auto made_1 = cocoon::IndexSet::index_set_with_index(1);
     * index_set.contains_index(1);
     * index_set.contains_indexes(cocoon::IndexSet());
     * index_set.index_greater_than_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsindexset
     */
    class IndexSet : public Object
    {
    public:
        /// @brief Creates a new `NSIndexSet` instance and returns a handle to it.
        explicit IndexSet(std::uint64_t value);
        /// @brief Creates a new `NSIndexSet` instance and returns a handle to it.
        explicit IndexSet(const Range& range);
        /// @brief Creates a new `NSIndexSet` instance and returns a handle to it.
        explicit IndexSet();
        /// @brief Creates a null handle that refers to no native object.
        IndexSet(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit IndexSet(Adopt adopt);
        /**
     * @brief Calls `-[NSIndexSet containsIndex:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool contains_index(std::uint64_t value) const;
        /**
     * @brief Calls `-[NSIndexSet containsIndexes:]`.
     * @param index_set Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool contains_indexes(const IndexSet& index_set) const;
        /**
     * @brief Calls `-[NSIndexSet containsIndexesInRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool contains_indexes_in_range(const Range& range) const;
        /**
     * @brief Calls `-[NSIndexSet countOfIndexesInRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t count_of_indexes_in_range(const Range& range) const;
        /**
     * @brief Calls `-[NSIndexSet enumerateIndexesInRange:options:usingBlock:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_indexes_in_range(const Range& range, EnumerationOptions opts, std::function<void(std::uint64_t, bool&)> block) const;
        /**
     * @brief Calls `-[NSIndexSet enumerateIndexesUsingBlock:]`.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_indexes_using_block(std::function<void(std::uint64_t, bool&)> block) const;
        /**
     * @brief Calls `-[NSIndexSet enumerateIndexesWithOptions:usingBlock:]`.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_indexes_with_options(EnumerationOptions opts, std::function<void(std::uint64_t, bool&)> block) const;
        /**
     * @brief Calls `-[NSIndexSet enumerateRangesInRange:options:usingBlock:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_ranges_in_range(const Range& range, EnumerationOptions opts, std::function<void(Range, bool&)> block) const;
        /**
     * @brief Calls `-[NSIndexSet enumerateRangesUsingBlock:]`.
     * @details The following three convenience methods allow you to enumerate the indexes in the receiver by ranges of contiguous indexes. The performance of these methods is not guaranteed to be any better than if they were implemented with enumerateIndexesInRange:options:usingBlock:. However, depending on the receiver's implementation, they may perform better than that. If the specified range for enumeration intersects a range of contiguous indexes in the receiver, then the block will be invoked with the intersection of those two ranges.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_ranges_using_block(std::function<void(Range, bool&)> block) const;
        /**
     * @brief Calls `-[NSIndexSet enumerateRangesWithOptions:usingBlock:]`.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_ranges_with_options(EnumerationOptions opts, std::function<void(Range, bool&)> block) const;
        /**
     * @brief Calls `-[NSIndexSet getIndexes:maxCount:inIndexRange:]`.
     * @details Fills up to bufferSize indexes in the specified range into the buffer and returns the number of indexes actually placed in the buffer; also modifies the optional range passed in by pointer to be "positioned" after the last index filled into the buffer.Example: if the index set contains the indexes 0, 2, 4, ..., 98, 100, for a buffer of size 10 and the range (20, 80) the buffer would contain 20, 22, ..., 38 and the range would be modified to (40, 60).
     * @param index_buffer Argument converted to the Objective-C parameter of the same role.
     * @param buffer_size Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t get_indexes(std::uint64_t* index_buffer, std::uint64_t buffer_size, Range* range) const;
        /**
     * @brief Calls `-[NSIndexSet indexGreaterThanIndex:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t index_greater_than_index(std::uint64_t value) const;
        /**
     * @brief Calls `-[NSIndexSet indexGreaterThanOrEqualToIndex:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t index_greater_than_or_equal_to_index(std::uint64_t value) const;
        /**
     * @brief Calls `-[NSIndexSet indexInRange:options:passingTest:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @param predicate Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t index_in_range(const Range& range, EnumerationOptions opts, std::function<bool(std::uint64_t, bool&)> predicate) const;
        /**
     * @brief Calls `-[NSIndexSet indexLessThanIndex:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t index_less_than_index(std::uint64_t value) const;
        /**
     * @brief Calls `-[NSIndexSet indexLessThanOrEqualToIndex:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t index_less_than_or_equal_to_index(std::uint64_t value) const;
        /**
     * @brief Calls `-[NSIndexSet indexPassingTest:]`.
     * @param predicate Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t index_passing_test(std::function<bool(std::uint64_t, bool&)> predicate) const;
        /**
     * @brief Calls `+[NSIndexSet indexSet]`.
     * @return The converted Objective-C result.
     */
        static IndexSet index_set();
        /**
     * @brief Calls `+[NSIndexSet indexSetWithIndex:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static IndexSet index_set_with_index(std::uint64_t value);
        /**
     * @brief Calls `+[NSIndexSet indexSetWithIndexesInRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static IndexSet index_set_with_indexes_in_range(const Range& range);
        /**
     * @brief Calls `-[NSIndexSet indexWithOptions:passingTest:]`.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @param predicate Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t index_with_options(EnumerationOptions opts, std::function<bool(std::uint64_t, bool&)> predicate) const;
        /**
     * @brief Calls `-[NSIndexSet indexesInRange:options:passingTest:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @param predicate Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        IndexSet indexes_in_range(const Range& range, EnumerationOptions opts, std::function<bool(std::uint64_t, bool&)> predicate) const;
        /**
     * @brief Calls `-[NSIndexSet indexesPassingTest:]`.
     * @param predicate Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        IndexSet indexes_passing_test(std::function<bool(std::uint64_t, bool&)> predicate) const;
        /**
     * @brief Calls `-[NSIndexSet indexesWithOptions:passingTest:]`.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @param predicate Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        IndexSet indexes_with_options(EnumerationOptions opts, std::function<bool(std::uint64_t, bool&)> predicate) const;
        /**
     * @brief Calls `-[NSIndexSet intersectsIndexesInRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool intersects_indexes_in_range(const Range& range) const;
        /**
     * @brief Calls `-[NSIndexSet isEqualToIndexSet:]`.
     * @param index_set Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_equal_to_index_set(const IndexSet& index_set) const;
        /**
     * @brief Returns the `count` property of `NSIndexSet`.
     * @return The converted Objective-C result.
     */
        std::uint64_t count() const;
        /**
     * @brief Returns the `firstIndex` property of `NSIndexSet`.
     * @details The following six methods will return NSNotFound if there is no index in the set satisfying the query.
     * @return The converted Objective-C result.
     */
        std::uint64_t first_index() const;
        /**
     * @brief Returns the `lastIndex` property of `NSIndexSet`.
     * @return The converted Objective-C result.
     */
        std::uint64_t last_index() const;
    };
}
