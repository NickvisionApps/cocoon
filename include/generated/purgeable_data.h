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
     * @details A mutable data object containing bytes that can be discarded when they're no longer needed. ''NSPurgeableData'' objects inherit their creation methods from their superclass, ''NSMutableData'' while providing a default implementation of the ''NSDiscardableContent'' protocol. All ''NSPurgeableData'' objects begin "accessed" to ensure that they are not instantly discarded. The ''NSDiscardableContent/beginContentAccess()'' method marks the object's bytes as "accessed," thus protecting them from being discarded, and must be called before accessing the object, or else an exception will be raised. This method returns \<doc://com.apple.documentation/documentation/swift/true> if the bytes have not been discarded and if they have been successfully marked as "accessed". Any method that directly or indirectly accesses these bytes or their length when they are not "accessed" will raise an exception. When you are done with the data, call ''NSDiscardableContent/endContentAccess()'' to allow them to be discarded in order to quickly free up memory. You may use these objects by themselves, and do not necessarily have to use them in conjunction with ''NSCache'' to get the purging behavior. The ''NSCache'' class incorporates a caching mechanism with some auto-removal policies to ensure that its memory footprint does not get too large. ''NSPurgeableData'' objects should not be used as keys in hashing-based collections, because the value of the bytes pointer can change after every mutation of the data.
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
