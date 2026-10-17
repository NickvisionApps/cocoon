#include "generated/scrubber_selection_view.h"
#include "internal.h"

namespace cocoon
{
    ScrubberSelectionView::ScrubberSelectionView() : ScrubberSelectionView(Adopt{cocoon::internal::retain([[::NSScrubberSelectionView alloc] init])})
    {
    }

    ScrubberSelectionView::ScrubberSelectionView(std::nullptr_t) : ScrubberArrangedView(nullptr)
    {
    }

    ScrubberSelectionView::ScrubberSelectionView(Adopt adopt) : ScrubberArrangedView(adopt)
    {
    }
}
