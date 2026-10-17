#pragma once

#include "generated/action_cell.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class Color;
    class Event;
    class Image;
    class Sound;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSButtonCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ActionCell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ButtonCell button_cell;
     * button_cell.set_alternate_image(cocoon::Image());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ButtonCell button_cell{};
     * button_cell.set_alternate_image(cocoon::Image());
     * auto alternate_image = button_cell.alternate_image();
     * button_cell.set_alternate_title("text");
     * auto alternate_title = button_cell.alternate_title();
     * button_cell.set_attributed_alternate_title(cocoon::AttributedString());
     * auto attributed_alternate_title = button_cell.attributed_alternate_title();
     * button_cell.draw_bezel_with_frame({{0, 0}, {100, 100}}, cocoon::View());
     * button_cell.draw_image(cocoon::Image(), {{0, 0}, {100, 100}}, cocoon::View());
     * button_cell.draw_title(cocoon::AttributedString(), {{0, 0}, {100, 100}}, cocoon::View());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsbuttoncell
     */
    class ButtonCell : public ActionCell
    {
    public:
        /// @brief Creates a new `NSButtonCell` instance and returns a handle to it.
        explicit ButtonCell(const Image& image);
        /// @brief Creates a new `NSButtonCell` instance and returns a handle to it.
        explicit ButtonCell(const std::string& string);
        /// @brief Creates a new `NSButtonCell` instance and returns a handle to it.
        explicit ButtonCell();
        /// @brief Creates a null handle that refers to no native object.
        ButtonCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ButtonCell(Adopt adopt);
        using Cell::get_periodic_delay;
        using Cell::is_opaque;
        using Cell::key_equivalent;
        using Cell::perform_click;
        using Cell::set_title;
        using Cell::title;
        /**
     * @brief Calls `-[NSButtonCell drawBezelWithFrame:inView:]`.
     * @param frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     */
        void draw_bezel_with_frame(const Rect& frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSButtonCell drawImage:withFrame:inView:]`.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @param frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     */
        void draw_image(const Image& image, const Rect& frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSButtonCell drawTitle:withFrame:inView:]`.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @param frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect draw_title(const AttributedString& title, const Rect& frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSButtonCell getPeriodicDelay:interval:]`.
     * @param delay Argument converted to the Objective-C parameter of the same role.
     * @param interval Argument converted to the Objective-C parameter of the same role.
     */
        void get_periodic_delay(float* delay, float* interval) const;
        /**
     * @brief Calls `-[NSButtonCell mouseEntered:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void mouse_entered(const Event& event) const;
        /**
     * @brief Calls `-[NSButtonCell mouseExited:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void mouse_exited(const Event& event) const;
        /**
     * @brief Calls `-[NSButtonCell performClick:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void perform_click(const Object& sender) const;
        /**
     * @brief Calls `-[NSButtonCell setButtonType:]`.
     * @param type Argument converted to the Objective-C parameter of the same role.
     */
        void set_button_type(ButtonType type) const;
        /**
     * @brief Calls `-[NSButtonCell setPeriodicDelay:interval:]`.
     * @param delay Argument converted to the Objective-C parameter of the same role.
     * @param interval Argument converted to the Objective-C parameter of the same role.
     */
        void set_periodic_delay(float delay, float interval) const;
        /**
     * @brief Returns the `alternateImage` property of `NSButtonCell`.
     * @return The converted Objective-C result.
     */
        Image alternate_image() const;
        /**
     * @brief Sets the `alternateImage` property of `NSButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_alternate_image(const Image& value) const;
        /**
     * @brief Returns the `alternateTitle` property of `NSButtonCell`.
     * @return The converted Objective-C result.
     */
        std::string alternate_title() const;
        /**
     * @brief Sets the `alternateTitle` property of `NSButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_alternate_title(const std::string& value) const;
        /**
     * @brief Returns the `attributedAlternateTitle` property of `NSButtonCell`.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_alternate_title() const;
        /**
     * @brief Sets the `attributedAlternateTitle` property of `NSButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_alternate_title(const AttributedString& value) const;
        /**
     * @brief Returns the `attributedTitle` property of `NSButtonCell`.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_title() const;
        /**
     * @brief Sets the `attributedTitle` property of `NSButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_title(const AttributedString& value) const;
        /**
     * @brief Returns the `backgroundColor` property of `NSButtonCell`.
     * @return The converted Objective-C result.
     */
        Color background_color() const;
        /**
     * @brief Sets the `backgroundColor` property of `NSButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_color(const Color& value) const;
        /**
     * @brief Returns the `bezelStyle` property of `NSButtonCell`.
     * @return The converted Objective-C result.
     */
        BezelStyle bezel_style() const;
        /**
     * @brief Sets the `bezelStyle` property of `NSButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bezel_style(BezelStyle value) const;
        /**
     * @brief Returns the `highlightsBy` property of `NSButtonCell`.
     * @return The converted Objective-C result.
     */
        CellStyleMask highlights_by() const;
        /**
     * @brief Sets the `highlightsBy` property of `NSButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_highlights_by(CellStyleMask value) const;
        /**
     * @brief Returns the `imageDimsWhenDisabled` property of `NSButtonCell`.
     * @return The converted Objective-C result.
     */
        bool image_dims_when_disabled() const;
        /**
     * @brief Sets the `imageDimsWhenDisabled` property of `NSButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image_dims_when_disabled(bool value) const;
        /**
     * @brief Returns the `imagePosition` property of `NSButtonCell`.
     * @return The converted Objective-C result.
     */
        CellImagePosition image_position() const;
        /**
     * @brief Sets the `imagePosition` property of `NSButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image_position(CellImagePosition value) const;
        /**
     * @brief Returns the `imageScaling` property of `NSButtonCell`.
     * @return The converted Objective-C result.
     */
        ImageScaling image_scaling() const;
        /**
     * @brief Sets the `imageScaling` property of `NSButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image_scaling(ImageScaling value) const;
        /**
     * @brief Returns the `keyEquivalent` property of `NSButtonCell`.
     * @return The converted Objective-C result.
     */
        std::string key_equivalent() const;
        /**
     * @brief Sets the `keyEquivalent` property of `NSButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_key_equivalent(const std::string& value) const;
        /**
     * @brief Returns the `keyEquivalentModifierMask` property of `NSButtonCell`.
     * @return The converted Objective-C result.
     */
        EventModifierFlags key_equivalent_modifier_mask() const;
        /**
     * @brief Sets the `keyEquivalentModifierMask` property of `NSButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_key_equivalent_modifier_mask(EventModifierFlags value) const;
        /**
     * @brief Returns the `opaque` property of `NSButtonCell`.
     * @return The converted Objective-C result.
     */
        bool is_opaque() const;
        /**
     * @brief Returns the `showsBorderOnlyWhileMouseInside` property of `NSButtonCell`.
     * @return The converted Objective-C result.
     */
        bool shows_border_only_while_mouse_inside() const;
        /**
     * @brief Sets the `showsBorderOnlyWhileMouseInside` property of `NSButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_border_only_while_mouse_inside(bool value) const;
        /**
     * @brief Returns the `showsStateBy` property of `NSButtonCell`.
     * @return The converted Objective-C result.
     */
        CellStyleMask shows_state_by() const;
        /**
     * @brief Sets the `showsStateBy` property of `NSButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_state_by(CellStyleMask value) const;
        /**
     * @brief Returns the `sound` property of `NSButtonCell`.
     * @return The converted Objective-C result.
     */
        Sound sound() const;
        /**
     * @brief Sets the `sound` property of `NSButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_sound(const Sound& value) const;
        /**
     * @brief Returns the `title` property of `NSButtonCell`.
     * @return The converted Objective-C result.
     */
        std::string title() const;
        /**
     * @brief Sets the `title` property of `NSButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title(const std::string& value) const;
        /**
     * @brief Returns the `transparent` property of `NSButtonCell`.
     * @return The converted Objective-C result.
     */
        bool is_transparent() const;
        /**
     * @brief Sets the `transparent` property of `NSButtonCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_transparent(bool value) const;
    };
}
