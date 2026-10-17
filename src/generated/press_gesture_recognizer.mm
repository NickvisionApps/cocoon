#include "generated/press_gesture_recognizer.h"
#include "internal.h"

namespace cocoon
{
    PressGestureRecognizer::PressGestureRecognizer() : PressGestureRecognizer(Adopt{cocoon::internal::retain([[::NSPressGestureRecognizer alloc] init])})
    {
        GestureRecognizer::install_delegate_delegate_(handle());
    }

    PressGestureRecognizer::PressGestureRecognizer(std::nullptr_t) : GestureRecognizer(nullptr)
    {
    }

    PressGestureRecognizer::PressGestureRecognizer(Adopt adopt) : GestureRecognizer(adopt)
    {
    }

    double PressGestureRecognizer::allowable_movement() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSPressGestureRecognizer>(this) allowableMovement]);
    }

    void PressGestureRecognizer::set_allowable_movement(double value) const
    {
        [cocoon::internal::ns<::NSPressGestureRecognizer>(this) setAllowableMovement:static_cast<::CGFloat>(value)];
    }

    std::uint64_t PressGestureRecognizer::button_mask() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSPressGestureRecognizer>(this) buttonMask]);
    }

    void PressGestureRecognizer::set_button_mask(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSPressGestureRecognizer>(this) setButtonMask:static_cast<::NSUInteger>(value)];
    }

    double PressGestureRecognizer::minimum_press_duration() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSPressGestureRecognizer>(this) minimumPressDuration]);
    }

    void PressGestureRecognizer::set_minimum_press_duration(double value) const
    {
        [cocoon::internal::ns<::NSPressGestureRecognizer>(this) setMinimumPressDuration:static_cast<::NSTimeInterval>(value)];
    }

    std::int64_t PressGestureRecognizer::number_of_touches_required() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPressGestureRecognizer>(this) numberOfTouchesRequired]);
    }

    void PressGestureRecognizer::set_number_of_touches_required(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSPressGestureRecognizer>(this) setNumberOfTouchesRequired:static_cast<::NSInteger>(value)];
    }
}
