#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class EnumeratorBase;
    class PointerFunctions;

    /**
     * @brief C++ handle for the Objective-C class `NSMapTable` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Use the typed template @ref MapTable to supply KeyType, ObjectType.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MapTableBase map_table_base;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MapTableBase map_table_base{};
     * auto made_0 = cocoon::MapTableBase::map_table_with_key_options(cocoon::PointerFunctionsOptions::StrongMemory, cocoon::PointerFunctionsOptions::StrongMemory);
     * auto made_1 = cocoon::MapTableBase::strong_to_strong_objects_map_table();
     * map_table_base.dictionary_representation();
     * map_table_base.key_enumerator();
     * map_table_base.object_enumerator();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmaptable
     */
    class MapTableBase : public Object
    {
    public:
        /// @brief Creates a new `NSMapTable` instance and returns a handle to it.
        explicit MapTableBase(PointerFunctionsOptions key_options, PointerFunctionsOptions value_options, std::uint64_t initial_capacity);
        /// @brief Creates a new `NSMapTable` instance and returns a handle to it.
        explicit MapTableBase(const PointerFunctions& key_functions, const PointerFunctions& value_functions, std::uint64_t initial_capacity);
        /// @brief Creates a new `NSMapTable` instance and returns a handle to it.
        explicit MapTableBase();
        /// @brief Creates a null handle that refers to no native object.
        MapTableBase(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MapTableBase(Adopt adopt);
        /**
         * @brief Calls `-[NSMapTable dictionaryRepresentation]`.
         * @return The converted Objective-C result.
         */
        std::vector<std::pair<Object, Object>> dictionary_representation() const;
        /**
         * @brief Calls `-[NSMapTable keyEnumerator]`.
         * @return The converted Objective-C result.
         */
        EnumeratorBase key_enumerator() const;
        /**
         * @brief Calls `+[NSMapTable mapTableWithKeyOptions:valueOptions:]`.
         * @param key_options Argument converted to the Objective-C parameter of the same role.
         * @param value_options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static MapTableBase map_table_with_key_options(PointerFunctionsOptions key_options, PointerFunctionsOptions value_options);
        /**
         * @brief Calls `-[NSMapTable objectEnumerator]`.
         * @return The converted Objective-C result.
         */
        EnumeratorBase object_enumerator() const;
        /**
         * @brief Calls `-[NSMapTable objectForKey:]`.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object object_for_key(const Object& a_key) const;
        /**
         * @brief Calls `-[NSMapTable removeAllObjects]`.
         */
        void remove_all_objects() const;
        /**
         * @brief Calls `-[NSMapTable removeObjectForKey:]`.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void remove_object_for_key(const Object& a_key) const;
        /**
         * @brief Calls `-[NSMapTable setObject:forKey:]`.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void set_object(const Object& an_object, const Object& a_key) const;
        /**
         * @brief Calls `+[NSMapTable strongToStrongObjectsMapTable]`.
         * @return The converted Objective-C result.
         */
        static MapTableBase strong_to_strong_objects_map_table();
        /**
         * @brief Calls `+[NSMapTable strongToWeakObjectsMapTable]`.
         * @return The converted Objective-C result.
         */
        static MapTableBase strong_to_weak_objects_map_table();
        /**
         * @brief Calls `+[NSMapTable weakToStrongObjectsMapTable]`.
         * @return The converted Objective-C result.
         */
        static MapTableBase weak_to_strong_objects_map_table();
        /**
         * @brief Calls `+[NSMapTable weakToWeakObjectsMapTable]`.
         * @return The converted Objective-C result.
         */
        static MapTableBase weak_to_weak_objects_map_table();
        /**
         * @brief Returns the `count` property of `NSMapTable`.
         * @return The converted Objective-C result.
         */
        std::uint64_t count() const;
        /**
         * @brief Returns the `keyPointerFunctions` property of `NSMapTable`.
         * @details return an NSPointerFunctions object reflecting the functions in use. This is a new autoreleased object that can be subsequently modified and/or used directly in the creation of other pointer "collections".
         * @return The converted Objective-C result.
         */
        PointerFunctions key_pointer_functions() const;
        /**
         * @brief Returns the `valuePointerFunctions` property of `NSMapTable`.
         * @return The converted Objective-C result.
         */
        PointerFunctions value_pointer_functions() const;
    };

    template <class KeyType, class ObjectType>
    class MapTable : public MapTableBase
    {
    public:
        using MapTableBase::MapTableBase;
        MapTable() : MapTableBase()
        {
        }
        MapTable(const MapTableBase& other) : MapTableBase(other)
        {
        }
        using MapTableBase::count;
        using MapTableBase::dictionary_representation;
        using MapTableBase::key_enumerator;
        using MapTableBase::key_pointer_functions;
        using MapTableBase::map_table_with_key_options;
        using MapTableBase::object_enumerator;
        using MapTableBase::object_for_key;
        using MapTableBase::remove_all_objects;
        using MapTableBase::remove_object_for_key;
        using MapTableBase::set_object;
        using MapTableBase::strong_to_strong_objects_map_table;
        using MapTableBase::strong_to_weak_objects_map_table;
        using MapTableBase::value_pointer_functions;
        using MapTableBase::weak_to_strong_objects_map_table;
        using MapTableBase::weak_to_weak_objects_map_table;
        auto object_for_key(const KeyType& a_key) const
        {
            return cocoon::unbox<ObjectType>(MapTableBase::object_for_key(cocoon::box(a_key)));
        }
        auto remove_object_for_key(const KeyType& a_key) const
        {
            MapTableBase::remove_object_for_key(cocoon::box(a_key));
        }
        auto set_object(const ObjectType& an_object, const KeyType& a_key) const
        {
            MapTableBase::set_object(cocoon::box(an_object), cocoon::box(a_key));
        }
    };
}
