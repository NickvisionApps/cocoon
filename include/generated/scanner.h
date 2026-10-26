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
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object localized_scanner_with_string(const std::string& string);
        /**
         * @brief Calls `-[NSScanner scanCharactersFromSet:intoString:]`.
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
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_double(double* result) const;
        /**
         * @brief Calls `-[NSScanner scanFloat:]`.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_float(float* result) const;
        /**
         * @brief Calls `-[NSScanner scanHexDouble:]`.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_hex_double(double* result) const;
        /**
         * @brief Calls `-[NSScanner scanHexFloat:]`.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_hex_float(float* result) const;
        /**
         * @brief Calls `-[NSScanner scanHexInt:]`.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_hex_int(unsigned int* result) const;
        /**
         * @brief Calls `-[NSScanner scanHexLongLong:]`.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_hex_long_long(std::uint64_t* result) const;
        /**
         * @brief Calls `-[NSScanner scanInt:]`.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_int(int* result) const;
        /**
         * @brief Calls `-[NSScanner scanInteger:]`.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_integer(std::int64_t* result) const;
        /**
         * @brief Calls `-[NSScanner scanLongLong:]`.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_long_long(std::int64_t* result) const;
        /**
         * @brief Calls `-[NSScanner scanString:intoString:]`.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_string(const std::string& string, std::string& result) const;
        /**
         * @brief Calls `-[NSScanner scanUnsignedLongLong:]`.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_unsigned_long_long(std::uint64_t* result) const;
        /**
         * @brief Calls `-[NSScanner scanUpToCharactersFromSet:intoString:]`.
         * @param set Argument converted to the Objective-C parameter of the same role.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_up_to_characters_from_set(const CharacterSet& set, std::string& result) const;
        /**
         * @brief Calls `-[NSScanner scanUpToString:intoString:]`.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool scan_up_to_string(const std::string& string, std::string& result) const;
        /**
         * @brief Returns the `atEnd` property of `NSScanner`.
         * @return The converted Objective-C result.
         */
        bool is_at_end() const;
        /**
         * @brief Returns the `caseSensitive` property of `NSScanner`.
         * @return The converted Objective-C result.
         */
        bool case_sensitive() const;
        /**
         * @brief Sets the `caseSensitive` property of `NSScanner`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_case_sensitive(bool value) const;
        /**
         * @brief Returns the `charactersToBeSkipped` property of `NSScanner`.
         * @return The converted Objective-C result.
         */
        CharacterSet characters_to_be_skipped() const;
        /**
         * @brief Sets the `charactersToBeSkipped` property of `NSScanner`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_characters_to_be_skipped(const CharacterSet& value) const;
        /**
         * @brief Returns the `locale` property of `NSScanner`.
         * @return The converted Objective-C result.
         */
        Object locale() const;
        /**
         * @brief Sets the `locale` property of `NSScanner`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_locale(const Object& value) const;
        /**
         * @brief Returns the `scanLocation` property of `NSScanner`.
         * @return The converted Objective-C result.
         */
        std::uint64_t scan_location() const;
        /**
         * @brief Sets the `scanLocation` property of `NSScanner`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_scan_location(std::uint64_t value) const;
        /**
         * @brief Returns the `string` property of `NSScanner`.
         * @return The converted Objective-C result.
         */
        std::string string() const;
    };
}
