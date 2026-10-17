#include "generated/input_stream.h"
#include "internal.h"

namespace cocoon
{
    InputStream::InputStream(const std::vector<std::uint8_t>& data) : InputStream(Adopt{cocoon::internal::retain([[::NSInputStream alloc] initWithData:cocoon::internal::to_data(data)])})
    {
        Stream::install_delegate_delegate_(handle());
    }

    InputStream::InputStream(const std::string& path) : InputStream(Adopt{cocoon::internal::retain([[::NSInputStream alloc] initWithFileAtPath:cocoon::internal::to(path)])})
    {
        Stream::install_delegate_delegate_(handle());
    }

    InputStream::InputStream(const URL& url) : InputStream(Adopt{cocoon::internal::retain([[::NSInputStream alloc] initWithURL:cocoon::internal::native<::NSURL>(url)])})
    {
        Stream::install_delegate_delegate_(handle());
    }

    InputStream::InputStream() : InputStream(Adopt{cocoon::internal::retain([[::NSInputStream alloc] init])})
    {
        Stream::install_delegate_delegate_(handle());
    }

    InputStream::InputStream(std::nullptr_t) : Stream(nullptr)
    {
    }

    InputStream::InputStream(Adopt adopt) : Stream(adopt)
    {
    }

    bool InputStream::get_buffer(std::uint8_t** buffer, std::uint64_t* len) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSInputStream>(this) getBuffer:(::uint8_t**)(buffer) length:(::NSUInteger*)(len)]);
    }

    InputStream InputStream::input_stream_with_data(const std::vector<std::uint8_t>& data)
    {
        return cocoon::internal::wrap<InputStream>([::NSInputStream inputStreamWithData:cocoon::internal::to_data(data)]);
    }

    InputStream InputStream::input_stream_with_file_at_path(const std::string& path)
    {
        return cocoon::internal::wrap<InputStream>([::NSInputStream inputStreamWithFileAtPath:cocoon::internal::to(path)]);
    }

    InputStream InputStream::input_stream_with_url(const URL& url)
    {
        return cocoon::internal::wrap<InputStream>([::NSInputStream inputStreamWithURL:cocoon::internal::native<::NSURL>(url)]);
    }

    std::int64_t InputStream::read(std::uint8_t* buffer, std::uint64_t len) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSInputStream>(this) read:(::uint8_t*)(buffer) maxLength:static_cast<::NSUInteger>(len)]);
    }

    bool InputStream::has_bytes_available() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSInputStream>(this) hasBytesAvailable]);
    }
}
