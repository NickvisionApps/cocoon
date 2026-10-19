#include "generated/text_field.h"
#include "internal.h"

@interface AKTextFieldDelegate : NSObject <NSTextFieldDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKTextFieldDelegate

- (void)controlTextDidBeginEditing:(NSNotification*)obj
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextField, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "control_text_did_begin_editing", cocoon::internal::wrap<cocoon::Notification>(obj));
}

- (void)controlTextDidEndEditing:(NSNotification*)obj
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextField, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "control_text_did_end_editing", cocoon::internal::wrap<cocoon::Notification>(obj));
}

- (void)controlTextDidChange:(NSNotification*)obj
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextField, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "control_text_did_change", cocoon::internal::wrap<cocoon::Notification>(obj));
}

- (BOOL)control:(NSControl*)control textShouldBeginEditing:(NSText*)fieldEditor
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextField, bool(cocoon::Text)>::emit((__bridge void*)strongHost, "control_text_should_begin_editing", cocoon::internal::wrap<cocoon::Text>(fieldEditor));
    return static_cast<::BOOL>(__r);
}

- (BOOL)control:(NSControl*)control textShouldEndEditing:(NSText*)fieldEditor
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextField, bool(cocoon::Text)>::emit((__bridge void*)strongHost, "control_text_should_end_editing", cocoon::internal::wrap<cocoon::Text>(fieldEditor));
    return static_cast<::BOOL>(__r);
}

- (BOOL)control:(NSControl*)control didFailToFormatString:(NSString*)string errorDescription:(NSString*)error
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextField, bool(std::string, std::string)>::emit((__bridge void*)strongHost, "did_fail_to_format_string_error_description", cocoon::internal::from(string), cocoon::internal::from(error));
    return static_cast<::BOOL>(__r);
}

- (void)control:(NSControl*)control didFailToValidatePartialString:(NSString*)string errorDescription:(NSString*)error
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextField, void(std::string, std::string)>::emit((__bridge void*)strongHost, "did_fail_to_validate_partial_string_error_description", cocoon::internal::from(string), cocoon::internal::from(error));
}

- (BOOL)control:(NSControl*)control isValidObject:(id)obj
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextField, bool(cocoon::Object)>::emit((__bridge void*)strongHost, "is_valid_object", cocoon::internal::wrap<cocoon::Object>(obj));
    return static_cast<::BOOL>(__r);
}

- (BOOL)control:(NSControl*)control textView:(NSTextView*)textView doCommandBySelector:(SEL)commandSelector
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextField, bool(cocoon::TextView, std::string)>::emit((__bridge void*)strongHost, "text_view_do_command_by_selector", cocoon::internal::wrap<cocoon::TextView>(textView), cocoon::internal::from(NSStringFromSelector(commandSelector)));
    return static_cast<::BOOL>(__r);
}

- (NSArray<NSString*>*)control:(NSControl*)control textView:(NSTextView*)textView completions:(NSArray<NSString*>*)words forPartialWordRange:(NSRange)charRange indexOfSelectedItem:(NSInteger*)index
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextField, std::vector<std::string>(cocoon::TextView, std::vector<std::string>, cocoon::Range, std::int64_t*)>::emit((__bridge void*)strongHost, "text_view_completions_for_partial_word_range_index_of_selected_item", cocoon::internal::wrap<cocoon::TextView>(textView), cocoon::internal::from_array<std::string>(words, [](id e) -> std::string
                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                return cocoon::internal::from((NSString*)e);
                                                                                                                                                                                                                                                                                                                                                            }),
                                                                                                                                                           cocoon::internal::from(charRange), (std::int64_t*)(index));
    return cocoon::internal::to_array(__r, [](const std::string& e) -> id
                                      {
                                          return cocoon::internal::to(e);
                                      });
}

- (NSArray*)textField:(NSTextField*)textField textView:(NSTextView*)textView candidatesForSelectedRange:(NSRange)selectedRange
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextField, std::vector<cocoon::Object>(cocoon::TextView, cocoon::Range)>::emit((__bridge void*)strongHost, "text_view_candidates_for_selected_range", cocoon::internal::wrap<cocoon::TextView>(textView), cocoon::internal::from(selectedRange));
    return cocoon::internal::to_array(__r, [](const cocoon::Object& e) -> id
                                      {
                                          return cocoon::internal::native_id(e);
                                      });
}

- (NSArray<NSTextCheckingResult*>*)textField:(NSTextField*)textField textView:(NSTextView*)textView candidates:(NSArray<NSTextCheckingResult*>*)candidates forSelectedRange:(NSRange)selectedRange
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextField, std::vector<cocoon::TextCheckingResult>(cocoon::TextView, std::vector<cocoon::TextCheckingResult>, cocoon::Range)>::emit((__bridge void*)strongHost, "text_field_text_view_candidates_for_selected_range", cocoon::internal::wrap<cocoon::TextView>(textView), cocoon::internal::from_array<cocoon::TextCheckingResult>(candidates, [](id e) -> cocoon::TextCheckingResult
                                                                                                                                                                                                                                                                                                                                                                         {
                                                                                                                                                                                                                                                                                                                                                                             return cocoon::internal::wrap<cocoon::TextCheckingResult>((::NSTextCheckingResult*)e);
                                                                                                                                                                                                                                                                                                                                                                         }),
                                                                                                                                                                          cocoon::internal::from(selectedRange));
    return cocoon::internal::to_array(__r, [](const cocoon::TextCheckingResult& e) -> id
                                      {
                                          return cocoon::internal::native<::NSTextCheckingResult>(e);
                                      });
}

- (BOOL)textField:(NSTextField*)textField textView:(NSTextView*)textView shouldSelectCandidateAtIndex:(NSUInteger)index
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextField, bool(cocoon::TextView, std::uint64_t)>::emit((__bridge void*)strongHost, "text_view_should_select_candidate_at_index", cocoon::internal::wrap<cocoon::TextView>(textView), static_cast<std::uint64_t>(index));
    return static_cast<::BOOL>(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(controlTextDidBeginEditing:))
    {
        return strongHost && cocoon::Signal<cocoon::TextField, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "control_text_did_begin_editing");
    }
    if (selector == @selector(controlTextDidEndEditing:))
    {
        return strongHost && cocoon::Signal<cocoon::TextField, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "control_text_did_end_editing");
    }
    if (selector == @selector(controlTextDidChange:))
    {
        return strongHost && cocoon::Signal<cocoon::TextField, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "control_text_did_change");
    }
    if (selector == @selector(control:textShouldBeginEditing:))
    {
        return strongHost && cocoon::Signal<cocoon::TextField, bool(cocoon::Text)>::connected((__bridge void*)strongHost, "control_text_should_begin_editing");
    }
    if (selector == @selector(control:textShouldEndEditing:))
    {
        return strongHost && cocoon::Signal<cocoon::TextField, bool(cocoon::Text)>::connected((__bridge void*)strongHost, "control_text_should_end_editing");
    }
    if (selector == @selector(control:didFailToFormatString:errorDescription:))
    {
        return strongHost && cocoon::Signal<cocoon::TextField, bool(std::string, std::string)>::connected((__bridge void*)strongHost, "did_fail_to_format_string_error_description");
    }
    if (selector == @selector(control:didFailToValidatePartialString:errorDescription:))
    {
        return strongHost && cocoon::Signal<cocoon::TextField, void(std::string, std::string)>::connected((__bridge void*)strongHost, "did_fail_to_validate_partial_string_error_description");
    }
    if (selector == @selector(control:isValidObject:))
    {
        return strongHost && cocoon::Signal<cocoon::TextField, bool(cocoon::Object)>::connected((__bridge void*)strongHost, "is_valid_object");
    }
    if (selector == @selector(control:textView:doCommandBySelector:))
    {
        return strongHost && cocoon::Signal<cocoon::TextField, bool(cocoon::TextView, std::string)>::connected((__bridge void*)strongHost, "text_view_do_command_by_selector");
    }
    if (selector == @selector(control:textView:completions:forPartialWordRange:indexOfSelectedItem:))
    {
        return strongHost && cocoon::Signal<cocoon::TextField, std::vector<std::string>(cocoon::TextView, std::vector<std::string>, cocoon::Range, std::int64_t*)>::connected((__bridge void*)strongHost, "text_view_completions_for_partial_word_range_index_of_selected_item");
    }
    if (selector == @selector(textField:textView:candidatesForSelectedRange:))
    {
        return strongHost && cocoon::Signal<cocoon::TextField, std::vector<cocoon::Object>(cocoon::TextView, cocoon::Range)>::connected((__bridge void*)strongHost, "text_view_candidates_for_selected_range");
    }
    if (selector == @selector(textField:textView:candidates:forSelectedRange:))
    {
        return strongHost && cocoon::Signal<cocoon::TextField, std::vector<cocoon::TextCheckingResult>(cocoon::TextView, std::vector<cocoon::TextCheckingResult>, cocoon::Range)>::connected((__bridge void*)strongHost, "text_field_text_view_candidates_for_selected_range");
    }
    if (selector == @selector(textField:textView:shouldSelectCandidateAtIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::TextField, bool(cocoon::TextView, std::uint64_t)>::connected((__bridge void*)strongHost, "text_view_should_select_candidate_at_index");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    TextField::TextField(const std::string& text) : TextField(Adopt{cocoon::internal::retain([NSTextField textFieldWithString:cocoon::internal::to(text)])})
    {
        TextField::bind_others_(handle());
        TextField::bind_action_(handle());
        TextField::install_delegate_delegate_(handle());
    }

    TextField::TextField(std::nullptr_t) : Control(nullptr)
    {
    }

    TextField::TextField(Adopt adopt) : Control(adopt)
    {
    }

    TextField TextField::label_with_attributed_string(const AttributedString& attributed_string_value)
    {
        return cocoon::internal::wrap<TextField>([::NSTextField labelWithAttributedString:cocoon::internal::native<::NSAttributedString>(attributed_string_value)]);
    }

    TextField TextField::label_with_string(const std::string& string_value)
    {
        return cocoon::internal::wrap<TextField>([::NSTextField labelWithString:cocoon::internal::to(string_value)]);
    }

    void TextField::select_text(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextField>(this) selectText:cocoon::internal::native_id(sender)];
    }

    void TextField::text_did_begin_editing(const Notification& notification) const
    {
        [cocoon::internal::ns<::NSTextField>(this) textDidBeginEditing:cocoon::internal::native<::NSNotification>(notification)];
    }

    void TextField::text_did_change(const Notification& notification) const
    {
        [cocoon::internal::ns<::NSTextField>(this) textDidChange:cocoon::internal::native<::NSNotification>(notification)];
    }

    void TextField::text_did_end_editing(const Notification& notification) const
    {
        [cocoon::internal::ns<::NSTextField>(this) textDidEndEditing:cocoon::internal::native<::NSNotification>(notification)];
    }

    TextField TextField::text_field_with_string(const std::string& string_value)
    {
        return cocoon::internal::wrap<TextField>([::NSTextField textFieldWithString:cocoon::internal::to(string_value)]);
    }

    bool TextField::text_should_begin_editing(const Text& text_object) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextField>(this) textShouldBeginEditing:cocoon::internal::native<::NSText>(text_object)]);
    }

    bool TextField::text_should_end_editing(const Text& text_object) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextField>(this) textShouldEndEditing:cocoon::internal::native<::NSText>(text_object)]);
    }

    TextField TextField::wrapping_label_with_string(const std::string& string_value)
    {
        return cocoon::internal::wrap<TextField>([::NSTextField wrappingLabelWithString:cocoon::internal::to(string_value)]);
    }

    bool TextField::accepts_first_responder() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextField>(this) acceptsFirstResponder]);
    }

    bool TextField::allows_character_picker_touch_bar_item() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextField>(this) allowsCharacterPickerTouchBarItem]);
    }

    void TextField::set_allows_character_picker_touch_bar_item(bool value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setAllowsCharacterPickerTouchBarItem:static_cast<::BOOL>(value)];
    }

    bool TextField::allows_default_tightening_for_truncation() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextField>(this) allowsDefaultTighteningForTruncation]);
    }

    void TextField::set_allows_default_tightening_for_truncation(bool value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setAllowsDefaultTighteningForTruncation:static_cast<::BOOL>(value)];
    }

    bool TextField::allows_editing_text_attributes() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextField>(this) allowsEditingTextAttributes]);
    }

    void TextField::set_allows_editing_text_attributes(bool value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setAllowsEditingTextAttributes:static_cast<::BOOL>(value)];
    }

    bool TextField::allows_writing_tools() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextField>(this) allowsWritingTools]);
    }

    void TextField::set_allows_writing_tools(bool value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setAllowsWritingTools:static_cast<::BOOL>(value)];
    }

    bool TextField::allows_writing_tools_affordance() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextField>(this) allowsWritingToolsAffordance]);
    }

    void TextField::set_allows_writing_tools_affordance(bool value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setAllowsWritingToolsAffordance:static_cast<::BOOL>(value)];
    }

    bool TextField::is_automatic_text_completion_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextField>(this) isAutomaticTextCompletionEnabled]);
    }

    void TextField::set_automatic_text_completion_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setAutomaticTextCompletionEnabled:static_cast<::BOOL>(value)];
    }

    Color TextField::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSTextField>(this) backgroundColor]);
    }

    void TextField::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    TextFieldBezelStyle TextField::bezel_style() const
    {
        return static_cast<TextFieldBezelStyle>([cocoon::internal::ns<::NSTextField>(this) bezelStyle]);
    }

    void TextField::set_bezel_style(TextFieldBezelStyle value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setBezelStyle:static_cast<::NSTextFieldBezelStyle>(value)];
    }

    bool TextField::is_bezeled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextField>(this) isBezeled]);
    }

    void TextField::set_bezeled(bool value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setBezeled:static_cast<::BOOL>(value)];
    }

    bool TextField::is_bordered() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextField>(this) isBordered]);
    }

    void TextField::set_bordered(bool value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setBordered:static_cast<::BOOL>(value)];
    }

    bool TextField::draws_background() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextField>(this) drawsBackground]);
    }

    void TextField::set_draws_background(bool value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setDrawsBackground:static_cast<::BOOL>(value)];
    }

    bool TextField::is_editable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextField>(this) isEditable]);
    }

    void TextField::set_editable(bool value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setEditable:static_cast<::BOOL>(value)];
    }

    bool TextField::imports_graphics() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextField>(this) importsGraphics]);
    }

    void TextField::set_imports_graphics(bool value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setImportsGraphics:static_cast<::BOOL>(value)];
    }

    LineBreakStrategy TextField::line_break_strategy() const
    {
        return static_cast<LineBreakStrategy>([cocoon::internal::ns<::NSTextField>(this) lineBreakStrategy]);
    }

    void TextField::set_line_break_strategy(LineBreakStrategy value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setLineBreakStrategy:static_cast<::NSLineBreakStrategy>(value)];
    }

    std::int64_t TextField::maximum_number_of_lines() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTextField>(this) maximumNumberOfLines]);
    }

    void TextField::set_maximum_number_of_lines(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setMaximumNumberOfLines:static_cast<::NSInteger>(value)];
    }

    AttributedString TextField::placeholder_attributed_string() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSTextField>(this) placeholderAttributedString]);
    }

    void TextField::set_placeholder_attributed_string(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setPlaceholderAttributedString:cocoon::internal::native<::NSAttributedString>(value)];
    }

    std::vector<AttributedString> TextField::placeholder_attributed_strings() const
    {
        return cocoon::internal::from_array<AttributedString>([cocoon::internal::ns<::NSTextField>(this) placeholderAttributedStrings], [](id e) -> AttributedString
                                                              {
                                                                  return cocoon::internal::wrap<AttributedString>((::NSAttributedString*)e);
                                                              });
    }

    void TextField::set_placeholder_attributed_strings(const std::vector<AttributedString>& value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setPlaceholderAttributedStrings:cocoon::internal::to_array(value, [](const AttributedString& e) -> id
                                                                                                              {
                                                                                                                  return cocoon::internal::native<::NSAttributedString>(e);
                                                                                                              })];
    }

    std::string TextField::placeholder_string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextField>(this) placeholderString]);
    }

    void TextField::set_placeholder_string(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setPlaceholderString:cocoon::internal::to(value)];
    }

    std::vector<std::string> TextField::placeholder_strings() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTextField>(this) placeholderStrings], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void TextField::set_placeholder_strings(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setPlaceholderStrings:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                    {
                                                                                                        return cocoon::internal::to(e);
                                                                                                    })];
    }

    double TextField::preferred_max_layout_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTextField>(this) preferredMaxLayoutWidth]);
    }

    void TextField::set_preferred_max_layout_width(double value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setPreferredMaxLayoutWidth:static_cast<::CGFloat>(value)];
    }

    bool TextField::resolves_natural_alignment_with_base_writing_direction() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextField>(this) resolvesNaturalAlignmentWithBaseWritingDirection]);
    }

    void TextField::set_resolves_natural_alignment_with_base_writing_direction(bool value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setResolvesNaturalAlignmentWithBaseWritingDirection:static_cast<::BOOL>(value)];
    }

    bool TextField::is_selectable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextField>(this) isSelectable]);
    }

    void TextField::set_selectable(bool value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setSelectable:static_cast<::BOOL>(value)];
    }

    Color TextField::text_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSTextField>(this) textColor]);
    }

    void TextField::set_text_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSTextField>(this) setTextColor:cocoon::internal::native<::NSColor>(value)];
    }

    void TextField::bind_action_(void* native)
    {
        id host = (__bridge id)native;
        cocoon::internal::bind_action(host, host, [](id host, id sender)
                                      {
                                          cocoon::Signal<cocoon::TextField, void()>::emit((__bridge void*)host, "editing_finished");
                                      });
    }

    void TextField::bind_others_(void* native)
    {
        id host = (__bridge id)native;
        cocoon::internal::observe(host, host, NSControlTextDidChangeNotification, [](id host, NSNotification* note)
                                  {
                                      cocoon::Signal<cocoon::TextField, void(std::string)>::emit((__bridge void*)host, "text_changed", cocoon::internal::from(((NSTextField*)note.object).stringValue));
                                  });
    }

    void TextField::install_delegate_delegate_(void* native)
    {
        ::NSTextField* host = (__bridge ::NSTextField*)native;
        AKTextFieldDelegate* delegate = [[AKTextFieldDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSTextField* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSTextField* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
