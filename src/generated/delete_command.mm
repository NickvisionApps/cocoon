#include "generated/delete_command.h"
#include "internal.h"

namespace cocoon
{
    DeleteCommand::DeleteCommand() : DeleteCommand(Adopt{cocoon::internal::retain([[::NSDeleteCommand alloc] init])})
    {
    }

    DeleteCommand::DeleteCommand(std::nullptr_t) : ScriptCommand(nullptr)
    {
    }

    DeleteCommand::DeleteCommand(Adopt adopt) : ScriptCommand(adopt)
    {
    }

    void DeleteCommand::set_receivers_specifier(const ScriptObjectSpecifier& receivers_ref) const
    {
        [cocoon::internal::ns<::NSDeleteCommand>(this) setReceiversSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(receivers_ref)];
    }

    ScriptObjectSpecifier DeleteCommand::key_specifier() const
    {
        return cocoon::internal::wrap<ScriptObjectSpecifier>([cocoon::internal::ns<::NSDeleteCommand>(this) keySpecifier]);
    }
}
