#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class IndexPath;
    class SortDescriptor;

    /**
     * @brief C++ handle for the Objective-C class `NSTreeNode` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TreeNode tree_node;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TreeNode tree_node{};
     * tree_node.descendant_node_at_index_path(cocoon::IndexPath());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstreenode
     */
    class TreeNode : public Object
    {
    public:
        /// @brief Creates a new `NSTreeNode` instance and returns a handle to it.
        explicit TreeNode(const Object& model_object);
        /// @brief Creates a new `NSTreeNode` instance and returns a handle to it.
        explicit TreeNode();
        /// @brief Creates a null handle that refers to no native object.
        TreeNode(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TreeNode(Adopt adopt);
        /**
     * @brief Calls `-[NSTreeNode descendantNodeAtIndexPath:]`.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        TreeNode descendant_node_at_index_path(const IndexPath& index_path) const;
        /**
     * @brief Calls `-[NSTreeNode sortWithSortDescriptors:recursively:]`.
     * @param sort_descriptors Argument converted to the Objective-C parameter of the same role.
     * @param recursively Argument converted to the Objective-C parameter of the same role.
     */
        void sort_with_sort_descriptors(const std::vector<SortDescriptor>& sort_descriptors, bool recursively) const;
        /**
     * @brief Calls `+[NSTreeNode treeNodeWithRepresentedObject:]`.
     * @param model_object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TreeNode tree_node_with_represented_object(const Object& model_object);
        /**
     * @brief Returns the `childNodes` property of `NSTreeNode`.
     * @return The converted Objective-C result.
     */
        std::vector<TreeNode> child_nodes() const;
        /**
     * @brief Returns the `indexPath` property of `NSTreeNode`.
     * @return The converted Objective-C result.
     */
        IndexPath index_path() const;
        /**
     * @brief Returns the `leaf` property of `NSTreeNode`.
     * @return The converted Objective-C result.
     */
        bool is_leaf() const;
        /**
     * @brief Returns the `mutableChildNodes` property of `NSTreeNode`.
     * @return The converted Objective-C result.
     */
        std::vector<TreeNode> mutable_child_nodes() const;
        /**
     * @brief Returns the `parentNode` property of `NSTreeNode`.
     * @return The converted Objective-C result.
     */
        TreeNode parent_node() const;
        /**
     * @brief Returns the `representedObject` property of `NSTreeNode`.
     * @return The converted Objective-C result.
     */
        Object represented_object() const;
    };
}
