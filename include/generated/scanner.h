#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CharacterSet;

    /**
     * @brief C++ handle for the Objective-C class `NSScanner` (Foundation).
     * @details A string parser that scans for substrings or characters in a character set, and for numeric values from decimal, hexadecimal, and floating-point representations. A ''Scanner'' object interprets and converts the characters of a \<doc://com.apple.documentation/documentation/swift/string> into number and string values. You assign the scanner's string when you create the scanner, and the scanner progresses through the characters of that string from beginning to end as you request items. Because of the nature of class clusters, a scanner object isn't an actual instance of the ''Scanner'' class, but is one of its private subclasses. Although a scanner object's class is private, its interface is public, as declared by this abstract superclass, ''Scanner''. The objects you create using this class are referred to as scanner objects (and when no confusion will result, merely as scanners). To set a ''Scanner'' object to ignore a set of characters as it scans the string, use the ''charactersToBeSkipped'' property. Characters in the skip set are skipped over before the target is scanned. The default set of characters to skip is the whitespace and newline character set. To retrieve the unscanned remainder of the string, use 'scanner.string.substring(from: scanner.scanLocation)'.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Scanner scanner;
     * scanner.set_case_sensitive(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Scanner scanner{};
     * scanner.set_case_sensitive(true);
     * auto case_sensitive = scanner.case_sensitive();
     * scanner.set_characters_to_be_skipped(cocoon::CharacterSet());
     * auto characters_to_be_skipped = scanner.characters_to_be_skipped();
     * scanner.set_scan_location(1);
     * auto scan_location = scanner.scan_location();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsscanner
     */
    class Scanner : public Object
    {
    public:
        /// @brief Creates a new `NSScanner` instance and returns a handle to it.
        explicit Scanner(const std::string& string);
        /// @brief Creates a new `NSScanner` instance and returns a handle to it.
        explicit Scanner();
        /// @brief Creates a null handle that refers to no native object.
        Scanner(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Scanner(Adopt adopt);
        /**
         * @brief Calls `+[NSScanner localizedScannerWithString:]`.
         * @details Returns an 'NSScanner' object that scans a given string according to the user's default locale. Sets the string to scan by invoking -initWithString: with 'aString'. The locale is set with the user's default locale. - Parameter string: The string to scan. - Returns: An 'NSScanner' object that scans 'aString' according to the user's default locale.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object localized_scanner_with_string(const std::string& string);
        /**
         * @brief Calls `-[NSScanner scanCharactersFromSet:intoString:]`.
         * @details Scans the string as long as characters from a given character set are encountered, accumulating characters into a string that's returned by reference. Invoke this method with 'NULL' as 'stringValue' to simply scan past a given set of characters. - Parameters: - set: The set of characters to scan. - result: Upon return, contains the characters scanned. - Returns: 'YES' if the receiver scanned any characters, otherwise 'NO'.
         * @param set Argument converted to the Objective-C parameter of the same role.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_characters_from_set(const CharacterSet& set, std::string& result) const;
        /**
         * @brief Calls `-[NSScanner scanDecimal:]`.
         * @param dcm Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_decimal(Decimal* dcm) const;
        /**
         * @brief Calls `-[NSScanner scanDouble:]`.
         * @details Scans for a double value, returning a found value by reference. Skips past excess digits in the case of overflow, so the scanner's position is past the entire floating-point representation. Invoke this method with 'NULL' as 'doubleValue' to simply scan past a double value representation. Floating-point representations are assumed to be IEEE compliant. - Parameter result: Upon return, contains the scanned value. Contains 'HUGE_VAL' or '-HUGE_VAL' on overflow, or '0.0' on underflow. - Returns: 'YES' if the receiver finds a valid floating-point representation, otherwise 'NO'. Overflow or underflow are both considered valid floating-point representations.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_double(double* result) const;
        /**
         * @brief Calls `-[NSScanner scanFloat:]`.
         * @details Scans for a float value, returning a found value by reference. Skips past excess digits in the case of overflow, so the scanner's position is past the entire floating-point representation. Invoke this method with 'NULL' as 'floatValue' to simply scan past a float value representation. Floating-point representations are assumed to be IEEE compliant. - Parameter result: Upon return, contains the scanned value. Contains 'HUGE_VAL' or '-HUGE_VAL' on overflow, or '0.0' on underflow. - Returns: 'YES' if the receiver finds a valid floating-point representation, otherwise 'NO'. Overflow or underflow are both considered valid floating-point representations.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_float(float* result) const;
        /**
         * @brief Calls `-[NSScanner scanHexDouble:]`.
         * @details Scans for a double value from a hexadecimal representation, returning a found value by reference. This corresponds to '\%a' or '\%A' formatting. The hexadecimal double representation must be preceded by '0x' or '0X'. Skips past excess digits in the case of overflow, so the scanner's position is past the entire floating-point representation. Invoke this method with 'NULL' as 'result' to simply scan past a hexadecimal double representation. - Parameter result: Upon return, contains the scanned value. Contains 'HUGE_VAL' or '-HUGE_VAL' on overflow, or '0.0' on underflow. - Returns: 'YES' if the receiver finds a valid double-point representation, otherwise 'NO'. Overflow or underflow are both considered valid floating-point representations.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_hex_double(double* result) const;
        /**
         * @brief Calls `-[NSScanner scanHexFloat:]`.
         * @details Scans for a double value from a hexadecimal representation, returning a found value by reference. This corresponds to '\%a' or '\%A' formatting. The hexadecimal float representation must be preceded by '0x' or '0X'. Skips past excess digits in the case of overflow, so the scanner's position is past the entire floating-point representation. Invoke this method with 'NULL' as 'result' to simply scan past a hexadecimal float representation. - Parameter result: Upon return, contains the scanned value. Contains 'HUGE_VAL' or '-HUGE_VAL' on overflow, or '0.0' on underflow. - Returns: 'YES' if the receiver finds a valid float-point representation, otherwise 'NO'. Overflow or underflow are both considered valid floating-point representations.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_hex_float(float* result) const;
        /**
         * @brief Calls `-[NSScanner scanHexInt:]`.
         * @details Scans for an unsigned value from a hexadecimal representation, returning a found value by reference. The hexadecimal integer representation may optionally be preceded by '0x' or '0X'. Skips past excess digits in the case of overflow, so the receiver's position is past the entire hexadecimal representation. Invoke this method with 'NULL' as 'intValue' to simply scan past a hexadecimal integer representation. - Parameter result: Upon return, contains the scanned value. Contains 'UINT_MAX' on overflow. - Returns: 'YES' if the receiver finds a valid hexadecimal integer representation, otherwise 'NO'. Overflow is considered a valid hexadecimal integer representation.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_hex_int(unsigned int* result) const;
        /**
         * @brief Calls `-[NSScanner scanHexLongLong:]`.
         * @details Scans for a long long value from a hexadecimal representation, returning a found value by reference. The hexadecimal integer representation may optionally be preceded by '0x' or '0X'. Skips past excess digits in the case of overflow, so the receiver's position is past the entire hexadecimal representation. Invoke this method with 'NULL' as 'result' to simply scan past a hexadecimal long long representation. - Parameter result: Upon return, contains the scanned value. Contains 'HUGE_VAL' or '-HUGE_VAL' on overflow. - Returns: 'YES' if the receiver finds a valid hexadecimal long long representation, otherwise 'NO'. Overflow is considered a valid hexadecimal long long representation.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_hex_long_long(std::uint64_t* result) const;
        /**
         * @brief Calls `-[NSScanner scanInt:]`.
         * @details Scans for an int value from a decimal representation, returning a found value by reference. Skips past excess digits in the case of overflow, so the receiver's position is past the entire decimal representation. Invoke this method with 'NULL' as 'intValue' to simply scan past a decimal integer representation. - Parameter result: Upon return, contains the scanned value. Contains 'INT_MAX' or 'INT_MIN' on overflow. - Returns: 'YES' if the receiver finds a valid decimal integer representation, otherwise 'NO'. Overflow is considered a valid integer representation.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_int(int* result) const;
        /**
         * @brief Calls `-[NSScanner scanInteger:]`.
         * @details Scans for an NSInteger value from a decimal representation, returning a found value by reference. Skips past excess digits in the case of overflow, so the receiver's position is past the entire integer representation. Invoke this method with 'NULL' as 'value' to simply scan past a decimal integer representation. - Parameter result: Upon return, contains the scanned value. Contains 'INT_MAX' or 'INT_MIN' on overflow. - Returns: 'YES' if the receiver finds a valid integer representation, otherwise 'NO'. Overflow is considered a valid integer representation.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_integer(std::int64_t* result) const;
        /**
         * @brief Calls `-[NSScanner scanLongLong:]`.
         * @details Scans for a long long value from a decimal representation, returning a found value by reference. All overflow digits are skipped. Skips past excess digits in the case of overflow, so the receiver's position is past the entire decimal representation. Invoke this method with 'NULL' as 'longLongValue' to simply scan past a long decimal integer representation. - Parameter result: Upon return, contains the scanned value. Contains 'LLONG_MAX' or 'LLONG_MIN' on overflow. - Returns: 'YES' if the receiver finds a valid decimal integer representation, otherwise 'NO'. Overflow is considered a valid decimal integer representation.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_long_long(std::int64_t* result) const;
        /**
         * @brief Calls `-[NSScanner scanString:intoString:]`.
         * @details Scans a given string, returning an equivalent string object by reference if a match is found. If 'string' is present at the current scan location, then the current scan location is advanced to after the string; otherwise the scan location does not change. Invoke this method with 'NULL' as 'stringValue' to simply scan past a given string. - Parameters: - string: The string for which to scan at the current scan location. - result: Upon return, if the receiver contains a string equivalent to 'string' at the current scan location, contains a string equivalent to 'string'. - Returns: 'YES' if 'string' matches the characters at the scan location, otherwise 'NO'.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_string(const std::string& string, std::string& result) const;
        /**
         * @brief Calls `-[NSScanner scanUnsignedLongLong:]`.
         * @details Scans for an unsigned long long value from a decimal representation, returning a found value by reference. All overflow digits are skipped. Skips past excess digits in the case of overflow, so the receiver's position is past the entire decimal representation. Invoke this method with 'NULL' as 'unsignedLongLongValue' to simply scan past an unsigned long decimal integer representation. - Parameter result: Upon return, contains the scanned value. Contains 'ULLONG_MAX' on overflow. - Returns: 'YES' if the receiver finds a valid decimal integer representation, otherwise 'NO'. Overflow is considered a valid decimal integer representation.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_unsigned_long_long(std::uint64_t* result) const;
        /**
         * @brief Calls `-[NSScanner scanUpToCharactersFromSet:intoString:]`.
         * @details Scans the string until a character from a given character set is encountered, accumulating characters into a string that's returned by reference. Invoke this method with 'NULL' as 'stringValue' to simply scan up to a given set of characters. If no characters in 'stopSet' are present in the scanner's source string, the remainder of the source string is put into 'stringValue', the receiver's 'scanLocation' is advanced to the end of the source string, and the method returns 'YES'. - Parameters: - set: The set of characters up to which to scan. - result: Upon return, contains the characters scanned. - Returns: 'YES' if the receiver scanned any characters, otherwise 'NO'. If the only scanned characters are in the 'charactersToBeSkipped' character set (which is the whitespace and newline character set by default), then returns 'NO'.
         * @param set Argument converted to the Objective-C parameter of the same role.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_up_to_characters_from_set(const CharacterSet& set, std::string& result) const;
        /**
         * @brief Calls `-[NSScanner scanUpToString:intoString:]`.
         * @details Scans the string until a given string is encountered, accumulating characters into a string that's returned by reference. If 'stopString' is present in the receiver, then on return the scan location is set to the beginning of that string. If 'stopString' is the first string in the receiver, then the method returns 'NO' and 'stringValue' is not changed. If the search string ('stopString') isn't present in the scanner's source string, the remainder of the source string is put into 'stringValue', the receiver's 'scanLocation' is advanced to the end of the source string, and the method returns 'YES'. Invoke this method with 'NULL' as 'stringValue' to simply scan up to a given string. - Parameters: - string: The string to scan up to. - result: Upon return, contains any characters that were scanned. - Returns: 'YES' if the receiver scans any characters, otherwise 'NO'. If the only scanned characters are in the 'charactersToBeSkipped' character set (which by default is the whitespace and newline character set), then this method returns 'NO'.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_up_to_string(const std::string& string, std::string& result) const;
        /**
         * @brief Returns the `atEnd` property of `NSScanner`.
         * @details Flag that indicates whether the receiver has exhausted all significant characters. 'YES' if the receiver has exhausted all significant characters in its string, otherwise 'NO'. If only characters from the set to be skipped remain, returns 'YES'.
         * @return The converted Objective-C result.
         */
        bool is_at_end() const;
        /**
         * @brief Returns the `caseSensitive` property of `NSScanner`.
         * @details Flag that indicates whether the receiver distinguishes case in the characters it scans. 'YES' if the receiver distinguishes case in the characters it scans, otherwise 'NO'. The default value is 'NO'. Note that case sensitivity doesn't apply to the characters to be skipped.
         * @return The converted Objective-C result.
         */
        bool case_sensitive() const;
        /**
         * @brief Sets the `caseSensitive` property of `NSScanner`.
         * @details Flag that indicates whether the receiver distinguishes case in the characters it scans. 'YES' if the receiver distinguishes case in the characters it scans, otherwise 'NO'. The default value is 'NO'. Note that case sensitivity doesn't apply to the characters to be skipped.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_case_sensitive(bool value) const;
        /**
         * @brief Returns the `charactersToBeSkipped` property of `NSScanner`.
         * @details Character set containing the characters the scanner ignores when looking for a scannable element. Characters to be skipped are skipped prior to the scanner examining the target. For example, if a scanner ignores spaces and you send it a -scanInt: message, it skips spaces until it finds a decimal digit or other character. While an element is being scanned, no characters are skipped. If you scan for something made of characters in the set to be skipped (for example, using -scanInt: when the set of characters to be skipped is the decimal digits), the result is undefined. The characters to be skipped are treated as single values. A scanner doesn't apply its case sensitivity setting to these characters and doesn't attempt to match composed character sequences with anything in the set of characters to be skipped (though it does match pre-composed characters individually). If you want to skip all vowels while scanning a string, for example, you can set the characters to be skipped to those in the string "AEIOUaeiou" (plus any accented variants with pre-composed characters). The default set to skip is the whitespace and newline character set.
         * @return The converted Objective-C result.
         */
        CharacterSet characters_to_be_skipped() const;
        /**
         * @brief Sets the `charactersToBeSkipped` property of `NSScanner`.
         * @details Character set containing the characters the scanner ignores when looking for a scannable element. Characters to be skipped are skipped prior to the scanner examining the target. For example, if a scanner ignores spaces and you send it a -scanInt: message, it skips spaces until it finds a decimal digit or other character. While an element is being scanned, no characters are skipped. If you scan for something made of characters in the set to be skipped (for example, using -scanInt: when the set of characters to be skipped is the decimal digits), the result is undefined. The characters to be skipped are treated as single values. A scanner doesn't apply its case sensitivity setting to these characters and doesn't attempt to match composed character sequences with anything in the set of characters to be skipped (though it does match pre-composed characters individually). If you want to skip all vowels while scanning a string, for example, you can set the characters to be skipped to those in the string "AEIOUaeiou" (plus any accented variants with pre-composed characters). The default set to skip is the whitespace and newline character set.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_characters_to_be_skipped(const CharacterSet& value) const;
        /**
         * @brief Returns the `locale` property of `NSScanner`.
         * @details The locale to use when scanning. A scanner's locale affects the way it interprets numeric values from the string. In particular, a scanner uses the locale's decimal separator to distinguish the integer and fractional parts of floating-point representations. A scanner with no locale set uses non-localized values. New scanners have no locale by default.
         * @return The converted Objective-C result.
         */
        Object locale() const;
        /**
         * @brief Sets the `locale` property of `NSScanner`.
         * @details The locale to use when scanning. A scanner's locale affects the way it interprets numeric values from the string. In particular, a scanner uses the locale's decimal separator to distinguish the integer and fractional parts of floating-point representations. A scanner with no locale set uses non-localized values. New scanners have no locale by default.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_locale(const Object& value) const;
        /**
         * @brief Returns the `scanLocation` property of `NSScanner`.
         * @details The character position at which the receiver will begin its next scanning operation. Raises an 'NSRangeException' if 'index' is beyond the end of the string being scanned. This property is useful for backing up to rescan after an error. Rather than setting the scan location directly to skip known sequences of characters, use -scanString:intoString: or -scanCharactersFromSet:intoString:, which allow you to verify that the expected substring (or set of characters) is in fact present.
         * @return The converted Objective-C result.
         */
        std::uint64_t scan_location() const;
        /**
         * @brief Sets the `scanLocation` property of `NSScanner`.
         * @details The character position at which the receiver will begin its next scanning operation. Raises an 'NSRangeException' if 'index' is beyond the end of the string being scanned. This property is useful for backing up to rescan after an error. Rather than setting the scan location directly to skip known sequences of characters, use -scanString:intoString: or -scanCharactersFromSet:intoString:, which allow you to verify that the expected substring (or set of characters) is in fact present.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_scan_location(std::uint64_t value) const;
        /**
         * @brief Returns the `string` property of `NSScanner`.
         * @details The string the scanner will scan.
         * @return The converted Objective-C result.
         */
        std::string string() const;
    };
}
