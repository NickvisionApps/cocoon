#include "generated/name_specifier.h"
#include "internal.h"

namespace cocoon
{
    NameSpecifier::NameSpecifier(const ScriptClassDescription& class_desc, const ScriptObjectSpecifier& container, const std::string& property, const std::string& name) : NameSpecifier(Adopt{cocoon::internal::retain([[::NSNameSpecifier alloc] initWithContainerClassDescription:cocoon::internal::native<::NSScriptClassDescription>(class_desc) containerSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(container) key:cocoon::internal::to(property) name:cocoon::internal::to(name)])})
    {
    }

    NameSpecifier::NameSpecifier() : NameSpecifier(Adopt{cocoon::internal::retain([[::NSNameSpecifier alloc] init])})
    {
    }

    NameSpecifier::NameSpecifier(std::nullptr_t) : ScriptObjectSpecifier(nullptr)
    {
    }

    NameSpecifier::NameSpecifier(Adopt adopt) : ScriptObjectSpecifier(adopt)
    {
    }

    std::string NameSpecifier::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNameSpecifier>(this) name]);
    }

    void NameSpecifier::set_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNameSpecifier>(this) setName:cocoon::internal::to(value)];
    }
}
