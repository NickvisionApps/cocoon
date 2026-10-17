#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class Event;
    class Number;
    class RulerMarker;
    class ScrollView;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSRulerView` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::RulerView ruler_view;
     * ruler_view.set_accessory_view(cocoon::View());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::RulerView ruler_view{};
     * ruler_view.set_accessory_view(cocoon::View());
     * auto accessory_view = ruler_view.accessory_view();
     * ruler_view.set_client_view(cocoon::View());
     * auto client_view = ruler_view.client_view();
     * ruler_view.set_measurement_units("text");
     * auto measurement_units = ruler_view.measurement_units();
     * ruler_view.add_marker(cocoon::RulerMarker());
     * ruler_view.draw_hash_marks_and_labels_in_rect({{0, 0}, {100, 100}});
     * ruler_view.draw_markers_in_rect({{0, 0}, {100, 100}});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsrulerview
     */
    class RulerView : public View
    {
    public:
        /// @brief Creates a new `NSRulerView` instance and returns a handle to it.
        explicit RulerView(const ScrollView& scroll_view, RulerOrientation orientation);
        /// @brief Creates a new `NSRulerView` instance and returns a handle to it.
        explicit RulerView();
        /// @brief Creates a null handle that refers to no native object.
        RulerView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit RulerView(Adopt adopt);
        using View::is_flipped;
        /**
     * @brief Calls `-[NSRulerView addMarker:]`.
     * @param marker Argument converted to the Objective-C parameter of the same role.
     */
        void add_marker(const RulerMarker& marker) const;
        /**
     * @brief Calls `-[NSRulerView drawHashMarksAndLabelsInRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     */
        void draw_hash_marks_and_labels_in_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSRulerView drawMarkersInRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     */
        void draw_markers_in_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSRulerView invalidateHashMarks]`.
     * @details Drawing and hash invalidation
     */
        void invalidate_hash_marks() const;
        /**
     * @brief Calls `-[NSRulerView moveRulerlineFromLocation:toLocation:]`.
     * @param old_location Argument converted to the Objective-C parameter of the same role.
     * @param new_location Argument converted to the Objective-C parameter of the same role.
     */
        void move_rulerline_from_location(double old_location, double new_location) const;
        /**
     * @brief Calls `+[NSRulerView registerUnitWithName:abbreviation:unitToPointsConversionFactor:stepUpCycle:stepDownCycle:]`.
     * @details Registering new units
     * @param unit_name Argument converted to the Objective-C parameter of the same role.
     * @param abbreviation Argument converted to the Objective-C parameter of the same role.
     * @param conversion_factor Argument converted to the Objective-C parameter of the same role.
     * @param step_up_cycle Argument converted to the Objective-C parameter of the same role.
     * @param step_down_cycle Argument converted to the Objective-C parameter of the same role.
     */
        static void register_unit_with_name(const std::string& unit_name, const std::string& abbreviation, double conversion_factor, const std::vector<Number>& step_up_cycle, const std::vector<Number>& step_down_cycle);
        /**
     * @brief Calls `-[NSRulerView removeMarker:]`.
     * @param marker Argument converted to the Objective-C parameter of the same role.
     */
        void remove_marker(const RulerMarker& marker) const;
        /**
     * @brief Calls `-[NSRulerView trackMarker:withMouseEvent:]`.
     * @param marker Argument converted to the Objective-C parameter of the same role.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool track_marker(const RulerMarker& marker, const Event& event) const;
        /**
     * @brief Returns the `accessoryView` property of `NSRulerView`.
     * @return The converted Objective-C result.
     */
        View accessory_view() const;
        /**
     * @brief Sets the `accessoryView` property of `NSRulerView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_accessory_view(const View& value) const;
        /**
     * @brief Returns the `baselineLocation` property of `NSRulerView`.
     * @details Ruler geometry
     * @return The converted Objective-C result.
     */
        double baseline_location() const;
        /**
     * @brief Returns the `clientView` property of `NSRulerView`.
     * @details Client view setup
     * @return The converted Objective-C result.
     */
        View client_view() const;
        /**
     * @brief Sets the `clientView` property of `NSRulerView`.
     * @details Client view setup
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_client_view(const View& value) const;
        /**
     * @brief Returns the `flipped` property of `NSRulerView`.
     * @details Key overrides
     * @return The converted Objective-C result.
     */
        bool is_flipped() const;
        /**
     * @brief Returns the `markers` property of `NSRulerView`.
     * @return The converted Objective-C result.
     */
        std::vector<RulerMarker> markers() const;
        /**
     * @brief Sets the `markers` property of `NSRulerView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_markers(const std::vector<RulerMarker>& value) const;
        /**
     * @brief Returns the `measurementUnits` property of `NSRulerView`.
     * @details Rule configuration
     * @return The converted Objective-C result.
     */
        std::string measurement_units() const;
        /**
     * @brief Sets the `measurementUnits` property of `NSRulerView`.
     * @details Rule configuration
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_measurement_units(const std::string& value) const;
        /**
     * @brief Returns the `orientation` property of `NSRulerView`.
     * @return The converted Objective-C result.
     */
        RulerOrientation orientation() const;
        /**
     * @brief Sets the `orientation` property of `NSRulerView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_orientation(RulerOrientation value) const;
        /**
     * @brief Returns the `originOffset` property of `NSRulerView`.
     * @return The converted Objective-C result.
     */
        double origin_offset() const;
        /**
     * @brief Sets the `originOffset` property of `NSRulerView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_origin_offset(double value) const;
        /**
     * @brief Returns the `requiredThickness` property of `NSRulerView`.
     * @return The converted Objective-C result.
     */
        double required_thickness() const;
        /**
     * @brief Returns the `reservedThicknessForAccessoryView` property of `NSRulerView`.
     * @return The converted Objective-C result.
     */
        double reserved_thickness_for_accessory_view() const;
        /**
     * @brief Sets the `reservedThicknessForAccessoryView` property of `NSRulerView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_reserved_thickness_for_accessory_view(double value) const;
        /**
     * @brief Returns the `reservedThicknessForMarkers` property of `NSRulerView`.
     * @return The converted Objective-C result.
     */
        double reserved_thickness_for_markers() const;
        /**
     * @brief Sets the `reservedThicknessForMarkers` property of `NSRulerView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_reserved_thickness_for_markers(double value) const;
        /**
     * @brief Returns the `ruleThickness` property of `NSRulerView`.
     * @return The converted Objective-C result.
     */
        double rule_thickness() const;
        /**
     * @brief Sets the `ruleThickness` property of `NSRulerView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_rule_thickness(double value) const;
        /**
     * @brief Returns the `scrollView` property of `NSRulerView`.
     * @details Basic setup
     * @return The converted Objective-C result.
     */
        ScrollView scroll_view() const;
        /**
     * @brief Sets the `scrollView` property of `NSRulerView`.
     * @details Basic setup
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_scroll_view(const ScrollView& value) const;
    };
}
