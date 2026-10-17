#include "generated/url_credential_storage.h"
#include "internal.h"

namespace cocoon
{
    URLCredentialStorage::URLCredentialStorage() : URLCredentialStorage(Adopt{cocoon::internal::retain([[::NSURLCredentialStorage alloc] init])})
    {
    }

    URLCredentialStorage::URLCredentialStorage(std::nullptr_t) : Object(nullptr)
    {
    }

    URLCredentialStorage::URLCredentialStorage(Adopt adopt) : Object(adopt)
    {
    }

    std::map<std::string, URLCredential> URLCredentialStorage::credentials_for_protection_space(const URLProtectionSpace& space) const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, URLCredential>>([cocoon::internal::ns<::NSURLCredentialStorage>(this) credentialsForProtectionSpace:cocoon::internal::native<::NSURLProtectionSpace>(space)], [](id k) -> std::string
                                                                         {
                                                                             return cocoon::internal::from((NSString*)k);
                                                                         },
                                                                         [](id v) -> URLCredential
                                                                         {
                                                                             return cocoon::internal::wrap<URLCredential>((::NSURLCredential*)v);
                                                                         });
    }

    URLCredential URLCredentialStorage::default_credential_for_protection_space(const URLProtectionSpace& space) const
    {
        return cocoon::internal::wrap<URLCredential>([cocoon::internal::ns<::NSURLCredentialStorage>(this) defaultCredentialForProtectionSpace:cocoon::internal::native<::NSURLProtectionSpace>(space)]);
    }

    void URLCredentialStorage::get_credentials_for_protection_space(const URLProtectionSpace& protection_space, const URLSessionTask& task, std::function<void(std::map<std::string, URLCredential>)> completion_handler) const
    {
        [cocoon::internal::ns<::NSURLCredentialStorage>(this) getCredentialsForProtectionSpace:cocoon::internal::native<::NSURLProtectionSpace>(protection_space) task:cocoon::internal::native<::NSURLSessionTask>(task) completionHandler:(completion_handler ? (void (^)(NSDictionary<NSString*, NSURLCredential*>*)) ^ void(NSDictionary * a230_0) { completion_handler(cocoon::internal::from_dictionary<std::map<std::string, URLCredential>>(a230_0, [](id k) -> std::string
                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                                                                                                                                                                                            },
                                                                                                                                                                                                                                                                                                                                                                                            [](id v) -> URLCredential
                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                return cocoon::internal::wrap<URLCredential>((::NSURLCredential*)v);
                                                                                                                                                                                                                                                                                                                                                                                            })); } : (void (^)(NSDictionary<NSString*, NSURLCredential*>*))nil)];
    }

    void URLCredentialStorage::get_default_credential_for_protection_space(const URLProtectionSpace& space, const URLSessionTask& task, std::function<void(URLCredential)> completion_handler) const
    {
        [cocoon::internal::ns<::NSURLCredentialStorage>(this) getDefaultCredentialForProtectionSpace:cocoon::internal::native<::NSURLProtectionSpace>(space) task:cocoon::internal::native<::NSURLSessionTask>(task) completionHandler:(completion_handler ? (void (^)(::NSURLCredential*)) ^ void(::NSURLCredential * a231_0) { completion_handler(cocoon::internal::wrap<URLCredential>(a231_0)); } : (void (^)(::NSURLCredential*))nil)];
    }

    void URLCredentialStorage::remove_credential(const URLCredential& credential, const URLProtectionSpace& space) const
    {
        [cocoon::internal::ns<::NSURLCredentialStorage>(this) removeCredential:cocoon::internal::native<::NSURLCredential>(credential) forProtectionSpace:cocoon::internal::native<::NSURLProtectionSpace>(space)];
    }

    void URLCredentialStorage::remove_credential(const URLCredential& credential, const URLProtectionSpace& space, const std::map<std::string, Object>& options) const
    {
        [cocoon::internal::ns<::NSURLCredentialStorage>(this) removeCredential:cocoon::internal::native<::NSURLCredential>(credential)
                                              forProtectionSpace:cocoon::internal::native<::NSURLProtectionSpace>(space)
                                                         options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                   {
                                                                                       return cocoon::internal::to(k);
                                                                                   },
                                                                                   [](const Object& v) -> id
                                                                                   {
                                                                                       return cocoon::internal::native_id(v);
                                                                                   })];
    }

    void URLCredentialStorage::remove_credential(const URLCredential& credential, const URLProtectionSpace& protection_space, const std::map<std::string, Object>& options, const URLSessionTask& task) const
    {
        [cocoon::internal::ns<::NSURLCredentialStorage>(this) removeCredential:cocoon::internal::native<::NSURLCredential>(credential)
                                              forProtectionSpace:cocoon::internal::native<::NSURLProtectionSpace>(protection_space)
                                                         options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                   {
                                                                                       return cocoon::internal::to(k);
                                                                                   },
                                                                                   [](const Object& v) -> id
                                                                                   {
                                                                                       return cocoon::internal::native_id(v);
                                                                                   })
                                                            task:cocoon::internal::native<::NSURLSessionTask>(task)];
    }

    void URLCredentialStorage::set_credential(const URLCredential& credential, const URLProtectionSpace& space) const
    {
        [cocoon::internal::ns<::NSURLCredentialStorage>(this) setCredential:cocoon::internal::native<::NSURLCredential>(credential) forProtectionSpace:cocoon::internal::native<::NSURLProtectionSpace>(space)];
    }

    void URLCredentialStorage::set_credential(const URLCredential& credential, const URLProtectionSpace& protection_space, const URLSessionTask& task) const
    {
        [cocoon::internal::ns<::NSURLCredentialStorage>(this) setCredential:cocoon::internal::native<::NSURLCredential>(credential) forProtectionSpace:cocoon::internal::native<::NSURLProtectionSpace>(protection_space) task:cocoon::internal::native<::NSURLSessionTask>(task)];
    }

    void URLCredentialStorage::set_default_credential(const URLCredential& credential, const URLProtectionSpace& space) const
    {
        [cocoon::internal::ns<::NSURLCredentialStorage>(this) setDefaultCredential:cocoon::internal::native<::NSURLCredential>(credential) forProtectionSpace:cocoon::internal::native<::NSURLProtectionSpace>(space)];
    }

    void URLCredentialStorage::set_default_credential(const URLCredential& credential, const URLProtectionSpace& protection_space, const URLSessionTask& task) const
    {
        [cocoon::internal::ns<::NSURLCredentialStorage>(this) setDefaultCredential:cocoon::internal::native<::NSURLCredential>(credential) forProtectionSpace:cocoon::internal::native<::NSURLProtectionSpace>(protection_space) task:cocoon::internal::native<::NSURLSessionTask>(task)];
    }

    std::vector<std::pair<URLProtectionSpace, std::map<std::string, URLCredential>>> URLCredentialStorage::all_credentials() const
    {
        return cocoon::internal::from_dictionary<std::vector<std::pair<URLProtectionSpace, std::map<std::string, URLCredential>>>>([cocoon::internal::ns<::NSURLCredentialStorage>(this) allCredentials], [](id k) -> URLProtectionSpace
                                                                                                                     {
                                                                                                                         return cocoon::internal::wrap<URLProtectionSpace>((::NSURLProtectionSpace*)k);
                                                                                                                     },
                                                                                                                     [](id v) -> std::map<std::string, URLCredential>
                                                                                                                     {
                                                                                                                         return cocoon::internal::from_dictionary<std::map<std::string, URLCredential>>((NSDictionary*)v, [](id k) -> std::string
                                                                                                                                                                                          {
                                                                                                                                                                                              return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                          },
                                                                                                                                                                                          [](id v) -> URLCredential
                                                                                                                                                                                          {
                                                                                                                                                                                              return cocoon::internal::wrap<URLCredential>((::NSURLCredential*)v);
                                                                                                                                                                                          });
                                                                                                                     });
    }

    URLCredentialStorage URLCredentialStorage::shared_credential_storage()
    {
        return cocoon::internal::wrap<URLCredentialStorage>([::NSURLCredentialStorage sharedCredentialStorage]);
    }
}
