#include "generated/date_components_formatter.h"
#include "internal.h"

namespace cocoon
{
    DateComponentsFormatter::DateComponentsFormatter() : DateComponentsFormatter(Adopt{cocoon::internal::retain([[::NSDateComponentsFormatter alloc] init])})
    {
    }

    DateComponentsFormatter::DateComponentsFormatter(std::nullptr_t) : Formatter(nullptr)
    {
    }

    DateComponentsFormatter::DateComponentsFormatter(Adopt adopt) : Formatter(adopt)
    {
    }

    std::string DateComponentsFormatter::localized_string_from_date_components(const DateComponents& components, DateComponentsFormatterUnitsStyle units_style)
    {
        return cocoon::internal::from([::NSDateComponentsFormatter localizedStringFromDateComponents:cocoon::internal::native<::NSDateComponents>(components) unitsStyle:static_cast<::NSDateComponentsFormatterUnitsStyle>(units_style)]);
    }

    std::string DateComponentsFormatter::string_for_object_value(const Object& obj) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDateComponentsFormatter>(this) stringForObjectValue:cocoon::internal::native_id(obj)]);
    }

    std::string DateComponentsFormatter::string_from_date(const Date& start_date, const Date& end_date) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDateComponentsFormatter>(this) stringFromDate:cocoon::internal::native<::NSDate>(start_date) toDate:cocoon::internal::native<::NSDate>(end_date)]);
    }

    std::string DateComponentsFormatter::string_from_date_components(const DateComponents& components) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDateComponentsFormatter>(this) stringFromDateComponents:cocoon::internal::native<::NSDateComponents>(components)]);
    }

    std::string DateComponentsFormatter::string_from_time_interval(double ti) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDateComponentsFormatter>(this) stringFromTimeInterval:static_cast<::NSTimeInterval>(ti)]);
    }

    CalendarUnit DateComponentsFormatter::allowed_units() const
    {
        return static_cast<CalendarUnit>([cocoon::internal::ns<::NSDateComponentsFormatter>(this) allowedUnits]);
    }

    void DateComponentsFormatter::set_allowed_units(CalendarUnit value) const
    {
        [cocoon::internal::ns<::NSDateComponentsFormatter>(this) setAllowedUnits:static_cast<::NSCalendarUnit>(value)];
    }

    bool DateComponentsFormatter::allows_fractional_units() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDateComponentsFormatter>(this) allowsFractionalUnits]);
    }

    void DateComponentsFormatter::set_allows_fractional_units(bool value) const
    {
        [cocoon::internal::ns<::NSDateComponentsFormatter>(this) setAllowsFractionalUnits:static_cast<::BOOL>(value)];
    }

    Calendar DateComponentsFormatter::calendar() const
    {
        return cocoon::internal::wrap<Calendar>([cocoon::internal::ns<::NSDateComponentsFormatter>(this) calendar]);
    }

    void DateComponentsFormatter::set_calendar(const Calendar& value) const
    {
        [cocoon::internal::ns<::NSDateComponentsFormatter>(this) setCalendar:cocoon::internal::native<::NSCalendar>(value)];
    }

    bool DateComponentsFormatter::collapses_largest_unit() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDateComponentsFormatter>(this) collapsesLargestUnit]);
    }

    void DateComponentsFormatter::set_collapses_largest_unit(bool value) const
    {
        [cocoon::internal::ns<::NSDateComponentsFormatter>(this) setCollapsesLargestUnit:static_cast<::BOOL>(value)];
    }

    FormattingContext DateComponentsFormatter::formatting_context() const
    {
        return static_cast<FormattingContext>([cocoon::internal::ns<::NSDateComponentsFormatter>(this) formattingContext]);
    }

    void DateComponentsFormatter::set_formatting_context(FormattingContext value) const
    {
        [cocoon::internal::ns<::NSDateComponentsFormatter>(this) setFormattingContext:static_cast<::NSFormattingContext>(value)];
    }

    bool DateComponentsFormatter::includes_approximation_phrase() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDateComponentsFormatter>(this) includesApproximationPhrase]);
    }

    void DateComponentsFormatter::set_includes_approximation_phrase(bool value) const
    {
        [cocoon::internal::ns<::NSDateComponentsFormatter>(this) setIncludesApproximationPhrase:static_cast<::BOOL>(value)];
    }

    bool DateComponentsFormatter::includes_time_remaining_phrase() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDateComponentsFormatter>(this) includesTimeRemainingPhrase]);
    }

    void DateComponentsFormatter::set_includes_time_remaining_phrase(bool value) const
    {
        [cocoon::internal::ns<::NSDateComponentsFormatter>(this) setIncludesTimeRemainingPhrase:static_cast<::BOOL>(value)];
    }

    std::int64_t DateComponentsFormatter::maximum_unit_count() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDateComponentsFormatter>(this) maximumUnitCount]);
    }

    void DateComponentsFormatter::set_maximum_unit_count(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSDateComponentsFormatter>(this) setMaximumUnitCount:static_cast<::NSInteger>(value)];
    }

    Date DateComponentsFormatter::reference_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDateComponentsFormatter>(this) referenceDate]);
    }

    void DateComponentsFormatter::set_reference_date(const Date& value) const
    {
        [cocoon::internal::ns<::NSDateComponentsFormatter>(this) setReferenceDate:cocoon::internal::native<::NSDate>(value)];
    }

    DateComponentsFormatterUnitsStyle DateComponentsFormatter::units_style() const
    {
        return static_cast<DateComponentsFormatterUnitsStyle>([cocoon::internal::ns<::NSDateComponentsFormatter>(this) unitsStyle]);
    }

    void DateComponentsFormatter::set_units_style(DateComponentsFormatterUnitsStyle value) const
    {
        [cocoon::internal::ns<::NSDateComponentsFormatter>(this) setUnitsStyle:static_cast<::NSDateComponentsFormatterUnitsStyle>(value)];
    }

    DateComponentsFormatterZeroFormattingBehavior DateComponentsFormatter::zero_formatting_behavior() const
    {
        return static_cast<DateComponentsFormatterZeroFormattingBehavior>([cocoon::internal::ns<::NSDateComponentsFormatter>(this) zeroFormattingBehavior]);
    }

    void DateComponentsFormatter::set_zero_formatting_behavior(DateComponentsFormatterZeroFormattingBehavior value) const
    {
        [cocoon::internal::ns<::NSDateComponentsFormatter>(this) setZeroFormattingBehavior:static_cast<::NSDateComponentsFormatterZeroFormattingBehavior>(value)];
    }
}
