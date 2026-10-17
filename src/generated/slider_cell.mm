#include "generated/slider_cell.h"
#include "internal.h"

namespace cocoon
{
    SliderCell::SliderCell() : SliderCell(Adopt{cocoon::internal::retain([[::NSSliderCell alloc] init])})
    {
    }

    SliderCell::SliderCell(std::nullptr_t) : ActionCell(nullptr)
    {
    }

    SliderCell::SliderCell(Adopt adopt) : ActionCell(adopt)
    {
    }

    Rect SliderCell::bar_rect_flipped(bool flipped) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSliderCell>(this) barRectFlipped:static_cast<::BOOL>(flipped)]);
    }

    double SliderCell::closest_tick_mark_value_to_value(double value) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSliderCell>(this) closestTickMarkValueToValue:static_cast<double>(value)]);
    }

    void SliderCell::draw_bar_inside(const Rect& rect, bool flipped) const
    {
        [cocoon::internal::ns<::NSSliderCell>(this) drawBarInside:cocoon::internal::to(rect) flipped:static_cast<::BOOL>(flipped)];
    }

    void SliderCell::draw_knob() const
    {
        [cocoon::internal::ns<::NSSliderCell>(this) drawKnob];
    }

    void SliderCell::draw_knob(const Rect& knob_rect) const
    {
        [cocoon::internal::ns<::NSSliderCell>(this) drawKnob:cocoon::internal::to(knob_rect)];
    }

    void SliderCell::draw_tick_marks() const
    {
        [cocoon::internal::ns<::NSSliderCell>(this) drawTickMarks];
    }

    std::int64_t SliderCell::index_of_tick_mark_at_point(const Point& point) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSSliderCell>(this) indexOfTickMarkAtPoint:cocoon::internal::to(point)]);
    }

    Rect SliderCell::knob_rect_flipped(bool flipped) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSliderCell>(this) knobRectFlipped:static_cast<::BOOL>(flipped)]);
    }

    Rect SliderCell::rect_of_tick_mark_at_index(std::int64_t index) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSliderCell>(this) rectOfTickMarkAtIndex:static_cast<::NSInteger>(index)]);
    }

    double SliderCell::tick_mark_value_at_index(std::int64_t index) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSliderCell>(this) tickMarkValueAtIndex:static_cast<::NSInteger>(index)]);
    }

    bool SliderCell::allows_tick_mark_values_only() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSliderCell>(this) allowsTickMarkValuesOnly]);
    }

    void SliderCell::set_allows_tick_mark_values_only(bool value) const
    {
        [cocoon::internal::ns<::NSSliderCell>(this) setAllowsTickMarkValuesOnly:static_cast<::BOOL>(value)];
    }

    double SliderCell::alt_increment_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSliderCell>(this) altIncrementValue]);
    }

    void SliderCell::set_alt_increment_value(double value) const
    {
        [cocoon::internal::ns<::NSSliderCell>(this) setAltIncrementValue:static_cast<double>(value)];
    }

    double SliderCell::knob_thickness() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSliderCell>(this) knobThickness]);
    }

    double SliderCell::max_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSliderCell>(this) maxValue]);
    }

    void SliderCell::set_max_value(double value) const
    {
        [cocoon::internal::ns<::NSSliderCell>(this) setMaxValue:static_cast<double>(value)];
    }

    double SliderCell::min_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSliderCell>(this) minValue]);
    }

    void SliderCell::set_min_value(double value) const
    {
        [cocoon::internal::ns<::NSSliderCell>(this) setMinValue:static_cast<double>(value)];
    }

    std::int64_t SliderCell::number_of_tick_marks() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSSliderCell>(this) numberOfTickMarks]);
    }

    void SliderCell::set_number_of_tick_marks(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSSliderCell>(this) setNumberOfTickMarks:static_cast<::NSInteger>(value)];
    }

    bool SliderCell::prefers_tracking_until_mouse_up()
    {
        return static_cast<bool>([::NSSliderCell prefersTrackingUntilMouseUp]);
    }

    SliderType SliderCell::slider_type() const
    {
        return static_cast<SliderType>([cocoon::internal::ns<::NSSliderCell>(this) sliderType]);
    }

    void SliderCell::set_slider_type(SliderType value) const
    {
        [cocoon::internal::ns<::NSSliderCell>(this) setSliderType:static_cast<::NSSliderType>(value)];
    }

    TickMarkPosition SliderCell::tick_mark_position() const
    {
        return static_cast<TickMarkPosition>([cocoon::internal::ns<::NSSliderCell>(this) tickMarkPosition]);
    }

    void SliderCell::set_tick_mark_position(TickMarkPosition value) const
    {
        [cocoon::internal::ns<::NSSliderCell>(this) setTickMarkPosition:static_cast<::NSTickMarkPosition>(value)];
    }

    Rect SliderCell::track_rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSliderCell>(this) trackRect]);
    }

    bool SliderCell::is_vertical() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSliderCell>(this) isVertical]);
    }
}
