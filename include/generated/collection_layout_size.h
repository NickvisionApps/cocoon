#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CollectionLayoutDimension;

    /**
     * @brief C++ handle for the Objective-C class `NSCollectionLayoutSize` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionLayoutSize collection_layout_size(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionLayoutSize collection_layout_size(nullptr);
     * auto made_0 = cocoon::CollectionLayoutSize::size_with_width_dimension(cocoon::CollectionLayoutDimension(), cocoon::CollectionLayoutDimension());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionlayoutsize
     */
    class CollectionLayoutSize : public Object
    {
    public:
        CollectionLayoutSize();
        /// @brief Creates a null handle that refers to no native object.
        CollectionLayoutSize(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionLayoutSize(Adopt adopt);
        /**
     * @brief Calls `+[NSCollectionLayoutSize sizeWithWidthDimension:heightDimension:]`.
     * @param width Argument converted to the Objective-C parameter of the same role.
     * @param height Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionLayoutSize size_with_width_dimension(const CollectionLayoutDimension& width, const CollectionLayoutDimension& height);
        /**
     * @brief Returns the `heightDimension` property of `NSCollectionLayoutSize`.
     * @return The converted Objective-C result.
     */
        CollectionLayoutDimension height_dimension() const;
        /**
     * @brief Returns the `widthDimension` property of `NSCollectionLayoutSize`.
     * @return The converted Objective-C result.
     */
        CollectionLayoutDimension width_dimension() const;
    };
}
