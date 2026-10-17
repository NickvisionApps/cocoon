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
     * @details An object that represents an indexed change within an ordered collection. An ordered collection change represents changes by adding, removing, or moving objects within an ordered collection. Changes with an associated index indicate a move within the collection.
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
     * @details Creates a change object that represents inserting or removing an object from an ordered collection at a specific index. - Parameter anObject: An object to be removed or inserted by the change. - Parameter type: The type of change. - Parameter index: The index location within an ordered collection where the change applies.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     * @param type Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static OrderedCollectionChangeBase change_with_object(const Object& an_object, CollectionChangeType type, std::uint64_t index);
        /**
     * @brief Calls `+[NSOrderedCollectionChange changeWithObject:type:index:associatedIndex:]`.
     * @details Creates a change object that represents inserting or removing an object from an ordered collection at a specific index, matched with an associated location that infers a move within the collection. - Parameter anObject: An object to be removed or inserted by the change. - Parameter type: The type of change. - Parameter index: The index location within an ordered collection where the change applies. - Parameter associatedIndex: The index of the change's counterpart of the opposite type in the diff.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     * @param type Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @param associated_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static OrderedCollectionChangeBase change_with_object(const Object& an_object, CollectionChangeType type, std::uint64_t index, std::uint64_t associated_index);
        /**
     * @brief Returns the `associatedIndex` property of `NSOrderedCollectionChange`.
     * @details When this property is set to a value other than 'NSNotFound', the receiver is one half of a move, and this value is the index of the change's counterpart of the opposite type in the diff. Pairs of changes with opposite types that refer to each other represent the index location of their counterpart with the 'associatedIndex' property. A move pair can have a different 'object' in its removal and insertion changes, which can imply that the change represents moving and changing or replacing an element. > Note: > Don't ignore a move when the indexes of its changes are the same. The calculated difference may legitimately produce a diff where a change removes the object at one index and the object at another index moves to the same index. Ignoring the move produces an incorrect result.
     * @return The converted Objective-C result.
     */
        std::uint64_t associated_index() const;
        /**
     * @brief Returns the `changeType` property of `NSOrderedCollectionChange`.
     * @details The type of change.
     * @return The converted Objective-C result.
     */
        CollectionChangeType change_type() const;
        /**
     * @brief Returns the `index` property of `NSOrderedCollectionChange`.
     * @details The index location of the change. For removals, the index of the object in the original state. For insertions, the index of the object in the final state.
     * @return The converted Objective-C result.
     */
        std::uint64_t index() const;
        /**
     * @brief Returns the `object` property of `NSOrderedCollectionChange`.
     * @details An object the change inserts or removes.
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
