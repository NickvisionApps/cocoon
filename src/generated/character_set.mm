#include "generated/character_set.h"
#include "internal.h"

namespace cocoon
{
    CharacterSet::CharacterSet() : CharacterSet(Adopt{cocoon::internal::retain([[::NSCharacterSet alloc] init])})
    {
    }

    CharacterSet::CharacterSet(std::nullptr_t) : Object(nullptr)
    {
    }

    CharacterSet::CharacterSet(Adopt adopt) : Object(adopt)
    {
    }

    bool CharacterSet::character_is_member(std::uint16_t a_character) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCharacterSet>(this) characterIsMember:static_cast<::unichar>(a_character)]);
    }

    CharacterSet CharacterSet::character_set_with_bitmap_representation(const std::vector<std::uint8_t>& data)
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet characterSetWithBitmapRepresentation:cocoon::internal::to_data(data)]);
    }

    CharacterSet CharacterSet::character_set_with_characters_in_string(const std::string& a_string)
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet characterSetWithCharactersInString:cocoon::internal::to(a_string)]);
    }

    CharacterSet CharacterSet::character_set_with_contents_of_file(const std::string& f_name)
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet characterSetWithContentsOfFile:cocoon::internal::to(f_name)]);
    }

    CharacterSet CharacterSet::character_set_with_range(const Range& a_range)
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet characterSetWithRange:cocoon::internal::to(a_range)]);
    }

    bool CharacterSet::has_member_in_plane(std::uint8_t the_plane) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCharacterSet>(this) hasMemberInPlane:static_cast<::uint8_t>(the_plane)]);
    }

    bool CharacterSet::is_superset_of_set(const CharacterSet& the_other_set) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCharacterSet>(this) isSupersetOfSet:cocoon::internal::native<::NSCharacterSet>(the_other_set)]);
    }

    bool CharacterSet::long_character_is_member(unsigned int the_long_char) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCharacterSet>(this) longCharacterIsMember:static_cast<::UTF32Char>(the_long_char)]);
    }

    CharacterSet CharacterSet::url_fragment_allowed_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet URLFragmentAllowedCharacterSet]);
    }

    CharacterSet CharacterSet::url_host_allowed_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet URLHostAllowedCharacterSet]);
    }

    CharacterSet CharacterSet::url_password_allowed_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet URLPasswordAllowedCharacterSet]);
    }

    CharacterSet CharacterSet::url_path_allowed_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet URLPathAllowedCharacterSet]);
    }

    CharacterSet CharacterSet::url_query_allowed_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet URLQueryAllowedCharacterSet]);
    }

    CharacterSet CharacterSet::url_user_allowed_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet URLUserAllowedCharacterSet]);
    }

    CharacterSet CharacterSet::alphanumeric_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet alphanumericCharacterSet]);
    }

    std::vector<std::uint8_t> CharacterSet::bitmap_representation() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSCharacterSet>(this) bitmapRepresentation]);
    }

    CharacterSet CharacterSet::capitalized_letter_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet capitalizedLetterCharacterSet]);
    }

    CharacterSet CharacterSet::control_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet controlCharacterSet]);
    }

    CharacterSet CharacterSet::decimal_digit_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet decimalDigitCharacterSet]);
    }

    CharacterSet CharacterSet::decomposable_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet decomposableCharacterSet]);
    }

    CharacterSet CharacterSet::illegal_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet illegalCharacterSet]);
    }

    CharacterSet CharacterSet::inverted_set() const
    {
        return cocoon::internal::wrap<CharacterSet>([cocoon::internal::ns<::NSCharacterSet>(this) invertedSet]);
    }

    CharacterSet CharacterSet::letter_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet letterCharacterSet]);
    }

    CharacterSet CharacterSet::lowercase_letter_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet lowercaseLetterCharacterSet]);
    }

    CharacterSet CharacterSet::newline_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet newlineCharacterSet]);
    }

    CharacterSet CharacterSet::non_base_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet nonBaseCharacterSet]);
    }

    CharacterSet CharacterSet::punctuation_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet punctuationCharacterSet]);
    }

    CharacterSet CharacterSet::symbol_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet symbolCharacterSet]);
    }

    CharacterSet CharacterSet::uppercase_letter_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet uppercaseLetterCharacterSet]);
    }

    CharacterSet CharacterSet::whitespace_and_newline_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet whitespaceAndNewlineCharacterSet]);
    }

    CharacterSet CharacterSet::whitespace_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSCharacterSet whitespaceCharacterSet]);
    }
}
