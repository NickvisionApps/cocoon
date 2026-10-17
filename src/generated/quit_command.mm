#include "generated/quit_command.h"
#include "internal.h"

namespace cocoon
{
    QuitCommand::QuitCommand() : QuitCommand(Adopt{cocoon::internal::retain([[::NSQuitCommand alloc] init])})
    {
    }

    QuitCommand::QuitCommand(std::nullptr_t) : ScriptCommand(nullptr)
    {
    }

    QuitCommand::QuitCommand(Adopt adopt) : ScriptCommand(adopt)
    {
    }

    SaveOptions QuitCommand::save_options() const
    {
        return static_cast<SaveOptions>([cocoon::internal::ns<::NSQuitCommand>(this) saveOptions]);
    }
}
