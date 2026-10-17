#include "generated/token_field.h"
#include "internal.h"

@interface AKTokenFieldDelegate : NSObject <NSTokenFieldDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKTokenFieldDelegate

- (NSArray*)tokenField:(NSTokenField*)tokenField completionsForSubstring:(NSString*)substring indexOfToken:(NSInteger)tokenIndex indexOfSelectedItem:(NSInteger*)selectedIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenField, std::vector<cocoon::Object>(std::string, std::int64_t, std::int64_t*)>::emit((__bridge void*)strongHost, "completions_for_substring_index_of_token_index_of_selected_item", cocoon::internal::from(substring), static_cast<std::int64_t>(tokenIndex), (std::int64_t*)(selectedIndex));
    return cocoon::internal::to_array(__r, [](const cocoon::Object& e) -> id
                                      {
                                          return cocoon::internal::native_id(e);
                                      });
}

- (NSArray*)tokenField:(NSTokenField*)tokenField shouldAddObjects:(NSArray*)tokens atIndex:(NSUInteger)index
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenField, std::vector<cocoon::Object>(std::vector<cocoon::Object>, std::uint64_t)>::emit((__bridge void*)strongHost, "should_add_objects_at_index", cocoon::internal::from_array<cocoon::Object>(tokens, [](id e) -> cocoon::Object
                                                                                                                                                                                                                                         {
                                                                                                                                                                                                                                             return cocoon::internal::wrap<cocoon::Object>(e);
                                                                                                                                                                                                                                         }),
                                                                                                                                 static_cast<std::uint64_t>(index));
    return cocoon::internal::to_array(__r, [](const cocoon::Object& e) -> id
                                      {
                                          return cocoon::internal::native_id(e);
                                      });
}

- (NSString*)tokenField:(NSTokenField*)tokenField displayStringForRepresentedObject:(id)representedObject
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenField, std::string(cocoon::Object)>::emit((__bridge void*)strongHost, "display_string_for_represented_object", cocoon::internal::wrap<cocoon::Object>(representedObject));
    return cocoon::internal::to(__r);
}

- (NSString*)tokenField:(NSTokenField*)tokenField editingStringForRepresentedObject:(id)representedObject
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenField, std::string(cocoon::Object)>::emit((__bridge void*)strongHost, "editing_string_for_represented_object", cocoon::internal::wrap<cocoon::Object>(representedObject));
    return cocoon::internal::to(__r);
}

- (id)tokenField:(NSTokenField*)tokenField representedObjectForEditingString:(NSString*)editingString
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenField, cocoon::Object(std::string)>::emit((__bridge void*)strongHost, "represented_object_for_editing_string", cocoon::internal::from(editingString));
    return cocoon::internal::native_id(__r);
}

- (BOOL)tokenField:(NSTokenField*)tokenField writeRepresentedObjects:(NSArray*)objects toPasteboard:(NSPasteboard*)pboard
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenField, bool(std::vector<cocoon::Object>, cocoon::Pasteboard)>::emit((__bridge void*)strongHost, "write_represented_objects_to_pasteboard", cocoon::internal::from_array<cocoon::Object>(objects, [](id e) -> cocoon::Object
                                                                                                                                                                                                                                   {
                                                                                                                                                                                                                                       return cocoon::internal::wrap<cocoon::Object>(e);
                                                                                                                                                                                                                                   }),
                                                                                                               cocoon::internal::wrap<cocoon::Pasteboard>(pboard));
    return static_cast<::BOOL>(__r);
}

- (NSArray*)tokenField:(NSTokenField*)tokenField readFromPasteboard:(NSPasteboard*)pboard
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenField, std::vector<cocoon::Object>(cocoon::Pasteboard)>::emit((__bridge void*)strongHost, "read_from_pasteboard", cocoon::internal::wrap<cocoon::Pasteboard>(pboard));
    return cocoon::internal::to_array(__r, [](const cocoon::Object& e) -> id
                                      {
                                          return cocoon::internal::native_id(e);
                                      });
}

- (NSMenu*)tokenField:(NSTokenField*)tokenField menuForRepresentedObject:(id)representedObject
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenField, cocoon::Menu(cocoon::Object)>::emit((__bridge void*)strongHost, "menu_for_represented_object", cocoon::internal::wrap<cocoon::Object>(representedObject));
    return cocoon::internal::native<::NSMenu>(__r);
}

- (BOOL)tokenField:(NSTokenField*)tokenField hasMenuForRepresentedObject:(id)representedObject
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenField, bool(cocoon::Object)>::emit((__bridge void*)strongHost, "has_menu_for_represented_object", cocoon::internal::wrap<cocoon::Object>(representedObject));
    return static_cast<::BOOL>(__r);
}

- (NSTokenStyle)tokenField:(NSTokenField*)tokenField styleForRepresentedObject:(id)representedObject
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenField, cocoon::TokenStyle(cocoon::Object)>::emit((__bridge void*)strongHost, "style_for_represented_object", cocoon::internal::wrap<cocoon::Object>(representedObject));
    return static_cast<::NSTokenStyle>(__r);
}

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
    if (selector == @selector(tokenField:completionsForSubstring:indexOfToken:indexOfSelectedItem:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenField, std::vector<cocoon::Object>(std::string, std::int64_t, std::int64_t*)>::connected((__bridge void*)strongHost, "completions_for_substring_index_of_token_index_of_selected_item");
    }
    if (selector == @selector(tokenField:shouldAddObjects:atIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenField, std::vector<cocoon::Object>(std::vector<cocoon::Object>, std::uint64_t)>::connected((__bridge void*)strongHost, "should_add_objects_at_index");
    }
    if (selector == @selector(tokenField:displayStringForRepresentedObject:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenField, std::string(cocoon::Object)>::connected((__bridge void*)strongHost, "display_string_for_represented_object");
    }
    if (selector == @selector(tokenField:editingStringForRepresentedObject:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenField, std::string(cocoon::Object)>::connected((__bridge void*)strongHost, "editing_string_for_represented_object");
    }
    if (selector == @selector(tokenField:representedObjectForEditingString:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenField, cocoon::Object(std::string)>::connected((__bridge void*)strongHost, "represented_object_for_editing_string");
    }
    if (selector == @selector(tokenField:writeRepresentedObjects:toPasteboard:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenField, bool(std::vector<cocoon::Object>, cocoon::Pasteboard)>::connected((__bridge void*)strongHost, "write_represented_objects_to_pasteboard");
    }
    if (selector == @selector(tokenField:readFromPasteboard:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenField, std::vector<cocoon::Object>(cocoon::Pasteboard)>::connected((__bridge void*)strongHost, "read_from_pasteboard");
    }
    if (selector == @selector(tokenField:menuForRepresentedObject:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenField, cocoon::Menu(cocoon::Object)>::connected((__bridge void*)strongHost, "menu_for_represented_object");
    }
    if (selector == @selector(tokenField:hasMenuForRepresentedObject:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenField, bool(cocoon::Object)>::connected((__bridge void*)strongHost, "has_menu_for_represented_object");
    }
    if (selector == @selector(tokenField:styleForRepresentedObject:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenField, cocoon::TokenStyle(cocoon::Object)>::connected((__bridge void*)strongHost, "style_for_represented_object");
    }
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
    TokenField::TokenField() : TokenField(Adopt{cocoon::internal::retain([[::NSTokenField alloc] init])})
    {
        TextField::bind_others_(handle());
        TextField::bind_action_(handle());
        TokenField::install_delegate_delegate_(handle());
    }

    TokenField::TokenField(std::nullptr_t) : TextField(nullptr)
    {
    }

    TokenField::TokenField(Adopt adopt) : TextField(adopt)
    {
    }

    double TokenField::completion_delay() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTokenField>(this) completionDelay]);
    }

    void TokenField::set_completion_delay(double value) const
    {
        [cocoon::internal::ns<::NSTokenField>(this) setCompletionDelay:static_cast<::NSTimeInterval>(value)];
    }

    double TokenField::default_completion_delay()
    {
        return static_cast<double>([::NSTokenField defaultCompletionDelay]);
    }

    CharacterSet TokenField::default_tokenizing_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSTokenField defaultTokenizingCharacterSet]);
    }

    TokenStyle TokenField::token_style() const
    {
        return static_cast<TokenStyle>([cocoon::internal::ns<::NSTokenField>(this) tokenStyle]);
    }

    void TokenField::set_token_style(TokenStyle value) const
    {
        [cocoon::internal::ns<::NSTokenField>(this) setTokenStyle:static_cast<::NSTokenStyle>(value)];
    }

    CharacterSet TokenField::tokenizing_character_set() const
    {
        return cocoon::internal::wrap<CharacterSet>([cocoon::internal::ns<::NSTokenField>(this) tokenizingCharacterSet]);
    }

    void TokenField::set_tokenizing_character_set(const CharacterSet& value) const
    {
        [cocoon::internal::ns<::NSTokenField>(this) setTokenizingCharacterSet:cocoon::internal::native<::NSCharacterSet>(value)];
    }

    void TokenField::install_delegate_delegate_(void* native)
    {
        ::NSTokenField* host = (__bridge ::NSTokenField*)native;
        AKTokenFieldDelegate* delegate = [[AKTokenFieldDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSTokenField* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSTokenField* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
