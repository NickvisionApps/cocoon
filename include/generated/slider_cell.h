#pragma once

#include "generated/action_cell.h"
#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSSliderCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ActionCell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SliderCell slider_cell;
     * slider_cell.set_allows_tick_mark_values_only(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SliderCell slider_cell{};
     * slider_cell.set_allows_tick_mark_values_only(true);
     * auto allows_tick_mark_values_only = slider_cell.allows_tick_mark_values_only();
     * slider_cell.set_alt_increment_value(1);
     * auto alt_increment_value = slider_cell.alt_increment_value();
     * slider_cell.set_max_value(1);
     * auto max_value = slider_cell.max_value();
     * slider_cell.bar_rect_flipped(true);
     * slider_cell.closest_tick_mark_value_to_value(1);
     * slider_cell.draw_bar_inside({{0, 0}, {100, 100}}, true);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsslidercell
     */
    class SliderCell : public ActionCell
    {
    public:
        /// @brief Creates a new `NSSliderCell` instance and returns a handle to it.
        explicit SliderCell();
        /// @brief Creates a null handle that refers to no native object.
        SliderCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SliderCell(Adopt adopt);
        using Cell::prefers_tracking_until_mouse_up;
        /**
         * @brief Calls `-[NSSliderCell barRectFlipped:]`.
         * @param flipped Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect bar_rect_flipped(bool flipped) const;
        /**
         * @brief Calls `-[NSSliderCell closestTickMarkValueToValue:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double closest_tick_mark_value_to_value(double value) const;
        /**
         * @brief Calls `-[NSSliderCell drawBarInside:flipped:]`.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         * @param flipped Argument converted to the Objective-C parameter of the same role.
         */
        void draw_bar_inside(const Rect& rect, bool flipped) const;
        /**
         * @brief Calls `-[NSSliderCell drawKnob]`.
         */
        void draw_knob() const;
        /**
         * @brief Calls `-[NSSliderCell drawKnob:]`.
         * @param knob_rect Argument converted to the Objective-C parameter of the same role.
         */
        void draw_knob(const Rect& knob_rect) const;
        /**
         * @brief Calls `-[NSSliderCell drawTickMarks]`.
         */
        void draw_tick_marks() const;
        /**
         * @brief Calls `-[NSSliderCell indexOfTickMarkAtPoint:]`.
         * @param point Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t index_of_tick_mark_at_point(const Point& point) const;
        /**
         * @brief Calls `-[NSSliderCell knobRectFlipped:]`.
         * @param flipped Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect knob_rect_flipped(bool flipped) const;
        /**
         * @brief Calls `-[NSSliderCell rectOfTickMarkAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect rect_of_tick_mark_at_index(std::int64_t index) const;
        /**
         * @brief Calls `-[NSSliderCell tickMarkValueAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double tick_mark_value_at_index(std::int64_t index) const;
        /**
         * @brief Returns the `allowsTickMarkValuesOnly` property of `NSSliderCell`.
         * @return The converted Objective-C result.
         */
        bool allows_tick_mark_values_only() const;
        /**
         * @brief Sets the `allowsTickMarkValuesOnly` property of `NSSliderCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_tick_mark_values_only(bool value) const;
        /**
         * @brief Returns the `altIncrementValue` property of `NSSliderCell`.
         * @return The converted Objective-C result.
         */
        double alt_increment_value() const;
        /**
         * @brief Sets the `altIncrementValue` property of `NSSliderCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_alt_increment_value(double value) const;
        /**
         * @brief Returns the `knobThickness` property of `NSSliderCell`.
         * @return The converted Objective-C result.
         */
        double knob_thickness() const;
        /**
         * @brief Returns the `maxValue` property of `NSSliderCell`.
         * @return The converted Objective-C result.
         */
        double max_value() const;
        /**
         * @brief Sets the `maxValue` property of `NSSliderCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_max_value(double value) const;
        /**
         * @brief Returns the `minValue` property of `NSSliderCell`.
         * @return The converted Objective-C result.
         */
        double min_value() const;
        /**
         * @brief Sets the `minValue` property of `NSSliderCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_min_value(double value) const;
        /**
         * @brief Returns the `numberOfTickMarks` property of `NSSliderCell`.
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_tick_marks() const;
        /**
         * @brief Sets the `numberOfTickMarks` property of `NSSliderCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_number_of_tick_marks(std::int64_t value) const;
        /**
         * @brief Returns the `prefersTrackingUntilMouseUp` property of `NSSliderCell`.
         * @return The converted Objective-C result.
         */
        static bool prefers_tracking_until_mouse_up();
        /**
         * @brief Returns the `sliderType` property of `NSSliderCell`.
         * @return The converted Objective-C result.
         */
        SliderType slider_type() const;
        /**
         * @brief Sets the `sliderType` property of `NSSliderCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_slider_type(SliderType value) const;
        /**
         * @brief Returns the `tickMarkPosition` property of `NSSliderCell`.
         * @return The converted Objective-C result.
         */
        TickMarkPosition tick_mark_position() const;
        /**
         * @brief Sets the `tickMarkPosition` property of `NSSliderCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tick_mark_position(TickMarkPosition value) const;
        /**
         * @brief Returns the `trackRect` property of `NSSliderCell`.
         * @return The converted Objective-C result.
         */
        Rect track_rect() const;
        /**
         * @brief Returns the `vertical` property of `NSSliderCell`.
         * @return The converted Objective-C result.
         */
        bool is_vertical() const;
    };
}
