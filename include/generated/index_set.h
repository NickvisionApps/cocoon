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
     * @details An immutable collection of unique integer values that represent indexes in another collection. In Swift, this type bridges to ''IndexSet''; use ''NSIndexSet'' when you need reference semantics or other Foundation-specific behavior. The 'NSIndexSet' class represents an immutable collection of unique unsigned integers, known as indexes because of the way they are used. This collection is referred to as an index set. Indexes must be in the range '0 .. NSNotFound - 1'. You use index sets in your code to store indexes into some other data structure. For example, given an 'NSArray' object, you could use an index set to identify a subset of objects in that array. You should not use index sets to store an arbitrary collection of integer values because index sets store indexes as sorted ranges. This makes them more efficient than storing a collection of individual integers. It also means that each index value can only appear once in the index set. The designated initializers of the 'NSIndexSet' class are: ''init(index:)'', ''init(indexesIn:)'', and ''init(indexSet:)''. You must not subclass the 'NSIndexSet' class. The mutable subclass of 'NSIndexSet' is ''NSMutableIndexSet''. > Important: > The Swift overlay to the Foundation framework provides the ''IndexSet'' structure, which bridges to the ''NSIndexSet'' class and its mutable subclass, ''NSMutableIndexSet''. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>.
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
         * @details Indicates whether the index set contains a specific index. - Parameter value: Index being inquired about. - Returns: 'YES' when the index set contains 'index', 'NO' otherwise.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool contains_index(std::uint64_t value) const;
        /**
         * @brief Calls `-[NSIndexSet containsIndexes:]`.
         * @details Indicates whether the receiving index set contains a superset of the indexes in another index set. - Parameter indexSet: Index set being inquired about. - Returns: 'YES' when the receiving index set contains a superset of the indexes in 'indexSet', 'NO' otherwise.
         * @param index_set Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool contains_indexes(const IndexSet& index_set) const;
        /**
         * @brief Calls `-[NSIndexSet containsIndexesInRange:]`.
         * @details Indicates whether the index set contains the indexes represented by an index range. - Parameter range: The index range being inquired about. - Returns: 'YES' when the index set contains the indexes in 'indexRange', 'NO' otherwise.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool contains_indexes_in_range(const Range& range) const;
        /**
         * @brief Calls `-[NSIndexSet countOfIndexesInRange:]`.
         * @details Returns the number of indexes in the index set that are members of a given range. - Parameter range: Index range being inquired about. - Returns: Number of indexes in the index set that are members of 'indexRange'.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t count_of_indexes_in_range(const Range& range) const;
        /**
         * @brief Calls `-[NSIndexSet enumerateIndexesInRange:options:usingBlock:]`.
         * @details Executes a given block using the indexes in the specified range, using the specified enumeration options. This method executes synchronously. - Parameters: - range: The range to enumerate. - opts: A bitmask that specifies the options for the enumeration (whether it should be performed concurrently and whether it should be performed in reverse order). - block: The block to apply to elements in the set. The block takes two arguments: 'idx' (the index of the object) and 'stop' (a reference to a Boolean value; set to 'YES' to stop further processing).
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param opts Argument converted to the Objective-C parameter of the same role.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void enumerate_indexes_in_range(const Range& range, EnumerationOptions opts, std::function<void(std::uint64_t, bool&)> block) const;
        /**
         * @brief Calls `-[NSIndexSet enumerateIndexesUsingBlock:]`.
         * @details Executes a given block using each object in the index set. This method executes synchronously. - Parameter block: The block to apply to elements in the set. The block takes two arguments: 'idx' (the index of the object) and 'stop' (a reference to a Boolean value; set to 'YES' to stop further processing).
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void enumerate_indexes_using_block(std::function<void(std::uint64_t, bool&)> block) const;
        /**
         * @brief Calls `-[NSIndexSet enumerateIndexesWithOptions:usingBlock:]`.
         * @details Executes a given block over the index set's indexes, using the specified enumeration options. This method executes synchronously. - Parameters: - opts: A bitmask that specifies the options for the enumeration (whether it should be performed concurrently and whether it should be performed in reverse order). - block: The block to apply to elements in the set. The block takes two arguments: 'idx' (the index of the object) and 'stop' (a reference to a Boolean value; set to 'YES' to stop further processing).
         * @param opts Argument converted to the Objective-C parameter of the same role.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void enumerate_indexes_with_options(EnumerationOptions opts, std::function<void(std::uint64_t, bool&)> block) const;
        /**
         * @brief Calls `-[NSIndexSet enumerateRangesInRange:options:usingBlock:]`.
         * @details Enumerates over the ranges in the range of objects using the block. By default, the enumeration starts with the first object and continues serially through the indexed set range to the last object in the range. You can specify 'NSEnumerationConcurrent' and/or 'NSEnumerationReverse' as enumeration options to modify this behavior. If the block parameter is 'nil' this method will raise an exception. This method executes synchronously. - Parameters: - range: The range of items to enumerate. If the range intersects a range of the receiver's indexes, then that intersection will be passed to the block. - opts: A bitmask that specifies the 'NSEnumerationOptions' for the enumeration. - block: The block to apply to elements in the index set. The block takes two arguments: 'range' (the range of elements) and 'stop' (a reference to a Boolean value; set to 'YES' to stop further processing).
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param opts Argument converted to the Objective-C parameter of the same role.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void enumerate_ranges_in_range(const Range& range, EnumerationOptions opts, std::function<void(Range, bool&)> block) const;
        /**
         * @brief Calls `-[NSIndexSet enumerateRangesUsingBlock:]`.
         * @details Executes a given block using each object in the index set, in the specified ranges. If the block parameter is 'nil' this method will raise an exception. This method executes synchronously. - Parameter block: The block to apply to elements in the index set. The block takes two arguments: 'range' (the range of elements) and 'stop' (a reference to a Boolean value; set to 'YES' to stop further processing).
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void enumerate_ranges_using_block(std::function<void(Range, bool&)> block) const;
        /**
         * @brief Calls `-[NSIndexSet enumerateRangesWithOptions:usingBlock:]`.
         * @details Executes a given block using each object in the index set, in the specified ranges. By default, the enumeration starts with the first object and continues serially through the indexed set range to the last object in the range. You can specify 'NSEnumerationConcurrent' and/or 'NSEnumerationReverse' as enumeration options to modify this behavior. If the block parameter is 'nil' this method will raise an exception. This method executes synchronously. - Parameters: - opts: A bitmask that specifies the 'NSEnumerationOptions' for the enumeration (whether it should be performed concurrently and whether it should be performed in reverse order). - block: The block to apply to elements in the index set. The block takes two arguments: 'range' (the range of elements) and 'stop' (a reference to a Boolean value; set to 'YES' to stop further processing).
         * @param opts Argument converted to the Objective-C parameter of the same role.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void enumerate_ranges_with_options(EnumerationOptions opts, std::function<void(Range, bool&)> block) const;
        /**
         * @brief Calls `-[NSIndexSet getIndexes:maxCount:inIndexRange:]`.
         * @details The index set fills an index buffer with the indexes contained both in the index set and in an index range, returning the number of indexes copied. You are responsible for allocating the memory required for 'indexBuffer' and for releasing it later. Suppose you have an index set with contiguous indexes from 1 to 100. If you use this method to request a range of '(1, 100)' and specify a buffer size of '20', this method returns 20 indexes (1 through 20) in 'indexBuffer' and sets 'indexRange' to '(21, 80)'. Use this method to retrieve entries quickly and efficiently from an index set. You can call this method repeatedly to retrieve blocks of index values and then process them. When doing so, use the return value and 'indexRange' to determine when you have finished processing the desired indexes. When the return value is less than 'bufferSize', you have reached the end of the range. - Parameters: - indexBuffer: Index buffer to fill. - bufferSize: Maximum size of 'indexBuffer'. - range: Index range to compare with indexes in the index set; 'nil' represents all the indexes in the index set. On output, the range of indexes not copied to 'indexBuffer'. - Returns: Number of indexes placed in 'indexBuffer'.
         * @param index_buffer Argument converted to the Objective-C parameter of the same role.
         * @param buffer_size Argument converted to the Objective-C parameter of the same role.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t get_indexes(std::uint64_t* index_buffer, std::uint64_t buffer_size, Range* range) const;
        /**
         * @brief Calls `-[NSIndexSet indexGreaterThanIndex:]`.
         * @details Returns either the closest index in the index set that is greater than a specific index or the not-found indicator. - Parameter value: Index being inquired about. - Returns: Closest index in the index set greater than 'index'; 'NSNotFound' when the index set contains no qualifying index.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t index_greater_than_index(std::uint64_t value) const;
        /**
         * @brief Calls `-[NSIndexSet indexGreaterThanOrEqualToIndex:]`.
         * @details Returns either the closest index in the index set that is greater than or equal to a specific index or the not-found indicator. - Parameter value: Index being inquired about. - Returns: Closest index in the index set greater than or equal to 'index'; 'NSNotFound' when the index set contains no qualifying index.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t index_greater_than_or_equal_to_index(std::uint64_t value) const;
        /**
         * @brief Calls `-[NSIndexSet indexInRange:options:passingTest:]`.
         * @details Returns the index of the first object in the specified range that passes the predicate block test. - Parameters: - range: The range of indexes to test. - opts: A bitmask that specifies the options for the enumeration (whether it should be performed concurrently and whether it should be performed in reverse order). - predicate: The block to apply to elements in the set. The block takes two arguments: 'idx' (the index of the object) and 'stop' (a reference to a Boolean value; set to 'YES' to stop further processing). The block returns a Boolean value that indicates whether the index passed the test. - Returns: The index of the first object that passes the predicate test.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param opts Argument converted to the Objective-C parameter of the same role.
         * @param predicate Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t index_in_range(const Range& range, EnumerationOptions opts, std::function<bool(std::uint64_t, bool&)> predicate) const;
        /**
         * @brief Calls `-[NSIndexSet indexLessThanIndex:]`.
         * @details Returns either the closest index in the index set that is less than a specific index or the not-found indicator. - Parameter value: Index being inquired about. - Returns: Closest index in the index set less than 'index'; 'NSNotFound' when the index set contains no qualifying index.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t index_less_than_index(std::uint64_t value) const;
        /**
         * @brief Calls `-[NSIndexSet indexLessThanOrEqualToIndex:]`.
         * @details Returns either the closest index in the index set that is less than or equal to a specific index or the not-found indicator. - Parameter value: Index being inquired about. - Returns: Closest index in the index set less than or equal to 'index'; 'NSNotFound' when the index set contains no qualifying index.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t index_less_than_or_equal_to_index(std::uint64_t value) const;
        /**
         * @brief Calls `-[NSIndexSet indexPassingTest:]`.
         * @details Returns the index of the first object that passes the predicate block test. - Parameter predicate: The block to apply to elements in the set. The block takes two arguments: 'idx' (the index of the object) and 'stop' (a reference to a Boolean value; set to 'YES' to stop further processing). The block returns a Boolean value that indicates whether the index passed the test. - Returns: The index of the first object that passes the predicate test.
         * @param predicate Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t index_passing_test(std::function<bool(std::uint64_t, bool&)> predicate) const;
        /**
         * @brief Calls `-[NSIndexSet indexWithOptions:passingTest:]`.
         * @details Returns the index of the first object that passes the predicate block test using the specified enumeration options. - Parameters: - opts: A bitmask that specifies the options for the enumeration (whether it should be performed concurrently and whether it should be performed in reverse order). - predicate: The block to apply to elements in the set. The block takes two arguments: 'idx' (the index of the object) and 'stop' (a reference to a Boolean value; set to 'YES' to stop further processing). The block returns a Boolean value that indicates whether the index passed the test. - Returns: The index of the first object that passes the predicate test.
         * @param opts Argument converted to the Objective-C parameter of the same role.
         * @param predicate Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t index_with_options(EnumerationOptions opts, std::function<bool(std::uint64_t, bool&)> predicate) const;
        /**
         * @brief Calls `-[NSIndexSet indexesInRange:options:passingTest:]`.
         * @details Returns an 'NSIndexSet' containing the receiving index set's objects in the specified range that pass the block test. - Parameters: - range: The range of indexes to test. - opts: A bitmask that specifies the options for the enumeration (whether it should be performed concurrently and whether it should be performed in reverse order). - predicate: The block to apply to elements in the set. The block takes two arguments: 'idx' (the index of the object) and 'stop' (a reference to a Boolean value; set to 'YES' to stop further processing). The block returns a Boolean value that indicates whether the index passed the test. - Returns: An 'NSIndexSet' containing the indexes of the receiving index set that passed the predicate block test.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param opts Argument converted to the Objective-C parameter of the same role.
         * @param predicate Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        IndexSet indexes_in_range(const Range& range, EnumerationOptions opts, std::function<bool(std::uint64_t, bool&)> predicate) const;
        /**
         * @brief Calls `-[NSIndexSet indexesPassingTest:]`.
         * @details Returns an 'NSIndexSet' containing the receiving index set's objects that pass the block test. - Parameter predicate: The block to apply to elements in the set. The block takes two arguments: 'idx' (the index of the object) and 'stop' (a reference to a Boolean value; set to 'YES' to stop further processing). The block returns a Boolean value that indicates whether the index passed the test. - Returns: An 'NSIndexSet' containing the indexes of the receiving index set that passed the predicate block test.
         * @param predicate Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        IndexSet indexes_passing_test(std::function<bool(std::uint64_t, bool&)> predicate) const;
        /**
         * @brief Calls `-[NSIndexSet indexesWithOptions:passingTest:]`.
         * @details Returns an 'NSIndexSet' containing the receiving index set's objects that pass the block test using the specified enumeration options. - Parameters: - opts: A bitmask that specifies the options for the enumeration (whether it should be performed concurrently and whether it should be performed in reverse order). - predicate: The block to apply to elements in the set. The block takes two arguments: 'idx' (the index of the object) and 'stop' (a reference to a Boolean value; set to 'YES' to stop further processing). The block returns a Boolean value that indicates whether the index passed the test. - Returns: An 'NSIndexSet' containing the indexes of the receiving index set that passed the predicate block test.
         * @param opts Argument converted to the Objective-C parameter of the same role.
         * @param predicate Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        IndexSet indexes_with_options(EnumerationOptions opts, std::function<bool(std::uint64_t, bool&)> predicate) const;
        /**
         * @brief Calls `-[NSIndexSet intersectsIndexesInRange:]`.
         * @details Indicates whether the index set contains any of the indexes in a range. - Parameter range: Index range being inquired about. - Returns: 'YES' when the index set contains one or more of the indexes in 'indexRange', 'NO' otherwise.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool intersects_indexes_in_range(const Range& range) const;
        /**
         * @brief Calls `-[NSIndexSet isEqualToIndexSet:]`.
         * @details Indicates whether the indexes in the receiving index set are the same indexes contained in another index set. - Parameter indexSet: Index set being inquired about. - Returns: 'YES' when the indexes in the receiving index set are the same indexes 'indexSet' contains, 'NO' otherwise.
         * @param index_set Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_equal_to_index_set(const IndexSet& index_set) const;
        /**
         * @brief Returns the `count` property of `NSIndexSet`.
         * @details The number of indexes in the index set.
         * @return The converted Objective-C result.
         */
        std::uint64_t count() const;
        /**
         * @brief Returns the `firstIndex` property of `NSIndexSet`.
         * @details The first index in the index set, or 'NSNotFound' when the index set is empty.
         * @return The converted Objective-C result.
         */
        std::uint64_t first_index() const;
        /**
         * @brief Returns the `lastIndex` property of `NSIndexSet`.
         * @details The last index in the index set, or 'NSNotFound' when the index set is empty.
         * @return The converted Objective-C result.
         */
        std::uint64_t last_index() const;
    };
}
