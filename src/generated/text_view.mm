#include "generated/text_view.h"
#include "internal.h"

@interface AKTextViewDelegate : NSObject <NSTextViewDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKTextViewDelegate

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

- (BOOL)textView:(NSTextView*)textView clickedOnLink:(id)link atIndex:(NSUInteger)charIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, bool(cocoon::Object, std::uint64_t)>::emit((__bridge void*)strongHost, "clicked_on_link_at_index", cocoon::internal::wrap<cocoon::Object>(link), static_cast<std::uint64_t>(charIndex));
    return static_cast<::BOOL>(__r);
}

- (void)textView:(NSTextView*)textView clickedOnCell:(id<NSTextAttachmentCell>)cell inRect:(NSRect)cellFrame atIndex:(NSUInteger)charIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextView, void(cocoon::Object, cocoon::Rect, std::uint64_t)>::emit((__bridge void*)strongHost, "clicked_on_cell_in_rect_at_index", cocoon::internal::wrap<cocoon::Object>(cell), cocoon::internal::from(cellFrame), static_cast<std::uint64_t>(charIndex));
}

- (void)textView:(NSTextView*)textView doubleClickedOnCell:(id<NSTextAttachmentCell>)cell inRect:(NSRect)cellFrame atIndex:(NSUInteger)charIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextView, void(cocoon::Object, cocoon::Rect, std::uint64_t)>::emit((__bridge void*)strongHost, "double_clicked_on_cell_in_rect_at_index", cocoon::internal::wrap<cocoon::Object>(cell), cocoon::internal::from(cellFrame), static_cast<std::uint64_t>(charIndex));
}

- (void)textView:(NSTextView*)view draggedCell:(id<NSTextAttachmentCell>)cell inRect:(NSRect)rect event:(NSEvent*)event atIndex:(NSUInteger)charIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextView, void(cocoon::Object, cocoon::Rect, cocoon::Event, std::uint64_t)>::emit((__bridge void*)strongHost, "dragged_cell_in_rect_event_at_index", cocoon::internal::wrap<cocoon::Object>(cell), cocoon::internal::from(rect), cocoon::internal::wrap<cocoon::Event>(event), static_cast<std::uint64_t>(charIndex));
}

- (NSArray<NSPasteboardType>*)textView:(NSTextView*)view writablePasteboardTypesForCell:(id<NSTextAttachmentCell>)cell atIndex:(NSUInteger)charIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, std::vector<std::string>(cocoon::Object, std::uint64_t)>::emit((__bridge void*)strongHost, "writable_pasteboard_types_for_cell_at_index", cocoon::internal::wrap<cocoon::Object>(cell), static_cast<std::uint64_t>(charIndex));
    return cocoon::internal::to_array(__r, [](const std::string& e) -> id
                                      {
                                          return cocoon::internal::to(e);
                                      });
}

- (BOOL)textView:(NSTextView*)view writeCell:(id<NSTextAttachmentCell>)cell atIndex:(NSUInteger)charIndex toPasteboard:(NSPasteboard*)pboard type:(NSPasteboardType)type
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, bool(cocoon::Object, std::uint64_t, cocoon::Pasteboard, std::string)>::emit((__bridge void*)strongHost, "write_cell_at_index_to_pasteboard_type", cocoon::internal::wrap<cocoon::Object>(cell), static_cast<std::uint64_t>(charIndex), cocoon::internal::wrap<cocoon::Pasteboard>(pboard), cocoon::internal::from(type));
    return static_cast<::BOOL>(__r);
}

- (NSRange)textView:(NSTextView*)textView willChangeSelectionFromCharacterRange:(NSRange)oldSelectedCharRange toCharacterRange:(NSRange)newSelectedCharRange
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, cocoon::Range(cocoon::Range, cocoon::Range)>::emit((__bridge void*)strongHost, "will_change_selection_from_character_range_to_character_range", cocoon::internal::from(oldSelectedCharRange), cocoon::internal::from(newSelectedCharRange));
    return cocoon::internal::to(__r);
}

- (NSArray<NSValue*>*)textView:(NSTextView*)textView willChangeSelectionFromCharacterRanges:(NSArray<NSValue*>*)oldSelectedCharRanges toCharacterRanges:(NSArray<NSValue*>*)newSelectedCharRanges
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, std::vector<cocoon::Value>(std::vector<cocoon::Value>, std::vector<cocoon::Value>)>::emit((__bridge void*)strongHost, "will_change_selection_from_character_ranges_to_character_ranges", cocoon::internal::from_array<cocoon::Value>(oldSelectedCharRanges, [](id e) -> cocoon::Value
                                                                                                                                                                                                                                                                                     {
                                                                                                                                                                                                                                                                                         return cocoon::internal::wrap<cocoon::Value>((::NSValue*)e);
                                                                                                                                                                                                                                                                                     }),
                                                                                                                                          cocoon::internal::from_array<cocoon::Value>(newSelectedCharRanges, [](id e) -> cocoon::Value
                                                                                                                                                                                      {
                                                                                                                                                                                          return cocoon::internal::wrap<cocoon::Value>((::NSValue*)e);
                                                                                                                                                                                      }));
    return cocoon::internal::to_array(__r, [](const cocoon::Value& e) -> id
                                      {
                                          return cocoon::internal::native<::NSValue>(e);
                                      });
}

- (BOOL)textView:(NSTextView*)textView shouldChangeTextInRanges:(NSArray<NSValue*>*)affectedRanges replacementStrings:(NSArray<NSString*>*)replacementStrings
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, bool(std::vector<cocoon::Value>, std::vector<std::string>)>::emit((__bridge void*)strongHost, "should_change_text_in_ranges_replacement_strings", cocoon::internal::from_array<cocoon::Value>(affectedRanges, [](id e) -> cocoon::Value
                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                  return cocoon::internal::wrap<cocoon::Value>((::NSValue*)e);
                                                                                                                                                                                                                                              }),
                                                                                                                  cocoon::internal::from_array<std::string>(replacementStrings, [](id e) -> std::string
                                                                                                                                                            {
                                                                                                                                                                return cocoon::internal::from((NSString*)e);
                                                                                                                                                            }));
    return static_cast<::BOOL>(__r);
}

- (NSDictionary<NSAttributedStringKey, id>*)textView:(NSTextView*)textView shouldChangeTypingAttributes:(NSDictionary<NSString*, id>*)oldTypingAttributes toAttributes:(NSDictionary<NSAttributedStringKey, id>*)newTypingAttributes
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, std::map<std::string, cocoon::Object>(std::map<std::string, cocoon::Object>, std::map<std::string, cocoon::Object>)>::emit((__bridge void*)strongHost, "should_change_typing_attributes_to_attributes", cocoon::internal::from_dictionary<std::map<std::string, cocoon::Object>>(oldTypingAttributes, [](id k) -> std::string
                                                                                                                                                                                                                                                                                                                                 {
                                                                                                                                                                                                                                                                                                                                     return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                                                                                                                                 },
                                                                                                                                                                                                                                                                                                                                 [](id v) -> cocoon::Object
                                                                                                                                                                                                                                                                                                                                 {
                                                                                                                                                                                                                                                                                                                                     return cocoon::internal::wrap<cocoon::Object>(v);
                                                                                                                                                                                                                                                                                                                                 }),
                                                                                                                                                                           cocoon::internal::from_dictionary<std::map<std::string, cocoon::Object>>(newTypingAttributes, [](id k) -> std::string
                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                        return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                                                    },
                                                                                                                                                                                                                                                    [](id v) -> cocoon::Object
                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                        return cocoon::internal::wrap<cocoon::Object>(v);
                                                                                                                                                                                                                                                    }));
    return cocoon::internal::to_dictionary(__r, [](const std::string& k) -> id
                                           {
                                               return cocoon::internal::to(k);
                                           },
                                           [](const cocoon::Object& v) -> id
                                           {
                                               return cocoon::internal::native_id(v);
                                           });
}

- (void)textViewDidChangeSelection:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_change_selection", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)textViewDidChangeTypingAttributes:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_change_typing_attributes", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (NSString*)textView:(NSTextView*)textView willDisplayToolTip:(NSString*)tooltip forCharacterAtIndex:(NSUInteger)characterIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, std::string(std::string, std::uint64_t)>::emit((__bridge void*)strongHost, "will_display_tool_tip_for_character_at_index", cocoon::internal::from(tooltip), static_cast<std::uint64_t>(characterIndex));
    return cocoon::internal::to(__r);
}

- (NSArray<NSString*>*)textView:(NSTextView*)textView completions:(NSArray<NSString*>*)words forPartialWordRange:(NSRange)charRange indexOfSelectedItem:(NSInteger*)index
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, std::vector<std::string>(std::vector<std::string>, cocoon::Range, std::int64_t*)>::emit((__bridge void*)strongHost, "completions_for_partial_word_range_index_of_selected_item", cocoon::internal::from_array<std::string>(words, [](id e) -> std::string
                                                                                                                                                                                                                                                                           {
                                                                                                                                                                                                                                                                               return cocoon::internal::from((NSString*)e);
                                                                                                                                                                                                                                                                           }),
                                                                                                                                        cocoon::internal::from(charRange), (std::int64_t*)(index));
    return cocoon::internal::to_array(__r, [](const std::string& e) -> id
                                      {
                                          return cocoon::internal::to(e);
                                      });
}

- (BOOL)textView:(NSTextView*)textView shouldChangeTextInRange:(NSRange)affectedCharRange replacementString:(NSString*)replacementString
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, bool(cocoon::Range, std::string)>::emit((__bridge void*)strongHost, "should_change_text_in_range_replacement_string", cocoon::internal::from(affectedCharRange), cocoon::internal::from(replacementString));
    return static_cast<::BOOL>(__r);
}

- (BOOL)textView:(NSTextView*)textView doCommandBySelector:(SEL)commandSelector
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, bool(std::string)>::emit((__bridge void*)strongHost, "do_command_by_selector", cocoon::internal::from(NSStringFromSelector(commandSelector)));
    return static_cast<::BOOL>(__r);
}

- (NSInteger)textView:(NSTextView*)textView shouldSetSpellingState:(NSInteger)value range:(NSRange)affectedCharRange
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, std::int64_t(std::int64_t, cocoon::Range)>::emit((__bridge void*)strongHost, "should_set_spelling_state_range", static_cast<std::int64_t>(value), cocoon::internal::from(affectedCharRange));
    return static_cast<::NSInteger>(__r);
}

- (NSMenu*)textView:(NSTextView*)view menu:(NSMenu*)menu forEvent:(NSEvent*)event atIndex:(NSUInteger)charIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, cocoon::Menu(cocoon::Menu, cocoon::Event, std::uint64_t)>::emit((__bridge void*)strongHost, "menu_for_event_at_index", cocoon::internal::wrap<cocoon::Menu>(menu), cocoon::internal::wrap<cocoon::Event>(event), static_cast<std::uint64_t>(charIndex));
    return cocoon::internal::native<::NSMenu>(__r);
}

- (NSDictionary<NSTextCheckingOptionKey, id>*)textView:(NSTextView*)view willCheckTextInRange:(NSRange)range options:(NSDictionary<NSTextCheckingOptionKey, id>*)options types:(NSTextCheckingTypes*)checkingTypes
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, std::map<std::string, cocoon::Object>(cocoon::Range, std::map<std::string, cocoon::Object>, std::uint64_t*)>::emit((__bridge void*)strongHost, "will_check_text_in_range_options_types", cocoon::internal::from(range), cocoon::internal::from_dictionary<std::map<std::string, cocoon::Object>>(options, [](id k) -> std::string
                                                                                                                                                                                                                                                                                                                                                 {
                                                                                                                                                                                                                                                                                                                                                     return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                                                                                                                                                 },
                                                                                                                                                                                                                                                                                                                                                 [](id v) -> cocoon::Object
                                                                                                                                                                                                                                                                                                                                                 {
                                                                                                                                                                                                                                                                                                                                                     return cocoon::internal::wrap<cocoon::Object>(v);
                                                                                                                                                                                                                                                                                                                                                 }),
                                                                                                                                                                   (std::uint64_t*)(checkingTypes));
    return cocoon::internal::to_dictionary(__r, [](const std::string& k) -> id
                                           {
                                               return cocoon::internal::to(k);
                                           },
                                           [](const cocoon::Object& v) -> id
                                           {
                                               return cocoon::internal::native_id(v);
                                           });
}

- (NSArray<NSTextCheckingResult*>*)textView:(NSTextView*)view didCheckTextInRange:(NSRange)range types:(NSTextCheckingTypes)checkingTypes options:(NSDictionary<NSTextCheckingOptionKey, id>*)options results:(NSArray<NSTextCheckingResult*>*)results orthography:(NSOrthography*)orthography wordCount:(NSInteger)wordCount
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, std::vector<cocoon::TextCheckingResult>(cocoon::Range, std::uint64_t, std::map<std::string, cocoon::Object>, std::vector<cocoon::TextCheckingResult>, cocoon::Orthography, std::int64_t)>::emit((__bridge void*)strongHost, "did_check_text_in_range_types_options_results_orthography_word_count", cocoon::internal::from(range), static_cast<std::uint64_t>(checkingTypes), cocoon::internal::from_dictionary<std::map<std::string, cocoon::Object>>(options, [](id k) -> std::string
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       },
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       [](id v) -> cocoon::Object
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           return cocoon::internal::wrap<cocoon::Object>(v);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       }),
                                                                                                                                                                                                                                                cocoon::internal::from_array<cocoon::TextCheckingResult>(results, [](id e) -> cocoon::TextCheckingResult
                                                                                                                                                                                                                                                                                                         {
                                                                                                                                                                                                                                                                                                             return cocoon::internal::wrap<cocoon::TextCheckingResult>((::NSTextCheckingResult*)e);
                                                                                                                                                                                                                                                                                                         }),
                                                                                                                                                                                                                                                cocoon::internal::wrap<cocoon::Orthography>(orthography), static_cast<std::int64_t>(wordCount));
    return cocoon::internal::to_array(__r, [](const cocoon::TextCheckingResult& e) -> id
                                      {
                                          return cocoon::internal::native<::NSTextCheckingResult>(e);
                                      });
}

- (NSURL*)textView:(NSTextView*)textView URLForContentsOfTextAttachment:(NSTextAttachment*)textAttachment atIndex:(NSUInteger)charIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, cocoon::URL(cocoon::TextAttachment, std::uint64_t)>::emit((__bridge void*)strongHost, "u_rl_for_contents_of_text_attachment_at_index", cocoon::internal::wrap<cocoon::TextAttachment>(textAttachment), static_cast<std::uint64_t>(charIndex));
    return cocoon::internal::native<::NSURL>(__r);
}

- (NSSharingServicePicker*)textView:(NSTextView*)textView willShowSharingServicePicker:(NSSharingServicePicker*)servicePicker forItems:(NSArray*)items
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, cocoon::SharingServicePicker(cocoon::SharingServicePicker, std::vector<cocoon::Object>)>::emit((__bridge void*)strongHost, "will_show_sharing_service_picker_for_items", cocoon::internal::wrap<cocoon::SharingServicePicker>(servicePicker), cocoon::internal::from_array<cocoon::Object>(items, [](id e) -> cocoon::Object
                                                                                                                                                                                                                                                                                                                                           {
                                                                                                                                                                                                                                                                                                                                               return cocoon::internal::wrap<cocoon::Object>(e);
                                                                                                                                                                                                                                                                                                                                           }));
    return cocoon::internal::native<::NSSharingServicePicker>(__r);
}

- (NSUndoManager*)undoManagerForTextView:(NSTextView*)view
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, cocoon::UndoManager()>::emit((__bridge void*)strongHost, "undo_manager_for_text_view");
    return cocoon::internal::native<::NSUndoManager>(__r);
}

- (NSArray<NSTouchBarItemIdentifier>*)textView:(NSTextView*)textView shouldUpdateTouchBarItemIdentifiers:(NSArray<NSTouchBarItemIdentifier>*)identifiers
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, std::vector<std::string>(std::vector<std::string>)>::emit((__bridge void*)strongHost, "should_update_touch_bar_item_identifiers", cocoon::internal::from_array<std::string>(identifiers, [](id e) -> std::string
                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                return cocoon::internal::from((NSString*)e);
                                                                                                                                                                                                                            }));
    return cocoon::internal::to_array(__r, [](const std::string& e) -> id
                                      {
                                          return cocoon::internal::to(e);
                                      });
}

- (NSArray*)textView:(NSTextView*)textView candidatesForSelectedRange:(NSRange)selectedRange
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, std::vector<cocoon::Object>(cocoon::Range)>::emit((__bridge void*)strongHost, "candidates_for_selected_range", cocoon::internal::from(selectedRange));
    return cocoon::internal::to_array(__r, [](const cocoon::Object& e) -> id
                                      {
                                          return cocoon::internal::native_id(e);
                                      });
}

- (NSArray<NSTextCheckingResult*>*)textView:(NSTextView*)textView candidates:(NSArray<NSTextCheckingResult*>*)candidates forSelectedRange:(NSRange)selectedRange
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, std::vector<cocoon::TextCheckingResult>(std::vector<cocoon::TextCheckingResult>, cocoon::Range)>::emit((__bridge void*)strongHost, "text_view_candidates_for_selected_range", cocoon::internal::from_array<cocoon::TextCheckingResult>(candidates, [](id e) -> cocoon::TextCheckingResult
                                                                                                                                                                                                                                                                                       {
                                                                                                                                                                                                                                                                                           return cocoon::internal::wrap<cocoon::TextCheckingResult>((::NSTextCheckingResult*)e);
                                                                                                                                                                                                                                                                                       }),
                                                                                                                                                       cocoon::internal::from(selectedRange));
    return cocoon::internal::to_array(__r, [](const cocoon::TextCheckingResult& e) -> id
                                      {
                                          return cocoon::internal::native<::NSTextCheckingResult>(e);
                                      });
}

- (BOOL)textView:(NSTextView*)textView shouldSelectCandidateAtIndex:(NSUInteger)index
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, bool(std::uint64_t)>::emit((__bridge void*)strongHost, "should_select_candidate_at_index", static_cast<std::uint64_t>(index));
    return static_cast<::BOOL>(__r);
}

- (void)textViewWritingToolsWillBegin:(NSTextView*)textView
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextView, void()>::emit((__bridge void*)strongHost, "writing_tools_will_begin");
}

- (void)textViewWritingToolsDidEnd:(NSTextView*)textView
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextView, void()>::emit((__bridge void*)strongHost, "writing_tools_did_end");
}

- (NSArray<NSValue*>*)textView:(NSTextView*)textView writingToolsIgnoredRangesInEnclosingRange:(NSRange)enclosingRange
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextView, std::vector<cocoon::Value>(cocoon::Range)>::emit((__bridge void*)strongHost, "writing_tools_ignored_ranges_in_enclosing_range", cocoon::internal::from(enclosingRange));
    return cocoon::internal::to_array(__r, [](const cocoon::Value& e) -> id
                                      {
                                          return cocoon::internal::native<::NSValue>(e);
                                      });
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
    if (selector == @selector(textView:clickedOnLink:atIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, bool(cocoon::Object, std::uint64_t)>::connected((__bridge void*)strongHost, "clicked_on_link_at_index");
    }
    if (selector == @selector(textView:clickedOnCell:inRect:atIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, void(cocoon::Object, cocoon::Rect, std::uint64_t)>::connected((__bridge void*)strongHost, "clicked_on_cell_in_rect_at_index");
    }
    if (selector == @selector(textView:doubleClickedOnCell:inRect:atIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, void(cocoon::Object, cocoon::Rect, std::uint64_t)>::connected((__bridge void*)strongHost, "double_clicked_on_cell_in_rect_at_index");
    }
    if (selector == @selector(textView:draggedCell:inRect:event:atIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, void(cocoon::Object, cocoon::Rect, cocoon::Event, std::uint64_t)>::connected((__bridge void*)strongHost, "dragged_cell_in_rect_event_at_index");
    }
    if (selector == @selector(textView:writablePasteboardTypesForCell:atIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, std::vector<std::string>(cocoon::Object, std::uint64_t)>::connected((__bridge void*)strongHost, "writable_pasteboard_types_for_cell_at_index");
    }
    if (selector == @selector(textView:writeCell:atIndex:toPasteboard:type:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, bool(cocoon::Object, std::uint64_t, cocoon::Pasteboard, std::string)>::connected((__bridge void*)strongHost, "write_cell_at_index_to_pasteboard_type");
    }
    if (selector == @selector(textView:willChangeSelectionFromCharacterRange:toCharacterRange:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, cocoon::Range(cocoon::Range, cocoon::Range)>::connected((__bridge void*)strongHost, "will_change_selection_from_character_range_to_character_range");
    }
    if (selector == @selector(textView:willChangeSelectionFromCharacterRanges:toCharacterRanges:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, std::vector<cocoon::Value>(std::vector<cocoon::Value>, std::vector<cocoon::Value>)>::connected((__bridge void*)strongHost, "will_change_selection_from_character_ranges_to_character_ranges");
    }
    if (selector == @selector(textView:shouldChangeTextInRanges:replacementStrings:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, bool(std::vector<cocoon::Value>, std::vector<std::string>)>::connected((__bridge void*)strongHost, "should_change_text_in_ranges_replacement_strings");
    }
    if (selector == @selector(textView:shouldChangeTypingAttributes:toAttributes:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, std::map<std::string, cocoon::Object>(std::map<std::string, cocoon::Object>, std::map<std::string, cocoon::Object>)>::connected((__bridge void*)strongHost, "should_change_typing_attributes_to_attributes");
    }
    if (selector == @selector(textViewDidChangeSelection:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_change_selection");
    }
    if (selector == @selector(textViewDidChangeTypingAttributes:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_change_typing_attributes");
    }
    if (selector == @selector(textView:willDisplayToolTip:forCharacterAtIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, std::string(std::string, std::uint64_t)>::connected((__bridge void*)strongHost, "will_display_tool_tip_for_character_at_index");
    }
    if (selector == @selector(textView:completions:forPartialWordRange:indexOfSelectedItem:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, std::vector<std::string>(std::vector<std::string>, cocoon::Range, std::int64_t*)>::connected((__bridge void*)strongHost, "completions_for_partial_word_range_index_of_selected_item");
    }
    if (selector == @selector(textView:shouldChangeTextInRange:replacementString:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, bool(cocoon::Range, std::string)>::connected((__bridge void*)strongHost, "should_change_text_in_range_replacement_string");
    }
    if (selector == @selector(textView:doCommandBySelector:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, bool(std::string)>::connected((__bridge void*)strongHost, "do_command_by_selector");
    }
    if (selector == @selector(textView:shouldSetSpellingState:range:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, std::int64_t(std::int64_t, cocoon::Range)>::connected((__bridge void*)strongHost, "should_set_spelling_state_range");
    }
    if (selector == @selector(textView:menu:forEvent:atIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, cocoon::Menu(cocoon::Menu, cocoon::Event, std::uint64_t)>::connected((__bridge void*)strongHost, "menu_for_event_at_index");
    }
    if (selector == @selector(textView:willCheckTextInRange:options:types:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, std::map<std::string, cocoon::Object>(cocoon::Range, std::map<std::string, cocoon::Object>, std::uint64_t*)>::connected((__bridge void*)strongHost, "will_check_text_in_range_options_types");
    }
    if (selector == @selector(textView:didCheckTextInRange:types:options:results:orthography:wordCount:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, std::vector<cocoon::TextCheckingResult>(cocoon::Range, std::uint64_t, std::map<std::string, cocoon::Object>, std::vector<cocoon::TextCheckingResult>, cocoon::Orthography, std::int64_t)>::connected((__bridge void*)strongHost, "did_check_text_in_range_types_options_results_orthography_word_count");
    }
    if (selector == @selector(textView:URLForContentsOfTextAttachment:atIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, cocoon::URL(cocoon::TextAttachment, std::uint64_t)>::connected((__bridge void*)strongHost, "u_rl_for_contents_of_text_attachment_at_index");
    }
    if (selector == @selector(textView:willShowSharingServicePicker:forItems:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, cocoon::SharingServicePicker(cocoon::SharingServicePicker, std::vector<cocoon::Object>)>::connected((__bridge void*)strongHost, "will_show_sharing_service_picker_for_items");
    }
    if (selector == @selector(undoManagerForTextView:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, cocoon::UndoManager()>::connected((__bridge void*)strongHost, "undo_manager_for_text_view");
    }
    if (selector == @selector(textView:shouldUpdateTouchBarItemIdentifiers:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, std::vector<std::string>(std::vector<std::string>)>::connected((__bridge void*)strongHost, "should_update_touch_bar_item_identifiers");
    }
    if (selector == @selector(textView:candidatesForSelectedRange:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, std::vector<cocoon::Object>(cocoon::Range)>::connected((__bridge void*)strongHost, "candidates_for_selected_range");
    }
    if (selector == @selector(textView:candidates:forSelectedRange:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, std::vector<cocoon::TextCheckingResult>(std::vector<cocoon::TextCheckingResult>, cocoon::Range)>::connected((__bridge void*)strongHost, "text_view_candidates_for_selected_range");
    }
    if (selector == @selector(textView:shouldSelectCandidateAtIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, bool(std::uint64_t)>::connected((__bridge void*)strongHost, "should_select_candidate_at_index");
    }
    if (selector == @selector(textViewWritingToolsWillBegin:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, void()>::connected((__bridge void*)strongHost, "writing_tools_will_begin");
    }
    if (selector == @selector(textViewWritingToolsDidEnd:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, void()>::connected((__bridge void*)strongHost, "writing_tools_did_end");
    }
    if (selector == @selector(textView:writingToolsIgnoredRangesInEnclosingRange:))
    {
        return strongHost && cocoon::Signal<cocoon::TextView, std::vector<cocoon::Value>(cocoon::Range)>::connected((__bridge void*)strongHost, "writing_tools_ignored_ranges_in_enclosing_range");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    TextView::TextView(bool using_text_layout_manager) : TextView(Adopt{cocoon::internal::retain([[::NSTextView alloc] initUsingTextLayoutManager:static_cast<::BOOL>(using_text_layout_manager)])})
    {
        TextView::install_delegate_delegate_(handle());
    }

    TextView::TextView(const Rect& frame_rect) : TextView(Adopt{cocoon::internal::retain([[::NSTextView alloc] initWithFrame:cocoon::internal::to(frame_rect)])})
    {
        TextView::install_delegate_delegate_(handle());
    }

    TextView::TextView(const Rect& frame_rect, const TextContainer& container) : TextView(Adopt{cocoon::internal::retain([[::NSTextView alloc] initWithFrame:cocoon::internal::to(frame_rect) textContainer:cocoon::internal::native<::NSTextContainer>(container)])})
    {
        TextView::install_delegate_delegate_(handle());
    }

    TextView::TextView() : TextView(Adopt{cocoon::internal::retain([[::NSTextView alloc] init])})
    {
        TextView::install_delegate_delegate_(handle());
    }

    TextView::TextView(std::nullptr_t) : Text(nullptr)
    {
    }

    TextView::TextView(Adopt adopt) : Text(adopt)
    {
    }

    void TextView::align_justified(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) alignJustified:cocoon::internal::native_id(sender)];
    }

    void TextView::break_undo_coalescing() const
    {
        [cocoon::internal::ns<::NSTextView>(this) breakUndoCoalescing];
    }

    void TextView::change_attributes(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) changeAttributes:cocoon::internal::native_id(sender)];
    }

    void TextView::change_color(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) changeColor:cocoon::internal::native_id(sender)];
    }

    void TextView::change_document_background_color(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) changeDocumentBackgroundColor:cocoon::internal::native_id(sender)];
    }

    void TextView::change_layout_orientation(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) changeLayoutOrientation:cocoon::internal::native_id(sender)];
    }

    std::uint64_t TextView::character_index_for_insertion_at_point(const Point& point) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSTextView>(this) characterIndexForInsertionAtPoint:cocoon::internal::to(point)]);
    }

    void TextView::check_text_in_document(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) checkTextInDocument:cocoon::internal::native_id(sender)];
    }

    void TextView::check_text_in_range(const Range& range, std::uint64_t checking_types, const std::map<std::string, Object>& options) const
    {
        [cocoon::internal::ns<::NSTextView>(this) checkTextInRange:cocoon::internal::to(range)
                                                             types:static_cast<::NSTextCheckingTypes>(checking_types)
                                                           options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                   {
                                                                                                       return cocoon::internal::to(k);
                                                                                                   },
                                                                                                   [](const Object& v) -> id
                                                                                                   {
                                                                                                       return cocoon::internal::native_id(v);
                                                                                                   })];
    }

    void TextView::check_text_in_selection(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) checkTextInSelection:cocoon::internal::native_id(sender)];
    }

    void TextView::clean_up_after_drag_operation() const
    {
        [cocoon::internal::ns<::NSTextView>(this) cleanUpAfterDragOperation];
    }

    void TextView::clicked_on_link(const Object& link, std::uint64_t char_index) const
    {
        [cocoon::internal::ns<::NSTextView>(this) clickedOnLink:cocoon::internal::native_id(link) atIndex:static_cast<::NSUInteger>(char_index)];
    }

    void TextView::complete(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) complete:cocoon::internal::native_id(sender)];
    }

    std::vector<std::string> TextView::completions_for_partial_word_range(const Range& char_range, std::int64_t* index) const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTextView>(this) completionsForPartialWordRange:cocoon::internal::to(char_range) indexOfSelectedItem:(::NSInteger*)(index)], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void TextView::did_change_text() const
    {
        [cocoon::internal::ns<::NSTextView>(this) didChangeText];
    }

    Image TextView::drag_image_for_selection_with_event(const Event& event, Point* origin) const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSTextView>(this) dragImageForSelectionWithEvent:cocoon::internal::native<::NSEvent>(event) origin:(::NSPointPointer)(origin)]);
    }

    DragOperation TextView::drag_operation_for_dragging_info(const Object& drag_info, const std::string& type) const
    {
        return static_cast<DragOperation>([cocoon::internal::ns<::NSTextView>(this) dragOperationForDraggingInfo:cocoon::internal::native_id(drag_info) type:cocoon::internal::to(type)]);
    }

    bool TextView::drag_selection_with_event(const Event& event, const Size& mouse_offset, bool slide_back) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) dragSelectionWithEvent:cocoon::internal::native<::NSEvent>(event) offset:cocoon::internal::to(mouse_offset) slideBack:static_cast<::BOOL>(slide_back)]);
    }

    void TextView::draw_insertion_point_in_rect(const Rect& rect, const Color& color, bool flag) const
    {
        [cocoon::internal::ns<::NSTextView>(this) drawInsertionPointInRect:cocoon::internal::to(rect) color:cocoon::internal::native<::NSColor>(color) turnedOn:static_cast<::BOOL>(flag)];
    }

    void TextView::draw_text_highlight_background_for_text_range(const TextRange& text_range, const Point& origin) const
    {
        [cocoon::internal::ns<::NSTextView>(this) drawTextHighlightBackgroundForTextRange:cocoon::internal::native<::NSTextRange>(text_range) origin:cocoon::internal::to(origin)];
    }

    void TextView::draw_view_background_in_rect(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSTextView>(this) drawViewBackgroundInRect:cocoon::internal::to(rect)];
    }

    TextView TextView::field_editor()
    {
        return cocoon::internal::wrap<TextView>([::NSTextView fieldEditor]);
    }

    void TextView::handle_text_checking_results(const std::vector<TextCheckingResult>& results, const Range& range, std::uint64_t checking_types, const std::map<std::string, Object>& options, const Orthography& orthography, std::int64_t word_count) const
    {
        [cocoon::internal::ns<::NSTextView>(this) handleTextCheckingResults:cocoon::internal::to_array(results, [](const TextCheckingResult& e) -> id
                                                                                                       {
                                                                                                           return cocoon::internal::native<::NSTextCheckingResult>(e);
                                                                                                       })
                                                                   forRange:cocoon::internal::to(range)
                                                                      types:static_cast<::NSTextCheckingTypes>(checking_types)
                                                                    options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                            {
                                                                                                                return cocoon::internal::to(k);
                                                                                                            },
                                                                                                            [](const Object& v) -> id
                                                                                                            {
                                                                                                                return cocoon::internal::native_id(v);
                                                                                                            })
                                                                orthography:cocoon::internal::native<::NSOrthography>(orthography)
                                                                  wordCount:static_cast<::NSInteger>(word_count)];
    }

    void TextView::highlight(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) highlight:cocoon::internal::native_id(sender)];
    }

    void TextView::insert_completion(const std::string& word, const Range& char_range, std::int64_t movement, bool flag) const
    {
        [cocoon::internal::ns<::NSTextView>(this) insertCompletion:cocoon::internal::to(word) forPartialWordRange:cocoon::internal::to(char_range) movement:static_cast<::NSInteger>(movement) isFinal:static_cast<::BOOL>(flag)];
    }

    void TextView::invalidate_text_container_origin() const
    {
        [cocoon::internal::ns<::NSTextView>(this) invalidateTextContainerOrigin];
    }

    void TextView::loosen_kerning(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) loosenKerning:cocoon::internal::native_id(sender)];
    }

    void TextView::lower_baseline(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) lowerBaseline:cocoon::internal::native_id(sender)];
    }

    void TextView::order_front_link_panel(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) orderFrontLinkPanel:cocoon::internal::native_id(sender)];
    }

    void TextView::order_front_list_panel(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) orderFrontListPanel:cocoon::internal::native_id(sender)];
    }

    void TextView::order_front_sharing_service_picker(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) orderFrontSharingServicePicker:cocoon::internal::native_id(sender)];
    }

    void TextView::order_front_spacing_panel(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) orderFrontSpacingPanel:cocoon::internal::native_id(sender)];
    }

    void TextView::order_front_substitutions_panel(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) orderFrontSubstitutionsPanel:cocoon::internal::native_id(sender)];
    }

    void TextView::order_front_table_panel(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) orderFrontTablePanel:cocoon::internal::native_id(sender)];
    }

    void TextView::outline(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) outline:cocoon::internal::native_id(sender)];
    }

    void TextView::paste_as_plain_text(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) pasteAsPlainText:cocoon::internal::native_id(sender)];
    }

    void TextView::paste_as_rich_text(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) pasteAsRichText:cocoon::internal::native_id(sender)];
    }

    void TextView::perform_find_panel_action(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) performFindPanelAction:cocoon::internal::native_id(sender)];
    }

    bool TextView::perform_validated_replacement_in_range(const Range& range, const AttributedString& attributed_string) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) performValidatedReplacementInRange:cocoon::internal::to(range) withAttributedString:cocoon::internal::native<::NSAttributedString>(attributed_string)]);
    }

    std::string TextView::preferred_pasteboard_type_from_array(const std::vector<std::string>& available_types, const std::vector<std::string>& allowed_types) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextView>(this) preferredPasteboardTypeFromArray:cocoon::internal::to_array(available_types, [](const std::string& e) -> id
                                                                                                                                            {
                                                                                                                                                return cocoon::internal::to(e);
                                                                                                                                            })
                                                                                      restrictedToTypesFromArray:cocoon::internal::to_array(allowed_types, [](const std::string& e) -> id
                                                                                                                                            {
                                                                                                                                                return cocoon::internal::to(e);
                                                                                                                                            })]);
    }

    std::vector<Object> TextView::quick_look_previewable_items_in_ranges(const std::vector<Value>& ranges) const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSTextView>(this) quickLookPreviewableItemsInRanges:cocoon::internal::to_array(ranges, [](const Value& e) -> id
                                                                                                                                                           {
                                                                                                                                                               return cocoon::internal::native<::NSValue>(e);
                                                                                                                                                           })],
                                                    [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    void TextView::raise_baseline(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) raiseBaseline:cocoon::internal::native_id(sender)];
    }

    bool TextView::read_selection_from_pasteboard(const Pasteboard& pboard) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) readSelectionFromPasteboard:cocoon::internal::native<::NSPasteboard>(pboard)]);
    }

    bool TextView::read_selection_from_pasteboard(const Pasteboard& pboard, const std::string& type) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) readSelectionFromPasteboard:cocoon::internal::native<::NSPasteboard>(pboard) type:cocoon::internal::to(type)]);
    }

    void TextView::register_for_services()
    {
        [::NSTextView registerForServices];
    }

    void TextView::replace_text_container(const TextContainer& new_container) const
    {
        [cocoon::internal::ns<::NSTextView>(this) replaceTextContainer:cocoon::internal::native<::NSTextContainer>(new_container)];
    }

    void TextView::ruler_view(const RulerView& ruler, const RulerMarker& marker) const
    {
        [cocoon::internal::ns<::NSTextView>(this) rulerView:cocoon::internal::native<::NSRulerView>(ruler) didAddMarker:cocoon::internal::native<::NSRulerMarker>(marker)];
    }

    void TextView::ruler_view(const RulerView& ruler, const Event& event) const
    {
        [cocoon::internal::ns<::NSTextView>(this) rulerView:cocoon::internal::native<::NSRulerView>(ruler) handleMouseDown:cocoon::internal::native<::NSEvent>(event)];
    }

    double TextView::ruler_view(const RulerView& ruler, const RulerMarker& marker, double location) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTextView>(this) rulerView:cocoon::internal::native<::NSRulerView>(ruler) willAddMarker:cocoon::internal::native<::NSRulerMarker>(marker) atLocation:static_cast<::CGFloat>(location)]);
    }

    ScrollView TextView::scrollable_document_content_text_view()
    {
        return cocoon::internal::wrap<ScrollView>([::NSTextView scrollableDocumentContentTextView]);
    }

    ScrollView TextView::scrollable_plain_document_content_text_view()
    {
        return cocoon::internal::wrap<ScrollView>([::NSTextView scrollablePlainDocumentContentTextView]);
    }

    ScrollView TextView::scrollable_text_view()
    {
        return cocoon::internal::wrap<ScrollView>([::NSTextView scrollableTextView]);
    }

    Range TextView::selection_range_for_proposed_range(const Range& proposed_char_range, SelectionGranularity granularity) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextView>(this) selectionRangeForProposedRange:cocoon::internal::to(proposed_char_range) granularity:static_cast<::NSSelectionGranularity>(granularity)]);
    }

    void TextView::set_alignment(TextAlignment alignment, const Range& range) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setAlignment:static_cast<::NSTextAlignment>(alignment) range:cocoon::internal::to(range)];
    }

    void TextView::set_base_writing_direction(WritingDirection writing_direction, const Range& range) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setBaseWritingDirection:static_cast<::NSWritingDirection>(writing_direction) range:cocoon::internal::to(range)];
    }

    void TextView::set_constrained_frame_size(const Size& desired_size) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setConstrainedFrameSize:cocoon::internal::to(desired_size)];
    }

    void TextView::set_layout_orientation(TextLayoutOrientation orientation) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setLayoutOrientation:static_cast<::NSTextLayoutOrientation>(orientation)];
    }

    void TextView::set_needs_display_in_rect(const Rect& rect, bool flag) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setNeedsDisplayInRect:cocoon::internal::to(rect) avoidAdditionalLayout:static_cast<::BOOL>(flag)];
    }

    void TextView::set_selected_range(const Range& char_range) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setSelectedRange:cocoon::internal::to(char_range)];
    }

    void TextView::set_selected_range(const Range& char_range, SelectionAffinity affinity, bool still_selecting_flag) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setSelectedRange:cocoon::internal::to(char_range) affinity:static_cast<::NSSelectionAffinity>(affinity) stillSelecting:static_cast<::BOOL>(still_selecting_flag)];
    }

    void TextView::set_selected_ranges(const std::vector<Value>& ranges, SelectionAffinity affinity, bool still_selecting_flag) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setSelectedRanges:cocoon::internal::to_array(ranges, [](const Value& e) -> id
                                                                                               {
                                                                                                   return cocoon::internal::native<::NSValue>(e);
                                                                                               })
                                                           affinity:static_cast<::NSSelectionAffinity>(affinity)
                                                     stillSelecting:static_cast<::BOOL>(still_selecting_flag)];
    }

    void TextView::set_spelling_state(std::int64_t value, const Range& char_range) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setSpellingState:static_cast<::NSInteger>(value) range:cocoon::internal::to(char_range)];
    }

    bool TextView::should_change_text_in_range(const Range& affected_char_range, const std::string& replacement_string) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) shouldChangeTextInRange:cocoon::internal::to(affected_char_range) replacementString:cocoon::internal::to(replacement_string)]);
    }

    bool TextView::should_change_text_in_ranges(const std::vector<Value>& affected_ranges, const std::vector<std::string>& replacement_strings) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) shouldChangeTextInRanges:cocoon::internal::to_array(affected_ranges, [](const Value& e) -> id
                                                                                                                               {
                                                                                                                                   return cocoon::internal::native<::NSValue>(e);
                                                                                                                               })
                                                                                 replacementStrings:cocoon::internal::to_array(replacement_strings, [](const std::string& e) -> id
                                                                                                                               {
                                                                                                                                   return cocoon::internal::to(e);
                                                                                                                               })]);
    }

    void TextView::show_find_indicator_for_range(const Range& char_range) const
    {
        [cocoon::internal::ns<::NSTextView>(this) showFindIndicatorForRange:cocoon::internal::to(char_range)];
    }

    Range TextView::smart_delete_range_for_proposed_range(const Range& proposed_char_range) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextView>(this) smartDeleteRangeForProposedRange:cocoon::internal::to(proposed_char_range)]);
    }

    std::string TextView::smart_insert_after_string_for_string(const std::string& paste_string, const Range& char_range_to_replace) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextView>(this) smartInsertAfterStringForString:cocoon::internal::to(paste_string) replacingRange:cocoon::internal::to(char_range_to_replace)]);
    }

    std::string TextView::smart_insert_before_string_for_string(const std::string& paste_string, const Range& char_range_to_replace) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextView>(this) smartInsertBeforeStringForString:cocoon::internal::to(paste_string) replacingRange:cocoon::internal::to(char_range_to_replace)]);
    }

    void TextView::smart_insert_for_string(const std::string& paste_string, const Range& char_range_to_replace, std::string& before_string, std::string& after_string) const
    {
        NSString* __v_before_string = nil;
        NSString* __v_after_string = nil;
        [cocoon::internal::ns<::NSTextView>(this) smartInsertForString:cocoon::internal::to(paste_string) replacingRange:cocoon::internal::to(char_range_to_replace) beforeString:&__v_before_string afterString:&__v_after_string];
        before_string = cocoon::internal::from(__v_before_string);
        after_string = cocoon::internal::from(__v_after_string);
    }

    void TextView::start_speaking(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) startSpeaking:cocoon::internal::native_id(sender)];
    }

    void TextView::stop_speaking(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) stopSpeaking:cocoon::internal::native_id(sender)];
    }

    TextView TextView::text_view_using_text_layout_manager(bool using_text_layout_manager)
    {
        return cocoon::internal::wrap<TextView>([::NSTextView textViewUsingTextLayoutManager:static_cast<::BOOL>(using_text_layout_manager)]);
    }

    void TextView::tighten_kerning(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) tightenKerning:cocoon::internal::native_id(sender)];
    }

    void TextView::toggle_automatic_dash_substitution(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) toggleAutomaticDashSubstitution:cocoon::internal::native_id(sender)];
    }

    void TextView::toggle_automatic_data_detection(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) toggleAutomaticDataDetection:cocoon::internal::native_id(sender)];
    }

    void TextView::toggle_automatic_link_detection(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) toggleAutomaticLinkDetection:cocoon::internal::native_id(sender)];
    }

    void TextView::toggle_automatic_quote_substitution(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) toggleAutomaticQuoteSubstitution:cocoon::internal::native_id(sender)];
    }

    void TextView::toggle_automatic_spelling_correction(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) toggleAutomaticSpellingCorrection:cocoon::internal::native_id(sender)];
    }

    void TextView::toggle_automatic_text_completion(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) toggleAutomaticTextCompletion:cocoon::internal::native_id(sender)];
    }

    void TextView::toggle_automatic_text_replacement(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) toggleAutomaticTextReplacement:cocoon::internal::native_id(sender)];
    }

    void TextView::toggle_continuous_spell_checking(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) toggleContinuousSpellChecking:cocoon::internal::native_id(sender)];
    }

    void TextView::toggle_grammar_checking(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) toggleGrammarChecking:cocoon::internal::native_id(sender)];
    }

    void TextView::toggle_quick_look_preview_panel(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) toggleQuickLookPreviewPanel:cocoon::internal::native_id(sender)];
    }

    void TextView::toggle_smart_insert_delete(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) toggleSmartInsertDelete:cocoon::internal::native_id(sender)];
    }

    void TextView::turn_off_kerning(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) turnOffKerning:cocoon::internal::native_id(sender)];
    }

    void TextView::turn_off_ligatures(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) turnOffLigatures:cocoon::internal::native_id(sender)];
    }

    void TextView::update_candidates() const
    {
        [cocoon::internal::ns<::NSTextView>(this) updateCandidates];
    }

    void TextView::update_drag_type_registration() const
    {
        [cocoon::internal::ns<::NSTextView>(this) updateDragTypeRegistration];
    }

    void TextView::update_font_panel() const
    {
        [cocoon::internal::ns<::NSTextView>(this) updateFontPanel];
    }

    void TextView::update_insertion_point_state_and_restart_timer(bool restart_flag) const
    {
        [cocoon::internal::ns<::NSTextView>(this) updateInsertionPointStateAndRestartTimer:static_cast<::BOOL>(restart_flag)];
    }

    void TextView::update_quick_look_preview_panel() const
    {
        [cocoon::internal::ns<::NSTextView>(this) updateQuickLookPreviewPanel];
    }

    void TextView::update_ruler() const
    {
        [cocoon::internal::ns<::NSTextView>(this) updateRuler];
    }

    void TextView::update_text_touch_bar_items() const
    {
        [cocoon::internal::ns<::NSTextView>(this) updateTextTouchBarItems];
    }

    void TextView::update_touch_bar_item_identifiers() const
    {
        [cocoon::internal::ns<::NSTextView>(this) updateTouchBarItemIdentifiers];
    }

    void TextView::use_all_ligatures(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) useAllLigatures:cocoon::internal::native_id(sender)];
    }

    void TextView::use_standard_kerning(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) useStandardKerning:cocoon::internal::native_id(sender)];
    }

    void TextView::use_standard_ligatures(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextView>(this) useStandardLigatures:cocoon::internal::native_id(sender)];
    }

    Object TextView::valid_requestor_for_send_type(const std::string& send_type, const std::string& return_type) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTextView>(this) validRequestorForSendType:cocoon::internal::to(send_type) returnType:cocoon::internal::to(return_type)]);
    }

    bool TextView::write_selection_to_pasteboard(const Pasteboard& pboard, const std::string& type) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) writeSelectionToPasteboard:cocoon::internal::native<::NSPasteboard>(pboard) type:cocoon::internal::to(type)]);
    }

    bool TextView::write_selection_to_pasteboard(const Pasteboard& pboard, const std::vector<std::string>& types) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) writeSelectionToPasteboard:cocoon::internal::native<::NSPasteboard>(pboard)
                                                                                                types:cocoon::internal::to_array(types, [](const std::string& e) -> id
                                                                                                                                 {
                                                                                                                                     return cocoon::internal::to(e);
                                                                                                                                 })]);
    }

    std::vector<std::string> TextView::acceptable_drag_types() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTextView>(this) acceptableDragTypes], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    bool TextView::accepts_glyph_info() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) acceptsGlyphInfo]);
    }

    void TextView::set_accepts_glyph_info(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setAcceptsGlyphInfo:static_cast<::BOOL>(value)];
    }

    std::vector<std::string> TextView::allowed_input_source_locales() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTextView>(this) allowedInputSourceLocales], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void TextView::set_allowed_input_source_locales(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setAllowedInputSourceLocales:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                          {
                                                                                                              return cocoon::internal::to(e);
                                                                                                          })];
    }

    WritingToolsResultOptions TextView::allowed_writing_tools_result_options() const
    {
        return static_cast<WritingToolsResultOptions>([cocoon::internal::ns<::NSTextView>(this) allowedWritingToolsResultOptions]);
    }

    void TextView::set_allowed_writing_tools_result_options(WritingToolsResultOptions value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setAllowedWritingToolsResultOptions:static_cast<::NSWritingToolsResultOptions>(value)];
    }

    bool TextView::allows_character_picker_touch_bar_item() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) allowsCharacterPickerTouchBarItem]);
    }

    void TextView::set_allows_character_picker_touch_bar_item(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setAllowsCharacterPickerTouchBarItem:static_cast<::BOOL>(value)];
    }

    bool TextView::allows_document_background_color_change() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) allowsDocumentBackgroundColorChange]);
    }

    void TextView::set_allows_document_background_color_change(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setAllowsDocumentBackgroundColorChange:static_cast<::BOOL>(value)];
    }

    bool TextView::allows_image_editing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) allowsImageEditing]);
    }

    void TextView::set_allows_image_editing(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setAllowsImageEditing:static_cast<::BOOL>(value)];
    }

    bool TextView::allows_undo() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) allowsUndo]);
    }

    void TextView::set_allows_undo(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setAllowsUndo:static_cast<::BOOL>(value)];
    }

    bool TextView::is_automatic_dash_substitution_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) isAutomaticDashSubstitutionEnabled]);
    }

    void TextView::set_automatic_dash_substitution_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setAutomaticDashSubstitutionEnabled:static_cast<::BOOL>(value)];
    }

    bool TextView::is_automatic_data_detection_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) isAutomaticDataDetectionEnabled]);
    }

    void TextView::set_automatic_data_detection_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setAutomaticDataDetectionEnabled:static_cast<::BOOL>(value)];
    }

    bool TextView::is_automatic_link_detection_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) isAutomaticLinkDetectionEnabled]);
    }

    void TextView::set_automatic_link_detection_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setAutomaticLinkDetectionEnabled:static_cast<::BOOL>(value)];
    }

    bool TextView::is_automatic_quote_substitution_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) isAutomaticQuoteSubstitutionEnabled]);
    }

    void TextView::set_automatic_quote_substitution_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setAutomaticQuoteSubstitutionEnabled:static_cast<::BOOL>(value)];
    }

    bool TextView::is_automatic_spelling_correction_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) isAutomaticSpellingCorrectionEnabled]);
    }

    void TextView::set_automatic_spelling_correction_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setAutomaticSpellingCorrectionEnabled:static_cast<::BOOL>(value)];
    }

    bool TextView::is_automatic_text_completion_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) isAutomaticTextCompletionEnabled]);
    }

    void TextView::set_automatic_text_completion_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setAutomaticTextCompletionEnabled:static_cast<::BOOL>(value)];
    }

    bool TextView::is_automatic_text_replacement_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) isAutomaticTextReplacementEnabled]);
    }

    void TextView::set_automatic_text_replacement_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setAutomaticTextReplacementEnabled:static_cast<::BOOL>(value)];
    }

    Color TextView::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSTextView>(this) backgroundColor]);
    }

    void TextView::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    CandidateListTouchBarItemBase TextView::candidate_list_touch_bar_item() const
    {
        return cocoon::internal::wrap<CandidateListTouchBarItemBase>([cocoon::internal::ns<::NSTextView>(this) candidateListTouchBarItem]);
    }

    bool TextView::is_coalescing_undo() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) isCoalescingUndo]);
    }

    bool TextView::is_continuous_spell_checking_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) isContinuousSpellCheckingEnabled]);
    }

    void TextView::set_continuous_spell_checking_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setContinuousSpellCheckingEnabled:static_cast<::BOOL>(value)];
    }

    ParagraphStyle TextView::default_paragraph_style() const
    {
        return cocoon::internal::wrap<ParagraphStyle>([cocoon::internal::ns<::NSTextView>(this) defaultParagraphStyle]);
    }

    void TextView::set_default_paragraph_style(const ParagraphStyle& value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setDefaultParagraphStyle:cocoon::internal::native<::NSParagraphStyle>(value)];
    }

    bool TextView::displays_link_tool_tips() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) displaysLinkToolTips]);
    }

    void TextView::set_displays_link_tool_tips(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setDisplaysLinkToolTips:static_cast<::BOOL>(value)];
    }

    bool TextView::draws_background() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) drawsBackground]);
    }

    void TextView::set_draws_background(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setDrawsBackground:static_cast<::BOOL>(value)];
    }

    bool TextView::is_editable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) isEditable]);
    }

    void TextView::set_editable(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setEditable:static_cast<::BOOL>(value)];
    }

    std::uint64_t TextView::enabled_text_checking_types() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSTextView>(this) enabledTextCheckingTypes]);
    }

    void TextView::set_enabled_text_checking_types(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setEnabledTextCheckingTypes:static_cast<::NSTextCheckingTypes>(value)];
    }

    bool TextView::is_field_editor() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) isFieldEditor]);
    }

    void TextView::set_field_editor(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setFieldEditor:static_cast<::BOOL>(value)];
    }

    bool TextView::is_grammar_checking_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) isGrammarCheckingEnabled]);
    }

    void TextView::set_grammar_checking_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setGrammarCheckingEnabled:static_cast<::BOOL>(value)];
    }

    bool TextView::imports_graphics() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) importsGraphics]);
    }

    void TextView::set_imports_graphics(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setImportsGraphics:static_cast<::BOOL>(value)];
    }

    bool TextView::is_incremental_searching_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) isIncrementalSearchingEnabled]);
    }

    void TextView::set_incremental_searching_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setIncrementalSearchingEnabled:static_cast<::BOOL>(value)];
    }

    TextInputTraitType TextView::inline_prediction_type() const
    {
        return static_cast<TextInputTraitType>([cocoon::internal::ns<::NSTextView>(this) inlinePredictionType]);
    }

    void TextView::set_inline_prediction_type(TextInputTraitType value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setInlinePredictionType:static_cast<::NSTextInputTraitType>(value)];
    }

    Color TextView::insertion_point_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSTextView>(this) insertionPointColor]);
    }

    void TextView::set_insertion_point_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setInsertionPointColor:cocoon::internal::native<::NSColor>(value)];
    }

    LayoutManager TextView::layout_manager() const
    {
        return cocoon::internal::wrap<LayoutManager>([cocoon::internal::ns<::NSTextView>(this) layoutManager]);
    }

    std::map<std::string, Object> TextView::link_text_attributes() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSTextView>(this) linkTextAttributes], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    void TextView::set_link_text_attributes(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setLinkTextAttributes:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                                        {
                                                                                                            return cocoon::internal::to(k);
                                                                                                        },
                                                                                                        [](const Object& v) -> id
                                                                                                        {
                                                                                                            return cocoon::internal::native_id(v);
                                                                                                        })];
    }

    std::map<std::string, Object> TextView::marked_text_attributes() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSTextView>(this) markedTextAttributes], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    void TextView::set_marked_text_attributes(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setMarkedTextAttributes:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                                          {
                                                                                                              return cocoon::internal::to(k);
                                                                                                          },
                                                                                                          [](const Object& v) -> id
                                                                                                          {
                                                                                                              return cocoon::internal::native_id(v);
                                                                                                          })];
    }

    TextInputTraitType TextView::math_expression_completion_type() const
    {
        return static_cast<TextInputTraitType>([cocoon::internal::ns<::NSTextView>(this) mathExpressionCompletionType]);
    }

    void TextView::set_math_expression_completion_type(TextInputTraitType value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setMathExpressionCompletionType:static_cast<::NSTextInputTraitType>(value)];
    }

    Range TextView::range_for_user_character_attribute_change() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextView>(this) rangeForUserCharacterAttributeChange]);
    }

    Range TextView::range_for_user_completion() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextView>(this) rangeForUserCompletion]);
    }

    Range TextView::range_for_user_paragraph_attribute_change() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextView>(this) rangeForUserParagraphAttributeChange]);
    }

    Range TextView::range_for_user_text_change() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextView>(this) rangeForUserTextChange]);
    }

    std::vector<Value> TextView::ranges_for_user_character_attribute_change() const
    {
        return cocoon::internal::from_array<Value>([cocoon::internal::ns<::NSTextView>(this) rangesForUserCharacterAttributeChange], [](id e) -> Value
                                                   {
                                                       return cocoon::internal::wrap<Value>((::NSValue*)e);
                                                   });
    }

    std::vector<Value> TextView::ranges_for_user_paragraph_attribute_change() const
    {
        return cocoon::internal::from_array<Value>([cocoon::internal::ns<::NSTextView>(this) rangesForUserParagraphAttributeChange], [](id e) -> Value
                                                   {
                                                       return cocoon::internal::wrap<Value>((::NSValue*)e);
                                                   });
    }

    std::vector<Value> TextView::ranges_for_user_text_change() const
    {
        return cocoon::internal::from_array<Value>([cocoon::internal::ns<::NSTextView>(this) rangesForUserTextChange], [](id e) -> Value
                                                   {
                                                       return cocoon::internal::wrap<Value>((::NSValue*)e);
                                                   });
    }

    std::vector<std::string> TextView::readable_pasteboard_types() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTextView>(this) readablePasteboardTypes], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    bool TextView::is_rich_text() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) isRichText]);
    }

    void TextView::set_rich_text(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setRichText:static_cast<::BOOL>(value)];
    }

    bool TextView::is_ruler_visible() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) isRulerVisible]);
    }

    void TextView::set_ruler_visible(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setRulerVisible:static_cast<::BOOL>(value)];
    }

    bool TextView::is_selectable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) isSelectable]);
    }

    void TextView::set_selectable(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setSelectable:static_cast<::BOOL>(value)];
    }

    std::vector<Value> TextView::selected_ranges() const
    {
        return cocoon::internal::from_array<Value>([cocoon::internal::ns<::NSTextView>(this) selectedRanges], [](id e) -> Value
                                                   {
                                                       return cocoon::internal::wrap<Value>((::NSValue*)e);
                                                   });
    }

    void TextView::set_selected_ranges(const std::vector<Value>& value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setSelectedRanges:cocoon::internal::to_array(value, [](const Value& e) -> id
                                                                                               {
                                                                                                   return cocoon::internal::native<::NSValue>(e);
                                                                                               })];
    }

    std::map<std::string, Object> TextView::selected_text_attributes() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSTextView>(this) selectedTextAttributes], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    void TextView::set_selected_text_attributes(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setSelectedTextAttributes:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                                            {
                                                                                                                return cocoon::internal::to(k);
                                                                                                            },
                                                                                                            [](const Object& v) -> id
                                                                                                            {
                                                                                                                return cocoon::internal::native_id(v);
                                                                                                            })];
    }

    SelectionAffinity TextView::selection_affinity() const
    {
        return static_cast<SelectionAffinity>([cocoon::internal::ns<::NSTextView>(this) selectionAffinity]);
    }

    SelectionGranularity TextView::selection_granularity() const
    {
        return static_cast<SelectionGranularity>([cocoon::internal::ns<::NSTextView>(this) selectionGranularity]);
    }

    void TextView::set_selection_granularity(SelectionGranularity value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setSelectionGranularity:static_cast<::NSSelectionGranularity>(value)];
    }

    bool TextView::should_draw_insertion_point() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) shouldDrawInsertionPoint]);
    }

    bool TextView::smart_insert_delete_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) smartInsertDeleteEnabled]);
    }

    void TextView::set_smart_insert_delete_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setSmartInsertDeleteEnabled:static_cast<::BOOL>(value)];
    }

    std::int64_t TextView::spell_checker_document_tag() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTextView>(this) spellCheckerDocumentTag]);
    }

    bool TextView::strongly_references_text_storage()
    {
        return static_cast<bool>([::NSTextView stronglyReferencesTextStorage]);
    }

    TextContainer TextView::text_container() const
    {
        return cocoon::internal::wrap<TextContainer>([cocoon::internal::ns<::NSTextView>(this) textContainer]);
    }

    void TextView::set_text_container(const TextContainer& value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setTextContainer:cocoon::internal::native<::NSTextContainer>(value)];
    }

    Size TextView::text_container_inset() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextView>(this) textContainerInset]);
    }

    void TextView::set_text_container_inset(const Size& value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setTextContainerInset:cocoon::internal::to(value)];
    }

    Point TextView::text_container_origin() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextView>(this) textContainerOrigin]);
    }

    TextContentStorage TextView::text_content_storage() const
    {
        return cocoon::internal::wrap<TextContentStorage>([cocoon::internal::ns<::NSTextView>(this) textContentStorage]);
    }

    std::map<std::string, Object> TextView::text_highlight_attributes() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSTextView>(this) textHighlightAttributes], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    void TextView::set_text_highlight_attributes(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setTextHighlightAttributes:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                                             {
                                                                                                                 return cocoon::internal::to(k);
                                                                                                             },
                                                                                                             [](const Object& v) -> id
                                                                                                             {
                                                                                                                 return cocoon::internal::native_id(v);
                                                                                                             })];
    }

    TextLayoutManager TextView::text_layout_manager() const
    {
        return cocoon::internal::wrap<TextLayoutManager>([cocoon::internal::ns<::NSTextView>(this) textLayoutManager]);
    }

    TextStorage TextView::text_storage() const
    {
        return cocoon::internal::wrap<TextStorage>([cocoon::internal::ns<::NSTextView>(this) textStorage]);
    }

    std::map<std::string, Object> TextView::typing_attributes() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSTextView>(this) typingAttributes], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    void TextView::set_typing_attributes(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setTypingAttributes:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                                      {
                                                                                                          return cocoon::internal::to(k);
                                                                                                      },
                                                                                                      [](const Object& v) -> id
                                                                                                      {
                                                                                                          return cocoon::internal::native_id(v);
                                                                                                      })];
    }

    bool TextView::uses_adaptive_color_mapping_for_dark_appearance() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) usesAdaptiveColorMappingForDarkAppearance]);
    }

    void TextView::set_uses_adaptive_color_mapping_for_dark_appearance(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setUsesAdaptiveColorMappingForDarkAppearance:static_cast<::BOOL>(value)];
    }

    bool TextView::uses_find_bar() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) usesFindBar]);
    }

    void TextView::set_uses_find_bar(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setUsesFindBar:static_cast<::BOOL>(value)];
    }

    bool TextView::uses_find_panel() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) usesFindPanel]);
    }

    void TextView::set_uses_find_panel(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setUsesFindPanel:static_cast<::BOOL>(value)];
    }

    bool TextView::uses_font_panel() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) usesFontPanel]);
    }

    void TextView::set_uses_font_panel(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setUsesFontPanel:static_cast<::BOOL>(value)];
    }

    bool TextView::uses_inspector_bar() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) usesInspectorBar]);
    }

    void TextView::set_uses_inspector_bar(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setUsesInspectorBar:static_cast<::BOOL>(value)];
    }

    bool TextView::uses_rollover_button_for_selection() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) usesRolloverButtonForSelection]);
    }

    void TextView::set_uses_rollover_button_for_selection(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setUsesRolloverButtonForSelection:static_cast<::BOOL>(value)];
    }

    bool TextView::uses_ruler() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) usesRuler]);
    }

    void TextView::set_uses_ruler(bool value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setUsesRuler:static_cast<::BOOL>(value)];
    }

    std::vector<std::string> TextView::writable_pasteboard_types() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTextView>(this) writablePasteboardTypes], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    bool TextView::is_writing_tools_active() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextView>(this) isWritingToolsActive]);
    }

    WritingToolsBehavior TextView::writing_tools_behavior() const
    {
        return static_cast<WritingToolsBehavior>([cocoon::internal::ns<::NSTextView>(this) writingToolsBehavior]);
    }

    void TextView::set_writing_tools_behavior(WritingToolsBehavior value) const
    {
        [cocoon::internal::ns<::NSTextView>(this) setWritingToolsBehavior:static_cast<::NSWritingToolsBehavior>(value)];
    }

    void TextView::install_delegate_delegate_(void* native)
    {
        ::NSTextView* host = (__bridge ::NSTextView*)native;
        AKTextViewDelegate* delegate = [[AKTextViewDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSTextView* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSTextView* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
