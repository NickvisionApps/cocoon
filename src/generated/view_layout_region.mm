#include "generated/view_layout_region.h"
#include "internal.h"

namespace cocoon
{
    ViewLayoutRegion::ViewLayoutRegion() : Object(nullptr)
    {
    }

    ViewLayoutRegion::ViewLayoutRegion(std::nullptr_t) : Object(nullptr)
    {
    }

    ViewLayoutRegion::ViewLayoutRegion(Adopt adopt) : Object(adopt)
    {
    }

    ViewLayoutRegion ViewLayoutRegion::margins_layout_region_with_corner_adaptation(ViewLayoutRegionAdaptivityAxis adaptivity_axis)
    {
        return cocoon::internal::wrap<ViewLayoutRegion>([::NSViewLayoutRegion marginsLayoutRegionWithCornerAdaptation:static_cast<::NSViewLayoutRegionAdaptivityAxis>(adaptivity_axis)]);
    }

    ViewLayoutRegion ViewLayoutRegion::safe_area_layout_region_with_corner_adaptation(ViewLayoutRegionAdaptivityAxis adaptivity_axis)
    {
        return cocoon::internal::wrap<ViewLayoutRegion>([::NSViewLayoutRegion safeAreaLayoutRegionWithCornerAdaptation:static_cast<::NSViewLayoutRegionAdaptivityAxis>(adaptivity_axis)]);
    }
}
