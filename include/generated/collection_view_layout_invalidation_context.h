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
     * @brief C++ handle for the Objective-C class `NSCollectionViewLayoutInvalidationContext` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionViewLayoutInvalidationContext collection_view_layout_invalidation_context;
     * collection_view_layout_invalidation_context.set_content_offset_adjustment({0, 0});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionViewLayoutInvalidationContext collection_view_layout_invalidation_context{};
     * collection_view_layout_invalidation_context.set_content_offset_adjustment({0, 0});
     * auto content_offset_adjustment = collection_view_layout_invalidation_context.content_offset_adjustment();
     * collection_view_layout_invalidation_context.set_content_size_adjustment({100, 100});
     * auto content_size_adjustment = collection_view_layout_invalidation_context.content_size_adjustment();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionviewlayoutinvalidationcontext
     */
    class CollectionViewLayoutInvalidationContext : public Object
    {
    public:
        /// @brief Creates a new `NSCollectionViewLayoutInvalidationContext` instance and returns a handle to it.
        explicit CollectionViewLayoutInvalidationContext();
        /// @brief Creates a null handle that refers to no native object.
        CollectionViewLayoutInvalidationContext(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionViewLayoutInvalidationContext(Adopt adopt);
        /**
         * @brief Calls `-[NSCollectionViewLayoutInvalidationContext invalidateDecorationElementsOfKind:atIndexPaths:]`.
         * @param element_kind Argument converted to the Objective-C parameter of the same role.
         * @param index_paths Argument converted to the Objective-C parameter of the same role.
         */
        void invalidate_decoration_elements_of_kind(const std::string& element_kind, const std::vector<IndexPath>& index_paths) const;
        /**
         * @brief Calls `-[NSCollectionViewLayoutInvalidationContext invalidateItemsAtIndexPaths:]`.
         * @param index_paths Argument converted to the Objective-C parameter of the same role.
         */
        void invalidate_items_at_index_paths(const std::vector<IndexPath>& index_paths) const;
        /**
         * @brief Calls `-[NSCollectionViewLayoutInvalidationContext invalidateSupplementaryElementsOfKind:atIndexPaths:]`.
         * @param element_kind Argument converted to the Objective-C parameter of the same role.
         * @param index_paths Argument converted to the Objective-C parameter of the same role.
         */
        void invalidate_supplementary_elements_of_kind(const std::string& element_kind, const std::vector<IndexPath>& index_paths) const;
        /**
         * @brief Returns the `contentOffsetAdjustment` property of `NSCollectionViewLayoutInvalidationContext`.
         * @return The converted Objective-C result.
         */
        Point content_offset_adjustment() const;
        /**
         * @brief Sets the `contentOffsetAdjustment` property of `NSCollectionViewLayoutInvalidationContext`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_content_offset_adjustment(const Point& value) const;
        /**
         * @brief Returns the `contentSizeAdjustment` property of `NSCollectionViewLayoutInvalidationContext`.
         * @return The converted Objective-C result.
         */
        Size content_size_adjustment() const;
        /**
         * @brief Sets the `contentSizeAdjustment` property of `NSCollectionViewLayoutInvalidationContext`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_content_size_adjustment(const Size& value) const;
        /**
         * @brief Returns the `invalidateDataSourceCounts` property of `NSCollectionViewLayoutInvalidationContext`.
         * @return The converted Objective-C result.
         */
        bool invalidate_data_source_counts() const;
        /**
         * @brief Returns the `invalidateEverything` property of `NSCollectionViewLayoutInvalidationContext`.
         * @return The converted Objective-C result.
         */
        bool invalidate_everything() const;
        /**
         * @brief Returns the `invalidatedDecorationIndexPaths` property of `NSCollectionViewLayoutInvalidationContext`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, std::vector<IndexPath>> invalidated_decoration_index_paths() const;
        /**
         * @brief Returns the `invalidatedItemIndexPaths` property of `NSCollectionViewLayoutInvalidationContext`.
         * @return The converted Objective-C result.
         */
        std::vector<IndexPath> invalidated_item_index_paths() const;
        /**
         * @brief Returns the `invalidatedSupplementaryIndexPaths` property of `NSCollectionViewLayoutInvalidationContext`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, std::vector<IndexPath>> invalidated_supplementary_index_paths() const;
    };
}
