#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSError` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Error error;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nserror
     */
    class Error : public Object
    {
    public:
        /// @brief Creates a new `NSError` instance and returns a handle to it.
        explicit Error(const std::string& domain, std::int64_t code, const std::map<std::string, Object>& dict);
        /// @brief Creates a new `NSError` instance and returns a handle to it.
        explicit Error();
        /// @brief Creates a null handle that refers to no native object.
        Error(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Error(Adopt adopt);
        /**
         * @brief Calls `+[NSError setUserInfoValueProviderForDomain:provider:]`.
         * @details Specify a block which will be called from the implementations of localizedDescription, localizedFailureReason, localizedRecoverySuggestion, localizedRecoveryOptions, recoveryAttempter, helpAnchor, and debugDescription when the underlying value for these is not present in the userInfo dictionary of NSError instances with the specified domain. The provider will be called with the userInfo key corresponding to the queried property: For instance, NSLocalizedDescriptionKey for localizedDescription. The provider should return nil for any keys it is not able to provide and, very importantly, any keys it does not recognize (since we may extend the list of keys in future releases). The specified block will be called synchronously at the time when the above properties are queried. The results are not cached. This provider is optional. It enables localization and formatting of error messages to be done lazily; rather than populating the userInfo at NSError creation time, these keys will be fetched on-demand when asked for. It is expected that only the “owner” of an NSError domain specifies the provider for the domain, and this is done once. This facility is not meant for consumers of errors to customize the userInfo entries. This facility should not be used to customize the behaviors of error domains provided by the system. If an appropriate result for the requested key cannot be provided, return nil rather than choosing to manufacture a generic fallback response such as "Operation could not be completed, error 42." NSError will take care of the fallback cases.
         * @param error_domain Argument converted to the Objective-C parameter of the same role.
         * @param provider Argument converted to the Objective-C parameter of the same role.
         */
        static void set_user_info_value_provider_for_domain(const std::string& error_domain, std::function<Object(Error, std::string)> provider);
        /**
         * @brief Calls `+[NSError userInfoValueProviderForDomain:]`.
         * @param error_domain Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::function<Object(Error, std::string)> user_info_value_provider_for_domain(const std::string& error_domain);
        /**
         * @brief Returns the `code` property of `NSError`.
         * @return The converted Objective-C result.
         */
        std::int64_t code() const;
        /**
         * @brief Returns the `domain` property of `NSError`.
         * @details These define the error. Domains are described by names that are arbitrary strings used to differentiate groups of codes; for custom domain using reverse-DNS naming will help avoid conflicts. Codes are domain-specific.
         * @return The converted Objective-C result.
         */
        std::string domain() const;
        /**
         * @brief Returns the `helpAnchor` property of `NSError`.
         * @details Return the help anchor that can be used to create a help button to accompany the error when it's displayed to the user. This is done automatically by +[NSAlert alertWithError:], which the presentError: variants in NSApplication go through. The default implementation of this picks up the value of the NSHelpAnchorErrorKey from the userInfo dictionary. If not present, it consults the userInfoValueProvider for the domain. If that returns nil, this also returns nil.
         * @return The converted Objective-C result.
         */
        std::string help_anchor() const;
        /**
         * @brief Returns the `localizedDescription` property of `NSError`.
         * @details The primary user-presentable message for the error, for instance for NSFileReadNoPermissionError: "The file "File Name" couldn't be opened because you don't have permission to view it.". This message should ideally indicate what failed and why it failed. This value either comes from NSLocalizedDescriptionKey, or NSLocalizedFailureErrorKey+NSLocalizedFailureReasonErrorKey, or NSLocalizedFailureErrorKey. The steps this takes to construct the description include: 1. Look for NSLocalizedDescriptionKey in userInfo, use value as-is if present. 2. Look for NSLocalizedFailureErrorKey in userInfo. If present, use, combining with value for NSLocalizedFailureReasonErrorKey if available. 3. Fetch NSLocalizedDescriptionKey from userInfoValueProvider, use value as-is if present. 4. Fetch NSLocalizedFailureErrorKey from userInfoValueProvider. If present, use, combining with value for NSLocalizedFailureReasonErrorKey if available. 5. Look for NSLocalizedFailureReasonErrorKey in userInfo or from userInfoValueProvider; combine with generic "Operation failed" message. 6. Last resort localized but barely-presentable string manufactured from domain and code. The result is never nil.
         * @return The converted Objective-C result.
         */
        std::string localized_description() const;
        /**
         * @brief Returns the `localizedFailureReason` property of `NSError`.
         * @details Return a complete sentence which describes why the operation failed. For instance, for NSFileReadNoPermissionError: "You don't have permission.". In many cases this will be just the "because" part of the error message (but as a complete sentence, which makes localization easier). Default implementation of this picks up the value of NSLocalizedFailureReasonErrorKey from the userInfo dictionary. If not present, it consults the userInfoValueProvider for the domain, and if that returns nil, this also returns nil.
         * @return The converted Objective-C result.
         */
        std::string localized_failure_reason() const;
        /**
         * @brief Returns the `localizedRecoveryOptions` property of `NSError`.
         * @details Return titles of buttons that are appropriate for displaying in an alert. These should match the string provided as a part of localizedRecoverySuggestion. The first string would be the title of the right-most and default button, the second one next to it, and so on. If used in an alert the corresponding default return values are NSAlertFirstButtonReturn + n. Default implementation of this picks up the value of NSLocalizedRecoveryOptionsErrorKey from the userInfo dictionary. If not present, it consults the userInfoValueProvider for the domain, and if that returns nil, this also returns nil. nil return usually implies no special suggestion, which would imply a single "OK" button.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> localized_recovery_options() const;
        /**
         * @brief Returns the `localizedRecoverySuggestion` property of `NSError`.
         * @details Return the string that can be displayed as the "informative" (aka "secondary") message on an alert panel. For instance, for NSFileReadNoPermissionError: "To view or change permissions, select the item in the Finder and choose File > Get Info.". Default implementation of this picks up the value of NSLocalizedRecoverySuggestionErrorKey from the userInfo dictionary. If not present, it consults the userInfoValueProvider for the domain, and if that returns nil, this also returns nil.
         * @return The converted Objective-C result.
         */
        std::string localized_recovery_suggestion() const;
        /**
         * @brief Returns the `recoveryAttempter` property of `NSError`.
         * @details Return an object that conforms to the NSErrorRecoveryAttempting informal protocol. The recovery attempter must be an object that can correctly interpret an index into the array returned by localizedRecoveryOptions. The default implementation of this picks up the value of NSRecoveryAttempterErrorKey from the userInfo dictionary. If not present, it consults the userInfoValueProvider for the domain. If that returns nil, this also returns nil.
         * @return The converted Objective-C result.
         */
        Object recovery_attempter() const;
        /**
         * @brief Returns the `underlyingErrors` property of `NSError`.
         * @details Return a list of underlying errors, if any. It includes the values of both NSUnderlyingErrorKey and NSMultipleUnderlyingErrorsKey. If there are no underlying errors, returns an empty array.
         * @return The converted Objective-C result.
         */
        std::vector<Error> underlying_errors() const;
        /**
         * @brief Returns the `userInfo` property of `NSError`.
         * @details Additional info which may be used to describe the error further. Examples of keys that might be included in here are "Line Number", "Failed URL", etc. Embedding other errors in here can also be used as a way to communicate underlying reasons for failures; for instance "File System Error" embedded in the userInfo of an NSError returned from a higher level document object. If the embedded error information is itself NSError, the standard key NSUnderlyingErrorKey can be used.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> user_info() const;
    };
}
