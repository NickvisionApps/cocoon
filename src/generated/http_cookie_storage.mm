#include "generated/http_cookie_storage.h"
#include "internal.h"

namespace cocoon
{
    HTTPCookieStorage::HTTPCookieStorage() : HTTPCookieStorage(Adopt{cocoon::internal::retain([[::NSHTTPCookieStorage alloc] init])})
    {
    }

    HTTPCookieStorage::HTTPCookieStorage(std::nullptr_t) : Object(nullptr)
    {
    }

    HTTPCookieStorage::HTTPCookieStorage(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<HTTPCookie> HTTPCookieStorage::cookies_for_url(const URL& url) const
    {
        return cocoon::internal::from_array<HTTPCookie>([cocoon::internal::ns<::NSHTTPCookieStorage>(this) cookiesForURL:cocoon::internal::native<::NSURL>(url)], [](id e) -> HTTPCookie
                                                        {
                                                            return cocoon::internal::wrap<HTTPCookie>((::NSHTTPCookie*)e);
                                                        });
    }

    void HTTPCookieStorage::delete_cookie(const HTTPCookie& cookie) const
    {
        [cocoon::internal::ns<::NSHTTPCookieStorage>(this) deleteCookie:cocoon::internal::native<::NSHTTPCookie>(cookie)];
    }

    void HTTPCookieStorage::get_cookies_for_task(const URLSessionTask& task, std::function<void(std::vector<HTTPCookie>)> completion_handler) const
    {
        [cocoon::internal::ns<::NSHTTPCookieStorage>(this) getCookiesForTask:cocoon::internal::native<::NSURLSessionTask>(task) completionHandler:(completion_handler ? (void (^)(NSArray<NSHTTPCookie*>*)) ^ void(NSArray * a156_0) { completion_handler(cocoon::internal::from_array<HTTPCookie>(a156_0, [](id e) -> HTTPCookie
                                                                                                                                                                                                                                                                                                   {
                                                                                                                                                                                                                                                                                                       return cocoon::internal::wrap<HTTPCookie>((::NSHTTPCookie*)e);
                                                                                                                                                                                                                                                                                                   })); } : (void (^)(NSArray<NSHTTPCookie*>*))nil)];
    }

    void HTTPCookieStorage::remove_cookies_since_date(const Date& date) const
    {
        [cocoon::internal::ns<::NSHTTPCookieStorage>(this) removeCookiesSinceDate:cocoon::internal::native<::NSDate>(date)];
    }

    void HTTPCookieStorage::set_cookie(const HTTPCookie& cookie) const
    {
        [cocoon::internal::ns<::NSHTTPCookieStorage>(this) setCookie:cocoon::internal::native<::NSHTTPCookie>(cookie)];
    }

    void HTTPCookieStorage::set_cookies(const std::vector<HTTPCookie>& cookies, const URL& url, const URL& main_document_url) const
    {
        [cocoon::internal::ns<::NSHTTPCookieStorage>(this) setCookies:cocoon::internal::to_array(cookies, [](const HTTPCookie& e) -> id
                                                                                                 {
                                                                                                     return cocoon::internal::native<::NSHTTPCookie>(e);
                                                                                                 })
                                                               forURL:cocoon::internal::native<::NSURL>(url)
                                                      mainDocumentURL:cocoon::internal::native<::NSURL>(main_document_url)];
    }

    HTTPCookieStorage HTTPCookieStorage::shared_cookie_storage_for_group_container_identifier(const std::string& identifier)
    {
        return cocoon::internal::wrap<HTTPCookieStorage>([::NSHTTPCookieStorage sharedCookieStorageForGroupContainerIdentifier:cocoon::internal::to(identifier)]);
    }

    std::vector<HTTPCookie> HTTPCookieStorage::sorted_cookies_using_descriptors(const std::vector<SortDescriptor>& sort_order) const
    {
        return cocoon::internal::from_array<HTTPCookie>([cocoon::internal::ns<::NSHTTPCookieStorage>(this) sortedCookiesUsingDescriptors:cocoon::internal::to_array(sort_order, [](const SortDescriptor& e) -> id
                                                                                                                                                                    {
                                                                                                                                                                        return cocoon::internal::native<::NSSortDescriptor>(e);
                                                                                                                                                                    })],
                                                        [](id e) -> HTTPCookie
                                                        {
                                                            return cocoon::internal::wrap<HTTPCookie>((::NSHTTPCookie*)e);
                                                        });
    }

    void HTTPCookieStorage::store_cookies(const std::vector<HTTPCookie>& cookies, const URLSessionTask& task) const
    {
        [cocoon::internal::ns<::NSHTTPCookieStorage>(this) storeCookies:cocoon::internal::to_array(cookies, [](const HTTPCookie& e) -> id
                                                                                                   {
                                                                                                       return cocoon::internal::native<::NSHTTPCookie>(e);
                                                                                                   })
                                                                forTask:cocoon::internal::native<::NSURLSessionTask>(task)];
    }

    HTTPCookieAcceptPolicy HTTPCookieStorage::cookie_accept_policy() const
    {
        return static_cast<HTTPCookieAcceptPolicy>([cocoon::internal::ns<::NSHTTPCookieStorage>(this) cookieAcceptPolicy]);
    }

    void HTTPCookieStorage::set_cookie_accept_policy(HTTPCookieAcceptPolicy value) const
    {
        [cocoon::internal::ns<::NSHTTPCookieStorage>(this) setCookieAcceptPolicy:static_cast<::NSHTTPCookieAcceptPolicy>(value)];
    }

    std::vector<HTTPCookie> HTTPCookieStorage::cookies() const
    {
        return cocoon::internal::from_array<HTTPCookie>([cocoon::internal::ns<::NSHTTPCookieStorage>(this) cookies], [](id e) -> HTTPCookie
                                                        {
                                                            return cocoon::internal::wrap<HTTPCookie>((::NSHTTPCookie*)e);
                                                        });
    }

    HTTPCookieStorage HTTPCookieStorage::shared_http_cookie_storage()
    {
        return cocoon::internal::wrap<HTTPCookieStorage>([::NSHTTPCookieStorage sharedHTTPCookieStorage]);
    }
}
