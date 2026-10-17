#include "generated/text_content_manager.h"
#include "internal.h"

@interface AKTextContentManagerDelegate : NSObject <NSTextContentManagerDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKTextContentManagerDelegate

- (NSTextElement*)textContentManager:(NSTextContentManager*)textContentManager textElementAtLocation:(id<NSTextLocation>)location
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextContentManager, cocoon::TextElement(cocoon::Object)>::emit((__bridge void*)strongHost, "text_element_at_location", cocoon::internal::wrap<cocoon::Object>(location));
    return cocoon::internal::native<::NSTextElement>(__r);
}

- (BOOL)textContentManager:(NSTextContentManager*)textContentManager shouldEnumerateTextElement:(NSTextElement*)textElement options:(NSTextContentManagerEnumerationOptions)options
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextContentManager, bool(cocoon::TextElement, cocoon::TextContentManagerEnumerationOptions)>::emit((__bridge void*)strongHost, "should_enumerate_text_element_options", cocoon::internal::wrap<cocoon::TextElement>(textElement), static_cast<cocoon::TextContentManagerEnumerationOptions>(options));
    return static_cast<::BOOL>(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(textContentManager:textElementAtLocation:))
    {
        return strongHost && cocoon::Signal<cocoon::TextContentManager, cocoon::TextElement(cocoon::Object)>::connected((__bridge void*)strongHost, "text_element_at_location");
    }
    if (selector == @selector(textContentManager:shouldEnumerateTextElement:options:))
    {
        return strongHost && cocoon::Signal<cocoon::TextContentManager, bool(cocoon::TextElement, cocoon::TextContentManagerEnumerationOptions)>::connected((__bridge void*)strongHost, "should_enumerate_text_element_options");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    TextContentManager::TextContentManager() : TextContentManager(Adopt{cocoon::internal::retain([[::NSTextContentManager alloc] init])})
    {
        TextContentManager::install_delegate_delegate_(handle());
    }

    TextContentManager::TextContentManager(std::nullptr_t) : Object(nullptr)
    {
    }

    TextContentManager::TextContentManager(Adopt adopt) : Object(adopt)
    {
    }

    void TextContentManager::add_text_layout_manager(const TextLayoutManager& text_layout_manager) const
    {
        [cocoon::internal::ns<::NSTextContentManager>(this) addTextLayoutManager:cocoon::internal::native<::NSTextLayoutManager>(text_layout_manager)];
    }

    void TextContentManager::perform_editing_transaction_using_block(std::function<void()> transaction) const
    {
        [cocoon::internal::ns<::NSTextContentManager>(this) performEditingTransactionUsingBlock:(transaction ? (void (^)(void)) ^ void() { transaction(); } : (void (^)(void))nil)];
    }

    void TextContentManager::record_edit_action_in_range(const TextRange& original_text_range, const TextRange& new_text_range) const
    {
        [cocoon::internal::ns<::NSTextContentManager>(this) recordEditActionInRange:cocoon::internal::native<::NSTextRange>(original_text_range) newTextRange:cocoon::internal::native<::NSTextRange>(new_text_range)];
    }

    void TextContentManager::remove_text_layout_manager(const TextLayoutManager& text_layout_manager) const
    {
        [cocoon::internal::ns<::NSTextContentManager>(this) removeTextLayoutManager:cocoon::internal::native<::NSTextLayoutManager>(text_layout_manager)];
    }

    void TextContentManager::synchronize_text_layout_managers(std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSTextContentManager>(this) synchronizeTextLayoutManagers:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a95_0) { completion_handler(cocoon::internal::wrap<Error>(a95_0)); } : (void (^)(::NSError*))nil)];
    }

    std::vector<TextElement> TextContentManager::text_elements_for_range(const TextRange& range) const
    {
        return cocoon::internal::from_array<TextElement>([cocoon::internal::ns<::NSTextContentManager>(this) textElementsForRange:cocoon::internal::native<::NSTextRange>(range)], [](id e) -> TextElement
                                           {
                                               return cocoon::internal::wrap<TextElement>((::NSTextElement*)e);
                                           });
    }

    bool TextContentManager::automatically_synchronizes_text_layout_managers() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextContentManager>(this) automaticallySynchronizesTextLayoutManagers]);
    }

    void TextContentManager::set_automatically_synchronizes_text_layout_managers(bool value) const
    {
        [cocoon::internal::ns<::NSTextContentManager>(this) setAutomaticallySynchronizesTextLayoutManagers:static_cast<::BOOL>(value)];
    }

    bool TextContentManager::automatically_synchronizes_to_backing_store() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextContentManager>(this) automaticallySynchronizesToBackingStore]);
    }

    void TextContentManager::set_automatically_synchronizes_to_backing_store(bool value) const
    {
        [cocoon::internal::ns<::NSTextContentManager>(this) setAutomaticallySynchronizesToBackingStore:static_cast<::BOOL>(value)];
    }

    bool TextContentManager::has_editing_transaction() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextContentManager>(this) hasEditingTransaction]);
    }

    TextLayoutManager TextContentManager::primary_text_layout_manager() const
    {
        return cocoon::internal::wrap<TextLayoutManager>([cocoon::internal::ns<::NSTextContentManager>(this) primaryTextLayoutManager]);
    }

    void TextContentManager::set_primary_text_layout_manager(const TextLayoutManager& value) const
    {
        [cocoon::internal::ns<::NSTextContentManager>(this) setPrimaryTextLayoutManager:cocoon::internal::native<::NSTextLayoutManager>(value)];
    }

    std::vector<TextLayoutManager> TextContentManager::text_layout_managers() const
    {
        return cocoon::internal::from_array<TextLayoutManager>([cocoon::internal::ns<::NSTextContentManager>(this) textLayoutManagers], [](id e) -> TextLayoutManager
                                                 {
                                                     return cocoon::internal::wrap<TextLayoutManager>((::NSTextLayoutManager*)e);
                                                 });
    }

    void TextContentManager::install_delegate_delegate_(void* native)
    {
        ::NSTextContentManager* host = (__bridge ::NSTextContentManager*)native;
        AKTextContentManagerDelegate* delegate = [[AKTextContentManagerDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSTextContentManager* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSTextContentManager* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
