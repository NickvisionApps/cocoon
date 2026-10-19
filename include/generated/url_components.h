#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Number;
    class URL;
    class URLQueryItem;

    /**
     * @brief C++ handle for the Objective-C class `NSURLComponents` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLComponents url_components;
     * url_components.set_encoded_host("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::URLComponents url_components{};
     * url_components.set_encoded_host("text");
     * auto encoded_host = url_components.encoded_host();
     * url_components.set_fragment("text");
     * auto fragment = url_components.fragment();
     * url_components.set_host("text");
     * auto host = url_components.host();
     * auto made_0 = cocoon::URLComponents::components_with_string("text");
     * auto made_1 = cocoon::URLComponents::components_with_string("text", true);
     * url_components.url_relative_to_url(cocoon::URL());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlcomponents
     */
    class URLComponents : public Object
    {
    public:
        /// @brief Creates a new `NSURLComponents` instance and returns a handle to it.
        explicit URLComponents(const std::string& url_string);
        /// @brief Creates a new `NSURLComponents` instance and returns a handle to it.
        explicit URLComponents(const std::string& url_string, bool encoding_invalid_characters);
        /// @brief Creates a new `NSURLComponents` instance and returns a handle to it.
        explicit URLComponents(const URL& url, bool resolve);
        /// @brief Creates a new `NSURLComponents` instance and returns a handle to it.
        explicit URLComponents();
        /// @brief Creates a null handle that refers to no native object.
        URLComponents(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLComponents(Adopt adopt);
        /**
     * @brief Calls `-[NSURLComponents URLRelativeToURL:]`.
     * @param base_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_relative_to_url(const URL& base_url) const;
        /**
     * @brief Calls `+[NSURLComponents componentsWithString:]`.
     * @param url_string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URLComponents components_with_string(const std::string& url_string);
        /**
     * @brief Calls `+[NSURLComponents componentsWithString:encodingInvalidCharacters:]`.
     * @details Initializes and returns a newly created 'NSURLComponents' with a URL string and the option to add (or skip) IDNA- and percent-encoding of invalid characters. If 'encodingInvalidCharacters' is false, and the URL string is invalid according to RFC 3986, 'nil' is returned. If 'encodingInvalidCharacters' is true, 'NSURLComponents' will try to encode the string to create a valid URL. If the URL string is still invalid after encoding, nil is returned. - Parameter URLString: The URL string. - Parameter encodingInvalidCharacters: True if 'NSURLComponents' should try to encode an invalid URL string, false otherwise. - Returns: An 'NSURLComponents' instance for a valid URL, or 'nil' if the URL is invalid.
     * @param url_string Argument converted to the Objective-C parameter of the same role.
     * @param encoding_invalid_characters Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URLComponents components_with_string(const std::string& url_string, bool encoding_invalid_characters);
        /**
     * @brief Calls `+[NSURLComponents componentsWithURL:resolvingAgainstBaseURL:]`.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param resolve Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URLComponents components_with_url(const URL& url, bool resolve);
        /**
     * @brief Returns the `URL` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        URL url() const;
        /**
     * @brief Returns the `encodedHost` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        std::string encoded_host() const;
        /**
     * @brief Sets the `encodedHost` property of `NSURLComponents`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_encoded_host(const std::string& value) const;
        /**
     * @brief Returns the `fragment` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        std::string fragment() const;
        /**
     * @brief Sets the `fragment` property of `NSURLComponents`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_fragment(const std::string& value) const;
        /**
     * @brief Returns the `host` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        std::string host() const;
        /**
     * @brief Sets the `host` property of `NSURLComponents`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_host(const std::string& value) const;
        /**
     * @brief Returns the `password` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        std::string password() const;
        /**
     * @brief Sets the `password` property of `NSURLComponents`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_password(const std::string& value) const;
        /**
     * @brief Returns the `path` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        std::string path() const;
        /**
     * @brief Sets the `path` property of `NSURLComponents`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_path(const std::string& value) const;
        /**
     * @brief Returns the `percentEncodedFragment` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        std::string percent_encoded_fragment() const;
        /**
     * @brief Sets the `percentEncodedFragment` property of `NSURLComponents`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_percent_encoded_fragment(const std::string& value) const;
        /**
     * @brief Returns the `percentEncodedHost` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        std::string percent_encoded_host() const;
        /**
     * @brief Sets the `percentEncodedHost` property of `NSURLComponents`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_percent_encoded_host(const std::string& value) const;
        /**
     * @brief Returns the `percentEncodedPassword` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        std::string percent_encoded_password() const;
        /**
     * @brief Sets the `percentEncodedPassword` property of `NSURLComponents`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_percent_encoded_password(const std::string& value) const;
        /**
     * @brief Returns the `percentEncodedPath` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        std::string percent_encoded_path() const;
        /**
     * @brief Sets the `percentEncodedPath` property of `NSURLComponents`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_percent_encoded_path(const std::string& value) const;
        /**
     * @brief Returns the `percentEncodedQuery` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        std::string percent_encoded_query() const;
        /**
     * @brief Sets the `percentEncodedQuery` property of `NSURLComponents`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_percent_encoded_query(const std::string& value) const;
        /**
     * @brief Returns the `percentEncodedQueryItems` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        std::vector<URLQueryItem> percent_encoded_query_items() const;
        /**
     * @brief Sets the `percentEncodedQueryItems` property of `NSURLComponents`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_percent_encoded_query_items(const std::vector<URLQueryItem>& value) const;
        /**
     * @brief Returns the `percentEncodedUser` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        std::string percent_encoded_user() const;
        /**
     * @brief Sets the `percentEncodedUser` property of `NSURLComponents`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_percent_encoded_user(const std::string& value) const;
        /**
     * @brief Returns the `port` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        Number port() const;
        /**
     * @brief Sets the `port` property of `NSURLComponents`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_port(const Number& value) const;
        /**
     * @brief Returns the `query` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        std::string query() const;
        /**
     * @brief Sets the `query` property of `NSURLComponents`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_query(const std::string& value) const;
        /**
     * @brief Returns the `queryItems` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        std::vector<URLQueryItem> query_items() const;
        /**
     * @brief Sets the `queryItems` property of `NSURLComponents`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_query_items(const std::vector<URLQueryItem>& value) const;
        /**
     * @brief Returns the `rangeOfFragment` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        Range range_of_fragment() const;
        /**
     * @brief Returns the `rangeOfHost` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        Range range_of_host() const;
        /**
     * @brief Returns the `rangeOfPassword` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        Range range_of_password() const;
        /**
     * @brief Returns the `rangeOfPath` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        Range range_of_path() const;
        /**
     * @brief Returns the `rangeOfPort` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        Range range_of_port() const;
        /**
     * @brief Returns the `rangeOfQuery` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        Range range_of_query() const;
        /**
     * @brief Returns the `rangeOfScheme` property of `NSURLComponents`.
     * @details These properties return the character range of a component in the URL string returned by -[NSURLComponents string]. If the component does not exist in the NSURLComponents object, {NSNotFound, 0} is returned. Note: Zero length components are legal. For example, the URL string "scheme://:\@/?\#" has a zero length user, password, host, query and fragment; the URL strings "scheme:" and "" both have a zero length path.
     * @return The converted Objective-C result.
     */
        Range range_of_scheme() const;
        /**
     * @brief Returns the `rangeOfUser` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        Range range_of_user() const;
        /**
     * @brief Returns the `scheme` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        std::string scheme() const;
        /**
     * @brief Sets the `scheme` property of `NSURLComponents`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_scheme(const std::string& value) const;
        /**
     * @brief Returns the `string` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        std::string string() const;
        /**
     * @brief Returns the `user` property of `NSURLComponents`.
     * @return The converted Objective-C result.
     */
        std::string user() const;
        /**
     * @brief Sets the `user` property of `NSURLComponents`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_user(const std::string& value) const;
    };
}
