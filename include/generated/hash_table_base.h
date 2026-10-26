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
     * @brief C++ handle for the Objective-C class `NSHashTable` (Foundation).
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
         * @param object Argument converted to the Objective-C parameter of the same role.
         */
        void add_object(const Object& object) const;
        /**
         * @brief Calls `-[NSHashTable containsObject:]`.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool contains_object(const Object& an_object) const;
        /**
         * @brief Calls `+[NSHashTable hashTableWithOptions:]`.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static HashTableBase hash_table_with_options(PointerFunctionsOptions options);
        /**
         * @brief Calls `-[NSHashTable intersectHashTable:]`.
         * @param other Argument converted to the Objective-C parameter of the same role.
         */
        void intersect_hash_table(const HashTableBase& other) const;
        /**
         * @brief Calls `-[NSHashTable intersectsHashTable:]`.
         * @param other Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool intersects_hash_table(const HashTableBase& other) const;
        /**
         * @brief Calls `-[NSHashTable isEqualToHashTable:]`.
         * @param other Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_equal_to_hash_table(const HashTableBase& other) const;
        /**
         * @brief Calls `-[NSHashTable isSubsetOfHashTable:]`.
         * @param other Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_subset_of_hash_table(const HashTableBase& other) const;
        /**
         * @brief Calls `-[NSHashTable member:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object member(const Object& object) const;
        /**
         * @brief Calls `-[NSHashTable minusHashTable:]`.
         * @param other Argument converted to the Objective-C parameter of the same role.
         */
        void minus_hash_table(const HashTableBase& other) const;
        /**
         * @brief Calls `-[NSHashTable objectEnumerator]`.
         * @return The converted Objective-C result.
         */
        EnumeratorBase object_enumerator() const;
        /**
         * @brief Calls `-[NSHashTable removeAllObjects]`.
         */
        void remove_all_objects() const;
        /**
         * @brief Calls `-[NSHashTable removeObject:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         */
        void remove_object(const Object& object) const;
        /**
         * @brief Calls `-[NSHashTable unionHashTable:]`.
         * @param other Argument converted to the Objective-C parameter of the same role.
         */
        void union_hash_table(const HashTableBase& other) const;
        /**
         * @brief Calls `+[NSHashTable weakObjectsHashTable]`.
         * @return The converted Objective-C result.
         */
        static HashTableBase weak_objects_hash_table();
        /**
         * @brief Returns the `allObjects` property of `NSHashTable`.
         * @return The converted Objective-C result.
         */
        std::vector<Object> all_objects() const;
        /**
         * @brief Returns the `anyObject` property of `NSHashTable`.
         * @return The converted Objective-C result.
         */
        Object any_object() const;
        /**
         * @brief Returns the `count` property of `NSHashTable`.
         * @return The converted Objective-C result.
         */
        std::uint64_t count() const;
        /**
         * @brief Returns the `pointerFunctions` property of `NSHashTable`.
         * @details return an NSPointerFunctions object reflecting the functions in use. This is a new autoreleased object that can be subsequently modified and/or used directly in the creation of other pointer "collections".
         * @return The converted Objective-C result.
         */
        PointerFunctions pointer_functions() const;
        /**
         * @brief Returns the `setRepresentation` property of `NSHashTable`.
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
