#pragma once

#include "generated/availability.h"
#include "generated/character_set.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class CharacterSet;

    /**
     * @brief C++ handle for the Objective-C class `NSMutableCharacterSet` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref CharacterSet.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MutableCharacterSet mutable_character_set;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MutableCharacterSet mutable_character_set{};
     * auto made_0 = cocoon::MutableCharacterSet::alphanumeric_character_set();
     * auto made_1 = cocoon::MutableCharacterSet::capitalized_letter_character_set();
     * mutable_character_set.add_characters_in_string("text");
     * mutable_character_set.form_intersection_with_character_set(cocoon::CharacterSet());
     * mutable_character_set.form_union_with_character_set(cocoon::CharacterSet());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmutablecharacterset
     */
    class MutableCharacterSet : public CharacterSet
    {
    public:
        /// @brief Creates a new `NSMutableCharacterSet` instance and returns a handle to it.
        explicit MutableCharacterSet();
        /// @brief Creates a null handle that refers to no native object.
        MutableCharacterSet(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MutableCharacterSet(Adopt adopt);
        using CharacterSet::alphanumeric_character_set;
        using CharacterSet::capitalized_letter_character_set;
        using CharacterSet::control_character_set;
        using CharacterSet::decimal_digit_character_set;
        using CharacterSet::decomposable_character_set;
        using CharacterSet::illegal_character_set;
        using CharacterSet::letter_character_set;
        using CharacterSet::lowercase_letter_character_set;
        using CharacterSet::newline_character_set;
        using CharacterSet::non_base_character_set;
        using CharacterSet::punctuation_character_set;
        using CharacterSet::symbol_character_set;
        using CharacterSet::uppercase_letter_character_set;
        using CharacterSet::whitespace_and_newline_character_set;
        using CharacterSet::whitespace_character_set;
        /**
         * @brief Calls `-[NSMutableCharacterSet addCharactersInRange:]`.
         * @param a_range Argument converted to the Objective-C parameter of the same role.
         */
        void add_characters_in_range(const Range& a_range) const;
        /**
         * @brief Calls `-[NSMutableCharacterSet addCharactersInString:]`.
         * @param a_string Argument converted to the Objective-C parameter of the same role.
         */
        void add_characters_in_string(const std::string& a_string) const;
        /**
         * @brief Calls `+[NSMutableCharacterSet alphanumericCharacterSet]`.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet alphanumeric_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet capitalizedLetterCharacterSet]`.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet capitalized_letter_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet characterSetWithBitmapRepresentation:]`.
         * @param data Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet character_set_with_bitmap_representation(const std::vector<std::uint8_t>& data);
        /**
         * @brief Calls `+[NSMutableCharacterSet characterSetWithCharactersInString:]`.
         * @param a_string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet character_set_with_characters_in_string(const std::string& a_string);
        /**
         * @brief Calls `+[NSMutableCharacterSet characterSetWithContentsOfFile:]`.
         * @param f_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet character_set_with_contents_of_file(const std::string& f_name);
        /**
         * @brief Calls `+[NSMutableCharacterSet characterSetWithRange:]`.
         * @param a_range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet character_set_with_range(const Range& a_range);
        /**
         * @brief Calls `+[NSMutableCharacterSet controlCharacterSet]`.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet control_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet decimalDigitCharacterSet]`.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet decimal_digit_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet decomposableCharacterSet]`.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet decomposable_character_set();
        /**
         * @brief Calls `-[NSMutableCharacterSet formIntersectionWithCharacterSet:]`.
         * @param other_set Argument converted to the Objective-C parameter of the same role.
         */
        void form_intersection_with_character_set(const CharacterSet& other_set) const;
        /**
         * @brief Calls `-[NSMutableCharacterSet formUnionWithCharacterSet:]`.
         * @param other_set Argument converted to the Objective-C parameter of the same role.
         */
        void form_union_with_character_set(const CharacterSet& other_set) const;
        /**
         * @brief Calls `+[NSMutableCharacterSet illegalCharacterSet]`.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet illegal_character_set();
        /**
         * @brief Calls `-[NSMutableCharacterSet invert]`.
         */
        void invert() const;
        /**
         * @brief Calls `+[NSMutableCharacterSet letterCharacterSet]`.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet letter_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet lowercaseLetterCharacterSet]`.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet lowercase_letter_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet newlineCharacterSet]`.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet newline_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet nonBaseCharacterSet]`.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet non_base_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet punctuationCharacterSet]`.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet punctuation_character_set();
        /**
         * @brief Calls `-[NSMutableCharacterSet removeCharactersInRange:]`.
         * @param a_range Argument converted to the Objective-C parameter of the same role.
         */
        void remove_characters_in_range(const Range& a_range) const;
        /**
         * @brief Calls `-[NSMutableCharacterSet removeCharactersInString:]`.
         * @param a_string Argument converted to the Objective-C parameter of the same role.
         */
        void remove_characters_in_string(const std::string& a_string) const;
        /**
         * @brief Calls `+[NSMutableCharacterSet symbolCharacterSet]`.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet symbol_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet uppercaseLetterCharacterSet]`.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet uppercase_letter_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet whitespaceAndNewlineCharacterSet]`.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet whitespace_and_newline_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet whitespaceCharacterSet]`.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet whitespace_character_set();
    };
}
