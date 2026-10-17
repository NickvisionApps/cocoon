#include "generated/collection_view_compositional_layout_configuration.h"
#include "internal.h"

namespace cocoon
{
    CollectionViewCompositionalLayoutConfiguration::CollectionViewCompositionalLayoutConfiguration() : CollectionViewCompositionalLayoutConfiguration(Adopt{cocoon::internal::retain([[::NSCollectionViewCompositionalLayoutConfiguration alloc] init])})
    {
    }

    CollectionViewCompositionalLayoutConfiguration::CollectionViewCompositionalLayoutConfiguration(std::nullptr_t) : Object(nullptr)
    {
    }

    CollectionViewCompositionalLayoutConfiguration::CollectionViewCompositionalLayoutConfiguration(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<CollectionLayoutBoundarySupplementaryItem> CollectionViewCompositionalLayoutConfiguration::boundary_supplementary_items() const
    {
        return cocoon::internal::from_array<CollectionLayoutBoundarySupplementaryItem>([cocoon::internal::ns<::NSCollectionViewCompositionalLayoutConfiguration>(this) boundarySupplementaryItems], [](id e) -> CollectionLayoutBoundarySupplementaryItem
                                                                                       {
                                                                                           return cocoon::internal::wrap<CollectionLayoutBoundarySupplementaryItem>((::NSCollectionLayoutBoundarySupplementaryItem*)e);
                                                                                       });
    }

    void CollectionViewCompositionalLayoutConfiguration::set_boundary_supplementary_items(const std::vector<CollectionLayoutBoundarySupplementaryItem>& value) const
    {
        [cocoon::internal::ns<::NSCollectionViewCompositionalLayoutConfiguration>(this) setBoundarySupplementaryItems:cocoon::internal::to_array(value, [](const CollectionLayoutBoundarySupplementaryItem& e) -> id
                                                                                                                                                 {
                                                                                                                                                     return cocoon::internal::native<::NSCollectionLayoutBoundarySupplementaryItem>(e);
                                                                                                                                                 })];
    }

    double CollectionViewCompositionalLayoutConfiguration::inter_section_spacing() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSCollectionViewCompositionalLayoutConfiguration>(this) interSectionSpacing]);
    }

    void CollectionViewCompositionalLayoutConfiguration::set_inter_section_spacing(double value) const
    {
        [cocoon::internal::ns<::NSCollectionViewCompositionalLayoutConfiguration>(this) setInterSectionSpacing:static_cast<::CGFloat>(value)];
    }

    CollectionViewScrollDirection CollectionViewCompositionalLayoutConfiguration::scroll_direction() const
    {
        return static_cast<CollectionViewScrollDirection>([cocoon::internal::ns<::NSCollectionViewCompositionalLayoutConfiguration>(this) scrollDirection]);
    }

    void CollectionViewCompositionalLayoutConfiguration::set_scroll_direction(CollectionViewScrollDirection value) const
    {
        [cocoon::internal::ns<::NSCollectionViewCompositionalLayoutConfiguration>(this) setScrollDirection:static_cast<::NSCollectionViewScrollDirection>(value)];
    }
}
