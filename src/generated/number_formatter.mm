#include "generated/number_formatter.h"
#include "internal.h"

namespace cocoon
{
    NumberFormatter::NumberFormatter() : NumberFormatter(Adopt{cocoon::internal::retain([[::NSNumberFormatter alloc] init])})
    {
    }

    NumberFormatter::NumberFormatter(std::nullptr_t) : Formatter(nullptr)
    {
    }

    NumberFormatter::NumberFormatter(Adopt adopt) : Formatter(adopt)
    {
    }

    NumberFormatterBehavior NumberFormatter::default_formatter_behavior()
    {
        return static_cast<NumberFormatterBehavior>([::NSNumberFormatter defaultFormatterBehavior]);
    }

    std::string NumberFormatter::localized_string_from_number(const Number& num, NumberFormatterStyle nstyle)
    {
        return cocoon::internal::from([::NSNumberFormatter localizedStringFromNumber:cocoon::internal::native<::NSNumber>(num) numberStyle:static_cast<::NSNumberFormatterStyle>(nstyle)]);
    }

    Number NumberFormatter::number_from_string(const std::string& string) const
    {
        return cocoon::internal::wrap<Number>([cocoon::internal::ns<::NSNumberFormatter>(this) numberFromString:cocoon::internal::to(string)]);
    }

    void NumberFormatter::set_default_formatter_behavior(NumberFormatterBehavior behavior)
    {
        [::NSNumberFormatter setDefaultFormatterBehavior:static_cast<::NSNumberFormatterBehavior>(behavior)];
    }

    std::string NumberFormatter::string_from_number(const Number& number) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) stringFromNumber:cocoon::internal::native<::NSNumber>(number)]);
    }

    bool NumberFormatter::allows_floats() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSNumberFormatter>(this) allowsFloats]);
    }

    void NumberFormatter::set_allows_floats(bool value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setAllowsFloats:static_cast<::BOOL>(value)];
    }

    bool NumberFormatter::always_shows_decimal_separator() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSNumberFormatter>(this) alwaysShowsDecimalSeparator]);
    }

    void NumberFormatter::set_always_shows_decimal_separator(bool value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setAlwaysShowsDecimalSeparator:static_cast<::BOOL>(value)];
    }

    AttributedString NumberFormatter::attributed_string_for_nil() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSNumberFormatter>(this) attributedStringForNil]);
    }

    void NumberFormatter::set_attributed_string_for_nil(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setAttributedStringForNil:cocoon::internal::native<::NSAttributedString>(value)];
    }

    AttributedString NumberFormatter::attributed_string_for_not_a_number() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSNumberFormatter>(this) attributedStringForNotANumber]);
    }

    void NumberFormatter::set_attributed_string_for_not_a_number(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setAttributedStringForNotANumber:cocoon::internal::native<::NSAttributedString>(value)];
    }

    AttributedString NumberFormatter::attributed_string_for_zero() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSNumberFormatter>(this) attributedStringForZero]);
    }

    void NumberFormatter::set_attributed_string_for_zero(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setAttributedStringForZero:cocoon::internal::native<::NSAttributedString>(value)];
    }

    std::string NumberFormatter::currency_code() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) currencyCode]);
    }

    void NumberFormatter::set_currency_code(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setCurrencyCode:cocoon::internal::to(value)];
    }

    std::string NumberFormatter::currency_decimal_separator() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) currencyDecimalSeparator]);
    }

    void NumberFormatter::set_currency_decimal_separator(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setCurrencyDecimalSeparator:cocoon::internal::to(value)];
    }

    std::string NumberFormatter::currency_grouping_separator() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) currencyGroupingSeparator]);
    }

    void NumberFormatter::set_currency_grouping_separator(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setCurrencyGroupingSeparator:cocoon::internal::to(value)];
    }

    std::string NumberFormatter::currency_symbol() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) currencySymbol]);
    }

    void NumberFormatter::set_currency_symbol(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setCurrencySymbol:cocoon::internal::to(value)];
    }

    std::string NumberFormatter::decimal_separator() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) decimalSeparator]);
    }

    void NumberFormatter::set_decimal_separator(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setDecimalSeparator:cocoon::internal::to(value)];
    }

    std::string NumberFormatter::exponent_symbol() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) exponentSymbol]);
    }

    void NumberFormatter::set_exponent_symbol(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setExponentSymbol:cocoon::internal::to(value)];
    }

    std::string NumberFormatter::format() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) format]);
    }

    void NumberFormatter::set_format(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setFormat:cocoon::internal::to(value)];
    }

    std::uint64_t NumberFormatter::format_width() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSNumberFormatter>(this) formatWidth]);
    }

    void NumberFormatter::set_format_width(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setFormatWidth:static_cast<::NSUInteger>(value)];
    }

    NumberFormatterBehavior NumberFormatter::formatter_behavior() const
    {
        return static_cast<NumberFormatterBehavior>([cocoon::internal::ns<::NSNumberFormatter>(this) formatterBehavior]);
    }

    void NumberFormatter::set_formatter_behavior(NumberFormatterBehavior value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setFormatterBehavior:static_cast<::NSNumberFormatterBehavior>(value)];
    }

    FormattingContext NumberFormatter::formatting_context() const
    {
        return static_cast<FormattingContext>([cocoon::internal::ns<::NSNumberFormatter>(this) formattingContext]);
    }

    void NumberFormatter::set_formatting_context(FormattingContext value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setFormattingContext:static_cast<::NSFormattingContext>(value)];
    }

    bool NumberFormatter::generates_decimal_numbers() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSNumberFormatter>(this) generatesDecimalNumbers]);
    }

    void NumberFormatter::set_generates_decimal_numbers(bool value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setGeneratesDecimalNumbers:static_cast<::BOOL>(value)];
    }

    std::string NumberFormatter::grouping_separator() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) groupingSeparator]);
    }

    void NumberFormatter::set_grouping_separator(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setGroupingSeparator:cocoon::internal::to(value)];
    }

    std::uint64_t NumberFormatter::grouping_size() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSNumberFormatter>(this) groupingSize]);
    }

    void NumberFormatter::set_grouping_size(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setGroupingSize:static_cast<::NSUInteger>(value)];
    }

    bool NumberFormatter::has_thousand_separators() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSNumberFormatter>(this) hasThousandSeparators]);
    }

    void NumberFormatter::set_has_thousand_separators(bool value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setHasThousandSeparators:static_cast<::BOOL>(value)];
    }

    std::string NumberFormatter::international_currency_symbol() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) internationalCurrencySymbol]);
    }

    void NumberFormatter::set_international_currency_symbol(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setInternationalCurrencySymbol:cocoon::internal::to(value)];
    }

    bool NumberFormatter::is_lenient() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSNumberFormatter>(this) isLenient]);
    }

    void NumberFormatter::set_lenient(bool value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setLenient:static_cast<::BOOL>(value)];
    }

    Locale NumberFormatter::locale() const
    {
        return cocoon::internal::wrap<Locale>([cocoon::internal::ns<::NSNumberFormatter>(this) locale]);
    }

    void NumberFormatter::set_locale(const Locale& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setLocale:cocoon::internal::native<::NSLocale>(value)];
    }

    bool NumberFormatter::localizes_format() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSNumberFormatter>(this) localizesFormat]);
    }

    void NumberFormatter::set_localizes_format(bool value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setLocalizesFormat:static_cast<::BOOL>(value)];
    }

    Number NumberFormatter::maximum() const
    {
        return cocoon::internal::wrap<Number>([cocoon::internal::ns<::NSNumberFormatter>(this) maximum]);
    }

    void NumberFormatter::set_maximum(const Number& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setMaximum:cocoon::internal::native<::NSNumber>(value)];
    }

    std::uint64_t NumberFormatter::maximum_fraction_digits() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSNumberFormatter>(this) maximumFractionDigits]);
    }

    void NumberFormatter::set_maximum_fraction_digits(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setMaximumFractionDigits:static_cast<::NSUInteger>(value)];
    }

    std::uint64_t NumberFormatter::maximum_integer_digits() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSNumberFormatter>(this) maximumIntegerDigits]);
    }

    void NumberFormatter::set_maximum_integer_digits(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setMaximumIntegerDigits:static_cast<::NSUInteger>(value)];
    }

    std::uint64_t NumberFormatter::maximum_significant_digits() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSNumberFormatter>(this) maximumSignificantDigits]);
    }

    void NumberFormatter::set_maximum_significant_digits(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setMaximumSignificantDigits:static_cast<::NSUInteger>(value)];
    }

    Number NumberFormatter::minimum() const
    {
        return cocoon::internal::wrap<Number>([cocoon::internal::ns<::NSNumberFormatter>(this) minimum]);
    }

    void NumberFormatter::set_minimum(const Number& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setMinimum:cocoon::internal::native<::NSNumber>(value)];
    }

    std::uint64_t NumberFormatter::minimum_fraction_digits() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSNumberFormatter>(this) minimumFractionDigits]);
    }

    void NumberFormatter::set_minimum_fraction_digits(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setMinimumFractionDigits:static_cast<::NSUInteger>(value)];
    }

    std::int64_t NumberFormatter::minimum_grouping_digits() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSNumberFormatter>(this) minimumGroupingDigits]);
    }

    void NumberFormatter::set_minimum_grouping_digits(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setMinimumGroupingDigits:static_cast<::NSInteger>(value)];
    }

    std::uint64_t NumberFormatter::minimum_integer_digits() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSNumberFormatter>(this) minimumIntegerDigits]);
    }

    void NumberFormatter::set_minimum_integer_digits(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setMinimumIntegerDigits:static_cast<::NSUInteger>(value)];
    }

    std::uint64_t NumberFormatter::minimum_significant_digits() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSNumberFormatter>(this) minimumSignificantDigits]);
    }

    void NumberFormatter::set_minimum_significant_digits(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setMinimumSignificantDigits:static_cast<::NSUInteger>(value)];
    }

    std::string NumberFormatter::minus_sign() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) minusSign]);
    }

    void NumberFormatter::set_minus_sign(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setMinusSign:cocoon::internal::to(value)];
    }

    Number NumberFormatter::multiplier() const
    {
        return cocoon::internal::wrap<Number>([cocoon::internal::ns<::NSNumberFormatter>(this) multiplier]);
    }

    void NumberFormatter::set_multiplier(const Number& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setMultiplier:cocoon::internal::native<::NSNumber>(value)];
    }

    std::string NumberFormatter::negative_format() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) negativeFormat]);
    }

    void NumberFormatter::set_negative_format(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setNegativeFormat:cocoon::internal::to(value)];
    }

    std::string NumberFormatter::negative_infinity_symbol() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) negativeInfinitySymbol]);
    }

    void NumberFormatter::set_negative_infinity_symbol(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setNegativeInfinitySymbol:cocoon::internal::to(value)];
    }

    std::string NumberFormatter::negative_prefix() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) negativePrefix]);
    }

    void NumberFormatter::set_negative_prefix(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setNegativePrefix:cocoon::internal::to(value)];
    }

    std::string NumberFormatter::negative_suffix() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) negativeSuffix]);
    }

    void NumberFormatter::set_negative_suffix(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setNegativeSuffix:cocoon::internal::to(value)];
    }

    std::string NumberFormatter::nil_symbol() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) nilSymbol]);
    }

    void NumberFormatter::set_nil_symbol(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setNilSymbol:cocoon::internal::to(value)];
    }

    std::string NumberFormatter::not_a_number_symbol() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) notANumberSymbol]);
    }

    void NumberFormatter::set_not_a_number_symbol(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setNotANumberSymbol:cocoon::internal::to(value)];
    }

    NumberFormatterStyle NumberFormatter::number_style() const
    {
        return static_cast<NumberFormatterStyle>([cocoon::internal::ns<::NSNumberFormatter>(this) numberStyle]);
    }

    void NumberFormatter::set_number_style(NumberFormatterStyle value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setNumberStyle:static_cast<::NSNumberFormatterStyle>(value)];
    }

    std::string NumberFormatter::padding_character() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) paddingCharacter]);
    }

    void NumberFormatter::set_padding_character(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setPaddingCharacter:cocoon::internal::to(value)];
    }

    NumberFormatterPadPosition NumberFormatter::padding_position() const
    {
        return static_cast<NumberFormatterPadPosition>([cocoon::internal::ns<::NSNumberFormatter>(this) paddingPosition]);
    }

    void NumberFormatter::set_padding_position(NumberFormatterPadPosition value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setPaddingPosition:static_cast<::NSNumberFormatterPadPosition>(value)];
    }

    bool NumberFormatter::is_partial_string_validation_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSNumberFormatter>(this) isPartialStringValidationEnabled]);
    }

    void NumberFormatter::set_partial_string_validation_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setPartialStringValidationEnabled:static_cast<::BOOL>(value)];
    }

    std::string NumberFormatter::per_mill_symbol() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) perMillSymbol]);
    }

    void NumberFormatter::set_per_mill_symbol(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setPerMillSymbol:cocoon::internal::to(value)];
    }

    std::string NumberFormatter::percent_symbol() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) percentSymbol]);
    }

    void NumberFormatter::set_percent_symbol(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setPercentSymbol:cocoon::internal::to(value)];
    }

    std::string NumberFormatter::plus_sign() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) plusSign]);
    }

    void NumberFormatter::set_plus_sign(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setPlusSign:cocoon::internal::to(value)];
    }

    std::string NumberFormatter::positive_format() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) positiveFormat]);
    }

    void NumberFormatter::set_positive_format(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setPositiveFormat:cocoon::internal::to(value)];
    }

    std::string NumberFormatter::positive_infinity_symbol() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) positiveInfinitySymbol]);
    }

    void NumberFormatter::set_positive_infinity_symbol(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setPositiveInfinitySymbol:cocoon::internal::to(value)];
    }

    std::string NumberFormatter::positive_prefix() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) positivePrefix]);
    }

    void NumberFormatter::set_positive_prefix(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setPositivePrefix:cocoon::internal::to(value)];
    }

    std::string NumberFormatter::positive_suffix() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) positiveSuffix]);
    }

    void NumberFormatter::set_positive_suffix(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setPositiveSuffix:cocoon::internal::to(value)];
    }

    DecimalNumberHandler NumberFormatter::rounding_behavior() const
    {
        return cocoon::internal::wrap<DecimalNumberHandler>([cocoon::internal::ns<::NSNumberFormatter>(this) roundingBehavior]);
    }

    void NumberFormatter::set_rounding_behavior(const DecimalNumberHandler& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setRoundingBehavior:cocoon::internal::native<::NSDecimalNumberHandler>(value)];
    }

    Number NumberFormatter::rounding_increment() const
    {
        return cocoon::internal::wrap<Number>([cocoon::internal::ns<::NSNumberFormatter>(this) roundingIncrement]);
    }

    void NumberFormatter::set_rounding_increment(const Number& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setRoundingIncrement:cocoon::internal::native<::NSNumber>(value)];
    }

    NumberFormatterRoundingMode NumberFormatter::rounding_mode() const
    {
        return static_cast<NumberFormatterRoundingMode>([cocoon::internal::ns<::NSNumberFormatter>(this) roundingMode]);
    }

    void NumberFormatter::set_rounding_mode(NumberFormatterRoundingMode value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setRoundingMode:static_cast<::NSNumberFormatterRoundingMode>(value)];
    }

    std::uint64_t NumberFormatter::secondary_grouping_size() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSNumberFormatter>(this) secondaryGroupingSize]);
    }

    void NumberFormatter::set_secondary_grouping_size(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setSecondaryGroupingSize:static_cast<::NSUInteger>(value)];
    }

    std::map<std::string, Object> NumberFormatter::text_attributes_for_negative_infinity() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSNumberFormatter>(this) textAttributesForNegativeInfinity], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    void NumberFormatter::set_text_attributes_for_negative_infinity(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setTextAttributesForNegativeInfinity:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                                                              {
                                                                                                                                  return cocoon::internal::to(k);
                                                                                                                              },
                                                                                                                              [](const Object& v) -> id
                                                                                                                              {
                                                                                                                                  return cocoon::internal::native_id(v);
                                                                                                                              })];
    }

    std::map<std::string, Object> NumberFormatter::text_attributes_for_negative_values() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSNumberFormatter>(this) textAttributesForNegativeValues], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    void NumberFormatter::set_text_attributes_for_negative_values(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setTextAttributesForNegativeValues:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                                                            {
                                                                                                                                return cocoon::internal::to(k);
                                                                                                                            },
                                                                                                                            [](const Object& v) -> id
                                                                                                                            {
                                                                                                                                return cocoon::internal::native_id(v);
                                                                                                                            })];
    }

    std::map<std::string, Object> NumberFormatter::text_attributes_for_nil() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSNumberFormatter>(this) textAttributesForNil], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    void NumberFormatter::set_text_attributes_for_nil(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setTextAttributesForNil:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                                                 {
                                                                                                                     return cocoon::internal::to(k);
                                                                                                                 },
                                                                                                                 [](const Object& v) -> id
                                                                                                                 {
                                                                                                                     return cocoon::internal::native_id(v);
                                                                                                                 })];
    }

    std::map<std::string, Object> NumberFormatter::text_attributes_for_not_a_number() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSNumberFormatter>(this) textAttributesForNotANumber], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    void NumberFormatter::set_text_attributes_for_not_a_number(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setTextAttributesForNotANumber:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                                                        {
                                                                                                                            return cocoon::internal::to(k);
                                                                                                                        },
                                                                                                                        [](const Object& v) -> id
                                                                                                                        {
                                                                                                                            return cocoon::internal::native_id(v);
                                                                                                                        })];
    }

    std::map<std::string, Object> NumberFormatter::text_attributes_for_positive_infinity() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSNumberFormatter>(this) textAttributesForPositiveInfinity], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    void NumberFormatter::set_text_attributes_for_positive_infinity(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setTextAttributesForPositiveInfinity:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                                                              {
                                                                                                                                  return cocoon::internal::to(k);
                                                                                                                              },
                                                                                                                              [](const Object& v) -> id
                                                                                                                              {
                                                                                                                                  return cocoon::internal::native_id(v);
                                                                                                                              })];
    }

    std::map<std::string, Object> NumberFormatter::text_attributes_for_positive_values() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSNumberFormatter>(this) textAttributesForPositiveValues], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    void NumberFormatter::set_text_attributes_for_positive_values(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setTextAttributesForPositiveValues:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                                                            {
                                                                                                                                return cocoon::internal::to(k);
                                                                                                                            },
                                                                                                                            [](const Object& v) -> id
                                                                                                                            {
                                                                                                                                return cocoon::internal::native_id(v);
                                                                                                                            })];
    }

    std::map<std::string, Object> NumberFormatter::text_attributes_for_zero() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSNumberFormatter>(this) textAttributesForZero], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    void NumberFormatter::set_text_attributes_for_zero(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setTextAttributesForZero:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                                                  {
                                                                                                                      return cocoon::internal::to(k);
                                                                                                                  },
                                                                                                                  [](const Object& v) -> id
                                                                                                                  {
                                                                                                                      return cocoon::internal::native_id(v);
                                                                                                                  })];
    }

    std::string NumberFormatter::thousand_separator() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) thousandSeparator]);
    }

    void NumberFormatter::set_thousand_separator(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setThousandSeparator:cocoon::internal::to(value)];
    }

    bool NumberFormatter::uses_grouping_separator() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSNumberFormatter>(this) usesGroupingSeparator]);
    }

    void NumberFormatter::set_uses_grouping_separator(bool value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setUsesGroupingSeparator:static_cast<::BOOL>(value)];
    }

    bool NumberFormatter::uses_significant_digits() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSNumberFormatter>(this) usesSignificantDigits]);
    }

    void NumberFormatter::set_uses_significant_digits(bool value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setUsesSignificantDigits:static_cast<::BOOL>(value)];
    }

    std::string NumberFormatter::zero_symbol() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSNumberFormatter>(this) zeroSymbol]);
    }

    void NumberFormatter::set_zero_symbol(const std::string& value) const
    {
        [cocoon::internal::ns<::NSNumberFormatter>(this) setZeroSymbol:cocoon::internal::to(value)];
    }
}
