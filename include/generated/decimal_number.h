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
     * @details An object for representing and performing arithmetic on base-10 numbers. In Swift, this object bridges to ''Decimal''; use ''NSDecimalNumber'' when you need reference semantics or other Foundation-specific behavior. 'NSDecimalNumber', an immutable subclass of 'NSNumber', provides an object-oriented wrapper for doing base-10 arithmetic. An instance can represent any number that can be expressed as 'mantissa x 10^exponent' where mantissa is a decimal integer up to 38 digits long, and exponent is an integer from –128 through 127. > Important: > The Swift overlay to the Foundation framework provides the ''Decimal'' structure, which bridges to the ''NSDecimalNumber'' class. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>.
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
     * @details Compares this decimal number to another number. - Parameter decimalNumber: The number to compare. This value must not be 'nil'. - Returns: 'NSOrderedAscending' if the value of 'decimalNumber' is greater than the receiver, 'NSOrderedSame' if they're equal, and 'NSOrderedDescending' if 'decimalNumber' is less.
     * @param decimal_number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ComparisonResult compare(const Number& decimal_number) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByAdding:]`.
     * @details Adds this number to another given number. - Parameter decimalNumber: The number to add to the receiver. - Returns: A new 'NSDecimalNumber' object whose value is the sum of the receiver and 'decimalNumber'. This method uses the default behavior when handling calculation errors and rounding.
     * @param decimal_number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_adding(const DecimalNumber& decimal_number) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByAdding:withBehavior:]`.
     * @details Adds this number to another given number using the specified behavior. - Parameters: - decimalNumber: The number to add to the receiver. - behavior: The behavior for handling calculation errors and rounding.
     * @param decimal_number Argument converted to the Objective-C parameter of the same role.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_adding(const DecimalNumber& decimal_number, const Object& behavior) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByDividingBy:]`.
     * @details Divides the number by another given number. - Parameter decimalNumber: The number by which to divide the receiver. - Returns: A new 'NSDecimalNumber' object whose value is the value of the receiver divided by 'decimalNumber'. This method uses the default behavior when handling calculation errors and rounding.
     * @param decimal_number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_dividing_by(const DecimalNumber& decimal_number) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByDividingBy:withBehavior:]`.
     * @details Divides the number by another given number using the specified behavior. - Parameters: - decimalNumber: The number by which to divide the receiver. - behavior: The behavior for handling calculation errors and rounding.
     * @param decimal_number Argument converted to the Objective-C parameter of the same role.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_dividing_by(const DecimalNumber& decimal_number, const Object& behavior) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByMultiplyingBy:]`.
     * @details Multiplies the number by another given number. - Parameter decimalNumber: The number by which to multiply the receiver. - Returns: A new 'NSDecimalNumber' object whose value is the receiver multiplied by 'decimalNumber'. This method uses the default behavior when handling calculation errors and rounding.
     * @param decimal_number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_multiplying_by(const DecimalNumber& decimal_number) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByMultiplyingBy:withBehavior:]`.
     * @details Multiplies the number by another given number using the specified behavior. - Parameters: - decimalNumber: The number by which to multiply the receiver. - behavior: The behavior for handling calculation errors and rounding.
     * @param decimal_number Argument converted to the Objective-C parameter of the same role.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_multiplying_by(const DecimalNumber& decimal_number, const Object& behavior) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByMultiplyingByPowerOf10:]`.
     * @details Multiplies the number by 10 raised to the given power. This method uses the default behavior when handling calculation errors and rounding.
     * @param power Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_multiplying_by_power_of10(std::int16_t power) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByMultiplyingByPowerOf10:withBehavior:]`.
     * @details Multiplies the number by 10 raised to the given power using the specified behavior.
     * @param power Argument converted to the Objective-C parameter of the same role.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_multiplying_by_power_of10(std::int16_t power, const Object& behavior) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByRaisingToPower:]`.
     * @details Raises the number to a given power. - Parameter power: The power to which to raise the receiver. - Returns: A new 'NSDecimalNumber' object whose value is the value of the receiver raised to the power 'power'. This method uses the default behavior when handling calculation errors and rounding.
     * @param power Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_raising_to_power(std::uint64_t power) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByRaisingToPower:withBehavior:]`.
     * @details Raises the number to a given power using the specified behavior. - Parameters: - power: The power to which to raise the receiver. - behavior: The behavior for handling calculation errors and rounding.
     * @param power Argument converted to the Objective-C parameter of the same role.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_raising_to_power(std::uint64_t power, const Object& behavior) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberByRoundingAccordingToBehavior:]`.
     * @details Returns a rounded version of the decimal number using the specified rounding behavior. - Parameter behavior: The rounding behavior to apply. The scale of the behavior determines the number of digits a rounded value is allowed to have after the decimal separator.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_rounding_according_to_behavior(const Object& behavior) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberBySubtracting:]`.
     * @details Subtracts another given number from this one. - Parameter decimalNumber: The number to subtract from the receiver. - Returns: A new 'NSDecimalNumber' object whose value is the receiver minus 'decimalNumber'. This method uses the default behavior when handling calculation errors and rounding.
     * @param decimal_number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_subtracting(const DecimalNumber& decimal_number) const;
        /**
     * @brief Calls `-[NSDecimalNumber decimalNumberBySubtracting:withBehavior:]`.
     * @details Subtracts another given number from this one using the specified behavior. - Parameters: - decimalNumber: The number to subtract from the receiver. - behavior: The behavior for handling calculation errors and rounding.
     * @param decimal_number Argument converted to the Objective-C parameter of the same role.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DecimalNumber decimal_number_by_subtracting(const DecimalNumber& decimal_number, const Object& behavior) const;
        /**
     * @brief Calls `-[NSDecimalNumber descriptionWithLocale:]`.
     * @details Returns a string that represents the contents of the decimal number for a given locale. - Parameter locale: An object containing locale information with which to format the description. - Returns: A string that represents the contents of the decimal number formatted using the locale information in 'locale'.
     * @param locale Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string description_with_locale(const Object& locale) const;
        /**
     * @brief Returns the `decimalValue` property of `NSDecimalNumber`.
     * @details The decimal value of the number.
     * @return The converted Objective-C result.
     */
        Decimal decimal_value() const;
        /**
     * @brief Returns the `defaultBehavior` property of `NSDecimalNumber`.
     * @details The way arithmetic methods round off and handle error conditions. By default, the arithmetic methods use the ''NSDecimalNumberHandler/defaultDecimalNumberHandler'' behavior: 'NSRoundPlain' rounding, assuming precision does not exceed 38 significant digits, and raising exceptions on overflow, underflow, and divide by zero. If this default behavior doesn't suit your application, you should use methods that let you specify the behavior, like ''adding(:withBehavior:)''. If you find yourself using a particular behavior consistently, you can specify a different default behavior with 'setDefaultBehavior(:)'. The default behavior is maintained separately for each thread in your app.
     * @return The converted Objective-C result.
     */
        static Object default_behavior();
        /**
     * @brief Sets the `defaultBehavior` property of `NSDecimalNumber`.
     * @details The way arithmetic methods round off and handle error conditions. By default, the arithmetic methods use the ''NSDecimalNumberHandler/defaultDecimalNumberHandler'' behavior: 'NSRoundPlain' rounding, assuming precision does not exceed 38 significant digits, and raising exceptions on overflow, underflow, and divide by zero. If this default behavior doesn't suit your application, you should use methods that let you specify the behavior, like ''adding(:withBehavior:)''. If you find yourself using a particular behavior consistently, you can specify a different default behavior with 'setDefaultBehavior(:)'. The default behavior is maintained separately for each thread in your app.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_default_behavior(const Object& value);
        /**
     * @brief Returns the `doubleValue` property of `NSDecimalNumber`.
     * @details An approximate 'double' value for the decimal number.
     * @return The converted Objective-C result.
     */
        double double_value() const;
        /**
     * @brief Returns the `maximumDecimalNumber` property of `NSDecimalNumber`.
     * @details The largest possible value of a decimal number.
     * @return The converted Objective-C result.
     */
        static DecimalNumber maximum_decimal_number();
        /**
     * @brief Returns the `minimumDecimalNumber` property of `NSDecimalNumber`.
     * @details The smallest possible value of a decimal number.
     * @return The converted Objective-C result.
     */
        static DecimalNumber minimum_decimal_number();
        /**
     * @brief Returns the `notANumber` property of `NSDecimalNumber`.
     * @details A decimal number that specifies no number. Any arithmetic method receiving 'notANumber' as an argument returns 'notANumber'.
     * @return The converted Objective-C result.
     */
        static DecimalNumber not_a_number();
        /**
     * @brief Returns the `objCType` property of `NSDecimalNumber`.
     * @details A C string containing the Objective-C type of the data contained in the decimal number object. Returns '"d"' (for 'double').
     * @return The converted Objective-C result.
     */
        std::string obj_c_type() const;
        /**
     * @brief Returns the `one` property of `NSDecimalNumber`.
     * @details A decimal number equivalent to the number 1.
     * @return The converted Objective-C result.
     */
        static DecimalNumber one();
        /**
     * @brief Returns the `zero` property of `NSDecimalNumber`.
     * @details A decimal number equivalent to the number 0.
     * @return The converted Objective-C result.
     */
        static DecimalNumber zero();
    };
}
