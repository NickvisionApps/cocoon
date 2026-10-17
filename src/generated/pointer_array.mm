#include "generated/pointer_array.h"
#include "internal.h"

namespace cocoon
{
    PointerArray::PointerArray(PointerFunctionsOptions options) : PointerArray(Adopt{cocoon::internal::retain([[::NSPointerArray alloc] initWithOptions:static_cast<::NSPointerFunctionsOptions>(options)])})
    {
    }

    PointerArray::PointerArray(const PointerFunctions& functions) : PointerArray(Adopt{cocoon::internal::retain([[::NSPointerArray alloc] initWithPointerFunctions:cocoon::internal::native<::NSPointerFunctions>(functions)])})
    {
    }

    PointerArray::PointerArray() : PointerArray(Adopt{cocoon::internal::retain([[::NSPointerArray alloc] init])})
    {
    }

    PointerArray::PointerArray(std::nullptr_t) : Object(nullptr)
    {
    }

    PointerArray::PointerArray(Adopt adopt) : Object(adopt)
    {
    }

    void PointerArray::add_pointer(void* pointer) const
    {
        [cocoon::internal::ns<::NSPointerArray>(this) addPointer:pointer];
    }

    void PointerArray::compact() const
    {
        [cocoon::internal::ns<::NSPointerArray>(this) compact];
    }

    void PointerArray::insert_pointer(void* item, std::uint64_t index) const
    {
        [cocoon::internal::ns<::NSPointerArray>(this) insertPointer:item atIndex:static_cast<::NSUInteger>(index)];
    }

    PointerArray PointerArray::pointer_array_with_options(PointerFunctionsOptions options)
    {
        return cocoon::internal::wrap<PointerArray>([::NSPointerArray pointerArrayWithOptions:static_cast<::NSPointerFunctionsOptions>(options)]);
    }

    PointerArray PointerArray::pointer_array_with_pointer_functions(const PointerFunctions& functions)
    {
        return cocoon::internal::wrap<PointerArray>([::NSPointerArray pointerArrayWithPointerFunctions:cocoon::internal::native<::NSPointerFunctions>(functions)]);
    }

    void* PointerArray::pointer_at_index(std::uint64_t index) const
    {
        return [cocoon::internal::ns<::NSPointerArray>(this) pointerAtIndex:static_cast<::NSUInteger>(index)];
    }

    void PointerArray::remove_pointer_at_index(std::uint64_t index) const
    {
        [cocoon::internal::ns<::NSPointerArray>(this) removePointerAtIndex:static_cast<::NSUInteger>(index)];
    }

    void PointerArray::replace_pointer_at_index(std::uint64_t index, void* item) const
    {
        [cocoon::internal::ns<::NSPointerArray>(this) replacePointerAtIndex:static_cast<::NSUInteger>(index) withPointer:item];
    }

    PointerArray PointerArray::strong_objects_pointer_array()
    {
        return cocoon::internal::wrap<PointerArray>([::NSPointerArray strongObjectsPointerArray]);
    }

    PointerArray PointerArray::weak_objects_pointer_array()
    {
        return cocoon::internal::wrap<PointerArray>([::NSPointerArray weakObjectsPointerArray]);
    }

    std::vector<Object> PointerArray::all_objects() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSPointerArray>(this) allObjects], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    std::uint64_t PointerArray::count() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSPointerArray>(this) count]);
    }

    void PointerArray::set_count(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSPointerArray>(this) setCount:static_cast<::NSUInteger>(value)];
    }

    PointerFunctions PointerArray::pointer_functions() const
    {
        return cocoon::internal::wrap<PointerFunctions>([cocoon::internal::ns<::NSPointerArray>(this) pointerFunctions]);
    }
}
