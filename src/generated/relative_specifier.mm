#include "generated/relative_specifier.h"
#include "internal.h"

namespace cocoon
{
    RelativeSpecifier::RelativeSpecifier(const ScriptClassDescription& class_desc, const ScriptObjectSpecifier& container, const std::string& property, RelativePosition rel_pos, const ScriptObjectSpecifier& base_specifier) : RelativeSpecifier(Adopt{cocoon::internal::retain([[::NSRelativeSpecifier alloc] initWithContainerClassDescription:cocoon::internal::native<::NSScriptClassDescription>(class_desc) containerSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(container) key:cocoon::internal::to(property) relativePosition:static_cast<::NSRelativePosition>(rel_pos) baseSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(base_specifier)])})
    {
    }

    RelativeSpecifier::RelativeSpecifier() : RelativeSpecifier(Adopt{cocoon::internal::retain([[::NSRelativeSpecifier alloc] init])})
    {
    }

    RelativeSpecifier::RelativeSpecifier(std::nullptr_t) : ScriptObjectSpecifier(nullptr)
    {
    }

    RelativeSpecifier::RelativeSpecifier(Adopt adopt) : ScriptObjectSpecifier(adopt)
    {
    }

    ScriptObjectSpecifier RelativeSpecifier::base_specifier() const
    {
        return cocoon::internal::wrap<ScriptObjectSpecifier>([cocoon::internal::ns<::NSRelativeSpecifier>(this) baseSpecifier]);
    }

    void RelativeSpecifier::set_base_specifier(const ScriptObjectSpecifier& value) const
    {
        [cocoon::internal::ns<::NSRelativeSpecifier>(this) setBaseSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(value)];
    }

    RelativePosition RelativeSpecifier::relative_position() const
    {
        return static_cast<RelativePosition>([cocoon::internal::ns<::NSRelativeSpecifier>(this) relativePosition]);
    }

    void RelativeSpecifier::set_relative_position(RelativePosition value) const
    {
        [cocoon::internal::ns<::NSRelativeSpecifier>(this) setRelativePosition:static_cast<::NSRelativePosition>(value)];
    }
}
