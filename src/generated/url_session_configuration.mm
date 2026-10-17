#include "generated/url_session_configuration.h"
#include "internal.h"

namespace cocoon
{
    URLSessionConfiguration::URLSessionConfiguration() : URLSessionConfiguration(Adopt{cocoon::internal::retain([[::NSURLSessionConfiguration alloc] init])})
    {
    }

    URLSessionConfiguration::URLSessionConfiguration(std::nullptr_t) : Object(nullptr)
    {
    }

    URLSessionConfiguration::URLSessionConfiguration(Adopt adopt) : Object(adopt)
    {
    }

    URLSessionConfiguration URLSessionConfiguration::background_session_configuration_with_identifier(const std::string& identifier)
    {
        return cocoon::internal::wrap<URLSessionConfiguration>([::NSURLSessionConfiguration backgroundSessionConfigurationWithIdentifier:cocoon::internal::to(identifier)]);
    }

    std::vector<std::pair<Object, Object>> URLSessionConfiguration::http_additional_headers() const
    {
        return cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) HTTPAdditionalHeaders], [](id k) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(k);
                                                                                         },
                                                                                         [](id v) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(v);
                                                                                         });
    }

    void URLSessionConfiguration::set_http_additional_headers(const std::vector<std::pair<Object, Object>>& value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setHTTPAdditionalHeaders:cocoon::internal::to_dictionary(value, [](const Object& k) -> id
                                                                                                                          {
                                                                                                                              return cocoon::internal::native_id(k);
                                                                                                                          },
                                                                                                                          [](const Object& v) -> id
                                                                                                                          {
                                                                                                                              return cocoon::internal::native_id(v);
                                                                                                                          })];
    }

    HTTPCookieAcceptPolicy URLSessionConfiguration::http_cookie_accept_policy() const
    {
        return static_cast<HTTPCookieAcceptPolicy>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) HTTPCookieAcceptPolicy]);
    }

    void URLSessionConfiguration::set_http_cookie_accept_policy(HTTPCookieAcceptPolicy value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setHTTPCookieAcceptPolicy:static_cast<::NSHTTPCookieAcceptPolicy>(value)];
    }

    HTTPCookieStorage URLSessionConfiguration::http_cookie_storage() const
    {
        return cocoon::internal::wrap<HTTPCookieStorage>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) HTTPCookieStorage]);
    }

    void URLSessionConfiguration::set_http_cookie_storage(const HTTPCookieStorage& value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setHTTPCookieStorage:cocoon::internal::native<::NSHTTPCookieStorage>(value)];
    }

    std::int64_t URLSessionConfiguration::http_maximum_connections_per_host() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) HTTPMaximumConnectionsPerHost]);
    }

    void URLSessionConfiguration::set_http_maximum_connections_per_host(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setHTTPMaximumConnectionsPerHost:static_cast<::NSInteger>(value)];
    }

    bool URLSessionConfiguration::http_should_set_cookies() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) HTTPShouldSetCookies]);
    }

    void URLSessionConfiguration::set_http_should_set_cookies(bool value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setHTTPShouldSetCookies:static_cast<::BOOL>(value)];
    }

    SSLProtocol URLSessionConfiguration::tls_maximum_supported_protocol() const
    {
        return static_cast<SSLProtocol>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) TLSMaximumSupportedProtocol]);
    }

    void URLSessionConfiguration::set_tls_maximum_supported_protocol(SSLProtocol value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setTLSMaximumSupportedProtocol:static_cast<::SSLProtocol>(value)];
    }

    tls_protocol_version_t URLSessionConfiguration::tls_maximum_supported_protocol_version() const
    {
        return static_cast<tls_protocol_version_t>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) TLSMaximumSupportedProtocolVersion]);
    }

    void URLSessionConfiguration::set_tls_maximum_supported_protocol_version(tls_protocol_version_t value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setTLSMaximumSupportedProtocolVersion:static_cast<::tls_protocol_version_t>(value)];
    }

    SSLProtocol URLSessionConfiguration::tls_minimum_supported_protocol() const
    {
        return static_cast<SSLProtocol>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) TLSMinimumSupportedProtocol]);
    }

    void URLSessionConfiguration::set_tls_minimum_supported_protocol(SSLProtocol value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setTLSMinimumSupportedProtocol:static_cast<::SSLProtocol>(value)];
    }

    tls_protocol_version_t URLSessionConfiguration::tls_minimum_supported_protocol_version() const
    {
        return static_cast<tls_protocol_version_t>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) TLSMinimumSupportedProtocolVersion]);
    }

    void URLSessionConfiguration::set_tls_minimum_supported_protocol_version(tls_protocol_version_t value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setTLSMinimumSupportedProtocolVersion:static_cast<::tls_protocol_version_t>(value)];
    }

    URLCache URLSessionConfiguration::url_cache() const
    {
        return cocoon::internal::wrap<URLCache>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) URLCache]);
    }

    void URLSessionConfiguration::set_url_cache(const URLCache& value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setURLCache:cocoon::internal::native<::NSURLCache>(value)];
    }

    URLCredentialStorage URLSessionConfiguration::url_credential_storage() const
    {
        return cocoon::internal::wrap<URLCredentialStorage>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) URLCredentialStorage]);
    }

    void URLSessionConfiguration::set_url_credential_storage(const URLCredentialStorage& value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setURLCredentialStorage:cocoon::internal::native<::NSURLCredentialStorage>(value)];
    }

    bool URLSessionConfiguration::allows_cellular_access() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) allowsCellularAccess]);
    }

    void URLSessionConfiguration::set_allows_cellular_access(bool value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setAllowsCellularAccess:static_cast<::BOOL>(value)];
    }

    bool URLSessionConfiguration::allows_constrained_network_access() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) allowsConstrainedNetworkAccess]);
    }

    void URLSessionConfiguration::set_allows_constrained_network_access(bool value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setAllowsConstrainedNetworkAccess:static_cast<::BOOL>(value)];
    }

    bool URLSessionConfiguration::allows_expensive_network_access() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) allowsExpensiveNetworkAccess]);
    }

    void URLSessionConfiguration::set_allows_expensive_network_access(bool value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setAllowsExpensiveNetworkAccess:static_cast<::BOOL>(value)];
    }

    bool URLSessionConfiguration::allows_ultra_constrained_network_access() const
    {
        if (@available(macOS 26.1, *))
        {
            return static_cast<bool>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) allowsUltraConstrainedNetworkAccess]);
        }
        return {};
    }

    void URLSessionConfiguration::set_allows_ultra_constrained_network_access(bool value) const
    {
        if (@available(macOS 26.1, *))
        {
            [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setAllowsUltraConstrainedNetworkAccess:static_cast<::BOOL>(value)];
        }
    }

    std::vector<std::pair<Object, Object>> URLSessionConfiguration::connection_proxy_dictionary() const
    {
        return cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) connectionProxyDictionary], [](id k) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(k);
                                                                                         },
                                                                                         [](id v) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(v);
                                                                                         });
    }

    void URLSessionConfiguration::set_connection_proxy_dictionary(const std::vector<std::pair<Object, Object>>& value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setConnectionProxyDictionary:cocoon::internal::to_dictionary(value, [](const Object& k) -> id
                                                                                                                              {
                                                                                                                                  return cocoon::internal::native_id(k);
                                                                                                                              },
                                                                                                                              [](const Object& v) -> id
                                                                                                                              {
                                                                                                                                  return cocoon::internal::native_id(v);
                                                                                                                              })];
    }

    URLSessionConfiguration URLSessionConfiguration::default_session_configuration()
    {
        return cocoon::internal::wrap<URLSessionConfiguration>([::NSURLSessionConfiguration defaultSessionConfiguration]);
    }

    bool URLSessionConfiguration::is_discretionary() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) isDiscretionary]);
    }

    void URLSessionConfiguration::set_discretionary(bool value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setDiscretionary:static_cast<::BOOL>(value)];
    }

    bool URLSessionConfiguration::enables_early_data() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) enablesEarlyData]);
    }

    void URLSessionConfiguration::set_enables_early_data(bool value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setEnablesEarlyData:static_cast<::BOOL>(value)];
    }

    URLSessionConfiguration URLSessionConfiguration::ephemeral_session_configuration()
    {
        return cocoon::internal::wrap<URLSessionConfiguration>([::NSURLSessionConfiguration ephemeralSessionConfiguration]);
    }

    std::string URLSessionConfiguration::identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLSessionConfiguration>(this) identifier]);
    }

    URLRequestNetworkServiceType URLSessionConfiguration::network_service_type() const
    {
        return static_cast<URLRequestNetworkServiceType>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) networkServiceType]);
    }

    void URLSessionConfiguration::set_network_service_type(URLRequestNetworkServiceType value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setNetworkServiceType:static_cast<::NSURLRequestNetworkServiceType>(value)];
    }

    std::vector<std::string> URLSessionConfiguration::protocol_classes() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) protocolClasses], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from(NSStringFromClass(e));
                                                         });
    }

    void URLSessionConfiguration::set_protocol_classes(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setProtocolClasses:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                               {
                                                                                                                   return NSClassFromString(cocoon::internal::to(e));
                                                                                                               })];
    }

    URLRequestCachePolicy URLSessionConfiguration::request_cache_policy() const
    {
        return static_cast<URLRequestCachePolicy>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) requestCachePolicy]);
    }

    void URLSessionConfiguration::set_request_cache_policy(URLRequestCachePolicy value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setRequestCachePolicy:static_cast<::NSURLRequestCachePolicy>(value)];
    }

    bool URLSessionConfiguration::requires_dnssec_validation() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) requiresDNSSECValidation]);
    }

    void URLSessionConfiguration::set_requires_dnssec_validation(bool value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setRequiresDNSSECValidation:static_cast<::BOOL>(value)];
    }

    bool URLSessionConfiguration::session_sends_launch_events() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) sessionSendsLaunchEvents]);
    }

    void URLSessionConfiguration::set_session_sends_launch_events(bool value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setSessionSendsLaunchEvents:static_cast<::BOOL>(value)];
    }

    std::string URLSessionConfiguration::shared_container_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLSessionConfiguration>(this) sharedContainerIdentifier]);
    }

    void URLSessionConfiguration::set_shared_container_identifier(const std::string& value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setSharedContainerIdentifier:cocoon::internal::to(value)];
    }

    double URLSessionConfiguration::timeout_interval_for_request() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) timeoutIntervalForRequest]);
    }

    void URLSessionConfiguration::set_timeout_interval_for_request(double value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setTimeoutIntervalForRequest:static_cast<::NSTimeInterval>(value)];
    }

    double URLSessionConfiguration::timeout_interval_for_resource() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) timeoutIntervalForResource]);
    }

    void URLSessionConfiguration::set_timeout_interval_for_resource(double value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setTimeoutIntervalForResource:static_cast<::NSTimeInterval>(value)];
    }

    bool URLSessionConfiguration::uses_classic_loading_mode() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) usesClassicLoadingMode]);
    }

    void URLSessionConfiguration::set_uses_classic_loading_mode(bool value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setUsesClassicLoadingMode:static_cast<::BOOL>(value)];
    }

    bool URLSessionConfiguration::waits_for_connectivity() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLSessionConfiguration>(this) waitsForConnectivity]);
    }

    void URLSessionConfiguration::set_waits_for_connectivity(bool value) const
    {
        [cocoon::internal::ns<::NSURLSessionConfiguration>(this) setWaitsForConnectivity:static_cast<::BOOL>(value)];
    }
}
