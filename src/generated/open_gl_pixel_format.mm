#include "generated/open_gl_pixel_format.h"
#include "internal.h"

namespace cocoon
{
    OpenGLPixelFormat::OpenGLPixelFormat(const unsigned int* attribs) : OpenGLPixelFormat(Adopt{cocoon::internal::retain([[::NSOpenGLPixelFormat alloc] initWithAttributes:(const ::NSOpenGLPixelFormatAttribute*)(attribs)])})
    {
    }

    OpenGLPixelFormat::OpenGLPixelFormat(const CGLPixelFormatObj& format) : OpenGLPixelFormat(Adopt{cocoon::internal::retain([[::NSOpenGLPixelFormat alloc] initWithCGLPixelFormatObj:((::CGLPixelFormatObj)(format).handle())])})
    {
    }

    OpenGLPixelFormat::OpenGLPixelFormat() : OpenGLPixelFormat(Adopt{cocoon::internal::retain([[::NSOpenGLPixelFormat alloc] init])})
    {
    }

    OpenGLPixelFormat::OpenGLPixelFormat(std::nullptr_t) : Object(nullptr)
    {
    }

    OpenGLPixelFormat::OpenGLPixelFormat(Adopt adopt) : Object(adopt)
    {
    }

    void OpenGLPixelFormat::get_values(int* vals, unsigned int attrib, int screen) const
    {
        [cocoon::internal::ns<::NSOpenGLPixelFormat>(this) getValues:(::GLint*)(vals) forAttribute:static_cast<::NSOpenGLPixelFormatAttribute>(attrib) forVirtualScreen:static_cast<::GLint>(screen)];
    }

    CGLPixelFormatObj OpenGLPixelFormat::cgl_pixel_format_obj() const
    {
        return cocoon::internal::wrap_cf<CGLPixelFormatObj>((const void*)([cocoon::internal::ns<::NSOpenGLPixelFormat>(this) CGLPixelFormatObj]));
    }

    int OpenGLPixelFormat::number_of_virtual_screens() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSOpenGLPixelFormat>(this) numberOfVirtualScreens]);
    }
}
