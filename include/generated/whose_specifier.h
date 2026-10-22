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
     * @details A specifier that indicates every object in a collection matching a condition. 'NSWhoseSpecifier' specifies every object in a collection (or every element in a container) that matches the condition defined by a single Boolean expression or multiple Boolean expressions connected by logical operators. 'NSWhoseSpecifier' is unique among object specifiers in that its top-level container is typically not the application object but an evaluated object specifier involved in the tested-for condition. An 'NSWhoseSpecifier' object encapsulates a "test" object for defining this condition. A test object is instantiated from a subclass of the abstract ''NSScriptWhoseTest'' class, whose one declared method is ''NSScriptWhoseTest/isTrue()''. See "Boolean Expressions and Logical Operations" in ''NSScriptObjectSpecifier'' and the descriptions in NSComparisonMethods and NSScriptingComparisonMethods for more information. The set of elements specified by an 'NSWhoseSpecifier' object can be a subset of those that pass the 'NSWhoseSpecifier' object's test. This subset is specified by the various sub-element properties of the 'NSWhoseSpecifier' object . Consider as an example the specifier 'paragraphs where color of third word is blue'. This would be represented by an 'NSWhoseSpecifier' object that uses a test specifier and another object specifier to identify a subset of the objects with the specified property. That is, the specifier's property is 'paragraphs'; the test specifier is an index specifier with property 'words' and 'index 3'; and the qualifier is a key value qualifier for key 'color' and value '[NSColor blueColor]'. The test object specifier ('word at index 3') is evaluated for each object (paragraph) using that object as the container; the resulting objects (if any) are tested with the qualifier ('color blue'). 'NSWhoseSpecifier' is part of Cocoa's built-in script handling. You don't normally subclass it.
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
         * @details The identifier for the end subelement.
         * @return The converted Objective-C result.
         */
        WhoseSubelementIdentifier end_subelement_identifier() const;
        /**
         * @brief Sets the `endSubelementIdentifier` property of `NSWhoseSpecifier`.
         * @details The identifier for the end subelement.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_end_subelement_identifier(WhoseSubelementIdentifier value) const;
        /**
         * @brief Returns the `endSubelementIndex` property of `NSWhoseSpecifier`.
         * @details The index of the end subelement. Only used if 'endSubelementIdentifier' is 'NSIndexSubelement'.
         * @return The converted Objective-C result.
         */
        std::int64_t end_subelement_index() const;
        /**
         * @brief Sets the `endSubelementIndex` property of `NSWhoseSpecifier`.
         * @details The index of the end subelement. Only used if 'endSubelementIdentifier' is 'NSIndexSubelement'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_end_subelement_index(std::int64_t value) const;
        /**
         * @brief Returns the `startSubelementIdentifier` property of `NSWhoseSpecifier`.
         * @details The identifier for the start subelement.
         * @return The converted Objective-C result.
         */
        WhoseSubelementIdentifier start_subelement_identifier() const;
        /**
         * @brief Sets the `startSubelementIdentifier` property of `NSWhoseSpecifier`.
         * @details The identifier for the start subelement.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_start_subelement_identifier(WhoseSubelementIdentifier value) const;
        /**
         * @brief Returns the `startSubelementIndex` property of `NSWhoseSpecifier`.
         * @details The index of the start subelement. Only used if 'startSubelementIdentifier' is 'NSIndexSubelement'.
         * @return The converted Objective-C result.
         */
        std::int64_t start_subelement_index() const;
        /**
         * @brief Sets the `startSubelementIndex` property of `NSWhoseSpecifier`.
         * @details The index of the start subelement. Only used if 'startSubelementIdentifier' is 'NSIndexSubelement'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_start_subelement_index(std::int64_t value) const;
        /**
         * @brief Returns the `test` property of `NSWhoseSpecifier`.
         * @details The test used to qualify the objects.
         * @return The converted Objective-C result.
         */
        ScriptWhoseTest test() const;
        /**
         * @brief Sets the `test` property of `NSWhoseSpecifier`.
         * @details The test used to qualify the objects.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_test(const ScriptWhoseTest& value) const;
    };
}
