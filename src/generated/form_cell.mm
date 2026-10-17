#include "generated/form_cell.h"
#include "internal.h"

namespace cocoon
{
    FormCell::FormCell(const std::string& string) : FormCell(Adopt{cocoon::internal::retain([[::NSFormCell alloc] initTextCell:cocoon::internal::to(string)])})
    {
    }

    FormCell::FormCell() : FormCell(Adopt{cocoon::internal::retain([[::NSFormCell alloc] init])})
    {
    }

    FormCell::FormCell(std::nullptr_t) : ActionCell(nullptr)
    {
    }

    FormCell::FormCell(Adopt adopt) : ActionCell(adopt)
    {
    }

    double FormCell::title_width(const Size& size) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSFormCell>(this) titleWidth:cocoon::internal::to(size)]);
    }

    AttributedString FormCell::attributed_title() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSFormCell>(this) attributedTitle]);
    }

    void FormCell::set_attributed_title(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSFormCell>(this) setAttributedTitle:cocoon::internal::native<::NSAttributedString>(value)];
    }

    bool FormCell::is_opaque() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFormCell>(this) isOpaque]);
    }

    AttributedString FormCell::placeholder_attributed_string() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSFormCell>(this) placeholderAttributedString]);
    }

    void FormCell::set_placeholder_attributed_string(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSFormCell>(this) setPlaceholderAttributedString:cocoon::internal::native<::NSAttributedString>(value)];
    }

    std::string FormCell::placeholder_string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFormCell>(this) placeholderString]);
    }

    void FormCell::set_placeholder_string(const std::string& value) const
    {
        [cocoon::internal::ns<::NSFormCell>(this) setPlaceholderString:cocoon::internal::to(value)];
    }

    double FormCell::preferred_text_field_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSFormCell>(this) preferredTextFieldWidth]);
    }

    void FormCell::set_preferred_text_field_width(double value) const
    {
        [cocoon::internal::ns<::NSFormCell>(this) setPreferredTextFieldWidth:static_cast<::CGFloat>(value)];
    }

    std::string FormCell::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFormCell>(this) title]);
    }

    void FormCell::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSFormCell>(this) setTitle:cocoon::internal::to(value)];
    }

    TextAlignment FormCell::title_alignment() const
    {
        return static_cast<TextAlignment>([cocoon::internal::ns<::NSFormCell>(this) titleAlignment]);
    }

    void FormCell::set_title_alignment(TextAlignment value) const
    {
        [cocoon::internal::ns<::NSFormCell>(this) setTitleAlignment:static_cast<::NSTextAlignment>(value)];
    }

    WritingDirection FormCell::title_base_writing_direction() const
    {
        return static_cast<WritingDirection>([cocoon::internal::ns<::NSFormCell>(this) titleBaseWritingDirection]);
    }

    void FormCell::set_title_base_writing_direction(WritingDirection value) const
    {
        [cocoon::internal::ns<::NSFormCell>(this) setTitleBaseWritingDirection:static_cast<::NSWritingDirection>(value)];
    }

    Font FormCell::title_font() const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSFormCell>(this) titleFont]);
    }

    void FormCell::set_title_font(const Font& value) const
    {
        [cocoon::internal::ns<::NSFormCell>(this) setTitleFont:cocoon::internal::native<::NSFont>(value)];
    }

    double FormCell::title_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSFormCell>(this) titleWidth]);
    }

    void FormCell::set_title_width(double value) const
    {
        [cocoon::internal::ns<::NSFormCell>(this) setTitleWidth:static_cast<::CGFloat>(value)];
    }
}
