#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSError` (Foundation).
     * @details Information about an error condition including a domain, a domain-specific error code, and application-specific information. Objective-C methods can signal an error condition by returning an ''NSError'' object by reference, which provides additional information about the kind of error and any underlying cause, if one can be determined. An ''NSError'' object may also provide localized error descriptions suitable for display to the user in its user info dictionary. See [Error Handling Programming Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ErrorHandlingCocoa/ErrorHandling/ErrorHandling.html\#//apple_ref/doc/uid/TP40001806) for more information. Methods in Foundation and other Cocoa frameworks most often produce errors in the Cocoa error domain (''NSCocoaErrorDomain''); error codes for the Cocoa Error Domain are documented in the \<doc:foundation-constants>. There are also predefined domains corresponding to Mach (''NSMachErrorDomain''), POSIX (''NSPOSIXErrorDomain''), and Carbon (''NSOSStatusErrorDomain'') errors. ''NSError'' is "toll-free bridged" with its Core Foundation counterpart, \<doc://com.apple.documentation/documentation/corefoundation/cferror>. See [Toll-Free Bridging](https://developer.apple.com/library/archive/documentation/General/Conceptual/CocoaEncyclopedia/Toll-FreeBridgin/Toll-FreeBridgin.html\#//apple_ref/doc/uid/TP40010810-CH2) for more information. \#\#\# Subclassing Notes Applications may choose to create subclasses of 'NSError', for example, to provide better localized error strings by overriding ''localizedDescription''.
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
     * @brief Calls `+[NSError errorWithDomain:code:userInfo:]`.
     * @details Creates and initializes an \@c NSError object for a given domain and code with a given \@c userInfo dictionary. \@param domain The error domain---this can be one of the predefined \@c NSError domains, or an arbitrary string describing a custom domain. \@param code The error code for the error. \@param dict The \@c userInfo dictionary for the error. May be \@c nil. \@return An \@c NSError object for \@c domain with the specified error \@c code and the dictionary of arbitrary data \@c userInfo.
     * @param domain Argument converted to the Objective-C parameter of the same role.
     * @param code Argument converted to the Objective-C parameter of the same role.
     * @param dict Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Error error_with_domain(const std::string& domain, std::int64_t code, const std::map<std::string, Object>& dict);
        /**
     * @brief Calls `+[NSError setUserInfoValueProviderForDomain:provider:]`.
     * @details Specifies a block to call when the corresponding property is not present in the user info dictionary. The provider is called synchronously from the implementations of \@c localizedDescription, \@c localizedFailureReason, \@c localizedRecoverySuggestion, \@c localizedRecoveryOptions, \@c recoveryAttempter, \@c helpAnchor, and \@c debugDescription when the underlying value is not present in the \@c userInfo dictionary of NSError instances with the specified domain. The provider should return \@c nil for any keys it is not able to provide and any keys it does not recognize. The results are not cached. It is expected that only the “owner” of an NSError domain specifies the provider, and this is done once. This facility is not meant for consumers of errors to customize the userInfo entries. This facility should not be used to customize the behaviors of error domains provided by the system. If an appropriate result for the requested key cannot be provided, return nil rather than choosing to manufacture a generic fallback response such as "Operation could not be completed, error 42." 'NSError' will take care of the fallback cases. \@param errorDomain The error domain of the provider. \@param provider A block to be executed synchronously at the time a corresponding property is accessed.
     * @param error_domain Argument converted to the Objective-C parameter of the same role.
     * @param provider Argument converted to the Objective-C parameter of the same role.
     */
        static void set_user_info_value_provider_for_domain(const std::string& error_domain, std::function<Object(Error, std::string)> provider);
        /**
     * @brief Calls `+[NSError userInfoValueProviderForDomain:]`.
     * @details Returns any user info provider specified for a given error domain. \@param errorDomain The error domain of the user info provider. \@return The user info provider of the error domain, or \@c nil if none is specified.
     * @param error_domain Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::function<Object(Error, std::string)> user_info_value_provider_for_domain(const std::string& error_domain);
        /**
     * @brief Returns the `code` property of `NSError`.
     * @details The error code. Codes are domain-specific.
     * @return The converted Objective-C result.
     */
        std::int64_t code() const;
        /**
     * @brief Returns the `domain` property of `NSError`.
     * @details A string containing the error domain. Domains are described by names that are arbitrary strings used to differentiate groups of codes; for custom domains, using reverse-DNS naming will help avoid conflicts.
     * @return The converted Objective-C result.
     */
        std::string domain() const;
        /**
     * @brief Returns the `helpAnchor` property of `NSError`.
     * @details A string to display in response to an alert panel help anchor button being pressed. The object in the user info dictionary for the key \@c NSHelpAnchorErrorKey. Returns \@c nil if not present.
     * @return The converted Objective-C result.
     */
        std::string help_anchor() const;
        /**
     * @brief Returns the `localizedDescription` property of `NSError`.
     * @details A string containing the localized description of the error. For instance, for 'NSFileReadNoPermissionError': "The file "File Name" couldn't be opened because you don't have permission to view it.". This message should ideally indicate what failed and why it failed. This value either comes from 'NSLocalizedDescriptionKey', or 'NSLocalizedFailureErrorKey' + 'NSLocalizedFailureReasonErrorKey', or 'NSLocalizedFailureErrorKey'. The steps this takes to construct the description include: 1. Look for NSLocalizedDescriptionKey in userInfo, use value as-is if present. 2. Look for NSLocalizedFailureErrorKey in userInfo. If present, use, combining with value for NSLocalizedFailureReasonErrorKey if available. 3. Fetch NSLocalizedDescriptionKey from userInfoValueProvider, use value as-is if present. 4. Fetch NSLocalizedFailureErrorKey from userInfoValueProvider. If present, use, combining with value for NSLocalizedFailureReasonErrorKey if available. 5. Look for NSLocalizedFailureReasonErrorKey in userInfo or from userInfoValueProvider; combine with generic "Operation failed" message. 6. Last resort localized but barely-presentable string manufactured from domain and code. The result is never nil. This value either comes from \@c NSLocalizedDescriptionKey, or \@c NSLocalizedFailureErrorKey combined with \@c NSLocalizedFailureReasonErrorKey, or a last-resort string manufactured from the domain and code.
     * @return The converted Objective-C result.
     */
        std::string localized_description() const;
        /**
     * @brief Returns the `localizedFailureReason` property of `NSError`.
     * @details A string containing the localized explanation of the reason for the error. Return a complete sentence which describes why the operation failed. For instance, for 'NSFileReadNoPermissionError': "You don't have permission.". In many cases this will be just the "because" part of the error message (but as a complete sentence, which makes localization easier). Default implementation of this picks up the value of 'NSLocalizedFailureReasonErrorKey' from the userInfo dictionary. If not present, it consults the 'userInfoValueProvider' for the domain, and if that returns 'nil', this also returns 'nil'. The object in the user info dictionary for the key \@c NSLocalizedFailureReasonErrorKey. If not present, consults the \@c userInfoValueProvider for the domain. Returns \@c nil if unavailable.
     * @return The converted Objective-C result.
     */
        std::string localized_failure_reason() const;
        /**
     * @brief Returns the `localizedRecoveryOptions` property of `NSError`.
     * @details An array containing the localized titles of buttons appropriate for displaying in an alert panel. The object in the user info dictionary for the key \@c NSLocalizedRecoveryOptionsErrorKey. These should match the string provided as a part of 'localizedRecoverySuggestion'. The first string would be the title of the right-most and default button, the second one next to it, and so on. If used in an alert the corresponding default return values are 'NSAlertFirstButtonReturn' + 'n'. Default implementation of this picks up the value of 'NSLocalizedRecoveryOptionsErrorKey' from the 'userInfo' dictionary. If not present, it consults the 'userInfoValueProvider' for the domain, and if that returns 'nil', this also returns 'nil'. 'nil' return usually implies no special suggestion, which would imply a single "OK" button. Returns \@c nil if no recovery options are available, which typically implies a single "OK" button.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> localized_recovery_options() const;
        /**
     * @brief Returns the `localizedRecoverySuggestion` property of `NSError`.
     * @details A string containing the localized recovery suggestion for the error. For instance, for 'NSFileReadNoPermissionError': "To view or change permissions, select the item in the Finder and choose File > Get Info.". The default implementation of this picks up the value of 'NSLocalizedRecoverySuggestionErrorKey' from the 'userInfo' dictionary. If not present, it consults the 'userInfoValueProvider' for the domain, and if that returns 'nil', this also returns 'nil'. The object in the user info dictionary for the key \@c NSLocalizedRecoverySuggestionErrorKey. The returned string is suitable for displaying as the secondary message in an alert panel. Returns \@c nil if unavailable.
     * @return The converted Objective-C result.
     */
        std::string localized_recovery_suggestion() const;
        /**
     * @brief Returns the `recoveryAttempter` property of `NSError`.
     * @details The object in the user info dictionary corresponding to the \@c NSRecoveryAttempterErrorKey key. The recovery attempter must be an object that conforms to the \@c NSErrorRecoveryAttempting informal protocol. It must be able to correctly interpret an index into the \@c localizedRecoveryOptions array. The default implementation of this picks up the value of 'NSRecoveryAttempterErrorKey' from the 'userInfo' dictionary. If not present, it consults the 'userInfoValueProvider' for the domain. If that returns 'nil', this also returns 'nil'. Returns \@c nil if not present in the user info or from the \@c userInfoValueProvider.
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
     * @details The user info dictionary. Contains application-specific data related to the error. Examples of keys that might be included are \@c NSLocalizedDescriptionKey, \@c NSFilePathErrorKey, and \@c NSUnderlyingErrorKey.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> user_info() const;
    };
}
