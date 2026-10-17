#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CGLPixelFormatObj;

    /**
     * @brief C++ handle for the Objective-C class `NSOpenGLPixelFormat` (AppKit).
     * @details NSOpenGLPixelFormat interface.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::OpenGLPixelFormat open_gl_pixel_format;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsopenglpixelformat
     */
    class OpenGLPixelFormat : public Object
    {
    public:
        /// @brief Creates a new `NSOpenGLPixelFormat` instance and returns a handle to it.
        explicit OpenGLPixelFormat(const unsigned int* attribs);
        /// @brief Creates a new `NSOpenGLPixelFormat` instance and returns a handle to it.
        explicit OpenGLPixelFormat(const CGLPixelFormatObj& format);
        /// @brief Creates a new `NSOpenGLPixelFormat` instance and returns a handle to it.
        explicit OpenGLPixelFormat();
        /// @brief Creates a null handle that refers to no native object.
        OpenGLPixelFormat(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit OpenGLPixelFormat(Adopt adopt);
        /**
     * @brief Calls `-[NSOpenGLPixelFormat getValues:forAttribute:forVirtualScreen:]`.
     * @param vals Argument converted to the Objective-C parameter of the same role.
     * @param attrib Argument converted to the Objective-C parameter of the same role.
     * @param screen Argument converted to the Objective-C parameter of the same role.
     */
        void get_values(int* vals, unsigned int attrib, int screen) const;
        /**
     * @brief Returns the `CGLPixelFormatObj` property of `NSOpenGLPixelFormat`.
     * @return The converted Objective-C result.
     */
        CGLPixelFormatObj cgl_pixel_format_obj() const;
        /**
     * @brief Returns the `numberOfVirtualScreens` property of `NSOpenGLPixelFormat`.
     * @return The converted Objective-C result.
     */
        int number_of_virtual_screens() const;
    };
}
