#pragma once

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
     * @details A formatter that converts between numeric values and their textual representations. Instances of ''NumberFormatter'' format the textual representation of cells that contain ''NSNumber'' objects and convert textual representations of numeric values into ''NSNumber'' objects. The representation encompasses integers, floats, and doubles; floats and doubles can be formatted to a specified decimal position. ''NumberFormatter'' objects can also impose ranges on the numeric values cells can accept. > Tip: > In Swift, you can use ''IntegerFormatStyle'', ''FloatingPointFormatStyle'', or ''Decimal/FormatStyle'' rather than ''NumberFormatter''. The ''FormatStyle'' API offers a declarative idiom for customizing the formatting of various types. Also, Foundation caches identical ''FormatStyle'' instances, so you don't need to pass them around your app, or risk wasting memory with duplicate formatters. \#\#\# Significant Digits and Fraction Digits The ''NumberFormatter'' class provides flexible options for displaying non-zero fractional parts of numbers. If you set the ''usesSignificantDigits'' property to \<doc://com.apple.documentation/documentation/swift/true>, you can configure ''NumberFormatter'' to display significant digits using the ''minimumSignificantDigits'' and ''maximumSignificantDigits'' properties. If ''usesSignificantDigits'' is \<doc://com.apple.documentation/documentation/swift/false>, these properties are ignored. See Configuring Significant Digits. Otherwise, you can configure the minimum and maximum number of integer and fraction digits, or the numbers before and after the decimal separator, respectively, using the ''minimumIntegerDigits'', ''maximumIntegerDigits'', ''minimumFractionDigits'', and ''maximumFractionDigits'' properties. See Configuring Integer and Fraction Digits. \#\#\# Thread Safety On iOS 7 and later ''NumberFormatter'' is thread-safe. In macOS 10.9 and later ''NumberFormatter'' is thread-safe so long as you are using the modern behavior in a 64-bit app. On earlier versions of the operating system, or when using the legacy formatter behavior or running in 32-bit in macOS, ''NumberFormatter'' is not thread-safe, and you therefore must not mutate a number formatter simultaneously from multiple threads.
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
     * @details Returns an \\c NSNumberFormatterBehavior constant that indicates default formatter behavior for new instances of \\c NSNumberFormatter.
     * @return The converted Objective-C result.
     */
        static NumberFormatterBehavior default_formatter_behavior();
        /**
     * @brief Calls `+[NSNumberFormatter localizedStringFromNumber:numberStyle:]`.
     * @details Returns a localized number string with the specified style. \@param num The number to localize. \@param nstyle The localization style to use. \@return An appropriately formatted \\c NSString.
     * @param num Argument converted to the Objective-C parameter of the same role.
     * @param nstyle Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string localized_string_from_number(const Number& num, NumberFormatterStyle nstyle);
        /**
     * @brief Calls `-[NSNumberFormatter numberFromString:]`.
     * @details Returns an \\c NSNumber object created by parsing a given string. If a string contains any characters other than numerical digits or locale-appropriate group or decimal separators, parsing will fail. Any leading or trailing space separator characters in a string are ignored. For example, the strings " 5", "5 ", and "5" all produce the number \\c 5. \@param string An \\c NSString object that is parsed to generate the returned number object. \@return An \\c NSNumber object created by parsing \\c string using the receiver's format, or \\c nil if no single number could be parsed.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Number number_from_string(const std::string& string) const;
        /**
     * @brief Calls `+[NSNumberFormatter setDefaultFormatterBehavior:]`.
     * @details Sets the default formatter behavior for new instances of \\c NSNumberFormatter. \@param behavior An \\c NSNumberFormatterBehavior constant that indicates the revision of the class providing the default behavior.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     */
        static void set_default_formatter_behavior(NumberFormatterBehavior behavior);
        /**
     * @brief Calls `-[NSNumberFormatter stringFromNumber:]`.
     * @details Returns a string containing the formatted value of the provided number object. \@param number An \\c NSNumber object that is parsed to create the returned string object. \@return A string containing the formatted value of \\c number using the receiver's current settings.
     * @param number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_number(const Number& number) const;
        /**
     * @brief Returns the `allowsFloats` property of `NSNumberFormatter`.
     * @details Determines whether the receiver allows as input floating-point values (that is, values that include the period character (\\c .)). By default, floating point values are allowed.
     * @return The converted Objective-C result.
     */
        bool allows_floats() const;
        /**
     * @brief Sets the `allowsFloats` property of `NSNumberFormatter`.
     * @details Determines whether the receiver allows as input floating-point values (that is, values that include the period character (\\c .)). By default, floating point values are allowed.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_floats(bool value) const;
        /**
     * @brief Returns the `alwaysShowsDecimalSeparator` property of `NSNumberFormatter`.
     * @details Determines whether the receiver always shows the decimal separator, even for integer numbers.
     * @return The converted Objective-C result.
     */
        bool always_shows_decimal_separator() const;
        /**
     * @brief Sets the `alwaysShowsDecimalSeparator` property of `NSNumberFormatter`.
     * @details Determines whether the receiver always shows the decimal separator, even for integer numbers.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_always_shows_decimal_separator(bool value) const;
        /**
     * @brief Returns the `attributedStringForNil` property of `NSNumberFormatter`.
     * @details The attributed string the receiver uses to display \\c nil values. By default \\c nil values are displayed as an empty string. This method is for use with formatters using \\c NSNumberFormatterBehavior10_0 behavior.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_string_for_nil() const;
        /**
     * @brief Sets the `attributedStringForNil` property of `NSNumberFormatter`.
     * @details The attributed string the receiver uses to display \\c nil values. By default \\c nil values are displayed as an empty string. This method is for use with formatters using \\c NSNumberFormatterBehavior10_0 behavior.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_string_for_nil(const AttributedString& value) const;
        /**
     * @brief Returns the `attributedStringForNotANumber` property of `NSNumberFormatter`.
     * @details The attributed string the receiver uses to display "not a number" values. By default "not a number" values are displayed as the string "NaN". This method is for use with formatters using \\c NSNumberFormatterBehavior10_0 behavior.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_string_for_not_a_number() const;
        /**
     * @brief Sets the `attributedStringForNotANumber` property of `NSNumberFormatter`.
     * @details The attributed string the receiver uses to display "not a number" values. By default "not a number" values are displayed as the string "NaN". This method is for use with formatters using \\c NSNumberFormatterBehavior10_0 behavior.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_string_for_not_a_number(const AttributedString& value) const;
        /**
     * @brief Returns the `attributedStringForZero` property of `NSNumberFormatter`.
     * @details The attributed string that the receiver uses to display zero values. By default zero values are displayed according to the format specified for positive values. This method is for use with formatters using \\c NSNumberFormatterBehavior10_0 behavior.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_string_for_zero() const;
        /**
     * @brief Sets the `attributedStringForZero` property of `NSNumberFormatter`.
     * @details The attributed string that the receiver uses to display zero values. By default zero values are displayed according to the format specified for positive values. This method is for use with formatters using \\c NSNumberFormatterBehavior10_0 behavior.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_string_for_zero(const AttributedString& value) const;
        /**
     * @brief Returns the `currencyCode` property of `NSNumberFormatter`.
     * @details The receiver's currency code. A currency code is a three-letter code that is, in most cases, composed of a region's two-character Internet region code plus an extra character to denote the currency unit. For example, the currency code for the Australian dollar is "AUD". Currency codes are based on the ISO 4217 standard.
     * @return The converted Objective-C result.
     */
        std::string currency_code() const;
        /**
     * @brief Sets the `currencyCode` property of `NSNumberFormatter`.
     * @details The receiver's currency code. A currency code is a three-letter code that is, in most cases, composed of a region's two-character Internet region code plus an extra character to denote the currency unit. For example, the currency code for the Australian dollar is "AUD". Currency codes are based on the ISO 4217 standard.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_currency_code(const std::string& value) const;
        /**
     * @brief Returns the `currencyDecimalSeparator` property of `NSNumberFormatter`.
     * @details The string used by the receiver as a currency decimal separator.
     * @return The converted Objective-C result.
     */
        std::string currency_decimal_separator() const;
        /**
     * @brief Sets the `currencyDecimalSeparator` property of `NSNumberFormatter`.
     * @details The string used by the receiver as a currency decimal separator.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_currency_decimal_separator(const std::string& value) const;
        /**
     * @brief Returns the `currencyGroupingSeparator` property of `NSNumberFormatter`.
     * @details The currency grouping separator for the receiver.
     * @return The converted Objective-C result.
     */
        std::string currency_grouping_separator() const;
        /**
     * @brief Sets the `currencyGroupingSeparator` property of `NSNumberFormatter`.
     * @details The currency grouping separator for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_currency_grouping_separator(const std::string& value) const;
        /**
     * @brief Returns the `currencySymbol` property of `NSNumberFormatter`.
     * @details The string used by the receiver as a local currency symbol. A region typically has a local currency symbol and an international currency symbol. The local symbol is used within the region, while the international currency symbol is used in international contexts to specify that region's currency unambiguously. The local currency symbol is often represented by a Unicode code point.
     * @return The converted Objective-C result.
     */
        std::string currency_symbol() const;
        /**
     * @brief Sets the `currencySymbol` property of `NSNumberFormatter`.
     * @details The string used by the receiver as a local currency symbol. A region typically has a local currency symbol and an international currency symbol. The local symbol is used within the region, while the international currency symbol is used in international contexts to specify that region's currency unambiguously. The local currency symbol is often represented by a Unicode code point.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_currency_symbol(const std::string& value) const;
        /**
     * @brief Returns the `decimalSeparator` property of `NSNumberFormatter`.
     * @details The character the receiver uses as a decimal separator.
     * @return The converted Objective-C result.
     */
        std::string decimal_separator() const;
        /**
     * @brief Sets the `decimalSeparator` property of `NSNumberFormatter`.
     * @details The character the receiver uses as a decimal separator.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_decimal_separator(const std::string& value) const;
        /**
     * @brief Returns the `exponentSymbol` property of `NSNumberFormatter`.
     * @details The string used to represent an exponent symbol. By default, this property is set to the latin capital letter E. The exponent symbol is the "E" or "e" in the scientific notation of numbers, as in "1.0E+42".
     * @return The converted Objective-C result.
     */
        std::string exponent_symbol() const;
        /**
     * @brief Sets the `exponentSymbol` property of `NSNumberFormatter`.
     * @details The string used to represent an exponent symbol. By default, this property is set to the latin capital letter E. The exponent symbol is the "E" or "e" in the scientific notation of numbers, as in "1.0E+42".
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_exponent_symbol(const std::string& value) const;
        /**
     * @brief Returns the `format` property of `NSNumberFormatter`.
     * @details The receiver's format. The format string uses the format patterns from the Unicode Technical Standard \#35. For more information, see the Data Formatting Guide.
     * @return The converted Objective-C result.
     */
        std::string format() const;
        /**
     * @brief Sets the `format` property of `NSNumberFormatter`.
     * @details The receiver's format. The format string uses the format patterns from the Unicode Technical Standard \#35. For more information, see the Data Formatting Guide.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_format(const std::string& value) const;
        /**
     * @brief Returns the `formatWidth` property of `NSNumberFormatter`.
     * @details The format width used by the receiver. The format width is the number of characters of a formatted number within a string that is either left justified or right justified based on the value contained in \\c paddingPosition.
     * @return The converted Objective-C result.
     */
        std::uint64_t format_width() const;
        /**
     * @brief Sets the `formatWidth` property of `NSNumberFormatter`.
     * @details The format width used by the receiver. The format width is the number of characters of a formatted number within a string that is either left justified or right justified based on the value contained in \\c paddingPosition.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_format_width(std::uint64_t value) const;
        /**
     * @brief Returns the `formatterBehavior` property of `NSNumberFormatter`.
     * @details The formatter behavior of the receiver.
     * @return The converted Objective-C result.
     */
        NumberFormatterBehavior formatter_behavior() const;
        /**
     * @brief Sets the `formatterBehavior` property of `NSNumberFormatter`.
     * @details The formatter behavior of the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_formatter_behavior(NumberFormatterBehavior value) const;
        /**
     * @brief Returns the `formattingContext` property of `NSNumberFormatter`.
     * @details The capitalization formatting context used when formatting a number. Defaults to \\c NSFormattingContextUnknown.
     * @return The converted Objective-C result.
     */
        FormattingContext formatting_context() const;
        /**
     * @brief Sets the `formattingContext` property of `NSNumberFormatter`.
     * @details The capitalization formatting context used when formatting a number. Defaults to \\c NSFormattingContextUnknown.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_formatting_context(FormattingContext value) const;
        /**
     * @brief Returns the `generatesDecimalNumbers` property of `NSNumberFormatter`.
     * @details Determines whether the receiver creates instances of \\c NSDecimalNumber when it converts strings to number objects.
     * @return The converted Objective-C result.
     */
        bool generates_decimal_numbers() const;
        /**
     * @brief Sets the `generatesDecimalNumbers` property of `NSNumberFormatter`.
     * @details Determines whether the receiver creates instances of \\c NSDecimalNumber when it converts strings to number objects.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_generates_decimal_numbers(bool value) const;
        /**
     * @brief Returns the `groupingSeparator` property of `NSNumberFormatter`.
     * @details The string used by the receiver for a grouping separator. For example, the grouping separator used in the United States is the comma ("10,000") whereas in France it is the space ("10 000").
     * @return The converted Objective-C result.
     */
        std::string grouping_separator() const;
        /**
     * @brief Sets the `groupingSeparator` property of `NSNumberFormatter`.
     * @details The string used by the receiver for a grouping separator. For example, the grouping separator used in the United States is the comma ("10,000") whereas in France it is the space ("10 000").
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_grouping_separator(const std::string& value) const;
        /**
     * @brief Returns the `groupingSize` property of `NSNumberFormatter`.
     * @details The grouping size of the receiver.
     * @return The converted Objective-C result.
     */
        std::uint64_t grouping_size() const;
        /**
     * @brief Sets the `groupingSize` property of `NSNumberFormatter`.
     * @details The grouping size of the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_grouping_size(std::uint64_t value) const;
        /**
     * @brief Returns the `hasThousandSeparators` property of `NSNumberFormatter`.
     * @details Determines whether the receiver uses thousand separators.
     * @return The converted Objective-C result.
     */
        bool has_thousand_separators() const;
        /**
     * @brief Sets the `hasThousandSeparators` property of `NSNumberFormatter`.
     * @details Determines whether the receiver uses thousand separators.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_has_thousand_separators(bool value) const;
        /**
     * @brief Returns the `internationalCurrencySymbol` property of `NSNumberFormatter`.
     * @details The international currency symbol used by the receiver. A region typically has a local currency symbol and an international currency symbol. The local symbol is used within the region, while the international currency symbol is used in international contexts to specify that region's currency unambiguously. The international currency symbol is often represented by a Unicode code point.
     * @return The converted Objective-C result.
     */
        std::string international_currency_symbol() const;
        /**
     * @brief Sets the `internationalCurrencySymbol` property of `NSNumberFormatter`.
     * @details The international currency symbol used by the receiver. A region typically has a local currency symbol and an international currency symbol. The local symbol is used within the region, while the international currency symbol is used in international contexts to specify that region's currency unambiguously. The international currency symbol is often represented by a Unicode code point.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_international_currency_symbol(const std::string& value) const;
        /**
     * @brief Returns the `lenient` property of `NSNumberFormatter`.
     * @details Determines whether the receiver will use heuristics to guess at the number which is intended by a string. If the formatter is set to be lenient, as with any guessing it may get the result number wrong (that is, a number other than that which was intended).
     * @return The converted Objective-C result.
     */
        bool is_lenient() const;
        /**
     * @brief Sets the `lenient` property of `NSNumberFormatter`.
     * @details Determines whether the receiver will use heuristics to guess at the number which is intended by a string. If the formatter is set to be lenient, as with any guessing it may get the result number wrong (that is, a number other than that which was intended).
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_lenient(bool value) const;
        /**
     * @brief Returns the `locale` property of `NSNumberFormatter`.
     * @details The locale of the receiver. The locale determines the default values for many formatter attributes, such as ISO region and language codes, currency code, calendar, system of measurement, and decimal separator.
     * @return The converted Objective-C result.
     */
        Locale locale() const;
        /**
     * @brief Sets the `locale` property of `NSNumberFormatter`.
     * @details The locale of the receiver. The locale determines the default values for many formatter attributes, such as ISO region and language codes, currency code, calendar, system of measurement, and decimal separator.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_locale(const Locale& value) const;
        /**
     * @brief Returns the `localizesFormat` property of `NSNumberFormatter`.
     * @details Determines whether the dollar sign character (\\c $), decimal separator character (\\c .), and thousand separator character (\\c ,) are converted to appropriately localized characters as specified by the user's localization preference. While the currency-symbol part of this feature may be useful in certain types of applications, it's probably more likely that you would tie a particular application to a particular currency (that is, that you would "hard-code" the currency symbol and separators instead of having them dynamically change based on the user's configuration). The reason for this, of course, is that \\c NSNumberFormatter doesn't perform currency conversions, it just formats numeric data. You wouldn't want one user interpreting the value "56324" as US currency and another user who's accessing the same data interpreting it as Japanese currency, simply based on each user's localization preferences.
     * @return The converted Objective-C result.
     */
        bool localizes_format() const;
        /**
     * @brief Sets the `localizesFormat` property of `NSNumberFormatter`.
     * @details Determines whether the dollar sign character (\\c $), decimal separator character (\\c .), and thousand separator character (\\c ,) are converted to appropriately localized characters as specified by the user's localization preference. While the currency-symbol part of this feature may be useful in certain types of applications, it's probably more likely that you would tie a particular application to a particular currency (that is, that you would "hard-code" the currency symbol and separators instead of having them dynamically change based on the user's configuration). The reason for this, of course, is that \\c NSNumberFormatter doesn't perform currency conversions, it just formats numeric data. You wouldn't want one user interpreting the value "56324" as US currency and another user who's accessing the same data interpreting it as Japanese currency, simply based on each user's localization preferences.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_localizes_format(bool value) const;
        /**
     * @brief Returns the `maximum` property of `NSNumberFormatter`.
     * @details The highest number allowed as input by the receiver.
     * @return The converted Objective-C result.
     */
        Number maximum() const;
        /**
     * @brief Sets the `maximum` property of `NSNumberFormatter`.
     * @details The highest number allowed as input by the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum(const Number& value) const;
        /**
     * @brief Returns the `maximumFractionDigits` property of `NSNumberFormatter`.
     * @details The maximum number of digits after the decimal separator. By default, this property is set to \\c 0.
     * @return The converted Objective-C result.
     */
        std::uint64_t maximum_fraction_digits() const;
        /**
     * @brief Sets the `maximumFractionDigits` property of `NSNumberFormatter`.
     * @details The maximum number of digits after the decimal separator. By default, this property is set to \\c 0.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_fraction_digits(std::uint64_t value) const;
        /**
     * @brief Returns the `maximumIntegerDigits` property of `NSNumberFormatter`.
     * @details The maximum number of digits before the decimal separator. By default, this property is set to \\c 42.
     * @return The converted Objective-C result.
     */
        std::uint64_t maximum_integer_digits() const;
        /**
     * @brief Sets the `maximumIntegerDigits` property of `NSNumberFormatter`.
     * @details The maximum number of digits before the decimal separator. By default, this property is set to \\c 42.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_integer_digits(std::uint64_t value) const;
        /**
     * @brief Returns the `maximumSignificantDigits` property of `NSNumberFormatter`.
     * @details The maximum number of significant digits for the number formatter. You must set the \\c usesSignificantDigits property to \\c YES in order for this property to affect formatting behavior. By default, the maximum number of significant digits is 6. Values less than 1 are ignored.
     * @return The converted Objective-C result.
     */
        std::uint64_t maximum_significant_digits() const;
        /**
     * @brief Sets the `maximumSignificantDigits` property of `NSNumberFormatter`.
     * @details The maximum number of significant digits for the number formatter. You must set the \\c usesSignificantDigits property to \\c YES in order for this property to affect formatting behavior. By default, the maximum number of significant digits is 6. Values less than 1 are ignored.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_significant_digits(std::uint64_t value) const;
        /**
     * @brief Returns the `minimum` property of `NSNumberFormatter`.
     * @details The lowest number allowed as input by the receiver.
     * @return The converted Objective-C result.
     */
        Number minimum() const;
        /**
     * @brief Sets the `minimum` property of `NSNumberFormatter`.
     * @details The lowest number allowed as input by the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum(const Number& value) const;
        /**
     * @brief Returns the `minimumFractionDigits` property of `NSNumberFormatter`.
     * @details The minimum number of digits after the decimal separator. By default, this property is set to \\c 0.
     * @return The converted Objective-C result.
     */
        std::uint64_t minimum_fraction_digits() const;
        /**
     * @brief Sets the `minimumFractionDigits` property of `NSNumberFormatter`.
     * @details The minimum number of digits after the decimal separator. By default, this property is set to \\c 0.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_fraction_digits(std::uint64_t value) const;
        /**
     * @brief Returns the `minimumGroupingDigits` property of `NSNumberFormatter`.
     * @details See \\c kCFNumberFormatterMinGroupingDigits in \\c CFNumberFormatter for an explanation on how minimum grouping digits is used.
     * @return The converted Objective-C result.
     */
        std::int64_t minimum_grouping_digits() const;
        /**
     * @brief Sets the `minimumGroupingDigits` property of `NSNumberFormatter`.
     * @details See \\c kCFNumberFormatterMinGroupingDigits in \\c CFNumberFormatter for an explanation on how minimum grouping digits is used.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_grouping_digits(std::int64_t value) const;
        /**
     * @brief Returns the `minimumIntegerDigits` property of `NSNumberFormatter`.
     * @details The minimum number of digits before the decimal separator. By default, this property is set to \\c 0.
     * @return The converted Objective-C result.
     */
        std::uint64_t minimum_integer_digits() const;
        /**
     * @brief Sets the `minimumIntegerDigits` property of `NSNumberFormatter`.
     * @details The minimum number of digits before the decimal separator. By default, this property is set to \\c 0.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_integer_digits(std::uint64_t value) const;
        /**
     * @brief Returns the `minimumSignificantDigits` property of `NSNumberFormatter`.
     * @details The minimum number of significant digits for the number formatter. You must set the \\c usesSignificantDigits property to \\c YES in order for this property to affect formatting behavior. By default, the minimum number of significant digits is 1.
     * @return The converted Objective-C result.
     */
        std::uint64_t minimum_significant_digits() const;
        /**
     * @brief Sets the `minimumSignificantDigits` property of `NSNumberFormatter`.
     * @details The minimum number of significant digits for the number formatter. You must set the \\c usesSignificantDigits property to \\c YES in order for this property to affect formatting behavior. By default, the minimum number of significant digits is 1.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_significant_digits(std::uint64_t value) const;
        /**
     * @brief Returns the `minusSign` property of `NSNumberFormatter`.
     * @details The string used to represent a minus sign. By default, this property is set to the minus sign (-).
     * @return The converted Objective-C result.
     */
        std::string minus_sign() const;
        /**
     * @brief Sets the `minusSign` property of `NSNumberFormatter`.
     * @details The string used to represent a minus sign. By default, this property is set to the minus sign (-).
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minus_sign(const std::string& value) const;
        /**
     * @brief Returns the `multiplier` property of `NSNumberFormatter`.
     * @details The multiplier of the receiver. A multiplier is a factor used in conversions between numbers and strings (that is, numbers as stored and numbers as displayed). When the input value is a string, the multiplier is used to divide, and when the input value is a number, the multiplier is used to multiply. These operations allow the formatted values to be different from the values that a program manipulates internally.
     * @return The converted Objective-C result.
     */
        Number multiplier() const;
        /**
     * @brief Sets the `multiplier` property of `NSNumberFormatter`.
     * @details The multiplier of the receiver. A multiplier is a factor used in conversions between numbers and strings (that is, numbers as stored and numbers as displayed). When the input value is a string, the multiplier is used to divide, and when the input value is a number, the multiplier is used to multiply. These operations allow the formatted values to be different from the values that a program manipulates internally.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_multiplier(const Number& value) const;
        /**
     * @brief Returns the `negativeFormat` property of `NSNumberFormatter`.
     * @details The format the receiver uses to display negative values.
     * @return The converted Objective-C result.
     */
        std::string negative_format() const;
        /**
     * @brief Sets the `negativeFormat` property of `NSNumberFormatter`.
     * @details The format the receiver uses to display negative values.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_negative_format(const std::string& value) const;
        /**
     * @brief Returns the `negativeInfinitySymbol` property of `NSNumberFormatter`.
     * @details The string used to represent a negative infinity symbol. By default, this property is set to the string "-\\u221e".
     * @return The converted Objective-C result.
     */
        std::string negative_infinity_symbol() const;
        /**
     * @brief Sets the `negativeInfinitySymbol` property of `NSNumberFormatter`.
     * @details The string used to represent a negative infinity symbol. By default, this property is set to the string "-\\u221e".
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_negative_infinity_symbol(const std::string& value) const;
        /**
     * @brief Returns the `negativePrefix` property of `NSNumberFormatter`.
     * @details The string the receiver uses as a prefix for negative values.
     * @return The converted Objective-C result.
     */
        std::string negative_prefix() const;
        /**
     * @brief Sets the `negativePrefix` property of `NSNumberFormatter`.
     * @details The string the receiver uses as a prefix for negative values.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_negative_prefix(const std::string& value) const;
        /**
     * @brief Returns the `negativeSuffix` property of `NSNumberFormatter`.
     * @details The string the receiver uses as a suffix for negative values.
     * @return The converted Objective-C result.
     */
        std::string negative_suffix() const;
        /**
     * @brief Sets the `negativeSuffix` property of `NSNumberFormatter`.
     * @details The string the receiver uses as a suffix for negative values.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_negative_suffix(const std::string& value) const;
        /**
     * @brief Returns the `nilSymbol` property of `NSNumberFormatter`.
     * @details The string used to represent a \\c nil value. By default, this property is set to an empty string ("").
     * @return The converted Objective-C result.
     */
        std::string nil_symbol() const;
        /**
     * @brief Sets the `nilSymbol` property of `NSNumberFormatter`.
     * @details The string used to represent a \\c nil value. By default, this property is set to an empty string ("").
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_nil_symbol(const std::string& value) const;
        /**
     * @brief Returns the `notANumberSymbol` property of `NSNumberFormatter`.
     * @details The string used to represent a NaN ("not a number") value. By default, this property is set to the string "NaN".
     * @return The converted Objective-C result.
     */
        std::string not_a_number_symbol() const;
        /**
     * @brief Sets the `notANumberSymbol` property of `NSNumberFormatter`.
     * @details The string used to represent a NaN ("not a number") value. By default, this property is set to the string "NaN".
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_not_a_number_symbol(const std::string& value) const;
        /**
     * @brief Returns the `numberStyle` property of `NSNumberFormatter`.
     * @details The number style used by the receiver. Styles are essentially predetermined sets of values for certain properties. Examples of number-formatter styles are those used for decimal values, percentage values, and currency.
     * @return The converted Objective-C result.
     */
        NumberFormatterStyle number_style() const;
        /**
     * @brief Sets the `numberStyle` property of `NSNumberFormatter`.
     * @details The number style used by the receiver. Styles are essentially predetermined sets of values for certain properties. Examples of number-formatter styles are those used for decimal values, percentage values, and currency.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_number_style(NumberFormatterStyle value) const;
        /**
     * @brief Returns the `paddingCharacter` property of `NSNumberFormatter`.
     * @details The string that the receiver uses to pad numbers in the formatted string representation.
     * @return The converted Objective-C result.
     */
        std::string padding_character() const;
        /**
     * @brief Sets the `paddingCharacter` property of `NSNumberFormatter`.
     * @details The string that the receiver uses to pad numbers in the formatted string representation.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_padding_character(const std::string& value) const;
        /**
     * @brief Returns the `paddingPosition` property of `NSNumberFormatter`.
     * @details The padding position used by the receiver.
     * @return The converted Objective-C result.
     */
        NumberFormatterPadPosition padding_position() const;
        /**
     * @brief Sets the `paddingPosition` property of `NSNumberFormatter`.
     * @details The padding position used by the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_padding_position(NumberFormatterPadPosition value) const;
        /**
     * @brief Returns the `partialStringValidationEnabled` property of `NSNumberFormatter`.
     * @details Determines whether partial string validation is enabled for the receiver.
     * @return The converted Objective-C result.
     */
        bool is_partial_string_validation_enabled() const;
        /**
     * @brief Sets the `partialStringValidationEnabled` property of `NSNumberFormatter`.
     * @details Determines whether partial string validation is enabled for the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_partial_string_validation_enabled(bool value) const;
        /**
     * @brief Returns the `perMillSymbol` property of `NSNumberFormatter`.
     * @details The string used to represent a per-mill (per-thousand) symbol. By default, this property is set to the per mille sign (\\u2030).
     * @return The converted Objective-C result.
     */
        std::string per_mill_symbol() const;
        /**
     * @brief Sets the `perMillSymbol` property of `NSNumberFormatter`.
     * @details The string used to represent a per-mill (per-thousand) symbol. By default, this property is set to the per mille sign (\\u2030).
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_per_mill_symbol(const std::string& value) const;
        /**
     * @brief Returns the `percentSymbol` property of `NSNumberFormatter`.
     * @details The string used to represent a percent symbol. By default, this property is set to the percent sign (\%).
     * @return The converted Objective-C result.
     */
        std::string percent_symbol() const;
        /**
     * @brief Sets the `percentSymbol` property of `NSNumberFormatter`.
     * @details The string used to represent a percent symbol. By default, this property is set to the percent sign (\%).
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_percent_symbol(const std::string& value) const;
        /**
     * @brief Returns the `plusSign` property of `NSNumberFormatter`.
     * @details The string used to represent a plus sign. By default, this property is set to the plus sign (+).
     * @return The converted Objective-C result.
     */
        std::string plus_sign() const;
        /**
     * @brief Sets the `plusSign` property of `NSNumberFormatter`.
     * @details The string used to represent a plus sign. By default, this property is set to the plus sign (+).
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_plus_sign(const std::string& value) const;
        /**
     * @brief Returns the `positiveFormat` property of `NSNumberFormatter`.
     * @details The format the receiver uses to display positive values.
     * @return The converted Objective-C result.
     */
        std::string positive_format() const;
        /**
     * @brief Sets the `positiveFormat` property of `NSNumberFormatter`.
     * @details The format the receiver uses to display positive values.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_positive_format(const std::string& value) const;
        /**
     * @brief Returns the `positiveInfinitySymbol` property of `NSNumberFormatter`.
     * @details The string used to represent a positive infinity symbol. By default, this property is set to the string "+\\u221e".
     * @return The converted Objective-C result.
     */
        std::string positive_infinity_symbol() const;
        /**
     * @brief Sets the `positiveInfinitySymbol` property of `NSNumberFormatter`.
     * @details The string used to represent a positive infinity symbol. By default, this property is set to the string "+\\u221e".
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_positive_infinity_symbol(const std::string& value) const;
        /**
     * @brief Returns the `positivePrefix` property of `NSNumberFormatter`.
     * @details The string the receiver uses as the prefix for positive values.
     * @return The converted Objective-C result.
     */
        std::string positive_prefix() const;
        /**
     * @brief Sets the `positivePrefix` property of `NSNumberFormatter`.
     * @details The string the receiver uses as the prefix for positive values.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_positive_prefix(const std::string& value) const;
        /**
     * @brief Returns the `positiveSuffix` property of `NSNumberFormatter`.
     * @details The string the receiver uses as the suffix for positive values.
     * @return The converted Objective-C result.
     */
        std::string positive_suffix() const;
        /**
     * @brief Sets the `positiveSuffix` property of `NSNumberFormatter`.
     * @details The string the receiver uses as the suffix for positive values.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_positive_suffix(const std::string& value) const;
        /**
     * @brief Returns the `roundingBehavior` property of `NSNumberFormatter`.
     * @details The rounding behavior used by the receiver.
     * @return The converted Objective-C result.
     */
        DecimalNumberHandler rounding_behavior() const;
        /**
     * @brief Sets the `roundingBehavior` property of `NSNumberFormatter`.
     * @details The rounding behavior used by the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_rounding_behavior(const DecimalNumberHandler& value) const;
        /**
     * @brief Returns the `roundingIncrement` property of `NSNumberFormatter`.
     * @details The rounding increment used by the receiver.
     * @return The converted Objective-C result.
     */
        Number rounding_increment() const;
        /**
     * @brief Sets the `roundingIncrement` property of `NSNumberFormatter`.
     * @details The rounding increment used by the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_rounding_increment(const Number& value) const;
        /**
     * @brief Returns the `roundingMode` property of `NSNumberFormatter`.
     * @details The rounding mode used by the receiver.
     * @return The converted Objective-C result.
     */
        NumberFormatterRoundingMode rounding_mode() const;
        /**
     * @brief Sets the `roundingMode` property of `NSNumberFormatter`.
     * @details The rounding mode used by the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_rounding_mode(NumberFormatterRoundingMode value) const;
        /**
     * @brief Returns the `secondaryGroupingSize` property of `NSNumberFormatter`.
     * @details The secondary grouping size of the receiver. Some locales allow the specification of another grouping size for larger numbers. For example, some locales may represent a number such as 61, 242, 378.46 (as in the United States) as 6,12,42,378.46. In this case, the secondary grouping size (covering the groups of digits furthest from the decimal point) is 2.
     * @return The converted Objective-C result.
     */
        std::uint64_t secondary_grouping_size() const;
        /**
     * @brief Sets the `secondaryGroupingSize` property of `NSNumberFormatter`.
     * @details The secondary grouping size of the receiver. Some locales allow the specification of another grouping size for larger numbers. For example, some locales may represent a number such as 61, 242, 378.46 (as in the United States) as 6,12,42,378.46. In this case, the secondary grouping size (covering the groups of digits furthest from the decimal point) is 2.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_secondary_grouping_size(std::uint64_t value) const;
        /**
     * @brief Returns the `textAttributesForNegativeInfinity` property of `NSNumberFormatter`.
     * @details The text attributes used to display the negative infinity symbol. This property is a dictionary that contains the text attributes used to display the negative infinity string.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> text_attributes_for_negative_infinity() const;
        /**
     * @brief Sets the `textAttributesForNegativeInfinity` property of `NSNumberFormatter`.
     * @details The text attributes used to display the negative infinity symbol. This property is a dictionary that contains the text attributes used to display the negative infinity string.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_attributes_for_negative_infinity(const std::map<std::string, Object>& value) const;
        /**
     * @brief Returns the `textAttributesForNegativeValues` property of `NSNumberFormatter`.
     * @details The text attributes to be used in displaying negative values. This property is a dictionary that contains the attributes used to display negative values.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> text_attributes_for_negative_values() const;
        /**
     * @brief Sets the `textAttributesForNegativeValues` property of `NSNumberFormatter`.
     * @details The text attributes to be used in displaying negative values. This property is a dictionary that contains the attributes used to display negative values.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_attributes_for_negative_values(const std::map<std::string, Object>& value) const;
        /**
     * @brief Returns the `textAttributesForNil` property of `NSNumberFormatter`.
     * @details The text attributes used to display the \\c nil symbol.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> text_attributes_for_nil() const;
        /**
     * @brief Sets the `textAttributesForNil` property of `NSNumberFormatter`.
     * @details The text attributes used to display the \\c nil symbol.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_attributes_for_nil(const std::map<std::string, Object>& value) const;
        /**
     * @brief Returns the `textAttributesForNotANumber` property of `NSNumberFormatter`.
     * @details The text attributes used to display the NaN ("not a number") string.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> text_attributes_for_not_a_number() const;
        /**
     * @brief Sets the `textAttributesForNotANumber` property of `NSNumberFormatter`.
     * @details The text attributes used to display the NaN ("not a number") string.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_attributes_for_not_a_number(const std::map<std::string, Object>& value) const;
        /**
     * @brief Returns the `textAttributesForPositiveInfinity` property of `NSNumberFormatter`.
     * @details The text attributes used to display the positive infinity symbol. This property is a dictionary that contains the text attributes used to display the positive infinity string.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> text_attributes_for_positive_infinity() const;
        /**
     * @brief Sets the `textAttributesForPositiveInfinity` property of `NSNumberFormatter`.
     * @details The text attributes used to display the positive infinity symbol. This property is a dictionary that contains the text attributes used to display the positive infinity string.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_attributes_for_positive_infinity(const std::map<std::string, Object>& value) const;
        /**
     * @brief Returns the `textAttributesForPositiveValues` property of `NSNumberFormatter`.
     * @details The text attributes to be used in displaying positive values. This property is a dictionary that contains the attributes used to display positive values.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> text_attributes_for_positive_values() const;
        /**
     * @brief Sets the `textAttributesForPositiveValues` property of `NSNumberFormatter`.
     * @details The text attributes to be used in displaying positive values. This property is a dictionary that contains the attributes used to display positive values.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_attributes_for_positive_values(const std::map<std::string, Object>& value) const;
        /**
     * @brief Returns the `textAttributesForZero` property of `NSNumberFormatter`.
     * @details The text attributes used to display a zero value. This property is a dictionary that contains the text attributes used to display zero values.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> text_attributes_for_zero() const;
        /**
     * @brief Sets the `textAttributesForZero` property of `NSNumberFormatter`.
     * @details The text attributes used to display a zero value. This property is a dictionary that contains the text attributes used to display zero values.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_attributes_for_zero(const std::map<std::string, Object>& value) const;
        /**
     * @brief Returns the `thousandSeparator` property of `NSNumberFormatter`.
     * @details The character the receiver uses as a thousand separator. If you don't have thousand separators enabled through any other means (such as \\c format), using this method enables them. This method is for use with formatters using \\c NSNumberFormatterBehavior10_0 behavior.
     * @return The converted Objective-C result.
     */
        std::string thousand_separator() const;
        /**
     * @brief Sets the `thousandSeparator` property of `NSNumberFormatter`.
     * @details The character the receiver uses as a thousand separator. If you don't have thousand separators enabled through any other means (such as \\c format), using this method enables them. This method is for use with formatters using \\c NSNumberFormatterBehavior10_0 behavior.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_thousand_separator(const std::string& value) const;
        /**
     * @brief Returns the `usesGroupingSeparator` property of `NSNumberFormatter`.
     * @details Determines whether the receiver displays the group separator.
     * @return The converted Objective-C result.
     */
        bool uses_grouping_separator() const;
        /**
     * @brief Sets the `usesGroupingSeparator` property of `NSNumberFormatter`.
     * @details Determines whether the receiver displays the group separator.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_grouping_separator(bool value) const;
        /**
     * @brief Returns the `usesSignificantDigits` property of `NSNumberFormatter`.
     * @details A Boolean value indicating whether the formatter uses minimum and maximum significant digits when formatting numbers. The \\c NSNumberFormatter class has two ways of determining how many digits to represent: using integer and fraction digits and using significant digits. When this property is set to \\c NO, numbers are formatted according to whether you want them formatted as fractions or as integers. This property is \\c NO by default. Set this property to \\c YES to format numbers according to the significant digits configuration specified by the \\c minimumSignificantDigits and \\c maximumSignificantDigits properties. By default, the minimum number of significant digits is 1, and the maximum number of significant digits is 6. When a number formatter is configured to use significant digits, it ignores any minimum or maximum values used to set integer or fraction digits.
     * @return The converted Objective-C result.
     */
        bool uses_significant_digits() const;
        /**
     * @brief Sets the `usesSignificantDigits` property of `NSNumberFormatter`.
     * @details A Boolean value indicating whether the formatter uses minimum and maximum significant digits when formatting numbers. The \\c NSNumberFormatter class has two ways of determining how many digits to represent: using integer and fraction digits and using significant digits. When this property is set to \\c NO, numbers are formatted according to whether you want them formatted as fractions or as integers. This property is \\c NO by default. Set this property to \\c YES to format numbers according to the significant digits configuration specified by the \\c minimumSignificantDigits and \\c maximumSignificantDigits properties. By default, the minimum number of significant digits is 1, and the maximum number of significant digits is 6. When a number formatter is configured to use significant digits, it ignores any minimum or maximum values used to set integer or fraction digits.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_significant_digits(bool value) const;
        /**
     * @brief Returns the `zeroSymbol` property of `NSNumberFormatter`.
     * @details The string used to represent a zero value. If not specified, zero values are formatted normally. You might, for example, set this property to \\c "-" in a spreadsheet used for accounting.
     * @return The converted Objective-C result.
     */
        std::string zero_symbol() const;
        /**
     * @brief Sets the `zeroSymbol` property of `NSNumberFormatter`.
     * @details The string used to represent a zero value. If not specified, zero values are formatted normally. You might, for example, set this property to \\c "-" in a spreadsheet used for accounting.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_zero_symbol(const std::string& value) const;
    };
}
