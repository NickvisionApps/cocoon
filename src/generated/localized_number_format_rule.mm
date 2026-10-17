#include "generated/localized_number_format_rule.h"
#include "internal.h"

namespace cocoon
{
    LocalizedNumberFormatRule::LocalizedNumberFormatRule() : Object(nullptr)
    {
    }

    LocalizedNumberFormatRule::LocalizedNumberFormatRule(std::nullptr_t) : Object(nullptr)
    {
    }

    LocalizedNumberFormatRule::LocalizedNumberFormatRule(Adopt adopt) : Object(adopt)
    {
    }

    LocalizedNumberFormatRule LocalizedNumberFormatRule::automatic()
    {
        return cocoon::internal::wrap<LocalizedNumberFormatRule>([::NSLocalizedNumberFormatRule automatic]);
    }
}
