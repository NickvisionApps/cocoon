#include "generated/unique_id_specifier.h"
#include "internal.h"

namespace cocoon
{
    UniqueIDSpecifier::UniqueIDSpecifier(const ScriptClassDescription& class_desc, const ScriptObjectSpecifier& container, const std::string& property, const Object& unique_id) : UniqueIDSpecifier(Adopt{cocoon::internal::retain([[::NSUniqueIDSpecifier alloc] initWithContainerClassDescription:cocoon::internal::native<::NSScriptClassDescription>(class_desc) containerSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(container) key:cocoon::internal::to(property) uniqueID:cocoon::internal::native_id(unique_id)])})
    {
    }

    UniqueIDSpecifier::UniqueIDSpecifier() : UniqueIDSpecifier(Adopt{cocoon::internal::retain([[::NSUniqueIDSpecifier alloc] init])})
    {
    }

    UniqueIDSpecifier::UniqueIDSpecifier(std::nullptr_t) : ScriptObjectSpecifier(nullptr)
    {
    }

    UniqueIDSpecifier::UniqueIDSpecifier(Adopt adopt) : ScriptObjectSpecifier(adopt)
    {
    }

    Object UniqueIDSpecifier::unique_id() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSUniqueIDSpecifier>(this) uniqueID]);
    }

    void UniqueIDSpecifier::set_unique_id(const Object& value) const
    {
        [cocoon::internal::ns<::NSUniqueIDSpecifier>(this) setUniqueID:cocoon::internal::native_id(value)];
    }
}
