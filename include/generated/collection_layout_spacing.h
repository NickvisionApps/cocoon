#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSCollectionLayoutSpacing` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionLayoutSpacing collection_layout_spacing(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionLayoutSpacing collection_layout_spacing(nullptr);
     * auto made_0 = cocoon::CollectionLayoutSpacing::fixed_spacing(1);
     * auto made_1 = cocoon::CollectionLayoutSpacing::flexible_spacing(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionlayoutspacing
     */
    class CollectionLayoutSpacing : public Object
    {
    public:
        CollectionLayoutSpacing();
        /// @brief Creates a null handle that refers to no native object.
        CollectionLayoutSpacing(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionLayoutSpacing(Adopt adopt);
        /**
         * @brief Calls `+[NSCollectionLayoutSpacing fixedSpacing:]`.
         * @param fixed_spacing Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static CollectionLayoutSpacing fixed_spacing(double fixed_spacing);
        /**
         * @brief Calls `+[NSCollectionLayoutSpacing flexibleSpacing:]`.
         * @param flexible_spacing Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static CollectionLayoutSpacing flexible_spacing(double flexible_spacing);
        /**
         * @brief Returns the `isFixedSpacing` property of `NSCollectionLayoutSpacing`.
         * @return The converted Objective-C result.
         */
        bool is_fixed_spacing() const;
        /**
         * @brief Returns the `isFlexibleSpacing` property of `NSCollectionLayoutSpacing`.
         * @return The converted Objective-C result.
         */
        bool is_flexible_spacing() const;
        /**
         * @brief Returns the `spacing` property of `NSCollectionLayoutSpacing`.
         * @return The converted Objective-C result.
         */
        double spacing() const;
    };
}
