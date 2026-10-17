#pragma once

#include "generated/class_description.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class ScriptCommandDescription;

    /**
     * @brief C++ handle for the Objective-C class `NSScriptClassDescription` (Foundation).
     * @details A scriptable class that a macOS app supports. A scriptable application provides scriptability information that describes the commands and objects scripters can use in scripts that target the application. That includes information about the classes those scriptable objects are created from. An application's scriptability information is collected automatically by an instance of ''NSScriptSuiteRegistry''. The registry object creates an 'NSScriptClassDescription' for each class it finds and caches these objects in memory. Cocoa scripting uses registry information in handling scripting requests that target the application. A class description instance stores the name, attributes, relationships, and supported commands for a class. For example, a scriptable 'document' class for a drawing application might support attributes such as 'file' and 'file type', relationships such as collections of 'circles', 'rectangles', and 'lines', and commands such as 'align' and 'rotate'. As with many of the classes in Cocoa's built-in scripting support, your application may never need to directly work with instances of 'NSScriptClassDescription'. However, one case where you might need access to a class description is if you override 'objectSpecifier' in a scriptable class. For information on how to do this, see [Object Specifiers](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ScriptableCocoaApplications/SApps_object_specifiers/SAppsObjectSpecifiers.html\#//apple_ref/doc/uid/TP40002164-CH3) in [Cocoa Scripting Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ScriptableCocoaApplications/SApps_intro/SAppsIntro.html\#//apple_ref/doc/uid/TP40002164). Another case where your application may need access to class description information is if you override 'indicesOfObjectsByEvaluatingWithContainer:count:' in a specifier class. Although you can subclass 'NSScriptClassDescription', it is unlikely that you would need to do so, or even to create instances of it.
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
     * @details Returns the Apple event code for the specified attribute or relationship in the receiver. - Parameter key: The identifying key for an attribute or relationship of the receiver. - Returns: The four-character Apple event code associated with the attribute or relationship identified by 'key' in the receiver or, if none exists, in the class description for the receiver's superclass. Returns '0' if no such attribute or relationship is found.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        unsigned int apple_event_code_for_key(const std::string& key) const;
        /**
     * @brief Calls `+[NSScriptClassDescription classDescriptionForClass:]`.
     * @details Returns the class description for the specified class or, if it is not scriptable, for the first superclass that is. - Parameter aClass: The class whose description is needed. - Returns: The class description for the class specified by 'aClass' or, if that class isn't scriptable, the class description for the first superclass that is. Returns 'nil' if it doesn't find a scriptable class.
     * @param a_class Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ScriptClassDescription class_description_for_class(const std::string& a_class);
        /**
     * @brief Calls `-[NSScriptClassDescription classDescriptionForKey:]`.
     * @details Returns the class description instance for the class type of the specified attribute or relationship. - Parameter key: The identifying key for an attribute or relationship of the receiver. - Returns: The instance of 'NSScriptClassDescription' for the type of the attribute or relationship specified by 'key'. Returns 'nil' if no scriptable property corresponds to 'key'.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ScriptClassDescription class_description_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSScriptClassDescription hasOrderedToManyRelationshipForKey:]`.
     * @details Returns a Boolean value indicating whether the described class has an ordered to-many relationship identified by the specified key. - Parameter key: The identifying key for a property of the receiver. - Returns: 'true' if the described class has an ordered to-many relationship identified by the specified key; otherwise, 'false'.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool has_ordered_to_many_relationship_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSScriptClassDescription hasPropertyForKey:]`.
     * @details Returns a Boolean value indicating whether the described class has a property identified by the specified key. - Parameter key: The identifying key for a property of the receiver. - Returns: 'true' if the described class has a property identified by the specified key; otherwise, 'false'.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool has_property_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSScriptClassDescription hasReadablePropertyForKey:]`.
     * @details Returns a Boolean value indicating whether the described class has a readable property identified by the specified key. To determine if a property is read-only, invoke ''NSScriptClassDescription/hasWritableProperty(forKey:)''. - Parameter key: The identifying key for a property of the receiver. - Returns: 'true' if the described class has a readable property identified by the specified key; otherwise, 'false'.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool has_readable_property_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSScriptClassDescription hasWritablePropertyForKey:]`.
     * @details Returns a Boolean value indicating whether the described class has a writable property identified by the specified key. - Parameter key: The identifying key for a property of the receiver. - Returns: 'true' if the described class has a writable property identified by the specified key; otherwise, 'false'.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool has_writable_property_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSScriptClassDescription isLocationRequiredToCreateForKey:]`.
     * @details Returns a Boolean value indicating whether an insertion location must be specified when creating a new object in the specified to-many relationship of the receiver. A script command object that creates a new object in a to-many relationship needs to know whether an explicitly specified insertion location is required. It can get this information from an instance of 'NSScriptClassDescription'. For example, 'NSMakeCommand' uses this method to determine whether or not a specific 'make' AppleScript command must have an 'at' parameter. - Parameter toManyRelationshipKey: The key for the to-many relationship that may require an insertion location. - Returns: 'true' if an insertion location must be specified; otherwise, 'false'.
     * @param to_many_relationship_key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_location_required_to_create_for_key(const std::string& to_many_relationship_key) const;
        /**
     * @brief Calls `-[NSScriptClassDescription keyWithAppleEventCode:]`.
     * @details Given an Apple event code that identifies a property or element class, returns the key for the corresponding attribute, one-to-one relationship, or one-to-many relationship. - Parameter appleEventCode: An Apple event code that identifies a property or element class. - Returns: The key that corresponds to the property or element class identified by 'appleEventCode' in the receiver or, if none exists, in a class description in the receiver's superclasses. Returns 'nil' if it cannot find any such attribute or relationship.
     * @param apple_event_code Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string key_with_apple_event_code(unsigned int apple_event_code) const;
        /**
     * @brief Calls `-[NSScriptClassDescription matchesAppleEventCode:]`.
     * @details Returns a Boolean value indicating whether a primary or secondary Apple event code in the receiver matches the passed code. - Parameter appleEventCode: An Apple event code to compare against the receiver's primary or secondary codes. - Returns: 'true' if the receiver's primary four-character Apple event code or any of its secondary codes (its synonyms) matches 'appleEventCode'; otherwise, 'false'.
     * @param apple_event_code Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool matches_apple_event_code(unsigned int apple_event_code) const;
        /**
     * @brief Calls `-[NSScriptClassDescription selectorForCommand:]`.
     * @details Returns the selector associated with the receiver for the specified command description. If the described class or one of its superclasses is explicitly declared to support the described command and the declaration includes a method name, returns the selector for the class' handler method for the command. - Parameter commandDescription: A description for a script command, such as 'duplicate', 'make', or 'move'. Encapsulates the scriptability information for that command, such as its Objective-C selector, its argument names and types, and its return type (if any). - Returns: The selector from the receiver for the command specified by 'commandDescription'. Searches in the receiver first, then in any superclass. Returns 'NULL' if no matching selector is found.
     * @param command_description Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string selector_for_command(const ScriptCommandDescription& command_description) const;
        /**
     * @brief Calls `-[NSScriptClassDescription supportsCommand:]`.
     * @details Returns a Boolean value indicating whether the receiver or any superclass supports the specified command. - Parameter commandDescription: A description for a script command, such as 'duplicate', 'make', or 'move'. Encapsulates the scriptability information for that command, such as its Objective-C selector, its argument names and types, and its return type (if any). - Returns: 'true' if the receiver or the instance of 'NSScriptClassDescription' of any superclass of the receiver's class lists the command described by 'commandDescription' among its supported commands; otherwise, 'false'.
     * @param command_description Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool supports_command(const ScriptCommandDescription& command_description) const;
        /**
     * @brief Calls `-[NSScriptClassDescription typeForKey:]`.
     * @details Returns the name of the declared type of the attribute or relationship identified by the passed key. - Parameter key: The identifying key for an attribute, one-to-one relationship, or one-to-many relationship of the receiver. - Returns: The name of the declared type of the attribute or relationship identified by 'key'; for example, '"NSString"'. Searches in the receiver first, then in any superclass. Returns 'nil' if no match is found.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string type_for_key(const std::string& key) const;
        /**
     * @brief Returns the `appleEventCode` property of `NSScriptClassDescription`.
     * @details The Apple event code associated with the receiver's class. This is the primary four-character code used to identify the described class in Apple events.
     * @return The converted Objective-C result.
     */
        unsigned int apple_event_code() const;
        /**
     * @brief Returns the `className` property of `NSScriptClassDescription`.
     * @details The name of the class the receiver describes, as provided at initialization time. This may be either the human-readable name for the class -- that is, the name that is used in a script -- or the name of the Objective-C class that is instantiated to implement the class. To reliably obtain the implementation name, use ''NSScriptClassDescription/implementationClassName''.
     * @return The converted Objective-C result.
     */
        std::string class_name() const;
        /**
     * @brief Returns the `defaultSubcontainerAttributeKey` property of `NSScriptClassDescription`.
     * @details The value of the 'DefaultSubcontainerAttribute' entry of the class declaration dictionary provided when the receiver was instantiated. Returns 'nil' if there was no such entry.
     * @return The converted Objective-C result.
     */
        std::string default_subcontainer_attribute_key() const;
        /**
     * @brief Returns the `implementationClassName` property of `NSScriptClassDescription`.
     * @details The name of the Objective-C class instantiated to implement the scripting class. The name returned by the ''NSScriptClassDescription/className'' property for an instance of 'NSScriptClassDescription' resulting from an sdef class declaration is the human-readable name for the class. To obtain the name of the Objective-C class instantiated to implement the class, use this property.
     * @return The converted Objective-C result.
     */
        std::string implementation_class_name() const;
        /**
     * @brief Returns the `suiteName` property of `NSScriptClassDescription`.
     * @details The name of the receiver's suite. Within an application's scriptability information, named suites contain related sets of information.
     * @return The converted Objective-C result.
     */
        std::string suite_name() const;
        /**
     * @brief Returns the `superclassDescription` property of `NSScriptClassDescription`.
     * @details The class description instance for the superclass of the receiver's class. The instance of 'NSScriptClassDescription' that describes the superclass can be in the same suite as the receiver or in a different suite. Returns 'nil' if the class has no superclass.
     * @return The converted Objective-C result.
     */
        ScriptClassDescription superclass_description() const;
    };
}
