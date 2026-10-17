#include "generated/rotation_gesture_recognizer.h"
#include "internal.h"

namespace cocoon
{
    RotationGestureRecognizer::RotationGestureRecognizer() : RotationGestureRecognizer(Adopt{cocoon::internal::retain([[::NSRotationGestureRecognizer alloc] init])})
    {
        GestureRecognizer::install_delegate_delegate_(handle());
    }

    RotationGestureRecognizer::RotationGestureRecognizer(std::nullptr_t) : GestureRecognizer(nullptr)
    {
    }

    RotationGestureRecognizer::RotationGestureRecognizer(Adopt adopt) : GestureRecognizer(adopt)
    {
    }

    double RotationGestureRecognizer::rotation() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSRotationGestureRecognizer>(this) rotation]);
    }

    void RotationGestureRecognizer::set_rotation(double value) const
    {
        [cocoon::internal::ns<::NSRotationGestureRecognizer>(this) setRotation:static_cast<::CGFloat>(value)];
    }

    double RotationGestureRecognizer::rotation_in_degrees() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSRotationGestureRecognizer>(this) rotationInDegrees]);
    }

    void RotationGestureRecognizer::set_rotation_in_degrees(double value) const
    {
        [cocoon::internal::ns<::NSRotationGestureRecognizer>(this) setRotationInDegrees:static_cast<::CGFloat>(value)];
    }
}
