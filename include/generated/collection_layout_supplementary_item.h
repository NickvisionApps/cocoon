#pragma once

#include "generated/collection_layout_item.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class CollectionLayoutAnchor;
    class CollectionLayoutSize;

    /**
     * @brief C++ handle for the Objective-C class `NSCollectionLayoutSupplementaryItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref CollectionLayoutItem.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionLayoutSupplementaryItem collection_layout_supplementary_item(nullptr);  // null handle; instances normally come from other API calls
     * collection_layout_supplementary_item.set_z_index(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionLayoutSupplementaryItem collection_layout_supplementary_item(nullptr);
     * collection_layout_supplementary_item.set_z_index(1);
     * auto z_index = collection_layout_supplementary_item.z_index();
     * auto made_0 = cocoon::CollectionLayoutSupplementaryItem::supplementary_item_with_layout_size(cocoon::CollectionLayoutSize(), "text", cocoon::CollectionLayoutAnchor());
     * auto made_1 = cocoon::CollectionLayoutSupplementaryItem::supplementary_item_with_layout_size(cocoon::CollectionLayoutSize(), "text", cocoon::CollectionLayoutAnchor(), cocoon::CollectionLayoutAnchor());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionlayoutsupplementaryitem
     */
    class CollectionLayoutSupplementaryItem : public CollectionLayoutItem
    {
    public:
        CollectionLayoutSupplementaryItem();
        /// @brief Creates a null handle that refers to no native object.
        CollectionLayoutSupplementaryItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionLayoutSupplementaryItem(Adopt adopt);
        /**
     * @brief Calls `+[NSCollectionLayoutSupplementaryItem supplementaryItemWithLayoutSize:elementKind:containerAnchor:]`.
     * @param layout_size Argument converted to the Objective-C parameter of the same role.
     * @param element_kind Argument converted to the Objective-C parameter of the same role.
     * @param container_anchor Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionLayoutSupplementaryItem supplementary_item_with_layout_size(const CollectionLayoutSize& layout_size, const std::string& element_kind, const CollectionLayoutAnchor& container_anchor);
        /**
     * @brief Calls `+[NSCollectionLayoutSupplementaryItem supplementaryItemWithLayoutSize:elementKind:containerAnchor:itemAnchor:]`.
     * @param layout_size Argument converted to the Objective-C parameter of the same role.
     * @param element_kind Argument converted to the Objective-C parameter of the same role.
     * @param container_anchor Argument converted to the Objective-C parameter of the same role.
     * @param item_anchor Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionLayoutSupplementaryItem supplementary_item_with_layout_size(const CollectionLayoutSize& layout_size, const std::string& element_kind, const CollectionLayoutAnchor& container_anchor, const CollectionLayoutAnchor& item_anchor);
        /**
     * @brief Returns the `containerAnchor` property of `NSCollectionLayoutSupplementaryItem`.
     * @return The converted Objective-C result.
     */
        CollectionLayoutAnchor container_anchor() const;
        /**
     * @brief Returns the `elementKind` property of `NSCollectionLayoutSupplementaryItem`.
     * @return The converted Objective-C result.
     */
        std::string element_kind() const;
        /**
     * @brief Returns the `itemAnchor` property of `NSCollectionLayoutSupplementaryItem`.
     * @return The converted Objective-C result.
     */
        CollectionLayoutAnchor item_anchor() const;
        /**
     * @brief Returns the `zIndex` property of `NSCollectionLayoutSupplementaryItem`.
     * @return The converted Objective-C result.
     */
        std::int64_t z_index() const;
        /**
     * @brief Sets the `zIndex` property of `NSCollectionLayoutSupplementaryItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_z_index(std::int64_t value) const;
    };
}
