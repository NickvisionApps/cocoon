#include "generated/mutable_url_request.h"
#include "internal.h"

namespace cocoon
{
    MutableURLRequest::MutableURLRequest() : MutableURLRequest(Adopt{cocoon::internal::retain([[::NSMutableURLRequest alloc] init])})
    {
    }

    MutableURLRequest::MutableURLRequest(std::nullptr_t) : URLRequest(nullptr)
    {
    }

    MutableURLRequest::MutableURLRequest(Adopt adopt) : URLRequest(adopt)
    {
    }

    void MutableURLRequest::add_value(const std::string& value, const std::string& field) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) addValue:cocoon::internal::to(value) forHTTPHeaderField:cocoon::internal::to(field)];
    }

    void MutableURLRequest::set_value(const std::string& value, const std::string& field) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setValue:cocoon::internal::to(value) forHTTPHeaderField:cocoon::internal::to(field)];
    }

    std::vector<std::uint8_t> MutableURLRequest::http_body() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSMutableURLRequest>(this) HTTPBody]);
    }

    void MutableURLRequest::set_http_body(const std::vector<std::uint8_t>& value) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setHTTPBody:cocoon::internal::to_data(value)];
    }

    InputStream MutableURLRequest::http_body_stream() const
    {
        return cocoon::internal::wrap<InputStream>([cocoon::internal::ns<::NSMutableURLRequest>(this) HTTPBodyStream]);
    }

    void MutableURLRequest::set_http_body_stream(const InputStream& value) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setHTTPBodyStream:cocoon::internal::native<::NSInputStream>(value)];
    }

    std::string MutableURLRequest::http_method() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMutableURLRequest>(this) HTTPMethod]);
    }

    void MutableURLRequest::set_http_method(const std::string& value) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setHTTPMethod:cocoon::internal::to(value)];
    }

    bool MutableURLRequest::http_should_handle_cookies() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMutableURLRequest>(this) HTTPShouldHandleCookies]);
    }

    void MutableURLRequest::set_http_should_handle_cookies(bool value) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setHTTPShouldHandleCookies:static_cast<::BOOL>(value)];
    }

    URL MutableURLRequest::url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSMutableURLRequest>(this) URL]);
    }

    void MutableURLRequest::set_url(const URL& value) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setURL:cocoon::internal::native<::NSURL>(value)];
    }

    std::map<std::string, std::string> MutableURLRequest::all_http_header_fields() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, std::string>>([cocoon::internal::ns<::NSMutableURLRequest>(this) allHTTPHeaderFields], [](id k) -> std::string
                                                                       {
                                                                           return cocoon::internal::from((NSString*)k);
                                                                       },
                                                                       [](id v) -> std::string
                                                                       {
                                                                           return cocoon::internal::from((NSString*)v);
                                                                       });
    }

    void MutableURLRequest::set_all_http_header_fields(const std::map<std::string, std::string>& value) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setAllHTTPHeaderFields:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                      {
                                                                                          return cocoon::internal::to(k);
                                                                                      },
                                                                                      [](const std::string& v) -> id
                                                                                      {
                                                                                          return cocoon::internal::to(v);
                                                                                      })];
    }

    bool MutableURLRequest::allows_cellular_access() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMutableURLRequest>(this) allowsCellularAccess]);
    }

    void MutableURLRequest::set_allows_cellular_access(bool value) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setAllowsCellularAccess:static_cast<::BOOL>(value)];
    }

    bool MutableURLRequest::allows_constrained_network_access() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMutableURLRequest>(this) allowsConstrainedNetworkAccess]);
    }

    void MutableURLRequest::set_allows_constrained_network_access(bool value) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setAllowsConstrainedNetworkAccess:static_cast<::BOOL>(value)];
    }

    bool MutableURLRequest::allows_expensive_network_access() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMutableURLRequest>(this) allowsExpensiveNetworkAccess]);
    }

    void MutableURLRequest::set_allows_expensive_network_access(bool value) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setAllowsExpensiveNetworkAccess:static_cast<::BOOL>(value)];
    }

    bool MutableURLRequest::allows_persistent_dns() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMutableURLRequest>(this) allowsPersistentDNS]);
    }

    void MutableURLRequest::set_allows_persistent_dns(bool value) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setAllowsPersistentDNS:static_cast<::BOOL>(value)];
    }

    bool MutableURLRequest::allows_ultra_constrained_network_access() const
    {
        if (@available(macOS 26.1, *))
        {
            return static_cast<bool>([cocoon::internal::ns<::NSMutableURLRequest>(this) allowsUltraConstrainedNetworkAccess]);
        }
        return {};
    }

    void MutableURLRequest::set_allows_ultra_constrained_network_access(bool value) const
    {
        if (@available(macOS 26.1, *))
        {
            [cocoon::internal::ns<::NSMutableURLRequest>(this) setAllowsUltraConstrainedNetworkAccess:static_cast<::BOOL>(value)];
        }
    }

    bool MutableURLRequest::assumes_http3_capable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMutableURLRequest>(this) assumesHTTP3Capable]);
    }

    void MutableURLRequest::set_assumes_http3_capable(bool value) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setAssumesHTTP3Capable:static_cast<::BOOL>(value)];
    }

    URLRequestAttribution MutableURLRequest::attribution() const
    {
        return static_cast<URLRequestAttribution>([cocoon::internal::ns<::NSMutableURLRequest>(this) attribution]);
    }

    void MutableURLRequest::set_attribution(URLRequestAttribution value) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setAttribution:static_cast<::NSURLRequestAttribution>(value)];
    }

    URLRequestCachePolicy MutableURLRequest::cache_policy() const
    {
        return static_cast<URLRequestCachePolicy>([cocoon::internal::ns<::NSMutableURLRequest>(this) cachePolicy]);
    }

    void MutableURLRequest::set_cache_policy(URLRequestCachePolicy value) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setCachePolicy:static_cast<::NSURLRequestCachePolicy>(value)];
    }

    std::string MutableURLRequest::cookie_partition_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMutableURLRequest>(this) cookiePartitionIdentifier]);
    }

    void MutableURLRequest::set_cookie_partition_identifier(const std::string& value) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setCookiePartitionIdentifier:cocoon::internal::to(value)];
    }

    URL MutableURLRequest::main_document_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSMutableURLRequest>(this) mainDocumentURL]);
    }

    void MutableURLRequest::set_main_document_url(const URL& value) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setMainDocumentURL:cocoon::internal::native<::NSURL>(value)];
    }

    URLRequestNetworkServiceType MutableURLRequest::network_service_type() const
    {
        return static_cast<URLRequestNetworkServiceType>([cocoon::internal::ns<::NSMutableURLRequest>(this) networkServiceType]);
    }

    void MutableURLRequest::set_network_service_type(URLRequestNetworkServiceType value) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setNetworkServiceType:static_cast<::NSURLRequestNetworkServiceType>(value)];
    }

    bool MutableURLRequest::requires_dnssec_validation() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMutableURLRequest>(this) requiresDNSSECValidation]);
    }

    void MutableURLRequest::set_requires_dnssec_validation(bool value) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setRequiresDNSSECValidation:static_cast<::BOOL>(value)];
    }

    double MutableURLRequest::timeout_interval() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMutableURLRequest>(this) timeoutInterval]);
    }

    void MutableURLRequest::set_timeout_interval(double value) const
    {
        [cocoon::internal::ns<::NSMutableURLRequest>(this) setTimeoutInterval:static_cast<::NSTimeInterval>(value)];
    }
}
