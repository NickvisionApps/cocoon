#include "generated/mutable_character_set.h"
#include "internal.h"

namespace cocoon
{
    MutableCharacterSet::MutableCharacterSet() : MutableCharacterSet(Adopt{cocoon::internal::retain([[::NSMutableCharacterSet alloc] init])})
    {
    }

    MutableCharacterSet::MutableCharacterSet(std::nullptr_t) : CharacterSet(nullptr)
    {
    }

    MutableCharacterSet::MutableCharacterSet(Adopt adopt) : CharacterSet(adopt)
    {
    }

    void MutableCharacterSet::add_characters_in_range(const Range& a_range) const
    {
        [cocoon::internal::ns<::NSMutableCharacterSet>(this) addCharactersInRange:cocoon::internal::to(a_range)];
    }

    void MutableCharacterSet::add_characters_in_string(const std::string& a_string) const
    {
        [cocoon::internal::ns<::NSMutableCharacterSet>(this) addCharactersInString:cocoon::internal::to(a_string)];
    }

    MutableCharacterSet MutableCharacterSet::alphanumeric_character_set()
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet alphanumericCharacterSet]);
    }

    MutableCharacterSet MutableCharacterSet::capitalized_letter_character_set()
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet capitalizedLetterCharacterSet]);
    }

    MutableCharacterSet MutableCharacterSet::character_set_with_bitmap_representation(const std::vector<std::uint8_t>& data)
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet characterSetWithBitmapRepresentation:cocoon::internal::to_data(data)]);
    }

    MutableCharacterSet MutableCharacterSet::character_set_with_characters_in_string(const std::string& a_string)
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet characterSetWithCharactersInString:cocoon::internal::to(a_string)]);
    }

    MutableCharacterSet MutableCharacterSet::character_set_with_contents_of_file(const std::string& f_name)
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet characterSetWithContentsOfFile:cocoon::internal::to(f_name)]);
    }

    MutableCharacterSet MutableCharacterSet::character_set_with_range(const Range& a_range)
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet characterSetWithRange:cocoon::internal::to(a_range)]);
    }

    MutableCharacterSet MutableCharacterSet::control_character_set()
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet controlCharacterSet]);
    }

    MutableCharacterSet MutableCharacterSet::decimal_digit_character_set()
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet decimalDigitCharacterSet]);
    }

    MutableCharacterSet MutableCharacterSet::decomposable_character_set()
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet decomposableCharacterSet]);
    }

    void MutableCharacterSet::form_intersection_with_character_set(const CharacterSet& other_set) const
    {
        [cocoon::internal::ns<::NSMutableCharacterSet>(this) formIntersectionWithCharacterSet:cocoon::internal::native<::NSCharacterSet>(other_set)];
    }

    void MutableCharacterSet::form_union_with_character_set(const CharacterSet& other_set) const
    {
        [cocoon::internal::ns<::NSMutableCharacterSet>(this) formUnionWithCharacterSet:cocoon::internal::native<::NSCharacterSet>(other_set)];
    }

    MutableCharacterSet MutableCharacterSet::illegal_character_set()
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet illegalCharacterSet]);
    }

    void MutableCharacterSet::invert() const
    {
        [cocoon::internal::ns<::NSMutableCharacterSet>(this) invert];
    }

    MutableCharacterSet MutableCharacterSet::letter_character_set()
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet letterCharacterSet]);
    }

    MutableCharacterSet MutableCharacterSet::lowercase_letter_character_set()
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet lowercaseLetterCharacterSet]);
    }

    MutableCharacterSet MutableCharacterSet::newline_character_set()
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet newlineCharacterSet]);
    }

    MutableCharacterSet MutableCharacterSet::non_base_character_set()
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet nonBaseCharacterSet]);
    }

    MutableCharacterSet MutableCharacterSet::punctuation_character_set()
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet punctuationCharacterSet]);
    }

    void MutableCharacterSet::remove_characters_in_range(const Range& a_range) const
    {
        [cocoon::internal::ns<::NSMutableCharacterSet>(this) removeCharactersInRange:cocoon::internal::to(a_range)];
    }

    void MutableCharacterSet::remove_characters_in_string(const std::string& a_string) const
    {
        [cocoon::internal::ns<::NSMutableCharacterSet>(this) removeCharactersInString:cocoon::internal::to(a_string)];
    }

    MutableCharacterSet MutableCharacterSet::symbol_character_set()
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet symbolCharacterSet]);
    }

    MutableCharacterSet MutableCharacterSet::uppercase_letter_character_set()
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet uppercaseLetterCharacterSet]);
    }

    MutableCharacterSet MutableCharacterSet::whitespace_and_newline_character_set()
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet whitespaceAndNewlineCharacterSet]);
    }

    MutableCharacterSet MutableCharacterSet::whitespace_character_set()
    {
        return cocoon::internal::wrap<MutableCharacterSet>([::NSMutableCharacterSet whitespaceCharacterSet]);
    }
}
