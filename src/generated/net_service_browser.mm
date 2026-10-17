#include "generated/net_service_browser.h"
#include "internal.h"

@interface AKNetServiceBrowserDelegate : NSObject <NSNetServiceBrowserDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKNetServiceBrowserDelegate

- (void)netServiceBrowserWillSearch:(NSNetServiceBrowser*)browser
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::NetServiceBrowser, void()>::emit((__bridge void*)strongHost, "will_search");
}

- (void)netServiceBrowserDidStopSearch:(NSNetServiceBrowser*)browser
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::NetServiceBrowser, void()>::emit((__bridge void*)strongHost, "did_stop_search");
}

- (void)netServiceBrowser:(NSNetServiceBrowser*)browser didNotSearch:(NSDictionary<NSString*, NSNumber*>*)errorDict
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::NetServiceBrowser, void(std::map<std::string, cocoon::Number>)>::emit((__bridge void*)strongHost, "did_not_search", cocoon::internal::from_dictionary<std::map<std::string, cocoon::Number>>(errorDict, [](id k) -> std::string
                                                                                                                                                                                                                        {
                                                                                                                                                                                                                            return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                        },
                                                                                                                                                                                                                        [](id v) -> cocoon::Number
                                                                                                                                                                                                                        {
                                                                                                                                                                                                                            return cocoon::internal::wrap<cocoon::Number>((::NSNumber*)v);
                                                                                                                                                                                                                        }));
}

- (void)netServiceBrowser:(NSNetServiceBrowser*)browser didFindDomain:(NSString*)domainString moreComing:(BOOL)moreComing
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::NetServiceBrowser, void(std::string, bool)>::emit((__bridge void*)strongHost, "did_find_domain_more_coming", cocoon::internal::from(domainString), static_cast<bool>(moreComing));
}

- (void)netServiceBrowser:(NSNetServiceBrowser*)browser didFindService:(NSNetService*)service moreComing:(BOOL)moreComing
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::NetServiceBrowser, void(cocoon::NetService, bool)>::emit((__bridge void*)strongHost, "did_find_service_more_coming", cocoon::internal::wrap<cocoon::NetService>(service), static_cast<bool>(moreComing));
}

- (void)netServiceBrowser:(NSNetServiceBrowser*)browser didRemoveDomain:(NSString*)domainString moreComing:(BOOL)moreComing
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::NetServiceBrowser, void(std::string, bool)>::emit((__bridge void*)strongHost, "did_remove_domain_more_coming", cocoon::internal::from(domainString), static_cast<bool>(moreComing));
}

- (void)netServiceBrowser:(NSNetServiceBrowser*)browser didRemoveService:(NSNetService*)service moreComing:(BOOL)moreComing
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::NetServiceBrowser, void(cocoon::NetService, bool)>::emit((__bridge void*)strongHost, "did_remove_service_more_coming", cocoon::internal::wrap<cocoon::NetService>(service), static_cast<bool>(moreComing));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(netServiceBrowserWillSearch:))
    {
        return strongHost && cocoon::Signal<cocoon::NetServiceBrowser, void()>::connected((__bridge void*)strongHost, "will_search");
    }
    if (selector == @selector(netServiceBrowserDidStopSearch:))
    {
        return strongHost && cocoon::Signal<cocoon::NetServiceBrowser, void()>::connected((__bridge void*)strongHost, "did_stop_search");
    }
    if (selector == @selector(netServiceBrowser:didNotSearch:))
    {
        return strongHost && cocoon::Signal<cocoon::NetServiceBrowser, void(std::map<std::string, cocoon::Number>)>::connected((__bridge void*)strongHost, "did_not_search");
    }
    if (selector == @selector(netServiceBrowser:didFindDomain:moreComing:))
    {
        return strongHost && cocoon::Signal<cocoon::NetServiceBrowser, void(std::string, bool)>::connected((__bridge void*)strongHost, "did_find_domain_more_coming");
    }
    if (selector == @selector(netServiceBrowser:didFindService:moreComing:))
    {
        return strongHost && cocoon::Signal<cocoon::NetServiceBrowser, void(cocoon::NetService, bool)>::connected((__bridge void*)strongHost, "did_find_service_more_coming");
    }
    if (selector == @selector(netServiceBrowser:didRemoveDomain:moreComing:))
    {
        return strongHost && cocoon::Signal<cocoon::NetServiceBrowser, void(std::string, bool)>::connected((__bridge void*)strongHost, "did_remove_domain_more_coming");
    }
    if (selector == @selector(netServiceBrowser:didRemoveService:moreComing:))
    {
        return strongHost && cocoon::Signal<cocoon::NetServiceBrowser, void(cocoon::NetService, bool)>::connected((__bridge void*)strongHost, "did_remove_service_more_coming");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    NetServiceBrowser::NetServiceBrowser() : NetServiceBrowser(Adopt{cocoon::internal::retain([[::NSNetServiceBrowser alloc] init])})
    {
        NetServiceBrowser::install_delegate_delegate_(handle());
    }

    NetServiceBrowser::NetServiceBrowser(std::nullptr_t) : Object(nullptr)
    {
    }

    NetServiceBrowser::NetServiceBrowser(Adopt adopt) : Object(adopt)
    {
    }

    void NetServiceBrowser::remove_from_run_loop(const RunLoop& a_run_loop, const std::string& mode) const
    {
        [cocoon::internal::ns<::NSNetServiceBrowser>(this) removeFromRunLoop:cocoon::internal::native<::NSRunLoop>(a_run_loop) forMode:cocoon::internal::to(mode)];
    }

    void NetServiceBrowser::schedule_in_run_loop(const RunLoop& a_run_loop, const std::string& mode) const
    {
        [cocoon::internal::ns<::NSNetServiceBrowser>(this) scheduleInRunLoop:cocoon::internal::native<::NSRunLoop>(a_run_loop) forMode:cocoon::internal::to(mode)];
    }

    void NetServiceBrowser::search_for_browsable_domains() const
    {
        [cocoon::internal::ns<::NSNetServiceBrowser>(this) searchForBrowsableDomains];
    }

    void NetServiceBrowser::search_for_registration_domains() const
    {
        [cocoon::internal::ns<::NSNetServiceBrowser>(this) searchForRegistrationDomains];
    }

    void NetServiceBrowser::search_for_services_of_type(const std::string& type, const std::string& domain_string) const
    {
        [cocoon::internal::ns<::NSNetServiceBrowser>(this) searchForServicesOfType:cocoon::internal::to(type) inDomain:cocoon::internal::to(domain_string)];
    }

    void NetServiceBrowser::stop() const
    {
        [cocoon::internal::ns<::NSNetServiceBrowser>(this) stop];
    }

    bool NetServiceBrowser::includes_peer_to_peer() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSNetServiceBrowser>(this) includesPeerToPeer]);
    }

    void NetServiceBrowser::set_includes_peer_to_peer(bool value) const
    {
        [cocoon::internal::ns<::NSNetServiceBrowser>(this) setIncludesPeerToPeer:static_cast<::BOOL>(value)];
    }

    void NetServiceBrowser::install_delegate_delegate_(void* native)
    {
        ::NSNetServiceBrowser* host = (__bridge ::NSNetServiceBrowser*)native;
        AKNetServiceBrowserDelegate* delegate = [[AKNetServiceBrowserDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSNetServiceBrowser* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSNetServiceBrowser* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
