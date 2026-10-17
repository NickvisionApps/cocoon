#include "generated/mutable_index_set.h"
#include "internal.h"

namespace cocoon
{
    MutableIndexSet::MutableIndexSet() : MutableIndexSet(Adopt{cocoon::internal::retain([[::NSMutableIndexSet alloc] init])})
    {
    }

    MutableIndexSet::MutableIndexSet(std::nullptr_t) : IndexSet(nullptr)
    {
    }

    MutableIndexSet::MutableIndexSet(Adopt adopt) : IndexSet(adopt)
    {
    }

    void MutableIndexSet::add_index(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSMutableIndexSet>(this) addIndex:static_cast<::NSUInteger>(value)];
    }

    void MutableIndexSet::add_indexes(const IndexSet& index_set) const
    {
        [cocoon::internal::ns<::NSMutableIndexSet>(this) addIndexes:cocoon::internal::native<::NSIndexSet>(index_set)];
    }

    void MutableIndexSet::add_indexes_in_range(const Range& range) const
    {
        [cocoon::internal::ns<::NSMutableIndexSet>(this) addIndexesInRange:cocoon::internal::to(range)];
    }

    void MutableIndexSet::remove_all_indexes() const
    {
        [cocoon::internal::ns<::NSMutableIndexSet>(this) removeAllIndexes];
    }

    void MutableIndexSet::remove_index(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSMutableIndexSet>(this) removeIndex:static_cast<::NSUInteger>(value)];
    }

    void MutableIndexSet::remove_indexes(const IndexSet& index_set) const
    {
        [cocoon::internal::ns<::NSMutableIndexSet>(this) removeIndexes:cocoon::internal::native<::NSIndexSet>(index_set)];
    }

    void MutableIndexSet::remove_indexes_in_range(const Range& range) const
    {
        [cocoon::internal::ns<::NSMutableIndexSet>(this) removeIndexesInRange:cocoon::internal::to(range)];
    }

    void MutableIndexSet::shift_indexes_starting_at_index(std::uint64_t index, std::int64_t delta) const
    {
        [cocoon::internal::ns<::NSMutableIndexSet>(this) shiftIndexesStartingAtIndex:static_cast<::NSUInteger>(index) by:static_cast<::NSInteger>(delta)];
    }
}
