#include "generated/text_input_context.h"
#include "internal.h"

namespace cocoon
{
    TextInputContext::TextInputContext(const Object& client) : TextInputContext(Adopt{cocoon::internal::retain([[::NSTextInputContext alloc] initWithClient:cocoon::internal::native_id(client)])})
    {
    }

    TextInputContext::TextInputContext() : Object(nullptr)
    {
    }

    TextInputContext::TextInputContext(std::nullptr_t) : Object(nullptr)
    {
    }

    TextInputContext::TextInputContext(Adopt adopt) : Object(adopt)
    {
    }

    void TextInputContext::activate() const
    {
        [cocoon::internal::ns<::NSTextInputContext>(this) activate];
    }

    void TextInputContext::deactivate() const
    {
        [cocoon::internal::ns<::NSTextInputContext>(this) deactivate];
    }

    void TextInputContext::discard_marked_text() const
    {
        [cocoon::internal::ns<::NSTextInputContext>(this) discardMarkedText];
    }

    bool TextInputContext::handle_event(const Event& event) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextInputContext>(this) handleEvent:cocoon::internal::native<::NSEvent>(event)]);
    }

    void TextInputContext::invalidate_character_coordinates() const
    {
        [cocoon::internal::ns<::NSTextInputContext>(this) invalidateCharacterCoordinates];
    }

    std::string TextInputContext::localized_name_for_input_source(const std::string& input_source_identifier)
    {
        return cocoon::internal::from([::NSTextInputContext localizedNameForInputSource:cocoon::internal::to(input_source_identifier)]);
    }

    void TextInputContext::text_input_client_did_end_scrolling_or_zooming() const
    {
        [cocoon::internal::ns<::NSTextInputContext>(this) textInputClientDidEndScrollingOrZooming];
    }

    void TextInputContext::text_input_client_did_scroll() const
    {
        [cocoon::internal::ns<::NSTextInputContext>(this) textInputClientDidScroll];
    }

    void TextInputContext::text_input_client_did_update_selection() const
    {
        [cocoon::internal::ns<::NSTextInputContext>(this) textInputClientDidUpdateSelection];
    }

    void TextInputContext::text_input_client_will_start_scrolling_or_zooming() const
    {
        [cocoon::internal::ns<::NSTextInputContext>(this) textInputClientWillStartScrollingOrZooming];
    }

    bool TextInputContext::accepts_glyph_info() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextInputContext>(this) acceptsGlyphInfo]);
    }

    void TextInputContext::set_accepts_glyph_info(bool value) const
    {
        [cocoon::internal::ns<::NSTextInputContext>(this) setAcceptsGlyphInfo:static_cast<::BOOL>(value)];
    }

    std::vector<std::string> TextInputContext::allowed_input_source_locales() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTextInputContext>(this) allowedInputSourceLocales], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void TextInputContext::set_allowed_input_source_locales(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSTextInputContext>(this) setAllowedInputSourceLocales:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                                  {
                                                                                                                      return cocoon::internal::to(e);
                                                                                                                  })];
    }

    TextInputContext TextInputContext::current_input_context()
    {
        return cocoon::internal::wrap<TextInputContext>([::NSTextInputContext currentInputContext]);
    }

    std::vector<std::string> TextInputContext::keyboard_input_sources() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTextInputContext>(this) keyboardInputSources], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::string TextInputContext::selected_keyboard_input_source() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextInputContext>(this) selectedKeyboardInputSource]);
    }

    void TextInputContext::set_selected_keyboard_input_source(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTextInputContext>(this) setSelectedKeyboardInputSource:cocoon::internal::to(value)];
    }
}
