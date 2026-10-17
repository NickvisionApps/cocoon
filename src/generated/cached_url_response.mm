#include "generated/cached_url_response.h"
#include "internal.h"

namespace cocoon
{
    CachedURLResponse::CachedURLResponse(const URLResponse& response, const std::vector<std::uint8_t>& data) : CachedURLResponse(Adopt{cocoon::internal::retain([[::NSCachedURLResponse alloc] initWithResponse:cocoon::internal::native<::NSURLResponse>(response) data:cocoon::internal::to_data(data)])})
    {
    }

    CachedURLResponse::CachedURLResponse(const URLResponse& response, const std::vector<std::uint8_t>& data, const std::vector<std::pair<Object, Object>>& user_info, URLCacheStoragePolicy storage_policy) : CachedURLResponse(Adopt{cocoon::internal::retain([[::NSCachedURLResponse alloc] initWithResponse:cocoon::internal::native<::NSURLResponse>(response)
                                                                                                                                                                                                                                                                                                          data:cocoon::internal::to_data(data)
                                                                                                                                                                                                                                                                                                      userInfo:cocoon::internal::to_dictionary(user_info, [](const Object& k) -> id
                                                                                                                                                                                                                                                                                                                                               {
                                                                                                                                                                                                                                                                                                                                                   return cocoon::internal::native_id(k);
                                                                                                                                                                                                                                                                                                                                               },
                                                                                                                                                                                                                                                                                                                                               [](const Object& v) -> id
                                                                                                                                                                                                                                                                                                                                               {
                                                                                                                                                                                                                                                                                                                                                   return cocoon::internal::native_id(v);
                                                                                                                                                                                                                                                                                                                                               })
                                                                                                                                                                                                                                                                                                 storagePolicy:static_cast<::NSURLCacheStoragePolicy>(storage_policy)])})
    {
    }

    CachedURLResponse::CachedURLResponse() : CachedURLResponse(Adopt{cocoon::internal::retain([[::NSCachedURLResponse alloc] init])})
    {
    }

    CachedURLResponse::CachedURLResponse(std::nullptr_t) : Object(nullptr)
    {
    }

    CachedURLResponse::CachedURLResponse(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<std::uint8_t> CachedURLResponse::data() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSCachedURLResponse>(this) data]);
    }

    URLResponse CachedURLResponse::response() const
    {
        return cocoon::internal::wrap<URLResponse>([cocoon::internal::ns<::NSCachedURLResponse>(this) response]);
    }

    URLCacheStoragePolicy CachedURLResponse::storage_policy() const
    {
        return static_cast<URLCacheStoragePolicy>([cocoon::internal::ns<::NSCachedURLResponse>(this) storagePolicy]);
    }

    std::vector<std::pair<Object, Object>> CachedURLResponse::user_info() const
    {
        return cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>([cocoon::internal::ns<::NSCachedURLResponse>(this) userInfo], [](id k) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(k);
                                                                                         },
                                                                                         [](id v) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(v);
                                                                                         });
    }
}
