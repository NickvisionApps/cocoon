#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSMorphologyCustomPronoun` (Foundation).
     * @details A custom pronoun behavior for use in a specific language.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MorphologyCustomPronoun morphology_custom_pronoun;
     * morphology_custom_pronoun.set_object_form("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MorphologyCustomPronoun morphology_custom_pronoun{};
     * morphology_custom_pronoun.set_object_form("text");
     * auto object_form = morphology_custom_pronoun.object_form();
     * morphology_custom_pronoun.set_possessive_adjective_form("text");
     * auto possessive_adjective_form = morphology_custom_pronoun.possessive_adjective_form();
     * morphology_custom_pronoun.set_possessive_form("text");
     * auto possessive_form = morphology_custom_pronoun.possessive_form();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmorphologycustompronoun
     */
    class MorphologyCustomPronoun : public Object
    {
    public:
        /// @brief Creates a new `NSMorphologyCustomPronoun` instance and returns a handle to it.
        explicit MorphologyCustomPronoun();
        /// @brief Creates a null handle that refers to no native object.
        MorphologyCustomPronoun(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MorphologyCustomPronoun(Adopt adopt);
        /**
     * @brief Calls `+[NSMorphologyCustomPronoun isSupportedForLanguage:]`.
     * @details Returns a Boolean value that indicates whether custom pronouns are supported for the specified language.
     * @param language Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool is_supported_for_language(const std::string& language);
        /**
     * @brief Calls `+[NSMorphologyCustomPronoun requiredKeysForLanguage:]`.
     * @details Returns the list of pronoun form keys required for the specified language.
     * @param language Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> required_keys_for_language(const std::string& language);
        /**
     * @brief Returns the `objectForm` property of `NSMorphologyCustomPronoun`.
     * @details The object pronoun form.
     * @return The converted Objective-C result.
     */
        std::string object_form() const;
        /**
     * @brief Sets the `objectForm` property of `NSMorphologyCustomPronoun`.
     * @details The object pronoun form.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_object_form(const std::string& value) const;
        /**
     * @brief Returns the `possessiveAdjectiveForm` property of `NSMorphologyCustomPronoun`.
     * @details The possessive adjective form.
     * @return The converted Objective-C result.
     */
        std::string possessive_adjective_form() const;
        /**
     * @brief Sets the `possessiveAdjectiveForm` property of `NSMorphologyCustomPronoun`.
     * @details The possessive adjective form.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_possessive_adjective_form(const std::string& value) const;
        /**
     * @brief Returns the `possessiveForm` property of `NSMorphologyCustomPronoun`.
     * @details The possessive pronoun form.
     * @return The converted Objective-C result.
     */
        std::string possessive_form() const;
        /**
     * @brief Sets the `possessiveForm` property of `NSMorphologyCustomPronoun`.
     * @details The possessive pronoun form.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_possessive_form(const std::string& value) const;
        /**
     * @brief Returns the `reflexiveForm` property of `NSMorphologyCustomPronoun`.
     * @details The reflexive pronoun form.
     * @return The converted Objective-C result.
     */
        std::string reflexive_form() const;
        /**
     * @brief Sets the `reflexiveForm` property of `NSMorphologyCustomPronoun`.
     * @details The reflexive pronoun form.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_reflexive_form(const std::string& value) const;
        /**
     * @brief Returns the `subjectForm` property of `NSMorphologyCustomPronoun`.
     * @details The subject pronoun form.
     * @return The converted Objective-C result.
     */
        std::string subject_form() const;
        /**
     * @brief Sets the `subjectForm` property of `NSMorphologyCustomPronoun`.
     * @details The subject pronoun form.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_subject_form(const std::string& value) const;
    };
}
