#include "generated/number.h"
#include "internal.h"

namespace cocoon
{
    Number::Number(bool value) : Number(Adopt{cocoon::internal::retain([[::NSNumber alloc] initWithBool:static_cast<::BOOL>(value)])})
    {
    }

    Number::Number(std::int8_t value) : Number(Adopt{cocoon::internal::retain([[::NSNumber alloc] initWithChar:static_cast<char>(value)])})
    {
    }

    Number::Number(double value) : Number(Adopt{cocoon::internal::retain([[::NSNumber alloc] initWithDouble:static_cast<double>(value)])})
    {
    }

    Number::Number(float value) : Number(Adopt{cocoon::internal::retain([[::NSNumber alloc] initWithFloat:static_cast<float>(value)])})
    {
    }

    Number::Number(int value) : Number(Adopt{cocoon::internal::retain([[::NSNumber alloc] initWithInt:static_cast<int>(value)])})
    {
    }

    Number::Number(std::int64_t value) : Number(Adopt{cocoon::internal::retain([[::NSNumber alloc] initWithInteger:static_cast<::NSInteger>(value)])})
    {
    }

    Number::Number(std::int16_t value) : Number(Adopt{cocoon::internal::retain([[::NSNumber alloc] initWithShort:static_cast<short>(value)])})
    {
    }

    Number::Number(std::uint8_t value) : Number(Adopt{cocoon::internal::retain([[::NSNumber alloc] initWithUnsignedChar:static_cast<unsigned char>(value)])})
    {
    }

    Number::Number(unsigned int value) : Number(Adopt{cocoon::internal::retain([[::NSNumber alloc] initWithUnsignedInt:static_cast<unsigned int>(value)])})
    {
    }

    Number::Number(std::uint64_t value) : Number(Adopt{cocoon::internal::retain([[::NSNumber alloc] initWithUnsignedInteger:static_cast<::NSUInteger>(value)])})
    {
    }

    Number::Number(std::uint16_t value) : Number(Adopt{cocoon::internal::retain([[::NSNumber alloc] initWithUnsignedShort:static_cast<unsigned short>(value)])})
    {
    }

    Number::Number() : Number(Adopt{cocoon::internal::retain([[::NSNumber alloc] init])})
    {
    }

    Number::Number(std::nullptr_t) : Value(nullptr)
    {
    }

    Number::Number(Adopt adopt) : Value(adopt)
    {
    }

    ComparisonResult Number::compare(const Number& other_number) const
    {
        return static_cast<ComparisonResult>([cocoon::internal::ns<::NSNumber>(this) compare:cocoon::internal::native<::NSNumber>(other_number)]);
    }

    std::string Number::description_with_locale(const Object& locale) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumber>(this) descriptionWithLocale:cocoon::internal::native_id(locale)]);
    }

    bool Number::is_equal_to_number(const Number& number) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSNumber>(this) isEqualToNumber:cocoon::internal::native<::NSNumber>(number)]);
    }

    bool Number::bool_value() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSNumber>(this) boolValue]);
    }

    std::int8_t Number::char_value() const
    {
        return static_cast<std::int8_t>([cocoon::internal::ns<::NSNumber>(this) charValue]);
    }

    Decimal Number::decimal_value() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumber>(this) decimalValue]);
    }

    double Number::double_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSNumber>(this) doubleValue]);
    }

    float Number::float_value() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSNumber>(this) floatValue]);
    }

    int Number::int_value() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSNumber>(this) intValue]);
    }

    std::int64_t Number::integer_value() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSNumber>(this) integerValue]);
    }

    std::int64_t Number::long_long_value() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSNumber>(this) longLongValue]);
    }

    std::int64_t Number::long_value() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSNumber>(this) longValue]);
    }

    std::int16_t Number::short_value() const
    {
        return static_cast<std::int16_t>([cocoon::internal::ns<::NSNumber>(this) shortValue]);
    }

    std::string Number::string_value() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumber>(this) stringValue]);
    }

    std::uint8_t Number::unsigned_char_value() const
    {
        return static_cast<std::uint8_t>([cocoon::internal::ns<::NSNumber>(this) unsignedCharValue]);
    }

    unsigned int Number::unsigned_int_value() const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSNumber>(this) unsignedIntValue]);
    }

    std::uint64_t Number::unsigned_integer_value() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSNumber>(this) unsignedIntegerValue]);
    }

    std::uint64_t Number::unsigned_long_long_value() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSNumber>(this) unsignedLongLongValue]);
    }

    std::uint64_t Number::unsigned_long_value() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSNumber>(this) unsignedLongValue]);
    }

    std::uint16_t Number::unsigned_short_value() const
    {
        return static_cast<std::uint16_t>([cocoon::internal::ns<::NSNumber>(this) unsignedShortValue]);
    }
}
