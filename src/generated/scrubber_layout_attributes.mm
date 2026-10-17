#include "generated/scrubber_layout_attributes.h"
#include "internal.h"

namespace cocoon
{
    ScrubberLayoutAttributes::ScrubberLayoutAttributes() : ScrubberLayoutAttributes(Adopt{cocoon::internal::retain([[::NSScrubberLayoutAttributes alloc] init])})
    {
    }

    ScrubberLayoutAttributes::ScrubberLayoutAttributes(std::nullptr_t) : Object(nullptr)
    {
    }

    ScrubberLayoutAttributes::ScrubberLayoutAttributes(Adopt adopt) : Object(adopt)
    {
    }

    ScrubberLayoutAttributes ScrubberLayoutAttributes::layout_attributes_for_item_at_index(std::int64_t index)
    {
        return cocoon::internal::wrap<ScrubberLayoutAttributes>([::NSScrubberLayoutAttributes layoutAttributesForItemAtIndex:static_cast<::NSInteger>(index)]);
    }

    double ScrubberLayoutAttributes::alpha() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSScrubberLayoutAttributes>(this) alpha]);
    }

    void ScrubberLayoutAttributes::set_alpha(double value) const
    {
        [cocoon::internal::ns<::NSScrubberLayoutAttributes>(this) setAlpha:static_cast<::CGFloat>(value)];
    }

    Rect ScrubberLayoutAttributes::frame() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScrubberLayoutAttributes>(this) frame]);
    }

    void ScrubberLayoutAttributes::set_frame(const Rect& value) const
    {
        [cocoon::internal::ns<::NSScrubberLayoutAttributes>(this) setFrame:cocoon::internal::to(value)];
    }

    std::int64_t ScrubberLayoutAttributes::item_index() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSScrubberLayoutAttributes>(this) itemIndex]);
    }

    void ScrubberLayoutAttributes::set_item_index(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSScrubberLayoutAttributes>(this) setItemIndex:static_cast<::NSInteger>(value)];
    }
}
