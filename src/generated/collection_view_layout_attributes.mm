#include "generated/collection_view_layout_attributes.h"
#include "internal.h"

namespace cocoon
{
    CollectionViewLayoutAttributes::CollectionViewLayoutAttributes() : CollectionViewLayoutAttributes(Adopt{cocoon::internal::retain([[::NSCollectionViewLayoutAttributes alloc] init])})
    {
    }

    CollectionViewLayoutAttributes::CollectionViewLayoutAttributes(std::nullptr_t) : Object(nullptr)
    {
    }

    CollectionViewLayoutAttributes::CollectionViewLayoutAttributes(Adopt adopt) : Object(adopt)
    {
    }

    CollectionViewLayoutAttributes CollectionViewLayoutAttributes::layout_attributes_for_decoration_view_of_kind(const std::string& decoration_view_kind, const IndexPath& index_path)
    {
        return cocoon::internal::wrap<CollectionViewLayoutAttributes>([::NSCollectionViewLayoutAttributes layoutAttributesForDecorationViewOfKind:cocoon::internal::to(decoration_view_kind) withIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)]);
    }

    CollectionViewLayoutAttributes CollectionViewLayoutAttributes::layout_attributes_for_inter_item_gap_before_index_path(const IndexPath& index_path)
    {
        return cocoon::internal::wrap<CollectionViewLayoutAttributes>([::NSCollectionViewLayoutAttributes layoutAttributesForInterItemGapBeforeIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)]);
    }

    CollectionViewLayoutAttributes CollectionViewLayoutAttributes::layout_attributes_for_item_with_index_path(const IndexPath& index_path)
    {
        return cocoon::internal::wrap<CollectionViewLayoutAttributes>([::NSCollectionViewLayoutAttributes layoutAttributesForItemWithIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)]);
    }

    CollectionViewLayoutAttributes CollectionViewLayoutAttributes::layout_attributes_for_supplementary_view_of_kind(const std::string& element_kind, const IndexPath& index_path)
    {
        return cocoon::internal::wrap<CollectionViewLayoutAttributes>([::NSCollectionViewLayoutAttributes layoutAttributesForSupplementaryViewOfKind:cocoon::internal::to(element_kind) withIndexPath:cocoon::internal::native<::NSIndexPath>(index_path)]);
    }

    double CollectionViewLayoutAttributes::alpha() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSCollectionViewLayoutAttributes>(this) alpha]);
    }

    void CollectionViewLayoutAttributes::set_alpha(double value) const
    {
        [cocoon::internal::ns<::NSCollectionViewLayoutAttributes>(this) setAlpha:static_cast<::CGFloat>(value)];
    }

    Rect CollectionViewLayoutAttributes::frame() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionViewLayoutAttributes>(this) frame]);
    }

    void CollectionViewLayoutAttributes::set_frame(const Rect& value) const
    {
        [cocoon::internal::ns<::NSCollectionViewLayoutAttributes>(this) setFrame:cocoon::internal::to(value)];
    }

    bool CollectionViewLayoutAttributes::is_hidden() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionViewLayoutAttributes>(this) isHidden]);
    }

    void CollectionViewLayoutAttributes::set_hidden(bool value) const
    {
        [cocoon::internal::ns<::NSCollectionViewLayoutAttributes>(this) setHidden:static_cast<::BOOL>(value)];
    }

    IndexPath CollectionViewLayoutAttributes::index_path() const
    {
        return cocoon::internal::wrap<IndexPath>([cocoon::internal::ns<::NSCollectionViewLayoutAttributes>(this) indexPath]);
    }

    void CollectionViewLayoutAttributes::set_index_path(const IndexPath& value) const
    {
        [cocoon::internal::ns<::NSCollectionViewLayoutAttributes>(this) setIndexPath:cocoon::internal::native<::NSIndexPath>(value)];
    }

    CollectionElementCategory CollectionViewLayoutAttributes::represented_element_category() const
    {
        return static_cast<CollectionElementCategory>([cocoon::internal::ns<::NSCollectionViewLayoutAttributes>(this) representedElementCategory]);
    }

    std::string CollectionViewLayoutAttributes::represented_element_kind() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionViewLayoutAttributes>(this) representedElementKind]);
    }

    Size CollectionViewLayoutAttributes::size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionViewLayoutAttributes>(this) size]);
    }

    void CollectionViewLayoutAttributes::set_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSCollectionViewLayoutAttributes>(this) setSize:cocoon::internal::to(value)];
    }

    std::int64_t CollectionViewLayoutAttributes::z_index() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSCollectionViewLayoutAttributes>(this) zIndex]);
    }

    void CollectionViewLayoutAttributes::set_z_index(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSCollectionViewLayoutAttributes>(this) setZIndex:static_cast<::NSInteger>(value)];
    }
}
