#pragma once

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
     * @details A configuration object that defines behavior and policies for a URL session. An ''URLSessionConfiguration'' object defines the behavior and policies to use when uploading and downloading data using an ''URLSession'' object. When uploading or downloading data, creating a configuration object is always the first step you must take. You use this object to configure the timeout values, caching policies, connection requirements, and other types of information that you intend to use with your ''URLSession'' object. It is important to configure your ''URLSessionConfiguration'' object appropriately before using it to initialize a session object. Session objects make a copy of the configuration settings you provide and use those settings to configure the session. Once configured, the session object ignores any changes you make to the ''URLSessionConfiguration'' object. If you need to modify your transfer policies, you must update the session configuration object and use it to create a new ''URLSession'' object. > Note: > In some cases, the policies defined in this configuration may be overridden by policies specified by an ''NSURLRequest'' object provided for a task. Any policy specified on the request object is respected unless the session's policy is more restrictive. For example, if the session configuration specifies that cellular networking should not be allowed, the ''NSURLRequest'' object cannot request cellular networking. For more information about using configuration objects to create sessions, see ''URLSession''. \#\#\# Types of session configurations The behavior and capabilities of a URL session are largely determined by the kind of configuration used to create the session. The singleton shared session (which has no configuration object) is for basic requests. It's not as customizable as sessions that you create, but it serves as a good starting point if you have very limited requirements. You access this session by calling the shared class method. See that method's discussion for more information about its limitations. Default sessions behave much like the shared session (unless you customize them further), but let you obtain data incrementally using a delegate. You can create a default session configuration by calling the default method on the URLSessionConfiguration class. Ephemeral sessions are similar to default sessions, but they don't write caches, cookies, or credentials to disk. You can create an ephemeral session configuration by calling the ephemeral method on the URLSessionConfiguration class. Background sessions let you perform uploads and downloads of content in the background while your app isn't running. You can create a background session configuration by calling the backgroundSessionConfiguration(\\:) method on the URLSessionConfiguration class.
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
     * @details Creates a session configuration object that allows HTTP and HTTPS uploads or downloads to be performed in the background. Use this method to initialize a configuration object suitable for transferring data files while the app runs in the background. A session configured with this object hands control of the transfers over to the system, which handles the transfers in a separate process. In iOS, this configuration makes it possible for transfers to continue even when the app itself is suspended or terminated. If an iOS app is terminated by the system and relaunched, the app can use the same 'identifier' to create a new configuration object and session and to retrieve the status of transfers that were in progress at the time of termination. This behavior applies only for normal termination of the app by the system. If the user terminates the app from the multitasking screen, the system cancels all of the session's background transfers. - Parameter identifier: The unique identifier for the configuration object. This parameter must not be 'nil' or an empty string. - Returns: A configuration object that causes the system to perform upload and download tasks in a separate process.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URLSessionConfiguration background_session_configuration_with_identifier(const std::string& identifier);
        /**
     * @brief Returns the `HTTPAdditionalHeaders` property of `NSURLSessionConfiguration`.
     * @details A dictionary of additional headers to send with requests. This property specifies additional headers that are added to all tasks within sessions based on this configuration. If the same header appears in both this dictionary and the request object (where applicable), the request object's value takes precedence. An 'NSURLSession' object is designed to handle various aspects of the HTTP protocol for you. As a result, you should not modify the following headers: 'Authorization', 'Connection', 'Host', 'Proxy-Authenticate', 'Proxy-Authorization', 'WWW-Authenticate'.
     * @return The converted Objective-C result.
     */
        std::vector<std::pair<Object, Object>> http_additional_headers() const;
        /**
     * @brief Sets the `HTTPAdditionalHeaders` property of `NSURLSessionConfiguration`.
     * @details A dictionary of additional headers to send with requests. This property specifies additional headers that are added to all tasks within sessions based on this configuration. If the same header appears in both this dictionary and the request object (where applicable), the request object's value takes precedence. An 'NSURLSession' object is designed to handle various aspects of the HTTP protocol for you. As a result, you should not modify the following headers: 'Authorization', 'Connection', 'Host', 'Proxy-Authenticate', 'Proxy-Authorization', 'WWW-Authenticate'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_http_additional_headers(const std::vector<std::pair<Object, Object>>& value) const;
        /**
     * @brief Returns the `HTTPCookieAcceptPolicy` property of `NSURLSessionConfiguration`.
     * @details A policy constant that determines when cookies should be accepted. This property determines the cookie accept policy for all tasks within sessions based on this configuration.
     * @return The converted Objective-C result.
     */
        HTTPCookieAcceptPolicy http_cookie_accept_policy() const;
        /**
     * @brief Sets the `HTTPCookieAcceptPolicy` property of `NSURLSessionConfiguration`.
     * @details A policy constant that determines when cookies should be accepted. This property determines the cookie accept policy for all tasks within sessions based on this configuration.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_http_cookie_accept_policy(HTTPCookieAcceptPolicy value) const;
        /**
     * @brief Returns the `HTTPCookieStorage` property of `NSURLSessionConfiguration`.
     * @details The cookie store for storing cookies within this session. To disable cookie storage, set this property to 'nil'. For default and background sessions, the default value is the shared cookie storage object. For ephemeral sessions, the default value is a private cookie storage object that stores data in memory only, and is destroyed when you invalidate the session.
     * @return The converted Objective-C result.
     */
        HTTPCookieStorage http_cookie_storage() const;
        /**
     * @brief Sets the `HTTPCookieStorage` property of `NSURLSessionConfiguration`.
     * @details The cookie store for storing cookies within this session. To disable cookie storage, set this property to 'nil'. For default and background sessions, the default value is the shared cookie storage object. For ephemeral sessions, the default value is a private cookie storage object that stores data in memory only, and is destroyed when you invalidate the session.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_http_cookie_storage(const HTTPCookieStorage& value) const;
        /**
     * @brief Returns the `HTTPMaximumConnectionsPerHost` property of `NSURLSessionConfiguration`.
     * @details The maximum number of simultaneous connections to make to a given host. This limit is per session, so if you use multiple sessions, your app as a whole may exceed this limit. The default value is '6'.
     * @return The converted Objective-C result.
     */
        std::int64_t http_maximum_connections_per_host() const;
        /**
     * @brief Sets the `HTTPMaximumConnectionsPerHost` property of `NSURLSessionConfiguration`.
     * @details The maximum number of simultaneous connections to make to a given host. This limit is per session, so if you use multiple sessions, your app as a whole may exceed this limit. The default value is '6'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_http_maximum_connections_per_host(std::int64_t value) const;
        /**
     * @brief Returns the `HTTPShouldSetCookies` property of `NSURLSessionConfiguration`.
     * @details A Boolean value that determines whether requests should contain cookies from the cookie store. The default value is 'YES'.
     * @return The converted Objective-C result.
     */
        bool http_should_set_cookies() const;
        /**
     * @brief Sets the `HTTPShouldSetCookies` property of `NSURLSessionConfiguration`.
     * @details A Boolean value that determines whether requests should contain cookies from the cookie store. The default value is 'YES'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_http_should_set_cookies(bool value) const;
        /**
     * @brief Returns the `TLSMaximumSupportedProtocol` property of `NSURLSessionConfiguration`.
     * @details The maximum TLS protocol version that the client should request when making connections in this session.
     * @return The converted Objective-C result.
     */
        SSLProtocol tls_maximum_supported_protocol() const;
        /**
     * @brief Sets the `TLSMaximumSupportedProtocol` property of `NSURLSessionConfiguration`.
     * @details The maximum TLS protocol version that the client should request when making connections in this session.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tls_maximum_supported_protocol(SSLProtocol value) const;
        /**
     * @brief Returns the `TLSMaximumSupportedProtocolVersion` property of `NSURLSessionConfiguration`.
     * @details The maximum TLS protocol version that the client should request when making connections in this session.
     * @return The converted Objective-C result.
     */
        tls_protocol_version_t tls_maximum_supported_protocol_version() const;
        /**
     * @brief Sets the `TLSMaximumSupportedProtocolVersion` property of `NSURLSessionConfiguration`.
     * @details The maximum TLS protocol version that the client should request when making connections in this session.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tls_maximum_supported_protocol_version(tls_protocol_version_t value) const;
        /**
     * @brief Returns the `TLSMinimumSupportedProtocol` property of `NSURLSessionConfiguration`.
     * @details The minimum TLS protocol to accept during protocol negotiation.
     * @return The converted Objective-C result.
     */
        SSLProtocol tls_minimum_supported_protocol() const;
        /**
     * @brief Sets the `TLSMinimumSupportedProtocol` property of `NSURLSessionConfiguration`.
     * @details The minimum TLS protocol to accept during protocol negotiation.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tls_minimum_supported_protocol(SSLProtocol value) const;
        /**
     * @brief Returns the `TLSMinimumSupportedProtocolVersion` property of `NSURLSessionConfiguration`.
     * @details The minimum TLS protocol version that the client should accept when making connections in this session.
     * @return The converted Objective-C result.
     */
        tls_protocol_version_t tls_minimum_supported_protocol_version() const;
        /**
     * @brief Sets the `TLSMinimumSupportedProtocolVersion` property of `NSURLSessionConfiguration`.
     * @details The minimum TLS protocol version that the client should accept when making connections in this session.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tls_minimum_supported_protocol_version(tls_protocol_version_t value) const;
        /**
     * @brief Returns the `URLCache` property of `NSURLSessionConfiguration`.
     * @details The URL cache for providing cached responses to requests within the session. To disable caching, set this property to 'nil'. For default sessions, the default value is the shared URL cache object. For background sessions, the default value is 'nil'. For ephemeral sessions, the default value is a private cache object that stores data in memory only, and is destroyed when you invalidate the session.
     * @return The converted Objective-C result.
     */
        URLCache url_cache() const;
        /**
     * @brief Sets the `URLCache` property of `NSURLSessionConfiguration`.
     * @details The URL cache for providing cached responses to requests within the session. To disable caching, set this property to 'nil'. For default sessions, the default value is the shared URL cache object. For background sessions, the default value is 'nil'. For ephemeral sessions, the default value is a private cache object that stores data in memory only, and is destroyed when you invalidate the session.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_url_cache(const URLCache& value) const;
        /**
     * @brief Returns the `URLCredentialStorage` property of `NSURLSessionConfiguration`.
     * @details A credential store that provides credentials for authentication. To not use a credential store, set this property to 'nil'. For default and background sessions, the default value is the shared credential storage object. For ephemeral sessions, the default value is a private credential store object that stores data in memory only, and is destroyed when you invalidate the session.
     * @return The converted Objective-C result.
     */
        URLCredentialStorage url_credential_storage() const;
        /**
     * @brief Sets the `URLCredentialStorage` property of `NSURLSessionConfiguration`.
     * @details A credential store that provides credentials for authentication. To not use a credential store, set this property to 'nil'. For default and background sessions, the default value is the shared credential storage object. For ephemeral sessions, the default value is a private credential store object that stores data in memory only, and is destroyed when you invalidate the session.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_url_credential_storage(const URLCredentialStorage& value) const;
        /**
     * @brief Returns the `allowsCellularAccess` property of `NSURLSessionConfiguration`.
     * @details A Boolean value that determines whether connections should be made over a cellular network. This property controls whether tasks in sessions based on this session configuration are allowed to make connections over a cellular network. The default value is 'YES'.
     * @return The converted Objective-C result.
     */
        bool allows_cellular_access() const;
        /**
     * @brief Sets the `allowsCellularAccess` property of `NSURLSessionConfiguration`.
     * @details A Boolean value that determines whether connections should be made over a cellular network. This property controls whether tasks in sessions based on this session configuration are allowed to make connections over a cellular network. The default value is 'YES'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_cellular_access(bool value) const;
        /**
     * @brief Returns the `allowsConstrainedNetworkAccess` property of `NSURLSessionConfiguration`.
     * @details A Boolean value that indicates whether connections may use the network when the user has specified Low Data Mode. The default value is 'YES'.
     * @return The converted Objective-C result.
     */
        bool allows_constrained_network_access() const;
        /**
     * @brief Sets the `allowsConstrainedNetworkAccess` property of `NSURLSessionConfiguration`.
     * @details A Boolean value that indicates whether connections may use the network when the user has specified Low Data Mode. The default value is 'YES'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_constrained_network_access(bool value) const;
        /**
     * @brief Returns the `allowsExpensiveNetworkAccess` property of `NSURLSessionConfiguration`.
     * @details A Boolean value that indicates whether connections may use a network interface that the system considers expensive. The default value is 'YES'.
     * @return The converted Objective-C result.
     */
        bool allows_expensive_network_access() const;
        /**
     * @brief Sets the `allowsExpensiveNetworkAccess` property of `NSURLSessionConfiguration`.
     * @details A Boolean value that indicates whether connections may use a network interface that the system considers expensive. The default value is 'YES'.
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
     * @details A dictionary containing information about the proxy to use within this session. Prefer using 'proxyConfigurations', which supports secure proxy and relay types. The default value is 'NULL', which means that tasks use the default system settings.
     * @return The converted Objective-C result.
     */
        std::vector<std::pair<Object, Object>> connection_proxy_dictionary() const;
        /**
     * @brief Sets the `connectionProxyDictionary` property of `NSURLSessionConfiguration`.
     * @details A dictionary containing information about the proxy to use within this session. Prefer using 'proxyConfigurations', which supports secure proxy and relay types. The default value is 'NULL', which means that tasks use the default system settings.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_connection_proxy_dictionary(const std::vector<std::pair<Object, Object>>& value) const;
        /**
     * @brief Returns the `defaultSessionConfiguration` property of `NSURLSessionConfiguration`.
     * @details A default session configuration object. The default session configuration uses a persistent disk-based cache (except when the result is downloaded to a file) and stores credentials in the user's keychain. It also stores cookies (by default) in the same shared cookie store as 'NSURLConnection' and 'NSURLDownload'. Modifying the returned session configuration object does not affect any configuration objects returned by future calls to this method, and does not change the default behavior for existing sessions. It is therefore always safe to use the returned object as a starting point for additional customization.
     * @return The converted Objective-C result.
     */
        static URLSessionConfiguration default_session_configuration();
        /**
     * @brief Returns the `discretionary` property of `NSURLSessionConfiguration`.
     * @details A Boolean value that determines whether background tasks can be scheduled at the discretion of the system for optimal performance. For configuration objects created using '+backgroundSessionConfigurationWithIdentifier:', use this property to give the system control over when transfers should occur. This property is ignored for configuration objects created using other methods. When transferring large amounts of data, you are encouraged to set this to 'YES'. Doing so lets the system schedule those transfers at times that are more optimal for the device. The default value is 'NO'.
     * @return The converted Objective-C result.
     */
        bool is_discretionary() const;
        /**
     * @brief Sets the `discretionary` property of `NSURLSessionConfiguration`.
     * @details A Boolean value that determines whether background tasks can be scheduled at the discretion of the system for optimal performance. For configuration objects created using '+backgroundSessionConfigurationWithIdentifier:', use this property to give the system control over when transfers should occur. This property is ignored for configuration objects created using other methods. When transferring large amounts of data, you are encouraged to set this to 'YES'. Doing so lets the system schedule those transfers at times that are more optimal for the device. The default value is 'NO'.
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
     * @details A session configuration that uses no persistent storage for caches, cookies, or credentials. An ephemeral session configuration object is similar to a default session configuration (see 'defaultSessionConfiguration'), except that the corresponding session object doesn't store caches, credential stores, or any session-related data to disk. Instead, session-related data is stored in RAM. The only time an ephemeral session writes data to disk is when you tell it to write the contents of a URL to a file. The main advantage to using ephemeral sessions is privacy. By not writing potentially sensitive data to disk, you make it less likely that the data will be intercepted and used later. For this reason, ephemeral sessions are ideal for private browsing modes in web browsers and other similar situations. When your app invalidates the session, all ephemeral session data is purged automatically. Additionally, in iOS, the in-memory cache isn't purged automatically when your app is suspended but may be purged when your app is terminated or when the system experiences memory pressure.
     * @return The converted Objective-C result.
     */
        static URLSessionConfiguration ephemeral_session_configuration();
        /**
     * @brief Returns the `identifier` property of `NSURLSessionConfiguration`.
     * @details The background session identifier of the configuration object. The value of this property is set only when you use '+backgroundSessionConfigurationWithIdentifier:' to create the configuration object. The string uniquely identifies a background session object. In iOS, you use this string in cases where the app was terminated while transfers were occurring in the background. When the app relaunches, it uses the string to recreate the configuration and session objects associated with the transfers.
     * @return The converted Objective-C result.
     */
        std::string identifier() const;
        /**
     * @brief Returns the `networkServiceType` property of `NSURLSessionConfiguration`.
     * @details The type of network service for all tasks within network sessions to enable Cellular Network Slicing.
     * @return The converted Objective-C result.
     */
        URLRequestNetworkServiceType network_service_type() const;
        /**
     * @brief Sets the `networkServiceType` property of `NSURLSessionConfiguration`.
     * @details The type of network service for all tasks within network sessions to enable Cellular Network Slicing.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_network_service_type(URLRequestNetworkServiceType value) const;
        /**
     * @brief Returns the `protocolClasses` property of `NSURLSessionConfiguration`.
     * @details An array of extra protocol subclasses that handle requests in a session. Use this array to extend the default set of common networking protocols available for use by a session with one or more custom protocols that you define. You should not use '+[NSURLProtocol registerClass:]', as that method will register your class with the default session rather than with an instance of 'NSURLSession'. > Note: You cannot use custom 'NSURLProtocol' subclasses in conjunction with background > sessions.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> protocol_classes() const;
        /**
     * @brief Sets the `protocolClasses` property of `NSURLSessionConfiguration`.
     * @details An array of extra protocol subclasses that handle requests in a session. Use this array to extend the default set of common networking protocols available for use by a session with one or more custom protocols that you define. You should not use '+[NSURLProtocol registerClass:]', as that method will register your class with the default session rather than with an instance of 'NSURLSession'. > Note: You cannot use custom 'NSURLProtocol' subclasses in conjunction with background > sessions.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_protocol_classes(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `requestCachePolicy` property of `NSURLSessionConfiguration`.
     * @details A predefined constant that determines when to return a response from the cache. This property determines the request caching policy used by tasks within sessions based on this configuration. The default value is 'NSURLRequestUseProtocolCachePolicy'.
     * @return The converted Objective-C result.
     */
        URLRequestCachePolicy request_cache_policy() const;
        /**
     * @brief Sets the `requestCachePolicy` property of `NSURLSessionConfiguration`.
     * @details A predefined constant that determines when to return a response from the cache. This property determines the request caching policy used by tasks within sessions based on this configuration. The default value is 'NSURLRequestUseProtocolCachePolicy'.
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
     * @details A Boolean value that indicates whether the app should be resumed or launched in the background when transfers finish. For configuration objects created using '+backgroundSessionConfigurationWithIdentifier:', you can use this property to control the launching behavior for an iOS app. This property is ignored for configuration objects created using other methods. The default value is 'YES'. When 'YES', the system automatically wakes up or launches the iOS app in the background when the session's tasks finish or require authentication. > Note: macOS apps based on AppKit do not support background launch.
     * @return The converted Objective-C result.
     */
        bool session_sends_launch_events() const;
        /**
     * @brief Sets the `sessionSendsLaunchEvents` property of `NSURLSessionConfiguration`.
     * @details A Boolean value that indicates whether the app should be resumed or launched in the background when transfers finish. For configuration objects created using '+backgroundSessionConfigurationWithIdentifier:', you can use this property to control the launching behavior for an iOS app. This property is ignored for configuration objects created using other methods. The default value is 'YES'. When 'YES', the system automatically wakes up or launches the iOS app in the background when the session's tasks finish or require authentication. > Note: macOS apps based on AppKit do not support background launch.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_session_sends_launch_events(bool value) const;
        /**
     * @brief Returns the `sharedContainerIdentifier` property of `NSURLSessionConfiguration`.
     * @details The identifier for the shared container into which files in background URL sessions should be downloaded. To create a URL session for use by an app extension, set this property to a valid identifier for a container shared between the app extension and its containing app. > Important: If you try to create a URL session from your app extension but fail to set > this property to a valid value, the URL session is invalidated upon creation.
     * @return The converted Objective-C result.
     */
        std::string shared_container_identifier() const;
        /**
     * @brief Sets the `sharedContainerIdentifier` property of `NSURLSessionConfiguration`.
     * @details The identifier for the shared container into which files in background URL sessions should be downloaded. To create a URL session for use by an app extension, set this property to a valid identifier for a container shared between the app extension and its containing app. > Important: If you try to create a URL session from your app extension but fail to set > this property to a valid value, the URL session is invalidated upon creation.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shared_container_identifier(const std::string& value) const;
        /**
     * @brief Returns the `timeoutIntervalForRequest` property of `NSURLSessionConfiguration`.
     * @details The timeout interval to use when waiting for additional data. This property determines the request timeout interval for all tasks within sessions based on this configuration. The request timeout interval controls how long (in seconds) a task should wait for additional data to arrive before giving up. The timer associated with this value is reset whenever new data arrives. When the request timer reaches the specified interval without receiving any new data, it triggers a timeout. The default value is '60'. > Important: Any upload or download tasks created by a background session are automatically > retried if the original request fails due to a timeout. To configure how long an upload > or download task should be allowed to be retried or transferred, use the > 'timeoutIntervalForResource' property.
     * @return The converted Objective-C result.
     */
        double timeout_interval_for_request() const;
        /**
     * @brief Sets the `timeoutIntervalForRequest` property of `NSURLSessionConfiguration`.
     * @details The timeout interval to use when waiting for additional data. This property determines the request timeout interval for all tasks within sessions based on this configuration. The request timeout interval controls how long (in seconds) a task should wait for additional data to arrive before giving up. The timer associated with this value is reset whenever new data arrives. When the request timer reaches the specified interval without receiving any new data, it triggers a timeout. The default value is '60'. > Important: Any upload or download tasks created by a background session are automatically > retried if the original request fails due to a timeout. To configure how long an upload > or download task should be allowed to be retried or transferred, use the > 'timeoutIntervalForResource' property.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_timeout_interval_for_request(double value) const;
        /**
     * @brief Returns the `timeoutIntervalForResource` property of `NSURLSessionConfiguration`.
     * @details The maximum amount of time that a resource request should be allowed to take. This property determines the resource timeout interval for all tasks within sessions based on this configuration. The resource timeout interval controls how long (in seconds) to wait for an entire resource to transfer before giving up. The resource timer starts when the request is initiated and counts until either the request completes or this timeout interval is reached, whichever comes first. The default value is 7 days.
     * @return The converted Objective-C result.
     */
        double timeout_interval_for_resource() const;
        /**
     * @brief Sets the `timeoutIntervalForResource` property of `NSURLSessionConfiguration`.
     * @details The maximum amount of time that a resource request should be allowed to take. This property determines the resource timeout interval for all tasks within sessions based on this configuration. The resource timeout interval controls how long (in seconds) to wait for an entire resource to transfer before giving up. The resource timer starts when the request is initiated and counts until either the request completes or this timeout interval is reached, whichever comes first. The default value is 7 days.
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
     * @details A Boolean value that indicates whether the session should wait for connectivity to become available, or fail immediately. Connectivity might be temporarily unavailable for several reasons. For example, a device might only have a cellular connection when 'allowsCellularAccess' is set to 'NO', or the device might require a VPN connection but none is available. If the value of this property is 'YES' and sufficient connectivity is unavailable, the session calls the 'URLSession:taskIsWaitingForConnectivity:' delegate method and waits for connectivity. If the value is 'NO' and connectivity is unavailable, the connection fails immediately with an error. Default value is 'NO'. Ignored by background sessions, as background sessions always wait for connectivity.
     * @return The converted Objective-C result.
     */
        bool waits_for_connectivity() const;
        /**
     * @brief Sets the `waitsForConnectivity` property of `NSURLSessionConfiguration`.
     * @details A Boolean value that indicates whether the session should wait for connectivity to become available, or fail immediately. Connectivity might be temporarily unavailable for several reasons. For example, a device might only have a cellular connection when 'allowsCellularAccess' is set to 'NO', or the device might require a VPN connection but none is available. If the value of this property is 'YES' and sufficient connectivity is unavailable, the session calls the 'URLSession:taskIsWaitingForConnectivity:' delegate method and waits for connectivity. If the value is 'NO' and connectivity is unavailable, the connection fails immediately with an error. Default value is 'NO'. Ignored by background sessions, as background sessions always wait for connectivity.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_waits_for_connectivity(bool value) const;
    };
}
