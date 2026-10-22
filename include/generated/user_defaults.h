#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSUserDefaults` (Foundation).
     * @details An interface to the user's defaults database, which stores system-wide and app-specific settings. A 'UserDefaults' object provides access to the defaults system, which is a persistent store for app-specific and system-wide settings. You use this system to store nonsensitive information, such as app-specific configuration details. The system also stores configuration details that apply to all apps, such as the current language settings for the device. In your code, you check values from this system and use them to dynamically alter your app's appearance or behavior. The term defaults refers to the fact that the stored data determines the default startup state and behavior. > Important: Don't store personal or sensitive information as settings. The defaults system stores information on disk in an unencrypted format. Store personal or sensitive information in the person's Keychain instead. To access the defaults system, obtain a 'UserDefaults' object and call its methods to read and write values. The ''standard'' object is a shared object you use to read and write your app's standard settings. You can also create unique 'UserDefaults' objects to manage specific sets of settings. For example, you can create a 'UserDefaults' object that reads and writes settings your app shares with an app extension. Don't subclass 'UserDefaults'. Each item you store in a defaults object consists of a key-value pair, where each key is a string that you use to locate the item and each value is a data object. The defaults database supports the same value types found in property list files, including types like 'Int', 'Float', 'Double', 'Bool', 'String', ''URL'', 'NSNumber', ''Date'', 'Array', and 'Dictionary'. To include other types of objects in the defaults database, archive them to a ''Data'' object first and store that object instead. Prefer simple types over custom objects whenever possible. With the exception of managed devices in educational institutions, the system stores defaults locally on the current device. When you write values to a 'UserDefaults' object, the object updates its in-memory version of that information right away, and writes the value to disk asynchronously. When someone backs up their device, the system includes any persistent defaults databases in the backup data. Because the data is device-specific, you don't use the defaults system to share data between devices. To share data between someone's devices, use the ''NSUbiquitousKeyValueStore'' instead. > Warning: Don't access the files of the defaults database directly from the file system. Modifying one of the underlying files directly may cause data loss, a delay in changes being available, or an app crash. In macOS, use the 'defaults' command-line utility to safely view or modify the defaults database outside of your app. While your app is running, the defaults system generates notifications to let you know when values change. To observe changes to individual settings, add a key-value observer to your 'UserDefaults' object, using key names to build the path to the setting you want. To observe changes for all settings, register for a ''didChangeNotification'' with your 'UserDefaults' object. The 'UserDefaults' type is thread-safe, and you can use the same object in multiple threads or tasks simultaneously. \#\#\# Domains and Settings Search Paths To integrate settings from different sources, the defaults system organizes them into domains. An app defines its own custom settings, but the system defines settings that apply to all apps. Similarly, you might choose to override a specific setting temporarily to test one of your app's features. The defaults system provides domains for each of these cases along with several others. When you request the value of a setting, the 'UserDefaults' object searches its domains in a specific order until it finds the value you want. The following table lists the key domains that the defaults system supports and their search order. Some domains might not be present for all apps. For example, the managed domain is present only on administrator-managed devices. | Domain | Type | Description | |----------|----------|----------| | Managed | persistent | This domain contains settings that an administrator provided for a managed device. | | Argument | volatile | This domain contains the settings you specified when launching your app from the command-line or Xcode. These keys represent temporary overrides of settings, and the system discards them after the app quits. | | Educational managed | persistent | For managed devices in an educational institution, this domain contains any settings saved to the iCloud key-value store for that institution. | | App | persistent | This domain contains the settings your app saves, either programmatically or using its settings UI. | | Suite | persistent | This domain contains custom settings from an app group or other app you specify at runtime. This domain is absent by default, but you can add a suite using the ''addSuite(named:)'' method. | | Global | persistent | This domain contains keys present for all apps on the system. The system provides the keys for this domain, and apps can't write to it. | | Registration | volatile | This domain contains system-provided default values and the default values you register for your app at launch time. Registering a set of default values prevents your code from receiving 'nil' values when requesting a setting. The system discards these values when your app quits, so you must register them each time your app launches. | The system stores data for most persistent domains on the current device, and doesn't share that data with other devices. To share settings among all of a person's devices, save them using an ''NSUbiquitousKeyValueStore'' object instead. \#\#\# Settings in Managed Environments If your app supports managed environments, an administrator might configure any managed devices with a default set of settings. Apps can't write to managed domains, so if your app encounters a managed setting, disable or hide any controls that someone might use to change that setting's value. To determine if a setting is managed, call the ''objectIsForced(forKey:)'' or ''objectIsForced(forKey:inDomain:)'' method of your 'UserDefaults' object. \#\#\# Sandbox Considerations A sandboxed app cannot access or modify the settings of another app or process, with the following exceptions: - An app can modify settings for one of its app extensions. - An app can modify settings for an app group to which it belongs.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UserDefaults user_defaults;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::UserDefaults user_defaults{};
     * user_defaults.url_for_key("text");
     * user_defaults.add_suite_named("text");
     * user_defaults.array_for_key("text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsuserdefaults
     */
    class UserDefaults : public Object
    {
    public:
        /// @brief Creates a new `NSUserDefaults` instance and returns a handle to it.
        explicit UserDefaults(const std::string& suitename);
        /// @brief Creates a new `NSUserDefaults` instance and returns a handle to it.
        explicit UserDefaults();
        /// @brief Creates a null handle that refers to no native object.
        UserDefaults(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UserDefaults(Adopt adopt);
        /**
         * @brief Calls `-[NSUserDefaults URLForKey:]`.
         * @details Returns the URL associated with the specified key. - Parameter defaultName: A key in the current user's defaults database. - Returns: The URL associated with the specified key, or 'nil' if the key doesn't exist or its value can't be converted to a URL. If the value is an 'NSString' path, then it will construct a file URL to that path. If the value is an archived URL from ''UserDefaults/set(:forKey:)-2bqjt'' it will be unarchived.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        URL url_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults addSuiteNamed:]`.
         * @details Inserts settings for the specified domain into the search list of the current object. - Parameter suiteName: The domain name to insert. This domain is inserted after the application domain. Passing ''NSGlobalDomain'' or the current application's bundle identifier is unsupported. The additional search lists are searched after the current domain, but before global defaults.
         * @param suite_name Argument converted to the Objective-C parameter of the same role.
         */
        void add_suite_named(const std::string& suite_name) const;
        /**
         * @brief Calls `-[NSUserDefaults arrayForKey:]`.
         * @details Returns the array associated with the specified key. - Parameter defaultName: A key in the current user's defaults database. - Returns: The array associated with the specified key, or 'nil' if the key doesn't exist or its value is not an array. The returned array and its contents are immutable, even if the values you originally set were mutable.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<Object> array_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults boolForKey:]`.
         * @details Returns the Boolean value associated with the specified key. - Parameter defaultName: A key in the current user's defaults database. - Returns: The Boolean value associated with the specified key. If the key doesn't exist, this method returns 'NO'. If the value is an 'NSNumber', 'NO' will be returned if the value is '0', 'YES' otherwise. If the value is an 'NSString', values of '"YES"' or '"1"' will return 'YES', and values of '"NO"', '"0"', or any other string will return 'NO'. If the value is absent or can't be converted to a 'BOOL', 'NO' will be returned.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool bool_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults dataForKey:]`.
         * @details Returns the data object associated with the specified key. - Parameter defaultName: A key in the current user's defaults database. - Returns: The data object associated with the specified key, or 'nil' if the key doesn't exist or its value is not a data object. The returned data object is immutable, even if the value you originally set was mutable.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> data_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults dictionaryForKey:]`.
         * @details Returns the dictionary object associated with the specified key. - Parameter defaultName: A key in the current user's defaults database. - Returns: The dictionary object associated with the specified key, or 'nil' if the key doesn't exist or its value is not a dictionary. The returned dictionary and its contents are immutable, even if the values you originally set were mutable.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> dictionary_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults dictionaryRepresentation]`.
         * @details Returns a dictionary with the union of all key-value pairs found from all domains. - Returns: A dictionary that contains the keys and their corresponding values from each of the search list's domains. For duplicate keys, the object from the domain that is closest to the front of the search list is used.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> dictionary_representation() const;
        /**
         * @brief Calls `-[NSUserDefaults doubleForKey:]`.
         * @details Returns the double value associated with the specified key. - Parameter defaultName: A key in the current user's defaults database. - Returns: The double value associated with the specified key. If the key doesn't exist, this method returns '0'. If the value is an 'NSNumber', the result of '-doubleValue' will be returned. If the value is an 'NSString', it will be converted if possible. Boolean values will not be converted.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double double_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults floatForKey:]`.
         * @details Returns the floating-point value associated with the specified key. - Parameter defaultName: A key in the current user's defaults database. - Returns: The float value associated with the specified key. If the key doesn't exist, this method returns '0'. If the value is an 'NSNumber', the result of '-floatValue' will be returned. If the value is an 'NSString', it will be converted if possible. Boolean values will not be converted.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        float float_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults integerForKey:]`.
         * @details Returns the integer value associated with the specified key. - Parameter defaultName: A key in the current user's defaults database. - Returns: The integer value associated with the specified key. If the key doesn't exist, this method returns '0'. If the value is an 'NSNumber', the result of '-integerValue' will be returned. If the value is an 'NSString', it will be converted to 'NSInteger' if possible. If the value is a Boolean, it will be converted to either '1' for 'YES' or '0' for 'NO'. If the value is absent or can't be converted to an integer, '0' will be returned.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t integer_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults objectForKey:]`.
         * @details Returns the object associated with the specified key. - Parameter defaultName: A key in the current user's defaults database. - Returns: The object associated with the specified key, or 'nil' if the key was not found. This method searches the receiver's search list for a default with the key 'defaultName' and returns it. If another process has changed defaults in the search list, NSUserDefaults will automatically update to the latest values. If the key in question has been marked as ubiquitous via a Defaults Configuration File, the latest value may not be immediately available, and the registered value will be returned instead. The returned object is immutable, even if the value you originally set was mutable.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object object_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults objectIsForcedForKey:]`.
         * @details Returns a Boolean value that indicates whether an administrator provided the value for the specified key. - Parameter key: The key whose status you want to check. - Returns: 'YES' if the value for 'key' is managed by an administrator; otherwise, 'NO'. A key is managed when its value has been set by a configuration profile or managed by a mobile device management (MDM) server. For keys that are managed, you should disable any user interface that allows the user to modify the value of that key.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool object_is_forced_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSUserDefaults objectIsForcedForKey:inDomain:]`.
         * @details Returns a Boolean value that indicates whether an administrator provided the value for the key in the specified domain. - Parameters: - key: The key whose status you want to check. - domain: The domain of the key. - Returns: 'YES' if the value for 'key' in 'domain' is managed by an administrator; otherwise, 'NO'. For keys that are managed, you should disable any user interface that allows the user to modify the value of that key.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @param domain Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool object_is_forced_for_key(const std::string& key, const std::string& domain) const;
        /**
         * @brief Calls `-[NSUserDefaults persistentDomainForName:]`.
         * @details Retrieves the settings from the specified persistent domain. - Parameter domainName: The domain name. - Returns: A dictionary containing the keys and values in the specified persistent domain, or 'nil' if the domain doesn't exist.
         * @param domain_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> persistent_domain_for_name(const std::string& domain_name) const;
        /**
         * @brief Calls `-[NSUserDefaults registerDefaults:]`.
         * @details Specifies the set of default settings and values to use as a fallback in cases where the app domain doesn't have them. - Parameter registrationDictionary: The dictionary of keys and values you want to register. The contents of the registration domain are not written to disk; you need to call this method each time your application starts. You can call this method more than once; each call adds or updates the entries in the registration domain. Default values from Defaults Configuration Files will automatically be registered.
         * @param registration_dictionary Argument converted to the Objective-C parameter of the same role.
         */
        void register_defaults(const std::map<std::string, Object>& registration_dictionary) const;
        /**
         * @brief Calls `-[NSUserDefaults removeObjectForKey:]`.
         * @details Removes the value for the specified key from the defaults database. - Parameter defaultName: The key whose value you want to remove. Removing a default has no effect on the value returned by the 'object(forKey:)' method if the same key exists in a domain that precedes the application domain in the search list.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         */
        void remove_object_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults removePersistentDomainForName:]`.
         * @details Removes the keys and values from the specified persistent domain. - Parameter domainName: The name of the persistent domain. Removes all values from the search list entry specified by 'domainName', the current user, and any host. The change is persistent.
         * @param domain_name Argument converted to the Objective-C parameter of the same role.
         */
        void remove_persistent_domain_for_name(const std::string& domain_name) const;
        /**
         * @brief Calls `-[NSUserDefaults removeSuiteNamed:]`.
         * @details Removes the specified domain from the search list of the current object. - Parameter suiteName: The domain name to remove.
         * @param suite_name Argument converted to the Objective-C parameter of the same role.
         */
        void remove_suite_named(const std::string& suite_name) const;
        /**
         * @brief Calls `-[NSUserDefaults removeVolatileDomainForName:]`.
         * @details Removes the keys and values from the specified volatile domain. - Parameter domainName: The name of the volatile domain to remove.
         * @param domain_name Argument converted to the Objective-C parameter of the same role.
         */
        void remove_volatile_domain_for_name(const std::string& domain_name) const;
        /**
         * @brief Calls `+[NSUserDefaults resetStandardUserDefaults]`.
         * @details This method has no effect and shouldn't be used.
         */
        static void reset_standard_user_defaults();
        /**
         * @brief Calls `-[NSUserDefaults setBool:forKey:]`.
         * @details Sets the value of the specified key to a Boolean value. - Parameters: - value: The Boolean value to store. - defaultName: The key with which to associate the value.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         */
        void set_bool(bool value, const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults setDouble:forKey:]`.
         * @details Sets the value of the specified key to a double. - Parameters: - value: The double value to store. - defaultName: The key with which to associate the value.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         */
        void set_double(double value, const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults setFloat:forKey:]`.
         * @details Sets the value of the specified key to a floating-point number. - Parameters: - value: The floating-point value to store. - defaultName: The key with which to associate the value.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         */
        void set_float(float value, const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults setInteger:forKey:]`.
         * @details Sets the value of the specified key to an integer. - Parameters: - value: The integer value to store. - defaultName: The key with which to associate the value.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         */
        void set_integer(std::int64_t value, const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults setObject:forKey:]`.
         * @details Sets the value of the specified key to a property list object. - Parameters: - value: The object to store in the defaults database. Pass 'nil' to remove the value for 'defaultName'. - defaultName: The key with which to associate the value. This method immediately stores a value (or removes the value if 'nil' is passed) for the provided key in the search list entry for the receiver's suite name in the current user and any host, then asynchronously stores the value persistently, where it is made available to other processes. Setting a default value to a non-property-list object that can't be archived will throw an exception.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         */
        void set_object(const Object& value, const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults setPersistentDomain:forName:]`.
         * @details Replaces the keys and values in the specified domain with the new keys and values you supply. - Parameters: - domain: The dictionary of keys and values to assign to the domain. - domainName: The name of the persistent domain. Replaces all values in the search list entry specified by 'domainName', the current user, and any host, with the values in 'domain'. The change will be persisted.
         * @param domain Argument converted to the Objective-C parameter of the same role.
         * @param domain_name Argument converted to the Objective-C parameter of the same role.
         */
        void set_persistent_domain(const std::map<std::string, Object>& domain, const std::string& domain_name) const;
        /**
         * @brief Calls `-[NSUserDefaults setURL:forKey:]`.
         * @details Sets the value of the specified key to a URL. - Parameters: - url: The URL to store. - defaultName: The key with which to associate the value. If 'url' is a file URL, the value that is archived is the 'path' with the user's home directory abbreviated using a tilde ('~') character. Use ''UserDefaults/url(forKey:)'' to retrieve values set this way.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         */
        void set_url(const URL& url, const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults setVolatileDomain:forName:]`.
         * @details Replaces the keys and values in the specified domain with the new keys and values you supply. - Parameters: - domain: The dictionary of keys and values to assign to the domain. - domainName: The name of the volatile domain.
         * @param domain Argument converted to the Objective-C parameter of the same role.
         * @param domain_name Argument converted to the Objective-C parameter of the same role.
         */
        void set_volatile_domain(const std::map<std::string, Object>& domain, const std::string& domain_name) const;
        /**
         * @brief Calls `-[NSUserDefaults stringArrayForKey:]`.
         * @details Returns the array of strings associated with the specified key. - Parameter defaultName: A key in the current user's defaults database. - Returns: The array of strings associated with the specified key, or 'nil' if the key doesn't exist, the value is not an array, or any element in the array is not a string. Unlike ''UserDefaults/string(forKey:)'', 'NSNumber' values are not converted to strings.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> string_array_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults stringForKey:]`.
         * @details Returns the string associated with the specified key. - Parameter defaultName: A key in the current user's defaults database. - Returns: The string associated with the specified key, or 'nil' if the key doesn't exist or the value is not a string. If the value is a number, this method converts it to a string representation.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string string_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults synchronize]`.
         * @details Waits for any pending asynchronous updates to the defaults database and returns; this method is unnecessary and shouldn't be used. This method is unnecessary and shouldn't be used.
         * @return The converted Objective-C result.
         */
        bool synchronize() const;
        /**
         * @brief Calls `-[NSUserDefaults volatileDomainForName:]`.
         * @details Retrieves the settings from the specified volatile domain. - Parameter domainName: The name of the volatile domain. - Returns: The dictionary for the volatile domain specified by 'domainName', or 'nil' if the domain doesn't exist.
         * @param domain_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> volatile_domain_for_name(const std::string& domain_name) const;
        /**
         * @brief Returns the `standardUserDefaults` property of `NSUserDefaults`.
         * @details The shared defaults object for the current app. The shared defaults object searches the current application's search list, which consists of the current domain, followed by any added suite domains, the global domain, and the registration domain.
         * @return The converted Objective-C result.
         */
        static UserDefaults standard_user_defaults();
        /**
         * @brief Returns the `volatileDomainNames` property of `NSUserDefaults`.
         * @details An array of identifiers for the volatile domains associated with the current object. Use ''UserDefaults/volatileDomain(forName:)'' to retrieve the contents of a specific volatile domain.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> volatile_domain_names() const;
    };
}
