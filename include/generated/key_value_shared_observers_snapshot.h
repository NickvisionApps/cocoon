#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSKeyValueSharedObserversSnapshot` (Foundation).
     * @details A collection of key-value observations which may be registered with multiple observable objects. Create using ''-[NSKeyValueSharedObservers snapshot]''
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::KeyValueSharedObserversSnapshot key_value_shared_observers_snapshot(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nskeyvaluesharedobserverssnapshot
     */
    class KeyValueSharedObserversSnapshot : public Object
    {
    public:
        KeyValueSharedObserversSnapshot();
        /// @brief Creates a null handle that refers to no native object.
        KeyValueSharedObserversSnapshot(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit KeyValueSharedObserversSnapshot(Adopt adopt);
    };
}
