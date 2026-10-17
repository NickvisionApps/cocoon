#include "generated/scrubber_arranged_view.h"
#include "internal.h"

namespace cocoon
{
    ScrubberArrangedView::ScrubberArrangedView() : ScrubberArrangedView(Adopt{cocoon::internal::retain([[::NSScrubberArrangedView alloc] init])})
    {
    }

    ScrubberArrangedView::ScrubberArrangedView(std::nullptr_t) : View(nullptr)
    {
    }

    ScrubberArrangedView::ScrubberArrangedView(Adopt adopt) : View(adopt)
    {
    }

    void ScrubberArrangedView::apply_layout_attributes(const ScrubberLayoutAttributes& layout_attributes) const
    {
        [cocoon::internal::ns<::NSScrubberArrangedView>(this) applyLayoutAttributes:cocoon::internal::native<::NSScrubberLayoutAttributes>(layout_attributes)];
    }

    bool ScrubberArrangedView::is_highlighted() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrubberArrangedView>(this) isHighlighted]);
    }

    void ScrubberArrangedView::set_highlighted(bool value) const
    {
        [cocoon::internal::ns<::NSScrubberArrangedView>(this) setHighlighted:static_cast<::BOOL>(value)];
    }

    bool ScrubberArrangedView::is_selected() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrubberArrangedView>(this) isSelected]);
    }

    void ScrubberArrangedView::set_selected(bool value) const
    {
        [cocoon::internal::ns<::NSScrubberArrangedView>(this) setSelected:static_cast<::BOOL>(value)];
    }
}
