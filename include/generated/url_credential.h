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
     * @details \@class NSURLCredential \@discussion This class is an immutable object representing an authentication credential. The actual type of the credential is determined by the constructor called in the categories declared below.
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
         * @details \@method credentialForTrust: \@abstract Create a new NSURLCredential which specifies that a handshake has been trusted. \@result The new autoreleased NSURLCredential
         * @param trust Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static URLCredential credential_for_trust(const SecTrust& trust);
        /**
         * @brief Calls `+[NSURLCredential credentialWithIdentity:certificates:persistence:]`.
         * @details \@method credentialWithIdentity:certificates:persistence: \@abstract Create a new NSURLCredential with an identity and certificate array \@param identity a SecIdentityRef object \@param certArray an array containing at least one SecCertificateRef objects \@param persistence enum that says to store per session, permanently or not at all \@result The new autoreleased NSURLCredential
         * @param identity Argument converted to the Objective-C parameter of the same role.
         * @param cert_array Argument converted to the Objective-C parameter of the same role.
         * @param persistence Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static URLCredential credential_with_identity(const SecIdentity& identity, const std::vector<Object>& cert_array, URLCredentialPersistence persistence);
        /**
         * @brief Calls `+[NSURLCredential credentialWithUser:password:persistence:]`.
         * @details \@method credentialWithUser:password:persistence: \@abstract Create a new NSURLCredential with a user and password \@param user the username \@param password the password \@param persistence enum that says to store per session, permanently or not at all \@result The new autoreleased NSURLCredential
         * @param user Argument converted to the Objective-C parameter of the same role.
         * @param password Argument converted to the Objective-C parameter of the same role.
         * @param persistence Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static URLCredential credential_with_user(const std::string& user, const std::string& password, URLCredentialPersistence persistence);
        /**
         * @brief Returns the `certificates` property of `NSURLCredential`.
         * @details \@abstract Returns an NSArray of SecCertificateRef objects representing the client certificate for this credential, if this credential was created with an identity and certificate. \@result an NSArray of SecCertificateRef or NULL if this is a username/password credential
         * @return The converted Objective-C result.
         */
        std::vector<Object> certificates() const;
        /**
         * @brief Returns the `hasPassword` property of `NSURLCredential`.
         * @details \@abstract Find out if this credential has a password, without trying to get it \@result YES if this credential has a password, otherwise NO \@discussion If this credential's password is actually kept in an external store, the password method may return nil even if this method returns YES, since getting the password may fail, or the user may refuse access.
         * @return The converted Objective-C result.
         */
        bool has_password() const;
        /**
         * @brief Returns the `identity` property of `NSURLCredential`.
         * @details \@abstract Returns the SecIdentityRef of this credential, if it was created with a certificate and identity \@result A SecIdentityRef or NULL if this is a username/password credential
         * @return The converted Objective-C result.
         */
        SecIdentity identity() const;
        /**
         * @brief Returns the `password` property of `NSURLCredential`.
         * @details \@abstract Get the password \@result The password string \@discussion This method might actually attempt to retrieve the password from an external store, possible resulting in prompting, so do not call it unless needed.
         * @return The converted Objective-C result.
         */
        std::string password() const;
        /**
         * @brief Returns the `persistence` property of `NSURLCredential`.
         * @details \@abstract Determine whether this credential is or should be stored persistently \@result A value indicating whether this credential is stored permanently, per session or not at all.
         * @return The converted Objective-C result.
         */
        URLCredentialPersistence persistence() const;
        /**
         * @brief Returns the `user` property of `NSURLCredential`.
         * @details \@abstract Get the username \@result The user string
         * @return The converted Objective-C result.
         */
        std::string user() const;
    };
}
