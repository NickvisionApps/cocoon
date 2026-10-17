#include "generated/collection_layout_section.h"
#include "internal.h"

namespace cocoon
{
    CollectionLayoutSection::CollectionLayoutSection() : Object(nullptr)
    {
    }

    CollectionLayoutSection::CollectionLayoutSection(std::nullptr_t) : Object(nullptr)
    {
    }

    CollectionLayoutSection::CollectionLayoutSection(Adopt adopt) : Object(adopt)
    {
    }

    CollectionLayoutSection CollectionLayoutSection::section_with_group(const CollectionLayoutGroup& group)
    {
        return cocoon::internal::wrap<CollectionLayoutSection>([::NSCollectionLayoutSection sectionWithGroup:cocoon::internal::native<::NSCollectionLayoutGroup>(group)]);
    }

    std::vector<CollectionLayoutBoundarySupplementaryItem> CollectionLayoutSection::boundary_supplementary_items() const
    {
        return cocoon::internal::from_array<CollectionLayoutBoundarySupplementaryItem>([cocoon::internal::ns<::NSCollectionLayoutSection>(this) boundarySupplementaryItems], [](id e) -> CollectionLayoutBoundarySupplementaryItem
                                                                         {
                                                                             return cocoon::internal::wrap<CollectionLayoutBoundarySupplementaryItem>((::NSCollectionLayoutBoundarySupplementaryItem*)e);
                                                                         });
    }

    void CollectionLayoutSection::set_boundary_supplementary_items(const std::vector<CollectionLayoutBoundarySupplementaryItem>& value) const
    {
        [cocoon::internal::ns<::NSCollectionLayoutSection>(this) setBoundarySupplementaryItems:cocoon::internal::to_array(value, [](const CollectionLayoutBoundarySupplementaryItem& e) -> id
                                                                                              {
                                                                                                  return cocoon::internal::native<::NSCollectionLayoutBoundarySupplementaryItem>(e);
                                                                                              })];
    }

    DirectionalEdgeInsets CollectionLayoutSection::content_insets() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionLayoutSection>(this) contentInsets]);
    }

    void CollectionLayoutSection::set_content_insets(const DirectionalEdgeInsets& value) const
    {
        [cocoon::internal::ns<::NSCollectionLayoutSection>(this) setContentInsets:cocoon::internal::to(value)];
    }

    std::vector<CollectionLayoutDecorationItem> CollectionLayoutSection::decoration_items() const
    {
        return cocoon::internal::from_array<CollectionLayoutDecorationItem>([cocoon::internal::ns<::NSCollectionLayoutSection>(this) decorationItems], [](id e) -> CollectionLayoutDecorationItem
                                                              {
                                                                  return cocoon::internal::wrap<CollectionLayoutDecorationItem>((::NSCollectionLayoutDecorationItem*)e);
                                                              });
    }

    void CollectionLayoutSection::set_decoration_items(const std::vector<CollectionLayoutDecorationItem>& value) const
    {
        [cocoon::internal::ns<::NSCollectionLayoutSection>(this) setDecorationItems:cocoon::internal::to_array(value, [](const CollectionLayoutDecorationItem& e) -> id
                                                                                   {
                                                                                       return cocoon::internal::native<::NSCollectionLayoutDecorationItem>(e);
                                                                                   })];
    }

    double CollectionLayoutSection::inter_group_spacing() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSCollectionLayoutSection>(this) interGroupSpacing]);
    }

    void CollectionLayoutSection::set_inter_group_spacing(double value) const
    {
        [cocoon::internal::ns<::NSCollectionLayoutSection>(this) setInterGroupSpacing:static_cast<::CGFloat>(value)];
    }

    CollectionLayoutSectionOrthogonalScrollingBehavior CollectionLayoutSection::orthogonal_scrolling_behavior() const
    {
        return static_cast<CollectionLayoutSectionOrthogonalScrollingBehavior>([cocoon::internal::ns<::NSCollectionLayoutSection>(this) orthogonalScrollingBehavior]);
    }

    void CollectionLayoutSection::set_orthogonal_scrolling_behavior(CollectionLayoutSectionOrthogonalScrollingBehavior value) const
    {
        [cocoon::internal::ns<::NSCollectionLayoutSection>(this) setOrthogonalScrollingBehavior:static_cast<::NSCollectionLayoutSectionOrthogonalScrollingBehavior>(value)];
    }

    bool CollectionLayoutSection::supplementaries_follow_content_insets() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionLayoutSection>(this) supplementariesFollowContentInsets]);
    }

    void CollectionLayoutSection::set_supplementaries_follow_content_insets(bool value) const
    {
        [cocoon::internal::ns<::NSCollectionLayoutSection>(this) setSupplementariesFollowContentInsets:static_cast<::BOOL>(value)];
    }

    std::function<void(std::vector<Object>, Point, Object)> CollectionLayoutSection::visible_items_invalidation_handler() const
    {
        return [&]() -> std::function<void(std::vector<Object>, Point, Object)>
        {
            auto blk = (::NSCollectionLayoutSectionVisibleItemsInvalidationHandler)([cocoon::internal::ns<::NSCollectionLayoutSection>(this) visibleItemsInvalidationHandler]);
            if (!blk)
            {
                return {};
            }
            return [blk](std::vector<Object> a16_0, Point a16_1, Object a16_2) -> void
            {
                blk(cocoon::internal::to_array(a16_0, [](const Object& e) -> id
                                 {
                                     return cocoon::internal::native_id(e);
                                 }),
                    cocoon::internal::to(a16_1), cocoon::internal::native_id(a16_2));
            };
        }();
    }

    void CollectionLayoutSection::set_visible_items_invalidation_handler(std::function<void(std::vector<Object>, Point, Object)> value) const
    {
        [cocoon::internal::ns<::NSCollectionLayoutSection>(this) setVisibleItemsInvalidationHandler:(value ? (::NSCollectionLayoutSectionVisibleItemsInvalidationHandler) ^ void(NSArray * a17_0, ::NSPoint a17_1, id a17_2) { value(cocoon::internal::from_array<Object>(a17_0, [](id e) -> Object
                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                  return cocoon::internal::wrap<Object>(e);
                                                                                                                                                                                                                                              }),
                                                                                                                                                                                                                       cocoon::internal::from(a17_1), cocoon::internal::wrap<Object>(a17_2)); } : (::NSCollectionLayoutSectionVisibleItemsInvalidationHandler)nil)];
    }
}
