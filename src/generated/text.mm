#include "generated/text.h"
#include "internal.h"

@interface AKTextDelegate : NSObject <NSTextDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKTextDelegate

- (BOOL)textShouldBeginEditing:(NSText*)textObject
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Text, bool()>::emit((__bridge void*)strongHost, "should_begin_editing");
    return static_cast<::BOOL>(__r);
}

- (BOOL)textShouldEndEditing:(NSText*)textObject
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Text, bool()>::emit((__bridge void*)strongHost, "should_end_editing");
    return static_cast<::BOOL>(__r);
}

- (void)textDidBeginEditing:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Text, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_begin_editing", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)textDidEndEditing:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Text, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_end_editing", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)textDidChange:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Text, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_change", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(textShouldBeginEditing:))
    {
        return strongHost && cocoon::Signal<cocoon::Text, bool()>::connected((__bridge void*)strongHost, "should_begin_editing");
    }
    if (selector == @selector(textShouldEndEditing:))
    {
        return strongHost && cocoon::Signal<cocoon::Text, bool()>::connected((__bridge void*)strongHost, "should_end_editing");
    }
    if (selector == @selector(textDidBeginEditing:))
    {
        return strongHost && cocoon::Signal<cocoon::Text, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_begin_editing");
    }
    if (selector == @selector(textDidEndEditing:))
    {
        return strongHost && cocoon::Signal<cocoon::Text, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_end_editing");
    }
    if (selector == @selector(textDidChange:))
    {
        return strongHost && cocoon::Signal<cocoon::Text, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_change");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    Text::Text(const Rect& frame_rect) : Text(Adopt{cocoon::internal::retain([[::NSText alloc] initWithFrame:cocoon::internal::to(frame_rect)])})
    {
        Text::install_delegate_delegate_(handle());
    }

    Text::Text() : Text(Adopt{cocoon::internal::retain([[::NSText alloc] init])})
    {
        Text::install_delegate_delegate_(handle());
    }

    Text::Text(std::nullptr_t) : View(nullptr)
    {
    }

    Text::Text(Adopt adopt) : View(adopt)
    {
    }

    std::vector<std::uint8_t> Text::rtfd_from_range(const Range& range) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSText>(this) RTFDFromRange:cocoon::internal::to(range)]);
    }

    std::vector<std::uint8_t> Text::rtf_from_range(const Range& range) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSText>(this) RTFFromRange:cocoon::internal::to(range)]);
    }

    void Text::align_center(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) alignCenter:cocoon::internal::native_id(sender)];
    }

    void Text::align_left(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) alignLeft:cocoon::internal::native_id(sender)];
    }

    void Text::align_right(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) alignRight:cocoon::internal::native_id(sender)];
    }

    void Text::change_font(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) changeFont:cocoon::internal::native_id(sender)];
    }

    void Text::check_spelling(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) checkSpelling:cocoon::internal::native_id(sender)];
    }

    void Text::copy(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) copy:cocoon::internal::native_id(sender)];
    }

    void Text::copy_font(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) copyFont:cocoon::internal::native_id(sender)];
    }

    void Text::copy_ruler(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) copyRuler:cocoon::internal::native_id(sender)];
    }

    void Text::cut(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) cut:cocoon::internal::native_id(sender)];
    }

    void Text::delete_(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) delete:cocoon::internal::native_id(sender)];
    }

    void Text::paste(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) paste:cocoon::internal::native_id(sender)];
    }

    void Text::paste_font(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) pasteFont:cocoon::internal::native_id(sender)];
    }

    void Text::paste_ruler(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) pasteRuler:cocoon::internal::native_id(sender)];
    }

    bool Text::read_rtfd_from_file(const std::string& path) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSText>(this) readRTFDFromFile:cocoon::internal::to(path)]);
    }

    void Text::replace_characters_in_range(const Range& range, const std::vector<std::uint8_t>& rtf_data) const
    {
        [cocoon::internal::ns<::NSText>(this) replaceCharactersInRange:cocoon::internal::to(range) withRTF:cocoon::internal::to_data(rtf_data)];
    }

    void Text::replace_characters_in_range(const Range& range, const std::string& string) const
    {
        [cocoon::internal::ns<::NSText>(this) replaceCharactersInRange:cocoon::internal::to(range) withString:cocoon::internal::to(string)];
    }

    void Text::scroll_range_to_visible(const Range& range) const
    {
        [cocoon::internal::ns<::NSText>(this) scrollRangeToVisible:cocoon::internal::to(range)];
    }

    void Text::select_all(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) selectAll:cocoon::internal::native_id(sender)];
    }

    void Text::set_font(const Font& font, const Range& range) const
    {
        [cocoon::internal::ns<::NSText>(this) setFont:cocoon::internal::native<::NSFont>(font) range:cocoon::internal::to(range)];
    }

    void Text::set_text_color(const Color& color, const Range& range) const
    {
        [cocoon::internal::ns<::NSText>(this) setTextColor:cocoon::internal::native<::NSColor>(color) range:cocoon::internal::to(range)];
    }

    void Text::show_guess_panel(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) showGuessPanel:cocoon::internal::native_id(sender)];
    }

    void Text::size_to_fit() const
    {
        [cocoon::internal::ns<::NSText>(this) sizeToFit];
    }

    void Text::subscript(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) subscript:cocoon::internal::native_id(sender)];
    }

    void Text::superscript(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) superscript:cocoon::internal::native_id(sender)];
    }

    void Text::toggle_ruler(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) toggleRuler:cocoon::internal::native_id(sender)];
    }

    void Text::underline(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) underline:cocoon::internal::native_id(sender)];
    }

    void Text::unscript(const Object& sender) const
    {
        [cocoon::internal::ns<::NSText>(this) unscript:cocoon::internal::native_id(sender)];
    }

    bool Text::write_rtfd_to_file(const std::string& path, bool flag) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSText>(this) writeRTFDToFile:cocoon::internal::to(path) atomically:static_cast<::BOOL>(flag)]);
    }

    TextAlignment Text::alignment() const
    {
        return static_cast<TextAlignment>([cocoon::internal::ns<::NSText>(this) alignment]);
    }

    void Text::set_alignment(TextAlignment value) const
    {
        [cocoon::internal::ns<::NSText>(this) setAlignment:static_cast<::NSTextAlignment>(value)];
    }

    Color Text::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSText>(this) backgroundColor]);
    }

    void Text::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSText>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    WritingDirection Text::base_writing_direction() const
    {
        return static_cast<WritingDirection>([cocoon::internal::ns<::NSText>(this) baseWritingDirection]);
    }

    void Text::set_base_writing_direction(WritingDirection value) const
    {
        [cocoon::internal::ns<::NSText>(this) setBaseWritingDirection:static_cast<::NSWritingDirection>(value)];
    }

    bool Text::draws_background() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSText>(this) drawsBackground]);
    }

    void Text::set_draws_background(bool value) const
    {
        [cocoon::internal::ns<::NSText>(this) setDrawsBackground:static_cast<::BOOL>(value)];
    }

    bool Text::is_editable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSText>(this) isEditable]);
    }

    void Text::set_editable(bool value) const
    {
        [cocoon::internal::ns<::NSText>(this) setEditable:static_cast<::BOOL>(value)];
    }

    bool Text::is_field_editor() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSText>(this) isFieldEditor]);
    }

    void Text::set_field_editor(bool value) const
    {
        [cocoon::internal::ns<::NSText>(this) setFieldEditor:static_cast<::BOOL>(value)];
    }

    Font Text::font() const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSText>(this) font]);
    }

    void Text::set_font(const Font& value) const
    {
        [cocoon::internal::ns<::NSText>(this) setFont:cocoon::internal::native<::NSFont>(value)];
    }

    bool Text::is_horizontally_resizable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSText>(this) isHorizontallyResizable]);
    }

    void Text::set_horizontally_resizable(bool value) const
    {
        [cocoon::internal::ns<::NSText>(this) setHorizontallyResizable:static_cast<::BOOL>(value)];
    }

    bool Text::imports_graphics() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSText>(this) importsGraphics]);
    }

    void Text::set_imports_graphics(bool value) const
    {
        [cocoon::internal::ns<::NSText>(this) setImportsGraphics:static_cast<::BOOL>(value)];
    }

    Size Text::max_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSText>(this) maxSize]);
    }

    void Text::set_max_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSText>(this) setMaxSize:cocoon::internal::to(value)];
    }

    Size Text::min_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSText>(this) minSize]);
    }

    void Text::set_min_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSText>(this) setMinSize:cocoon::internal::to(value)];
    }

    bool Text::is_rich_text() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSText>(this) isRichText]);
    }

    void Text::set_rich_text(bool value) const
    {
        [cocoon::internal::ns<::NSText>(this) setRichText:static_cast<::BOOL>(value)];
    }

    bool Text::is_ruler_visible() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSText>(this) isRulerVisible]);
    }

    bool Text::is_selectable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSText>(this) isSelectable]);
    }

    void Text::set_selectable(bool value) const
    {
        [cocoon::internal::ns<::NSText>(this) setSelectable:static_cast<::BOOL>(value)];
    }

    Range Text::selected_range() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSText>(this) selectedRange]);
    }

    void Text::set_selected_range(const Range& value) const
    {
        [cocoon::internal::ns<::NSText>(this) setSelectedRange:cocoon::internal::to(value)];
    }

    std::string Text::string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSText>(this) string]);
    }

    void Text::set_string(const std::string& value) const
    {
        [cocoon::internal::ns<::NSText>(this) setString:cocoon::internal::to(value)];
    }

    Color Text::text_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSText>(this) textColor]);
    }

    void Text::set_text_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSText>(this) setTextColor:cocoon::internal::native<::NSColor>(value)];
    }

    bool Text::uses_font_panel() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSText>(this) usesFontPanel]);
    }

    void Text::set_uses_font_panel(bool value) const
    {
        [cocoon::internal::ns<::NSText>(this) setUsesFontPanel:static_cast<::BOOL>(value)];
    }

    bool Text::is_vertically_resizable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSText>(this) isVerticallyResizable]);
    }

    void Text::set_vertically_resizable(bool value) const
    {
        [cocoon::internal::ns<::NSText>(this) setVerticallyResizable:static_cast<::BOOL>(value)];
    }

    void Text::install_delegate_delegate_(void* native)
    {
        ::NSText* host = (__bridge ::NSText*)native;
        AKTextDelegate* delegate = [[AKTextDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSText* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSText* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
