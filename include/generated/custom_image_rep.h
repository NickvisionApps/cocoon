#pragma once

#include "generated/enums.h"
#include "generated/image_rep.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSCustomImageRep` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ImageRep.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CustomImageRep custom_image_rep;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscustomimagerep
     */
    class CustomImageRep : public ImageRep
    {
    public:
        /// @brief Creates a new `NSCustomImageRep` instance and returns a handle to it.
        explicit CustomImageRep(const std::string& selector, const Object& delegate);
        /// @brief Creates a new `NSCustomImageRep` instance and returns a handle to it.
        explicit CustomImageRep(const Size& size, bool drawing_handler_should_be_called_with_flipped_context, std::function<bool(Rect)> drawing_handler);
        /// @brief Creates a new `NSCustomImageRep` instance and returns a handle to it.
        explicit CustomImageRep();
        /// @brief Creates a null handle that refers to no native object.
        CustomImageRep(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CustomImageRep(Adopt adopt);
        /**
     * @brief Returns the `delegate` property of `NSCustomImageRep`.
     * @return The converted Objective-C result.
     */
        Object delegate() const;
        /**
     * @brief Returns the `drawSelector` property of `NSCustomImageRep`.
     * @return The converted Objective-C result.
     */
        std::string draw_selector() const;
        /**
     * @brief Returns the `drawingHandler` property of `NSCustomImageRep`.
     * @return The converted Objective-C result.
     */
        std::function<bool(Rect)> drawing_handler() const;
    };
}
