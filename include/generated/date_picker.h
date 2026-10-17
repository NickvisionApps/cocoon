#pragma once

#include "generated/control.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Calendar;
    class Color;
    class Date;
    class Locale;
    class TimeZone;

    /**
     * @brief A date and time picker.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Control.
     *
     * @par Example
     * @code
     * cocoon::DatePicker picker;
     * picker.set_timestamp(0);
     * picker.date_changed().connect([](double seconds) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DatePicker date_picker{};
     * date_picker.set_background_color(cocoon::Color());
     * auto background_color = date_picker.background_color();
     * date_picker.set_bezeled(true);
     * auto bezeled = date_picker.is_bezeled();
     * date_picker.set_bordered(true);
     * auto bordered = date_picker.is_bordered();
     * date_picker.date_changed().connect([](double a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsdatepicker
     */
    class DatePicker : public Control
    {
    public:
        /// @brief Creates a new `NSDatePicker` instance and returns a handle to it.
        explicit DatePicker();
        /// @brief Creates a null handle that refers to no native object.
        DatePicker(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DatePicker(Adopt adopt);
        using View::set_background_color;
        /**
     * @brief Returns the `backgroundColor` property of `NSDatePicker`.
     * @return The converted Objective-C result.
     */
        Color background_color() const;
        /**
     * @brief Sets the `backgroundColor` property of `NSDatePicker`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_color(const Color& value) const;
        /**
     * @brief Returns the `bezeled` property of `NSDatePicker`.
     * @return The converted Objective-C result.
     */
        bool is_bezeled() const;
        /**
     * @brief Sets the `bezeled` property of `NSDatePicker`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bezeled(bool value) const;
        /**
     * @brief Returns the `bordered` property of `NSDatePicker`.
     * @return The converted Objective-C result.
     */
        bool is_bordered() const;
        /**
     * @brief Sets the `bordered` property of `NSDatePicker`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bordered(bool value) const;
        /**
     * @brief Returns the `calendar` property of `NSDatePicker`.
     * @return The converted Objective-C result.
     */
        Calendar calendar() const;
        /**
     * @brief Sets the `calendar` property of `NSDatePicker`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_calendar(const Calendar& value) const;
        /**
     * @brief Returns the `datePickerElements` property of `NSDatePicker`.
     * @return The converted Objective-C result.
     */
        DatePickerElementFlags date_picker_elements() const;
        /**
     * @brief Sets the `datePickerElements` property of `NSDatePicker`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_date_picker_elements(DatePickerElementFlags value) const;
        /**
     * @brief Returns the `datePickerMode` property of `NSDatePicker`.
     * @return The converted Objective-C result.
     */
        DatePickerMode date_picker_mode() const;
        /**
     * @brief Sets the `datePickerMode` property of `NSDatePicker`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_date_picker_mode(DatePickerMode value) const;
        /**
     * @brief Returns the `datePickerStyle` property of `NSDatePicker`.
     * @return The converted Objective-C result.
     */
        DatePickerStyle date_picker_style() const;
        /**
     * @brief Sets the `datePickerStyle` property of `NSDatePicker`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_date_picker_style(DatePickerStyle value) const;
        /**
     * @brief Returns the `dateValue` property of `NSDatePicker`.
     * @return The converted Objective-C result.
     */
        Date date_value() const;
        /**
     * @brief Sets the `dateValue` property of `NSDatePicker`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_date_value(const Date& value) const;
        /**
     * @brief Returns the `drawsBackground` property of `NSDatePicker`.
     * @return The converted Objective-C result.
     */
        bool draws_background() const;
        /**
     * @brief Sets the `drawsBackground` property of `NSDatePicker`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_draws_background(bool value) const;
        /**
     * @brief Returns the `locale` property of `NSDatePicker`.
     * @return The converted Objective-C result.
     */
        Locale locale() const;
        /**
     * @brief Sets the `locale` property of `NSDatePicker`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_locale(const Locale& value) const;
        /**
     * @brief Returns the `maxDate` property of `NSDatePicker`.
     * @return The converted Objective-C result.
     */
        Date max_date() const;
        /**
     * @brief Sets the `maxDate` property of `NSDatePicker`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_max_date(const Date& value) const;
        /**
     * @brief Returns the `minDate` property of `NSDatePicker`.
     * @return The converted Objective-C result.
     */
        Date min_date() const;
        /**
     * @brief Sets the `minDate` property of `NSDatePicker`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_min_date(const Date& value) const;
        /**
     * @brief Returns the `presentsCalendarOverlay` property of `NSDatePicker`.
     * @return The converted Objective-C result.
     */
        bool presents_calendar_overlay() const;
        /**
     * @brief Sets the `presentsCalendarOverlay` property of `NSDatePicker`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_presents_calendar_overlay(bool value) const;
        /**
     * @brief Returns the `textColor` property of `NSDatePicker`.
     * @return The converted Objective-C result.
     */
        Color text_color() const;
        /**
     * @brief Sets the `textColor` property of `NSDatePicker`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_color(const Color& value) const;
        /**
     * @brief Returns the `timeInterval` property of `NSDatePicker`.
     * @return The converted Objective-C result.
     */
        double time_interval() const;
        /**
     * @brief Sets the `timeInterval` property of `NSDatePicker`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_time_interval(double value) const;
        /**
     * @brief Returns the `timeZone` property of `NSDatePicker`.
     * @return The converted Objective-C result.
     */
        TimeZone time_zone() const;
        /**
     * @brief Sets the `timeZone` property of `NSDatePicker`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_time_zone(const TimeZone& value) const;
        /// @brief Convenience helper `timestamp` provided by cocoon.
        double timestamp() const;
        /// @brief Convenience helper `set_timestamp` provided by cocoon.
        void set_timestamp(double seconds) const;
        /// @brief Signal `date_changed`: connect a callback with `date_changed().connect(...)`.
        Signal<DatePicker, void(double)> date_changed() const
        {
            return Signal<DatePicker, void(double)>(handle(), "date_changed");
        }
        /// @brief Signal for the delegate/data-source method behind `validate_proposed_date_value_time_interval`; connect a callback with `validate_proposed_date_value_time_interval().connect(...)`.
        Signal<DatePicker, void(Date&, double*)> validate_proposed_date_value_time_interval() const
        {
            return Signal<DatePicker, void(Date&, double*)>(handle(), "validate_proposed_date_value_time_interval");
        }

    protected:
        static void bind_action_(void* native);
        static void install_delegate_delegate_(void* native);
    };
}
