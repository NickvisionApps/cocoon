#include "generated/close_command.h"
#include "internal.h"

namespace cocoon
{
    CloseCommand::CloseCommand() : CloseCommand(Adopt{cocoon::internal::retain([[::NSCloseCommand alloc] init])})
    {
    }

    CloseCommand::CloseCommand(std::nullptr_t) : ScriptCommand(nullptr)
    {
    }

    CloseCommand::CloseCommand(Adopt adopt) : ScriptCommand(adopt)
    {
    }

    SaveOptions CloseCommand::save_options() const
    {
        return static_cast<SaveOptions>([cocoon::internal::ns<::NSCloseCommand>(this) saveOptions]);
    }
}
