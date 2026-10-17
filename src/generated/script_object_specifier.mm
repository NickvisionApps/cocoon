#include "generated/script_object_specifier.h"
#include "internal.h"

namespace cocoon
{
    ScriptObjectSpecifier::ScriptObjectSpecifier(const ScriptClassDescription& class_desc, const ScriptObjectSpecifier& container, const std::string& property) : ScriptObjectSpecifier(Adopt{cocoon::internal::retain([[::NSScriptObjectSpecifier alloc] initWithContainerClassDescription:cocoon::internal::native<::NSScriptClassDescription>(class_desc) containerSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(container) key:cocoon::internal::to(property)])})
    {
    }

    ScriptObjectSpecifier::ScriptObjectSpecifier(const ScriptObjectSpecifier& container, const std::string& property) : ScriptObjectSpecifier(Adopt{cocoon::internal::retain([[::NSScriptObjectSpecifier alloc] initWithContainerSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(container) key:cocoon::internal::to(property)])})
    {
    }

    ScriptObjectSpecifier::ScriptObjectSpecifier() : ScriptObjectSpecifier(Adopt{cocoon::internal::retain([[::NSScriptObjectSpecifier alloc] init])})
    {
    }

    ScriptObjectSpecifier::ScriptObjectSpecifier(std::nullptr_t) : Object(nullptr)
    {
    }

    ScriptObjectSpecifier::ScriptObjectSpecifier(Adopt adopt) : Object(adopt)
    {
    }

    std::int64_t* ScriptObjectSpecifier::indices_of_objects_by_evaluating_with_container(const Object& container, std::int64_t* count) const
    {
        return (std::int64_t*)([cocoon::internal::ns<::NSScriptObjectSpecifier>(this) indicesOfObjectsByEvaluatingWithContainer:cocoon::internal::native_id(container) count:(::NSInteger*)(count)]);
    }

    ScriptObjectSpecifier ScriptObjectSpecifier::object_specifier_with_descriptor(const AppleEventDescriptor& descriptor)
    {
        return cocoon::internal::wrap<ScriptObjectSpecifier>([::NSScriptObjectSpecifier objectSpecifierWithDescriptor:cocoon::internal::native<::NSAppleEventDescriptor>(descriptor)]);
    }

    Object ScriptObjectSpecifier::objects_by_evaluating_with_containers(const Object& containers) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSScriptObjectSpecifier>(this) objectsByEvaluatingWithContainers:cocoon::internal::native_id(containers)]);
    }

    ScriptObjectSpecifier ScriptObjectSpecifier::child_specifier() const
    {
        return cocoon::internal::wrap<ScriptObjectSpecifier>([cocoon::internal::ns<::NSScriptObjectSpecifier>(this) childSpecifier]);
    }

    void ScriptObjectSpecifier::set_child_specifier(const ScriptObjectSpecifier& value) const
    {
        [cocoon::internal::ns<::NSScriptObjectSpecifier>(this) setChildSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(value)];
    }

    ScriptClassDescription ScriptObjectSpecifier::container_class_description() const
    {
        return cocoon::internal::wrap<ScriptClassDescription>([cocoon::internal::ns<::NSScriptObjectSpecifier>(this) containerClassDescription]);
    }

    void ScriptObjectSpecifier::set_container_class_description(const ScriptClassDescription& value) const
    {
        [cocoon::internal::ns<::NSScriptObjectSpecifier>(this) setContainerClassDescription:cocoon::internal::native<::NSScriptClassDescription>(value)];
    }

    bool ScriptObjectSpecifier::container_is_object_being_tested() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScriptObjectSpecifier>(this) containerIsObjectBeingTested]);
    }

    void ScriptObjectSpecifier::set_container_is_object_being_tested(bool value) const
    {
        [cocoon::internal::ns<::NSScriptObjectSpecifier>(this) setContainerIsObjectBeingTested:static_cast<::BOOL>(value)];
    }

    bool ScriptObjectSpecifier::container_is_range_container_object() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScriptObjectSpecifier>(this) containerIsRangeContainerObject]);
    }

    void ScriptObjectSpecifier::set_container_is_range_container_object(bool value) const
    {
        [cocoon::internal::ns<::NSScriptObjectSpecifier>(this) setContainerIsRangeContainerObject:static_cast<::BOOL>(value)];
    }

    ScriptObjectSpecifier ScriptObjectSpecifier::container_specifier() const
    {
        return cocoon::internal::wrap<ScriptObjectSpecifier>([cocoon::internal::ns<::NSScriptObjectSpecifier>(this) containerSpecifier]);
    }

    void ScriptObjectSpecifier::set_container_specifier(const ScriptObjectSpecifier& value) const
    {
        [cocoon::internal::ns<::NSScriptObjectSpecifier>(this) setContainerSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(value)];
    }

    AppleEventDescriptor ScriptObjectSpecifier::descriptor() const
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([cocoon::internal::ns<::NSScriptObjectSpecifier>(this) descriptor]);
    }

    std::int64_t ScriptObjectSpecifier::evaluation_error_number() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSScriptObjectSpecifier>(this) evaluationErrorNumber]);
    }

    void ScriptObjectSpecifier::set_evaluation_error_number(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSScriptObjectSpecifier>(this) setEvaluationErrorNumber:static_cast<::NSInteger>(value)];
    }

    ScriptObjectSpecifier ScriptObjectSpecifier::evaluation_error_specifier() const
    {
        return cocoon::internal::wrap<ScriptObjectSpecifier>([cocoon::internal::ns<::NSScriptObjectSpecifier>(this) evaluationErrorSpecifier]);
    }

    std::string ScriptObjectSpecifier::key() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScriptObjectSpecifier>(this) key]);
    }

    void ScriptObjectSpecifier::set_key(const std::string& value) const
    {
        [cocoon::internal::ns<::NSScriptObjectSpecifier>(this) setKey:cocoon::internal::to(value)];
    }

    ScriptClassDescription ScriptObjectSpecifier::key_class_description() const
    {
        return cocoon::internal::wrap<ScriptClassDescription>([cocoon::internal::ns<::NSScriptObjectSpecifier>(this) keyClassDescription]);
    }

    Object ScriptObjectSpecifier::objects_by_evaluating_specifier() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSScriptObjectSpecifier>(this) objectsByEvaluatingSpecifier]);
    }
}
