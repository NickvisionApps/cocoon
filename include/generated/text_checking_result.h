#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;
    class Orthography;
    class RegularExpression;
    class TimeZone;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSTextCheckingResult` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextCheckingResult text_checking_result;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextCheckingResult text_checking_result{};
     * text_checking_result.range_at_index(1);
     * text_checking_result.range_with_name("text");
     * text_checking_result.result_by_adjusting_ranges_with_offset(1);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nstextcheckingresult
     */
    class TextCheckingResult : public Object
    {
    public:
        /// @brief Creates a new `NSTextCheckingResult` instance and returns a handle to it.
        explicit TextCheckingResult();
        /// @brief Creates a null handle that refers to no native object.
        TextCheckingResult(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextCheckingResult(Adopt adopt);
        /**
     * @brief Calls `+[NSTextCheckingResult addressCheckingResultWithRange:components:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param components Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextCheckingResult address_checking_result_with_range(const Range& range, const std::map<std::string, std::string>& components);
        /**
     * @brief Calls `+[NSTextCheckingResult correctionCheckingResultWithRange:replacementString:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param replacement_string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextCheckingResult correction_checking_result_with_range(const Range& range, const std::string& replacement_string);
        /**
     * @brief Calls `+[NSTextCheckingResult correctionCheckingResultWithRange:replacementString:alternativeStrings:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param replacement_string Argument converted to the Objective-C parameter of the same role.
     * @param alternative_strings Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextCheckingResult correction_checking_result_with_range(const Range& range, const std::string& replacement_string, const std::vector<std::string>& alternative_strings);
        /**
     * @brief Calls `+[NSTextCheckingResult dashCheckingResultWithRange:replacementString:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param replacement_string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextCheckingResult dash_checking_result_with_range(const Range& range, const std::string& replacement_string);
        /**
     * @brief Calls `+[NSTextCheckingResult dateCheckingResultWithRange:date:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextCheckingResult date_checking_result_with_range(const Range& range, const Date& date);
        /**
     * @brief Calls `+[NSTextCheckingResult dateCheckingResultWithRange:date:timeZone:duration:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @param time_zone Argument converted to the Objective-C parameter of the same role.
     * @param duration Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextCheckingResult date_checking_result_with_range(const Range& range, const Date& date, const TimeZone& time_zone, double duration);
        /**
     * @brief Calls `+[NSTextCheckingResult grammarCheckingResultWithRange:details:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param details Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextCheckingResult grammar_checking_result_with_range(const Range& range, const std::vector<std::map<std::string, Object>>& details);
        /**
     * @brief Calls `+[NSTextCheckingResult linkCheckingResultWithRange:URL:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextCheckingResult link_checking_result_with_range(const Range& range, const URL& url);
        /**
     * @brief Calls `+[NSTextCheckingResult orthographyCheckingResultWithRange:orthography:]`.
     * @details Methods for creating instances of the various types of results.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param orthography Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextCheckingResult orthography_checking_result_with_range(const Range& range, const Orthography& orthography);
        /**
     * @brief Calls `+[NSTextCheckingResult phoneNumberCheckingResultWithRange:phoneNumber:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param phone_number Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextCheckingResult phone_number_checking_result_with_range(const Range& range, const std::string& phone_number);
        /**
     * @brief Calls `+[NSTextCheckingResult quoteCheckingResultWithRange:replacementString:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param replacement_string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextCheckingResult quote_checking_result_with_range(const Range& range, const std::string& replacement_string);
        /**
     * @brief Calls `-[NSTextCheckingResult rangeAtIndex:]`.
     * @param idx Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Range range_at_index(std::uint64_t idx) const;
        /**
     * @brief Calls `-[NSTextCheckingResult rangeWithName:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Range range_with_name(const std::string& name) const;
        /**
     * @brief Calls `+[NSTextCheckingResult regularExpressionCheckingResultWithRanges:count:regularExpression:]`.
     * @param ranges Argument converted to the Objective-C parameter of the same role.
     * @param count Argument converted to the Objective-C parameter of the same role.
     * @param regular_expression Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextCheckingResult regular_expression_checking_result_with_ranges(Range* ranges, std::uint64_t count, const RegularExpression& regular_expression);
        /**
     * @brief Calls `+[NSTextCheckingResult replacementCheckingResultWithRange:replacementString:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param replacement_string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextCheckingResult replacement_checking_result_with_range(const Range& range, const std::string& replacement_string);
        /**
     * @brief Calls `-[NSTextCheckingResult resultByAdjustingRangesWithOffset:]`.
     * @param offset Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        TextCheckingResult result_by_adjusting_ranges_with_offset(std::int64_t offset) const;
        /**
     * @brief Calls `+[NSTextCheckingResult spellCheckingResultWithRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextCheckingResult spell_checking_result_with_range(const Range& range);
        /**
     * @brief Calls `+[NSTextCheckingResult transitInformationCheckingResultWithRange:components:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param components Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TextCheckingResult transit_information_checking_result_with_range(const Range& range, const std::map<std::string, std::string>& components);
        /**
     * @brief Returns the `URL` property of `NSTextCheckingResult`.
     * @return The converted Objective-C result.
     */
        URL url() const;
        /**
     * @brief Returns the `addressComponents` property of `NSTextCheckingResult`.
     * @return The converted Objective-C result.
     */
        std::map<std::string, std::string> address_components() const;
        /**
     * @brief Returns the `alternativeStrings` property of `NSTextCheckingResult`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> alternative_strings() const;
        /**
     * @brief Returns the `components` property of `NSTextCheckingResult`.
     * @return The converted Objective-C result.
     */
        std::map<std::string, std::string> components() const;
        /**
     * @brief Returns the `date` property of `NSTextCheckingResult`.
     * @return The converted Objective-C result.
     */
        Date date() const;
        /**
     * @brief Returns the `duration` property of `NSTextCheckingResult`.
     * @return The converted Objective-C result.
     */
        double duration() const;
        /**
     * @brief Returns the `grammarDetails` property of `NSTextCheckingResult`.
     * @return The converted Objective-C result.
     */
        std::vector<std::map<std::string, Object>> grammar_details() const;
        /**
     * @brief Returns the `numberOfRanges` property of `NSTextCheckingResult`.
     * @details A result must have at least one range, but may optionally have more (for example, to represent regular expression capture groups). The range at index 0 always matches the range property. Additional ranges, if any, will have indexes from 1 to numberOfRanges-1. rangeWithName: can be used with named regular expression capture groups.
     * @return The converted Objective-C result.
     */
        std::uint64_t number_of_ranges() const;
        /**
     * @brief Returns the `orthography` property of `NSTextCheckingResult`.
     * @details Optional properties, used with certain types of results.
     * @return The converted Objective-C result.
     */
        Orthography orthography() const;
        /**
     * @brief Returns the `phoneNumber` property of `NSTextCheckingResult`.
     * @return The converted Objective-C result.
     */
        std::string phone_number() const;
        /**
     * @brief Returns the `range` property of `NSTextCheckingResult`.
     * @return The converted Objective-C result.
     */
        Range range() const;
        /**
     * @brief Returns the `regularExpression` property of `NSTextCheckingResult`.
     * @return The converted Objective-C result.
     */
        RegularExpression regular_expression() const;
        /**
     * @brief Returns the `replacementString` property of `NSTextCheckingResult`.
     * @return The converted Objective-C result.
     */
        std::string replacement_string() const;
        /**
     * @brief Returns the `resultType` property of `NSTextCheckingResult`.
     * @details Mandatory properties, used with all types of results.
     * @return The converted Objective-C result.
     */
        TextCheckingType result_type() const;
        /**
     * @brief Returns the `timeZone` property of `NSTextCheckingResult`.
     * @return The converted Objective-C result.
     */
        TimeZone time_zone() const;
    };
}
