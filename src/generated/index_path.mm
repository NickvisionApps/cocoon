#include "generated/index_path.h"
#include "internal.h"

namespace cocoon
{
    IndexPath::IndexPath(std::uint64_t index) : IndexPath(Adopt{cocoon::internal::retain([[::NSIndexPath alloc] initWithIndex:static_cast<::NSUInteger>(index)])})
    {
    }

    IndexPath::IndexPath(const std::uint64_t* indexes, std::uint64_t length) : IndexPath(Adopt{cocoon::internal::retain([[::NSIndexPath alloc] initWithIndexes:(const ::NSUInteger*)(indexes) length:static_cast<::NSUInteger>(length)])})
    {
    }

    IndexPath::IndexPath() : IndexPath(Adopt{cocoon::internal::retain([[::NSIndexPath alloc] init])})
    {
    }

    IndexPath::IndexPath(std::nullptr_t) : Object(nullptr)
    {
    }

    IndexPath::IndexPath(Adopt adopt) : Object(adopt)
    {
    }

    ComparisonResult IndexPath::compare(const IndexPath& other_object) const
    {
        return static_cast<ComparisonResult>([cocoon::internal::ns<::NSIndexPath>(this) compare:cocoon::internal::native<::NSIndexPath>(other_object)]);
    }

    void IndexPath::get_indexes(std::uint64_t* indexes) const
    {
        [cocoon::internal::ns<::NSIndexPath>(this) getIndexes:(::NSUInteger*)(indexes)];
    }

    void IndexPath::get_indexes(std::uint64_t* indexes, const Range& position_range) const
    {
        [cocoon::internal::ns<::NSIndexPath>(this) getIndexes:(::NSUInteger*)(indexes) range:cocoon::internal::to(position_range)];
    }

    std::uint64_t IndexPath::index_at_position(std::uint64_t position) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSIndexPath>(this) indexAtPosition:static_cast<::NSUInteger>(position)]);
    }

    IndexPath IndexPath::index_path_by_adding_index(std::uint64_t index) const
    {
        return cocoon::internal::wrap<IndexPath>([cocoon::internal::ns<::NSIndexPath>(this) indexPathByAddingIndex:static_cast<::NSUInteger>(index)]);
    }

    IndexPath IndexPath::index_path_by_removing_last_index() const
    {
        return cocoon::internal::wrap<IndexPath>([cocoon::internal::ns<::NSIndexPath>(this) indexPathByRemovingLastIndex]);
    }

    IndexPath IndexPath::index_path_for_item(std::int64_t item, std::int64_t section)
    {
        return cocoon::internal::wrap<IndexPath>([::NSIndexPath indexPathForItem:static_cast<::NSInteger>(item) inSection:static_cast<::NSInteger>(section)]);
    }

    std::int64_t IndexPath::item() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSIndexPath>(this) item]);
    }

    std::uint64_t IndexPath::length() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSIndexPath>(this) length]);
    }

    std::int64_t IndexPath::section() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSIndexPath>(this) section]);
    }
}
