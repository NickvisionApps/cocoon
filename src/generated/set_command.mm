#include "generated/set_command.h"
#include "internal.h"

namespace cocoon
{
    SetCommand::SetCommand() : SetCommand(Adopt{cocoon::internal::retain([[::NSSetCommand alloc] init])})
    {
    }

    SetCommand::SetCommand(std::nullptr_t) : ScriptCommand(nullptr)
    {
    }

    SetCommand::SetCommand(Adopt adopt) : ScriptCommand(adopt)
    {
    }

    void SetCommand::set_receivers_specifier(const ScriptObjectSpecifier& receivers_ref) const
    {
        [cocoon::internal::ns<::NSSetCommand>(this) setReceiversSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(receivers_ref)];
    }

    ScriptObjectSpecifier SetCommand::key_specifier() const
    {
        return cocoon::internal::wrap<ScriptObjectSpecifier>([cocoon::internal::ns<::NSSetCommand>(this) keySpecifier]);
    }
}
