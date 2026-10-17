#include "generated/symbol_effect_options.h"
#include "internal.h"

namespace cocoon
{
    SymbolEffectOptions::SymbolEffectOptions() : Object(nullptr)
    {
    }

    SymbolEffectOptions::SymbolEffectOptions(std::nullptr_t) : Object(nullptr)
    {
    }

    SymbolEffectOptions::SymbolEffectOptions(Adopt adopt) : Object(adopt)
    {
    }

    SymbolEffectOptions SymbolEffectOptions::options()
    {
        return cocoon::internal::wrap<SymbolEffectOptions>([::NSSymbolEffectOptions options]);
    }

    SymbolEffectOptions SymbolEffectOptions::options_with_non_repeating() const
    {
        return cocoon::internal::wrap<SymbolEffectOptions>([cocoon::internal::ns<::NSSymbolEffectOptions>(this) optionsWithNonRepeating]);
    }

    SymbolEffectOptions SymbolEffectOptions::options_with_repeat_count(std::int64_t count) const
    {
        return cocoon::internal::wrap<SymbolEffectOptions>([cocoon::internal::ns<::NSSymbolEffectOptions>(this) optionsWithRepeatCount:static_cast<::NSInteger>(count)]);
    }

    SymbolEffectOptions SymbolEffectOptions::options_with_repeating() const
    {
        return cocoon::internal::wrap<SymbolEffectOptions>([cocoon::internal::ns<::NSSymbolEffectOptions>(this) optionsWithRepeating]);
    }

    SymbolEffectOptions SymbolEffectOptions::options_with_speed(double speed) const
    {
        return cocoon::internal::wrap<SymbolEffectOptions>([cocoon::internal::ns<::NSSymbolEffectOptions>(this) optionsWithSpeed:static_cast<double>(speed)]);
    }
}
