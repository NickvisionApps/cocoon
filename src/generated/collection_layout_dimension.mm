#include "generated/collection_layout_dimension.h"
#include "internal.h"

namespace cocoon
{
    CollectionLayoutDimension::CollectionLayoutDimension() : Object(nullptr)
    {
    }

    CollectionLayoutDimension::CollectionLayoutDimension(std::nullptr_t) : Object(nullptr)
    {
    }

    CollectionLayoutDimension::CollectionLayoutDimension(Adopt adopt) : Object(adopt)
    {
    }

    CollectionLayoutDimension CollectionLayoutDimension::absolute_dimension(double absolute_dimension)
    {
        return cocoon::internal::wrap<CollectionLayoutDimension>([::NSCollectionLayoutDimension absoluteDimension:static_cast<::CGFloat>(absolute_dimension)]);
    }

    CollectionLayoutDimension CollectionLayoutDimension::estimated_dimension(double estimated_dimension)
    {
        return cocoon::internal::wrap<CollectionLayoutDimension>([::NSCollectionLayoutDimension estimatedDimension:static_cast<::CGFloat>(estimated_dimension)]);
    }

    CollectionLayoutDimension CollectionLayoutDimension::fractional_height_dimension(double fractional_height)
    {
        return cocoon::internal::wrap<CollectionLayoutDimension>([::NSCollectionLayoutDimension fractionalHeightDimension:static_cast<::CGFloat>(fractional_height)]);
    }

    CollectionLayoutDimension CollectionLayoutDimension::fractional_width_dimension(double fractional_width)
    {
        return cocoon::internal::wrap<CollectionLayoutDimension>([::NSCollectionLayoutDimension fractionalWidthDimension:static_cast<::CGFloat>(fractional_width)]);
    }

    double CollectionLayoutDimension::dimension() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSCollectionLayoutDimension>(this) dimension]);
    }

    bool CollectionLayoutDimension::is_absolute() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionLayoutDimension>(this) isAbsolute]);
    }

    bool CollectionLayoutDimension::is_estimated() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionLayoutDimension>(this) isEstimated]);
    }

    bool CollectionLayoutDimension::is_fractional_height() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionLayoutDimension>(this) isFractionalHeight]);
    }

    bool CollectionLayoutDimension::is_fractional_width() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionLayoutDimension>(this) isFractionalWidth]);
    }
}
