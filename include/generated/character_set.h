#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSCharacterSet` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CharacterSet character_set;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CharacterSet character_set{};
     * character_set.character_is_member(1);
     * character_set.has_member_in_plane(1);
     * character_set.is_superset_of_set(cocoon::CharacterSet());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nscharacterset
     */
    class CharacterSet : public Object
    {
    public:
        /// @brief Creates a new `NSCharacterSet` instance and returns a handle to it.
        explicit CharacterSet(const std::vector<std::uint8_t>& data);
        /// @brief Creates a new `NSCharacterSet` instance and returns a handle to it.
        explicit CharacterSet(const std::string& a_string);
        /// @brief Creates a new `NSCharacterSet` instance and returns a handle to it.
        explicit CharacterSet(const Range& a_range);
        /// @brief Creates a new `NSCharacterSet` instance and returns a handle to it.
        explicit CharacterSet();
        /// @brief Creates a null handle that refers to no native object.
        CharacterSet(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CharacterSet(Adopt adopt);
        /**
         * @brief Calls `-[NSCharacterSet characterIsMember:]`.
         * @param a_character Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool character_is_member(std::uint16_t a_character) const;
        /**
         * @brief Calls `-[NSCharacterSet hasMemberInPlane:]`.
         * @param the_plane Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool has_member_in_plane(std::uint8_t the_plane) const;
        /**
         * @brief Calls `-[NSCharacterSet isSupersetOfSet:]`.
         * @param the_other_set Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_superset_of_set(const CharacterSet& the_other_set) const;
        /**
         * @brief Calls `-[NSCharacterSet longCharacterIsMember:]`.
         * @param the_long_char Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool long_character_is_member(unsigned int the_long_char) const;
        /**
         * @brief Returns the `URLFragmentAllowedCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet url_fragment_allowed_character_set();
        /**
         * @brief Returns the `URLHostAllowedCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet url_host_allowed_character_set();
        /**
         * @brief Returns the `URLPasswordAllowedCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet url_password_allowed_character_set();
        /**
         * @brief Returns the `URLPathAllowedCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet url_path_allowed_character_set();
        /**
         * @brief Returns the `URLQueryAllowedCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet url_query_allowed_character_set();
        /**
         * @brief Returns the `URLUserAllowedCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet url_user_allowed_character_set();
        /**
         * @brief Returns the `alphanumericCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet alphanumeric_character_set();
        /**
         * @brief Returns the `bitmapRepresentation` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> bitmap_representation() const;
        /**
         * @brief Returns the `capitalizedLetterCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet capitalized_letter_character_set();
        /**
         * @brief Returns the `controlCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet control_character_set();
        /**
         * @brief Returns the `decimalDigitCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet decimal_digit_character_set();
        /**
         * @brief Returns the `decomposableCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet decomposable_character_set();
        /**
         * @brief Returns the `illegalCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet illegal_character_set();
        /**
         * @brief Returns the `invertedSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        CharacterSet inverted_set() const;
        /**
         * @brief Returns the `letterCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet letter_character_set();
        /**
         * @brief Returns the `lowercaseLetterCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet lowercase_letter_character_set();
        /**
         * @brief Returns the `newlineCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet newline_character_set();
        /**
         * @brief Returns the `nonBaseCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet non_base_character_set();
        /**
         * @brief Returns the `punctuationCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet punctuation_character_set();
        /**
         * @brief Returns the `symbolCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet symbol_character_set();
        /**
         * @brief Returns the `uppercaseLetterCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet uppercase_letter_character_set();
        /**
         * @brief Returns the `whitespaceAndNewlineCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet whitespace_and_newline_character_set();
        /**
         * @brief Returns the `whitespaceCharacterSet` property of `NSCharacterSet`.
         * @return The converted Objective-C result.
         */
        static CharacterSet whitespace_character_set();
    };
}
