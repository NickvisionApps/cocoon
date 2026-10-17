#include "generated/image_cell.h"
#include "internal.h"

namespace cocoon
{
    ImageCell::ImageCell() : ImageCell(Adopt{cocoon::internal::retain([[::NSImageCell alloc] init])})
    {
    }

    ImageCell::ImageCell(std::nullptr_t) : Cell(nullptr)
    {
    }

    ImageCell::ImageCell(Adopt adopt) : Cell(adopt)
    {
    }

    ImageAlignment ImageCell::image_alignment() const
    {
        return static_cast<ImageAlignment>([cocoon::internal::ns<::NSImageCell>(this) imageAlignment]);
    }

    void ImageCell::set_image_alignment(ImageAlignment value) const
    {
        [cocoon::internal::ns<::NSImageCell>(this) setImageAlignment:static_cast<::NSImageAlignment>(value)];
    }

    ImageFrameStyle ImageCell::image_frame_style() const
    {
        return static_cast<ImageFrameStyle>([cocoon::internal::ns<::NSImageCell>(this) imageFrameStyle]);
    }

    void ImageCell::set_image_frame_style(ImageFrameStyle value) const
    {
        [cocoon::internal::ns<::NSImageCell>(this) setImageFrameStyle:static_cast<::NSImageFrameStyle>(value)];
    }

    ImageScaling ImageCell::image_scaling() const
    {
        return static_cast<ImageScaling>([cocoon::internal::ns<::NSImageCell>(this) imageScaling]);
    }

    void ImageCell::set_image_scaling(ImageScaling value) const
    {
        [cocoon::internal::ns<::NSImageCell>(this) setImageScaling:static_cast<::NSImageScaling>(value)];
    }
}
