#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSWorkspaceAuthorization` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::WorkspaceAuthorization workspace_authorization;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsworkspaceauthorization
     */
    class WorkspaceAuthorization : public Object
    {
    public:
        /// @brief Creates a new `NSWorkspaceAuthorization` instance and returns a handle to it.
        explicit WorkspaceAuthorization();
        /// @brief Creates a null handle that refers to no native object.
        WorkspaceAuthorization(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit WorkspaceAuthorization(Adopt adopt);
    };
}
