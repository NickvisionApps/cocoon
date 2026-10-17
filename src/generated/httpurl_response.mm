#include "generated/httpurl_response.h"
#include "internal.h"

namespace cocoon
{
    HTTPURLResponse::HTTPURLResponse(const URL& url, std::int64_t status_code, const std::string& http_version, const std::map<std::string, std::string>& header_fields) : HTTPURLResponse(Adopt{cocoon::internal::retain([[::NSHTTPURLResponse alloc] initWithURL:cocoon::internal::native<::NSURL>(url)
                                                                                                                                                                                                                                                        statusCode:static_cast<::NSInteger>(status_code)
                                                                                                                                                                                                                                                       HTTPVersion:cocoon::internal::to(http_version)
                                                                                                                                                                                                                                                      headerFields:cocoon::internal::to_dictionary(header_fields, [](const std::string& k) -> id
                                                                                                                                                                                                                                                                                                   {
                                                                                                                                                                                                                                                                                                       return cocoon::internal::to(k);
                                                                                                                                                                                                                                                                                                   },
                                                                                                                                                                                                                                                                                                   [](const std::string& v) -> id
                                                                                                                                                                                                                                                                                                   {
                                                                                                                                                                                                                                                                                                       return cocoon::internal::to(v);
                                                                                                                                                                                                                                                                                                   })])})
    {
    }

    HTTPURLResponse::HTTPURLResponse() : HTTPURLResponse(Adopt{cocoon::internal::retain([[::NSHTTPURLResponse alloc] init])})
    {
    }

    HTTPURLResponse::HTTPURLResponse(std::nullptr_t) : URLResponse(nullptr)
    {
    }

    HTTPURLResponse::HTTPURLResponse(Adopt adopt) : URLResponse(adopt)
    {
    }

    std::string HTTPURLResponse::localized_string_for_status_code(std::int64_t status_code)
    {
        return cocoon::internal::from([::NSHTTPURLResponse localizedStringForStatusCode:static_cast<::NSInteger>(status_code)]);
    }

    std::string HTTPURLResponse::value_for_http_header_field(const std::string& field) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSHTTPURLResponse>(this) valueForHTTPHeaderField:cocoon::internal::to(field)]);
    }

    std::vector<std::pair<Object, Object>> HTTPURLResponse::all_header_fields() const
    {
        return cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>([cocoon::internal::ns<::NSHTTPURLResponse>(this) allHeaderFields], [](id k) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(k);
                                                                                         },
                                                                                         [](id v) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(v);
                                                                                         });
    }

    std::int64_t HTTPURLResponse::status_code() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSHTTPURLResponse>(this) statusCode]);
    }
}
