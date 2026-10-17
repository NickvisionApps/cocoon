#include "generated/touch.h"
#include "internal.h"

namespace cocoon
{
    Touch::Touch() : Touch(Adopt{cocoon::internal::retain([[::NSTouch alloc] init])})
    {
    }

    Touch::Touch(std::nullptr_t) : Object(nullptr)
    {
    }

    Touch::Touch(Adopt adopt) : Object(adopt)
    {
    }

    Point Touch::location_in_view(const View& view) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTouch>(this) locationInView:cocoon::internal::native<::NSView>(view)]);
    }

    Point Touch::previous_location_in_view(const View& view) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTouch>(this) previousLocationInView:cocoon::internal::native<::NSView>(view)]);
    }

    Object Touch::device() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTouch>(this) device]);
    }

    Size Touch::device_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTouch>(this) deviceSize]);
    }

    Point Touch::normalized_position() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTouch>(this) normalizedPosition]);
    }

    TouchPhase Touch::phase() const
    {
        return static_cast<TouchPhase>([cocoon::internal::ns<::NSTouch>(this) phase]);
    }

    bool Touch::is_resting() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTouch>(this) isResting]);
    }

    TouchType Touch::type() const
    {
        return static_cast<TouchType>([cocoon::internal::ns<::NSTouch>(this) type]);
    }
}
