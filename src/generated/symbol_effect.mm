#include "generated/symbol_effect.h"
#include "internal.h"

namespace cocoon
{
    SymbolEffect::SymbolEffect() : Object(nullptr)
    {
    }

    SymbolEffect::SymbolEffect(std::nullptr_t) : Object(nullptr)
    {
    }

    SymbolEffect::SymbolEffect(Adopt adopt) : Object(adopt)
    {
    }
}
