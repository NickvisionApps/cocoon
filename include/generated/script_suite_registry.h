#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Bundle;
    class ScriptClassDescription;
    class ScriptCommandDescription;

    /**
     * @brief C++ handle for the Objective-C class `NSScriptSuiteRegistry` (Foundation).
     * @details The top-level repository of scriptability information for an app at runtime. Scriptability information specifies the terminology available for use in scripts that target an application. It also provides information, used by AppleScript and by Cocoa, about how support for that terminology is implemented in the application. This information includes descriptions of the scriptable object classes in an application and of the commands the application supports. There are two standard formats for supplying scriptability information: the older script suite format, consisting of a script suite file and one or more script terminology files, and the newer scripting definition (or sdef) format, consisting of a single sdef file. There is one instance of 'NSScriptSuiteRegistry' per scriptable application. This registry object collects scriptability information when the application first needs to respond to an Apple event for which Cocoa hasn't installed a default event handler. It then creates one instance of ''NSScriptClassDescription'' for each object class and one instance of ''NSScriptCommandDescription'' for each command class, and installs a command handler for each command. When a user executes an AppleScript script, Apple events are sent to the targeted application. Using the information stored in the registry object, Cocoa automatically converts incoming Apple events into script commands (based on ''NSScriptCommand'' or a subclass) that manipulate objects in the application. The public methods of 'NSScriptSuiteRegistry' are used primarily by Cocoa's built-in scripting support. You should not need to create a subclass of 'NSScriptSuiteRegistry'. For information on scriptability information formats, loading of scriptability information, and related topics, see "Scriptability Information" in [Overview of Cocoa Support for Scriptable Applications](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ScriptableCocoaApplications/SApps_about_apps/SAppsAboutApps.html\#//apple_ref/doc/uid/TP40001976) in [Cocoa Scripting Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ScriptableCocoaApplications/SApps_intro/SAppsIntro.html\#//apple_ref/doc/uid/TP40002164).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScriptSuiteRegistry script_suite_registry;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ScriptSuiteRegistry script_suite_registry{};
     * auto made_0 = cocoon::ScriptSuiteRegistry::shared_script_suite_registry();
     * script_suite_registry.aete_resource("text");
     * script_suite_registry.apple_event_code_for_suite("text");
     * script_suite_registry.bundle_for_suite("text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsscriptsuiteregistry
     */
    class ScriptSuiteRegistry : public Object
    {
    public:
        /// @brief Creates a new `NSScriptSuiteRegistry` instance and returns a handle to it.
        explicit ScriptSuiteRegistry();
        /// @brief Creates a null handle that refers to no native object.
        ScriptSuiteRegistry(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScriptSuiteRegistry(Adopt adopt);
        /**
         * @brief Calls `-[NSScriptSuiteRegistry aeteResource:]`.
         * @details Returns an 'NSData' object that contains data in ''aete'' resource format describing the scriptability information currently known to the application. This method is typically invoked to implement the 'get aete' Apple event for an application that provides scriptability information in the script suite format. The 'languageName' argument is the name of a language for which a localized resource directory (such as 'English.lproj') exists. This language indication specifies the set of '.scriptTerminology' files to be used to generate the data. 'NSScriptSuiteRegistry' does not create an ''aete'' resource unless this method is called. - Parameter languageName: The name of a language for which localized script terminology files exist. - Returns: Data in ''aete'' resource format, or 'nil' if the data cannot be generated.
         * @param language_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> aete_resource(const std::string& language_name) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry appleEventCodeForSuite:]`.
         * @details Returns the Apple event code associated with the suite named 'suiteName', such as ''core'' for the Core suite. - Parameter suiteName: The name of a scripting suite. - Returns: The four-character code used to identify the named suite.
         * @param suite_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        unsigned int apple_event_code_for_suite(const std::string& suite_name) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry bundleForSuite:]`.
         * @details Returns the bundle containing the suite-definition property list (extension '.scriptSuite') identified by 'suiteName'. - Parameter suiteName: The name of a scripting suite. - Returns: The bundle that contains the code that implements the named suite.
         * @param suite_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Bundle bundle_for_suite(const std::string& suite_name) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry classDescriptionWithAppleEventCode:]`.
         * @details Returns the class description associated with the given four-character Apple event code, 'appleEventCode'. Overriding behavior is important here. Multiple classes can have the same code if the classes have an uninterrupted linear inheritance from one another. For example, if class B is a subclass of A and class C is a subclass of B, and all three classes have the same four-character Apple event code, then this method returns the class description for class C. - Parameter appleEventCode: A four-character code used to identify a scriptable class in Apple events. - Returns: The class description, or 'nil' if no class matches.
         * @param apple_event_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        ScriptClassDescription class_description_with_apple_event_code(unsigned int apple_event_code) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry classDescriptionsInSuite:]`.
         * @details Returns the class descriptions contained in the suite identified by 'suiteName'. Each class description (instance of ''NSScriptClassDescription'') in the returned dictionary is identified by class name. - Parameter suiteName: The name of a scripting suite. - Returns: A dictionary containing the descriptions of all of the classes in the named suite, keyed by class name.
         * @param suite_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, ScriptClassDescription> class_descriptions_in_suite(const std::string& suite_name) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry commandDescriptionWithAppleEventClass:andAppleEventCode:]`.
         * @details Returns the command description identified by a suite's four-character Apple event code of the class and the four-character Apple event code of the command. - Parameters: - appleEventClassCode: The four-character Apple event class code. - appleEventIDCode: The four-character Apple event ID code. - Returns: The command description, or 'nil' if no command matches.
         * @param apple_event_class_code Argument converted to the Objective-C parameter of the same role.
         * @param apple_event_id_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        ScriptCommandDescription command_description_with_apple_event_class(unsigned int apple_event_class_code, unsigned int apple_event_id_code) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry commandDescriptionsInSuite:]`.
         * @details Returns the command descriptions contained in the suite identified by 'suiteName'. Each command description (instance of ''NSScriptCommandDescription'') in the returned dictionary is identified by command name. - Parameter suiteName: The name of a scripting suite. - Returns: A dictionary containing the descriptions of all of the commands in the named suite, keyed by command name.
         * @param suite_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, ScriptCommandDescription> command_descriptions_in_suite(const std::string& suite_name) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry loadSuiteWithDictionary:fromBundle:]`.
         * @details Loads the suite definition encapsulated in 'suiteDeclaration'; previously, this suite definition was parsed from a '.scriptSuite' property list contained in a framework or in 'bundle'. The method extracts information from the dictionary and caches it in various internal collection objects. If keys are missing or values are of the wrong type, it logs messages to the console. It also registers class descriptions and command descriptions. In registering a class description, it invokes the ''NSClassDescription'' class method ''NSClassDescription/register(:for:)''. In registering a command description, it arranges for the Apple event translator to handle incoming Apple events that represent the defined commands. This method is invoked when the shared instance is initialized and when bundles are loaded at runtime. Prior to invoking it, 'NSScriptSuiteRegistry' creates the dictionary argument from the '.scriptSuite' property list. If you invoke this method in your code, you should try to do it before the application receives its first Apple event. - Parameters: - suiteDeclaration: A scripting suite declaration dictionary of the sort that is valid in '.scriptSuite' property list files. - bundle: The bundle that contains the code that implements the suite.
         * @param suite_declaration Argument converted to the Objective-C parameter of the same role.
         * @param bundle Argument converted to the Objective-C parameter of the same role.
         */
        void load_suite_with_dictionary(const std::vector<std::pair<Object, Object>>& suite_declaration, const Bundle& bundle) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry loadSuitesFromBundle:]`.
         * @details Loads the suite definitions in the specified bundle, invoking ''NSScriptSuiteRegistry/loadSuite(with:from:)'' for each suite found. If errors occur while the method is parsing a suite-definition file, the method logs error messages to the console. Redundant invocations of this method are ignored. - Parameter bundle: The bundle from which to load '.scriptSuite'/'.scriptTerminology' resource files.
         * @param bundle Argument converted to the Objective-C parameter of the same role.
         */
        void load_suites_from_bundle(const Bundle& bundle) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry registerClassDescription:]`.
         * @details Registers class description 'classDescription' for use by Cocoa's built-in scripting support by storing it in a per-suite internal dictionary under the class name. - Parameter classDescription: The scripting class description to register.
         * @param class_description Argument converted to the Objective-C parameter of the same role.
         */
        void register_class_description(const ScriptClassDescription& class_description) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry registerCommandDescription:]`.
         * @details Registers command description 'commandDescription' for use by Cocoa's built-in scripting support by storing it in a per-suite internal dictionary under the command name. Also registers with the single, shared instance of ''NSAppleEventManager'' to handle incoming Apple events that should be handled by the command. - Parameter commandDescription: The scripting command description to register.
         * @param command_description Argument converted to the Objective-C parameter of the same role.
         */
        void register_command_description(const ScriptCommandDescription& command_description) const;
        /**
         * @brief Calls `+[NSScriptSuiteRegistry setSharedScriptSuiteRegistry:]`.
         * @details Sets the single, shared instance of 'NSScriptSuiteRegistry' to 'registry'.
         * @param registry Argument converted to the Objective-C parameter of the same role.
         */
        static void set_shared_script_suite_registry(const ScriptSuiteRegistry& registry);
        /**
         * @brief Calls `+[NSScriptSuiteRegistry sharedScriptSuiteRegistry]`.
         * @details Returns the single, shared instance of 'NSScriptSuiteRegistry', creating it first if it doesn't exist. If it creates an instance, and if the application provides scriptability information in the script suite format, the method loads suite definitions in all frameworks and other bundles that the application currently imports or includes; if information is provided in the sdef format, the method loads information only from the specified sdef file. If in reading scriptability information an exception is raised because of parsing errors, it handles the exception by printing a line of information to the console.
         * @return The converted Objective-C result.
         */
        static ScriptSuiteRegistry shared_script_suite_registry();
        /**
         * @brief Calls `-[NSScriptSuiteRegistry suiteForAppleEventCode:]`.
         * @details Returns the name of the suite definition associated with the given four-character Apple event code, 'appleEventCode'. - Parameter appleEventCode: A four-character code used to identify a scripting suite. - Returns: The name of the suite, or 'nil' if no suite matches.
         * @param apple_event_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string suite_for_apple_event_code(unsigned int apple_event_code) const;
        /**
         * @brief Returns the `suiteNames` property of `NSScriptSuiteRegistry`.
         * @details The names of the suite definitions currently loaded by the application.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> suite_names() const;
    };
}
