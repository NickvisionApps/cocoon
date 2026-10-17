#include "generated/range_specifier.h"
#include "internal.h"

namespace cocoon
{
    RangeSpecifier::RangeSpecifier(const ScriptClassDescription& class_desc, const ScriptObjectSpecifier& container, const std::string& property, const ScriptObjectSpecifier& start_spec, const ScriptObjectSpecifier& end_spec) : RangeSpecifier(Adopt{cocoon::internal::retain([[::NSRangeSpecifier alloc] initWithContainerClassDescription:cocoon::internal::native<::NSScriptClassDescription>(class_desc) containerSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(container) key:cocoon::internal::to(property) startSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(start_spec) endSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(end_spec)])})
    {
    }

    RangeSpecifier::RangeSpecifier() : RangeSpecifier(Adopt{cocoon::internal::retain([[::NSRangeSpecifier alloc] init])})
    {
    }

    RangeSpecifier::RangeSpecifier(std::nullptr_t) : ScriptObjectSpecifier(nullptr)
    {
    }

    RangeSpecifier::RangeSpecifier(Adopt adopt) : ScriptObjectSpecifier(adopt)
    {
    }

    ScriptObjectSpecifier RangeSpecifier::end_specifier() const
    {
        return cocoon::internal::wrap<ScriptObjectSpecifier>([cocoon::internal::ns<::NSRangeSpecifier>(this) endSpecifier]);
    }

    void RangeSpecifier::set_end_specifier(const ScriptObjectSpecifier& value) const
    {
        [cocoon::internal::ns<::NSRangeSpecifier>(this) setEndSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(value)];
    }

    ScriptObjectSpecifier RangeSpecifier::start_specifier() const
    {
        return cocoon::internal::wrap<ScriptObjectSpecifier>([cocoon::internal::ns<::NSRangeSpecifier>(this) startSpecifier]);
    }

    void RangeSpecifier::set_start_specifier(const ScriptObjectSpecifier& value) const
    {
        [cocoon::internal::ns<::NSRangeSpecifier>(this) setStartSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(value)];
    }
}
