#include "generated/collection_view_layout_invalidation_context.h"
#include "internal.h"

namespace cocoon
{
    CollectionViewLayoutInvalidationContext::CollectionViewLayoutInvalidationContext() : CollectionViewLayoutInvalidationContext(Adopt{cocoon::internal::retain([[::NSCollectionViewLayoutInvalidationContext alloc] init])})
    {
    }

    CollectionViewLayoutInvalidationContext::CollectionViewLayoutInvalidationContext(std::nullptr_t) : Object(nullptr)
    {
    }

    CollectionViewLayoutInvalidationContext::CollectionViewLayoutInvalidationContext(Adopt adopt) : Object(adopt)
    {
    }

    void CollectionViewLayoutInvalidationContext::invalidate_decoration_elements_of_kind(const std::string& element_kind, const std::vector<IndexPath>& index_paths) const
    {
        [cocoon::internal::ns<::NSCollectionViewLayoutInvalidationContext>(this) invalidateDecorationElementsOfKind:cocoon::internal::to(element_kind)
                                                                                                       atIndexPaths:[NSSet setWithArray:cocoon::internal::to_array(index_paths, [](const IndexPath& e) -> id
                                                                                                                                                                   {
                                                                                                                                                                       return cocoon::internal::native<::NSIndexPath>(e);
                                                                                                                                                                   })]];
    }

    void CollectionViewLayoutInvalidationContext::invalidate_items_at_index_paths(const std::vector<IndexPath>& index_paths) const
    {
        [cocoon::internal::ns<::NSCollectionViewLayoutInvalidationContext>(this) invalidateItemsAtIndexPaths:[NSSet setWithArray:cocoon::internal::to_array(index_paths, [](const IndexPath& e) -> id
                                                                                                                                                            {
                                                                                                                                                                return cocoon::internal::native<::NSIndexPath>(e);
                                                                                                                                                            })]];
    }

    void CollectionViewLayoutInvalidationContext::invalidate_supplementary_elements_of_kind(const std::string& element_kind, const std::vector<IndexPath>& index_paths) const
    {
        [cocoon::internal::ns<::NSCollectionViewLayoutInvalidationContext>(this) invalidateSupplementaryElementsOfKind:cocoon::internal::to(element_kind)
                                                                                                          atIndexPaths:[NSSet setWithArray:cocoon::internal::to_array(index_paths, [](const IndexPath& e) -> id
                                                                                                                                                                      {
                                                                                                                                                                          return cocoon::internal::native<::NSIndexPath>(e);
                                                                                                                                                                      })]];
    }

    Point CollectionViewLayoutInvalidationContext::content_offset_adjustment() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionViewLayoutInvalidationContext>(this) contentOffsetAdjustment]);
    }

    void CollectionViewLayoutInvalidationContext::set_content_offset_adjustment(const Point& value) const
    {
        [cocoon::internal::ns<::NSCollectionViewLayoutInvalidationContext>(this) setContentOffsetAdjustment:cocoon::internal::to(value)];
    }

    Size CollectionViewLayoutInvalidationContext::content_size_adjustment() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionViewLayoutInvalidationContext>(this) contentSizeAdjustment]);
    }

    void CollectionViewLayoutInvalidationContext::set_content_size_adjustment(const Size& value) const
    {
        [cocoon::internal::ns<::NSCollectionViewLayoutInvalidationContext>(this) setContentSizeAdjustment:cocoon::internal::to(value)];
    }

    bool CollectionViewLayoutInvalidationContext::invalidate_data_source_counts() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionViewLayoutInvalidationContext>(this) invalidateDataSourceCounts]);
    }

    bool CollectionViewLayoutInvalidationContext::invalidate_everything() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionViewLayoutInvalidationContext>(this) invalidateEverything]);
    }

    std::map<std::string, std::vector<IndexPath>> CollectionViewLayoutInvalidationContext::invalidated_decoration_index_paths() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, std::vector<IndexPath>>>([cocoon::internal::ns<::NSCollectionViewLayoutInvalidationContext>(this) invalidatedDecorationIndexPaths], [](id k) -> std::string
                                                                                                {
                                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                                },
                                                                                                [](id v) -> std::vector<IndexPath>
                                                                                                {
                                                                                                    return cocoon::internal::from_array<IndexPath>([(NSSet*)v allObjects], [](id e) -> IndexPath
                                                                                                                                                   {
                                                                                                                                                       return cocoon::internal::wrap<IndexPath>((::NSIndexPath*)e);
                                                                                                                                                   });
                                                                                                });
    }

    std::vector<IndexPath> CollectionViewLayoutInvalidationContext::invalidated_item_index_paths() const
    {
        return cocoon::internal::from_array<IndexPath>([[cocoon::internal::ns<::NSCollectionViewLayoutInvalidationContext>(this) invalidatedItemIndexPaths] allObjects], [](id e) -> IndexPath
                                                       {
                                                           return cocoon::internal::wrap<IndexPath>((::NSIndexPath*)e);
                                                       });
    }

    std::map<std::string, std::vector<IndexPath>> CollectionViewLayoutInvalidationContext::invalidated_supplementary_index_paths() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, std::vector<IndexPath>>>([cocoon::internal::ns<::NSCollectionViewLayoutInvalidationContext>(this) invalidatedSupplementaryIndexPaths], [](id k) -> std::string
                                                                                                {
                                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                                },
                                                                                                [](id v) -> std::vector<IndexPath>
                                                                                                {
                                                                                                    return cocoon::internal::from_array<IndexPath>([(NSSet*)v allObjects], [](id e) -> IndexPath
                                                                                                                                                   {
                                                                                                                                                       return cocoon::internal::wrap<IndexPath>((::NSIndexPath*)e);
                                                                                                                                                   });
                                                                                                });
    }
}
