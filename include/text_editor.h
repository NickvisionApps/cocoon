#pragma once

#include <string>
#include "generated/font.h"
#include "generated/view.h"

namespace cocoon
{
    /**
     * @brief A scrollable multi-line text editor (NSTextView in a scroll view).
     * @par Example
     * @code
     * cocoon::TextEditor editor;
     * editor.set_text("Hello");
     * editor.set_font(cocoon::Font::monospaced_system_font_of_size(13, cocoon::FontWeight::regular()));
     * editor.text_changed().connect([](const std::string& text) { });
     * @endcode
     */
    class TextEditor : public View
    {
    public:
        /// Creates an empty editor.
        TextEditor();
        /// Creates a null handle.
        TextEditor(std::nullptr_t) : View(nullptr)
        {
        }
        /// Wraps an existing native scroll view.
        explicit TextEditor(Adopt adopt);

        /// @return The current text.
        std::string text() const;
        /// Replaces the text.
        void set_text(const std::string& text) const;
        /// @return True if the user can edit the text.
        bool is_editable() const;
        /// Enables or disables editing.
        void set_editable(bool editable) const;
        /// Sets the text font.
        void set_font(const Font& font) const;

        /// Signal emitted with the full text after every edit.
        Signal<TextEditor, void(const std::string&)> text_changed() const
        {
            return Signal<TextEditor, void(const std::string&)>(handle(), "text_changed");
        }
    };
}
