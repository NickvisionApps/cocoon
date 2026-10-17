#include "generated/archiver.h"
#include "internal.h"

namespace cocoon
{
    Archiver::Archiver(const std::vector<std::uint8_t>& mdata) : Archiver(Adopt{cocoon::internal::retain([[::NSArchiver alloc] initForWritingWithMutableData:cocoon::internal::to_mutable_data(mdata)])})
    {
    }

    Archiver::Archiver() : Archiver(Adopt{cocoon::internal::retain([[::NSArchiver alloc] init])})
    {
    }

    Archiver::Archiver(std::nullptr_t) : Coder(nullptr)
    {
    }

    Archiver::Archiver(Adopt adopt) : Coder(adopt)
    {
    }

    bool Archiver::archive_root_object(const Object& root_object, const std::string& path)
    {
        return static_cast<bool>([::NSArchiver archiveRootObject:cocoon::internal::native_id(root_object) toFile:cocoon::internal::to(path)]);
    }

    std::vector<std::uint8_t> Archiver::archived_data_with_root_object(const Object& root_object)
    {
        return cocoon::internal::from_data([::NSArchiver archivedDataWithRootObject:cocoon::internal::native_id(root_object)]);
    }

    std::string Archiver::class_name_encoded_for_true_class_name(const std::string& true_name) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSArchiver>(this) classNameEncodedForTrueClassName:cocoon::internal::to(true_name)]);
    }

    void Archiver::encode_class_name(const std::string& true_name, const std::string& in_archive_name) const
    {
        [cocoon::internal::ns<::NSArchiver>(this) encodeClassName:cocoon::internal::to(true_name) intoClassName:cocoon::internal::to(in_archive_name)];
    }

    void Archiver::encode_conditional_object(const Object& object) const
    {
        [cocoon::internal::ns<::NSArchiver>(this) encodeConditionalObject:cocoon::internal::native_id(object)];
    }

    void Archiver::encode_root_object(const Object& root_object) const
    {
        [cocoon::internal::ns<::NSArchiver>(this) encodeRootObject:cocoon::internal::native_id(root_object)];
    }

    void Archiver::replace_object(const Object& object, const Object& new_object) const
    {
        [cocoon::internal::ns<::NSArchiver>(this) replaceObject:cocoon::internal::native_id(object) withObject:cocoon::internal::native_id(new_object)];
    }

    std::vector<std::uint8_t> Archiver::archiver_data() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSArchiver>(this) archiverData]);
    }
}
