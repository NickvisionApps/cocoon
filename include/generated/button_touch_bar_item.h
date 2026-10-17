#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/touch_bar_item.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class Image;

    /**
     * @brief C++ handle for the Objective-C class `NSButtonTouchBarItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TouchBarItem.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ButtonTouchBarItem button_touch_bar_item(nullptr);  // null handle; instances normally come from other API calls
     * button_touch_bar_item.set_action("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ButtonTouchBarItem button_touch_bar_item(nullptr);
     * button_touch_bar_item.set_action("text");
     * auto action = button_touch_bar_item.action();
     * button_touch_bar_item.set_bezel_color(cocoon::Color());
     * auto bezel_color = button_touch_bar_item.bezel_color();
     * button_touch_bar_item.set_customization_label("text");
     * auto customization_label = button_touch_bar_item.customization_label();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsbuttontouchbaritem
     */
    class ButtonTouchBarItem : public TouchBarItem
    {
    public:
        ButtonTouchBarItem();
        /// @brief Creates a null handle that refers to no native object.
        ButtonTouchBarItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ButtonTouchBarItem(Adopt adopt);
        using TouchBarItem::customization_label;
        /**
     * @brief Calls `+[NSButtonTouchBarItem buttonTouchBarItemWithIdentifier:image:target:action:]`.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ButtonTouchBarItem button_touch_bar_item_with_identifier(const std::string& identifier, const Image& image, const Object& target, const std::string& action);
        /**
     * @brief Calls `+[NSButtonTouchBarItem buttonTouchBarItemWithIdentifier:title:image:target:action:]`.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ButtonTouchBarItem button_touch_bar_item_with_identifier(const std::string& identifier, const std::string& title, const Image& image, const Object& target, const std::string& action);
        /**
     * @brief Calls `+[NSButtonTouchBarItem buttonTouchBarItemWithIdentifier:title:target:action:]`.
     * @details Creates a standard item with an button appropriate for use in an NSTouchBar
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ButtonTouchBarItem button_touch_bar_item_with_identifier(const std::string& identifier, const std::string& title, const Object& target, const std::string& action);
        /**
     * @brief Returns the `action` property of `NSButtonTouchBarItem`.
     * @return The converted Objective-C result.
     */
        std::string action() const;
        /**
     * @brief Sets the `action` property of `NSButtonTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_action(const std::string& value) const;
        /**
     * @brief Returns the `bezelColor` property of `NSButtonTouchBarItem`.
     * @return The converted Objective-C result.
     */
        Color bezel_color() const;
        /**
     * @brief Sets the `bezelColor` property of `NSButtonTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bezel_color(const Color& value) const;
        /**
     * @brief Returns the `customizationLabel` property of `NSButtonTouchBarItem`.
     * @details The localized string labeling this item during user customization. The default value is empty string.
     * @return The converted Objective-C result.
     */
        std::string customization_label() const;
        /**
     * @brief Sets the `customizationLabel` property of `NSButtonTouchBarItem`.
     * @details The localized string labeling this item during user customization. The default value is empty string.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_customization_label(const std::string& value) const;
        /**
     * @brief Returns the `enabled` property of `NSButtonTouchBarItem`.
     * @return The converted Objective-C result.
     */
        bool is_enabled() const;
        /**
     * @brief Sets the `enabled` property of `NSButtonTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_enabled(bool value) const;
        /**
     * @brief Returns the `image` property of `NSButtonTouchBarItem`.
     * @return The converted Objective-C result.
     */
        Image image() const;
        /**
     * @brief Sets the `image` property of `NSButtonTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image(const Image& value) const;
        /**
     * @brief Returns the `target` property of `NSButtonTouchBarItem`.
     * @return The converted Objective-C result.
     */
        Object target() const;
        /**
     * @brief Sets the `target` property of `NSButtonTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_target(const Object& value) const;
        /**
     * @brief Returns the `title` property of `NSButtonTouchBarItem`.
     * @return The converted Objective-C result.
     */
        std::string title() const;
        /**
     * @brief Sets the `title` property of `NSButtonTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title(const std::string& value) const;
    };
}
