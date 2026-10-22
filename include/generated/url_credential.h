#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class SecIdentity;
    class SecTrust;

    /**
     * @brief C++ handle for the Objective-C class `NSURLCredential` (Foundation).
     * @details An authentication credential consisting of information specific to the type of credential and the type of persistent storage to use, if any. The URL Loading System supports password-based user credentials, certificate-based user credentials, and certificate-based server credentials. When you create a credential, you can specify it for a single request, persist it temporarily (until your app quits), or persist it permanently. Permanent persistence can be local persistence in the keychain, or synchronized persistence across the user's devices, based on their Apple ID. > Note: > Permanent storage of credentials is only available for password-based credentials. TLS credentials are never stored permanently by ''URLCredentialStorage''. In general, use for-session persistence for TLS credentials.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLCredential url_credential;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::URLCredential url_credential{};
     * auto made_0 = cocoon::URLCredential::credential_with_user("text", "text", cocoon::URLCredentialPersistence::None);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlcredential
     */
    class URLCredential : public Object
    {
    public:
        /// @brief Creates a new `NSURLCredential` instance and returns a handle to it.
        explicit URLCredential(const SecIdentity& identity, const std::vector<Object>& cert_array, URLCredentialPersistence persistence);
        /// @brief Creates a new `NSURLCredential` instance and returns a handle to it.
        explicit URLCredential(const SecTrust& trust);
        /// @brief Creates a new `NSURLCredential` instance and returns a handle to it.
        explicit URLCredential(const std::string& user, const std::string& password, URLCredentialPersistence persistence);
        /// @brief Creates a new `NSURLCredential` instance and returns a handle to it.
        explicit URLCredential();
        /// @brief Creates a null handle that refers to no native object.
        URLCredential(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLCredential(Adopt adopt);
        /**
         * @brief Calls `+[NSURLCredential credentialForTrust:]`.
         * @details Creates a URL credential instance for server trust authentication with a given accepted trust. Before creating a server trust credential, it is the responsibility of the delegate of an ''NSURLConnection'' instance or an ''NSURLDownload'' instance to evaluate the trust. Do this by calling 'SecTrustEvaluate', passing it the trust obtained from the 'serverTrust' method of the server's ''NSURLProtectionSpace'' instance. If the trust is invalid, the authentication challenge should be cancelled with the ''NSURLAuthenticationChallengeSender'' protocol's 'cancelAuthenticationChallenge:' method. - Parameter trust: The accepted trust. - Returns: A new URL credential object, containing the accepted server trust.
         * @param trust Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static URLCredential credential_for_trust(const SecTrust& trust);
        /**
         * @brief Calls `+[NSURLCredential credentialWithIdentity:certificates:persistence:]`.
         * @details Creates a new 'NSURLCredential' with an identity and certificate array. - Parameter identity: A 'SecIdentityRef' object. - Parameter certArray: An array containing at least one 'SecCertificateRef' objects. - Parameter persistence: A value indicating whether the credential should be stored permanently, for the duration of the current session, or not at all. - Returns: The new autoreleased 'NSURLCredential'.
         * @param identity Argument converted to the Objective-C parameter of the same role.
         * @param cert_array Argument converted to the Objective-C parameter of the same role.
         * @param persistence Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static URLCredential credential_with_identity(const SecIdentity& identity, const std::vector<Object>& cert_array, URLCredentialPersistence persistence);
        /**
         * @brief Calls `+[NSURLCredential credentialWithUser:password:persistence:]`.
         * @details Creates a new 'NSURLCredential' with a user and password. - Parameter user: The user for the credential. - Parameter password: The password for 'user'. - Parameter persistence: A value indicating whether the credential should be stored permanently, for the duration of the current session, or not at all. - Returns: The new autoreleased 'NSURLCredential'.
         * @param user Argument converted to the Objective-C parameter of the same role.
         * @param password Argument converted to the Objective-C parameter of the same role.
         * @param persistence Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static URLCredential credential_with_user(const std::string& user, const std::string& password, URLCredentialPersistence persistence);
        /**
         * @brief Returns the `certificates` property of `NSURLCredential`.
         * @details The intermediate certificates of the credential, if it is a client certificate credential. The certificates are 'SecCertificateRef' objects. This value is 'nil' if this is not a client certificate credential.
         * @return The converted Objective-C result.
         */
        std::vector<Object> certificates() const;
        /**
         * @brief Returns the `hasPassword` property of `NSURLCredential`.
         * @details A Boolean value that indicates whether the credential has a password. This method does not attempt to retrieve the password. If this credential's password is stored in the user's keychain, the 'password' property may return 'nil' even if this method returns 'YES' -- getting the password may fail, or the user may refuse access.
         * @return The converted Objective-C result.
         */
        bool has_password() const;
        /**
         * @brief Returns the `identity` property of `NSURLCredential`.
         * @details The identity of this credential if it is a client certificate credential. This value is 'nil' if the credential is not a client certificate credential.
         * @return The converted Objective-C result.
         */
        SecIdentity identity() const;
        /**
         * @brief Returns the `password` property of `NSURLCredential`.
         * @details The credential's password. You should only access this property if you need the actual password value. If you only need to know if there is a password, use 'hasPassword'. Accessing this property may result in prompting the user for access.
         * @return The converted Objective-C result.
         */
        std::string password() const;
        /**
         * @brief Returns the `persistence` property of `NSURLCredential`.
         * @details The credential's persistence setting.
         * @return The converted Objective-C result.
         */
        URLCredentialPersistence persistence() const;
        /**
         * @brief Returns the `user` property of `NSURLCredential`.
         * @details The credential's user name.
         * @return The converted Objective-C result.
         */
        std::string user() const;
    };
}
