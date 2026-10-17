#include "generated/metadata_query_attribute_value_tuple.h"
#include "internal.h"

namespace cocoon
{
    MetadataQueryAttributeValueTuple::MetadataQueryAttributeValueTuple() : MetadataQueryAttributeValueTuple(Adopt{cocoon::internal::retain([[::NSMetadataQueryAttributeValueTuple alloc] init])})
    {
    }

    MetadataQueryAttributeValueTuple::MetadataQueryAttributeValueTuple(std::nullptr_t) : Object(nullptr)
    {
    }

    MetadataQueryAttributeValueTuple::MetadataQueryAttributeValueTuple(Adopt adopt) : Object(adopt)
    {
    }

    std::string MetadataQueryAttributeValueTuple::attribute() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMetadataQueryAttributeValueTuple>(this) attribute]);
    }

    std::uint64_t MetadataQueryAttributeValueTuple::count() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSMetadataQueryAttributeValueTuple>(this) count]);
    }

    Object MetadataQueryAttributeValueTuple::value() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSMetadataQueryAttributeValueTuple>(this) value]);
    }
}
