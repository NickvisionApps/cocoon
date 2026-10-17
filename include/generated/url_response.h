#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSURLResponse` (Foundation).
     * @details The metadata associated with the response to a URL load request, independent of protocol and URL scheme. The related ''HTTPURLResponse'' class is a commonly used subclass of ''URLResponse'' whose objects represent a response to an HTTP URL load request and store additional protocol-specific information such as the response headers. Whenever you make an HTTP request, the ''URLResponse'' object you get back is actually an instance of the ''HTTPURLResponse'' class. > Note: > ''URLResponse'' objects don't contain the actual bytes representing the content of a URL. Instead, the data is returned either a piece at a time through delegate calls or in its entirety when the request completes, depending on the method and class used to initiate the request. > > Read \<doc:fetching-website-data-into-memory> to learn various ways to receive the content data from a URL load.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLResponse url_response;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlresponse
     */
    class URLResponse : public Object
    {
    public:
        /// @brief Creates a new `NSURLResponse` instance and returns a handle to it.
        explicit URLResponse(const URL& url, const std::string& mime_type, std::int64_t length, const std::string& name);
        /// @brief Creates a new `NSURLResponse` instance and returns a handle to it.
        explicit URLResponse();
        /// @brief Creates a null handle that refers to no native object.
        URLResponse(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLResponse(Adopt adopt);
        /**
     * @brief Returns the `MIMEType` property of `NSURLResponse`.
     * @details The MIME type of the response. The MIME type is often provided by the response's originating source. However, that value may be changed or corrected by a protocol implementation if it can be determined that the response's source reported the information incorrectly. If the response's originating source does not provide a MIME type, an attempt to guess the MIME type may be made.
     * @return The converted Objective-C result.
     */
        std::string mime_type() const;
        /**
     * @brief Returns the `URL` property of `NSURLResponse`.
     * @details The URL for the response.
     * @return The converted Objective-C result.
     */
        URL url() const;
        /**
     * @brief Returns the `expectedContentLength` property of `NSURLResponse`.
     * @details The expected length of the response's content. This property's value is 'NSURLResponseUnknownLength' if the length can't be determined. Some protocol implementations report the content length as part of the response, but not all protocols guarantee to deliver that amount of data. Your app should be prepared to deal with more or less data.
     * @return The converted Objective-C result.
     */
        std::int64_t expected_content_length() const;
        /**
     * @brief Returns the `suggestedFilename` property of `NSURLResponse`.
     * @details A suggested filename for the response data. Accessing this property attempts to generate a filename using the following information, in order: 1. A filename specified using the content disposition header. 2. The last path component of the URL. 3. The host of the URL. If the host of URL can't be converted to a valid filename, the filename '"unknown"' is used. In most cases, this property appends the proper file extension based on the MIME type. Accessing this property always returns a valid filename regardless of whether the resource is saved to disk.
     * @return The converted Objective-C result.
     */
        std::string suggested_filename() const;
        /**
     * @brief Returns the `textEncodingName` property of `NSURLResponse`.
     * @details The name of the text encoding provided by the response's originating source. If no text encoding was provided by the protocol, this property's value is 'nil'. You can convert this string to a 'CFStringEncoding' value by calling 'CFStringConvertIANACharSetNameToEncoding(:)'. You can subsequently convert that value to an 'NSStringEncoding' value by calling 'CFStringConvertEncodingToNSStringEncoding(:)'.
     * @return The converted Objective-C result.
     */
        std::string text_encoding_name() const;
    };
}
