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
     * @details An object representing a mutable set of Unicode character values for use in search operations. In Swift, this object bridges to ''CharacterSet''; use ''NSMutableCharacterSet'' when you need reference semantics or other Foundation-specific behavior. The 'NSMutableCharacterSet' class declares the programmatic interface to objects that manage a modifiable set of Unicode characters. You can add or remove characters from a mutable character set as numeric values in 'NSRange' structures or as character values in strings, combine character sets by union or intersection, and invert a character set. Mutable character sets are less efficient to use than immutable character sets. If you don't need to change a character set after creating it, create an immutable copy with 'copy' and use that. 'NSMutableCharacterSet' defines no primitive methods. Subclasses must implement all methods declared by this class in addition to the primitives of ''NSCharacterSet''. They must also implement ''NSMutableCopying/mutableCopy(with:)''. 'NSMutableCharacterSet' is "toll-free bridged" with its Core Foundation counterpart, \<doc://com.apple.documentation/documentation/corefoundation/cfmutablecharacterset>. See [Toll-Free Bridging](https://developer.apple.com/library/archive/documentation/General/Conceptual/CocoaEncyclopedia/Toll-FreeBridgin/Toll-FreeBridgin.html\#//apple_ref/doc/uid/TP40010810-CH2) for more information. > Important: > The Swift overlay to the Foundation framework provides the ''CharacterSet'' structure, which bridges to the ''NSMutableCharacterSet'' class and its immutable superclass, ''NSCharacterSet''. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>.
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
         * @details Adds to the receiver the characters whose Unicode values are in a given range. This code excerpt adds to a character set the lowercase English alphabetic characters: '''objc NSMutableCharacterSet aCharacterSet = [[NSMutableCharacterSet alloc] init]; NSRange lcEnglishRange; lcEnglishRange.location = (unsigned int)'a'; lcEnglishRange.length = 26; [aCharacterSet addCharactersInRange:lcEnglishRange]; ''' - Parameter aRange: The range of characters to add. 'aRange.location' is the value of the first character to add; 'aRange.location + aRange.length - 1' is the value of the last. If 'aRange.length' is '0', this method has no effect.
         * @param a_range Argument converted to the Objective-C parameter of the same role.
         */
        void add_characters_in_range(const Range& a_range) const;
        /**
         * @brief Calls `-[NSMutableCharacterSet addCharactersInString:]`.
         * @details Adds to the receiver the characters in a given string. This method has no effect if 'aString' is empty. - Parameter aString: The characters to add to the receiver.
         * @param a_string Argument converted to the Objective-C parameter of the same role.
         */
        void add_characters_in_string(const std::string& a_string) const;
        /**
         * @brief Calls `+[NSMutableCharacterSet alphanumericCharacterSet]`.
         * @details Returns a mutable character set containing the characters in Unicode General Categories L\\, M\\, and N\\.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet alphanumeric_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet capitalizedLetterCharacterSet]`.
         * @details Returns a mutable character set containing the characters in Unicode General Category Lt.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet capitalized_letter_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet characterSetWithBitmapRepresentation:]`.
         * @details Returns a mutable character set containing characters determined by a given bitmap representation.
         * @param data Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet character_set_with_bitmap_representation(const std::vector<std::uint8_t>& data);
        /**
         * @brief Calls `+[NSMutableCharacterSet characterSetWithCharactersInString:]`.
         * @details Returns a mutable character set containing the characters in a given string.
         * @param a_string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet character_set_with_characters_in_string(const std::string& a_string);
        /**
         * @brief Calls `+[NSMutableCharacterSet characterSetWithContentsOfFile:]`.
         * @details Returns a mutable character set read from the bitmap representation stored in the file at a given path.
         * @param f_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet character_set_with_contents_of_file(const std::string& f_name);
        /**
         * @brief Calls `+[NSMutableCharacterSet characterSetWithRange:]`.
         * @details Returns a mutable character set containing characters with Unicode values in a given range.
         * @param a_range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet character_set_with_range(const Range& a_range);
        /**
         * @brief Calls `+[NSMutableCharacterSet controlCharacterSet]`.
         * @details Returns a mutable character set containing the characters in Unicode General Category Cc and Cf.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet control_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet decimalDigitCharacterSet]`.
         * @details Returns a mutable character set containing the characters in the category of decimal numbers.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet decimal_digit_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet decomposableCharacterSet]`.
         * @details Returns a mutable character set containing individual Unicode characters that can also be represented as composed character sequences (such as for letters with accents), by the definition of "standard decomposition" in version 3.2 of the Unicode character encoding standard.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet decomposable_character_set();
        /**
         * @brief Calls `-[NSMutableCharacterSet formIntersectionWithCharacterSet:]`.
         * @details Modifies the receiver so it contains only characters that exist in both the receiver and another set. - Parameter otherSet: The character set with which to perform the intersection.
         * @param other_set Argument converted to the Objective-C parameter of the same role.
         */
        void form_intersection_with_character_set(const CharacterSet& other_set) const;
        /**
         * @brief Calls `-[NSMutableCharacterSet formUnionWithCharacterSet:]`.
         * @details Modifies the receiver so it contains all characters that exist in either the receiver or another set.
         * @param other_set Argument converted to the Objective-C parameter of the same role.
         */
        void form_union_with_character_set(const CharacterSet& other_set) const;
        /**
         * @brief Calls `+[NSMutableCharacterSet illegalCharacterSet]`.
         * @details Returns a mutable character set containing values in the category of Non-Characters or that have not yet been defined in version 3.2 of the Unicode standard.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet illegal_character_set();
        /**
         * @brief Calls `-[NSMutableCharacterSet invert]`.
         * @details Replaces all the characters in the receiver with all the characters it didn't previously contain. Inverting a mutable character set, whether by 'invert' or by 'invertedSet', is much less efficient than inverting an immutable character set with 'invertedSet'.
         */
        void invert() const;
        /**
         * @brief Calls `+[NSMutableCharacterSet letterCharacterSet]`.
         * @details Returns a mutable character set containing the characters in Unicode General Category L\\ & M\\.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet letter_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet lowercaseLetterCharacterSet]`.
         * @details Returns a mutable character set containing the characters in Unicode General Category Ll.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet lowercase_letter_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet newlineCharacterSet]`.
         * @details Returns a mutable character set containing the newline characters ('U+000A' ~ 'U+000D', 'U+0085', 'U+2028', and 'U+2029').
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet newline_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet nonBaseCharacterSet]`.
         * @details Returns a mutable character set containing the characters in Unicode General Category M\\.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet non_base_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet punctuationCharacterSet]`.
         * @details Returns a mutable character set containing the characters in Unicode General Category P\\.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet punctuation_character_set();
        /**
         * @brief Calls `-[NSMutableCharacterSet removeCharactersInRange:]`.
         * @details Removes from the receiver the characters whose Unicode values are in a given range. - Parameter aRange: The range of characters to remove. 'aRange.location' is the value of the first character to remove; 'aRange.location + aRange.length - 1' is the value of the last. If 'aRange.length' is '0', this method has no effect.
         * @param a_range Argument converted to the Objective-C parameter of the same role.
         */
        void remove_characters_in_range(const Range& a_range) const;
        /**
         * @brief Calls `-[NSMutableCharacterSet removeCharactersInString:]`.
         * @details Removes from the receiver the characters in a given string. This method has no effect if 'aString' is empty. - Parameter aString: The characters to remove from the receiver.
         * @param a_string Argument converted to the Objective-C parameter of the same role.
         */
        void remove_characters_in_string(const std::string& a_string) const;
        /**
         * @brief Calls `+[NSMutableCharacterSet symbolCharacterSet]`.
         * @details Returns a mutable character set containing the characters in Unicode General Category S\\.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet symbol_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet uppercaseLetterCharacterSet]`.
         * @details Returns a mutable character set containing the characters in Unicode General Category Lu and Lt.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet uppercase_letter_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet whitespaceAndNewlineCharacterSet]`.
         * @details Returns a mutable character set containing characters in Unicode General Category Z\\, 'U+000A' ~ 'U+000D', and 'U+0085'.
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet whitespace_and_newline_character_set();
        /**
         * @brief Calls `+[NSMutableCharacterSet whitespaceCharacterSet]`.
         * @details Returns a mutable character set containing the characters in Unicode General Category Zs and 'CHARACTER TABULATION' ('U+0009').
         * @return The converted Objective-C result.
         */
        static MutableCharacterSet whitespace_character_set();
    };
}
