#include "generated/pan_gesture_recognizer.h"
#include "internal.h"

namespace cocoon
{
    PanGestureRecognizer::PanGestureRecognizer() : PanGestureRecognizer(Adopt{cocoon::internal::retain([[::NSPanGestureRecognizer alloc] init])})
    {
        GestureRecognizer::install_delegate_delegate_(handle());
    }

    PanGestureRecognizer::PanGestureRecognizer(std::nullptr_t) : GestureRecognizer(nullptr)
    {
    }

    PanGestureRecognizer::PanGestureRecognizer(Adopt adopt) : GestureRecognizer(adopt)
    {
    }

    void PanGestureRecognizer::set_translation(const Point& translation, const View& view) const
    {
        [cocoon::internal::ns<::NSPanGestureRecognizer>(this) setTranslation:cocoon::internal::to(translation) inView:cocoon::internal::native<::NSView>(view)];
    }

    Point PanGestureRecognizer::translation_in_view(const View& view) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPanGestureRecognizer>(this) translationInView:cocoon::internal::native<::NSView>(view)]);
    }

    Point PanGestureRecognizer::velocity_in_view(const View& view) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPanGestureRecognizer>(this) velocityInView:cocoon::internal::native<::NSView>(view)]);
    }

    std::uint64_t PanGestureRecognizer::button_mask() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSPanGestureRecognizer>(this) buttonMask]);
    }

    void PanGestureRecognizer::set_button_mask(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSPanGestureRecognizer>(this) setButtonMask:static_cast<::NSUInteger>(value)];
    }

    std::int64_t PanGestureRecognizer::maximum_number_of_touches() const
    {
        if (@available(macOS 27.0, *))
        {
            return static_cast<std::int64_t>([cocoon::internal::ns<::NSPanGestureRecognizer>(this) maximumNumberOfTouches]);
        }
        return {};
    }

    void PanGestureRecognizer::set_maximum_number_of_touches(std::int64_t value) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSPanGestureRecognizer>(this) setMaximumNumberOfTouches:static_cast<::NSInteger>(value)];
        }
    }

    std::int64_t PanGestureRecognizer::minimum_number_of_touches() const
    {
        if (@available(macOS 27.0, *))
        {
            return static_cast<std::int64_t>([cocoon::internal::ns<::NSPanGestureRecognizer>(this) minimumNumberOfTouches]);
        }
        return {};
    }

    void PanGestureRecognizer::set_minimum_number_of_touches(std::int64_t value) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSPanGestureRecognizer>(this) setMinimumNumberOfTouches:static_cast<::NSInteger>(value)];
        }
    }

    std::int64_t PanGestureRecognizer::number_of_touches_required() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPanGestureRecognizer>(this) numberOfTouchesRequired]);
    }

    void PanGestureRecognizer::set_number_of_touches_required(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSPanGestureRecognizer>(this) setNumberOfTouchesRequired:static_cast<::NSInteger>(value)];
    }
}
