#include "generated/url_protocol.h"
#include "internal.h"

namespace cocoon
{
    URLProtocol::URLProtocol(const URLRequest& request, const CachedURLResponse& cached_response, const Object& client) : URLProtocol(Adopt{cocoon::internal::retain([[::NSURLProtocol alloc] initWithRequest:cocoon::internal::native<::NSURLRequest>(request) cachedResponse:cocoon::internal::native<::NSCachedURLResponse>(cached_response) client:cocoon::internal::native_id(client)])})
    {
    }

    URLProtocol::URLProtocol(const URLSessionTask& task, const CachedURLResponse& cached_response, const Object& client) : URLProtocol(Adopt{cocoon::internal::retain([[::NSURLProtocol alloc] initWithTask:cocoon::internal::native<::NSURLSessionTask>(task) cachedResponse:cocoon::internal::native<::NSCachedURLResponse>(cached_response) client:cocoon::internal::native_id(client)])})
    {
    }

    URLProtocol::URLProtocol() : URLProtocol(Adopt{cocoon::internal::retain([[::NSURLProtocol alloc] init])})
    {
    }

    URLProtocol::URLProtocol(std::nullptr_t) : Object(nullptr)
    {
    }

    URLProtocol::URLProtocol(Adopt adopt) : Object(adopt)
    {
    }

    bool URLProtocol::can_init_with_request(const URLRequest& request)
    {
        return static_cast<bool>([::NSURLProtocol canInitWithRequest:cocoon::internal::native<::NSURLRequest>(request)]);
    }

    bool URLProtocol::can_init_with_task(const URLSessionTask& task)
    {
        return static_cast<bool>([::NSURLProtocol canInitWithTask:cocoon::internal::native<::NSURLSessionTask>(task)]);
    }

    URLRequest URLProtocol::canonical_request_for_request(const URLRequest& request)
    {
        return cocoon::internal::wrap<URLRequest>([::NSURLProtocol canonicalRequestForRequest:cocoon::internal::native<::NSURLRequest>(request)]);
    }

    Object URLProtocol::property_for_key(const std::string& key, const URLRequest& request)
    {
        return cocoon::internal::wrap<Object>([::NSURLProtocol propertyForKey:cocoon::internal::to(key) inRequest:cocoon::internal::native<::NSURLRequest>(request)]);
    }

    bool URLProtocol::register_class(const std::string& protocol_class)
    {
        return static_cast<bool>([::NSURLProtocol registerClass:NSClassFromString(cocoon::internal::to(protocol_class))]);
    }

    void URLProtocol::remove_property_for_key(const std::string& key, const MutableURLRequest& request)
    {
        [::NSURLProtocol removePropertyForKey:cocoon::internal::to(key) inRequest:cocoon::internal::native<::NSMutableURLRequest>(request)];
    }

    bool URLProtocol::request_is_cache_equivalent(const URLRequest& a, const URLRequest& b)
    {
        return static_cast<bool>([::NSURLProtocol requestIsCacheEquivalent:cocoon::internal::native<::NSURLRequest>(a) toRequest:cocoon::internal::native<::NSURLRequest>(b)]);
    }

    void URLProtocol::set_property(const Object& value, const std::string& key, const MutableURLRequest& request)
    {
        [::NSURLProtocol setProperty:cocoon::internal::native_id(value) forKey:cocoon::internal::to(key) inRequest:cocoon::internal::native<::NSMutableURLRequest>(request)];
    }

    void URLProtocol::start_loading() const
    {
        [cocoon::internal::ns<::NSURLProtocol>(this) startLoading];
    }

    void URLProtocol::stop_loading() const
    {
        [cocoon::internal::ns<::NSURLProtocol>(this) stopLoading];
    }

    void URLProtocol::unregister_class(const std::string& protocol_class)
    {
        [::NSURLProtocol unregisterClass:NSClassFromString(cocoon::internal::to(protocol_class))];
    }

    CachedURLResponse URLProtocol::cached_response() const
    {
        return cocoon::internal::wrap<CachedURLResponse>([cocoon::internal::ns<::NSURLProtocol>(this) cachedResponse]);
    }

    URLRequest URLProtocol::request() const
    {
        return cocoon::internal::wrap<URLRequest>([cocoon::internal::ns<::NSURLProtocol>(this) request]);
    }

    URLSessionTask URLProtocol::task() const
    {
        return cocoon::internal::wrap<URLSessionTask>([cocoon::internal::ns<::NSURLProtocol>(this) task]);
    }
}
