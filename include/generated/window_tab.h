#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSWindowTab` (AppKit).
     * @details This class encapsulates all the state and properties for a window when it exists in a tabbed window environment. See [NSWindow allowsAutomaticWindowTabbing] and [NSWindow tabbingIdentifier]. These properties can be set at anytime, but will only take effect when the window is shown in a tab.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::WindowTab window_tab;
     * window_tab.set_accessory_view(cocoon::View());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::WindowTab window_tab{};
     * window_tab.set_accessory_view(cocoon::View());
     * auto accessory_view = window_tab.accessory_view();
     * window_tab.set_attributed_title(cocoon::AttributedString());
     * auto attributed_title = window_tab.attributed_title();
     * window_tab.set_title("text");
     * auto title = window_tab.title();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nswindowtab
     */
    class WindowTab : public Object
    {
    public:
        /// @brief Creates a new `NSWindowTab` instance and returns a handle to it.
        explicit WindowTab();
        /// @brief Creates a null handle that refers to no native object.
        WindowTab(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit WindowTab(Adopt adopt);
        /**
         * @brief Returns the `accessoryView` property of `NSWindowTab`.
         * @details Get and set the accessory view for this window when it is in a tabbed window. translatesAutoresizingMaskIntoConstraints will automatically be set to NO on the view. Constraints can be created and activated to specify the view's width and height values. A constraint will automatically be added to y-center the view, and to right align the view.
         * @return The converted Objective-C result.
         */
        View accessory_view() const;
        /**
         * @brief Sets the `accessoryView` property of `NSWindowTab`.
         * @details Get and set the accessory view for this window when it is in a tabbed window. translatesAutoresizingMaskIntoConstraints will automatically be set to NO on the view. Constraints can be created and activated to specify the view's width and height values. A constraint will automatically be added to y-center the view, and to right align the view.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_accessory_view(const View& value) const;
        /**
         * @brief Returns the `attributedTitle` property of `NSWindowTab`.
         * @details The attributed string tab title for this window when in a tab. This value is only used when non-nil; otherwise the title is used. The attributedTitle will use the provided attributes that are explicitly given. Attributes not given, such as the font type, color and size, will default to the correct values for the window tab.
         * @return The converted Objective-C result.
         */
        AttributedString attributed_title() const;
        /**
         * @brief Sets the `attributedTitle` property of `NSWindowTab`.
         * @details The attributed string tab title for this window when in a tab. This value is only used when non-nil; otherwise the title is used. The attributedTitle will use the provided attributes that are explicitly given. Attributes not given, such as the font type, color and size, will default to the correct values for the window tab.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_attributed_title(const AttributedString& value) const;
        /**
         * @brief Returns the `title` property of `NSWindowTab`.
         * @details The tab title for this window when in a tab. By default it follows the window.title. You can override this by explicitly setting it to something custom. Setting it to nil will make it follow the window.title again.
         * @return The converted Objective-C result.
         */
        std::string title() const;
        /**
         * @brief Sets the `title` property of `NSWindowTab`.
         * @details The tab title for this window when in a tab. By default it follows the window.title. You can override this by explicitly setting it to something custom. Setting it to nil will make it follow the window.title again.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_title(const std::string& value) const;
        /**
         * @brief Returns the `toolTip` property of `NSWindowTab`.
         * @details The tool tip for this window when in a tab. By default, it is self.title but can be set to something custom. Setting it back to nil will make it follow self.title again.
         * @return The converted Objective-C result.
         */
        std::string tool_tip() const;
        /**
         * @brief Sets the `toolTip` property of `NSWindowTab`.
         * @details The tool tip for this window when in a tab. By default, it is self.title but can be set to something custom. Setting it back to nil will make it follow self.title again.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tool_tip(const std::string& value) const;
    };
}
