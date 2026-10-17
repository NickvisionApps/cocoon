#include "generated/relative_date_time_formatter.h"
#include "internal.h"

namespace cocoon
{
    RelativeDateTimeFormatter::RelativeDateTimeFormatter() : RelativeDateTimeFormatter(Adopt{cocoon::internal::retain([[::NSRelativeDateTimeFormatter alloc] init])})
    {
    }

    RelativeDateTimeFormatter::RelativeDateTimeFormatter(std::nullptr_t) : Formatter(nullptr)
    {
    }

    RelativeDateTimeFormatter::RelativeDateTimeFormatter(Adopt adopt) : Formatter(adopt)
    {
    }

    std::string RelativeDateTimeFormatter::localized_string_for_date(const Date& date, const Date& reference_date) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRelativeDateTimeFormatter>(this) localizedStringForDate:cocoon::internal::native<::NSDate>(date) relativeToDate:cocoon::internal::native<::NSDate>(reference_date)]);
    }

    std::string RelativeDateTimeFormatter::localized_string_from_date_components(const DateComponents& date_components) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRelativeDateTimeFormatter>(this) localizedStringFromDateComponents:cocoon::internal::native<::NSDateComponents>(date_components)]);
    }

    std::string RelativeDateTimeFormatter::localized_string_from_time_interval(double time_interval) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRelativeDateTimeFormatter>(this) localizedStringFromTimeInterval:static_cast<::NSTimeInterval>(time_interval)]);
    }

    std::string RelativeDateTimeFormatter::string_for_object_value(const Object& obj) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRelativeDateTimeFormatter>(this) stringForObjectValue:cocoon::internal::native_id(obj)]);
    }

    Calendar RelativeDateTimeFormatter::calendar() const
    {
        return cocoon::internal::wrap<Calendar>([cocoon::internal::ns<::NSRelativeDateTimeFormatter>(this) calendar]);
    }

    void RelativeDateTimeFormatter::set_calendar(const Calendar& value) const
    {
        [cocoon::internal::ns<::NSRelativeDateTimeFormatter>(this) setCalendar:cocoon::internal::native<::NSCalendar>(value)];
    }

    RelativeDateTimeFormatterStyle RelativeDateTimeFormatter::date_time_style() const
    {
        return static_cast<RelativeDateTimeFormatterStyle>([cocoon::internal::ns<::NSRelativeDateTimeFormatter>(this) dateTimeStyle]);
    }

    void RelativeDateTimeFormatter::set_date_time_style(RelativeDateTimeFormatterStyle value) const
    {
        [cocoon::internal::ns<::NSRelativeDateTimeFormatter>(this) setDateTimeStyle:static_cast<::NSRelativeDateTimeFormatterStyle>(value)];
    }

    FormattingContext RelativeDateTimeFormatter::formatting_context() const
    {
        return static_cast<FormattingContext>([cocoon::internal::ns<::NSRelativeDateTimeFormatter>(this) formattingContext]);
    }

    void RelativeDateTimeFormatter::set_formatting_context(FormattingContext value) const
    {
        [cocoon::internal::ns<::NSRelativeDateTimeFormatter>(this) setFormattingContext:static_cast<::NSFormattingContext>(value)];
    }

    Locale RelativeDateTimeFormatter::locale() const
    {
        return cocoon::internal::wrap<Locale>([cocoon::internal::ns<::NSRelativeDateTimeFormatter>(this) locale]);
    }

    void RelativeDateTimeFormatter::set_locale(const Locale& value) const
    {
        [cocoon::internal::ns<::NSRelativeDateTimeFormatter>(this) setLocale:cocoon::internal::native<::NSLocale>(value)];
    }

    RelativeDateTimeFormatterUnitsStyle RelativeDateTimeFormatter::units_style() const
    {
        return static_cast<RelativeDateTimeFormatterUnitsStyle>([cocoon::internal::ns<::NSRelativeDateTimeFormatter>(this) unitsStyle]);
    }

    void RelativeDateTimeFormatter::set_units_style(RelativeDateTimeFormatterUnitsStyle value) const
    {
        [cocoon::internal::ns<::NSRelativeDateTimeFormatter>(this) setUnitsStyle:static_cast<::NSRelativeDateTimeFormatterUnitsStyle>(value)];
    }
}
