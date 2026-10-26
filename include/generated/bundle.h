#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class Image;
    class Number;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSBundle` (Foundation).
     * @details Because NSBundle caches allocated instances, subclasses should be prepared to receive an already initialized object back from [super initWithPath:]
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Bundle bundle;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Bundle bundle{};
     * auto made_0 = cocoon::Bundle::bundle_for_class("text");
     * bundle.url_for_auxiliary_executable("text");
     * bundle.url_for_image_resource("text");
     * bundle.url_for_resource("text", "text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsbundle
     */
    class Bundle : public Object
    {
    public:
        /// @brief Creates a new `NSBundle` instance and returns a handle to it.
        explicit Bundle(const std::string& path);
        /// @brief Creates a new `NSBundle` instance and returns a handle to it.
        explicit Bundle(const URL& url);
        /// @brief Creates a new `NSBundle` instance and returns a handle to it.
        explicit Bundle();
        /// @brief Creates a null handle that refers to no native object.
        Bundle(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Bundle(Adopt adopt);
        /**
         * @brief Calls `-[NSBundle URLForAuxiliaryExecutable:]`.
         * @param executable_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        URL url_for_auxiliary_executable(const std::string& executable_name) const;
        /**
         * @brief Calls `-[NSBundle URLForImageResource:]`.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        URL url_for_image_resource(const std::string& name) const;
        /**
         * @brief Calls `-[NSBundle URLForResource:withExtension:]`.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param ext Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        URL url_for_resource(const std::string& name, const std::string& ext) const;
        /**
         * @brief Calls `-[NSBundle URLForResource:withExtension:subdirectory:]`.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param ext Argument converted to the Objective-C parameter of the same role.
         * @param subpath Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        URL url_for_resource(const std::string& name, const std::string& ext, const std::string& subpath) const;
        /**
         * @brief Calls `+[NSBundle URLForResource:withExtension:subdirectory:inBundleWithURL:]`.
         * @details Methods for locating bundle resources. Instance methods locate resources in the bundle indicated by the receiver; class methods take an argument pointing to a bundle on disk. In the class methods, bundleURL is a URL pointing to the location of a bundle on disk, and may not be nil; bundlePath is the path equivalent of bundleURL, an absolute path pointing to the location of a bundle on disk. By contrast, subpath is a relative path to a subdirectory inside the relevant global or localized resource directory, and should be nil if the resource file in question is not in a subdirectory. Where appropriate, localizationName is the name of a .lproj directory in the bundle, minus the .lproj extension; passing nil for localizationName retrieves only global resources, whereas using a method without this argument retrieves both global and localized resources (using the standard localization search algorithm).
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param ext Argument converted to the Objective-C parameter of the same role.
         * @param subpath Argument converted to the Objective-C parameter of the same role.
         * @param bundle_url Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static URL url_for_resource(const std::string& name, const std::string& ext, const std::string& subpath, const URL& bundle_url);
        /**
         * @brief Calls `-[NSBundle URLForResource:withExtension:subdirectory:localization:]`.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param ext Argument converted to the Objective-C parameter of the same role.
         * @param subpath Argument converted to the Objective-C parameter of the same role.
         * @param localization_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        URL url_for_resource(const std::string& name, const std::string& ext, const std::string& subpath, const std::string& localization_name) const;
        /**
         * @brief Calls `-[NSBundle URLsForResourcesWithExtension:subdirectory:]`.
         * @param ext Argument converted to the Objective-C parameter of the same role.
         * @param subpath Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<URL> ur_ls_for_resources_with_extension(const std::string& ext, const std::string& subpath) const;
        /**
         * @brief Calls `+[NSBundle URLsForResourcesWithExtension:subdirectory:inBundleWithURL:]`.
         * @param ext Argument converted to the Objective-C parameter of the same role.
         * @param subpath Argument converted to the Objective-C parameter of the same role.
         * @param bundle_url Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::vector<URL> ur_ls_for_resources_with_extension(const std::string& ext, const std::string& subpath, const URL& bundle_url);
        /**
         * @brief Calls `-[NSBundle URLsForResourcesWithExtension:subdirectory:localization:]`.
         * @param ext Argument converted to the Objective-C parameter of the same role.
         * @param subpath Argument converted to the Objective-C parameter of the same role.
         * @param localization_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<URL> ur_ls_for_resources_with_extension(const std::string& ext, const std::string& subpath, const std::string& localization_name) const;
        /**
         * @brief Calls `+[NSBundle bundleForClass:]`.
         * @param a_class Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Bundle bundle_for_class(const std::string& a_class);
        /**
         * @brief Calls `-[NSBundle classNamed:]`.
         * @param class_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string class_named(const std::string& class_name) const;
        /**
         * @brief Calls `-[NSBundle contextHelpForKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AttributedString context_help_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSBundle imageForResource:]`.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Image image_for_resource(const std::string& name) const;
        /**
         * @brief Calls `-[NSBundle loadAndReturnError:]`.
         * @return The converted Objective-C result.
         */
        bool load_and_return_error() const;
        /**
         * @brief Calls `-[NSBundle loadNibNamed:owner:topLevelObjects:]`.
         * @param nib_name Argument converted to the Objective-C parameter of the same role.
         * @param owner Argument converted to the Objective-C parameter of the same role.
         * @param top_level_objects Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool load_nib_named(const std::string& nib_name, const Object& owner, std::vector<Object>& top_level_objects) const;
        /**
         * @brief Calls `-[NSBundle localizedAttributedStringForKey:value:table:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param table_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AttributedString localized_attributed_string_for_key(const std::string& key, const std::string& value, const std::string& table_name) const;
        /**
         * @brief Calls `-[NSBundle localizedStringForKey:value:table:]`.
         * @details Methods for retrieving localized strings.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param table_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string localized_string_for_key(const std::string& key, const std::string& value, const std::string& table_name) const;
        /**
         * @brief Calls `-[NSBundle localizedStringForKey:value:table:localizations:]`.
         * @details Look up a localized string given a list of available localizations. - Parameters: - key: The key for the localized string to retrieve. - value: A default value to return if a localized string for ''key'' cannot be found. - tableName: The name of the strings file to search. If 'nil', the method uses tables in 'Localizable.strings'. - localizations: An array of BCP 47 language codes corresponding to available localizations. Bundle compares the array against its available localizations, and uses the best result to retrieve the localized string. If empty, we treat it as no localization is available, and may return a fallback. - Returns: A localized version of the string designated by ''key'' in table ''tableName''.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param table_name Argument converted to the Objective-C parameter of the same role.
         * @param localizations Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string localized_string_for_key(const std::string& key, const std::string& value, const std::string& table_name, const std::vector<std::string>& localizations) const;
        /**
         * @brief Calls `-[NSBundle objectForInfoDictionaryKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object object_for_info_dictionary_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSBundle pathForAuxiliaryExecutable:]`.
         * @param executable_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string path_for_auxiliary_executable(const std::string& executable_name) const;
        /**
         * @brief Calls `-[NSBundle pathForImageResource:]`.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string path_for_image_resource(const std::string& name) const;
        /**
         * @brief Calls `-[NSBundle pathForResource:ofType:]`.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param ext Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string path_for_resource(const std::string& name, const std::string& ext) const;
        /**
         * @brief Calls `-[NSBundle pathForResource:ofType:inDirectory:]`.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param ext Argument converted to the Objective-C parameter of the same role.
         * @param subpath Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string path_for_resource(const std::string& name, const std::string& ext, const std::string& subpath) const;
        /**
         * @brief Calls `-[NSBundle pathForResource:ofType:inDirectory:forLocalization:]`.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param ext Argument converted to the Objective-C parameter of the same role.
         * @param subpath Argument converted to the Objective-C parameter of the same role.
         * @param localization_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string path_for_resource(const std::string& name, const std::string& ext, const std::string& subpath, const std::string& localization_name) const;
        /**
         * @brief Calls `-[NSBundle pathForSoundResource:]`.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string path_for_sound_resource(const std::string& name) const;
        /**
         * @brief Calls `-[NSBundle pathsForResourcesOfType:inDirectory:]`.
         * @param ext Argument converted to the Objective-C parameter of the same role.
         * @param subpath Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> paths_for_resources_of_type(const std::string& ext, const std::string& subpath) const;
        /**
         * @brief Calls `-[NSBundle pathsForResourcesOfType:inDirectory:forLocalization:]`.
         * @param ext Argument converted to the Objective-C parameter of the same role.
         * @param subpath Argument converted to the Objective-C parameter of the same role.
         * @param localization_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> paths_for_resources_of_type(const std::string& ext, const std::string& subpath, const std::string& localization_name) const;
        /**
         * @brief Calls `+[NSBundle preferredLocalizationsFromArray:]`.
         * @param localizations_array Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> preferred_localizations_from_array(const std::vector<std::string>& localizations_array);
        /**
         * @brief Calls `+[NSBundle preferredLocalizationsFromArray:forPreferences:]`.
         * @param localizations_array Argument converted to the Objective-C parameter of the same role.
         * @param preferences_array Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> preferred_localizations_from_array(const std::vector<std::string>& localizations_array, const std::vector<std::string>& preferences_array);
        /**
         * @brief Calls `-[NSBundle preflightAndReturnError:]`.
         * @return The converted Objective-C result.
         */
        bool preflight_and_return_error() const;
        /**
         * @brief Calls `-[NSBundle unload]`.
         * @return The converted Objective-C result.
         */
        bool unload() const;
        /**
         * @brief Returns the `allBundles` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        static std::vector<Bundle> all_bundles();
        /**
         * @brief Returns the `allFrameworks` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        static std::vector<Bundle> all_frameworks();
        /**
         * @brief Returns the `appStoreReceiptURL` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        URL app_store_receipt_url() const;
        /**
         * @brief Returns the `builtInPlugInsPath` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        std::string built_in_plug_ins_path() const;
        /**
         * @brief Returns the `builtInPlugInsURL` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        URL built_in_plug_ins_url() const;
        /**
         * @brief Returns the `bundleIdentifier` property of `NSBundle`.
         * @details Methods for obtaining various information about a bundle.
         * @return The converted Objective-C result.
         */
        std::string bundle_identifier() const;
        /**
         * @brief Returns the `bundlePath` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        std::string bundle_path() const;
        /**
         * @brief Returns the `bundleURL` property of `NSBundle`.
         * @details Methods for locating various components of a bundle.
         * @return The converted Objective-C result.
         */
        URL bundle_url() const;
        /**
         * @brief Returns the `developmentLocalization` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        std::string development_localization() const;
        /**
         * @brief Returns the `executableArchitectures` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        std::vector<Number> executable_architectures() const;
        /**
         * @brief Returns the `executablePath` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        std::string executable_path() const;
        /**
         * @brief Returns the `executableURL` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        URL executable_url() const;
        /**
         * @brief Returns the `infoDictionary` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> info_dictionary() const;
        /**
         * @brief Returns the `loaded` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        bool is_loaded() const;
        /**
         * @brief Returns the `localizations` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> localizations() const;
        /**
         * @brief Returns the `localizedInfoDictionary` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> localized_info_dictionary() const;
        /**
         * @brief Returns the `mainBundle` property of `NSBundle`.
         * @details Methods for creating or retrieving bundle instances.
         * @return The converted Objective-C result.
         */
        static Bundle main_bundle();
        /**
         * @brief Returns the `preferredLocalizations` property of `NSBundle`.
         * @details Methods for dealing with localizations.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> preferred_localizations() const;
        /**
         * @brief Returns the `principalClass` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        std::string principal_class() const;
        /**
         * @brief Returns the `privateFrameworksPath` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        std::string private_frameworks_path() const;
        /**
         * @brief Returns the `privateFrameworksURL` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        URL private_frameworks_url() const;
        /**
         * @brief Returns the `resourcePath` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        std::string resource_path() const;
        /**
         * @brief Returns the `resourceURL` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        URL resource_url() const;
        /**
         * @brief Returns the `sharedFrameworksPath` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        std::string shared_frameworks_path() const;
        /**
         * @brief Returns the `sharedFrameworksURL` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        URL shared_frameworks_url() const;
        /**
         * @brief Returns the `sharedSupportPath` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        std::string shared_support_path() const;
        /**
         * @brief Returns the `sharedSupportURL` property of `NSBundle`.
         * @return The converted Objective-C result.
         */
        URL shared_support_url() const;
    };
}
