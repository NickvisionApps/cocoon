#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/script_object_specifier.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class ScriptClassDescription;
    class ScriptObjectSpecifier;
    class ScriptWhoseTest;

    /**
     * @brief C++ handle for the Objective-C class `NSWhoseSpecifier` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScriptObjectSpecifier.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::WhoseSpecifier whose_specifier;
     * whose_specifier.set_end_subelement_identifier(cocoon::WhoseSubelementIdentifier::IndexSubelement);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::WhoseSpecifier whose_specifier{};
     * whose_specifier.set_end_subelement_identifier(cocoon::WhoseSubelementIdentifier::IndexSubelement);
     * auto end_subelement_identifier = whose_specifier.end_subelement_identifier();
     * whose_specifier.set_end_subelement_index(1);
     * auto end_subelement_index = whose_specifier.end_subelement_index();
     * whose_specifier.set_start_subelement_identifier(cocoon::WhoseSubelementIdentifier::IndexSubelement);
     * auto start_subelement_identifier = whose_specifier.start_subelement_identifier();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nswhosespecifier
     */
    class WhoseSpecifier : public ScriptObjectSpecifier
    {
    public:
        /// @brief Creates a new `NSWhoseSpecifier` instance and returns a handle to it.
        explicit WhoseSpecifier(const ScriptClassDescription& class_desc, const ScriptObjectSpecifier& container, const std::string& property, const ScriptWhoseTest& test);
        /// @brief Creates a new `NSWhoseSpecifier` instance and returns a handle to it.
        explicit WhoseSpecifier();
        /// @brief Creates a null handle that refers to no native object.
        WhoseSpecifier(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit WhoseSpecifier(Adopt adopt);
        /**
         * @brief Returns the `endSubelementIdentifier` property of `NSWhoseSpecifier`.
         * @return The converted Objective-C result.
         */
        WhoseSubelementIdentifier end_subelement_identifier() const;
        /**
         * @brief Sets the `endSubelementIdentifier` property of `NSWhoseSpecifier`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_end_subelement_identifier(WhoseSubelementIdentifier value) const;
        /**
         * @brief Returns the `endSubelementIndex` property of `NSWhoseSpecifier`.
         * @return The converted Objective-C result.
         */
        std::int64_t end_subelement_index() const;
        /**
         * @brief Sets the `endSubelementIndex` property of `NSWhoseSpecifier`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_end_subelement_index(std::int64_t value) const;
        /**
         * @brief Returns the `startSubelementIdentifier` property of `NSWhoseSpecifier`.
         * @return The converted Objective-C result.
         */
        WhoseSubelementIdentifier start_subelement_identifier() const;
        /**
         * @brief Sets the `startSubelementIdentifier` property of `NSWhoseSpecifier`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_start_subelement_identifier(WhoseSubelementIdentifier value) const;
        /**
         * @brief Returns the `startSubelementIndex` property of `NSWhoseSpecifier`.
         * @return The converted Objective-C result.
         */
        std::int64_t start_subelement_index() const;
        /**
         * @brief Sets the `startSubelementIndex` property of `NSWhoseSpecifier`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_start_subelement_index(std::int64_t value) const;
        /**
         * @brief Returns the `test` property of `NSWhoseSpecifier`.
         * @return The converted Objective-C result.
         */
        ScriptWhoseTest test() const;
        /**
         * @brief Sets the `test` property of `NSWhoseSpecifier`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_test(const ScriptWhoseTest& value) const;
    };
}
