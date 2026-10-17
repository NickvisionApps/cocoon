#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class IndexPath;

    /**
     * @brief C++ handle for the Objective-C class `NSCollectionViewUpdateItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionViewUpdateItem collection_view_update_item;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionviewupdateitem
     */
    class CollectionViewUpdateItem : public Object
    {
    public:
        /// @brief Creates a new `NSCollectionViewUpdateItem` instance and returns a handle to it.
        explicit CollectionViewUpdateItem();
        /// @brief Creates a null handle that refers to no native object.
        CollectionViewUpdateItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionViewUpdateItem(Adopt adopt);
        /**
     * @brief Returns the `indexPathAfterUpdate` property of `NSCollectionViewUpdateItem`.
     * @return The converted Objective-C result.
     */
        IndexPath index_path_after_update() const;
        /**
     * @brief Returns the `indexPathBeforeUpdate` property of `NSCollectionViewUpdateItem`.
     * @return The converted Objective-C result.
     */
        IndexPath index_path_before_update() const;
        /**
     * @brief Returns the `updateAction` property of `NSCollectionViewUpdateItem`.
     * @return The converted Objective-C result.
     */
        CollectionUpdateAction update_action() const;
    };
}
