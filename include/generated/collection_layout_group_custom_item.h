#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSCollectionLayoutGroupCustomItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionLayoutGroupCustomItem collection_layout_group_custom_item(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionLayoutGroupCustomItem collection_layout_group_custom_item(nullptr);
     * auto made_0 = cocoon::CollectionLayoutGroupCustomItem::custom_item_with_frame({{0, 0}, {100, 100}});
     * auto made_1 = cocoon::CollectionLayoutGroupCustomItem::custom_item_with_frame({{0, 0}, {100, 100}}, 1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionlayoutgroupcustomitem
     */
    class CollectionLayoutGroupCustomItem : public Object
    {
    public:
        CollectionLayoutGroupCustomItem();
        /// @brief Creates a null handle that refers to no native object.
        CollectionLayoutGroupCustomItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionLayoutGroupCustomItem(Adopt adopt);
        /**
     * @brief Calls `+[NSCollectionLayoutGroupCustomItem customItemWithFrame:]`.
     * @param frame Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionLayoutGroupCustomItem custom_item_with_frame(const Rect& frame);
        /**
     * @brief Calls `+[NSCollectionLayoutGroupCustomItem customItemWithFrame:zIndex:]`.
     * @param frame Argument converted to the Objective-C parameter of the same role.
     * @param z_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionLayoutGroupCustomItem custom_item_with_frame(const Rect& frame, std::int64_t z_index);
        /**
     * @brief Returns the `frame` property of `NSCollectionLayoutGroupCustomItem`.
     * @return The converted Objective-C result.
     */
        Rect frame() const;
        /**
     * @brief Returns the `zIndex` property of `NSCollectionLayoutGroupCustomItem`.
     * @return The converted Objective-C result.
     */
        std::int64_t z_index() const;
    };
}
