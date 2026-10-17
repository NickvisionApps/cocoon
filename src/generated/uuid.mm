#include "generated/uuid.h"
#include "internal.h"

namespace cocoon
{
    UUID::UUID(const std::uint8_t* bytes) : UUID(Adopt{cocoon::internal::retain([[::NSUUID alloc] initWithUUIDBytes:(const unsigned char*)(bytes)])})
    {
    }

    UUID::UUID(const std::string& string) : UUID(Adopt{cocoon::internal::retain([[::NSUUID alloc] initWithUUIDString:cocoon::internal::to(string)])})
    {
    }

    UUID::UUID() : UUID(Adopt{cocoon::internal::retain([[::NSUUID alloc] init])})
    {
    }

    UUID::UUID(std::nullptr_t) : Object(nullptr)
    {
    }

    UUID::UUID(Adopt adopt) : Object(adopt)
    {
    }

    UUID UUID::uuid()
    {
        return cocoon::internal::wrap<UUID>([::NSUUID UUID]);
    }

    ComparisonResult UUID::compare(const UUID& other_uuid) const
    {
        return static_cast<ComparisonResult>([cocoon::internal::ns<::NSUUID>(this) compare:cocoon::internal::native<::NSUUID>(other_uuid)]);
    }

    void UUID::get_uuid_bytes(std::uint8_t* uuid) const
    {
        [cocoon::internal::ns<::NSUUID>(this) getUUIDBytes:(unsigned char*)(uuid)];
    }

    std::string UUID::uuid_string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUUID>(this) UUIDString]);
    }
}
