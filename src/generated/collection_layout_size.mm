#include "generated/collection_layout_size.h"
#include "internal.h"

namespace cocoon
{
    CollectionLayoutSize::CollectionLayoutSize() : Object(nullptr)
    {
    }

    CollectionLayoutSize::CollectionLayoutSize(std::nullptr_t) : Object(nullptr)
    {
    }

    CollectionLayoutSize::CollectionLayoutSize(Adopt adopt) : Object(adopt)
    {
    }

    CollectionLayoutSize CollectionLayoutSize::size_with_width_dimension(const CollectionLayoutDimension& width, const CollectionLayoutDimension& height)
    {
        return cocoon::internal::wrap<CollectionLayoutSize>([::NSCollectionLayoutSize sizeWithWidthDimension:cocoon::internal::native<::NSCollectionLayoutDimension>(width) heightDimension:cocoon::internal::native<::NSCollectionLayoutDimension>(height)]);
    }

    CollectionLayoutDimension CollectionLayoutSize::height_dimension() const
    {
        return cocoon::internal::wrap<CollectionLayoutDimension>([cocoon::internal::ns<::NSCollectionLayoutSize>(this) heightDimension]);
    }

    CollectionLayoutDimension CollectionLayoutSize::width_dimension() const
    {
        return cocoon::internal::wrap<CollectionLayoutDimension>([cocoon::internal::ns<::NSCollectionLayoutSize>(this) widthDimension]);
    }
}
