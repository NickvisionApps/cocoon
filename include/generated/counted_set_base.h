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
     * @details Counted Set
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
         * @param object Argument converted to the Objective-C parameter of the same role.
         */
        void add_object(const Object& object) const;
        /**
         * @brief Calls `-[NSCountedSet countForObject:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t count_for_object(const Object& object) const;
        /**
         * @brief Calls `-[NSCountedSet objectEnumerator]`.
         * @return The converted Objective-C result.
         */
        EnumeratorBase object_enumerator() const;
        /**
         * @brief Calls `-[NSCountedSet removeObject:]`.
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
