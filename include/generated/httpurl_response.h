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
     * @details \@class NSHTTPURLResponse \@abstract An NSHTTPURLResponse object represents a response to an HTTP URL load. It is a specialization of NSURLResponse which provides conveniences for accessing information specific to HTTP protocol responses.
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
         * @details \@method localizedStringForStatusCode: \@abstract Convenience method which returns a localized string corresponding to the status code for this response. \@param statusCode the status code to use to produce a localized string. \@result A localized string corresponding to the given status code.
         * @param status_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::string localized_string_for_status_code(std::int64_t status_code);
        /**
         * @brief Calls `-[NSHTTPURLResponse valueForHTTPHeaderField:]`.
         * @details \@method valueForHTTPHeaderField: \@abstract Returns the value which corresponds to the given header field. Note that, in keeping with the HTTP RFC, HTTP header field names are case-insensitive. \@param field the header field name to use for the lookup (case-insensitive). \@result the value associated with the given header field, or nil if there is no value associated with the given header field.
         * @param field Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string value_for_http_header_field(const std::string& field) const;
        /**
         * @brief Returns the `allHeaderFields` property of `NSHTTPURLResponse`.
         * @details \@abstract Returns a dictionary containing all the HTTP header fields of the receiver. \@discussion By examining this header dictionary, clients can see the "raw" header information which was reported to the protocol implementation by the HTTP server. This may be of use to sophisticated or special-purpose HTTP clients. \@result A dictionary containing all the HTTP header fields of the receiver.
         * @return The converted Objective-C result.
         */
        std::vector<std::pair<Object, Object>> all_header_fields() const;
        /**
         * @brief Returns the `statusCode` property of `NSHTTPURLResponse`.
         * @details \@abstract Returns the HTTP status code of the receiver. \@result The HTTP status code of the receiver.
         * @return The converted Objective-C result.
         */
        std::int64_t status_code() const;
    };
}
