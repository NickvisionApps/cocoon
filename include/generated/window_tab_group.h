#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Window;

    /**
     * @brief C++ handle for the Objective-C class `NSWindowTabGroup` (AppKit).
     * @details NSWindowTabGroup represents a group of windows that are shown together in one tab group. See NSWindow's tabGroup property.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::WindowTabGroup window_tab_group;
     * window_tab_group.set_overview_visible(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::WindowTabGroup window_tab_group{};
     * window_tab_group.set_overview_visible(true);
     * auto overview_visible = window_tab_group.is_overview_visible();
     * window_tab_group.set_selected_window(cocoon::Window());
     * auto selected_window = window_tab_group.selected_window();
     * window_tab_group.add_window(cocoon::Window());
     * window_tab_group.insert_window(cocoon::Window(), 1);
     * window_tab_group.remove_window(cocoon::Window());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nswindowtabgroup
     */
    class WindowTabGroup : public Object
    {
    public:
        /// @brief Creates a new `NSWindowTabGroup` instance and returns a handle to it.
        explicit WindowTabGroup();
        /// @brief Creates a null handle that refers to no native object.
        WindowTabGroup(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit WindowTabGroup(Adopt adopt);
        /**
     * @brief Calls `-[NSWindowTabGroup addWindow:]`.
     * @details Allows adding a new window to this tab group. Adding a window will first remove it from its existing tab window group. A window can implicitly be removed by ordering it out, or it can be explicitly be removed by calling removeWindow.
     * @param window Argument converted to the Objective-C parameter of the same role.
     */
        void add_window(const Window& window) const;
        /**
     * @brief Calls `-[NSWindowTabGroup insertWindow:atIndex:]`.
     * @param window Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_window(const Window& window, std::int64_t index) const;
        /**
     * @brief Calls `-[NSWindowTabGroup removeWindow:]`.
     * @param window Argument converted to the Objective-C parameter of the same role.
     */
        void remove_window(const Window& window) const;
        /**
     * @brief Returns the `identifier` property of `NSWindowTabGroup`.
     * @details The identifier for this group; all windows in the group will have the same identifier.
     * @return The converted Objective-C result.
     */
        std::string identifier() const;
        /**
     * @brief Returns the `overviewVisible` property of `NSWindowTabGroup`.
     * @details Determines if the Tab Picker / Tab Overview UI is visible, and can be set to make it explicitly visible or hidden. KVO compliant and can be observed so that UI can be updated or disabled when the tab overview is visible.
     * @return The converted Objective-C result.
     */
        bool is_overview_visible() const;
        /**
     * @brief Sets the `overviewVisible` property of `NSWindowTabGroup`.
     * @details Determines if the Tab Picker / Tab Overview UI is visible, and can be set to make it explicitly visible or hidden. KVO compliant and can be observed so that UI can be updated or disabled when the tab overview is visible.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_overview_visible(bool value) const;
        /**
     * @brief Returns the `selectedWindow` property of `NSWindowTabGroup`.
     * @details Returns the current window that is selected. This is KVO compliant. Assignments can only work for a window in the tab group, otherwise an exception will be thrown.
     * @return The converted Objective-C result.
     */
        Window selected_window() const;
        /**
     * @brief Sets the `selectedWindow` property of `NSWindowTabGroup`.
     * @details Returns the current window that is selected. This is KVO compliant. Assignments can only work for a window in the tab group, otherwise an exception will be thrown.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selected_window(const Window& value) const;
        /**
     * @brief Returns the `tabBarVisible` property of `NSWindowTabGroup`.
     * @details Returns YES when the tab bar is visible.
     * @return The converted Objective-C result.
     */
        bool is_tab_bar_visible() const;
        /**
     * @brief Returns the `windows` property of `NSWindowTabGroup`.
     * @details Returns the entire group (stack) of windows that are all visually shown together in one virtual tabbed window and associated with this particular window tab group. Operations can then be done on each window, as necessary. For instance, iterating over each window in the group and calling performClose: will close the entire stack. The order of items in the array is the same order as the tabs visually shown (leading to trailing). This property is KVO compliant
     * @return The converted Objective-C result.
     */
        std::vector<Window> windows() const;
    };
}
