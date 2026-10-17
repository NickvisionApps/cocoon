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
     * @details An object that parses URLs into and constructs URLs from their constituent parts. In Swift, this object bridges to ''URLComponents''; use ''NSURLComponents'' when you need reference semantics or other Foundation-specific behavior. The ''NSURLComponents'' class is a class that is designed to parse URLs based on [RFC 3986](http://www.ietf.org/rfc/rfc3986.txt) and to construct URLs from their constituent parts. Its behavior differs subtly from the ''NSURL'' class, which conforms to older RFCs. However, you can easily obtain an ''NSURL'' object based on the contents of a URL components object or vice versa. You create a URL components object in one of three ways: from an ''NSString'' object that contains a URL, from an ''NSURL'' object, or from scratch by using the default initializer. From there, you can modify the URL's individual components and subcomponents by modifying various properties, either in unencoded form or in URL-encoded form. If you set the unencoded property, you can then obtain the encoded equivalent by reading the encoded property value and vice versa. > Important: > The Swift overlay to the Foundation framework provides the ''URLComponents'' structure, which bridges to the ''NSURLComponents'' class. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>.
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
     * @details Returns a URL object derived from the components object, relative to a base URL. If the components object has an authority component (user, password, host, or port) and a path component, then the path must either begin with '"/"' or be an empty string. Otherwise, this method returns 'nil'. If the components object does not have an authority component (user, password, host, or port) and has a path component, the path component must not start with '"//"'. If it does, this method returns 'nil'. - Parameter baseURL: If non-'nil', this URL is used as the base URL portion of the resulting URL object.
     * @param base_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_relative_to_url(const URL& base_url) const;
        /**
     * @brief Calls `+[NSURLComponents componentsWithString:]`.
     * @details Returns a URL components object by parsing a URL in string form. - Parameter URLString: The URL string to parse. - Returns: Returns the new URL components object, or 'nil' if the URL string could not be parsed.
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
     * @details Returns a URL components object by parsing the URL from an 'NSURL' object. - Parameters: - url: The URL to parse. - resolve: Controls whether the URL should be resolved against its base URL before parsing. If 'YES', and if the 'url' parameter contains a relative URL, the original URL is resolved against its base URL before parsing by calling the 'absoluteURL' method. Otherwise, the string portion is used by itself. - Returns: Returns the new URL components object, or 'nil' if the URL could not be parsed.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param resolve Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URLComponents components_with_url(const URL& url, bool resolve);
        /**
     * @brief Returns the `URL` property of `NSURLComponents`.
     * @details A URL object derived from the components object. If the receiver has an authority component (user, password, host, or port) and a path component, then the path must either begin with '"/"' or be an empty string. Otherwise, this property contains 'nil'. If the receiver does not have an authority component (user, password, host, or port) and has a path component, the path component must not start with '"//"'. If it does, this property contains 'nil'.
     * @return The converted Objective-C result.
     */
        URL url() const;
        /**
     * @brief Returns the `encodedHost` property of `NSURLComponents`.
     * @details The host subcomponent, percent-encoded. The getter for this property retains any percent-encoding this component may have. Setting this property assumes the component string already has the correct percent-encoding. Attempting to set an incorrectly percent-encoded string raises an exception.
     * @return The converted Objective-C result.
     */
        std::string encoded_host() const;
        /**
     * @brief Sets the `encodedHost` property of `NSURLComponents`.
     * @details The host subcomponent, percent-encoded. The getter for this property retains any percent-encoding this component may have. Setting this property assumes the component string already has the correct percent-encoding. Attempting to set an incorrectly percent-encoded string raises an exception.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_encoded_host(const std::string& value) const;
        /**
     * @brief Returns the `fragment` property of `NSURLComponents`.
     * @details The fragment URL component (the part after a '\#' symbol), or 'nil' if not present. For example, in the URL 'http://www.example.com/index.html\#jumpLocation', the fragment is 'jumpLocation'. Getting this property removes any percent encoding this component may have. Setting this property assumes the string is not percent encoded and will add percent encoding.
     * @return The converted Objective-C result.
     */
        std::string fragment() const;
        /**
     * @brief Sets the `fragment` property of `NSURLComponents`.
     * @details The fragment URL component (the part after a '\#' symbol), or 'nil' if not present. For example, in the URL 'http://www.example.com/index.html\#jumpLocation', the fragment is 'jumpLocation'. Getting this property removes any percent encoding this component may have. Setting this property assumes the string is not percent encoded and will add percent encoding.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_fragment(const std::string& value) const;
        /**
     * @brief Returns the `host` property of `NSURLComponents`.
     * @details The host URL subcomponent, or 'nil' if not present. For example, in the URL 'http://www.example.com/index.html', the host is 'www.example.com'. Getting this property removes any percent encoding this component may have. Setting this property assumes the string is not percent encoded and will add percent encoding.
     * @return The converted Objective-C result.
     */
        std::string host() const;
        /**
     * @brief Sets the `host` property of `NSURLComponents`.
     * @details The host URL subcomponent, or 'nil' if not present. For example, in the URL 'http://www.example.com/index.html', the host is 'www.example.com'. Getting this property removes any percent encoding this component may have. Setting this property assumes the string is not percent encoded and will add percent encoding.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_host(const std::string& value) const;
        /**
     * @brief Returns the `password` property of `NSURLComponents`.
     * @details The password URL subcomponent, or 'nil' if not present. For example, in the URL 'http://username:password\@www.example.com/index.html', the password is 'password'. Getting this property removes any percent encoding this component may have. Setting this property assumes the string is not percent encoded and will add percent encoding.
     * @return The converted Objective-C result.
     */
        std::string password() const;
        /**
     * @brief Sets the `password` property of `NSURLComponents`.
     * @details The password URL subcomponent, or 'nil' if not present. For example, in the URL 'http://username:password\@www.example.com/index.html', the password is 'password'. Getting this property removes any percent encoding this component may have. Setting this property assumes the string is not percent encoded and will add percent encoding.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_password(const std::string& value) const;
        /**
     * @brief Returns the `path` property of `NSURLComponents`.
     * @details The path URL component, or 'nil' if not present. For example, in the URL 'http://www.example.com/index.html', the path is '/index.html'. Getting this property removes any percent encoding this component may have. Setting this property assumes the string is not percent encoded and will add percent encoding.
     * @return The converted Objective-C result.
     */
        std::string path() const;
        /**
     * @brief Sets the `path` property of `NSURLComponents`.
     * @details The path URL component, or 'nil' if not present. For example, in the URL 'http://www.example.com/index.html', the path is '/index.html'. Getting this property removes any percent encoding this component may have. Setting this property assumes the string is not percent encoded and will add percent encoding.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_path(const std::string& value) const;
        /**
     * @brief Returns the `percentEncodedFragment` property of `NSURLComponents`.
     * @details The fragment URL component (the part after a '\#' symbol) expressed as a URL-encoded string, or 'nil' if not present. If you set this value to something that is not a valid, percent-encoded string, this class throws an exception.
     * @return The converted Objective-C result.
     */
        std::string percent_encoded_fragment() const;
        /**
     * @brief Sets the `percentEncodedFragment` property of `NSURLComponents`.
     * @details The fragment URL component (the part after a '\#' symbol) expressed as a URL-encoded string, or 'nil' if not present. If you set this value to something that is not a valid, percent-encoded string, this class throws an exception.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_percent_encoded_fragment(const std::string& value) const;
        /**
     * @brief Returns the `percentEncodedHost` property of `NSURLComponents`.
     * @details The host URL subcomponent expressed as a URL-encoded string, or 'nil' if not present. If you set this value to something that is not a valid, percent-encoded string, this class throws an exception.
     * @return The converted Objective-C result.
     */
        std::string percent_encoded_host() const;
        /**
     * @brief Sets the `percentEncodedHost` property of `NSURLComponents`.
     * @details The host URL subcomponent expressed as a URL-encoded string, or 'nil' if not present. If you set this value to something that is not a valid, percent-encoded string, this class throws an exception.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_percent_encoded_host(const std::string& value) const;
        /**
     * @brief Returns the `percentEncodedPassword` property of `NSURLComponents`.
     * @details The password URL subcomponent expressed as a URL-encoded string, or 'nil' if not present. If you set this value to something that is not a valid, percent-encoded string, this class throws an exception.
     * @return The converted Objective-C result.
     */
        std::string percent_encoded_password() const;
        /**
     * @brief Sets the `percentEncodedPassword` property of `NSURLComponents`.
     * @details The password URL subcomponent expressed as a URL-encoded string, or 'nil' if not present. If you set this value to something that is not a valid, percent-encoded string, this class throws an exception.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_percent_encoded_password(const std::string& value) const;
        /**
     * @brief Returns the `percentEncodedPath` property of `NSURLComponents`.
     * @details The path URL component expressed as a URL-encoded string, or 'nil' if not present. If you set this value to something that is not a valid, percent-encoded string, this class throws an exception. Although an unencoded semicolon is a valid character in a percent-encoded path, for compatibility with 'NSURL', you should always percent-encode it.
     * @return The converted Objective-C result.
     */
        std::string percent_encoded_path() const;
        /**
     * @brief Sets the `percentEncodedPath` property of `NSURLComponents`.
     * @details The path URL component expressed as a URL-encoded string, or 'nil' if not present. If you set this value to something that is not a valid, percent-encoded string, this class throws an exception. Although an unencoded semicolon is a valid character in a percent-encoded path, for compatibility with 'NSURL', you should always percent-encode it.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_percent_encoded_path(const std::string& value) const;
        /**
     * @brief Returns the `percentEncodedQuery` property of `NSURLComponents`.
     * @details The query URL component expressed as a URL-encoded string, or 'nil' if not present. If you set this value to something that is not a valid, percent-encoded string, this class throws an exception.
     * @return The converted Objective-C result.
     */
        std::string percent_encoded_query() const;
        /**
     * @brief Sets the `percentEncodedQuery` property of `NSURLComponents`.
     * @details The query URL component expressed as a URL-encoded string, or 'nil' if not present. If you set this value to something that is not a valid, percent-encoded string, this class throws an exception.
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
     * @details The username URL subcomponent expressed as a URL-encoded string, or 'nil' if not present. If you set this value to something that is not a valid, percent-encoded string, this class throws an exception.
     * @return The converted Objective-C result.
     */
        std::string percent_encoded_user() const;
        /**
     * @brief Sets the `percentEncodedUser` property of `NSURLComponents`.
     * @details The username URL subcomponent expressed as a URL-encoded string, or 'nil' if not present. If you set this value to something that is not a valid, percent-encoded string, this class throws an exception.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_percent_encoded_user(const std::string& value) const;
        /**
     * @brief Returns the `port` property of `NSURLComponents`.
     * @details The port number URL component, or 'nil' if not present. For example, in the URL 'http://www.example.com:8080/index.php', the port number is '8080'. Attempting to set a negative port number will cause an exception.
     * @return The converted Objective-C result.
     */
        Number port() const;
        /**
     * @brief Sets the `port` property of `NSURLComponents`.
     * @details The port number URL component, or 'nil' if not present. For example, in the URL 'http://www.example.com:8080/index.php', the port number is '8080'. Attempting to set a negative port number will cause an exception.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_port(const Number& value) const;
        /**
     * @brief Returns the `query` property of `NSURLComponents`.
     * @details The query URL component as a string, or 'nil' if not present. For example, in the URL 'http://www.example.com/index.php?key1=value1&key2=value2', the query string is 'key1=value1&key2=value2'. Getting this property removes any percent encoding this component may have. Setting this property assumes the string is not percent encoded and will add percent encoding.
     * @return The converted Objective-C result.
     */
        std::string query() const;
        /**
     * @brief Sets the `query` property of `NSURLComponents`.
     * @details The query URL component as a string, or 'nil' if not present. For example, in the URL 'http://www.example.com/index.php?key1=value1&key2=value2', the query string is 'key1=value1&key2=value2'. Getting this property removes any percent encoding this component may have. Setting this property assumes the string is not percent encoded and will add percent encoding.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_query(const std::string& value) const;
        /**
     * @brief Returns the `queryItems` property of `NSURLComponents`.
     * @details The query URL component as an array of name/value pairs. When you get this property's value, the 'NSURLComponents' class parses the 'query' string and returns an array of 'NSURLQueryItem' objects, each of which represents a single key-value pair, in the order in which they appear in the original query string. Because a name may appear more than once in a single query string, the name properties of query items are not guaranteed to be unique. If the 'query' property is an empty string, the 'queryItems' property is an empty array. If the 'query' property is 'nil', the 'queryItems' property is also 'nil'. When you set this property's value, the 'NSURLComponents' class joins each name/value pair with a '=' delimiter and joins the array with a '&' delimiter, then sets the 'query' property to the resulting string. Setting this property to an empty array sets the 'query' property to an empty string. Setting this property to 'nil' sets the 'query' property to 'nil'.
     * @return The converted Objective-C result.
     */
        std::vector<URLQueryItem> query_items() const;
        /**
     * @brief Sets the `queryItems` property of `NSURLComponents`.
     * @details The query URL component as an array of name/value pairs. When you get this property's value, the 'NSURLComponents' class parses the 'query' string and returns an array of 'NSURLQueryItem' objects, each of which represents a single key-value pair, in the order in which they appear in the original query string. Because a name may appear more than once in a single query string, the name properties of query items are not guaranteed to be unique. If the 'query' property is an empty string, the 'queryItems' property is an empty array. If the 'query' property is 'nil', the 'queryItems' property is also 'nil'. When you set this property's value, the 'NSURLComponents' class joins each name/value pair with a '=' delimiter and joins the array with a '&' delimiter, then sets the 'query' property to the resulting string. Setting this property to an empty array sets the 'query' property to an empty string. Setting this property to 'nil' sets the 'query' property to 'nil'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_query_items(const std::vector<URLQueryItem>& value) const;
        /**
     * @brief Returns the `rangeOfFragment` property of `NSURLComponents`.
     * @details Returns the character range of the fragment in the URL string returned by the 'string' property. If the component does not exist in the 'NSURLComponents' object, '{NSNotFound, 0}' is returned.
     * @return The converted Objective-C result.
     */
        Range range_of_fragment() const;
        /**
     * @brief Returns the `rangeOfHost` property of `NSURLComponents`.
     * @details Returns the character range of the host in the URL string returned by the 'string' property. If the component does not exist in the 'NSURLComponents' object, '{NSNotFound, 0}' is returned.
     * @return The converted Objective-C result.
     */
        Range range_of_host() const;
        /**
     * @brief Returns the `rangeOfPassword` property of `NSURLComponents`.
     * @details Returns the character range of the password in the URL string returned by the 'string' property. If the component does not exist in the 'NSURLComponents' object, '{NSNotFound, 0}' is returned.
     * @return The converted Objective-C result.
     */
        Range range_of_password() const;
        /**
     * @brief Returns the `rangeOfPath` property of `NSURLComponents`.
     * @details Returns the character range of the path in the URL string returned by the 'string' property. If the component does not exist in the 'NSURLComponents' object, '{NSNotFound, 0}' is returned.
     * @return The converted Objective-C result.
     */
        Range range_of_path() const;
        /**
     * @brief Returns the `rangeOfPort` property of `NSURLComponents`.
     * @details Returns the character range of the port in the URL string returned by the 'string' property. If the component does not exist in the 'NSURLComponents' object, '{NSNotFound, 0}' is returned.
     * @return The converted Objective-C result.
     */
        Range range_of_port() const;
        /**
     * @brief Returns the `rangeOfQuery` property of `NSURLComponents`.
     * @details Returns the character range of the query in the URL string returned by the 'string' property. If the component does not exist in the 'NSURLComponents' object, '{NSNotFound, 0}' is returned.
     * @return The converted Objective-C result.
     */
        Range range_of_query() const;
        /**
     * @brief Returns the `rangeOfScheme` property of `NSURLComponents`.
     * @details Returns the character range of the scheme in the URL string returned by the 'string' property. If the component does not exist in the 'NSURLComponents' object, '{NSNotFound, 0}' is returned.
     * @return The converted Objective-C result.
     */
        Range range_of_scheme() const;
        /**
     * @brief Returns the `rangeOfUser` property of `NSURLComponents`.
     * @details Returns the character range of the user in the URL string returned by the 'string' property. If the component does not exist in the 'NSURLComponents' object, '{NSNotFound, 0}' is returned.
     * @return The converted Objective-C result.
     */
        Range range_of_user() const;
        /**
     * @brief Returns the `scheme` property of `NSURLComponents`.
     * @details The scheme URL component, or 'nil' if not present. For example, in the URL 'http://www.example.com/index.html', the scheme is 'http'. Attempting to set the scheme with an invalid scheme string will cause an exception.
     * @return The converted Objective-C result.
     */
        std::string scheme() const;
        /**
     * @brief Sets the `scheme` property of `NSURLComponents`.
     * @details The scheme URL component, or 'nil' if not present. For example, in the URL 'http://www.example.com/index.html', the scheme is 'http'. Attempting to set the scheme with an invalid scheme string will cause an exception.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_scheme(const std::string& value) const;
        /**
     * @brief Returns the `string` property of `NSURLComponents`.
     * @details A URL derived from the components object, in string form. If the receiver has an authority component (user, password, host, or port) and a path component, then the path must either begin with '"/"' or be an empty string. Otherwise, this property contains 'nil'. If the receiver does not have an authority component (user, password, host, or port) and has a path component, the path component must not start with '"//"'. If it does, this property contains 'nil'.
     * @return The converted Objective-C result.
     */
        std::string string() const;
        /**
     * @brief Returns the `user` property of `NSURLComponents`.
     * @details The username URL subcomponent, or 'nil' if not present. For example, in the URL 'http://username:password\@www.example.com/index.html', the user is 'username'. Getting this property removes any percent encoding this component may have. Setting this property assumes the string is not percent encoded and will add percent encoding.
     * @return The converted Objective-C result.
     */
        std::string user() const;
        /**
     * @brief Sets the `user` property of `NSURLComponents`.
     * @details The username URL subcomponent, or 'nil' if not present. For example, in the URL 'http://username:password\@www.example.com/index.html', the user is 'username'. Getting this property removes any percent encoding this component may have. Setting this property assumes the string is not percent encoded and will add percent encoding.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_user(const std::string& value) const;
    };
}
