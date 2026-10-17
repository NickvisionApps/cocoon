#include "generated/pict_image_rep.h"
#include "internal.h"

namespace cocoon
{
    PICTImageRep::PICTImageRep(const std::vector<std::uint8_t>& pict_data) : PICTImageRep(Adopt{cocoon::internal::retain([[::NSPICTImageRep alloc] initWithData:cocoon::internal::to_data(pict_data)])})
    {
    }

    PICTImageRep::PICTImageRep() : PICTImageRep(Adopt{cocoon::internal::retain([[::NSPICTImageRep alloc] init])})
    {
    }

    PICTImageRep::PICTImageRep(std::nullptr_t) : ImageRep(nullptr)
    {
    }

    PICTImageRep::PICTImageRep(Adopt adopt) : ImageRep(adopt)
    {
    }

    PICTImageRep PICTImageRep::image_rep_with_data(const std::vector<std::uint8_t>& pict_data)
    {
        return cocoon::internal::wrap<PICTImageRep>([::NSPICTImageRep imageRepWithData:cocoon::internal::to_data(pict_data)]);
    }

    std::vector<std::uint8_t> PICTImageRep::pict_representation() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSPICTImageRep>(this) PICTRepresentation]);
    }

    Rect PICTImageRep::bounding_box() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPICTImageRep>(this) boundingBox]);
    }
}
