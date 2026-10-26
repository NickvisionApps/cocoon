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
         */
        void evaluate() const;
        /**
         * @brief Calls `-[NSPositionalSpecifier setInsertionClassDescription:]`.
         * @param class_description Argument converted to the Objective-C parameter of the same role.
         */
        void set_insertion_class_description(const ScriptClassDescription& class_description) const;
        /**
         * @brief Returns the `insertionContainer` property of `NSPositionalSpecifier`.
         * @return The converted Objective-C result.
         */
        Object insertion_container() const;
        /**
         * @brief Returns the `insertionIndex` property of `NSPositionalSpecifier`.
         * @return The converted Objective-C result.
         */
        std::int64_t insertion_index() const;
        /**
         * @brief Returns the `insertionKey` property of `NSPositionalSpecifier`.
         * @return The converted Objective-C result.
         */
        std::string insertion_key() const;
        /**
         * @brief Returns the `insertionReplaces` property of `NSPositionalSpecifier`.
         * @return The converted Objective-C result.
         */
        bool insertion_replaces() const;
        /**
         * @brief Returns the `objectSpecifier` property of `NSPositionalSpecifier`.
         * @return The converted Objective-C result.
         */
        ScriptObjectSpecifier object_specifier() const;
        /**
         * @brief Returns the `position` property of `NSPositionalSpecifier`.
         * @return The converted Objective-C result.
         */
        InsertionPosition position() const;
    };
}
