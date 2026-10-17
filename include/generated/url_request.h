#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class InputStream;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSURLRequest` (Foundation).
     * @details A URL load request that is independent of protocol or URL scheme. Use this type in Swift when you need reference semantics or other Foundation-specific behavior. ''NSURLRequest'' encapsulates two essential properties of a load request: the URL to load and the policies used to load it. In addition, for HTTP and HTTPS requests, ''URLRequest'' includes the HTTP method ('GET', 'POST', and so on) and the HTTP headers. Finally, custom protocols can support custom properties as explained in \<doc:\#Custom-protocol-properties>. ''NSURLRequest'' only represents information about the request. Use other classes, such as ''URLSession'', to send the request to a server. See \<doc:fetching-website-data-into-memory> and \<doc:uploading-data-to-a-website> for an introduction to these techniques. The mutable subclass of ''NSURLRequest'' is ''NSMutableURLRequest''. > Important: > The Swift overlay to the Foundation framework provides the ''URLRequest'' structure, which bridges to the ''NSURLRequest'' class and its mutable subclass, ''NSMutableURLRequest''. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>. \#\#\# Reserved HTTP headers The URL Loading System handles various aspects of the HTTP protocol for you (HTTP 1.1 persistent connections, proxies, authentication, and so on). As part of this support, the URL Loading System takes responsibility for certain HTTP headers: - 'Content-Length' - 'Authorization' - 'Connection' - 'Host' - 'Proxy-Authenticate' - 'Proxy-Authorization' - 'WWW-Authenticate' If you set a value for one of these reserved headers, the system may ignore the value you set, or overwrite it with its own value, or simply not send it. Moreover, the exact behavior may change over time. To avoid confusing problems like this, do not set these headers directly. The URL Loading System sets the 'Content-Length' header based on whether the request body has a known length: - If so, it uses the identity transfer encoding and sets the 'Content-Length' header to that known length. You see this when you set the request body to a data object. - If not, it uses the chunked transfer encoding and omits the 'Content-Length' header. You see this when you set the request body to a stream. \#\#\# Custom protocol properties If you implement a custom URL protocol by subclassing ''URLProtocol'', and it needs protocol-specific properties, extend ''NSURLRequest'' with accessor methods for those custom properties. In your accessor methods, call ''URLProtocol/property(forKey:in:)'' and ''URLProtocol/setProperty(:forKey:in:)'' to associate property values with the request.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLRequest url_request;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::URLRequest url_request{};
     * auto made_0 = cocoon::URLRequest::request_with_url(cocoon::URL());
     * auto made_1 = cocoon::URLRequest::request_with_url(cocoon::URL(), cocoon::URLRequestCachePolicy::UseProtocolCachePolicy, 1);
     * url_request.value_for_http_header_field("text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlrequest
     */
    class URLRequest : public Object
    {
    public:
        /// @brief Creates a new `NSURLRequest` instance and returns a handle to it.
        explicit URLRequest(const URL& url);
        /// @brief Creates a new `NSURLRequest` instance and returns a handle to it.
        explicit URLRequest(const URL& url, URLRequestCachePolicy cache_policy, double timeout_interval);
        /// @brief Creates a new `NSURLRequest` instance and returns a handle to it.
        explicit URLRequest();
        /// @brief Creates a null handle that refers to no native object.
        URLRequest(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLRequest(Adopt adopt);
        /**
     * @brief Calls `+[NSURLRequest requestWithURL:]`.
     * @details Allocates and initializes an 'NSURLRequest' with the given URL. Default values are used for cache policy ('NSURLRequestUseProtocolCachePolicy') and timeout interval (60 seconds). - Parameter URL: The URL for the request. - Returns: A newly-created and autoreleased 'NSURLRequest' instance.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URLRequest request_with_url(const URL& url);
        /**
     * @brief Calls `+[NSURLRequest requestWithURL:cachePolicy:timeoutInterval:]`.
     * @details Allocates and initializes an 'NSURLRequest' with the given URL and cache policy. - Parameters: - URL: The URL for the request. - cachePolicy: The cache policy for the request. - timeoutInterval: The timeout interval for the request, in seconds. - Returns: A newly-created and autoreleased 'NSURLRequest' instance.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param cache_policy Argument converted to the Objective-C parameter of the same role.
     * @param timeout_interval Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URLRequest request_with_url(const URL& url, URLRequestCachePolicy cache_policy, double timeout_interval);
        /**
     * @brief Calls `-[NSURLRequest valueForHTTPHeaderField:]`.
     * @details Returns the value which corresponds to the given header field. In keeping with the HTTP RFC, HTTP header field names are case-insensitive. - Parameter field: The header field name to use for the lookup (case-insensitive). - Returns: The value associated with the given header field, or 'nil' if there is no value associated with the given header field.
     * @param field Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string value_for_http_header_field(const std::string& field) const;
        /**
     * @brief Returns the `HTTPBody` property of `NSURLRequest`.
     * @details The request body data of the receiver. This data is sent as the message body of the request, as in done in an HTTP POST request.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> http_body() const;
        /**
     * @brief Returns the `HTTPBodyStream` property of `NSURLRequest`.
     * @details The request body stream of the receiver, if any. The stream is returned for examination only; it is not safe for the caller to manipulate the stream in any way. Note that the 'HTTPBodyStream' and 'HTTPBody' are mutually exclusive - only one can be set on a given request. Also note that the body stream is preserved across copies, but is lost when the request is coded via the 'NSCoding' protocol.
     * @return The converted Objective-C result.
     */
        InputStream http_body_stream() const;
        /**
     * @brief Returns the `HTTPMethod` property of `NSURLRequest`.
     * @details The HTTP request method of the receiver.
     * @return The converted Objective-C result.
     */
        std::string http_method() const;
        /**
     * @brief Returns the `HTTPShouldHandleCookies` property of `NSURLRequest`.
     * @details A Boolean value that indicates whether the default cookie handling will happen for this request.
     * @return The converted Objective-C result.
     */
        bool http_should_handle_cookies() const;
        /**
     * @brief Returns the `URL` property of `NSURLRequest`.
     * @details The URL of the receiver.
     * @return The converted Objective-C result.
     */
        URL url() const;
        /**
     * @brief Returns the `allHTTPHeaderFields` property of `NSURLRequest`.
     * @details A dictionary containing all the HTTP header fields of the receiver.
     * @return The converted Objective-C result.
     */
        std::map<std::string, std::string> all_http_header_fields() const;
        /**
     * @brief Returns the `allowsCellularAccess` property of `NSURLRequest`.
     * @details A Boolean value that indicates whether a connection created with this request is allowed to use the built-in cellular radios (if present).
     * @return The converted Objective-C result.
     */
        bool allows_cellular_access() const;
        /**
     * @brief Returns the `allowsConstrainedNetworkAccess` property of `NSURLRequest`.
     * @details A Boolean value that indicates whether a connection created with this request is allowed to use network interfaces which have been marked as constrained.
     * @return The converted Objective-C result.
     */
        bool allows_constrained_network_access() const;
        /**
     * @brief Returns the `allowsExpensiveNetworkAccess` property of `NSURLRequest`.
     * @details A Boolean value that indicates whether a connection created with this request is allowed to use network interfaces which have been marked as expensive.
     * @return The converted Objective-C result.
     */
        bool allows_expensive_network_access() const;
        /**
     * @brief Returns the `allowsPersistentDNS` property of `NSURLRequest`.
     * @details A Boolean value that indicates whether storing and usage of DNS answers in a persistent per-process cache is allowed. This should only be set for hostnames whose resolutions are not expected to change across networks. Defaults to 'NO'.
     * @return The converted Objective-C result.
     */
        bool allows_persistent_dns() const;
        /**
     * @brief Returns the `allowsUltraConstrainedNetworkAccess` property of `NSURLRequest`.
     * @details A Boolean value that indicates whether a connection created with this request is allowed to use network interfaces which have been marked as ultra constrained.
     * @return The converted Objective-C result.
     */
        bool allows_ultra_constrained_network_access() const;
        /**
     * @brief Returns the `assumesHTTP3Capable` property of `NSURLRequest`.
     * @details A Boolean value that indicates whether the server is assumed to support HTTP/3. When 'YES', enables QUIC racing without HTTP/3 service discovery. Defaults to 'NO'. The default may be 'YES' in a future OS update.
     * @return The converted Objective-C result.
     */
        bool assumes_http3_capable() const;
        /**
     * @brief Returns the `attribution` property of `NSURLRequest`.
     * @details The 'NSURLRequestAttribution' associated with this request. Returns 'NSURLRequestAttributionDeveloper' for requests that have not explicitly set an attribution.
     * @return The converted Objective-C result.
     */
        URLRequestAttribution attribution() const;
        /**
     * @brief Returns the `cachePolicy` property of `NSURLRequest`.
     * @details The cache policy of the receiver.
     * @return The converted Objective-C result.
     */
        URLRequestCachePolicy cache_policy() const;
        /**
     * @brief Returns the `cookiePartitionIdentifier` property of `NSURLRequest`.
     * @details Cookie partition identifier used for cookie storage and retrieval.
     * @return The converted Objective-C result.
     */
        std::string cookie_partition_identifier() const;
        /**
     * @brief Returns the `mainDocumentURL` property of `NSURLRequest`.
     * @details The main document URL associated with this load. This URL is used for the cookie "same domain as main document" policy, and attributing the request as a sub-resource of a user-specified URL. There may also be other future uses.
     * @return The converted Objective-C result.
     */
        URL main_document_url() const;
        /**
     * @brief Returns the `networkServiceType` property of `NSURLRequest`.
     * @details The 'NSURLRequestNetworkServiceType' associated with this request. Returns 'NSURLNetworkServiceTypeDefault' for requests that have not explicitly set a network service type.
     * @return The converted Objective-C result.
     */
        URLRequestNetworkServiceType network_service_type() const;
        /**
     * @brief Returns the `requiresDNSSECValidation` property of `NSURLRequest`.
     * @details A Boolean value that indicates whether a request requires DNSSEC validation during DNS lookup. 'YES' if the DNS lookup for this request should require DNSSEC validation. Defaults to 'NO'.
     * @return The converted Objective-C result.
     */
        bool requires_dnssec_validation() const;
        /**
     * @brief Returns the `supportsSecureCoding` property of `NSURLRequest`.
     * @details Indicates that 'NSURLRequest' implements the 'NSSecureCoding' protocol.
     * @return The converted Objective-C result.
     */
        static bool supports_secure_coding();
        /**
     * @brief Returns the `timeoutInterval` property of `NSURLRequest`.
     * @details The timeout interval of the receiver, measured in seconds. The timeout interval specifies the limit on the idle interval allotted to a request in the process of loading. The "idle interval" is defined as the period of time that has passed since the last instance of load activity occurred for a request that is in the process of loading. Hence, when an instance of load activity occurs (e.g. bytes are received from the network for a request), the idle interval for a request is reset to 0. If the idle interval ever becomes greater than or equal to the timeout interval, the request is considered to have timed out.
     * @return The converted Objective-C result.
     */
        double timeout_interval() const;
    };
}
