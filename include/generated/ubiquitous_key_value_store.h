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
     * @details An iCloud-based container of key-value pairs you share among instances of your app running on a person’s devices. Use the shared 'NSUbiquitousKeyValueStore' object to store settings, configuration information, and app-specific data in a person’s iCloud account and share it among instances of your app running on all of the person’s devices. The object stores a dictionary of key-value pairs that you provide, and propagates that data to devices with the same Apple account. Sharing data among different devices gives you a way to coordinate your app’s behavior on those devices. For example, a textbook app might save the current page number on someone’s iPhone so that the person can continue reading from the same place on their other devices. > Important: Don't store personal or sensitive information in the key-value store. The system stores the information on disk in an unencrypted format. Store personal or sensitive information in the person's Keychain instead. Each app has a single iCloud key-value store object, which you retrieve from the ''NSUbiquitousKeyValueStore/default'' class property. Use this same object throughout your app to read and write values. Don’t subclass 'NSUbiquitousKeyValueStore'. > Note: To use this object, you must distribute your app through the App Store or Mac App Store, and you must request the [iCloud key-value store entitlement](\<doc://com.apple.documentation/documentation/bundleresources/entitlements/com.apple.developer.ubiquity-kvstore-identifier>) in your Xcode project. The keys in the iCloud key-value store identify the item and its purpose in your app, and the value is a data object you use to implement the corresponding behavior in your app. Values must be property list types such as \<doc://com.apple.documentation/documentation/Swift/Int64>, \<doc://com.apple.documentation/documentation/swift/float>, \<doc://com.apple.documentation/documentation/swift/double>, \<doc://com.apple.documentation/documentation/swift/bool>, \<doc://com.apple.documentation/documentation/swift/string>, \<doc://com.apple.documentation/documentation/foundation/nsnumber>, ''Date'', \<doc://com.apple.documentation/documentation/swift/array>, or \<doc://com.apple.documentation/documentation/swift/dictionary>. To include other types of objects in the key-value store, archive them to a ''Data'' object first and store that object instead. Prefer simple types over custom objects whenever possible. When you write a new value, the iCloud key-value store saves it in memory initially and writes it to disk asynchronously later. If the device doesn’t have an active Apple account, the changes remain only on the current device. When the person signs into their account, the system forwards any changes to the iCloud server and reconciles the values there with the local ones. As you make more changes, the system keeps the local and server-based copies of the data synchronized, updating each one at appropriate times. When a value changes on one device, iCloud forwards that change to the person’s other devices. If your app is running on one of those other devices, the system posts ''NSUbiquitousKeyValueStore/didChangeExternallyNotification'' to report the change. Register for that notification to keep all instances of your app in sync. When designing the keys and values you intend to save for your app, consider the following size limitations: Your app can have no more than 1024 keys in the iCloud key-value store. The total amount of available storage space for all values is 1 megabyte. The maximum size for a single value is 1 megabyte. Therefore, if you associate 1 megabyte of data with a single key, you can’t write other keys to the store. The maximum length for each key string is 128 characters using the UTF-16 encoding. Key strings don’t count against the 1 megabyte quota for values. If you exceed any of the prescribed limits during a write operation, the operation fails and the system doesn’t add the keys or values to the store. If a key string exceeds the maximum length, the system raises an exception. If a write operation would exceed your app’s quota, the system posts ''NSUbiquitousKeyValueStore/didChangeExternallyNotification'' notification with the change reason set to ''NSUbiquitousKeyValueStoreQuotaViolationChange''.
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
         * @details Returns the array associated with the specified key.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<Object> array_for_key(const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore boolForKey:]`.
         * @details Returns the Boolean value associated with the specified key.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool bool_for_key(const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore dataForKey:]`.
         * @details Returns the data object associated with the specified key.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> data_for_key(const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore dictionaryForKey:]`.
         * @details Returns the dictionary object associated with the specified key.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> dictionary_for_key(const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore doubleForKey:]`.
         * @details Returns the 'double' value associated with the specified key.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double double_for_key(const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore longLongForKey:]`.
         * @details Returns the 64-bit integer value associated with the specified key.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t long_long_for_key(const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore objectForKey:]`.
         * @details Returns the object associated with the specified key. - Parameter aKey: The key to retrieve from the iCloud key-value store. - Returns: The object associated with 'aKey', or 'nil' if the key isn't present.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object object_for_key(const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore removeObjectForKey:]`.
         * @details Removes the value for the specified key from the iCloud key-value store.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void remove_object_for_key(const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore setArray:forKey:]`.
         * @details Sets the value of the specified key to an array of property list objects.
         * @param an_array Argument converted to the Objective-C parameter of the same role.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void set_array(const std::vector<Object>& an_array, const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore setBool:forKey:]`.
         * @details Sets the value of the specified key to a Boolean value.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void set_bool(bool value, const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore setData:forKey:]`.
         * @details Sets the value of the specified key to a data object.
         * @param a_data Argument converted to the Objective-C parameter of the same role.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void set_data(const std::vector<std::uint8_t>& a_data, const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore setDictionary:forKey:]`.
         * @details Sets the value of the specified key to a dictionary of property list objects.
         * @param a_dictionary Argument converted to the Objective-C parameter of the same role.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void set_dictionary(const std::map<std::string, Object>& a_dictionary, const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore setDouble:forKey:]`.
         * @details Sets the value of the specified key to a double value.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void set_double(double value, const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore setLongLong:forKey:]`.
         * @details Sets the value of the specified key to a 64-bit integer value.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void set_long_long(std::int64_t value, const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore setObject:forKey:]`.
         * @details Sets the value of the specified key to a property list object.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void set_object(const Object& an_object, const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore setString:forKey:]`.
         * @details Sets the value of the specified key to a string value.
         * @param a_string Argument converted to the Objective-C parameter of the same role.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         */
        void set_string(const std::string& a_string, const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore stringForKey:]`.
         * @details Returns the string associated with the specified key.
         * @param a_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string string_for_key(const std::string& a_key) const;
        /**
         * @brief Calls `-[NSUbiquitousKeyValueStore synchronize]`.
         * @details Synchronizes the in-memory keys and values with the ones stored in iCloud. - Returns: 'YES' if the in-memory and iCloud keys are synchronized, or 'NO' if an error occurred.
         * @return The converted Objective-C result.
         */
        bool synchronize() const;
        /**
         * @brief Returns the `defaultStore` property of `NSUbiquitousKeyValueStore`.
         * @details The shared iCloud key-value store object. Use this object to access the shared iCloud key-value store tied to your app and the current person.
         * @return The converted Objective-C result.
         */
        static UbiquitousKeyValueStore default_store();
        /**
         * @brief Returns the `dictionaryRepresentation` property of `NSUbiquitousKeyValueStore`.
         * @details A dictionary with all of the key-value pairs in the iCloud key-value store.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> dictionary_representation() const;
    };
}
