#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSPersonNameComponents` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PersonNameComponents person_name_components;
     * person_name_components.set_family_name("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PersonNameComponents person_name_components{};
     * person_name_components.set_family_name("text");
     * auto family_name = person_name_components.family_name();
     * person_name_components.set_given_name("text");
     * auto given_name = person_name_components.given_name();
     * person_name_components.set_middle_name("text");
     * auto middle_name = person_name_components.middle_name();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nspersonnamecomponents
     */
    class PersonNameComponents : public Object
    {
    public:
        /// @brief Creates a new `NSPersonNameComponents` instance and returns a handle to it.
        explicit PersonNameComponents();
        /// @brief Creates a null handle that refers to no native object.
        PersonNameComponents(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PersonNameComponents(Adopt adopt);
        /**
         * @brief Returns the `familyName` property of `NSPersonNameComponents`.
         * @details Name passed from one generation to another to indicate lineage, e.g. Appleseed
         * @return The converted Objective-C result.
         */
        std::string family_name() const;
        /**
         * @brief Sets the `familyName` property of `NSPersonNameComponents`.
         * @details Name passed from one generation to another to indicate lineage, e.g. Appleseed
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_family_name(const std::string& value) const;
        /**
         * @brief Returns the `givenName` property of `NSPersonNameComponents`.
         * @details Name bestowed upon an individual by one's parents, e.g. Johnathan
         * @return The converted Objective-C result.
         */
        std::string given_name() const;
        /**
         * @brief Sets the `givenName` property of `NSPersonNameComponents`.
         * @details Name bestowed upon an individual by one's parents, e.g. Johnathan
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_given_name(const std::string& value) const;
        /**
         * @brief Returns the `middleName` property of `NSPersonNameComponents`.
         * @details Secondary given name chosen to differentiate those with the same first name, e.g. Maple
         * @return The converted Objective-C result.
         */
        std::string middle_name() const;
        /**
         * @brief Sets the `middleName` property of `NSPersonNameComponents`.
         * @details Secondary given name chosen to differentiate those with the same first name, e.g. Maple
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_middle_name(const std::string& value) const;
        /**
         * @brief Returns the `namePrefix` property of `NSPersonNameComponents`.
         * @details Pre-nominal letters denoting title, salutation, or honorific, e.g. Dr., Mr.
         * @return The converted Objective-C result.
         */
        std::string name_prefix() const;
        /**
         * @brief Sets the `namePrefix` property of `NSPersonNameComponents`.
         * @details Pre-nominal letters denoting title, salutation, or honorific, e.g. Dr., Mr.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_name_prefix(const std::string& value) const;
        /**
         * @brief Returns the `nameSuffix` property of `NSPersonNameComponents`.
         * @details Post-nominal letters denoting degree, accreditation, or other honor, e.g. Esq., Jr., Ph.D.
         * @return The converted Objective-C result.
         */
        std::string name_suffix() const;
        /**
         * @brief Sets the `nameSuffix` property of `NSPersonNameComponents`.
         * @details Post-nominal letters denoting degree, accreditation, or other honor, e.g. Esq., Jr., Ph.D.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_name_suffix(const std::string& value) const;
        /**
         * @brief Returns the `nickname` property of `NSPersonNameComponents`.
         * @details Name substituted for the purposes of familiarity, e.g. "Johnny"
         * @return The converted Objective-C result.
         */
        std::string nickname() const;
        /**
         * @brief Sets the `nickname` property of `NSPersonNameComponents`.
         * @details Name substituted for the purposes of familiarity, e.g. "Johnny"
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_nickname(const std::string& value) const;
        /**
         * @brief Returns the `phoneticRepresentation` property of `NSPersonNameComponents`.
         * @details Each element of the phoneticRepresentation should correspond to an element of the original PersonNameComponents instance. The phoneticRepresentation of the phoneticRepresentation object itself will be ignored. nil by default, must be instantiated.
         * @return The converted Objective-C result.
         */
        PersonNameComponents phonetic_representation() const;
        /**
         * @brief Sets the `phoneticRepresentation` property of `NSPersonNameComponents`.
         * @details Each element of the phoneticRepresentation should correspond to an element of the original PersonNameComponents instance. The phoneticRepresentation of the phoneticRepresentation object itself will be ignored. nil by default, must be instantiated.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_phonetic_representation(const PersonNameComponents& value) const;
    };
}
