#include "generated/inflection_rule_explicit.h"
#include "internal.h"

namespace cocoon
{
    InflectionRuleExplicit::InflectionRuleExplicit(const Morphology& morphology) : InflectionRuleExplicit(Adopt{cocoon::internal::retain([[::NSInflectionRuleExplicit alloc] initWithMorphology:cocoon::internal::native<::NSMorphology>(morphology)])})
    {
    }

    InflectionRuleExplicit::InflectionRuleExplicit() : InflectionRule(nullptr)
    {
    }

    InflectionRuleExplicit::InflectionRuleExplicit(std::nullptr_t) : InflectionRule(nullptr)
    {
    }

    InflectionRuleExplicit::InflectionRuleExplicit(Adopt adopt) : InflectionRule(adopt)
    {
    }

    Morphology InflectionRuleExplicit::morphology() const
    {
        return cocoon::internal::wrap<Morphology>([cocoon::internal::ns<::NSInflectionRuleExplicit>(this) morphology]);
    }
}
