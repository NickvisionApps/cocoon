#include "generated/ordered_collection_change_base.h"
#include "internal.h"

namespace cocoon
{
    OrderedCollectionChangeBase::OrderedCollectionChangeBase(const Object& an_object, CollectionChangeType type, std::uint64_t index) : OrderedCollectionChangeBase(Adopt{cocoon::internal::retain([[::NSOrderedCollectionChange alloc] initWithObject:cocoon::internal::native_id(an_object) type:static_cast<::NSCollectionChangeType>(type) index:static_cast<::NSUInteger>(index)])})
    {
    }

    OrderedCollectionChangeBase::OrderedCollectionChangeBase(const Object& an_object, CollectionChangeType type, std::uint64_t index, std::uint64_t associated_index) : OrderedCollectionChangeBase(Adopt{cocoon::internal::retain([[::NSOrderedCollectionChange alloc] initWithObject:cocoon::internal::native_id(an_object) type:static_cast<::NSCollectionChangeType>(type) index:static_cast<::NSUInteger>(index) associatedIndex:static_cast<::NSUInteger>(associated_index)])})
    {
    }

    OrderedCollectionChangeBase::OrderedCollectionChangeBase() : Object(nullptr)
    {
    }

    OrderedCollectionChangeBase::OrderedCollectionChangeBase(std::nullptr_t) : Object(nullptr)
    {
    }

    OrderedCollectionChangeBase::OrderedCollectionChangeBase(Adopt adopt) : Object(adopt)
    {
    }

    OrderedCollectionChangeBase OrderedCollectionChangeBase::change_with_object(const Object& an_object, CollectionChangeType type, std::uint64_t index)
    {
        return cocoon::internal::wrap<OrderedCollectionChangeBase>([::NSOrderedCollectionChange changeWithObject:cocoon::internal::native_id(an_object) type:static_cast<::NSCollectionChangeType>(type) index:static_cast<::NSUInteger>(index)]);
    }

    OrderedCollectionChangeBase OrderedCollectionChangeBase::change_with_object(const Object& an_object, CollectionChangeType type, std::uint64_t index, std::uint64_t associated_index)
    {
        return cocoon::internal::wrap<OrderedCollectionChangeBase>([::NSOrderedCollectionChange changeWithObject:cocoon::internal::native_id(an_object) type:static_cast<::NSCollectionChangeType>(type) index:static_cast<::NSUInteger>(index) associatedIndex:static_cast<::NSUInteger>(associated_index)]);
    }

    std::uint64_t OrderedCollectionChangeBase::associated_index() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSOrderedCollectionChange>(this) associatedIndex]);
    }

    CollectionChangeType OrderedCollectionChangeBase::change_type() const
    {
        return static_cast<CollectionChangeType>([cocoon::internal::ns<::NSOrderedCollectionChange>(this) changeType]);
    }

    std::uint64_t OrderedCollectionChangeBase::index() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSOrderedCollectionChange>(this) index]);
    }

    Object OrderedCollectionChangeBase::object() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSOrderedCollectionChange>(this) object]);
    }
}
