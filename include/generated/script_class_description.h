#pragma once

#include "generated/availability.h"
#include "generated/class_description.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class ScriptCommandDescription;

    /**
     * @brief C++ handle for the Objective-C class `NSScriptClassDescription` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ClassDescription.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScriptClassDescription script_class_description;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ScriptClassDescription script_class_description{};
     * auto made_0 = cocoon::ScriptClassDescription::class_description_for_class("text");
     * script_class_description.apple_event_code_for_key("text");
     * script_class_description.class_description_for_key("text");
     * script_class_description.has_ordered_to_many_relationship_for_key("text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsscriptclassdescription
     */
    class ScriptClassDescription : public ClassDescription
    {
    public:
        /// @brief Creates a new `NSScriptClassDescription` instance and returns a handle to it.
        explicit ScriptClassDescription(const std::string& suite_name, const std::string& class_name, const std::vector<std::pair<Object, Object>>& class_declaration);
        /// @brief Creates a new `NSScriptClassDescription` instance and returns a handle to it.
        explicit ScriptClassDescription();
        /// @brief Creates a null handle that refers to no native object.
        ScriptClassDescription(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScriptClassDescription(Adopt adopt);
        using ClassDescription::class_description_for_class;
        /**
         * @brief Calls `-[NSScriptClassDescription appleEventCodeForKey:]`.
         * @details Return the four character code that identifies the keyed attribute, to-one relationship, or to-many relationship in Apple events.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        unsigned int apple_event_code_for_key(const std::string& key) const;
        /**
         * @brief Calls `+[NSScriptClassDescription classDescriptionForClass:]`.
         * @details Return the class description for a class or, if it is not scriptable, the first superclass that is.
         * @param a_class Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static ScriptClassDescription class_description_for_class(const std::string& a_class);
        /**
         * @brief Calls `-[NSScriptClassDescription classDescriptionForKey:]`.
         * @details Return the class description for the keyed attribute, to-one relationship, or to-many relationship.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        ScriptClassDescription class_description_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSScriptClassDescription hasOrderedToManyRelationshipForKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool has_ordered_to_many_relationship_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSScriptClassDescription hasPropertyForKey:]`.
         * @details Return whether the described class has a property identified by the key, whether it's a to-many relationship, whether it's readable, or whether it's writable, respectively.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool has_property_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSScriptClassDescription hasReadablePropertyForKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool has_readable_property_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSScriptClassDescription hasWritablePropertyForKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool has_writable_property_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSScriptClassDescription isLocationRequiredToCreateForKey:]`.
         * @details Return YES if creation of objects for the relationship specified by the key, in containers of the class described by the receiver, requires an explicitly specified insertion location. Return NO otherwise. For example, NSCreateCommand uses this method to determine whether or not a specific Make command must have an at parameter.
         * @param to_many_relationship_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_location_required_to_create_for_key(const std::string& to_many_relationship_key) const;
        /**
         * @brief Calls `-[NSScriptClassDescription keyWithAppleEventCode:]`.
         * @details Given a four character code used to identify a property or element class in Apple events, return the key identifying the corresponding attribute, to-one relationship or to-many relationship.
         * @param apple_event_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string key_with_apple_event_code(unsigned int apple_event_code) const;
        /**
         * @brief Calls `-[NSScriptClassDescription matchesAppleEventCode:]`.
         * @details Return YES if the four character code identifies the described class in Apple events. Return NO otherwise.
         * @param apple_event_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool matches_apple_event_code(unsigned int apple_event_code) const;
        /**
         * @brief Calls `-[NSScriptClassDescription selectorForCommand:]`.
         * @details If the described class or one of its superclasses is explicitly declared to support the described command and the declaration includes a method name, return the selector for the class' handler method for the command. Return NULL otherwise.
         * @param command_description Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string selector_for_command(const ScriptCommandDescription& command_description) const;
        /**
         * @brief Calls `-[NSScriptClassDescription supportsCommand:]`.
         * @details Return YES if the described class or one of its superclasses is explicitly declared to support the described command, NO otherwise.
         * @param command_description Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool supports_command(const ScriptCommandDescription& command_description) const;
        /**
         * @brief Calls `-[NSScriptClassDescription typeForKey:]`.
         * @details Return the name of the declared type of the keyed attribute, to-one relationship, or to-many relationship.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string type_for_key(const std::string& key) const;
        /**
         * @brief Returns the `appleEventCode` property of `NSScriptClassDescription`.
         * @details Return the primary four character code used to identify the described class in Apple events.
         * @return The converted Objective-C result.
         */
        unsigned int apple_event_code() const;
        /**
         * @brief Returns the `className` property of `NSScriptClassDescription`.
         * @return The converted Objective-C result.
         */
        std::string class_name() const;
        /**
         * @brief Returns the `defaultSubcontainerAttributeKey` property of `NSScriptClassDescription`.
         * @details Return the value of the DefaultSubcontainerAttribute entry of the class declaration dictionary provided when the receiver was instantiated, or nil if there was no such entry.
         * @return The converted Objective-C result.
         */
        std::string default_subcontainer_attribute_key() const;
        /**
         * @brief Returns the `implementationClassName` property of `NSScriptClassDescription`.
         * @details Return the name of the Objective-C that implements the described scriptable class.
         * @return The converted Objective-C result.
         */
        std::string implementation_class_name() const;
        /**
         * @brief Returns the `suiteName` property of `NSScriptClassDescription`.
         * @details Return the suite name or class name provided at initialization time.
         * @return The converted Objective-C result.
         */
        std::string suite_name() const;
        /**
         * @brief Returns the `superclassDescription` property of `NSScriptClassDescription`.
         * @details Return the scripting class description of the superclass of the class described by the receiver.
         * @return The converted Objective-C result.
         */
        ScriptClassDescription superclass_description() const;
    };
}
