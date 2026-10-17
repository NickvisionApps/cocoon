#pragma once

#include "generated/array_controller.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class DictionaryControllerKeyValuePair;

    /**
     * @brief C++ handle for the Objective-C class `NSDictionaryController` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ArrayController.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DictionaryController dictionary_controller;
     * dictionary_controller.set_excluded_keys({"a", "b"});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DictionaryController dictionary_controller{};
     * dictionary_controller.set_excluded_keys({"a", "b"});
     * auto excluded_keys = dictionary_controller.excluded_keys();
     * dictionary_controller.set_included_keys({"a", "b"});
     * auto included_keys = dictionary_controller.included_keys();
     * dictionary_controller.set_initial_key("text");
     * auto initial_key = dictionary_controller.initial_key();
     * dictionary_controller.new_object();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsdictionarycontroller
     */
    class DictionaryController : public ArrayController
    {
    public:
        /// @brief Creates a new `NSDictionaryController` instance and returns a handle to it.
        explicit DictionaryController();
        /// @brief Creates a null handle that refers to no native object.
        DictionaryController(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DictionaryController(Adopt adopt);
        using ObjectController::new_object;
        /**
     * @brief Calls `-[NSDictionaryController newObject]`.
     * @return The converted Objective-C result.
     */
        DictionaryControllerKeyValuePair new_object() const;
        /**
     * @brief Returns the `excludedKeys` property of `NSDictionaryController`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> excluded_keys() const;
        /**
     * @brief Sets the `excludedKeys` property of `NSDictionaryController`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_excluded_keys(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `includedKeys` property of `NSDictionaryController`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> included_keys() const;
        /**
     * @brief Sets the `includedKeys` property of `NSDictionaryController`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_included_keys(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `initialKey` property of `NSDictionaryController`.
     * @return The converted Objective-C result.
     */
        std::string initial_key() const;
        /**
     * @brief Sets the `initialKey` property of `NSDictionaryController`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_initial_key(const std::string& value) const;
        /**
     * @brief Returns the `initialValue` property of `NSDictionaryController`.
     * @return The converted Objective-C result.
     */
        Object initial_value() const;
        /**
     * @brief Sets the `initialValue` property of `NSDictionaryController`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_initial_value(const Object& value) const;
        /**
     * @brief Returns the `localizedKeyDictionary` property of `NSDictionaryController`.
     * @return The converted Objective-C result.
     */
        std::map<std::string, std::string> localized_key_dictionary() const;
        /**
     * @brief Sets the `localizedKeyDictionary` property of `NSDictionaryController`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_localized_key_dictionary(const std::map<std::string, std::string>& value) const;
        /**
     * @brief Returns the `localizedKeyTable` property of `NSDictionaryController`.
     * @return The converted Objective-C result.
     */
        std::string localized_key_table() const;
        /**
     * @brief Sets the `localizedKeyTable` property of `NSDictionaryController`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_localized_key_table(const std::string& value) const;
    };
}
