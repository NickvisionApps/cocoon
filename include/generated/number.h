#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/value.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSNumber` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Value.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Number number;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Number number{};
     * auto made_0 = cocoon::Number::number_with_bool(true);
     * auto made_1 = cocoon::Number::number_with_char(1);
     * number.compare(cocoon::Number());
     * number.is_equal_to_number(cocoon::Number());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsnumber
     */
    class Number : public Value
    {
    public:
        /// @brief Creates a new `NSNumber` instance and returns a handle to it.
        explicit Number(bool value);
        /// @brief Creates a new `NSNumber` instance and returns a handle to it.
        explicit Number(std::int8_t value);
        /// @brief Creates a new `NSNumber` instance and returns a handle to it.
        explicit Number(double value);
        /// @brief Creates a new `NSNumber` instance and returns a handle to it.
        explicit Number(float value);
        /// @brief Creates a new `NSNumber` instance and returns a handle to it.
        explicit Number(int value);
        /// @brief Creates a new `NSNumber` instance and returns a handle to it.
        explicit Number(std::int64_t value);
        /// @brief Creates a new `NSNumber` instance and returns a handle to it.
        explicit Number(std::int16_t value);
        /// @brief Creates a new `NSNumber` instance and returns a handle to it.
        explicit Number(std::uint8_t value);
        /// @brief Creates a new `NSNumber` instance and returns a handle to it.
        explicit Number(unsigned int value);
        /// @brief Creates a new `NSNumber` instance and returns a handle to it.
        explicit Number(std::uint64_t value);
        /// @brief Creates a new `NSNumber` instance and returns a handle to it.
        explicit Number(std::uint16_t value);
        /// @brief Creates a new `NSNumber` instance and returns a handle to it.
        explicit Number();
        /// @brief Creates a null handle that refers to no native object.
        Number(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Number(Adopt adopt);
        /**
     * @brief Calls `-[NSNumber compare:]`.
     * @param other_number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ComparisonResult compare(const Number& other_number) const;
        /**
     * @brief Calls `-[NSNumber descriptionWithLocale:]`.
     * @param locale Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string description_with_locale(const Object& locale) const;
        /**
     * @brief Calls `-[NSNumber isEqualToNumber:]`.
     * @param number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_equal_to_number(const Number& number) const;
        /**
     * @brief Calls `+[NSNumber numberWithBool:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_bool(bool value);
        /**
     * @brief Calls `+[NSNumber numberWithChar:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_char(std::int8_t value);
        /**
     * @brief Calls `+[NSNumber numberWithDouble:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_double(double value);
        /**
     * @brief Calls `+[NSNumber numberWithFloat:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_float(float value);
        /**
     * @brief Calls `+[NSNumber numberWithInt:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_int(int value);
        /**
     * @brief Calls `+[NSNumber numberWithInteger:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_integer(std::int64_t value);
        /**
     * @brief Calls `+[NSNumber numberWithLong:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_long(std::int64_t value);
        /**
     * @brief Calls `+[NSNumber numberWithLongLong:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_long_long(std::int64_t value);
        /**
     * @brief Calls `+[NSNumber numberWithShort:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_short(std::int16_t value);
        /**
     * @brief Calls `+[NSNumber numberWithUnsignedChar:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_unsigned_char(std::uint8_t value);
        /**
     * @brief Calls `+[NSNumber numberWithUnsignedInt:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_unsigned_int(unsigned int value);
        /**
     * @brief Calls `+[NSNumber numberWithUnsignedInteger:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_unsigned_integer(std::uint64_t value);
        /**
     * @brief Calls `+[NSNumber numberWithUnsignedLong:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_unsigned_long(std::uint64_t value);
        /**
     * @brief Calls `+[NSNumber numberWithUnsignedLongLong:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_unsigned_long_long(std::uint64_t value);
        /**
     * @brief Calls `+[NSNumber numberWithUnsignedShort:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_unsigned_short(std::uint16_t value);
        /**
     * @brief Returns the `boolValue` property of `NSNumber`.
     * @return The converted Objective-C result.
     */
        bool bool_value() const;
        /**
     * @brief Returns the `charValue` property of `NSNumber`.
     * @return The converted Objective-C result.
     */
        std::int8_t char_value() const;
        /**
     * @brief Returns the `decimalValue` property of `NSNumber`.
     * @return The converted Objective-C result.
     */
        Decimal decimal_value() const;
        /**
     * @brief Returns the `doubleValue` property of `NSNumber`.
     * @return The converted Objective-C result.
     */
        double double_value() const;
        /**
     * @brief Returns the `floatValue` property of `NSNumber`.
     * @return The converted Objective-C result.
     */
        float float_value() const;
        /**
     * @brief Returns the `intValue` property of `NSNumber`.
     * @return The converted Objective-C result.
     */
        int int_value() const;
        /**
     * @brief Returns the `integerValue` property of `NSNumber`.
     * @return The converted Objective-C result.
     */
        std::int64_t integer_value() const;
        /**
     * @brief Returns the `longLongValue` property of `NSNumber`.
     * @return The converted Objective-C result.
     */
        std::int64_t long_long_value() const;
        /**
     * @brief Returns the `longValue` property of `NSNumber`.
     * @return The converted Objective-C result.
     */
        std::int64_t long_value() const;
        /**
     * @brief Returns the `shortValue` property of `NSNumber`.
     * @return The converted Objective-C result.
     */
        std::int16_t short_value() const;
        /**
     * @brief Returns the `stringValue` property of `NSNumber`.
     * @return The converted Objective-C result.
     */
        std::string string_value() const;
        /**
     * @brief Returns the `unsignedCharValue` property of `NSNumber`.
     * @return The converted Objective-C result.
     */
        std::uint8_t unsigned_char_value() const;
        /**
     * @brief Returns the `unsignedIntValue` property of `NSNumber`.
     * @return The converted Objective-C result.
     */
        unsigned int unsigned_int_value() const;
        /**
     * @brief Returns the `unsignedIntegerValue` property of `NSNumber`.
     * @return The converted Objective-C result.
     */
        std::uint64_t unsigned_integer_value() const;
        /**
     * @brief Returns the `unsignedLongLongValue` property of `NSNumber`.
     * @return The converted Objective-C result.
     */
        std::uint64_t unsigned_long_long_value() const;
        /**
     * @brief Returns the `unsignedLongValue` property of `NSNumber`.
     * @return The converted Objective-C result.
     */
        std::uint64_t unsigned_long_value() const;
        /**
     * @brief Returns the `unsignedShortValue` property of `NSNumber`.
     * @return The converted Objective-C result.
     */
        std::uint16_t unsigned_short_value() const;
    };
}
