#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/toolbar_item.h"
#include "types.h"

namespace cocoon
{
    class Menu;

    /**
     * @brief C++ handle for the Objective-C class `NSMenuToolbarItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ToolbarItem.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MenuToolbarItem menu_toolbar_item;
     * menu_toolbar_item.set_menu(cocoon::Menu());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MenuToolbarItem menu_toolbar_item{};
     * menu_toolbar_item.set_menu(cocoon::Menu());
     * auto menu = menu_toolbar_item.menu();
     * menu_toolbar_item.set_shows_indicator(true);
     * auto shows_indicator = menu_toolbar_item.shows_indicator();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsmenutoolbaritem
     */
    class MenuToolbarItem : public ToolbarItem
    {
    public:
        /// @brief Creates a new `NSMenuToolbarItem` instance and returns a handle to it.
        explicit MenuToolbarItem();
        /// @brief Creates a null handle that refers to no native object.
        MenuToolbarItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MenuToolbarItem(Adopt adopt);
        /**
     * @brief Returns the `menu` property of `NSMenuToolbarItem`.
     * @details The menu presented to the user from the item. If the item has an action, an arrow will be shown to the user next to the button to access the menu. This will also be shown as the menuFormRepresentation unless otherwise set.
     * @return The converted Objective-C result.
     */
        Menu menu() const;
        /**
     * @brief Sets the `menu` property of `NSMenuToolbarItem`.
     * @details The menu presented to the user from the item. If the item has an action, an arrow will be shown to the user next to the button to access the menu. This will also be shown as the menuFormRepresentation unless otherwise set.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_menu(const Menu& value) const;
        /**
     * @brief Returns the `showsIndicator` property of `NSMenuToolbarItem`.
     * @details When YES, an indicator will be visible to the user as part of the control indicating that additional functionality is available. Defaults to YES.
     * @return The converted Objective-C result.
     */
        bool shows_indicator() const;
        /**
     * @brief Sets the `showsIndicator` property of `NSMenuToolbarItem`.
     * @details When YES, an indicator will be visible to the user as part of the control indicating that additional functionality is available. Defaults to YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_indicator(bool value) const;
    };
}
