#include "generated/regular_expression.h"
#include "internal.h"

namespace cocoon
{
    RegularExpression::RegularExpression(const std::string& pattern, RegularExpressionOptions options) : RegularExpression(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                                                                          {
                                                                                                                                                              NSError* __error = nil;
                                                                                                                                                              id __r = [[::NSRegularExpression alloc] initWithPattern:cocoon::internal::to(pattern) options:static_cast<::NSRegularExpressionOptions>(options) error:&__error];
                                                                                                                                                              if (!__r && __error)
                                                                                                                                                              {
                                                                                                                                                                  throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                                                                                              }
                                                                                                                                                              return __r;
                                                                                                                                                          }())})
    {
    }

    RegularExpression::RegularExpression() : RegularExpression(Adopt{cocoon::internal::retain([[::NSRegularExpression alloc] init])})
    {
    }

    RegularExpression::RegularExpression(std::nullptr_t) : Object(nullptr)
    {
    }

    RegularExpression::RegularExpression(Adopt adopt) : Object(adopt)
    {
    }

    void RegularExpression::enumerate_matches_in_string(const std::string& string, MatchingOptions options, const Range& range, std::function<void(TextCheckingResult, MatchingFlags, bool&)> block) const
    {
        [cocoon::internal::ns<::NSRegularExpression>(this) enumerateMatchesInString:cocoon::internal::to(string) options:static_cast<::NSMatchingOptions>(options) range:cocoon::internal::to(range) usingBlock:(block ? (void (^)(::NSTextCheckingResult*, ::NSMatchingFlags, BOOL*)) ^ void(::NSTextCheckingResult * a214_0, ::NSMatchingFlags a214_1, ::BOOL * a214_2) { bool __o214_2 = a214_2 ? static_cast<bool>(*a214_2) : bool(); block(cocoon::internal::wrap<TextCheckingResult>(a214_0), static_cast<MatchingFlags>(a214_1), __o214_2); if (a214_2) { *a214_2 = static_cast<::BOOL>(__o214_2); } } : (void (^)(::NSTextCheckingResult*, ::NSMatchingFlags, BOOL*))nil)];
    }

    std::string RegularExpression::escaped_pattern_for_string(const std::string& string)
    {
        return cocoon::internal::from([::NSRegularExpression escapedPatternForString:cocoon::internal::to(string)]);
    }

    std::string RegularExpression::escaped_template_for_string(const std::string& string)
    {
        return cocoon::internal::from([::NSRegularExpression escapedTemplateForString:cocoon::internal::to(string)]);
    }

    TextCheckingResult RegularExpression::first_match_in_string(const std::string& string, MatchingOptions options, const Range& range) const
    {
        return cocoon::internal::wrap<TextCheckingResult>([cocoon::internal::ns<::NSRegularExpression>(this) firstMatchInString:cocoon::internal::to(string) options:static_cast<::NSMatchingOptions>(options) range:cocoon::internal::to(range)]);
    }

    std::vector<TextCheckingResult> RegularExpression::matches_in_string(const std::string& string, MatchingOptions options, const Range& range) const
    {
        return cocoon::internal::from_array<TextCheckingResult>([cocoon::internal::ns<::NSRegularExpression>(this) matchesInString:cocoon::internal::to(string) options:static_cast<::NSMatchingOptions>(options) range:cocoon::internal::to(range)], [](id e) -> TextCheckingResult
                                                                {
                                                                    return cocoon::internal::wrap<TextCheckingResult>((::NSTextCheckingResult*)e);
                                                                });
    }

    std::uint64_t RegularExpression::number_of_matches_in_string(const std::string& string, MatchingOptions options, const Range& range) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSRegularExpression>(this) numberOfMatchesInString:cocoon::internal::to(string) options:static_cast<::NSMatchingOptions>(options) range:cocoon::internal::to(range)]);
    }

    Range RegularExpression::range_of_first_match_in_string(const std::string& string, MatchingOptions options, const Range& range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRegularExpression>(this) rangeOfFirstMatchInString:cocoon::internal::to(string) options:static_cast<::NSMatchingOptions>(options) range:cocoon::internal::to(range)]);
    }

    RegularExpression RegularExpression::regular_expression_with_pattern(const std::string& pattern, RegularExpressionOptions options)
    {
        NSError* __error = nil;
        auto __r = [::NSRegularExpression regularExpressionWithPattern:cocoon::internal::to(pattern) options:static_cast<::NSRegularExpressionOptions>(options) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<RegularExpression>(__r);
    }

    std::uint64_t RegularExpression::replace_matches_in_string(const std::string& string, MatchingOptions options, const Range& range, const std::string& templ) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSRegularExpression>(this) replaceMatchesInString:[cocoon::internal::to(string) mutableCopy] options:static_cast<::NSMatchingOptions>(options) range:cocoon::internal::to(range) withTemplate:cocoon::internal::to(templ)]);
    }

    std::string RegularExpression::replacement_string_for_result(const TextCheckingResult& result, const std::string& string, std::int64_t offset, const std::string& templ) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRegularExpression>(this) replacementStringForResult:cocoon::internal::native<::NSTextCheckingResult>(result) inString:cocoon::internal::to(string) offset:static_cast<::NSInteger>(offset) template:cocoon::internal::to(templ)]);
    }

    std::string RegularExpression::string_by_replacing_matches_in_string(const std::string& string, MatchingOptions options, const Range& range, const std::string& templ) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRegularExpression>(this) stringByReplacingMatchesInString:cocoon::internal::to(string) options:static_cast<::NSMatchingOptions>(options) range:cocoon::internal::to(range) withTemplate:cocoon::internal::to(templ)]);
    }

    std::uint64_t RegularExpression::number_of_capture_groups() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSRegularExpression>(this) numberOfCaptureGroups]);
    }

    RegularExpressionOptions RegularExpression::options() const
    {
        return static_cast<RegularExpressionOptions>([cocoon::internal::ns<::NSRegularExpression>(this) options]);
    }

    std::string RegularExpression::pattern() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRegularExpression>(this) pattern]);
    }
}
