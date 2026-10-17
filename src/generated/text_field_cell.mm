#include "generated/text_field_cell.h"
#include "internal.h"

namespace cocoon
{
    TextFieldCell::TextFieldCell(const std::string& string) : TextFieldCell(Adopt{cocoon::internal::retain([[::NSTextFieldCell alloc] initTextCell:cocoon::internal::to(string)])})
    {
    }

    TextFieldCell::TextFieldCell() : TextFieldCell(Adopt{cocoon::internal::retain([[::NSTextFieldCell alloc] init])})
    {
    }

    TextFieldCell::TextFieldCell(std::nullptr_t) : ActionCell(nullptr)
    {
    }

    TextFieldCell::TextFieldCell(Adopt adopt) : ActionCell(adopt)
    {
    }

    Text TextFieldCell::set_up_field_editor_attributes(const Text& text_obj) const
    {
        return cocoon::internal::wrap<Text>([cocoon::internal::ns<::NSTextFieldCell>(this) setUpFieldEditorAttributes:cocoon::internal::native<::NSText>(text_obj)]);
    }

    void TextFieldCell::set_wants_notification_for_marked_text(bool flag) const
    {
        [cocoon::internal::ns<::NSTextFieldCell>(this) setWantsNotificationForMarkedText:static_cast<::BOOL>(flag)];
    }

    std::vector<std::string> TextFieldCell::allowed_input_source_locales() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTextFieldCell>(this) allowedInputSourceLocales], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void TextFieldCell::set_allowed_input_source_locales(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSTextFieldCell>(this) setAllowedInputSourceLocales:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                               {
                                                                                                                   return cocoon::internal::to(e);
                                                                                                               })];
    }

    Color TextFieldCell::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSTextFieldCell>(this) backgroundColor]);
    }

    void TextFieldCell::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSTextFieldCell>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    TextFieldBezelStyle TextFieldCell::bezel_style() const
    {
        return static_cast<TextFieldBezelStyle>([cocoon::internal::ns<::NSTextFieldCell>(this) bezelStyle]);
    }

    void TextFieldCell::set_bezel_style(TextFieldBezelStyle value) const
    {
        [cocoon::internal::ns<::NSTextFieldCell>(this) setBezelStyle:static_cast<::NSTextFieldBezelStyle>(value)];
    }

    bool TextFieldCell::draws_background() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextFieldCell>(this) drawsBackground]);
    }

    void TextFieldCell::set_draws_background(bool value) const
    {
        [cocoon::internal::ns<::NSTextFieldCell>(this) setDrawsBackground:static_cast<::BOOL>(value)];
    }

    AttributedString TextFieldCell::placeholder_attributed_string() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSTextFieldCell>(this) placeholderAttributedString]);
    }

    void TextFieldCell::set_placeholder_attributed_string(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSTextFieldCell>(this) setPlaceholderAttributedString:cocoon::internal::native<::NSAttributedString>(value)];
    }

    std::string TextFieldCell::placeholder_string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextFieldCell>(this) placeholderString]);
    }

    void TextFieldCell::set_placeholder_string(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTextFieldCell>(this) setPlaceholderString:cocoon::internal::to(value)];
    }

    Color TextFieldCell::text_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSTextFieldCell>(this) textColor]);
    }

    void TextFieldCell::set_text_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSTextFieldCell>(this) setTextColor:cocoon::internal::native<::NSColor>(value)];
    }
}
