#include "generated/text_content_storage.h"
#include "internal.h"

@interface AKTextContentStorageDelegate : NSObject <NSTextContentStorageDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKTextContentStorageDelegate

- (NSTextParagraph*)textContentStorage:(NSTextContentStorage*)textContentStorage textParagraphWithRange:(NSRange)range
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextContentStorage, cocoon::TextParagraph(cocoon::Range)>::emit((__bridge void*)strongHost, "text_paragraph_with_range", cocoon::internal::from(range));
    return cocoon::internal::native<::NSTextParagraph>(__r);
}

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
    if (selector == @selector(textContentStorage:textParagraphWithRange:))
    {
        return strongHost && cocoon::Signal<cocoon::TextContentStorage, cocoon::TextParagraph(cocoon::Range)>::connected((__bridge void*)strongHost, "text_paragraph_with_range");
    }
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
    TextContentStorage::TextContentStorage() : TextContentStorage(Adopt{cocoon::internal::retain([[::NSTextContentStorage alloc] init])})
    {
        TextContentStorage::install_delegate_delegate_(handle());
    }

    TextContentStorage::TextContentStorage(std::nullptr_t) : TextContentManager(nullptr)
    {
    }

    TextContentStorage::TextContentStorage(Adopt adopt) : TextContentManager(adopt)
    {
    }

    TextRange TextContentStorage::adjusted_range_from_range(const TextRange& text_range, bool for_editing_text_selection) const
    {
        return cocoon::internal::wrap<TextRange>([cocoon::internal::ns<::NSTextContentStorage>(this) adjustedRangeFromRange:cocoon::internal::native<::NSTextRange>(text_range) forEditingTextSelection:static_cast<::BOOL>(for_editing_text_selection)]);
    }

    AttributedString TextContentStorage::attributed_string_for_text_element(const TextElement& text_element) const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSTextContentStorage>(this) attributedStringForTextElement:cocoon::internal::native<::NSTextElement>(text_element)]);
    }

    Object TextContentStorage::location_from_location(const Object& location, std::int64_t offset) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTextContentStorage>(this) locationFromLocation:cocoon::internal::native_id(location) withOffset:static_cast<::NSInteger>(offset)]);
    }

    std::int64_t TextContentStorage::offset_from_location(const Object& from, const Object& to) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTextContentStorage>(this) offsetFromLocation:cocoon::internal::native_id(from) toLocation:cocoon::internal::native_id(to)]);
    }

    TextElement TextContentStorage::text_element_for_attributed_string(const AttributedString& attributed_string) const
    {
        return cocoon::internal::wrap<TextElement>([cocoon::internal::ns<::NSTextContentStorage>(this) textElementForAttributedString:cocoon::internal::native<::NSAttributedString>(attributed_string)]);
    }

    AttributedString TextContentStorage::attributed_string() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSTextContentStorage>(this) attributedString]);
    }

    void TextContentStorage::set_attributed_string(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSTextContentStorage>(this) setAttributedString:cocoon::internal::native<::NSAttributedString>(value)];
    }

    bool TextContentStorage::includes_text_list_markers() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextContentStorage>(this) includesTextListMarkers]);
    }

    void TextContentStorage::set_includes_text_list_markers(bool value) const
    {
        [cocoon::internal::ns<::NSTextContentStorage>(this) setIncludesTextListMarkers:static_cast<::BOOL>(value)];
    }

    void TextContentStorage::install_delegate_delegate_(void* native)
    {
        ::NSTextContentStorage* host = (__bridge ::NSTextContentStorage*)native;
        AKTextContentStorageDelegate* delegate = [[AKTextContentStorageDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSTextContentStorage* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSTextContentStorage* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
