#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class ScriptClassDescription;
    class ScriptObjectSpecifier;

    /**
     * @brief C++ handle for the Objective-C class `NSPositionalSpecifier` (Foundation).
     * @details A specifier for an insertion point in a container relative to another object in the container. Instances of 'NSPositionalSpecifier' specify an insertion point in a container relative to another object in the container, for example, 'before first word' or 'after paragraph 4'. The container is specified by an instance of 'NSScriptObjectSpecifier'. 'NSPositionalSpecifier' objects commonly encapsulate object specifiers used as arguments to the 'make' ('create') and 'move' commands and indicate where the created or moved object is to be inserted relative to the object represented by an object specifier. Invoking an accessor method to obtain information about an instance of 'NSPositionalSpecifier' causes the object to be evaluated if it hasn't been already. You don't normally subclass 'NSPositionalSpecifier'.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PositionalSpecifier positional_specifier;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PositionalSpecifier positional_specifier{};
     * positional_specifier.evaluate();
     * positional_specifier.set_insertion_class_description(cocoon::ScriptClassDescription());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nspositionalspecifier
     */
    class PositionalSpecifier : public Object
    {
    public:
        /// @brief Creates a new `NSPositionalSpecifier` instance and returns a handle to it.
        explicit PositionalSpecifier(InsertionPosition position, const ScriptObjectSpecifier& specifier);
        /// @brief Creates a new `NSPositionalSpecifier` instance and returns a handle to it.
        explicit PositionalSpecifier();
        /// @brief Creates a null handle that refers to no native object.
        PositionalSpecifier(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PositionalSpecifier(Adopt adopt);
        /**
     * @brief Calls `-[NSPositionalSpecifier evaluate]`.
     * @details Evaluates this positional specifier.
     */
        void evaluate() const;
        /**
     * @brief Calls `-[NSPositionalSpecifier setInsertionClassDescription:]`.
     * @details Sets the class description for the object or objects to be inserted.
     * @param class_description Argument converted to the Objective-C parameter of the same role.
     */
        void set_insertion_class_description(const ScriptClassDescription& class_description) const;
        /**
     * @brief Returns the `insertionContainer` property of `NSPositionalSpecifier`.
     * @details The container into which insertion should be done, if evaluation has been successful.
     * @return The converted Objective-C result.
     */
        Object insertion_container() const;
        /**
     * @brief Returns the `insertionIndex` property of `NSPositionalSpecifier`.
     * @details The index at which insertion should be done, if evaluation has been successful.
     * @return The converted Objective-C result.
     */
        std::int64_t insertion_index() const;
        /**
     * @brief Returns the `insertionKey` property of `NSPositionalSpecifier`.
     * @details The key for the to-many relationship for which insertion should be done, if evaluation has been successful.
     * @return The converted Objective-C result.
     */
        std::string insertion_key() const;
        /**
     * @brief Returns the `insertionReplaces` property of `NSPositionalSpecifier`.
     * @details A Boolean value that indicates whether the object to be inserted should replace the keyed, indexed object.
     * @return The converted Objective-C result.
     */
        bool insertion_replaces() const;
        /**
     * @brief Returns the `objectSpecifier` property of `NSPositionalSpecifier`.
     * @details The object specifier that identifies the reference object.
     * @return The converted Objective-C result.
     */
        ScriptObjectSpecifier object_specifier() const;
        /**
     * @brief Returns the `position` property of `NSPositionalSpecifier`.
     * @details The insertion position.
     * @return The converted Objective-C result.
     */
        InsertionPosition position() const;
    };
}
