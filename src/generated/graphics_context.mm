#include "generated/graphics_context.h"
#include "internal.h"

namespace cocoon
{
    GraphicsContext::GraphicsContext() : GraphicsContext(Adopt{cocoon::internal::retain([[::NSGraphicsContext alloc] init])})
    {
    }

    GraphicsContext::GraphicsContext(std::nullptr_t) : Object(nullptr)
    {
    }

    GraphicsContext::GraphicsContext(Adopt adopt) : Object(adopt)
    {
    }

    bool GraphicsContext::current_context_drawing_to_screen()
    {
        return static_cast<bool>([::NSGraphicsContext currentContextDrawingToScreen]);
    }

    void GraphicsContext::flush_graphics() const
    {
        [cocoon::internal::ns<::NSGraphicsContext>(this) flushGraphics];
    }

    GraphicsContext GraphicsContext::graphics_context_with_attributes(const std::map<std::string, Object>& attributes)
    {
        return cocoon::internal::wrap<GraphicsContext>([::NSGraphicsContext graphicsContextWithAttributes:cocoon::internal::to_dictionary(attributes, [](const std::string& k) -> id
                                                                                                                                          {
                                                                                                                                              return cocoon::internal::to(k);
                                                                                                                                          },
                                                                                                                                          [](const Object& v) -> id
                                                                                                                                          {
                                                                                                                                              return cocoon::internal::native_id(v);
                                                                                                                                          })]);
    }

    GraphicsContext GraphicsContext::graphics_context_with_bitmap_image_rep(const BitmapImageRep& bitmap_rep)
    {
        return cocoon::internal::wrap<GraphicsContext>([::NSGraphicsContext graphicsContextWithBitmapImageRep:cocoon::internal::native<::NSBitmapImageRep>(bitmap_rep)]);
    }

    GraphicsContext GraphicsContext::graphics_context_with_cg_context(const CGContext& graphics_port, bool initial_flipped_state)
    {
        return cocoon::internal::wrap<GraphicsContext>([::NSGraphicsContext graphicsContextWithCGContext:((::CGContextRef)(graphics_port).handle()) flipped:static_cast<::BOOL>(initial_flipped_state)]);
    }

    void GraphicsContext::restore_graphics_state() const
    {
        [cocoon::internal::ns<::NSGraphicsContext>(this) restoreGraphicsState];
    }

    void GraphicsContext::save_graphics_state() const
    {
        [cocoon::internal::ns<::NSGraphicsContext>(this) saveGraphicsState];
    }

    CGContext GraphicsContext::cg_context() const
    {
        return cocoon::internal::wrap_cf<CGContext>((const void*)([cocoon::internal::ns<::NSGraphicsContext>(this) CGContext]));
    }

    Object GraphicsContext::ci_context() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSGraphicsContext>(this) CIContext]);
    }

    std::map<std::string, Object> GraphicsContext::attributes() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSGraphicsContext>(this) attributes], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    ColorRenderingIntent GraphicsContext::color_rendering_intent() const
    {
        return static_cast<ColorRenderingIntent>([cocoon::internal::ns<::NSGraphicsContext>(this) colorRenderingIntent]);
    }

    void GraphicsContext::set_color_rendering_intent(ColorRenderingIntent value) const
    {
        [cocoon::internal::ns<::NSGraphicsContext>(this) setColorRenderingIntent:static_cast<::NSColorRenderingIntent>(value)];
    }

    CompositingOperation GraphicsContext::compositing_operation() const
    {
        return static_cast<CompositingOperation>([cocoon::internal::ns<::NSGraphicsContext>(this) compositingOperation]);
    }

    void GraphicsContext::set_compositing_operation(CompositingOperation value) const
    {
        [cocoon::internal::ns<::NSGraphicsContext>(this) setCompositingOperation:static_cast<::NSCompositingOperation>(value)];
    }

    GraphicsContext GraphicsContext::current_context()
    {
        return cocoon::internal::wrap<GraphicsContext>([::NSGraphicsContext currentContext]);
    }

    void GraphicsContext::set_current_context(const GraphicsContext& value)
    {
        [::NSGraphicsContext setCurrentContext:cocoon::internal::native<::NSGraphicsContext>(value)];
    }

    bool GraphicsContext::is_drawing_to_screen() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSGraphicsContext>(this) isDrawingToScreen]);
    }

    bool GraphicsContext::is_flipped() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSGraphicsContext>(this) isFlipped]);
    }

    ImageInterpolation GraphicsContext::image_interpolation() const
    {
        return static_cast<ImageInterpolation>([cocoon::internal::ns<::NSGraphicsContext>(this) imageInterpolation]);
    }

    void GraphicsContext::set_image_interpolation(ImageInterpolation value) const
    {
        [cocoon::internal::ns<::NSGraphicsContext>(this) setImageInterpolation:static_cast<::NSImageInterpolation>(value)];
    }

    Point GraphicsContext::pattern_phase() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSGraphicsContext>(this) patternPhase]);
    }

    void GraphicsContext::set_pattern_phase(const Point& value) const
    {
        [cocoon::internal::ns<::NSGraphicsContext>(this) setPatternPhase:cocoon::internal::to(value)];
    }

    bool GraphicsContext::should_antialias() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSGraphicsContext>(this) shouldAntialias]);
    }

    void GraphicsContext::set_should_antialias(bool value) const
    {
        [cocoon::internal::ns<::NSGraphicsContext>(this) setShouldAntialias:static_cast<::BOOL>(value)];
    }
}
