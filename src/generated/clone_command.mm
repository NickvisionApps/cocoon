#include "generated/clone_command.h"
#include "internal.h"

namespace cocoon
{
    CloneCommand::CloneCommand() : CloneCommand(Adopt{cocoon::internal::retain([[::NSCloneCommand alloc] init])})
    {
    }

    CloneCommand::CloneCommand(std::nullptr_t) : ScriptCommand(nullptr)
    {
    }

    CloneCommand::CloneCommand(Adopt adopt) : ScriptCommand(adopt)
    {
    }

    void CloneCommand::set_receivers_specifier(const ScriptObjectSpecifier& receivers_ref) const
    {
        [cocoon::internal::ns<::NSCloneCommand>(this) setReceiversSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(receivers_ref)];
    }

    ScriptObjectSpecifier CloneCommand::key_specifier() const
    {
        return cocoon::internal::wrap<ScriptObjectSpecifier>([cocoon::internal::ns<::NSCloneCommand>(this) keySpecifier]);
    }
}
