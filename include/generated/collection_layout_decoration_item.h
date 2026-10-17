#pragma once

#include "generated/collection_layout_item.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSCollectionLayoutDecorationItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref CollectionLayoutItem.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionLayoutDecorationItem collection_layout_decoration_item(nullptr);  // null handle; instances normally come from other API calls
     * collection_layout_decoration_item.set_z_index(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionLayoutDecorationItem collection_layout_decoration_item(nullptr);
     * collection_layout_decoration_item.set_z_index(1);
     * auto z_index = collection_layout_decoration_item.z_index();
     * auto made_0 = cocoon::CollectionLayoutDecorationItem::background_decoration_item_with_element_kind("text");
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionlayoutdecorationitem
     */
    class CollectionLayoutDecorationItem : public CollectionLayoutItem
    {
    public:
        CollectionLayoutDecorationItem();
        /// @brief Creates a null handle that refers to no native object.
        CollectionLayoutDecorationItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionLayoutDecorationItem(Adopt adopt);
        /**
     * @brief Calls `+[NSCollectionLayoutDecorationItem backgroundDecorationItemWithElementKind:]`.
     * @param element_kind Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionLayoutDecorationItem background_decoration_item_with_element_kind(const std::string& element_kind);
        /**
     * @brief Returns the `elementKind` property of `NSCollectionLayoutDecorationItem`.
     * @return The converted Objective-C result.
     */
        std::string element_kind() const;
        /**
     * @brief Returns the `zIndex` property of `NSCollectionLayoutDecorationItem`.
     * @return The converted Objective-C result.
     */
        std::int64_t z_index() const;
        /**
     * @brief Sets the `zIndex` property of `NSCollectionLayoutDecorationItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_z_index(std::int64_t value) const;
    };
}
