#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSSymbolEffectOptions` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SymbolEffectOptions symbol_effect_options(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SymbolEffectOptions symbol_effect_options(nullptr);
     * auto made_0 = cocoon::SymbolEffectOptions::options();
     * symbol_effect_options.options_with_non_repeating();
     * symbol_effect_options.options_with_repeat_count(1);
     * symbol_effect_options.options_with_repeating();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssymboleffectoptions
     */
    class SymbolEffectOptions : public Object
    {
    public:
        SymbolEffectOptions();
        /// @brief Creates a null handle that refers to no native object.
        SymbolEffectOptions(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SymbolEffectOptions(Adopt adopt);
        /**
     * @brief Calls `+[NSSymbolEffectOptions options]`.
     * @return The converted Objective-C result.
     */
        static SymbolEffectOptions options();
        /**
     * @brief Calls `-[NSSymbolEffectOptions optionsWithNonRepeating]`.
     * @return The converted Objective-C result.
     */
        SymbolEffectOptions options_with_non_repeating() const;
        /**
     * @brief Calls `-[NSSymbolEffectOptions optionsWithRepeatCount:]`.
     * @param count Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        SymbolEffectOptions options_with_repeat_count(std::int64_t count) const;
        /**
     * @brief Calls `-[NSSymbolEffectOptions optionsWithRepeating]`.
     * @return The converted Objective-C result.
     */
        SymbolEffectOptions options_with_repeating() const;
        /**
     * @brief Calls `-[NSSymbolEffectOptions optionsWithSpeed:]`.
     * @param speed Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        SymbolEffectOptions options_with_speed(double speed) const;
    };
}
