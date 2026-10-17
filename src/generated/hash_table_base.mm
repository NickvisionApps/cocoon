#include "generated/hash_table_base.h"
#include "internal.h"

namespace cocoon
{
    HashTableBase::HashTableBase(PointerFunctionsOptions options, std::uint64_t initial_capacity) : HashTableBase(Adopt{cocoon::internal::retain([[::NSHashTable alloc] initWithOptions:static_cast<::NSPointerFunctionsOptions>(options) capacity:static_cast<::NSUInteger>(initial_capacity)])})
    {
    }

    HashTableBase::HashTableBase(const PointerFunctions& functions, std::uint64_t initial_capacity) : HashTableBase(Adopt{cocoon::internal::retain([[::NSHashTable alloc] initWithPointerFunctions:cocoon::internal::native<::NSPointerFunctions>(functions) capacity:static_cast<::NSUInteger>(initial_capacity)])})
    {
    }

    HashTableBase::HashTableBase() : HashTableBase(Adopt{cocoon::internal::retain([[::NSHashTable alloc] init])})
    {
    }

    HashTableBase::HashTableBase(std::nullptr_t) : Object(nullptr)
    {
    }

    HashTableBase::HashTableBase(Adopt adopt) : Object(adopt)
    {
    }

    void HashTableBase::add_object(const Object& object) const
    {
        [cocoon::internal::ns<::NSHashTable>(this) addObject:cocoon::internal::native_id(object)];
    }

    bool HashTableBase::contains_object(const Object& an_object) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSHashTable>(this) containsObject:cocoon::internal::native_id(an_object)]);
    }

    HashTableBase HashTableBase::hash_table_with_options(PointerFunctionsOptions options)
    {
        return cocoon::internal::wrap<HashTableBase>([::NSHashTable hashTableWithOptions:static_cast<::NSPointerFunctionsOptions>(options)]);
    }

    void HashTableBase::intersect_hash_table(const HashTableBase& other) const
    {
        [cocoon::internal::ns<::NSHashTable>(this) intersectHashTable:cocoon::internal::native<::NSHashTable>(other)];
    }

    bool HashTableBase::intersects_hash_table(const HashTableBase& other) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSHashTable>(this) intersectsHashTable:cocoon::internal::native<::NSHashTable>(other)]);
    }

    bool HashTableBase::is_equal_to_hash_table(const HashTableBase& other) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSHashTable>(this) isEqualToHashTable:cocoon::internal::native<::NSHashTable>(other)]);
    }

    bool HashTableBase::is_subset_of_hash_table(const HashTableBase& other) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSHashTable>(this) isSubsetOfHashTable:cocoon::internal::native<::NSHashTable>(other)]);
    }

    Object HashTableBase::member(const Object& object) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSHashTable>(this) member:cocoon::internal::native_id(object)]);
    }

    void HashTableBase::minus_hash_table(const HashTableBase& other) const
    {
        [cocoon::internal::ns<::NSHashTable>(this) minusHashTable:cocoon::internal::native<::NSHashTable>(other)];
    }

    EnumeratorBase HashTableBase::object_enumerator() const
    {
        return cocoon::internal::wrap<EnumeratorBase>([cocoon::internal::ns<::NSHashTable>(this) objectEnumerator]);
    }

    void HashTableBase::remove_all_objects() const
    {
        [cocoon::internal::ns<::NSHashTable>(this) removeAllObjects];
    }

    void HashTableBase::remove_object(const Object& object) const
    {
        [cocoon::internal::ns<::NSHashTable>(this) removeObject:cocoon::internal::native_id(object)];
    }

    void HashTableBase::union_hash_table(const HashTableBase& other) const
    {
        [cocoon::internal::ns<::NSHashTable>(this) unionHashTable:cocoon::internal::native<::NSHashTable>(other)];
    }

    HashTableBase HashTableBase::weak_objects_hash_table()
    {
        return cocoon::internal::wrap<HashTableBase>([::NSHashTable weakObjectsHashTable]);
    }

    std::vector<Object> HashTableBase::all_objects() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSHashTable>(this) allObjects], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    Object HashTableBase::any_object() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSHashTable>(this) anyObject]);
    }

    std::uint64_t HashTableBase::count() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSHashTable>(this) count]);
    }

    PointerFunctions HashTableBase::pointer_functions() const
    {
        return cocoon::internal::wrap<PointerFunctions>([cocoon::internal::ns<::NSHashTable>(this) pointerFunctions]);
    }

    std::vector<Object> HashTableBase::set_representation() const
    {
        return cocoon::internal::from_array<Object>([[cocoon::internal::ns<::NSHashTable>(this) setRepresentation] allObjects], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }
}
