#include "generated/byte_count_formatter.h"
#include "internal.h"

namespace cocoon
{
    ByteCountFormatter::ByteCountFormatter() : ByteCountFormatter(Adopt{cocoon::internal::retain([[::NSByteCountFormatter alloc] init])})
    {
    }

    ByteCountFormatter::ByteCountFormatter(std::nullptr_t) : Formatter(nullptr)
    {
    }

    ByteCountFormatter::ByteCountFormatter(Adopt adopt) : Formatter(adopt)
    {
    }

    std::string ByteCountFormatter::string_for_object_value(const Object& obj) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSByteCountFormatter>(this) stringForObjectValue:cocoon::internal::native_id(obj)]);
    }

    std::string ByteCountFormatter::string_from_byte_count(std::int64_t byte_count) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSByteCountFormatter>(this) stringFromByteCount:static_cast<long long>(byte_count)]);
    }

    std::string ByteCountFormatter::string_from_byte_count(std::int64_t byte_count, ByteCountFormatterCountStyle count_style)
    {
        return cocoon::internal::from([::NSByteCountFormatter stringFromByteCount:static_cast<long long>(byte_count) countStyle:static_cast<::NSByteCountFormatterCountStyle>(count_style)]);
    }

    std::string ByteCountFormatter::string_from_measurement(const MeasurementBase& measurement) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSByteCountFormatter>(this) stringFromMeasurement:cocoon::internal::native<::NSMeasurement>(measurement)]);
    }

    std::string ByteCountFormatter::string_from_measurement(const MeasurementBase& measurement, ByteCountFormatterCountStyle count_style)
    {
        return cocoon::internal::from([::NSByteCountFormatter stringFromMeasurement:cocoon::internal::native<::NSMeasurement>(measurement) countStyle:static_cast<::NSByteCountFormatterCountStyle>(count_style)]);
    }

    bool ByteCountFormatter::is_adaptive() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSByteCountFormatter>(this) isAdaptive]);
    }

    void ByteCountFormatter::set_adaptive(bool value) const
    {
        [cocoon::internal::ns<::NSByteCountFormatter>(this) setAdaptive:static_cast<::BOOL>(value)];
    }

    ByteCountFormatterUnits ByteCountFormatter::allowed_units() const
    {
        return static_cast<ByteCountFormatterUnits>([cocoon::internal::ns<::NSByteCountFormatter>(this) allowedUnits]);
    }

    void ByteCountFormatter::set_allowed_units(ByteCountFormatterUnits value) const
    {
        [cocoon::internal::ns<::NSByteCountFormatter>(this) setAllowedUnits:static_cast<::NSByteCountFormatterUnits>(value)];
    }

    bool ByteCountFormatter::allows_nonnumeric_formatting() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSByteCountFormatter>(this) allowsNonnumericFormatting]);
    }

    void ByteCountFormatter::set_allows_nonnumeric_formatting(bool value) const
    {
        [cocoon::internal::ns<::NSByteCountFormatter>(this) setAllowsNonnumericFormatting:static_cast<::BOOL>(value)];
    }

    ByteCountFormatterCountStyle ByteCountFormatter::count_style() const
    {
        return static_cast<ByteCountFormatterCountStyle>([cocoon::internal::ns<::NSByteCountFormatter>(this) countStyle]);
    }

    void ByteCountFormatter::set_count_style(ByteCountFormatterCountStyle value) const
    {
        [cocoon::internal::ns<::NSByteCountFormatter>(this) setCountStyle:static_cast<::NSByteCountFormatterCountStyle>(value)];
    }

    FormattingContext ByteCountFormatter::formatting_context() const
    {
        return static_cast<FormattingContext>([cocoon::internal::ns<::NSByteCountFormatter>(this) formattingContext]);
    }

    void ByteCountFormatter::set_formatting_context(FormattingContext value) const
    {
        [cocoon::internal::ns<::NSByteCountFormatter>(this) setFormattingContext:static_cast<::NSFormattingContext>(value)];
    }

    bool ByteCountFormatter::includes_actual_byte_count() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSByteCountFormatter>(this) includesActualByteCount]);
    }

    void ByteCountFormatter::set_includes_actual_byte_count(bool value) const
    {
        [cocoon::internal::ns<::NSByteCountFormatter>(this) setIncludesActualByteCount:static_cast<::BOOL>(value)];
    }

    bool ByteCountFormatter::includes_count() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSByteCountFormatter>(this) includesCount]);
    }

    void ByteCountFormatter::set_includes_count(bool value) const
    {
        [cocoon::internal::ns<::NSByteCountFormatter>(this) setIncludesCount:static_cast<::BOOL>(value)];
    }

    bool ByteCountFormatter::includes_unit() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSByteCountFormatter>(this) includesUnit]);
    }

    void ByteCountFormatter::set_includes_unit(bool value) const
    {
        [cocoon::internal::ns<::NSByteCountFormatter>(this) setIncludesUnit:static_cast<::BOOL>(value)];
    }

    bool ByteCountFormatter::zero_pads_fraction_digits() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSByteCountFormatter>(this) zeroPadsFractionDigits]);
    }

    void ByteCountFormatter::set_zero_pads_fraction_digits(bool value) const
    {
        [cocoon::internal::ns<::NSByteCountFormatter>(this) setZeroPadsFractionDigits:static_cast<::BOOL>(value)];
    }
}
