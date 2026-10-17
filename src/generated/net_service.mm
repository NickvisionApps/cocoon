#include "generated/net_service.h"
#include "internal.h"

@interface AKNetServiceDelegate : NSObject <NSNetServiceDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKNetServiceDelegate

- (void)netServiceWillPublish:(NSNetService*)sender
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::NetService, void()>::emit((__bridge void*)strongHost, "will_publish");
}

- (void)netServiceDidPublish:(NSNetService*)sender
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::NetService, void()>::emit((__bridge void*)strongHost, "did_publish");
}

- (void)netService:(NSNetService*)sender didNotPublish:(NSDictionary<NSString*, NSNumber*>*)errorDict
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::NetService, void(std::map<std::string, cocoon::Number>)>::emit((__bridge void*)strongHost, "did_not_publish", cocoon::internal::from_dictionary<std::map<std::string, cocoon::Number>>(errorDict, [](id k) -> std::string
                                                                                                                                                                                                    {
                                                                                                                                                                                                        return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                    },
                                                                                                                                                                                                    [](id v) -> cocoon::Number
                                                                                                                                                                                                    {
                                                                                                                                                                                                        return cocoon::internal::wrap<cocoon::Number>((::NSNumber*)v);
                                                                                                                                                                                                    }));
}

- (void)netServiceWillResolve:(NSNetService*)sender
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::NetService, void()>::emit((__bridge void*)strongHost, "will_resolve");
}

- (void)netServiceDidResolveAddress:(NSNetService*)sender
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::NetService, void()>::emit((__bridge void*)strongHost, "did_resolve_address");
}

- (void)netService:(NSNetService*)sender didNotResolve:(NSDictionary<NSString*, NSNumber*>*)errorDict
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::NetService, void(std::map<std::string, cocoon::Number>)>::emit((__bridge void*)strongHost, "did_not_resolve", cocoon::internal::from_dictionary<std::map<std::string, cocoon::Number>>(errorDict, [](id k) -> std::string
                                                                                                                                                                                                    {
                                                                                                                                                                                                        return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                    },
                                                                                                                                                                                                    [](id v) -> cocoon::Number
                                                                                                                                                                                                    {
                                                                                                                                                                                                        return cocoon::internal::wrap<cocoon::Number>((::NSNumber*)v);
                                                                                                                                                                                                    }));
}

- (void)netServiceDidStop:(NSNetService*)sender
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::NetService, void()>::emit((__bridge void*)strongHost, "did_stop");
}

- (void)netService:(NSNetService*)sender didUpdateTXTRecordData:(NSData*)data
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::NetService, void(std::vector<std::uint8_t>)>::emit((__bridge void*)strongHost, "did_update_txt_record_data", cocoon::internal::from_data(data));
}

- (void)netService:(NSNetService*)sender didAcceptConnectionWithInputStream:(NSInputStream*)inputStream outputStream:(NSOutputStream*)outputStream
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::NetService, void(cocoon::InputStream, cocoon::OutputStream)>::emit((__bridge void*)strongHost, "did_accept_connection_with_input_stream_output_stream", cocoon::internal::wrap<cocoon::InputStream>(inputStream), cocoon::internal::wrap<cocoon::OutputStream>(outputStream));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(netServiceWillPublish:))
    {
        return strongHost && cocoon::Signal<cocoon::NetService, void()>::connected((__bridge void*)strongHost, "will_publish");
    }
    if (selector == @selector(netServiceDidPublish:))
    {
        return strongHost && cocoon::Signal<cocoon::NetService, void()>::connected((__bridge void*)strongHost, "did_publish");
    }
    if (selector == @selector(netService:didNotPublish:))
    {
        return strongHost && cocoon::Signal<cocoon::NetService, void(std::map<std::string, cocoon::Number>)>::connected((__bridge void*)strongHost, "did_not_publish");
    }
    if (selector == @selector(netServiceWillResolve:))
    {
        return strongHost && cocoon::Signal<cocoon::NetService, void()>::connected((__bridge void*)strongHost, "will_resolve");
    }
    if (selector == @selector(netServiceDidResolveAddress:))
    {
        return strongHost && cocoon::Signal<cocoon::NetService, void()>::connected((__bridge void*)strongHost, "did_resolve_address");
    }
    if (selector == @selector(netService:didNotResolve:))
    {
        return strongHost && cocoon::Signal<cocoon::NetService, void(std::map<std::string, cocoon::Number>)>::connected((__bridge void*)strongHost, "did_not_resolve");
    }
    if (selector == @selector(netServiceDidStop:))
    {
        return strongHost && cocoon::Signal<cocoon::NetService, void()>::connected((__bridge void*)strongHost, "did_stop");
    }
    if (selector == @selector(netService:didUpdateTXTRecordData:))
    {
        return strongHost && cocoon::Signal<cocoon::NetService, void(std::vector<std::uint8_t>)>::connected((__bridge void*)strongHost, "did_update_txt_record_data");
    }
    if (selector == @selector(netService:didAcceptConnectionWithInputStream:outputStream:))
    {
        return strongHost && cocoon::Signal<cocoon::NetService, void(cocoon::InputStream, cocoon::OutputStream)>::connected((__bridge void*)strongHost, "did_accept_connection_with_input_stream_output_stream");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    NetService::NetService(const std::string& domain, const std::string& type, const std::string& name) : NetService(Adopt{cocoon::internal::retain([[::NSNetService alloc] initWithDomain:cocoon::internal::to(domain) type:cocoon::internal::to(type) name:cocoon::internal::to(name)])})
    {
        NetService::install_delegate_delegate_(handle());
    }

    NetService::NetService(const std::string& domain, const std::string& type, const std::string& name, int port) : NetService(Adopt{cocoon::internal::retain([[::NSNetService alloc] initWithDomain:cocoon::internal::to(domain) type:cocoon::internal::to(type) name:cocoon::internal::to(name) port:static_cast<int>(port)])})
    {
        NetService::install_delegate_delegate_(handle());
    }

    NetService::NetService() : NetService(Adopt{cocoon::internal::retain([[::NSNetService alloc] init])})
    {
        NetService::install_delegate_delegate_(handle());
    }

    NetService::NetService(std::nullptr_t) : Object(nullptr)
    {
    }

    NetService::NetService(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<std::uint8_t> NetService::txt_record_data() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSNetService>(this) TXTRecordData]);
    }

    std::vector<std::uint8_t> NetService::data_from_txt_record_dictionary(const std::map<std::string, std::vector<std::uint8_t>>& txt_dictionary)
    {
        return cocoon::internal::from_data([::NSNetService dataFromTXTRecordDictionary:cocoon::internal::to_dictionary(txt_dictionary, [](const std::string& k) -> id
                                                                                           {
                                                                                               return cocoon::internal::to(k);
                                                                                           },
                                                                                           [](const std::vector<std::uint8_t>& v) -> id
                                                                                           {
                                                                                               return cocoon::internal::to_data(v);
                                                                                           })]);
    }

    std::map<std::string, std::vector<std::uint8_t>> NetService::dictionary_from_txt_record_data(const std::vector<std::uint8_t>& txt_data)
    {
        return cocoon::internal::from_dictionary<std::map<std::string, std::vector<std::uint8_t>>>([::NSNetService dictionaryFromTXTRecordData:cocoon::internal::to_data(txt_data)], [](id k) -> std::string
                                                                                     {
                                                                                         return cocoon::internal::from((NSString*)k);
                                                                                     },
                                                                                     [](id v) -> std::vector<std::uint8_t>
                                                                                     {
                                                                                         return cocoon::internal::from_data((NSData*)v);
                                                                                     });
    }

    bool NetService::get_input_stream(InputStream& input_stream, OutputStream& output_stream) const
    {
        ::NSInputStream* __v_input_stream = nil;
        ::NSOutputStream* __v_output_stream = nil;
        auto __r = [cocoon::internal::ns<::NSNetService>(this) getInputStream:&__v_input_stream outputStream:&__v_output_stream];
        input_stream = cocoon::internal::wrap<InputStream>(__v_input_stream);
        output_stream = cocoon::internal::wrap<OutputStream>(__v_output_stream);
        return static_cast<bool>(__r);
    }

    void NetService::publish() const
    {
        [cocoon::internal::ns<::NSNetService>(this) publish];
    }

    void NetService::publish_with_options(NetServiceOptions options) const
    {
        [cocoon::internal::ns<::NSNetService>(this) publishWithOptions:static_cast<::NSNetServiceOptions>(options)];
    }

    void NetService::remove_from_run_loop(const RunLoop& a_run_loop, const std::string& mode) const
    {
        [cocoon::internal::ns<::NSNetService>(this) removeFromRunLoop:cocoon::internal::native<::NSRunLoop>(a_run_loop) forMode:cocoon::internal::to(mode)];
    }

    void NetService::resolve_with_timeout(double timeout) const
    {
        [cocoon::internal::ns<::NSNetService>(this) resolveWithTimeout:static_cast<::NSTimeInterval>(timeout)];
    }

    void NetService::schedule_in_run_loop(const RunLoop& a_run_loop, const std::string& mode) const
    {
        [cocoon::internal::ns<::NSNetService>(this) scheduleInRunLoop:cocoon::internal::native<::NSRunLoop>(a_run_loop) forMode:cocoon::internal::to(mode)];
    }

    bool NetService::set_txt_record_data(const std::vector<std::uint8_t>& record_data) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSNetService>(this) setTXTRecordData:cocoon::internal::to_data(record_data)]);
    }

    void NetService::start_monitoring() const
    {
        [cocoon::internal::ns<::NSNetService>(this) startMonitoring];
    }

    void NetService::stop() const
    {
        [cocoon::internal::ns<::NSNetService>(this) stop];
    }

    void NetService::stop_monitoring() const
    {
        [cocoon::internal::ns<::NSNetService>(this) stopMonitoring];
    }

    std::vector<std::vector<std::uint8_t>> NetService::addresses() const
    {
        return cocoon::internal::from_array<std::vector<std::uint8_t>>([cocoon::internal::ns<::NSNetService>(this) addresses], [](id e) -> std::vector<std::uint8_t>
                                                         {
                                                             return cocoon::internal::from_data((NSData*)e);
                                                         });
    }

    std::string NetService::domain() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNetService>(this) domain]);
    }

    std::string NetService::host_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNetService>(this) hostName]);
    }

    bool NetService::includes_peer_to_peer() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSNetService>(this) includesPeerToPeer]);
    }

    void NetService::set_includes_peer_to_peer(bool value) const
    {
        [cocoon::internal::ns<::NSNetService>(this) setIncludesPeerToPeer:static_cast<::BOOL>(value)];
    }

    std::string NetService::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNetService>(this) name]);
    }

    std::int64_t NetService::port() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSNetService>(this) port]);
    }

    std::string NetService::type() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNetService>(this) type]);
    }

    void NetService::install_delegate_delegate_(void* native)
    {
        ::NSNetService* host = (__bridge ::NSNetService*)native;
        AKNetServiceDelegate* delegate = [[AKNetServiceDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSNetService* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSNetService* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
