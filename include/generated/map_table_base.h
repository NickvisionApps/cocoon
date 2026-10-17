#pragma once

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
     * @details A collection similar to a dictionary, but with a broader range of available memory semantics. The map table is modeled after ''NSDictionary'' with the following differences: - Keys and/or values are optionally held "weakly" such that entries are removed when one of the objects is reclaimed. - Its keys or values may be copied on input or may use pointer identity for equality and hashing. - It can contain arbitrary pointers (its contents are not constrained to being objects). You can configure an ''NSMapTable'' instance to operate on arbitrary pointers and not just objects, although typically you are encouraged to use the C function API for void \\ pointers. The object-based API (such as ''setObject(:forKey:)'') will not work for non-object pointers without type-casting. When configuring map tables, note that only the options listed in ''NSMapTableOptions'' guarantee that the rest of the API will work correctly—including copying, archiving, and fast enumeration. While other ''NSPointerFunctions'' options are used for certain configurations, such as to hold arbitrary pointers, not all combinations of the options are valid. With some combinations the map table may not work correctly, or may not even be initialized correctly. \#\#\# Subclassing Notes 'NSMapTable' is not suitable for subclassing.
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
     * @details Returns a dictionary representation of the map table. - Returns: A dictionary representation of the map table.
     * @return The converted Objective-C result.
     */
        std::vector<std::pair<Object, Object>> dictionary_representation() const;
        /**
     * @brief Calls `-[NSMapTable keyEnumerator]`.
     * @details Returns an enumerator object that lets you access each key in the map table. It is more efficient to use the fast enumeration protocol (see 'NSFastEnumeration'). - Returns: An enumerator object that lets you access each key in the map table.
     * @return The converted Objective-C result.
     */
        EnumeratorBase key_enumerator() const;
        /**
     * @brief Calls `+[NSMapTable mapTableWithKeyOptions:valueOptions:]`.
     * @details Returns a new map table, initialized with the given options. - Parameter keyOptions: A bit field that specifies the options for the keys in the map table. - Parameter valueOptions: A bit field that specifies the options for the values in the map table. - Returns: A new map table, initialized with the given options.
     * @param key_options Argument converted to the Objective-C parameter of the same role.
     * @param value_options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static MapTableBase map_table_with_key_options(PointerFunctionsOptions key_options, PointerFunctionsOptions value_options);
        /**
     * @brief Calls `-[NSMapTable objectEnumerator]`.
     * @details Returns an enumerator object that lets you access each value in the map table. It is more efficient to use the fast enumeration protocol (see 'NSFastEnumeration'). - Returns: An enumerator object that lets you access each value in the map table.
     * @return The converted Objective-C result.
     */
        EnumeratorBase object_enumerator() const;
        /**
     * @brief Calls `-[NSMapTable objectForKey:]`.
     * @details Returns the value associated with a given key. - Parameter aKey: The key for which to return the corresponding value. - Returns: The value associated with 'aKey', or 'nil' if no value is associated with 'aKey'.
     * @param a_key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object object_for_key(const Object& a_key) const;
        /**
     * @brief Calls `-[NSMapTable removeAllObjects]`.
     * @details Empties the map table of its entries.
     */
        void remove_all_objects() const;
        /**
     * @brief Calls `-[NSMapTable removeObjectForKey:]`.
     * @details Removes a given key and its associated value from the map table. Does nothing if 'aKey' does not exist. - Parameter aKey: The key to remove.
     * @param a_key Argument converted to the Objective-C parameter of the same role.
     */
        void remove_object_for_key(const Object& a_key) const;
        /**
     * @brief Calls `-[NSMapTable setObject:forKey:]`.
     * @details Adds a given key-value pair to the map table. - Parameter anObject: The value for 'aKey'. - Parameter aKey: The key for 'anObject'.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     * @param a_key Argument converted to the Objective-C parameter of the same role.
     */
        void set_object(const Object& an_object, const Object& a_key) const;
        /**
     * @brief Calls `+[NSMapTable strongToStrongObjectsMapTable]`.
     * @details Returns a new map table object which has strong references to the keys and values.
     * @return The converted Objective-C result.
     */
        static MapTableBase strong_to_strong_objects_map_table();
        /**
     * @brief Calls `+[NSMapTable strongToWeakObjectsMapTable]`.
     * @details Returns a new map table object which has strong references to the keys and weak references to the values.
     * @return The converted Objective-C result.
     */
        static MapTableBase strong_to_weak_objects_map_table();
        /**
     * @brief Calls `+[NSMapTable weakToStrongObjectsMapTable]`.
     * @details Returns a new map table object which has weak references to the keys and strong references to the values. Use of weak-to-strong map tables is not recommended. The strong values for weak keys which get zeroed out continue to be maintained until the map table resizes itself.
     * @return The converted Objective-C result.
     */
        static MapTableBase weak_to_strong_objects_map_table();
        /**
     * @brief Calls `+[NSMapTable weakToWeakObjectsMapTable]`.
     * @details Returns a new map table object which has weak references to the keys and values.
     * @return The converted Objective-C result.
     */
        static MapTableBase weak_to_weak_objects_map_table();
        /**
     * @brief Returns the `count` property of `NSMapTable`.
     * @details The number of key-value pairs in the map table.
     * @return The converted Objective-C result.
     */
        std::uint64_t count() const;
        /**
     * @brief Returns the `keyPointerFunctions` property of `NSMapTable`.
     * @details The pointer functions the map table uses to manage keys.
     * @return The converted Objective-C result.
     */
        PointerFunctions key_pointer_functions() const;
        /**
     * @brief Returns the `valuePointerFunctions` property of `NSMapTable`.
     * @details The pointer functions the map table uses to manage values.
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
