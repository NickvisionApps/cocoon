#include "generated/metadata_query_result_group.h"
#include "internal.h"

namespace cocoon
{
    MetadataQueryResultGroup::MetadataQueryResultGroup() : MetadataQueryResultGroup(Adopt{cocoon::internal::retain([[::NSMetadataQueryResultGroup alloc] init])})
    {
    }

    MetadataQueryResultGroup::MetadataQueryResultGroup(std::nullptr_t) : Object(nullptr)
    {
    }

    MetadataQueryResultGroup::MetadataQueryResultGroup(Adopt adopt) : Object(adopt)
    {
    }

    Object MetadataQueryResultGroup::result_at_index(std::uint64_t idx) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSMetadataQueryResultGroup>(this) resultAtIndex:static_cast<::NSUInteger>(idx)]);
    }

    std::string MetadataQueryResultGroup::attribute() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMetadataQueryResultGroup>(this) attribute]);
    }

    std::uint64_t MetadataQueryResultGroup::result_count() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSMetadataQueryResultGroup>(this) resultCount]);
    }

    std::vector<Object> MetadataQueryResultGroup::results() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSMetadataQueryResultGroup>(this) results], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    std::vector<MetadataQueryResultGroup> MetadataQueryResultGroup::subgroups() const
    {
        return cocoon::internal::from_array<MetadataQueryResultGroup>([cocoon::internal::ns<::NSMetadataQueryResultGroup>(this) subgroups], [](id e) -> MetadataQueryResultGroup
                                                        {
                                                            return cocoon::internal::wrap<MetadataQueryResultGroup>((::NSMetadataQueryResultGroup*)e);
                                                        });
    }

    Object MetadataQueryResultGroup::value() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSMetadataQueryResultGroup>(this) value]);
    }
}
