#include "generated/collection_view_grid_layout.h"
#include "internal.h"

namespace cocoon
{
    CollectionViewGridLayout::CollectionViewGridLayout() : CollectionViewGridLayout(Adopt{cocoon::internal::retain([[::NSCollectionViewGridLayout alloc] init])})
    {
    }

    CollectionViewGridLayout::CollectionViewGridLayout(std::nullptr_t) : CollectionViewLayout(nullptr)
    {
    }

    CollectionViewGridLayout::CollectionViewGridLayout(Adopt adopt) : CollectionViewLayout(adopt)
    {
    }

    std::vector<Color> CollectionViewGridLayout::background_colors() const
    {
        return cocoon::internal::from_array<Color>([cocoon::internal::ns<::NSCollectionViewGridLayout>(this) backgroundColors], [](id e) -> Color
                                                   {
                                                       return cocoon::internal::wrap<Color>((::NSColor*)e);
                                                   });
    }

    void CollectionViewGridLayout::set_background_colors(const std::vector<Color>& value) const
    {
        [cocoon::internal::ns<::NSCollectionViewGridLayout>(this) setBackgroundColors:cocoon::internal::to_array(value, [](const Color& e) -> id
                                                                                                                 {
                                                                                                                     return cocoon::internal::native<::NSColor>(e);
                                                                                                                 })];
    }

    Insets CollectionViewGridLayout::margins() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionViewGridLayout>(this) margins]);
    }

    void CollectionViewGridLayout::set_margins(const Insets& value) const
    {
        [cocoon::internal::ns<::NSCollectionViewGridLayout>(this) setMargins:cocoon::internal::to(value)];
    }

    Size CollectionViewGridLayout::maximum_item_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionViewGridLayout>(this) maximumItemSize]);
    }

    void CollectionViewGridLayout::set_maximum_item_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSCollectionViewGridLayout>(this) setMaximumItemSize:cocoon::internal::to(value)];
    }

    std::uint64_t CollectionViewGridLayout::maximum_number_of_columns() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSCollectionViewGridLayout>(this) maximumNumberOfColumns]);
    }

    void CollectionViewGridLayout::set_maximum_number_of_columns(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSCollectionViewGridLayout>(this) setMaximumNumberOfColumns:static_cast<::NSUInteger>(value)];
    }

    std::uint64_t CollectionViewGridLayout::maximum_number_of_rows() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSCollectionViewGridLayout>(this) maximumNumberOfRows]);
    }

    void CollectionViewGridLayout::set_maximum_number_of_rows(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSCollectionViewGridLayout>(this) setMaximumNumberOfRows:static_cast<::NSUInteger>(value)];
    }

    double CollectionViewGridLayout::minimum_interitem_spacing() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSCollectionViewGridLayout>(this) minimumInteritemSpacing]);
    }

    void CollectionViewGridLayout::set_minimum_interitem_spacing(double value) const
    {
        [cocoon::internal::ns<::NSCollectionViewGridLayout>(this) setMinimumInteritemSpacing:static_cast<::CGFloat>(value)];
    }

    Size CollectionViewGridLayout::minimum_item_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCollectionViewGridLayout>(this) minimumItemSize]);
    }

    void CollectionViewGridLayout::set_minimum_item_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSCollectionViewGridLayout>(this) setMinimumItemSize:cocoon::internal::to(value)];
    }

    double CollectionViewGridLayout::minimum_line_spacing() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSCollectionViewGridLayout>(this) minimumLineSpacing]);
    }

    void CollectionViewGridLayout::set_minimum_line_spacing(double value) const
    {
        [cocoon::internal::ns<::NSCollectionViewGridLayout>(this) setMinimumLineSpacing:static_cast<::CGFloat>(value)];
    }
}
