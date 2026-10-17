#include "generated/combo_box.h"
#include "internal.h"

@interface AKComboBoxDataSourceDelegate : NSObject <NSComboBoxDataSource>
{
@public
    __weak id host;
}
@end

@implementation AKComboBoxDataSourceDelegate

- (NSInteger)numberOfItemsInComboBox:(NSComboBox*)comboBox
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::ComboBox, std::int64_t()>::emit((__bridge void*)strongHost, "number_of_items_in_combo_box");
    return static_cast<::NSInteger>(__r);
}

- (id)comboBox:(NSComboBox*)comboBox objectValueForItemAtIndex:(NSInteger)index
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::ComboBox, cocoon::Object(std::int64_t)>::emit((__bridge void*)strongHost, "object_value_for_item_at_index", static_cast<std::int64_t>(index));
    return cocoon::internal::native_id(__r);
}

- (NSUInteger)comboBox:(NSComboBox*)comboBox indexOfItemWithStringValue:(NSString*)string
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::ComboBox, std::uint64_t(std::string)>::emit((__bridge void*)strongHost, "index_of_item_with_string_value", cocoon::internal::from(string));
    return static_cast<::NSUInteger>(__r);
}

- (NSString*)comboBox:(NSComboBox*)comboBox completedString:(NSString*)string
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::ComboBox, std::string(std::string)>::emit((__bridge void*)strongHost, "completed_string", cocoon::internal::from(string));
    return cocoon::internal::to(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(numberOfItemsInComboBox:))
    {
        return strongHost && cocoon::Signal<cocoon::ComboBox, std::int64_t()>::connected((__bridge void*)strongHost, "number_of_items_in_combo_box");
    }
    if (selector == @selector(comboBox:objectValueForItemAtIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::ComboBox, cocoon::Object(std::int64_t)>::connected((__bridge void*)strongHost, "object_value_for_item_at_index");
    }
    if (selector == @selector(comboBox:indexOfItemWithStringValue:))
    {
        return strongHost && cocoon::Signal<cocoon::ComboBox, std::uint64_t(std::string)>::connected((__bridge void*)strongHost, "index_of_item_with_string_value");
    }
    if (selector == @selector(comboBox:completedString:))
    {
        return strongHost && cocoon::Signal<cocoon::ComboBox, std::string(std::string)>::connected((__bridge void*)strongHost, "completed_string");
    }
    return [super respondsToSelector:selector];
}

@end

@interface AKComboBoxDelegate : NSObject <NSComboBoxDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKComboBoxDelegate

- (void)comboBoxWillPopUp:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::ComboBox, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_pop_up", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)comboBoxWillDismiss:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::ComboBox, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_dismiss", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)comboBoxSelectionDidChange:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::ComboBox, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "selection_did_change", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)comboBoxSelectionIsChanging:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::ComboBox, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "selection_is_changing", cocoon::internal::wrap<cocoon::Notification>(notification));
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
    if (selector == @selector(comboBoxWillPopUp:))
    {
        return strongHost && cocoon::Signal<cocoon::ComboBox, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_pop_up");
    }
    if (selector == @selector(comboBoxWillDismiss:))
    {
        return strongHost && cocoon::Signal<cocoon::ComboBox, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_dismiss");
    }
    if (selector == @selector(comboBoxSelectionDidChange:))
    {
        return strongHost && cocoon::Signal<cocoon::ComboBox, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "selection_did_change");
    }
    if (selector == @selector(comboBoxSelectionIsChanging:))
    {
        return strongHost && cocoon::Signal<cocoon::ComboBox, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "selection_is_changing");
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
    ComboBox::ComboBox() : ComboBox(Adopt{cocoon::internal::retain([[NSComboBox alloc] init])})
    {
        TextField::bind_others_(handle());
        ComboBox::bind_others_(handle());
        TextField::bind_action_(handle());
        ComboBox::install_data_source_delegate_(handle());
        ComboBox::install_delegate_delegate_(handle());
    }

    ComboBox::ComboBox(std::nullptr_t) : TextField(nullptr)
    {
    }

    ComboBox::ComboBox(Adopt adopt) : TextField(adopt)
    {
    }

    void ComboBox::add_item_with_object_value(const Object& object) const
    {
        [cocoon::internal::ns<::NSComboBox>(this) addItemWithObjectValue:cocoon::internal::native_id(object)];
    }

    void ComboBox::add_items_with_object_values(const std::vector<Object>& objects) const
    {
        [cocoon::internal::ns<::NSComboBox>(this) addItemsWithObjectValues:cocoon::internal::to_array(objects, [](const Object& e) -> id
                                                                          {
                                                                              return cocoon::internal::native_id(e);
                                                                          })];
    }

    void ComboBox::deselect_item_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSComboBox>(this) deselectItemAtIndex:static_cast<::NSInteger>(index)];
    }

    std::int64_t ComboBox::index_of_item_with_object_value(const Object& object) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSComboBox>(this) indexOfItemWithObjectValue:cocoon::internal::native_id(object)]);
    }

    void ComboBox::insert_item_with_object_value(const Object& object, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSComboBox>(this) insertItemWithObjectValue:cocoon::internal::native_id(object) atIndex:static_cast<::NSInteger>(index)];
    }

    Object ComboBox::item_object_value_at_index(std::int64_t index) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSComboBox>(this) itemObjectValueAtIndex:static_cast<::NSInteger>(index)]);
    }

    void ComboBox::note_number_of_items_changed() const
    {
        [cocoon::internal::ns<::NSComboBox>(this) noteNumberOfItemsChanged];
    }

    void ComboBox::reload_data() const
    {
        [cocoon::internal::ns<::NSComboBox>(this) reloadData];
    }

    void ComboBox::remove_all_items() const
    {
        [cocoon::internal::ns<::NSComboBox>(this) removeAllItems];
    }

    void ComboBox::remove_item_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSComboBox>(this) removeItemAtIndex:static_cast<::NSInteger>(index)];
    }

    void ComboBox::remove_item_with_object_value(const Object& object) const
    {
        [cocoon::internal::ns<::NSComboBox>(this) removeItemWithObjectValue:cocoon::internal::native_id(object)];
    }

    void ComboBox::scroll_item_at_index_to_top(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSComboBox>(this) scrollItemAtIndexToTop:static_cast<::NSInteger>(index)];
    }

    void ComboBox::scroll_item_at_index_to_visible(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSComboBox>(this) scrollItemAtIndexToVisible:static_cast<::NSInteger>(index)];
    }

    void ComboBox::select_item_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSComboBox>(this) selectItemAtIndex:static_cast<::NSInteger>(index)];
    }

    void ComboBox::select_item_with_object_value(const Object& object) const
    {
        [cocoon::internal::ns<::NSComboBox>(this) selectItemWithObjectValue:cocoon::internal::native_id(object)];
    }

    bool ComboBox::is_button_bordered() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSComboBox>(this) isButtonBordered]);
    }

    void ComboBox::set_button_bordered(bool value) const
    {
        [cocoon::internal::ns<::NSComboBox>(this) setButtonBordered:static_cast<::BOOL>(value)];
    }

    bool ComboBox::completes() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSComboBox>(this) completes]);
    }

    void ComboBox::set_completes(bool value) const
    {
        [cocoon::internal::ns<::NSComboBox>(this) setCompletes:static_cast<::BOOL>(value)];
    }

    bool ComboBox::has_vertical_scroller() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSComboBox>(this) hasVerticalScroller]);
    }

    void ComboBox::set_has_vertical_scroller(bool value) const
    {
        [cocoon::internal::ns<::NSComboBox>(this) setHasVerticalScroller:static_cast<::BOOL>(value)];
    }

    std::int64_t ComboBox::index_of_selected_item() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSComboBox>(this) indexOfSelectedItem]);
    }

    Size ComboBox::intercell_spacing() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSComboBox>(this) intercellSpacing]);
    }

    void ComboBox::set_intercell_spacing(const Size& value) const
    {
        [cocoon::internal::ns<::NSComboBox>(this) setIntercellSpacing:cocoon::internal::to(value)];
    }

    double ComboBox::item_height() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSComboBox>(this) itemHeight]);
    }

    void ComboBox::set_item_height(double value) const
    {
        [cocoon::internal::ns<::NSComboBox>(this) setItemHeight:static_cast<::CGFloat>(value)];
    }

    std::int64_t ComboBox::number_of_items() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSComboBox>(this) numberOfItems]);
    }

    std::int64_t ComboBox::number_of_visible_items() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSComboBox>(this) numberOfVisibleItems]);
    }

    void ComboBox::set_number_of_visible_items(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSComboBox>(this) setNumberOfVisibleItems:static_cast<::NSInteger>(value)];
    }

    Object ComboBox::object_value_of_selected_item() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSComboBox>(this) objectValueOfSelectedItem]);
    }

    std::vector<Object> ComboBox::object_values() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSComboBox>(this) objectValues], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    bool ComboBox::uses_data_source() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSComboBox>(this) usesDataSource]);
    }

    void ComboBox::set_uses_data_source(bool value) const
    {
        [cocoon::internal::ns<::NSComboBox>(this) setUsesDataSource:static_cast<::BOOL>(value)];
    }

    void ComboBox::add_item(const std::string& item) const
    {
        [cocoon::internal::ns<NSComboBox>(this) addItemWithObjectValue:cocoon::internal::to(item)];
    }

    void ComboBox::bind_others_(void* native)
    {
        id host = (__bridge id)native;
        cocoon::internal::observe(host, host, NSComboBoxSelectionDidChangeNotification, [](id host, NSNotification* note)
                    {
                        cocoon::Signal<cocoon::ComboBox, void(std::int64_t)>::emit((__bridge void*)host, "selection_changed", ((NSComboBox*)note.object).indexOfSelectedItem);
                    });
    }

    void ComboBox::install_data_source_delegate_(void* native)
    {
        ::NSComboBox* host = (__bridge ::NSComboBox*)native;
        AKComboBoxDataSourceDelegate* delegate = [[AKComboBoxDataSourceDelegate alloc] init];
        delegate->host = host;
        host.dataSource = delegate;
        __weak::NSComboBox* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSComboBox* strongHost = weakHost;
            strongHost.dataSource = nil;
            strongHost.dataSource = delegate;
        });
    }

    void ComboBox::install_delegate_delegate_(void* native)
    {
        ::NSComboBox* host = (__bridge ::NSComboBox*)native;
        AKComboBoxDelegate* delegate = [[AKComboBoxDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSComboBox* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSComboBox* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
