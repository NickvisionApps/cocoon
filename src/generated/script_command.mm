#include "generated/script_command.h"
#include "internal.h"

namespace cocoon
{
    ScriptCommand::ScriptCommand(const ScriptCommandDescription& command_def) : ScriptCommand(Adopt{cocoon::internal::retain([[::NSScriptCommand alloc] initWithCommandDescription:cocoon::internal::native<::NSScriptCommandDescription>(command_def)])})
    {
    }

    ScriptCommand::ScriptCommand() : ScriptCommand(Adopt{cocoon::internal::retain([[::NSScriptCommand alloc] init])})
    {
    }

    ScriptCommand::ScriptCommand(std::nullptr_t) : Object(nullptr)
    {
    }

    ScriptCommand::ScriptCommand(Adopt adopt) : Object(adopt)
    {
    }

    ScriptCommand ScriptCommand::current_command()
    {
        return cocoon::internal::wrap<ScriptCommand>([::NSScriptCommand currentCommand]);
    }

    Object ScriptCommand::execute_command() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSScriptCommand>(this) executeCommand]);
    }

    Object ScriptCommand::perform_default_implementation() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSScriptCommand>(this) performDefaultImplementation]);
    }

    void ScriptCommand::resume_execution_with_result(const Object& result) const
    {
        [cocoon::internal::ns<::NSScriptCommand>(this) resumeExecutionWithResult:cocoon::internal::native_id(result)];
    }

    void ScriptCommand::suspend_execution() const
    {
        [cocoon::internal::ns<::NSScriptCommand>(this) suspendExecution];
    }

    AppleEventDescriptor ScriptCommand::apple_event() const
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([cocoon::internal::ns<::NSScriptCommand>(this) appleEvent]);
    }

    std::map<std::string, Object> ScriptCommand::arguments() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSScriptCommand>(this) arguments], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    void ScriptCommand::set_arguments(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::NSScriptCommand>(this) setArguments:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                        {
                                                                            return cocoon::internal::to(k);
                                                                        },
                                                                        [](const Object& v) -> id
                                                                        {
                                                                            return cocoon::internal::native_id(v);
                                                                        })];
    }

    ScriptCommandDescription ScriptCommand::command_description() const
    {
        return cocoon::internal::wrap<ScriptCommandDescription>([cocoon::internal::ns<::NSScriptCommand>(this) commandDescription]);
    }

    Object ScriptCommand::direct_parameter() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSScriptCommand>(this) directParameter]);
    }

    void ScriptCommand::set_direct_parameter(const Object& value) const
    {
        [cocoon::internal::ns<::NSScriptCommand>(this) setDirectParameter:cocoon::internal::native_id(value)];
    }

    std::map<std::string, Object> ScriptCommand::evaluated_arguments() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSScriptCommand>(this) evaluatedArguments], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    Object ScriptCommand::evaluated_receivers() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSScriptCommand>(this) evaluatedReceivers]);
    }

    ScriptObjectSpecifier ScriptCommand::receivers_specifier() const
    {
        return cocoon::internal::wrap<ScriptObjectSpecifier>([cocoon::internal::ns<::NSScriptCommand>(this) receiversSpecifier]);
    }

    void ScriptCommand::set_receivers_specifier(const ScriptObjectSpecifier& value) const
    {
        [cocoon::internal::ns<::NSScriptCommand>(this) setReceiversSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(value)];
    }

    AppleEventDescriptor ScriptCommand::script_error_expected_type_descriptor() const
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([cocoon::internal::ns<::NSScriptCommand>(this) scriptErrorExpectedTypeDescriptor]);
    }

    void ScriptCommand::set_script_error_expected_type_descriptor(const AppleEventDescriptor& value) const
    {
        [cocoon::internal::ns<::NSScriptCommand>(this) setScriptErrorExpectedTypeDescriptor:cocoon::internal::native<::NSAppleEventDescriptor>(value)];
    }

    std::int64_t ScriptCommand::script_error_number() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSScriptCommand>(this) scriptErrorNumber]);
    }

    void ScriptCommand::set_script_error_number(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSScriptCommand>(this) setScriptErrorNumber:static_cast<::NSInteger>(value)];
    }

    AppleEventDescriptor ScriptCommand::script_error_offending_object_descriptor() const
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([cocoon::internal::ns<::NSScriptCommand>(this) scriptErrorOffendingObjectDescriptor]);
    }

    void ScriptCommand::set_script_error_offending_object_descriptor(const AppleEventDescriptor& value) const
    {
        [cocoon::internal::ns<::NSScriptCommand>(this) setScriptErrorOffendingObjectDescriptor:cocoon::internal::native<::NSAppleEventDescriptor>(value)];
    }

    std::string ScriptCommand::script_error_string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScriptCommand>(this) scriptErrorString]);
    }

    void ScriptCommand::set_script_error_string(const std::string& value) const
    {
        [cocoon::internal::ns<::NSScriptCommand>(this) setScriptErrorString:cocoon::internal::to(value)];
    }

    bool ScriptCommand::is_well_formed() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScriptCommand>(this) isWellFormed]);
    }
}
