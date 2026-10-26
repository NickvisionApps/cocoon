#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class HTTPCookieStorage;
    class URLCache;
    class URLCredentialStorage;

    /**
     * @brief C++ handle for the Objective-C class `NSURLSessionConfiguration` (Foundation).
     * @details Configuration options for an NSURLSession. When a session is created, a copy of the configuration object is made - you cannot modify the configuration of a session after it has been created. The shared session uses the global credential, cache and cookie storage objects. An ephemeral session has no persistent disk storage for cookies, cache or credentials. A background session can be used to perform networking operations on behalf of a suspended application, within certain constraints.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLSessionConfiguration url_session_configuration;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::URLSessionConfiguration url_session_configuration{};
     * url_session_configuration.set_http_cookie_accept_policy(cocoon::HTTPCookieAcceptPolicy::Always);
     * auto http_cookie_accept_policy = url_session_configuration.http_cookie_accept_policy();
     * url_session_configuration.set_http_cookie_storage(cocoon::HTTPCookieStorage());
     * auto http_cookie_storage = url_session_configuration.http_cookie_storage();
     * url_session_configuration.set_http_maximum_connections_per_host(1);
     * auto http_maximum_connections_per_host = url_session_configuration.http_maximum_connections_per_host();
     * auto made_0 = cocoon::URLSessionConfiguration::background_session_configuration_with_identifier("text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlsessionconfiguration
     */
    class URLSessionConfiguration : public Object
    {
    public:
        /// @brief Creates a new `NSURLSessionConfiguration` instance and returns a handle to it.
        explicit URLSessionConfiguration();
        /// @brief Creates a null handle that refers to no native object.
        URLSessionConfiguration(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLSessionConfiguration(Adopt adopt);
        /**
         * @brief Calls `+[NSURLSessionConfiguration backgroundSessionConfigurationWithIdentifier:]`.
         * @param identifier Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static URLSessionConfiguration background_session_configuration_with_identifier(const std::string& identifier);
        /**
         * @brief Returns the `HTTPAdditionalHeaders` property of `NSURLSessionConfiguration`.
         * @details Specifies additional headers which will be set on outgoing requests. Note that these headers are added to the request only if not already present.
         * @return The converted Objective-C result.
         */
        std::vector<std::pair<Object, Object>> http_additional_headers() const;
        /**
         * @brief Sets the `HTTPAdditionalHeaders` property of `NSURLSessionConfiguration`.
         * @details Specifies additional headers which will be set on outgoing requests. Note that these headers are added to the request only if not already present.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_http_additional_headers(const std::vector<std::pair<Object, Object>>& value) const;
        /**
         * @brief Returns the `HTTPCookieAcceptPolicy` property of `NSURLSessionConfiguration`.
         * @details Policy for accepting cookies. This overrides the policy otherwise specified by the cookie storage.
         * @return The converted Objective-C result.
         */
        HTTPCookieAcceptPolicy http_cookie_accept_policy() const;
        /**
         * @brief Sets the `HTTPCookieAcceptPolicy` property of `NSURLSessionConfiguration`.
         * @details Policy for accepting cookies. This overrides the policy otherwise specified by the cookie storage.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_http_cookie_accept_policy(HTTPCookieAcceptPolicy value) const;
        /**
         * @brief Returns the `HTTPCookieStorage` property of `NSURLSessionConfiguration`.
         * @details The cookie storage object to use, or nil to indicate that no cookies should be handled
         * @return The converted Objective-C result.
         */
        HTTPCookieStorage http_cookie_storage() const;
        /**
         * @brief Sets the `HTTPCookieStorage` property of `NSURLSessionConfiguration`.
         * @details The cookie storage object to use, or nil to indicate that no cookies should be handled
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_http_cookie_storage(const HTTPCookieStorage& value) const;
        /**
         * @brief Returns the `HTTPMaximumConnectionsPerHost` property of `NSURLSessionConfiguration`.
         * @details The maximum number of simultaneous persistent connections per host
         * @return The converted Objective-C result.
         */
        std::int64_t http_maximum_connections_per_host() const;
        /**
         * @brief Sets the `HTTPMaximumConnectionsPerHost` property of `NSURLSessionConfiguration`.
         * @details The maximum number of simultaneous persistent connections per host
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_http_maximum_connections_per_host(std::int64_t value) const;
        /**
         * @brief Returns the `HTTPShouldSetCookies` property of `NSURLSessionConfiguration`.
         * @details Allow the session to set cookies on requests
         * @return The converted Objective-C result.
         */
        bool http_should_set_cookies() const;
        /**
         * @brief Sets the `HTTPShouldSetCookies` property of `NSURLSessionConfiguration`.
         * @details Allow the session to set cookies on requests
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_http_should_set_cookies(bool value) const;
        /**
         * @brief Returns the `TLSMaximumSupportedProtocol` property of `NSURLSessionConfiguration`.
         * @details The maximum allowable versions of the TLS protocol, from \<Security/SecureTransport.h>
         * @return The converted Objective-C result.
         */
        SSLProtocol tls_maximum_supported_protocol() const;
        /**
         * @brief Sets the `TLSMaximumSupportedProtocol` property of `NSURLSessionConfiguration`.
         * @details The maximum allowable versions of the TLS protocol, from \<Security/SecureTransport.h>
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tls_maximum_supported_protocol(SSLProtocol value) const;
        /**
         * @brief Returns the `TLSMaximumSupportedProtocolVersion` property of `NSURLSessionConfiguration`.
         * @details The maximum allowable versions of the TLS protocol, from \<Security/SecProtocolTypes.h>
         * @return The converted Objective-C result.
         */
        tls_protocol_version_t tls_maximum_supported_protocol_version() const;
        /**
         * @brief Sets the `TLSMaximumSupportedProtocolVersion` property of `NSURLSessionConfiguration`.
         * @details The maximum allowable versions of the TLS protocol, from \<Security/SecProtocolTypes.h>
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tls_maximum_supported_protocol_version(tls_protocol_version_t value) const;
        /**
         * @brief Returns the `TLSMinimumSupportedProtocol` property of `NSURLSessionConfiguration`.
         * @details The minimum allowable versions of the TLS protocol, from \<Security/SecureTransport.h>
         * @return The converted Objective-C result.
         */
        SSLProtocol tls_minimum_supported_protocol() const;
        /**
         * @brief Sets the `TLSMinimumSupportedProtocol` property of `NSURLSessionConfiguration`.
         * @details The minimum allowable versions of the TLS protocol, from \<Security/SecureTransport.h>
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tls_minimum_supported_protocol(SSLProtocol value) const;
        /**
         * @brief Returns the `TLSMinimumSupportedProtocolVersion` property of `NSURLSessionConfiguration`.
         * @details The minimum allowable versions of the TLS protocol, from \<Security/SecProtocolTypes.h>
         * @return The converted Objective-C result.
         */
        tls_protocol_version_t tls_minimum_supported_protocol_version() const;
        /**
         * @brief Sets the `TLSMinimumSupportedProtocolVersion` property of `NSURLSessionConfiguration`.
         * @details The minimum allowable versions of the TLS protocol, from \<Security/SecProtocolTypes.h>
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tls_minimum_supported_protocol_version(tls_protocol_version_t value) const;
        /**
         * @brief Returns the `URLCache` property of `NSURLSessionConfiguration`.
         * @details The URL resource cache, or nil to indicate that no caching is to be performed
         * @return The converted Objective-C result.
         */
        URLCache url_cache() const;
        /**
         * @brief Sets the `URLCache` property of `NSURLSessionConfiguration`.
         * @details The URL resource cache, or nil to indicate that no caching is to be performed
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_url_cache(const URLCache& value) const;
        /**
         * @brief Returns the `URLCredentialStorage` property of `NSURLSessionConfiguration`.
         * @details The credential storage object, or nil to indicate that no credential storage is to be used
         * @return The converted Objective-C result.
         */
        URLCredentialStorage url_credential_storage() const;
        /**
         * @brief Sets the `URLCredentialStorage` property of `NSURLSessionConfiguration`.
         * @details The credential storage object, or nil to indicate that no credential storage is to be used
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_url_credential_storage(const URLCredentialStorage& value) const;
        /**
         * @brief Returns the `allowsCellularAccess` property of `NSURLSessionConfiguration`.
         * @details allow request to route over cellular.
         * @return The converted Objective-C result.
         */
        bool allows_cellular_access() const;
        /**
         * @brief Sets the `allowsCellularAccess` property of `NSURLSessionConfiguration`.
         * @details allow request to route over cellular.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_cellular_access(bool value) const;
        /**
         * @brief Returns the `allowsConstrainedNetworkAccess` property of `NSURLSessionConfiguration`.
         * @details allow request to route over networks in constrained mode. Defaults to YES.
         * @return The converted Objective-C result.
         */
        bool allows_constrained_network_access() const;
        /**
         * @brief Sets the `allowsConstrainedNetworkAccess` property of `NSURLSessionConfiguration`.
         * @details allow request to route over networks in constrained mode. Defaults to YES.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_constrained_network_access(bool value) const;
        /**
         * @brief Returns the `allowsExpensiveNetworkAccess` property of `NSURLSessionConfiguration`.
         * @details allow request to route over expensive networks. Defaults to YES.
         * @return The converted Objective-C result.
         */
        bool allows_expensive_network_access() const;
        /**
         * @brief Sets the `allowsExpensiveNetworkAccess` property of `NSURLSessionConfiguration`.
         * @details allow request to route over expensive networks. Defaults to YES.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_expensive_network_access(bool value) const;
        /**
         * @brief Returns the `allowsUltraConstrainedNetworkAccess` property of `NSURLSessionConfiguration`.
         * @details allow request to route over ultra constrained networks.
         * @return The converted Objective-C result.
         */
        bool allows_ultra_constrained_network_access() const;
        /**
         * @brief Sets the `allowsUltraConstrainedNetworkAccess` property of `NSURLSessionConfiguration`.
         * @details allow request to route over ultra constrained networks.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_ultra_constrained_network_access(bool value) const;
        /**
         * @brief Returns the `connectionProxyDictionary` property of `NSURLSessionConfiguration`.
         * @details The proxy dictionary, as described by \<CFNetwork/CFHTTPStream.h>
         * @return The converted Objective-C result.
         */
        std::vector<std::pair<Object, Object>> connection_proxy_dictionary() const;
        /**
         * @brief Sets the `connectionProxyDictionary` property of `NSURLSessionConfiguration`.
         * @details The proxy dictionary, as described by \<CFNetwork/CFHTTPStream.h>
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_connection_proxy_dictionary(const std::vector<std::pair<Object, Object>>& value) const;
        /**
         * @brief Returns the `defaultSessionConfiguration` property of `NSURLSessionConfiguration`.
         * @return The converted Objective-C result.
         */
        static URLSessionConfiguration default_session_configuration();
        /**
         * @brief Returns the `discretionary` property of `NSURLSessionConfiguration`.
         * @details allows background tasks to be scheduled at the discretion of the system for optimal performance.
         * @return The converted Objective-C result.
         */
        bool is_discretionary() const;
        /**
         * @brief Sets the `discretionary` property of `NSURLSessionConfiguration`.
         * @details allows background tasks to be scheduled at the discretion of the system for optimal performance.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_discretionary(bool value) const;
        /**
         * @brief Returns the `enablesEarlyData` property of `NSURLSessionConfiguration`.
         * @details Enables HTTP/3 0-RTT early data transmission of safe requests (GET or HEAD requests). WARNING: Inclusion in TLS early data changes the security guarantees offered by TLS. Requests sent in early data are not covered by anti-replay security protections. Early data must be idempotent and the impact of adversarial replays must be carefully evaluated, as the data may be replayed. Early data also does not provide full forward secrecy; data transmitted is more susceptible to data breach and security compromise of the server, even if the breach happens after the data was transmitted. See Section 8 of RFC8446 for more details. https://datatracker.ietf.org/doc/html/rfc8446\#section-8 See RFC8470 for additional discussion and security considerations. https://datatracker.ietf.org/doc/html/rfc8470 If these risks are acceptable for your use case, set this property to YES. If unsure, NO is the safest option. NOTE: Not supported in the classic loading mode. Defaults to NO.
         * @return The converted Objective-C result.
         */
        bool enables_early_data() const;
        /**
         * @brief Sets the `enablesEarlyData` property of `NSURLSessionConfiguration`.
         * @details Enables HTTP/3 0-RTT early data transmission of safe requests (GET or HEAD requests). WARNING: Inclusion in TLS early data changes the security guarantees offered by TLS. Requests sent in early data are not covered by anti-replay security protections. Early data must be idempotent and the impact of adversarial replays must be carefully evaluated, as the data may be replayed. Early data also does not provide full forward secrecy; data transmitted is more susceptible to data breach and security compromise of the server, even if the breach happens after the data was transmitted. See Section 8 of RFC8446 for more details. https://datatracker.ietf.org/doc/html/rfc8446\#section-8 See RFC8470 for additional discussion and security considerations. https://datatracker.ietf.org/doc/html/rfc8470 If these risks are acceptable for your use case, set this property to YES. If unsure, NO is the safest option. NOTE: Not supported in the classic loading mode. Defaults to NO.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_enables_early_data(bool value) const;
        /**
         * @brief Returns the `ephemeralSessionConfiguration` property of `NSURLSessionConfiguration`.
         * @return The converted Objective-C result.
         */
        static URLSessionConfiguration ephemeral_session_configuration();
        /**
         * @brief Returns the `identifier` property of `NSURLSessionConfiguration`.
         * @details identifier for the background session configuration
         * @return The converted Objective-C result.
         */
        std::string identifier() const;
        /**
         * @brief Returns the `networkServiceType` property of `NSURLSessionConfiguration`.
         * @details type of service for requests.
         * @return The converted Objective-C result.
         */
        URLRequestNetworkServiceType network_service_type() const;
        /**
         * @brief Sets the `networkServiceType` property of `NSURLSessionConfiguration`.
         * @details type of service for requests.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_network_service_type(URLRequestNetworkServiceType value) const;
        /**
         * @brief Returns the `protocolClasses` property of `NSURLSessionConfiguration`.
         * @details An optional array of Class objects which subclass NSURLProtocol. The Class will be sent +canInitWithRequest: when determining if an instance of the class can be used for a given URL scheme. You should not use +[NSURLProtocol registerClass:], as that method will register your class with the default session rather than with an instance of NSURLSession. Custom NSURLProtocol subclasses are not available to background sessions.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> protocol_classes() const;
        /**
         * @brief Sets the `protocolClasses` property of `NSURLSessionConfiguration`.
         * @details An optional array of Class objects which subclass NSURLProtocol. The Class will be sent +canInitWithRequest: when determining if an instance of the class can be used for a given URL scheme. You should not use +[NSURLProtocol registerClass:], as that method will register your class with the default session rather than with an instance of NSURLSession. Custom NSURLProtocol subclasses are not available to background sessions.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_protocol_classes(const std::vector<std::string>& value) const;
        /**
         * @brief Returns the `requestCachePolicy` property of `NSURLSessionConfiguration`.
         * @details default cache policy for requests
         * @return The converted Objective-C result.
         */
        URLRequestCachePolicy request_cache_policy() const;
        /**
         * @brief Sets the `requestCachePolicy` property of `NSURLSessionConfiguration`.
         * @details default cache policy for requests
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_request_cache_policy(URLRequestCachePolicy value) const;
        /**
         * @brief Returns the `requiresDNSSECValidation` property of `NSURLSessionConfiguration`.
         * @details requires requests from the session to be made with DNSSEC validation enabled. Defaults to NO.
         * @return The converted Objective-C result.
         */
        bool requires_dnssec_validation() const;
        /**
         * @brief Sets the `requiresDNSSECValidation` property of `NSURLSessionConfiguration`.
         * @details requires requests from the session to be made with DNSSEC validation enabled. Defaults to NO.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_requires_dnssec_validation(bool value) const;
        /**
         * @brief Returns the `sessionSendsLaunchEvents` property of `NSURLSessionConfiguration`.
         * @details Allows the app to be resumed or launched in the background when tasks in background sessions complete or when auth is required. This only applies to configurations created with +backgroundSessionConfigurationWithIdentifier: and the default value is YES. NOTE: macOS apps based on AppKit do not support background launch.
         * @return The converted Objective-C result.
         */
        bool session_sends_launch_events() const;
        /**
         * @brief Sets the `sessionSendsLaunchEvents` property of `NSURLSessionConfiguration`.
         * @details Allows the app to be resumed or launched in the background when tasks in background sessions complete or when auth is required. This only applies to configurations created with +backgroundSessionConfigurationWithIdentifier: and the default value is YES. NOTE: macOS apps based on AppKit do not support background launch.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_session_sends_launch_events(bool value) const;
        /**
         * @brief Returns the `sharedContainerIdentifier` property of `NSURLSessionConfiguration`.
         * @details The identifier of the shared data container into which files in background sessions should be downloaded. App extensions wishing to use background sessions must set this property to a valid container identifier, or all transfers in that session will fail with NSURLErrorBackgroundSessionRequiresSharedContainer.
         * @return The converted Objective-C result.
         */
        std::string shared_container_identifier() const;
        /**
         * @brief Sets the `sharedContainerIdentifier` property of `NSURLSessionConfiguration`.
         * @details The identifier of the shared data container into which files in background sessions should be downloaded. App extensions wishing to use background sessions must set this property to a valid container identifier, or all transfers in that session will fail with NSURLErrorBackgroundSessionRequiresSharedContainer.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_shared_container_identifier(const std::string& value) const;
        /**
         * @brief Returns the `timeoutIntervalForRequest` property of `NSURLSessionConfiguration`.
         * @details default timeout for requests. This will cause a timeout if no data is transmitted for the given timeout value, and is reset whenever data is transmitted.
         * @return The converted Objective-C result.
         */
        double timeout_interval_for_request() const;
        /**
         * @brief Sets the `timeoutIntervalForRequest` property of `NSURLSessionConfiguration`.
         * @details default timeout for requests. This will cause a timeout if no data is transmitted for the given timeout value, and is reset whenever data is transmitted.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_timeout_interval_for_request(double value) const;
        /**
         * @brief Returns the `timeoutIntervalForResource` property of `NSURLSessionConfiguration`.
         * @details default timeout for requests. This will cause a timeout if a resource is not able to be retrieved within a given timeout.
         * @return The converted Objective-C result.
         */
        double timeout_interval_for_resource() const;
        /**
         * @brief Sets the `timeoutIntervalForResource` property of `NSURLSessionConfiguration`.
         * @details default timeout for requests. This will cause a timeout if a resource is not able to be retrieved within a given timeout.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_timeout_interval_for_resource(double value) const;
        /**
         * @brief Returns the `usesClassicLoadingMode` property of `NSURLSessionConfiguration`.
         * @details Uses the classic network loader. NOTE: FTP and HTTP/1 pipelining are only supported in the classic loading mode. Defaults to YES. The default may be NO in a future OS update.
         * @return The converted Objective-C result.
         */
        bool uses_classic_loading_mode() const;
        /**
         * @brief Sets the `usesClassicLoadingMode` property of `NSURLSessionConfiguration`.
         * @details Uses the classic network loader. NOTE: FTP and HTTP/1 pipelining are only supported in the classic loading mode. Defaults to YES. The default may be NO in a future OS update.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_uses_classic_loading_mode(bool value) const;
        /**
         * @brief Returns the `waitsForConnectivity` property of `NSURLSessionConfiguration`.
         * @details Causes tasks to wait for network connectivity to become available, rather than immediately failing with an error (such as NSURLErrorNotConnectedToInternet) when it is not. When waiting for connectivity, the timeoutIntervalForRequest property does not apply, but the timeoutIntervalForResource property does. Unsatisfactory connectivity (that requires waiting) includes cases where the device has limited or insufficient connectivity for a task (e.g., only has a cellular connection but the allowsCellularAccess property is NO, or requires a VPN connection in order to reach the desired host). Default value is NO. Ignored by background sessions, as background sessions always wait for connectivity.
         * @return The converted Objective-C result.
         */
        bool waits_for_connectivity() const;
        /**
         * @brief Sets the `waitsForConnectivity` property of `NSURLSessionConfiguration`.
         * @details Causes tasks to wait for network connectivity to become available, rather than immediately failing with an error (such as NSURLErrorNotConnectedToInternet) when it is not. When waiting for connectivity, the timeoutIntervalForRequest property does not apply, but the timeoutIntervalForResource property does. Unsatisfactory connectivity (that requires waiting) includes cases where the device has limited or insufficient connectivity for a task (e.g., only has a cellular connection but the allowsCellularAccess property is NO, or requires a VPN connection in order to reach the desired host). Default value is NO. Ignored by background sessions, as background sessions always wait for connectivity.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_waits_for_connectivity(bool value) const;
    };
}
