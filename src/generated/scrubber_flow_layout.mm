#include "generated/scrubber_flow_layout.h"
#include "internal.h"

namespace cocoon
{
    ScrubberFlowLayout::ScrubberFlowLayout() : ScrubberFlowLayout(Adopt{cocoon::internal::retain([[::NSScrubberFlowLayout alloc] init])})
    {
    }

    ScrubberFlowLayout::ScrubberFlowLayout(std::nullptr_t) : ScrubberLayout(nullptr)
    {
    }

    ScrubberFlowLayout::ScrubberFlowLayout(Adopt adopt) : ScrubberLayout(adopt)
    {
    }

    void ScrubberFlowLayout::invalidate_layout_for_items_at_indexes(const IndexSet& invalid_item_indexes) const
    {
        [cocoon::internal::ns<::NSScrubberFlowLayout>(this) invalidateLayoutForItemsAtIndexes:cocoon::internal::native<::NSIndexSet>(invalid_item_indexes)];
    }

    Size ScrubberFlowLayout::item_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScrubberFlowLayout>(this) itemSize]);
    }

    void ScrubberFlowLayout::set_item_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSScrubberFlowLayout>(this) setItemSize:cocoon::internal::to(value)];
    }

    double ScrubberFlowLayout::item_spacing() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSScrubberFlowLayout>(this) itemSpacing]);
    }

    void ScrubberFlowLayout::set_item_spacing(double value) const
    {
        [cocoon::internal::ns<::NSScrubberFlowLayout>(this) setItemSpacing:static_cast<::CGFloat>(value)];
    }
}
