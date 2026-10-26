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
     * @details NSUserDefaults is a hierarchical persistent interprocess (optionally distributed) key-value store, optimized for storing user settings. Hierarchical: NSUserDefaults has a list of places to look for data called the "search list". A search list is referred to by an arbitrary string called the "suite identifier" or "domain identifier". When queried, NSUserDefaults checks each entry of its search list until it finds one that contains the key in question, or has searched the whole list. The list is (note: "current host + current user" preferences are unimplemented on iOS, watchOS, and tvOS, and "any user" preferences are not generally useful for applications on those operating systems): - Managed ("forced") preferences, set by a configuration profile or via mcx from a network administrator - Commandline arguments - Preferences for the current domain, in the cloud - Preferences for the current domain, the current user, in the current host - Preferences for the current domain, the current user, in any host - Preferences added via -addSuiteNamed: - Preferences global to all apps for the current user, in the current host - Preferences global to all apps for the current user, in any host - Preferences for the current domain, for all users, in the current host - Preferences global to all apps for all users, in the current host - Preferences registered with -registerDefaults: Persistent: Preferences stored in NSUserDefaults persist across reboots and relaunches of apps unless otherwise specified. Interprocess: Preferences may be accessible to and modified from multiple processes simultaneously (for example between an application and an extension). Optionally distributed (Currently only supported in Shared iPad for Students mode): Data stored in user defaults can be made "ubiqitous", i.e. synchronized between devices via the cloud. Ubiquitous user defaults are automatically propagated to all devices logged into the same iCloud account. When reading defaults (via -ForKey: methods on NSUserDefaults), ubiquitous defaults are searched before local defaults. All operations on ubiquitous defaults are asynchronous, so registered defaults may be returned in place of ubiquitous defaults if downloading from iCloud hasn't finished. Ubiquitous defaults are specified in the Defaults Configuration File for an application. Key-Value Store: NSUserDefaults stores Property List objects (NSString, NSData, NSNumber, NSDate, NSArray, and NSDictionary) identified by NSString keys, similar to an NSMutableDictionary. Optimized for storing user settings: NSUserDefaults is intended for relatively small amounts of data, queried very frequently, and modified occasionally. Using it in other ways may be slow or use more memory than solutions more suited to those uses. The 'App' CFPreferences functions in CoreFoundation act on the same search lists that NSUserDefaults does. NSUserDefaults can be observed using Key-Value Observing for any key stored in it. Using NSKeyValueObservingOptionPrior to observe changes from other processes or devices will behave as though NSKeyValueObservingOptionPrior was not specified.
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
         * @details -URLForKey: is equivalent to -objectForKey: except that it converts the returned value to an NSURL. If the value is an NSString path, then it will construct a file URL to that path. If the value is an archived URL from -setURL:forKey: it will be unarchived. If the value is absent or can't be converted to an NSURL, nil will be returned.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        URL url_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults addSuiteNamed:]`.
         * @details -addSuiteNamed: adds the full search list for 'suiteName' as a sub-search-list of the receiver's. The additional search lists are searched after the current domain, but before global defaults. Passing NSGlobalDomain or the current application's bundle identifier is unsupported.
         * @param suite_name Argument converted to the Objective-C parameter of the same role.
         */
        void add_suite_named(const std::string& suite_name) const;
        /**
         * @brief Calls `-[NSUserDefaults arrayForKey:]`.
         * @details -arrayForKey: is equivalent to -objectForKey:, except that it will return nil if the value is not an NSArray.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<Object> array_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults boolForKey:]`.
         * @details -boolForKey: is equivalent to -objectForKey:, except that it converts the returned value to a BOOL. If the value is an NSNumber, NO will be returned if the value is 0, YES otherwise. If the value is an NSString, values of "YES" or "1" will return YES, and values of "NO", "0", or any other string will return NO. If the value is absent or can't be converted to a BOOL, NO will be returned.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool bool_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults dataForKey:]`.
         * @details -dataForKey: is equivalent to -objectForKey:, except that it will return nil if the value is not an NSData.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> data_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults dictionaryForKey:]`.
         * @details -dictionaryForKey: is equivalent to -objectForKey:, except that it will return nil if the value is not an NSDictionary.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> dictionary_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults dictionaryRepresentation]`.
         * @details -dictionaryRepresentation returns a composite snapshot of the values in the receiver's search list, such that [[receiver dictionaryRepresentation] objectForKey:x] will return the same thing as [receiver objectForKey:x].
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> dictionary_representation() const;
        /**
         * @brief Calls `-[NSUserDefaults doubleForKey:]`.
         * @details -doubleForKey: is similar to -integerForKey:, except that it returns a double, and boolean values will not be converted.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double double_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults floatForKey:]`.
         * @details -floatForKey: is similar to -integerForKey:, except that it returns a float, and boolean values will not be converted.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        float float_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults integerForKey:]`.
         * @details -integerForKey: is equivalent to -objectForKey:, except that it converts the returned value to an NSInteger. If the value is an NSNumber, the result of -integerValue will be returned. If the value is an NSString, it will be converted to NSInteger if possible. If the value is a boolean, it will be converted to either 1 for YES or 0 for NO. If the value is absent or can't be converted to an integer, 0 will be returned.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t integer_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults objectForKey:]`.
         * @details -objectForKey: will search the receiver's search list for a default with the key 'defaultName' and return it. If another process has changed defaults in the search list, NSUserDefaults will automatically update to the latest values. If the key in question has been marked as ubiquitous via a Defaults Configuration File, the latest value may not be immediately available, and the registered value will be returned instead.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object object_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults objectIsForcedForKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool object_is_forced_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSUserDefaults objectIsForcedForKey:inDomain:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @param domain Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool object_is_forced_for_key(const std::string& key, const std::string& domain) const;
        /**
         * @brief Calls `-[NSUserDefaults persistentDomainForName:]`.
         * @details -persistentDomainForName: returns a dictionary representation of the search list entry specified by 'domainName', the current user, and any host.
         * @param domain_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> persistent_domain_for_name(const std::string& domain_name) const;
        /**
         * @brief Calls `-[NSUserDefaults registerDefaults:]`.
         * @details -registerDefaults: adds the registrationDictionary to the last item in every search list. This means that after NSUserDefaults has looked for a value in every other valid location, it will look in registered defaults, making them useful as a "fallback" value. Registered defaults are never stored between runs of an application, and are visible only to the application that registers them. Default values from Defaults Configuration Files will automatically be registered.
         * @param registration_dictionary Argument converted to the Objective-C parameter of the same role.
         */
        void register_defaults(const std::map<std::string, Object>& registration_dictionary) const;
        /**
         * @brief Calls `-[NSUserDefaults removeObjectForKey:]`.
         * @details -removeObjectForKey: is equivalent to -[... setObject:nil forKey:defaultName]
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         */
        void remove_object_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults removePersistentDomainForName:]`.
         * @details -removePersistentDomainForName: removes all values from the search list entry specified by 'domainName', the current user, and any host. The change is persistent.
         * @param domain_name Argument converted to the Objective-C parameter of the same role.
         */
        void remove_persistent_domain_for_name(const std::string& domain_name) const;
        /**
         * @brief Calls `-[NSUserDefaults removeSuiteNamed:]`.
         * @details -removeSuiteNamed: removes a sub-searchlist added via -addSuiteNamed:.
         * @param suite_name Argument converted to the Objective-C parameter of the same role.
         */
        void remove_suite_named(const std::string& suite_name) const;
        /**
         * @brief Calls `-[NSUserDefaults removeVolatileDomainForName:]`.
         * @param domain_name Argument converted to the Objective-C parameter of the same role.
         */
        void remove_volatile_domain_for_name(const std::string& domain_name) const;
        /**
         * @brief Calls `+[NSUserDefaults resetStandardUserDefaults]`.
         * @details +resetStandardUserDefaults releases the standardUserDefaults and sets it to nil. A new standardUserDefaults will be created the next time it's accessed. The only visible effect this has is that all KVO observers of the previous standardUserDefaults will no longer be observing it.
         */
        static void reset_standard_user_defaults();
        /**
         * @brief Calls `-[NSUserDefaults setBool:forKey:]`.
         * @details -setBool:forKey: is equivalent to -setObject:forKey: except that the value is converted from a BOOL to an NSNumber.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         */
        void set_bool(bool value, const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults setDouble:forKey:]`.
         * @details -setDouble:forKey: is equivalent to -setObject:forKey: except that the value is converted from a double to an NSNumber.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         */
        void set_double(double value, const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults setFloat:forKey:]`.
         * @details -setFloat:forKey: is equivalent to -setObject:forKey: except that the value is converted from a float to an NSNumber.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         */
        void set_float(float value, const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults setInteger:forKey:]`.
         * @details -setInteger:forKey: is equivalent to -setObject:forKey: except that the value is converted from an NSInteger to an NSNumber.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         */
        void set_integer(std::int64_t value, const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults setObject:forKey:]`.
         * @details -setObject:forKey: immediately stores a value (or removes the value if nil is passed as the value) for the provided key in the search list entry for the receiver's suite name in the current user and any host, then asynchronously stores the value persistently, where it is made available to other processes.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         */
        void set_object(const Object& value, const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults setPersistentDomain:forName:]`.
         * @details -setPersistentDomain:forName: replaces all values in the search list entry specified by 'domainName', the current user, and any host, with the values in 'domain'. The change will be persisted.
         * @param domain Argument converted to the Objective-C parameter of the same role.
         * @param domain_name Argument converted to the Objective-C parameter of the same role.
         */
        void set_persistent_domain(const std::map<std::string, Object>& domain, const std::string& domain_name) const;
        /**
         * @brief Calls `-[NSUserDefaults setURL:forKey:]`.
         * @details -setURL:forKey is equivalent to -setObject:forKey: except that the value is archived to an NSData. Use -URLForKey: to retrieve values set this way.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         */
        void set_url(const URL& url, const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults setVolatileDomain:forName:]`.
         * @param domain Argument converted to the Objective-C parameter of the same role.
         * @param domain_name Argument converted to the Objective-C parameter of the same role.
         */
        void set_volatile_domain(const std::map<std::string, Object>& domain, const std::string& domain_name) const;
        /**
         * @brief Calls `-[NSUserDefaults stringArrayForKey:]`.
         * @details -stringForKey: is equivalent to -objectForKey:, except that it will return nil if the value is not an NSArray\<NSString >. Note that unlike -stringForKey:, NSNumbers are not converted to NSStrings.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> string_array_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults stringForKey:]`.
         * @details -stringForKey: is equivalent to -objectForKey:, except that it will convert NSNumber values to their NSString representation. If a non-string non-number value is found, nil will be returned.
         * @param default_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string string_for_key(const std::string& default_name) const;
        /**
         * @brief Calls `-[NSUserDefaults synchronize]`.
         * @details -synchronize is deprecated and will be marked with the API_DEPRECATED macro in a future release. -synchronize blocks the calling thread until all in-progress set operations have completed. This is no longer necessary. Replacements for previous uses of -synchronize depend on what the intent of calling synchronize was. If you synchronized... - ...before reading in order to fetch updated values: remove the synchronize call - ...after writing in order to notify another program to read: the other program can use KVO to observe the default without needing to notify - ...before exiting in a non-app (command line tool, agent, or daemon) process: call CFPreferencesAppSynchronize(kCFPreferencesCurrentApplication) - ...for any other reason: remove the synchronize call
         * @return The converted Objective-C result.
         */
        bool synchronize() const;
        /**
         * @brief Calls `-[NSUserDefaults volatileDomainForName:]`.
         * @param domain_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> volatile_domain_for_name(const std::string& domain_name) const;
        /**
         * @brief Returns the `standardUserDefaults` property of `NSUserDefaults`.
         * @details +standardUserDefaults returns a global instance of NSUserDefaults configured to search the current application's search list.
         * @return The converted Objective-C result.
         */
        static UserDefaults standard_user_defaults();
        /**
         * @brief Returns the `volatileDomainNames` property of `NSUserDefaults`.
         * @details Volatile domains are not added to any search list, are not persisted, and are not visible to other applications. Using them is not recommended.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> volatile_domain_names() const;
    };
}
