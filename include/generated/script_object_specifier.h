#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AppleEventDescriptor;
    class ScriptClassDescription;

    /**
     * @brief C++ handle for the Objective-C class `NSScriptObjectSpecifier` (Foundation).
     * @details An abstract class used to represent natural language expressions. 'NSScriptObjectSpecifier' is the abstract superclass for classes that instantiate objects called "object specifiers." An object specifier represents an AppleScript reference form, which is a natural-language expression such as 'words 10 through 20' or 'front document' or 'words whose color is red'. The scripting system maps these words or phrases to attributes and relationships of scriptable objects. A reference form rarely occurs in isolation; usually a script statement consists of a series of reference forms preceded by a command and typically connected to each other by 'of', such as: '''objc get words whose color is blue of paragraph 10 of front document ''' The expression 'words whose color is blue of paragraph 10 of front document' specifies a location in the application's AppleScript object model—the objects the application makes available to scripters. The classes of objects in the object model often closely match the classes of actual objects in the application, but they are not required to. An object specifier locates objects in the running application that correspond to the specified object model objects. Your application typically creates object specifiers when it implements the 'objectSpecifier' method for its scriptable classes. That method is defined by the NSScriptObjectSpecifiers protocol. It is unlikely that you would ever need to create your own subclass of 'NSScriptObjectSpecifier'; the set of valid AppleScript reference forms is determined by Apple Computer and object specifier classes are already implemented for this set. If for some reason you do need to create a subclass, you must override the primitive method ''indicesOfObjectsByEvaluating(withContainer:count:)'' to return indices to the elements within the container whose values are matched with the child specifier's key. In addition, you probably need to declare any special instance variables and implement an initializer that invokes super's designated initializer, ''init(containerClassDescription:containerSpecifier:key:)'', and initializes these variables. For a comprehensive treatment of object specifiers, including sample code, see [Object Specifiers](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ScriptableCocoaApplications/SApps_object_specifiers/SAppsObjectSpecifiers.html\#//apple_ref/doc/uid/TP40002164-CH3) in [Cocoa Scripting Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ScriptableCocoaApplications/SApps_intro/SAppsIntro.html\#//apple_ref/doc/uid/TP40002164).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScriptObjectSpecifier script_object_specifier;
     * script_object_specifier.set_child_specifier(cocoon::ScriptObjectSpecifier());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ScriptObjectSpecifier script_object_specifier{};
     * script_object_specifier.set_child_specifier(cocoon::ScriptObjectSpecifier());
     * auto child_specifier = script_object_specifier.child_specifier();
     * script_object_specifier.set_container_class_description(cocoon::ScriptClassDescription());
     * auto container_class_description = script_object_specifier.container_class_description();
     * script_object_specifier.set_container_is_object_being_tested(true);
     * auto container_is_object_being_tested = script_object_specifier.container_is_object_being_tested();
     * auto made_0 = cocoon::ScriptObjectSpecifier::object_specifier_with_descriptor(cocoon::AppleEventDescriptor());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsscriptobjectspecifier
     */
    class ScriptObjectSpecifier : public Object
    {
    public:
        /// @brief Creates a new `NSScriptObjectSpecifier` instance and returns a handle to it.
        explicit ScriptObjectSpecifier(const ScriptClassDescription& class_desc, const ScriptObjectSpecifier& container, const std::string& property);
        /// @brief Creates a new `NSScriptObjectSpecifier` instance and returns a handle to it.
        explicit ScriptObjectSpecifier(const ScriptObjectSpecifier& container, const std::string& property);
        /// @brief Creates a new `NSScriptObjectSpecifier` instance and returns a handle to it.
        explicit ScriptObjectSpecifier();
        /// @brief Creates a null handle that refers to no native object.
        ScriptObjectSpecifier(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScriptObjectSpecifier(Adopt adopt);
        /**
         * @brief Calls `-[NSScriptObjectSpecifier indicesOfObjectsByEvaluatingWithContainer:count:]`.
         * @details Returns the indices of the specified objects in the container.
         * @param container Argument converted to the Objective-C parameter of the same role.
         * @param count Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t* indices_of_objects_by_evaluating_with_container(const Object& container, std::int64_t* count) const;
        /**
         * @brief Calls `+[NSScriptObjectSpecifier objectSpecifierWithDescriptor:]`.
         * @details Given a 'typeObjectSpecifier' Apple event descriptor, creates and returns an object specifier. Returns 'nil' on failure. If this is invoked and fails during the execution of a script command, information about the error that caused the failure is recorded in '[NSScriptCommand currentCommand]'.
         * @param descriptor Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static ScriptObjectSpecifier object_specifier_with_descriptor(const AppleEventDescriptor& descriptor);
        /**
         * @brief Calls `-[NSScriptObjectSpecifier objectsByEvaluatingWithContainers:]`.
         * @details Returns the specified objects from the given containers.
         * @param containers Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object objects_by_evaluating_with_containers(const Object& containers) const;
        /**
         * @brief Returns the `childSpecifier` property of `NSScriptObjectSpecifier`.
         * @details The child specifier of this specifier.
         * @return The converted Objective-C result.
         */
        ScriptObjectSpecifier child_specifier() const;
        /**
         * @brief Sets the `childSpecifier` property of `NSScriptObjectSpecifier`.
         * @details The child specifier of this specifier.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_child_specifier(const ScriptObjectSpecifier& value) const;
        /**
         * @brief Returns the `containerClassDescription` property of `NSScriptObjectSpecifier`.
         * @details The class description for the container.
         * @return The converted Objective-C result.
         */
        ScriptClassDescription container_class_description() const;
        /**
         * @brief Sets the `containerClassDescription` property of `NSScriptObjectSpecifier`.
         * @details The class description for the container.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_container_class_description(const ScriptClassDescription& value) const;
        /**
         * @brief Returns the `containerIsObjectBeingTested` property of `NSScriptObjectSpecifier`.
         * @details A Boolean value that indicates whether the container is the object currently being tested by an 'NSWhoseSpecifier'.
         * @return The converted Objective-C result.
         */
        bool container_is_object_being_tested() const;
        /**
         * @brief Sets the `containerIsObjectBeingTested` property of `NSScriptObjectSpecifier`.
         * @details A Boolean value that indicates whether the container is the object currently being tested by an 'NSWhoseSpecifier'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_container_is_object_being_tested(bool value) const;
        /**
         * @brief Returns the `containerIsRangeContainerObject` property of `NSScriptObjectSpecifier`.
         * @details A Boolean value that indicates whether the container is the container for the current range specifier being evaluated.
         * @return The converted Objective-C result.
         */
        bool container_is_range_container_object() const;
        /**
         * @brief Sets the `containerIsRangeContainerObject` property of `NSScriptObjectSpecifier`.
         * @details A Boolean value that indicates whether the container is the container for the current range specifier being evaluated.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_container_is_range_container_object(bool value) const;
        /**
         * @brief Returns the `containerSpecifier` property of `NSScriptObjectSpecifier`.
         * @details The container specifier of this specifier.
         * @return The converted Objective-C result.
         */
        ScriptObjectSpecifier container_specifier() const;
        /**
         * @brief Sets the `containerSpecifier` property of `NSScriptObjectSpecifier`.
         * @details The container specifier of this specifier.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_container_specifier(const ScriptObjectSpecifier& value) const;
        /**
         * @brief Returns the `descriptor` property of `NSScriptObjectSpecifier`.
         * @details An Apple event descriptor that represents this specifier.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor descriptor() const;
        /**
         * @brief Returns the `evaluationErrorNumber` property of `NSScriptObjectSpecifier`.
         * @details The error number from the most recent evaluation.
         * @return The converted Objective-C result.
         */
        std::int64_t evaluation_error_number() const;
        /**
         * @brief Sets the `evaluationErrorNumber` property of `NSScriptObjectSpecifier`.
         * @details The error number from the most recent evaluation.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_evaluation_error_number(std::int64_t value) const;
        /**
         * @brief Returns the `evaluationErrorSpecifier` property of `NSScriptObjectSpecifier`.
         * @details The specifier in which an evaluation error occurred.
         * @return The converted Objective-C result.
         */
        ScriptObjectSpecifier evaluation_error_specifier() const;
        /**
         * @brief Returns the `key` property of `NSScriptObjectSpecifier`.
         * @details The name of the key in the container object to be accessed by this specifier.
         * @return The converted Objective-C result.
         */
        std::string key() const;
        /**
         * @brief Sets the `key` property of `NSScriptObjectSpecifier`.
         * @details The name of the key in the container object to be accessed by this specifier.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_key(const std::string& value) const;
        /**
         * @brief Returns the `keyClassDescription` property of `NSScriptObjectSpecifier`.
         * @details The class description for the keyed objects.
         * @return The converted Objective-C result.
         */
        ScriptClassDescription key_class_description() const;
        /**
         * @brief Returns the `objectsByEvaluatingSpecifier` property of `NSScriptObjectSpecifier`.
         * @details The actual objects represented by this specifier.
         * @return The converted Objective-C result.
         */
        Object objects_by_evaluating_specifier() const;
    };
}
