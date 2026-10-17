#include "generated/url_credential.h"
#include "internal.h"

namespace cocoon
{
    URLCredential::URLCredential(const SecIdentity& identity, const std::vector<Object>& cert_array, URLCredentialPersistence persistence) : URLCredential(Adopt{cocoon::internal::retain([[::NSURLCredential alloc] initWithIdentity:((::SecIdentityRef)(identity).handle())
                                                                                                                                                                                                           certificates:cocoon::internal::to_array(cert_array, [](const Object& e) -> id
                                                                                                                                                                                                                                     {
                                                                                                                                                                                                                                         return cocoon::internal::native_id(e);
                                                                                                                                                                                                                                     })
                                                                                                                                                                                                            persistence:static_cast<::NSURLCredentialPersistence>(persistence)])})
    {
    }

    URLCredential::URLCredential(const SecTrust& trust) : URLCredential(Adopt{cocoon::internal::retain([[::NSURLCredential alloc] initWithTrust:((::SecTrustRef)(trust).handle())])})
    {
    }

    URLCredential::URLCredential(const std::string& user, const std::string& password, URLCredentialPersistence persistence) : URLCredential(Adopt{cocoon::internal::retain([[::NSURLCredential alloc] initWithUser:cocoon::internal::to(user) password:cocoon::internal::to(password) persistence:static_cast<::NSURLCredentialPersistence>(persistence)])})
    {
    }

    URLCredential::URLCredential() : URLCredential(Adopt{cocoon::internal::retain([[::NSURLCredential alloc] init])})
    {
    }

    URLCredential::URLCredential(std::nullptr_t) : Object(nullptr)
    {
    }

    URLCredential::URLCredential(Adopt adopt) : Object(adopt)
    {
    }

    URLCredential URLCredential::credential_for_trust(const SecTrust& trust)
    {
        return cocoon::internal::wrap<URLCredential>([::NSURLCredential credentialForTrust:((::SecTrustRef)(trust).handle())]);
    }

    URLCredential URLCredential::credential_with_identity(const SecIdentity& identity, const std::vector<Object>& cert_array, URLCredentialPersistence persistence)
    {
        return cocoon::internal::wrap<URLCredential>([::NSURLCredential credentialWithIdentity:((::SecIdentityRef)(identity).handle())
                                                                    certificates:cocoon::internal::to_array(cert_array, [](const Object& e) -> id
                                                                                              {
                                                                                                  return cocoon::internal::native_id(e);
                                                                                              })
                                                                     persistence:static_cast<::NSURLCredentialPersistence>(persistence)]);
    }

    URLCredential URLCredential::credential_with_user(const std::string& user, const std::string& password, URLCredentialPersistence persistence)
    {
        return cocoon::internal::wrap<URLCredential>([::NSURLCredential credentialWithUser:cocoon::internal::to(user) password:cocoon::internal::to(password) persistence:static_cast<::NSURLCredentialPersistence>(persistence)]);
    }

    std::vector<Object> URLCredential::certificates() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSURLCredential>(this) certificates], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    bool URLCredential::has_password() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLCredential>(this) hasPassword]);
    }

    SecIdentity URLCredential::identity() const
    {
        return cocoon::internal::wrap_cf<SecIdentity>((const void*)([cocoon::internal::ns<::NSURLCredential>(this) identity]));
    }

    std::string URLCredential::password() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLCredential>(this) password]);
    }

    URLCredentialPersistence URLCredential::persistence() const
    {
        return static_cast<URLCredentialPersistence>([cocoon::internal::ns<::NSURLCredential>(this) persistence]);
    }

    std::string URLCredential::user() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLCredential>(this) user]);
    }
}
