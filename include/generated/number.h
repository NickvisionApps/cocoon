#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/value.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSNumber` (Foundation).
     * @details An object wrapper for primitive scalar numeric values. 'NSNumber' is a subclass of 'NSValue' that offers a value as any C scalar (numeric) type. It defines a set of methods specifically for setting and accessing the value as a signed or unsigned 'char', 'short int', 'int', 'long int', 'long long int', 'float', or 'double' or as a 'BOOL'. (Note that number objects do not necessarily preserve the type they are created with.) It also defines a ''compare(:)'' method to determine the ordering of two 'NSNumber' objects. 'NSNumber' is "toll-free bridged" with its Core Foundation counterparts: \<doc://com.apple.documentation/documentation/corefoundation/cfnumber> for integer and floating point values, and \<doc://com.apple.documentation/documentation/corefoundation/cfboolean> for Boolean values. See [Toll-Free Bridging](https://developer.apple.com/library/archive/documentation/General/Conceptual/CocoaEncyclopedia/Toll-FreeBridgin/Toll-FreeBridgin.html\#//apple_ref/doc/uid/TP40010810-CH2) for more information on toll-free bridging. \#\#\# Value Conversions 'NSNumber' provides readonly properties that return the object's stored value converted to a particular Boolean, integer, unsigned integer, or floating point C scalar type. Because numeric types have different storage capabilities, attempting to initialize with a value of one type and access the value of another type may produce an erroneous result—for example, initializing with a 'double' value exceeding 'FLT_MAX' and accessing its ''floatValue'', or initializing with an negative integer value and accessing its ''uintValue''. In some cases, attempting to initialize with a value of a type and access the value of another type may result in loss of precision—for example, initializing with a 'double' value with many significant digits and accessing its ''floatValue'', or initializing with a large integer value and accessing its ''int8Value''. An 'NSNumber' object initialized with a value of a particular type accessing the converted value of a different kind of type, such as 'unsigned int' and 'float', will convert its stored value to that converted type in the following ways: | 'Value' | ''boolValue'' | ''intValue-95zzp'' | ''uintValue'' | ''floatValue'' | |---|---|---|---|---| | \<doc://com.apple.documentation/documentation/swift/false> | \<doc://com.apple.documentation/documentation/swift/false> | '0' | '0' | '0.0' | | \<doc://com.apple.documentation/documentation/swift/true> | \<doc://com.apple.documentation/documentation/swift/true> | '1' | '1' | '1.0' | | 'Value' | ''boolValue'' | ''intValue-95zzp'' | ''uintValue'' | ''floatValue'' | |---|---|---|---|---| | '0' | \<doc://com.apple.documentation/documentation/swift/false> | '0' | '0' | '0.0' | | '1' | \<doc://com.apple.documentation/documentation/swift/true> | '1' | '1' | '1.0' | | '-1' | \<doc://com.apple.documentation/documentation/swift/true> | '-1' | invalid, erroneous result | '-1.0' | | 'Value' | ''boolValue'' | ''intValue-95zzp'' | ''uintValue'' | ''floatValue'' | |---|---|---|---|---| | '0' | \<doc://com.apple.documentation/documentation/swift/false> | '0' | '0' | '0.0' | | '1' | \<doc://com.apple.documentation/documentation/swift/true> | '1' | '1' | '1.0' | | 'Value' | ''boolValue'' | ''intValue-95zzp'' | ''uintValue'' | ''floatValue'' | |---|---|---|---|---| | '0.0' | \<doc://com.apple.documentation/documentation/swift/false> | '0' | '0' | '0.0' | | '1.0' | \<doc://com.apple.documentation/documentation/swift/true> | '1' | '1' | '1.0' | | '-1.0' | \<doc://com.apple.documentation/documentation/swift/true> | '-1' | invalid, erroneous result | '-1.0' | \#\#\# Subclassing Notes As with any class cluster, subclasses of 'NSNumber' must override the primitive methods of its superclass, 'NSValue'. In addition, there are two requirements around the data type your subclass represents: 1. Your implementation of ''NSValue/objCType'' must return one of "'c'", "'C'", "'s'", "'S'", "'i'", "'I'", "'l'", "'L'", "'q'", "'Q'", "'f'", and "'d'". This is required for the other methods of ''NSNumber'' to behave correctly. 2. Your subclass must override the accessor method that corresponds to the declared type—for example, if your implementation of ''NSValue/objCType'' returns "'i'", you must override ''int32Value''.
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
     * @details Returns an 'NSComparisonResult' value that indicates whether the number object's value is greater than, equal to, or less than a given number. - Parameter otherNumber: The number to compare to the number object's value. This value must not be 'nil'. - Returns: 'NSOrderedAscending' if the value of 'otherNumber' is greater than the number object's, 'NSOrderedSame' if they're equal, and 'NSOrderedDescending' if the value of 'otherNumber' is less than the number object's. The ''NSNumber/compare:'' method follows the standard C rules for type conversion. For example, if you compare an 'NSNumber' object that has an integer value with an 'NSNumber' object that has a floating point value, the integer value is converted to a floating-point value for comparison.
     * @param other_number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ComparisonResult compare(const Number& other_number) const;
        /**
     * @brief Calls `-[NSNumber descriptionWithLocale:]`.
     * @details Returns a string that represents the contents of the number object for a given locale. - Parameter locale: An object containing locale information with which to format the description. Use 'nil' if you don't want the description formatted. - Returns: A string that represents the contents of the number object formatted using the locale information in 'locale'.
     * @param locale Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string description_with_locale(const Object& locale) const;
        /**
     * @brief Calls `-[NSNumber isEqualToNumber:]`.
     * @details Returns a Boolean value that indicates whether the number object's value and a given number are equal. - Parameter number: The number to compare to the number object's value. - Returns: 'YES' if the number object's value and 'number' are equal; otherwise, 'NO'. Two 'NSNumber' objects are considered equal if they have the same id values or if they have equivalent values (as determined by the ''NSNumber/compare:'' method). This method is more efficient than ''NSNumber/compare:'' if you know the two objects are numbers.
     * @param number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_equal_to_number(const Number& number) const;
        /**
     * @brief Calls `+[NSNumber numberWithBool:]`.
     * @details Creates and returns an 'NSNumber' object containing a given value, treating it as a 'BOOL'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_bool(bool value);
        /**
     * @brief Calls `+[NSNumber numberWithChar:]`.
     * @details Creates and returns an 'NSNumber' object containing a given value, treating it as a 'char'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_char(std::int8_t value);
        /**
     * @brief Calls `+[NSNumber numberWithDouble:]`.
     * @details Creates and returns an 'NSNumber' object containing a given value, treating it as a 'double'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_double(double value);
        /**
     * @brief Calls `+[NSNumber numberWithFloat:]`.
     * @details Creates and returns an 'NSNumber' object containing a given value, treating it as a 'float'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_float(float value);
        /**
     * @brief Calls `+[NSNumber numberWithInt:]`.
     * @details Creates and returns an 'NSNumber' object containing a given value, treating it as an 'int'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_int(int value);
        /**
     * @brief Calls `+[NSNumber numberWithInteger:]`.
     * @details Creates and returns an 'NSNumber' object containing a given value, treating it as an 'NSInteger'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_integer(std::int64_t value);
        /**
     * @brief Calls `+[NSNumber numberWithLong:]`.
     * @details Creates and returns an 'NSNumber' object containing a given value, treating it as a 'long'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_long(std::int64_t value);
        /**
     * @brief Calls `+[NSNumber numberWithLongLong:]`.
     * @details Creates and returns an 'NSNumber' object containing a given value, treating it as a 'long long'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_long_long(std::int64_t value);
        /**
     * @brief Calls `+[NSNumber numberWithShort:]`.
     * @details Creates and returns an 'NSNumber' object containing a given value, treating it as a 'short'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_short(std::int16_t value);
        /**
     * @brief Calls `+[NSNumber numberWithUnsignedChar:]`.
     * @details Creates and returns an 'NSNumber' object containing a given value, treating it as an 'unsigned char'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_unsigned_char(std::uint8_t value);
        /**
     * @brief Calls `+[NSNumber numberWithUnsignedInt:]`.
     * @details Creates and returns an 'NSNumber' object containing a given value, treating it as an 'unsigned int'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_unsigned_int(unsigned int value);
        /**
     * @brief Calls `+[NSNumber numberWithUnsignedInteger:]`.
     * @details Creates and returns an 'NSNumber' object containing a given value, treating it as an 'NSUInteger'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_unsigned_integer(std::uint64_t value);
        /**
     * @brief Calls `+[NSNumber numberWithUnsignedLong:]`.
     * @details Creates and returns an 'NSNumber' object containing a given value, treating it as an 'unsigned long'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_unsigned_long(std::uint64_t value);
        /**
     * @brief Calls `+[NSNumber numberWithUnsignedLongLong:]`.
     * @details Creates and returns an 'NSNumber' object containing a given value, treating it as an 'unsigned long long'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_unsigned_long_long(std::uint64_t value);
        /**
     * @brief Calls `+[NSNumber numberWithUnsignedShort:]`.
     * @details Creates and returns an 'NSNumber' object containing a given value, treating it as an 'unsigned short'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Number number_with_unsigned_short(std::uint16_t value);
        /**
     * @brief Returns the `boolValue` property of `NSNumber`.
     * @details The number object's value expressed as a Boolean value. A '0' value always means 'NO', and any nonzero value is interpreted as 'YES'.
     * @return The converted Objective-C result.
     */
        bool bool_value() const;
        /**
     * @brief Returns the `charValue` property of `NSNumber`.
     * @details The number object's value expressed as a 'char'.
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
     * @details The number object's value expressed as a 'double'.
     * @return The converted Objective-C result.
     */
        double double_value() const;
        /**
     * @brief Returns the `floatValue` property of `NSNumber`.
     * @details The number object's value expressed as a 'float'.
     * @return The converted Objective-C result.
     */
        float float_value() const;
        /**
     * @brief Returns the `intValue` property of `NSNumber`.
     * @details The number object's value expressed as an 'int'.
     * @return The converted Objective-C result.
     */
        int int_value() const;
        /**
     * @brief Returns the `integerValue` property of `NSNumber`.
     * @details The number object's value expressed as an 'NSInteger'.
     * @return The converted Objective-C result.
     */
        std::int64_t integer_value() const;
        /**
     * @brief Returns the `longLongValue` property of `NSNumber`.
     * @details The number object's value expressed as a 'long long'.
     * @return The converted Objective-C result.
     */
        std::int64_t long_long_value() const;
        /**
     * @brief Returns the `longValue` property of `NSNumber`.
     * @details The number object's value expressed as a 'long'.
     * @return The converted Objective-C result.
     */
        std::int64_t long_value() const;
        /**
     * @brief Returns the `shortValue` property of `NSNumber`.
     * @details The number object's value expressed as a 'short'.
     * @return The converted Objective-C result.
     */
        std::int16_t short_value() const;
        /**
     * @brief Returns the `stringValue` property of `NSNumber`.
     * @details The number object's value expressed as a human-readable string. The string is created by invoking ''NSNumber/descriptionWithLocale:'' where locale is 'nil'.
     * @return The converted Objective-C result.
     */
        std::string string_value() const;
        /**
     * @brief Returns the `unsignedCharValue` property of `NSNumber`.
     * @details The number object's value expressed as an 'unsigned char'.
     * @return The converted Objective-C result.
     */
        std::uint8_t unsigned_char_value() const;
        /**
     * @brief Returns the `unsignedIntValue` property of `NSNumber`.
     * @details The number object's value expressed as an 'unsigned int'.
     * @return The converted Objective-C result.
     */
        unsigned int unsigned_int_value() const;
        /**
     * @brief Returns the `unsignedIntegerValue` property of `NSNumber`.
     * @details The number object's value expressed as an 'NSUInteger'.
     * @return The converted Objective-C result.
     */
        std::uint64_t unsigned_integer_value() const;
        /**
     * @brief Returns the `unsignedLongLongValue` property of `NSNumber`.
     * @details The number object's value expressed as an 'unsigned long long'.
     * @return The converted Objective-C result.
     */
        std::uint64_t unsigned_long_long_value() const;
        /**
     * @brief Returns the `unsignedLongValue` property of `NSNumber`.
     * @details The number object's value expressed as an 'unsigned long'.
     * @return The converted Objective-C result.
     */
        std::uint64_t unsigned_long_value() const;
        /**
     * @brief Returns the `unsignedShortValue` property of `NSNumber`.
     * @details The number object's value expressed as an 'unsigned short'.
     * @return The converted Objective-C result.
     */
        std::uint16_t unsigned_short_value() const;
    };
}
