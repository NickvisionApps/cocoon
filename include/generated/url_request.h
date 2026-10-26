#pragma once

#include "generated/availability.h"
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
     * @details \@class NSURLRequest \@abstract An NSURLRequest object represents a URL load request in a manner independent of protocol and URL scheme. \@discussion NSURLRequest encapsulates two basic data elements about a URL load request: \<ul> \<li>The URL to load. \<li>The policy to use when consulting the URL content cache made available by the implementation. \</ul> In addition, NSURLRequest is designed to be extended to support protocol-specific data by adding categories to access a property object provided in an interface targeted at protocol implementors. \<ul> \<li>Protocol implementors should direct their attention to the NSURLRequestExtensibility category on NSURLRequest for more information on how to provide extensions on NSURLRequest to support protocol-specific request information. \<li>Clients of this API who wish to create NSURLRequest objects to load URL content should consult the protocol-specific NSURLRequest categories that are available. The NSHTTPURLRequest category on NSURLRequest is an example. \</ul> \<p> Objects of this class are used to create NSURLConnection instances, which can are used to perform the load of a URL, or as input to the NSURLConnection class method which performs synchronous loads.
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
         * @details \@method requestWithURL: \@abstract Allocates and initializes an NSURLRequest with the given URL. \@discussion Default values are used for cache policy (NSURLRequestUseProtocolCachePolicy) and timeout interval (60 seconds). \@param URL The URL for the request. \@result A newly-created and autoreleased NSURLRequest instance.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static URLRequest request_with_url(const URL& url);
        /**
         * @brief Calls `+[NSURLRequest requestWithURL:cachePolicy:timeoutInterval:]`.
         * @details \@method requestWithURL:cachePolicy:timeoutInterval: \@abstract Allocates and initializes a NSURLRequest with the given URL and cache policy. \@param URL The URL for the request. \@param cachePolicy The cache policy for the request. \@param timeoutInterval The timeout interval for the request. See the commentary for the \<tt>timeoutInterval\</tt> for more information on timeout intervals. \@result A newly-created and autoreleased NSURLRequest instance.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @param cache_policy Argument converted to the Objective-C parameter of the same role.
         * @param timeout_interval Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static URLRequest request_with_url(const URL& url, URLRequestCachePolicy cache_policy, double timeout_interval);
        /**
         * @brief Calls `-[NSURLRequest valueForHTTPHeaderField:]`.
         * @details \@method valueForHTTPHeaderField: \@abstract Returns the value which corresponds to the given header field. Note that, in keeping with the HTTP RFC, HTTP header field names are case-insensitive. \@param field the header field name to use for the lookup (case-insensitive). \@result the value associated with the given header field, or nil if there is no value associated with the given header field.
         * @param field Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string value_for_http_header_field(const std::string& field) const;
        /**
         * @brief Returns the `HTTPBody` property of `NSURLRequest`.
         * @details \@abstract Returns the request body data of the receiver. \@discussion This data is sent as the message body of the request, as in done in an HTTP POST request. \@result The request body data of the receiver.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> http_body() const;
        /**
         * @brief Returns the `HTTPBodyStream` property of `NSURLRequest`.
         * @details \@abstract Returns the request body stream of the receiver if any has been set \@discussion The stream is returned for examination only; it is not safe for the caller to manipulate the stream in any way. Also note that the HTTPBodyStream and HTTPBody are mutually exclusive - only one can be set on a given request. Also note that the body stream is preserved across copies, but is LOST when the request is coded via the NSCoding protocol \@result The request body stream of the receiver.
         * @return The converted Objective-C result.
         */
        InputStream http_body_stream() const;
        /**
         * @brief Returns the `HTTPMethod` property of `NSURLRequest`.
         * @details \@abstract Returns the HTTP request method of the receiver. \@result the HTTP request method of the receiver.
         * @return The converted Objective-C result.
         */
        std::string http_method() const;
        /**
         * @brief Returns the `HTTPShouldHandleCookies` property of `NSURLRequest`.
         * @details \@abstract Determine whether default cookie handling will happen for this request. \@discussion NOTE: This value is not used prior to 10.3 \@result YES if cookies will be sent with and set for this request; otherwise NO.
         * @return The converted Objective-C result.
         */
        bool http_should_handle_cookies() const;
        /**
         * @brief Returns the `URL` property of `NSURLRequest`.
         * @details \@abstract Returns the URL of the receiver. \@result The URL of the receiver.
         * @return The converted Objective-C result.
         */
        URL url() const;
        /**
         * @brief Returns the `allHTTPHeaderFields` property of `NSURLRequest`.
         * @details \@abstract Returns a dictionary containing all the HTTP header fields of the receiver. \@result a dictionary containing all the HTTP header fields of the receiver.
         * @return The converted Objective-C result.
         */
        std::map<std::string, std::string> all_http_header_fields() const;
        /**
         * @brief Returns the `allowsCellularAccess` property of `NSURLRequest`.
         * @details \@abstract returns whether a connection created with this request is allowed to use the built in cellular radios (if present). \@result YES if the receiver is allowed to use the built in cellular radios to satisfy the request, NO otherwise.
         * @return The converted Objective-C result.
         */
        bool allows_cellular_access() const;
        /**
         * @brief Returns the `allowsConstrainedNetworkAccess` property of `NSURLRequest`.
         * @details \@abstract returns whether a connection created with this request is allowed to use network interfaces which have been marked as constrained. \@result YES if the receiver is allowed to use an interface marked as constrained to satisfy the request, NO otherwise.
         * @return The converted Objective-C result.
         */
        bool allows_constrained_network_access() const;
        /**
         * @brief Returns the `allowsExpensiveNetworkAccess` property of `NSURLRequest`.
         * @details \@abstract returns whether a connection created with this request is allowed to use network interfaces which have been marked as expensive. \@result YES if the receiver is allowed to use an interface marked as expensive to satisfy the request, NO otherwise.
         * @return The converted Objective-C result.
         */
        bool allows_expensive_network_access() const;
        /**
         * @brief Returns the `allowsPersistentDNS` property of `NSURLRequest`.
         * @details \@abstract Allows storing and usage of DNS answers, potentially beyond TTL expiry, in a persistent per-process cache. This should only be set for hostnames whose resolutions are not expected to change across networks. \@discussion YES, if the DNS lookup for this request is allowed to use a persistent per-process cache, NO otherwise. Defaults to NO.
         * @return The converted Objective-C result.
         */
        bool allows_persistent_dns() const;
        /**
         * @brief Returns the `allowsUltraConstrainedNetworkAccess` property of `NSURLRequest`.
         * @details \@abstract returns whether a connection created with this request is allowed to use network interfaces which have been marked as ultra constrained. \@result YES if the receiver is allowed to use an interface marked as ultra constrained to satisfy the request, NO otherwise.
         * @return The converted Objective-C result.
         */
        bool allows_ultra_constrained_network_access() const;
        /**
         * @brief Returns the `assumesHTTP3Capable` property of `NSURLRequest`.
         * @details \@abstract returns whether we assume that server supports HTTP/3. Enables QUIC racing without HTTP/3 service discovery. \@result YES if server endpoint is known to support HTTP/3. Defaults to NO. The default may be YES in a future OS update.
         * @return The converted Objective-C result.
         */
        bool assumes_http3_capable() const;
        /**
         * @brief Returns the `attribution` property of `NSURLRequest`.
         * @details \@abstract Returns the NSURLRequestAttribution associated with this request. \@discussion This will return NSURLRequestAttributionDeveloper for requests that have not explicitly set an attribution. \@result The NSURLRequestAttribution associated with this request.
         * @return The converted Objective-C result.
         */
        URLRequestAttribution attribution() const;
        /**
         * @brief Returns the `cachePolicy` property of `NSURLRequest`.
         * @details \@abstract Returns the cache policy of the receiver. \@result The cache policy of the receiver.
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
         * @details \@abstract The main document URL associated with this load. \@discussion This URL is used for the cookie "same domain as main document" policy, and attributing the request as a sub-resource of a user-specified URL. There may also be other future uses. See setMainDocumentURL: \@result The main document URL.
         * @return The converted Objective-C result.
         */
        URL main_document_url() const;
        /**
         * @brief Returns the `networkServiceType` property of `NSURLRequest`.
         * @details \@abstract Returns the NSURLRequestNetworkServiceType associated with this request. \@discussion This will return NSURLNetworkServiceTypeDefault for requests that have not explicitly set a networkServiceType (using the setNetworkServiceType method). \@result The NSURLRequestNetworkServiceType associated with this request.
         * @return The converted Objective-C result.
         */
        URLRequestNetworkServiceType network_service_type() const;
        /**
         * @brief Returns the `requiresDNSSECValidation` property of `NSURLRequest`.
         * @details \@abstract sets whether a request is required to do DNSSEC validation during DNS lookup. \@discussion YES, if the DNS lookup for this request should require DNSSEC validation, No otherwise. Defaults to NO.
         * @return The converted Objective-C result.
         */
        bool requires_dnssec_validation() const;
        /**
         * @brief Returns the `supportsSecureCoding` property of `NSURLRequest`.
         * @details \@property supportsSecureCoding \@abstract Indicates that NSURLRequest implements the NSSecureCoding protocol. \@result A BOOL value set to YES.
         * @return The converted Objective-C result.
         */
        static bool supports_secure_coding();
        /**
         * @brief Returns the `timeoutInterval` property of `NSURLRequest`.
         * @details \@abstract Returns the timeout interval of the receiver. \@discussion The timeout interval specifies the limit on the idle interval allotted to a request in the process of loading. The "idle interval" is defined as the period of time that has passed since the last instance of load activity occurred for a request that is in the process of loading. Hence, when an instance of load activity occurs (e.g. bytes are received from the network for a request), the idle interval for a request is reset to 0. If the idle interval ever becomes greater than or equal to the timeout interval, the request is considered to have timed out. This timeout interval is measured in seconds. \@result The timeout interval of the receiver.
         * @return The converted Objective-C result.
         */
        double timeout_interval() const;
    };
}
