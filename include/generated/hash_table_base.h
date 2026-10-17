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
     * @brief C++ handle for the Objective-C class `NSHashTable` (Foundation).
     * @details A collection similar to a set, but with broader range of available memory semantics. The hash table is modeled after ''NSSet'' with the following differences: - It can hold weak references to its members. - Its members may be copied on input or may use pointer identity for equality and hashing. - It can contain arbitrary pointers (its members are not constrained to being objects). You can configure an ''NSHashTable'' instance to operate on arbitrary pointers and not just objects, although typically you are encouraged to use the C function API for void \\ pointers. The object-based API (such as ''add(:)'') will not work for non-object pointers without type-casting. Because of its options, 'NSHashTable' is not a set because it can behave differently (for example, if pointer equality is specified two 'isEqual:' strings will both be entered). When configuring hash tables, note that only the options listed in ''NSHashTableOptions'' guarantee that the rest of the API will work correctly—including copying, archiving, and fast enumeration. While other ''NSPointerFunctions'' options are used for certain configurations, such as to hold arbitrary pointers, not all combinations of the options are valid. With some combinations the hash table may not work correctly, or may not even be initialized correctly. \#\#\# Subclassing Notes 'NSHashTable' is not suitable for subclassing.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Use the typed template @ref HashTable to supply ObjectType.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::HashTableBase hash_table_base;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::HashTableBase hash_table_base{};
     * auto made_0 = cocoon::HashTableBase::hash_table_with_options(cocoon::PointerFunctionsOptions::StrongMemory);
     * auto made_1 = cocoon::HashTableBase::weak_objects_hash_table();
     * hash_table_base.object_enumerator();
     * hash_table_base.remove_all_objects();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nshashtable
     */
    class HashTableBase : public Object
    {
    public:
        /// @brief Creates a new `NSHashTable` instance and returns a handle to it.
        explicit HashTableBase(PointerFunctionsOptions options, std::uint64_t initial_capacity);
        /// @brief Creates a new `NSHashTable` instance and returns a handle to it.
        explicit HashTableBase(const PointerFunctions& functions, std::uint64_t initial_capacity);
        /// @brief Creates a new `NSHashTable` instance and returns a handle to it.
        explicit HashTableBase();
        /// @brief Creates a null handle that refers to no native object.
        HashTableBase(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit HashTableBase(Adopt adopt);
        /**
     * @brief Calls `-[NSHashTable addObject:]`.
     * @details Adds a given object to the hash table. - Parameter object: The object to add to the hash table.
     * @param object Argument converted to the Objective-C parameter of the same role.
     */
        void add_object(const Object& object) const;
        /**
     * @brief Calls `-[NSHashTable containsObject:]`.
     * @details Returns a Boolean value that indicates whether the hash table contains a given object. - Parameter anObject: The object to test for membership in the hash table. - Returns: 'YES' if the hash table contains 'anObject', otherwise 'NO'.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool contains_object(const Object& an_object) const;
        /**
     * @brief Calls `+[NSHashTable hashTableWithOptions:]`.
     * @details Returns a hash table with given pointer functions options. - Parameter options: A bit field that specifies the options for the elements in the hash table. - Returns: A hash table with given pointer functions options.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static HashTableBase hash_table_with_options(PointerFunctionsOptions options);
        /**
     * @brief Calls `-[NSHashTable intersectHashTable:]`.
     * @details Removes from the receiving hash table each element that isn't a member of another given hash table. - Parameter other: The hash table with which to perform the intersection.
     * @param other Argument converted to the Objective-C parameter of the same role.
     */
        void intersect_hash_table(const HashTableBase& other) const;
        /**
     * @brief Calls `-[NSHashTable intersectsHashTable:]`.
     * @details Returns a Boolean value that indicates whether a given hash table intersects with the receiving hash table. - Parameter other: The hash table with which to compare the receiving hash table. - Returns: 'YES' if 'other' intersects with the receiving hash table, otherwise 'NO'.
     * @param other Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool intersects_hash_table(const HashTableBase& other) const;
        /**
     * @brief Calls `-[NSHashTable isEqualToHashTable:]`.
     * @details Returns a Boolean value that indicates whether a given hash table is equal to the receiving hash table. Two hash tables have equal contents if they each have the same number of members and if each member of one hash table is present in the other. - Parameter other: The hash table with which to compare the receiving hash table. - Returns: 'YES' if the contents of 'other' are equal to the contents of the receiving hash table, otherwise 'NO'.
     * @param other Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_equal_to_hash_table(const HashTableBase& other) const;
        /**
     * @brief Calls `-[NSHashTable isSubsetOfHashTable:]`.
     * @details Returns a Boolean value that indicates whether every element in the receiving hash table is also present in another given hash table. - Parameter other: The hash table with which to compare the receiving hash table. - Returns: 'YES' if every element in the receiving hash table is also present in 'other', otherwise 'NO'.
     * @param other Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_subset_of_hash_table(const HashTableBase& other) const;
        /**
     * @brief Calls `-[NSHashTable member:]`.
     * @details Determines whether the hash table contains a given object, and returns that object if it is present. - Parameter object: The object to test for membership in the hash table. - Returns: If 'object' is a member of the hash table, returns 'object', otherwise returns 'nil'.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object member(const Object& object) const;
        /**
     * @brief Calls `-[NSHashTable minusHashTable:]`.
     * @details Removes each element in another given hash table from the receiving hash table, if present. - Parameter other: The hash table of elements to remove from the receiving hash table.
     * @param other Argument converted to the Objective-C parameter of the same role.
     */
        void minus_hash_table(const HashTableBase& other) const;
        /**
     * @brief Calls `-[NSHashTable objectEnumerator]`.
     * @details Returns an enumerator object that lets you access each object in the hash table. It is more efficient to use the fast enumeration protocol (see 'NSFastEnumeration'). - Returns: An enumerator object that lets you access each object in the hash table.
     * @return The converted Objective-C result.
     */
        EnumeratorBase object_enumerator() const;
        /**
     * @brief Calls `-[NSHashTable removeAllObjects]`.
     * @details Removes all objects from the hash table.
     */
        void remove_all_objects() const;
        /**
     * @brief Calls `-[NSHashTable removeObject:]`.
     * @details Removes a given object from the hash table. - Parameter object: The object to remove from the hash table.
     * @param object Argument converted to the Objective-C parameter of the same role.
     */
        void remove_object(const Object& object) const;
        /**
     * @brief Calls `-[NSHashTable unionHashTable:]`.
     * @details Adds each element in another given hash table to the receiving hash table, if not present. - Parameter other: The hash table of elements to add to the receiving hash table.
     * @param other Argument converted to the Objective-C parameter of the same role.
     */
        void union_hash_table(const HashTableBase& other) const;
        /**
     * @brief Calls `+[NSHashTable weakObjectsHashTable]`.
     * @details Returns a new hash table for storing weak references to its contents.
     * @return The converted Objective-C result.
     */
        static HashTableBase weak_objects_hash_table();
        /**
     * @brief Returns the `allObjects` property of `NSHashTable`.
     * @details The hash table's members.
     * @return The converted Objective-C result.
     */
        std::vector<Object> all_objects() const;
        /**
     * @brief Returns the `anyObject` property of `NSHashTable`.
     * @details One of the objects in the hash table. One of the objects in the hash table, or 'nil' if the hash table contains no objects. The object returned is chosen at the hash table's convenience -- the selection is not guaranteed to be random.
     * @return The converted Objective-C result.
     */
        Object any_object() const;
        /**
     * @brief Returns the `count` property of `NSHashTable`.
     * @details The number of elements in the hash table.
     * @return The converted Objective-C result.
     */
        std::uint64_t count() const;
        /**
     * @brief Returns the `pointerFunctions` property of `NSHashTable`.
     * @details The pointer functions for the hash table.
     * @return The converted Objective-C result.
     */
        PointerFunctions pointer_functions() const;
        /**
     * @brief Returns the `setRepresentation` property of `NSHashTable`.
     * @details A set that contains the hash table's members.
     * @return The converted Objective-C result.
     */
        std::vector<Object> set_representation() const;
    };

    template <class ObjectType>
    class HashTable : public HashTableBase
    {
    public:
        using HashTableBase::HashTableBase;
        HashTable() : HashTableBase()
        {
        }
        HashTable(const HashTableBase& other) : HashTableBase(other)
        {
        }
        using HashTableBase::add_object;
        using HashTableBase::all_objects;
        using HashTableBase::any_object;
        using HashTableBase::contains_object;
        using HashTableBase::count;
        using HashTableBase::hash_table_with_options;
        using HashTableBase::intersect_hash_table;
        using HashTableBase::intersects_hash_table;
        using HashTableBase::is_equal_to_hash_table;
        using HashTableBase::is_subset_of_hash_table;
        using HashTableBase::member;
        using HashTableBase::minus_hash_table;
        using HashTableBase::object_enumerator;
        using HashTableBase::pointer_functions;
        using HashTableBase::remove_all_objects;
        using HashTableBase::remove_object;
        using HashTableBase::set_representation;
        using HashTableBase::union_hash_table;
        using HashTableBase::weak_objects_hash_table;
        auto add_object(const ObjectType& object) const
        {
            HashTableBase::add_object(cocoon::box(object));
        }
        auto contains_object(const ObjectType& an_object) const
        {
            return HashTableBase::contains_object(cocoon::box(an_object));
        }
        auto member(const ObjectType& object) const
        {
            return cocoon::unbox<ObjectType>(HashTableBase::member(cocoon::box(object)));
        }
        auto remove_object(const ObjectType& object) const
        {
            HashTableBase::remove_object(cocoon::box(object));
        }
        auto all_objects() const
        {
            return cocoon::unbox_all<ObjectType>(HashTableBase::all_objects());
        }
        auto any_object() const
        {
            return cocoon::unbox<ObjectType>(HashTableBase::any_object());
        }
    };
}
