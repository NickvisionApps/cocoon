#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CollectionLayoutSpacing;

    /**
     * @brief C++ handle for the Objective-C class `NSCollectionLayoutEdgeSpacing` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionLayoutEdgeSpacing collection_layout_edge_spacing(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionLayoutEdgeSpacing collection_layout_edge_spacing(nullptr);
     * auto made_0 = cocoon::CollectionLayoutEdgeSpacing::spacing_for_leading(cocoon::CollectionLayoutSpacing(), cocoon::CollectionLayoutSpacing(), cocoon::CollectionLayoutSpacing(), cocoon::CollectionLayoutSpacing());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionlayoutedgespacing
     */
    class CollectionLayoutEdgeSpacing : public Object
    {
    public:
        CollectionLayoutEdgeSpacing();
        /// @brief Creates a null handle that refers to no native object.
        CollectionLayoutEdgeSpacing(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionLayoutEdgeSpacing(Adopt adopt);
        /**
     * @brief Calls `+[NSCollectionLayoutEdgeSpacing spacingForLeading:top:trailing:bottom:]`.
     * @param leading Argument converted to the Objective-C parameter of the same role.
     * @param top Argument converted to the Objective-C parameter of the same role.
     * @param trailing Argument converted to the Objective-C parameter of the same role.
     * @param bottom Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionLayoutEdgeSpacing spacing_for_leading(const CollectionLayoutSpacing& leading, const CollectionLayoutSpacing& top, const CollectionLayoutSpacing& trailing, const CollectionLayoutSpacing& bottom);
        /**
     * @brief Returns the `bottom` property of `NSCollectionLayoutEdgeSpacing`.
     * @return The converted Objective-C result.
     */
        CollectionLayoutSpacing bottom() const;
        /**
     * @brief Returns the `leading` property of `NSCollectionLayoutEdgeSpacing`.
     * @return The converted Objective-C result.
     */
        CollectionLayoutSpacing leading() const;
        /**
     * @brief Returns the `top` property of `NSCollectionLayoutEdgeSpacing`.
     * @return The converted Objective-C result.
     */
        CollectionLayoutSpacing top() const;
        /**
     * @brief Returns the `trailing` property of `NSCollectionLayoutEdgeSpacing`.
     * @return The converted Objective-C result.
     */
        CollectionLayoutSpacing trailing() const;
    };
}
