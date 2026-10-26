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
         * @details Return suitable reply data for the standard Get AETE Apple event, given the set of scripting suites currently registered.
         * @param language_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> aete_resource(const std::string& language_name) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry appleEventCodeForSuite:]`.
         * @details Return the four character code used to identify the named suite.
         * @param suite_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        unsigned int apple_event_code_for_suite(const std::string& suite_name) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry bundleForSuite:]`.
         * @details Return the bundle that contains the code that implements the named suite.
         * @param suite_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Bundle bundle_for_suite(const std::string& suite_name) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry classDescriptionWithAppleEventCode:]`.
         * @details Given a four character code used to identify a scriptable class in Apple events, return the class description.
         * @param apple_event_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        ScriptClassDescription class_description_with_apple_event_code(unsigned int apple_event_code) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry classDescriptionsInSuite:]`.
         * @details Return a dictionary containing the descriptions of all of the classes or commands in the named suite, keyed by class or comand name.
         * @param suite_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, ScriptClassDescription> class_descriptions_in_suite(const std::string& suite_name) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry commandDescriptionWithAppleEventClass:andAppleEventCode:]`.
         * @details Given the pair of four character codes used to identify a scripting command in Apple events, return the command description.
         * @param apple_event_class_code Argument converted to the Objective-C parameter of the same role.
         * @param apple_event_id_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        ScriptCommandDescription command_description_with_apple_event_class(unsigned int apple_event_class_code, unsigned int apple_event_id_code) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry commandDescriptionsInSuite:]`.
         * @param suite_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, ScriptCommandDescription> command_descriptions_in_suite(const std::string& suite_name) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry loadSuiteWithDictionary:fromBundle:]`.
         * @details Given a scripting suite declaration dictionary of the sort that is valid in .scriptSuite property list files, and a pointer to the bundle that contains the code that implements the suite, register class and command descriptions for the suite.
         * @param suite_declaration Argument converted to the Objective-C parameter of the same role.
         * @param bundle Argument converted to the Objective-C parameter of the same role.
         */
        void load_suite_with_dictionary(const std::vector<std::pair<Object, Object>>& suite_declaration, const Bundle& bundle) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry loadSuitesFromBundle:]`.
         * @details Given a bundle, register class and command descriptions from any .scriptSuite/.scriptTerminology resource files in the bundle. Redundant invocations of this method are ignored.
         * @param bundle Argument converted to the Objective-C parameter of the same role.
         */
        void load_suites_from_bundle(const Bundle& bundle) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry registerClassDescription:]`.
         * @details Register a scripting class or command description.
         * @param class_description Argument converted to the Objective-C parameter of the same role.
         */
        void register_class_description(const ScriptClassDescription& class_description) const;
        /**
         * @brief Calls `-[NSScriptSuiteRegistry registerCommandDescription:]`.
         * @param command_description Argument converted to the Objective-C parameter of the same role.
         */
        void register_command_description(const ScriptCommandDescription& command_description) const;
        /**
         * @brief Calls `+[NSScriptSuiteRegistry setSharedScriptSuiteRegistry:]`.
         * @param registry Argument converted to the Objective-C parameter of the same role.
         */
        static void set_shared_script_suite_registry(const ScriptSuiteRegistry& registry);
        /**
         * @brief Calls `+[NSScriptSuiteRegistry sharedScriptSuiteRegistry]`.
         * @details Get or set the program's single NSScriptSuiteRegistry.
         * @return The converted Objective-C result.
         */
        static ScriptSuiteRegistry shared_script_suite_registry();
        /**
         * @brief Calls `-[NSScriptSuiteRegistry suiteForAppleEventCode:]`.
         * @details Given a four character code used to identify a scripting suite, return the name of the suite.
         * @param apple_event_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string suite_for_apple_event_code(unsigned int apple_event_code) const;
        /**
         * @brief Returns the `suiteNames` property of `NSScriptSuiteRegistry`.
         * @details Return a list of all registered suite names.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> suite_names() const;
    };
}
