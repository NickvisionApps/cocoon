#include "generated/index_specifier.h"
#include "internal.h"

namespace cocoon
{
    IndexSpecifier::IndexSpecifier(const ScriptClassDescription& class_desc, const ScriptObjectSpecifier& container, const std::string& property, std::int64_t index) : IndexSpecifier(Adopt{cocoon::internal::retain([[::NSIndexSpecifier alloc] initWithContainerClassDescription:cocoon::internal::native<::NSScriptClassDescription>(class_desc) containerSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(container) key:cocoon::internal::to(property) index:static_cast<::NSInteger>(index)])})
    {
    }

    IndexSpecifier::IndexSpecifier() : IndexSpecifier(Adopt{cocoon::internal::retain([[::NSIndexSpecifier alloc] init])})
    {
    }

    IndexSpecifier::IndexSpecifier(std::nullptr_t) : ScriptObjectSpecifier(nullptr)
    {
    }

    IndexSpecifier::IndexSpecifier(Adopt adopt) : ScriptObjectSpecifier(adopt)
    {
    }

    std::int64_t IndexSpecifier::index() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSIndexSpecifier>(this) index]);
    }

    void IndexSpecifier::set_index(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSIndexSpecifier>(this) setIndex:static_cast<::NSInteger>(value)];
    }
}
