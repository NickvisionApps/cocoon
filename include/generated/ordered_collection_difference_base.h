#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class IndexSet;
    class OrderedCollectionChangeBase;

    /**
     * @brief C++ handle for the Objective-C class `NSOrderedCollectionDifference` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Use the typed template @ref OrderedCollectionDifference to supply ObjectType.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::OrderedCollectionDifferenceBase ordered_collection_difference_base;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::OrderedCollectionDifferenceBase ordered_collection_difference_base{};
     * ordered_collection_difference_base.inverse_difference();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsorderedcollectiondifference
     */
    class OrderedCollectionDifferenceBase : public Object
    {
    public:
        /// @brief Creates a new `NSOrderedCollectionDifference` instance and returns a handle to it.
        explicit OrderedCollectionDifferenceBase(const std::vector<OrderedCollectionChangeBase>& changes);
        /// @brief Creates a new `NSOrderedCollectionDifference` instance and returns a handle to it.
        explicit OrderedCollectionDifferenceBase(const IndexSet& inserts, const std::vector<Object>& inserted_objects, const IndexSet& removes, const std::vector<Object>& removed_objects);
        /// @brief Creates a new `NSOrderedCollectionDifference` instance and returns a handle to it.
        explicit OrderedCollectionDifferenceBase(const IndexSet& inserts, const std::vector<Object>& inserted_objects, const IndexSet& removes, const std::vector<Object>& removed_objects, const std::vector<OrderedCollectionChangeBase>& changes);
        /// @brief Creates a new `NSOrderedCollectionDifference` instance and returns a handle to it.
        explicit OrderedCollectionDifferenceBase();
        /// @brief Creates a null handle that refers to no native object.
        OrderedCollectionDifferenceBase(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit OrderedCollectionDifferenceBase(Adopt adopt);
        /**
         * @brief Calls `-[NSOrderedCollectionDifference differenceByTransformingChangesWithBlock:]`.
         * @param block Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        OrderedCollectionDifferenceBase difference_by_transforming_changes_with_block(std::function<OrderedCollectionChangeBase(OrderedCollectionChangeBase)> block) const;
        /**
         * @brief Calls `-[NSOrderedCollectionDifference inverseDifference]`.
         * @return The converted Objective-C result.
         */
        OrderedCollectionDifferenceBase inverse_difference() const;
        /**
         * @brief Returns the `hasChanges` property of `NSOrderedCollectionDifference`.
         * @return The converted Objective-C result.
         */
        bool has_changes() const;
        /**
         * @brief Returns the `insertions` property of `NSOrderedCollectionDifference`.
         * @return The converted Objective-C result.
         */
        std::vector<OrderedCollectionChangeBase> insertions() const;
        /**
         * @brief Returns the `removals` property of `NSOrderedCollectionDifference`.
         * @return The converted Objective-C result.
         */
        std::vector<OrderedCollectionChangeBase> removals() const;
    };

    template <class ObjectType>
    class OrderedCollectionDifference : public OrderedCollectionDifferenceBase
    {
    public:
        using OrderedCollectionDifferenceBase::OrderedCollectionDifferenceBase;
        OrderedCollectionDifference() : OrderedCollectionDifferenceBase()
        {
        }
        OrderedCollectionDifference(const OrderedCollectionDifferenceBase& other) : OrderedCollectionDifferenceBase(other)
        {
        }
        using OrderedCollectionDifferenceBase::difference_by_transforming_changes_with_block;
        using OrderedCollectionDifferenceBase::has_changes;
        using OrderedCollectionDifferenceBase::insertions;
        using OrderedCollectionDifferenceBase::inverse_difference;
        using OrderedCollectionDifferenceBase::removals;
    };
}
