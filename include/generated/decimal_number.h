#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/number.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Number;

    /**
     * @brief C++ handle for the Objective-C class `NSDecimalNumber` (Foundation).
     * @details NSDecimalNumber: the class
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Number.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DecimalNumber decimal_number;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DecimalNumber decimal_number{};
     * auto made_0 = cocoon::DecimalNumber::decimal_number_with_mantissa(1, 1, true);
     * auto made_1 = cocoon::DecimalNumber::decimal_number_with_string("text");
     * decimal_number.compare(cocoon::Number());
     * decimal_number.decimal_number_by_adding(cocoon::DecimalNumber());
     * decimal_number.decimal_number_by_dividing_by(cocoon::DecimalNumber());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsdecimalnumber
     */
    class DecimalNumber : public Number
    {
    public:
        /// @brief Creates a new `NSDecimalNumber` instance and returns a handle to it.
        explicit DecimalNumber(const Decimal& dcm);
        /// @brief Creates a new `NSDecimalNumber` instance and returns a handle to it.
        explicit DecimalNumber(std::uint64_t mantissa, std::int16_t exponent, bool flag);
        /// @brief Creates a new `NSDecimalNumber` instance and returns a handle to it.
        explicit DecimalNumber(const std::string& number_value);
        /// @brief Creates a new `NSDecimalNumber` instance and returns a handle to it.
        explicit DecimalNumber(const std::string& number_value, const Object& locale);
        /// @brief Creates a new `NSDecimalNumber` instance and returns a handle to it.
        explicit DecimalNumber();
        /// @brief Creates a null handle that refers to no native object.
        DecimalNumber(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DecimalNumber(Adopt adopt);
        using Number::compare;
        using Number::decimal_value;
        using Number::description_with_locale;
        using Number::double_value;
        using Value::obj_c_type;
        /**
     * @brief Calls `-[NSDecimalNumber compare:]`.
     * @param decimal_number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ComparisonResult compare(const Number& decimal_number) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByAdding:]`.
     * @param decimal_number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_adding(const DecimalNumber& decimal_number) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByAdding:withBehavior:]`.
     * @param decimal_number Argument converted to the Objective-C parameter of the same role.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_adding(const DecimalNumber& decimal_number, const Object& behavior) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByDividingBy:]`.
     * @param decimal_number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_dividing_by(const DecimalNumber& decimal_number) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByDividingBy:withBehavior:]`.
     * @param decimal_number Argument converted to the Objective-C parameter of the same role.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_dividing_by(const DecimalNumber& decimal_number, const Object& behavior) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByMultiplyingBy:]`.
     * @param decimal_number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_multiplying_by(const DecimalNumber& decimal_number) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByMultiplyingBy:withBehavior:]`.
     * @param decimal_number Argument converted to the Objective-C parameter of the same role.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_multiplying_by(const DecimalNumber& decimal_number, const Object& behavior) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByMultiplyingByPowerOf10:]`.
     * @param power Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_multiplying_by_power_of10(std::int16_t power) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByMultiplyingByPowerOf10:withBehavior:]`.
     * @param power Argument converted to the Objective-C parameter of the same role.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_multiplying_by_power_of10(std::int16_t power, const Object& behavior) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByRaisingToPower:]`.
     * @param power Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_raising_to_power(std::uint64_t power) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByRaisingToPower:withBehavior:]`.
     * @param power Argument converted to the Objective-C parameter of the same role.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_raising_to_power(std::uint64_t power, const Object& behavior) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByRoundingAccordingToBehavior:]`.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_rounding_according_to_behavior(const Object& behavior) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberBySubtracting:]`.
     * @param decimal_number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_subtracting(const DecimalNumber& decimal_number) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberBySubtracting:withBehavior:]`.
     * @param decimal_number Argument converted to the Objective-C parameter of the same role.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_subtracting(const DecimalNumber& decimal_number, const Object& behavior) const;
        /**
     * @brief Calls `+[NSDecimalNumber decimalNumberWithDecimal:]`.
     * @param dcm Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static DecimalNumber decimal_number_with_decimal(const Decimal& dcm);
        /**
     * @brief Calls `+[NSDecimalNumber decimalNumberWithMantissa:exponent:isNegative:]`.
     * @param mantissa Argument converted to the Objective-C parameter of the same role.
     * @param exponent Argument converted to the Objective-C parameter of the same role.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static DecimalNumber decimal_number_with_mantissa(std::uint64_t mantissa, std::int16_t exponent, bool flag);
        /**
     * @brief Calls `+[NSDecimalNumber decimalNumberWithString:]`.
     * @param number_value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static DecimalNumber decimal_number_with_string(const std::string& number_value);
        /**
     * @brief Calls `+[NSDecimalNumber decimalNumberWithString:locale:]`.
     * @param number_value Argument converted to the Objective-C parameter of the same role.
     * @param locale Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static DecimalNumber decimal_number_with_string(const std::string& number_value, const Object& locale);
        /**
     * @brief Calls `-[NSDecimalNumber descriptionWithLocale:]`.
     * @param locale Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string description_with_locale(const Object& locale) const;
        /**
     * @brief Returns the `decimalValue` property of `NSDecimalNumber`.
     * @return The converted Objective-C result.
     */
        Decimal decimal_value() const;
        /**
     * @brief Returns the `defaultBehavior` property of `NSDecimalNumber`.
     * @return The converted Objective-C result.
     */
        static Object default_behavior();
        /**
     * @brief Sets the `defaultBehavior` property of `NSDecimalNumber`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_default_behavior(const Object& value);
        /**
     * @brief Returns the `doubleValue` property of `NSDecimalNumber`.
     * @return The converted Objective-C result.
     */
        double double_value() const;
        /**
     * @brief Returns the `maximumDecimalNumber` property of `NSDecimalNumber`.
     * @return The converted Objective-C result.
     */
        static DecimalNumber maximum_decimal_number();
        /**
     * @brief Returns the `minimumDecimalNumber` property of `NSDecimalNumber`.
     * @return The converted Objective-C result.
     */
        static DecimalNumber minimum_decimal_number();
        /**
     * @brief Returns the `notANumber` property of `NSDecimalNumber`.
     * @return The converted Objective-C result.
     */
        static DecimalNumber not_a_number();
        /**
     * @brief Returns the `objCType` property of `NSDecimalNumber`.
     * @return The converted Objective-C result.
     */
        std::string obj_c_type() const;
        /**
     * @brief Returns the `one` property of `NSDecimalNumber`.
     * @return The converted Objective-C result.
     */
        static DecimalNumber one();
        /**
     * @brief Returns the `zero` property of `NSDecimalNumber`.
     * @return The converted Objective-C result.
     */
        static DecimalNumber zero();
    };
}
