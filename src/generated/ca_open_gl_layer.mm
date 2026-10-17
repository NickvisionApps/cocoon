#include "generated/ca_open_gl_layer.h"
#include "internal.h"

namespace cocoon
{
    CAOpenGLLayer::CAOpenGLLayer() : CAOpenGLLayer(Adopt{cocoon::internal::retain([[::CAOpenGLLayer alloc] init])})
    {
        CALayer::install_delegate_delegate_(handle());
    }

    CAOpenGLLayer::CAOpenGLLayer(std::nullptr_t) : CALayer(nullptr)
    {
    }

    CAOpenGLLayer::CAOpenGLLayer(Adopt adopt) : CALayer(adopt)
    {
    }

    bool CAOpenGLLayer::can_draw_in_cgl_context(const CGLContextObj& ctx, const CGLPixelFormatObj& pf, double t, const CVTimeStamp* ts) const
    {
        return static_cast<bool>([cocoon::internal::ns<::CAOpenGLLayer>(this) canDrawInCGLContext:((::CGLContextObj)(ctx).handle()) pixelFormat:((::CGLPixelFormatObj)(pf).handle())forLayerTime:static_cast<::CFTimeInterval>(t) displayTime:(const ::CVTimeStamp*)(ts)]);
    }

    CGLContextObj CAOpenGLLayer::copy_cgl_context_for_pixel_format(const CGLPixelFormatObj& pf) const
    {
        return cocoon::internal::wrap_cf<CGLContextObj>((const void*)([cocoon::internal::ns<::CAOpenGLLayer>(this) copyCGLContextForPixelFormat:((::CGLPixelFormatObj)(pf).handle())]));
    }

    CGLPixelFormatObj CAOpenGLLayer::copy_cgl_pixel_format_for_display_mask(unsigned int mask) const
    {
        return cocoon::internal::wrap_cf<CGLPixelFormatObj>((const void*)([cocoon::internal::ns<::CAOpenGLLayer>(this) copyCGLPixelFormatForDisplayMask:static_cast<::uint32_t>(mask)]));
    }

    void CAOpenGLLayer::draw_in_cgl_context(const CGLContextObj& ctx, const CGLPixelFormatObj& pf, double t, const CVTimeStamp* ts) const
    {
        [cocoon::internal::ns<::CAOpenGLLayer>(this) drawInCGLContext:((::CGLContextObj)(ctx).handle()) pixelFormat:((::CGLPixelFormatObj)(pf).handle())forLayerTime:static_cast<::CFTimeInterval>(t) displayTime:(const ::CVTimeStamp*)(ts)];
    }

    void CAOpenGLLayer::release_cgl_context(const CGLContextObj& ctx) const
    {
        [cocoon::internal::ns<::CAOpenGLLayer>(this) releaseCGLContext:((::CGLContextObj)(ctx).handle())];
    }

    void CAOpenGLLayer::release_cgl_pixel_format(const CGLPixelFormatObj& pf) const
    {
        [cocoon::internal::ns<::CAOpenGLLayer>(this) releaseCGLPixelFormat:((::CGLPixelFormatObj)(pf).handle())];
    }

    bool CAOpenGLLayer::is_asynchronous() const
    {
        return static_cast<bool>([cocoon::internal::ns<::CAOpenGLLayer>(this) isAsynchronous]);
    }

    void CAOpenGLLayer::set_asynchronous(bool value) const
    {
        [cocoon::internal::ns<::CAOpenGLLayer>(this) setAsynchronous:static_cast<::BOOL>(value)];
    }

    CGColorSpace CAOpenGLLayer::colorspace() const
    {
        return cocoon::internal::wrap_cf<CGColorSpace>((const void*)([cocoon::internal::ns<::CAOpenGLLayer>(this) colorspace]));
    }

    void CAOpenGLLayer::set_colorspace(const CGColorSpace& value) const
    {
        [cocoon::internal::ns<::CAOpenGLLayer>(this) setColorspace:((::CGColorSpaceRef)(value).handle())];
    }

    bool CAOpenGLLayer::wants_extended_dynamic_range_content() const
    {
        return static_cast<bool>([cocoon::internal::ns<::CAOpenGLLayer>(this) wantsExtendedDynamicRangeContent]);
    }

    void CAOpenGLLayer::set_wants_extended_dynamic_range_content(bool value) const
    {
        [cocoon::internal::ns<::CAOpenGLLayer>(this) setWantsExtendedDynamicRangeContent:static_cast<::BOOL>(value)];
    }
}
