#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSAssertionHandler` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::AssertionHandler assertion_handler;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsassertionhandler
     */
    class AssertionHandler : public Object
    {
    public:
        /// @brief Creates a new `NSAssertionHandler` instance and returns a handle to it.
        explicit AssertionHandler();
        /// @brief Creates a null handle that refers to no native object.
        AssertionHandler(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit AssertionHandler(Adopt adopt);
        /**
     * @brief Returns the `currentHandler` property of `NSAssertionHandler`.
     * @return The converted Objective-C result.
     */
        static AssertionHandler current_handler();
    };
}
