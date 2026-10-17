#include "generated/magnification_gesture_recognizer.h"
#include "internal.h"

namespace cocoon
{
    MagnificationGestureRecognizer::MagnificationGestureRecognizer() : MagnificationGestureRecognizer(Adopt{cocoon::internal::retain([[::NSMagnificationGestureRecognizer alloc] init])})
    {
        GestureRecognizer::install_delegate_delegate_(handle());
    }

    MagnificationGestureRecognizer::MagnificationGestureRecognizer(std::nullptr_t) : GestureRecognizer(nullptr)
    {
    }

    MagnificationGestureRecognizer::MagnificationGestureRecognizer(Adopt adopt) : GestureRecognizer(adopt)
    {
    }

    double MagnificationGestureRecognizer::magnification() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMagnificationGestureRecognizer>(this) magnification]);
    }

    void MagnificationGestureRecognizer::set_magnification(double value) const
    {
        [cocoon::internal::ns<::NSMagnificationGestureRecognizer>(this) setMagnification:static_cast<::CGFloat>(value)];
    }
}
