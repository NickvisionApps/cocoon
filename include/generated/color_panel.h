#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/panel.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class ColorList;
    class Event;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSColorPanel` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Panel.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ColorPanel color_panel;
     * color_panel.set_accessory_view(cocoon::View());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ColorPanel color_panel{};
     * color_panel.set_accessory_view(cocoon::View());
     * auto accessory_view = color_panel.accessory_view();
     * color_panel.set_color(cocoon::Color());
     * auto color = color_panel.color();
     * color_panel.set_continuous(true);
     * auto continuous = color_panel.is_continuous();
     * color_panel.attach_color_list(cocoon::ColorList());
     * color_panel.detach_color_list(cocoon::ColorList());
     * color_panel.set_action("text");
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscolorpanel
     */
    class ColorPanel : public Panel
    {
    public:
        /// @brief Creates a new `NSColorPanel` instance and returns a handle to it.
        explicit ColorPanel();
        /// @brief Creates a null handle that refers to no native object.
        ColorPanel(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ColorPanel(Adopt adopt);
        /**
         * @brief Calls `-[NSColorPanel attachColorList:]`.
         * @param color_list Argument converted to the Objective-C parameter of the same role.
         */
        void attach_color_list(const ColorList& color_list) const;
        /**
         * @brief Calls `-[NSColorPanel detachColorList:]`.
         * @param color_list Argument converted to the Objective-C parameter of the same role.
         */
        void detach_color_list(const ColorList& color_list) const;
        /**
         * @brief Calls `+[NSColorPanel dragColor:withEvent:fromView:]`.
         * @param color Argument converted to the Objective-C parameter of the same role.
         * @param event Argument converted to the Objective-C parameter of the same role.
         * @param source_view Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static bool drag_color(const Color& color, const Event& event, const View& source_view);
        /**
         * @brief Calls `-[NSColorPanel setAction:]`.
         * @param selector Argument converted to the Objective-C parameter of the same role.
         */
        void set_action(const std::string& selector) const;
        /**
         * @brief Calls `+[NSColorPanel setPickerMask:]`.
         * @param mask Argument converted to the Objective-C parameter of the same role.
         */
        static void set_picker_mask(ColorPanelOptions mask);
        /**
         * @brief Calls `+[NSColorPanel setPickerMode:]`.
         * @param mode Argument converted to the Objective-C parameter of the same role.
         */
        static void set_picker_mode(ColorPanelMode mode);
        /**
         * @brief Calls `-[NSColorPanel setTarget:]`.
         * @param target Argument converted to the Objective-C parameter of the same role.
         */
        void set_target(const Object& target) const;
        /**
         * @brief Returns the `accessoryView` property of `NSColorPanel`.
         * @return The converted Objective-C result.
         */
        View accessory_view() const;
        /**
         * @brief Sets the `accessoryView` property of `NSColorPanel`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_accessory_view(const View& value) const;
        /**
         * @brief Returns the `alpha` property of `NSColorPanel`.
         * @return The converted Objective-C result.
         */
        double alpha() const;
        /**
         * @brief Returns the `color` property of `NSColorPanel`.
         * @return The converted Objective-C result.
         */
        Color color() const;
        /**
         * @brief Sets the `color` property of `NSColorPanel`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_color(const Color& value) const;
        /**
         * @brief Returns the `continuous` property of `NSColorPanel`.
         * @return The converted Objective-C result.
         */
        bool is_continuous() const;
        /**
         * @brief Sets the `continuous` property of `NSColorPanel`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_continuous(bool value) const;
        /**
         * @brief Returns the `maximumLinearExposure` property of `NSColorPanel`.
         * @details The maximum linear exposure that can be set on a color picked in the color panel. Defaults to 1 and ignores any value less than 1. If set to a value >= 2, the color picked by the panel may have a linear exposure applied to it.
         * @return The converted Objective-C result.
         */
        double maximum_linear_exposure() const;
        /**
         * @brief Sets the `maximumLinearExposure` property of `NSColorPanel`.
         * @details The maximum linear exposure that can be set on a color picked in the color panel. Defaults to 1 and ignores any value less than 1. If set to a value >= 2, the color picked by the panel may have a linear exposure applied to it.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_maximum_linear_exposure(double value) const;
        /**
         * @brief Returns the `mode` property of `NSColorPanel`.
         * @return The converted Objective-C result.
         */
        ColorPanelMode mode() const;
        /**
         * @brief Sets the `mode` property of `NSColorPanel`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_mode(ColorPanelMode value) const;
        /**
         * @brief Returns the `sharedColorPanel` property of `NSColorPanel`.
         * @return The converted Objective-C result.
         */
        static ColorPanel shared_color_panel();
        /**
         * @brief Returns the `sharedColorPanelExists` property of `NSColorPanel`.
         * @return The converted Objective-C result.
         */
        static bool shared_color_panel_exists();
        /**
         * @brief Returns the `showsAlpha` property of `NSColorPanel`.
         * @return The converted Objective-C result.
         */
        bool shows_alpha() const;
        /**
         * @brief Sets the `showsAlpha` property of `NSColorPanel`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_shows_alpha(bool value) const;
    };
}
