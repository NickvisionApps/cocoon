#include "generated/open_gl_layer.h"
#include "internal.h"

namespace cocoon
{
    OpenGLLayer::OpenGLLayer() : OpenGLLayer(Adopt{cocoon::internal::retain([[::NSOpenGLLayer alloc] init])})
    {
        CALayer::install_delegate_delegate_(handle());
    }

    OpenGLLayer::OpenGLLayer(std::nullptr_t) : CAOpenGLLayer(nullptr)
    {
    }

    OpenGLLayer::OpenGLLayer(Adopt adopt) : CAOpenGLLayer(adopt)
    {
    }

    bool OpenGLLayer::can_draw_in_open_gl_context(const OpenGLContext& context, const OpenGLPixelFormat& pixel_format, double t, const CVTimeStamp* ts) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOpenGLLayer>(this) canDrawInOpenGLContext:cocoon::internal::native<::NSOpenGLContext>(context) pixelFormat:cocoon::internal::native<::NSOpenGLPixelFormat>(pixel_format) forLayerTime:static_cast<::CFTimeInterval>(t) displayTime:(const ::CVTimeStamp*)(ts)]);
    }

    void OpenGLLayer::draw_in_open_gl_context(const OpenGLContext& context, const OpenGLPixelFormat& pixel_format, double t, const CVTimeStamp* ts) const
    {
        [cocoon::internal::ns<::NSOpenGLLayer>(this) drawInOpenGLContext:cocoon::internal::native<::NSOpenGLContext>(context) pixelFormat:cocoon::internal::native<::NSOpenGLPixelFormat>(pixel_format) forLayerTime:static_cast<::CFTimeInterval>(t) displayTime:(const ::CVTimeStamp*)(ts)];
    }

    OpenGLContext OpenGLLayer::open_gl_context_for_pixel_format(const OpenGLPixelFormat& pixel_format) const
    {
        return cocoon::internal::wrap<OpenGLContext>([cocoon::internal::ns<::NSOpenGLLayer>(this) openGLContextForPixelFormat:cocoon::internal::native<::NSOpenGLPixelFormat>(pixel_format)]);
    }

    OpenGLPixelFormat OpenGLLayer::open_gl_pixel_format_for_display_mask(unsigned int mask) const
    {
        return cocoon::internal::wrap<OpenGLPixelFormat>([cocoon::internal::ns<::NSOpenGLLayer>(this) openGLPixelFormatForDisplayMask:static_cast<::uint32_t>(mask)]);
    }

    OpenGLContext OpenGLLayer::open_gl_context() const
    {
        return cocoon::internal::wrap<OpenGLContext>([cocoon::internal::ns<::NSOpenGLLayer>(this) openGLContext]);
    }

    void OpenGLLayer::set_open_gl_context(const OpenGLContext& value) const
    {
        [cocoon::internal::ns<::NSOpenGLLayer>(this) setOpenGLContext:cocoon::internal::native<::NSOpenGLContext>(value)];
    }

    OpenGLPixelFormat OpenGLLayer::open_gl_pixel_format() const
    {
        return cocoon::internal::wrap<OpenGLPixelFormat>([cocoon::internal::ns<::NSOpenGLLayer>(this) openGLPixelFormat]);
    }

    void OpenGLLayer::set_open_gl_pixel_format(const OpenGLPixelFormat& value) const
    {
        [cocoon::internal::ns<::NSOpenGLLayer>(this) setOpenGLPixelFormat:cocoon::internal::native<::NSOpenGLPixelFormat>(value)];
    }

    View OpenGLLayer::view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSOpenGLLayer>(this) view]);
    }

    void OpenGLLayer::set_view(const View& value) const
    {
        [cocoon::internal::ns<::NSOpenGLLayer>(this) setView:cocoon::internal::native<::NSView>(value)];
    }
}
