#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CGImage;
    class Value;

    /**
     * @brief C++ handle for the Objective-C class `NSTextPreview` (AppKit).
     * @details A snapshot of the text in your view, which the system uses to create user-visible effects. An 'NSTextPreview' object provides a static image of your view’s text content that the system can use to create animations. You provide preview objects in response to system requests, such as ones from Writing Tools. In addition to creating an image of your view’s text, you also specify the location of that text in your view’s frame rectangle. When creating animations, the system places the image on top of your view’s content and animates changes to the image instead of to your view. Create an 'NSTextPreview' object in response to specific system requests. Create an image with a transparent background and render your view’s text into the image using the current text attributes. Construct your 'NSTextPreview' object with both the image and the frame rectangle that represents the location of the rendered text in your view’s coordinate system. To highlight specific portions of text, instead of all the text in the image, provide a set of candidate rectangles with the locations of the text you want to highlight.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextPreview text_preview(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextpreview
     */
    class TextPreview : public Object
    {
    public:
        /// @brief Creates a new `NSTextPreview` instance and returns a handle to it.
        explicit TextPreview(const CGImage& snapshot_image, const Rect& presentation_frame);
        /// @brief Creates a new `NSTextPreview` instance and returns a handle to it.
        explicit TextPreview(const CGImage& snapshot_image, const Rect& presentation_frame, const std::vector<Value>& candidate_rects);
        TextPreview();
        /// @brief Creates a null handle that refers to no native object.
        TextPreview(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextPreview(Adopt adopt);
        /**
     * @brief Returns the `candidateRects` property of `NSTextPreview`.
     * @details Rectangles that define the specific portions of text to highlight. At initialization time, you set this property to an array of \<doc://com.apple.documentation/documentation/foundation/nsvalue> objects, each of which contains an \<doc://com.apple.documentation/documentation/foundation/nsrect> in the coordinate space of the target view. Each rectangle contains a bounding rectangle for text that is part of the preview. When applying visual effects, the system adds highlights only to the text in the specified rectangles.
     * @return The converted Objective-C result.
     */
        std::vector<Value> candidate_rects() const;
        /**
     * @brief Returns the `presentationFrame` property of `NSTextPreview`.
     * @details The frame rectangle that places the preview image directly over the matching text. You specify this value at initialization time. The system uses it to position the preview image over the text in your view. Make sure the frame rectangle is in your view's coordinate space.
     * @return The converted Objective-C result.
     */
        Rect presentation_frame() const;
        /**
     * @brief Returns the `previewImage` property of `NSTextPreview`.
     * @details The image that contains the requested text from your view. You specify this image at initialization time. The system uses it to implement any visual effects involving your view’s text. Create the image with your text on a transparent background.
     * @return The converted Objective-C result.
     */
        CGImage preview_image() const;
    };
}
