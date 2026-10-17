#pragma once

#include "generated/controller.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class UserDefaults;

    /**
     * @brief C++ handle for the Objective-C class `NSUserDefaultsController` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Controller.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UserDefaultsController user_defaults_controller;
     * user_defaults_controller.set_applies_immediately(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::UserDefaultsController user_defaults_controller{};
     * user_defaults_controller.set_applies_immediately(true);
     * auto applies_immediately = user_defaults_controller.applies_immediately();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsuserdefaultscontroller
     */
    class UserDefaultsController : public Controller
    {
    public:
        /// @brief Creates a new `NSUserDefaultsController` instance and returns a handle to it.
        explicit UserDefaultsController(const UserDefaults& defaults, const std::map<std::string, Object>& initial_values);
        /// @brief Creates a new `NSUserDefaultsController` instance and returns a handle to it.
        explicit UserDefaultsController();
        /// @brief Creates a null handle that refers to no native object.
        UserDefaultsController(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UserDefaultsController(Adopt adopt);
        /**
     * @brief Calls `-[NSUserDefaultsController revert:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void revert(const Object& sender) const;
        /**
     * @brief Calls `-[NSUserDefaultsController revertToInitialValues:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void revert_to_initial_values(const Object& sender) const;
        /**
     * @brief Calls `-[NSUserDefaultsController save:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void save(const Object& sender) const;
        /**
     * @brief Returns the `appliesImmediately` property of `NSUserDefaultsController`.
     * @return The converted Objective-C result.
     */
        bool applies_immediately() const;
        /**
     * @brief Sets the `appliesImmediately` property of `NSUserDefaultsController`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_applies_immediately(bool value) const;
        /**
     * @brief Returns the `defaults` property of `NSUserDefaultsController`.
     * @return The converted Objective-C result.
     */
        UserDefaults defaults() const;
        /**
     * @brief Returns the `hasUnappliedChanges` property of `NSUserDefaultsController`.
     * @return The converted Objective-C result.
     */
        bool has_unapplied_changes() const;
        /**
     * @brief Returns the `initialValues` property of `NSUserDefaultsController`.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> initial_values() const;
        /**
     * @brief Sets the `initialValues` property of `NSUserDefaultsController`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_initial_values(const std::map<std::string, Object>& value) const;
        /**
     * @brief Returns the `sharedUserDefaultsController` property of `NSUserDefaultsController`.
     * @return The converted Objective-C result.
     */
        static UserDefaultsController shared_user_defaults_controller();
        /**
     * @brief Returns the `values` property of `NSUserDefaultsController`.
     * @return The converted Objective-C result.
     */
        Object values() const;
    };
}
