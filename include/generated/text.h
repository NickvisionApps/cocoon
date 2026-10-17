#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class Font;
    class Notification;

    /**
     * @brief C++ handle for the Objective-C class `NSText` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Text text;
     * text.set_alignment(cocoon::TextAlignment::Left);
     * text.did_begin_editing().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Text text{};
     * text.set_alignment(cocoon::TextAlignment::Left);
     * auto alignment = text.alignment();
     * text.set_background_color(cocoon::Color());
     * auto background_color = text.background_color();
     * text.set_base_writing_direction(cocoon::WritingDirection::Natural);
     * auto base_writing_direction = text.base_writing_direction();
     * text.read_rtfd_from_file("text");
     * text.size_to_fit();
     * text.write_rtfd_to_file("text", true);
     * text.did_begin_editing().connect([](cocoon::Notification a0) {});
     * text.did_end_editing().connect([](cocoon::Notification a0) {});
     * text.did_change().connect([](cocoon::Notification a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstext
     */
    class Text : public View
    {
    public:
        /// @brief Creates a new `NSText` instance and returns a handle to it.
        explicit Text(const Rect& frame_rect);
        /// @brief Creates a new `NSText` instance and returns a handle to it.
        explicit Text();
        /// @brief Creates a null handle that refers to no native object.
        Text(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Text(Adopt adopt);
        using View::set_background_color;
        /**
     * @brief Calls `-[NSText RTFDFromRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> rtfd_from_range(const Range& range) const;
        /**
     * @brief Calls `-[NSText RTFFromRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> rtf_from_range(const Range& range) const;
        /**
     * @brief Calls `-[NSText alignCenter:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void align_center(const Object& sender) const;
        /**
     * @brief Calls `-[NSText alignLeft:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void align_left(const Object& sender) const;
        /**
     * @brief Calls `-[NSText alignRight:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void align_right(const Object& sender) const;
        /**
     * @brief Calls `-[NSText changeFont:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void change_font(const Object& sender) const;
        /**
     * @brief Calls `-[NSText checkSpelling:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void check_spelling(const Object& sender) const;
        /**
     * @brief Calls `-[NSText copy:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void copy(const Object& sender) const;
        /**
     * @brief Calls `-[NSText copyFont:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void copy_font(const Object& sender) const;
        /**
     * @brief Calls `-[NSText copyRuler:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void copy_ruler(const Object& sender) const;
        /**
     * @brief Calls `-[NSText cut:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void cut(const Object& sender) const;
        /**
     * @brief Calls `-[NSText delete:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void delete_(const Object& sender) const;
        /**
     * @brief Calls `-[NSText paste:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void paste(const Object& sender) const;
        /**
     * @brief Calls `-[NSText pasteFont:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void paste_font(const Object& sender) const;
        /**
     * @brief Calls `-[NSText pasteRuler:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void paste_ruler(const Object& sender) const;
        /**
     * @brief Calls `-[NSText readRTFDFromFile:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool read_rtfd_from_file(const std::string& path) const;
        /**
     * @brief Calls `-[NSText replaceCharactersInRange:withRTF:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param rtf_data Argument converted to the Objective-C parameter of the same role.
     */
        void replace_characters_in_range(const Range& range, const std::vector<std::uint8_t>& rtf_data) const;
        /**
     * @brief Calls `-[NSText replaceCharactersInRange:withString:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param string Argument converted to the Objective-C parameter of the same role.
     */
        void replace_characters_in_range(const Range& range, const std::string& string) const;
        /**
     * @brief Calls `-[NSText scrollRangeToVisible:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void scroll_range_to_visible(const Range& range) const;
        /**
     * @brief Calls `-[NSText selectAll:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void select_all(const Object& sender) const;
        /**
     * @brief Calls `-[NSText setFont:range:]`.
     * @param font Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void set_font(const Font& font, const Range& range) const;
        /**
     * @brief Calls `-[NSText setTextColor:range:]`.
     * @param color Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_color(const Color& color, const Range& range) const;
        /**
     * @brief Calls `-[NSText showGuessPanel:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void show_guess_panel(const Object& sender) const;
        /**
     * @brief Calls `-[NSText sizeToFit]`.
     */
        void size_to_fit() const;
        /**
     * @brief Calls `-[NSText subscript:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void subscript(const Object& sender) const;
        /**
     * @brief Calls `-[NSText superscript:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void superscript(const Object& sender) const;
        /**
     * @brief Calls `-[NSText toggleRuler:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void toggle_ruler(const Object& sender) const;
        /**
     * @brief Calls `-[NSText underline:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void underline(const Object& sender) const;
        /**
     * @brief Calls `-[NSText unscript:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void unscript(const Object& sender) const;
        /**
     * @brief Calls `-[NSText writeRTFDToFile:atomically:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool write_rtfd_to_file(const std::string& path, bool flag) const;
        /**
     * @brief Returns the `alignment` property of `NSText`.
     * @return The converted Objective-C result.
     */
        TextAlignment alignment() const;
        /**
     * @brief Sets the `alignment` property of `NSText`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_alignment(TextAlignment value) const;
        /**
     * @brief Returns the `backgroundColor` property of `NSText`.
     * @return The converted Objective-C result.
     */
        Color background_color() const;
        /**
     * @brief Sets the `backgroundColor` property of `NSText`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_color(const Color& value) const;
        /**
     * @brief Returns the `baseWritingDirection` property of `NSText`.
     * @return The converted Objective-C result.
     */
        WritingDirection base_writing_direction() const;
        /**
     * @brief Sets the `baseWritingDirection` property of `NSText`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_base_writing_direction(WritingDirection value) const;
        /**
     * @brief Returns the `drawsBackground` property of `NSText`.
     * @return The converted Objective-C result.
     */
        bool draws_background() const;
        /**
     * @brief Sets the `drawsBackground` property of `NSText`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_draws_background(bool value) const;
        /**
     * @brief Returns the `editable` property of `NSText`.
     * @return The converted Objective-C result.
     */
        bool is_editable() const;
        /**
     * @brief Sets the `editable` property of `NSText`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_editable(bool value) const;
        /**
     * @brief Returns the `fieldEditor` property of `NSText`.
     * @return The converted Objective-C result.
     */
        bool is_field_editor() const;
        /**
     * @brief Sets the `fieldEditor` property of `NSText`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_field_editor(bool value) const;
        /**
     * @brief Returns the `font` property of `NSText`.
     * @return The converted Objective-C result.
     */
        Font font() const;
        /**
     * @brief Sets the `font` property of `NSText`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_font(const Font& value) const;
        /**
     * @brief Returns the `horizontallyResizable` property of `NSText`.
     * @return The converted Objective-C result.
     */
        bool is_horizontally_resizable() const;
        /**
     * @brief Sets the `horizontallyResizable` property of `NSText`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_horizontally_resizable(bool value) const;
        /**
     * @brief Returns the `importsGraphics` property of `NSText`.
     * @return The converted Objective-C result.
     */
        bool imports_graphics() const;
        /**
     * @brief Sets the `importsGraphics` property of `NSText`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_imports_graphics(bool value) const;
        /**
     * @brief Returns the `maxSize` property of `NSText`.
     * @return The converted Objective-C result.
     */
        Size max_size() const;
        /**
     * @brief Sets the `maxSize` property of `NSText`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_max_size(const Size& value) const;
        /**
     * @brief Returns the `minSize` property of `NSText`.
     * @return The converted Objective-C result.
     */
        Size min_size() const;
        /**
     * @brief Sets the `minSize` property of `NSText`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_min_size(const Size& value) const;
        /**
     * @brief Returns the `richText` property of `NSText`.
     * @return The converted Objective-C result.
     */
        bool is_rich_text() const;
        /**
     * @brief Sets the `richText` property of `NSText`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_rich_text(bool value) const;
        /**
     * @brief Returns the `rulerVisible` property of `NSText`.
     * @return The converted Objective-C result.
     */
        bool is_ruler_visible() const;
        /**
     * @brief Returns the `selectable` property of `NSText`.
     * @return The converted Objective-C result.
     */
        bool is_selectable() const;
        /**
     * @brief Sets the `selectable` property of `NSText`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selectable(bool value) const;
        /**
     * @brief Returns the `selectedRange` property of `NSText`.
     * @return The converted Objective-C result.
     */
        Range selected_range() const;
        /**
     * @brief Sets the `selectedRange` property of `NSText`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selected_range(const Range& value) const;
        /**
     * @brief Returns the `string` property of `NSText`.
     * @return The converted Objective-C result.
     */
        std::string string() const;
        /**
     * @brief Sets the `string` property of `NSText`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_string(const std::string& value) const;
        /**
     * @brief Returns the `textColor` property of `NSText`.
     * @return The converted Objective-C result.
     */
        Color text_color() const;
        /**
     * @brief Sets the `textColor` property of `NSText`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_color(const Color& value) const;
        /**
     * @brief Returns the `usesFontPanel` property of `NSText`.
     * @return The converted Objective-C result.
     */
        bool uses_font_panel() const;
        /**
     * @brief Sets the `usesFontPanel` property of `NSText`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_font_panel(bool value) const;
        /**
     * @brief Returns the `verticallyResizable` property of `NSText`.
     * @return The converted Objective-C result.
     */
        bool is_vertically_resizable() const;
        /**
     * @brief Sets the `verticallyResizable` property of `NSText`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_vertically_resizable(bool value) const;
        /// @brief Signal for the delegate/data-source method behind `should_begin_editing`; connect a callback with `should_begin_editing().connect(...)`.
        Signal<Text, bool()> should_begin_editing() const
        {
            return Signal<Text, bool()>(handle(), "should_begin_editing");
        }
        /// @brief Signal for the delegate/data-source method behind `should_end_editing`; connect a callback with `should_end_editing().connect(...)`.
        Signal<Text, bool()> should_end_editing() const
        {
            return Signal<Text, bool()>(handle(), "should_end_editing");
        }
        /// @brief Signal for the delegate/data-source method behind `did_begin_editing`; connect a callback with `did_begin_editing().connect(...)`.
        Signal<Text, void(Notification)> did_begin_editing() const
        {
            return Signal<Text, void(Notification)>(handle(), "did_begin_editing");
        }
        /// @brief Signal for the delegate/data-source method behind `did_end_editing`; connect a callback with `did_end_editing().connect(...)`.
        Signal<Text, void(Notification)> did_end_editing() const
        {
            return Signal<Text, void(Notification)>(handle(), "did_end_editing");
        }
        /// @brief Signal for the delegate/data-source method behind `did_change`; connect a callback with `did_change().connect(...)`.
        Signal<Text, void(Notification)> did_change() const
        {
            return Signal<Text, void(Notification)>(handle(), "did_change");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
