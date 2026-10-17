#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/matrix.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Font;
    class FormCell;

    /**
     * @brief C++ handle for the Objective-C class `NSForm` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Matrix.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Form form;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Form form{};
     * form.add_entry("text");
     * form.cell_at_index(1);
     * form.draw_cell_at_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsform
     */
    class Form : public Matrix
    {
    public:
        /// @brief Creates a new `NSForm` instance and returns a handle to it.
        explicit Form();
        /// @brief Creates a null handle that refers to no native object.
        Form(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Form(Adopt adopt);
        using View::set_frame_size;
        /**
     * @brief Calls `-[NSForm addEntry:]`.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        FormCell add_entry(const std::string& title) const;
        /**
     * @brief Calls `-[NSForm cellAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object cell_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSForm drawCellAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void draw_cell_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSForm indexOfCellWithTag:]`.
     * @param tag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_cell_with_tag(std::int64_t tag) const;
        /**
     * @brief Calls `-[NSForm indexOfSelectedItem]`.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_selected_item() const;
        /**
     * @brief Calls `-[NSForm insertEntry:atIndex:]`.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        FormCell insert_entry(const std::string& title, std::int64_t index) const;
        /**
     * @brief Calls `-[NSForm preferredTextFieldWidth]`.
     * @return The converted Objective-C result.
     */
        double preferred_text_field_width() const;
        /**
     * @brief Calls `-[NSForm removeEntryAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void remove_entry_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSForm selectTextAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void select_text_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSForm setBezeled:]`.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     */
        void set_bezeled(bool flag) const;
        /**
     * @brief Calls `-[NSForm setBordered:]`.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     */
        void set_bordered(bool flag) const;
        /**
     * @brief Calls `-[NSForm setEntryWidth:]`.
     * @param width Argument converted to the Objective-C parameter of the same role.
     */
        void set_entry_width(double width) const;
        /**
     * @brief Calls `-[NSForm setFrameSize:]`.
     * @param new_size Argument converted to the Objective-C parameter of the same role.
     */
        void set_frame_size(const Size& new_size) const;
        /**
     * @brief Calls `-[NSForm setInterlineSpacing:]`.
     * @param spacing Argument converted to the Objective-C parameter of the same role.
     */
        void set_interline_spacing(double spacing) const;
        /**
     * @brief Calls `-[NSForm setPreferredTextFieldWidth:]`.
     * @details Determine the preferred width of the text field portion of the receiver's cells. The preferred width is reflected in the cell's cellSize, which will be large enough to accommodate the title, bezel, and a text field of width preferredTextWidth. It is also reflected in the intrinsicContentSize of the NSForm. That is, under autolayout, the NSForm will try to size itself so that the text field cell is the given width, according to the usual content size constraint priorities. If the width is negative, the cellSize matches the historic behavior, which is that it is large enough to accommodate the title, bezel, and the current text. The default is -1. This method can aid migration to autolayout, and is sufficient for simple cases. However, for new apps, prefer to use NSTextFields directly instead of NSForm.
     * @param preferred_width Argument converted to the Objective-C parameter of the same role.
     */
        void set_preferred_text_field_width(double preferred_width) const;
        /**
     * @brief Calls `-[NSForm setTextAlignment:]`.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_alignment(TextAlignment mode) const;
        /**
     * @brief Calls `-[NSForm setTextBaseWritingDirection:]`.
     * @param writing_direction Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_base_writing_direction(WritingDirection writing_direction) const;
        /**
     * @brief Calls `-[NSForm setTextFont:]`.
     * @param font_obj Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_font(const Font& font_obj) const;
        /**
     * @brief Calls `-[NSForm setTitleAlignment:]`.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void set_title_alignment(TextAlignment mode) const;
        /**
     * @brief Calls `-[NSForm setTitleBaseWritingDirection:]`.
     * @param writing_direction Argument converted to the Objective-C parameter of the same role.
     */
        void set_title_base_writing_direction(WritingDirection writing_direction) const;
        /**
     * @brief Calls `-[NSForm setTitleFont:]`.
     * @param font_obj Argument converted to the Objective-C parameter of the same role.
     */
        void set_title_font(const Font& font_obj) const;
    };
}
