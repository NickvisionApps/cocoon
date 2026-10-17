#include "generated/collection_layout_spacing.h"
#include "internal.h"

namespace cocoon
{
    CollectionLayoutSpacing::CollectionLayoutSpacing() : Object(nullptr)
    {
    }

    CollectionLayoutSpacing::CollectionLayoutSpacing(std::nullptr_t) : Object(nullptr)
    {
    }

    CollectionLayoutSpacing::CollectionLayoutSpacing(Adopt adopt) : Object(adopt)
    {
    }

    CollectionLayoutSpacing CollectionLayoutSpacing::fixed_spacing(double fixed_spacing)
    {
        return cocoon::internal::wrap<CollectionLayoutSpacing>([::NSCollectionLayoutSpacing fixedSpacing:static_cast<::CGFloat>(fixed_spacing)]);
    }

    CollectionLayoutSpacing CollectionLayoutSpacing::flexible_spacing(double flexible_spacing)
    {
        return cocoon::internal::wrap<CollectionLayoutSpacing>([::NSCollectionLayoutSpacing flexibleSpacing:static_cast<::CGFloat>(flexible_spacing)]);
    }

    bool CollectionLayoutSpacing::is_fixed_spacing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionLayoutSpacing>(this) isFixedSpacing]);
    }

    bool CollectionLayoutSpacing::is_flexible_spacing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionLayoutSpacing>(this) isFlexibleSpacing]);
    }

    double CollectionLayoutSpacing::spacing() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSCollectionLayoutSpacing>(this) spacing]);
    }
}
