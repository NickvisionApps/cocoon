#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSTextAlternatives` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextAlternatives text_alternatives;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextAlternatives text_alternatives{};
     * text_alternatives.note_selected_alternative_string("text");
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextalternatives
     */
    class TextAlternatives : public Object
    {
    public:
        /// @brief Creates a new `NSTextAlternatives` instance and returns a handle to it.
        explicit TextAlternatives(const std::string& primary_string, const std::vector<std::string>& alternative_strings);
        /// @brief Creates a new `NSTextAlternatives` instance and returns a handle to it.
        explicit TextAlternatives();
        /// @brief Creates a null handle that refers to no native object.
        TextAlternatives(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextAlternatives(Adopt adopt);
        /**
     * @brief Calls `-[NSTextAlternatives noteSelectedAlternativeString:]`.
     * @param alternative_string Argument converted to the Objective-C parameter of the same role.
     */
        void note_selected_alternative_string(const std::string& alternative_string) const;
        /**
     * @brief Returns the `alternativeStrings` property of `NSTextAlternatives`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> alternative_strings() const;
        /**
     * @brief Returns the `primaryString` property of `NSTextAlternatives`.
     * @return The converted Objective-C result.
     */
        std::string primary_string() const;
    };
}
