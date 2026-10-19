#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnit` (Foundation).
     * @details NSUnit is the base class for all unit types (dimensional and dimensionless).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Unit unit{"text"};
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunit
     */
    class Unit : public Object
    {
    public:
        /// @brief Creates a new `NSUnit` instance and returns a handle to it.
        explicit Unit(const std::string& symbol);
        Unit();
        /// @brief Creates a null handle that refers to no native object.
        Unit(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Unit(Adopt adopt);
        /**
     * @brief Returns the `symbol` property of `NSUnit`.
     * @return The converted Objective-C result.
     */
        std::string symbol() const;
    };
}
