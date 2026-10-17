#include "generated/text_selection_manager.h"
#include "internal.h"

#ifdef COCOON_MACOS_27
@interface AKTextSelectionManagerDelegate : NSObject <NSTextSelectionManagerDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKTextSelectionManagerDelegate

#ifdef COCOON_MACOS_27
- (BOOL)selectionManager:(NSTextSelectionManager*)selectionManager shouldBeginSelectionAtPoint:(NSPoint)point
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextSelectionManager, bool(cocoon::Point)>::emit((__bridge void*)strongHost, "selection_manager_should_begin_selection_at_point", cocoon::internal::from(point));
    return static_cast<::BOOL>(__r);
}

#endif

#ifdef COCOON_MACOS_27
- (void)selectionManagerWillBeginSelection:(NSTextSelectionManager*)selectionManager
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextSelectionManager, void()>::emit((__bridge void*)strongHost, "selection_manager_will_begin_selection");
}

#endif

#ifdef COCOON_MACOS_27
- (void)selectionManagerDidEndSelection:(NSTextSelectionManager*)selectionManager
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextSelectionManager, void()>::emit((__bridge void*)strongHost, "selection_manager_did_end_selection");
}

#endif

#ifdef COCOON_MACOS_27
- (id<NSTextLocation>)selectionManager:(NSTextSelectionManager*)selectionManager locationOfTextContainerAtPoint:(NSPoint)point
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextSelectionManager, cocoon::Object(cocoon::Point)>::emit((__bridge void*)strongHost, "selection_manager_location_of_text_container_at_point", cocoon::internal::from(point));
    return cocoon::internal::native_id(__r);
}

#endif

#ifdef COCOON_MACOS_27
- (NSRect)selectionManager:(NSTextSelectionManager*)selectionManager frameOfTextContainerAtPoint:(NSPoint)point
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextSelectionManager, cocoon::Rect(cocoon::Point)>::emit((__bridge void*)strongHost, "selection_manager_frame_of_text_container_at_point", cocoon::internal::from(point));
    return cocoon::internal::to(__r);
}

#endif

#ifdef COCOON_MACOS_27
- (NSDraggingSession*)selectionManager:(NSTextSelectionManager*)selectionManager makeDraggingSessionWithGesture:(NSGestureRecognizer*)gesture
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextSelectionManager, cocoon::DraggingSession(cocoon::GestureRecognizer)>::emit((__bridge void*)strongHost, "selection_manager_make_dragging_session_with_gesture", cocoon::internal::wrap<cocoon::GestureRecognizer>(gesture));
    return cocoon::internal::native<::NSDraggingSession>(__r);
}

#endif

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
#ifdef COCOON_MACOS_27
    if (selector == @selector(selectionManager:shouldBeginSelectionAtPoint:))
    {
        return strongHost && cocoon::Signal<cocoon::TextSelectionManager, bool(cocoon::Point)>::connected((__bridge void*)strongHost, "selection_manager_should_begin_selection_at_point");
    }
#endif

#ifdef COCOON_MACOS_27
    if (selector == @selector(selectionManagerWillBeginSelection:))
    {
        return strongHost && cocoon::Signal<cocoon::TextSelectionManager, void()>::connected((__bridge void*)strongHost, "selection_manager_will_begin_selection");
    }
#endif

#ifdef COCOON_MACOS_27
    if (selector == @selector(selectionManagerDidEndSelection:))
    {
        return strongHost && cocoon::Signal<cocoon::TextSelectionManager, void()>::connected((__bridge void*)strongHost, "selection_manager_did_end_selection");
    }
#endif

#ifdef COCOON_MACOS_27
    if (selector == @selector(selectionManager:locationOfTextContainerAtPoint:))
    {
        return strongHost && cocoon::Signal<cocoon::TextSelectionManager, cocoon::Object(cocoon::Point)>::connected((__bridge void*)strongHost, "selection_manager_location_of_text_container_at_point");
    }
#endif

#ifdef COCOON_MACOS_27
    if (selector == @selector(selectionManager:frameOfTextContainerAtPoint:))
    {
        return strongHost && cocoon::Signal<cocoon::TextSelectionManager, cocoon::Rect(cocoon::Point)>::connected((__bridge void*)strongHost, "selection_manager_frame_of_text_container_at_point");
    }
#endif

#ifdef COCOON_MACOS_27
    if (selector == @selector(selectionManager:makeDraggingSessionWithGesture:))
    {
        return strongHost && cocoon::Signal<cocoon::TextSelectionManager, cocoon::DraggingSession(cocoon::GestureRecognizer)>::connected((__bridge void*)strongHost, "selection_manager_make_dragging_session_with_gesture");
    }
#endif

    return [super respondsToSelector:selector];
}

@end

@interface AKTextSelectionManagerTextSelectionDataSourceDelegate : NSObject <NSTextSelectionDataSource>
{
@public
    __weak id host;
}
@end

@implementation AKTextSelectionManagerTextSelectionDataSourceDelegate

- (void)enumerateSubstringsFromLocation:(id<NSTextLocation>)location options:(NSStringEnumerationOptions)options usingBlock:(void(NS_NOESCAPE ^)(NSString*, NSTextRange*, NSTextRange*, BOOL*))block
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextSelectionManager, void(cocoon::StringEnumerationOptions, std::function<void(std::string, cocoon::TextRange, cocoon::TextRange, bool&)>)>::emit((__bridge void*)strongHost, "enumerate_substrings_from_location_options_using_block", static_cast<cocoon::StringEnumerationOptions>(options), [&]() -> std::function<void(std::string, cocoon::TextRange, cocoon::TextRange, bool&)>
                                                                                                                                                                              {
                                                                                                                                                                                  auto blk = (void (^)(::NSString*, ::NSTextRange*, ::NSTextRange*, BOOL*))(block);
                                                                                                                                                                                  if (!blk)
                                                                                                                                                                                  {
                                                                                                                                                                                      return {};
                                                                                                                                                                                  }
                                                                                                                                                                                  return [blk](std::string a283_0, cocoon::TextRange a283_1, cocoon::TextRange a283_2, bool& a283_3) -> void
                                                                                                                                                                                  {
                                                                                                                                                                                      ::BOOL __o283_3 = static_cast<::BOOL>(a283_3);
                                                                                                                                                                                      blk(cocoon::internal::to(a283_0), cocoon::internal::native<::NSTextRange>(a283_1), cocoon::internal::native<::NSTextRange>(a283_2), &__o283_3);
                                                                                                                                                                                      a283_3 = static_cast<bool>(__o283_3);
                                                                                                                                                                                  };
                                                                                                                                                                              }());
}

- (NSTextRange*)textRangeForSelectionGranularity:(NSTextSelectionGranularity)selectionGranularity enclosingLocation:(id<NSTextLocation>)location
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextSelectionManager, cocoon::TextRange(cocoon::Object)>::emit((__bridge void*)strongHost, "text_range_for_selection_granularity_enclosing_location", cocoon::internal::wrap<cocoon::Object>(location));
    return cocoon::internal::native<::NSTextRange>(__r);
}

- (id<NSTextLocation>)locationFromLocation:(id<NSTextLocation>)location withOffset:(NSInteger)offset
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextSelectionManager, cocoon::Object(std::int64_t)>::emit((__bridge void*)strongHost, "location_from_location_with_offset", static_cast<std::int64_t>(offset));
    return cocoon::internal::native_id(__r);
}

- (NSInteger)offsetFromLocation:(id<NSTextLocation>)from toLocation:(id<NSTextLocation>)to
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextSelectionManager, std::int64_t(cocoon::Object)>::emit((__bridge void*)strongHost, "offset_from_location_to_location", cocoon::internal::wrap<cocoon::Object>(to));
    return static_cast<::NSInteger>(__r);
}

- (NSTextSelectionNavigationWritingDirection)baseWritingDirectionAtLocation:(id<NSTextLocation>)location
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextSelectionManager, cocoon::TextSelectionNavigationWritingDirection()>::emit((__bridge void*)strongHost, "base_writing_direction_at_location");
    return static_cast<::NSTextSelectionNavigationWritingDirection>(__r);
}

- (void)enumerateCaretOffsetsInLineFragmentAtLocation:(id<NSTextLocation>)location usingBlock:(void(NS_NOESCAPE ^)(CGFloat, id<NSTextLocation>, BOOL, BOOL*))block
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextSelectionManager, void(std::function<void(double, cocoon::Object, bool, bool&)>)>::emit((__bridge void*)strongHost, "enumerate_caret_offsets_in_line_fragment_at_location_using_block", [&]() -> std::function<void(double, cocoon::Object, bool, bool&)>
                                                                                                                       {
                                                                                                                           auto blk = (void (^)(::CGFloat, id<NSTextLocation>, BOOL, BOOL*))(block);
                                                                                                                           if (!blk)
                                                                                                                           {
                                                                                                                               return {};
                                                                                                                           }
                                                                                                                           return [blk](double a284_0, cocoon::Object a284_1, bool a284_2, bool& a284_3) -> void
                                                                                                                           {
                                                                                                                               ::BOOL __o284_3 = static_cast<::BOOL>(a284_3);
                                                                                                                               blk(static_cast<::CGFloat>(a284_0), cocoon::internal::native_id(a284_1), static_cast<::BOOL>(a284_2), &__o284_3);
                                                                                                                               a284_3 = static_cast<bool>(__o284_3);
                                                                                                                           };
                                                                                                                       }());
}

- (NSTextRange*)lineFragmentRangeForPoint:(CGPoint)point inContainerAtLocation:(id<NSTextLocation>)location
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextSelectionManager, cocoon::TextRange(cocoon::Object)>::emit((__bridge void*)strongHost, "line_fragment_range_for_point_in_container_at_location", cocoon::internal::wrap<cocoon::Object>(location));
    return cocoon::internal::native<::NSTextRange>(__r);
}

- (void)enumerateContainerBoundariesFromLocation:(id<NSTextLocation>)location reverse:(BOOL)reverse usingBlock:(void(NS_NOESCAPE ^)(id<NSTextLocation>, BOOL*))block
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextSelectionManager, void(bool, std::function<void(cocoon::Object, bool&)>)>::emit((__bridge void*)strongHost, "enumerate_container_boundaries_from_location_reverse_using_block", static_cast<bool>(reverse), [&]() -> std::function<void(cocoon::Object, bool&)>
                                                                                                               {
                                                                                                                   auto blk = (void (^)(id<NSTextLocation>, BOOL*))(block);
                                                                                                                   if (!blk)
                                                                                                                   {
                                                                                                                       return {};
                                                                                                                   }
                                                                                                                   return [blk](cocoon::Object a285_0, bool& a285_1) -> void
                                                                                                                   {
                                                                                                                       ::BOOL __o285_1 = static_cast<::BOOL>(a285_1);
                                                                                                                       blk(cocoon::internal::native_id(a285_0), &__o285_1);
                                                                                                                       a285_1 = static_cast<bool>(__o285_1);
                                                                                                                   };
                                                                                                               }());
}

- (NSTextSelectionNavigationLayoutOrientation)textLayoutOrientationAtLocation:(id<NSTextLocation>)location
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextSelectionManager, cocoon::TextSelectionNavigationLayoutOrientation()>::emit((__bridge void*)strongHost, "text_layout_orientation_at_location");
    return static_cast<::NSTextSelectionNavigationLayoutOrientation>(__r);
}

#ifdef COCOON_MACOS_27
- (CGPoint)convertInteractionPoint:(CGPoint)point toContainerAtLocation:(id<NSTextLocation>)containerLocation
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextSelectionManager, cocoon::Point(cocoon::Object)>::emit((__bridge void*)strongHost, "convert_interaction_point_to_container_at_location", cocoon::internal::wrap<cocoon::Object>(containerLocation));
    return cocoon::internal::to(__r);
}

#endif

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(enumerateSubstringsFromLocation:options:usingBlock:))
    {
        return strongHost && cocoon::Signal<cocoon::TextSelectionManager, void(cocoon::StringEnumerationOptions, std::function<void(std::string, cocoon::TextRange, cocoon::TextRange, bool&)>)>::connected((__bridge void*)strongHost, "enumerate_substrings_from_location_options_using_block");
    }
    if (selector == @selector(textRangeForSelectionGranularity:enclosingLocation:))
    {
        return strongHost && cocoon::Signal<cocoon::TextSelectionManager, cocoon::TextRange(cocoon::Object)>::connected((__bridge void*)strongHost, "text_range_for_selection_granularity_enclosing_location");
    }
    if (selector == @selector(locationFromLocation:withOffset:))
    {
        return strongHost && cocoon::Signal<cocoon::TextSelectionManager, cocoon::Object(std::int64_t)>::connected((__bridge void*)strongHost, "location_from_location_with_offset");
    }
    if (selector == @selector(offsetFromLocation:toLocation:))
    {
        return strongHost && cocoon::Signal<cocoon::TextSelectionManager, std::int64_t(cocoon::Object)>::connected((__bridge void*)strongHost, "offset_from_location_to_location");
    }
    if (selector == @selector(baseWritingDirectionAtLocation:))
    {
        return strongHost && cocoon::Signal<cocoon::TextSelectionManager, cocoon::TextSelectionNavigationWritingDirection()>::connected((__bridge void*)strongHost, "base_writing_direction_at_location");
    }
    if (selector == @selector(enumerateCaretOffsetsInLineFragmentAtLocation:usingBlock:))
    {
        return strongHost && cocoon::Signal<cocoon::TextSelectionManager, void(std::function<void(double, cocoon::Object, bool, bool&)>)>::connected((__bridge void*)strongHost, "enumerate_caret_offsets_in_line_fragment_at_location_using_block");
    }
    if (selector == @selector(lineFragmentRangeForPoint:inContainerAtLocation:))
    {
        return strongHost && cocoon::Signal<cocoon::TextSelectionManager, cocoon::TextRange(cocoon::Object)>::connected((__bridge void*)strongHost, "line_fragment_range_for_point_in_container_at_location");
    }
    if (selector == @selector(enumerateContainerBoundariesFromLocation:reverse:usingBlock:))
    {
        return strongHost && cocoon::Signal<cocoon::TextSelectionManager, void(bool, std::function<void(cocoon::Object, bool&)>)>::connected((__bridge void*)strongHost, "enumerate_container_boundaries_from_location_reverse_using_block");
    }
    if (selector == @selector(textLayoutOrientationAtLocation:))
    {
        return strongHost && cocoon::Signal<cocoon::TextSelectionManager, cocoon::TextSelectionNavigationLayoutOrientation()>::connected((__bridge void*)strongHost, "text_layout_orientation_at_location");
    }
#ifdef COCOON_MACOS_27
    if (selector == @selector(convertInteractionPoint:toContainerAtLocation:))
    {
        return strongHost && cocoon::Signal<cocoon::TextSelectionManager, cocoon::Point(cocoon::Object)>::connected((__bridge void*)strongHost, "convert_interaction_point_to_container_at_location");
    }
#endif

    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    TextSelectionManager::TextSelectionManager() : TextSelectionManager(Adopt{cocoon::internal::retain([[::NSTextSelectionManager alloc] init])})
    {
        TextSelectionManager::install_delegate_delegate_(handle());
        TextSelectionManager::install_text_selection_data_source_delegate_(handle());
    }

    TextSelectionManager::TextSelectionManager(std::nullptr_t) : Object(nullptr)
    {
    }

    TextSelectionManager::TextSelectionManager(Adopt adopt) : Object(adopt)
    {
    }

#ifdef COCOON_MACOS_27
    std::vector<GestureRecognizer> TextSelectionManager::gestures_for_failure_requirements() const
    {
        if (@available(macOS 27.0, *))
        {
            return cocoon::internal::from_array<GestureRecognizer>([cocoon::internal::ns<::NSTextSelectionManager>(this) gesturesForFailureRequirements], [](id e) -> GestureRecognizer
                                                                   {
                                                                       return cocoon::internal::wrap<GestureRecognizer>((::NSGestureRecognizer*)e);
                                                                   });
        }
        return {};
    }

#endif

#ifdef COCOON_MACOS_27
    TextSelectionMode TextSelectionManager::text_selection_mode() const
    {
        if (@available(macOS 27.0, *))
        {
            return static_cast<TextSelectionMode>([cocoon::internal::ns<::NSTextSelectionManager>(this) textSelectionMode]);
        }
        return {};
    }

#endif

#ifdef COCOON_MACOS_27
    void TextSelectionManager::set_text_selection_mode(TextSelectionMode value) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSTextSelectionManager>(this) setTextSelectionMode:static_cast<::NSTextSelectionMode>(value)];
        }
    }

#endif

    void TextSelectionManager::install_delegate_delegate_(void* native)
    {
        ::NSTextSelectionManager* host = (__bridge ::NSTextSelectionManager*)native;
        AKTextSelectionManagerDelegate* delegate = [[AKTextSelectionManagerDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSTextSelectionManager* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSTextSelectionManager* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }

    void TextSelectionManager::install_text_selection_data_source_delegate_(void* native)
    {
        ::NSTextSelectionManager* host = (__bridge ::NSTextSelectionManager*)native;
        AKTextSelectionManagerTextSelectionDataSourceDelegate* delegate = [[AKTextSelectionManagerTextSelectionDataSourceDelegate alloc] init];
        delegate->host = host;
        host.textSelectionDataSource = delegate;
        __weak::NSTextSelectionManager* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSTextSelectionManager* strongHost = weakHost;
            strongHost.textSelectionDataSource = nil;
            strongHost.textSelectionDataSource = delegate;
        });
    }
}

#endif
