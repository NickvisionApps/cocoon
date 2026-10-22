#pragma once

#include "generated/availability.h"
#include "generated/collection_layout_supplementary_item.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class CollectionLayoutSize;

    /**
     * @brief C++ handle for the Objective-C class `NSCollectionLayoutBoundarySupplementaryItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref CollectionLayoutSupplementaryItem.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionLayoutBoundarySupplementaryItem collection_layout_boundary_supplementary_item(nullptr);  // null handle; instances normally come from other API calls
     * collection_layout_boundary_supplementary_item.set_extends_boundary(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionLayoutBoundarySupplementaryItem collection_layout_boundary_supplementary_item(nullptr);
     * collection_layout_boundary_supplementary_item.set_extends_boundary(true);
     * auto extends_boundary = collection_layout_boundary_supplementary_item.extends_boundary();
     * collection_layout_boundary_supplementary_item.set_pin_to_visible_bounds(true);
     * auto pin_to_visible_bounds = collection_layout_boundary_supplementary_item.pin_to_visible_bounds();
     * auto made_0 = cocoon::CollectionLayoutBoundarySupplementaryItem::boundary_supplementary_item_with_layout_size(cocoon::CollectionLayoutSize(), "text", cocoon::RectAlignment::None);
     * auto made_1 = cocoon::CollectionLayoutBoundarySupplementaryItem::boundary_supplementary_item_with_layout_size(cocoon::CollectionLayoutSize(), "text", cocoon::RectAlignment::None, {0, 0});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionlayoutboundarysupplementaryitem
     */
    class CollectionLayoutBoundarySupplementaryItem : public CollectionLayoutSupplementaryItem
    {
    public:
        CollectionLayoutBoundarySupplementaryItem();
        /// @brief Creates a null handle that refers to no native object.
        CollectionLayoutBoundarySupplementaryItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionLayoutBoundarySupplementaryItem(Adopt adopt);
        /**
         * @brief Calls `+[NSCollectionLayoutBoundarySupplementaryItem boundarySupplementaryItemWithLayoutSize:elementKind:alignment:]`.
         * @param layout_size Argument converted to the Objective-C parameter of the same role.
         * @param element_kind Argument converted to the Objective-C parameter of the same role.
         * @param alignment Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static CollectionLayoutBoundarySupplementaryItem boundary_supplementary_item_with_layout_size(const CollectionLayoutSize& layout_size, const std::string& element_kind, RectAlignment alignment);
        /**
         * @brief Calls `+[NSCollectionLayoutBoundarySupplementaryItem boundarySupplementaryItemWithLayoutSize:elementKind:alignment:absoluteOffset:]`.
         * @param layout_size Argument converted to the Objective-C parameter of the same role.
         * @param element_kind Argument converted to the Objective-C parameter of the same role.
         * @param alignment Argument converted to the Objective-C parameter of the same role.
         * @param absolute_offset Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static CollectionLayoutBoundarySupplementaryItem boundary_supplementary_item_with_layout_size(const CollectionLayoutSize& layout_size, const std::string& element_kind, RectAlignment alignment, const Point& absolute_offset);
        /**
         * @brief Returns the `alignment` property of `NSCollectionLayoutBoundarySupplementaryItem`.
         * @return The converted Objective-C result.
         */
        RectAlignment alignment() const;
        /**
         * @brief Returns the `extendsBoundary` property of `NSCollectionLayoutBoundarySupplementaryItem`.
         * @return The converted Objective-C result.
         */
        bool extends_boundary() const;
        /**
         * @brief Sets the `extendsBoundary` property of `NSCollectionLayoutBoundarySupplementaryItem`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_extends_boundary(bool value) const;
        /**
         * @brief Returns the `offset` property of `NSCollectionLayoutBoundarySupplementaryItem`.
         * @return The converted Objective-C result.
         */
        Point offset() const;
        /**
         * @brief Returns the `pinToVisibleBounds` property of `NSCollectionLayoutBoundarySupplementaryItem`.
         * @return The converted Objective-C result.
         */
        bool pin_to_visible_bounds() const;
        /**
         * @brief Sets the `pinToVisibleBounds` property of `NSCollectionLayoutBoundarySupplementaryItem`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_pin_to_visible_bounds(bool value) const;
    };
}
