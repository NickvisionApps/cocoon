#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CGLPBufferObj;

    /**
     * @brief C++ handle for the Objective-C class `NSOpenGLPixelBuffer` (AppKit).
     * @details NOTE: PBuffers should be considered deprecated as of 10.7. Use GL_EXT_framebuffer_object instead.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::OpenGLPixelBuffer open_gl_pixel_buffer;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsopenglpixelbuffer
     */
    class OpenGLPixelBuffer : public Object
    {
    public:
        /// @brief Creates a new `NSOpenGLPixelBuffer` instance and returns a handle to it.
        explicit OpenGLPixelBuffer();
        /// @brief Creates a null handle that refers to no native object.
        OpenGLPixelBuffer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit OpenGLPixelBuffer(Adopt adopt);
        /**
         * @brief Returns the `CGLPBufferObj` property of `NSOpenGLPixelBuffer`.
         * @details - (nullable NSOpenGLPixelBuffer )initWithCGLPBufferObj:(CGLPBufferObj)pbuffer API_DEPRECATED("", macos(10.6,10.7)); / Use IOSurface instead of NSOpenGLPixelBuffer on Mac OS 10.7 and newer.
         * @return The converted Objective-C result.
         */
        CGLPBufferObj cglp_buffer_obj() const;
    };
}
