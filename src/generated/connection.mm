#include "generated/connection.h"
#include "internal.h"

@interface AKConnectionDelegate : NSObject <NSConnectionDelegate>
{
@public
    __unsafe_unretained id host;
}
@end

@implementation AKConnectionDelegate

- (BOOL)makeNewConnection:(NSConnection*)conn sender:(NSConnection*)ancestor
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Connection, bool(cocoon::Connection)>::emit((__bridge void*)strongHost, "make_new_connection_sender", cocoon::internal::wrap<cocoon::Connection>(ancestor));
    return static_cast<::BOOL>(__r);
}

- (BOOL)connection:(NSConnection*)ancestor shouldMakeNewConnection:(NSConnection*)conn
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Connection, bool(cocoon::Connection)>::emit((__bridge void*)strongHost, "should_make_new_connection", cocoon::internal::wrap<cocoon::Connection>(conn));
    return static_cast<::BOOL>(__r);
}

- (NSData*)authenticationDataForComponents:(NSArray*)components
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Connection, std::vector<std::uint8_t>()>::emit((__bridge void*)strongHost, "authentication_data_for_components");
    return cocoon::internal::to_data(__r);
}

- (BOOL)authenticateComponents:(NSArray*)components withData:(NSData*)signature
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Connection, bool(std::vector<std::uint8_t>)>::emit((__bridge void*)strongHost, "authenticate_components_with_data", cocoon::internal::from_data(signature));
    return static_cast<::BOOL>(__r);
}

- (id)createConversationForConnection:(NSConnection*)conn
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Connection, cocoon::Object()>::emit((__bridge void*)strongHost, "create_conversation_for_connection");
    return cocoon::internal::native_id(__r);
}

- (BOOL)connection:(NSConnection*)connection handleRequest:(NSDistantObjectRequest*)doreq
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Connection, bool(cocoon::DistantObjectRequest)>::emit((__bridge void*)strongHost, "handle_request", cocoon::internal::wrap<cocoon::DistantObjectRequest>(doreq));
    return static_cast<::BOOL>(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(makeNewConnection:sender:))
    {
        return strongHost && cocoon::Signal<cocoon::Connection, bool(cocoon::Connection)>::connected((__bridge void*)strongHost, "make_new_connection_sender");
    }
    if (selector == @selector(connection:shouldMakeNewConnection:))
    {
        return strongHost && cocoon::Signal<cocoon::Connection, bool(cocoon::Connection)>::connected((__bridge void*)strongHost, "should_make_new_connection");
    }
    if (selector == @selector(authenticationDataForComponents:))
    {
        return strongHost && cocoon::Signal<cocoon::Connection, std::vector<std::uint8_t>()>::connected((__bridge void*)strongHost, "authentication_data_for_components");
    }
    if (selector == @selector(authenticateComponents:withData:))
    {
        return strongHost && cocoon::Signal<cocoon::Connection, bool(std::vector<std::uint8_t>)>::connected((__bridge void*)strongHost, "authenticate_components_with_data");
    }
    if (selector == @selector(createConversationForConnection:))
    {
        return strongHost && cocoon::Signal<cocoon::Connection, cocoon::Object()>::connected((__bridge void*)strongHost, "create_conversation_for_connection");
    }
    if (selector == @selector(connection:handleRequest:))
    {
        return strongHost && cocoon::Signal<cocoon::Connection, bool(cocoon::DistantObjectRequest)>::connected((__bridge void*)strongHost, "handle_request");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    Connection::Connection(const Port& receive_port, const Port& send_port) : Connection(Adopt{cocoon::internal::retain([[::NSConnection alloc] initWithReceivePort:cocoon::internal::native<::NSPort>(receive_port) sendPort:cocoon::internal::native<::NSPort>(send_port)])})
    {
        Connection::install_delegate_delegate_(handle());
    }

    Connection::Connection() : Connection(Adopt{cocoon::internal::retain([[::NSConnection alloc] init])})
    {
        Connection::install_delegate_delegate_(handle());
    }

    Connection::Connection(std::nullptr_t) : Object(nullptr)
    {
    }

    Connection::Connection(Adopt adopt) : Object(adopt)
    {
    }

    void Connection::add_request_mode(const std::string& rmode) const
    {
        [cocoon::internal::ns<::NSConnection>(this) addRequestMode:cocoon::internal::to(rmode)];
    }

    void Connection::add_run_loop(const RunLoop& runloop) const
    {
        [cocoon::internal::ns<::NSConnection>(this) addRunLoop:cocoon::internal::native<::NSRunLoop>(runloop)];
    }

    std::vector<Connection> Connection::all_connections()
    {
        return cocoon::internal::from_array<Connection>([::NSConnection allConnections], [](id e) -> Connection
                                                        {
                                                            return cocoon::internal::wrap<Connection>((::NSConnection*)e);
                                                        });
    }

    Connection Connection::connection_with_receive_port(const Port& receive_port, const Port& send_port)
    {
        return cocoon::internal::wrap<Connection>([::NSConnection connectionWithReceivePort:cocoon::internal::native<::NSPort>(receive_port) sendPort:cocoon::internal::native<::NSPort>(send_port)]);
    }

    Connection Connection::connection_with_registered_name(const std::string& name, const std::string& host_name)
    {
        return cocoon::internal::wrap<Connection>([::NSConnection connectionWithRegisteredName:cocoon::internal::to(name) host:cocoon::internal::to(host_name)]);
    }

    Connection Connection::connection_with_registered_name(const std::string& name, const std::string& host_name, const PortNameServer& server)
    {
        return cocoon::internal::wrap<Connection>([::NSConnection connectionWithRegisteredName:cocoon::internal::to(name) host:cocoon::internal::to(host_name) usingNameServer:cocoon::internal::native<::NSPortNameServer>(server)]);
    }

    Object Connection::current_conversation()
    {
        return cocoon::internal::wrap<Object>([::NSConnection currentConversation]);
    }

    void Connection::dispatch_with_components(const std::vector<Object>& components) const
    {
        [cocoon::internal::ns<::NSConnection>(this) dispatchWithComponents:cocoon::internal::to_array(components, [](const Object& e) -> id
                                                                                                      {
                                                                                                          return cocoon::internal::native_id(e);
                                                                                                      })];
    }

    void Connection::enable_multiple_threads() const
    {
        [cocoon::internal::ns<::NSConnection>(this) enableMultipleThreads];
    }

    void Connection::invalidate() const
    {
        [cocoon::internal::ns<::NSConnection>(this) invalidate];
    }

    bool Connection::register_name(const std::string& name) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSConnection>(this) registerName:cocoon::internal::to(name)]);
    }

    bool Connection::register_name(const std::string& name, const PortNameServer& server) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSConnection>(this) registerName:cocoon::internal::to(name) withNameServer:cocoon::internal::native<::NSPortNameServer>(server)]);
    }

    void Connection::remove_request_mode(const std::string& rmode) const
    {
        [cocoon::internal::ns<::NSConnection>(this) removeRequestMode:cocoon::internal::to(rmode)];
    }

    void Connection::remove_run_loop(const RunLoop& runloop) const
    {
        [cocoon::internal::ns<::NSConnection>(this) removeRunLoop:cocoon::internal::native<::NSRunLoop>(runloop)];
    }

    void Connection::run_in_new_thread() const
    {
        [cocoon::internal::ns<::NSConnection>(this) runInNewThread];
    }

    Connection Connection::service_connection_with_name(const std::string& name, const Object& root)
    {
        return cocoon::internal::wrap<Connection>([::NSConnection serviceConnectionWithName:cocoon::internal::to(name) rootObject:cocoon::internal::native_id(root)]);
    }

    Connection Connection::service_connection_with_name(const std::string& name, const Object& root, const PortNameServer& server)
    {
        return cocoon::internal::wrap<Connection>([::NSConnection serviceConnectionWithName:cocoon::internal::to(name) rootObject:cocoon::internal::native_id(root) usingNameServer:cocoon::internal::native<::NSPortNameServer>(server)]);
    }

    bool Connection::independent_conversation_queueing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSConnection>(this) independentConversationQueueing]);
    }

    void Connection::set_independent_conversation_queueing(bool value) const
    {
        [cocoon::internal::ns<::NSConnection>(this) setIndependentConversationQueueing:static_cast<::BOOL>(value)];
    }

    std::vector<Object> Connection::local_objects() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSConnection>(this) localObjects], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    bool Connection::multiple_threads_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSConnection>(this) multipleThreadsEnabled]);
    }

    Port Connection::receive_port() const
    {
        return cocoon::internal::wrap<Port>([cocoon::internal::ns<::NSConnection>(this) receivePort]);
    }

    std::vector<Object> Connection::remote_objects() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSConnection>(this) remoteObjects], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    double Connection::reply_timeout() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSConnection>(this) replyTimeout]);
    }

    void Connection::set_reply_timeout(double value) const
    {
        [cocoon::internal::ns<::NSConnection>(this) setReplyTimeout:static_cast<::NSTimeInterval>(value)];
    }

    std::vector<std::string> Connection::request_modes() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSConnection>(this) requestModes], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    double Connection::request_timeout() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSConnection>(this) requestTimeout]);
    }

    void Connection::set_request_timeout(double value) const
    {
        [cocoon::internal::ns<::NSConnection>(this) setRequestTimeout:static_cast<::NSTimeInterval>(value)];
    }

    Object Connection::root_object() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSConnection>(this) rootObject]);
    }

    void Connection::set_root_object(const Object& value) const
    {
        [cocoon::internal::ns<::NSConnection>(this) setRootObject:cocoon::internal::native_id(value)];
    }

    Port Connection::send_port() const
    {
        return cocoon::internal::wrap<Port>([cocoon::internal::ns<::NSConnection>(this) sendPort]);
    }

    std::map<std::string, Number> Connection::statistics() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Number>>([cocoon::internal::ns<::NSConnection>(this) statistics], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Number
                                                                                {
                                                                                    return cocoon::internal::wrap<Number>((::NSNumber*)v);
                                                                                });
    }

    bool Connection::is_valid() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSConnection>(this) isValid]);
    }

    void Connection::install_delegate_delegate_(void* native)
    {
        ::NSConnection* host = (__bridge ::NSConnection*)native;
        AKConnectionDelegate* delegate = [[AKConnectionDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __unsafe_unretained::NSConnection* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSConnection* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
