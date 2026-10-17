#pragma once

#include "generated/action_cell.h"
#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class Font;

    /**
     * @brief C++ handle for the Objective-C class `NSFormCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ActionCell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::FormCell form_cell;
     * form_cell.set_attributed_title(cocoon::AttributedString());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::FormCell form_cell{};
     * form_cell.set_attributed_title(cocoon::AttributedString());
     * auto attributed_title = form_cell.attributed_title();
     * form_cell.set_placeholder_attributed_string(cocoon::AttributedString());
     * auto placeholder_attributed_string = form_cell.placeholder_attributed_string();
     * form_cell.set_placeholder_string("text");
     * auto placeholder_string = form_cell.placeholder_string();
     * form_cell.title_width({100, 100});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsformcell
     */
    class FormCell : public ActionCell
    {
    public:
        /// @brief Creates a new `NSFormCell` instance and returns a handle to it.
        explicit FormCell(const std::string& string);
        /// @brief Creates a new `NSFormCell` instance and returns a handle to it.
        explicit FormCell();
        /// @brief Creates a null handle that refers to no native object.
        FormCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit FormCell(Adopt adopt);
        using Cell::is_opaque;
        using Cell::set_title;
        using Cell::title;
        /**
     * @brief Calls `-[NSFormCell titleWidth:]`.
     * @param size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double title_width(const Size& size) const;
        /**
     * @brief Returns the `attributedTitle` property of `NSFormCell`.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_title() const;
        /**
     * @brief Sets the `attributedTitle` property of `NSFormCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_title(const AttributedString& value) const;
        /**
     * @brief Returns the `opaque` property of `NSFormCell`.
     * @return The converted Objective-C result.
     */
        bool is_opaque() const;
        /**
     * @brief Returns the `placeholderAttributedString` property of `NSFormCell`.
     * @return The converted Objective-C result.
     */
        AttributedString placeholder_attributed_string() const;
        /**
     * @brief Sets the `placeholderAttributedString` property of `NSFormCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_placeholder_attributed_string(const AttributedString& value) const;
        /**
     * @brief Returns the `placeholderString` property of `NSFormCell`.
     * @return The converted Objective-C result.
     */
        std::string placeholder_string() const;
        /**
     * @brief Sets the `placeholderString` property of `NSFormCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_placeholder_string(const std::string& value) const;
        /**
     * @brief Returns the `preferredTextFieldWidth` property of `NSFormCell`.
     * @details Determine the preferred width of the text field portion of the receiver. The preferred width is reflected in the cell's cellSize, which will be large enough to accommodate the title, bezel, and a text field of width preferredTextWidth. It is also reflected in the intrinsicContentSize of the NSForm. That is, under autolayout, the NSForm will try to size itself so that the text field cell is the given width, according to the usual content size constraint priorities. If the width is negative, the cellSize matches the historic behavior, which is that it is large enough to accommodate the title, bezel, and the current text. The default is -1. This method can aid migration to autolayout, and is sufficient for simple cases. However, for new apps, prefer to use NSTextFields directly instead of NSForm.
     * @return The converted Objective-C result.
     */
        double preferred_text_field_width() const;
        /**
     * @brief Sets the `preferredTextFieldWidth` property of `NSFormCell`.
     * @details Determine the preferred width of the text field portion of the receiver. The preferred width is reflected in the cell's cellSize, which will be large enough to accommodate the title, bezel, and a text field of width preferredTextWidth. It is also reflected in the intrinsicContentSize of the NSForm. That is, under autolayout, the NSForm will try to size itself so that the text field cell is the given width, according to the usual content size constraint priorities. If the width is negative, the cellSize matches the historic behavior, which is that it is large enough to accommodate the title, bezel, and the current text. The default is -1. This method can aid migration to autolayout, and is sufficient for simple cases. However, for new apps, prefer to use NSTextFields directly instead of NSForm.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preferred_text_field_width(double value) const;
        /**
     * @brief Returns the `title` property of `NSFormCell`.
     * @return The converted Objective-C result.
     */
        std::string title() const;
        /**
     * @brief Sets the `title` property of `NSFormCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title(const std::string& value) const;
        /**
     * @brief Returns the `titleAlignment` property of `NSFormCell`.
     * @return The converted Objective-C result.
     */
        TextAlignment title_alignment() const;
        /**
     * @brief Sets the `titleAlignment` property of `NSFormCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title_alignment(TextAlignment value) const;
        /**
     * @brief Returns the `titleBaseWritingDirection` property of `NSFormCell`.
     * @return The converted Objective-C result.
     */
        WritingDirection title_base_writing_direction() const;
        /**
     * @brief Sets the `titleBaseWritingDirection` property of `NSFormCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title_base_writing_direction(WritingDirection value) const;
        /**
     * @brief Returns the `titleFont` property of `NSFormCell`.
     * @return The converted Objective-C result.
     */
        Font title_font() const;
        /**
     * @brief Sets the `titleFont` property of `NSFormCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title_font(const Font& value) const;
        /**
     * @brief Returns the `titleWidth` property of `NSFormCell`.
     * @return The converted Objective-C result.
     */
        double title_width() const;
        /**
     * @brief Sets the `titleWidth` property of `NSFormCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title_width(double value) const;
    };
}
