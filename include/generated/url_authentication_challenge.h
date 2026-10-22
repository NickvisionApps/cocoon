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
     * @details A challenge from a server requiring authentication from the client. Your app receives authentication challenges in various ''URLSession'', ''NSURLConnection'', and ''NSURLDownload'' delegate methods, such as ''URLSessionTaskDelegate/urlSession(:task:didReceive:completionHandler:)''. These objects provide the information you'll need when deciding how to handle a server's request for authentication. At the core of that authentication challenge is a protection space that defines the type of authentication being requested, the host and port number, the networking protocol, and (where applicable) the authentication realm (a group of related URLs on the same server that share a single set of credentials).
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
         * @details The error representing authentication failure. If there was a previous authentication failure, and this protocol uses errors to indicate authentication failure, then this method will return the error. Otherwise it will return 'nil'.
         * @return The converted Objective-C result.
         */
        Error error() const;
        /**
         * @brief Returns the `failureResponse` property of `NSURLAuthenticationChallenge`.
         * @details The response representing authentication failure. If there was a previous authentication failure, and this protocol uses responses to indicate authentication failure, then this method will return the response. Otherwise it will return 'nil'.
         * @return The converted Objective-C result.
         */
        URLResponse failure_response() const;
        /**
         * @brief Returns the `previousFailureCount` property of `NSURLAuthenticationChallenge`.
         * @details The count of previous failed authentication attempts.
         * @return The converted Objective-C result.
         */
        std::int64_t previous_failure_count() const;
        /**
         * @brief Returns the `proposedCredential` property of `NSURLAuthenticationChallenge`.
         * @details The proposed credential for this challenge. The proposed credential may be 'nil', if there is no default credential to use for this challenge (either stored or in the URL). If the credential is not 'nil' and returns 'YES' for 'hasPassword', it is ready to use as-is. If it returns 'NO' for 'hasPassword', it provides a default username the client could use when prompting.
         * @return The converted Objective-C result.
         */
        URLCredential proposed_credential() const;
        /**
         * @brief Returns the `protectionSpace` property of `NSURLAuthenticationChallenge`.
         * @details A description of the protection space that requires authentication.
         * @return The converted Objective-C result.
         */
        URLProtectionSpace protection_space() const;
    };
}
