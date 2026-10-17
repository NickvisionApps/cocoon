#include "generated/open_gl_pixel_buffer.h"
#include "internal.h"

namespace cocoon
{
    OpenGLPixelBuffer::OpenGLPixelBuffer() : OpenGLPixelBuffer(Adopt{cocoon::internal::retain([[::NSOpenGLPixelBuffer alloc] init])})
    {
    }

    OpenGLPixelBuffer::OpenGLPixelBuffer(std::nullptr_t) : Object(nullptr)
    {
    }

    OpenGLPixelBuffer::OpenGLPixelBuffer(Adopt adopt) : Object(adopt)
    {
    }

    CGLPBufferObj OpenGLPixelBuffer::cglp_buffer_obj() const
    {
        return cocoon::internal::wrap_cf<CGLPBufferObj>((const void*)([cocoon::internal::ns<::NSOpenGLPixelBuffer>(this) CGLPBufferObj]));
    }
}
