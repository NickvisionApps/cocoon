#include "generated/date_picker_cell.h"
#include "internal.h"

@interface AKDatePickerCellDelegate : NSObject <NSDatePickerCellDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKDatePickerCellDelegate

- (void)datePickerCell:(NSDatePickerCell*)datePickerCell validateProposedDateValue:(NSDate**)proposedDateValue timeInterval:(NSTimeInterval*)proposedTimeInterval
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Date __v_proposedDateValue = proposedDateValue ? cocoon::internal::wrap<cocoon::Date>(*proposedDateValue) : cocoon::Date();
    cocoon::Signal<cocoon::DatePickerCell, void(cocoon::Date&, double*)>::emit((__bridge void*)strongHost, "validate_proposed_date_value_time_interval", __v_proposedDateValue, (double*)(proposedTimeInterval));
    if (proposedDateValue)
    {
        *proposedDateValue = cocoon::internal::native<::NSDate>(__v_proposedDateValue);
    }
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(datePickerCell:validateProposedDateValue:timeInterval:))
    {
        return strongHost && cocoon::Signal<cocoon::DatePickerCell, void(cocoon::Date&, double*)>::connected((__bridge void*)strongHost, "validate_proposed_date_value_time_interval");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    DatePickerCell::DatePickerCell(const std::string& string) : DatePickerCell(Adopt{cocoon::internal::retain([[::NSDatePickerCell alloc] initTextCell:cocoon::internal::to(string)])})
    {
        DatePickerCell::install_delegate_delegate_(handle());
    }

    DatePickerCell::DatePickerCell() : DatePickerCell(Adopt{cocoon::internal::retain([[::NSDatePickerCell alloc] init])})
    {
        DatePickerCell::install_delegate_delegate_(handle());
    }

    DatePickerCell::DatePickerCell(std::nullptr_t) : ActionCell(nullptr)
    {
    }

    DatePickerCell::DatePickerCell(Adopt adopt) : ActionCell(adopt)
    {
    }

    Color DatePickerCell::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSDatePickerCell>(this) backgroundColor]);
    }

    void DatePickerCell::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSDatePickerCell>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    Calendar DatePickerCell::calendar() const
    {
        return cocoon::internal::wrap<Calendar>([cocoon::internal::ns<::NSDatePickerCell>(this) calendar]);
    }

    void DatePickerCell::set_calendar(const Calendar& value) const
    {
        [cocoon::internal::ns<::NSDatePickerCell>(this) setCalendar:cocoon::internal::native<::NSCalendar>(value)];
    }

    DatePickerElementFlags DatePickerCell::date_picker_elements() const
    {
        return static_cast<DatePickerElementFlags>([cocoon::internal::ns<::NSDatePickerCell>(this) datePickerElements]);
    }

    void DatePickerCell::set_date_picker_elements(DatePickerElementFlags value) const
    {
        [cocoon::internal::ns<::NSDatePickerCell>(this) setDatePickerElements:static_cast<::NSDatePickerElementFlags>(value)];
    }

    DatePickerMode DatePickerCell::date_picker_mode() const
    {
        return static_cast<DatePickerMode>([cocoon::internal::ns<::NSDatePickerCell>(this) datePickerMode]);
    }

    void DatePickerCell::set_date_picker_mode(DatePickerMode value) const
    {
        [cocoon::internal::ns<::NSDatePickerCell>(this) setDatePickerMode:static_cast<::NSDatePickerMode>(value)];
    }

    DatePickerStyle DatePickerCell::date_picker_style() const
    {
        return static_cast<DatePickerStyle>([cocoon::internal::ns<::NSDatePickerCell>(this) datePickerStyle]);
    }

    void DatePickerCell::set_date_picker_style(DatePickerStyle value) const
    {
        [cocoon::internal::ns<::NSDatePickerCell>(this) setDatePickerStyle:static_cast<::NSDatePickerStyle>(value)];
    }

    Date DatePickerCell::date_value() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDatePickerCell>(this) dateValue]);
    }

    void DatePickerCell::set_date_value(const Date& value) const
    {
        [cocoon::internal::ns<::NSDatePickerCell>(this) setDateValue:cocoon::internal::native<::NSDate>(value)];
    }

    bool DatePickerCell::draws_background() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDatePickerCell>(this) drawsBackground]);
    }

    void DatePickerCell::set_draws_background(bool value) const
    {
        [cocoon::internal::ns<::NSDatePickerCell>(this) setDrawsBackground:static_cast<::BOOL>(value)];
    }

    Locale DatePickerCell::locale() const
    {
        return cocoon::internal::wrap<Locale>([cocoon::internal::ns<::NSDatePickerCell>(this) locale]);
    }

    void DatePickerCell::set_locale(const Locale& value) const
    {
        [cocoon::internal::ns<::NSDatePickerCell>(this) setLocale:cocoon::internal::native<::NSLocale>(value)];
    }

    Date DatePickerCell::max_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDatePickerCell>(this) maxDate]);
    }

    void DatePickerCell::set_max_date(const Date& value) const
    {
        [cocoon::internal::ns<::NSDatePickerCell>(this) setMaxDate:cocoon::internal::native<::NSDate>(value)];
    }

    Date DatePickerCell::min_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDatePickerCell>(this) minDate]);
    }

    void DatePickerCell::set_min_date(const Date& value) const
    {
        [cocoon::internal::ns<::NSDatePickerCell>(this) setMinDate:cocoon::internal::native<::NSDate>(value)];
    }

    Color DatePickerCell::text_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSDatePickerCell>(this) textColor]);
    }

    void DatePickerCell::set_text_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSDatePickerCell>(this) setTextColor:cocoon::internal::native<::NSColor>(value)];
    }

    double DatePickerCell::time_interval() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSDatePickerCell>(this) timeInterval]);
    }

    void DatePickerCell::set_time_interval(double value) const
    {
        [cocoon::internal::ns<::NSDatePickerCell>(this) setTimeInterval:static_cast<::NSTimeInterval>(value)];
    }

    TimeZone DatePickerCell::time_zone() const
    {
        return cocoon::internal::wrap<TimeZone>([cocoon::internal::ns<::NSDatePickerCell>(this) timeZone]);
    }

    void DatePickerCell::set_time_zone(const TimeZone& value) const
    {
        [cocoon::internal::ns<::NSDatePickerCell>(this) setTimeZone:cocoon::internal::native<::NSTimeZone>(value)];
    }

    void DatePickerCell::install_delegate_delegate_(void* native)
    {
        ::NSDatePickerCell* host = (__bridge ::NSDatePickerCell*)native;
        AKDatePickerCellDelegate* delegate = [[AKDatePickerCellDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSDatePickerCell* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSDatePickerCell* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
