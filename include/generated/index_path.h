#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSIndexPath` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::IndexPath index_path;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::IndexPath index_path{};
     * auto made_0 = cocoon::IndexPath::index_path_for_item(1, 1);
     * auto made_1 = cocoon::IndexPath::index_path_with_index(1);
     * index_path.compare(cocoon::IndexPath());
     * index_path.index_at_position(1);
     * index_path.index_path_by_adding_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsindexpath
     */
    class IndexPath : public Object
    {
    public:
        /// @brief Creates a new `NSIndexPath` instance and returns a handle to it.
        explicit IndexPath(std::uint64_t index);
        /// @brief Creates a new `NSIndexPath` instance and returns a handle to it.
        explicit IndexPath(const std::uint64_t* indexes, std::uint64_t length);
        /// @brief Creates a new `NSIndexPath` instance and returns a handle to it.
        explicit IndexPath();
        /// @brief Creates a null handle that refers to no native object.
        IndexPath(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit IndexPath(Adopt adopt);
        /**
     * @brief Calls `-[NSIndexPath compare:]`.
     * @param other_object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ComparisonResult compare(const IndexPath& other_object) const;
        /**
     * @brief Calls `-[NSIndexPath getIndexes:]`.
     * @details This method is unsafe because it could potentially cause buffer overruns. You should use -getIndexes:range: instead.
     * @param indexes Argument converted to the Objective-C parameter of the same role.
     */
        void get_indexes(std::uint64_t* indexes) const;
        /**
     * @brief Calls `-[NSIndexPath getIndexes:range:]`.
     * @details \@abstract Copies the indexes stored in this index path from the positions specified by positionRange into indexes. \@param indexes Buffer of at least as many NSUIntegers as specified by the length of positionRange. On return, this memory will hold the index path's indexes. \@param positionRange A range of valid positions within this index path. If the location plus the length of positionRange is greater than the length of this index path, this method raises an NSRangeException. \@discussion It is the developer’s responsibility to allocate the memory for the C array.
     * @param indexes Argument converted to the Objective-C parameter of the same role.
     * @param position_range Argument converted to the Objective-C parameter of the same role.
     */
        void get_indexes(std::uint64_t* indexes, const Range& position_range) const;
        /**
     * @brief Calls `-[NSIndexPath indexAtPosition:]`.
     * @param position Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t index_at_position(std::uint64_t position) const;
        /**
     * @brief Calls `-[NSIndexPath indexPathByAddingIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        IndexPath index_path_by_adding_index(std::uint64_t index) const;
        /**
     * @brief Calls `-[NSIndexPath indexPathByRemovingLastIndex]`.
     * @return The converted Objective-C result.
     */
        IndexPath index_path_by_removing_last_index() const;
        /**
     * @brief Calls `+[NSIndexPath indexPathForItem:inSection:]`.
     * @param item Argument converted to the Objective-C parameter of the same role.
     * @param section Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static IndexPath index_path_for_item(std::int64_t item, std::int64_t section);
        /**
     * @brief Calls `+[NSIndexPath indexPathWithIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static IndexPath index_path_with_index(std::uint64_t index);
        /**
     * @brief Calls `+[NSIndexPath indexPathWithIndexes:length:]`.
     * @param indexes Argument converted to the Objective-C parameter of the same role.
     * @param length Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static IndexPath index_path_with_indexes(const std::uint64_t* indexes, std::uint64_t length);
        /**
     * @brief Returns the `item` property of `NSIndexPath`.
     * @return The converted Objective-C result.
     */
        std::int64_t item() const;
        /**
     * @brief Returns the `length` property of `NSIndexPath`.
     * @return The converted Objective-C result.
     */
        std::uint64_t length() const;
        /**
     * @brief Returns the `section` property of `NSIndexPath`.
     * @return The converted Objective-C result.
     */
        std::int64_t section() const;
    };
}
