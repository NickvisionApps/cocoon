#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSEnumerator` (Foundation).
     * @details An abstract class whose subclasses enumerate collections of objects, such as arrays and dictionaries.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Use the typed template @ref Enumerator to supply ObjectType.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::EnumeratorBase enumerator_base;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::EnumeratorBase enumerator_base{};
     * enumerator_base.next_object();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsenumerator
     */
    class EnumeratorBase : public Object
    {
    public:
        /// @brief Creates a new `NSEnumerator` instance and returns a handle to it.
        explicit EnumeratorBase();
        /// @brief Creates a null handle that refers to no native object.
        EnumeratorBase(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit EnumeratorBase(Adopt adopt);
        /**
     * @brief Calls `-[NSEnumerator nextObject]`.
     * @details Returns the next object from the collection being enumerated.
     * @return The converted Objective-C result.
     */
        Object next_object() const;
        /**
     * @brief Returns the `allObjects` property of `NSEnumerator`.
     * @details The array of unenumerated objects.
     * @return The converted Objective-C result.
     */
        std::vector<Object> all_objects() const;
    };

    template <class ObjectType>
    class Enumerator : public EnumeratorBase
    {
    public:
        using EnumeratorBase::EnumeratorBase;
        Enumerator() : EnumeratorBase()
        {
        }
        Enumerator(const EnumeratorBase& other) : EnumeratorBase(other)
        {
        }
        using EnumeratorBase::all_objects;
        using EnumeratorBase::next_object;
        auto next_object() const
        {
            return cocoon::unbox<ObjectType>(EnumeratorBase::next_object());
        }
        auto all_objects() const
        {
            return cocoon::unbox_all<ObjectType>(EnumeratorBase::all_objects());
        }
    };
}
