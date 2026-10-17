#include "generated/url_response.h"
#include "internal.h"

namespace cocoon
{
    URLResponse::URLResponse(const URL& url, const std::string& mime_type, std::int64_t length, const std::string& name) : URLResponse(Adopt{cocoon::internal::retain([[::NSURLResponse alloc] initWithURL:cocoon::internal::native<::NSURL>(url) MIMEType:cocoon::internal::to(mime_type) expectedContentLength:static_cast<::NSInteger>(length) textEncodingName:cocoon::internal::to(name)])})
    {
    }

    URLResponse::URLResponse() : URLResponse(Adopt{cocoon::internal::retain([[::NSURLResponse alloc] init])})
    {
    }

    URLResponse::URLResponse(std::nullptr_t) : Object(nullptr)
    {
    }

    URLResponse::URLResponse(Adopt adopt) : Object(adopt)
    {
    }

    std::string URLResponse::mime_type() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLResponse>(this) MIMEType]);
    }

    URL URLResponse::url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSURLResponse>(this) URL]);
    }

    std::int64_t URLResponse::expected_content_length() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSURLResponse>(this) expectedContentLength]);
    }

    std::string URLResponse::suggested_filename() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLResponse>(this) suggestedFilename]);
    }

    std::string URLResponse::text_encoding_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLResponse>(this) textEncodingName]);
    }
}
