#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSCharacterSet` (Foundation).
     * @details An object representing a fixed set of Unicode character values for use in search operations. In Swift, this bridges to a ''CharacterSet''; use ''NSCharacterSet'' when you need reference semantics or other Foundation-specific behavior. An 'NSCharacterSet' object represents a set of Unicode-compliant characters. 'NSString' and 'NSScanner' objects use 'NSCharacterSet' objects to group characters together for searching operations, so that they can find any of a particular set of characters during a search. The cluster's two public classes, 'NSCharacterSet' and ''NSMutableCharacterSet'', declare the programmatic interface for static and dynamic character sets, respectively. The objects you create using these classes are referred to as character set objects (and when no confusion will result, merely as character sets). Because of the nature of class clusters, character set objects aren't actual instances of the 'NSCharacterSet' or 'NSMutableCharacterSet' classes but of one of their private subclasses. Although a character set object's class is private, its interface is public, as declared by these abstract superclasses, 'NSCharacterSet' and 'NSMutableCharacterSet'. The character set classes adopt the 'NSCopying' and 'NSMutableCopying' protocols, making it convenient to convert a character set of one type to the other. The 'NSCharacterSet' class declares the programmatic interface for an object that manages a set of Unicode characters (see the ''NSString'' class cluster specification for information on Unicode). 'NSCharacterSet''s principal primitive method, ''characterIsMember(:)'', provides the basis for all other instance methods in its interface. A subclass of 'NSCharacterSet' needs only to implement this method, plus ''NSMutableCopying/mutableCopy(with:)'', for proper behavior. For optimal performance, a subclass should also override ''bitmapRepresentation'', which otherwise works by invoking ''characterIsMember(:)'' for every possible Unicode value. 'NSCharacterSet' is "toll-free bridged" with its Core Foundation counterpart, \<doc://com.apple.documentation/documentation/corefoundation/cfcharacterset>. See [Toll-Free Bridging](https://developer.apple.com/library/archive/documentation/General/Conceptual/CocoaEncyclopedia/Toll-FreeBridgin/Toll-FreeBridgin.html\#//apple_ref/doc/uid/TP40010810-CH2) for more information on toll-free bridging. > Important: > The Swift overlay to the Foundation framework provides the ''CharacterSet'' structure, which bridges to the ''NSCharacterSet'' class and its mutable subclass, ''NSMutableCharacterSet''. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>.
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
     * auto made_0 = cocoon::CharacterSet::character_set_with_characters_in_string("text");
     * auto made_1 = cocoon::CharacterSet::character_set_with_contents_of_file("text");
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
        explicit CharacterSet();
        /// @brief Creates a null handle that refers to no native object.
        CharacterSet(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CharacterSet(Adopt adopt);
        /**
     * @brief Calls `-[NSCharacterSet characterIsMember:]`.
     * @details Returns a Boolean value that indicates whether a given character is in the receiver. - Parameter aCharacter: The character to test for membership of the receiver. - Returns: 'YES' if 'aCharacter' is in the receiving character set, otherwise 'NO'.
     * @param a_character Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool character_is_member(std::uint16_t a_character) const;
        /**
     * @brief Calls `+[NSCharacterSet characterSetWithBitmapRepresentation:]`.
     * @details Returns a character set containing characters determined by a given bitmap representation. This method is useful for creating a character set object with data from a file or other external data source. A raw bitmap representation of a character set is a byte array with the first 2^16 bits (that is, 8192 bytes) representing the code point range of the Basic Multilingual Plane (BMP), such that the value of the bit at position n represents the presence in the character set of the character with decimal Unicode value n. A bitmap representation may contain zero to sixteen additional 8192 byte segments for each additional Unicode plane containing a character in a character set, with each 8192 byte segment prepended with a single plane index byte. To add a character in the Basic Multilingual Plane (BMP) with decimal Unicode value n to a raw bitmap representation, you might do the following: '''objc unsigned char bitmapRep[8192]; bitmapRep[n >> 3] |= (((unsigned int)1) \<\< (n & 7)); ''' To remove that character: '''objc bitmapRep[n >> 3] &= ~(((unsigned int)1) \<\< (n & 7)); ''' - Parameter data: A bitmap representation of a character set. - Returns: A character set containing characters determined by 'data'.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CharacterSet character_set_with_bitmap_representation(const std::vector<std::uint8_t>& data);
        /**
     * @brief Calls `+[NSCharacterSet characterSetWithCharactersInString:]`.
     * @details Returns a character set containing the characters in a given string. - Parameter aString: A string containing characters for the new character set. - Returns: A character set containing the characters in 'aString'. Returns an empty character set if 'aString' is empty.
     * @param a_string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CharacterSet character_set_with_characters_in_string(const std::string& a_string);
        /**
     * @brief Calls `+[NSCharacterSet characterSetWithContentsOfFile:]`.
     * @details Returns a character set read from the bitmap representation stored in the file at a given path. This method doesn't use filenames to check for the uniqueness of the character sets it creates. To prevent duplication of character sets in memory, cache them and make them available through an API that checks whether the requested set has already been loaded. To read a bitmap representation from any file, use the 'NSData' method 'dataWithContentsOfFile:options:error:' and pass the result to ''characterSetWithBitmapRepresentation:''. - Parameter fName: A path to a file containing a bitmap representation of a character set. The path name must end with the extension '.bitmap'. - Returns: A character set read from the bitmap representation stored in the file at 'fName'.
     * @param f_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CharacterSet character_set_with_contents_of_file(const std::string& f_name);
        /**
     * @brief Calls `+[NSCharacterSet characterSetWithRange:]`.
     * @details Returns a character set containing characters with Unicode values in a given range. This code excerpt creates a character set object containing the lowercase English alphabetic characters: '''objc NSRange lcEnglishRange; NSCharacterSet lcEnglishLetters; lcEnglishRange.location = (unsigned int)'a'; lcEnglishRange.length = 26; lcEnglishLetters = [NSCharacterSet characterSetWithRange:lcEnglishRange]; ''' - Parameter aRange: A range of Unicode values. 'aRange.location' is the value of the first character to return; 'aRange.location + aRange.length - 1' is the value of the last. - Returns: A character set containing characters whose Unicode values are given by 'aRange'. If 'aRange.length' is '0', returns an empty character set.
     * @param a_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CharacterSet character_set_with_range(const Range& a_range);
        /**
     * @brief Calls `-[NSCharacterSet hasMemberInPlane:]`.
     * @details Returns a Boolean value that indicates whether the receiver has at least one member in a given character plane. This method makes it easier to find the plane containing the members of the current character set. The Basic Multilingual Plane (BMP) is plane '0'. - Parameter thePlane: A character plane. - Returns: 'YES' if the receiver has at least one member in 'thePlane', otherwise 'NO'.
     * @param the_plane Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool has_member_in_plane(std::uint8_t the_plane) const;
        /**
     * @brief Calls `-[NSCharacterSet isSupersetOfSet:]`.
     * @details Returns a Boolean value that indicates whether the receiver is a superset of another given character set. - Parameter theOtherSet: A character set. - Returns: 'YES' if the receiver is a superset of 'theOtherSet', otherwise 'NO'.
     * @param the_other_set Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_superset_of_set(const CharacterSet& the_other_set) const;
        /**
     * @brief Calls `-[NSCharacterSet longCharacterIsMember:]`.
     * @details Returns a Boolean value that indicates whether a given long character is a member of the receiver. This method supports the specification of 32-bit characters. - Parameter theLongChar: A UTF32 character. - Returns: 'YES' if 'theLongChar' is in the receiver, otherwise 'NO'.
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
     * @details A character set containing the characters in Unicode General Categories L\\, M\\, and N\\. Informally, this set is the set of all characters used as basic units of alphabets, syllabaries, ideographs, and digits.
     * @return The converted Objective-C result.
     */
        static CharacterSet alphanumeric_character_set();
        /**
     * @brief Returns the `bitmapRepresentation` property of `NSCharacterSet`.
     * @details An 'NSData' object encoding the receiver in binary format. This format is suitable for saving to a file or otherwise transmitting or archiving. A raw bitmap representation of a character set is a byte array with the first 2^16 bits (that is, 8192 bytes) representing the code point range of the Basic Multilingual Plane (BMP), such that the value of the bit at position n represents the presence in the character set of the character with decimal Unicode value n. A bitmap representation may contain zero to sixteen additional 8192 byte segments for each additional Unicode plane containing a character in a character set, with each 8192 byte segment prepended with a single plane index byte. For example, a character set containing only Basic Latin (ASCII) characters, which are contained by the Basic Multilingual Plane (BMP, plane 0), has a bitmap representation with a size of 8192 bytes, whereas a character set containing both Basic Latin (ASCII) characters and emoji characters, which are contained by the Supplementary Multilingual Plane (SMP, plane 1), has a bitmap representation with a size of 16385 bytes (8192 bytes for BMP, followed by the byte '0x01' for the plane index of SMP, followed by 8192 bytes for SMP). To test for the presence of a character in the Basic Multilingual Plane (BMP) with decimal Unicode value n in a raw bitmap representation, you might do the following: '''objc unsigned char bitmapRep[8192]; if (bitmapRep[n >> 3] & (((unsigned int)1) \<\< (n & 7))) { / Character is present. } '''
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> bitmap_representation() const;
        /**
     * @brief Returns the `capitalizedLetterCharacterSet` property of `NSCharacterSet`.
     * @details A character set containing the characters in Unicode General Category Lt.
     * @return The converted Objective-C result.
     */
        static CharacterSet capitalized_letter_character_set();
        /**
     * @brief Returns the `controlCharacterSet` property of `NSCharacterSet`.
     * @details A character set containing the characters in Unicode General Category Cc and Cf. These characters include, for example, the soft hyphen ('U+00AD'), control characters to support bi-directional text, and IETF language tag characters.
     * @return The converted Objective-C result.
     */
        static CharacterSet control_character_set();
        /**
     * @brief Returns the `decimalDigitCharacterSet` property of `NSCharacterSet`.
     * @details A character set containing the characters in the category of Decimal Numbers. Informally, this set is the set of all characters used to represent the decimal values '0' through '9'. These characters include, for example, the decimal digits of the Indic scripts and Arabic.
     * @return The converted Objective-C result.
     */
        static CharacterSet decimal_digit_character_set();
        /**
     * @brief Returns the `decomposableCharacterSet` property of `NSCharacterSet`.
     * @details A character set containing individual Unicode characters that can also be represented as composed character sequences (such as for letters with accents), by the definition of "standard decomposition" in version 3.2 of the Unicode character encoding standard. These characters include compatibility characters as well as pre-composed characters. > Note: This character set doesn't currently include the Hangul characters defined in version 2.0 of the Unicode standard.
     * @return The converted Objective-C result.
     */
        static CharacterSet decomposable_character_set();
        /**
     * @brief Returns the `illegalCharacterSet` property of `NSCharacterSet`.
     * @details A character set containing values in the category of Non-Characters or that have not yet been defined in version 3.2 of the Unicode standard.
     * @return The converted Objective-C result.
     */
        static CharacterSet illegal_character_set();
        /**
     * @brief Returns the `invertedSet` property of `NSCharacterSet`.
     * @details A character set containing only characters that don't exist in the receiver. Using the inverse of an immutable character set is much more efficient than inverting a mutable character set.
     * @return The converted Objective-C result.
     */
        CharacterSet inverted_set() const;
        /**
     * @brief Returns the `letterCharacterSet` property of `NSCharacterSet`.
     * @details A character set containing the characters in Unicode General Category L\\ & M\\. Informally, this set is the set of all characters used as letters of alphabets and ideographs.
     * @return The converted Objective-C result.
     */
        static CharacterSet letter_character_set();
        /**
     * @brief Returns the `lowercaseLetterCharacterSet` property of `NSCharacterSet`.
     * @details A character set containing the characters in Unicode General Category Ll. Informally, this set is the set of all characters used as lowercase letters in alphabets that make case distinctions.
     * @return The converted Objective-C result.
     */
        static CharacterSet lowercase_letter_character_set();
        /**
     * @brief Returns the `newlineCharacterSet` property of `NSCharacterSet`.
     * @details A character set containing the newline characters ('U+000A' ~ 'U+000D', 'U+0085', 'U+2028', and 'U+2029').
     * @return The converted Objective-C result.
     */
        static CharacterSet newline_character_set();
        /**
     * @brief Returns the `nonBaseCharacterSet` property of `NSCharacterSet`.
     * @details A character set containing the characters in Unicode General Category M\\. This set is also defined as all legal Unicode characters with a non-spacing priority greater than '0'. Informally, this set is the set of all characters used as modifiers of base characters.
     * @return The converted Objective-C result.
     */
        static CharacterSet non_base_character_set();
        /**
     * @brief Returns the `punctuationCharacterSet` property of `NSCharacterSet`.
     * @details A character set containing the characters in Unicode General Category P\\. Informally, this set is the set of all non-whitespace characters used to separate linguistic units in scripts, such as periods, dashes, parentheses, and so on.
     * @return The converted Objective-C result.
     */
        static CharacterSet punctuation_character_set();
        /**
     * @brief Returns the `symbolCharacterSet` property of `NSCharacterSet`.
     * @details A character set containing the characters in Unicode General Category S\\. These characters include, for example, the dollar sign ('$') and the plus ('+') sign.
     * @return The converted Objective-C result.
     */
        static CharacterSet symbol_character_set();
        /**
     * @brief Returns the `uppercaseLetterCharacterSet` property of `NSCharacterSet`.
     * @details A character set containing the characters in Unicode General Category Lu and Lt. Informally, this set is the set of all characters used as uppercase letters in alphabets that make case distinctions.
     * @return The converted Objective-C result.
     */
        static CharacterSet uppercase_letter_character_set();
        /**
     * @brief Returns the `whitespaceAndNewlineCharacterSet` property of `NSCharacterSet`.
     * @details A character set containing characters in Unicode General Category Z\\, 'U+000A' ~ 'U+000D', and 'U+0085'.
     * @return The converted Objective-C result.
     */
        static CharacterSet whitespace_and_newline_character_set();
        /**
     * @brief Returns the `whitespaceCharacterSet` property of `NSCharacterSet`.
     * @details A character set containing the characters in Unicode General Category Zs and 'CHARACTER TABULATION' ('U+0009'). This set doesn't contain the newline or carriage return characters.
     * @return The converted Objective-C result.
     */
        static CharacterSet whitespace_character_set();
    };
}
