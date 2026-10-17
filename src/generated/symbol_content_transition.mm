#include "generated/symbol_content_transition.h"
#include "internal.h"

namespace cocoon
{
    SymbolContentTransition::SymbolContentTransition() : Object(nullptr)
    {
    }

    SymbolContentTransition::SymbolContentTransition(std::nullptr_t) : Object(nullptr)
    {
    }

    SymbolContentTransition::SymbolContentTransition(Adopt adopt) : Object(adopt)
    {
    }
}
