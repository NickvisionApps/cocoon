#include "generated/tree_node.h"
#include "internal.h"

namespace cocoon
{
    TreeNode::TreeNode(const Object& model_object) : TreeNode(Adopt{cocoon::internal::retain([[::NSTreeNode alloc] initWithRepresentedObject:cocoon::internal::native_id(model_object)])})
    {
    }

    TreeNode::TreeNode() : TreeNode(Adopt{cocoon::internal::retain([[::NSTreeNode alloc] init])})
    {
    }

    TreeNode::TreeNode(std::nullptr_t) : Object(nullptr)
    {
    }

    TreeNode::TreeNode(Adopt adopt) : Object(adopt)
    {
    }

    TreeNode TreeNode::descendant_node_at_index_path(const IndexPath& index_path) const
    {
        return cocoon::internal::wrap<TreeNode>([cocoon::internal::ns<::NSTreeNode>(this) descendantNodeAtIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)]);
    }

    void TreeNode::sort_with_sort_descriptors(const std::vector<SortDescriptor>& sort_descriptors, bool recursively) const
    {
        [cocoon::internal::ns<::NSTreeNode>(this) sortWithSortDescriptors:cocoon::internal::to_array(sort_descriptors, [](const SortDescriptor& e) -> id
                                                                                                     {
                                                                                                         return cocoon::internal::native<::NSSortDescriptor>(e);
                                                                                                     })
                                                              recursively:static_cast<::BOOL>(recursively)];
    }

    std::vector<TreeNode> TreeNode::child_nodes() const
    {
        return cocoon::internal::from_array<TreeNode>([cocoon::internal::ns<::NSTreeNode>(this) childNodes], [](id e) -> TreeNode
                                                      {
                                                          return cocoon::internal::wrap<TreeNode>((::NSTreeNode*)e);
                                                      });
    }

    IndexPath TreeNode::index_path() const
    {
        return cocoon::internal::wrap<IndexPath>([cocoon::internal::ns<::NSTreeNode>(this) indexPath]);
    }

    bool TreeNode::is_leaf() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTreeNode>(this) isLeaf]);
    }

    std::vector<TreeNode> TreeNode::mutable_child_nodes() const
    {
        return cocoon::internal::from_array<TreeNode>([cocoon::internal::ns<::NSTreeNode>(this) mutableChildNodes], [](id e) -> TreeNode
                                                      {
                                                          return cocoon::internal::wrap<TreeNode>((::NSTreeNode*)e);
                                                      });
    }

    TreeNode TreeNode::parent_node() const
    {
        return cocoon::internal::wrap<TreeNode>([cocoon::internal::ns<::NSTreeNode>(this) parentNode]);
    }

    Object TreeNode::represented_object() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTreeNode>(this) representedObject]);
    }
}
