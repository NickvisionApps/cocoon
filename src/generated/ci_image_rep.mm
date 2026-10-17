#include "generated/ci_image_rep.h"
#include "internal.h"

namespace cocoon
{
    CIImageRep::CIImageRep(const CIImage& image) : CIImageRep(Adopt{cocoon::internal::retain([[::NSCIImageRep alloc] initWithCIImage:cocoon::internal::native<::CIImage>(image)])})
    {
    }

    CIImageRep::CIImageRep() : CIImageRep(Adopt{cocoon::internal::retain([[::NSCIImageRep alloc] init])})
    {
    }

    CIImageRep::CIImageRep(std::nullptr_t) : ImageRep(nullptr)
    {
    }

    CIImageRep::CIImageRep(Adopt adopt) : ImageRep(adopt)
    {
    }

    CIImageRep CIImageRep::image_rep_with_ci_image(const CIImage& image)
    {
        return cocoon::internal::wrap<CIImageRep>([::NSCIImageRep imageRepWithCIImage:cocoon::internal::native<::CIImage>(image)]);
    }

    CIImage CIImageRep::ci_image() const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::NSCIImageRep>(this) CIImage]);
    }
}
