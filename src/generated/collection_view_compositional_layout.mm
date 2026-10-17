#include "generated/collection_view_compositional_layout.h"
#include "internal.h"

namespace cocoon
{
    CollectionViewCompositionalLayout::CollectionViewCompositionalLayout(const CollectionLayoutSection& section) : CollectionViewCompositionalLayout(Adopt{cocoon::internal::retain([[::NSCollectionViewCompositionalLayout alloc] initWithSection:cocoon::internal::native<::NSCollectionLayoutSection>(section)])})
    {
    }

    CollectionViewCompositionalLayout::CollectionViewCompositionalLayout(const CollectionLayoutSection& section, const CollectionViewCompositionalLayoutConfiguration& configuration) : CollectionViewCompositionalLayout(Adopt{cocoon::internal::retain([[::NSCollectionViewCompositionalLayout alloc] initWithSection:cocoon::internal::native<::NSCollectionLayoutSection>(section) configuration:cocoon::internal::native<::NSCollectionViewCompositionalLayoutConfiguration>(configuration)])})
    {
    }

    CollectionViewCompositionalLayout::CollectionViewCompositionalLayout(std::function<CollectionLayoutSection(std::int64_t, Object)> section_provider) : CollectionViewCompositionalLayout(Adopt{cocoon::internal::retain([[::NSCollectionViewCompositionalLayout alloc] initWithSectionProvider:(section_provider ? (::NSCollectionViewCompositionalLayoutSectionProvider) ^ ::NSCollectionLayoutSection * (::NSInteger a14_0, id a14_1) { auto __r = section_provider(static_cast<std::int64_t>(a14_0), cocoon::internal::wrap<Object>(a14_1)); return cocoon::internal::native<::NSCollectionLayoutSection>(__r); } : (::NSCollectionViewCompositionalLayoutSectionProvider)nil)])})
    {
    }

    CollectionViewCompositionalLayout::CollectionViewCompositionalLayout(std::function<CollectionLayoutSection(std::int64_t, Object)> section_provider, const CollectionViewCompositionalLayoutConfiguration& configuration) : CollectionViewCompositionalLayout(Adopt{cocoon::internal::retain([[::NSCollectionViewCompositionalLayout alloc] initWithSectionProvider:(section_provider ? (::NSCollectionViewCompositionalLayoutSectionProvider) ^ ::NSCollectionLayoutSection * (::NSInteger a15_0, id a15_1) { auto __r = section_provider(static_cast<std::int64_t>(a15_0), cocoon::internal::wrap<Object>(a15_1)); return cocoon::internal::native<::NSCollectionLayoutSection>(__r); } : (::NSCollectionViewCompositionalLayoutSectionProvider)nil) configuration:cocoon::internal::native<::NSCollectionViewCompositionalLayoutConfiguration>(configuration)])})
    {
    }

    CollectionViewCompositionalLayout::CollectionViewCompositionalLayout() : CollectionViewLayout(nullptr)
    {
    }

    CollectionViewCompositionalLayout::CollectionViewCompositionalLayout(std::nullptr_t) : CollectionViewLayout(nullptr)
    {
    }

    CollectionViewCompositionalLayout::CollectionViewCompositionalLayout(Adopt adopt) : CollectionViewLayout(adopt)
    {
    }

    CollectionViewCompositionalLayoutConfiguration CollectionViewCompositionalLayout::configuration() const
    {
        return cocoon::internal::wrap<CollectionViewCompositionalLayoutConfiguration>([cocoon::internal::ns<::NSCollectionViewCompositionalLayout>(this) configuration]);
    }

    void CollectionViewCompositionalLayout::set_configuration(const CollectionViewCompositionalLayoutConfiguration& value) const
    {
        [cocoon::internal::ns<::NSCollectionViewCompositionalLayout>(this) setConfiguration:cocoon::internal::native<::NSCollectionViewCompositionalLayoutConfiguration>(value)];
    }
}
