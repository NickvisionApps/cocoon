#pragma once

#include "generated/action_cell.h"
#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class Color;
    class Text;

    /**
     * @brief C++ handle for the Objective-C class `NSTextFieldCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ActionCell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextFieldCell text_field_cell;
     * text_field_cell.set_allowed_input_source_locales({"a", "b"});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextFieldCell text_field_cell{};
     * text_field_cell.set_allowed_input_source_locales({"a", "b"});
     * auto allowed_input_source_locales = text_field_cell.allowed_input_source_locales();
     * text_field_cell.set_background_color(cocoon::Color());
     * auto background_color = text_field_cell.background_color();
     * text_field_cell.set_bezel_style(cocoon::TextFieldBezelStyle::SquareBezel);
     * auto bezel_style = text_field_cell.bezel_style();
     * text_field_cell.set_up_field_editor_attributes(cocoon::Text());
     * text_field_cell.set_wants_notification_for_marked_text(true);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextfieldcell
     */
    class TextFieldCell : public ActionCell
    {
    public:
        /// @brief Creates a new `NSTextFieldCell` instance and returns a handle to it.
        explicit TextFieldCell(const std::string& string);
        /// @brief Creates a new `NSTextFieldCell` instance and returns a handle to it.
        explicit TextFieldCell();
        /// @brief Creates a null handle that refers to no native object.
        TextFieldCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextFieldCell(Adopt adopt);
        using Cell::set_up_field_editor_attributes;
        /**
         * @brief Calls `-[NSTextFieldCell setUpFieldEditorAttributes:]`.
         * @param text_obj Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Text set_up_field_editor_attributes(const Text& text_obj) const;
        /**
         * @brief Calls `-[NSTextFieldCell setWantsNotificationForMarkedText:]`.
         * @param flag Argument converted to the Objective-C parameter of the same role.
         */
        void set_wants_notification_for_marked_text(bool flag) const;
        /**
         * @brief Returns the `allowedInputSourceLocales` property of `NSTextFieldCell`.
         * @details Returns an array of locale identifiers representing keyboard input sources allowed to be enabled when the receiver has the keyboard focus.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> allowed_input_source_locales() const;
        /**
         * @brief Sets the `allowedInputSourceLocales` property of `NSTextFieldCell`.
         * @details Returns an array of locale identifiers representing keyboard input sources allowed to be enabled when the receiver has the keyboard focus.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allowed_input_source_locales(const std::vector<std::string>& value) const;
        /**
         * @brief Returns the `backgroundColor` property of `NSTextFieldCell`.
         * @return The converted Objective-C result.
         */
        Color background_color() const;
        /**
         * @brief Sets the `backgroundColor` property of `NSTextFieldCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_background_color(const Color& value) const;
        /**
         * @brief Returns the `bezelStyle` property of `NSTextFieldCell`.
         * @return The converted Objective-C result.
         */
        TextFieldBezelStyle bezel_style() const;
        /**
         * @brief Sets the `bezelStyle` property of `NSTextFieldCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_bezel_style(TextFieldBezelStyle value) const;
        /**
         * @brief Returns the `drawsBackground` property of `NSTextFieldCell`.
         * @return The converted Objective-C result.
         */
        bool draws_background() const;
        /**
         * @brief Sets the `drawsBackground` property of `NSTextFieldCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_draws_background(bool value) const;
        /**
         * @brief Returns the `placeholderAttributedString` property of `NSTextFieldCell`.
         * @return The converted Objective-C result.
         */
        AttributedString placeholder_attributed_string() const;
        /**
         * @brief Sets the `placeholderAttributedString` property of `NSTextFieldCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_placeholder_attributed_string(const AttributedString& value) const;
        /**
         * @brief Returns the `placeholderString` property of `NSTextFieldCell`.
         * @return The converted Objective-C result.
         */
        std::string placeholder_string() const;
        /**
         * @brief Sets the `placeholderString` property of `NSTextFieldCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_placeholder_string(const std::string& value) const;
        /**
         * @brief Returns the `textColor` property of `NSTextFieldCell`.
         * @return The converted Objective-C result.
         */
        Color text_color() const;
        /**
         * @brief Sets the `textColor` property of `NSTextFieldCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_text_color(const Color& value) const;
    };
}
