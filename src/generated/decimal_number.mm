#include "generated/decimal_number.h"
#include "internal.h"

namespace cocoon
{
    DecimalNumber::DecimalNumber(const Decimal& dcm) : DecimalNumber(Adopt{cocoon::internal::retain([[::NSDecimalNumber alloc] initWithDecimal:cocoon::internal::to(dcm)])})
    {
    }

    DecimalNumber::DecimalNumber(std::uint64_t mantissa, std::int16_t exponent, bool flag) : DecimalNumber(Adopt{cocoon::internal::retain([[::NSDecimalNumber alloc] initWithMantissa:static_cast<unsigned long long>(mantissa) exponent:static_cast<short>(exponent) isNegative:static_cast<::BOOL>(flag)])})
    {
    }

    DecimalNumber::DecimalNumber(const std::string& number_value) : DecimalNumber(Adopt{cocoon::internal::retain([[::NSDecimalNumber alloc] initWithString:cocoon::internal::to(number_value)])})
    {
    }

    DecimalNumber::DecimalNumber(const std::string& number_value, const Object& locale) : DecimalNumber(Adopt{cocoon::internal::retain([[::NSDecimalNumber alloc] initWithString:cocoon::internal::to(number_value) locale:cocoon::internal::native_id(locale)])})
    {
    }

    DecimalNumber::DecimalNumber() : DecimalNumber(Adopt{cocoon::internal::retain([[::NSDecimalNumber alloc] init])})
    {
    }

    DecimalNumber::DecimalNumber(std::nullptr_t) : Number(nullptr)
    {
    }

    DecimalNumber::DecimalNumber(Adopt adopt) : Number(adopt)
    {
    }

    ComparisonResult DecimalNumber::compare(const Number& decimal_number) const
    {
        return static_cast<ComparisonResult>([cocoon::internal::ns<::NSDecimalNumber>(this) compare:cocoon::internal::native<::NSNumber>(decimal_number)]);
    }

    DecimalNumber DecimalNumber::decimal_number_by_adding(const DecimalNumber& decimal_number) const
    {
        return cocoon::internal::wrap<DecimalNumber>([cocoon::internal::ns<::NSDecimalNumber>(this) decimalNumberByAdding:cocoon::internal::native<::NSDecimalNumber>(decimal_number)]);
    }

    DecimalNumber DecimalNumber::decimal_number_by_adding(const DecimalNumber& decimal_number, const Object& behavior) const
    {
        return cocoon::internal::wrap<DecimalNumber>([cocoon::internal::ns<::NSDecimalNumber>(this) decimalNumberByAdding:cocoon::internal::native<::NSDecimalNumber>(decimal_number) withBehavior:cocoon::internal::native_id(behavior)]);
    }

    DecimalNumber DecimalNumber::decimal_number_by_dividing_by(const DecimalNumber& decimal_number) const
    {
        return cocoon::internal::wrap<DecimalNumber>([cocoon::internal::ns<::NSDecimalNumber>(this) decimalNumberByDividingBy:cocoon::internal::native<::NSDecimalNumber>(decimal_number)]);
    }

    DecimalNumber DecimalNumber::decimal_number_by_dividing_by(const DecimalNumber& decimal_number, const Object& behavior) const
    {
        return cocoon::internal::wrap<DecimalNumber>([cocoon::internal::ns<::NSDecimalNumber>(this) decimalNumberByDividingBy:cocoon::internal::native<::NSDecimalNumber>(decimal_number) withBehavior:cocoon::internal::native_id(behavior)]);
    }

    DecimalNumber DecimalNumber::decimal_number_by_multiplying_by(const DecimalNumber& decimal_number) const
    {
        return cocoon::internal::wrap<DecimalNumber>([cocoon::internal::ns<::NSDecimalNumber>(this) decimalNumberByMultiplyingBy:cocoon::internal::native<::NSDecimalNumber>(decimal_number)]);
    }

    DecimalNumber DecimalNumber::decimal_number_by_multiplying_by(const DecimalNumber& decimal_number, const Object& behavior) const
    {
        return cocoon::internal::wrap<DecimalNumber>([cocoon::internal::ns<::NSDecimalNumber>(this) decimalNumberByMultiplyingBy:cocoon::internal::native<::NSDecimalNumber>(decimal_number) withBehavior:cocoon::internal::native_id(behavior)]);
    }

    DecimalNumber DecimalNumber::decimal_number_by_multiplying_by_power_of10(std::int16_t power) const
    {
        return cocoon::internal::wrap<DecimalNumber>([cocoon::internal::ns<::NSDecimalNumber>(this) decimalNumberByMultiplyingByPowerOf10:static_cast<short>(power)]);
    }

    DecimalNumber DecimalNumber::decimal_number_by_multiplying_by_power_of10(std::int16_t power, const Object& behavior) const
    {
        return cocoon::internal::wrap<DecimalNumber>([cocoon::internal::ns<::NSDecimalNumber>(this) decimalNumberByMultiplyingByPowerOf10:static_cast<short>(power) withBehavior:cocoon::internal::native_id(behavior)]);
    }

    DecimalNumber DecimalNumber::decimal_number_by_raising_to_power(std::uint64_t power) const
    {
        return cocoon::internal::wrap<DecimalNumber>([cocoon::internal::ns<::NSDecimalNumber>(this) decimalNumberByRaisingToPower:static_cast<::NSUInteger>(power)]);
    }

    DecimalNumber DecimalNumber::decimal_number_by_raising_to_power(std::uint64_t power, const Object& behavior) const
    {
        return cocoon::internal::wrap<DecimalNumber>([cocoon::internal::ns<::NSDecimalNumber>(this) decimalNumberByRaisingToPower:static_cast<::NSUInteger>(power) withBehavior:cocoon::internal::native_id(behavior)]);
    }

    DecimalNumber DecimalNumber::decimal_number_by_rounding_according_to_behavior(const Object& behavior) const
    {
        return cocoon::internal::wrap<DecimalNumber>([cocoon::internal::ns<::NSDecimalNumber>(this) decimalNumberByRoundingAccordingToBehavior:cocoon::internal::native_id(behavior)]);
    }

    DecimalNumber DecimalNumber::decimal_number_by_subtracting(const DecimalNumber& decimal_number) const
    {
        return cocoon::internal::wrap<DecimalNumber>([cocoon::internal::ns<::NSDecimalNumber>(this) decimalNumberBySubtracting:cocoon::internal::native<::NSDecimalNumber>(decimal_number)]);
    }

    DecimalNumber DecimalNumber::decimal_number_by_subtracting(const DecimalNumber& decimal_number, const Object& behavior) const
    {
        return cocoon::internal::wrap<DecimalNumber>([cocoon::internal::ns<::NSDecimalNumber>(this) decimalNumberBySubtracting:cocoon::internal::native<::NSDecimalNumber>(decimal_number) withBehavior:cocoon::internal::native_id(behavior)]);
    }

    DecimalNumber DecimalNumber::decimal_number_with_decimal(const Decimal& dcm)
    {
        return cocoon::internal::wrap<DecimalNumber>([::NSDecimalNumber decimalNumberWithDecimal:cocoon::internal::to(dcm)]);
    }

    DecimalNumber DecimalNumber::decimal_number_with_mantissa(std::uint64_t mantissa, std::int16_t exponent, bool flag)
    {
        return cocoon::internal::wrap<DecimalNumber>([::NSDecimalNumber decimalNumberWithMantissa:static_cast<unsigned long long>(mantissa) exponent:static_cast<short>(exponent) isNegative:static_cast<::BOOL>(flag)]);
    }

    DecimalNumber DecimalNumber::decimal_number_with_string(const std::string& number_value)
    {
        return cocoon::internal::wrap<DecimalNumber>([::NSDecimalNumber decimalNumberWithString:cocoon::internal::to(number_value)]);
    }

    DecimalNumber DecimalNumber::decimal_number_with_string(const std::string& number_value, const Object& locale)
    {
        return cocoon::internal::wrap<DecimalNumber>([::NSDecimalNumber decimalNumberWithString:cocoon::internal::to(number_value) locale:cocoon::internal::native_id(locale)]);
    }

    std::string DecimalNumber::description_with_locale(const Object& locale) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDecimalNumber>(this) descriptionWithLocale:cocoon::internal::native_id(locale)]);
    }

    Decimal DecimalNumber::decimal_value() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDecimalNumber>(this) decimalValue]);
    }

    Object DecimalNumber::default_behavior()
    {
        return cocoon::internal::wrap<Object>([::NSDecimalNumber defaultBehavior]);
    }

    void DecimalNumber::set_default_behavior(const Object& value)
    {
        [::NSDecimalNumber setDefaultBehavior:cocoon::internal::native_id(value)];
    }

    double DecimalNumber::double_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSDecimalNumber>(this) doubleValue]);
    }

    DecimalNumber DecimalNumber::maximum_decimal_number()
    {
        return cocoon::internal::wrap<DecimalNumber>([::NSDecimalNumber maximumDecimalNumber]);
    }

    DecimalNumber DecimalNumber::minimum_decimal_number()
    {
        return cocoon::internal::wrap<DecimalNumber>([::NSDecimalNumber minimumDecimalNumber]);
    }

    DecimalNumber DecimalNumber::not_a_number()
    {
        return cocoon::internal::wrap<DecimalNumber>([::NSDecimalNumber notANumber]);
    }

    std::string DecimalNumber::obj_c_type() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDecimalNumber>(this) objCType]);
    }

    DecimalNumber DecimalNumber::one()
    {
        return cocoon::internal::wrap<DecimalNumber>([::NSDecimalNumber one]);
    }

    DecimalNumber DecimalNumber::zero()
    {
        return cocoon::internal::wrap<DecimalNumber>([::NSDecimalNumber zero]);
    }
}
