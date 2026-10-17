#pragma once

#include "generated/availability.h"
#include "generated/cell.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSImageCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Cell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ImageCell image_cell;
     * image_cell.set_image_alignment(cocoon::ImageAlignment::Center);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ImageCell image_cell{};
     * image_cell.set_image_alignment(cocoon::ImageAlignment::Center);
     * auto image_alignment = image_cell.image_alignment();
     * image_cell.set_image_frame_style(cocoon::ImageFrameStyle::None);
     * auto image_frame_style = image_cell.image_frame_style();
     * image_cell.set_image_scaling(cocoon::ImageScaling::ImageScaleProportionallyDown);
     * auto image_scaling = image_cell.image_scaling();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsimagecell
     */
    class ImageCell : public Cell
    {
    public:
        /// @brief Creates a new `NSImageCell` instance and returns a handle to it.
        explicit ImageCell();
        /// @brief Creates a null handle that refers to no native object.
        ImageCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ImageCell(Adopt adopt);
        /**
     * @brief Returns the `imageAlignment` property of `NSImageCell`.
     * @return The converted Objective-C result.
     */
        ImageAlignment image_alignment() const;
        /**
     * @brief Sets the `imageAlignment` property of `NSImageCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image_alignment(ImageAlignment value) const;
        /**
     * @brief Returns the `imageFrameStyle` property of `NSImageCell`.
     * @return The converted Objective-C result.
     */
        ImageFrameStyle image_frame_style() const;
        /**
     * @brief Sets the `imageFrameStyle` property of `NSImageCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image_frame_style(ImageFrameStyle value) const;
        /**
     * @brief Returns the `imageScaling` property of `NSImageCell`.
     * @return The converted Objective-C result.
     */
        ImageScaling image_scaling() const;
        /**
     * @brief Sets the `imageScaling` property of `NSImageCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image_scaling(ImageScaling value) const;
    };
}
