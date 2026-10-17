#include "generated/scrubber_item_view.h"
#include "internal.h"

namespace cocoon
{
    ScrubberItemView::ScrubberItemView() : ScrubberItemView(Adopt{cocoon::internal::retain([[::NSScrubberItemView alloc] init])})
    {
    }

    ScrubberItemView::ScrubberItemView(std::nullptr_t) : ScrubberArrangedView(nullptr)
    {
    }

    ScrubberItemView::ScrubberItemView(Adopt adopt) : ScrubberArrangedView(adopt)
    {
    }
}
