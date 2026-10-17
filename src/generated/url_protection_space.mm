#include "generated/url_protection_space.h"
#include "internal.h"

namespace cocoon
{
    URLProtectionSpace::URLProtectionSpace(const std::string& host, std::int64_t port, const std::string& protocol, const std::string& realm, const std::string& authentication_method) : URLProtectionSpace(Adopt{cocoon::internal::retain([[::NSURLProtectionSpace alloc] initWithHost:cocoon::internal::to(host) port:static_cast<::NSInteger>(port) protocol:cocoon::internal::to(protocol) realm:cocoon::internal::to(realm) authenticationMethod:cocoon::internal::to(authentication_method)])})
    {
    }

    URLProtectionSpace::URLProtectionSpace() : URLProtectionSpace(Adopt{cocoon::internal::retain([[::NSURLProtectionSpace alloc] init])})
    {
    }

    URLProtectionSpace::URLProtectionSpace(std::nullptr_t) : Object(nullptr)
    {
    }

    URLProtectionSpace::URLProtectionSpace(Adopt adopt) : Object(adopt)
    {
    }

    std::string URLProtectionSpace::authentication_method() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLProtectionSpace>(this) authenticationMethod]);
    }

    std::vector<std::vector<std::uint8_t>> URLProtectionSpace::distinguished_names() const
    {
        return cocoon::internal::from_array<std::vector<std::uint8_t>>([cocoon::internal::ns<::NSURLProtectionSpace>(this) distinguishedNames], [](id e) -> std::vector<std::uint8_t>
                                                         {
                                                             return cocoon::internal::from_data((NSData*)e);
                                                         });
    }

    std::string URLProtectionSpace::host() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLProtectionSpace>(this) host]);
    }

    bool URLProtectionSpace::is_proxy() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLProtectionSpace>(this) isProxy]);
    }

    std::int64_t URLProtectionSpace::port() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSURLProtectionSpace>(this) port]);
    }

    std::string URLProtectionSpace::protocol() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLProtectionSpace>(this) protocol]);
    }

    std::string URLProtectionSpace::proxy_type() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLProtectionSpace>(this) proxyType]);
    }

    std::string URLProtectionSpace::realm() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLProtectionSpace>(this) realm]);
    }

    bool URLProtectionSpace::receives_credential_securely() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLProtectionSpace>(this) receivesCredentialSecurely]);
    }

    SecTrust URLProtectionSpace::server_trust() const
    {
        return cocoon::internal::wrap_cf<SecTrust>((const void*)([cocoon::internal::ns<::NSURLProtectionSpace>(this) serverTrust]));
    }
}
