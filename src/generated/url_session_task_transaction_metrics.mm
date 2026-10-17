#include "generated/url_session_task_transaction_metrics.h"
#include "internal.h"

namespace cocoon
{
    URLSessionTaskTransactionMetrics::URLSessionTaskTransactionMetrics() : URLSessionTaskTransactionMetrics(Adopt{cocoon::internal::retain([[::NSURLSessionTaskTransactionMetrics alloc] init])})
    {
    }

    URLSessionTaskTransactionMetrics::URLSessionTaskTransactionMetrics(std::nullptr_t) : Object(nullptr)
    {
    }

    URLSessionTaskTransactionMetrics::URLSessionTaskTransactionMetrics(Adopt adopt) : Object(adopt)
    {
    }

    bool URLSessionTaskTransactionMetrics::is_cellular() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) isCellular]);
    }

    Date URLSessionTaskTransactionMetrics::connect_end_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) connectEndDate]);
    }

    Date URLSessionTaskTransactionMetrics::connect_start_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) connectStartDate]);
    }

    bool URLSessionTaskTransactionMetrics::is_constrained() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) isConstrained]);
    }

    std::int64_t URLSessionTaskTransactionMetrics::count_of_request_body_bytes_before_encoding() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) countOfRequestBodyBytesBeforeEncoding]);
    }

    std::int64_t URLSessionTaskTransactionMetrics::count_of_request_body_bytes_sent() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) countOfRequestBodyBytesSent]);
    }

    std::int64_t URLSessionTaskTransactionMetrics::count_of_request_header_bytes_sent() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) countOfRequestHeaderBytesSent]);
    }

    std::int64_t URLSessionTaskTransactionMetrics::count_of_response_body_bytes_after_decoding() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) countOfResponseBodyBytesAfterDecoding]);
    }

    std::int64_t URLSessionTaskTransactionMetrics::count_of_response_body_bytes_received() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) countOfResponseBodyBytesReceived]);
    }

    std::int64_t URLSessionTaskTransactionMetrics::count_of_response_header_bytes_received() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) countOfResponseHeaderBytesReceived]);
    }

    Date URLSessionTaskTransactionMetrics::domain_lookup_end_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) domainLookupEndDate]);
    }

    Date URLSessionTaskTransactionMetrics::domain_lookup_start_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) domainLookupStartDate]);
    }

    URLSessionTaskMetricsDomainResolutionProtocol URLSessionTaskTransactionMetrics::domain_resolution_protocol() const
    {
        return static_cast<URLSessionTaskMetricsDomainResolutionProtocol>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) domainResolutionProtocol]);
    }

    bool URLSessionTaskTransactionMetrics::is_expensive() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) isExpensive]);
    }

    Date URLSessionTaskTransactionMetrics::fetch_start_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) fetchStartDate]);
    }

    std::string URLSessionTaskTransactionMetrics::local_address() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) localAddress]);
    }

    Number URLSessionTaskTransactionMetrics::local_port() const
    {
        return cocoon::internal::wrap<Number>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) localPort]);
    }

    bool URLSessionTaskTransactionMetrics::is_multipath() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) isMultipath]);
    }

    Number URLSessionTaskTransactionMetrics::negotiated_tls_cipher_suite() const
    {
        return cocoon::internal::wrap<Number>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) negotiatedTLSCipherSuite]);
    }

    Number URLSessionTaskTransactionMetrics::negotiated_tls_protocol_version() const
    {
        return cocoon::internal::wrap<Number>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) negotiatedTLSProtocolVersion]);
    }

    std::string URLSessionTaskTransactionMetrics::network_protocol_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) networkProtocolName]);
    }

    bool URLSessionTaskTransactionMetrics::is_proxy_connection() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) isProxyConnection]);
    }

    std::string URLSessionTaskTransactionMetrics::remote_address() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) remoteAddress]);
    }

    Number URLSessionTaskTransactionMetrics::remote_port() const
    {
        return cocoon::internal::wrap<Number>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) remotePort]);
    }

    URLRequest URLSessionTaskTransactionMetrics::request() const
    {
        return cocoon::internal::wrap<URLRequest>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) request]);
    }

    Date URLSessionTaskTransactionMetrics::request_end_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) requestEndDate]);
    }

    Date URLSessionTaskTransactionMetrics::request_start_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) requestStartDate]);
    }

    URLSessionTaskMetricsResourceFetchType URLSessionTaskTransactionMetrics::resource_fetch_type() const
    {
        return static_cast<URLSessionTaskMetricsResourceFetchType>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) resourceFetchType]);
    }

    URLResponse URLSessionTaskTransactionMetrics::response() const
    {
        return cocoon::internal::wrap<URLResponse>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) response]);
    }

    Date URLSessionTaskTransactionMetrics::response_end_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) responseEndDate]);
    }

    Date URLSessionTaskTransactionMetrics::response_start_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) responseStartDate]);
    }

    bool URLSessionTaskTransactionMetrics::is_reused_connection() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) isReusedConnection]);
    }

    Date URLSessionTaskTransactionMetrics::secure_connection_end_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) secureConnectionEndDate]);
    }

    Date URLSessionTaskTransactionMetrics::secure_connection_start_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSURLSessionTaskTransactionMetrics>(this) secureConnectionStartDate]);
    }
}
