#include "generated/linguistic_tagger.h"
#include "internal.h"

namespace cocoon
{
    LinguisticTagger::LinguisticTagger(const std::vector<std::string>& tag_schemes, std::uint64_t opts) : LinguisticTagger(Adopt{cocoon::internal::retain([[::NSLinguisticTagger alloc] initWithTagSchemes:cocoon::internal::to_array(tag_schemes, [](const std::string& e) -> id
                                                                                                                                                                                                          {
                                                                                                                                                                                                              return cocoon::internal::to(e);
                                                                                                                                                                                                          })
                                                                                                                                                                                     options:static_cast<::NSUInteger>(opts)])})
    {
    }

    LinguisticTagger::LinguisticTagger() : LinguisticTagger(Adopt{cocoon::internal::retain([[::NSLinguisticTagger alloc] init])})
    {
    }

    LinguisticTagger::LinguisticTagger(std::nullptr_t) : Object(nullptr)
    {
    }

    LinguisticTagger::LinguisticTagger(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<std::string> LinguisticTagger::available_tag_schemes_for_language(const std::string& language)
    {
        return cocoon::internal::from_array<std::string>([::NSLinguisticTagger availableTagSchemesForLanguage:cocoon::internal::to(language)], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> LinguisticTagger::available_tag_schemes_for_unit(LinguisticTaggerUnit unit, const std::string& language)
    {
        return cocoon::internal::from_array<std::string>([::NSLinguisticTagger availableTagSchemesForUnit:static_cast<::NSLinguisticTaggerUnit>(unit) language:cocoon::internal::to(language)], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::string LinguisticTagger::dominant_language_for_string(const std::string& string)
    {
        return cocoon::internal::from([::NSLinguisticTagger dominantLanguageForString:cocoon::internal::to(string)]);
    }

    void LinguisticTagger::enumerate_tags_for_string(const std::string& string, const Range& range, LinguisticTaggerUnit unit, const std::string& scheme, LinguisticTaggerOptions options, const Orthography& orthography, std::function<void(std::string, Range, bool&)> block)
    {
        [::NSLinguisticTagger enumerateTagsForString:cocoon::internal::to(string) range:cocoon::internal::to(range) unit:static_cast<::NSLinguisticTaggerUnit>(unit) scheme:cocoon::internal::to(scheme) options:static_cast<::NSLinguisticTaggerOptions>(options) orthography:cocoon::internal::native<::NSOrthography>(orthography) usingBlock:(block ? (void (^)(::NSLinguisticTag, ::NSRange, BOOL*)) ^ void(NSString * a189_0, ::NSRange a189_1, ::BOOL * a189_2) { bool __o189_2 = a189_2 ? static_cast<bool>(*a189_2) : bool(); block(cocoon::internal::from(a189_0), cocoon::internal::from(a189_1), __o189_2); if (a189_2) { *a189_2 = static_cast<::BOOL>(__o189_2); } } : (void (^)(::NSLinguisticTag, ::NSRange, BOOL*))nil)];
    }

    void LinguisticTagger::enumerate_tags_in_range(const Range& range, const std::string& tag_scheme, LinguisticTaggerOptions opts, std::function<void(std::string, Range, Range, bool&)> block) const
    {
        [cocoon::internal::ns<::NSLinguisticTagger>(this) enumerateTagsInRange:cocoon::internal::to(range) scheme:cocoon::internal::to(tag_scheme) options:static_cast<::NSLinguisticTaggerOptions>(opts) usingBlock:(block ? (void (^)(::NSLinguisticTag, ::NSRange, ::NSRange, BOOL*)) ^ void(NSString * a190_0, ::NSRange a190_1, ::NSRange a190_2, ::BOOL * a190_3) { bool __o190_3 = a190_3 ? static_cast<bool>(*a190_3) : bool(); block(cocoon::internal::from(a190_0), cocoon::internal::from(a190_1), cocoon::internal::from(a190_2), __o190_3); if (a190_3) { *a190_3 = static_cast<::BOOL>(__o190_3); } } : (void (^)(::NSLinguisticTag, ::NSRange, ::NSRange, BOOL*))nil)];
    }

    void LinguisticTagger::enumerate_tags_in_range(const Range& range, LinguisticTaggerUnit unit, const std::string& scheme, LinguisticTaggerOptions options, std::function<void(std::string, Range, bool&)> block) const
    {
        [cocoon::internal::ns<::NSLinguisticTagger>(this) enumerateTagsInRange:cocoon::internal::to(range) unit:static_cast<::NSLinguisticTaggerUnit>(unit) scheme:cocoon::internal::to(scheme) options:static_cast<::NSLinguisticTaggerOptions>(options) usingBlock:(block ? (void (^)(::NSLinguisticTag, ::NSRange, BOOL*)) ^ void(NSString * a191_0, ::NSRange a191_1, ::BOOL * a191_2) { bool __o191_2 = a191_2 ? static_cast<bool>(*a191_2) : bool(); block(cocoon::internal::from(a191_0), cocoon::internal::from(a191_1), __o191_2); if (a191_2) { *a191_2 = static_cast<::BOOL>(__o191_2); } } : (void (^)(::NSLinguisticTag, ::NSRange, BOOL*))nil)];
    }

    Orthography LinguisticTagger::orthography_at_index(std::uint64_t char_index, Range* effective_range) const
    {
        return cocoon::internal::wrap<Orthography>([cocoon::internal::ns<::NSLinguisticTagger>(this) orthographyAtIndex:static_cast<::NSUInteger>(char_index) effectiveRange:(::NSRangePointer)(effective_range)]);
    }

    std::vector<std::string> LinguisticTagger::possible_tags_at_index(std::uint64_t char_index, const std::string& tag_scheme, Range* token_range, Range* sentence_range, std::vector<Value>& scores) const
    {
        NSArray* __v_scores = nil;
        auto __r = [cocoon::internal::ns<::NSLinguisticTagger>(this) possibleTagsAtIndex:static_cast<::NSUInteger>(char_index) scheme:cocoon::internal::to(tag_scheme) tokenRange:(::NSRangePointer)(token_range)sentenceRange:(::NSRangePointer)(sentence_range)scores:&__v_scores];
        scores = cocoon::internal::from_array<Value>(__v_scores, [](id e) -> Value
                                       {
                                           return cocoon::internal::wrap<Value>((::NSValue*)e);
                                       });
        return cocoon::internal::from_array<std::string>(__r, [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    Range LinguisticTagger::sentence_range_for_range(const Range& range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLinguisticTagger>(this) sentenceRangeForRange:cocoon::internal::to(range)]);
    }

    void LinguisticTagger::set_orthography(const Orthography& orthography, const Range& range) const
    {
        [cocoon::internal::ns<::NSLinguisticTagger>(this) setOrthography:cocoon::internal::native<::NSOrthography>(orthography) range:cocoon::internal::to(range)];
    }

    void LinguisticTagger::string_edited_in_range(const Range& new_range, std::int64_t delta) const
    {
        [cocoon::internal::ns<::NSLinguisticTagger>(this) stringEditedInRange:cocoon::internal::to(new_range) changeInLength:static_cast<::NSInteger>(delta)];
    }

    std::string LinguisticTagger::tag_at_index(std::uint64_t char_index, const std::string& scheme, Range* token_range, Range* sentence_range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLinguisticTagger>(this) tagAtIndex:static_cast<::NSUInteger>(char_index) scheme:cocoon::internal::to(scheme) tokenRange:(::NSRangePointer)(token_range)sentenceRange:(::NSRangePointer)(sentence_range)]);
    }

    std::string LinguisticTagger::tag_at_index(std::uint64_t char_index, LinguisticTaggerUnit unit, const std::string& scheme, Range* token_range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLinguisticTagger>(this) tagAtIndex:static_cast<::NSUInteger>(char_index) unit:static_cast<::NSLinguisticTaggerUnit>(unit) scheme:cocoon::internal::to(scheme) tokenRange:(::NSRangePointer)(token_range)]);
    }

    std::string LinguisticTagger::tag_for_string(const std::string& string, std::uint64_t char_index, LinguisticTaggerUnit unit, const std::string& scheme, const Orthography& orthography, Range* token_range)
    {
        return cocoon::internal::from([::NSLinguisticTagger tagForString:cocoon::internal::to(string) atIndex:static_cast<::NSUInteger>(char_index) unit:static_cast<::NSLinguisticTaggerUnit>(unit) scheme:cocoon::internal::to(scheme) orthography:cocoon::internal::native<::NSOrthography>(orthography) tokenRange:(::NSRangePointer)(token_range)]);
    }

    std::vector<std::string> LinguisticTagger::tags_for_string(const std::string& string, const Range& range, LinguisticTaggerUnit unit, const std::string& scheme, LinguisticTaggerOptions options, const Orthography& orthography, std::vector<Value>& token_ranges)
    {
        NSArray* __v_token_ranges = nil;
        auto __r = [::NSLinguisticTagger tagsForString:cocoon::internal::to(string) range:cocoon::internal::to(range) unit:static_cast<::NSLinguisticTaggerUnit>(unit) scheme:cocoon::internal::to(scheme) options:static_cast<::NSLinguisticTaggerOptions>(options) orthography:cocoon::internal::native<::NSOrthography>(orthography) tokenRanges:&__v_token_ranges];
        token_ranges = cocoon::internal::from_array<Value>(__v_token_ranges, [](id e) -> Value
                                             {
                                                 return cocoon::internal::wrap<Value>((::NSValue*)e);
                                             });
        return cocoon::internal::from_array<std::string>(__r, [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> LinguisticTagger::tags_in_range(const Range& range, const std::string& tag_scheme, LinguisticTaggerOptions opts, std::vector<Value>& token_ranges) const
    {
        NSArray* __v_token_ranges = nil;
        auto __r = [cocoon::internal::ns<::NSLinguisticTagger>(this) tagsInRange:cocoon::internal::to(range) scheme:cocoon::internal::to(tag_scheme) options:static_cast<::NSLinguisticTaggerOptions>(opts) tokenRanges:&__v_token_ranges];
        token_ranges = cocoon::internal::from_array<Value>(__v_token_ranges, [](id e) -> Value
                                             {
                                                 return cocoon::internal::wrap<Value>((::NSValue*)e);
                                             });
        return cocoon::internal::from_array<std::string>(__r, [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> LinguisticTagger::tags_in_range(const Range& range, LinguisticTaggerUnit unit, const std::string& scheme, LinguisticTaggerOptions options, std::vector<Value>& token_ranges) const
    {
        NSArray* __v_token_ranges = nil;
        auto __r = [cocoon::internal::ns<::NSLinguisticTagger>(this) tagsInRange:cocoon::internal::to(range) unit:static_cast<::NSLinguisticTaggerUnit>(unit) scheme:cocoon::internal::to(scheme) options:static_cast<::NSLinguisticTaggerOptions>(options) tokenRanges:&__v_token_ranges];
        token_ranges = cocoon::internal::from_array<Value>(__v_token_ranges, [](id e) -> Value
                                             {
                                                 return cocoon::internal::wrap<Value>((::NSValue*)e);
                                             });
        return cocoon::internal::from_array<std::string>(__r, [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    Range LinguisticTagger::token_range_at_index(std::uint64_t char_index, LinguisticTaggerUnit unit) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLinguisticTagger>(this) tokenRangeAtIndex:static_cast<::NSUInteger>(char_index) unit:static_cast<::NSLinguisticTaggerUnit>(unit)]);
    }

    std::string LinguisticTagger::dominant_language() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLinguisticTagger>(this) dominantLanguage]);
    }

    std::string LinguisticTagger::string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLinguisticTagger>(this) string]);
    }

    void LinguisticTagger::set_string(const std::string& value) const
    {
        [cocoon::internal::ns<::NSLinguisticTagger>(this) setString:cocoon::internal::to(value)];
    }

    std::vector<std::string> LinguisticTagger::tag_schemes() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSLinguisticTagger>(this) tagSchemes], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }
}
