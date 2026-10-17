#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSCollectionLayoutDimension` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionLayoutDimension collection_layout_dimension(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionLayoutDimension collection_layout_dimension(nullptr);
     * auto made_0 = cocoon::CollectionLayoutDimension::absolute_dimension(1);
     * auto made_1 = cocoon::CollectionLayoutDimension::estimated_dimension(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionlayoutdimension
     */
    class CollectionLayoutDimension : public Object
    {
    public:
        CollectionLayoutDimension();
        /// @brief Creates a null handle that refers to no native object.
        CollectionLayoutDimension(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionLayoutDimension(Adopt adopt);
        /**
     * @brief Calls `+[NSCollectionLayoutDimension absoluteDimension:]`.
     * @param absolute_dimension Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionLayoutDimension absolute_dimension(double absolute_dimension);
        /**
     * @brief Calls `+[NSCollectionLayoutDimension estimatedDimension:]`.
     * @param estimated_dimension Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionLayoutDimension estimated_dimension(double estimated_dimension);
        /**
     * @brief Calls `+[NSCollectionLayoutDimension fractionalHeightDimension:]`.
     * @param fractional_height Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionLayoutDimension fractional_height_dimension(double fractional_height);
        /**
     * @brief Calls `+[NSCollectionLayoutDimension fractionalWidthDimension:]`.
     * @param fractional_width Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionLayoutDimension fractional_width_dimension(double fractional_width);
        /**
     * @brief Returns the `dimension` property of `NSCollectionLayoutDimension`.
     * @return The converted Objective-C result.
     */
        double dimension() const;
        /**
     * @brief Returns the `isAbsolute` property of `NSCollectionLayoutDimension`.
     * @return The converted Objective-C result.
     */
        bool is_absolute() const;
        /**
     * @brief Returns the `isEstimated` property of `NSCollectionLayoutDimension`.
     * @return The converted Objective-C result.
     */
        bool is_estimated() const;
        /**
     * @brief Returns the `isFractionalHeight` property of `NSCollectionLayoutDimension`.
     * @return The converted Objective-C result.
     */
        bool is_fractional_height() const;
        /**
     * @brief Returns the `isFractionalWidth` property of `NSCollectionLayoutDimension`.
     * @return The converted Objective-C result.
     */
        bool is_fractional_width() const;
    };
}
