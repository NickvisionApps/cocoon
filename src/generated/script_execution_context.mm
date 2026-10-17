#include "generated/script_execution_context.h"
#include "internal.h"

namespace cocoon
{
    ScriptExecutionContext::ScriptExecutionContext() : ScriptExecutionContext(Adopt{cocoon::internal::retain([[::NSScriptExecutionContext alloc] init])})
    {
    }

    ScriptExecutionContext::ScriptExecutionContext(std::nullptr_t) : Object(nullptr)
    {
    }

    ScriptExecutionContext::ScriptExecutionContext(Adopt adopt) : Object(adopt)
    {
    }

    ScriptExecutionContext ScriptExecutionContext::shared_script_execution_context()
    {
        return cocoon::internal::wrap<ScriptExecutionContext>([::NSScriptExecutionContext sharedScriptExecutionContext]);
    }

    Object ScriptExecutionContext::object_being_tested() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSScriptExecutionContext>(this) objectBeingTested]);
    }

    void ScriptExecutionContext::set_object_being_tested(const Object& value) const
    {
        [cocoon::internal::ns<::NSScriptExecutionContext>(this) setObjectBeingTested:cocoon::internal::native_id(value)];
    }

    Object ScriptExecutionContext::range_container_object() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSScriptExecutionContext>(this) rangeContainerObject]);
    }

    void ScriptExecutionContext::set_range_container_object(const Object& value) const
    {
        [cocoon::internal::ns<::NSScriptExecutionContext>(this) setRangeContainerObject:cocoon::internal::native_id(value)];
    }

    Object ScriptExecutionContext::top_level_object() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSScriptExecutionContext>(this) topLevelObject]);
    }

    void ScriptExecutionContext::set_top_level_object(const Object& value) const
    {
        [cocoon::internal::ns<::NSScriptExecutionContext>(this) setTopLevelObject:cocoon::internal::native_id(value)];
    }
}
