#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CGLContextObj;
    class OpenGLPixelFormat;

    /**
     * @brief C++ handle for the Objective-C class `NSOpenGLContext` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::OpenGLContext open_gl_context;
     * open_gl_context.set_current_virtual_screen(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::OpenGLContext open_gl_context{};
     * open_gl_context.set_current_virtual_screen(1);
     * auto current_virtual_screen = open_gl_context.current_virtual_screen();
     * open_gl_context.clear_drawable();
     * open_gl_context.flush_buffer();
     * open_gl_context.make_current_context();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsopenglcontext
     */
    class OpenGLContext : public Object
    {
    public:
        /// @brief Creates a new `NSOpenGLContext` instance and returns a handle to it.
        explicit OpenGLContext(const CGLContextObj& context);
        /// @brief Creates a new `NSOpenGLContext` instance and returns a handle to it.
        explicit OpenGLContext(const OpenGLPixelFormat& format, const OpenGLContext& share);
        /// @brief Creates a new `NSOpenGLContext` instance and returns a handle to it.
        explicit OpenGLContext();
        /// @brief Creates a null handle that refers to no native object.
        OpenGLContext(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit OpenGLContext(Adopt adopt);
        /**
     * @brief Calls `+[NSOpenGLContext clearCurrentContext]`.
     */
        static void clear_current_context();
        /**
     * @brief Calls `-[NSOpenGLContext clearDrawable]`.
     */
        void clear_drawable() const;
        /**
     * @brief Calls `-[NSOpenGLContext flushBuffer]`.
     * @details Flush draw buffer
     */
        void flush_buffer() const;
        /**
     * @brief Calls `-[NSOpenGLContext getValues:forParameter:]`.
     * @param vals Argument converted to the Objective-C parameter of the same role.
     * @param param Argument converted to the Objective-C parameter of the same role.
     */
        void get_values(int* vals, OpenGLContextParameter param) const;
        /**
     * @brief Calls `-[NSOpenGLContext makeCurrentContext]`.
     * @details Current context control
     */
        void make_current_context() const;
        /**
     * @brief Calls `-[NSOpenGLContext setValues:forParameter:]`.
     * @details Context Parameter handling
     * @param vals Argument converted to the Objective-C parameter of the same role.
     * @param param Argument converted to the Objective-C parameter of the same role.
     */
        void set_values(const int* vals, OpenGLContextParameter param) const;
        /**
     * @brief Calls `-[NSOpenGLContext update]`.
     */
        void update() const;
        /**
     * @brief Returns the `CGLContextObj` property of `NSOpenGLContext`.
     * @return The converted Objective-C result.
     */
        CGLContextObj cgl_context_obj() const;
        /**
     * @brief Returns the `currentContext` property of `NSOpenGLContext`.
     * @return The converted Objective-C result.
     */
        static OpenGLContext current_context();
        /**
     * @brief Returns the `currentVirtualScreen` property of `NSOpenGLContext`.
     * @details virtual screens
     * @return The converted Objective-C result.
     */
        int current_virtual_screen() const;
        /**
     * @brief Sets the `currentVirtualScreen` property of `NSOpenGLContext`.
     * @details virtual screens
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_current_virtual_screen(int value) const;
        /**
     * @brief Returns the `pixelFormat` property of `NSOpenGLContext`.
     * @return The converted Objective-C result.
     */
        OpenGLPixelFormat pixel_format() const;
    };
}
