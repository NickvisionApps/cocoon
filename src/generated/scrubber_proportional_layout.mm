#include "generated/scrubber_proportional_layout.h"
#include "internal.h"

namespace cocoon
{
    ScrubberProportionalLayout::ScrubberProportionalLayout(std::int64_t number_of_visible_items) : ScrubberProportionalLayout(Adopt{cocoon::internal::retain([[::NSScrubberProportionalLayout alloc] initWithNumberOfVisibleItems:static_cast<::NSInteger>(number_of_visible_items)])})
    {
    }

    ScrubberProportionalLayout::ScrubberProportionalLayout() : ScrubberProportionalLayout(Adopt{cocoon::internal::retain([[::NSScrubberProportionalLayout alloc] init])})
    {
    }

    ScrubberProportionalLayout::ScrubberProportionalLayout(std::nullptr_t) : ScrubberLayout(nullptr)
    {
    }

    ScrubberProportionalLayout::ScrubberProportionalLayout(Adopt adopt) : ScrubberLayout(adopt)
    {
    }

    std::int64_t ScrubberProportionalLayout::number_of_visible_items() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSScrubberProportionalLayout>(this) numberOfVisibleItems]);
    }

    void ScrubberProportionalLayout::set_number_of_visible_items(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSScrubberProportionalLayout>(this) setNumberOfVisibleItems:static_cast<::NSInteger>(value)];
    }
}
