#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSAdaptiveImageGlyph` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::AdaptiveImageGlyph adaptive_image_glyph(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsadaptiveimageglyph
     */
    class AdaptiveImageGlyph : public Object
    {
    public:
        /// @brief Creates a new `NSAdaptiveImageGlyph` instance and returns a handle to it.
        explicit AdaptiveImageGlyph(const std::vector<std::uint8_t>& image_content);
        AdaptiveImageGlyph();
        /// @brief Creates a null handle that refers to no native object.
        AdaptiveImageGlyph(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit AdaptiveImageGlyph(Adopt adopt);
        /**
     * @brief Returns the `contentDescription` property of `NSAdaptiveImageGlyph`.
     * @return The converted Objective-C result.
     */
        std::string content_description() const;
        /**
     * @brief Returns the `contentIdentifier` property of `NSAdaptiveImageGlyph`.
     * @return The converted Objective-C result.
     */
        std::string content_identifier() const;
        /**
     * @brief Returns the `contentType` property of `NSAdaptiveImageGlyph`.
     * @return The converted Objective-C result.
     */
        static Object content_type();
        /**
     * @brief Returns the `imageContent` property of `NSAdaptiveImageGlyph`.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> image_content() const;
    };
}
