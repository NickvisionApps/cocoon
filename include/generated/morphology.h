#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSMorphology` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Morphology morphology;
     * morphology.set_definiteness(cocoon::GrammaticalDefiniteness::NotSet);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Morphology morphology{};
     * morphology.set_definiteness(cocoon::GrammaticalDefiniteness::NotSet);
     * auto definiteness = morphology.definiteness();
     * morphology.set_determination(cocoon::GrammaticalDetermination::NotSet);
     * auto determination = morphology.determination();
     * morphology.set_grammatical_case(cocoon::GrammaticalCase::NotSet);
     * auto grammatical_case = morphology.grammatical_case();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmorphology
     */
    class Morphology : public Object
    {
    public:
        /// @brief Creates a new `NSMorphology` instance and returns a handle to it.
        explicit Morphology();
        /// @brief Creates a null handle that refers to no native object.
        Morphology(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Morphology(Adopt adopt);
        /**
     * @brief Returns the `definiteness` property of `NSMorphology`.
     * @return The converted Objective-C result.
     */
        GrammaticalDefiniteness definiteness() const;
        /**
     * @brief Sets the `definiteness` property of `NSMorphology`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_definiteness(GrammaticalDefiniteness value) const;
        /**
     * @brief Returns the `determination` property of `NSMorphology`.
     * @return The converted Objective-C result.
     */
        GrammaticalDetermination determination() const;
        /**
     * @brief Sets the `determination` property of `NSMorphology`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_determination(GrammaticalDetermination value) const;
        /**
     * @brief Returns the `grammaticalCase` property of `NSMorphology`.
     * @return The converted Objective-C result.
     */
        GrammaticalCase grammatical_case() const;
        /**
     * @brief Sets the `grammaticalCase` property of `NSMorphology`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_grammatical_case(GrammaticalCase value) const;
        /**
     * @brief Returns the `grammaticalGender` property of `NSMorphology`.
     * @return The converted Objective-C result.
     */
        GrammaticalGender grammatical_gender() const;
        /**
     * @brief Sets the `grammaticalGender` property of `NSMorphology`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_grammatical_gender(GrammaticalGender value) const;
        /**
     * @brief Returns the `grammaticalPerson` property of `NSMorphology`.
     * @return The converted Objective-C result.
     */
        GrammaticalPerson grammatical_person() const;
        /**
     * @brief Sets the `grammaticalPerson` property of `NSMorphology`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_grammatical_person(GrammaticalPerson value) const;
        /**
     * @brief Returns the `number` property of `NSMorphology`.
     * @return The converted Objective-C result.
     */
        GrammaticalNumber number() const;
        /**
     * @brief Sets the `number` property of `NSMorphology`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_number(GrammaticalNumber value) const;
        /**
     * @brief Returns the `partOfSpeech` property of `NSMorphology`.
     * @return The converted Objective-C result.
     */
        GrammaticalPartOfSpeech part_of_speech() const;
        /**
     * @brief Sets the `partOfSpeech` property of `NSMorphology`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_part_of_speech(GrammaticalPartOfSpeech value) const;
        /**
     * @brief Returns the `pronounType` property of `NSMorphology`.
     * @return The converted Objective-C result.
     */
        GrammaticalPronounType pronoun_type() const;
        /**
     * @brief Sets the `pronounType` property of `NSMorphology`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_pronoun_type(GrammaticalPronounType value) const;
        /**
     * @brief Returns the `unspecified` property of `NSMorphology`.
     * @return The converted Objective-C result.
     */
        bool is_unspecified() const;
        /**
     * @brief Returns the `userMorphology` property of `NSMorphology`.
     * @return The converted Objective-C result.
     */
        static Morphology user_morphology();
    };
}
