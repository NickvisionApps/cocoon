#include "generated/script_command_description.h"
#include "internal.h"

namespace cocoon
{
    ScriptCommandDescription::ScriptCommandDescription(const std::string& suite_name, const std::string& command_name, const std::vector<std::pair<Object, Object>>& command_declaration) : ScriptCommandDescription(Adopt{cocoon::internal::retain([[::NSScriptCommandDescription alloc] initWithSuiteName:cocoon::internal::to(suite_name)
                                                                                                                                                                                                                                                                                  commandName:cocoon::internal::to(command_name)
                                                                                                                                                                                                                                                                                   dictionary:cocoon::internal::to_dictionary(command_declaration, [](const Object& k) -> id
                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                    return cocoon::internal::native_id(k);
                                                                                                                                                                                                                                                                                                                },
                                                                                                                                                                                                                                                                                                                [](const Object& v) -> id
                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                    return cocoon::internal::native_id(v);
                                                                                                                                                                                                                                                                                                                })])})
    {
    }

    ScriptCommandDescription::ScriptCommandDescription() : Object(nullptr)
    {
    }

    ScriptCommandDescription::ScriptCommandDescription(std::nullptr_t) : Object(nullptr)
    {
    }

    ScriptCommandDescription::ScriptCommandDescription(Adopt adopt) : Object(adopt)
    {
    }

    unsigned int ScriptCommandDescription::apple_event_code_for_argument_with_name(const std::string& argument_name) const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSScriptCommandDescription>(this) appleEventCodeForArgumentWithName:cocoon::internal::to(argument_name)]);
    }

    ScriptCommand ScriptCommandDescription::create_command_instance() const
    {
        return cocoon::internal::wrap<ScriptCommand>([cocoon::internal::ns<::NSScriptCommandDescription>(this) createCommandInstance]);
    }

    bool ScriptCommandDescription::is_optional_argument_with_name(const std::string& argument_name) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScriptCommandDescription>(this) isOptionalArgumentWithName:cocoon::internal::to(argument_name)]);
    }

    std::string ScriptCommandDescription::type_for_argument_with_name(const std::string& argument_name) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScriptCommandDescription>(this) typeForArgumentWithName:cocoon::internal::to(argument_name)]);
    }

    unsigned int ScriptCommandDescription::apple_event_class_code() const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSScriptCommandDescription>(this) appleEventClassCode]);
    }

    unsigned int ScriptCommandDescription::apple_event_code() const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSScriptCommandDescription>(this) appleEventCode]);
    }

    unsigned int ScriptCommandDescription::apple_event_code_for_return_type() const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSScriptCommandDescription>(this) appleEventCodeForReturnType]);
    }

    std::vector<std::string> ScriptCommandDescription::argument_names() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSScriptCommandDescription>(this) argumentNames], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::string ScriptCommandDescription::command_class_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScriptCommandDescription>(this) commandClassName]);
    }

    std::string ScriptCommandDescription::command_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScriptCommandDescription>(this) commandName]);
    }

    std::string ScriptCommandDescription::return_type() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScriptCommandDescription>(this) returnType]);
    }

    std::string ScriptCommandDescription::suite_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScriptCommandDescription>(this) suiteName]);
    }
}
