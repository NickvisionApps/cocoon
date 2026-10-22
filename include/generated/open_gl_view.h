#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class OpenGLContext;
    class OpenGLPixelFormat;

    /**
     * @brief C++ handle for the Objective-C class `NSOpenGLView` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::OpenGLView open_gl_view;
     * open_gl_view.set_open_gl_context(cocoon::OpenGLContext());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::OpenGLView open_gl_view{};
     * open_gl_view.set_open_gl_context(cocoon::OpenGLContext());
     * auto open_gl_context = open_gl_view.open_gl_context();
     * open_gl_view.set_pixel_format(cocoon::OpenGLPixelFormat());
     * auto pixel_format = open_gl_view.pixel_format();
     * open_gl_view.set_wants_best_resolution_open_gl_surface(true);
     * auto wants_best_resolution_open_gl_surface = open_gl_view.wants_best_resolution_open_gl_surface();
     * open_gl_view.clear_gl_context();
     * open_gl_view.prepare_open_gl();
     * open_gl_view.reshape();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsopenglview
     */
    class OpenGLView : public View
    {
    public:
        /// @brief Creates a new `NSOpenGLView` instance and returns a handle to it.
        explicit OpenGLView(const Rect& frame_rect, const OpenGLPixelFormat& format);
        /// @brief Creates a new `NSOpenGLView` instance and returns a handle to it.
        explicit OpenGLView();
        /// @brief Creates a null handle that refers to no native object.
        OpenGLView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit OpenGLView(Adopt adopt);
        /**
         * @brief Calls `-[NSOpenGLView clearGLContext]`.
         */
        void clear_gl_context() const;
        /**
         * @brief Calls `+[NSOpenGLView defaultPixelFormat]`.
         * @return The converted Objective-C result.
         */
        static OpenGLPixelFormat default_pixel_format();
        /**
         * @brief Calls `-[NSOpenGLView prepareOpenGL]`.
         */
        void prepare_open_gl() const;
        /**
         * @brief Calls `-[NSOpenGLView reshape]`.
         */
        void reshape() const;
        /**
         * @brief Calls `-[NSOpenGLView update]`.
         */
        void update() const;
        /**
         * @brief Returns the `openGLContext` property of `NSOpenGLView`.
         * @return The converted Objective-C result.
         */
        OpenGLContext open_gl_context() const;
        /**
         * @brief Sets the `openGLContext` property of `NSOpenGLView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_open_gl_context(const OpenGLContext& value) const;
        /**
         * @brief Returns the `pixelFormat` property of `NSOpenGLView`.
         * @return The converted Objective-C result.
         */
        OpenGLPixelFormat pixel_format() const;
        /**
         * @brief Sets the `pixelFormat` property of `NSOpenGLView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_pixel_format(const OpenGLPixelFormat& value) const;
        /**
         * @brief Returns the `wantsBestResolutionOpenGLSurface` property of `NSOpenGLView`.
         * @return The converted Objective-C result.
         */
        bool wants_best_resolution_open_gl_surface() const;
        /**
         * @brief Sets the `wantsBestResolutionOpenGLSurface` property of `NSOpenGLView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_wants_best_resolution_open_gl_surface(bool value) const;
        /**
         * @brief Returns the `wantsExtendedDynamicRangeOpenGLSurface` property of `NSOpenGLView`.
         * @return The converted Objective-C result.
         */
        bool wants_extended_dynamic_range_open_gl_surface() const;
        /**
         * @brief Sets the `wantsExtendedDynamicRangeOpenGLSurface` property of `NSOpenGLView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_wants_extended_dynamic_range_open_gl_surface(bool value) const;
    };
}
