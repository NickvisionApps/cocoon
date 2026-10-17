#pragma once

#include "generated/collection_view_layout.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Color;

    /**
     * @brief C++ handle for the Objective-C class `NSCollectionViewGridLayout` (AppKit).
     * @details NSCollectionView's default "Grid" layout, which matches NSCollectionView's layout behavior on OS X 10.5 through 10.10. When you create a new NSCollectionView, its collectionViewLayout property defaults to an instance of NSCollectionViewGridLayout.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref CollectionViewLayout.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionViewGridLayout collection_view_grid_layout;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionViewGridLayout collection_view_grid_layout{};
     * collection_view_grid_layout.set_margins(cocoon::Insets(8));
     * auto margins = collection_view_grid_layout.margins();
     * collection_view_grid_layout.set_maximum_item_size({100, 100});
     * auto maximum_item_size = collection_view_grid_layout.maximum_item_size();
     * collection_view_grid_layout.set_maximum_number_of_columns(1);
     * auto maximum_number_of_columns = collection_view_grid_layout.maximum_number_of_columns();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionviewgridlayout
     */
    class CollectionViewGridLayout : public CollectionViewLayout
    {
    public:
        /// @brief Creates a new `NSCollectionViewGridLayout` instance and returns a handle to it.
        explicit CollectionViewGridLayout();
        /// @brief Creates a null handle that refers to no native object.
        CollectionViewGridLayout(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionViewGridLayout(Adopt adopt);
        /**
     * @brief Returns the `backgroundColors` property of `NSCollectionViewGridLayout`.
     * @details The colors with which to fill the background. Defaults to nil. Setting this to nil causes a default background color to be used. Setting it to an empty array causes the CollectionView to draw no background fill. Setting it to a single-NSColor array causes the entire CollectionView to be drawn with the given background fill color. For CollectionViews using the old, pre-10.11 API: Setting it to an array of (N >= 2) colors causes the CollectionView to use them in sequence, applying color (index \% N) behind the item at "index”. For new, 10.11-and-later NSCollectionViews, colors after the first are ignored.
     * @return The converted Objective-C result.
     */
        std::vector<Color> background_colors() const;
        /**
     * @brief Sets the `backgroundColors` property of `NSCollectionViewGridLayout`.
     * @details The colors with which to fill the background. Defaults to nil. Setting this to nil causes a default background color to be used. Setting it to an empty array causes the CollectionView to draw no background fill. Setting it to a single-NSColor array causes the entire CollectionView to be drawn with the given background fill color. For CollectionViews using the old, pre-10.11 API: Setting it to an array of (N >= 2) colors causes the CollectionView to use them in sequence, applying color (index \% N) behind the item at "index”. For new, 10.11-and-later NSCollectionViews, colors after the first are ignored.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_colors(const std::vector<Color>& value) const;
        /**
     * @brief Returns the `margins` property of `NSCollectionViewGridLayout`.
     * @details The amount of empty space to leave between the edges of the CollectionView's frame and the items within it. Items will be laid out in the rectangle that remains after margins have been subtracted. Defaults to NSEdgeInsetsZero.
     * @return The converted Objective-C result.
     */
        Insets margins() const;
        /**
     * @brief Sets the `margins` property of `NSCollectionViewGridLayout`.
     * @details The amount of empty space to leave between the edges of the CollectionView's frame and the items within it. Items will be laid out in the rectangle that remains after margins have been subtracted. Defaults to NSEdgeInsetsZero.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_margins(const Insets& value) const;
        /**
     * @brief Returns the `maximumItemSize` property of `NSCollectionViewGridLayout`.
     * @details The largest allowed dimensions for an item's root view. Defaults to NSZeroSize, which makes the layout attempt to infer maximum dimensions from the provided itemPrototype's view's frame size.
     * @return The converted Objective-C result.
     */
        Size maximum_item_size() const;
        /**
     * @brief Sets the `maximumItemSize` property of `NSCollectionViewGridLayout`.
     * @details The largest allowed dimensions for an item's root view. Defaults to NSZeroSize, which makes the layout attempt to infer maximum dimensions from the provided itemPrototype's view's frame size.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_item_size(const Size& value) const;
        /**
     * @brief Returns the `maximumNumberOfColumns` property of `NSCollectionViewGridLayout`.
     * @details The largest number of item columns to attempt to fit in the CollectionView's visible area (if enclosed in a ScrollView). Defaults to 0, which is interpreted to mean there should be no limit other than minimumItemSize.width.
     * @return The converted Objective-C result.
     */
        std::uint64_t maximum_number_of_columns() const;
        /**
     * @brief Sets the `maximumNumberOfColumns` property of `NSCollectionViewGridLayout`.
     * @details The largest number of item columns to attempt to fit in the CollectionView's visible area (if enclosed in a ScrollView). Defaults to 0, which is interpreted to mean there should be no limit other than minimumItemSize.width.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_number_of_columns(std::uint64_t value) const;
        /**
     * @brief Returns the `maximumNumberOfRows` property of `NSCollectionViewGridLayout`.
     * @details The largest number of item rows to attempt to fit in the CollectionView's visible area (if enclosed in a ScrollView). Defaults to 0, which is interpreted to mean there should be no limit other than minimumItemSize.height.
     * @return The converted Objective-C result.
     */
        std::uint64_t maximum_number_of_rows() const;
        /**
     * @brief Sets the `maximumNumberOfRows` property of `NSCollectionViewGridLayout`.
     * @details The largest number of item rows to attempt to fit in the CollectionView's visible area (if enclosed in a ScrollView). Defaults to 0, which is interpreted to mean there should be no limit other than minimumItemSize.height.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_number_of_rows(std::uint64_t value) const;
        /**
     * @brief Returns the `minimumInteritemSpacing` property of `NSCollectionViewGridLayout`.
     * @details For a vertically scrolling grid, this value represents the minimum spacing between items in the same row. For a horizontally scrolling grid, this value represents the minimum spacing between items in the same column. This spacing is used to compute how many items can fit in a single line, but after the number of items is determined, the actual spacing may possibly be adjusted upward. Defaults to 0 for a Grid layout.
     * @return The converted Objective-C result.
     */
        double minimum_interitem_spacing() const;
        /**
     * @brief Sets the `minimumInteritemSpacing` property of `NSCollectionViewGridLayout`.
     * @details For a vertically scrolling grid, this value represents the minimum spacing between items in the same row. For a horizontally scrolling grid, this value represents the minimum spacing between items in the same column. This spacing is used to compute how many items can fit in a single line, but after the number of items is determined, the actual spacing may possibly be adjusted upward. Defaults to 0 for a Grid layout.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_interitem_spacing(double value) const;
        /**
     * @brief Returns the `minimumItemSize` property of `NSCollectionViewGridLayout`.
     * @details The smallest allowed dimensions for an item's root view. Defaults to NSZeroSize, which makes the layout attempt to infer minimum dimensions from the provided itemPrototype's view's frame size.
     * @return The converted Objective-C result.
     */
        Size minimum_item_size() const;
        /**
     * @brief Sets the `minimumItemSize` property of `NSCollectionViewGridLayout`.
     * @details The smallest allowed dimensions for an item's root view. Defaults to NSZeroSize, which makes the layout attempt to infer minimum dimensions from the provided itemPrototype's view's frame size.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_item_size(const Size& value) const;
        /**
     * @brief Returns the `minimumLineSpacing` property of `NSCollectionViewGridLayout`.
     * @details For a vertically scrolling grid, this value represents the minimum spacing between successive rows. For a horizontally scrolling grid, this value represents the minimum spacing between successive columns. This spacing is not applied to the space between the header and the first line or between the last line and the footer. Defaults to 0 for a Grid layout.
     * @return The converted Objective-C result.
     */
        double minimum_line_spacing() const;
        /**
     * @brief Sets the `minimumLineSpacing` property of `NSCollectionViewGridLayout`.
     * @details For a vertically scrolling grid, this value represents the minimum spacing between successive rows. For a horizontally scrolling grid, this value represents the minimum spacing between successive columns. This spacing is not applied to the space between the header and the first line or between the last line and the footer. Defaults to 0 for a Grid layout.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_line_spacing(double value) const;
    };
}
