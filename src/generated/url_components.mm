#include "generated/url_components.h"
#include "internal.h"

namespace cocoon
{
    URLComponents::URLComponents(const std::string& url_string) : URLComponents(Adopt{cocoon::internal::retain([[::NSURLComponents alloc] initWithString:cocoon::internal::to(url_string)])})
    {
    }

    URLComponents::URLComponents(const std::string& url_string, bool encoding_invalid_characters) : URLComponents(Adopt{cocoon::internal::retain([[::NSURLComponents alloc] initWithString:cocoon::internal::to(url_string) encodingInvalidCharacters:static_cast<::BOOL>(encoding_invalid_characters)])})
    {
    }

    URLComponents::URLComponents(const URL& url, bool resolve) : URLComponents(Adopt{cocoon::internal::retain([[::NSURLComponents alloc] initWithURL:cocoon::internal::native<::NSURL>(url) resolvingAgainstBaseURL:static_cast<::BOOL>(resolve)])})
    {
    }

    URLComponents::URLComponents() : URLComponents(Adopt{cocoon::internal::retain([[::NSURLComponents alloc] init])})
    {
    }

    URLComponents::URLComponents(std::nullptr_t) : Object(nullptr)
    {
    }

    URLComponents::URLComponents(Adopt adopt) : Object(adopt)
    {
    }

    URL URLComponents::url_relative_to_url(const URL& base_url) const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSURLComponents>(this) URLRelativeToURL:cocoon::internal::native<::NSURL>(base_url)]);
    }

    URLComponents URLComponents::components_with_string(const std::string& url_string)
    {
        return cocoon::internal::wrap<URLComponents>([::NSURLComponents componentsWithString:cocoon::internal::to(url_string)]);
    }

    URLComponents URLComponents::components_with_string(const std::string& url_string, bool encoding_invalid_characters)
    {
        return cocoon::internal::wrap<URLComponents>([::NSURLComponents componentsWithString:cocoon::internal::to(url_string) encodingInvalidCharacters:static_cast<::BOOL>(encoding_invalid_characters)]);
    }

    URLComponents URLComponents::components_with_url(const URL& url, bool resolve)
    {
        return cocoon::internal::wrap<URLComponents>([::NSURLComponents componentsWithURL:cocoon::internal::native<::NSURL>(url) resolvingAgainstBaseURL:static_cast<::BOOL>(resolve)]);
    }

    URL URLComponents::url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSURLComponents>(this) URL]);
    }

    std::string URLComponents::encoded_host() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) encodedHost]);
    }

    void URLComponents::set_encoded_host(const std::string& value) const
    {
        [cocoon::internal::ns<::NSURLComponents>(this) setEncodedHost:cocoon::internal::to(value)];
    }

    std::string URLComponents::fragment() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) fragment]);
    }

    void URLComponents::set_fragment(const std::string& value) const
    {
        [cocoon::internal::ns<::NSURLComponents>(this) setFragment:cocoon::internal::to(value)];
    }

    std::string URLComponents::host() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) host]);
    }

    void URLComponents::set_host(const std::string& value) const
    {
        [cocoon::internal::ns<::NSURLComponents>(this) setHost:cocoon::internal::to(value)];
    }

    std::string URLComponents::password() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) password]);
    }

    void URLComponents::set_password(const std::string& value) const
    {
        [cocoon::internal::ns<::NSURLComponents>(this) setPassword:cocoon::internal::to(value)];
    }

    std::string URLComponents::path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) path]);
    }

    void URLComponents::set_path(const std::string& value) const
    {
        [cocoon::internal::ns<::NSURLComponents>(this) setPath:cocoon::internal::to(value)];
    }

    std::string URLComponents::percent_encoded_fragment() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) percentEncodedFragment]);
    }

    void URLComponents::set_percent_encoded_fragment(const std::string& value) const
    {
        [cocoon::internal::ns<::NSURLComponents>(this) setPercentEncodedFragment:cocoon::internal::to(value)];
    }

    std::string URLComponents::percent_encoded_host() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) percentEncodedHost]);
    }

    void URLComponents::set_percent_encoded_host(const std::string& value) const
    {
        [cocoon::internal::ns<::NSURLComponents>(this) setPercentEncodedHost:cocoon::internal::to(value)];
    }

    std::string URLComponents::percent_encoded_password() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) percentEncodedPassword]);
    }

    void URLComponents::set_percent_encoded_password(const std::string& value) const
    {
        [cocoon::internal::ns<::NSURLComponents>(this) setPercentEncodedPassword:cocoon::internal::to(value)];
    }

    std::string URLComponents::percent_encoded_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) percentEncodedPath]);
    }

    void URLComponents::set_percent_encoded_path(const std::string& value) const
    {
        [cocoon::internal::ns<::NSURLComponents>(this) setPercentEncodedPath:cocoon::internal::to(value)];
    }

    std::string URLComponents::percent_encoded_query() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) percentEncodedQuery]);
    }

    void URLComponents::set_percent_encoded_query(const std::string& value) const
    {
        [cocoon::internal::ns<::NSURLComponents>(this) setPercentEncodedQuery:cocoon::internal::to(value)];
    }

    std::vector<URLQueryItem> URLComponents::percent_encoded_query_items() const
    {
        return cocoon::internal::from_array<URLQueryItem>([cocoon::internal::ns<::NSURLComponents>(this) percentEncodedQueryItems], [](id e) -> URLQueryItem
                                                          {
                                                              return cocoon::internal::wrap<URLQueryItem>((::NSURLQueryItem*)e);
                                                          });
    }

    void URLComponents::set_percent_encoded_query_items(const std::vector<URLQueryItem>& value) const
    {
        [cocoon::internal::ns<::NSURLComponents>(this) setPercentEncodedQueryItems:cocoon::internal::to_array(value, [](const URLQueryItem& e) -> id
                                                                                                              {
                                                                                                                  return cocoon::internal::native<::NSURLQueryItem>(e);
                                                                                                              })];
    }

    std::string URLComponents::percent_encoded_user() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) percentEncodedUser]);
    }

    void URLComponents::set_percent_encoded_user(const std::string& value) const
    {
        [cocoon::internal::ns<::NSURLComponents>(this) setPercentEncodedUser:cocoon::internal::to(value)];
    }

    Number URLComponents::port() const
    {
        return cocoon::internal::wrap<Number>([cocoon::internal::ns<::NSURLComponents>(this) port]);
    }

    void URLComponents::set_port(const Number& value) const
    {
        [cocoon::internal::ns<::NSURLComponents>(this) setPort:cocoon::internal::native<::NSNumber>(value)];
    }

    std::string URLComponents::query() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) query]);
    }

    void URLComponents::set_query(const std::string& value) const
    {
        [cocoon::internal::ns<::NSURLComponents>(this) setQuery:cocoon::internal::to(value)];
    }

    std::vector<URLQueryItem> URLComponents::query_items() const
    {
        return cocoon::internal::from_array<URLQueryItem>([cocoon::internal::ns<::NSURLComponents>(this) queryItems], [](id e) -> URLQueryItem
                                                          {
                                                              return cocoon::internal::wrap<URLQueryItem>((::NSURLQueryItem*)e);
                                                          });
    }

    void URLComponents::set_query_items(const std::vector<URLQueryItem>& value) const
    {
        [cocoon::internal::ns<::NSURLComponents>(this) setQueryItems:cocoon::internal::to_array(value, [](const URLQueryItem& e) -> id
                                                                                                {
                                                                                                    return cocoon::internal::native<::NSURLQueryItem>(e);
                                                                                                })];
    }

    Range URLComponents::range_of_fragment() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) rangeOfFragment]);
    }

    Range URLComponents::range_of_host() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) rangeOfHost]);
    }

    Range URLComponents::range_of_password() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) rangeOfPassword]);
    }

    Range URLComponents::range_of_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) rangeOfPath]);
    }

    Range URLComponents::range_of_port() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) rangeOfPort]);
    }

    Range URLComponents::range_of_query() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) rangeOfQuery]);
    }

    Range URLComponents::range_of_scheme() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) rangeOfScheme]);
    }

    Range URLComponents::range_of_user() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) rangeOfUser]);
    }

    std::string URLComponents::scheme() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) scheme]);
    }

    void URLComponents::set_scheme(const std::string& value) const
    {
        [cocoon::internal::ns<::NSURLComponents>(this) setScheme:cocoon::internal::to(value)];
    }

    std::string URLComponents::string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) string]);
    }

    std::string URLComponents::user() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLComponents>(this) user]);
    }

    void URLComponents::set_user(const std::string& value) const
    {
        [cocoon::internal::ns<::NSURLComponents>(this) setUser:cocoon::internal::to(value)];
    }
}
