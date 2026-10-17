#include "generated/view_corner_radii.h"
#include "internal.h"

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

    double ViewCornerRadii::bottom_left() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSViewCornerRadii>(this) bottomLeft]);
    }

    double ViewCornerRadii::bottom_right() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSViewCornerRadii>(this) bottomRight]);
    }

    double ViewCornerRadii::top_left() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSViewCornerRadii>(this) topLeft]);
    }

    double ViewCornerRadii::top_right() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSViewCornerRadii>(this) topRight]);
    }
}
