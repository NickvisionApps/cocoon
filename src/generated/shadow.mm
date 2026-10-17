#include "generated/shadow.h"
#include "internal.h"

namespace cocoon
{
    Shadow::Shadow() : Shadow(Adopt{cocoon::internal::retain([[::NSShadow alloc] init])})
    {
    }

    Shadow::Shadow(std::nullptr_t) : Object(nullptr)
    {
    }

    Shadow::Shadow(Adopt adopt) : Object(adopt)
    {
    }

    void Shadow::set() const
    {
        [cocoon::internal::ns<::NSShadow>(this) set];
    }

    double Shadow::shadow_blur_radius() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSShadow>(this) shadowBlurRadius]);
    }

    void Shadow::set_shadow_blur_radius(double value) const
    {
        [cocoon::internal::ns<::NSShadow>(this) setShadowBlurRadius:static_cast<::CGFloat>(value)];
    }

    Color Shadow::shadow_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSShadow>(this) shadowColor]);
    }

    void Shadow::set_shadow_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSShadow>(this) setShadowColor:cocoon::internal::native<::NSColor>(value)];
    }

    Size Shadow::shadow_offset() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSShadow>(this) shadowOffset]);
    }

    void Shadow::set_shadow_offset(const Size& value) const
    {
        [cocoon::internal::ns<::NSShadow>(this) setShadowOffset:cocoon::internal::to(value)];
    }
}
