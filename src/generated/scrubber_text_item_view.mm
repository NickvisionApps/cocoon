#include "generated/scrubber_text_item_view.h"
#include "internal.h"

namespace cocoon
{
    ScrubberTextItemView::ScrubberTextItemView() : ScrubberTextItemView(Adopt{cocoon::internal::retain([[::NSScrubberTextItemView alloc] init])})
    {
    }

    ScrubberTextItemView::ScrubberTextItemView(std::nullptr_t) : ScrubberItemView(nullptr)
    {
    }

    ScrubberTextItemView::ScrubberTextItemView(Adopt adopt) : ScrubberItemView(adopt)
    {
    }

    TextField ScrubberTextItemView::text_field() const
    {
        return cocoon::internal::wrap<TextField>([cocoon::internal::ns<::NSScrubberTextItemView>(this) textField]);
    }

    std::string ScrubberTextItemView::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScrubberTextItemView>(this) title]);
    }

    void ScrubberTextItemView::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSScrubberTextItemView>(this) setTitle:cocoon::internal::to(value)];
    }
}
