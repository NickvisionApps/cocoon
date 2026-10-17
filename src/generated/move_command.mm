#include "generated/move_command.h"
#include "internal.h"

namespace cocoon
{
    MoveCommand::MoveCommand() : MoveCommand(Adopt{cocoon::internal::retain([[::NSMoveCommand alloc] init])})
    {
    }

    MoveCommand::MoveCommand(std::nullptr_t) : ScriptCommand(nullptr)
    {
    }

    MoveCommand::MoveCommand(Adopt adopt) : ScriptCommand(adopt)
    {
    }

    void MoveCommand::set_receivers_specifier(const ScriptObjectSpecifier& receivers_ref) const
    {
        [cocoon::internal::ns<::NSMoveCommand>(this) setReceiversSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(receivers_ref)];
    }

    ScriptObjectSpecifier MoveCommand::key_specifier() const
    {
        return cocoon::internal::wrap<ScriptObjectSpecifier>([cocoon::internal::ns<::NSMoveCommand>(this) keySpecifier]);
    }
}
