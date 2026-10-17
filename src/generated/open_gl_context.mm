#include "generated/open_gl_context.h"
#include "internal.h"

namespace cocoon
{
    OpenGLContext::OpenGLContext(const CGLContextObj& context) : OpenGLContext(Adopt{cocoon::internal::retain([[::NSOpenGLContext alloc] initWithCGLContextObj:((::CGLContextObj)(context).handle())])})
    {
    }

    OpenGLContext::OpenGLContext(const OpenGLPixelFormat& format, const OpenGLContext& share) : OpenGLContext(Adopt{cocoon::internal::retain([[::NSOpenGLContext alloc] initWithFormat:cocoon::internal::native<::NSOpenGLPixelFormat>(format) shareContext:cocoon::internal::native<::NSOpenGLContext>(share)])})
    {
    }

    OpenGLContext::OpenGLContext() : OpenGLContext(Adopt{cocoon::internal::retain([[::NSOpenGLContext alloc] init])})
    {
    }

    OpenGLContext::OpenGLContext(std::nullptr_t) : Object(nullptr)
    {
    }

    OpenGLContext::OpenGLContext(Adopt adopt) : Object(adopt)
    {
    }

    void OpenGLContext::clear_current_context()
    {
        [::NSOpenGLContext clearCurrentContext];
    }

    void OpenGLContext::clear_drawable() const
    {
        [cocoon::internal::ns<::NSOpenGLContext>(this) clearDrawable];
    }

    void OpenGLContext::flush_buffer() const
    {
        [cocoon::internal::ns<::NSOpenGLContext>(this) flushBuffer];
    }

    void OpenGLContext::get_values(int* vals, OpenGLContextParameter param) const
    {
        [cocoon::internal::ns<::NSOpenGLContext>(this) getValues:(::GLint*)(vals) forParameter:static_cast<::NSOpenGLContextParameter>(param)];
    }

    void OpenGLContext::make_current_context() const
    {
        [cocoon::internal::ns<::NSOpenGLContext>(this) makeCurrentContext];
    }

    void OpenGLContext::set_values(const int* vals, OpenGLContextParameter param) const
    {
        [cocoon::internal::ns<::NSOpenGLContext>(this) setValues:(const ::GLint*)(vals) forParameter:static_cast<::NSOpenGLContextParameter>(param)];
    }

    void OpenGLContext::update() const
    {
        [cocoon::internal::ns<::NSOpenGLContext>(this) update];
    }

    CGLContextObj OpenGLContext::cgl_context_obj() const
    {
        return cocoon::internal::wrap_cf<CGLContextObj>((const void*)([cocoon::internal::ns<::NSOpenGLContext>(this) CGLContextObj]));
    }

    OpenGLContext OpenGLContext::current_context()
    {
        return cocoon::internal::wrap<OpenGLContext>([::NSOpenGLContext currentContext]);
    }

    int OpenGLContext::current_virtual_screen() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSOpenGLContext>(this) currentVirtualScreen]);
    }

    void OpenGLContext::set_current_virtual_screen(int value) const
    {
        [cocoon::internal::ns<::NSOpenGLContext>(this) setCurrentVirtualScreen:static_cast<::GLint>(value)];
    }

    OpenGLPixelFormat OpenGLContext::pixel_format() const
    {
        return cocoon::internal::wrap<OpenGLPixelFormat>([cocoon::internal::ns<::NSOpenGLContext>(this) pixelFormat]);
    }
}
