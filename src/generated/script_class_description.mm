#include "generated/script_class_description.h"
#include "internal.h"

namespace cocoon
{
    ScriptClassDescription::ScriptClassDescription(const std::string& suite_name, const std::string& class_name, const std::vector<std::pair<Object, Object>>& class_declaration) : ScriptClassDescription(Adopt{cocoon::internal::retain([[::NSScriptClassDescription alloc] initWithSuiteName:cocoon::internal::to(suite_name)
                                                                                                                                                                                                                                                                                      className:cocoon::internal::to(class_name)
                                                                                                                                                                                                                                                                                     dictionary:cocoon::internal::to_dictionary(class_declaration, [](const Object& k) -> id
                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                    return cocoon::internal::native_id(k);
                                                                                                                                                                                                                                                                                                                                },
                                                                                                                                                                                                                                                                                                                                [](const Object& v) -> id
                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                    return cocoon::internal::native_id(v);
                                                                                                                                                                                                                                                                                                                                })])})
    {
    }

    ScriptClassDescription::ScriptClassDescription() : ScriptClassDescription(Adopt{cocoon::internal::retain([[::NSScriptClassDescription alloc] init])})
    {
    }

    ScriptClassDescription::ScriptClassDescription(std::nullptr_t) : ClassDescription(nullptr)
    {
    }

    ScriptClassDescription::ScriptClassDescription(Adopt adopt) : ClassDescription(adopt)
    {
    }

    unsigned int ScriptClassDescription::apple_event_code_for_key(const std::string& key) const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSScriptClassDescription>(this) appleEventCodeForKey:cocoon::internal::to(key)]);
    }

    ScriptClassDescription ScriptClassDescription::class_description_for_class(const std::string& a_class)
    {
        return cocoon::internal::wrap<ScriptClassDescription>([::NSScriptClassDescription classDescriptionForClass:NSClassFromString(cocoon::internal::to(a_class))]);
    }

    ScriptClassDescription ScriptClassDescription::class_description_for_key(const std::string& key) const
    {
        return cocoon::internal::wrap<ScriptClassDescription>([cocoon::internal::ns<::NSScriptClassDescription>(this) classDescriptionForKey:cocoon::internal::to(key)]);
    }

    bool ScriptClassDescription::has_ordered_to_many_relationship_for_key(const std::string& key) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScriptClassDescription>(this) hasOrderedToManyRelationshipForKey:cocoon::internal::to(key)]);
    }

    bool ScriptClassDescription::has_property_for_key(const std::string& key) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScriptClassDescription>(this) hasPropertyForKey:cocoon::internal::to(key)]);
    }

    bool ScriptClassDescription::has_readable_property_for_key(const std::string& key) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScriptClassDescription>(this) hasReadablePropertyForKey:cocoon::internal::to(key)]);
    }

    bool ScriptClassDescription::has_writable_property_for_key(const std::string& key) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScriptClassDescription>(this) hasWritablePropertyForKey:cocoon::internal::to(key)]);
    }

    bool ScriptClassDescription::is_location_required_to_create_for_key(const std::string& to_many_relationship_key) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScriptClassDescription>(this) isLocationRequiredToCreateForKey:cocoon::internal::to(to_many_relationship_key)]);
    }

    std::string ScriptClassDescription::key_with_apple_event_code(unsigned int apple_event_code) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScriptClassDescription>(this) keyWithAppleEventCode:static_cast<::FourCharCode>(apple_event_code)]);
    }

    bool ScriptClassDescription::matches_apple_event_code(unsigned int apple_event_code) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScriptClassDescription>(this) matchesAppleEventCode:static_cast<::FourCharCode>(apple_event_code)]);
    }

    std::string ScriptClassDescription::selector_for_command(const ScriptCommandDescription& command_description) const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSScriptClassDescription>(this) selectorForCommand:cocoon::internal::native<::NSScriptCommandDescription>(command_description)]));
    }

    bool ScriptClassDescription::supports_command(const ScriptCommandDescription& command_description) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScriptClassDescription>(this) supportsCommand:cocoon::internal::native<::NSScriptCommandDescription>(command_description)]);
    }

    std::string ScriptClassDescription::type_for_key(const std::string& key) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScriptClassDescription>(this) typeForKey:cocoon::internal::to(key)]);
    }

    unsigned int ScriptClassDescription::apple_event_code() const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSScriptClassDescription>(this) appleEventCode]);
    }

    std::string ScriptClassDescription::class_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScriptClassDescription>(this) className]);
    }

    std::string ScriptClassDescription::default_subcontainer_attribute_key() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScriptClassDescription>(this) defaultSubcontainerAttributeKey]);
    }

    std::string ScriptClassDescription::implementation_class_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScriptClassDescription>(this) implementationClassName]);
    }

    std::string ScriptClassDescription::suite_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScriptClassDescription>(this) suiteName]);
    }

    ScriptClassDescription ScriptClassDescription::superclass_description() const
    {
        return cocoon::internal::wrap<ScriptClassDescription>([cocoon::internal::ns<::NSScriptClassDescription>(this) superclassDescription]);
    }
}
