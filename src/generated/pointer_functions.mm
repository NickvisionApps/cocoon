#include "generated/pointer_functions.h"
#include "internal.h"

namespace cocoon
{
    PointerFunctions::PointerFunctions(PointerFunctionsOptions options) : PointerFunctions(Adopt{cocoon::internal::retain([[::NSPointerFunctions alloc] initWithOptions:static_cast<::NSPointerFunctionsOptions>(options)])})
    {
    }

    PointerFunctions::PointerFunctions() : PointerFunctions(Adopt{cocoon::internal::retain([[::NSPointerFunctions alloc] init])})
    {
    }

    PointerFunctions::PointerFunctions(std::nullptr_t) : Object(nullptr)
    {
    }

    PointerFunctions::PointerFunctions(Adopt adopt) : Object(adopt)
    {
    }

    PointerFunctions PointerFunctions::pointer_functions_with_options(PointerFunctionsOptions options)
    {
        return cocoon::internal::wrap<PointerFunctions>([::NSPointerFunctions pointerFunctionsWithOptions:static_cast<::NSPointerFunctionsOptions>(options)]);
    }

    auto PointerFunctions::acquire_function() const -> void* (*)(void*, std::uint64_t (*)(void*), bool)
    {
        return (void* (*)(void*, std::uint64_t (*)(void*), bool))([cocoon::internal::ns<::NSPointerFunctions>(this) acquireFunction]);
    }

    void PointerFunctions::set_acquire_function(void* (*value)(void*, std::uint64_t (*)(void*), bool)) const
    {
        [cocoon::internal::ns<::NSPointerFunctions>(this) setAcquireFunction:(void* (*)(const void*, ::NSUInteger (*)(const void*), BOOL))(value)];
    }

    auto PointerFunctions::description_function() const -> void* (*)(void*)
    {
        return (void* (*)(void*))([cocoon::internal::ns<::NSPointerFunctions>(this) descriptionFunction]);
    }

    void PointerFunctions::set_description_function(void* (*value)(void*)) const
    {
        [cocoon::internal::ns<::NSPointerFunctions>(this) setDescriptionFunction:(::NSString * (*)(const void*))(value)];
    }

    auto PointerFunctions::hash_function() const -> std::uint64_t (*)(void*, std::uint64_t (*)(void*))
    {
        return (std::uint64_t (*)(void*, std::uint64_t (*)(void*)))([cocoon::internal::ns<::NSPointerFunctions>(this) hashFunction]);
    }

    void PointerFunctions::set_hash_function(std::uint64_t (*value)(void*, std::uint64_t (*)(void*))) const
    {
        [cocoon::internal::ns<::NSPointerFunctions>(this) setHashFunction:(::NSUInteger (*)(const void*, ::NSUInteger (*)(const void*)))(value)];
    }

    auto PointerFunctions::is_equal_function() const -> bool (*)(void*, void*, std::uint64_t (*)(void*))
    {
        return (bool (*)(void*, void*, std::uint64_t (*)(void*)))([cocoon::internal::ns<::NSPointerFunctions>(this) isEqualFunction]);
    }

    void PointerFunctions::set_is_equal_function(bool (*value)(void*, void*, std::uint64_t (*)(void*))) const
    {
        [cocoon::internal::ns<::NSPointerFunctions>(this) setIsEqualFunction:(BOOL (*)(const void*, const void*, ::NSUInteger (*)(const void*)))(value)];
    }

    auto PointerFunctions::relinquish_function() const -> void (*)(void*, std::uint64_t (*)(void*))
    {
        return (void (*)(void*, std::uint64_t (*)(void*)))([cocoon::internal::ns<::NSPointerFunctions>(this) relinquishFunction]);
    }

    void PointerFunctions::set_relinquish_function(void (*value)(void*, std::uint64_t (*)(void*))) const
    {
        [cocoon::internal::ns<::NSPointerFunctions>(this) setRelinquishFunction:(void (*)(const void*, ::NSUInteger (*)(const void*)))(value)];
    }

    auto PointerFunctions::size_function() const -> std::uint64_t (*)(void*)
    {
        return (std::uint64_t (*)(void*))([cocoon::internal::ns<::NSPointerFunctions>(this) sizeFunction]);
    }

    void PointerFunctions::set_size_function(std::uint64_t (*value)(void*)) const
    {
        [cocoon::internal::ns<::NSPointerFunctions>(this) setSizeFunction:(::NSUInteger (*)(const void*))(value)];
    }
}
