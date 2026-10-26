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
         * @details \@method cachedResponseForRequest: \@abstract Returns the NSCachedURLResponse stored in the cache with the given request. \@discussion The method returns nil if there is no NSCachedURLResponse stored using the given request. \@param request the NSURLRequest to use as a key for the lookup. \@result The NSCachedURLResponse stored in the cache with the given request, or nil if there is no NSCachedURLResponse stored with the given request.
         * @param request Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        CachedURLResponse cached_response_for_request(const URLRequest& request) const;
        /**
         * @brief Calls `-[NSURLCache getCachedResponseForDataTask:completionHandler:]`.
         * @param data_task Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void get_cached_response_for_data_task(const URLSessionDataTask& data_task, std::function<void(CachedURLResponse)> completion_handler) const;
        /**
         * @brief Calls `-[NSURLCache removeAllCachedResponses]`.
         * @details \@method removeAllCachedResponses \@abstract Clears the given cache, removing all NSCachedURLResponse objects that it stores.
         */
        void remove_all_cached_responses() const;
        /**
         * @brief Calls `-[NSURLCache removeCachedResponseForDataTask:]`.
         * @param data_task Argument converted to the Objective-C parameter of the same role.
         */
        void remove_cached_response_for_data_task(const URLSessionDataTask& data_task) const;
        /**
         * @brief Calls `-[NSURLCache removeCachedResponseForRequest:]`.
         * @details \@method removeCachedResponseForRequest: \@abstract Removes the NSCachedURLResponse from the cache that is stored using the given request. \@discussion No action is taken if there is no NSCachedURLResponse stored with the given request. \@param request the NSURLRequest to use as a key for the lookup.
         * @param request Argument converted to the Objective-C parameter of the same role.
         */
        void remove_cached_response_for_request(const URLRequest& request) const;
        /**
         * @brief Calls `-[NSURLCache removeCachedResponsesSinceDate:]`.
         * @details \@method removeCachedResponsesSince: \@abstract Clears the given cache of any cached responses since the provided date.
         * @param date Argument converted to the Objective-C parameter of the same role.
         */
        void remove_cached_responses_since_date(const Date& date) const;
        /**
         * @brief Calls `-[NSURLCache storeCachedResponse:forDataTask:]`.
         * @param cached_response Argument converted to the Objective-C parameter of the same role.
         * @param data_task Argument converted to the Objective-C parameter of the same role.
         */
        void store_cached_response(const CachedURLResponse& cached_response, const URLSessionDataTask& data_task) const;
        /**
         * @brief Calls `-[NSURLCache storeCachedResponse:forRequest:]`.
         * @details \@method storeCachedResponse:forRequest: \@abstract Stores the given NSCachedURLResponse in the cache using the given request. \@param cachedResponse The cached response to store. \@param request the NSURLRequest to use as a key for the storage.
         * @param cached_response Argument converted to the Objective-C parameter of the same role.
         * @param request Argument converted to the Objective-C parameter of the same role.
         */
        void store_cached_response(const CachedURLResponse& cached_response, const URLRequest& request) const;
        /**
         * @brief Returns the `currentDiskUsage` property of `NSURLCache`.
         * @details \@abstract Returns the current amount of space consumed by the on-disk cache of the receiver. \@discussion This size, measured in bytes, indicates the current usage of the on-disk cache. \@result the current usage of the on-disk cache of the receiver.
         * @return The converted Objective-C result.
         */
        std::uint64_t current_disk_usage() const;
        /**
         * @brief Returns the `currentMemoryUsage` property of `NSURLCache`.
         * @details \@abstract Returns the current amount of space consumed by the in-memory cache of the receiver. \@discussion This size, measured in bytes, indicates the current usage of the in-memory cache. \@result the current usage of the in-memory cache of the receiver.
         * @return The converted Objective-C result.
         */
        std::uint64_t current_memory_usage() const;
        /**
         * @brief Returns the `diskCapacity` property of `NSURLCache`.
         * @details \@abstract The on-disk capacity of the receiver. \@discussion The on-disk capacity, measured in bytes, for the receiver. On mutation the on-disk cache will truncate its contents to the size given, if necessary.
         * @return The converted Objective-C result.
         */
        std::uint64_t disk_capacity() const;
        /**
         * @brief Sets the `diskCapacity` property of `NSURLCache`.
         * @details \@abstract The on-disk capacity of the receiver. \@discussion The on-disk capacity, measured in bytes, for the receiver. On mutation the on-disk cache will truncate its contents to the size given, if necessary.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_disk_capacity(std::uint64_t value) const;
        /**
         * @brief Returns the `memoryCapacity` property of `NSURLCache`.
         * @details \@abstract In-memory capacity of the receiver. \@discussion At the time this call is made, the in-memory cache will truncate its contents to the size given, if necessary. \@result The in-memory capacity, measured in bytes, for the receiver.
         * @return The converted Objective-C result.
         */
        std::uint64_t memory_capacity() const;
        /**
         * @brief Sets the `memoryCapacity` property of `NSURLCache`.
         * @details \@abstract In-memory capacity of the receiver. \@discussion At the time this call is made, the in-memory cache will truncate its contents to the size given, if necessary. \@result The in-memory capacity, measured in bytes, for the receiver.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_memory_capacity(std::uint64_t value) const;
        /**
         * @brief Returns the `sharedURLCache` property of `NSURLCache`.
         * @details \@property sharedURLCache \@abstract Returns the shared NSURLCache instance or sets the NSURLCache instance shared by all clients of the current process. This will be the new object returned when calls to the \<tt>sharedURLCache\</tt> method are made. \@discussion Unless set explicitly through a call to \<tt>+setSharedURLCache:\</tt>, this method returns an NSURLCache instance created with the following default values: \<ul> \<li>Memory capacity: 4 megabytes (4 1024 1024 bytes) \<li>Disk capacity: 20 megabytes (20 1024 1024 bytes) \<li>Disk path: \<nobr>(user home directory)/Library/Caches/(application bundle id)\</nobr> \</ul> \<p>Users who do not have special caching requirements or constraints should find the default shared cache instance acceptable. If this default shared cache instance is not acceptable, \<tt>+setSharedURLCache:\</tt> can be called to set a different NSURLCache instance to be returned from this method. Callers should take care to ensure that the setter is called at a time when no other caller has a reference to the previously-set shared URL cache. This is to prevent storing cache data from becoming unexpectedly unretrievable. \@result the shared NSURLCache instance.
         * @return The converted Objective-C result.
         */
        static URLCache shared_url_cache();
        /**
         * @brief Sets the `sharedURLCache` property of `NSURLCache`.
         * @details \@property sharedURLCache \@abstract Returns the shared NSURLCache instance or sets the NSURLCache instance shared by all clients of the current process. This will be the new object returned when calls to the \<tt>sharedURLCache\</tt> method are made. \@discussion Unless set explicitly through a call to \<tt>+setSharedURLCache:\</tt>, this method returns an NSURLCache instance created with the following default values: \<ul> \<li>Memory capacity: 4 megabytes (4 1024 1024 bytes) \<li>Disk capacity: 20 megabytes (20 1024 1024 bytes) \<li>Disk path: \<nobr>(user home directory)/Library/Caches/(application bundle id)\</nobr> \</ul> \<p>Users who do not have special caching requirements or constraints should find the default shared cache instance acceptable. If this default shared cache instance is not acceptable, \<tt>+setSharedURLCache:\</tt> can be called to set a different NSURLCache instance to be returned from this method. Callers should take care to ensure that the setter is called at a time when no other caller has a reference to the previously-set shared URL cache. This is to prevent storing cache data from becoming unexpectedly unretrievable. \@result the shared NSURLCache instance.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        static void set_shared_url_cache(const URLCache& value);
    };
}
