#pragma once

#include "generated/action_cell.h"
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
     * @brief C++ handle for the Objective-C class `NSDatePickerCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ActionCell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DatePickerCell date_picker_cell;
     * date_picker_cell.set_background_color(cocoon::Color());
     * date_picker_cell.validate_proposed_date_value_time_interval().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DatePickerCell date_picker_cell{};
     * date_picker_cell.set_background_color(cocoon::Color());
     * auto background_color = date_picker_cell.background_color();
     * date_picker_cell.set_calendar(cocoon::Calendar());
     * auto calendar = date_picker_cell.calendar();
     * date_picker_cell.set_date_picker_elements(cocoon::DatePickerElementFlags::HourMinute);
     * auto date_picker_elements = date_picker_cell.date_picker_elements();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsdatepickercell
     */
    class DatePickerCell : public ActionCell
    {
    public:
        /// @brief Creates a new `NSDatePickerCell` instance and returns a handle to it.
        explicit DatePickerCell(const std::string& string);
        /// @brief Creates a new `NSDatePickerCell` instance and returns a handle to it.
        explicit DatePickerCell();
        /// @brief Creates a null handle that refers to no native object.
        DatePickerCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DatePickerCell(Adopt adopt);
        /**
     * @brief Returns the `backgroundColor` property of `NSDatePickerCell`.
     * @return The converted Objective-C result.
     */
        Color background_color() const;
        /**
     * @brief Sets the `backgroundColor` property of `NSDatePickerCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_color(const Color& value) const;
        /**
     * @brief Returns the `calendar` property of `NSDatePickerCell`.
     * @return The converted Objective-C result.
     */
        Calendar calendar() const;
        /**
     * @brief Sets the `calendar` property of `NSDatePickerCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_calendar(const Calendar& value) const;
        /**
     * @brief Returns the `datePickerElements` property of `NSDatePickerCell`.
     * @return The converted Objective-C result.
     */
        DatePickerElementFlags date_picker_elements() const;
        /**
     * @brief Sets the `datePickerElements` property of `NSDatePickerCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_date_picker_elements(DatePickerElementFlags value) const;
        /**
     * @brief Returns the `datePickerMode` property of `NSDatePickerCell`.
     * @return The converted Objective-C result.
     */
        DatePickerMode date_picker_mode() const;
        /**
     * @brief Sets the `datePickerMode` property of `NSDatePickerCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_date_picker_mode(DatePickerMode value) const;
        /**
     * @brief Returns the `datePickerStyle` property of `NSDatePickerCell`.
     * @return The converted Objective-C result.
     */
        DatePickerStyle date_picker_style() const;
        /**
     * @brief Sets the `datePickerStyle` property of `NSDatePickerCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_date_picker_style(DatePickerStyle value) const;
        /**
     * @brief Returns the `dateValue` property of `NSDatePickerCell`.
     * @return The converted Objective-C result.
     */
        Date date_value() const;
        /**
     * @brief Sets the `dateValue` property of `NSDatePickerCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_date_value(const Date& value) const;
        /**
     * @brief Returns the `drawsBackground` property of `NSDatePickerCell`.
     * @return The converted Objective-C result.
     */
        bool draws_background() const;
        /**
     * @brief Sets the `drawsBackground` property of `NSDatePickerCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_draws_background(bool value) const;
        /**
     * @brief Returns the `locale` property of `NSDatePickerCell`.
     * @return The converted Objective-C result.
     */
        Locale locale() const;
        /**
     * @brief Sets the `locale` property of `NSDatePickerCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_locale(const Locale& value) const;
        /**
     * @brief Returns the `maxDate` property of `NSDatePickerCell`.
     * @return The converted Objective-C result.
     */
        Date max_date() const;
        /**
     * @brief Sets the `maxDate` property of `NSDatePickerCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_max_date(const Date& value) const;
        /**
     * @brief Returns the `minDate` property of `NSDatePickerCell`.
     * @return The converted Objective-C result.
     */
        Date min_date() const;
        /**
     * @brief Sets the `minDate` property of `NSDatePickerCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_min_date(const Date& value) const;
        /**
     * @brief Returns the `textColor` property of `NSDatePickerCell`.
     * @return The converted Objective-C result.
     */
        Color text_color() const;
        /**
     * @brief Sets the `textColor` property of `NSDatePickerCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_color(const Color& value) const;
        /**
     * @brief Returns the `timeInterval` property of `NSDatePickerCell`.
     * @return The converted Objective-C result.
     */
        double time_interval() const;
        /**
     * @brief Sets the `timeInterval` property of `NSDatePickerCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_time_interval(double value) const;
        /**
     * @brief Returns the `timeZone` property of `NSDatePickerCell`.
     * @return The converted Objective-C result.
     */
        TimeZone time_zone() const;
        /**
     * @brief Sets the `timeZone` property of `NSDatePickerCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_time_zone(const TimeZone& value) const;
        /// @brief Signal for the delegate/data-source method behind `validate_proposed_date_value_time_interval`; connect a callback with `validate_proposed_date_value_time_interval().connect(...)`.
        Signal<DatePickerCell, void(Date&, double*)> validate_proposed_date_value_time_interval() const
        {
            return Signal<DatePickerCell, void(Date&, double*)>(handle(), "validate_proposed_date_value_time_interval");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
