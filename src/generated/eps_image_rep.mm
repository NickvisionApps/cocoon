#include "generated/eps_image_rep.h"
#include "internal.h"

namespace cocoon
{
    EPSImageRep::EPSImageRep(const std::vector<std::uint8_t>& eps_data) : EPSImageRep(Adopt{cocoon::internal::retain([[::NSEPSImageRep alloc] initWithData:cocoon::internal::to_data(eps_data)])})
    {
    }

    EPSImageRep::EPSImageRep() : EPSImageRep(Adopt{cocoon::internal::retain([[::NSEPSImageRep alloc] init])})
    {
    }

    EPSImageRep::EPSImageRep(std::nullptr_t) : ImageRep(nullptr)
    {
    }

    EPSImageRep::EPSImageRep(Adopt adopt) : ImageRep(adopt)
    {
    }

    EPSImageRep EPSImageRep::image_rep_with_data(const std::vector<std::uint8_t>& eps_data)
    {
        return cocoon::internal::wrap<EPSImageRep>([::NSEPSImageRep imageRepWithData:cocoon::internal::to_data(eps_data)]);
    }

    std::vector<std::uint8_t> EPSImageRep::eps_representation() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSEPSImageRep>(this) EPSRepresentation]);
    }

    Rect EPSImageRep::bounding_box() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSEPSImageRep>(this) boundingBox]);
    }
}
