#include "generated/scrubber_layout.h"
#include "internal.h"

namespace cocoon
{
    ScrubberLayout::ScrubberLayout() : ScrubberLayout(Adopt{cocoon::internal::retain([[::NSScrubberLayout alloc] init])})
    {
    }

    ScrubberLayout::ScrubberLayout(std::nullptr_t) : Object(nullptr)
    {
    }

    ScrubberLayout::ScrubberLayout(Adopt adopt) : Object(adopt)
    {
    }

    void ScrubberLayout::invalidate_layout() const
    {
        [cocoon::internal::ns<::NSScrubberLayout>(this) invalidateLayout];
    }

    ScrubberLayoutAttributes ScrubberLayout::layout_attributes_for_item_at_index(std::int64_t index) const
    {
        return cocoon::internal::wrap<ScrubberLayoutAttributes>([cocoon::internal::ns<::NSScrubberLayout>(this) layoutAttributesForItemAtIndex:static_cast<::NSInteger>(index)]);
    }

    std::vector<ScrubberLayoutAttributes> ScrubberLayout::layout_attributes_for_items_in_rect(const Rect& rect) const
    {
        return cocoon::internal::from_array<ScrubberLayoutAttributes>([[cocoon::internal::ns<::NSScrubberLayout>(this) layoutAttributesForItemsInRect:cocoon::internal::to(rect)] allObjects], [](id e) -> ScrubberLayoutAttributes
                                                                      {
                                                                          return cocoon::internal::wrap<ScrubberLayoutAttributes>((::NSScrubberLayoutAttributes*)e);
                                                                      });
    }

    void ScrubberLayout::prepare_layout() const
    {
        [cocoon::internal::ns<::NSScrubberLayout>(this) prepareLayout];
    }

    bool ScrubberLayout::should_invalidate_layout_for_change_from_visible_rect(const Rect& from_visible_rect, const Rect& to_visible_rect) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrubberLayout>(this) shouldInvalidateLayoutForChangeFromVisibleRect:cocoon::internal::to(from_visible_rect) toVisibleRect:cocoon::internal::to(to_visible_rect)]);
    }

    bool ScrubberLayout::automatically_mirrors_in_right_to_left_layout() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrubberLayout>(this) automaticallyMirrorsInRightToLeftLayout]);
    }

    std::string ScrubberLayout::layout_attributes_class()
    {
        return cocoon::internal::from(NSStringFromClass([::NSScrubberLayout layoutAttributesClass]));
    }

    Scrubber ScrubberLayout::scrubber() const
    {
        return cocoon::internal::wrap<Scrubber>([cocoon::internal::ns<::NSScrubberLayout>(this) scrubber]);
    }

    Size ScrubberLayout::scrubber_content_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScrubberLayout>(this) scrubberContentSize]);
    }

    bool ScrubberLayout::should_invalidate_layout_for_highlight_change() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrubberLayout>(this) shouldInvalidateLayoutForHighlightChange]);
    }

    bool ScrubberLayout::should_invalidate_layout_for_selection_change() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrubberLayout>(this) shouldInvalidateLayoutForSelectionChange]);
    }

    Rect ScrubberLayout::visible_rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScrubberLayout>(this) visibleRect]);
    }
}
