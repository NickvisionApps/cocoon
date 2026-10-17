#include "generated/map_table_base.h"
#include "internal.h"

namespace cocoon
{
    MapTableBase::MapTableBase(PointerFunctionsOptions key_options, PointerFunctionsOptions value_options, std::uint64_t initial_capacity) : MapTableBase(Adopt{cocoon::internal::retain([[::NSMapTable alloc] initWithKeyOptions:static_cast<::NSPointerFunctionsOptions>(key_options) valueOptions:static_cast<::NSPointerFunctionsOptions>(value_options) capacity:static_cast<::NSUInteger>(initial_capacity)])})
    {
    }

    MapTableBase::MapTableBase(const PointerFunctions& key_functions, const PointerFunctions& value_functions, std::uint64_t initial_capacity) : MapTableBase(Adopt{cocoon::internal::retain([[::NSMapTable alloc] initWithKeyPointerFunctions:cocoon::internal::native<::NSPointerFunctions>(key_functions) valuePointerFunctions:cocoon::internal::native<::NSPointerFunctions>(value_functions) capacity:static_cast<::NSUInteger>(initial_capacity)])})
    {
    }

    MapTableBase::MapTableBase() : MapTableBase(Adopt{cocoon::internal::retain([[::NSMapTable alloc] init])})
    {
    }

    MapTableBase::MapTableBase(std::nullptr_t) : Object(nullptr)
    {
    }

    MapTableBase::MapTableBase(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<std::pair<Object, Object>> MapTableBase::dictionary_representation() const
    {
        return cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>([cocoon::internal::ns<::NSMapTable>(this) dictionaryRepresentation], [](id k) -> Object
                                                                           {
                                                                               return cocoon::internal::wrap<Object>(k);
                                                                           },
                                                                           [](id v) -> Object
                                                                           {
                                                                               return cocoon::internal::wrap<Object>(v);
                                                                           });
    }

    EnumeratorBase MapTableBase::key_enumerator() const
    {
        return cocoon::internal::wrap<EnumeratorBase>([cocoon::internal::ns<::NSMapTable>(this) keyEnumerator]);
    }

    MapTableBase MapTableBase::map_table_with_key_options(PointerFunctionsOptions key_options, PointerFunctionsOptions value_options)
    {
        return cocoon::internal::wrap<MapTableBase>([::NSMapTable mapTableWithKeyOptions:static_cast<::NSPointerFunctionsOptions>(key_options) valueOptions:static_cast<::NSPointerFunctionsOptions>(value_options)]);
    }

    EnumeratorBase MapTableBase::object_enumerator() const
    {
        return cocoon::internal::wrap<EnumeratorBase>([cocoon::internal::ns<::NSMapTable>(this) objectEnumerator]);
    }

    Object MapTableBase::object_for_key(const Object& a_key) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSMapTable>(this) objectForKey:cocoon::internal::native_id(a_key)]);
    }

    void MapTableBase::remove_all_objects() const
    {
        [cocoon::internal::ns<::NSMapTable>(this) removeAllObjects];
    }

    void MapTableBase::remove_object_for_key(const Object& a_key) const
    {
        [cocoon::internal::ns<::NSMapTable>(this) removeObjectForKey:cocoon::internal::native_id(a_key)];
    }

    void MapTableBase::set_object(const Object& an_object, const Object& a_key) const
    {
        [cocoon::internal::ns<::NSMapTable>(this) setObject:cocoon::internal::native_id(an_object) forKey:cocoon::internal::native_id(a_key)];
    }

    MapTableBase MapTableBase::strong_to_strong_objects_map_table()
    {
        return cocoon::internal::wrap<MapTableBase>([::NSMapTable strongToStrongObjectsMapTable]);
    }

    MapTableBase MapTableBase::strong_to_weak_objects_map_table()
    {
        return cocoon::internal::wrap<MapTableBase>([::NSMapTable strongToWeakObjectsMapTable]);
    }

    MapTableBase MapTableBase::weak_to_strong_objects_map_table()
    {
        return cocoon::internal::wrap<MapTableBase>([::NSMapTable weakToStrongObjectsMapTable]);
    }

    MapTableBase MapTableBase::weak_to_weak_objects_map_table()
    {
        return cocoon::internal::wrap<MapTableBase>([::NSMapTable weakToWeakObjectsMapTable]);
    }

    std::uint64_t MapTableBase::count() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSMapTable>(this) count]);
    }

    PointerFunctions MapTableBase::key_pointer_functions() const
    {
        return cocoon::internal::wrap<PointerFunctions>([cocoon::internal::ns<::NSMapTable>(this) keyPointerFunctions]);
    }

    PointerFunctions MapTableBase::value_pointer_functions() const
    {
        return cocoon::internal::wrap<PointerFunctions>([cocoon::internal::ns<::NSMapTable>(this) valuePointerFunctions]);
    }
}
