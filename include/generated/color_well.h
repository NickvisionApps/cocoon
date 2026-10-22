#pragma once

#include "generated/availability.h"
#include "generated/control.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class Image;

    /**
     * @brief A color selection well.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Control.
     *
     * @par Example
     * @code
     * cocoon::ColorWell well;
     * well.color_changed().connect([](cocoon::Color color) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ColorWell color_well{};
     * color_well.set_bordered(true);
     * auto bordered = color_well.is_bordered();
     * color_well.set_color(cocoon::Color());
     * auto color = color_well.color();
     * color_well.set_color_well_style(cocoon::ColorWellStyle::Default);
     * auto color_well_style = color_well.color_well_style();
     * color_well.activate(true);
     * color_well.deactivate();
     * color_well.draw_well_inside({{0, 0}, {100, 100}});
     * color_well.color_changed().connect([](cocoon::Color a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscolorwell
     */
    class ColorWell : public Control
    {
    public:
        /// @brief Creates a new `NSColorWell` instance and returns a handle to it.
        explicit ColorWell();
        /// @brief Creates a new `NSColorWell` instance and returns a handle to it.
        explicit ColorWell(ColorWellStyle style);
        /// @brief Creates a null handle that refers to no native object.
        ColorWell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ColorWell(Adopt adopt);
        /**
         * @brief Calls `-[NSColorWell activate:]`.
         * @param exclusive Argument converted to the Objective-C parameter of the same role.
         */
        void activate(bool exclusive) const;
        /**
         * @brief Calls `-[NSColorWell deactivate]`.
         */
        void deactivate() const;
        /**
         * @brief Calls `-[NSColorWell drawWellInside:]`.
         * @param inside_rect Argument converted to the Objective-C parameter of the same role.
         */
        void draw_well_inside(const Rect& inside_rect) const;
        /**
         * @brief Calls `-[NSColorWell takeColorFrom:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void take_color_from(const Object& sender) const;
        /**
         * @brief Returns the `active` property of `NSColorWell`.
         * @return The converted Objective-C result.
         */
        bool is_active() const;
        /**
         * @brief Returns the `bordered` property of `NSColorWell`.
         * @return The converted Objective-C result.
         */
        bool is_bordered() const;
        /**
         * @brief Sets the `bordered` property of `NSColorWell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_bordered(bool value) const;
        /**
         * @brief Returns the `color` property of `NSColorWell`.
         * @return The converted Objective-C result.
         */
        Color color() const;
        /**
         * @brief Sets the `color` property of `NSColorWell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_color(const Color& value) const;
        /**
         * @brief Returns the `colorWellStyle` property of `NSColorWell`.
         * @return The converted Objective-C result.
         */
        ColorWellStyle color_well_style() const;
        /**
         * @brief Sets the `colorWellStyle` property of `NSColorWell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_color_well_style(ColorWellStyle value) const;
        /**
         * @brief Returns the `image` property of `NSColorWell`.
         * @return The converted Objective-C result.
         */
        Image image() const;
        /**
         * @brief Sets the `image` property of `NSColorWell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_image(const Image& value) const;
        /**
         * @brief Returns the `maximumLinearExposure` property of `NSColorWell`.
         * @details The maximum linear exposure a color in this color well can be set to. Defaults to 1 and ignores any value less than 1. If set to a value >= 2, the color picked for this well may have a linear exposure applied to it.
         * @return The converted Objective-C result.
         */
        double maximum_linear_exposure() const;
        /**
         * @brief Sets the `maximumLinearExposure` property of `NSColorWell`.
         * @details The maximum linear exposure a color in this color well can be set to. Defaults to 1 and ignores any value less than 1. If set to a value >= 2, the color picked for this well may have a linear exposure applied to it.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_maximum_linear_exposure(double value) const;
        /**
         * @brief Returns the `pulldownAction` property of `NSColorWell`.
         * @return The converted Objective-C result.
         */
        std::string pulldown_action() const;
        /**
         * @brief Sets the `pulldownAction` property of `NSColorWell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_pulldown_action(const std::string& value) const;
        /**
         * @brief Returns the `pulldownTarget` property of `NSColorWell`.
         * @return The converted Objective-C result.
         */
        Object pulldown_target() const;
        /**
         * @brief Sets the `pulldownTarget` property of `NSColorWell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_pulldown_target(const Object& value) const;
        /**
         * @brief Returns the `supportsAlpha` property of `NSColorWell`.
         * @details Controls alpha support for the current color well, and the visibility of alpha slider in the color panel. When 'NSColor.ignoresAlpha' (deprecated) is set to 'YES', this property will always return 'NO' and alpha is not supported globally.
         * @return The converted Objective-C result.
         */
        bool supports_alpha() const;
        /**
         * @brief Sets the `supportsAlpha` property of `NSColorWell`.
         * @details Controls alpha support for the current color well, and the visibility of alpha slider in the color panel. When 'NSColor.ignoresAlpha' (deprecated) is set to 'YES', this property will always return 'NO' and alpha is not supported globally.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_supports_alpha(bool value) const;
        /// @brief Signal `color_changed`: connect a callback with `color_changed().connect(...)`.
        Signal<ColorWell, void(Color)> color_changed() const
        {
            return Signal<ColorWell, void(Color)>(handle(), "color_changed");
        }

    protected:
        static void bind_action_(void* native);
    };
}
