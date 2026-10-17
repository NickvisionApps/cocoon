#include "generated/text_checking_result.h"
#include "internal.h"

namespace cocoon
{
    TextCheckingResult::TextCheckingResult() : TextCheckingResult(Adopt{cocoon::internal::retain([[::NSTextCheckingResult alloc] init])})
    {
    }

    TextCheckingResult::TextCheckingResult(std::nullptr_t) : Object(nullptr)
    {
    }

    TextCheckingResult::TextCheckingResult(Adopt adopt) : Object(adopt)
    {
    }

    TextCheckingResult TextCheckingResult::address_checking_result_with_range(const Range& range, const std::map<std::string, std::string>& components)
    {
        return cocoon::internal::wrap<TextCheckingResult>([::NSTextCheckingResult addressCheckingResultWithRange:cocoon::internal::to(range)
                                                                                                      components:cocoon::internal::to_dictionary(components, [](const std::string& k) -> id
                                                                                                                                                 {
                                                                                                                                                     return cocoon::internal::to(k);
                                                                                                                                                 },
                                                                                                                                                 [](const std::string& v) -> id
                                                                                                                                                 {
                                                                                                                                                     return cocoon::internal::to(v);
                                                                                                                                                 })]);
    }

    TextCheckingResult TextCheckingResult::correction_checking_result_with_range(const Range& range, const std::string& replacement_string)
    {
        return cocoon::internal::wrap<TextCheckingResult>([::NSTextCheckingResult correctionCheckingResultWithRange:cocoon::internal::to(range) replacementString:cocoon::internal::to(replacement_string)]);
    }

    TextCheckingResult TextCheckingResult::correction_checking_result_with_range(const Range& range, const std::string& replacement_string, const std::vector<std::string>& alternative_strings)
    {
        return cocoon::internal::wrap<TextCheckingResult>([::NSTextCheckingResult correctionCheckingResultWithRange:cocoon::internal::to(range)
                                                                                                  replacementString:cocoon::internal::to(replacement_string)
                                                                                                 alternativeStrings:cocoon::internal::to_array(alternative_strings, [](const std::string& e) -> id
                                                                                                                                               {
                                                                                                                                                   return cocoon::internal::to(e);
                                                                                                                                               })]);
    }

    TextCheckingResult TextCheckingResult::dash_checking_result_with_range(const Range& range, const std::string& replacement_string)
    {
        return cocoon::internal::wrap<TextCheckingResult>([::NSTextCheckingResult dashCheckingResultWithRange:cocoon::internal::to(range) replacementString:cocoon::internal::to(replacement_string)]);
    }

    TextCheckingResult TextCheckingResult::date_checking_result_with_range(const Range& range, const Date& date)
    {
        return cocoon::internal::wrap<TextCheckingResult>([::NSTextCheckingResult dateCheckingResultWithRange:cocoon::internal::to(range) date:cocoon::internal::native<::NSDate>(date)]);
    }

    TextCheckingResult TextCheckingResult::date_checking_result_with_range(const Range& range, const Date& date, const TimeZone& time_zone, double duration)
    {
        return cocoon::internal::wrap<TextCheckingResult>([::NSTextCheckingResult dateCheckingResultWithRange:cocoon::internal::to(range) date:cocoon::internal::native<::NSDate>(date) timeZone:cocoon::internal::native<::NSTimeZone>(time_zone) duration:static_cast<::NSTimeInterval>(duration)]);
    }

    TextCheckingResult TextCheckingResult::grammar_checking_result_with_range(const Range& range, const std::vector<std::map<std::string, Object>>& details)
    {
        return cocoon::internal::wrap<TextCheckingResult>([::NSTextCheckingResult grammarCheckingResultWithRange:cocoon::internal::to(range)
                                                                                                         details:cocoon::internal::to_array(details, [](const std::map<std::string, Object>& e) -> id
                                                                                                                                            {
                                                                                                                                                return cocoon::internal::to_dictionary(e, [](const std::string& k) -> id
                                                                                                                                                                                       {
                                                                                                                                                                                           return cocoon::internal::to(k);
                                                                                                                                                                                       },
                                                                                                                                                                                       [](const Object& v) -> id
                                                                                                                                                                                       {
                                                                                                                                                                                           return cocoon::internal::native_id(v);
                                                                                                                                                                                       });
                                                                                                                                            })]);
    }

    TextCheckingResult TextCheckingResult::link_checking_result_with_range(const Range& range, const URL& url)
    {
        return cocoon::internal::wrap<TextCheckingResult>([::NSTextCheckingResult linkCheckingResultWithRange:cocoon::internal::to(range) URL:cocoon::internal::native<::NSURL>(url)]);
    }

    TextCheckingResult TextCheckingResult::orthography_checking_result_with_range(const Range& range, const Orthography& orthography)
    {
        return cocoon::internal::wrap<TextCheckingResult>([::NSTextCheckingResult orthographyCheckingResultWithRange:cocoon::internal::to(range) orthography:cocoon::internal::native<::NSOrthography>(orthography)]);
    }

    TextCheckingResult TextCheckingResult::phone_number_checking_result_with_range(const Range& range, const std::string& phone_number)
    {
        return cocoon::internal::wrap<TextCheckingResult>([::NSTextCheckingResult phoneNumberCheckingResultWithRange:cocoon::internal::to(range) phoneNumber:cocoon::internal::to(phone_number)]);
    }

    TextCheckingResult TextCheckingResult::quote_checking_result_with_range(const Range& range, const std::string& replacement_string)
    {
        return cocoon::internal::wrap<TextCheckingResult>([::NSTextCheckingResult quoteCheckingResultWithRange:cocoon::internal::to(range) replacementString:cocoon::internal::to(replacement_string)]);
    }

    Range TextCheckingResult::range_at_index(std::uint64_t idx) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextCheckingResult>(this) rangeAtIndex:static_cast<::NSUInteger>(idx)]);
    }

    Range TextCheckingResult::range_with_name(const std::string& name) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextCheckingResult>(this) rangeWithName:cocoon::internal::to(name)]);
    }

    TextCheckingResult TextCheckingResult::regular_expression_checking_result_with_ranges(Range* ranges, std::uint64_t count, const RegularExpression& regular_expression)
    {
        return cocoon::internal::wrap<TextCheckingResult>([::NSTextCheckingResult regularExpressionCheckingResultWithRanges:(::NSRangePointer)(ranges) count:static_cast<::NSUInteger>(count) regularExpression:cocoon::internal::native<::NSRegularExpression>(regular_expression)]);
    }

    TextCheckingResult TextCheckingResult::replacement_checking_result_with_range(const Range& range, const std::string& replacement_string)
    {
        return cocoon::internal::wrap<TextCheckingResult>([::NSTextCheckingResult replacementCheckingResultWithRange:cocoon::internal::to(range) replacementString:cocoon::internal::to(replacement_string)]);
    }

    TextCheckingResult TextCheckingResult::result_by_adjusting_ranges_with_offset(std::int64_t offset) const
    {
        return cocoon::internal::wrap<TextCheckingResult>([cocoon::internal::ns<::NSTextCheckingResult>(this) resultByAdjustingRangesWithOffset:static_cast<::NSInteger>(offset)]);
    }

    TextCheckingResult TextCheckingResult::spell_checking_result_with_range(const Range& range)
    {
        return cocoon::internal::wrap<TextCheckingResult>([::NSTextCheckingResult spellCheckingResultWithRange:cocoon::internal::to(range)]);
    }

    TextCheckingResult TextCheckingResult::transit_information_checking_result_with_range(const Range& range, const std::map<std::string, std::string>& components)
    {
        return cocoon::internal::wrap<TextCheckingResult>([::NSTextCheckingResult transitInformationCheckingResultWithRange:cocoon::internal::to(range)
                                                                                                                 components:cocoon::internal::to_dictionary(components, [](const std::string& k) -> id
                                                                                                                                                            {
                                                                                                                                                                return cocoon::internal::to(k);
                                                                                                                                                            },
                                                                                                                                                            [](const std::string& v) -> id
                                                                                                                                                            {
                                                                                                                                                                return cocoon::internal::to(v);
                                                                                                                                                            })]);
    }

    URL TextCheckingResult::url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSTextCheckingResult>(this) URL]);
    }

    std::map<std::string, std::string> TextCheckingResult::address_components() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, std::string>>([cocoon::internal::ns<::NSTextCheckingResult>(this) addressComponents], [](id k) -> std::string
                                                                                     {
                                                                                         return cocoon::internal::from((NSString*)k);
                                                                                     },
                                                                                     [](id v) -> std::string
                                                                                     {
                                                                                         return cocoon::internal::from((NSString*)v);
                                                                                     });
    }

    std::vector<std::string> TextCheckingResult::alternative_strings() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTextCheckingResult>(this) alternativeStrings], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::map<std::string, std::string> TextCheckingResult::components() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, std::string>>([cocoon::internal::ns<::NSTextCheckingResult>(this) components], [](id k) -> std::string
                                                                                     {
                                                                                         return cocoon::internal::from((NSString*)k);
                                                                                     },
                                                                                     [](id v) -> std::string
                                                                                     {
                                                                                         return cocoon::internal::from((NSString*)v);
                                                                                     });
    }

    Date TextCheckingResult::date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSTextCheckingResult>(this) date]);
    }

    double TextCheckingResult::duration() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTextCheckingResult>(this) duration]);
    }

    std::vector<std::map<std::string, Object>> TextCheckingResult::grammar_details() const
    {
        return cocoon::internal::from_array<std::map<std::string, Object>>([cocoon::internal::ns<::NSTextCheckingResult>(this) grammarDetails], [](id e) -> std::map<std::string, Object>
                                                                           {
                                                                               return cocoon::internal::from_dictionary<std::map<std::string, Object>>((NSDictionary*)e, [](id k) -> std::string
                                                                                                                                                       {
                                                                                                                                                           return cocoon::internal::from((NSString*)k);
                                                                                                                                                       },
                                                                                                                                                       [](id v) -> Object
                                                                                                                                                       {
                                                                                                                                                           return cocoon::internal::wrap<Object>(v);
                                                                                                                                                       });
                                                                           });
    }

    std::uint64_t TextCheckingResult::number_of_ranges() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSTextCheckingResult>(this) numberOfRanges]);
    }

    Orthography TextCheckingResult::orthography() const
    {
        return cocoon::internal::wrap<Orthography>([cocoon::internal::ns<::NSTextCheckingResult>(this) orthography]);
    }

    std::string TextCheckingResult::phone_number() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextCheckingResult>(this) phoneNumber]);
    }

    Range TextCheckingResult::range() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextCheckingResult>(this) range]);
    }

    RegularExpression TextCheckingResult::regular_expression() const
    {
        return cocoon::internal::wrap<RegularExpression>([cocoon::internal::ns<::NSTextCheckingResult>(this) regularExpression]);
    }

    std::string TextCheckingResult::replacement_string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextCheckingResult>(this) replacementString]);
    }

    TextCheckingType TextCheckingResult::result_type() const
    {
        return static_cast<TextCheckingType>([cocoon::internal::ns<::NSTextCheckingResult>(this) resultType]);
    }

    TimeZone TextCheckingResult::time_zone() const
    {
        return cocoon::internal::wrap<TimeZone>([cocoon::internal::ns<::NSTextCheckingResult>(this) timeZone]);
    }
}
