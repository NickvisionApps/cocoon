#include "generated/url_query_item.h"
#include "internal.h"

namespace cocoon
{
    URLQueryItem::URLQueryItem(const std::string& name, const std::string& value) : URLQueryItem(Adopt{cocoon::internal::retain([[::NSURLQueryItem alloc] initWithName:cocoon::internal::to(name) value:cocoon::internal::to(value)])})
    {
    }

    URLQueryItem::URLQueryItem() : URLQueryItem(Adopt{cocoon::internal::retain([[::NSURLQueryItem alloc] init])})
    {
    }

    URLQueryItem::URLQueryItem(std::nullptr_t) : Object(nullptr)
    {
    }

    URLQueryItem::URLQueryItem(Adopt adopt) : Object(adopt)
    {
    }

    URLQueryItem URLQueryItem::query_item_with_name(const std::string& name, const std::string& value)
    {
        return cocoon::internal::wrap<URLQueryItem>([::NSURLQueryItem queryItemWithName:cocoon::internal::to(name) value:cocoon::internal::to(value)]);
    }

    std::string URLQueryItem::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLQueryItem>(this) name]);
    }

    std::string URLQueryItem::value() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLQueryItem>(this) value]);
    }
}
