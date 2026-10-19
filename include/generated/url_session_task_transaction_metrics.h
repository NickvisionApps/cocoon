#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;
    class Number;
    class URLRequest;
    class URLResponse;

    /**
     * @brief C++ handle for the Objective-C class `NSURLSessionTaskTransactionMetrics` (Foundation).
     * @details This class defines the performance metrics collected for a request/response transaction during the task execution.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLSessionTaskTransactionMetrics url_session_task_transaction_metrics;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlsessiontasktransactionmetrics
     */
    class URLSessionTaskTransactionMetrics : public Object
    {
    public:
        /// @brief Creates a new `NSURLSessionTaskTransactionMetrics` instance and returns a handle to it.
        explicit URLSessionTaskTransactionMetrics();
        /// @brief Creates a null handle that refers to no native object.
        URLSessionTaskTransactionMetrics(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLSessionTaskTransactionMetrics(Adopt adopt);
        /**
     * @brief Returns the `cellular` property of `NSURLSessionTaskTransactionMetrics`.
     * @details Whether the connection is established over a cellular interface.
     * @return The converted Objective-C result.
     */
        bool is_cellular() const;
        /**
     * @brief Returns the `connectEndDate` property of `NSURLSessionTaskTransactionMetrics`.
     * @details connectEndDate is the time immediately after the user agent finished establishing the connection to the server, including completion of security-related and other handshakes.
     * @return The converted Objective-C result.
     */
        Date connect_end_date() const;
        /**
     * @brief Returns the `connectStartDate` property of `NSURLSessionTaskTransactionMetrics`.
     * @details connectStartDate is the time immediately before the user agent started establishing the connection to the server. For example, this would correspond to the time immediately before the user agent started trying to establish the TCP connection.
     * @return The converted Objective-C result.
     */
        Date connect_start_date() const;
        /**
     * @brief Returns the `constrained` property of `NSURLSessionTaskTransactionMetrics`.
     * @details Whether the connection is established over a constrained interface.
     * @return The converted Objective-C result.
     */
        bool is_constrained() const;
        /**
     * @brief Returns the `countOfRequestBodyBytesBeforeEncoding` property of `NSURLSessionTaskTransactionMetrics`.
     * @details countOfRequestBodyBytesBeforeEncoding is the size of upload body data, file, or stream.
     * @return The converted Objective-C result.
     */
        std::int64_t count_of_request_body_bytes_before_encoding() const;
        /**
     * @brief Returns the `countOfRequestBodyBytesSent` property of `NSURLSessionTaskTransactionMetrics`.
     * @details countOfRequestBodyBytesSent is the number of bytes transferred for request body. It includes protocol-specific framing, transfer encoding, and content encoding.
     * @return The converted Objective-C result.
     */
        std::int64_t count_of_request_body_bytes_sent() const;
        /**
     * @brief Returns the `countOfRequestHeaderBytesSent` property of `NSURLSessionTaskTransactionMetrics`.
     * @details countOfRequestHeaderBytesSent is the number of bytes transferred for request header.
     * @return The converted Objective-C result.
     */
        std::int64_t count_of_request_header_bytes_sent() const;
        /**
     * @brief Returns the `countOfResponseBodyBytesAfterDecoding` property of `NSURLSessionTaskTransactionMetrics`.
     * @details countOfResponseBodyBytesAfterDecoding is the size of data delivered to your delegate or completion handler.
     * @return The converted Objective-C result.
     */
        std::int64_t count_of_response_body_bytes_after_decoding() const;
        /**
     * @brief Returns the `countOfResponseBodyBytesReceived` property of `NSURLSessionTaskTransactionMetrics`.
     * @details countOfResponseBodyBytesReceived is the number of bytes transferred for response header. It includes protocol-specific framing, transfer encoding, and content encoding.
     * @return The converted Objective-C result.
     */
        std::int64_t count_of_response_body_bytes_received() const;
        /**
     * @brief Returns the `countOfResponseHeaderBytesReceived` property of `NSURLSessionTaskTransactionMetrics`.
     * @details countOfResponseHeaderBytesReceived is the number of bytes transferred for response header.
     * @return The converted Objective-C result.
     */
        std::int64_t count_of_response_header_bytes_received() const;
        /**
     * @brief Returns the `domainLookupEndDate` property of `NSURLSessionTaskTransactionMetrics`.
     * @details domainLookupEndDate returns the time after the name lookup was completed.
     * @return The converted Objective-C result.
     */
        Date domain_lookup_end_date() const;
        /**
     * @brief Returns the `domainLookupStartDate` property of `NSURLSessionTaskTransactionMetrics`.
     * @details domainLookupStartDate returns the time immediately before the user agent started the name lookup for the resource.
     * @return The converted Objective-C result.
     */
        Date domain_lookup_start_date() const;
        /**
     * @brief Returns the `domainResolutionProtocol` property of `NSURLSessionTaskTransactionMetrics`.
     * @details DNS protocol used for domain resolution.
     * @return The converted Objective-C result.
     */
        URLSessionTaskMetricsDomainResolutionProtocol domain_resolution_protocol() const;
        /**
     * @brief Returns the `expensive` property of `NSURLSessionTaskTransactionMetrics`.
     * @details Whether the connection is established over an expensive interface.
     * @return The converted Objective-C result.
     */
        bool is_expensive() const;
        /**
     * @brief Returns the `fetchStartDate` property of `NSURLSessionTaskTransactionMetrics`.
     * @details fetchStartDate returns the time when the user agent started fetching the resource, whether or not the resource was retrieved from the server or local resources. The following metrics will be set to nil, if a persistent connection was used or the resource was retrieved from local resources: domainLookupStartDate domainLookupEndDate connectStartDate connectEndDate secureConnectionStartDate secureConnectionEndDate
     * @return The converted Objective-C result.
     */
        Date fetch_start_date() const;
        /**
     * @brief Returns the `localAddress` property of `NSURLSessionTaskTransactionMetrics`.
     * @details localAddress is the IP address string of the local interface for the connection. For multipath protocols, this is the local address of the initial flow. If a connection was not used, this attribute is set to nil.
     * @return The converted Objective-C result.
     */
        std::string local_address() const;
        /**
     * @brief Returns the `localPort` property of `NSURLSessionTaskTransactionMetrics`.
     * @details localPort is the port number of the local interface for the connection. For multipath protocols, this is the local port of the initial flow. If a connection was not used, this attribute is set to nil.
     * @return The converted Objective-C result.
     */
        Number local_port() const;
        /**
     * @brief Returns the `multipath` property of `NSURLSessionTaskTransactionMetrics`.
     * @details Whether a multipath protocol is successfully negotiated for the connection.
     * @return The converted Objective-C result.
     */
        bool is_multipath() const;
        /**
     * @brief Returns the `negotiatedTLSCipherSuite` property of `NSURLSessionTaskTransactionMetrics`.
     * @details negotiatedTLSCipherSuite is the TLS cipher suite negotiated for the connection. It is a 2-byte sequence in host byte order. Please refer to tls_ciphersuite_t enum in Security/SecProtocolTypes.h If an encrypted connection was not used, this attribute is set to nil.
     * @return The converted Objective-C result.
     */
        Number negotiated_tls_cipher_suite() const;
        /**
     * @brief Returns the `negotiatedTLSProtocolVersion` property of `NSURLSessionTaskTransactionMetrics`.
     * @details negotiatedTLSProtocolVersion is the TLS protocol version negotiated for the connection. It is a 2-byte sequence in host byte order. Please refer to tls_protocol_version_t enum in Security/SecProtocolTypes.h If an encrypted connection was not used, this attribute is set to nil.
     * @return The converted Objective-C result.
     */
        Number negotiated_tls_protocol_version() const;
        /**
     * @brief Returns the `networkProtocolName` property of `NSURLSessionTaskTransactionMetrics`.
     * @details The network protocol used to fetch the resource, as identified by the ALPN Protocol ID Identification Sequence [RFC7301]. E.g., h3, h2, http/1.1. When a proxy is configured AND a tunnel connection is established, then this attribute returns the value for the tunneled protocol. For example: If no proxy were used, and HTTP/2 was negotiated, then h2 would be returned. If HTTP/1.1 were used to the proxy, and the tunneled connection was HTTP/2, then h2 would be returned. If HTTP/1.1 were used to the proxy, and there were no tunnel, then http/1.1 would be returned.
     * @return The converted Objective-C result.
     */
        std::string network_protocol_name() const;
        /**
     * @brief Returns the `proxyConnection` property of `NSURLSessionTaskTransactionMetrics`.
     * @details This property is set to YES if a proxy connection was used to fetch the resource.
     * @return The converted Objective-C result.
     */
        bool is_proxy_connection() const;
        /**
     * @brief Returns the `remoteAddress` property of `NSURLSessionTaskTransactionMetrics`.
     * @details remoteAddress is the IP address string of the remote interface for the connection. For multipath protocols, this is the remote address of the initial flow. If a connection was not used, this attribute is set to nil.
     * @return The converted Objective-C result.
     */
        std::string remote_address() const;
        /**
     * @brief Returns the `remotePort` property of `NSURLSessionTaskTransactionMetrics`.
     * @details remotePort is the port number of the remote interface for the connection. For multipath protocols, this is the remote port of the initial flow. If a connection was not used, this attribute is set to nil.
     * @return The converted Objective-C result.
     */
        Number remote_port() const;
        /**
     * @brief Returns the `request` property of `NSURLSessionTaskTransactionMetrics`.
     * @details Represents the transaction request.
     * @return The converted Objective-C result.
     */
        URLRequest request() const;
        /**
     * @brief Returns the `requestEndDate` property of `NSURLSessionTaskTransactionMetrics`.
     * @details requestEndDate is the time immediately after the user agent finished requesting the source, regardless of whether the resource was retrieved from the server or local resources. For example, this would correspond to the time immediately after the user agent finished sending the last byte of the request.
     * @return The converted Objective-C result.
     */
        Date request_end_date() const;
        /**
     * @brief Returns the `requestStartDate` property of `NSURLSessionTaskTransactionMetrics`.
     * @details requestStartDate is the time immediately before the user agent started requesting the source, regardless of whether the resource was retrieved from the server or local resources. For example, this would correspond to the time immediately before the user agent sent an HTTP GET request.
     * @return The converted Objective-C result.
     */
        Date request_start_date() const;
        /**
     * @brief Returns the `resourceFetchType` property of `NSURLSessionTaskTransactionMetrics`.
     * @details Indicates whether the resource was loaded, pushed or retrieved from the local cache.
     * @return The converted Objective-C result.
     */
        URLSessionTaskMetricsResourceFetchType resource_fetch_type() const;
        /**
     * @brief Returns the `response` property of `NSURLSessionTaskTransactionMetrics`.
     * @details Represents the transaction response. Can be nil if error occurred and no response was generated.
     * @return The converted Objective-C result.
     */
        URLResponse response() const;
        /**
     * @brief Returns the `responseEndDate` property of `NSURLSessionTaskTransactionMetrics`.
     * @details responseEndDate is the time immediately after the user agent received the last byte of the resource.
     * @return The converted Objective-C result.
     */
        Date response_end_date() const;
        /**
     * @brief Returns the `responseStartDate` property of `NSURLSessionTaskTransactionMetrics`.
     * @details responseStartDate is the time immediately after the user agent received the first byte of the response from the server or from local resources. For example, this would correspond to the time immediately after the user agent received the first byte of an HTTP response.
     * @return The converted Objective-C result.
     */
        Date response_start_date() const;
        /**
     * @brief Returns the `reusedConnection` property of `NSURLSessionTaskTransactionMetrics`.
     * @details This property is set to YES if a persistent connection was used to fetch the resource.
     * @return The converted Objective-C result.
     */
        bool is_reused_connection() const;
        /**
     * @brief Returns the `secureConnectionEndDate` property of `NSURLSessionTaskTransactionMetrics`.
     * @details If an encrypted connection was used, secureConnectionEndDate is the time immediately after the security handshake completed. If an encrypted connection was not used, this attribute is set to nil.
     * @return The converted Objective-C result.
     */
        Date secure_connection_end_date() const;
        /**
     * @brief Returns the `secureConnectionStartDate` property of `NSURLSessionTaskTransactionMetrics`.
     * @details If an encrypted connection was used, secureConnectionStartDate is the time immediately before the user agent started the security handshake to secure the current connection. For example, this would correspond to the time immediately before the user agent started the TLS handshake. If an encrypted connection was not used, this attribute is set to nil.
     * @return The converted Objective-C result.
     */
        Date secure_connection_start_date() const;
    };
}
