#include "generated/inflection_rule.h"
#include "internal.h"

namespace cocoon
{
    InflectionRule::InflectionRule() : Object(nullptr)
    {
    }

    InflectionRule::InflectionRule(std::nullptr_t) : Object(nullptr)
    {
    }

    InflectionRule::InflectionRule(Adopt adopt) : Object(adopt)
    {
    }

    bool InflectionRule::can_inflect_language(const std::string& language)
    {
        return static_cast<bool>([::NSInflectionRule canInflectLanguage:cocoon::internal::to(language)]);
    }

    InflectionRule InflectionRule::automatic_rule()
    {
        return cocoon::internal::wrap<InflectionRule>([::NSInflectionRule automaticRule]);
    }

    bool InflectionRule::can_inflect_preferred_localization()
    {
        return static_cast<bool>([::NSInflectionRule canInflectPreferredLocalization]);
    }
}
