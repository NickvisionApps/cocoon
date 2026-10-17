#include "generated/view_corner_radius.h"
#include "internal.h"

#ifdef COCOON_MACOS_27
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

#ifdef COCOON_MACOS_27
    ViewCornerRadius ViewCornerRadius::container_concentric_radius_with_minimum(double minimum_radius)
    {
        if (@available(macOS 27.0, *))
        {
            return cocoon::internal::wrap<ViewCornerRadius>([::NSViewCornerRadius containerConcentricRadiusWithMinimum:static_cast<::CGFloat>(minimum_radius)]);
        }
        return ViewCornerRadius(nullptr);
    }

#endif

#ifdef COCOON_MACOS_27
    ViewCornerRadius ViewCornerRadius::fixed_radius(double radius)
    {
        if (@available(macOS 27.0, *))
        {
            return cocoon::internal::wrap<ViewCornerRadius>([::NSViewCornerRadius fixedRadius:static_cast<::CGFloat>(radius)]);
        }
        return ViewCornerRadius(nullptr);
    }

#endif

#ifdef COCOON_MACOS_27
    ViewCornerRadius ViewCornerRadius::container_concentric_radius()
    {
        if (@available(macOS 27.0, *))
        {
            return cocoon::internal::wrap<ViewCornerRadius>([::NSViewCornerRadius containerConcentricRadius]);
        }
        return ViewCornerRadius(nullptr);
    }

#endif
}

#endif
