#include "generated/slider.h"
#include "internal.h"

namespace cocoon
{
    Slider::Slider(double min_value, double max_value, double value) : Slider(Adopt{cocoon::internal::retain([NSSlider sliderWithValue:value minValue:min_value maxValue:max_value target:nil action:nil])})
    {
        Slider::bind_action_(handle());
    }

    Slider::Slider(const Object& target, const std::string& action) : Slider(Adopt{cocoon::internal::retain([::NSSlider sliderWithTarget:cocoon::internal::native_id(target) action:NSSelectorFromString(cocoon::internal::to(action))])})
    {
        Slider::bind_action_(handle());
    }

    Slider::Slider(double value, double min_value, double max_value, const Object& target, const std::string& action) : Slider(Adopt{cocoon::internal::retain([::NSSlider sliderWithValue:static_cast<double>(value) minValue:static_cast<double>(min_value) maxValue:static_cast<double>(max_value) target:cocoon::internal::native_id(target) action:NSSelectorFromString(cocoon::internal::to(action))])})
    {
        Slider::bind_action_(handle());
    }

    Slider::Slider(std::nullptr_t) : Control(nullptr)
    {
    }

    Slider::Slider(Adopt adopt) : Control(adopt)
    {
    }

    bool Slider::accepts_first_mouse(const Event& event) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSlider>(this) acceptsFirstMouse:cocoon::internal::native<::NSEvent>(event)]);
    }

    double Slider::closest_tick_mark_value_to_value(double value) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSlider>(this) closestTickMarkValueToValue:static_cast<double>(value)]);
    }

    std::int64_t Slider::index_of_tick_mark_at_point(const Point& point) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSSlider>(this) indexOfTickMarkAtPoint:cocoon::internal::to(point)]);
    }

    Rect Slider::rect_of_tick_mark_at_index(std::int64_t index) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSlider>(this) rectOfTickMarkAtIndex:static_cast<::NSInteger>(index)]);
    }

    double Slider::tick_mark_value_at_index(std::int64_t index) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSlider>(this) tickMarkValueAtIndex:static_cast<::NSInteger>(index)]);
    }

    bool Slider::allows_tick_mark_values_only() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSlider>(this) allowsTickMarkValuesOnly]);
    }

    void Slider::set_allows_tick_mark_values_only(bool value) const
    {
        [cocoon::internal::ns<::NSSlider>(this) setAllowsTickMarkValuesOnly:static_cast<::BOOL>(value)];
    }

    double Slider::alt_increment_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSlider>(this) altIncrementValue]);
    }

    void Slider::set_alt_increment_value(double value) const
    {
        [cocoon::internal::ns<::NSSlider>(this) setAltIncrementValue:static_cast<double>(value)];
    }

    double Slider::knob_thickness() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSlider>(this) knobThickness]);
    }

    double Slider::max_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSlider>(this) maxValue]);
    }

    void Slider::set_max_value(double value) const
    {
        [cocoon::internal::ns<::NSSlider>(this) setMaxValue:static_cast<double>(value)];
    }

    double Slider::min_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSlider>(this) minValue]);
    }

    void Slider::set_min_value(double value) const
    {
        [cocoon::internal::ns<::NSSlider>(this) setMinValue:static_cast<double>(value)];
    }

    double Slider::neutral_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSlider>(this) neutralValue]);
    }

    void Slider::set_neutral_value(double value) const
    {
        [cocoon::internal::ns<::NSSlider>(this) setNeutralValue:static_cast<double>(value)];
    }

    std::int64_t Slider::number_of_tick_marks() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSSlider>(this) numberOfTickMarks]);
    }

    void Slider::set_number_of_tick_marks(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSSlider>(this) setNumberOfTickMarks:static_cast<::NSInteger>(value)];
    }

    SliderType Slider::slider_type() const
    {
        return static_cast<SliderType>([cocoon::internal::ns<::NSSlider>(this) sliderType]);
    }

    void Slider::set_slider_type(SliderType value) const
    {
        [cocoon::internal::ns<::NSSlider>(this) setSliderType:static_cast<::NSSliderType>(value)];
    }

    TickMarkPosition Slider::tick_mark_position() const
    {
        return static_cast<TickMarkPosition>([cocoon::internal::ns<::NSSlider>(this) tickMarkPosition]);
    }

    void Slider::set_tick_mark_position(TickMarkPosition value) const
    {
        [cocoon::internal::ns<::NSSlider>(this) setTickMarkPosition:static_cast<::NSTickMarkPosition>(value)];
    }

    TintProminence Slider::tint_prominence() const
    {
        return static_cast<TintProminence>([cocoon::internal::ns<::NSSlider>(this) tintProminence]);
    }

    void Slider::set_tint_prominence(TintProminence value) const
    {
        [cocoon::internal::ns<::NSSlider>(this) setTintProminence:static_cast<::NSTintProminence>(value)];
    }

    Color Slider::track_fill_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSSlider>(this) trackFillColor]);
    }

    void Slider::set_track_fill_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSSlider>(this) setTrackFillColor:cocoon::internal::native<::NSColor>(value)];
    }

    bool Slider::is_vertical() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSlider>(this) isVertical]);
    }

    double Slider::value() const
    {
        return cocoon::internal::ns<NSSlider>(this).doubleValue;
    }

    void Slider::set_value(double value) const
    {
        cocoon::internal::ns<NSSlider>(this).doubleValue = value;
    }

    void Slider::bind_action_(void* native)
    {
        id host = (__bridge id)native;
        cocoon::internal::bind_action(host, host, [](id host, id sender)
                                      {
                                          cocoon::Signal<cocoon::Slider, void(double)>::emit((__bridge void*)host, "value_changed", [(NSSlider*)sender doubleValue]);
                                      });
    }
}
