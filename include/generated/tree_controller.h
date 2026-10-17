#pragma once

#include "generated/enums.h"
#include "generated/object_controller.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class IndexPath;
    class SortDescriptor;
    class TreeNode;

    /**
     * @brief C++ handle for the Objective-C class `NSTreeController` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ObjectController.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TreeController tree_controller;
     * tree_controller.set_always_uses_multiple_values_marker(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TreeController tree_controller{};
     * tree_controller.set_always_uses_multiple_values_marker(true);
     * auto always_uses_multiple_values_marker = tree_controller.always_uses_multiple_values_marker();
     * tree_controller.set_avoids_empty_selection(true);
     * auto avoids_empty_selection = tree_controller.avoids_empty_selection();
     * tree_controller.set_children_key_path("text");
     * auto children_key_path = tree_controller.children_key_path();
     * tree_controller.children_key_path_for_node(cocoon::TreeNode());
     * tree_controller.count_key_path_for_node(cocoon::TreeNode());
     * tree_controller.leaf_key_path_for_node(cocoon::TreeNode());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstreecontroller
     */
    class TreeController : public ObjectController
    {
    public:
        /// @brief Creates a new `NSTreeController` instance and returns a handle to it.
        explicit TreeController();
        /// @brief Creates a null handle that refers to no native object.
        TreeController(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TreeController(Adopt adopt);
        using ObjectController::add;
        using ObjectController::content;
        using ObjectController::remove;
        using ObjectController::selected_objects;
        using ObjectController::set_content;
        /**
     * @brief Calls `-[NSTreeController add:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void add(const Object& sender) const;
        /**
     * @brief Calls `-[NSTreeController addChild:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void add_child(const Object& sender) const;
        /**
     * @brief Calls `-[NSTreeController addSelectionIndexPaths:]`.
     * @param index_paths Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool add_selection_index_paths(const std::vector<IndexPath>& index_paths) const;
        /**
     * @brief Calls `-[NSTreeController childrenKeyPathForNode:]`.
     * @param node Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string children_key_path_for_node(const TreeNode& node) const;
        /**
     * @brief Calls `-[NSTreeController countKeyPathForNode:]`.
     * @param node Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string count_key_path_for_node(const TreeNode& node) const;
        /**
     * @brief Calls `-[NSTreeController insert:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void insert(const Object& sender) const;
        /**
     * @brief Calls `-[NSTreeController insertChild:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void insert_child(const Object& sender) const;
        /**
     * @brief Calls `-[NSTreeController insertObject:atArrangedObjectIndexPath:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     */
        void insert_object(const Object& object, const IndexPath& index_path) const;
        /**
     * @brief Calls `-[NSTreeController insertObjects:atArrangedObjectIndexPaths:]`.
     * @param objects Argument converted to the Objective-C parameter of the same role.
     * @param index_paths Argument converted to the Objective-C parameter of the same role.
     */
        void insert_objects(const std::vector<Object>& objects, const std::vector<IndexPath>& index_paths) const;
        /**
     * @brief Calls `-[NSTreeController leafKeyPathForNode:]`.
     * @param node Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string leaf_key_path_for_node(const TreeNode& node) const;
        /**
     * @brief Calls `-[NSTreeController moveNode:toIndexPath:]`.
     * @param node Argument converted to the Objective-C parameter of the same role.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     */
        void move_node(const TreeNode& node, const IndexPath& index_path) const;
        /**
     * @brief Calls `-[NSTreeController moveNodes:toIndexPath:]`.
     * @param nodes Argument converted to the Objective-C parameter of the same role.
     * @param starting_index_path Argument converted to the Objective-C parameter of the same role.
     */
        void move_nodes(const std::vector<TreeNode>& nodes, const IndexPath& starting_index_path) const;
        /**
     * @brief Calls `-[NSTreeController rearrangeObjects]`.
     */
        void rearrange_objects() const;
        /**
     * @brief Calls `-[NSTreeController remove:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void remove(const Object& sender) const;
        /**
     * @brief Calls `-[NSTreeController removeObjectAtArrangedObjectIndexPath:]`.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     */
        void remove_object_at_arranged_object_index_path(const IndexPath& index_path) const;
        /**
     * @brief Calls `-[NSTreeController removeObjectsAtArrangedObjectIndexPaths:]`.
     * @param index_paths Argument converted to the Objective-C parameter of the same role.
     */
        void remove_objects_at_arranged_object_index_paths(const std::vector<IndexPath>& index_paths) const;
        /**
     * @brief Calls `-[NSTreeController removeSelectionIndexPaths:]`.
     * @param index_paths Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool remove_selection_index_paths(const std::vector<IndexPath>& index_paths) const;
        /**
     * @brief Calls `-[NSTreeController setSelectionIndexPath:]`.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_selection_index_path(const IndexPath& index_path) const;
        /**
     * @brief Calls `-[NSTreeController setSelectionIndexPaths:]`.
     * @param index_paths Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_selection_index_paths(const std::vector<IndexPath>& index_paths) const;
        /**
     * @brief Returns the `alwaysUsesMultipleValuesMarker` property of `NSTreeController`.
     * @return The converted Objective-C result.
     */
        bool always_uses_multiple_values_marker() const;
        /**
     * @brief Sets the `alwaysUsesMultipleValuesMarker` property of `NSTreeController`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_always_uses_multiple_values_marker(bool value) const;
        /**
     * @brief Returns the `arrangedObjects` property of `NSTreeController`.
     * @return The converted Objective-C result.
     */
        TreeNode arranged_objects() const;
        /**
     * @brief Returns the `avoidsEmptySelection` property of `NSTreeController`.
     * @return The converted Objective-C result.
     */
        bool avoids_empty_selection() const;
        /**
     * @brief Sets the `avoidsEmptySelection` property of `NSTreeController`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_avoids_empty_selection(bool value) const;
        /**
     * @brief Returns the `canAddChild` property of `NSTreeController`.
     * @return The converted Objective-C result.
     */
        bool can_add_child() const;
        /**
     * @brief Returns the `canInsert` property of `NSTreeController`.
     * @return The converted Objective-C result.
     */
        bool can_insert() const;
        /**
     * @brief Returns the `canInsertChild` property of `NSTreeController`.
     * @return The converted Objective-C result.
     */
        bool can_insert_child() const;
        /**
     * @brief Returns the `childrenKeyPath` property of `NSTreeController`.
     * @return The converted Objective-C result.
     */
        std::string children_key_path() const;
        /**
     * @brief Sets the `childrenKeyPath` property of `NSTreeController`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_children_key_path(const std::string& value) const;
        /**
     * @brief Returns the `content` property of `NSTreeController`.
     * @return The converted Objective-C result.
     */
        Object content() const;
        /**
     * @brief Sets the `content` property of `NSTreeController`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content(const Object& value) const;
        /**
     * @brief Returns the `countKeyPath` property of `NSTreeController`.
     * @return The converted Objective-C result.
     */
        std::string count_key_path() const;
        /**
     * @brief Sets the `countKeyPath` property of `NSTreeController`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_count_key_path(const std::string& value) const;
        /**
     * @brief Returns the `leafKeyPath` property of `NSTreeController`.
     * @return The converted Objective-C result.
     */
        std::string leaf_key_path() const;
        /**
     * @brief Sets the `leafKeyPath` property of `NSTreeController`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_leaf_key_path(const std::string& value) const;
        /**
     * @brief Returns the `preservesSelection` property of `NSTreeController`.
     * @return The converted Objective-C result.
     */
        bool preserves_selection() const;
        /**
     * @brief Sets the `preservesSelection` property of `NSTreeController`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preserves_selection(bool value) const;
        /**
     * @brief Returns the `selectedNodes` property of `NSTreeController`.
     * @return The converted Objective-C result.
     */
        std::vector<TreeNode> selected_nodes() const;
        /**
     * @brief Returns the `selectedObjects` property of `NSTreeController`.
     * @details All selection modification methods returning a BOOL indicate through that flag whether changing the selection was successful (changing the selection might trigger a commitEditing call which fails and thus deny's the selection change).
     * @return The converted Objective-C result.
     */
        std::vector<Object> selected_objects() const;
        /**
     * @brief Returns the `selectionIndexPath` property of `NSTreeController`.
     * @return The converted Objective-C result.
     */
        IndexPath selection_index_path() const;
        /**
     * @brief Returns the `selectionIndexPaths` property of `NSTreeController`.
     * @return The converted Objective-C result.
     */
        std::vector<IndexPath> selection_index_paths() const;
        /**
     * @brief Returns the `selectsInsertedObjects` property of `NSTreeController`.
     * @return The converted Objective-C result.
     */
        bool selects_inserted_objects() const;
        /**
     * @brief Sets the `selectsInsertedObjects` property of `NSTreeController`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selects_inserted_objects(bool value) const;
        /**
     * @brief Returns the `sortDescriptors` property of `NSTreeController`.
     * @return The converted Objective-C result.
     */
        std::vector<SortDescriptor> sort_descriptors() const;
        /**
     * @brief Sets the `sortDescriptors` property of `NSTreeController`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_sort_descriptors(const std::vector<SortDescriptor>& value) const;
    };
}
