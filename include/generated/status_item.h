#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Menu;
    class StatusBar;
    class StatusBarButton;

    /**
     * @brief C++ handle for the Objective-C class `NSStatusItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::StatusItem status_item;
     * status_item.set_autosave_name("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::StatusItem status_item{};
     * status_item.set_autosave_name("text");
     * auto autosave_name = status_item.autosave_name();
     * status_item.set_behavior(cocoon::StatusItemBehavior::RemovalAllowed);
     * auto behavior = status_item.behavior();
     * status_item.set_length(1);
     * auto length = status_item.length();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsstatusitem
     */
    class StatusItem : public Object
    {
    public:
        /// @brief Creates a new `NSStatusItem` instance and returns a handle to it.
        explicit StatusItem();
        /// @brief Creates a null handle that refers to no native object.
        StatusItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit StatusItem(Adopt adopt);
        /**
     * @brief Returns the `autosaveName` property of `NSStatusItem`.
     * @details Specifies a unique name for persisting visibility information. If none is specified, one is automatically chosen. Apps with multiple status bar items should set an autosave after creation. Setting to nil resets the automatically chosen name and clears saved information.
     * @return The converted Objective-C result.
     */
        std::string autosave_name() const;
        /**
     * @brief Sets the `autosaveName` property of `NSStatusItem`.
     * @details Specifies a unique name for persisting visibility information. If none is specified, one is automatically chosen. Apps with multiple status bar items should set an autosave after creation. Setting to nil resets the automatically chosen name and clears saved information.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_autosave_name(const std::string& value) const;
        /**
     * @brief Returns the `behavior` property of `NSStatusItem`.
     * @details Specifies the behavior of the status item.
     * @return The converted Objective-C result.
     */
        StatusItemBehavior behavior() const;
        /**
     * @brief Sets the `behavior` property of `NSStatusItem`.
     * @details Specifies the behavior of the status item.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_behavior(StatusItemBehavior value) const;
        /**
     * @brief Returns the `button` property of `NSStatusItem`.
     * @details The button that is displayed in the status bar. This is created automatically on the creation of the StatusItem. Behavior customization for the button, such as image, target/action, tooltip, can be set with this property.
     * @return The converted Objective-C result.
     */
        StatusBarButton button() const;
        /**
     * @brief Returns the `length` property of `NSStatusItem`.
     * @details The amount of space in the status bar that should be allocated to the receiver. \\c NSVariableStatusItemLength will adjust the length to the size of the status item's contents and \\c NSSquareStatusItemLength will keep the length the same as the status bar's height.
     * @return The converted Objective-C result.
     */
        double length() const;
        /**
     * @brief Sets the `length` property of `NSStatusItem`.
     * @details The amount of space in the status bar that should be allocated to the receiver. \\c NSVariableStatusItemLength will adjust the length to the size of the status item's contents and \\c NSSquareStatusItemLength will keep the length the same as the status bar's height.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_length(double value) const;
        /**
     * @brief Returns the `menu` property of `NSStatusItem`.
     * @details The drop down menu that is displayed when the status item is pressed or clicked.
     * @return The converted Objective-C result.
     */
        Menu menu() const;
        /**
     * @brief Sets the `menu` property of `NSStatusItem`.
     * @details The drop down menu that is displayed when the status item is pressed or clicked.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_menu(const Menu& value) const;
        /**
     * @brief Returns the `statusBar` property of `NSStatusItem`.
     * @details The status bar that the receiver is displayed in.
     * @return The converted Objective-C result.
     */
        StatusBar status_bar() const;
        /**
     * @brief Returns the `visible` property of `NSStatusItem`.
     * @details Specifies if the status item is currently visible in the status bar, even if it is obscured by the application menu. Defaults to YES. Persisted based on the -autosaveName. This is observable through KVO.
     * @return The converted Objective-C result.
     */
        bool is_visible() const;
        /**
     * @brief Sets the `visible` property of `NSStatusItem`.
     * @details Specifies if the status item is currently visible in the status bar, even if it is obscured by the application menu. Defaults to YES. Persisted based on the -autosaveName. This is observable through KVO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_visible(bool value) const;
    };
}
