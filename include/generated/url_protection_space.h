#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class SecTrust;

    /**
     * @brief C++ handle for the Objective-C class `NSURLProtectionSpace` (Foundation).
     * @details A server or an area on a server, commonly referred to as a realm, that requires authentication. A protection space defines a series of matching constraints that determine which credential should be provided. For example, if a request provides your delegate with a ''URLAuthenticationChallenge'' object that requests a client username and password, your app should provide the correct username and password for the particular host, port, protocol, and realm, as specified in the challenge's protection space. > Note: > This class has no designated initializer; its 'init' method always returns 'nil'. You must initialize this class by calling one of the initialization methods described in Creating a protection space.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLProtectionSpace url_protection_space;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlprotectionspace
     */
    class URLProtectionSpace : public Object
    {
    public:
        /// @brief Creates a new `NSURLProtectionSpace` instance and returns a handle to it.
        explicit URLProtectionSpace(const std::string& host, std::int64_t port, const std::string& protocol, const std::string& realm, const std::string& authentication_method);
        /// @brief Creates a new `NSURLProtectionSpace` instance and returns a handle to it.
        explicit URLProtectionSpace();
        /// @brief Creates a null handle that refers to no native object.
        URLProtectionSpace(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLProtectionSpace(Adopt adopt);
        /**
         * @brief Returns the `authenticationMethod` property of `NSURLProtectionSpace`.
         * @details The authentication method used by the receiver.
         * @return The converted Objective-C result.
         */
        std::string authentication_method() const;
        /**
         * @brief Returns the `distinguishedNames` property of `NSURLProtectionSpace`.
         * @details The acceptable certificate-issuing authorities for client certificate authentication. Issuers are identified by their distinguished name and returned as DER encoded data. This value is 'nil' if the authentication method is not 'NSURLAuthenticationMethodClientCertificate'.
         * @return The converted Objective-C result.
         */
        std::vector<std::vector<std::uint8_t>> distinguished_names() const;
        /**
         * @brief Returns the `host` property of `NSURLProtectionSpace`.
         * @details The receiver's host.
         * @return The converted Objective-C result.
         */
        std::string host() const;
        /**
         * @brief Returns the `isProxy` property of `NSURLProtectionSpace`.
         * @details A Boolean value that indicates whether this authenticating protection space is a proxy server.
         * @return The converted Objective-C result.
         */
        bool is_proxy() const;
        /**
         * @brief Returns the `port` property of `NSURLProtectionSpace`.
         * @details The receiver's port.
         * @return The converted Objective-C result.
         */
        std::int64_t port() const;
        /**
         * @brief Returns the `protocol` property of `NSURLProtectionSpace`.
         * @details The receiver's protocol. This value is 'nil' if the receiver represents a proxy protection space.
         * @return The converted Objective-C result.
         */
        std::string protocol() const;
        /**
         * @brief Returns the `proxyType` property of `NSURLProtectionSpace`.
         * @details The receiver's proxy type. This value is 'nil' if the receiver does not represent a proxy protection space.
         * @return The converted Objective-C result.
         */
        std::string proxy_type() const;
        /**
         * @brief Returns the `realm` property of `NSURLProtectionSpace`.
         * @details The receiver's authentication realm. This value is 'nil' if no realm has been set. A realm is generally only specified for HTTP and HTTPS authentication.
         * @return The converted Objective-C result.
         */
        std::string realm() const;
        /**
         * @brief Returns the `receivesCredentialSecurely` property of `NSURLProtectionSpace`.
         * @details A Boolean value that indicates whether the credentials for the protection space can be sent securely.
         * @return The converted Objective-C result.
         */
        bool receives_credential_securely() const;
        /**
         * @brief Returns the `serverTrust` property of `NSURLProtectionSpace`.
         * @details A representation of the server's SSL transaction state. This value is 'nil' if the authentication method is not 'NSURLAuthenticationMethodServerTrust'.
         * @return The converted Objective-C result.
         */
        SecTrust server_trust() const;
    };
}
