#include "generated/open_gl_view.h"
#include "internal.h"

namespace cocoon
{
    OpenGLView::OpenGLView(const Rect& frame_rect, const OpenGLPixelFormat& format) : OpenGLView(Adopt{cocoon::internal::retain([[::NSOpenGLView alloc] initWithFrame:cocoon::internal::to(frame_rect) pixelFormat:cocoon::internal::native<::NSOpenGLPixelFormat>(format)])})
    {
    }

    OpenGLView::OpenGLView() : OpenGLView(Adopt{cocoon::internal::retain([[::NSOpenGLView alloc] init])})
    {
    }

    OpenGLView::OpenGLView(std::nullptr_t) : View(nullptr)
    {
    }

    OpenGLView::OpenGLView(Adopt adopt) : View(adopt)
    {
    }

    void OpenGLView::clear_gl_context() const
    {
        [cocoon::internal::ns<::NSOpenGLView>(this) clearGLContext];
    }

    OpenGLPixelFormat OpenGLView::default_pixel_format()
    {
        return cocoon::internal::wrap<OpenGLPixelFormat>([::NSOpenGLView defaultPixelFormat]);
    }

    void OpenGLView::prepare_open_gl() const
    {
        [cocoon::internal::ns<::NSOpenGLView>(this) prepareOpenGL];
    }

    void OpenGLView::reshape() const
    {
        [cocoon::internal::ns<::NSOpenGLView>(this) reshape];
    }

    void OpenGLView::update() const
    {
        [cocoon::internal::ns<::NSOpenGLView>(this) update];
    }

    OpenGLContext OpenGLView::open_gl_context() const
    {
        return cocoon::internal::wrap<OpenGLContext>([cocoon::internal::ns<::NSOpenGLView>(this) openGLContext]);
    }

    void OpenGLView::set_open_gl_context(const OpenGLContext& value) const
    {
        [cocoon::internal::ns<::NSOpenGLView>(this) setOpenGLContext:cocoon::internal::native<::NSOpenGLContext>(value)];
    }

    OpenGLPixelFormat OpenGLView::pixel_format() const
    {
        return cocoon::internal::wrap<OpenGLPixelFormat>([cocoon::internal::ns<::NSOpenGLView>(this) pixelFormat]);
    }

    void OpenGLView::set_pixel_format(const OpenGLPixelFormat& value) const
    {
        [cocoon::internal::ns<::NSOpenGLView>(this) setPixelFormat:cocoon::internal::native<::NSOpenGLPixelFormat>(value)];
    }

    bool OpenGLView::wants_best_resolution_open_gl_surface() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOpenGLView>(this) wantsBestResolutionOpenGLSurface]);
    }

    void OpenGLView::set_wants_best_resolution_open_gl_surface(bool value) const
    {
        [cocoon::internal::ns<::NSOpenGLView>(this) setWantsBestResolutionOpenGLSurface:static_cast<::BOOL>(value)];
    }

    bool OpenGLView::wants_extended_dynamic_range_open_gl_surface() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOpenGLView>(this) wantsExtendedDynamicRangeOpenGLSurface]);
    }

    void OpenGLView::set_wants_extended_dynamic_range_open_gl_surface(bool value) const
    {
        [cocoon::internal::ns<::NSOpenGLView>(this) setWantsExtendedDynamicRangeOpenGLSurface:static_cast<::BOOL>(value)];
    }
}
