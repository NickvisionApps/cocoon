#include "generated/ruler_view.h"
#include "internal.h"

namespace cocoon
{
    RulerView::RulerView(const ScrollView& scroll_view, RulerOrientation orientation) : RulerView(Adopt{cocoon::internal::retain([[::NSRulerView alloc] initWithScrollView:cocoon::internal::native<::NSScrollView>(scroll_view) orientation:static_cast<::NSRulerOrientation>(orientation)])})
    {
    }

    RulerView::RulerView() : RulerView(Adopt{cocoon::internal::retain([[::NSRulerView alloc] init])})
    {
    }

    RulerView::RulerView(std::nullptr_t) : View(nullptr)
    {
    }

    RulerView::RulerView(Adopt adopt) : View(adopt)
    {
    }

    void RulerView::add_marker(const RulerMarker& marker) const
    {
        [cocoon::internal::ns<::NSRulerView>(this) addMarker:cocoon::internal::native<::NSRulerMarker>(marker)];
    }

    void RulerView::draw_hash_marks_and_labels_in_rect(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSRulerView>(this) drawHashMarksAndLabelsInRect:cocoon::internal::to(rect)];
    }

    void RulerView::draw_markers_in_rect(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSRulerView>(this) drawMarkersInRect:cocoon::internal::to(rect)];
    }

    void RulerView::invalidate_hash_marks() const
    {
        [cocoon::internal::ns<::NSRulerView>(this) invalidateHashMarks];
    }

    void RulerView::move_rulerline_from_location(double old_location, double new_location) const
    {
        [cocoon::internal::ns<::NSRulerView>(this) moveRulerlineFromLocation:static_cast<::CGFloat>(old_location) toLocation:static_cast<::CGFloat>(new_location)];
    }

    void RulerView::register_unit_with_name(const std::string& unit_name, const std::string& abbreviation, double conversion_factor, const std::vector<Number>& step_up_cycle, const std::vector<Number>& step_down_cycle)
    {
        [::NSRulerView registerUnitWithName:cocoon::internal::to(unit_name)
                               abbreviation:cocoon::internal::to(abbreviation)
               unitToPointsConversionFactor:static_cast<::CGFloat>(conversion_factor)
                                stepUpCycle:cocoon::internal::to_array(step_up_cycle, [](const Number& e) -> id
                                                         {
                                                             return cocoon::internal::native<::NSNumber>(e);
                                                         })
                              stepDownCycle:cocoon::internal::to_array(step_down_cycle, [](const Number& e) -> id
                                                         {
                                                             return cocoon::internal::native<::NSNumber>(e);
                                                         })];
    }

    void RulerView::remove_marker(const RulerMarker& marker) const
    {
        [cocoon::internal::ns<::NSRulerView>(this) removeMarker:cocoon::internal::native<::NSRulerMarker>(marker)];
    }

    bool RulerView::track_marker(const RulerMarker& marker, const Event& event) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRulerView>(this) trackMarker:cocoon::internal::native<::NSRulerMarker>(marker) withMouseEvent:cocoon::internal::native<::NSEvent>(event)]);
    }

    View RulerView::accessory_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSRulerView>(this) accessoryView]);
    }

    void RulerView::set_accessory_view(const View& value) const
    {
        [cocoon::internal::ns<::NSRulerView>(this) setAccessoryView:cocoon::internal::native<::NSView>(value)];
    }

    double RulerView::baseline_location() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSRulerView>(this) baselineLocation]);
    }

    View RulerView::client_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSRulerView>(this) clientView]);
    }

    void RulerView::set_client_view(const View& value) const
    {
        [cocoon::internal::ns<::NSRulerView>(this) setClientView:cocoon::internal::native<::NSView>(value)];
    }

    bool RulerView::is_flipped() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRulerView>(this) isFlipped]);
    }

    std::vector<RulerMarker> RulerView::markers() const
    {
        return cocoon::internal::from_array<RulerMarker>([cocoon::internal::ns<::NSRulerView>(this) markers], [](id e) -> RulerMarker
                                           {
                                               return cocoon::internal::wrap<RulerMarker>((::NSRulerMarker*)e);
                                           });
    }

    void RulerView::set_markers(const std::vector<RulerMarker>& value) const
    {
        [cocoon::internal::ns<::NSRulerView>(this) setMarkers:cocoon::internal::to_array(value, [](const RulerMarker& e) -> id
                                                             {
                                                                 return cocoon::internal::native<::NSRulerMarker>(e);
                                                             })];
    }

    std::string RulerView::measurement_units() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRulerView>(this) measurementUnits]);
    }

    void RulerView::set_measurement_units(const std::string& value) const
    {
        [cocoon::internal::ns<::NSRulerView>(this) setMeasurementUnits:cocoon::internal::to(value)];
    }

    RulerOrientation RulerView::orientation() const
    {
        return static_cast<RulerOrientation>([cocoon::internal::ns<::NSRulerView>(this) orientation]);
    }

    void RulerView::set_orientation(RulerOrientation value) const
    {
        [cocoon::internal::ns<::NSRulerView>(this) setOrientation:static_cast<::NSRulerOrientation>(value)];
    }

    double RulerView::origin_offset() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSRulerView>(this) originOffset]);
    }

    void RulerView::set_origin_offset(double value) const
    {
        [cocoon::internal::ns<::NSRulerView>(this) setOriginOffset:static_cast<::CGFloat>(value)];
    }

    double RulerView::required_thickness() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSRulerView>(this) requiredThickness]);
    }

    double RulerView::reserved_thickness_for_accessory_view() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSRulerView>(this) reservedThicknessForAccessoryView]);
    }

    void RulerView::set_reserved_thickness_for_accessory_view(double value) const
    {
        [cocoon::internal::ns<::NSRulerView>(this) setReservedThicknessForAccessoryView:static_cast<::CGFloat>(value)];
    }

    double RulerView::reserved_thickness_for_markers() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSRulerView>(this) reservedThicknessForMarkers]);
    }

    void RulerView::set_reserved_thickness_for_markers(double value) const
    {
        [cocoon::internal::ns<::NSRulerView>(this) setReservedThicknessForMarkers:static_cast<::CGFloat>(value)];
    }

    double RulerView::rule_thickness() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSRulerView>(this) ruleThickness]);
    }

    void RulerView::set_rule_thickness(double value) const
    {
        [cocoon::internal::ns<::NSRulerView>(this) setRuleThickness:static_cast<::CGFloat>(value)];
    }

    ScrollView RulerView::scroll_view() const
    {
        return cocoon::internal::wrap<ScrollView>([cocoon::internal::ns<::NSRulerView>(this) scrollView]);
    }

    void RulerView::set_scroll_view(const ScrollView& value) const
    {
        [cocoon::internal::ns<::NSRulerView>(this) setScrollView:cocoon::internal::native<::NSScrollView>(value)];
    }
}
