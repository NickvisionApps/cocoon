#include "generated/unit.h"
#include "internal.h"

namespace cocoon
{
    Unit::Unit(const std::string& symbol) : Unit(Adopt{cocoon::internal::retain([[::NSUnit alloc] initWithSymbol:cocoon::internal::to(symbol)])})
    {
    }

    Unit::Unit() : Object(nullptr)
    {
    }

    Unit::Unit(std::nullptr_t) : Object(nullptr)
    {
    }

    Unit::Unit(Adopt adopt) : Object(adopt)
    {
    }

    std::string Unit::symbol() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUnit>(this) symbol]);
    }
}
