#include "generated/unarchiver.h"
#include "internal.h"

namespace cocoon
{
    Unarchiver::Unarchiver(const std::vector<std::uint8_t>& data) : Unarchiver(Adopt{cocoon::internal::retain([[::NSUnarchiver alloc] initForReadingWithData:cocoon::internal::to_data(data)])})
    {
    }

    Unarchiver::Unarchiver() : Unarchiver(Adopt{cocoon::internal::retain([[::NSUnarchiver alloc] init])})
    {
    }

    Unarchiver::Unarchiver(std::nullptr_t) : Coder(nullptr)
    {
    }

    Unarchiver::Unarchiver(Adopt adopt) : Coder(adopt)
    {
    }

    std::string Unarchiver::class_name_decoded_for_archive_class_name(const std::string& in_archive_name) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUnarchiver>(this) classNameDecodedForArchiveClassName:cocoon::internal::to(in_archive_name)]);
    }

    void Unarchiver::decode_class_name(const std::string& in_archive_name, const std::string& true_name) const
    {
        [cocoon::internal::ns<::NSUnarchiver>(this) decodeClassName:cocoon::internal::to(in_archive_name) asClassName:cocoon::internal::to(true_name)];
    }

    void Unarchiver::replace_object(const Object& object, const Object& new_object) const
    {
        [cocoon::internal::ns<::NSUnarchiver>(this) replaceObject:cocoon::internal::native_id(object) withObject:cocoon::internal::native_id(new_object)];
    }

    Object Unarchiver::unarchive_object_with_data(const std::vector<std::uint8_t>& data)
    {
        return cocoon::internal::wrap<Object>([::NSUnarchiver unarchiveObjectWithData:cocoon::internal::to_data(data)]);
    }

    Object Unarchiver::unarchive_object_with_file(const std::string& path)
    {
        return cocoon::internal::wrap<Object>([::NSUnarchiver unarchiveObjectWithFile:cocoon::internal::to(path)]);
    }

    bool Unarchiver::is_at_end() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUnarchiver>(this) isAtEnd]);
    }

    unsigned int Unarchiver::system_version() const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSUnarchiver>(this) systemVersion]);
    }
}
