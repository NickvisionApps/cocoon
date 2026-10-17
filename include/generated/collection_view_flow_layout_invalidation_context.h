#pragma once

#include "generated/collection_view_layout_invalidation_context.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSCollectionViewFlowLayoutInvalidationContext` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref CollectionViewLayoutInvalidationContext.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionViewFlowLayoutInvalidationContext collection_view_flow_layout_invalidation_context;
     * collection_view_flow_layout_invalidation_context.set_invalidate_flow_layout_attributes(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionViewFlowLayoutInvalidationContext collection_view_flow_layout_invalidation_context{};
     * collection_view_flow_layout_invalidation_context.set_invalidate_flow_layout_attributes(true);
     * auto invalidate_flow_layout_attributes = collection_view_flow_layout_invalidation_context.invalidate_flow_layout_attributes();
     * collection_view_flow_layout_invalidation_context.set_invalidate_flow_layout_delegate_metrics(true);
     * auto invalidate_flow_layout_delegate_metrics = collection_view_flow_layout_invalidation_context.invalidate_flow_layout_delegate_metrics();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionviewflowlayoutinvalidationcontext
     */
    class CollectionViewFlowLayoutInvalidationContext : public CollectionViewLayoutInvalidationContext
    {
    public:
        /// @brief Creates a new `NSCollectionViewFlowLayoutInvalidationContext` instance and returns a handle to it.
        explicit CollectionViewFlowLayoutInvalidationContext();
        /// @brief Creates a null handle that refers to no native object.
        CollectionViewFlowLayoutInvalidationContext(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionViewFlowLayoutInvalidationContext(Adopt adopt);
        /**
     * @brief Returns the `invalidateFlowLayoutAttributes` property of `NSCollectionViewFlowLayoutInvalidationContext`.
     * @return The converted Objective-C result.
     */
        bool invalidate_flow_layout_attributes() const;
        /**
     * @brief Sets the `invalidateFlowLayoutAttributes` property of `NSCollectionViewFlowLayoutInvalidationContext`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_invalidate_flow_layout_attributes(bool value) const;
        /**
     * @brief Returns the `invalidateFlowLayoutDelegateMetrics` property of `NSCollectionViewFlowLayoutInvalidationContext`.
     * @return The converted Objective-C result.
     */
        bool invalidate_flow_layout_delegate_metrics() const;
        /**
     * @brief Sets the `invalidateFlowLayoutDelegateMetrics` property of `NSCollectionViewFlowLayoutInvalidationContext`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_invalidate_flow_layout_delegate_metrics(bool value) const;
    };
}
