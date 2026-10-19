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
     * @details \@class NSURLResponse \@abstract An NSURLResponse object represents a URL load response in a manner independent of protocol and URL scheme. \@discussion NSURLResponse encapsulates the metadata associated with a URL load. Note that NSURLResponse objects do not contain the actual bytes representing the content of a URL. See NSURLConnection and NSURLConnectionDelegate for more information about receiving the content data for a URL load.
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
     * @details \@abstract Returns the MIME type of the receiver. \@discussion The MIME type is based on the information provided from an origin source. However, that value may be changed or corrected by a protocol implementation if it can be determined that the origin server or source reported the information incorrectly or imprecisely. An attempt to guess the MIME type may be made if the origin source did not report any such information. \@result The MIME type of the receiver.
     * @return The converted Objective-C result.
     */
        std::string mime_type() const;
        /**
     * @brief Returns the `URL` property of `NSURLResponse`.
     * @details \@abstract Returns the URL of the receiver. \@result The URL of the receiver.
     * @return The converted Objective-C result.
     */
        URL url() const;
        /**
     * @brief Returns the `expectedContentLength` property of `NSURLResponse`.
     * @details \@abstract Returns the expected content length of the receiver. \@discussion Some protocol implementations report a content length as part of delivering load metadata, but not all protocols guarantee the amount of data that will be delivered in actuality. Hence, this method returns an expected amount. Clients should use this value as an advisory, and should be prepared to deal with either more or less data. \@result The expected content length of the receiver, or -1 if there is no expectation that can be arrived at regarding expected content length.
     * @return The converted Objective-C result.
     */
        std::int64_t expected_content_length() const;
        /**
     * @brief Returns the `suggestedFilename` property of `NSURLResponse`.
     * @details \@abstract Returns a suggested filename if the resource were saved to disk. \@discussion The method first checks if the server has specified a filename using the content disposition header. If no valid filename is specified using that mechanism, this method checks the last path component of the URL. If no valid filename can be obtained using the last path component, this method uses the URL's host as the filename. If the URL's host can't be converted to a valid filename, the filename "unknown" is used. In most cases, this method appends the proper file extension based on the MIME type. This method always returns a valid filename. \@result A suggested filename to use if saving the resource to disk.
     * @return The converted Objective-C result.
     */
        std::string suggested_filename() const;
        /**
     * @brief Returns the `textEncodingName` property of `NSURLResponse`.
     * @details \@abstract Returns the name of the text encoding of the receiver. \@discussion This name will be the actual string reported by the origin source during the course of performing a protocol-specific URL load. Clients can inspect this string and convert it to an NSStringEncoding or CFStringEncoding using the methods and functions made available in the appropriate framework. \@result The name of the text encoding of the receiver, or nil if no text encoding was specified.
     * @return The converted Objective-C result.
     */
        std::string text_encoding_name() const;
    };
}
