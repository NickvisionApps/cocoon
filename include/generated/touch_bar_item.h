#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class View;
    class ViewController;

    /**
     * @brief C++ handle for the Objective-C class `NSTouchBarItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TouchBarItem touch_bar_item{"text"};
     * touch_bar_item.set_visibility_priority(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TouchBarItem touch_bar_item{"text"};
     * touch_bar_item.set_visibility_priority(1);
     * auto visibility_priority = touch_bar_item.visibility_priority();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstouchbaritem
     */
    class TouchBarItem : public Object
    {
    public:
        /// @brief Creates a new `NSTouchBarItem` instance and returns a handle to it.
        explicit TouchBarItem(const std::string& identifier);
        TouchBarItem();
        /// @brief Creates a null handle that refers to no native object.
        TouchBarItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TouchBarItem(Adopt adopt);
        /**
         * @brief Returns the `customizationLabel` property of `NSTouchBarItem`.
         * @details The user visible string identifying this item during customization. By default this method returns the empty string.
         * @return The converted Objective-C result.
         */
        std::string customization_label() const;
        /**
         * @brief Returns the `identifier` property of `NSTouchBarItem`.
         * @details The identifier of this item. Apart from spaces, item identifiers should be globally unique.
         * @return The converted Objective-C result.
         */
        std::string identifier() const;
        /**
         * @brief Returns the `view` property of `NSTouchBarItem`.
         * @details Intended for subclassing. By default, this method returns this item's view controller's view.
         * @return The converted Objective-C result.
         */
        View view() const;
        /**
         * @brief Returns the `viewController` property of `NSTouchBarItem`.
         * @details Intended for subclassing. By default, this method returns nil.
         * @return The converted Objective-C result.
         */
        ViewController view_controller() const;
        /**
         * @brief Returns the `visibilityPriority` property of `NSTouchBarItem`.
         * @details If there are more items in the NSTouchBar than can be displayed, some will be hidden. Items with high visibility priority will be hidden after items with low visibility priority.
         * @return The converted Objective-C result.
         */
        float visibility_priority() const;
        /**
         * @brief Sets the `visibilityPriority` property of `NSTouchBarItem`.
         * @details If there are more items in the NSTouchBar than can be displayed, some will be hidden. Items with high visibility priority will be hidden after items with low visibility priority.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_visibility_priority(float value) const;
        /**
         * @brief Returns the `visible` property of `NSTouchBarItem`.
         * @details When YES, this item is attached to a visible NSTouchBar, and is being displayed. Note that some types of items are never considered visible, for example spaces, other items proxys, and groups. This property is key value observable.
         * @return The converted Objective-C result.
         */
        bool is_visible() const;
    };
}
