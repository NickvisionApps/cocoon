#include "generated/method_signature.h"
#include "internal.h"

namespace cocoon
{
    MethodSignature::MethodSignature() : MethodSignature(Adopt{cocoon::internal::retain([[::NSMethodSignature alloc] init])})
    {
    }

    MethodSignature::MethodSignature(std::nullptr_t) : Object(nullptr)
    {
    }

    MethodSignature::MethodSignature(Adopt adopt) : Object(adopt)
    {
    }

    std::string MethodSignature::get_argument_type_at_index(std::uint64_t idx) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMethodSignature>(this) getArgumentTypeAtIndex:static_cast<::NSUInteger>(idx)]);
    }

    bool MethodSignature::is_oneway() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMethodSignature>(this) isOneway]);
    }

    MethodSignature MethodSignature::signature_with_obj_c_types(const std::string& types)
    {
        return cocoon::internal::wrap<MethodSignature>([::NSMethodSignature signatureWithObjCTypes:types.c_str()]);
    }

    std::uint64_t MethodSignature::frame_length() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSMethodSignature>(this) frameLength]);
    }

    std::uint64_t MethodSignature::method_return_length() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSMethodSignature>(this) methodReturnLength]);
    }

    std::string MethodSignature::method_return_type() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMethodSignature>(this) methodReturnType]);
    }

    std::uint64_t MethodSignature::number_of_arguments() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSMethodSignature>(this) numberOfArguments]);
    }
}
