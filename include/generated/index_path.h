#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSIndexPath` (Foundation).
     * @details A list of indexes that together represent the path to a specific location in a tree of nested arrays. In Swift, this object bridges to ''IndexPath''; use ''NSIndexPath'' when you need reference semantics or other Foundation-specific behavior. Each index in an index path represents the index into an array of children from one node in the tree to another, deeper, node. For example, the index path '1.4.3.2' specifies the path shown in [Figure 1](/documentation/foundation/nsindexpath\#1965825). ![Index path “1.4.3.2”](media-1965825) > Note: > The UIKit framework adds programming interfaces to the 'NSIndexPath' class of the Foundation framework to facilitate the identification of rows and sections in \<doc://com.apple.documentation/documentation/uikit/uitableview> objects and the identification of items and sections in \<doc://com.apple.documentation/documentation/uikit/uicollectionview> objects. The API consists of class factory methods and properties for accessing the various indexed values. You use the factory methods to create an index path for the corresponding table view or collection view. > Important: > The Swift overlay to the Foundation framework provides the ''IndexPath'' structure, which bridges to the ''NSIndexPath'' class. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>.
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
     * @details Indicates the depth-first traversal order of the receiving index path and another index path. - Parameter otherObject: Index path to compare. This value must not be 'nil'. If the value is 'nil', the behavior is undefined. - Returns: The depth-first traversal ordering of the receiving index path and 'otherObject'.
     * @param other_object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ComparisonResult compare(const IndexPath& other_object) const;
        /**
     * @brief Calls `-[NSIndexPath getIndexes:]`.
     * @details Copies the objects contained in the index path into indexes. This method is unsafe because it could potentially cause buffer overruns. You should use 'getIndexes:range:' instead. You must allocate the memory for the C array. - Parameter indexes: Pointer to a C array of objects of size at least the length of the index path. On return, the index path's indexes.
     * @param indexes Argument converted to the Objective-C parameter of the same role.
     */
        void get_indexes(std::uint64_t* indexes) const;
        /**
     * @brief Calls `-[NSIndexPath getIndexes:range:]`.
     * @details Copies the indexes stored in the index path from the positions specified by the position range into the specified indexes. It is the developer’s responsibility to allocate the memory for the C array. - Parameters: - indexes: Buffer of at least as many 'NSUInteger' values as specified by the length of 'positionRange'. On return, this memory will hold the index path’s indexes. - positionRange: A range of valid positions within this index path. If the location plus the length of 'positionRange' is greater than the length of this index path, this method raises an 'NSRangeException'.
     * @param indexes Argument converted to the Objective-C parameter of the same role.
     * @param position_range Argument converted to the Objective-C parameter of the same role.
     */
        void get_indexes(std::uint64_t* indexes, const Range& position_range) const;
        /**
     * @brief Calls `-[NSIndexPath indexAtPosition:]`.
     * @details Provides the value at a particular node in the index path. - Parameter position: Index value of the desired node. Node numbering starts at zero. - Returns: The index value at 'position' or 'NSNotFound' if the node is outside the range of the index path.
     * @param position Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t index_at_position(std::uint64_t position) const;
        /**
     * @brief Calls `-[NSIndexPath indexPathByAddingIndex:]`.
     * @details Returns an index path containing the nodes in the receiving index path plus another given index. - Parameter index: Index to append to the index path's indexes. - Returns: A new index path containing the receiving index path's indexes and 'index'.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        IndexPath index_path_by_adding_index(std::uint64_t index) const;
        /**
     * @brief Calls `-[NSIndexPath indexPathByRemovingLastIndex]`.
     * @details Returns an index path with the nodes in the receiving index path, excluding the last one. Returns an empty 'NSIndexPath' instance if the receiving index path's length is 1 or less. - Returns: A new index path with the receiving index path's indexes, excluding the last one.
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
     * @details Creates a one-node index path. - Parameter index: Index of the item in node 0 to point to. - Returns: One-node index path with 'index'.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static IndexPath index_path_with_index(std::uint64_t index);
        /**
     * @brief Calls `+[NSIndexPath indexPathWithIndexes:length:]`.
     * @details Creates an index path with one or more nodes. - Parameters: - indexes: Array of indexes to make up the index path. - length: Number of nodes to include in the index path. - Returns: Index path with 'indexes' up to 'length'.
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
     * @details The number of nodes in the index path.
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
