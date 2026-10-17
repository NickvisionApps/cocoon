#include "generated/date_picker.h"
#include "internal.h"

@interface AKDatePickerDelegate : NSObject <NSDatePickerCellDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKDatePickerDelegate

- (void)datePickerCell:(NSDatePickerCell*)datePickerCell validateProposedDateValue:(NSDate**)proposedDateValue timeInterval:(NSTimeInterval*)proposedTimeInterval
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Date __v_proposedDateValue = proposedDateValue ? cocoon::internal::wrap<cocoon::Date>(*proposedDateValue) : cocoon::Date();
    cocoon::Signal<cocoon::DatePicker, void(cocoon::Date&, double*)>::emit((__bridge void*)strongHost, "validate_proposed_date_value_time_interval", __v_proposedDateValue, (double*)(proposedTimeInterval));
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
        return strongHost && cocoon::Signal<cocoon::DatePicker, void(cocoon::Date&, double*)>::connected((__bridge void*)strongHost, "validate_proposed_date_value_time_interval");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    DatePicker::DatePicker() : DatePicker(Adopt{cocoon::internal::retain([[NSDatePicker alloc] init])})
    {
        DatePicker::bind_action_(handle());
        DatePicker::install_delegate_delegate_(handle());
    }

    DatePicker::DatePicker(std::nullptr_t) : Control(nullptr)
    {
    }

    DatePicker::DatePicker(Adopt adopt) : Control(adopt)
    {
    }

    Color DatePicker::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSDatePicker>(this) backgroundColor]);
    }

    void DatePicker::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSDatePicker>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    bool DatePicker::is_bezeled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDatePicker>(this) isBezeled]);
    }

    void DatePicker::set_bezeled(bool value) const
    {
        [cocoon::internal::ns<::NSDatePicker>(this) setBezeled:static_cast<::BOOL>(value)];
    }

    bool DatePicker::is_bordered() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDatePicker>(this) isBordered]);
    }

    void DatePicker::set_bordered(bool value) const
    {
        [cocoon::internal::ns<::NSDatePicker>(this) setBordered:static_cast<::BOOL>(value)];
    }

    Calendar DatePicker::calendar() const
    {
        return cocoon::internal::wrap<Calendar>([cocoon::internal::ns<::NSDatePicker>(this) calendar]);
    }

    void DatePicker::set_calendar(const Calendar& value) const
    {
        [cocoon::internal::ns<::NSDatePicker>(this) setCalendar:cocoon::internal::native<::NSCalendar>(value)];
    }

    DatePickerElementFlags DatePicker::date_picker_elements() const
    {
        return static_cast<DatePickerElementFlags>([cocoon::internal::ns<::NSDatePicker>(this) datePickerElements]);
    }

    void DatePicker::set_date_picker_elements(DatePickerElementFlags value) const
    {
        [cocoon::internal::ns<::NSDatePicker>(this) setDatePickerElements:static_cast<::NSDatePickerElementFlags>(value)];
    }

    DatePickerMode DatePicker::date_picker_mode() const
    {
        return static_cast<DatePickerMode>([cocoon::internal::ns<::NSDatePicker>(this) datePickerMode]);
    }

    void DatePicker::set_date_picker_mode(DatePickerMode value) const
    {
        [cocoon::internal::ns<::NSDatePicker>(this) setDatePickerMode:static_cast<::NSDatePickerMode>(value)];
    }

    DatePickerStyle DatePicker::date_picker_style() const
    {
        return static_cast<DatePickerStyle>([cocoon::internal::ns<::NSDatePicker>(this) datePickerStyle]);
    }

    void DatePicker::set_date_picker_style(DatePickerStyle value) const
    {
        [cocoon::internal::ns<::NSDatePicker>(this) setDatePickerStyle:static_cast<::NSDatePickerStyle>(value)];
    }

    Date DatePicker::date_value() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDatePicker>(this) dateValue]);
    }

    void DatePicker::set_date_value(const Date& value) const
    {
        [cocoon::internal::ns<::NSDatePicker>(this) setDateValue:cocoon::internal::native<::NSDate>(value)];
    }

    bool DatePicker::draws_background() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDatePicker>(this) drawsBackground]);
    }

    void DatePicker::set_draws_background(bool value) const
    {
        [cocoon::internal::ns<::NSDatePicker>(this) setDrawsBackground:static_cast<::BOOL>(value)];
    }

    Locale DatePicker::locale() const
    {
        return cocoon::internal::wrap<Locale>([cocoon::internal::ns<::NSDatePicker>(this) locale]);
    }

    void DatePicker::set_locale(const Locale& value) const
    {
        [cocoon::internal::ns<::NSDatePicker>(this) setLocale:cocoon::internal::native<::NSLocale>(value)];
    }

    Date DatePicker::max_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDatePicker>(this) maxDate]);
    }

    void DatePicker::set_max_date(const Date& value) const
    {
        [cocoon::internal::ns<::NSDatePicker>(this) setMaxDate:cocoon::internal::native<::NSDate>(value)];
    }

    Date DatePicker::min_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDatePicker>(this) minDate]);
    }

    void DatePicker::set_min_date(const Date& value) const
    {
        [cocoon::internal::ns<::NSDatePicker>(this) setMinDate:cocoon::internal::native<::NSDate>(value)];
    }

    bool DatePicker::presents_calendar_overlay() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDatePicker>(this) presentsCalendarOverlay]);
    }

    void DatePicker::set_presents_calendar_overlay(bool value) const
    {
        [cocoon::internal::ns<::NSDatePicker>(this) setPresentsCalendarOverlay:static_cast<::BOOL>(value)];
    }

    Color DatePicker::text_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSDatePicker>(this) textColor]);
    }

    void DatePicker::set_text_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSDatePicker>(this) setTextColor:cocoon::internal::native<::NSColor>(value)];
    }

    double DatePicker::time_interval() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSDatePicker>(this) timeInterval]);
    }

    void DatePicker::set_time_interval(double value) const
    {
        [cocoon::internal::ns<::NSDatePicker>(this) setTimeInterval:static_cast<::NSTimeInterval>(value)];
    }

    TimeZone DatePicker::time_zone() const
    {
        return cocoon::internal::wrap<TimeZone>([cocoon::internal::ns<::NSDatePicker>(this) timeZone]);
    }

    void DatePicker::set_time_zone(const TimeZone& value) const
    {
        [cocoon::internal::ns<::NSDatePicker>(this) setTimeZone:cocoon::internal::native<::NSTimeZone>(value)];
    }

    double DatePicker::timestamp() const
    {
        return cocoon::internal::ns<NSDatePicker>(this).dateValue.timeIntervalSince1970;
    }

    void DatePicker::set_timestamp(double seconds) const
    {
        cocoon::internal::ns<NSDatePicker>(this).dateValue = [NSDate dateWithTimeIntervalSince1970:seconds];
    }

    void DatePicker::bind_action_(void* native)
    {
        id host = (__bridge id)native;
        cocoon::internal::bind_action(host, host, [](id host, id sender)
                        {
                            cocoon::Signal<cocoon::DatePicker, void(double)>::emit((__bridge void*)host, "date_changed", ((NSDatePicker*)sender).dateValue.timeIntervalSince1970);
                        });
    }

    void DatePicker::install_delegate_delegate_(void* native)
    {
        ::NSDatePicker* host = (__bridge ::NSDatePicker*)native;
        AKDatePickerDelegate* delegate = [[AKDatePickerDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSDatePicker* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSDatePicker* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
