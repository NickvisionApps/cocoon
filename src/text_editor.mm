#include "internal.h"
#include "text_editor.h"

namespace cocoon
{
    TextEditor::TextEditor(Adopt adopt) : View(adopt)
    {
    }

    TextEditor::TextEditor() : TextEditor(Adopt{cocoon::internal::retain([NSTextView scrollableTextView])})
    {
        id host = cocoon::internal::obj(this);
        cocoon::internal::observe(host, ((NSScrollView*)host).documentView, NSTextDidChangeNotification, [](id host, id note)
                                  {
                                      Signal<TextEditor, void(const std::string&)>::emit((__bridge void*)host, "text_changed", cocoon::internal::from(((NSTextView*)((NSScrollView*)host).documentView).string));
                                  });
    }

    std::string TextEditor::text() const
    {
        return cocoon::internal::from(((NSTextView*)cocoon::internal::ns<NSScrollView>(this).documentView).string);
    }

    void TextEditor::set_text(const std::string& text) const
    {
        ((NSTextView*)cocoon::internal::ns<NSScrollView>(this).documentView).string = cocoon::internal::to(text);
    }

    bool TextEditor::is_editable() const
    {
        return ((NSTextView*)cocoon::internal::ns<NSScrollView>(this).documentView).editable;
    }

    void TextEditor::set_editable(bool editable) const
    {
        ((NSTextView*)cocoon::internal::ns<NSScrollView>(this).documentView).editable = editable;
    }

    void TextEditor::set_font(const Font& font) const
    {
        ((NSTextView*)cocoon::internal::ns<NSScrollView>(this).documentView).font = cocoon::internal::native<NSFont>(font);
    }
}
