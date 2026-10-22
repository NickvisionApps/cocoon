#include "generated/output_stream.h"
#include "internal.h"

namespace cocoon
{
    OutputStream::OutputStream(std::uint8_t* buffer, std::uint64_t capacity) : OutputStream(Adopt{cocoon::internal::retain([[::NSOutputStream alloc] initToBuffer:(::uint8_t*)(buffer) capacity:static_cast<::NSUInteger>(capacity)])})
    {
        Stream::install_delegate_delegate_(handle());
    }

    OutputStream::OutputStream(const std::string& path, bool should_append) : OutputStream(Adopt{cocoon::internal::retain([[::NSOutputStream alloc] initToFileAtPath:cocoon::internal::to(path) append:static_cast<::BOOL>(should_append)])})
    {
        Stream::install_delegate_delegate_(handle());
    }

    OutputStream::OutputStream() : OutputStream(Adopt{cocoon::internal::retain([[::NSOutputStream alloc] initToMemory])})
    {
        Stream::install_delegate_delegate_(handle());
    }

    OutputStream::OutputStream(const URL& url, bool should_append) : OutputStream(Adopt{cocoon::internal::retain([[::NSOutputStream alloc] initWithURL:cocoon::internal::native<::NSURL>(url) append:static_cast<::BOOL>(should_append)])})
    {
        Stream::install_delegate_delegate_(handle());
    }

    OutputStream::OutputStream(std::nullptr_t) : Stream(nullptr)
    {
    }

    OutputStream::OutputStream(Adopt adopt) : Stream(adopt)
    {
    }

    OutputStream OutputStream::output_stream_to_buffer(std::uint8_t* buffer, std::uint64_t capacity)
    {
        return cocoon::internal::wrap<OutputStream>([::NSOutputStream outputStreamToBuffer:(::uint8_t*)(buffer) capacity:static_cast<::NSUInteger>(capacity)]);
    }

    OutputStream OutputStream::output_stream_to_file_at_path(const std::string& path, bool should_append)
    {
        return cocoon::internal::wrap<OutputStream>([::NSOutputStream outputStreamToFileAtPath:cocoon::internal::to(path) append:static_cast<::BOOL>(should_append)]);
    }

    OutputStream OutputStream::output_stream_to_memory()
    {
        return cocoon::internal::wrap<OutputStream>([::NSOutputStream outputStreamToMemory]);
    }

    std::int64_t OutputStream::write(const std::uint8_t* buffer, std::uint64_t len) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSOutputStream>(this) write:(const ::uint8_t*)(buffer) maxLength:static_cast<::NSUInteger>(len)]);
    }

    bool OutputStream::has_space_available() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOutputStream>(this) hasSpaceAvailable]);
    }
}
