#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class URLResponse;

    /**
     * @brief C++ handle for the Objective-C class `NSCachedURLResponse` (Foundation).
     * @details A cached response to a URL request. A ''CachedURLResponse'' object provides the server's response metadata in the form of a ''URLResponse'' object, along with an [NSData](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/PropertyLists/OldStylePlists/OldStylePLists.html\#//apple_ref/doc/uid/20001012-47169) object containing the actual cached content data. Its storage policy determines whether the response should be cached on disk, in memory, or not at all. Cached responses also contain a user info dictionary where you can store app-specific information about the cached item. The ''URLCache'' class stores and retrieves instances of ''CachedURLResponse''.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CachedURLResponse cached_url_response;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nscachedurlresponse
     */
    class CachedURLResponse : public Object
    {
    public:
        /// @brief Creates a new `NSCachedURLResponse` instance and returns a handle to it.
        explicit CachedURLResponse(const URLResponse& response, const std::vector<std::uint8_t>& data);
        /// @brief Creates a new `NSCachedURLResponse` instance and returns a handle to it.
        explicit CachedURLResponse(const URLResponse& response, const std::vector<std::uint8_t>& data, const std::vector<std::pair<Object, Object>>& user_info, URLCacheStoragePolicy storage_policy);
        /// @brief Creates a new `NSCachedURLResponse` instance and returns a handle to it.
        explicit CachedURLResponse();
        /// @brief Creates a null handle that refers to no native object.
        CachedURLResponse(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CachedURLResponse(Adopt adopt);
        /**
         * @brief Returns the `data` property of `NSCachedURLResponse`.
         * @details The cached response's data.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> data() const;
        /**
         * @brief Returns the `response` property of `NSCachedURLResponse`.
         * @details The URL response object associated with the instance.
         * @return The converted Objective-C result.
         */
        URLResponse response() const;
        /**
         * @brief Returns the `storagePolicy` property of `NSCachedURLResponse`.
         * @details The cached response's storage policy.
         * @return The converted Objective-C result.
         */
        URLCacheStoragePolicy storage_policy() const;
        /**
         * @brief Returns the `userInfo` property of `NSCachedURLResponse`.
         * @details The cached response's user info dictionary.
         * @return The converted Objective-C result.
         */
        std::vector<std::pair<Object, Object>> user_info() const;
    };
}
