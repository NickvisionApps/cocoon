#pragma once

#include "generated/availability.h"

#ifdef COCOON_MACOS_27
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class Color;

    /**
     * @brief C++ handle for the Objective-C class `NSRefreshController` (AppKit).
     * @details A controller that provides pull-to-refresh functionality for scroll views. 'NSRefreshController' enables users to trigger refresh operations by pulling down on scrollable content. Add a refresh controller to an 'NSScrollView' to provide this functionality. Configure the target and action to handle refresh events.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::RefreshController refresh_controller;
     * refresh_controller.set_action("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::RefreshController refresh_controller{};
     * refresh_controller.set_action("text");
     * auto action = refresh_controller.action();
     * refresh_controller.set_attributed_title(cocoon::AttributedString());
     * auto attributed_title = refresh_controller.attributed_title();
     * refresh_controller.set_tint_color(cocoon::Color());
     * auto tint_color = refresh_controller.tint_color();
     * refresh_controller.begin_refreshing();
     * refresh_controller.end_refreshing();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsrefreshcontroller
     */
    class RefreshController : public Object
    {
    public:
        /// @brief Creates a new `NSRefreshController` instance and returns a handle to it.
        explicit RefreshController();
        /// @brief Creates a null handle that refers to no native object.
        RefreshController(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit RefreshController(Adopt adopt);
#ifdef COCOON_MACOS_27
        /**
         * @brief Calls `-[NSRefreshController beginRefreshing]`.
         * @details Tells the refresh controller that a refresh operation has begun. Call this method to programmatically start a refresh operation. The refresh controller enters the refreshing state and displays its activity indicator. This is typically used when you want to show a refresh initiated by something other than user interaction.
         */
        void begin_refreshing() const;
#endif

#ifdef COCOON_MACOS_27
        /**
         * @brief Calls `-[NSRefreshController endRefreshing]`.
         * @details Tells the refresh controller that a refresh operation has ended. Call this method when your refresh operation completes. The refresh controller returns to its default appearance and exits the refreshing state.
         */
        void end_refreshing() const;
#endif

#ifdef COCOON_MACOS_27
        /**
         * @brief Returns the `action` property of `NSRefreshController`.
         * @details The action method to call when refresh is triggered.
         * @return The converted Objective-C result.
         */
        std::string action() const;
#endif

#ifdef COCOON_MACOS_27
        /**
         * @brief Sets the `action` property of `NSRefreshController`.
         * @details The action method to call when refresh is triggered.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_action(const std::string& value) const;
#endif

#ifdef COCOON_MACOS_27
        /**
         * @brief Returns the `attributedTitle` property of `NSRefreshController`.
         * @details The styled text to display in the refresh controller. Use this property to provide additional context about the refresh operation.
         * @return The converted Objective-C result.
         */
        AttributedString attributed_title() const;
#endif

#ifdef COCOON_MACOS_27
        /**
         * @brief Sets the `attributedTitle` property of `NSRefreshController`.
         * @details The styled text to display in the refresh controller. Use this property to provide additional context about the refresh operation.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_attributed_title(const AttributedString& value) const;
#endif

#ifdef COCOON_MACOS_27
        /**
         * @brief Returns the `isRefreshing` property of `NSRefreshController`.
         * @details A Boolean value indicating whether a refresh operation is in progress. The default value of this property is 'NO'. When the user triggers a refresh, this property automatically becomes 'YES'. Call ''endRefreshing'' when your refresh operation completes to reset this property to 'NO'.
         * @return The converted Objective-C result.
         */
        bool is_refreshing() const;
#endif

#ifdef COCOON_MACOS_27
        /**
         * @brief Returns the `target` property of `NSRefreshController`.
         * @details The target object that receives action messages.
         * @return The converted Objective-C result.
         */
        Object target() const;
#endif

#ifdef COCOON_MACOS_27
        /**
         * @brief Sets the `target` property of `NSRefreshController`.
         * @details The target object that receives action messages.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_target(const Object& value) const;
#endif

#ifdef COCOON_MACOS_27
        /**
         * @brief Returns the `tintColor` property of `NSRefreshController`.
         * @details The tint color for the refresh controller. This color is used for the refresh indicator.
         * @return The converted Objective-C result.
         */
        Color tint_color() const;
#endif

#ifdef COCOON_MACOS_27
        /**
         * @brief Sets the `tintColor` property of `NSRefreshController`.
         * @details The tint color for the refresh controller. This color is used for the refresh indicator.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tint_color(const Color& value) const;
#endif
    };
}

#endif
