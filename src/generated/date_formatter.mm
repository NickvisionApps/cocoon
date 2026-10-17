#include "generated/date_formatter.h"
#include "internal.h"

namespace cocoon
{
    DateFormatter::DateFormatter() : DateFormatter(Adopt{cocoon::internal::retain([[::NSDateFormatter alloc] init])})
    {
    }

    DateFormatter::DateFormatter(std::nullptr_t) : Formatter(nullptr)
    {
    }

    DateFormatter::DateFormatter(Adopt adopt) : Formatter(adopt)
    {
    }

    std::string DateFormatter::date_format_from_template(const std::string& tmplate, std::uint64_t opts, const Locale& locale)
    {
        return cocoon::internal::from([::NSDateFormatter dateFormatFromTemplate:cocoon::internal::to(tmplate) options:static_cast<::NSUInteger>(opts) locale:cocoon::internal::native<::NSLocale>(locale)]);
    }

    Date DateFormatter::date_from_string(const std::string& string) const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDateFormatter>(this) dateFromString:cocoon::internal::to(string)]);
    }

    std::string DateFormatter::localized_string_from_date(const Date& date, DateFormatterStyle dstyle, DateFormatterStyle tstyle)
    {
        return cocoon::internal::from([::NSDateFormatter localizedStringFromDate:cocoon::internal::native<::NSDate>(date) dateStyle:static_cast<::NSDateFormatterStyle>(dstyle) timeStyle:static_cast<::NSDateFormatterStyle>(tstyle)]);
    }

    void DateFormatter::set_localized_date_format_from_template(const std::string& date_format_template) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setLocalizedDateFormatFromTemplate:cocoon::internal::to(date_format_template)];
    }

    std::string DateFormatter::string_from_date(const Date& date) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDateFormatter>(this) stringFromDate:cocoon::internal::native<::NSDate>(date)]);
    }

    std::string DateFormatter::am_symbol() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDateFormatter>(this) AMSymbol]);
    }

    void DateFormatter::set_am_symbol(const std::string& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setAMSymbol:cocoon::internal::to(value)];
    }

    std::string DateFormatter::pm_symbol() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDateFormatter>(this) PMSymbol]);
    }

    void DateFormatter::set_pm_symbol(const std::string& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setPMSymbol:cocoon::internal::to(value)];
    }

    Calendar DateFormatter::calendar() const
    {
        return cocoon::internal::wrap<Calendar>([cocoon::internal::ns<::NSDateFormatter>(this) calendar]);
    }

    void DateFormatter::set_calendar(const Calendar& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setCalendar:cocoon::internal::native<::NSCalendar>(value)];
    }

    std::string DateFormatter::date_format() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDateFormatter>(this) dateFormat]);
    }

    void DateFormatter::set_date_format(const std::string& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setDateFormat:cocoon::internal::to(value)];
    }

    DateFormatterStyle DateFormatter::date_style() const
    {
        return static_cast<DateFormatterStyle>([cocoon::internal::ns<::NSDateFormatter>(this) dateStyle]);
    }

    void DateFormatter::set_date_style(DateFormatterStyle value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setDateStyle:static_cast<::NSDateFormatterStyle>(value)];
    }

    Date DateFormatter::default_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDateFormatter>(this) defaultDate]);
    }

    void DateFormatter::set_default_date(const Date& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setDefaultDate:cocoon::internal::native<::NSDate>(value)];
    }

    DateFormatterBehavior DateFormatter::default_formatter_behavior()
    {
        return static_cast<DateFormatterBehavior>([::NSDateFormatter defaultFormatterBehavior]);
    }

    void DateFormatter::set_default_formatter_behavior(DateFormatterBehavior value)
    {
        [::NSDateFormatter setDefaultFormatterBehavior:static_cast<::NSDateFormatterBehavior>(value)];
    }

    bool DateFormatter::does_relative_date_formatting() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDateFormatter>(this) doesRelativeDateFormatting]);
    }

    void DateFormatter::set_does_relative_date_formatting(bool value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setDoesRelativeDateFormatting:static_cast<::BOOL>(value)];
    }

    std::vector<std::string> DateFormatter::era_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDateFormatter>(this) eraSymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void DateFormatter::set_era_symbols(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setEraSymbols:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                {
                                                                                                    return cocoon::internal::to(e);
                                                                                                })];
    }

    DateFormatterBehavior DateFormatter::formatter_behavior() const
    {
        return static_cast<DateFormatterBehavior>([cocoon::internal::ns<::NSDateFormatter>(this) formatterBehavior]);
    }

    void DateFormatter::set_formatter_behavior(DateFormatterBehavior value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setFormatterBehavior:static_cast<::NSDateFormatterBehavior>(value)];
    }

    FormattingContext DateFormatter::formatting_context() const
    {
        return static_cast<FormattingContext>([cocoon::internal::ns<::NSDateFormatter>(this) formattingContext]);
    }

    void DateFormatter::set_formatting_context(FormattingContext value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setFormattingContext:static_cast<::NSFormattingContext>(value)];
    }

    bool DateFormatter::generates_calendar_dates() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDateFormatter>(this) generatesCalendarDates]);
    }

    void DateFormatter::set_generates_calendar_dates(bool value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setGeneratesCalendarDates:static_cast<::BOOL>(value)];
    }

    Date DateFormatter::gregorian_start_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDateFormatter>(this) gregorianStartDate]);
    }

    void DateFormatter::set_gregorian_start_date(const Date& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setGregorianStartDate:cocoon::internal::native<::NSDate>(value)];
    }

    bool DateFormatter::is_lenient() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDateFormatter>(this) isLenient]);
    }

    void DateFormatter::set_lenient(bool value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setLenient:static_cast<::BOOL>(value)];
    }

    Locale DateFormatter::locale() const
    {
        return cocoon::internal::wrap<Locale>([cocoon::internal::ns<::NSDateFormatter>(this) locale]);
    }

    void DateFormatter::set_locale(const Locale& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setLocale:cocoon::internal::native<::NSLocale>(value)];
    }

    std::vector<std::string> DateFormatter::long_era_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDateFormatter>(this) longEraSymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void DateFormatter::set_long_era_symbols(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setLongEraSymbols:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                    {
                                                                                                        return cocoon::internal::to(e);
                                                                                                    })];
    }

    std::vector<std::string> DateFormatter::month_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDateFormatter>(this) monthSymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void DateFormatter::set_month_symbols(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setMonthSymbols:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                  {
                                                                                                      return cocoon::internal::to(e);
                                                                                                  })];
    }

    std::vector<std::string> DateFormatter::quarter_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDateFormatter>(this) quarterSymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void DateFormatter::set_quarter_symbols(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setQuarterSymbols:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                    {
                                                                                                        return cocoon::internal::to(e);
                                                                                                    })];
    }

    std::vector<std::string> DateFormatter::short_month_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDateFormatter>(this) shortMonthSymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void DateFormatter::set_short_month_symbols(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setShortMonthSymbols:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                       {
                                                                                                           return cocoon::internal::to(e);
                                                                                                       })];
    }

    std::vector<std::string> DateFormatter::short_quarter_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDateFormatter>(this) shortQuarterSymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void DateFormatter::set_short_quarter_symbols(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setShortQuarterSymbols:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                         {
                                                                                                             return cocoon::internal::to(e);
                                                                                                         })];
    }

    std::vector<std::string> DateFormatter::short_standalone_month_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDateFormatter>(this) shortStandaloneMonthSymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void DateFormatter::set_short_standalone_month_symbols(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setShortStandaloneMonthSymbols:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                                 {
                                                                                                                     return cocoon::internal::to(e);
                                                                                                                 })];
    }

    std::vector<std::string> DateFormatter::short_standalone_quarter_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDateFormatter>(this) shortStandaloneQuarterSymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void DateFormatter::set_short_standalone_quarter_symbols(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setShortStandaloneQuarterSymbols:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                                   {
                                                                                                                       return cocoon::internal::to(e);
                                                                                                                   })];
    }

    std::vector<std::string> DateFormatter::short_standalone_weekday_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDateFormatter>(this) shortStandaloneWeekdaySymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void DateFormatter::set_short_standalone_weekday_symbols(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setShortStandaloneWeekdaySymbols:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                                   {
                                                                                                                       return cocoon::internal::to(e);
                                                                                                                   })];
    }

    std::vector<std::string> DateFormatter::short_weekday_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDateFormatter>(this) shortWeekdaySymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void DateFormatter::set_short_weekday_symbols(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setShortWeekdaySymbols:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                         {
                                                                                                             return cocoon::internal::to(e);
                                                                                                         })];
    }

    std::vector<std::string> DateFormatter::standalone_month_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDateFormatter>(this) standaloneMonthSymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void DateFormatter::set_standalone_month_symbols(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setStandaloneMonthSymbols:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                            {
                                                                                                                return cocoon::internal::to(e);
                                                                                                            })];
    }

    std::vector<std::string> DateFormatter::standalone_quarter_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDateFormatter>(this) standaloneQuarterSymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void DateFormatter::set_standalone_quarter_symbols(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setStandaloneQuarterSymbols:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                              {
                                                                                                                  return cocoon::internal::to(e);
                                                                                                              })];
    }

    std::vector<std::string> DateFormatter::standalone_weekday_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDateFormatter>(this) standaloneWeekdaySymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void DateFormatter::set_standalone_weekday_symbols(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setStandaloneWeekdaySymbols:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                              {
                                                                                                                  return cocoon::internal::to(e);
                                                                                                              })];
    }

    DateFormatterStyle DateFormatter::time_style() const
    {
        return static_cast<DateFormatterStyle>([cocoon::internal::ns<::NSDateFormatter>(this) timeStyle]);
    }

    void DateFormatter::set_time_style(DateFormatterStyle value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setTimeStyle:static_cast<::NSDateFormatterStyle>(value)];
    }

    TimeZone DateFormatter::time_zone() const
    {
        return cocoon::internal::wrap<TimeZone>([cocoon::internal::ns<::NSDateFormatter>(this) timeZone]);
    }

    void DateFormatter::set_time_zone(const TimeZone& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setTimeZone:cocoon::internal::native<::NSTimeZone>(value)];
    }

    Date DateFormatter::two_digit_start_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDateFormatter>(this) twoDigitStartDate]);
    }

    void DateFormatter::set_two_digit_start_date(const Date& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setTwoDigitStartDate:cocoon::internal::native<::NSDate>(value)];
    }

    std::vector<std::string> DateFormatter::very_short_month_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDateFormatter>(this) veryShortMonthSymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void DateFormatter::set_very_short_month_symbols(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setVeryShortMonthSymbols:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                           {
                                                                                                               return cocoon::internal::to(e);
                                                                                                           })];
    }

    std::vector<std::string> DateFormatter::very_short_standalone_month_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDateFormatter>(this) veryShortStandaloneMonthSymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void DateFormatter::set_very_short_standalone_month_symbols(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setVeryShortStandaloneMonthSymbols:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                                     {
                                                                                                                         return cocoon::internal::to(e);
                                                                                                                     })];
    }

    std::vector<std::string> DateFormatter::very_short_standalone_weekday_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDateFormatter>(this) veryShortStandaloneWeekdaySymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void DateFormatter::set_very_short_standalone_weekday_symbols(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setVeryShortStandaloneWeekdaySymbols:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                                       {
                                                                                                                           return cocoon::internal::to(e);
                                                                                                                       })];
    }

    std::vector<std::string> DateFormatter::very_short_weekday_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDateFormatter>(this) veryShortWeekdaySymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void DateFormatter::set_very_short_weekday_symbols(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setVeryShortWeekdaySymbols:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                             {
                                                                                                                 return cocoon::internal::to(e);
                                                                                                             })];
    }

    std::vector<std::string> DateFormatter::weekday_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDateFormatter>(this) weekdaySymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void DateFormatter::set_weekday_symbols(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSDateFormatter>(this) setWeekdaySymbols:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                    {
                                                                                                        return cocoon::internal::to(e);
                                                                                                    })];
    }
}
