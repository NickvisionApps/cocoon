#include "generated/scrubber_selection_style.h"
#include "internal.h"

namespace cocoon
{
    ScrubberSelectionStyle::ScrubberSelectionStyle() : ScrubberSelectionStyle(Adopt{cocoon::internal::retain([[::NSScrubberSelectionStyle alloc] init])})
    {
    }

    ScrubberSelectionStyle::ScrubberSelectionStyle(std::nullptr_t) : Object(nullptr)
    {
    }

    ScrubberSelectionStyle::ScrubberSelectionStyle(Adopt adopt) : Object(adopt)
    {
    }

    ScrubberSelectionView ScrubberSelectionStyle::make_selection_view() const
    {
        return cocoon::internal::wrap<ScrubberSelectionView>([cocoon::internal::ns<::NSScrubberSelectionStyle>(this) makeSelectionView]);
    }

    ScrubberSelectionStyle ScrubberSelectionStyle::outline_overlay_style()
    {
        return cocoon::internal::wrap<ScrubberSelectionStyle>([::NSScrubberSelectionStyle outlineOverlayStyle]);
    }

    ScrubberSelectionStyle ScrubberSelectionStyle::rounded_background_style()
    {
        return cocoon::internal::wrap<ScrubberSelectionStyle>([::NSScrubberSelectionStyle roundedBackgroundStyle]);
    }
}
