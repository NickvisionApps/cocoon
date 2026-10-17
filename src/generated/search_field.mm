#include "generated/search_field.h"
#include "internal.h"

@interface AKSearchFieldDelegate : NSObject <NSSearchFieldDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKSearchFieldDelegate

- (void)searchFieldDidStartSearching:(NSSearchField*)sender
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SearchField, void()>::emit((__bridge void*)strongHost, "did_start_searching");
}

- (void)searchFieldDidEndSearching:(NSSearchField*)sender
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SearchField, void()>::emit((__bridge void*)strongHost, "did_end_searching");
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
    if (selector == @selector(searchFieldDidStartSearching:))
    {
        return strongHost && cocoon::Signal<cocoon::SearchField, void()>::connected((__bridge void*)strongHost, "did_start_searching");
    }
    if (selector == @selector(searchFieldDidEndSearching:))
    {
        return strongHost && cocoon::Signal<cocoon::SearchField, void()>::connected((__bridge void*)strongHost, "did_end_searching");
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
    SearchField::SearchField() : SearchField(Adopt{cocoon::internal::retain([[NSSearchField alloc] init])})
    {
        TextField::bind_others_(handle());
        TextField::bind_action_(handle());
        SearchField::install_delegate_delegate_(handle());
    }

    SearchField::SearchField(std::nullptr_t) : TextField(nullptr)
    {
    }

    SearchField::SearchField(Adopt adopt) : TextField(adopt)
    {
    }

    Rect SearchField::cancel_button_bounds() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSearchField>(this) cancelButtonBounds]);
    }

    std::int64_t SearchField::maximum_recents() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSSearchField>(this) maximumRecents]);
    }

    void SearchField::set_maximum_recents(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSSearchField>(this) setMaximumRecents:static_cast<::NSInteger>(value)];
    }

    std::vector<std::string> SearchField::recent_searches() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSSearchField>(this) recentSearches], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    void SearchField::set_recent_searches(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSSearchField>(this) setRecentSearches:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                      {
                                                                          return cocoon::internal::to(e);
                                                                      })];
    }

    std::string SearchField::recents_autosave_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSearchField>(this) recentsAutosaveName]);
    }

    void SearchField::set_recents_autosave_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSSearchField>(this) setRecentsAutosaveName:cocoon::internal::to(value)];
    }

    Rect SearchField::search_button_bounds() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSearchField>(this) searchButtonBounds]);
    }

    Menu SearchField::search_menu_template() const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSSearchField>(this) searchMenuTemplate]);
    }

    void SearchField::set_search_menu_template(const Menu& value) const
    {
        [cocoon::internal::ns<::NSSearchField>(this) setSearchMenuTemplate:cocoon::internal::native<::NSMenu>(value)];
    }

    Rect SearchField::search_text_bounds() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSearchField>(this) searchTextBounds]);
    }

    bool SearchField::sends_search_string_immediately() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSearchField>(this) sendsSearchStringImmediately]);
    }

    void SearchField::set_sends_search_string_immediately(bool value) const
    {
        [cocoon::internal::ns<::NSSearchField>(this) setSendsSearchStringImmediately:static_cast<::BOOL>(value)];
    }

    bool SearchField::sends_whole_search_string() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSearchField>(this) sendsWholeSearchString]);
    }

    void SearchField::set_sends_whole_search_string(bool value) const
    {
        [cocoon::internal::ns<::NSSearchField>(this) setSendsWholeSearchString:static_cast<::BOOL>(value)];
    }

    void SearchField::install_delegate_delegate_(void* native)
    {
        ::NSSearchField* host = (__bridge ::NSSearchField*)native;
        AKSearchFieldDelegate* delegate = [[AKSearchFieldDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSSearchField* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSSearchField* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
