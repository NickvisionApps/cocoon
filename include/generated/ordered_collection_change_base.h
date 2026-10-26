#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSOrderedCollectionChange` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Use the typed template @ref OrderedCollectionChange to supply ObjectType.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::OrderedCollectionChangeBase ordered_collection_change_base(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsorderedcollectionchange
     */
    class OrderedCollectionChangeBase : public Object
    {
    public:
        /// @brief Creates a new `NSOrderedCollectionChange` instance and returns a handle to it.
        explicit OrderedCollectionChangeBase(const Object& an_object, CollectionChangeType type, std::uint64_t index);
        /// @brief Creates a new `NSOrderedCollectionChange` instance and returns a handle to it.
        explicit OrderedCollectionChangeBase(const Object& an_object, CollectionChangeType type, std::uint64_t index, std::uint64_t associated_index);
        OrderedCollectionChangeBase();
        /// @brief Creates a null handle that refers to no native object.
        OrderedCollectionChangeBase(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit OrderedCollectionChangeBase(Adopt adopt);
        /**
         * @brief Calls `+[NSOrderedCollectionChange changeWithObject:type:index:]`.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static OrderedCollectionChangeBase change_with_object(const Object& an_object, CollectionChangeType type, std::uint64_t index);
        /**
         * @brief Calls `+[NSOrderedCollectionChange changeWithObject:type:index:associatedIndex:]`.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @param associated_index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static OrderedCollectionChangeBase change_with_object(const Object& an_object, CollectionChangeType type, std::uint64_t index, std::uint64_t associated_index);
        /**
         * @brief Returns the `associatedIndex` property of `NSOrderedCollectionChange`.
         * @return The converted Objective-C result.
         */
        std::uint64_t associated_index() const;
        /**
         * @brief Returns the `changeType` property of `NSOrderedCollectionChange`.
         * @return The converted Objective-C result.
         */
        CollectionChangeType change_type() const;
        /**
         * @brief Returns the `index` property of `NSOrderedCollectionChange`.
         * @return The converted Objective-C result.
         */
        std::uint64_t index() const;
        /**
         * @brief Returns the `object` property of `NSOrderedCollectionChange`.
         * @return The converted Objective-C result.
         */
        Object object() const;
    };

    template <class ObjectType>
    class OrderedCollectionChange : public OrderedCollectionChangeBase
    {
    public:
        using OrderedCollectionChangeBase::OrderedCollectionChangeBase;
        OrderedCollectionChange() : OrderedCollectionChangeBase()
        {
        }
        OrderedCollectionChange(const OrderedCollectionChangeBase& other) : OrderedCollectionChangeBase(other)
        {
        }
        using OrderedCollectionChangeBase::associated_index;
        using OrderedCollectionChangeBase::change_type;
        using OrderedCollectionChangeBase::change_with_object;
        using OrderedCollectionChangeBase::index;
        using OrderedCollectionChangeBase::object;
        static auto change_with_object(const ObjectType& an_object, CollectionChangeType type, std::uint64_t index)
        {
            return OrderedCollectionChangeBase::change_with_object(cocoon::box(an_object), type, index);
        }
        static auto change_with_object(const ObjectType& an_object, CollectionChangeType type, std::uint64_t index, std::uint64_t associated_index)
        {
            return OrderedCollectionChangeBase::change_with_object(cocoon::box(an_object), type, index, associated_index);
        }
        auto object() const
        {
            return cocoon::unbox<ObjectType>(OrderedCollectionChangeBase::object());
        }
    };
}
