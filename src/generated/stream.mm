#include "generated/stream.h"
#include "internal.h"

@interface AKStreamDelegate : NSObject <NSStreamDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKStreamDelegate

- (void)stream:(NSStream*)aStream handleEvent:(NSStreamEvent)eventCode
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Stream, void(cocoon::StreamEvent)>::emit((__bridge void*)strongHost, "handle_event", static_cast<cocoon::StreamEvent>(eventCode));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(stream:handleEvent:))
    {
        return strongHost && cocoon::Signal<cocoon::Stream, void(cocoon::StreamEvent)>::connected((__bridge void*)strongHost, "handle_event");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    Stream::Stream() : Stream(Adopt{cocoon::internal::retain([[::NSStream alloc] init])})
    {
        Stream::install_delegate_delegate_(handle());
    }

    Stream::Stream(std::nullptr_t) : Object(nullptr)
    {
    }

    Stream::Stream(Adopt adopt) : Object(adopt)
    {
    }

    void Stream::close() const
    {
        [cocoon::internal::ns<::NSStream>(this) close];
    }

    void Stream::get_bound_streams_with_buffer_size(std::uint64_t buffer_size, InputStream& input_stream, OutputStream& output_stream)
    {
        ::NSInputStream* __v_input_stream = nil;
        ::NSOutputStream* __v_output_stream = nil;
        [::NSStream getBoundStreamsWithBufferSize:static_cast<::NSUInteger>(buffer_size) inputStream:&__v_input_stream outputStream:&__v_output_stream];
        input_stream = cocoon::internal::wrap<InputStream>(__v_input_stream);
        output_stream = cocoon::internal::wrap<OutputStream>(__v_output_stream);
    }

    void Stream::get_streams_to_host_with_name(const std::string& hostname, std::int64_t port, InputStream& input_stream, OutputStream& output_stream)
    {
        ::NSInputStream* __v_input_stream = nil;
        ::NSOutputStream* __v_output_stream = nil;
        [::NSStream getStreamsToHostWithName:cocoon::internal::to(hostname) port:static_cast<::NSInteger>(port) inputStream:&__v_input_stream outputStream:&__v_output_stream];
        input_stream = cocoon::internal::wrap<InputStream>(__v_input_stream);
        output_stream = cocoon::internal::wrap<OutputStream>(__v_output_stream);
    }

    void Stream::open() const
    {
        [cocoon::internal::ns<::NSStream>(this) open];
    }

    Object Stream::property_for_key(const std::string& key) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSStream>(this) propertyForKey:cocoon::internal::to(key)]);
    }

    void Stream::remove_from_run_loop(const RunLoop& a_run_loop, const std::string& mode) const
    {
        [cocoon::internal::ns<::NSStream>(this) removeFromRunLoop:cocoon::internal::native<::NSRunLoop>(a_run_loop) forMode:cocoon::internal::to(mode)];
    }

    void Stream::schedule_in_run_loop(const RunLoop& a_run_loop, const std::string& mode) const
    {
        [cocoon::internal::ns<::NSStream>(this) scheduleInRunLoop:cocoon::internal::native<::NSRunLoop>(a_run_loop) forMode:cocoon::internal::to(mode)];
    }

    bool Stream::set_property(const Object& property, const std::string& key) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSStream>(this) setProperty:cocoon::internal::native_id(property) forKey:cocoon::internal::to(key)]);
    }

    Error Stream::stream_error() const
    {
        return cocoon::internal::wrap<Error>([cocoon::internal::ns<::NSStream>(this) streamError]);
    }

    StreamStatus Stream::stream_status() const
    {
        return static_cast<StreamStatus>([cocoon::internal::ns<::NSStream>(this) streamStatus]);
    }

    void Stream::install_delegate_delegate_(void* native)
    {
        ::NSStream* host = (__bridge ::NSStream*)native;
        AKStreamDelegate* delegate = [[AKStreamDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSStream* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSStream* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
