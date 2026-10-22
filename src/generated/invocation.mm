#include "generated/invocation.h"
#include "internal.h"

namespace cocoon
{
    Invocation::Invocation(const MethodSignature& sig) : Invocation(Adopt{cocoon::internal::retain([::NSInvocation invocationWithMethodSignature:cocoon::internal::native<::NSMethodSignature>(sig)])})
    {
    }

    Invocation::Invocation() : Invocation(Adopt{cocoon::internal::retain([[::NSInvocation alloc] init])})
    {
    }

    Invocation::Invocation(std::nullptr_t) : Object(nullptr)
    {
    }

    Invocation::Invocation(Adopt adopt) : Object(adopt)
    {
    }

    void Invocation::get_argument(void* argument_location, std::int64_t idx) const
    {
        [cocoon::internal::ns<::NSInvocation>(this) getArgument:argument_location atIndex:static_cast<::NSInteger>(idx)];
    }

    void Invocation::get_return_value(void* ret_loc) const
    {
        [cocoon::internal::ns<::NSInvocation>(this) getReturnValue:ret_loc];
    }

    void Invocation::invoke() const
    {
        [cocoon::internal::ns<::NSInvocation>(this) invoke];
    }

    void Invocation::invoke_using_imp(void (*imp)()) const
    {
        [cocoon::internal::ns<::NSInvocation>(this) invokeUsingIMP:(::IMP)(imp)];
    }

    void Invocation::invoke_with_target(const Object& target) const
    {
        [cocoon::internal::ns<::NSInvocation>(this) invokeWithTarget:cocoon::internal::native_id(target)];
    }

    void Invocation::retain_arguments() const
    {
        [cocoon::internal::ns<::NSInvocation>(this) retainArguments];
    }

    void Invocation::set_argument(void* argument_location, std::int64_t idx) const
    {
        [cocoon::internal::ns<::NSInvocation>(this) setArgument:argument_location atIndex:static_cast<::NSInteger>(idx)];
    }

    void Invocation::set_return_value(void* ret_loc) const
    {
        [cocoon::internal::ns<::NSInvocation>(this) setReturnValue:ret_loc];
    }

    bool Invocation::arguments_retained() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSInvocation>(this) argumentsRetained]);
    }

    MethodSignature Invocation::method_signature() const
    {
        return cocoon::internal::wrap<MethodSignature>([cocoon::internal::ns<::NSInvocation>(this) methodSignature]);
    }

    std::string Invocation::selector() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSInvocation>(this) selector]));
    }

    void Invocation::set_selector(const std::string& value) const
    {
        [cocoon::internal::ns<::NSInvocation>(this) setSelector:NSSelectorFromString(cocoon::internal::to(value))];
    }

    Object Invocation::target() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSInvocation>(this) target]);
    }

    void Invocation::set_target(const Object& value) const
    {
        [cocoon::internal::ns<::NSInvocation>(this) setTarget:cocoon::internal::native_id(value)];
    }
}
