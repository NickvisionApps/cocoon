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
     * @details A representation of the code and resources stored in a bundle directory on disk. Apple uses bundles to represent apps, frameworks, plug-ins, and many other specific types of content. Bundles organize their contained resources into well-defined subdirectories, and bundle structures vary depending on the platform and the type of the bundle. By using a bundle object, you can access a bundle's resources without knowing the structure of the bundle. The bundle object provides a single interface for locating items, taking into account the bundle structure, user preferences, available localizations, and other relevant factors. Any executable can use a bundle object to locate resources, either inside an app's bundle or in a known bundle located elsewhere. You don't use a bundle object to locate files in a container directory or in other parts of the file system. The general pattern for using a bundle object is as follows: 1. Create a bundle object for the intended bundle directory. 2. Use the methods of the bundle object to locate or load the needed resource. 3. Use other system APIs to interact with the resource. Some types of frequently used resources can be located and opened without a bundle. For example, when loading images, you store images in asset catalogs and load them using the \<doc://com.apple.documentation/documentation/uikit/uiimage/init(named:)> methods of \<doc://com.apple.documentation/documentation/uikit/uiimage> or \<doc://com.apple.documentation/documentation/appkit/nsimage>. Similarly, for string resources, you use ''NSLocalizedString'' to load individual strings instead of loading the entire '.strings' file yourself. > Note: Unlike some other Foundation classes with corresponding Core Foundation names (such as ''NSString'' and \<doc://com.apple.documentation/documentation/corefoundation/cfstring>), ''Bundle'' objects cannot be cast to \<doc://com.apple.documentation/documentation/corefoundation/cfbundle> references. If you need functionality provided by \<doc://com.apple.documentation/documentation/corefoundation/cfbundle>, you can still create a \<doc://com.apple.documentation/documentation/corefoundation/cfbundle> and use the \<doc://com.apple.documentation/documentation/corefoundation/cfbundle> API. See [Toll-Free Bridging](https://developer.apple.com/library/archive/documentation/General/Conceptual/CocoaEncyclopedia/Toll-FreeBridgin/Toll-FreeBridgin.html\#//apple_ref/doc/uid/TP40010810-CH2) for more information. \#\#\# Finding and Opening a Bundle Before you can locate a resource, you must first specify which bundle contains it. The ''Bundle'' class has many constructors, but the one you use most often is ''main''. The main bundle represents the bundle directory that contains the currently executing code. So for an app, the main bundle object gives you access to the resources that shipped with your app. If your app interacts directly with plug-ins, frameworks, or other bundled content, you can use other methods of this class to create appropriate bundle objects. You can always create bundle objects from a known URL or path, but other methods make it easier to access bundles your app is already using. For example, if you link to a framework, you can use the ''init(for:)'' method to locate the framework bundle based on a class defined in that framework. \@TabNavigator { \@Tab("Swift") { '''swift // Get the app's main bundle let mainBundle = Bundle.main // Get the bundle containing the specified private class. let myBundle = Bundle(for: NSClassFromString("MyPrivateClass")!) ''' } \@Tab("Objective-C") { '''objc // Get the app's main bundle NSBundle main = [NSBundle mainBundle]; // Get the bundle containing the specified private class. NSBundle myBundle = [NSBundle bundleForClass:[MyPrivateClass class]]; ''' } } In Swift, use the ''bundle()'' macro to insert a bundle instance appropriate to the current execution context, whether an app, app extension, framework, or Swift package. \#\#\# Locating Resources in a Bundle You use ''Bundle'' objects to obtain the location of specific resources inside the bundle. When looking for resources, you provide the name of the resource and its type at a minimum. For resources in a specific subdirectory, you can also specify that directory. After locating the resource, the bundle routines return a path string or URL that you can use to open the file. Locating a single resource in a bundle '''objc NSBundle main = [NSBundle mainBundle]; NSString resourcePath = [main pathForResource:\@"Seagull" ofType:\@"jpg"]; ''' Bundle objects follow a specific search pattern when looking for resources on disk. Global resources—that is, resources not in a language-specific '.lproj' directory—are returned first, followed by region- and language-specific resources. This search pattern means that the bundle looks for resources in the following order: 1. Global (nonlocalized) resources 2. Region-specific localized resources (based on the user's region preferences) 3. Language-specific localized resources (based on the user's language preferences) 4. Development language resources (as specified by the [CFBundleDevelopmentRegion](https://developer.apple.com/library/archive/documentation/General/Reference/InfoPlistKeyReference/Articles/CoreFoundationKeys.html\#//apple_ref/doc/uid/20001431-130430) key in the bundle's Info.plist file) Because global resources take precedence over language-specific resources, you should never include both a global and localized version of a given resource in your app. When a global version of a resource exists, language-specific versions are never returned. The reason for this precedence is performance. If localized resources were searched first, the bundle object might waste time searching for a nonexistent localized resource before returning the global resource. > Important: > Bundle objects always consider case when searching for resource files, even on file systems that support case-insensitive filenames. Always make sure that you specify filenames with case sensitivity in mind. When locating resource files, the bundle object automatically considers many standard filename modifiers when determining which file to return. Resources may be tagged for a specific device ('~iphone', '~ipad') or for a specific screen resolution ('\@2x', '\@3x'). Do not include these modifiers when specifying the name of the resource you want. The bundle object selects the file that is most appropriate for the underlying device. For more information, see [App Icons on iPhone, iPad and Apple Watch](https://developer.apple.com/library/archive/qa/qa1686/index.html\#//apple_ref/doc/uid/DTS40009882). \#\#\# Understanding Bundle Structures Bundle structures vary depending on the target platform and the type of bundle you are building. The ''Bundle'' class hides this underlying structure in most (but not all) cases. Many of the methods you use to load resources from a bundle automatically locate the appropriate starting directory and look for resources in known places. You can also use the methods and properties of this class to get the location of known bundle directories and to retrieve resources specifically from those directories. For information about the bundle structure of iOS and macOS apps, see [Bundle Programming Guide](https://developer.apple.com/library/archive/documentation/CoreFoundation/Conceptual/CFBundles/Introduction/Introduction.html\#//apple_ref/doc/uid/10000123i). For information about the structure of framework bundles, see [Framework Programming Guide](https://developer.apple.com/library/archive/documentation/MacOSX/Conceptual/BPFrameworks/Frameworks.html\#//apple_ref/doc/uid/10000183i). For information about the structure of macOS plug-ins, see [Code Loading Programming Topics](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/LoadingCode/LoadingCode.html\#//apple_ref/doc/uid/10000052i).
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
     * @details Returns the file URL of the executable with the specified name in the receiver's bundle. This method returns the appropriate path for modern application and framework bundles. This method may not return a URL for non-standard bundle formats or for some older bundle formats. \@param executableName The name of an executable file. \@return The file URL of the executable in the receiver's bundle.
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
     * @details Returns the file URL for the resource identified by the specified name and file extension. \@param name The name of the resource file. If \@c nil, the method returns the first resource file it finds with the specified extension. \@param ext The extension of the resource file. If an empty string or \@c nil, the extension is assumed not to exist. \@return The file URL for the resource file or \@c nil if the file could not be located.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param ext Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_for_resource(const std::string& name, const std::string& ext) const;
        /**
     * @brief Calls `-[NSBundle URLForResource:withExtension:subdirectory:]`.
     * @details Returns the file URL for the resource file identified by the specified name and extension and residing in a given bundle directory. \@param name The name of a resource file. If \@c nil, the method returns the first resource file it finds with the specified extension. \@param ext The filename extension of the file to locate. If an empty string or \@c nil, the extension is assumed not to exist. \@param subpath The name of the bundle subdirectory to search. \@return The file URL for the resource file or \@c nil if the file could not be located.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param ext Argument converted to the Objective-C parameter of the same role.
     * @param subpath Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_for_resource(const std::string& name, const std::string& ext, const std::string& subpath) const;
        /**
     * @brief Calls `+[NSBundle URLForResource:withExtension:subdirectory:inBundleWithURL:]`.
     * @details Creates and returns a file URL for the resource with the specified name and extension in the specified bundle. \@param name The name of the resource file. If \@c nil, the method returns the first resource file it finds that matches the remaining criteria. \@param ext The filename extension of the file to locate. If an empty string or \@c nil, the extension is assumed not to exist. \@param subpath The name of the bundle subdirectory to search. \@param bundleURL The file URL of the bundle to search. \@return The file URL for the resource file or \@c nil if the file could not be located.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param ext Argument converted to the Objective-C parameter of the same role.
     * @param subpath Argument converted to the Objective-C parameter of the same role.
     * @param bundle_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL url_for_resource(const std::string& name, const std::string& ext, const std::string& subpath, const URL& bundle_url);
        /**
     * @brief Calls `-[NSBundle URLForResource:withExtension:subdirectory:localization:]`.
     * @details Returns the file URL for the resource identified by the specified name and file extension, located in the specified bundle subdirectory, and limited to global resources and those associated with the specified localization. \@param name The name of the resource file. If \@c nil, the method returns the first resource file it finds that matches the remaining criteria. \@param ext The filename extension of the file to locate. If an empty string or \@c nil, the extension is assumed not to exist. \@param subpath The name of the bundle subdirectory to search. \@param localizationName The language ID for the localization. This parameter should correspond to the name of one of the bundle's language-specific resource directories without the \@c .lproj extension. \@return The file URL for the resource file or \@c nil if the file could not be located.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param ext Argument converted to the Objective-C parameter of the same role.
     * @param subpath Argument converted to the Objective-C parameter of the same role.
     * @param localization_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_for_resource(const std::string& name, const std::string& ext, const std::string& subpath, const std::string& localization_name) const;
        /**
     * @brief Calls `-[NSBundle URLsForResourcesWithExtension:subdirectory:]`.
     * @details Returns an array of file URLs for all resources identified by the specified file extension and located in the specified bundle subdirectory. \@param ext The filename extension of the files to locate. If an empty string or \@c nil, all files in \@c subpath are returned. \@param subpath The name of the bundle subdirectory. \@return An array of file URLs for the resource files or \@c nil if no files could be located.
     * @param ext Argument converted to the Objective-C parameter of the same role.
     * @param subpath Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<URL> ur_ls_for_resources_with_extension(const std::string& ext, const std::string& subpath) const;
        /**
     * @brief Calls `+[NSBundle URLsForResourcesWithExtension:subdirectory:inBundleWithURL:]`.
     * @details Returns an array containing the file URLs for all bundle resources having the specified filename extension, residing in the specified resource subdirectory, within the specified bundle. \@param ext The filename extension of the files to locate. If an empty string or \@c nil, all files in \@c subpath are returned. \@param subpath The name of the bundle subdirectory to search. \@param bundleURL The file URL of the bundle to search. \@return An array of file URLs for the resource files matching the criteria or an empty array if no files could be located.
     * @param ext Argument converted to the Objective-C parameter of the same role.
     * @param subpath Argument converted to the Objective-C parameter of the same role.
     * @param bundle_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<URL> ur_ls_for_resources_with_extension(const std::string& ext, const std::string& subpath, const URL& bundle_url);
        /**
     * @brief Calls `-[NSBundle URLsForResourcesWithExtension:subdirectory:localization:]`.
     * @details Returns an array containing the file URLs for all bundle resources having the specified filename extension, residing in the specified resource subdirectory, and limited to global resources and those associated with the specified localization. \@param ext The filename extension of the files to locate. If an empty string or \@c nil, all files in \@c subpath are returned. \@param subpath The name of the bundle subdirectory to search. \@param localizationName The language ID for the localization. This parameter should correspond to the name of one of the bundle's language-specific resource directories without the \@c .lproj extension. \@return An array containing the file URLs for all bundle resources matching the specified criteria. Returns an empty array if no matching resource files are found.
     * @param ext Argument converted to the Objective-C parameter of the same role.
     * @param subpath Argument converted to the Objective-C parameter of the same role.
     * @param localization_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<URL> ur_ls_for_resources_with_extension(const std::string& ext, const std::string& subpath, const std::string& localization_name) const;
        /**
     * @brief Calls `+[NSBundle bundleForClass:]`.
     * @details Returns the 'NSBundle' object with which the specified class is associated. \@param aClass A class. \@return The 'NSBundle' object that dynamically loaded \@c aClass (a loadable bundle), the 'NSBundle' object for the framework in which \@c aClass is defined, or the main bundle object if \@c aClass was not dynamically loaded or is not defined in a framework.
     * @param a_class Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Bundle bundle_for_class(const std::string& a_class);
        /**
     * @brief Calls `-[NSBundle classNamed:]`.
     * @details Returns the \@c Class object for the specified name. If the bundle's executable code is not yet loaded, this method dynamically loads it into memory. \@param className The name of a class. \@return The \@c Class object for \@c className. Returns \@c nil if \@c className is not one of the classes associated with the receiver or if there is an error loading the executable code.
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
     * @details Loads the bundle's executable code and returns any errors. If this method returns \@c NO and you pass a value for the \@c error parameter, a suitable error object is returned. Potential errors include \@c NSFileNoSuchFileError, \@c NSExecutableNotLoadableError, \@c NSExecutableArchitectureMismatchError, \@c NSExecutableRuntimeMismatchError, \@c NSExecutableLoadError, and \@c NSExecutableLinkError. \@param error On output, this variable may contain an error object indicating why the bundle's executable could not be loaded. \@return \@c YES if the bundle's executable code was loaded successfully or was already loaded; otherwise, \@c NO.
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
     * @details Returns a localized version of the string designated by the specified key and residing in the specified table. \@param key The key for a string in the table identified by \@c tableName. \@param value The value to return if \@c key is \@c nil or if a localized string for \@c key can't be found in the table. \@param tableName The receiver's string table to search. If \@c nil or an empty string, the method attempts to use the table in \@c Localizable.strings. \@return A localized version of the string designated by \@c key in table \@c tableName.
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
     * @details Returns the value associated with the specified key in the receiver's information property list. Use of this method is preferred over other access methods because it returns the localized value of a key when one is available. \@param key A key in the receiver's property list. \@return The value associated with \@c key in the receiver's property list (\@c Info.plist). The localized value of a key is returned when one is available.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object object_for_info_dictionary_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSBundle pathForAuxiliaryExecutable:]`.
     * @details Returns the full pathname of the executable with the specified name in the receiver's bundle. This method returns the appropriate path for modern application and framework bundles. This method may not return a path for non-standard bundle formats or for some older bundle formats. \@param executableName The name of an executable file. \@return The full pathname of the executable in the receiver's bundle.
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
     * @details Returns the full pathname for the resource identified by the specified name and file extension. The method first looks for a matching resource file in the non-localized resource directory of the specified bundle. If a matching resource file is not found, it then looks in the top level of an available language-specific \@c .lproj folder. \@param name The name of the resource file. If \@c nil, the method returns the first resource file it finds with the specified extension. \@param ext The filename extension of the file to locate. If an empty string or \@c nil, the extension is assumed not to exist. \@return The full pathname for the resource file, or \@c nil if the file could not be located.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param ext Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string path_for_resource(const std::string& name, const std::string& ext) const;
        /**
     * @brief Calls `-[NSBundle pathForResource:ofType:inDirectory:]`.
     * @details Returns the full pathname for the resource identified by the specified name and file extension and located in the specified bundle subdirectory. \@param name The name of the resource file. If \@c nil, the method returns the first resource file it finds that matches the remaining criteria. \@param ext The filename extension of the files to locate. If an empty string or \@c nil, all files in \@c subpath and its subdirectories are returned. \@param subpath The name of the bundle subdirectory. \@return The full pathname for the resource file, or \@c nil if the file could not be located.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param ext Argument converted to the Objective-C parameter of the same role.
     * @param subpath Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string path_for_resource(const std::string& name, const std::string& ext, const std::string& subpath) const;
        /**
     * @brief Calls `-[NSBundle pathForResource:ofType:inDirectory:forLocalization:]`.
     * @details Returns the full pathname for the resource identified by the specified name and file extension, located in the specified bundle subdirectory, and limited to global resources and those associated with the specified localization. \@param name The name of the resource file. If \@c nil, the method returns the first resource file it finds that matches the remaining criteria. \@param ext The filename extension of the files to locate. If an empty string or \@c nil, the extension is assumed not to exist. \@param subpath The name of the bundle subdirectory to search. \@param localizationName The language ID for the localization. This parameter should correspond to the name of one of the bundle's language-specific resource directories without the \@c .lproj extension. \@return The full pathname for the resource file or \@c nil if the file could not be located.
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
     * @details Returns an array containing the pathnames for all bundle resources having the specified filename extension and residing in the resource subdirectory. \@param ext The filename extension of the files to locate. If an empty string or \@c nil, all files in \@c subpath are returned. \@param subpath The name of the bundle subdirectory to search. \@return An array containing the full pathnames for all bundle resources matching the specified criteria. Returns an empty array if no matching resource files are found.
     * @param ext Argument converted to the Objective-C parameter of the same role.
     * @param subpath Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> paths_for_resources_of_type(const std::string& ext, const std::string& subpath) const;
        /**
     * @brief Calls `-[NSBundle pathsForResourcesOfType:inDirectory:forLocalization:]`.
     * @details Returns an array containing the file for all bundle resources having the specified filename extension, residing in the specified resource subdirectory, and limited to global resources and those associated with the specified localization. \@param ext The filename extension of the files to locate. If an empty string or \@c nil, all files in \@c subpath are returned. \@param subpath The name of the bundle subdirectory to search. \@param localizationName The language ID for the localization. This parameter should correspond to the name of one of the bundle's language-specific resource directories without the \@c .lproj extension. \@return An array containing the full pathnames for all bundle resources matching the specified criteria. Returns an empty array if no matching resource files are found.
     * @param ext Argument converted to the Objective-C parameter of the same role.
     * @param subpath Argument converted to the Objective-C parameter of the same role.
     * @param localization_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> paths_for_resources_of_type(const std::string& ext, const std::string& subpath, const std::string& localization_name) const;
        /**
     * @brief Calls `+[NSBundle preferredLocalizationsFromArray:]`.
     * @details Returns one or more localizations from the specified list that a bundle object would use to locate resources for the current user. This method does not return all localizations in preference order but only those from which \@c NSBundle would get localized content, typically either a single non-region-specific localization or a region-specific localization followed by a corresponding non-region-specific localization as a fallback. \@param localizationsArray An array of \@c NSString objects, each of which specifies the language ID for a localization that the bundle supports. \@return An array of \@c NSString objects containing the preferred localizations, ordered according to the user's language preferences.
     * @param localizations_array Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> preferred_localizations_from_array(const std::vector<std::string>& localizations_array);
        /**
     * @brief Calls `+[NSBundle preferredLocalizationsFromArray:forPreferences:]`.
     * @details Returns locale identifiers for which a bundle would provide localized content, given a specified list of candidates for a user's language preferences. \@param localizationsArray An array of identifiers, each corresponding to a localization that a bundle can support. \@param preferencesArray An array of BCP 47 language codes corresponding to a user's preferred languages. If \@c nil, the method uses the current user's language preferences. \@return An array of locale identifiers, ordered according to user preference. If none of the user-preferred localizations are available, this method returns one of the values in \@c localizationsArray.
     * @param localizations_array Argument converted to the Objective-C parameter of the same role.
     * @param preferences_array Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> preferred_localizations_from_array(const std::vector<std::string>& localizations_array, const std::vector<std::string>& preferences_array);
        /**
     * @brief Calls `-[NSBundle preflightAndReturnError:]`.
     * @details Returns a Boolean value indicating whether the bundle's executable code could be loaded successfully. This method does not actually load the bundle's executable code. Instead, it performs several checks to see if the code could be loaded and with one exception returns the same errors that would occur during an actual load operation. \@param error On output, this variable may contain an error object indicating why the bundle's executable could not be loaded. \@return \@c YES if the bundle's executable code could be loaded successfully or is already loaded; otherwise, \@c NO.
     * @return The converted Objective-C result.
     */
        bool preflight_and_return_error() const;
        /**
     * @brief Calls `-[NSBundle unload]`.
     * @details Unloads the code associated with the receiver. This method attempts to unload a bundle's executable code using the underlying dynamic loader (typically \@c dyld). You may use this method to unload plug-in and framework bundles when you no longer need the code they contain. It is the responsibility of the caller to ensure that no in-memory objects or data structures refer to the code being unloaded. \@return \@c YES if the bundle was successfully unloaded or was not already loaded; otherwise, \@c NO if the bundle could not be unloaded.
     * @return The converted Objective-C result.
     */
        bool unload() const;
        /**
     * @brief Returns the `allBundles` property of `NSBundle`.
     * @details An array of all the application's non-framework bundles. The returned array includes the main bundle and all bundles that have been dynamically created but doesn't contain any bundles that represent frameworks.
     * @return The converted Objective-C result.
     */
        static std::vector<Bundle> all_bundles();
        /**
     * @brief Returns the `allFrameworks` property of `NSBundle`.
     * @details An array of all of the application's bundles that represent frameworks. The returned array includes frameworks that are linked into an application when the application is built and bundles for frameworks that have been dynamically created. Only frameworks with one or more Objective-C classes in them are included.
     * @return The converted Objective-C result.
     */
        static std::vector<Bundle> all_frameworks();
        /**
     * @brief Returns the `appStoreReceiptURL` property of `NSBundle`.
     * @details The file URL for the bundle's App Store receipt. Use this app bundle property to locate the app receipt if it's present; this property is \@c nil if the receipt isn't present. In the rare case a receipt is invalid or missing in an app that a user downloads from the App Store, use \@c SKReceiptRefreshRequest to request a new receipt.
     * @return The converted Objective-C result.
     */
        URL app_store_receipt_url() const;
        /**
     * @brief Returns the `builtInPlugInsPath` property of `NSBundle`.
     * @details The full pathname of the receiver's subdirectory containing plug-ins. This is the appropriate path for modern application and framework bundles. This may not be a path for non-standard bundle formats or for some older bundle formats.
     * @return The converted Objective-C result.
     */
        std::string built_in_plug_ins_path() const;
        /**
     * @brief Returns the `builtInPlugInsURL` property of `NSBundle`.
     * @details The file URL of the receiver's subdirectory containing plug-ins. This is the appropriate path for modern application and framework bundles. This may not be a URL for non-standard bundle formats or for some older bundle formats.
     * @return The converted Objective-C result.
     */
        URL built_in_plug_ins_url() const;
        /**
     * @brief Returns the `bundleIdentifier` property of `NSBundle`.
     * @details The receiver's bundle identifier. The bundle identifier is defined by the \@c CFBundleIdentifier key in the bundle's information property list.
     * @return The converted Objective-C result.
     */
        std::string bundle_identifier() const;
        /**
     * @brief Returns the `bundlePath` property of `NSBundle`.
     * @details The full pathname of the receiver's bundle directory.
     * @return The converted Objective-C result.
     */
        std::string bundle_path() const;
        /**
     * @brief Returns the `bundleURL` property of `NSBundle`.
     * @details The full URL of the receiver's bundle directory.
     * @return The converted Objective-C result.
     */
        URL bundle_url() const;
        /**
     * @brief Returns the `developmentLocalization` property of `NSBundle`.
     * @details The localization for the development language. This property corresponds to the value in the \@c CFBundleDevelopmentRegion key of the bundle's property list (\@c Info.plist).
     * @return The converted Objective-C result.
     */
        std::string development_localization() const;
        /**
     * @brief Returns the `executableArchitectures` property of `NSBundle`.
     * @details An array of numbers indicating the architecture types supported by the bundle's executable. An array of \@c NSNumber objects, each of which contains an integer value corresponding to a supported processor architecture. If the bundle does not contain a Mach-O executable, this is \@c nil.
     * @return The converted Objective-C result.
     */
        std::vector<Number> executable_architectures() const;
        /**
     * @brief Returns the `executablePath` property of `NSBundle`.
     * @details The full pathname of the receiver's executable file.
     * @return The converted Objective-C result.
     */
        std::string executable_path() const;
        /**
     * @brief Returns the `executableURL` property of `NSBundle`.
     * @details The file URL of the receiver's executable file.
     * @return The converted Objective-C result.
     */
        URL executable_url() const;
        /**
     * @brief Returns the `infoDictionary` property of `NSBundle`.
     * @details A dictionary, constructed from the bundle's \@c Info.plist file, that contains information about the receiver. If the bundle does not contain an \@c Info.plist file, this dictionary contains only private keys that are used internally by the \@c NSBundle class. Common keys for accessing the values of the dictionary are \@c CFBundleIdentifier, \@c NSMainNibFile, and \@c NSPrincipalClass.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> info_dictionary() const;
        /**
     * @brief Returns the `loaded` property of `NSBundle`.
     * @details The load status of a bundle. \@c YES if the bundle's code is currently loaded, otherwise \@c NO.
     * @return The converted Objective-C result.
     */
        bool is_loaded() const;
        /**
     * @brief Returns the `localizations` property of `NSBundle`.
     * @details A list of all the localizations contained in the bundle. An array of \@c NSString objects containing language IDs for all the localizations contained in the bundle.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> localizations() const;
        /**
     * @brief Returns the `localizedInfoDictionary` property of `NSBundle`.
     * @details A dictionary with the keys from the bundle's localized property list. This property uses the preferred localization for the current user when determining which resources to include. If the preferred localization is not available, this property chooses the most appropriate localization found in the bundle.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> localized_info_dictionary() const;
        /**
     * @brief Returns the `mainBundle` property of `NSBundle`.
     * @details Returns the bundle object that contains the current executable. The main bundle lets you access the resources in the same directory as the currently running executable. For a running app or code running in a framework, the main bundle offers access to the app's bundle directory. This method may return a valid bundle object even for unbundled apps. It may also return 'nil' if the bundle object could not be created, so always check the return value.
     * @return The converted Objective-C result.
     */
        static Bundle main_bundle();
        /**
     * @brief Returns the `preferredLocalizations` property of `NSBundle`.
     * @details An ordered list of preferred localizations contained in the bundle. An array of \@c NSString objects containing language IDs for localizations in the bundle. The strings are ordered according to the user's language preferences and available localizations.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> preferred_localizations() const;
        /**
     * @brief Returns the `principalClass` property of `NSBundle`.
     * @details The bundle's principal class. This property is set after ensuring that the code containing the definition of the class is dynamically loaded. If the bundle encounters errors in loading or if it can't find the executable code file in the bundle directory, this property is \@c nil. The bundle obtains the principal class from the information dictionary using the key \@c NSPrincipalClass. For non-loadable bundles (applications and frameworks), if the principal class is not specified in the property list, this property is \@c nil.
     * @return The converted Objective-C result.
     */
        std::string principal_class() const;
        /**
     * @brief Returns the `privateFrameworksPath` property of `NSBundle`.
     * @details The full pathname of the bundle's subdirectory containing private frameworks. This property contains the appropriate path for modern application and framework bundles. This property may not contain a path for non-standard bundle formats or for some older bundle formats.
     * @return The converted Objective-C result.
     */
        std::string private_frameworks_path() const;
        /**
     * @brief Returns the `privateFrameworksURL` property of `NSBundle`.
     * @details The file URL of the bundle's subdirectory containing private frameworks. This property contains the appropriate path for modern application and framework bundles. This property may not be a URL for non-standard bundle formats or for some older bundle formats.
     * @return The converted Objective-C result.
     */
        URL private_frameworks_url() const;
        /**
     * @brief Returns the `resourcePath` property of `NSBundle`.
     * @details The full pathname of the bundle's subdirectory containing resources.
     * @return The converted Objective-C result.
     */
        std::string resource_path() const;
        /**
     * @brief Returns the `resourceURL` property of `NSBundle`.
     * @details The file URL of the bundle's subdirectory containing resource files. This property contains the appropriate path for modern application and framework bundles. This property may not contain a path for non-standard bundle formats or for some older bundle formats.
     * @return The converted Objective-C result.
     */
        URL resource_url() const;
        /**
     * @brief Returns the `sharedFrameworksPath` property of `NSBundle`.
     * @details The full pathname of the bundle's subdirectory containing shared frameworks. This property contains the appropriate path for modern application and framework bundles. This property may not contain a path for non-standard bundle formats or for some older bundle formats.
     * @return The converted Objective-C result.
     */
        std::string shared_frameworks_path() const;
        /**
     * @brief Returns the `sharedFrameworksURL` property of `NSBundle`.
     * @details The file URL of the receiver's subdirectory containing shared frameworks. This property contains the appropriate path for modern application and framework bundles. This property may not contain a URL for non-standard bundle formats or for some older bundle formats.
     * @return The converted Objective-C result.
     */
        URL shared_frameworks_url() const;
        /**
     * @brief Returns the `sharedSupportPath` property of `NSBundle`.
     * @details The full pathname of the bundle's subdirectory containing shared support files. This property contains the appropriate path for modern application and framework bundles. This property may not contain a path for non-standard bundle formats or for some older bundle formats.
     * @return The converted Objective-C result.
     */
        std::string shared_support_path() const;
        /**
     * @brief Returns the `sharedSupportURL` property of `NSBundle`.
     * @details The file URL of the bundle's subdirectory containing shared support files. This property contains the appropriate path for modern application and framework bundles. This property may not contain a path for non-standard bundle formats or for some older bundle formats.
     * @return The converted Objective-C result.
     */
        URL shared_support_url() const;
    };
}
