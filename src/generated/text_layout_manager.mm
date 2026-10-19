#include "generated/text_layout_manager.h"
#include "internal.h"

@interface AKTextLayoutManagerDelegate : NSObject <NSTextLayoutManagerDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKTextLayoutManagerDelegate

- (NSTextLayoutFragment*)textLayoutManager:(NSTextLayoutManager*)textLayoutManager textLayoutFragmentForLocation:(id<NSTextLocation>)location inTextElement:(NSTextElement*)textElement
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextLayoutManager, cocoon::TextLayoutFragment(cocoon::Object, cocoon::TextElement)>::emit((__bridge void*)strongHost, "text_layout_fragment_for_location_in_text_element", cocoon::internal::wrap<cocoon::Object>(location), cocoon::internal::wrap<cocoon::TextElement>(textElement));
    return cocoon::internal::native<::NSTextLayoutFragment>(__r);
}

- (BOOL)textLayoutManager:(NSTextLayoutManager*)textLayoutManager shouldBreakLineBeforeLocation:(id<NSTextLocation>)location hyphenating:(BOOL)hyphenating
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextLayoutManager, bool(cocoon::Object, bool)>::emit((__bridge void*)strongHost, "should_break_line_before_location_hyphenating", cocoon::internal::wrap<cocoon::Object>(location), static_cast<bool>(hyphenating));
    return static_cast<::BOOL>(__r);
}

- (NSDictionary<NSAttributedStringKey, id>*)textLayoutManager:(NSTextLayoutManager*)textLayoutManager renderingAttributesForLink:(id)link atLocation:(id<NSTextLocation>)location defaultAttributes:(NSDictionary<NSAttributedStringKey, id>*)renderingAttributes
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextLayoutManager, std::map<std::string, cocoon::Object>(cocoon::Object, cocoon::Object, std::map<std::string, cocoon::Object>)>::emit((__bridge void*)strongHost, "rendering_attributes_for_link_at_location_default_attributes", cocoon::internal::wrap<cocoon::Object>(link), cocoon::internal::wrap<cocoon::Object>(location), cocoon::internal::from_dictionary<std::map<std::string, cocoon::Object>>(renderingAttributes, [](id k) -> std::string
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

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(textLayoutManager:textLayoutFragmentForLocation:inTextElement:))
    {
        return strongHost && cocoon::Signal<cocoon::TextLayoutManager, cocoon::TextLayoutFragment(cocoon::Object, cocoon::TextElement)>::connected((__bridge void*)strongHost, "text_layout_fragment_for_location_in_text_element");
    }
    if (selector == @selector(textLayoutManager:shouldBreakLineBeforeLocation:hyphenating:))
    {
        return strongHost && cocoon::Signal<cocoon::TextLayoutManager, bool(cocoon::Object, bool)>::connected((__bridge void*)strongHost, "should_break_line_before_location_hyphenating");
    }
    if (selector == @selector(textLayoutManager:renderingAttributesForLink:atLocation:defaultAttributes:))
    {
        return strongHost && cocoon::Signal<cocoon::TextLayoutManager, std::map<std::string, cocoon::Object>(cocoon::Object, cocoon::Object, std::map<std::string, cocoon::Object>)>::connected((__bridge void*)strongHost, "rendering_attributes_for_link_at_location_default_attributes");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    TextLayoutManager::TextLayoutManager() : TextLayoutManager(Adopt{cocoon::internal::retain([[::NSTextLayoutManager alloc] init])})
    {
        TextLayoutManager::install_delegate_delegate_(handle());
    }

    TextLayoutManager::TextLayoutManager(std::nullptr_t) : Object(nullptr)
    {
    }

    TextLayoutManager::TextLayoutManager(Adopt adopt) : Object(adopt)
    {
    }

    void TextLayoutManager::add_rendering_attribute(const std::string& rendering_attribute, const Object& value, const TextRange& text_range) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) addRenderingAttribute:cocoon::internal::to(rendering_attribute) value:cocoon::internal::native_id(value) forTextRange:cocoon::internal::native<::NSTextRange>(text_range)];
    }

    void TextLayoutManager::ensure_layout_for_bounds(const Rect& bounds) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) ensureLayoutForBounds:cocoon::internal::to(bounds)];
    }

    void TextLayoutManager::ensure_layout_for_range(const TextRange& range) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) ensureLayoutForRange:cocoon::internal::native<::NSTextRange>(range)];
    }

    void TextLayoutManager::enumerate_rendering_attributes_from_location(const Object& location, bool reverse, std::function<bool(TextLayoutManager, std::map<std::string, Object>, TextRange)> block) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) enumerateRenderingAttributesFromLocation:cocoon::internal::native_id(location) reverse:static_cast<::BOOL>(reverse) usingBlock:(block ? (BOOL(^)(::NSTextLayoutManager*, NSDictionary<NSAttributedStringKey, id>*, ::NSTextRange*)) ^ ::BOOL(::NSTextLayoutManager * a98_0, NSDictionary * a98_1, ::NSTextRange * a98_2) { auto __r = block(cocoon::internal::wrap<TextLayoutManager>(a98_0), cocoon::internal::from_dictionary<std::map<std::string, Object>>(a98_1, [](id k) -> std::string { return cocoon::internal::from((NSString *)k); }, [](id v) -> Object { return cocoon::internal::wrap<Object>(v); }), cocoon::internal::wrap<TextRange>(a98_2)); return static_cast<::BOOL>(__r); } : (BOOL(^)(::NSTextLayoutManager*, NSDictionary<NSAttributedStringKey, id>*, ::NSTextRange*))nil)];
    }

    Object TextLayoutManager::enumerate_text_layout_fragments_from_location(const Object& location, TextLayoutFragmentEnumerationOptions options, std::function<bool(TextLayoutFragment)> block) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTextLayoutManager>(this) enumerateTextLayoutFragmentsFromLocation:cocoon::internal::native_id(location) options:static_cast<::NSTextLayoutFragmentEnumerationOptions>(options) usingBlock:(block ? (BOOL(^)(::NSTextLayoutFragment*)) ^ ::BOOL(::NSTextLayoutFragment * a99_0) { auto __r = block(cocoon::internal::wrap<TextLayoutFragment>(a99_0)); return static_cast<::BOOL>(__r); } : (BOOL(^)(::NSTextLayoutFragment*))nil)]);
    }

    void TextLayoutManager::enumerate_text_segments_in_range(const TextRange& text_range, TextLayoutManagerSegmentType type, TextLayoutManagerSegmentOptions options, std::function<bool(TextRange, Rect, double, TextContainer)> block) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) enumerateTextSegmentsInRange:cocoon::internal::native<::NSTextRange>(text_range) type:static_cast<::NSTextLayoutManagerSegmentType>(type) options:static_cast<::NSTextLayoutManagerSegmentOptions>(options) usingBlock:(block ? (BOOL(^)(::NSTextRange*, ::CGRect, ::CGFloat, ::NSTextContainer*)) ^ ::BOOL(::NSTextRange * a100_0, ::CGRect a100_1, ::CGFloat a100_2, ::NSTextContainer * a100_3) { auto __r = block(cocoon::internal::wrap<TextRange>(a100_0), cocoon::internal::from(a100_1), static_cast<double>(a100_2), cocoon::internal::wrap<TextContainer>(a100_3)); return static_cast<::BOOL>(__r); } : (BOOL(^)(::NSTextRange*, ::CGRect, ::CGFloat, ::NSTextContainer*))nil)];
    }

    void TextLayoutManager::invalidate_layout_for_range(const TextRange& range) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) invalidateLayoutForRange:cocoon::internal::native<::NSTextRange>(range)];
    }

    void TextLayoutManager::invalidate_rendering_attributes_for_text_range(const TextRange& text_range) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) invalidateRenderingAttributesForTextRange:cocoon::internal::native<::NSTextRange>(text_range)];
    }

    void TextLayoutManager::remove_rendering_attribute(const std::string& rendering_attribute, const TextRange& text_range) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) removeRenderingAttribute:cocoon::internal::to(rendering_attribute) forTextRange:cocoon::internal::native<::NSTextRange>(text_range)];
    }

    std::map<std::string, Object> TextLayoutManager::rendering_attributes_for_link(const Object& link, const Object& location) const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSTextLayoutManager>(this) renderingAttributesForLink:cocoon::internal::native_id(link) atLocation:cocoon::internal::native_id(location)], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    void TextLayoutManager::replace_contents_in_range(const TextRange& range, const AttributedString& attributed_string) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) replaceContentsInRange:cocoon::internal::native<::NSTextRange>(range) withAttributedString:cocoon::internal::native<::NSAttributedString>(attributed_string)];
    }

    void TextLayoutManager::replace_contents_in_range(const TextRange& range, const std::vector<TextElement>& text_elements) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) replaceContentsInRange:cocoon::internal::native<::NSTextRange>(range)
                                                                 withTextElements:cocoon::internal::to_array(text_elements, [](const TextElement& e) -> id
                                                                                                             {
                                                                                                                 return cocoon::internal::native<::NSTextElement>(e);
                                                                                                             })];
    }

    void TextLayoutManager::replace_text_content_manager(const TextContentManager& text_content_manager) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) replaceTextContentManager:cocoon::internal::native<::NSTextContentManager>(text_content_manager)];
    }

    void TextLayoutManager::set_rendering_attributes(const std::map<std::string, Object>& rendering_attributes, const TextRange& text_range) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) setRenderingAttributes:cocoon::internal::to_dictionary(rendering_attributes, [](const std::string& k) -> id
                                                                                                                  {
                                                                                                                      return cocoon::internal::to(k);
                                                                                                                  },
                                                                                                                  [](const Object& v) -> id
                                                                                                                  {
                                                                                                                      return cocoon::internal::native_id(v);
                                                                                                                  })
                                                                     forTextRange:cocoon::internal::native<::NSTextRange>(text_range)];
    }

    TextLayoutFragment TextLayoutManager::text_layout_fragment_for_location(const Object& location) const
    {
        return cocoon::internal::wrap<TextLayoutFragment>([cocoon::internal::ns<::NSTextLayoutManager>(this) textLayoutFragmentForLocation:cocoon::internal::native_id(location)]);
    }

    TextLayoutFragment TextLayoutManager::text_layout_fragment_for_position(const Point& position) const
    {
        return cocoon::internal::wrap<TextLayoutFragment>([cocoon::internal::ns<::NSTextLayoutManager>(this) textLayoutFragmentForPosition:cocoon::internal::to(position)]);
    }

    OperationQueue TextLayoutManager::layout_queue() const
    {
        return cocoon::internal::wrap<OperationQueue>([cocoon::internal::ns<::NSTextLayoutManager>(this) layoutQueue]);
    }

    void TextLayoutManager::set_layout_queue(const OperationQueue& value) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) setLayoutQueue:cocoon::internal::native<::NSOperationQueue>(value)];
    }

    bool TextLayoutManager::limits_layout_for_suspicious_contents() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextLayoutManager>(this) limitsLayoutForSuspiciousContents]);
    }

    void TextLayoutManager::set_limits_layout_for_suspicious_contents(bool value) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) setLimitsLayoutForSuspiciousContents:static_cast<::BOOL>(value)];
    }

    std::map<std::string, Object> TextLayoutManager::link_rendering_attributes()
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([::NSTextLayoutManager linkRenderingAttributes], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    std::function<void(TextLayoutManager, TextLayoutFragment)> TextLayoutManager::rendering_attributes_validator() const
    {
        return [&]() -> std::function<void(TextLayoutManager, TextLayoutFragment)>
        {
            auto blk = (void (^)(::NSTextLayoutManager*, ::NSTextLayoutFragment*))([cocoon::internal::ns<::NSTextLayoutManager>(this) renderingAttributesValidator]);
            if (!blk)
            {
                return {};
            }
            return [blk](TextLayoutManager a101_0, TextLayoutFragment a101_1) -> void
            {
                blk(cocoon::internal::native<::NSTextLayoutManager>(a101_0), cocoon::internal::native<::NSTextLayoutFragment>(a101_1));
            };
        }();
    }

    void TextLayoutManager::set_rendering_attributes_validator(std::function<void(TextLayoutManager, TextLayoutFragment)> value) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) setRenderingAttributesValidator:(value ? (void (^)(::NSTextLayoutManager*, ::NSTextLayoutFragment*)) ^ void(::NSTextLayoutManager * a102_0, ::NSTextLayoutFragment * a102_1) { value(cocoon::internal::wrap<TextLayoutManager>(a102_0), cocoon::internal::wrap<TextLayoutFragment>(a102_1)); } : (void (^)(::NSTextLayoutManager*, ::NSTextLayoutFragment*))nil)];
    }

    bool TextLayoutManager::resolves_natural_alignment_with_base_writing_direction() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextLayoutManager>(this) resolvesNaturalAlignmentWithBaseWritingDirection]);
    }

    void TextLayoutManager::set_resolves_natural_alignment_with_base_writing_direction(bool value) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) setResolvesNaturalAlignmentWithBaseWritingDirection:static_cast<::BOOL>(value)];
    }

    TextContainer TextLayoutManager::text_container() const
    {
        return cocoon::internal::wrap<TextContainer>([cocoon::internal::ns<::NSTextLayoutManager>(this) textContainer]);
    }

    void TextLayoutManager::set_text_container(const TextContainer& value) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) setTextContainer:cocoon::internal::native<::NSTextContainer>(value)];
    }

    TextContentManager TextLayoutManager::text_content_manager() const
    {
        return cocoon::internal::wrap<TextContentManager>([cocoon::internal::ns<::NSTextLayoutManager>(this) textContentManager]);
    }

    TextSelectionNavigation TextLayoutManager::text_selection_navigation() const
    {
        return cocoon::internal::wrap<TextSelectionNavigation>([cocoon::internal::ns<::NSTextLayoutManager>(this) textSelectionNavigation]);
    }

    void TextLayoutManager::set_text_selection_navigation(const TextSelectionNavigation& value) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) setTextSelectionNavigation:cocoon::internal::native<::NSTextSelectionNavigation>(value)];
    }

    std::vector<TextSelection> TextLayoutManager::text_selections() const
    {
        return cocoon::internal::from_array<TextSelection>([cocoon::internal::ns<::NSTextLayoutManager>(this) textSelections], [](id e) -> TextSelection
                                                           {
                                                               return cocoon::internal::wrap<TextSelection>((::NSTextSelection*)e);
                                                           });
    }

    void TextLayoutManager::set_text_selections(const std::vector<TextSelection>& value) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) setTextSelections:cocoon::internal::to_array(value, [](const TextSelection& e) -> id
                                                                                                        {
                                                                                                            return cocoon::internal::native<::NSTextSelection>(e);
                                                                                                        })];
    }

    TextViewportLayoutController TextLayoutManager::text_viewport_layout_controller() const
    {
        return cocoon::internal::wrap<TextViewportLayoutController>([cocoon::internal::ns<::NSTextLayoutManager>(this) textViewportLayoutController]);
    }

    Rect TextLayoutManager::usage_bounds_for_text_container() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextLayoutManager>(this) usageBoundsForTextContainer]);
    }

    bool TextLayoutManager::uses_font_leading() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextLayoutManager>(this) usesFontLeading]);
    }

    void TextLayoutManager::set_uses_font_leading(bool value) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) setUsesFontLeading:static_cast<::BOOL>(value)];
    }

    bool TextLayoutManager::uses_hyphenation() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextLayoutManager>(this) usesHyphenation]);
    }

    void TextLayoutManager::set_uses_hyphenation(bool value) const
    {
        [cocoon::internal::ns<::NSTextLayoutManager>(this) setUsesHyphenation:static_cast<::BOOL>(value)];
    }

    void TextLayoutManager::install_delegate_delegate_(void* native)
    {
        ::NSTextLayoutManager* host = (__bridge ::NSTextLayoutManager*)native;
        AKTextLayoutManagerDelegate* delegate = [[AKTextLayoutManagerDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSTextLayoutManager* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSTextLayoutManager* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
