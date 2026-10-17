#include "generated/view_corner_radii.h"
#include "internal.h"

#ifdef COCOON_MACOS_27
namespace cocoon
{
    ViewCornerRadii::ViewCornerRadii() : Object(nullptr)
    {
    }

    ViewCornerRadii::ViewCornerRadii(std::nullptr_t) : Object(nullptr)
    {
    }

    ViewCornerRadii::ViewCornerRadii(Adopt adopt) : Object(adopt)
    {
    }

#ifdef COCOON_MACOS_27
    double ViewCornerRadii::bottom_left() const
    {
        if (@available(macOS 27.0, *))
        {
            return static_cast<double>([cocoon::internal::ns<::NSViewCornerRadii>(this) bottomLeft]);
        }
        return {};
    }

#endif

#ifdef COCOON_MACOS_27
    double ViewCornerRadii::bottom_right() const
    {
        if (@available(macOS 27.0, *))
        {
            return static_cast<double>([cocoon::internal::ns<::NSViewCornerRadii>(this) bottomRight]);
        }
        return {};
    }

#endif

#ifdef COCOON_MACOS_27
    double ViewCornerRadii::top_left() const
    {
        if (@available(macOS 27.0, *))
        {
            return static_cast<double>([cocoon::internal::ns<::NSViewCornerRadii>(this) topLeft]);
        }
        return {};
    }

#endif

#ifdef COCOON_MACOS_27
    double ViewCornerRadii::top_right() const
    {
        if (@available(macOS 27.0, *))
        {
            return static_cast<double>([cocoon::internal::ns<::NSViewCornerRadii>(this) topRight]);
        }
        return {};
    }

#endif
}

#endif
