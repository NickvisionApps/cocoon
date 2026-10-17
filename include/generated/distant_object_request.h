#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Connection;
    class Exception;
    class Invocation;

    /**
     * @brief C++ handle for the Objective-C class `NSDistantObjectRequest` (Foundation).
     * @details \@DeprecationSummary { Use ''NSXPCConnection'' instead. } An object used by the distributed objects system to help handle invocations between different processes. Do not create ''NSDistantObjectRequest'' objects directly. Unless you are getting involved with the low-level details of distributed objects, there should never be a need to access an ''NSDistantObjectRequest''. To intercept and possibly process requests yourself, implement the ''NSConnection'' delegate method ''NSConnectionDelegate/connection:handleRequest:''.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DistantObjectRequest distant_object_request;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DistantObjectRequest distant_object_request{};
     * distant_object_request.reply_with_exception(cocoon::Exception());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsdistantobjectrequest
     */
    class DistantObjectRequest : public Object
    {
    public:
        /// @brief Creates a new `NSDistantObjectRequest` instance and returns a handle to it.
        explicit DistantObjectRequest();
        /// @brief Creates a null handle that refers to no native object.
        DistantObjectRequest(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DistantObjectRequest(Adopt adopt);
        /**
     * @brief Calls `-[NSDistantObjectRequest replyWithException:]`.
     * @details Sends a reply back to the sender of the request, signaling an exception if one is provided.
     * @param exception Argument converted to the Objective-C parameter of the same role.
     */
        void reply_with_exception(const Exception& exception) const;
        /**
     * @brief Returns the `connection` property of `NSDistantObjectRequest`.
     * @details The connection over which the request was received.
     * @return The converted Objective-C result.
     */
        Connection connection() const;
        /**
     * @brief Returns the `conversation` property of `NSDistantObjectRequest`.
     * @details The token object representing the conversation in which the request was received.
     * @return The converted Objective-C result.
     */
        Object conversation() const;
        /**
     * @brief Returns the `invocation` property of `NSDistantObjectRequest`.
     * @details The invocation object for the request.
     * @return The converted Objective-C result.
     */
        Invocation invocation() const;
    };
}
