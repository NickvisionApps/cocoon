#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CollectionLayoutEdgeSpacing;
    class CollectionLayoutSize;
    class CollectionLayoutSupplementaryItem;

    /**
     * @brief C++ handle for the Objective-C class `NSCollectionLayoutItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionLayoutItem collection_layout_item(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionLayoutItem collection_layout_item(nullptr);
     * collection_layout_item.set_edge_spacing(cocoon::CollectionLayoutEdgeSpacing());
     * auto edge_spacing = collection_layout_item.edge_spacing();
     * auto made_0 = cocoon::CollectionLayoutItem::item_with_layout_size(cocoon::CollectionLayoutSize());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionlayoutitem
     */
    class CollectionLayoutItem : public Object
    {
    public:
        CollectionLayoutItem();
        /// @brief Creates a null handle that refers to no native object.
        CollectionLayoutItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionLayoutItem(Adopt adopt);
        /**
         * @brief Calls `+[NSCollectionLayoutItem itemWithLayoutSize:]`.
         * @param layout_size Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static CollectionLayoutItem item_with_layout_size(const CollectionLayoutSize& layout_size);
        /**
         * @brief Calls `+[NSCollectionLayoutItem itemWithLayoutSize:supplementaryItems:]`.
         * @param layout_size Argument converted to the Objective-C parameter of the same role.
         * @param supplementary_items Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static CollectionLayoutItem item_with_layout_size(const CollectionLayoutSize& layout_size, const std::vector<CollectionLayoutSupplementaryItem>& supplementary_items);
        /**
         * @brief Returns the `contentInsets` property of `NSCollectionLayoutItem`.
         * @return The converted Objective-C result.
         */
        DirectionalEdgeInsets content_insets() const;
        /**
         * @brief Sets the `contentInsets` property of `NSCollectionLayoutItem`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_content_insets(const DirectionalEdgeInsets& value) const;
        /**
         * @brief Returns the `edgeSpacing` property of `NSCollectionLayoutItem`.
         * @return The converted Objective-C result.
         */
        CollectionLayoutEdgeSpacing edge_spacing() const;
        /**
         * @brief Sets the `edgeSpacing` property of `NSCollectionLayoutItem`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_edge_spacing(const CollectionLayoutEdgeSpacing& value) const;
        /**
         * @brief Returns the `layoutSize` property of `NSCollectionLayoutItem`.
         * @return The converted Objective-C result.
         */
        CollectionLayoutSize layout_size() const;
        /**
         * @brief Returns the `supplementaryItems` property of `NSCollectionLayoutItem`.
         * @return The converted Objective-C result.
         */
        std::vector<CollectionLayoutSupplementaryItem> supplementary_items() const;
    };
}
