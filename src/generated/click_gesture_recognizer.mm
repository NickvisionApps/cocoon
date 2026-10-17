#include "generated/click_gesture_recognizer.h"
#include "internal.h"

namespace cocoon
{
    ClickGestureRecognizer::ClickGestureRecognizer() : ClickGestureRecognizer(Adopt{cocoon::internal::retain([[::NSClickGestureRecognizer alloc] init])})
    {
        GestureRecognizer::install_delegate_delegate_(handle());
    }

    ClickGestureRecognizer::ClickGestureRecognizer(std::nullptr_t) : GestureRecognizer(nullptr)
    {
    }

    ClickGestureRecognizer::ClickGestureRecognizer(Adopt adopt) : GestureRecognizer(adopt)
    {
    }

    std::uint64_t ClickGestureRecognizer::button_mask() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSClickGestureRecognizer>(this) buttonMask]);
    }

    void ClickGestureRecognizer::set_button_mask(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSClickGestureRecognizer>(this) setButtonMask:static_cast<::NSUInteger>(value)];
    }

    std::int64_t ClickGestureRecognizer::number_of_clicks_required() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSClickGestureRecognizer>(this) numberOfClicksRequired]);
    }

    void ClickGestureRecognizer::set_number_of_clicks_required(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSClickGestureRecognizer>(this) setNumberOfClicksRequired:static_cast<::NSInteger>(value)];
    }

    std::int64_t ClickGestureRecognizer::number_of_touches_required() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSClickGestureRecognizer>(this) numberOfTouchesRequired]);
    }

    void ClickGestureRecognizer::set_number_of_touches_required(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSClickGestureRecognizer>(this) setNumberOfTouchesRequired:static_cast<::NSInteger>(value)];
    }
}
