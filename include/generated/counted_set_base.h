#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class EnumeratorBase;

    /**
     * @brief C++ handle for the Objective-C class `NSCountedSet` (Foundation).
     * @details A mutable, unordered collection of distinct objects that may appear more than once in the collection. Each distinct object inserted into an 'NSCountedSet' object has a counter associated with it. 'NSCountedSet' keeps track of the number of times objects are inserted and requires that objects be removed the same number of times. Thus, there is only one instance of an object in an 'NSSet' object even if the object has been added to the set multiple times. The 'count' method defined by the superclass 'NSSet' has special significance; it returns the number of distinct objects, not the total number of times objects are represented in the set. The 'NSSet' and 'NSMutableSet' classes are provided for static and dynamic sets, respectively, whose elements are distinct. While 'NSCountedSet' and 'CFBag' are not toll-free bridged, they provide similar functionality. For more information about 'CFBag', see the 'CFBag'. \#\#\# Subclassing Notes Because 'NSCountedSet' is not a class cluster, it does not have primitive methods that provide the basis for its implementation. In general, there should be little need for subclassing. \#\#\#\# Methods to Override If you subclass 'NSCountedSet', you must override any method of which you want to change the behavior. If you change the primitive behavior of an 'NSCountedSet', for instance if you change how objects are stored, you must override all of the affected methods. These include: - 'addObject:' - 'removeObject:' - 'objectEnumerator' - 'countForObject:' If you change the primitive behavior, you must also override the primitive methods of 'NSSet' and 'NSMutableSet'.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Use the typed template @ref CountedSet to supply ObjectType.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CountedSetBase counted_set_base;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CountedSetBase counted_set_base{};
     * counted_set_base.object_enumerator();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nscountedset
     */
    class CountedSetBase : public Object
    {
    public:
        /// @brief Creates a new `NSCountedSet` instance and returns a handle to it.
        explicit CountedSetBase(const std::vector<Object>& array);
        /// @brief Creates a new `NSCountedSet` instance and returns a handle to it.
        explicit CountedSetBase(std::uint64_t num_items);
        /// @brief Creates a new `NSCountedSet` instance and returns a handle to it.
        explicit CountedSetBase();
        /// @brief Creates a null handle that refers to no native object.
        CountedSetBase(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CountedSetBase(Adopt adopt);
        /**
         * @brief Calls `-[NSCountedSet addObject:]`.
         * @details Adds a given object to the set. If 'object' is already a member, 'addObject:' increments the count associated with the object. If 'object' is not already a member, it is sent a 'retain' message. - Parameter object: The object to add to the set.
         * @param object Argument converted to the Objective-C parameter of the same role.
         */
        void add_object(const Object& object) const;
        /**
         * @brief Calls `-[NSCountedSet countForObject:]`.
         * @details Returns the count associated with a given object in the set. - Parameter object: The object for which to return the count. - Returns: The count associated with 'object' in the set, which can be thought of as the number of occurrences of 'object' present in the set.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t count_for_object(const Object& object) const;
        /**
         * @brief Calls `-[NSCountedSet objectEnumerator]`.
         * @details Returns an enumerator object that lets you access each object in the set once, independent of its count. If you add a given object to the counted set multiple times, an enumeration of the set will produce that object only once. You shouldn't modify the set during enumeration. If you intend to modify the set, use the 'allObjects' method to create a "snapshot," then enumerate the snapshot and modify the original set. - Returns: An enumerator object that lets you access each object in the set once, independent of its count.
         * @return The converted Objective-C result.
         */
        EnumeratorBase object_enumerator() const;
        /**
         * @brief Calls `-[NSCountedSet removeObject:]`.
         * @details Removes a given object from the set. If 'object' is present in the set, decrements the count associated with it. If the count is decremented to '0', 'object' is removed from the set. 'removeObject:' does nothing if 'object' is not present in the set. - Parameter object: The object to remove from the set.
         * @param object Argument converted to the Objective-C parameter of the same role.
         */
        void remove_object(const Object& object) const;
    };

    template <class ObjectType>
    class CountedSet : public CountedSetBase
    {
    public:
        using CountedSetBase::CountedSetBase;
        CountedSet() : CountedSetBase()
        {
        }
        CountedSet(const CountedSetBase& other) : CountedSetBase(other)
        {
        }
        using CountedSetBase::add_object;
        using CountedSetBase::count_for_object;
        using CountedSetBase::object_enumerator;
        using CountedSetBase::remove_object;
        auto add_object(const ObjectType& object) const
        {
            CountedSetBase::add_object(cocoon::box(object));
        }
        auto count_for_object(const ObjectType& object) const
        {
            return CountedSetBase::count_for_object(cocoon::box(object));
        }
        auto remove_object(const ObjectType& object) const
        {
            CountedSetBase::remove_object(cocoon::box(object));
        }
    };
}
