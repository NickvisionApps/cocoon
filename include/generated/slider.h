#pragma once

#include "generated/availability.h"
#include "generated/control.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class Event;

    /**
     * @brief A slider control (NSSlider).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Control.
     *
     * @par Example
     * @code
     * cocoon::Slider slider(0, 100, 50);
     * slider.value_changed().connect([](double value) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Slider slider{1, 1, 1};
     * slider.set_allows_tick_mark_values_only(true);
     * auto allows_tick_mark_values_only = slider.allows_tick_mark_values_only();
     * slider.set_alt_increment_value(1);
     * auto alt_increment_value = slider.alt_increment_value();
     * slider.set_max_value(1);
     * auto max_value = slider.max_value();
     * slider.accepts_first_mouse(cocoon::Event());
     * slider.closest_tick_mark_value_to_value(1);
     * slider.index_of_tick_mark_at_point({0, 0});
     * slider.value_changed().connect([](double a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsslider
     */
    class Slider : public Control
    {
    public:
        /// @brief Creates a new `NSSlider` instance and returns a handle to it.
        explicit Slider(double min_value = 0, double max_value = 1, double value = 0);
        /// @brief Creates a new `NSSlider` instance and returns a handle to it.
        explicit Slider(const Object& target, const std::string& action);
        /// @brief Creates a new `NSSlider` instance and returns a handle to it.
        explicit Slider(double value, double min_value, double max_value, const Object& target, const std::string& action);
        /// @brief Creates a null handle that refers to no native object.
        Slider(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Slider(Adopt adopt);
        using View::accepts_first_mouse;
        /**
         * @brief Calls `-[NSSlider acceptsFirstMouse:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool accepts_first_mouse(const Event& event) const;
        /**
         * @brief Calls `-[NSSlider closestTickMarkValueToValue:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double closest_tick_mark_value_to_value(double value) const;
        /**
         * @brief Calls `-[NSSlider indexOfTickMarkAtPoint:]`.
         * @param point Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t index_of_tick_mark_at_point(const Point& point) const;
        /**
         * @brief Calls `-[NSSlider rectOfTickMarkAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect rect_of_tick_mark_at_index(std::int64_t index) const;
        /**
         * @brief Calls `-[NSSlider tickMarkValueAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double tick_mark_value_at_index(std::int64_t index) const;
        /**
         * @brief Returns the `allowsTickMarkValuesOnly` property of `NSSlider`.
         * @return The converted Objective-C result.
         */
        bool allows_tick_mark_values_only() const;
        /**
         * @brief Sets the `allowsTickMarkValuesOnly` property of `NSSlider`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_tick_mark_values_only(bool value) const;
        /**
         * @brief Returns the `altIncrementValue` property of `NSSlider`.
         * @return The converted Objective-C result.
         */
        double alt_increment_value() const;
        /**
         * @brief Sets the `altIncrementValue` property of `NSSlider`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_alt_increment_value(double value) const;
        /**
         * @brief Returns the `knobThickness` property of `NSSlider`.
         * @return The converted Objective-C result.
         */
        double knob_thickness() const;
        /**
         * @brief Returns the `maxValue` property of `NSSlider`.
         * @return The converted Objective-C result.
         */
        double max_value() const;
        /**
         * @brief Sets the `maxValue` property of `NSSlider`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_max_value(double value) const;
        /**
         * @brief Returns the `minValue` property of `NSSlider`.
         * @return The converted Objective-C result.
         */
        double min_value() const;
        /**
         * @brief Sets the `minValue` property of `NSSlider`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_min_value(double value) const;
        /**
         * @brief Returns the `neutralValue` property of `NSSlider`.
         * @details The value this slider will be filled from. This slider will be filled from its 'neutralValue' to its current value. If 'neutralValue' has not been explicitly set before, access to 'neutralValue' will return 'minValue'.
         * @return The converted Objective-C result.
         */
        double neutral_value() const;
        /**
         * @brief Sets the `neutralValue` property of `NSSlider`.
         * @details The value this slider will be filled from. This slider will be filled from its 'neutralValue' to its current value. If 'neutralValue' has not been explicitly set before, access to 'neutralValue' will return 'minValue'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_neutral_value(double value) const;
        /**
         * @brief Returns the `numberOfTickMarks` property of `NSSlider`.
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_tick_marks() const;
        /**
         * @brief Sets the `numberOfTickMarks` property of `NSSlider`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_number_of_tick_marks(std::int64_t value) const;
        /**
         * @brief Returns the `sliderType` property of `NSSlider`.
         * @return The converted Objective-C result.
         */
        SliderType slider_type() const;
        /**
         * @brief Sets the `sliderType` property of `NSSlider`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_slider_type(SliderType value) const;
        /**
         * @brief Returns the `tickMarkPosition` property of `NSSlider`.
         * @return The converted Objective-C result.
         */
        TickMarkPosition tick_mark_position() const;
        /**
         * @brief Sets the `tickMarkPosition` property of `NSSlider`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tick_mark_position(TickMarkPosition value) const;
        /**
         * @brief Returns the `tintProminence` property of `NSSlider`.
         * @details The tint prominence of the slider. The automatic behavior for a regular slider tints its track fill, while a slider with tick marks is untinted. Setting the tint prominence will override this default behavior and choose an explicit track fill tint behavior. See ''NSTintProminence'' for a list of possible values.
         * @return The converted Objective-C result.
         */
        TintProminence tint_prominence() const;
        /**
         * @brief Sets the `tintProminence` property of `NSSlider`.
         * @details The tint prominence of the slider. The automatic behavior for a regular slider tints its track fill, while a slider with tick marks is untinted. Setting the tint prominence will override this default behavior and choose an explicit track fill tint behavior. See ''NSTintProminence'' for a list of possible values.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tint_prominence(TintProminence value) const;
        /**
         * @brief Returns the `trackFillColor` property of `NSSlider`.
         * @return The converted Objective-C result.
         */
        Color track_fill_color() const;
        /**
         * @brief Sets the `trackFillColor` property of `NSSlider`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_track_fill_color(const Color& value) const;
        /**
         * @brief Returns the `vertical` property of `NSSlider`.
         * @return The converted Objective-C result.
         */
        bool is_vertical() const;
        /// @brief Convenience helper `value` provided by cocoon.
        double value() const;
        /// @brief Convenience helper `set_value` provided by cocoon.
        void set_value(double value) const;
        /// @brief Signal `value_changed`: connect a callback with `value_changed().connect(...)`.
        Signal<Slider, void(double)> value_changed() const
        {
            return Signal<Slider, void(double)>(handle(), "value_changed");
        }

    protected:
        static void bind_action_(void* native);
    };
}
