#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSSymbolEffect` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SymbolEffect symbol_effect(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssymboleffect
     */
    class SymbolEffect : public Object
    {
    public:
        SymbolEffect();
        /// @brief Creates a null handle that refers to no native object.
        SymbolEffect(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SymbolEffect(Adopt adopt);
    };
}
