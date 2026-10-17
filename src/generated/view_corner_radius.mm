#include "generated/view_corner_radius.h"
#include "internal.h"

namespace cocoon
{
    ViewCornerRadius::ViewCornerRadius() : Object(nullptr)
    {
    }

    ViewCornerRadius::ViewCornerRadius(std::nullptr_t) : Object(nullptr)
    {
    }

    ViewCornerRadius::ViewCornerRadius(Adopt adopt) : Object(adopt)
    {
    }

    ViewCornerRadius ViewCornerRadius::container_concentric_radius_with_minimum(double minimum_radius)
    {
        return cocoon::internal::wrap<ViewCornerRadius>([::NSViewCornerRadius containerConcentricRadiusWithMinimum:static_cast<::CGFloat>(minimum_radius)]);
    }

    ViewCornerRadius ViewCornerRadius::fixed_radius(double radius)
    {
        return cocoon::internal::wrap<ViewCornerRadius>([::NSViewCornerRadius fixedRadius:static_cast<::CGFloat>(radius)]);
    }

    ViewCornerRadius ViewCornerRadius::container_concentric_radius()
    {
        return cocoon::internal::wrap<ViewCornerRadius>([::NSViewCornerRadius containerConcentricRadius]);
    }
}
