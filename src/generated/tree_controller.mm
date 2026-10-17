#include "generated/tree_controller.h"
#include "internal.h"

namespace cocoon
{
    TreeController::TreeController() : TreeController(Adopt{cocoon::internal::retain([[::NSTreeController alloc] init])})
    {
    }

    TreeController::TreeController(std::nullptr_t) : ObjectController(nullptr)
    {
    }

    TreeController::TreeController(Adopt adopt) : ObjectController(adopt)
    {
    }

    void TreeController::add(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) add:cocoon::internal::native_id(sender)];
    }

    void TreeController::add_child(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) addChild:cocoon::internal::native_id(sender)];
    }

    bool TreeController::add_selection_index_paths(const std::vector<IndexPath>& index_paths) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTreeController>(this) addSelectionIndexPaths:cocoon::internal::to_array(index_paths, [](const IndexPath& e) -> id
                                                                                                       {
                                                                                                           return cocoon::internal::native<::NSIndexPath>(e);
                                                                                                       })]);
    }

    std::string TreeController::children_key_path_for_node(const TreeNode& node) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTreeController>(this) childrenKeyPathForNode:cocoon::internal::native<::NSTreeNode>(node)]);
    }

    std::string TreeController::count_key_path_for_node(const TreeNode& node) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTreeController>(this) countKeyPathForNode:cocoon::internal::native<::NSTreeNode>(node)]);
    }

    void TreeController::insert(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) insert:cocoon::internal::native_id(sender)];
    }

    void TreeController::insert_child(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) insertChild:cocoon::internal::native_id(sender)];
    }

    void TreeController::insert_object(const Object& object, const IndexPath& index_path) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) insertObject:cocoon::internal::native_id(object) atArrangedObjectIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)];
    }

    void TreeController::insert_objects(const std::vector<Object>& objects, const std::vector<IndexPath>& index_paths) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) insertObjects:cocoon::internal::to_array(objects, [](const Object& e) -> id
                                                                     {
                                                                         return cocoon::internal::native_id(e);
                                                                     })
                             atArrangedObjectIndexPaths:cocoon::internal::to_array(index_paths, [](const IndexPath& e) -> id
                                                                     {
                                                                         return cocoon::internal::native<::NSIndexPath>(e);
                                                                     })];
    }

    std::string TreeController::leaf_key_path_for_node(const TreeNode& node) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTreeController>(this) leafKeyPathForNode:cocoon::internal::native<::NSTreeNode>(node)]);
    }

    void TreeController::move_node(const TreeNode& node, const IndexPath& index_path) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) moveNode:cocoon::internal::native<::NSTreeNode>(node) toIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)];
    }

    void TreeController::move_nodes(const std::vector<TreeNode>& nodes, const IndexPath& starting_index_path) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) moveNodes:cocoon::internal::to_array(nodes, [](const TreeNode& e) -> id
                                                                 {
                                                                     return cocoon::internal::native<::NSTreeNode>(e);
                                                                 })
                                        toIndexPath:cocoon::internal::native<::NSIndexPath>(starting_index_path)];
    }

    void TreeController::rearrange_objects() const
    {
        [cocoon::internal::ns<::NSTreeController>(this) rearrangeObjects];
    }

    void TreeController::remove(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) remove:cocoon::internal::native_id(sender)];
    }

    void TreeController::remove_object_at_arranged_object_index_path(const IndexPath& index_path) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) removeObjectAtArrangedObjectIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)];
    }

    void TreeController::remove_objects_at_arranged_object_index_paths(const std::vector<IndexPath>& index_paths) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) removeObjectsAtArrangedObjectIndexPaths:cocoon::internal::to_array(index_paths, [](const IndexPath& e) -> id
                                                                                               {
                                                                                                   return cocoon::internal::native<::NSIndexPath>(e);
                                                                                               })];
    }

    bool TreeController::remove_selection_index_paths(const std::vector<IndexPath>& index_paths) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTreeController>(this) removeSelectionIndexPaths:cocoon::internal::to_array(index_paths, [](const IndexPath& e) -> id
                                                                                                          {
                                                                                                              return cocoon::internal::native<::NSIndexPath>(e);
                                                                                                          })]);
    }

    bool TreeController::set_selection_index_path(const IndexPath& index_path) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTreeController>(this) setSelectionIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)]);
    }

    bool TreeController::set_selection_index_paths(const std::vector<IndexPath>& index_paths) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTreeController>(this) setSelectionIndexPaths:cocoon::internal::to_array(index_paths, [](const IndexPath& e) -> id
                                                                                                       {
                                                                                                           return cocoon::internal::native<::NSIndexPath>(e);
                                                                                                       })]);
    }

    bool TreeController::always_uses_multiple_values_marker() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTreeController>(this) alwaysUsesMultipleValuesMarker]);
    }

    void TreeController::set_always_uses_multiple_values_marker(bool value) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) setAlwaysUsesMultipleValuesMarker:static_cast<::BOOL>(value)];
    }

    TreeNode TreeController::arranged_objects() const
    {
        return cocoon::internal::wrap<TreeNode>([cocoon::internal::ns<::NSTreeController>(this) arrangedObjects]);
    }

    bool TreeController::avoids_empty_selection() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTreeController>(this) avoidsEmptySelection]);
    }

    void TreeController::set_avoids_empty_selection(bool value) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) setAvoidsEmptySelection:static_cast<::BOOL>(value)];
    }

    bool TreeController::can_add_child() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTreeController>(this) canAddChild]);
    }

    bool TreeController::can_insert() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTreeController>(this) canInsert]);
    }

    bool TreeController::can_insert_child() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTreeController>(this) canInsertChild]);
    }

    std::string TreeController::children_key_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTreeController>(this) childrenKeyPath]);
    }

    void TreeController::set_children_key_path(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) setChildrenKeyPath:cocoon::internal::to(value)];
    }

    Object TreeController::content() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTreeController>(this) content]);
    }

    void TreeController::set_content(const Object& value) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) setContent:cocoon::internal::native_id(value)];
    }

    std::string TreeController::count_key_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTreeController>(this) countKeyPath]);
    }

    void TreeController::set_count_key_path(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) setCountKeyPath:cocoon::internal::to(value)];
    }

    std::string TreeController::leaf_key_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTreeController>(this) leafKeyPath]);
    }

    void TreeController::set_leaf_key_path(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) setLeafKeyPath:cocoon::internal::to(value)];
    }

    bool TreeController::preserves_selection() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTreeController>(this) preservesSelection]);
    }

    void TreeController::set_preserves_selection(bool value) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) setPreservesSelection:static_cast<::BOOL>(value)];
    }

    std::vector<TreeNode> TreeController::selected_nodes() const
    {
        return cocoon::internal::from_array<TreeNode>([cocoon::internal::ns<::NSTreeController>(this) selectedNodes], [](id e) -> TreeNode
                                        {
                                            return cocoon::internal::wrap<TreeNode>((::NSTreeNode*)e);
                                        });
    }

    std::vector<Object> TreeController::selected_objects() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSTreeController>(this) selectedObjects], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    IndexPath TreeController::selection_index_path() const
    {
        return cocoon::internal::wrap<IndexPath>([cocoon::internal::ns<::NSTreeController>(this) selectionIndexPath]);
    }

    std::vector<IndexPath> TreeController::selection_index_paths() const
    {
        return cocoon::internal::from_array<IndexPath>([cocoon::internal::ns<::NSTreeController>(this) selectionIndexPaths], [](id e) -> IndexPath
                                         {
                                             return cocoon::internal::wrap<IndexPath>((::NSIndexPath*)e);
                                         });
    }

    bool TreeController::selects_inserted_objects() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTreeController>(this) selectsInsertedObjects]);
    }

    void TreeController::set_selects_inserted_objects(bool value) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) setSelectsInsertedObjects:static_cast<::BOOL>(value)];
    }

    std::vector<SortDescriptor> TreeController::sort_descriptors() const
    {
        return cocoon::internal::from_array<SortDescriptor>([cocoon::internal::ns<::NSTreeController>(this) sortDescriptors], [](id e) -> SortDescriptor
                                              {
                                                  return cocoon::internal::wrap<SortDescriptor>((::NSSortDescriptor*)e);
                                              });
    }

    void TreeController::set_sort_descriptors(const std::vector<SortDescriptor>& value) const
    {
        [cocoon::internal::ns<::NSTreeController>(this) setSortDescriptors:cocoon::internal::to_array(value, [](const SortDescriptor& e) -> id
                                                                          {
                                                                              return cocoon::internal::native<::NSSortDescriptor>(e);
                                                                          })];
    }
}
