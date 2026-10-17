#include "generated/scrubber_image_item_view.h"
#include "internal.h"

namespace cocoon
{
    ScrubberImageItemView::ScrubberImageItemView() : ScrubberImageItemView(Adopt{cocoon::internal::retain([[::NSScrubberImageItemView alloc] init])})
    {
    }

    ScrubberImageItemView::ScrubberImageItemView(std::nullptr_t) : ScrubberItemView(nullptr)
    {
    }

    ScrubberImageItemView::ScrubberImageItemView(Adopt adopt) : ScrubberItemView(adopt)
    {
    }

    Image ScrubberImageItemView::image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSScrubberImageItemView>(this) image]);
    }

    void ScrubberImageItemView::set_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSScrubberImageItemView>(this) setImage:cocoon::internal::native<::NSImage>(value)];
    }

    ImageAlignment ScrubberImageItemView::image_alignment() const
    {
        return static_cast<ImageAlignment>([cocoon::internal::ns<::NSScrubberImageItemView>(this) imageAlignment]);
    }

    void ScrubberImageItemView::set_image_alignment(ImageAlignment value) const
    {
        [cocoon::internal::ns<::NSScrubberImageItemView>(this) setImageAlignment:static_cast<::NSImageAlignment>(value)];
    }

    ImageView ScrubberImageItemView::image_view() const
    {
        return cocoon::internal::wrap<ImageView>([cocoon::internal::ns<::NSScrubberImageItemView>(this) imageView]);
    }
}
