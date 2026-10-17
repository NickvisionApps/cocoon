#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/touch_bar_item.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class ColorList;
    class ColorSpace;
    class Image;

    /**
     * @brief C++ handle for the Objective-C class `NSColorPickerTouchBarItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TouchBarItem.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ColorPickerTouchBarItem color_picker_touch_bar_item(nullptr);  // null handle; instances normally come from other API calls
     * color_picker_touch_bar_item.set_action("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ColorPickerTouchBarItem color_picker_touch_bar_item(nullptr);
     * color_picker_touch_bar_item.set_action("text");
     * auto action = color_picker_touch_bar_item.action();
     * color_picker_touch_bar_item.set_color(cocoon::Color());
     * auto color = color_picker_touch_bar_item.color();
     * color_picker_touch_bar_item.set_color_list(cocoon::ColorList());
     * auto color_list = color_picker_touch_bar_item.color_list();
     * auto made_0 = cocoon::ColorPickerTouchBarItem::color_picker_with_identifier("text");
     * auto made_1 = cocoon::ColorPickerTouchBarItem::color_picker_with_identifier("text", cocoon::Image());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscolorpickertouchbaritem
     */
    class ColorPickerTouchBarItem : public TouchBarItem
    {
    public:
        ColorPickerTouchBarItem();
        /// @brief Creates a null handle that refers to no native object.
        ColorPickerTouchBarItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ColorPickerTouchBarItem(Adopt adopt);
        using TouchBarItem::customization_label;
        /**
     * @brief Calls `+[NSColorPickerTouchBarItem colorPickerWithIdentifier:]`.
     * @details Creates a bar item containing a button with the standard color picker icon that invokes the color picker.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ColorPickerTouchBarItem color_picker_with_identifier(const std::string& identifier);
        /**
     * @brief Calls `+[NSColorPickerTouchBarItem colorPickerWithIdentifier:buttonImage:]`.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ColorPickerTouchBarItem color_picker_with_identifier(const std::string& identifier, const Image& image);
        /**
     * @brief Calls `+[NSColorPickerTouchBarItem strokeColorPickerWithIdentifier:]`.
     * @details Creates a bar item containing a button with the standard stroke color picker icon that invokes the color picker. Should be used when the item is used for picking stroke colors.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ColorPickerTouchBarItem stroke_color_picker_with_identifier(const std::string& identifier);
        /**
     * @brief Calls `+[NSColorPickerTouchBarItem textColorPickerWithIdentifier:]`.
     * @details Creates a bar item containing a button with the standard text color picker icon that invokes the color picker. Should be used when the item is used for picking text colors.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ColorPickerTouchBarItem text_color_picker_with_identifier(const std::string& identifier);
        /**
     * @brief Returns the `action` property of `NSColorPickerTouchBarItem`.
     * @return The converted Objective-C result.
     */
        std::string action() const;
        /**
     * @brief Sets the `action` property of `NSColorPickerTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_action(const std::string& value) const;
        /**
     * @brief Returns the `allowedColorSpaces` property of `NSColorPickerTouchBarItem`.
     * @details Controls the color spaces that the receiver is able to produce. If a color outside of the allowed spaces are displayed or selected, it will first be converted to the first color space in the array. 'nil' signifies any color space is allowed. Empty array is an invalid value and will raise an exception if set. Defaults to 'nil'.
     * @return The converted Objective-C result.
     */
        std::vector<ColorSpace> allowed_color_spaces() const;
        /**
     * @brief Sets the `allowedColorSpaces` property of `NSColorPickerTouchBarItem`.
     * @details Controls the color spaces that the receiver is able to produce. If a color outside of the allowed spaces are displayed or selected, it will first be converted to the first color space in the array. 'nil' signifies any color space is allowed. Empty array is an invalid value and will raise an exception if set. Defaults to 'nil'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allowed_color_spaces(const std::vector<ColorSpace>& value) const;
        /**
     * @brief Returns the `color` property of `NSColorPickerTouchBarItem`.
     * @return The converted Objective-C result.
     */
        Color color() const;
        /**
     * @brief Sets the `color` property of `NSColorPickerTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_color(const Color& value) const;
        /**
     * @brief Returns the `colorList` property of `NSColorPickerTouchBarItem`.
     * @details The color list displayed in the list color picker. Defaults to the standard system color list. Setting a custom color list will disable the additional tints/shades that appear on long-press.
     * @return The converted Objective-C result.
     */
        ColorList color_list() const;
        /**
     * @brief Sets the `colorList` property of `NSColorPickerTouchBarItem`.
     * @details The color list displayed in the list color picker. Defaults to the standard system color list. Setting a custom color list will disable the additional tints/shades that appear on long-press.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_color_list(const ColorList& value) const;
        /**
     * @brief Returns the `customizationLabel` property of `NSColorPickerTouchBarItem`.
     * @details The localized string labeling this item during user customization. The default value is the localized string of "Color Picker".
     * @return The converted Objective-C result.
     */
        std::string customization_label() const;
        /**
     * @brief Sets the `customizationLabel` property of `NSColorPickerTouchBarItem`.
     * @details The localized string labeling this item during user customization. The default value is the localized string of "Color Picker".
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_customization_label(const std::string& value) const;
        /**
     * @brief Returns the `enabled` property of `NSColorPickerTouchBarItem`.
     * @details Enables or disabled the color picker. If it is currently being shown in a popover, it will be dismissed.
     * @return The converted Objective-C result.
     */
        bool is_enabled() const;
        /**
     * @brief Sets the `enabled` property of `NSColorPickerTouchBarItem`.
     * @details Enables or disabled the color picker. If it is currently being shown in a popover, it will be dismissed.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_enabled(bool value) const;
        /**
     * @brief Returns the `showsAlpha` property of `NSColorPickerTouchBarItem`.
     * @details Whether or not the picker should allow picking a color with non-1.0 alpha. Defaults to '!NSColor.ignoresAlpha'.
     * @return The converted Objective-C result.
     */
        bool shows_alpha() const;
        /**
     * @brief Sets the `showsAlpha` property of `NSColorPickerTouchBarItem`.
     * @details Whether or not the picker should allow picking a color with non-1.0 alpha. Defaults to '!NSColor.ignoresAlpha'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_alpha(bool value) const;
        /**
     * @brief Returns the `target` property of `NSColorPickerTouchBarItem`.
     * @return The converted Objective-C result.
     */
        Object target() const;
        /**
     * @brief Sets the `target` property of `NSColorPickerTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_target(const Object& value) const;
    };
}
