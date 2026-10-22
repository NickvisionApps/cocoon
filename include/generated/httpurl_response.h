#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/url_response.h"
#include "types.h"

namespace cocoon
{
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSHTTPURLResponse` (Foundation).
     * @details The metadata associated with the response to an HTTP protocol URL load request. The ''HTTPURLResponse'' class is a subclass of ''URLResponse'' that provides methods for accessing information specific to HTTP protocol responses. Whenever you make HTTP URL load requests, any response objects you get back from the ''URLSession'', ''NSURLConnection'', or ''NSURLDownload'' class are instances of the ''HTTPURLResponse'' class.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref URLResponse.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::HTTPURLResponse httpurl_response;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::HTTPURLResponse httpurl_response{};
     * httpurl_response.value_for_http_header_field("text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nshttpurlresponse
     */
    class HTTPURLResponse : public URLResponse
    {
    public:
        /// @brief Creates a new `NSHTTPURLResponse` instance and returns a handle to it.
        explicit HTTPURLResponse(const URL& url, std::int64_t status_code, const std::string& http_version, const std::map<std::string, std::string>& header_fields);
        /// @brief Creates a new `NSHTTPURLResponse` instance and returns a handle to it.
        explicit HTTPURLResponse();
        /// @brief Creates a null handle that refers to no native object.
        HTTPURLResponse(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit HTTPURLResponse(Adopt adopt);
        /**
         * @brief Calls `+[NSHTTPURLResponse localizedStringForStatusCode:]`.
         * @details Returns a localized string corresponding to a specified HTTP status code. - Parameter statusCode: The HTTP status code. See [RFC 2616](http://www.ietf.org/rfc/rfc2616.txt) for details. - Returns: A localized string suitable for displaying to users that describes the specified status code.
         * @param status_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::string localized_string_for_status_code(std::int64_t status_code);
        /**
         * @brief Calls `-[NSHTTPURLResponse valueForHTTPHeaderField:]`.
         * @details Returns the value that corresponds to the given header field. In keeping with the HTTP RFC, HTTP header field names are case-insensitive. - Parameter field: The header field name to use for the lookup (case-insensitive). - Returns: The value associated with the given header field, or 'nil' if there is no value associated with the given header field.
         * @param field Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string value_for_http_header_field(const std::string& field) const;
        /**
         * @brief Returns the `allHeaderFields` property of `NSHTTPURLResponse`.
         * @details All HTTP header fields of the response. The value of this property is a dictionary that contains all the HTTP header fields received as part of the server's response. By examining this dictionary, clients can see the "raw" header information returned by the HTTP server. HTTP headers are case insensitive. To simplify your code, URL Loading System canonicalizes certain header field names into their standard form. For example, if the server sends a 'content-length' header, it's automatically adjusted to be 'Content-Length'. When using Swift, this property is a standard dictionary, so its keys are case-sensitive. To perform a case-insensitive header lookup, use the 'valueForHTTPHeaderField:' method instead.
         * @return The converted Objective-C result.
         */
        std::vector<std::pair<Object, Object>> all_header_fields() const;
        /**
         * @brief Returns the `statusCode` property of `NSHTTPURLResponse`.
         * @details The response's HTTP status code. See [RFC 2616](http://www.ietf.org/rfc/rfc2616.txt) for details.
         * @return The converted Objective-C result.
         */
        std::int64_t status_code() const;
    };
}
