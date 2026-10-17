#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/scrubber_item_view.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Image;
    class ImageView;

    /**
     * @brief C++ handle for the Objective-C class `NSScrubberImageItemView` (AppKit).
     * @details \@class NSScrubberTextItemView \@abstract A simple \@c NSScrubberItemView for displaying an image. \@discussion If the provided image is larger than the view's frame, it is scaled proportionally to fill the entire frame. The cropped portion of the image is determined by the \@c imageAlignment property.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScrubberItemView.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScrubberImageItemView scrubber_image_item_view;
     * scrubber_image_item_view.set_image(cocoon::Image());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ScrubberImageItemView scrubber_image_item_view{};
     * scrubber_image_item_view.set_image(cocoon::Image());
     * auto image = scrubber_image_item_view.image();
     * scrubber_image_item_view.set_image_alignment(cocoon::ImageAlignment::Center);
     * auto image_alignment = scrubber_image_item_view.image_alignment();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsscrubberimageitemview
     */
    class ScrubberImageItemView : public ScrubberItemView
    {
    public:
        /// @brief Creates a new `NSScrubberImageItemView` instance and returns a handle to it.
        explicit ScrubberImageItemView();
        /// @brief Creates a null handle that refers to no native object.
        ScrubberImageItemView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScrubberImageItemView(Adopt adopt);
        /**
     * @brief Returns the `image` property of `NSScrubberImageItemView`.
     * @return The converted Objective-C result.
     */
        Image image() const;
        /**
     * @brief Sets the `image` property of `NSScrubberImageItemView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image(const Image& value) const;
        /**
     * @brief Returns the `imageAlignment` property of `NSScrubberImageItemView`.
     * @return The converted Objective-C result.
     */
        ImageAlignment image_alignment() const;
        /**
     * @brief Sets the `imageAlignment` property of `NSScrubberImageItemView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image_alignment(ImageAlignment value) const;
        /**
     * @brief Returns the `imageView` property of `NSScrubberImageItemView`.
     * @return The converted Objective-C result.
     */
        ImageView image_view() const;
    };
}
