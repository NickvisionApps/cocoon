#include "generated/collection_view_flow_layout.h"
#include "internal.h"

namespace cocoon
{
    CollectionViewFlowLayout::CollectionViewFlowLayout() : CollectionViewFlowLayout(Adopt{cocoon::internal::retain([[::NSCollectionViewFlowLayout alloc] init])})
    {
    }

    CollectionViewFlowLayout::CollectionViewFlowLayout(std::nullptr_t) : CollectionViewLayout(nullptr)
    {
    }

    CollectionViewFlowLayout::CollectionViewFlowLayout(Adopt adopt) : CollectionViewLayout(adopt)
    {
    }

    void CollectionViewFlowLayout::collapse_section_at_index(std::uint64_t section_index) const
    {
        [cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) collapseSectionAtIndex:static_cast<::NSUInteger>(section_index)];
    }

    void CollectionViewFlowLayout::expand_section_at_index(std::uint64_t section_index) const
    {
        [cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) expandSectionAtIndex:static_cast<::NSUInteger>(section_index)];
    }

    bool CollectionViewFlowLayout::section_at_index_is_collapsed(std::uint64_t section_index) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) sectionAtIndexIsCollapsed:static_cast<::NSUInteger>(section_index)]);
    }

    Size CollectionViewFlowLayout::estimated_item_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) estimatedItemSize]);
    }

    void CollectionViewFlowLayout::set_estimated_item_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) setEstimatedItemSize:cocoon::internal::to(value)];
    }

    Size CollectionViewFlowLayout::footer_reference_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) footerReferenceSize]);
    }

    void CollectionViewFlowLayout::set_footer_reference_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) setFooterReferenceSize:cocoon::internal::to(value)];
    }

    Size CollectionViewFlowLayout::header_reference_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) headerReferenceSize]);
    }

    void CollectionViewFlowLayout::set_header_reference_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) setHeaderReferenceSize:cocoon::internal::to(value)];
    }

    Size CollectionViewFlowLayout::item_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) itemSize]);
    }

    void CollectionViewFlowLayout::set_item_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) setItemSize:cocoon::internal::to(value)];
    }

    double CollectionViewFlowLayout::minimum_interitem_spacing() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) minimumInteritemSpacing]);
    }

    void CollectionViewFlowLayout::set_minimum_interitem_spacing(double value) const
    {
        [cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) setMinimumInteritemSpacing:static_cast<::CGFloat>(value)];
    }

    double CollectionViewFlowLayout::minimum_line_spacing() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) minimumLineSpacing]);
    }

    void CollectionViewFlowLayout::set_minimum_line_spacing(double value) const
    {
        [cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) setMinimumLineSpacing:static_cast<::CGFloat>(value)];
    }

    CollectionViewScrollDirection CollectionViewFlowLayout::scroll_direction() const
    {
        return static_cast<CollectionViewScrollDirection>([cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) scrollDirection]);
    }

    void CollectionViewFlowLayout::set_scroll_direction(CollectionViewScrollDirection value) const
    {
        [cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) setScrollDirection:static_cast<::NSCollectionViewScrollDirection>(value)];
    }

    bool CollectionViewFlowLayout::section_footers_pin_to_visible_bounds() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) sectionFootersPinToVisibleBounds]);
    }

    void CollectionViewFlowLayout::set_section_footers_pin_to_visible_bounds(bool value) const
    {
        [cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) setSectionFootersPinToVisibleBounds:static_cast<::BOOL>(value)];
    }

    bool CollectionViewFlowLayout::section_headers_pin_to_visible_bounds() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) sectionHeadersPinToVisibleBounds]);
    }

    void CollectionViewFlowLayout::set_section_headers_pin_to_visible_bounds(bool value) const
    {
        [cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) setSectionHeadersPinToVisibleBounds:static_cast<::BOOL>(value)];
    }

    Insets CollectionViewFlowLayout::section_inset() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) sectionInset]);
    }

    void CollectionViewFlowLayout::set_section_inset(const Insets& value) const
    {
        [cocoon::internal::ns<::NSCollectionViewFlowLayout>(this) setSectionInset:cocoon::internal::to(value)];
    }
}
