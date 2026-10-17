#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSDictionaryControllerKeyValuePair` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DictionaryControllerKeyValuePair dictionary_controller_key_value_pair(nullptr);  // null handle; instances normally come from other API calls
     * dictionary_controller_key_value_pair.set_key("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DictionaryControllerKeyValuePair dictionary_controller_key_value_pair(nullptr);
     * dictionary_controller_key_value_pair.set_key("text");
     * auto key = dictionary_controller_key_value_pair.key();
     * dictionary_controller_key_value_pair.set_localized_key("text");
     * auto localized_key = dictionary_controller_key_value_pair.localized_key();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsdictionarycontrollerkeyvaluepair
     */
    class DictionaryControllerKeyValuePair : public Object
    {
    public:
        DictionaryControllerKeyValuePair();
        /// @brief Creates a null handle that refers to no native object.
        DictionaryControllerKeyValuePair(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DictionaryControllerKeyValuePair(Adopt adopt);
        /**
     * @brief Returns the `explicitlyIncluded` property of `NSDictionaryControllerKeyValuePair`.
     * @return The converted Objective-C result.
     */
        bool is_explicitly_included() const;
        /**
     * @brief Returns the `key` property of `NSDictionaryControllerKeyValuePair`.
     * @return The converted Objective-C result.
     */
        std::string key() const;
        /**
     * @brief Sets the `key` property of `NSDictionaryControllerKeyValuePair`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_key(const std::string& value) const;
        /**
     * @brief Returns the `localizedKey` property of `NSDictionaryControllerKeyValuePair`.
     * @return The converted Objective-C result.
     */
        std::string localized_key() const;
        /**
     * @brief Sets the `localizedKey` property of `NSDictionaryControllerKeyValuePair`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_localized_key(const std::string& value) const;
        /**
     * @brief Returns the `value` property of `NSDictionaryControllerKeyValuePair`.
     * @return The converted Objective-C result.
     */
        Object value() const;
        /**
     * @brief Sets the `value` property of `NSDictionaryControllerKeyValuePair`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_value(const Object& value) const;
    };
}
