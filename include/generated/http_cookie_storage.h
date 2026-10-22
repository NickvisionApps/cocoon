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
     * @details A container that manages the storage of cookies. Each stored cookie is represented by an instance of the ''HTTPCookie'' class. \#\#\# Sharing cookie storage The persistent cookie storage returned by ''shared'' may be available to app extensions or other apps, subject to the following guidelines: - iOS — Each app and app extension has a unique data container, meaning they have separate cookie stores. You can obtain a common cookie storage by using the ''sharedCookieStorage(forGroupContainerIdentifier:)'' method. - macOS (non-sandboxed) — As of macOS 10.11, each app has its own cookie storage. Prior to macOS 10.11, a common cookie store is shared among the user's apps. - macOS (sandboxed) — Same as iOS. - \<doc://com.apple.documentation/documentation/uikit/uiwebview> — 'UIWebView' instances within an app inherit the parent app's shared cookie storage. - \<doc://com.apple.documentation/documentation/webkit/wkwebview> — Each 'WKWebView' instance has its own cookie storage. See the \<doc://com.apple.documentation/documentation/webkit/wkhttpcookiestore> class for more information. Session cookies (where the cookie object's ''HTTPCookie/isSessionOnly'' property is \<doc://com.apple.documentation/documentation/swift/true>) are local to a single process and are not shared. > Note: > In cases where a cookie storage is shared between processes, changes made to the cookie accept policy affect all currently running apps using the cookie storage. \#\#\# Subclassing notes The ''HTTPCookieStorage'' class is usable as-is, but you can subclass it. For example, you can override the storage methods like ''storeCookies(:for:)'', ''getCookiesFor(:completionHandler:)'' to screen which cookies are stored, or reimplement the storage mechanism for security or other reasons. When overriding methods of this class, be aware that methods that take a 'task' parameter are preferred by the system to equivalent methods that do not. Therefore, you should override the task-based methods when subclassing, as follows: - Retrieving cookies — Override ''getCookiesFor(:completionHandler:)'', instead of or in addition to ''cookies(for:)''. - Adding cookies — Override ''storeCookies(:for:)'', instead of or in addition to ''setCookies(:for:mainDocumentURL:)''.
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
         * @details Returns all the cookie storage's cookies that are sent to a specified URL. - Parameter URL: The URL to filter on. - Returns: An array of cookies whose URL matches the provided URL. You can use '+[NSHTTPCookie requestHeaderFieldsWithCookies:]' to turn this array into a set of header fields to add to a request.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<HTTPCookie> cookies_for_url(const URL& url) const;
        /**
         * @brief Calls `-[NSHTTPCookieStorage deleteCookie:]`.
         * @details Deletes the specified cookie from the cookie storage.
         * @param cookie Argument converted to the Objective-C parameter of the same role.
         */
        void delete_cookie(const HTTPCookie& cookie) const;
        /**
         * @brief Calls `-[NSHTTPCookieStorage getCookiesForTask:completionHandler:]`.
         * @details Fetches cookies relevant to the specified task and passes them to the completion handler.
         * @param task Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void get_cookies_for_task(const URLSessionTask& task, std::function<void(std::vector<HTTPCookie>)> completion_handler) const;
        /**
         * @brief Calls `-[NSHTTPCookieStorage removeCookiesSinceDate:]`.
         * @details Removes cookies that were stored after a given date.
         * @param date Argument converted to the Objective-C parameter of the same role.
         */
        void remove_cookies_since_date(const Date& date) const;
        /**
         * @brief Calls `-[NSHTTPCookieStorage setCookie:]`.
         * @details Stores a specified cookie in the cookie storage if the cookie accept policy permits. The cookie replaces an existing cookie with the same name, domain, and path, if one exists.
         * @param cookie Argument converted to the Objective-C parameter of the same role.
         */
        void set_cookie(const HTTPCookie& cookie) const;
        /**
         * @brief Calls `-[NSHTTPCookieStorage setCookies:forURL:mainDocumentURL:]`.
         * @details Adds an array of cookies to the cookie store, following the cookie accept policy. - Parameter cookies: The cookies to set. - Parameter URL: The URL from which the cookies were sent. - Parameter mainDocumentURL: The main document URL to be used as a base for the "same domain as main document" policy. For 'mainDocumentURL', the caller should pass the URL for an appropriate main document, if known. For example, when loading a web page, the URL of the main html document for the top-level frame should be passed. To save cookies based on a set of response headers, you can use '+[NSHTTPCookie cookiesWithResponseHeaderFields:forURL:]' on a header field dictionary and then use this method to store the resulting cookies in accordance with policy settings.
         * @param cookies Argument converted to the Objective-C parameter of the same role.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @param main_document_url Argument converted to the Objective-C parameter of the same role.
         */
        void set_cookies(const std::vector<HTTPCookie>& cookies, const URL& url, const URL& main_document_url) const;
        /**
         * @brief Calls `+[NSHTTPCookieStorage sharedCookieStorageForGroupContainerIdentifier:]`.
         * @details Returns the cookie storage instance for the container associated with the specified app group identifier. - Parameter identifier: The application group identifier. - Returns: A cookie storage with a persistent store in the application group container. By default, apps and associated app extensions will have different data containers. As a result, the 'sharedHTTPCookieStorage' singleton will refer to different persistent cookie stores when called by the app and by its extensions. You can use this method to create a persistent cookie storage available to all apps and extensions with access to the same app group. Subsequent calls to this method with the same identifier will return the same cookie storage instance.
         * @param identifier Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static HTTPCookieStorage shared_cookie_storage_for_group_container_identifier(const std::string& identifier);
        /**
         * @brief Calls `-[NSHTTPCookieStorage sortedCookiesUsingDescriptors:]`.
         * @details Returns all of the cookie storage's cookies, sorted according to a given set of sort descriptors. - Parameter sortOrder: An array of 'NSSortDescriptor' objects which represent the preferred sort order of the resulting array. - Returns: The sorted array of cookies. Proper sorting of cookies may require extensive string conversion, which can be avoided by allowing the system to perform the sorting. This API is to be preferred over the more generic 'cookies' property, if sorting is going to be performed.
         * @param sort_order Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<HTTPCookie> sorted_cookies_using_descriptors(const std::vector<SortDescriptor>& sort_order) const;
        /**
         * @brief Calls `-[NSHTTPCookieStorage storeCookies:forTask:]`.
         * @details Stores an array of cookies in the cookie storage, on behalf of the provided task, if the cookie accept policy permits.
         * @param cookies Argument converted to the Objective-C parameter of the same role.
         * @param task Argument converted to the Objective-C parameter of the same role.
         */
        void store_cookies(const std::vector<HTTPCookie>& cookies, const URLSessionTask& task) const;
        /**
         * @brief Returns the `cookieAcceptPolicy` property of `NSHTTPCookieStorage`.
         * @details The cookie accept policy preference of the receiver. The default cookie accept policy is 'NSHTTPCookieAcceptPolicyAlways'.
         * @return The converted Objective-C result.
         */
        HTTPCookieAcceptPolicy cookie_accept_policy() const;
        /**
         * @brief Sets the `cookieAcceptPolicy` property of `NSHTTPCookieStorage`.
         * @details The cookie accept policy preference of the receiver. The default cookie accept policy is 'NSHTTPCookieAcceptPolicyAlways'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_cookie_accept_policy(HTTPCookieAcceptPolicy value) const;
        /**
         * @brief Returns the `cookies` property of `NSHTTPCookieStorage`.
         * @details The cookie storage's cookies. If you want to sort the cookie storage's cookies, you should use the 'sortedCookiesUsingDescriptors:' method instead of sorting the result of this property.
         * @return The converted Objective-C result.
         */
        std::vector<HTTPCookie> cookies() const;
        /**
         * @brief Returns the `sharedHTTPCookieStorage` property of `NSHTTPCookieStorage`.
         * @details The shared cookie storage instance. Starting in OS X 10.11, each app has its own 'sharedHTTPCookieStorage' singleton, which will not be shared with other applications.
         * @return The converted Objective-C result.
         */
        static HTTPCookieStorage shared_http_cookie_storage();
    };
}
