#include "generated/script_suite_registry.h"
#include "internal.h"

namespace cocoon
{
    ScriptSuiteRegistry::ScriptSuiteRegistry() : ScriptSuiteRegistry(Adopt{cocoon::internal::retain([[::NSScriptSuiteRegistry alloc] init])})
    {
    }

    ScriptSuiteRegistry::ScriptSuiteRegistry(std::nullptr_t) : Object(nullptr)
    {
    }

    ScriptSuiteRegistry::ScriptSuiteRegistry(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<std::uint8_t> ScriptSuiteRegistry::aete_resource(const std::string& language_name) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSScriptSuiteRegistry>(this) aeteResource:cocoon::internal::to(language_name)]);
    }

    unsigned int ScriptSuiteRegistry::apple_event_code_for_suite(const std::string& suite_name) const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSScriptSuiteRegistry>(this) appleEventCodeForSuite:cocoon::internal::to(suite_name)]);
    }

    Bundle ScriptSuiteRegistry::bundle_for_suite(const std::string& suite_name) const
    {
        return cocoon::internal::wrap<Bundle>([cocoon::internal::ns<::NSScriptSuiteRegistry>(this) bundleForSuite:cocoon::internal::to(suite_name)]);
    }

    ScriptClassDescription ScriptSuiteRegistry::class_description_with_apple_event_code(unsigned int apple_event_code) const
    {
        return cocoon::internal::wrap<ScriptClassDescription>([cocoon::internal::ns<::NSScriptSuiteRegistry>(this) classDescriptionWithAppleEventCode:static_cast<::FourCharCode>(apple_event_code)]);
    }

    std::map<std::string, ScriptClassDescription> ScriptSuiteRegistry::class_descriptions_in_suite(const std::string& suite_name) const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, ScriptClassDescription>>([cocoon::internal::ns<::NSScriptSuiteRegistry>(this) classDescriptionsInSuite:cocoon::internal::to(suite_name)], [](id k) -> std::string
                                                                                                {
                                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                                },
                                                                                                [](id v) -> ScriptClassDescription
                                                                                                {
                                                                                                    return cocoon::internal::wrap<ScriptClassDescription>((::NSScriptClassDescription*)v);
                                                                                                });
    }

    ScriptCommandDescription ScriptSuiteRegistry::command_description_with_apple_event_class(unsigned int apple_event_class_code, unsigned int apple_event_id_code) const
    {
        return cocoon::internal::wrap<ScriptCommandDescription>([cocoon::internal::ns<::NSScriptSuiteRegistry>(this) commandDescriptionWithAppleEventClass:static_cast<::FourCharCode>(apple_event_class_code) andAppleEventCode:static_cast<::FourCharCode>(apple_event_id_code)]);
    }

    std::map<std::string, ScriptCommandDescription> ScriptSuiteRegistry::command_descriptions_in_suite(const std::string& suite_name) const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, ScriptCommandDescription>>([cocoon::internal::ns<::NSScriptSuiteRegistry>(this) commandDescriptionsInSuite:cocoon::internal::to(suite_name)], [](id k) -> std::string
                                                                                                  {
                                                                                                      return cocoon::internal::from((NSString*)k);
                                                                                                  },
                                                                                                  [](id v) -> ScriptCommandDescription
                                                                                                  {
                                                                                                      return cocoon::internal::wrap<ScriptCommandDescription>((::NSScriptCommandDescription*)v);
                                                                                                  });
    }

    void ScriptSuiteRegistry::load_suite_with_dictionary(const std::vector<std::pair<Object, Object>>& suite_declaration, const Bundle& bundle) const
    {
        [cocoon::internal::ns<::NSScriptSuiteRegistry>(this) loadSuiteWithDictionary:cocoon::internal::to_dictionary(suite_declaration, [](const Object& k) -> id
                                                                                                                     {
                                                                                                                         return cocoon::internal::native_id(k);
                                                                                                                     },
                                                                                                                     [](const Object& v) -> id
                                                                                                                     {
                                                                                                                         return cocoon::internal::native_id(v);
                                                                                                                     })
                                                                          fromBundle:cocoon::internal::native<::NSBundle>(bundle)];
    }

    void ScriptSuiteRegistry::load_suites_from_bundle(const Bundle& bundle) const
    {
        [cocoon::internal::ns<::NSScriptSuiteRegistry>(this) loadSuitesFromBundle:cocoon::internal::native<::NSBundle>(bundle)];
    }

    void ScriptSuiteRegistry::register_class_description(const ScriptClassDescription& class_description) const
    {
        [cocoon::internal::ns<::NSScriptSuiteRegistry>(this) registerClassDescription:cocoon::internal::native<::NSScriptClassDescription>(class_description)];
    }

    void ScriptSuiteRegistry::register_command_description(const ScriptCommandDescription& command_description) const
    {
        [cocoon::internal::ns<::NSScriptSuiteRegistry>(this) registerCommandDescription:cocoon::internal::native<::NSScriptCommandDescription>(command_description)];
    }

    void ScriptSuiteRegistry::set_shared_script_suite_registry(const ScriptSuiteRegistry& registry)
    {
        [::NSScriptSuiteRegistry setSharedScriptSuiteRegistry:cocoon::internal::native<::NSScriptSuiteRegistry>(registry)];
    }

    ScriptSuiteRegistry ScriptSuiteRegistry::shared_script_suite_registry()
    {
        return cocoon::internal::wrap<ScriptSuiteRegistry>([::NSScriptSuiteRegistry sharedScriptSuiteRegistry]);
    }

    std::string ScriptSuiteRegistry::suite_for_apple_event_code(unsigned int apple_event_code) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScriptSuiteRegistry>(this) suiteForAppleEventCode:static_cast<::FourCharCode>(apple_event_code)]);
    }

    std::vector<std::string> ScriptSuiteRegistry::suite_names() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSScriptSuiteRegistry>(this) suiteNames], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }
}
