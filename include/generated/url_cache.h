#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CachedURLResponse;
    class Date;
    class URL;
    class URLRequest;
    class URLSessionDataTask;

    /**
     * @brief C++ handle for the Objective-C class `NSURLCache` (Foundation).
     * @details An object that maps URL requests to cached response objects. The ''URLCache'' class implements the caching of responses to URL load requests, by mapping ''NSURLRequest'' objects to ''CachedURLResponse'' objects. It provides a composite in-memory and on-disk cache, and lets you manipulate the sizes of both the in-memory and on-disk portions. You can also control the path where cache data is persistently stored. > Note: > In iOS, the on-disk cache may be purged when the system runs low on disk space, but only when your app is not running. \#\#\# Thread safety In iOS 8 and later, and macOS 10.10 and later, ''URLCache'' is thread safe. Although ''URLCache'' instance methods can safely be called from multiple execution contexts at the same time, be aware that methods like ''cachedResponse(for:)'' and ''storeCachedResponse(:for:)-7p7bl'' have an unavoidable race condition when attempting to read or write responses for the same request. Subclasses of ''URLCache'' must implement overridden methods in such a thread-safe manner. \#\#\# Subclassing notes The ''URLCache'' class is meant to be used as-is, but you can subclass it when you have specific needs. For example, you might want to screen which responses are cached, or reimplement the storage mechanism for security or other reasons. When overriding methods of this class, be aware that methods that take a 'task' parameter are preferred by the system to those that do not. Therefore, you should override the task-based methods when subclassing, as follows: - Storing responses in the cache — Override the task-based ''storeCachedResponse(:for:)-8uq91'', instead of or in addition to the request-based ''storeCachedResponse(:for:)-7p7bl''. - Getting responses from the cache — Override ''getCachedResponse(for:completionHandler:)'', instead of or in addition to ''cachedResponse(for:)''. - Removing cached responses — Override the task-based ''removeCachedResponse(for:)-1zwp6'', instead of or in addition to the request-based ''removeCachedResponse(for:)-1dh89''.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLCache url_cache;
     * url_cache.set_disk_capacity(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::URLCache url_cache{};
     * url_cache.set_disk_capacity(1);
     * auto disk_capacity = url_cache.disk_capacity();
     * url_cache.set_memory_capacity(1);
     * auto memory_capacity = url_cache.memory_capacity();
     * url_cache.set_shared_url_cache(cocoon::URLCache());
     * auto shared_url_cache = url_cache.shared_url_cache();
     * url_cache.cached_response_for_request(cocoon::URLRequest());
     * url_cache.remove_all_cached_responses();
     * url_cache.remove_cached_response_for_data_task(cocoon::URLSessionDataTask());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlcache
     */
    class URLCache : public Object
    {
    public:
        /// @brief Creates a new `NSURLCache` instance and returns a handle to it.
        explicit URLCache(std::uint64_t memory_capacity, std::uint64_t disk_capacity, const URL& directory_url);
        /// @brief Creates a new `NSURLCache` instance and returns a handle to it.
        explicit URLCache(std::uint64_t memory_capacity, std::uint64_t disk_capacity, const std::string& path);
        /// @brief Creates a new `NSURLCache` instance and returns a handle to it.
        explicit URLCache();
        /// @brief Creates a null handle that refers to no native object.
        URLCache(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLCache(Adopt adopt);
        /**
         * @brief Calls `-[NSURLCache cachedResponseForRequest:]`.
         * @details Returns the cached URL response in the cache for the specified URL request. Returns 'nil' if there is no 'NSCachedURLResponse' stored using the given request. - Parameter request: The 'NSURLRequest' to use as a key for the lookup. - Returns: The 'NSCachedURLResponse' stored in the cache with the given request, or 'nil' if there is no cached response.
         * @param request Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        CachedURLResponse cached_response_for_request(const URLRequest& request) const;
        /**
         * @brief Calls `-[NSURLCache getCachedResponseForDataTask:completionHandler:]`.
         * @details Gets the cached URL response for a specified data task, passing it to a completion handler.
         * @param data_task Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void get_cached_response_for_data_task(const URLSessionDataTask& data_task, std::function<void(CachedURLResponse)> completion_handler) const;
        /**
         * @brief Calls `-[NSURLCache removeAllCachedResponses]`.
         * @details Clears the cache, removing all 'NSCachedURLResponse' objects that it stores.
         */
        void remove_all_cached_responses() const;
        /**
         * @brief Calls `-[NSURLCache removeCachedResponseForDataTask:]`.
         * @details Removes the cached URL response for a specified data task.
         * @param data_task Argument converted to the Objective-C parameter of the same role.
         */
        void remove_cached_response_for_data_task(const URLSessionDataTask& data_task) const;
        /**
         * @brief Calls `-[NSURLCache removeCachedResponseForRequest:]`.
         * @details Removes the cached URL response for a specified request. No action is taken if there is no 'NSCachedURLResponse' stored with the given request. - Parameter request: The 'NSURLRequest' to use as a key for the lookup.
         * @param request Argument converted to the Objective-C parameter of the same role.
         */
        void remove_cached_response_for_request(const URLRequest& request) const;
        /**
         * @brief Calls `-[NSURLCache removeCachedResponsesSinceDate:]`.
         * @details Clears the cache of any cached responses since the provided date.
         * @param date Argument converted to the Objective-C parameter of the same role.
         */
        void remove_cached_responses_since_date(const Date& date) const;
        /**
         * @brief Calls `-[NSURLCache storeCachedResponse:forDataTask:]`.
         * @details Stores a cached URL response for a specified data task.
         * @param cached_response Argument converted to the Objective-C parameter of the same role.
         * @param data_task Argument converted to the Objective-C parameter of the same role.
         */
        void store_cached_response(const CachedURLResponse& cached_response, const URLSessionDataTask& data_task) const;
        /**
         * @brief Calls `-[NSURLCache storeCachedResponse:forRequest:]`.
         * @details Stores a cached URL response for a specified request. - Parameters: - cachedResponse: The cached response to store. - request: The 'NSURLRequest' to use as a key for the storage.
         * @param cached_response Argument converted to the Objective-C parameter of the same role.
         * @param request Argument converted to the Objective-C parameter of the same role.
         */
        void store_cached_response(const CachedURLResponse& cached_response, const URLRequest& request) const;
        /**
         * @brief Returns the `currentDiskUsage` property of `NSURLCache`.
         * @details The current amount of space consumed by the on-disk cache of the receiver, measured in bytes.
         * @return The converted Objective-C result.
         */
        std::uint64_t current_disk_usage() const;
        /**
         * @brief Returns the `currentMemoryUsage` property of `NSURLCache`.
         * @details The current amount of space consumed by the in-memory cache of the receiver, measured in bytes.
         * @return The converted Objective-C result.
         */
        std::uint64_t current_memory_usage() const;
        /**
         * @brief Returns the `diskCapacity` property of `NSURLCache`.
         * @details The on-disk capacity of the receiver, measured in bytes. On mutation, the on-disk cache will truncate its contents to the size given, if necessary.
         * @return The converted Objective-C result.
         */
        std::uint64_t disk_capacity() const;
        /**
         * @brief Sets the `diskCapacity` property of `NSURLCache`.
         * @details The on-disk capacity of the receiver, measured in bytes. On mutation, the on-disk cache will truncate its contents to the size given, if necessary.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_disk_capacity(std::uint64_t value) const;
        /**
         * @brief Returns the `memoryCapacity` property of `NSURLCache`.
         * @details The in-memory capacity of the receiver, measured in bytes. At the time this value is set, the in-memory cache will truncate its contents to the size given, if necessary.
         * @return The converted Objective-C result.
         */
        std::uint64_t memory_capacity() const;
        /**
         * @brief Sets the `memoryCapacity` property of `NSURLCache`.
         * @details The in-memory capacity of the receiver, measured in bytes. At the time this value is set, the in-memory cache will truncate its contents to the size given, if necessary.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_memory_capacity(std::uint64_t value) const;
        /**
         * @brief Returns the `sharedURLCache` property of `NSURLCache`.
         * @details The shared URL cache instance. Unless set explicitly, this method returns an 'NSURLCache' instance created with the following default values: - Memory capacity: 4 megabytes (4 1024 1024 bytes) - Disk capacity: 20 megabytes (20 1024 1024 bytes) - Disk path: '(user home directory)/Library/Caches/(application bundle id)' If your app doesn't have special caching requirements or constraints, the default shared cache instance should be acceptable. Callers should take care to ensure that the setter is called at a time when no other caller has a reference to the previously-set shared URL cache.
         * @return The converted Objective-C result.
         */
        static URLCache shared_url_cache();
        /**
         * @brief Sets the `sharedURLCache` property of `NSURLCache`.
         * @details The shared URL cache instance. Unless set explicitly, this method returns an 'NSURLCache' instance created with the following default values: - Memory capacity: 4 megabytes (4 1024 1024 bytes) - Disk capacity: 20 megabytes (20 1024 1024 bytes) - Disk path: '(user home directory)/Library/Caches/(application bundle id)' If your app doesn't have special caching requirements or constraints, the default shared cache instance should be acceptable. Callers should take care to ensure that the setter is called at a time when no other caller has a reference to the previously-set shared URL cache.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        static void set_shared_url_cache(const URLCache& value);
    };
}
