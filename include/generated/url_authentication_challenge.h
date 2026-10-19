#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class URLCredential;
    class URLProtectionSpace;
    class URLResponse;

    /**
     * @brief C++ handle for the Objective-C class `NSURLAuthenticationChallenge` (Foundation).
     * @details \@class NSURLAuthenticationChallenge \@discussion This class represents an authentication challenge. It provides all the information about the challenge, and has a method to indicate when it's done.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLAuthenticationChallenge url_authentication_challenge;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlauthenticationchallenge
     */
    class URLAuthenticationChallenge : public Object
    {
    public:
        /// @brief Creates a new `NSURLAuthenticationChallenge` instance and returns a handle to it.
        explicit URLAuthenticationChallenge(const URLAuthenticationChallenge& challenge, const Object& sender);
        /// @brief Creates a new `NSURLAuthenticationChallenge` instance and returns a handle to it.
        explicit URLAuthenticationChallenge(const URLProtectionSpace& space, const URLCredential& credential, std::int64_t previous_failure_count, const URLResponse& response, const Error& error, const Object& sender);
        /// @brief Creates a new `NSURLAuthenticationChallenge` instance and returns a handle to it.
        explicit URLAuthenticationChallenge();
        /// @brief Creates a null handle that refers to no native object.
        URLAuthenticationChallenge(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLAuthenticationChallenge(Adopt adopt);
        /**
     * @brief Returns the `error` property of `NSURLAuthenticationChallenge`.
     * @details \@abstract Get the error representing authentication failure. \@discussion If there was a previous authentication failure, and this protocol uses errors to indicate authentication failure, then this method will return the error. Otherwise it will return nil.
     * @return The converted Objective-C result.
     */
        Error error() const;
        /**
     * @brief Returns the `failureResponse` property of `NSURLAuthenticationChallenge`.
     * @details \@abstract Get the response representing authentication failure. \@result The failure response or nil \@discussion If there was a previous authentication failure, and this protocol uses responses to indicate authentication failure, then this method will return the response. Otherwise it will return nil.
     * @return The converted Objective-C result.
     */
        URLResponse failure_response() const;
        /**
     * @brief Returns the `previousFailureCount` property of `NSURLAuthenticationChallenge`.
     * @details \@abstract Get count of previous failed authentication attempts \@result The count of previous failures
     * @return The converted Objective-C result.
     */
        std::int64_t previous_failure_count() const;
        /**
     * @brief Returns the `proposedCredential` property of `NSURLAuthenticationChallenge`.
     * @details \@abstract Get the proposed credential for this challenge \@result The proposed credential \@discussion proposedCredential may be nil, if there is no default credential to use for this challenge (either stored or in the URL). If the credential is not nil and returns YES for hasPassword, this means the NSURLConnection thinks the credential is ready to use as-is. If it returns NO for hasPassword, then the credential is not ready to use as-is, but provides a default username the client could use when prompting.
     * @return The converted Objective-C result.
     */
        URLCredential proposed_credential() const;
        /**
     * @brief Returns the `protectionSpace` property of `NSURLAuthenticationChallenge`.
     * @details \@abstract Get a description of the protection space that requires authentication \@result The protection space that needs authentication
     * @return The converted Objective-C result.
     */
        URLProtectionSpace protection_space() const;
    };
}
