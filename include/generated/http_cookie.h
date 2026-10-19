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
     * @details \@class NSHTTPCookie \@abstract NSHTTPCookie represents an http cookie. \@discussion A NSHTTPCookie instance represents a single http cookie. It is an immutable object initialized from a dictionary that contains the various cookie attributes. It has accessors to get the various attributes of a cookie.
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
     * @details \@method cookieWithProperties: \@abstract Allocates and initializes an NSHTTPCookie with the given dictionary. \@discussion See the NSHTTPCookie \<tt>-initWithProperties:\</tt> method for more information on the constraints imposed on the dictionary, and for descriptions of the supported keys and values. \@param properties The dictionary to use to initialize this cookie. \@result A newly-created and autoreleased NSHTTPCookie instance, or nil if the set of dictionary keys is invalid, for example because a required key is missing, or a recognized key maps to an illegal value.
     * @param properties Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static HTTPCookie cookie_with_properties(const std::map<std::string, Object>& properties);
        /**
     * @brief Calls `+[NSHTTPCookie cookiesWithResponseHeaderFields:forURL:]`.
     * @details \@method cookiesWithResponseHeaderFields:forURL: \@abstract Return an array of cookies parsed from the specified response header fields and URL. \@param headerFields The response header fields to check for cookies. \@param URL The URL that the cookies came from - relevant to how the cookies are interpreted. \@result An NSArray of NSHTTPCookie objects \@discussion This method will ignore irrelevant header fields so you can pass a dictionary containing data other than cookie data.
     * @param header_fields Argument converted to the Objective-C parameter of the same role.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<HTTPCookie> cookies_with_response_header_fields(const std::map<std::string, std::string>& header_fields, const URL& url);
        /**
     * @brief Calls `+[NSHTTPCookie requestHeaderFieldsWithCookies:]`.
     * @details \@method requestHeaderFieldsWithCookies: \@abstract Return a dictionary of header fields that can be used to add the specified cookies to the request. \@param cookies The cookies to turn into request headers. \@result An NSDictionary where the keys are header field names, and the values are the corresponding header field values.
     * @param cookies Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::map<std::string, std::string> request_header_fields_with_cookies(const std::vector<HTTPCookie>& cookies);
        /**
     * @brief Returns the `HTTPOnly` property of `NSHTTPCookie`.
     * @details \@abstract Returns whether the receiver should only be sent to HTTP servers per RFC 2965 \@discussion Cookies may be marked as HTTPOnly by a server (or by a javascript). Cookies marked as such must only be sent via HTTP Headers in HTTP Requests for URL's that match both the path and domain of the respective Cookies. Specifically these cookies should not be delivered to any javascript applications to prevent cross-site scripting vulnerabilities. \@result YES if this cookie should only be sent via HTTP headers, NO otherwise.
     * @return The converted Objective-C result.
     */
        bool is_http_only() const;
        /**
     * @brief Returns the `comment` property of `NSHTTPCookie`.
     * @details \@abstract Returns the comment of the receiver. \@discussion This value specifies a string which is suitable for presentation to the user explaining the contents and purpose of this cookie. It may be nil. \@result The comment of the receiver, or nil if the receiver has no comment.
     * @return The converted Objective-C result.
     */
        std::string comment() const;
        /**
     * @brief Returns the `commentURL` property of `NSHTTPCookie`.
     * @details \@abstract Returns the comment URL of the receiver. \@discussion This value specifies a URL which is suitable for presentation to the user as a link for further information about this cookie. It may be nil. \@result The comment URL of the receiver, or nil if the receiver has no comment URL.
     * @return The converted Objective-C result.
     */
        URL comment_url() const;
        /**
     * @brief Returns the `domain` property of `NSHTTPCookie`.
     * @details \@abstract Returns the domain of the receiver. \@discussion This value specifies URL domain to which the cookie should be sent. A domain with a leading dot means the cookie should be sent to subdomains as well, assuming certain other restrictions are valid. See RFC 2965 for more detail. \@result The domain of the receiver.
     * @return The converted Objective-C result.
     */
        std::string domain() const;
        /**
     * @brief Returns the `expiresDate` property of `NSHTTPCookie`.
     * @details \@abstract Returns the expires date of the receiver. \@result the expires date of the receiver. \@discussion The expires date is the date when the cookie should be deleted. The result will be nil if there is no specific expires date. This will be the case only for "session-only" cookies. \@result The expires date of the receiver.
     * @return The converted Objective-C result.
     */
        Date expires_date() const;
        /**
     * @brief Returns the `name` property of `NSHTTPCookie`.
     * @details \@abstract Returns the name of the receiver. \@result the name of the receiver.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Returns the `path` property of `NSHTTPCookie`.
     * @details \@abstract Returns the path of the receiver. \@discussion This value specifies the URL path under the cookie's domain for which this cookie should be sent. The cookie will also be sent for children of that path, so "/" is the most general. \@result The path of the receiver.
     * @return The converted Objective-C result.
     */
        std::string path() const;
        /**
     * @brief Returns the `portList` property of `NSHTTPCookie`.
     * @details \@abstract Returns the list ports to which the receiver should be sent. \@discussion This value specifies an NSArray of NSNumbers (containing integers) which specify the only ports to which this cookie should be sent. \@result The list ports to which the receiver should be sent. The array may be nil, in which case this cookie can be sent to any port.
     * @return The converted Objective-C result.
     */
        std::vector<Number> port_list() const;
        /**
     * @brief Returns the `properties` property of `NSHTTPCookie`.
     * @details \@abstract Returns a dictionary representation of the receiver. \@discussion This method returns a dictionary representation of the NSHTTPCookie which can be saved and passed to \<tt>-initWithProperties:\</tt> or \<tt>+cookieWithProperties:\</tt> later to reconstitute an equivalent cookie. \<p>See the NSHTTPCookie \<tt>-initWithProperties:\</tt> method for more information on the constraints imposed on the dictionary, and for descriptions of the supported keys and values. \@result The dictionary representation of the receiver.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> properties() const;
        /**
     * @brief Returns the `sameSitePolicy` property of `NSHTTPCookie`.
     * @details \@abstract Returns the value of the same site attribute on the cookie. \@discussion Cookies can be marked with an attribute Strict or Lax. Cookies marked with "strict" (NSHTTPCookieSameSiteStrict) are not sent along with cross-site requests. Cookies marked with "lax" (NSHTTPCookieSameSiteLax) sent along cross-site requests provided the cross-site requests are top-level-requests (one that changes the url in the address bar). The attribute value is canonicalized and stored. Any value other than the default (strict and lax) will be ignored. \@result strict or lax. The result could also be nil, in which case the cookie will be sent along with all cross-site requests.
     * @return The converted Objective-C result.
     */
        std::string same_site_policy() const;
        /**
     * @brief Returns the `secure` property of `NSHTTPCookie`.
     * @details \@abstract Returns whether the receiver should be sent only over secure channels \@discussion Cookies may be marked secure by a server (or by a javascript). Cookies marked as such must only be sent via an encrypted connection to trusted servers (i.e. via SSL or TLS), and should not be delivered to any javascript applications to prevent cross-site scripting vulnerabilities. \@result YES if this cookie should be sent only over secure channels, NO otherwise.
     * @return The converted Objective-C result.
     */
        bool is_secure() const;
        /**
     * @brief Returns the `sessionOnly` property of `NSHTTPCookie`.
     * @details \@abstract Returns whether the receiver is session-only. \@result YES if this receiver should be discarded at the end of the session (regardless of expiration date), NO if receiver need not be discarded at the end of the session.
     * @return The converted Objective-C result.
     */
        bool is_session_only() const;
        /**
     * @brief Returns the `value` property of `NSHTTPCookie`.
     * @details \@abstract Returns the value of the receiver. \@result the value of the receiver.
     * @return The converted Objective-C result.
     */
        std::string value() const;
        /**
     * @brief Returns the `version` property of `NSHTTPCookie`.
     * @details \@abstract Returns the version of the receiver. \@discussion Version 0 maps to "old-style" Netscape cookies. Version 1 maps to RFC2965 cookies. There may be future versions. \@result the version of the receiver.
     * @return The converted Objective-C result.
     */
        std::uint64_t version() const;
    };
}
