#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class BitmapImageRep;
    class CGContext;

    /**
     * @brief C++ handle for the Objective-C class `NSGraphicsContext` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::GraphicsContext graphics_context;
     * graphics_context.set_color_rendering_intent(cocoon::ColorRenderingIntent::Default);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::GraphicsContext graphics_context{};
     * graphics_context.set_color_rendering_intent(cocoon::ColorRenderingIntent::Default);
     * auto color_rendering_intent = graphics_context.color_rendering_intent();
     * graphics_context.set_compositing_operation(cocoon::CompositingOperation::Clear);
     * auto compositing_operation = graphics_context.compositing_operation();
     * graphics_context.set_current_context(cocoon::GraphicsContext());
     * auto current_context = graphics_context.current_context();
     * graphics_context.flush_graphics();
     * graphics_context.restore_graphics_state();
     * graphics_context.save_graphics_state();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsgraphicscontext
     */
    class GraphicsContext : public Object
    {
    public:
        /// @brief Creates a new `NSGraphicsContext` instance and returns a handle to it.
        explicit GraphicsContext(const std::map<std::string, Object>& attributes);
        /// @brief Creates a new `NSGraphicsContext` instance and returns a handle to it.
        explicit GraphicsContext(const BitmapImageRep& bitmap_rep);
        /// @brief Creates a new `NSGraphicsContext` instance and returns a handle to it.
        explicit GraphicsContext(const CGContext& graphics_port, bool initial_flipped_state);
        /// @brief Creates a new `NSGraphicsContext` instance and returns a handle to it.
        explicit GraphicsContext();
        /// @brief Creates a null handle that refers to no native object.
        GraphicsContext(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit GraphicsContext(Adopt adopt);
        /**
         * @brief Calls `+[NSGraphicsContext currentContextDrawingToScreen]`.
         * @return The converted Objective-C result.
         */
        static bool current_context_drawing_to_screen();
        /**
         * @brief Calls `-[NSGraphicsContext flushGraphics]`.
         */
        void flush_graphics() const;
        /**
         * @brief Calls `-[NSGraphicsContext restoreGraphicsState]`.
         */
        void restore_graphics_state() const;
        /**
         * @brief Calls `-[NSGraphicsContext saveGraphicsState]`.
         */
        void save_graphics_state() const;
        /**
         * @brief Returns the `CGContext` property of `NSGraphicsContext`.
         * @return The converted Objective-C result.
         */
        CGContext cg_context() const;
        /**
         * @brief Returns the `CIContext` property of `NSGraphicsContext`.
         * @return The converted Objective-C result.
         */
        Object ci_context() const;
        /**
         * @brief Returns the `attributes` property of `NSGraphicsContext`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> attributes() const;
        /**
         * @brief Returns the `colorRenderingIntent` property of `NSGraphicsContext`.
         * @return The converted Objective-C result.
         */
        ColorRenderingIntent color_rendering_intent() const;
        /**
         * @brief Sets the `colorRenderingIntent` property of `NSGraphicsContext`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_color_rendering_intent(ColorRenderingIntent value) const;
        /**
         * @brief Returns the `compositingOperation` property of `NSGraphicsContext`.
         * @return The converted Objective-C result.
         */
        CompositingOperation compositing_operation() const;
        /**
         * @brief Sets the `compositingOperation` property of `NSGraphicsContext`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_compositing_operation(CompositingOperation value) const;
        /**
         * @brief Returns the `currentContext` property of `NSGraphicsContext`.
         * @return The converted Objective-C result.
         */
        static GraphicsContext current_context();
        /**
         * @brief Sets the `currentContext` property of `NSGraphicsContext`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        static void set_current_context(const GraphicsContext& value);
        /**
         * @brief Returns the `drawingToScreen` property of `NSGraphicsContext`.
         * @return The converted Objective-C result.
         */
        bool is_drawing_to_screen() const;
        /**
         * @brief Returns the `flipped` property of `NSGraphicsContext`.
         * @details Returns the flip state of the receiver. The state is determined by messaging -isFlipped to the focus view in the context. If no view has focus, returns NO unless the receiver is instantiated via graphicsContextWithGraphicsPort:drawingToScreen:flipped: with initialFlippedState == YES.
         * @return The converted Objective-C result.
         */
        bool is_flipped() const;
        /**
         * @brief Returns the `imageInterpolation` property of `NSGraphicsContext`.
         * @return The converted Objective-C result.
         */
        ImageInterpolation image_interpolation() const;
        /**
         * @brief Sets the `imageInterpolation` property of `NSGraphicsContext`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_image_interpolation(ImageInterpolation value) const;
        /**
         * @brief Returns the `patternPhase` property of `NSGraphicsContext`.
         * @return The converted Objective-C result.
         */
        Point pattern_phase() const;
        /**
         * @brief Sets the `patternPhase` property of `NSGraphicsContext`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_pattern_phase(const Point& value) const;
        /**
         * @brief Returns the `shouldAntialias` property of `NSGraphicsContext`.
         * @return The converted Objective-C result.
         */
        bool should_antialias() const;
        /**
         * @brief Sets the `shouldAntialias` property of `NSGraphicsContext`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_should_antialias(bool value) const;
    };
}
