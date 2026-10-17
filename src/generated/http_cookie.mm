#include "generated/http_cookie.h"
#include "internal.h"

namespace cocoon
{
    HTTPCookie::HTTPCookie(const std::map<std::string, Object>& properties) : HTTPCookie(Adopt{cocoon::internal::retain([[::NSHTTPCookie alloc] initWithProperties:cocoon::internal::to_dictionary(properties, [](const std::string& k) -> id
                                                                                                                                                                                                   {
                                                                                                                                                                                                       return cocoon::internal::to(k);
                                                                                                                                                                                                   },
                                                                                                                                                                                                   [](const Object& v) -> id
                                                                                                                                                                                                   {
                                                                                                                                                                                                       return cocoon::internal::native_id(v);
                                                                                                                                                                                                   })])})
    {
    }

    HTTPCookie::HTTPCookie() : HTTPCookie(Adopt{cocoon::internal::retain([[::NSHTTPCookie alloc] init])})
    {
    }

    HTTPCookie::HTTPCookie(std::nullptr_t) : Object(nullptr)
    {
    }

    HTTPCookie::HTTPCookie(Adopt adopt) : Object(adopt)
    {
    }

    HTTPCookie HTTPCookie::cookie_with_properties(const std::map<std::string, Object>& properties)
    {
        return cocoon::internal::wrap<HTTPCookie>([::NSHTTPCookie cookieWithProperties:cocoon::internal::to_dictionary(properties, [](const std::string& k) -> id
                                                                                                                       {
                                                                                                                           return cocoon::internal::to(k);
                                                                                                                       },
                                                                                                                       [](const Object& v) -> id
                                                                                                                       {
                                                                                                                           return cocoon::internal::native_id(v);
                                                                                                                       })]);
    }

    std::vector<HTTPCookie> HTTPCookie::cookies_with_response_header_fields(const std::map<std::string, std::string>& header_fields, const URL& url)
    {
        return cocoon::internal::from_array<HTTPCookie>([::NSHTTPCookie cookiesWithResponseHeaderFields:cocoon::internal::to_dictionary(header_fields, [](const std::string& k) -> id
                                                                                                                                        {
                                                                                                                                            return cocoon::internal::to(k);
                                                                                                                                        },
                                                                                                                                        [](const std::string& v) -> id
                                                                                                                                        {
                                                                                                                                            return cocoon::internal::to(v);
                                                                                                                                        })
                                                                                                 forURL:cocoon::internal::native<::NSURL>(url)],
                                                        [](id e) -> HTTPCookie
                                                        {
                                                            return cocoon::internal::wrap<HTTPCookie>((::NSHTTPCookie*)e);
                                                        });
    }

    std::map<std::string, std::string> HTTPCookie::request_header_fields_with_cookies(const std::vector<HTTPCookie>& cookies)
    {
        return cocoon::internal::from_dictionary<std::map<std::string, std::string>>([::NSHTTPCookie requestHeaderFieldsWithCookies:cocoon::internal::to_array(cookies, [](const HTTPCookie& e) -> id
                                                                                                                                                               {
                                                                                                                                                                   return cocoon::internal::native<::NSHTTPCookie>(e);
                                                                                                                                                               })],
                                                                                     [](id k) -> std::string
                                                                                     {
                                                                                         return cocoon::internal::from((NSString*)k);
                                                                                     },
                                                                                     [](id v) -> std::string
                                                                                     {
                                                                                         return cocoon::internal::from((NSString*)v);
                                                                                     });
    }

    bool HTTPCookie::is_http_only() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSHTTPCookie>(this) isHTTPOnly]);
    }

    std::string HTTPCookie::comment() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSHTTPCookie>(this) comment]);
    }

    URL HTTPCookie::comment_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSHTTPCookie>(this) commentURL]);
    }

    std::string HTTPCookie::domain() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSHTTPCookie>(this) domain]);
    }

    Date HTTPCookie::expires_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSHTTPCookie>(this) expiresDate]);
    }

    std::string HTTPCookie::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSHTTPCookie>(this) name]);
    }

    std::string HTTPCookie::path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSHTTPCookie>(this) path]);
    }

    std::vector<Number> HTTPCookie::port_list() const
    {
        return cocoon::internal::from_array<Number>([cocoon::internal::ns<::NSHTTPCookie>(this) portList], [](id e) -> Number
                                                    {
                                                        return cocoon::internal::wrap<Number>((::NSNumber*)e);
                                                    });
    }

    std::map<std::string, Object> HTTPCookie::properties() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSHTTPCookie>(this) properties], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    std::string HTTPCookie::same_site_policy() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSHTTPCookie>(this) sameSitePolicy]);
    }

    bool HTTPCookie::is_secure() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSHTTPCookie>(this) isSecure]);
    }

    bool HTTPCookie::is_session_only() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSHTTPCookie>(this) isSessionOnly]);
    }

    std::string HTTPCookie::value() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSHTTPCookie>(this) value]);
    }

    std::uint64_t HTTPCookie::version() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSHTTPCookie>(this) version]);
    }
}
