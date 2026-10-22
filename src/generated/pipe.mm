#include "generated/pipe.h"
#include "internal.h"

namespace cocoon
{
    Pipe::Pipe() : Pipe(Adopt{cocoon::internal::retain([::NSPipe pipe])})
    {
    }

    Pipe::Pipe(std::nullptr_t) : Object(nullptr)
    {
    }

    Pipe::Pipe(Adopt adopt) : Object(adopt)
    {
    }

    FileHandle Pipe::file_handle_for_reading() const
    {
        return cocoon::internal::wrap<FileHandle>([cocoon::internal::ns<::NSPipe>(this) fileHandleForReading]);
    }

    FileHandle Pipe::file_handle_for_writing() const
    {
        return cocoon::internal::wrap<FileHandle>([cocoon::internal::ns<::NSPipe>(this) fileHandleForWriting]);
    }
}
