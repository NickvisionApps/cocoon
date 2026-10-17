#include "generated/token_field_cell.h"
#include "internal.h"

@interface AKTokenFieldCellDelegate : NSObject <NSTokenFieldCellDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKTokenFieldCellDelegate

- (NSArray*)tokenFieldCell:(NSTokenFieldCell*)tokenFieldCell completionsForSubstring:(NSString*)substring indexOfToken:(NSInteger)tokenIndex indexOfSelectedItem:(NSInteger*)selectedIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenFieldCell, std::vector<cocoon::Object>(std::string, std::int64_t, std::int64_t*)>::emit((__bridge void*)strongHost, "completions_for_substring_index_of_token_index_of_selected_item", cocoon::internal::from(substring), static_cast<std::int64_t>(tokenIndex), (std::int64_t*)(selectedIndex));
    return cocoon::internal::to_array(__r, [](const cocoon::Object& e) -> id
                                      {
                                          return cocoon::internal::native_id(e);
                                      });
}

- (NSArray*)tokenFieldCell:(NSTokenFieldCell*)tokenFieldCell shouldAddObjects:(NSArray*)tokens atIndex:(NSUInteger)index
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenFieldCell, std::vector<cocoon::Object>(std::vector<cocoon::Object>, std::uint64_t)>::emit((__bridge void*)strongHost, "should_add_objects_at_index", cocoon::internal::from_array<cocoon::Object>(tokens, [](id e) -> cocoon::Object
                                                                                                                                                                                                                                             {
                                                                                                                                                                                                                                                 return cocoon::internal::wrap<cocoon::Object>(e);
                                                                                                                                                                                                                                             }),
                                                                                                                                     static_cast<std::uint64_t>(index));
    return cocoon::internal::to_array(__r, [](const cocoon::Object& e) -> id
                                      {
                                          return cocoon::internal::native_id(e);
                                      });
}

- (NSString*)tokenFieldCell:(NSTokenFieldCell*)tokenFieldCell displayStringForRepresentedObject:(id)representedObject
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenFieldCell, std::string(cocoon::Object)>::emit((__bridge void*)strongHost, "display_string_for_represented_object", cocoon::internal::wrap<cocoon::Object>(representedObject));
    return cocoon::internal::to(__r);
}

- (NSString*)tokenFieldCell:(NSTokenFieldCell*)tokenFieldCell editingStringForRepresentedObject:(id)representedObject
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenFieldCell, std::string(cocoon::Object)>::emit((__bridge void*)strongHost, "editing_string_for_represented_object", cocoon::internal::wrap<cocoon::Object>(representedObject));
    return cocoon::internal::to(__r);
}

- (id)tokenFieldCell:(NSTokenFieldCell*)tokenFieldCell representedObjectForEditingString:(NSString*)editingString
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenFieldCell, cocoon::Object(std::string)>::emit((__bridge void*)strongHost, "represented_object_for_editing_string", cocoon::internal::from(editingString));
    return cocoon::internal::native_id(__r);
}

- (BOOL)tokenFieldCell:(NSTokenFieldCell*)tokenFieldCell writeRepresentedObjects:(NSArray*)objects toPasteboard:(NSPasteboard*)pboard
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenFieldCell, bool(std::vector<cocoon::Object>, cocoon::Pasteboard)>::emit((__bridge void*)strongHost, "write_represented_objects_to_pasteboard", cocoon::internal::from_array<cocoon::Object>(objects, [](id e) -> cocoon::Object
                                                                                                                                                                                                                                       {
                                                                                                                                                                                                                                           return cocoon::internal::wrap<cocoon::Object>(e);
                                                                                                                                                                                                                                       }),
                                                                                                                   cocoon::internal::wrap<cocoon::Pasteboard>(pboard));
    return static_cast<::BOOL>(__r);
}

- (NSArray*)tokenFieldCell:(NSTokenFieldCell*)tokenFieldCell readFromPasteboard:(NSPasteboard*)pboard
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenFieldCell, std::vector<cocoon::Object>(cocoon::Pasteboard)>::emit((__bridge void*)strongHost, "read_from_pasteboard", cocoon::internal::wrap<cocoon::Pasteboard>(pboard));
    return cocoon::internal::to_array(__r, [](const cocoon::Object& e) -> id
                                      {
                                          return cocoon::internal::native_id(e);
                                      });
}

- (NSMenu*)tokenFieldCell:(NSTokenFieldCell*)tokenFieldCell menuForRepresentedObject:(id)representedObject
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenFieldCell, cocoon::Menu(cocoon::Object)>::emit((__bridge void*)strongHost, "menu_for_represented_object", cocoon::internal::wrap<cocoon::Object>(representedObject));
    return cocoon::internal::native<::NSMenu>(__r);
}

- (BOOL)tokenFieldCell:(NSTokenFieldCell*)tokenFieldCell hasMenuForRepresentedObject:(id)representedObject
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenFieldCell, bool(cocoon::Object)>::emit((__bridge void*)strongHost, "has_menu_for_represented_object", cocoon::internal::wrap<cocoon::Object>(representedObject));
    return static_cast<::BOOL>(__r);
}

- (NSTokenStyle)tokenFieldCell:(NSTokenFieldCell*)tokenFieldCell styleForRepresentedObject:(id)representedObject
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TokenFieldCell, cocoon::TokenStyle(cocoon::Object)>::emit((__bridge void*)strongHost, "style_for_represented_object", cocoon::internal::wrap<cocoon::Object>(representedObject));
    return static_cast<::NSTokenStyle>(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(tokenFieldCell:completionsForSubstring:indexOfToken:indexOfSelectedItem:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenFieldCell, std::vector<cocoon::Object>(std::string, std::int64_t, std::int64_t*)>::connected((__bridge void*)strongHost, "completions_for_substring_index_of_token_index_of_selected_item");
    }
    if (selector == @selector(tokenFieldCell:shouldAddObjects:atIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenFieldCell, std::vector<cocoon::Object>(std::vector<cocoon::Object>, std::uint64_t)>::connected((__bridge void*)strongHost, "should_add_objects_at_index");
    }
    if (selector == @selector(tokenFieldCell:displayStringForRepresentedObject:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenFieldCell, std::string(cocoon::Object)>::connected((__bridge void*)strongHost, "display_string_for_represented_object");
    }
    if (selector == @selector(tokenFieldCell:editingStringForRepresentedObject:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenFieldCell, std::string(cocoon::Object)>::connected((__bridge void*)strongHost, "editing_string_for_represented_object");
    }
    if (selector == @selector(tokenFieldCell:representedObjectForEditingString:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenFieldCell, cocoon::Object(std::string)>::connected((__bridge void*)strongHost, "represented_object_for_editing_string");
    }
    if (selector == @selector(tokenFieldCell:writeRepresentedObjects:toPasteboard:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenFieldCell, bool(std::vector<cocoon::Object>, cocoon::Pasteboard)>::connected((__bridge void*)strongHost, "write_represented_objects_to_pasteboard");
    }
    if (selector == @selector(tokenFieldCell:readFromPasteboard:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenFieldCell, std::vector<cocoon::Object>(cocoon::Pasteboard)>::connected((__bridge void*)strongHost, "read_from_pasteboard");
    }
    if (selector == @selector(tokenFieldCell:menuForRepresentedObject:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenFieldCell, cocoon::Menu(cocoon::Object)>::connected((__bridge void*)strongHost, "menu_for_represented_object");
    }
    if (selector == @selector(tokenFieldCell:hasMenuForRepresentedObject:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenFieldCell, bool(cocoon::Object)>::connected((__bridge void*)strongHost, "has_menu_for_represented_object");
    }
    if (selector == @selector(tokenFieldCell:styleForRepresentedObject:))
    {
        return strongHost && cocoon::Signal<cocoon::TokenFieldCell, cocoon::TokenStyle(cocoon::Object)>::connected((__bridge void*)strongHost, "style_for_represented_object");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    TokenFieldCell::TokenFieldCell() : TokenFieldCell(Adopt{cocoon::internal::retain([[::NSTokenFieldCell alloc] init])})
    {
        TokenFieldCell::install_delegate_delegate_(handle());
    }

    TokenFieldCell::TokenFieldCell(std::nullptr_t) : TextFieldCell(nullptr)
    {
    }

    TokenFieldCell::TokenFieldCell(Adopt adopt) : TextFieldCell(adopt)
    {
    }

    double TokenFieldCell::completion_delay() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTokenFieldCell>(this) completionDelay]);
    }

    void TokenFieldCell::set_completion_delay(double value) const
    {
        [cocoon::internal::ns<::NSTokenFieldCell>(this) setCompletionDelay:static_cast<::NSTimeInterval>(value)];
    }

    double TokenFieldCell::default_completion_delay()
    {
        return static_cast<double>([::NSTokenFieldCell defaultCompletionDelay]);
    }

    CharacterSet TokenFieldCell::default_tokenizing_character_set()
    {
        return cocoon::internal::wrap<CharacterSet>([::NSTokenFieldCell defaultTokenizingCharacterSet]);
    }

    TokenStyle TokenFieldCell::token_style() const
    {
        return static_cast<TokenStyle>([cocoon::internal::ns<::NSTokenFieldCell>(this) tokenStyle]);
    }

    void TokenFieldCell::set_token_style(TokenStyle value) const
    {
        [cocoon::internal::ns<::NSTokenFieldCell>(this) setTokenStyle:static_cast<::NSTokenStyle>(value)];
    }

    CharacterSet TokenFieldCell::tokenizing_character_set() const
    {
        return cocoon::internal::wrap<CharacterSet>([cocoon::internal::ns<::NSTokenFieldCell>(this) tokenizingCharacterSet]);
    }

    void TokenFieldCell::set_tokenizing_character_set(const CharacterSet& value) const
    {
        [cocoon::internal::ns<::NSTokenFieldCell>(this) setTokenizingCharacterSet:cocoon::internal::native<::NSCharacterSet>(value)];
    }

    void TokenFieldCell::install_delegate_delegate_(void* native)
    {
        ::NSTokenFieldCell* host = (__bridge ::NSTokenFieldCell*)native;
        AKTokenFieldCellDelegate* delegate = [[AKTokenFieldCellDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSTokenFieldCell* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSTokenFieldCell* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
