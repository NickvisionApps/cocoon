#include "generated/scroller.h"
#include "internal.h"

namespace cocoon
{
    Scroller::Scroller() : Scroller(Adopt{cocoon::internal::retain([[::NSScroller alloc] init])})
    {
    }

    Scroller::Scroller(std::nullptr_t) : Control(nullptr)
    {
    }

    Scroller::Scroller(Adopt adopt) : Control(adopt)
    {
    }

    void Scroller::check_space_for_parts() const
    {
        [cocoon::internal::ns<::NSScroller>(this) checkSpaceForParts];
    }

    void Scroller::draw_knob() const
    {
        [cocoon::internal::ns<::NSScroller>(this) drawKnob];
    }

    void Scroller::draw_knob_slot_in_rect(const Rect& slot_rect, bool flag) const
    {
        [cocoon::internal::ns<::NSScroller>(this) drawKnobSlotInRect:cocoon::internal::to(slot_rect) highlight:static_cast<::BOOL>(flag)];
    }

    Rect Scroller::rect_for_part(ScrollerPart part_code) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScroller>(this) rectForPart:static_cast<::NSScrollerPart>(part_code)]);
    }

    double Scroller::scroller_width_for_control_size(ControlSize control_size, ScrollerStyle scroller_style)
    {
        return static_cast<double>([::NSScroller scrollerWidthForControlSize:static_cast<::NSControlSize>(control_size) scrollerStyle:static_cast<::NSScrollerStyle>(scroller_style)]);
    }

    void Scroller::set_knob_proportion(double proportion) const
    {
        [cocoon::internal::ns<::NSScroller>(this) setKnobProportion:static_cast<::CGFloat>(proportion)];
    }

    ScrollerPart Scroller::test_part(const Point& point) const
    {
        return static_cast<ScrollerPart>([cocoon::internal::ns<::NSScroller>(this) testPart:cocoon::internal::to(point)]);
    }

    void Scroller::track_knob(const Event& event) const
    {
        [cocoon::internal::ns<::NSScroller>(this) trackKnob:cocoon::internal::native<::NSEvent>(event)];
    }

    bool Scroller::is_compatible_with_overlay_scrollers()
    {
        return static_cast<bool>([::NSScroller isCompatibleWithOverlayScrollers]);
    }

    ControlSize Scroller::control_size() const
    {
        return static_cast<ControlSize>([cocoon::internal::ns<::NSScroller>(this) controlSize]);
    }

    void Scroller::set_control_size(ControlSize value) const
    {
        [cocoon::internal::ns<::NSScroller>(this) setControlSize:static_cast<::NSControlSize>(value)];
    }

    ScrollerPart Scroller::hit_part() const
    {
        return static_cast<ScrollerPart>([cocoon::internal::ns<::NSScroller>(this) hitPart]);
    }

    double Scroller::knob_proportion() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSScroller>(this) knobProportion]);
    }

    ScrollerKnobStyle Scroller::knob_style() const
    {
        return static_cast<ScrollerKnobStyle>([cocoon::internal::ns<::NSScroller>(this) knobStyle]);
    }

    void Scroller::set_knob_style(ScrollerKnobStyle value) const
    {
        [cocoon::internal::ns<::NSScroller>(this) setKnobStyle:static_cast<::NSScrollerKnobStyle>(value)];
    }

    ScrollerStyle Scroller::preferred_scroller_style()
    {
        return static_cast<ScrollerStyle>([::NSScroller preferredScrollerStyle]);
    }

    ScrollerStyle Scroller::scroller_style() const
    {
        return static_cast<ScrollerStyle>([cocoon::internal::ns<::NSScroller>(this) scrollerStyle]);
    }

    void Scroller::set_scroller_style(ScrollerStyle value) const
    {
        [cocoon::internal::ns<::NSScroller>(this) setScrollerStyle:static_cast<::NSScrollerStyle>(value)];
    }

    UsableScrollerParts Scroller::usable_parts() const
    {
        return static_cast<UsableScrollerParts>([cocoon::internal::ns<::NSScroller>(this) usableParts]);
    }
}
