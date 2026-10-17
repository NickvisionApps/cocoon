#include "generated/string_drawing_context.h"
#include "internal.h"

namespace cocoon
{
    StringDrawingContext::StringDrawingContext() : StringDrawingContext(Adopt{cocoon::internal::retain([[::NSStringDrawingContext alloc] init])})
    {
    }

    StringDrawingContext::StringDrawingContext(std::nullptr_t) : Object(nullptr)
    {
    }

    StringDrawingContext::StringDrawingContext(Adopt adopt) : Object(adopt)
    {
    }

    double StringDrawingContext::actual_scale_factor() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSStringDrawingContext>(this) actualScaleFactor]);
    }

    double StringDrawingContext::minimum_scale_factor() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSStringDrawingContext>(this) minimumScaleFactor]);
    }

    void StringDrawingContext::set_minimum_scale_factor(double value) const
    {
        [cocoon::internal::ns<::NSStringDrawingContext>(this) setMinimumScaleFactor:static_cast<::CGFloat>(value)];
    }

    Rect StringDrawingContext::total_bounds() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSStringDrawingContext>(this) totalBounds]);
    }
}
