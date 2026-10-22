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
     * @details The manager of a shared credentials cache. The shared cache stores and retrieves instances of ''URLCredential''. You can store password-based credentials permanently, based on the ''URLCredential/Persistence'' they were created with. Certificate-based credentials are never stored permanently. \#\#\# Subclassing notes The ''URLCredentialStorage'' class is meant to be used as-is, but you can subclass it if you have specific needs, such as screening which credentials are stored. When overriding methods of this class, be aware that methods that take a 'task' parameter are preferred to equivalent methods that do not. Therefore, you should override the task-based methods when subclassing, as follows: - Setting credentials — Override ''set(:for:task:)'' instead of or in addition to ''set(:for:)''. - Getting credentials — Override ''getCredentials(for:task:completionHandler:)'' instead of or in addition to ''credentials(for:)''. - Removing credentials — Override ''remove(:for:options:task:)'' instead of or in addition to ''remove(:for:options:)'' and ''remove(:for:)''. - Setting default credentials — Override ''setDefaultCredential(:for:task:)'' instead of or in addition to ''setDefaultCredential(:for:)''. - Getting default credentials — Override ''getDefaultCredential(for:task:completionHandler:)'' instead of or in addition to ''defaultCredential(for:)''.
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
         * @details Gets a dictionary mapping usernames to credentials for the specified protection space. - Parameter space: An 'NSURLProtectionSpace' indicating the protection space for which to get credentials. - Returns: A dictionary where the keys are usernames and the values are the corresponding 'NSURLCredential' instances.
         * @param space Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, URLCredential> credentials_for_protection_space(const URLProtectionSpace& space) const;
        /**
         * @brief Calls `-[NSURLCredentialStorage defaultCredentialForProtectionSpace:]`.
         * @details Gets the default credential for the specified protection space. - Parameter space: The protection space for which to get the default credential.
         * @param space Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        URLCredential default_credential_for_protection_space(const URLProtectionSpace& space) const;
        /**
         * @brief Calls `-[NSURLCredentialStorage getCredentialsForProtectionSpace:task:completionHandler:]`.
         * @details Fetches credentials for the specified protection space and task, passing them to the completion handler.
         * @param protection_space Argument converted to the Objective-C parameter of the same role.
         * @param task Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void get_credentials_for_protection_space(const URLProtectionSpace& protection_space, const URLSessionTask& task, std::function<void(std::map<std::string, URLCredential>)> completion_handler) const;
        /**
         * @brief Calls `-[NSURLCredentialStorage getDefaultCredentialForProtectionSpace:task:completionHandler:]`.
         * @details Fetches the default credential for the specified protection space and task, passing it to the completion handler.
         * @param space Argument converted to the Objective-C parameter of the same role.
         * @param task Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void get_default_credential_for_protection_space(const URLProtectionSpace& space, const URLSessionTask& task, std::function<void(URLCredential)> completion_handler) const;
        /**
         * @brief Calls `-[NSURLCredentialStorage removeCredential:forProtectionSpace:]`.
         * @details Removes the credential from the set for the specified protection space. - Parameter credential: The credential to remove. - Parameter space: The protection space for which a credential should be removed. The credential is removed from both persistent and temporary storage. A credential that has a persistence policy of 'NSURLCredentialPersistenceSynchronizable' will fail. See 'removeCredential:forProtectionSpace:options:'.
         * @param credential Argument converted to the Objective-C parameter of the same role.
         * @param space Argument converted to the Objective-C parameter of the same role.
         */
        void remove_credential(const URLCredential& credential, const URLProtectionSpace& space) const;
        /**
         * @brief Calls `-[NSURLCredentialStorage removeCredential:forProtectionSpace:options:]`.
         * @details Removes the credential from the set for the specified protection space based on options. - Parameter credential: The credential to remove. - Parameter space: The protection space for which a credential should be removed. - Parameter options: A dictionary containing options to consider when removing the credential. This should be used when trying to delete a credential that has the 'NSURLCredentialPersistenceSynchronizable' policy. When such credentials are removed, the credential will be removed on all devices that contain this credential. The credential is removed from both persistent and temporary storage.
         * @param credential Argument converted to the Objective-C parameter of the same role.
         * @param space Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         */
        void remove_credential(const URLCredential& credential, const URLProtectionSpace& space, const std::map<std::string, Object>& options) const;
        /**
         * @brief Calls `-[NSURLCredentialStorage removeCredential:forProtectionSpace:options:task:]`.
         * @details Removes a credential for the specified protection space, options, and task.
         * @param credential Argument converted to the Objective-C parameter of the same role.
         * @param protection_space Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param task Argument converted to the Objective-C parameter of the same role.
         */
        void remove_credential(const URLCredential& credential, const URLProtectionSpace& protection_space, const std::map<std::string, Object>& options, const URLSessionTask& task) const;
        /**
         * @brief Calls `-[NSURLCredentialStorage setCredential:forProtectionSpace:]`.
         * @details Adds a new credential to the set for the specified protection space or replaces an existing one. - Parameter credential: The credential to set. - Parameter space: The protection space for which to add it. Multiple credentials may be set for a given protection space, but each must have a distinct user. If a credential with the same user is already set for the protection space, the new one will replace it.
         * @param credential Argument converted to the Objective-C parameter of the same role.
         * @param space Argument converted to the Objective-C parameter of the same role.
         */
        void set_credential(const URLCredential& credential, const URLProtectionSpace& space) const;
        /**
         * @brief Calls `-[NSURLCredentialStorage setCredential:forProtectionSpace:task:]`.
         * @details Sets a credential for the specified protection space and task.
         * @param credential Argument converted to the Objective-C parameter of the same role.
         * @param protection_space Argument converted to the Objective-C parameter of the same role.
         * @param task Argument converted to the Objective-C parameter of the same role.
         */
        void set_credential(const URLCredential& credential, const URLProtectionSpace& protection_space, const URLSessionTask& task) const;
        /**
         * @brief Calls `-[NSURLCredentialStorage setDefaultCredential:forProtectionSpace:]`.
         * @details Sets the default credential for the specified protection space. - Parameter credential: The credential to set as default. - Parameter space: The protection space for which the credential should be set as default. If the credential is not yet in the set for the protection space, it will be added to it.
         * @param credential Argument converted to the Objective-C parameter of the same role.
         * @param space Argument converted to the Objective-C parameter of the same role.
         */
        void set_default_credential(const URLCredential& credential, const URLProtectionSpace& space) const;
        /**
         * @brief Calls `-[NSURLCredentialStorage setDefaultCredential:forProtectionSpace:task:]`.
         * @details Sets the default credential for the specified protection space and task.
         * @param credential Argument converted to the Objective-C parameter of the same role.
         * @param protection_space Argument converted to the Objective-C parameter of the same role.
         * @param task Argument converted to the Objective-C parameter of the same role.
         */
        void set_default_credential(const URLCredential& credential, const URLProtectionSpace& protection_space, const URLSessionTask& task) const;
        /**
         * @brief Returns the `allCredentials` property of `NSURLCredentialStorage`.
         * @details The credentials for all available protection spaces. The dictionary has keys corresponding to 'NSURLProtectionSpace' instances. The values are dictionaries where the keys are user name strings, and each value is the corresponding 'NSURLCredential' instance.
         * @return The converted Objective-C result.
         */
        std::vector<std::pair<URLProtectionSpace, std::map<std::string, URLCredential>>> all_credentials() const;
        /**
         * @brief Returns the `sharedCredentialStorage` property of `NSURLCredentialStorage`.
         * @details The shared singleton authentication storage.
         * @return The converted Objective-C result.
         */
        static URLCredentialStorage shared_credential_storage();
    };
}
