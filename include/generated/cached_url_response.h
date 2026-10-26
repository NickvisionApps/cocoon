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
     * @details \@class NSCachedURLResponse NSCachedURLResponse is a class whose objects functions as a wrapper for objects that are stored in the framework's caching system. It is used to maintain characteristics and attributes of a cached object.
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
         * @details \@abstract Returns the data of the receiver. \@result The data of the receiver.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> data() const;
        /**
         * @brief Returns the `response` property of `NSCachedURLResponse`.
         * @details \@abstract Returns the response wrapped by this instance. \@result The response wrapped by this instance.
         * @return The converted Objective-C result.
         */
        URLResponse response() const;
        /**
         * @brief Returns the `storagePolicy` property of `NSCachedURLResponse`.
         * @details \@abstract Returns the NSURLCacheStoragePolicy constant of the receiver. \@result The NSURLCacheStoragePolicy constant of the receiver.
         * @return The converted Objective-C result.
         */
        URLCacheStoragePolicy storage_policy() const;
        /**
         * @brief Returns the `userInfo` property of `NSCachedURLResponse`.
         * @details \@abstract Returns the userInfo dictionary of the receiver. \@result The userInfo dictionary of the receiver.
         * @return The converted Objective-C result.
         */
        std::vector<std::pair<Object, Object>> user_info() const;
    };
}
