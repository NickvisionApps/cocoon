#include "generated/ordered_collection_difference_base.h"
#include "internal.h"

namespace cocoon
{
    OrderedCollectionDifferenceBase::OrderedCollectionDifferenceBase(const std::vector<OrderedCollectionChangeBase>& changes) : OrderedCollectionDifferenceBase(Adopt{cocoon::internal::retain([[::NSOrderedCollectionDifference alloc] initWithChanges:cocoon::internal::to_array(changes, [](const OrderedCollectionChangeBase& e) -> id
                                                                                                                                                                                                                                                       {
                                                                                                                                                                                                                                                           return cocoon::internal::native<::NSOrderedCollectionChange>(e);
                                                                                                                                                                                                                                                       })])})
    {
    }

    OrderedCollectionDifferenceBase::OrderedCollectionDifferenceBase(const IndexSet& inserts, const std::vector<Object>& inserted_objects, const IndexSet& removes, const std::vector<Object>& removed_objects) : OrderedCollectionDifferenceBase(Adopt{cocoon::internal::retain([[::NSOrderedCollectionDifference alloc] initWithInsertIndexes:cocoon::internal::native<::NSIndexSet>(inserts)
                                                                                                                                                                                                                                                                                                                  insertedObjects:cocoon::internal::to_array(inserted_objects, [](const Object& e) -> id
                                                                                                                                                                                                                                                                                                                                               {
                                                                                                                                                                                                                                                                                                                                                   return cocoon::internal::native_id(e);
                                                                                                                                                                                                                                                                                                                                               })
                                                                                                                                                                                                                                                                                                                    removeIndexes:cocoon::internal::native<::NSIndexSet>(removes)
                                                                                                                                                                                                                                                                                                                   removedObjects:cocoon::internal::to_array(removed_objects, [](const Object& e) -> id
                                                                                                                                                                                                                                                                                                                                               {
                                                                                                                                                                                                                                                                                                                                                   return cocoon::internal::native_id(e);
                                                                                                                                                                                                                                                                                                                                               })])})
    {
    }

    OrderedCollectionDifferenceBase::OrderedCollectionDifferenceBase(const IndexSet& inserts, const std::vector<Object>& inserted_objects, const IndexSet& removes, const std::vector<Object>& removed_objects, const std::vector<OrderedCollectionChangeBase>& changes) : OrderedCollectionDifferenceBase(Adopt{cocoon::internal::retain([[::NSOrderedCollectionDifference alloc] initWithInsertIndexes:cocoon::internal::native<::NSIndexSet>(inserts)
                                                                                                                                                                                                                                                                                                                                                                           insertedObjects:cocoon::internal::to_array(inserted_objects, [](const Object& e) -> id
                                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                                            return cocoon::internal::native_id(e);
                                                                                                                                                                                                                                                                                                                                                                                                        })
                                                                                                                                                                                                                                                                                                                                                                             removeIndexes:cocoon::internal::native<::NSIndexSet>(removes)
                                                                                                                                                                                                                                                                                                                                                                            removedObjects:cocoon::internal::to_array(removed_objects, [](const Object& e) -> id
                                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                                            return cocoon::internal::native_id(e);
                                                                                                                                                                                                                                                                                                                                                                                                        })
                                                                                                                                                                                                                                                                                                                                                                         additionalChanges:cocoon::internal::to_array(changes, [](const OrderedCollectionChangeBase& e) -> id
                                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                                            return cocoon::internal::native<::NSOrderedCollectionChange>(e);
                                                                                                                                                                                                                                                                                                                                                                                                        })])})
    {
    }

    OrderedCollectionDifferenceBase::OrderedCollectionDifferenceBase() : OrderedCollectionDifferenceBase(Adopt{cocoon::internal::retain([[::NSOrderedCollectionDifference alloc] init])})
    {
    }

    OrderedCollectionDifferenceBase::OrderedCollectionDifferenceBase(std::nullptr_t) : Object(nullptr)
    {
    }

    OrderedCollectionDifferenceBase::OrderedCollectionDifferenceBase(Adopt adopt) : Object(adopt)
    {
    }

    OrderedCollectionDifferenceBase OrderedCollectionDifferenceBase::difference_by_transforming_changes_with_block(std::function<OrderedCollectionChangeBase(OrderedCollectionChangeBase)> block) const
    {
        return cocoon::internal::wrap<OrderedCollectionDifferenceBase>([cocoon::internal::ns<::NSOrderedCollectionDifference>(this) differenceByTransformingChangesWithBlock:(block ? (NSOrderedCollectionChange<id> * (^)(NSOrderedCollectionChange<id>*)) ^ ::NSOrderedCollectionChange * (::NSOrderedCollectionChange * a202_0) { auto __r = block(cocoon::internal::wrap<OrderedCollectionChangeBase>(a202_0)); return cocoon::internal::native<::NSOrderedCollectionChange>(__r); } : (NSOrderedCollectionChange<id> * (^)(NSOrderedCollectionChange<id>*)) nil)]);
    }

    OrderedCollectionDifferenceBase OrderedCollectionDifferenceBase::inverse_difference() const
    {
        return cocoon::internal::wrap<OrderedCollectionDifferenceBase>([cocoon::internal::ns<::NSOrderedCollectionDifference>(this) inverseDifference]);
    }

    bool OrderedCollectionDifferenceBase::has_changes() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOrderedCollectionDifference>(this) hasChanges]);
    }

    std::vector<OrderedCollectionChangeBase> OrderedCollectionDifferenceBase::insertions() const
    {
        return cocoon::internal::from_array<OrderedCollectionChangeBase>([cocoon::internal::ns<::NSOrderedCollectionDifference>(this) insertions], [](id e) -> OrderedCollectionChangeBase
                                                           {
                                                               return cocoon::internal::wrap<OrderedCollectionChangeBase>((::NSOrderedCollectionChange*)e);
                                                           });
    }

    std::vector<OrderedCollectionChangeBase> OrderedCollectionDifferenceBase::removals() const
    {
        return cocoon::internal::from_array<OrderedCollectionChangeBase>([cocoon::internal::ns<::NSOrderedCollectionDifference>(this) removals], [](id e) -> OrderedCollectionChangeBase
                                                           {
                                                               return cocoon::internal::wrap<OrderedCollectionChangeBase>((::NSOrderedCollectionChange*)e);
                                                           });
    }
}
