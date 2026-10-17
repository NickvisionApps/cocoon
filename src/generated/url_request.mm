#include "generated/url_request.h"
#include "internal.h"

namespace cocoon
{
    URLRequest::URLRequest(const URL& url) : URLRequest(Adopt{cocoon::internal::retain([[::NSURLRequest alloc] initWithURL:cocoon::internal::native<::NSURL>(url)])})
    {
    }

    URLRequest::URLRequest(const URL& url, URLRequestCachePolicy cache_policy, double timeout_interval) : URLRequest(Adopt{cocoon::internal::retain([[::NSURLRequest alloc] initWithURL:cocoon::internal::native<::NSURL>(url) cachePolicy:static_cast<::NSURLRequestCachePolicy>(cache_policy) timeoutInterval:static_cast<::NSTimeInterval>(timeout_interval)])})
    {
    }

    URLRequest::URLRequest() : URLRequest(Adopt{cocoon::internal::retain([[::NSURLRequest alloc] init])})
    {
    }

    URLRequest::URLRequest(std::nullptr_t) : Object(nullptr)
    {
    }

    URLRequest::URLRequest(Adopt adopt) : Object(adopt)
    {
    }

    URLRequest URLRequest::request_with_url(const URL& url)
    {
        return cocoon::internal::wrap<URLRequest>([::NSURLRequest requestWithURL:cocoon::internal::native<::NSURL>(url)]);
    }

    URLRequest URLRequest::request_with_url(const URL& url, URLRequestCachePolicy cache_policy, double timeout_interval)
    {
        return cocoon::internal::wrap<URLRequest>([::NSURLRequest requestWithURL:cocoon::internal::native<::NSURL>(url) cachePolicy:static_cast<::NSURLRequestCachePolicy>(cache_policy) timeoutInterval:static_cast<::NSTimeInterval>(timeout_interval)]);
    }

    std::string URLRequest::value_for_http_header_field(const std::string& field) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLRequest>(this) valueForHTTPHeaderField:cocoon::internal::to(field)]);
    }

    std::vector<std::uint8_t> URLRequest::http_body() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSURLRequest>(this) HTTPBody]);
    }

    InputStream URLRequest::http_body_stream() const
    {
        return cocoon::internal::wrap<InputStream>([cocoon::internal::ns<::NSURLRequest>(this) HTTPBodyStream]);
    }

    std::string URLRequest::http_method() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLRequest>(this) HTTPMethod]);
    }

    bool URLRequest::http_should_handle_cookies() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLRequest>(this) HTTPShouldHandleCookies]);
    }

    URL URLRequest::url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSURLRequest>(this) URL]);
    }

    std::map<std::string, std::string> URLRequest::all_http_header_fields() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, std::string>>([cocoon::internal::ns<::NSURLRequest>(this) allHTTPHeaderFields], [](id k) -> std::string
                                                                       {
                                                                           return cocoon::internal::from((NSString*)k);
                                                                       },
                                                                       [](id v) -> std::string
                                                                       {
                                                                           return cocoon::internal::from((NSString*)v);
                                                                       });
    }

    bool URLRequest::allows_cellular_access() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLRequest>(this) allowsCellularAccess]);
    }

    bool URLRequest::allows_constrained_network_access() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLRequest>(this) allowsConstrainedNetworkAccess]);
    }

    bool URLRequest::allows_expensive_network_access() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLRequest>(this) allowsExpensiveNetworkAccess]);
    }

    bool URLRequest::allows_persistent_dns() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLRequest>(this) allowsPersistentDNS]);
    }

    bool URLRequest::allows_ultra_constrained_network_access() const
    {
        if (@available(macOS 26.1, *))
        {
            return static_cast<bool>([cocoon::internal::ns<::NSURLRequest>(this) allowsUltraConstrainedNetworkAccess]);
        }
        return {};
    }

    bool URLRequest::assumes_http3_capable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLRequest>(this) assumesHTTP3Capable]);
    }

    URLRequestAttribution URLRequest::attribution() const
    {
        return static_cast<URLRequestAttribution>([cocoon::internal::ns<::NSURLRequest>(this) attribution]);
    }

    URLRequestCachePolicy URLRequest::cache_policy() const
    {
        return static_cast<URLRequestCachePolicy>([cocoon::internal::ns<::NSURLRequest>(this) cachePolicy]);
    }

    std::string URLRequest::cookie_partition_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLRequest>(this) cookiePartitionIdentifier]);
    }

    URL URLRequest::main_document_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSURLRequest>(this) mainDocumentURL]);
    }

    URLRequestNetworkServiceType URLRequest::network_service_type() const
    {
        return static_cast<URLRequestNetworkServiceType>([cocoon::internal::ns<::NSURLRequest>(this) networkServiceType]);
    }

    bool URLRequest::requires_dnssec_validation() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLRequest>(this) requiresDNSSECValidation]);
    }

    bool URLRequest::supports_secure_coding()
    {
        return static_cast<bool>([::NSURLRequest supportsSecureCoding]);
    }

    double URLRequest::timeout_interval() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSURLRequest>(this) timeoutInterval]);
    }
}
