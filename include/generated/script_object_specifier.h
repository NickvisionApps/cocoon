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
         * @param container Argument converted to the Objective-C parameter of the same role.
         * @param count Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t* indices_of_objects_by_evaluating_with_container(const Object& container, std::int64_t* count) const;
        /**
         * @brief Calls `+[NSScriptObjectSpecifier objectSpecifierWithDescriptor:]`.
         * @details Given a typeObjectSpecifier Apple event descriptor, create and return an object specifier, or nil for failure. If this is invoked and fails during the execution of a script command, information about the error that caused the failure is recorded in [NSScriptCommand currentCommand].
         * @param descriptor Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static ScriptObjectSpecifier object_specifier_with_descriptor(const AppleEventDescriptor& descriptor);
        /**
         * @brief Calls `-[NSScriptObjectSpecifier objectsByEvaluatingWithContainers:]`.
         * @param containers Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object objects_by_evaluating_with_containers(const Object& containers) const;
        /**
         * @brief Returns the `childSpecifier` property of `NSScriptObjectSpecifier`.
         * @return The converted Objective-C result.
         */
        ScriptObjectSpecifier child_specifier() const;
        /**
         * @brief Sets the `childSpecifier` property of `NSScriptObjectSpecifier`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_child_specifier(const ScriptObjectSpecifier& value) const;
        /**
         * @brief Returns the `containerClassDescription` property of `NSScriptObjectSpecifier`.
         * @return The converted Objective-C result.
         */
        ScriptClassDescription container_class_description() const;
        /**
         * @brief Sets the `containerClassDescription` property of `NSScriptObjectSpecifier`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_container_class_description(const ScriptClassDescription& value) const;
        /**
         * @brief Returns the `containerIsObjectBeingTested` property of `NSScriptObjectSpecifier`.
         * @return The converted Objective-C result.
         */
        bool container_is_object_being_tested() const;
        /**
         * @brief Sets the `containerIsObjectBeingTested` property of `NSScriptObjectSpecifier`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_container_is_object_being_tested(bool value) const;
        /**
         * @brief Returns the `containerIsRangeContainerObject` property of `NSScriptObjectSpecifier`.
         * @return The converted Objective-C result.
         */
        bool container_is_range_container_object() const;
        /**
         * @brief Sets the `containerIsRangeContainerObject` property of `NSScriptObjectSpecifier`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_container_is_range_container_object(bool value) const;
        /**
         * @brief Returns the `containerSpecifier` property of `NSScriptObjectSpecifier`.
         * @return The converted Objective-C result.
         */
        ScriptObjectSpecifier container_specifier() const;
        /**
         * @brief Sets the `containerSpecifier` property of `NSScriptObjectSpecifier`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_container_specifier(const ScriptObjectSpecifier& value) const;
        /**
         * @brief Returns the `descriptor` property of `NSScriptObjectSpecifier`.
         * @details Return an Apple event descriptor that represents the receiver. If the receiver was created with +objectSpecifierWithDescriptor: that passed-in descriptor is returned. Otherwise a new one is created and returned (autoreleased, of course).
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor descriptor() const;
        /**
         * @brief Returns the `evaluationErrorNumber` property of `NSScriptObjectSpecifier`.
         * @return The converted Objective-C result.
         */
        std::int64_t evaluation_error_number() const;
        /**
         * @brief Sets the `evaluationErrorNumber` property of `NSScriptObjectSpecifier`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_evaluation_error_number(std::int64_t value) const;
        /**
         * @brief Returns the `evaluationErrorSpecifier` property of `NSScriptObjectSpecifier`.
         * @return The converted Objective-C result.
         */
        ScriptObjectSpecifier evaluation_error_specifier() const;
        /**
         * @brief Returns the `key` property of `NSScriptObjectSpecifier`.
         * @return The converted Objective-C result.
         */
        std::string key() const;
        /**
         * @brief Sets the `key` property of `NSScriptObjectSpecifier`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_key(const std::string& value) const;
        /**
         * @brief Returns the `keyClassDescription` property of `NSScriptObjectSpecifier`.
         * @return The converted Objective-C result.
         */
        ScriptClassDescription key_class_description() const;
        /**
         * @brief Returns the `objectsByEvaluatingSpecifier` property of `NSScriptObjectSpecifier`.
         * @return The converted Objective-C result.
         */
        Object objects_by_evaluating_specifier() const;
    };
}
