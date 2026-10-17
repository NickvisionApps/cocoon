#pragma once

#include "generated/control.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class Color;
    class Event;
    class Image;
    class ImageSymbolConfiguration;
    class Sound;
    class UserInterfaceCompressionOptions;

    /**
     * @brief A push button (NSButton).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Control.
     *
     * @par Example
     * @code
     * cocoon::Button button("Click me");
     * button.set_bezel_style(cocoon::BezelStyle::Push);
     * button.clicked().connect([] {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Button button{"text"};
     * button.set_allows_mixed_state(true);
     * auto allows_mixed_state = button.allows_mixed_state();
     * button.set_alternate_image(cocoon::Image());
     * auto alternate_image = button.alternate_image();
     * button.set_alternate_title("text");
     * auto alternate_title = button.alternate_title();
     * button.highlight(true);
     * button.perform_key_equivalent(cocoon::Event());
     * button.set_button_type(cocoon::ButtonType::MomentaryLight);
     * button.clicked().connect([]() {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsbutton
     */
    class Button : public Control
    {
    public:
        /// @brief Creates a new `NSButton` instance and returns a handle to it.
        explicit Button(const std::string& title = "");
        /// @brief Creates a null handle that refers to no native object.
        Button(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Button(Adopt adopt);
        using Control::perform_click;
        using View::perform_key_equivalent;
        /**
     * @brief Calls `+[NSButton buttonWithImage:target:action:]`.
     * @details Creates a standard push button with the provided image. Set the image's accessibilityDescription property to ensure accessibility for this control. \@param image The image to display in the body of the button. \@param target The target object that receives action messages from the control. \@param action The action message sent by the control. \@return An initialized button object.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Button button_with_image(const Image& image, const Object& target, const std::string& action);
        /**
     * @brief Calls `+[NSButton buttonWithTitle:image:target:action:]`.
     * @details Creates a standard push button with a title and image. \@param title The localized title string that is displayed on the button. \@param image The image that is displayed alongside the title. In left-to-right localizations, the image is displayed to the left of the title. In right-to-left localizations, it is displayed to the right. \@param target The target object that receives action messages from the control. \@param action The action message sent by the control. \@return An initialized button object.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Button button_with_title(const std::string& title, const Image& image, const Object& target, const std::string& action);
        /**
     * @brief Calls `+[NSButton buttonWithTitle:target:action:]`.
     * @details Creates a standard push button with the provided title. \@param title The localized title string that is displayed on the button. \@param target The target object that receives action messages from the control. \@param action The action message sent by the control. \@return An initialized button object.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Button button_with_title(const std::string& title, const Object& target, const std::string& action);
        /**
     * @brief Calls `+[NSButton checkboxWithTitle:target:action:]`.
     * @details Creates a standard checkbox with the provided title. \@param title The localized title string that is displayed alongside the checkbox. \@param target The target object that receives action messages from the control. \@param action The action message sent by the control. \@return An initialized button object.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Button checkbox_with_title(const std::string& title, const Object& target, const std::string& action);
        /**
     * @brief Calls `-[NSButton compressWithPrioritizedCompressionOptions:]`.
     * @param prioritized_options Argument converted to the Objective-C parameter of the same role.
     */
        void compress_with_prioritized_compression_options(const std::vector<UserInterfaceCompressionOptions>& prioritized_options) const;
        /**
     * @brief Calls `-[NSButton getPeriodicDelay:interval:]`.
     * @details Gets the initial delay and repeat interval, in seconds, for repeated action messages sent when 'continuous' is YES. Both parameters to this method must not be NULL.
     * @param delay Argument converted to the Objective-C parameter of the same role.
     * @param interval Argument converted to the Objective-C parameter of the same role.
     */
        void get_periodic_delay(float* delay, float* interval) const;
        /**
     * @brief Calls `-[NSButton highlight:]`.
     * @details Highlights, or un-highlights, the button. Highlighting makes the button appear "pressed", which may include showing an illuminated bezel, or showing the alternate image or title, depending on the type of button.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     */
        void highlight(bool flag) const;
        /**
     * @brief Calls `-[NSButton minimumSizeWithPrioritizedCompressionOptions:]`.
     * @param prioritized_options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Size minimum_size_with_prioritized_compression_options(const std::vector<UserInterfaceCompressionOptions>& prioritized_options) const;
        /**
     * @brief Calls `-[NSButton performKeyEquivalent:]`.
     * @details If the event parameter matches the button's key equivalent, the button briefly highlights and performs its action, and then returns YES. Otherwise, returns NO.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool perform_key_equivalent(const Event& key) const;
        /**
     * @brief Calls `+[NSButton radioButtonWithTitle:target:action:]`.
     * @details Creates a standard radio button with the provided title. \@param title The localized title string that is displayed alongside the radio button. \@param target The target object that receives action messages from the control. \@param action The action message sent by the control. \@return An initialized button object.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Button radio_button_with_title(const std::string& title, const Object& target, const std::string& action);
        /**
     * @brief Calls `-[NSButton setButtonType:]`.
     * @details Sets the button’s type, which affects its user interface and behavior when clicked. See the NSButtonType enumeration for possible options and their behaviors.
     * @param type Argument converted to the Objective-C parameter of the same role.
     */
        void set_button_type(ButtonType type) const;
        /**
     * @brief Calls `-[NSButton setNextState]`.
     * @details Sets the button to its next eligible state. If the button allows mixed state, this cycles through the states in the order: on, off, mixed, on, etc. If the button does not allow mixed state, it toggles between off and on.
     */
        void set_next_state() const;
        /**
     * @brief Calls `-[NSButton setPeriodicDelay:interval:]`.
     * @details Sets the initial delay and repeat interval, in seconds, for repeated action messages sent when 'continuous' is YES.
     * @param delay Argument converted to the Objective-C parameter of the same role.
     * @param interval Argument converted to the Objective-C parameter of the same role.
     */
        void set_periodic_delay(float delay, float interval) const;
        /**
     * @brief Returns the `activeCompressionOptions` property of `NSButton`.
     * @return The converted Objective-C result.
     */
        UserInterfaceCompressionOptions active_compression_options() const;
        /**
     * @brief Returns the `allowsMixedState` property of `NSButton`.
     * @details A Boolean value that indicates whether the button allows a mixed state. If NO, the button has two states (on and off), and if YES, the button has three states (on, off, and mixed). The mixed state is commonly used with checkboxes and radio buttons to indicate a value which is partially on.
     * @return The converted Objective-C result.
     */
        bool allows_mixed_state() const;
        /**
     * @brief Sets the `allowsMixedState` property of `NSButton`.
     * @details A Boolean value that indicates whether the button allows a mixed state. If NO, the button has two states (on and off), and if YES, the button has three states (on, off, and mixed). The mixed state is commonly used with checkboxes and radio buttons to indicate a value which is partially on.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_mixed_state(bool value) const;
        /**
     * @brief Returns the `alternateImage` property of `NSButton`.
     * @details An alternate image that appears on the button when the button is in an on state, or nil if there is no such image. Note that some button types do not display an alternate image.
     * @return The converted Objective-C result.
     */
        Image alternate_image() const;
        /**
     * @brief Sets the `alternateImage` property of `NSButton`.
     * @details An alternate image that appears on the button when the button is in an on state, or nil if there is no such image. Note that some button types do not display an alternate image.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_alternate_image(const Image& value) const;
        /**
     * @brief Returns the `alternateTitle` property of `NSButton`.
     * @details The title that the button displays when the button is in an on state, or an empty string if there is no such title. Note that some button types do not display an alternate title.
     * @return The converted Objective-C result.
     */
        std::string alternate_title() const;
        /**
     * @brief Sets the `alternateTitle` property of `NSButton`.
     * @details The title that the button displays when the button is in an on state, or an empty string if there is no such title. Note that some button types do not display an alternate title.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_alternate_title(const std::string& value) const;
        /**
     * @brief Returns the `attributedAlternateTitle` property of `NSButton`.
     * @details The alternate title, expressed as an attributed string.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_alternate_title() const;
        /**
     * @brief Sets the `attributedAlternateTitle` property of `NSButton`.
     * @details The alternate title, expressed as an attributed string.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_alternate_title(const AttributedString& value) const;
        /**
     * @brief Returns the `attributedTitle` property of `NSButton`.
     * @details The button's title, expressed as an attributed string.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_title() const;
        /**
     * @brief Sets the `attributedTitle` property of `NSButton`.
     * @details The button's title, expressed as an attributed string.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_title(const AttributedString& value) const;
        /**
     * @brief Returns the `bezelColor` property of `NSButton`.
     * @details Applies a custom color to the button's bezel, in appearances that support it. A nil value indicates an unmodified button appearance. The default value is nil.
     * @return The converted Objective-C result.
     */
        Color bezel_color() const;
        /**
     * @brief Sets the `bezelColor` property of `NSButton`.
     * @details Applies a custom color to the button's bezel, in appearances that support it. A nil value indicates an unmodified button appearance. The default value is nil.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bezel_color(const Color& value) const;
        /**
     * @brief Returns the `bezelStyle` property of `NSButton`.
     * @details The bezel style of the button, which provides a set of bezel artwork, layout metrics, and content styling from a set of system-provided styles. See the NSBezelStyle enumeration for a list of available styles. The bezel style is not used if the 'bordered' property is set to 'NO'.
     * @return The converted Objective-C result.
     */
        BezelStyle bezel_style() const;
        /**
     * @brief Sets the `bezelStyle` property of `NSButton`.
     * @details The bezel style of the button, which provides a set of bezel artwork, layout metrics, and content styling from a set of system-provided styles. See the NSBezelStyle enumeration for a list of available styles. The bezel style is not used if the 'bordered' property is set to 'NO'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bezel_style(BezelStyle value) const;
        /**
     * @brief Returns the `borderShape` property of `NSButton`.
     * @return The converted Objective-C result.
     */
        ControlBorderShape border_shape() const;
        /**
     * @brief Sets the `borderShape` property of `NSButton`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_border_shape(ControlBorderShape value) const;
        /**
     * @brief Returns the `bordered` property of `NSButton`.
     * @details A Boolean value that determines whether the button draws a border.
     * @return The converted Objective-C result.
     */
        bool is_bordered() const;
        /**
     * @brief Sets the `bordered` property of `NSButton`.
     * @details A Boolean value that determines whether the button draws a border.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bordered(bool value) const;
        /**
     * @brief Returns the `contentTintColor` property of `NSButton`.
     * @details Applies a tint color to template image and text content, in combination with other theme-appropriate effects. Only applicable to borderless buttons. A nil value indicates the standard set of effects without color modification. The default value is nil. Non-template images and attributed string values are not affected by the contentTintColor.
     * @return The converted Objective-C result.
     */
        Color content_tint_color() const;
        /**
     * @brief Sets the `contentTintColor` property of `NSButton`.
     * @details Applies a tint color to template image and text content, in combination with other theme-appropriate effects. Only applicable to borderless buttons. A nil value indicates the standard set of effects without color modification. The default value is nil. Non-template images and attributed string values are not affected by the contentTintColor.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_tint_color(const Color& value) const;
        /**
     * @brief Returns the `hasDestructiveAction` property of `NSButton`.
     * @details Indicates whether the button's action has a destructive effect on user data. AppKit may guard a destructive-actioned button against accidental presses, and may give the button a special appearance in certain contexts to caution against unintentional use. Defaults to NO.
     * @return The converted Objective-C result.
     */
        bool has_destructive_action() const;
        /**
     * @brief Sets the `hasDestructiveAction` property of `NSButton`.
     * @details Indicates whether the button's action has a destructive effect on user data. AppKit may guard a destructive-actioned button against accidental presses, and may give the button a special appearance in certain contexts to caution against unintentional use. Defaults to NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_has_destructive_action(bool value) const;
        /**
     * @brief Returns the `image` property of `NSButton`.
     * @details The image that appears on the button when it’s in an off state, or nil if there is no such image.
     * @return The converted Objective-C result.
     */
        Image image() const;
        /**
     * @brief Sets the `image` property of `NSButton`.
     * @details The image that appears on the button when it’s in an off state, or nil if there is no such image.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image(const Image& value) const;
        /**
     * @brief Returns the `imageHugsTitle` property of `NSButton`.
     * @details A Boolean value that determines how the button's image and title are positioned together within the button bezel. If false, the image is positioned according to the imagePosition property at the edge of the button bezel, and the title is positioned within the remaining space. If true, the button’s image is positioned directly adjacent to the title based on the imagePosition property, and the image and title are positioned within the button bezel as a single unit.
     * @return The converted Objective-C result.
     */
        bool image_hugs_title() const;
        /**
     * @brief Sets the `imageHugsTitle` property of `NSButton`.
     * @details A Boolean value that determines how the button's image and title are positioned together within the button bezel. If false, the image is positioned according to the imagePosition property at the edge of the button bezel, and the title is positioned within the remaining space. If true, the button’s image is positioned directly adjacent to the title based on the imagePosition property, and the image and title are positioned within the button bezel as a single unit.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image_hugs_title(bool value) const;
        /**
     * @brief Returns the `imagePosition` property of `NSButton`.
     * @details The position of the button's image relative to its title. See the NSCellImagePosition enumeration for possible values.
     * @return The converted Objective-C result.
     */
        CellImagePosition image_position() const;
        /**
     * @brief Sets the `imagePosition` property of `NSButton`.
     * @details The position of the button's image relative to its title. See the NSCellImagePosition enumeration for possible values.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image_position(CellImagePosition value) const;
        /**
     * @brief Returns the `imageScaling` property of `NSButton`.
     * @details The scaling mode applied to make the button's image fit within its bounds.
     * @return The converted Objective-C result.
     */
        ImageScaling image_scaling() const;
        /**
     * @brief Sets the `imageScaling` property of `NSButton`.
     * @details The scaling mode applied to make the button's image fit within its bounds.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image_scaling(ImageScaling value) const;
        /**
     * @brief Returns the `keyEquivalent` property of `NSButton`.
     * @details This property contains the button's key equivalent, or the empty string if no equivalent has been defined. Buttons don’t have a default key equivalent. Setting the key equivalent to the Return character causes it to act as the default button for its window.
     * @return The converted Objective-C result.
     */
        std::string key_equivalent() const;
        /**
     * @brief Sets the `keyEquivalent` property of `NSButton`.
     * @details This property contains the button's key equivalent, or the empty string if no equivalent has been defined. Buttons don’t have a default key equivalent. Setting the key equivalent to the Return character causes it to act as the default button for its window.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_key_equivalent(const std::string& value) const;
        /**
     * @brief Returns the `keyEquivalentModifierMask` property of `NSButton`.
     * @details A bitmask specifying the modifier keys that are applied to the button's key equivalent. Mask bits are defined by the NSEventModifierFlags option set. The only mask bits relevant in button key-equivalent modifier masks are NSEventModifierFlagControl, NSEventModifierFlagOption, and NSEventModifierFlagCommand.
     * @return The converted Objective-C result.
     */
        EventModifierFlags key_equivalent_modifier_mask() const;
        /**
     * @brief Sets the `keyEquivalentModifierMask` property of `NSButton`.
     * @details A bitmask specifying the modifier keys that are applied to the button's key equivalent. Mask bits are defined by the NSEventModifierFlags option set. The only mask bits relevant in button key-equivalent modifier masks are NSEventModifierFlagControl, NSEventModifierFlagOption, and NSEventModifierFlagCommand.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_key_equivalent_modifier_mask(EventModifierFlags value) const;
        /**
     * @brief Returns the `maxAcceleratorLevel` property of `NSButton`.
     * @details Configures the maximum allowed level for an NSMultiLevelAcceleratorButton, allowed values range from [1,5]. Defaults to 2.
     * @return The converted Objective-C result.
     */
        std::int64_t max_accelerator_level() const;
        /**
     * @brief Sets the `maxAcceleratorLevel` property of `NSButton`.
     * @details Configures the maximum allowed level for an NSMultiLevelAcceleratorButton, allowed values range from [1,5]. Defaults to 2.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_max_accelerator_level(std::int64_t value) const;
        /**
     * @brief Returns the `showsBorderOnlyWhileMouseInside` property of `NSButton`.
     * @details A Boolean value that determines whether the button displays its border only when the pointer is over it.
     * @return The converted Objective-C result.
     */
        bool shows_border_only_while_mouse_inside() const;
        /**
     * @brief Sets the `showsBorderOnlyWhileMouseInside` property of `NSButton`.
     * @details A Boolean value that determines whether the button displays its border only when the pointer is over it.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_border_only_while_mouse_inside(bool value) const;
        /**
     * @brief Returns the `sound` property of `NSButton`.
     * @details The sound that plays when the user clicks the button, or nil if the button should not play a sound. The default value is nil.
     * @return The converted Objective-C result.
     */
        Sound sound() const;
        /**
     * @brief Sets the `sound` property of `NSButton`.
     * @details The sound that plays when the user clicks the button, or nil if the button should not play a sound. The default value is nil.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_sound(const Sound& value) const;
        /**
     * @brief Returns the `springLoaded` property of `NSButton`.
     * @details Sends action on deep-press or extended hover while dragging. Defaults to NO.
     * @return The converted Objective-C result.
     */
        bool is_spring_loaded() const;
        /**
     * @brief Sets the `springLoaded` property of `NSButton`.
     * @details Sends action on deep-press or extended hover while dragging. Defaults to NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_spring_loaded(bool value) const;
        /**
     * @brief Returns the `state` property of `NSButton`.
     * @details The button's state. Buttons support the off and on states, and an additional mixed state depending on the value of the 'allowsMixedState' property.
     * @return The converted Objective-C result.
     */
        ControlState state() const;
        /**
     * @brief Sets the `state` property of `NSButton`.
     * @details The button's state. Buttons support the off and on states, and an additional mixed state depending on the value of the 'allowsMixedState' property.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_state(ControlState value) const;
        /**
     * @brief Returns the `symbolConfiguration` property of `NSButton`.
     * @details Specifies a combination of point size, weight, and scale to use when sizing and displaying symbol images. If a symbol configuration isn't provided, the symbol is matched to the button's 'font' property. The default value is nil.
     * @return The converted Objective-C result.
     */
        ImageSymbolConfiguration symbol_configuration() const;
        /**
     * @brief Sets the `symbolConfiguration` property of `NSButton`.
     * @details Specifies a combination of point size, weight, and scale to use when sizing and displaying symbol images. If a symbol configuration isn't provided, the symbol is matched to the button's 'font' property. The default value is nil.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_symbol_configuration(const ImageSymbolConfiguration& value) const;
        /**
     * @brief Returns the `tintProminence` property of `NSButton`.
     * @details The tint prominence of the button. Use tint prominence to gently suggest a hierarchy when multiple buttons perform similar actions. A button with primary tint prominence suggests the most preferred option, while secondary prominence indicates a reasonable alternative. See ''NSTintProminence'' for a list of possible values.
     * @return The converted Objective-C result.
     */
        TintProminence tint_prominence() const;
        /**
     * @brief Sets the `tintProminence` property of `NSButton`.
     * @details The tint prominence of the button. Use tint prominence to gently suggest a hierarchy when multiple buttons perform similar actions. A button with primary tint prominence suggests the most preferred option, while secondary prominence indicates a reasonable alternative. See ''NSTintProminence'' for a list of possible values.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tint_prominence(TintProminence value) const;
        /**
     * @brief Returns the `title` property of `NSButton`.
     * @details The title displayed on the button when it’s in an off state, or an empty string if the button does not display a title. By default, a button's title is "Button".
     * @return The converted Objective-C result.
     */
        std::string title() const;
        /**
     * @brief Sets the `title` property of `NSButton`.
     * @details The title displayed on the button when it’s in an off state, or an empty string if the button does not display a title. By default, a button's title is "Button".
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title(const std::string& value) const;
        /**
     * @brief Returns the `transparent` property of `NSButton`.
     * @details A Boolean value that indicates whether the button is transparent. A transparent button never draws itself, but it receives mouse events, sends its action, and tracks the mouse properly.
     * @return The converted Objective-C result.
     */
        bool is_transparent() const;
        /**
     * @brief Sets the `transparent` property of `NSButton`.
     * @details A Boolean value that indicates whether the button is transparent. A transparent button never draws itself, but it receives mouse events, sends its action, and tracks the mouse properly.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_transparent(bool value) const;
        /// @brief Convenience helper `perform_click` provided by cocoon.
        void perform_click() const;
        /// @brief Signal `clicked`: connect a callback with `clicked().connect(...)`.
        Signal<Button, void()> clicked() const
        {
            return Signal<Button, void()>(handle(), "clicked");
        }

    protected:
        static void bind_action_(void* native);
    };
}
