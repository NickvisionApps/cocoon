#include "generated/text_storage.h"
#include "internal.h"

@interface AKTextStorageDelegate : NSObject <NSTextStorageDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKTextStorageDelegate

- (void)textStorage:(NSTextStorage*)textStorage willProcessEditing:(NSTextStorageEditActions)editedMask range:(NSRange)editedRange changeInLength:(NSInteger)delta
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextStorage, void(cocoon::TextStorageEditActions, cocoon::Range, std::int64_t)>::emit((__bridge void*)strongHost, "will_process_editing_range_change_in_length", static_cast<cocoon::TextStorageEditActions>(editedMask), cocoon::internal::from(editedRange), static_cast<std::int64_t>(delta));
}

- (void)textStorage:(NSTextStorage*)textStorage didProcessEditing:(NSTextStorageEditActions)editedMask range:(NSRange)editedRange changeInLength:(NSInteger)delta
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextStorage, void(cocoon::TextStorageEditActions, cocoon::Range, std::int64_t)>::emit((__bridge void*)strongHost, "did_process_editing_range_change_in_length", static_cast<cocoon::TextStorageEditActions>(editedMask), cocoon::internal::from(editedRange), static_cast<std::int64_t>(delta));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(textStorage:willProcessEditing:range:changeInLength:))
    {
        return strongHost && cocoon::Signal<cocoon::TextStorage, void(cocoon::TextStorageEditActions, cocoon::Range, std::int64_t)>::connected((__bridge void*)strongHost, "will_process_editing_range_change_in_length");
    }
    if (selector == @selector(textStorage:didProcessEditing:range:changeInLength:))
    {
        return strongHost && cocoon::Signal<cocoon::TextStorage, void(cocoon::TextStorageEditActions, cocoon::Range, std::int64_t)>::connected((__bridge void*)strongHost, "did_process_editing_range_change_in_length");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    TextStorage::TextStorage() : TextStorage(Adopt{cocoon::internal::retain([[::NSTextStorage alloc] init])})
    {
        TextStorage::install_delegate_delegate_(handle());
    }

    TextStorage::TextStorage(std::nullptr_t) : MutableAttributedString(nullptr)
    {
    }

    TextStorage::TextStorage(Adopt adopt) : MutableAttributedString(adopt)
    {
    }

    void TextStorage::add_layout_manager(const LayoutManager& a_layout_manager) const
    {
        [cocoon::internal::ns<::NSTextStorage>(this) addLayoutManager:cocoon::internal::native<::NSLayoutManager>(a_layout_manager)];
    }

    void TextStorage::edited(TextStorageEditActions edited_mask, const Range& edited_range, std::int64_t delta) const
    {
        [cocoon::internal::ns<::NSTextStorage>(this) edited:static_cast<::NSTextStorageEditActions>(edited_mask) range:cocoon::internal::to(edited_range) changeInLength:static_cast<::NSInteger>(delta)];
    }

    void TextStorage::ensure_attributes_are_fixed_in_range(const Range& range) const
    {
        [cocoon::internal::ns<::NSTextStorage>(this) ensureAttributesAreFixedInRange:cocoon::internal::to(range)];
    }

    void TextStorage::invalidate_attributes_in_range(const Range& range) const
    {
        [cocoon::internal::ns<::NSTextStorage>(this) invalidateAttributesInRange:cocoon::internal::to(range)];
    }

    void TextStorage::process_editing() const
    {
        [cocoon::internal::ns<::NSTextStorage>(this) processEditing];
    }

    void TextStorage::remove_layout_manager(const LayoutManager& a_layout_manager) const
    {
        [cocoon::internal::ns<::NSTextStorage>(this) removeLayoutManager:cocoon::internal::native<::NSLayoutManager>(a_layout_manager)];
    }

    std::vector<TextStorage> TextStorage::attribute_runs() const
    {
        return cocoon::internal::from_array<TextStorage>([cocoon::internal::ns<::NSTextStorage>(this) attributeRuns], [](id e) -> TextStorage
                                           {
                                               return cocoon::internal::wrap<TextStorage>((::NSTextStorage*)e);
                                           });
    }

    void TextStorage::set_attribute_runs(const std::vector<TextStorage>& value) const
    {
        [cocoon::internal::ns<::NSTextStorage>(this) setAttributeRuns:cocoon::internal::to_array(value, [](const TextStorage& e) -> id
                                                                     {
                                                                         return cocoon::internal::native<::NSTextStorage>(e);
                                                                     })];
    }

    std::int64_t TextStorage::change_in_length() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTextStorage>(this) changeInLength]);
    }

    std::vector<TextStorage> TextStorage::characters() const
    {
        return cocoon::internal::from_array<TextStorage>([cocoon::internal::ns<::NSTextStorage>(this) characters], [](id e) -> TextStorage
                                           {
                                               return cocoon::internal::wrap<TextStorage>((::NSTextStorage*)e);
                                           });
    }

    void TextStorage::set_characters(const std::vector<TextStorage>& value) const
    {
        [cocoon::internal::ns<::NSTextStorage>(this) setCharacters:cocoon::internal::to_array(value, [](const TextStorage& e) -> id
                                                                  {
                                                                      return cocoon::internal::native<::NSTextStorage>(e);
                                                                  })];
    }

    TextStorageEditActions TextStorage::edited_mask() const
    {
        return static_cast<TextStorageEditActions>([cocoon::internal::ns<::NSTextStorage>(this) editedMask]);
    }

    Range TextStorage::edited_range() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextStorage>(this) editedRange]);
    }

    bool TextStorage::fixes_attributes_lazily() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextStorage>(this) fixesAttributesLazily]);
    }

    Font TextStorage::font() const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSTextStorage>(this) font]);
    }

    void TextStorage::set_font(const Font& value) const
    {
        [cocoon::internal::ns<::NSTextStorage>(this) setFont:cocoon::internal::native<::NSFont>(value)];
    }

    Color TextStorage::foreground_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSTextStorage>(this) foregroundColor]);
    }

    void TextStorage::set_foreground_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSTextStorage>(this) setForegroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    std::vector<LayoutManager> TextStorage::layout_managers() const
    {
        return cocoon::internal::from_array<LayoutManager>([cocoon::internal::ns<::NSTextStorage>(this) layoutManagers], [](id e) -> LayoutManager
                                             {
                                                 return cocoon::internal::wrap<LayoutManager>((::NSLayoutManager*)e);
                                             });
    }

    std::vector<TextStorage> TextStorage::paragraphs() const
    {
        return cocoon::internal::from_array<TextStorage>([cocoon::internal::ns<::NSTextStorage>(this) paragraphs], [](id e) -> TextStorage
                                           {
                                               return cocoon::internal::wrap<TextStorage>((::NSTextStorage*)e);
                                           });
    }

    void TextStorage::set_paragraphs(const std::vector<TextStorage>& value) const
    {
        [cocoon::internal::ns<::NSTextStorage>(this) setParagraphs:cocoon::internal::to_array(value, [](const TextStorage& e) -> id
                                                                  {
                                                                      return cocoon::internal::native<::NSTextStorage>(e);
                                                                  })];
    }

    Object TextStorage::text_storage_observer() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTextStorage>(this) textStorageObserver]);
    }

    void TextStorage::set_text_storage_observer(const Object& value) const
    {
        [cocoon::internal::ns<::NSTextStorage>(this) setTextStorageObserver:cocoon::internal::native_id(value)];
    }

    std::vector<TextStorage> TextStorage::words() const
    {
        return cocoon::internal::from_array<TextStorage>([cocoon::internal::ns<::NSTextStorage>(this) words], [](id e) -> TextStorage
                                           {
                                               return cocoon::internal::wrap<TextStorage>((::NSTextStorage*)e);
                                           });
    }

    void TextStorage::set_words(const std::vector<TextStorage>& value) const
    {
        [cocoon::internal::ns<::NSTextStorage>(this) setWords:cocoon::internal::to_array(value, [](const TextStorage& e) -> id
                                                             {
                                                                 return cocoon::internal::native<::NSTextStorage>(e);
                                                             })];
    }

    void TextStorage::install_delegate_delegate_(void* native)
    {
        ::NSTextStorage* host = (__bridge ::NSTextStorage*)native;
        AKTextStorageDelegate* delegate = [[AKTextStorageDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSTextStorage* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSTextStorage* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
