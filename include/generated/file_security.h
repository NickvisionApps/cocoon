#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSFileSecurity` (Foundation).
     * @details A stub class that encapsulates security information about a file. ''NSFileSecurity'' contains no methods of its own. Instead, it is transparently bridged to \<doc://com.apple.documentation/documentation/corefoundation/cffilesecurity>.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::FileSecurity file_security;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsfilesecurity
     */
    class FileSecurity : public Object
    {
    public:
        /// @brief Creates a new `NSFileSecurity` instance and returns a handle to it.
        explicit FileSecurity();
        /// @brief Creates a null handle that refers to no native object.
        FileSecurity(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit FileSecurity(Adopt adopt);
    };
}
