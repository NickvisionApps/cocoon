#pragma once

#include "generated/availability.h"
#include "generated/control.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Image;
    class Menu;

    /**
     * @brief C++ handle for the Objective-C class `NSComboButton` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Control.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ComboButton combo_button;
     * combo_button.set_image(cocoon::Image());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ComboButton combo_button{};
     * combo_button.set_image(cocoon::Image());
     * auto image = combo_button.image();
     * combo_button.set_image_scaling(cocoon::ImageScaling::ImageScaleProportionallyDown);
     * auto image_scaling = combo_button.image_scaling();
     * combo_button.set_menu(cocoon::Menu());
     * auto menu = combo_button.menu();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscombobutton
     */
    class ComboButton : public Control
    {
    public:
        /// @brief Creates a new `NSComboButton` instance and returns a handle to it.
        explicit ComboButton(const Image& image, const Menu& menu, const Object& target, const std::string& action);
        /// @brief Creates a new `NSComboButton` instance and returns a handle to it.
        explicit ComboButton(const std::string& title, const Image& image, const Menu& menu, const Object& target, const std::string& action);
        /// @brief Creates a new `NSComboButton` instance and returns a handle to it.
        explicit ComboButton(const std::string& title, const Menu& menu, const Object& target, const std::string& action);
        /// @brief Creates a new `NSComboButton` instance and returns a handle to it.
        explicit ComboButton();
        /// @brief Creates a null handle that refers to no native object.
        ComboButton(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ComboButton(Adopt adopt);
        using Responder::menu;
        using Responder::set_menu;
        /**
         * @brief Returns the `image` property of `NSComboButton`.
         * @details The image displayed on the control. The default value is 'nil'.
         * @return The converted Objective-C result.
         */
        Image image() const;
        /**
         * @brief Sets the `image` property of `NSComboButton`.
         * @details The image displayed on the control. The default value is 'nil'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_image(const Image& value) const;
        /**
         * @brief Returns the `imageScaling` property of `NSComboButton`.
         * @details The scaling mode applied to fit the button's image within the content area. The default value is 'NSImageScaleProportionallyDown'.
         * @return The converted Objective-C result.
         */
        ImageScaling image_scaling() const;
        /**
         * @brief Sets the `imageScaling` property of `NSComboButton`.
         * @details The scaling mode applied to fit the button's image within the content area. The default value is 'NSImageScaleProportionallyDown'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_image_scaling(ImageScaling value) const;
        /**
         * @brief Returns the `menu` property of `NSComboButton`.
         * @details Overrides behavior of NSResponder menu. This menu is shown when interacting with the button (see NSComboButtonStyle). NSComboButton does not have a context menu. Items in this menu specify their own target and action independent of the primary action that is configured on the control.
         * @return The converted Objective-C result.
         */
        Menu menu() const;
        /**
         * @brief Sets the `menu` property of `NSComboButton`.
         * @details Overrides behavior of NSResponder menu. This menu is shown when interacting with the button (see NSComboButtonStyle). NSComboButton does not have a context menu. Items in this menu specify their own target and action independent of the primary action that is configured on the control.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_menu(const Menu& value) const;
        /**
         * @brief Returns the `style` property of `NSComboButton`.
         * @details Specifies the visual presentation and behavior for NSComboButton's primary action and its menu. The default value is 'NSComboButtonStyleSplit'.
         * @return The converted Objective-C result.
         */
        ComboButtonStyle style() const;
        /**
         * @brief Sets the `style` property of `NSComboButton`.
         * @details Specifies the visual presentation and behavior for NSComboButton's primary action and its menu. The default value is 'NSComboButtonStyleSplit'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_style(ComboButtonStyle value) const;
        /**
         * @brief Returns the `title` property of `NSComboButton`.
         * @details The title displayed on the control. The default value is an empty string.
         * @return The converted Objective-C result.
         */
        std::string title() const;
        /**
         * @brief Sets the `title` property of `NSComboButton`.
         * @details The title displayed on the control. The default value is an empty string.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_title(const std::string& value) const;
    };
}
