#pragma once

#include "generated/availability.h"
#include "generated/ca_layer.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class CGColorSpace;
    class CGLContextObj;
    class CGLPixelFormatObj;

    /**
     * @brief C++ handle for the Objective-C class `CAOpenGLLayer` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref CALayer.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CAOpenGLLayer ca_open_gl_layer;
     * ca_open_gl_layer.set_asynchronous(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CAOpenGLLayer ca_open_gl_layer{};
     * ca_open_gl_layer.set_asynchronous(true);
     * auto asynchronous = ca_open_gl_layer.is_asynchronous();
     * ca_open_gl_layer.set_wants_extended_dynamic_range_content(true);
     * auto wants_extended_dynamic_range_content = ca_open_gl_layer.wants_extended_dynamic_range_content();
     * ca_open_gl_layer.copy_cgl_pixel_format_for_display_mask(1);
     * @endcode
     */
    class CAOpenGLLayer : public CALayer
    {
    public:
        /// @brief Creates a new `CAOpenGLLayer` instance and returns a handle to it.
        explicit CAOpenGLLayer();
        /// @brief Creates a null handle that refers to no native object.
        CAOpenGLLayer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CAOpenGLLayer(Adopt adopt);
        /**
         * @brief Calls `-[CAOpenGLLayer canDrawInCGLContext:pixelFormat:forLayerTime:displayTime:]`.
         * @param ctx Argument converted to the Objective-C parameter of the same role.
         * @param pf Argument converted to the Objective-C parameter of the same role.
         * @param t Argument converted to the Objective-C parameter of the same role.
         * @param ts Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool can_draw_in_cgl_context(const CGLContextObj& ctx, const CGLPixelFormatObj& pf, double t, const CVTimeStamp* ts) const;
        /**
         * @brief Calls `-[CAOpenGLLayer copyCGLContextForPixelFormat:]`.
         * @param pf Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        CGLContextObj copy_cgl_context_for_pixel_format(const CGLPixelFormatObj& pf) const;
        /**
         * @brief Calls `-[CAOpenGLLayer copyCGLPixelFormatForDisplayMask:]`.
         * @param mask Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        CGLPixelFormatObj copy_cgl_pixel_format_for_display_mask(unsigned int mask) const;
        /**
         * @brief Calls `-[CAOpenGLLayer drawInCGLContext:pixelFormat:forLayerTime:displayTime:]`.
         * @param ctx Argument converted to the Objective-C parameter of the same role.
         * @param pf Argument converted to the Objective-C parameter of the same role.
         * @param t Argument converted to the Objective-C parameter of the same role.
         * @param ts Argument converted to the Objective-C parameter of the same role.
         */
        void draw_in_cgl_context(const CGLContextObj& ctx, const CGLPixelFormatObj& pf, double t, const CVTimeStamp* ts) const;
        /**
         * @brief Calls `-[CAOpenGLLayer releaseCGLContext:]`.
         * @param ctx Argument converted to the Objective-C parameter of the same role.
         */
        void release_cgl_context(const CGLContextObj& ctx) const;
        /**
         * @brief Calls `-[CAOpenGLLayer releaseCGLPixelFormat:]`.
         * @param pf Argument converted to the Objective-C parameter of the same role.
         */
        void release_cgl_pixel_format(const CGLPixelFormatObj& pf) const;
        /**
         * @brief Returns the `asynchronous` property of `CAOpenGLLayer`.
         * @return The converted Objective-C result.
         */
        bool is_asynchronous() const;
        /**
         * @brief Sets the `asynchronous` property of `CAOpenGLLayer`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_asynchronous(bool value) const;
        /**
         * @brief Returns the `colorspace` property of `CAOpenGLLayer`.
         * @return The converted Objective-C result.
         */
        CGColorSpace colorspace() const;
        /**
         * @brief Sets the `colorspace` property of `CAOpenGLLayer`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_colorspace(const CGColorSpace& value) const;
        /**
         * @brief Returns the `wantsExtendedDynamicRangeContent` property of `CAOpenGLLayer`.
         * @return The converted Objective-C result.
         */
        bool wants_extended_dynamic_range_content() const;
        /**
         * @brief Sets the `wantsExtendedDynamicRangeContent` property of `CAOpenGLLayer`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_wants_extended_dynamic_range_content(bool value) const;
    };
}
