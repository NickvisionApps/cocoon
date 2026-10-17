#pragma once

#include "generated/availability.h"
#include "generated/ca_open_gl_layer.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class OpenGLContext;
    class OpenGLPixelFormat;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSOpenGLLayer` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref CAOpenGLLayer.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::OpenGLLayer open_gl_layer;
     * open_gl_layer.set_open_gl_context(cocoon::OpenGLContext());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::OpenGLLayer open_gl_layer{};
     * open_gl_layer.set_open_gl_context(cocoon::OpenGLContext());
     * auto open_gl_context = open_gl_layer.open_gl_context();
     * open_gl_layer.set_open_gl_pixel_format(cocoon::OpenGLPixelFormat());
     * auto open_gl_pixel_format = open_gl_layer.open_gl_pixel_format();
     * open_gl_layer.set_view(cocoon::View());
     * auto view = open_gl_layer.view();
     * open_gl_layer.open_gl_context_for_pixel_format(cocoon::OpenGLPixelFormat());
     * open_gl_layer.open_gl_pixel_format_for_display_mask(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsopengllayer
     */
    class OpenGLLayer : public CAOpenGLLayer
    {
    public:
        /// @brief Creates a new `NSOpenGLLayer` instance and returns a handle to it.
        explicit OpenGLLayer();
        /// @brief Creates a null handle that refers to no native object.
        OpenGLLayer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit OpenGLLayer(Adopt adopt);
        /**
     * @brief Calls `-[NSOpenGLLayer canDrawInOpenGLContext:pixelFormat:forLayerTime:displayTime:]`.
     * @details Invoked by AppKit to ask the layer whether it can draw. Normally one would return YES, but one can return NO to cause the current frame to be skipped.
     * @param context Argument converted to the Objective-C parameter of the same role.
     * @param pixel_format Argument converted to the Objective-C parameter of the same role.
     * @param t Argument converted to the Objective-C parameter of the same role.
     * @param ts Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool can_draw_in_open_gl_context(const OpenGLContext& context, const OpenGLPixelFormat& pixel_format, double t, const CVTimeStamp* ts) const;
        /**
     * @brief Calls `-[NSOpenGLLayer drawInOpenGLContext:pixelFormat:forLayerTime:displayTime:]`.
     * @details Invoked by AppKit to ask the layer to draw.
     * @param context Argument converted to the Objective-C parameter of the same role.
     * @param pixel_format Argument converted to the Objective-C parameter of the same role.
     * @param t Argument converted to the Objective-C parameter of the same role.
     * @param ts Argument converted to the Objective-C parameter of the same role.
     */
        void draw_in_open_gl_context(const OpenGLContext& context, const OpenGLPixelFormat& pixel_format, double t, const CVTimeStamp* ts) const;
        /**
     * @brief Calls `-[NSOpenGLLayer openGLContextForPixelFormat:]`.
     * @details Invoked by AppKit to ask for the OpenGL context to use. Should return an autoreleased NSOpenGLContext.
     * @param pixel_format Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        OpenGLContext open_gl_context_for_pixel_format(const OpenGLPixelFormat& pixel_format) const;
        /**
     * @brief Calls `-[NSOpenGLLayer openGLPixelFormatForDisplayMask:]`.
     * @details Invoked by AppKit to ask for the pixel format to use. Should return an autoreleased NSOpenGLPixelFormat suitable for the displays specified by "mask". (In practice, this means including an NSOpenGLPFAScreenMask specification in the pixel format attribute list that's used to instantiate the NSOpenGLPixelFormat.)
     * @param mask Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        OpenGLPixelFormat open_gl_pixel_format_for_display_mask(unsigned int mask) const;
        /**
     * @brief Returns the `openGLContext` property of `NSOpenGLLayer`.
     * @details Provides access to the layer's associated NSOpenGLContext. Subclasses shouldn't invoke -setOpenGLContext:, but can override it if desired to intercept assignment of the layer's context.
     * @return The converted Objective-C result.
     */
        OpenGLContext open_gl_context() const;
        /**
     * @brief Sets the `openGLContext` property of `NSOpenGLLayer`.
     * @details Provides access to the layer's associated NSOpenGLContext. Subclasses shouldn't invoke -setOpenGLContext:, but can override it if desired to intercept assignment of the layer's context.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_open_gl_context(const OpenGLContext& value) const;
        /**
     * @brief Returns the `openGLPixelFormat` property of `NSOpenGLLayer`.
     * @details Provides access to the layer's associated NSOpenGLPixelFormat. Subclasses shouldn't invoke -setOpenGLPixelFormat:, but can override it if desired to intercept assignment of the layer's pixel format.
     * @return The converted Objective-C result.
     */
        OpenGLPixelFormat open_gl_pixel_format() const;
        /**
     * @brief Sets the `openGLPixelFormat` property of `NSOpenGLLayer`.
     * @details Provides access to the layer's associated NSOpenGLPixelFormat. Subclasses shouldn't invoke -setOpenGLPixelFormat:, but can override it if desired to intercept assignment of the layer's pixel format.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_open_gl_pixel_format(const OpenGLPixelFormat& value) const;
        /**
     * @brief Returns the `view` property of `NSOpenGLLayer`.
     * @details Provides access to the layer's associated view. Subclasses shouldn't invoke -setView:, but can override it if desired to intercept the layer's association to, or dissociation from, a view.
     * @return The converted Objective-C result.
     */
        View view() const;
        /**
     * @brief Sets the `view` property of `NSOpenGLLayer`.
     * @details Provides access to the layer's associated view. Subclasses shouldn't invoke -setView:, but can override it if desired to intercept the layer's association to, or dissociation from, a view.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_view(const View& value) const;
    };
}
