#include "generated/xpc_listener.h"
#include "internal.h"

@interface AKXPCListenerDelegate : NSObject <NSXPCListenerDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKXPCListenerDelegate

- (BOOL)listener:(NSXPCListener*)listener shouldAcceptNewConnection:(NSXPCConnection*)newConnection
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::XPCListener, bool(cocoon::XPCConnection)>::emit((__bridge void*)strongHost, "listener_should_accept_new_connection", cocoon::internal::wrap<cocoon::XPCConnection>(newConnection));
    return static_cast<::BOOL>(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(listener:shouldAcceptNewConnection:))
    {
        return strongHost && cocoon::Signal<cocoon::XPCListener, bool(cocoon::XPCConnection)>::connected((__bridge void*)strongHost, "listener_should_accept_new_connection");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    XPCListener::XPCListener(const std::string& name) : XPCListener(Adopt{cocoon::internal::retain([[::NSXPCListener alloc] initWithMachServiceName:cocoon::internal::to(name)])})
    {
        XPCListener::install_delegate_delegate_(handle());
    }

    XPCListener::XPCListener() : XPCListener(Adopt{cocoon::internal::retain([[::NSXPCListener alloc] init])})
    {
        XPCListener::install_delegate_delegate_(handle());
    }

    XPCListener::XPCListener(std::nullptr_t) : Object(nullptr)
    {
    }

    XPCListener::XPCListener(Adopt adopt) : Object(adopt)
    {
    }

    void XPCListener::activate() const
    {
        [cocoon::internal::ns<::NSXPCListener>(this) activate];
    }

    XPCListener XPCListener::anonymous_listener()
    {
        return cocoon::internal::wrap<XPCListener>([::NSXPCListener anonymousListener]);
    }

    void XPCListener::invalidate() const
    {
        [cocoon::internal::ns<::NSXPCListener>(this) invalidate];
    }

    void XPCListener::resume() const
    {
        [cocoon::internal::ns<::NSXPCListener>(this) resume];
    }

    XPCListener XPCListener::service_listener()
    {
        return cocoon::internal::wrap<XPCListener>([::NSXPCListener serviceListener]);
    }

    void XPCListener::set_connection_code_signing_requirement(const std::string& requirement) const
    {
        [cocoon::internal::ns<::NSXPCListener>(this) setConnectionCodeSigningRequirement:cocoon::internal::to(requirement)];
    }

    void XPCListener::suspend() const
    {
        [cocoon::internal::ns<::NSXPCListener>(this) suspend];
    }

    XPCListenerEndpoint XPCListener::endpoint() const
    {
        return cocoon::internal::wrap<XPCListenerEndpoint>([cocoon::internal::ns<::NSXPCListener>(this) endpoint]);
    }

    void XPCListener::install_delegate_delegate_(void* native)
    {
        ::NSXPCListener* host = (__bridge ::NSXPCListener*)native;
        AKXPCListenerDelegate* delegate = [[AKXPCListenerDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSXPCListener* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSXPCListener* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
