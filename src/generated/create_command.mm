#include "generated/create_command.h"
#include "internal.h"

namespace cocoon
{
    CreateCommand::CreateCommand() : CreateCommand(Adopt{cocoon::internal::retain([[::NSCreateCommand alloc] init])})
    {
    }

    CreateCommand::CreateCommand(std::nullptr_t) : ScriptCommand(nullptr)
    {
    }

    CreateCommand::CreateCommand(Adopt adopt) : ScriptCommand(adopt)
    {
    }

    ScriptClassDescription CreateCommand::create_class_description() const
    {
        return cocoon::internal::wrap<ScriptClassDescription>([cocoon::internal::ns<::NSCreateCommand>(this) createClassDescription]);
    }

    std::map<std::string, Object> CreateCommand::resolved_key_dictionary() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSCreateCommand>(this) resolvedKeyDictionary], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }
}
