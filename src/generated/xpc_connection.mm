#include "generated/xpc_connection.h"
#include "internal.h"

namespace cocoon
{
    XPCConnection::XPCConnection(const XPCListenerEndpoint& endpoint) : XPCConnection(Adopt{cocoon::internal::retain([[::NSXPCConnection alloc] initWithListenerEndpoint:cocoon::internal::native<::NSXPCListenerEndpoint>(endpoint)])})
    {
    }

    XPCConnection::XPCConnection(const std::string& name, XPCConnectionOptions options) : XPCConnection(Adopt{cocoon::internal::retain([[::NSXPCConnection alloc] initWithMachServiceName:cocoon::internal::to(name) options:static_cast<::NSXPCConnectionOptions>(options)])})
    {
    }

    XPCConnection::XPCConnection(const std::string& service_name) : XPCConnection(Adopt{cocoon::internal::retain([[::NSXPCConnection alloc] initWithServiceName:cocoon::internal::to(service_name)])})
    {
    }

    XPCConnection::XPCConnection() : XPCConnection(Adopt{cocoon::internal::retain([[::NSXPCConnection alloc] init])})
    {
    }

    XPCConnection::XPCConnection(std::nullptr_t) : Object(nullptr)
    {
    }

    XPCConnection::XPCConnection(Adopt adopt) : Object(adopt)
    {
    }

    void XPCConnection::activate() const
    {
        [cocoon::internal::ns<::NSXPCConnection>(this) activate];
    }

    XPCConnection XPCConnection::current_connection()
    {
        return cocoon::internal::wrap<XPCConnection>([::NSXPCConnection currentConnection]);
    }

    void XPCConnection::invalidate() const
    {
        [cocoon::internal::ns<::NSXPCConnection>(this) invalidate];
    }

    Object XPCConnection::remote_object_proxy_with_error_handler(std::function<void(Error)> handler) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSXPCConnection>(this) remoteObjectProxyWithErrorHandler:(handler ? (void (^)(::NSError*)) ^ void(::NSError * a259_0) { handler(cocoon::internal::wrap<Error>(a259_0)); } : (void (^)(::NSError*))nil)]);
    }

    void XPCConnection::resume() const
    {
        [cocoon::internal::ns<::NSXPCConnection>(this) resume];
    }

    void XPCConnection::schedule_send_barrier_block(std::function<void()> block) const
    {
        [cocoon::internal::ns<::NSXPCConnection>(this) scheduleSendBarrierBlock:(block ? (void (^)(void)) ^ void() { block(); } : (void (^)(void))nil)];
    }

    void XPCConnection::set_code_signing_requirement(const std::string& requirement) const
    {
        [cocoon::internal::ns<::NSXPCConnection>(this) setCodeSigningRequirement:cocoon::internal::to(requirement)];
    }

    void XPCConnection::suspend() const
    {
        [cocoon::internal::ns<::NSXPCConnection>(this) suspend];
    }

    Object XPCConnection::synchronous_remote_object_proxy_with_error_handler(std::function<void(Error)> handler) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSXPCConnection>(this) synchronousRemoteObjectProxyWithErrorHandler:(handler ? (void (^)(::NSError*)) ^ void(::NSError * a261_0) { handler(cocoon::internal::wrap<Error>(a261_0)); } : (void (^)(::NSError*))nil)]);
    }

    int XPCConnection::audit_session_identifier() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSXPCConnection>(this) auditSessionIdentifier]);
    }

    unsigned int XPCConnection::effective_group_identifier() const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSXPCConnection>(this) effectiveGroupIdentifier]);
    }

    unsigned int XPCConnection::effective_user_identifier() const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSXPCConnection>(this) effectiveUserIdentifier]);
    }

    XPCListenerEndpoint XPCConnection::endpoint() const
    {
        return cocoon::internal::wrap<XPCListenerEndpoint>([cocoon::internal::ns<::NSXPCConnection>(this) endpoint]);
    }

    XPCInterface XPCConnection::exported_interface() const
    {
        return cocoon::internal::wrap<XPCInterface>([cocoon::internal::ns<::NSXPCConnection>(this) exportedInterface]);
    }

    void XPCConnection::set_exported_interface(const XPCInterface& value) const
    {
        [cocoon::internal::ns<::NSXPCConnection>(this) setExportedInterface:cocoon::internal::native<::NSXPCInterface>(value)];
    }

    Object XPCConnection::exported_object() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSXPCConnection>(this) exportedObject]);
    }

    void XPCConnection::set_exported_object(const Object& value) const
    {
        [cocoon::internal::ns<::NSXPCConnection>(this) setExportedObject:cocoon::internal::native_id(value)];
    }

    std::function<void()> XPCConnection::interruption_handler() const
    {
        return [&]() -> std::function<void()>
        {
            auto blk = (void (^)(void))([cocoon::internal::ns<::NSXPCConnection>(this) interruptionHandler]);
            if (!blk)
            {
                return {};
            }
            return [blk]() -> void
            {
                blk();
            };
        }();
    }

    void XPCConnection::set_interruption_handler(std::function<void()> value) const
    {
        [cocoon::internal::ns<::NSXPCConnection>(this) setInterruptionHandler:(value ? (void (^)(void)) ^ void() { value(); } : (void (^)(void))nil)];
    }

    std::function<void()> XPCConnection::invalidation_handler() const
    {
        return [&]() -> std::function<void()>
        {
            auto blk = (void (^)(void))([cocoon::internal::ns<::NSXPCConnection>(this) invalidationHandler]);
            if (!blk)
            {
                return {};
            }
            return [blk]() -> void
            {
                blk();
            };
        }();
    }

    void XPCConnection::set_invalidation_handler(std::function<void()> value) const
    {
        [cocoon::internal::ns<::NSXPCConnection>(this) setInvalidationHandler:(value ? (void (^)(void)) ^ void() { value(); } : (void (^)(void))nil)];
    }

    int XPCConnection::process_identifier() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSXPCConnection>(this) processIdentifier]);
    }

    XPCInterface XPCConnection::remote_object_interface() const
    {
        return cocoon::internal::wrap<XPCInterface>([cocoon::internal::ns<::NSXPCConnection>(this) remoteObjectInterface]);
    }

    void XPCConnection::set_remote_object_interface(const XPCInterface& value) const
    {
        [cocoon::internal::ns<::NSXPCConnection>(this) setRemoteObjectInterface:cocoon::internal::native<::NSXPCInterface>(value)];
    }

    Object XPCConnection::remote_object_proxy() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSXPCConnection>(this) remoteObjectProxy]);
    }

    std::string XPCConnection::service_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXPCConnection>(this) serviceName]);
    }
}
