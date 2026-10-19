#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class URLCredential;
    class URLProtectionSpace;
    class URLSessionTask;

    /**
     * @brief C++ handle for the Objective-C class `NSURLCredentialStorage` (Foundation).
     * @details \@class NSURLCredentialStorage \@discussion NSURLCredentialStorage implements a singleton object (shared instance) which manages the shared credentials cache. Note: Whereas in Mac OS X any application can access any credential with a persistence of NSURLCredentialPersistencePermanent provided the user gives permission, in iPhone OS an application can access only its own credentials.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLCredentialStorage url_credential_storage;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::URLCredentialStorage url_credential_storage{};
     * url_credential_storage.credentials_for_protection_space(cocoon::URLProtectionSpace());
     * url_credential_storage.default_credential_for_protection_space(cocoon::URLProtectionSpace());
     * url_credential_storage.remove_credential(cocoon::URLCredential(), cocoon::URLProtectionSpace());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlcredentialstorage
     */
    class URLCredentialStorage : public Object
    {
    public:
        /// @brief Creates a new `NSURLCredentialStorage` instance and returns a handle to it.
        explicit URLCredentialStorage();
        /// @brief Creates a null handle that refers to no native object.
        URLCredentialStorage(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLCredentialStorage(Adopt adopt);
        /**
     * @brief Calls `-[NSURLCredentialStorage credentialsForProtectionSpace:]`.
     * @details \@method credentialsForProtectionSpace: \@abstract Get a dictionary mapping usernames to credentials for the specified protection space. \@param space An NSURLProtectionSpace indicating the protection space for which to get credentials \@result A dictionary where the keys are usernames and the values are the corresponding NSURLCredentials.
     * @param space Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::map<std::string, URLCredential> credentials_for_protection_space(const URLProtectionSpace& space) const;
        /**
     * @brief Calls `-[NSURLCredentialStorage defaultCredentialForProtectionSpace:]`.
     * @details \@method defaultCredentialForProtectionSpace: \@abstract Get the default credential for the specified protection space. \@param space The protection space for which to get the default credential.
     * @param space Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URLCredential default_credential_for_protection_space(const URLProtectionSpace& space) const;
        /**
     * @brief Calls `-[NSURLCredentialStorage getCredentialsForProtectionSpace:task:completionHandler:]`.
     * @param protection_space Argument converted to the Objective-C parameter of the same role.
     * @param task Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void get_credentials_for_protection_space(const URLProtectionSpace& protection_space, const URLSessionTask& task, std::function<void(std::map<std::string, URLCredential>)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLCredentialStorage getDefaultCredentialForProtectionSpace:task:completionHandler:]`.
     * @param space Argument converted to the Objective-C parameter of the same role.
     * @param task Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void get_default_credential_for_protection_space(const URLProtectionSpace& space, const URLSessionTask& task, std::function<void(URLCredential)> completion_handler) const;
        /**
     * @brief Calls `-[NSURLCredentialStorage removeCredential:forProtectionSpace:]`.
     * @details \@method removeCredential:forProtectionSpace: \@abstract Remove the credential from the set for the specified protection space. \@param credential The credential to remove. \@param space The protection space for which a credential should be removed \@discussion The credential is removed from both persistent and temporary storage. A credential that has a persistence policy of NSURLCredentialPersistenceSynchronizable will fail. See removeCredential:forProtectionSpace:options.
     * @param credential Argument converted to the Objective-C parameter of the same role.
     * @param space Argument converted to the Objective-C parameter of the same role.
     */
        void remove_credential(const URLCredential& credential, const URLProtectionSpace& space) const;
        /**
     * @brief Calls `-[NSURLCredentialStorage removeCredential:forProtectionSpace:options:]`.
     * @details \@method removeCredential:forProtectionSpace:options \@abstract Remove the credential from the set for the specified protection space based on options. \@param credential The credential to remove. \@param space The protection space for which a credential should be removed \@param options A dictionary containing options to consider when removing the credential. This should be used when trying to delete a credential that has the NSURLCredentialPersistenceSynchronizable policy. Please note that when NSURLCredential objects that have a NSURLCredentialPersistenceSynchronizable policy are removed, the credential will be removed on all devices that contain this credential. \@discussion The credential is removed from both persistent and temporary storage.
     * @param credential Argument converted to the Objective-C parameter of the same role.
     * @param space Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     */
        void remove_credential(const URLCredential& credential, const URLProtectionSpace& space, const std::map<std::string, Object>& options) const;
        /**
     * @brief Calls `-[NSURLCredentialStorage removeCredential:forProtectionSpace:options:task:]`.
     * @param credential Argument converted to the Objective-C parameter of the same role.
     * @param protection_space Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param task Argument converted to the Objective-C parameter of the same role.
     */
        void remove_credential(const URLCredential& credential, const URLProtectionSpace& protection_space, const std::map<std::string, Object>& options, const URLSessionTask& task) const;
        /**
     * @brief Calls `-[NSURLCredentialStorage setCredential:forProtectionSpace:]`.
     * @details \@method setCredential:forProtectionSpace: \@abstract Add a new credential to the set for the specified protection space or replace an existing one. \@param credential The credential to set. \@param space The protection space for which to add it. \@discussion Multiple credentials may be set for a given protection space, but each must have a distinct user. If a credential with the same user is already set for the protection space, the new one will replace it.
     * @param credential Argument converted to the Objective-C parameter of the same role.
     * @param space Argument converted to the Objective-C parameter of the same role.
     */
        void set_credential(const URLCredential& credential, const URLProtectionSpace& space) const;
        /**
     * @brief Calls `-[NSURLCredentialStorage setCredential:forProtectionSpace:task:]`.
     * @param credential Argument converted to the Objective-C parameter of the same role.
     * @param protection_space Argument converted to the Objective-C parameter of the same role.
     * @param task Argument converted to the Objective-C parameter of the same role.
     */
        void set_credential(const URLCredential& credential, const URLProtectionSpace& protection_space, const URLSessionTask& task) const;
        /**
     * @brief Calls `-[NSURLCredentialStorage setDefaultCredential:forProtectionSpace:]`.
     * @details \@method setDefaultCredential:forProtectionSpace: \@abstract Set the default credential for the specified protection space. \@param credential The credential to set as default. \@param space The protection space for which the credential should be set as default. \@discussion If the credential is not yet in the set for the protection space, it will be added to it.
     * @param credential Argument converted to the Objective-C parameter of the same role.
     * @param space Argument converted to the Objective-C parameter of the same role.
     */
        void set_default_credential(const URLCredential& credential, const URLProtectionSpace& space) const;
        /**
     * @brief Calls `-[NSURLCredentialStorage setDefaultCredential:forProtectionSpace:task:]`.
     * @param credential Argument converted to the Objective-C parameter of the same role.
     * @param protection_space Argument converted to the Objective-C parameter of the same role.
     * @param task Argument converted to the Objective-C parameter of the same role.
     */
        void set_default_credential(const URLCredential& credential, const URLProtectionSpace& protection_space, const URLSessionTask& task) const;
        /**
     * @brief Returns the `allCredentials` property of `NSURLCredentialStorage`.
     * @details \@abstract Get a dictionary mapping NSURLProtectionSpaces to dictionaries which map usernames to NSURLCredentials \@result an NSDictionary where the keys are NSURLProtectionSpaces and the values are dictionaries, in which the keys are usernames and the values are NSURLCredentials
     * @return The converted Objective-C result.
     */
        std::vector<std::pair<URLProtectionSpace, std::map<std::string, URLCredential>>> all_credentials() const;
        /**
     * @brief Returns the `sharedCredentialStorage` property of `NSURLCredentialStorage`.
     * @details \@property sharedCredentialStorage \@abstract Get the shared singleton authentication storage \@result the shared authentication storage
     * @return The converted Objective-C result.
     */
        static URLCredentialStorage shared_credential_storage();
    };
}
