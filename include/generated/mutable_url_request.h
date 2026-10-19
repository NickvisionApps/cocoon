#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/url_request.h"
#include "types.h"

namespace cocoon
{
    class InputStream;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSMutableURLRequest` (Foundation).
     * @details \@class NSMutableURLRequest \@abstract An NSMutableURLRequest object represents a mutable URL load request in a manner independent of protocol and URL scheme. \@discussion This specialization of NSURLRequest is provided to aid developers who may find it more convenient to mutate a single request object for a series of URL loads instead of creating an immutable NSURLRequest for each load. This programming model is supported by the following contract stipulation between NSMutableURLRequest and NSURLConnection: NSURLConnection makes a deep copy of each NSMutableURLRequest object passed to one of its initializers. \<p>NSMutableURLRequest is designed to be extended to support protocol-specific data by adding categories to access a property object provided in an interface targeted at protocol implementors. \<ul> \<li>Protocol implementors should direct their attention to the NSMutableURLRequestExtensibility category on NSMutableURLRequest for more information on how to provide extensions on NSMutableURLRequest to support protocol-specific request information. \<li>Clients of this API who wish to create NSMutableURLRequest objects to load URL content should consult the protocol-specific NSMutableURLRequest categories that are available. The NSMutableHTTPURLRequest category on NSMutableURLRequest is an example. \</ul>
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref URLRequest.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MutableURLRequest mutable_url_request;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MutableURLRequest mutable_url_request{};
     * mutable_url_request.set_http_body_stream(cocoon::InputStream());
     * auto http_body_stream = mutable_url_request.http_body_stream();
     * mutable_url_request.set_http_method("text");
     * auto http_method = mutable_url_request.http_method();
     * mutable_url_request.set_http_should_handle_cookies(true);
     * auto http_should_handle_cookies = mutable_url_request.http_should_handle_cookies();
     * mutable_url_request.add_value("text", "text");
     * mutable_url_request.set_value("text", "text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmutableurlrequest
     */
    class MutableURLRequest : public URLRequest
    {
    public:
        /// @brief Creates a new `NSMutableURLRequest` instance and returns a handle to it.
        explicit MutableURLRequest();
        /// @brief Creates a null handle that refers to no native object.
        MutableURLRequest(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MutableURLRequest(Adopt adopt);
        using URLRequest::all_http_header_fields;
        using URLRequest::allows_cellular_access;
        using URLRequest::allows_constrained_network_access;
        using URLRequest::allows_expensive_network_access;
        using URLRequest::allows_persistent_dns;
        using URLRequest::allows_ultra_constrained_network_access;
        using URLRequest::assumes_http3_capable;
        using URLRequest::attribution;
        using URLRequest::cache_policy;
        using URLRequest::cookie_partition_identifier;
        using URLRequest::http_body;
        using URLRequest::http_body_stream;
        using URLRequest::http_method;
        using URLRequest::http_should_handle_cookies;
        using URLRequest::main_document_url;
        using URLRequest::network_service_type;
        using URLRequest::requires_dnssec_validation;
        using URLRequest::timeout_interval;
        using URLRequest::url;
        /**
     * @brief Calls `-[NSMutableURLRequest addValue:forHTTPHeaderField:]`.
     * @details \@method addValue:forHTTPHeaderField: \@abstract Adds an HTTP header field in the current header dictionary. \@discussion This method provides a way to add values to header fields incrementally. If a value was previously set for the given header field, the given value is appended to the previously-existing value. The appropriate field delimiter, a comma in the case of HTTP, is added by the implementation, and should not be added to the given value by the caller. Note that, in keeping with the HTTP RFC, HTTP header field names are case-insensitive. \@param value the header field value. \@param field the header field name (case-insensitive).
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param field Argument converted to the Objective-C parameter of the same role.
     */
        void add_value(const std::string& value, const std::string& field) const;
        /**
     * @brief Calls `-[NSMutableURLRequest setValue:forHTTPHeaderField:]`.
     * @details \@method setValue:forHTTPHeaderField: \@abstract Sets the value of the given HTTP header field. \@discussion If a value was previously set for the given header field, that value is replaced with the given value. Note that, in keeping with the HTTP RFC, HTTP header field names are case-insensitive. \@param value the header field value. \@param field the header field name (case-insensitive).
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param field Argument converted to the Objective-C parameter of the same role.
     */
        void set_value(const std::string& value, const std::string& field) const;
        /**
     * @brief Returns the `HTTPBody` property of `NSMutableURLRequest`.
     * @details \@abstract Sets the request body data of the receiver. \@discussion This data is sent as the message body of the request, as in done in an HTTP POST request.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> http_body() const;
        /**
     * @brief Sets the `HTTPBody` property of `NSMutableURLRequest`.
     * @details \@abstract Sets the request body data of the receiver. \@discussion This data is sent as the message body of the request, as in done in an HTTP POST request.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_http_body(const std::vector<std::uint8_t>& value) const;
        /**
     * @brief Returns the `HTTPBodyStream` property of `NSMutableURLRequest`.
     * @details \@abstract Sets the request body to be the contents of the given stream. \@discussion The provided stream should be unopened; the request will take over the stream's delegate. The entire stream's contents will be transmitted as the HTTP body of the request. Note that the body stream and the body data (set by setHTTPBody:, above) are mutually exclusive - setting one will clear the other.
     * @return The converted Objective-C result.
     */
        InputStream http_body_stream() const;
        /**
     * @brief Sets the `HTTPBodyStream` property of `NSMutableURLRequest`.
     * @details \@abstract Sets the request body to be the contents of the given stream. \@discussion The provided stream should be unopened; the request will take over the stream's delegate. The entire stream's contents will be transmitted as the HTTP body of the request. Note that the body stream and the body data (set by setHTTPBody:, above) are mutually exclusive - setting one will clear the other.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_http_body_stream(const InputStream& value) const;
        /**
     * @brief Returns the `HTTPMethod` property of `NSMutableURLRequest`.
     * @details \@abstract Sets the HTTP request method of the receiver.
     * @return The converted Objective-C result.
     */
        std::string http_method() const;
        /**
     * @brief Sets the `HTTPMethod` property of `NSMutableURLRequest`.
     * @details \@abstract Sets the HTTP request method of the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_http_method(const std::string& value) const;
        /**
     * @brief Returns the `HTTPShouldHandleCookies` property of `NSMutableURLRequest`.
     * @details \@abstract Decide whether default cookie handling will happen for this request (YES if cookies should be sent with and set for this request; otherwise NO). \@discussion The default is YES - in other words, cookies are sent from and stored to the cookie manager by default. NOTE: In releases prior to 10.3, this value is ignored
     * @return The converted Objective-C result.
     */
        bool http_should_handle_cookies() const;
        /**
     * @brief Sets the `HTTPShouldHandleCookies` property of `NSMutableURLRequest`.
     * @details \@abstract Decide whether default cookie handling will happen for this request (YES if cookies should be sent with and set for this request; otherwise NO). \@discussion The default is YES - in other words, cookies are sent from and stored to the cookie manager by default. NOTE: In releases prior to 10.3, this value is ignored
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_http_should_handle_cookies(bool value) const;
        /**
     * @brief Returns the `URL` property of `NSMutableURLRequest`.
     * @details \@abstract The URL of the receiver.
     * @return The converted Objective-C result.
     */
        URL url() const;
        /**
     * @brief Sets the `URL` property of `NSMutableURLRequest`.
     * @details \@abstract The URL of the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_url(const URL& value) const;
        /**
     * @brief Returns the `allHTTPHeaderFields` property of `NSMutableURLRequest`.
     * @details \@abstract Sets the HTTP header fields of the receiver to the given dictionary. \@discussion This method replaces all header fields that may have existed before this method call. \<p>Since HTTP header fields must be string values, each object and key in the dictionary passed to this method must answer YES when sent an \<tt>-isKindOfClass:[NSString class]\</tt> message. If either the key or value for a key-value pair answers NO when sent this message, the key-value pair is skipped.
     * @return The converted Objective-C result.
     */
        std::map<std::string, std::string> all_http_header_fields() const;
        /**
     * @brief Sets the `allHTTPHeaderFields` property of `NSMutableURLRequest`.
     * @details \@abstract Sets the HTTP header fields of the receiver to the given dictionary. \@discussion This method replaces all header fields that may have existed before this method call. \<p>Since HTTP header fields must be string values, each object and key in the dictionary passed to this method must answer YES when sent an \<tt>-isKindOfClass:[NSString class]\</tt> message. If either the key or value for a key-value pair answers NO when sent this message, the key-value pair is skipped.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_all_http_header_fields(const std::map<std::string, std::string>& value) const;
        /**
     * @brief Returns the `allowsCellularAccess` property of `NSMutableURLRequest`.
     * @details \@abstract sets whether a connection created with this request is allowed to use the built in cellular radios (if present). \@discussion NO if the receiver should not be allowed to use the built in cellular radios to satisfy the request, YES otherwise. The default is YES.
     * @return The converted Objective-C result.
     */
        bool allows_cellular_access() const;
        /**
     * @brief Sets the `allowsCellularAccess` property of `NSMutableURLRequest`.
     * @details \@abstract sets whether a connection created with this request is allowed to use the built in cellular radios (if present). \@discussion NO if the receiver should not be allowed to use the built in cellular radios to satisfy the request, YES otherwise. The default is YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_cellular_access(bool value) const;
        /**
     * @brief Returns the `allowsConstrainedNetworkAccess` property of `NSMutableURLRequest`.
     * @details \@abstract sets whether a connection created with this request is allowed to use network interfaces which have been marked as constrained. \@discussion NO if the receiver should not be allowed to use an interface marked as constrained to satisfy the request, YES otherwise.
     * @return The converted Objective-C result.
     */
        bool allows_constrained_network_access() const;
        /**
     * @brief Sets the `allowsConstrainedNetworkAccess` property of `NSMutableURLRequest`.
     * @details \@abstract sets whether a connection created with this request is allowed to use network interfaces which have been marked as constrained. \@discussion NO if the receiver should not be allowed to use an interface marked as constrained to satisfy the request, YES otherwise.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_constrained_network_access(bool value) const;
        /**
     * @brief Returns the `allowsExpensiveNetworkAccess` property of `NSMutableURLRequest`.
     * @details \@abstract sets whether a connection created with this request is allowed to use network interfaces which have been marked as expensive. \@discussion NO if the receiver should not be allowed to use an interface marked as expensive to satisfy the request, YES otherwise.
     * @return The converted Objective-C result.
     */
        bool allows_expensive_network_access() const;
        /**
     * @brief Sets the `allowsExpensiveNetworkAccess` property of `NSMutableURLRequest`.
     * @details \@abstract sets whether a connection created with this request is allowed to use network interfaces which have been marked as expensive. \@discussion NO if the receiver should not be allowed to use an interface marked as expensive to satisfy the request, YES otherwise.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_expensive_network_access(bool value) const;
        /**
     * @brief Returns the `allowsPersistentDNS` property of `NSMutableURLRequest`.
     * @details \@abstract Allows storing and usage of DNS answers, potentially beyond TTL expiry, in a persistent per-process cache. This should only be set for hostnames whose resolutions are not expected to change across networks. \@discussion YES, if the DNS lookup for this request is allowed to use a persistent per-process cache, NO otherwise. Defaults to NO.
     * @return The converted Objective-C result.
     */
        bool allows_persistent_dns() const;
        /**
     * @brief Sets the `allowsPersistentDNS` property of `NSMutableURLRequest`.
     * @details \@abstract Allows storing and usage of DNS answers, potentially beyond TTL expiry, in a persistent per-process cache. This should only be set for hostnames whose resolutions are not expected to change across networks. \@discussion YES, if the DNS lookup for this request is allowed to use a persistent per-process cache, NO otherwise. Defaults to NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_persistent_dns(bool value) const;
        /**
     * @brief Returns the `allowsUltraConstrainedNetworkAccess` property of `NSMutableURLRequest`.
     * @details \@abstract sets whether a connection created with this request is allowed to use network interfaces which have been marked as ultra constrained. \@discussion NO if the receiver should not be allowed to use an interface marked as ultra constrained to satisfy the request, YES otherwise.
     * @return The converted Objective-C result.
     */
        bool allows_ultra_constrained_network_access() const;
        /**
     * @brief Sets the `allowsUltraConstrainedNetworkAccess` property of `NSMutableURLRequest`.
     * @details \@abstract sets whether a connection created with this request is allowed to use network interfaces which have been marked as ultra constrained. \@discussion NO if the receiver should not be allowed to use an interface marked as ultra constrained to satisfy the request, YES otherwise.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_ultra_constrained_network_access(bool value) const;
        /**
     * @brief Returns the `assumesHTTP3Capable` property of `NSMutableURLRequest`.
     * @details \@abstract returns whether we assume that server supports HTTP/3. Enables QUIC racing without HTTP/3 service discovery. \@result YES if server endpoint is known to support HTTP/3. Defaults to NO. The default may be YES in a future OS update.
     * @return The converted Objective-C result.
     */
        bool assumes_http3_capable() const;
        /**
     * @brief Sets the `assumesHTTP3Capable` property of `NSMutableURLRequest`.
     * @details \@abstract returns whether we assume that server supports HTTP/3. Enables QUIC racing without HTTP/3 service discovery. \@result YES if server endpoint is known to support HTTP/3. Defaults to NO. The default may be YES in a future OS update.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_assumes_http3_capable(bool value) const;
        /**
     * @brief Returns the `attribution` property of `NSMutableURLRequest`.
     * @details \@abstract Sets the NSURLRequestAttribution to associate with this request. \@discussion Set to NSURLRequestAttributionUser if the URL was specified by the user. Defaults to NSURLRequestAttributionDeveloper.
     * @return The converted Objective-C result.
     */
        URLRequestAttribution attribution() const;
        /**
     * @brief Sets the `attribution` property of `NSMutableURLRequest`.
     * @details \@abstract Sets the NSURLRequestAttribution to associate with this request. \@discussion Set to NSURLRequestAttributionUser if the URL was specified by the user. Defaults to NSURLRequestAttributionDeveloper.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attribution(URLRequestAttribution value) const;
        /**
     * @brief Returns the `cachePolicy` property of `NSMutableURLRequest`.
     * @details \@abstract The cache policy of the receiver.
     * @return The converted Objective-C result.
     */
        URLRequestCachePolicy cache_policy() const;
        /**
     * @brief Sets the `cachePolicy` property of `NSMutableURLRequest`.
     * @details \@abstract The cache policy of the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_cache_policy(URLRequestCachePolicy value) const;
        /**
     * @brief Returns the `cookiePartitionIdentifier` property of `NSMutableURLRequest`.
     * @details Cookie partition identifier used for cookie storage and retrieval.
     * @return The converted Objective-C result.
     */
        std::string cookie_partition_identifier() const;
        /**
     * @brief Sets the `cookiePartitionIdentifier` property of `NSMutableURLRequest`.
     * @details Cookie partition identifier used for cookie storage and retrieval.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_cookie_partition_identifier(const std::string& value) const;
        /**
     * @brief Returns the `mainDocumentURL` property of `NSMutableURLRequest`.
     * @details \@abstract Sets the main document URL \@discussion The caller should pass the URL for an appropriate main document, if known. For example, when loading a web page, the URL of the main html document for the top-level frame should be passed. This main document is used to implement the cookie "only from same domain as main document" policy, attributing this request as a sub-resource of a user-specified URL, and possibly other things in the future.
     * @return The converted Objective-C result.
     */
        URL main_document_url() const;
        /**
     * @brief Sets the `mainDocumentURL` property of `NSMutableURLRequest`.
     * @details \@abstract Sets the main document URL \@discussion The caller should pass the URL for an appropriate main document, if known. For example, when loading a web page, the URL of the main html document for the top-level frame should be passed. This main document is used to implement the cookie "only from same domain as main document" policy, attributing this request as a sub-resource of a user-specified URL, and possibly other things in the future.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_main_document_url(const URL& value) const;
        /**
     * @brief Returns the `networkServiceType` property of `NSMutableURLRequest`.
     * @details \@abstract Sets the NSURLRequestNetworkServiceType to associate with this request \@discussion This method is used to provide the network layers with a hint as to the purpose of the request. Most clients should not need to use this method.
     * @return The converted Objective-C result.
     */
        URLRequestNetworkServiceType network_service_type() const;
        /**
     * @brief Sets the `networkServiceType` property of `NSMutableURLRequest`.
     * @details \@abstract Sets the NSURLRequestNetworkServiceType to associate with this request \@discussion This method is used to provide the network layers with a hint as to the purpose of the request. Most clients should not need to use this method.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_network_service_type(URLRequestNetworkServiceType value) const;
        /**
     * @brief Returns the `requiresDNSSECValidation` property of `NSMutableURLRequest`.
     * @details \@abstract sets whether a request is required to do DNSSEC validation during DNS lookup. \@discussion YES, if the DNS lookup for this request should require DNSSEC validation, No otherwise. Defaults to NO.
     * @return The converted Objective-C result.
     */
        bool requires_dnssec_validation() const;
        /**
     * @brief Sets the `requiresDNSSECValidation` property of `NSMutableURLRequest`.
     * @details \@abstract sets whether a request is required to do DNSSEC validation during DNS lookup. \@discussion YES, if the DNS lookup for this request should require DNSSEC validation, No otherwise. Defaults to NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_requires_dnssec_validation(bool value) const;
        /**
     * @brief Returns the `timeoutInterval` property of `NSMutableURLRequest`.
     * @details \@abstract Sets the timeout interval of the receiver. \@discussion The timeout interval specifies the limit on the idle interval allotted to a request in the process of loading. The "idle interval" is defined as the period of time that has passed since the last instance of load activity occurred for a request that is in the process of loading. Hence, when an instance of load activity occurs (e.g. bytes are received from the network for a request), the idle interval for a request is reset to 0. If the idle interval ever becomes greater than or equal to the timeout interval, the request is considered to have timed out. This timeout interval is measured in seconds.
     * @return The converted Objective-C result.
     */
        double timeout_interval() const;
        /**
     * @brief Sets the `timeoutInterval` property of `NSMutableURLRequest`.
     * @details \@abstract Sets the timeout interval of the receiver. \@discussion The timeout interval specifies the limit on the idle interval allotted to a request in the process of loading. The "idle interval" is defined as the period of time that has passed since the last instance of load activity occurred for a request that is in the process of loading. Hence, when an instance of load activity occurs (e.g. bytes are received from the network for a request), the idle interval for a request is reset to 0. If the idle interval ever becomes greater than or equal to the timeout interval, the request is considered to have timed out. This timeout interval is measured in seconds.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_timeout_interval(double value) const;
    };
}
