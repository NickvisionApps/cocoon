#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class XPCConnection;

    /**
     * @brief C++ handle for the Objective-C class `NSFileProviderService` (Foundation).
     * @details In an application that has received a URL to a file owned by a file provider, instances of NSFileProviderService can by obtained by calling -[NSFileManager getFileProviderServicesForItemAtURL:completionHandler:]. Each NSFileProviderService instance can only be used to operate on the URL originally passed to that method.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::FileProviderService file_provider_service;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsfileproviderservice
     */
    class FileProviderService : public Object
    {
    public:
        /// @brief Creates a new `NSFileProviderService` instance and returns a handle to it.
        explicit FileProviderService();
        /// @brief Creates a null handle that refers to no native object.
        FileProviderService(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit FileProviderService(Adopt adopt);
        /**
     * @brief Calls `-[NSFileProviderService getFileProviderConnectionWithCompletionHandler:]`.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void get_file_provider_connection_with_completion_handler(std::function<void(XPCConnection, Error)> completion_handler) const;
        /**
     * @brief Returns the `name` property of `NSFileProviderService`.
     * @return The converted Objective-C result.
     */
        std::string name() const;
    };
}
