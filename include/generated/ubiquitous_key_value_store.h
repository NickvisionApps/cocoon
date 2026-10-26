#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUbiquitousKeyValueStore` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UbiquitousKeyValueStore ubiquitous_key_value_store;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::UbiquitousKeyValueStore ubiquitous_key_value_store{};
     * ubiquitous_key_value_store.array_for_key("text");
     * ubiquitous_key_value_store.bool_for_key("text");
     * ubiquitous_key_value_store.data_for_key("text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsubiquitouskeyvaluestore
     */
    class UbiquitousKeyValueStore : public Object
    {
    public:
        /// @brief Creates a new `NSUbiquitousKeyValueStore` instance and returns a handle to it.
        explicit UbiquitousKeyValueStore();
        /// @brief Creates a null handle that refers to no native object.
        UbiquitousKeyValueStore(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UbiquitousKeyValueStore(Adopt adopt);
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore arrayForKey:]`.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<Object> array_for_key(const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore boolForKey:]`.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool bool_for_key(const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore dataForKey:]`.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> data_for_key(const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore dictionaryForKey:]`.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> dictionary_for_key(const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore doubleForKey:]`.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double double_for_key(const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore longLongForKey:]`.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t long_long_for_key(const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore objectForKey:]`.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object object_for_key(const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore removeObjectForKey:]`.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void remove_object_for_key(const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore setArray:forKey:]`.
         * @param an_array Argument converted to the Objective-C parameter of the same role.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void set_array(const std::vector<Object>& an_array, const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore setBool:forKey:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void set_bool(bool value, const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore setData:forKey:]`.
         * @param a_data Argument converted to the Objective-C parameter of the same role.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void set_data(const std::vector<std::uint8_t>& a_data, const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore setDictionary:forKey:]`.
         * @param a_dictionary Argument converted to the Objective-C parameter of the same role.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void set_dictionary(const std::map<std::string, Object>& a_dictionary, const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore setDouble:forKey:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void set_double(double value, const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore setLongLong:forKey:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void set_long_long(std::int64_t value, const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore setObject:forKey:]`.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void set_object(const Object& an_object, const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore setString:forKey:]`.
         * @param a_string Argument converted to the Objective-C parameter of the same role.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void set_string(const std::string& a_string, const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore stringForKey:]`.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string string_for_key(const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore synchronize]`.
         * @return The converted Objective-C result.
         */
        bool synchronize() const;
        /**
         * @brief Returns the `defaultStore` property of `NSUbiquitousKeyValueStore`.
         * @return The converted Objective-C result.
         */
        static UbiquitousKeyValueStore default_store();
        /**
         * @brief Returns the `dictionaryRepresentation` property of `NSUbiquitousKeyValueStore`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> dictionary_representation() const;
    };
}
