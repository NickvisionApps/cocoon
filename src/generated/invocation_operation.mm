#include "generated/invocation_operation.h"
#include "internal.h"

namespace cocoon
{
    InvocationOperation::InvocationOperation(const Invocation& inv) : InvocationOperation(Adopt{cocoon::internal::retain([[::NSInvocationOperation alloc] initWithInvocation:cocoon::internal::native<::NSInvocation>(inv)])})
    {
    }

    InvocationOperation::InvocationOperation(const Object& target, const std::string& sel, const Object& arg) : InvocationOperation(Adopt{cocoon::internal::retain([[::NSInvocationOperation alloc] initWithTarget:cocoon::internal::native_id(target) selector:NSSelectorFromString(cocoon::internal::to(sel)) object:cocoon::internal::native_id(arg)])})
    {
    }

    InvocationOperation::InvocationOperation() : InvocationOperation(Adopt{cocoon::internal::retain([[::NSInvocationOperation alloc] init])})
    {
    }

    InvocationOperation::InvocationOperation(std::nullptr_t) : Operation(nullptr)
    {
    }

    InvocationOperation::InvocationOperation(Adopt adopt) : Operation(adopt)
    {
    }

    Invocation InvocationOperation::invocation() const
    {
        return cocoon::internal::wrap<Invocation>([cocoon::internal::ns<::NSInvocationOperation>(this) invocation]);
    }

    Object InvocationOperation::result() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSInvocationOperation>(this) result]);
    }
}
