#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSPurgeableData` (Foundation).
     * @details Purgeable Data
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PurgeableData purgeable_data;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nspurgeabledata
     */
    class PurgeableData : public Object
    {
    public:
        /// @brief Creates a new `NSPurgeableData` instance and returns a handle to it.
        explicit PurgeableData();
        /// @brief Creates a null handle that refers to no native object.
        PurgeableData(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PurgeableData(Adopt adopt);
    };
}
