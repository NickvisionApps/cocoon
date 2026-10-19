#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;
    class HTTPCookie;
    class SortDescriptor;
    class URL;
    class URLSessionTask;

    /**
     * @brief C++ handle for the Objective-C class `NSHTTPCookieStorage` (Foundation).
     * @details \@class NSHTTPCookieStorage \@discussion NSHTTPCookieStorage implements a singleton object (shared instance) which manages the shared cookie store. It has methods to allow clients to set and remove cookies, and get the current set of cookies. It also has convenience methods to parse and generate cookie-related HTTP header fields.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::HTTPCookieStorage http_cookie_storage;
     * http_cookie_storage.set_cookie_accept_policy(cocoon::HTTPCookieAcceptPolicy::Always);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::HTTPCookieStorage http_cookie_storage{};
     * http_cookie_storage.set_cookie_accept_policy(cocoon::HTTPCookieAcceptPolicy::Always);
     * auto cookie_accept_policy = http_cookie_storage.cookie_accept_policy();
     * auto made_0 = cocoon::HTTPCookieStorage::shared_cookie_storage_for_group_container_identifier("text");
     * http_cookie_storage.cookies_for_url(cocoon::URL());
     * http_cookie_storage.delete_cookie(cocoon::HTTPCookie());
     * http_cookie_storage.remove_cookies_since_date(cocoon::Date());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nshttpcookiestorage
     */
    class HTTPCookieStorage : public Object
    {
    public:
        /// @brief Creates a new `NSHTTPCookieStorage` instance and returns a handle to it.
        explicit HTTPCookieStorage();
        /// @brief Creates a null handle that refers to no native object.
        HTTPCookieStorage(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit HTTPCookieStorage(Adopt adopt);
        /**
     * @brief Calls `-[NSHTTPCookieStorage cookiesForURL:]`.
     * @details \@method cookiesForURL: \@abstract Returns an array of cookies to send to the given URL. \@param URL The URL for which to get cookies. \@result an NSArray of NSHTTPCookie objects. \@discussion The cookie manager examines the cookies it stores and includes those which should be sent to the given URL. You can use \<tt>+[NSCookie requestHeaderFieldsWithCookies:]\</tt> to turn this array into a set of header fields to add to a request.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<HTTPCookie> cookies_for_url(const URL& url) const;
        /**
     * @brief Calls `-[NSHTTPCookieStorage deleteCookie:]`.
     * @details \@method deleteCookie: \@abstract Delete the specified cookie
     * @param cookie Argument converted to the Objective-C parameter of the same role.
     */
        void delete_cookie(const HTTPCookie& cookie) const;
        /**
     * @brief Calls `-[NSHTTPCookieStorage getCookiesForTask:completionHandler:]`.
     * @param task Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void get_cookies_for_task(const URLSessionTask& task, std::function<void(std::vector<HTTPCookie>)> completion_handler) const;
        /**
     * @brief Calls `-[NSHTTPCookieStorage removeCookiesSinceDate:]`.
     * @details \@method removeCookiesSince: \@abstract Delete all cookies from the cookie storage since the provided date.
     * @param date Argument converted to the Objective-C parameter of the same role.
     */
        void remove_cookies_since_date(const Date& date) const;
        /**
     * @brief Calls `-[NSHTTPCookieStorage setCookie:]`.
     * @details \@method setCookie: \@abstract Set a cookie \@discussion The cookie will override an existing cookie with the same name, domain and path, if any.
     * @param cookie Argument converted to the Objective-C parameter of the same role.
     */
        void set_cookie(const HTTPCookie& cookie) const;
        /**
     * @brief Calls `-[NSHTTPCookieStorage setCookies:forURL:mainDocumentURL:]`.
     * @details \@method setCookies:forURL:mainDocumentURL: \@abstract Adds an array cookies to the cookie store, following the cookie accept policy. \@param cookies The cookies to set. \@param URL The URL from which the cookies were sent. \@param mainDocumentURL The main document URL to be used as a base for the "same domain as main document" policy. \@discussion For mainDocumentURL, the caller should pass the URL for an appropriate main document, if known. For example, when loading a web page, the URL of the main html document for the top-level frame should be passed. To save cookies based on a set of response headers, you can use \<tt>+[NSCookie cookiesWithResponseHeaderFields:forURL:]\</tt> on a header field dictionary and then use this method to store the resulting cookies in accordance with policy settings.
     * @param cookies Argument converted to the Objective-C parameter of the same role.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param main_document_url Argument converted to the Objective-C parameter of the same role.
     */
        void set_cookies(const std::vector<HTTPCookie>& cookies, const URL& url, const URL& main_document_url) const;
        /**
     * @brief Calls `+[NSHTTPCookieStorage sharedCookieStorageForGroupContainerIdentifier:]`.
     * @details \@method sharedCookieStorageForGroupContainerIdentifier: \@abstract Get the cookie storage for the container associated with the specified application group identifier \@param identifier The application group identifier \@result A cookie storage with a persistent store in the application group container \@discussion By default, applications and associated app extensions have different data containers, which means that the sharedHTTPCookieStorage singleton will refer to different persistent cookie stores in an application and any app extensions that it contains. This method allows clients to create a persistent cookie storage that can be shared among all applications and extensions with access to the same application group. Subsequent calls to this method with the same identifier will return the same cookie storage instance.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static HTTPCookieStorage shared_cookie_storage_for_group_container_identifier(const std::string& identifier);
        /**
     * @brief Calls `-[NSHTTPCookieStorage sortedCookiesUsingDescriptors:]`.
     * @details \@method sortedCookiesUsingDescriptors: \@abstract Returns an array of all cookies in the store, sorted according to the key value and sorting direction of the NSSortDescriptors specified in the parameter. \@param sortOrder an array of NSSortDescriptors which represent the preferred sort order of the resulting array. \@discussion proper sorting of cookies may require extensive string conversion, which can be avoided by allowing the system to perform the sorting. This API is to be preferred over the more generic -[NSHTTPCookieStorage cookies] API, if sorting is going to be performed.
     * @param sort_order Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<HTTPCookie> sorted_cookies_using_descriptors(const std::vector<SortDescriptor>& sort_order) const;
        /**
     * @brief Calls `-[NSHTTPCookieStorage storeCookies:forTask:]`.
     * @param cookies Argument converted to the Objective-C parameter of the same role.
     * @param task Argument converted to the Objective-C parameter of the same role.
     */
        void store_cookies(const std::vector<HTTPCookie>& cookies, const URLSessionTask& task) const;
        /**
     * @brief Returns the `cookieAcceptPolicy` property of `NSHTTPCookieStorage`.
     * @details \@abstract The cookie accept policy preference of the receiver.
     * @return The converted Objective-C result.
     */
        HTTPCookieAcceptPolicy cookie_accept_policy() const;
        /**
     * @brief Sets the `cookieAcceptPolicy` property of `NSHTTPCookieStorage`.
     * @details \@abstract The cookie accept policy preference of the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_cookie_accept_policy(HTTPCookieAcceptPolicy value) const;
        /**
     * @brief Returns the `cookies` property of `NSHTTPCookieStorage`.
     * @details \@abstract Get all the cookies \@result An NSArray of NSHTTPCookies
     * @return The converted Objective-C result.
     */
        std::vector<HTTPCookie> cookies() const;
        /**
     * @brief Returns the `sharedHTTPCookieStorage` property of `NSHTTPCookieStorage`.
     * @details \@property sharedHTTPCookieStorage \@abstract Get the shared cookie storage in the default location. \@result The shared cookie storage \@discussion Starting in OS X 10.11, each app has its own sharedHTTPCookieStorage singleton, which will not be shared with other applications.
     * @return The converted Objective-C result.
     */
        static HTTPCookieStorage shared_http_cookie_storage();
    };
}
