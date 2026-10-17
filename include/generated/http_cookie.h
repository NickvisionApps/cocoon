#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;
    class Number;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSHTTPCookie` (Foundation).
     * @details A representation of an HTTP cookie. An ''HTTPCookie'' object is immutable, initialized from a dictionary that contains the attributes of the cookie. This class supports two different cookie versions: - Version 0: The original cookie format defined by Netscape. Most cookies are in this format. - Version 1: The cookie format defined in [RFC 6265](https://tools.ietf.org/html/rfc6265), HTTP State Management Mechanism.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::HTTPCookie http_cookie;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nshttpcookie
     */
    class HTTPCookie : public Object
    {
    public:
        /// @brief Creates a new `NSHTTPCookie` instance and returns a handle to it.
        explicit HTTPCookie(const std::map<std::string, Object>& properties);
        /// @brief Creates a new `NSHTTPCookie` instance and returns a handle to it.
        explicit HTTPCookie();
        /// @brief Creates a null handle that refers to no native object.
        HTTPCookie(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit HTTPCookie(Adopt adopt);
        /**
     * @brief Calls `+[NSHTTPCookie cookieWithProperties:]`.
     * @details Allocates and initializes an 'NSHTTPCookie' with the given dictionary. - Parameter properties: The dictionary to use to initialize this cookie. - Returns: A newly-created and autoreleased 'NSHTTPCookie' instance, or 'nil' if the set of dictionary keys is invalid, for example because a required key is missing, or a recognized key maps to an illegal value. See the 'NSHTTPCookie' '-initWithProperties:' method for more information on the constraints imposed on the dictionary, and for descriptions of the supported keys and values.
     * @param properties Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static HTTPCookie cookie_with_properties(const std::map<std::string, Object>& properties);
        /**
     * @brief Calls `+[NSHTTPCookie cookiesWithResponseHeaderFields:forURL:]`.
     * @details Creates an array of HTTP cookies that corresponds to the provided response header fields for the provided URL. - Parameter headerFields: The response header fields to check for cookies. - Parameter URL: The URL that the cookies came from, relevant to how the cookies are interpreted. - Returns: An 'NSArray' of 'NSHTTPCookie' objects. This method ignores irrelevant header fields in 'headerFields', allowing dictionaries to contain additional data.
     * @param header_fields Argument converted to the Objective-C parameter of the same role.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<HTTPCookie> cookies_with_response_header_fields(const std::map<std::string, std::string>& header_fields, const URL& url);
        /**
     * @brief Calls `+[NSHTTPCookie requestHeaderFieldsWithCookies:]`.
     * @details Converts an array of cookies to a dictionary of header fields. - Parameter cookies: The cookies from which the header fields are created. - Returns: An 'NSDictionary' where the keys are header field names, and the values are the corresponding header field values.
     * @param cookies Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::map<std::string, std::string> request_header_fields_with_cookies(const std::vector<HTTPCookie>& cookies);
        /**
     * @brief Returns the `HTTPOnly` property of `NSHTTPCookie`.
     * @details A Boolean value that indicates whether the cookie should only be sent to HTTP servers. Cookies can be marked as HTTP-only by a server (or by JavaScript code). Cookies marked as such must only be sent via HTTP Headers in HTTP requests for URLs that match both the path and domain of the respective cookies. > Important: To prevent cross-site scripting vulnerabilities, don't deliver cookies marked as HTTP-only to JavaScript code.
     * @return The converted Objective-C result.
     */
        bool is_http_only() const;
        /**
     * @brief Returns the `comment` property of `NSHTTPCookie`.
     * @details The cookie's comment string. This value is 'nil' if the cookie has no comment. You can present this string to the user, explaining the contents and purpose of this cookie.
     * @return The converted Objective-C result.
     */
        std::string comment() const;
        /**
     * @brief Returns the `commentURL` property of `NSHTTPCookie`.
     * @details The cookie's comment URL. This value is 'nil' if the cookie has no comment URL. This value specifies a URL that can be presented to the user as a link for further information about this cookie.
     * @return The converted Objective-C result.
     */
        URL comment_url() const;
        /**
     * @brief Returns the `domain` property of `NSHTTPCookie`.
     * @details The domain of the cookie. If the domain does not start with a dot, then the cookie is only sent to the exact host specified by the domain. If the domain does start with a dot, then the cookie is sent to other hosts in that domain as well, subject to certain restrictions. See RFC 6265 for more detail.
     * @return The converted Objective-C result.
     */
        std::string domain() const;
        /**
     * @brief Returns the `expiresDate` property of `NSHTTPCookie`.
     * @details The cookie's expiration date. This value is 'nil' if there is no specific expiration date, as with session-only cookies. The expiration date is the date when the cookie should be deleted.
     * @return The converted Objective-C result.
     */
        Date expires_date() const;
        /**
     * @brief Returns the `name` property of `NSHTTPCookie`.
     * @details The cookie's name.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Returns the `path` property of `NSHTTPCookie`.
     * @details The cookie's path. The cookie will be sent with requests for this path in the cookie's domain, and all paths that have this prefix. A path of '"/"' means the cookie will be sent for all URLs in the domain.
     * @return The converted Objective-C result.
     */
        std::string path() const;
        /**
     * @brief Returns the `portList` property of `NSHTTPCookie`.
     * @details The cookie's port list. The list of ports for the cookie, returned as an array of 'NSNumber' objects containing integers. If the cookie has no port list, the value of this property is 'nil' and the cookie will be sent to any port. Otherwise, the cookie is only sent to ports specified in the port list.
     * @return The converted Objective-C result.
     */
        std::vector<Number> port_list() const;
        /**
     * @brief Returns the `properties` property of `NSHTTPCookie`.
     * @details The cookie's properties. This dictionary can be used with '-initWithProperties:' or '+cookieWithProperties:' to create an equivalent 'NSHTTPCookie' object.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> properties() const;
        /**
     * @brief Returns the `sameSitePolicy` property of `NSHTTPCookie`.
     * @details A Boolean value that indicates whether to restrict the cookie to requests sent back to the same site that created it. Cookies can be marked with an attribute Strict or Lax. Cookies marked with "strict" ('NSHTTPCookieSameSiteStrict') are not sent along with cross-site requests. Cookies marked with "lax" ('NSHTTPCookieSameSiteLax') are sent along cross-site requests provided the cross-site requests are top-level requests (one that changes the URL in the address bar). The result could also be 'nil', in which case the cookie will be sent along with all cross-site requests.
     * @return The converted Objective-C result.
     */
        std::string same_site_policy() const;
        /**
     * @brief Returns the `secure` property of `NSHTTPCookie`.
     * @details A Boolean value that indicates whether the cookie may only be sent over secure channels. Cookies may be marked secure by a server (or by a javascript). Cookies marked as such must only be sent via an encrypted connection to trusted servers (i.e. via SSL or TLS), and should not be delivered to any javascript applications to prevent cross-site scripting vulnerabilities.
     * @return The converted Objective-C result.
     */
        bool is_secure() const;
        /**
     * @brief Returns the `sessionOnly` property of `NSHTTPCookie`.
     * @details A Boolean value that indicates whether the cookie should be discarded at the end of the session (regardless of expiration date).
     * @return The converted Objective-C result.
     */
        bool is_session_only() const;
        /**
     * @brief Returns the `value` property of `NSHTTPCookie`.
     * @details The cookie's string value.
     * @return The converted Objective-C result.
     */
        std::string value() const;
        /**
     * @brief Returns the `version` property of `NSHTTPCookie`.
     * @details The cookie's version. Version 0 maps to "old-style" Netscape cookies. Version 1 maps to RFC 2965 cookies. There may be future versions.
     * @return The converted Objective-C result.
     */
        std::uint64_t version() const;
    };
}
