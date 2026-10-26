#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/formatter.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class DecimalNumberHandler;
    class Locale;
    class Number;

    /**
     * @brief C++ handle for the Objective-C class `NSNumberFormatter` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Formatter.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::NumberFormatter number_formatter;
     * number_formatter.set_allows_floats(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::NumberFormatter number_formatter{};
     * number_formatter.set_allows_floats(true);
     * auto allows_floats = number_formatter.allows_floats();
     * number_formatter.set_always_shows_decimal_separator(true);
     * auto always_shows_decimal_separator = number_formatter.always_shows_decimal_separator();
     * number_formatter.set_attributed_string_for_nil(cocoon::AttributedString());
     * auto attributed_string_for_nil = number_formatter.attributed_string_for_nil();
     * number_formatter.number_from_string("text");
     * number_formatter.string_from_number(cocoon::Number());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsnumberformatter
     */
    class NumberFormatter : public Formatter
    {
    public:
        /// @brief Creates a new `NSNumberFormatter` instance and returns a handle to it.
        explicit NumberFormatter();
        /// @brief Creates a null handle that refers to no native object.
        NumberFormatter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit NumberFormatter(Adopt adopt);
        /**
         * @brief Calls `+[NSNumberFormatter defaultFormatterBehavior]`.
         * @return The converted Objective-C result.
         */
        static NumberFormatterBehavior default_formatter_behavior();
        /**
         * @brief Calls `+[NSNumberFormatter localizedStringFromNumber:numberStyle:]`.
         * @param num Argument converted to the Objective-C parameter of the same role.
         * @param nstyle Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::string localized_string_from_number(const Number& num, NumberFormatterStyle nstyle);
        /**
         * @brief Calls `-[NSNumberFormatter numberFromString:]`.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Number number_from_string(const std::string& string) const;
        /**
         * @brief Calls `+[NSNumberFormatter setDefaultFormatterBehavior:]`.
         * @param behavior Argument converted to the Objective-C parameter of the same role.
         */
        static void set_default_formatter_behavior(NumberFormatterBehavior behavior);
        /**
         * @brief Calls `-[NSNumberFormatter stringFromNumber:]`.
         * @param number Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string string_from_number(const Number& number) const;
        /**
         * @brief Returns the `allowsFloats` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        bool allows_floats() const;
        /**
         * @brief Sets the `allowsFloats` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_floats(bool value) const;
        /**
         * @brief Returns the `alwaysShowsDecimalSeparator` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        bool always_shows_decimal_separator() const;
        /**
         * @brief Sets the `alwaysShowsDecimalSeparator` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_always_shows_decimal_separator(bool value) const;
        /**
         * @brief Returns the `attributedStringForNil` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        AttributedString attributed_string_for_nil() const;
        /**
         * @brief Sets the `attributedStringForNil` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_attributed_string_for_nil(const AttributedString& value) const;
        /**
         * @brief Returns the `attributedStringForNotANumber` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        AttributedString attributed_string_for_not_a_number() const;
        /**
         * @brief Sets the `attributedStringForNotANumber` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_attributed_string_for_not_a_number(const AttributedString& value) const;
        /**
         * @brief Returns the `attributedStringForZero` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        AttributedString attributed_string_for_zero() const;
        /**
         * @brief Sets the `attributedStringForZero` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_attributed_string_for_zero(const AttributedString& value) const;
        /**
         * @brief Returns the `currencyCode` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string currency_code() const;
        /**
         * @brief Sets the `currencyCode` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_currency_code(const std::string& value) const;
        /**
         * @brief Returns the `currencyDecimalSeparator` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string currency_decimal_separator() const;
        /**
         * @brief Sets the `currencyDecimalSeparator` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_currency_decimal_separator(const std::string& value) const;
        /**
         * @brief Returns the `currencyGroupingSeparator` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string currency_grouping_separator() const;
        /**
         * @brief Sets the `currencyGroupingSeparator` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_currency_grouping_separator(const std::string& value) const;
        /**
         * @brief Returns the `currencySymbol` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string currency_symbol() const;
        /**
         * @brief Sets the `currencySymbol` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_currency_symbol(const std::string& value) const;
        /**
         * @brief Returns the `decimalSeparator` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string decimal_separator() const;
        /**
         * @brief Sets the `decimalSeparator` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_decimal_separator(const std::string& value) const;
        /**
         * @brief Returns the `exponentSymbol` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string exponent_symbol() const;
        /**
         * @brief Sets the `exponentSymbol` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_exponent_symbol(const std::string& value) const;
        /**
         * @brief Returns the `format` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string format() const;
        /**
         * @brief Sets the `format` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_format(const std::string& value) const;
        /**
         * @brief Returns the `formatWidth` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::uint64_t format_width() const;
        /**
         * @brief Sets the `formatWidth` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_format_width(std::uint64_t value) const;
        /**
         * @brief Returns the `formatterBehavior` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        NumberFormatterBehavior formatter_behavior() const;
        /**
         * @brief Sets the `formatterBehavior` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_formatter_behavior(NumberFormatterBehavior value) const;
        /**
         * @brief Returns the `formattingContext` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        FormattingContext formatting_context() const;
        /**
         * @brief Sets the `formattingContext` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_formatting_context(FormattingContext value) const;
        /**
         * @brief Returns the `generatesDecimalNumbers` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        bool generates_decimal_numbers() const;
        /**
         * @brief Sets the `generatesDecimalNumbers` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_generates_decimal_numbers(bool value) const;
        /**
         * @brief Returns the `groupingSeparator` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string grouping_separator() const;
        /**
         * @brief Sets the `groupingSeparator` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_grouping_separator(const std::string& value) const;
        /**
         * @brief Returns the `groupingSize` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::uint64_t grouping_size() const;
        /**
         * @brief Sets the `groupingSize` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_grouping_size(std::uint64_t value) const;
        /**
         * @brief Returns the `hasThousandSeparators` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        bool has_thousand_separators() const;
        /**
         * @brief Sets the `hasThousandSeparators` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_has_thousand_separators(bool value) const;
        /**
         * @brief Returns the `internationalCurrencySymbol` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string international_currency_symbol() const;
        /**
         * @brief Sets the `internationalCurrencySymbol` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_international_currency_symbol(const std::string& value) const;
        /**
         * @brief Returns the `lenient` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        bool is_lenient() const;
        /**
         * @brief Sets the `lenient` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_lenient(bool value) const;
        /**
         * @brief Returns the `locale` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        Locale locale() const;
        /**
         * @brief Sets the `locale` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_locale(const Locale& value) const;
        /**
         * @brief Returns the `localizesFormat` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        bool localizes_format() const;
        /**
         * @brief Sets the `localizesFormat` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_localizes_format(bool value) const;
        /**
         * @brief Returns the `maximum` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        Number maximum() const;
        /**
         * @brief Sets the `maximum` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_maximum(const Number& value) const;
        /**
         * @brief Returns the `maximumFractionDigits` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::uint64_t maximum_fraction_digits() const;
        /**
         * @brief Sets the `maximumFractionDigits` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_maximum_fraction_digits(std::uint64_t value) const;
        /**
         * @brief Returns the `maximumIntegerDigits` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::uint64_t maximum_integer_digits() const;
        /**
         * @brief Sets the `maximumIntegerDigits` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_maximum_integer_digits(std::uint64_t value) const;
        /**
         * @brief Returns the `maximumSignificantDigits` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::uint64_t maximum_significant_digits() const;
        /**
         * @brief Sets the `maximumSignificantDigits` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_maximum_significant_digits(std::uint64_t value) const;
        /**
         * @brief Returns the `minimum` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        Number minimum() const;
        /**
         * @brief Sets the `minimum` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_minimum(const Number& value) const;
        /**
         * @brief Returns the `minimumFractionDigits` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::uint64_t minimum_fraction_digits() const;
        /**
         * @brief Sets the `minimumFractionDigits` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_minimum_fraction_digits(std::uint64_t value) const;
        /**
         * @brief Returns the `minimumGroupingDigits` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::int64_t minimum_grouping_digits() const;
        /**
         * @brief Sets the `minimumGroupingDigits` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_minimum_grouping_digits(std::int64_t value) const;
        /**
         * @brief Returns the `minimumIntegerDigits` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::uint64_t minimum_integer_digits() const;
        /**
         * @brief Sets the `minimumIntegerDigits` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_minimum_integer_digits(std::uint64_t value) const;
        /**
         * @brief Returns the `minimumSignificantDigits` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::uint64_t minimum_significant_digits() const;
        /**
         * @brief Sets the `minimumSignificantDigits` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_minimum_significant_digits(std::uint64_t value) const;
        /**
         * @brief Returns the `minusSign` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string minus_sign() const;
        /**
         * @brief Sets the `minusSign` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_minus_sign(const std::string& value) const;
        /**
         * @brief Returns the `multiplier` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        Number multiplier() const;
        /**
         * @brief Sets the `multiplier` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_multiplier(const Number& value) const;
        /**
         * @brief Returns the `negativeFormat` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string negative_format() const;
        /**
         * @brief Sets the `negativeFormat` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_negative_format(const std::string& value) const;
        /**
         * @brief Returns the `negativeInfinitySymbol` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string negative_infinity_symbol() const;
        /**
         * @brief Sets the `negativeInfinitySymbol` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_negative_infinity_symbol(const std::string& value) const;
        /**
         * @brief Returns the `negativePrefix` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string negative_prefix() const;
        /**
         * @brief Sets the `negativePrefix` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_negative_prefix(const std::string& value) const;
        /**
         * @brief Returns the `negativeSuffix` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string negative_suffix() const;
        /**
         * @brief Sets the `negativeSuffix` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_negative_suffix(const std::string& value) const;
        /**
         * @brief Returns the `nilSymbol` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string nil_symbol() const;
        /**
         * @brief Sets the `nilSymbol` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_nil_symbol(const std::string& value) const;
        /**
         * @brief Returns the `notANumberSymbol` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string not_a_number_symbol() const;
        /**
         * @brief Sets the `notANumberSymbol` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_not_a_number_symbol(const std::string& value) const;
        /**
         * @brief Returns the `numberStyle` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        NumberFormatterStyle number_style() const;
        /**
         * @brief Sets the `numberStyle` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_number_style(NumberFormatterStyle value) const;
        /**
         * @brief Returns the `paddingCharacter` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string padding_character() const;
        /**
         * @brief Sets the `paddingCharacter` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_padding_character(const std::string& value) const;
        /**
         * @brief Returns the `paddingPosition` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        NumberFormatterPadPosition padding_position() const;
        /**
         * @brief Sets the `paddingPosition` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_padding_position(NumberFormatterPadPosition value) const;
        /**
         * @brief Returns the `partialStringValidationEnabled` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        bool is_partial_string_validation_enabled() const;
        /**
         * @brief Sets the `partialStringValidationEnabled` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_partial_string_validation_enabled(bool value) const;
        /**
         * @brief Returns the `perMillSymbol` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string per_mill_symbol() const;
        /**
         * @brief Sets the `perMillSymbol` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_per_mill_symbol(const std::string& value) const;
        /**
         * @brief Returns the `percentSymbol` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string percent_symbol() const;
        /**
         * @brief Sets the `percentSymbol` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_percent_symbol(const std::string& value) const;
        /**
         * @brief Returns the `plusSign` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string plus_sign() const;
        /**
         * @brief Sets the `plusSign` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_plus_sign(const std::string& value) const;
        /**
         * @brief Returns the `positiveFormat` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string positive_format() const;
        /**
         * @brief Sets the `positiveFormat` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_positive_format(const std::string& value) const;
        /**
         * @brief Returns the `positiveInfinitySymbol` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string positive_infinity_symbol() const;
        /**
         * @brief Sets the `positiveInfinitySymbol` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_positive_infinity_symbol(const std::string& value) const;
        /**
         * @brief Returns the `positivePrefix` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string positive_prefix() const;
        /**
         * @brief Sets the `positivePrefix` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_positive_prefix(const std::string& value) const;
        /**
         * @brief Returns the `positiveSuffix` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string positive_suffix() const;
        /**
         * @brief Sets the `positiveSuffix` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_positive_suffix(const std::string& value) const;
        /**
         * @brief Returns the `roundingBehavior` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        DecimalNumberHandler rounding_behavior() const;
        /**
         * @brief Sets the `roundingBehavior` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_rounding_behavior(const DecimalNumberHandler& value) const;
        /**
         * @brief Returns the `roundingIncrement` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        Number rounding_increment() const;
        /**
         * @brief Sets the `roundingIncrement` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_rounding_increment(const Number& value) const;
        /**
         * @brief Returns the `roundingMode` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        NumberFormatterRoundingMode rounding_mode() const;
        /**
         * @brief Sets the `roundingMode` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_rounding_mode(NumberFormatterRoundingMode value) const;
        /**
         * @brief Returns the `secondaryGroupingSize` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::uint64_t secondary_grouping_size() const;
        /**
         * @brief Sets the `secondaryGroupingSize` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_secondary_grouping_size(std::uint64_t value) const;
        /**
         * @brief Returns the `textAttributesForNegativeInfinity` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> text_attributes_for_negative_infinity() const;
        /**
         * @brief Sets the `textAttributesForNegativeInfinity` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_text_attributes_for_negative_infinity(const std::map<std::string, Object>& value) const;
        /**
         * @brief Returns the `textAttributesForNegativeValues` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> text_attributes_for_negative_values() const;
        /**
         * @brief Sets the `textAttributesForNegativeValues` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_text_attributes_for_negative_values(const std::map<std::string, Object>& value) const;
        /**
         * @brief Returns the `textAttributesForNil` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> text_attributes_for_nil() const;
        /**
         * @brief Sets the `textAttributesForNil` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_text_attributes_for_nil(const std::map<std::string, Object>& value) const;
        /**
         * @brief Returns the `textAttributesForNotANumber` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> text_attributes_for_not_a_number() const;
        /**
         * @brief Sets the `textAttributesForNotANumber` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_text_attributes_for_not_a_number(const std::map<std::string, Object>& value) const;
        /**
         * @brief Returns the `textAttributesForPositiveInfinity` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> text_attributes_for_positive_infinity() const;
        /**
         * @brief Sets the `textAttributesForPositiveInfinity` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_text_attributes_for_positive_infinity(const std::map<std::string, Object>& value) const;
        /**
         * @brief Returns the `textAttributesForPositiveValues` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> text_attributes_for_positive_values() const;
        /**
         * @brief Sets the `textAttributesForPositiveValues` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_text_attributes_for_positive_values(const std::map<std::string, Object>& value) const;
        /**
         * @brief Returns the `textAttributesForZero` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> text_attributes_for_zero() const;
        /**
         * @brief Sets the `textAttributesForZero` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_text_attributes_for_zero(const std::map<std::string, Object>& value) const;
        /**
         * @brief Returns the `thousandSeparator` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string thousand_separator() const;
        /**
         * @brief Sets the `thousandSeparator` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_thousand_separator(const std::string& value) const;
        /**
         * @brief Returns the `usesGroupingSeparator` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        bool uses_grouping_separator() const;
        /**
         * @brief Sets the `usesGroupingSeparator` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_uses_grouping_separator(bool value) const;
        /**
         * @brief Returns the `usesSignificantDigits` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        bool uses_significant_digits() const;
        /**
         * @brief Sets the `usesSignificantDigits` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_uses_significant_digits(bool value) const;
        /**
         * @brief Returns the `zeroSymbol` property of `NSNumberFormatter`.
         * @return The converted Objective-C result.
         */
        std::string zero_symbol() const;
        /**
         * @brief Sets the `zeroSymbol` property of `NSNumberFormatter`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_zero_symbol(const std::string& value) const;
    };
}
