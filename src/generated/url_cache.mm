#include "generated/url_cache.h"
#include "internal.h"

namespace cocoon
{
    URLCache::URLCache(std::uint64_t memory_capacity, std::uint64_t disk_capacity, const URL& directory_url) : URLCache(Adopt{cocoon::internal::retain([[::NSURLCache alloc] initWithMemoryCapacity:static_cast<::NSUInteger>(memory_capacity) diskCapacity:static_cast<::NSUInteger>(disk_capacity) directoryURL:cocoon::internal::native<::NSURL>(directory_url)])})
    {
    }

    URLCache::URLCache(std::uint64_t memory_capacity, std::uint64_t disk_capacity, const std::string& path) : URLCache(Adopt{cocoon::internal::retain([[::NSURLCache alloc] initWithMemoryCapacity:static_cast<::NSUInteger>(memory_capacity) diskCapacity:static_cast<::NSUInteger>(disk_capacity) diskPath:cocoon::internal::to(path)])})
    {
    }

    URLCache::URLCache() : URLCache(Adopt{cocoon::internal::retain([[::NSURLCache alloc] init])})
    {
    }

    URLCache::URLCache(std::nullptr_t) : Object(nullptr)
    {
    }

    URLCache::URLCache(Adopt adopt) : Object(adopt)
    {
    }

    CachedURLResponse URLCache::cached_response_for_request(const URLRequest& request) const
    {
        return cocoon::internal::wrap<CachedURLResponse>([cocoon::internal::ns<::NSURLCache>(this) cachedResponseForRequest:cocoon::internal::native<::NSURLRequest>(request)]);
    }

    void URLCache::get_cached_response_for_data_task(const URLSessionDataTask& data_task, std::function<void(CachedURLResponse)> completion_handler) const
    {
        [cocoon::internal::ns<::NSURLCache>(this) getCachedResponseForDataTask:cocoon::internal::native<::NSURLSessionDataTask>(data_task) completionHandler:(completion_handler ? (void (^)(::NSCachedURLResponse*)) ^ void(::NSCachedURLResponse * a228_0) { completion_handler(cocoon::internal::wrap<CachedURLResponse>(a228_0)); } : (void (^)(::NSCachedURLResponse*))nil)];
    }

    void URLCache::remove_all_cached_responses() const
    {
        [cocoon::internal::ns<::NSURLCache>(this) removeAllCachedResponses];
    }

    void URLCache::remove_cached_response_for_data_task(const URLSessionDataTask& data_task) const
    {
        [cocoon::internal::ns<::NSURLCache>(this) removeCachedResponseForDataTask:cocoon::internal::native<::NSURLSessionDataTask>(data_task)];
    }

    void URLCache::remove_cached_response_for_request(const URLRequest& request) const
    {
        [cocoon::internal::ns<::NSURLCache>(this) removeCachedResponseForRequest:cocoon::internal::native<::NSURLRequest>(request)];
    }

    void URLCache::remove_cached_responses_since_date(const Date& date) const
    {
        [cocoon::internal::ns<::NSURLCache>(this) removeCachedResponsesSinceDate:cocoon::internal::native<::NSDate>(date)];
    }

    void URLCache::store_cached_response(const CachedURLResponse& cached_response, const URLSessionDataTask& data_task) const
    {
        [cocoon::internal::ns<::NSURLCache>(this) storeCachedResponse:cocoon::internal::native<::NSCachedURLResponse>(cached_response) forDataTask:cocoon::internal::native<::NSURLSessionDataTask>(data_task)];
    }

    void URLCache::store_cached_response(const CachedURLResponse& cached_response, const URLRequest& request) const
    {
        [cocoon::internal::ns<::NSURLCache>(this) storeCachedResponse:cocoon::internal::native<::NSCachedURLResponse>(cached_response) forRequest:cocoon::internal::native<::NSURLRequest>(request)];
    }

    std::uint64_t URLCache::current_disk_usage() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSURLCache>(this) currentDiskUsage]);
    }

    std::uint64_t URLCache::current_memory_usage() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSURLCache>(this) currentMemoryUsage]);
    }

    std::uint64_t URLCache::disk_capacity() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSURLCache>(this) diskCapacity]);
    }

    void URLCache::set_disk_capacity(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSURLCache>(this) setDiskCapacity:static_cast<::NSUInteger>(value)];
    }

    std::uint64_t URLCache::memory_capacity() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSURLCache>(this) memoryCapacity]);
    }

    void URLCache::set_memory_capacity(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSURLCache>(this) setMemoryCapacity:static_cast<::NSUInteger>(value)];
    }

    URLCache URLCache::shared_url_cache()
    {
        return cocoon::internal::wrap<URLCache>([::NSURLCache sharedURLCache]);
    }

    void URLCache::set_shared_url_cache(const URLCache& value)
    {
        [::NSURLCache setSharedURLCache:cocoon::internal::native<::NSURLCache>(value)];
    }
}
