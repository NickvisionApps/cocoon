#include "generated/script_coercion_handler.h"
#include "internal.h"

namespace cocoon
{
    ScriptCoercionHandler::ScriptCoercionHandler() : ScriptCoercionHandler(Adopt{cocoon::internal::retain([[::NSScriptCoercionHandler alloc] init])})
    {
    }

    ScriptCoercionHandler::ScriptCoercionHandler(std::nullptr_t) : Object(nullptr)
    {
    }

    ScriptCoercionHandler::ScriptCoercionHandler(Adopt adopt) : Object(adopt)
    {
    }

    Object ScriptCoercionHandler::coerce_value(const Object& value, const std::string& to_class) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSScriptCoercionHandler>(this) coerceValue:cocoon::internal::native_id(value) toClass:NSClassFromString(cocoon::internal::to(to_class))]);
    }

    void ScriptCoercionHandler::register_coercer(const Object& coercer, const std::string& selector, const std::string& from_class, const std::string& to_class) const
    {
        [cocoon::internal::ns<::NSScriptCoercionHandler>(this) registerCoercer:cocoon::internal::native_id(coercer) selector:NSSelectorFromString(cocoon::internal::to(selector)) toConvertFromClass:NSClassFromString(cocoon::internal::to(from_class)) toClass:NSClassFromString(cocoon::internal::to(to_class))];
    }

    ScriptCoercionHandler ScriptCoercionHandler::shared_coercion_handler()
    {
        return cocoon::internal::wrap<ScriptCoercionHandler>([::NSScriptCoercionHandler sharedCoercionHandler]);
    }
}
