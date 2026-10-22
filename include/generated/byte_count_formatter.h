#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/formatter.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class MeasurementBase;

    /**
     * @brief C++ handle for the Objective-C class `NSByteCountFormatter` (Foundation).
     * @details A formatter that converts a byte count value into a localized description that is formatted with the appropriate byte modifier (KB, MB, GB and so on). > Tip: > In Swift, you can use ''ByteCountFormatStyle'' or ''Measurement/FormatStyle/ByteCount'' rather than ''ByteCountFormatter''. The ''FormatStyle'' API offers a declarative idiom for customizing the formatting of various types. Also, Foundation caches identical ''FormatStyle'' instances, so you don't need to pass them around your app, or risk wasting memory with duplicate formatters.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Formatter.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ByteCountFormatter byte_count_formatter;
     * byte_count_formatter.set_adaptive(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ByteCountFormatter byte_count_formatter{};
     * byte_count_formatter.set_adaptive(true);
     * auto adaptive = byte_count_formatter.is_adaptive();
     * byte_count_formatter.set_allowed_units(cocoon::ByteCountFormatterUnits::Default);
     * auto allowed_units = byte_count_formatter.allowed_units();
     * byte_count_formatter.set_allows_nonnumeric_formatting(true);
     * auto allows_nonnumeric_formatting = byte_count_formatter.allows_nonnumeric_formatting();
     * byte_count_formatter.string_from_byte_count(1);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsbytecountformatter
     */
    class ByteCountFormatter : public Formatter
    {
    public:
        /// @brief Creates a new `NSByteCountFormatter` instance and returns a handle to it.
        explicit ByteCountFormatter();
        /// @brief Creates a null handle that refers to no native object.
        ByteCountFormatter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ByteCountFormatter(Adopt adopt);
        using Formatter::string_for_object_value;
        /**
         * @brief Calls `-[NSByteCountFormatter stringForObjectValue:]`.
         * @details Formats 'obj' as a byte count (if 'obj' is an 'NSNumber') or specific byte measurement (if 'obj' is an 'NSMeasurement') using the receiver's settings. Returns 'nil' if 'obj' is not of the correct class ('NSNumber' or 'NSMeasurement'). Throws an exception if 'obj' is an 'NSMeasurement' whose unit does not belong to the 'NSUnitInformationStorage' dimension.
         * @param obj Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string string_for_object_value(const Object& obj) const;
        /**
         * @brief Calls `-[NSByteCountFormatter stringFromByteCount:]`.
         * @details Converts a byte count into a string without creating an 'NSNumber' object. This is a convenience method on 'stringForObjectValue:'. \@param byteCount The byte count. \@return A string containing the formatted 'byteCount' value.
         * @param byte_count Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string string_from_byte_count(std::int64_t byte_count) const;
        /**
         * @brief Calls `+[NSByteCountFormatter stringFromByteCount:countStyle:]`.
         * @details Converts a byte count into the specified string format without creating an 'NSNumber' object. If you need to specify options other than 'countStyle', create an instance of 'NSByteCountFormatter' first. \@param byteCount The byte count. \@param countStyle The formatter style. See 'NSByteCountFormatterCountStyle' for possible values. \@return A string containing the formatted 'byteCount' value.
         * @param byte_count Argument converted to the Objective-C parameter of the same role.
         * @param count_style Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::string string_from_byte_count(std::int64_t byte_count, ByteCountFormatterCountStyle count_style);
        /**
         * @brief Calls `-[NSByteCountFormatter stringFromMeasurement:]`.
         * @details Formats the value of the given measurement using the receiver's 'countStyle'. Converts the measurement to the units allowed by the receiver's 'allowedUnits' before formatting; depending on the value of the measurement, this may result in a string which implies an approximate value (e.g. if the measurement is too large to represent in 'allowedUnits', like '1e20 YB' expressed in 'NSByteCountFormatterUseBytes'). Throws an exception if the given measurement's unit does not belong to the 'NSUnitInformationStorage' dimension.
         * @param measurement Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string string_from_measurement(const MeasurementBase& measurement) const;
        /**
         * @brief Calls `+[NSByteCountFormatter stringFromMeasurement:countStyle:]`.
         * @details Formats the value of the given measurement using the given 'countStyle'. Throws an exception if the given measurement's unit does not belong to the 'NSUnitInformationStorage' dimension.
         * @param measurement Argument converted to the Objective-C parameter of the same role.
         * @param count_style Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::string string_from_measurement(const MeasurementBase& measurement, ByteCountFormatterCountStyle count_style);
        /**
         * @brief Returns the `adaptive` property of `NSByteCountFormatter`.
         * @details Determines the display style of the size representation. The "adaptive" algorithm is platform specific and uses a different number of fraction digits based on the magnitude (in OS X v10.8: 0 fraction digits for bytes and KB; 1 fraction digits for MB; 2 for GB and above). Otherwise the result always tries to show at least three significant digits, introducing fraction digits as necessary. Default is 'YES'.
         * @return The converted Objective-C result.
         */
        bool is_adaptive() const;
        /**
         * @brief Sets the `adaptive` property of `NSByteCountFormatter`.
         * @details Determines the display style of the size representation. The "adaptive" algorithm is platform specific and uses a different number of fraction digits based on the magnitude (in OS X v10.8: 0 fraction digits for bytes and KB; 1 fraction digits for MB; 2 for GB and above). Otherwise the result always tries to show at least three significant digits, introducing fraction digits as necessary. Default is 'YES'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_adaptive(bool value) const;
        /**
         * @brief Returns the `allowedUnits` property of `NSByteCountFormatter`.
         * @details Specify the units that can be used in the output. If the value is 'NSByteCountFormatterUseDefault', the formatter uses platform-appropriate settings; otherwise only the specified units are used. > Note: ZB and YB cannot be covered by the range of possible values, but you can still choose to use these units to get fractional display ("0.0035 ZB" for instance).
         * @return The converted Objective-C result.
         */
        ByteCountFormatterUnits allowed_units() const;
        /**
         * @brief Sets the `allowedUnits` property of `NSByteCountFormatter`.
         * @details Specify the units that can be used in the output. If the value is 'NSByteCountFormatterUseDefault', the formatter uses platform-appropriate settings; otherwise only the specified units are used. > Note: ZB and YB cannot be covered by the range of possible values, but you can still choose to use these units to get fractional display ("0.0035 ZB" for instance).
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allowed_units(ByteCountFormatterUnits value) const;
        /**
         * @brief Returns the `allowsNonnumericFormatting` property of `NSByteCountFormatter`.
         * @details Determines whether to allow more natural display of some values. Displays a more natural display of some values, such as zero, where it may be displayed as "Zero KB", ignoring all other flags or options (with the exception of 'NSByteCountFormatterUseBytes', which would generate "Zero bytes"). The result is appropriate for standalone output. Special handling of certain values such as zero is especially important in some languages, so it's highly recommended that this property be left in its default state. Default value is 'YES'.
         * @return The converted Objective-C result.
         */
        bool allows_nonnumeric_formatting() const;
        /**
         * @brief Sets the `allowsNonnumericFormatting` property of `NSByteCountFormatter`.
         * @details Determines whether to allow more natural display of some values. Displays a more natural display of some values, such as zero, where it may be displayed as "Zero KB", ignoring all other flags or options (with the exception of 'NSByteCountFormatterUseBytes', which would generate "Zero bytes"). The result is appropriate for standalone output. Special handling of certain values such as zero is especially important in some languages, so it's highly recommended that this property be left in its default state. Default value is 'YES'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_nonnumeric_formatting(bool value) const;
        /**
         * @brief Returns the `countStyle` property of `NSByteCountFormatter`.
         * @details Specify the number of bytes to be used for kilobytes. The default setting is 'NSByteCountFormatterCountStyleFile', which is the system specific value for file and storage sizes.
         * @return The converted Objective-C result.
         */
        ByteCountFormatterCountStyle count_style() const;
        /**
         * @brief Sets the `countStyle` property of `NSByteCountFormatter`.
         * @details Specify the number of bytes to be used for kilobytes. The default setting is 'NSByteCountFormatterCountStyleFile', which is the system specific value for file and storage sizes.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_count_style(ByteCountFormatterCountStyle value) const;
        /**
         * @brief Returns the `formattingContext` property of `NSByteCountFormatter`.
         * @details Specify the formatting context for the formatted string. The default value is 'NSFormattingContextUnknown'.
         * @return The converted Objective-C result.
         */
        FormattingContext formatting_context() const;
        /**
         * @brief Sets the `formattingContext` property of `NSByteCountFormatter`.
         * @details Specify the formatting context for the formatted string. The default value is 'NSFormattingContextUnknown'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_formatting_context(FormattingContext value) const;
        /**
         * @brief Returns the `includesActualByteCount` property of `NSByteCountFormatter`.
         * @details Determines whether to include the number of bytes after the formatted string. Setting this value to 'YES' causes the byte count to be displayed parenthetically (localized as appropriate), for instance "723 KB (722,842 bytes)". This will happen only if needed, that is, the first part is already not showing the exact byte count. If 'includesUnit' or 'includesCount' are 'NO', then this setting has no effect. Default value is 'NO'.
         * @return The converted Objective-C result.
         */
        bool includes_actual_byte_count() const;
        /**
         * @brief Sets the `includesActualByteCount` property of `NSByteCountFormatter`.
         * @details Determines whether to include the number of bytes after the formatted string. Setting this value to 'YES' causes the byte count to be displayed parenthetically (localized as appropriate), for instance "723 KB (722,842 bytes)". This will happen only if needed, that is, the first part is already not showing the exact byte count. If 'includesUnit' or 'includesCount' are 'NO', then this setting has no effect. Default value is 'NO'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_includes_actual_byte_count(bool value) const;
        /**
         * @brief Returns the `includesCount` property of `NSByteCountFormatter`.
         * @details Determines whether to include the count in the resulting formatted string. If set to 'YES' and 'includesUnit' is set to 'NO', no unit is displayed. For example, a value of 723 KB is formatted as "723". You can set this property and 'includesUnit' individually to get both parts, separately. Note that putting them together yourself via string concatenation may be incorrect for some locales. The default value is 'YES'.
         * @return The converted Objective-C result.
         */
        bool includes_count() const;
        /**
         * @brief Sets the `includesCount` property of `NSByteCountFormatter`.
         * @details Determines whether to include the count in the resulting formatted string. If set to 'YES' and 'includesUnit' is set to 'NO', no unit is displayed. For example, a value of 723 KB is formatted as "723". You can set this property and 'includesUnit' individually to get both parts, separately. Note that putting them together yourself via string concatenation may be incorrect for some locales. The default value is 'YES'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_includes_count(bool value) const;
        /**
         * @brief Returns the `includesUnit` property of `NSByteCountFormatter`.
         * @details Determines whether to include the units in the resulting formatted string. If set to 'YES' and 'includesCount' is set to 'NO', no count is displayed. For example, a value of 723 KB is formatted as "KB". You can set this property and 'includesCount' individually to get both parts, separately. Note that putting them together yourself via string concatenation may be incorrect for some locales. The default value is 'YES'.
         * @return The converted Objective-C result.
         */
        bool includes_unit() const;
        /**
         * @brief Sets the `includesUnit` property of `NSByteCountFormatter`.
         * @details Determines whether to include the units in the resulting formatted string. If set to 'YES' and 'includesCount' is set to 'NO', no count is displayed. For example, a value of 723 KB is formatted as "KB". You can set this property and 'includesCount' individually to get both parts, separately. Note that putting them together yourself via string concatenation may be incorrect for some locales. The default value is 'YES'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_includes_unit(bool value) const;
        /**
         * @brief Returns the `zeroPadsFractionDigits` property of `NSByteCountFormatter`.
         * @details Determines whether to zero pad fraction digits so a consistent number of characters is displayed in a representation. Displaying values using zero pad fraction digits causes a consistent number of fraction digits to be displayed, causing updating displays to remain more stable. For instance, if the adaptive algorithm is used, this option formats 1.19 and 1.2 GB as "1.19 GB" and "1.20 GB", respectively, while without the option the latter would be displayed as "1.2 GB". Default value is 'NO'.
         * @return The converted Objective-C result.
         */
        bool zero_pads_fraction_digits() const;
        /**
         * @brief Sets the `zeroPadsFractionDigits` property of `NSByteCountFormatter`.
         * @details Determines whether to zero pad fraction digits so a consistent number of characters is displayed in a representation. Displaying values using zero pad fraction digits causes a consistent number of fraction digits to be displayed, causing updating displays to remain more stable. For instance, if the adaptive algorithm is used, this option formats 1.19 and 1.2 GB as "1.19 GB" and "1.20 GB", respectively, while without the option the latter would be displayed as "1.2 GB". Default value is 'NO'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_zero_pads_fraction_digits(bool value) const;
    };
}
