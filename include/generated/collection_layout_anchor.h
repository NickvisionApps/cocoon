#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSCollectionLayoutAnchor` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionLayoutAnchor collection_layout_anchor(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionLayoutAnchor collection_layout_anchor(nullptr);
     * auto made_0 = cocoon::CollectionLayoutAnchor::layout_anchor_with_edges(cocoon::DirectionalRectEdge::None);
     * auto made_1 = cocoon::CollectionLayoutAnchor::layout_anchor_with_edges(cocoon::DirectionalRectEdge::None, {0, 0});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionlayoutanchor
     */
    class CollectionLayoutAnchor : public Object
    {
    public:
        CollectionLayoutAnchor();
        /// @brief Creates a null handle that refers to no native object.
        CollectionLayoutAnchor(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionLayoutAnchor(Adopt adopt);
        /**
         * @brief Calls `+[NSCollectionLayoutAnchor layoutAnchorWithEdges:]`.
         * @param edges Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static CollectionLayoutAnchor layout_anchor_with_edges(DirectionalRectEdge edges);
        /**
         * @brief Calls `+[NSCollectionLayoutAnchor layoutAnchorWithEdges:absoluteOffset:]`.
         * @param edges Argument converted to the Objective-C parameter of the same role.
         * @param absolute_offset Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static CollectionLayoutAnchor layout_anchor_with_edges(DirectionalRectEdge edges, const Point& absolute_offset);
        /**
         * @brief Returns the `edges` property of `NSCollectionLayoutAnchor`.
         * @return The converted Objective-C result.
         */
        DirectionalRectEdge edges() const;
        /**
         * @brief Returns the `isAbsoluteOffset` property of `NSCollectionLayoutAnchor`.
         * @return The converted Objective-C result.
         */
        bool is_absolute_offset() const;
        /**
         * @brief Returns the `isFractionalOffset` property of `NSCollectionLayoutAnchor`.
         * @return The converted Objective-C result.
         */
        bool is_fractional_offset() const;
        /**
         * @brief Returns the `offset` property of `NSCollectionLayoutAnchor`.
         * @return The converted Objective-C result.
         */
        Point offset() const;
    };
}
