#include "generated/window.h"
#include "internal.h"

@interface AKWindowDelegate : NSObject <NSWindowDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKWindowDelegate

- (BOOL)windowShouldClose:(NSWindow*)sender
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Window, bool()>::emit((__bridge void*)strongHost, "should_close");
    return static_cast<::BOOL>(__r);
}

- (id)windowWillReturnFieldEditor:(NSWindow*)sender toObject:(id)client
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Window, cocoon::Object(cocoon::Object)>::emit((__bridge void*)strongHost, "will_return_field_editor_to_object", cocoon::internal::wrap<cocoon::Object>(client));
    return cocoon::internal::native_id(__r);
}

- (NSSize)windowWillResize:(NSWindow*)sender toSize:(NSSize)frameSize
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Window, cocoon::Size(cocoon::Size)>::emit((__bridge void*)strongHost, "will_resize_to_size", cocoon::internal::from(frameSize));
    return cocoon::internal::to(__r);
}

- (NSRect)windowWillUseStandardFrame:(NSWindow*)window defaultFrame:(NSRect)newFrame
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Window, cocoon::Rect(cocoon::Rect)>::emit((__bridge void*)strongHost, "will_use_standard_frame_default_frame", cocoon::internal::from(newFrame));
    return cocoon::internal::to(__r);
}

- (BOOL)windowShouldZoom:(NSWindow*)window toFrame:(NSRect)newFrame
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Window, bool(cocoon::Rect)>::emit((__bridge void*)strongHost, "should_zoom_to_frame", cocoon::internal::from(newFrame));
    return static_cast<::BOOL>(__r);
}

- (NSUndoManager*)windowWillReturnUndoManager:(NSWindow*)window
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Window, cocoon::UndoManager()>::emit((__bridge void*)strongHost, "will_return_undo_manager");
    return cocoon::internal::native<::NSUndoManager>(__r);
}

- (NSRect)window:(NSWindow*)window willPositionSheet:(NSWindow*)sheet usingRect:(NSRect)rect
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Window, cocoon::Rect(cocoon::Window, cocoon::Rect)>::emit((__bridge void*)strongHost, "will_position_sheet_using_rect", cocoon::internal::wrap<cocoon::Window>(sheet), cocoon::internal::from(rect));
    return cocoon::internal::to(__r);
}

- (BOOL)window:(NSWindow*)window shouldPopUpDocumentPathMenu:(NSMenu*)menu
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Window, bool(cocoon::Menu)>::emit((__bridge void*)strongHost, "should_pop_up_document_path_menu", cocoon::internal::wrap<cocoon::Menu>(menu));
    return static_cast<::BOOL>(__r);
}

- (BOOL)window:(NSWindow*)window shouldDragDocumentWithEvent:(NSEvent*)event from:(NSPoint)dragImageLocation withPasteboard:(NSPasteboard*)pasteboard
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Window, bool(cocoon::Event, cocoon::Point, cocoon::Pasteboard)>::emit((__bridge void*)strongHost, "should_drag_document_with_event_from_with_pasteboard", cocoon::internal::wrap<cocoon::Event>(event), cocoon::internal::from(dragImageLocation), cocoon::internal::wrap<cocoon::Pasteboard>(pasteboard));
    return static_cast<::BOOL>(__r);
}

- (NSSize)window:(NSWindow*)window willUseFullScreenContentSize:(NSSize)proposedSize
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Window, cocoon::Size(cocoon::Size)>::emit((__bridge void*)strongHost, "will_use_full_screen_content_size", cocoon::internal::from(proposedSize));
    return cocoon::internal::to(__r);
}

- (NSApplicationPresentationOptions)window:(NSWindow*)window willUseFullScreenPresentationOptions:(NSApplicationPresentationOptions)proposedOptions
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Window, cocoon::ApplicationPresentationOptions(cocoon::ApplicationPresentationOptions)>::emit((__bridge void*)strongHost, "will_use_full_screen_presentation_options", static_cast<cocoon::ApplicationPresentationOptions>(proposedOptions));
    return static_cast<::NSApplicationPresentationOptions>(__r);
}

- (NSArray<NSWindow*>*)customWindowsToEnterFullScreenForWindow:(NSWindow*)window
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Window, std::vector<cocoon::Window>()>::emit((__bridge void*)strongHost, "custom_windows_to_enter_full_screen_for_window");
    return cocoon::internal::to_array(__r, [](const cocoon::Window& e) -> id
                                      {
                                          return cocoon::internal::native<::NSWindow>(e);
                                      });
}

- (void)window:(NSWindow*)window startCustomAnimationToEnterFullScreenWithDuration:(NSTimeInterval)duration
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(double)>::emit((__bridge void*)strongHost, "start_custom_animation_to_enter_full_screen_with_duration", static_cast<double>(duration));
}

- (void)windowDidFailToEnterFullScreen:(NSWindow*)window
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void()>::emit((__bridge void*)strongHost, "did_fail_to_enter_full_screen");
}

- (NSArray<NSWindow*>*)customWindowsToExitFullScreenForWindow:(NSWindow*)window
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Window, std::vector<cocoon::Window>()>::emit((__bridge void*)strongHost, "custom_windows_to_exit_full_screen_for_window");
    return cocoon::internal::to_array(__r, [](const cocoon::Window& e) -> id
                                      {
                                          return cocoon::internal::native<::NSWindow>(e);
                                      });
}

- (void)window:(NSWindow*)window startCustomAnimationToExitFullScreenWithDuration:(NSTimeInterval)duration
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(double)>::emit((__bridge void*)strongHost, "start_custom_animation_to_exit_full_screen_with_duration", static_cast<double>(duration));
}

- (NSArray<NSWindow*>*)customWindowsToEnterFullScreenForWindow:(NSWindow*)window onScreen:(NSScreen*)screen
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Window, std::vector<cocoon::Window>(cocoon::Screen)>::emit((__bridge void*)strongHost, "custom_windows_to_enter_full_screen_for_window_on_screen", cocoon::internal::wrap<cocoon::Screen>(screen));
    return cocoon::internal::to_array(__r, [](const cocoon::Window& e) -> id
                                      {
                                          return cocoon::internal::native<::NSWindow>(e);
                                      });
}

- (void)window:(NSWindow*)window startCustomAnimationToEnterFullScreenOnScreen:(NSScreen*)screen withDuration:(NSTimeInterval)duration
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Screen, double)>::emit((__bridge void*)strongHost, "start_custom_animation_to_enter_full_screen_on_screen_with_duration", cocoon::internal::wrap<cocoon::Screen>(screen), static_cast<double>(duration));
}

- (void)windowDidFailToExitFullScreen:(NSWindow*)window
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void()>::emit((__bridge void*)strongHost, "did_fail_to_exit_full_screen");
}

- (NSSize)window:(NSWindow*)window willResizeForVersionBrowserWithMaxPreferredSize:(NSSize)maxPreferredFrameSize maxAllowedSize:(NSSize)maxAllowedFrameSize
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Window, cocoon::Size(cocoon::Size, cocoon::Size)>::emit((__bridge void*)strongHost, "will_resize_for_version_browser_with_max_preferred_size_max_allowed_size", cocoon::internal::from(maxPreferredFrameSize), cocoon::internal::from(maxAllowedFrameSize));
    return cocoon::internal::to(__r);
}

- (void)window:(NSWindow*)window willEncodeRestorableState:(NSCoder*)state
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Coder)>::emit((__bridge void*)strongHost, "will_encode_restorable_state", cocoon::internal::wrap<cocoon::Coder>(state));
}

- (void)window:(NSWindow*)window didDecodeRestorableState:(NSCoder*)state
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Coder)>::emit((__bridge void*)strongHost, "did_decode_restorable_state", cocoon::internal::wrap<cocoon::Coder>(state));
}

- (NSArray<id<NSPreviewRepresentableActivityItem>>*)previewRepresentableActivityItemsForWindow:(NSWindow*)window
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Window, std::vector<cocoon::Object>()>::emit((__bridge void*)strongHost, "preview_representable_activity_items_for_window");
    return cocoon::internal::to_array(__r, [](const cocoon::Object& e) -> id
                                      {
                                          return cocoon::internal::native_id(e);
                                      });
}

- (NSWindow*)windowForSharingRequestFromWindow:(NSWindow*)window
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Window, cocoon::Window()>::emit((__bridge void*)strongHost, "for_sharing_request_from_window");
    return cocoon::internal::native<::NSWindow>(__r);
}

- (void)windowDidResize:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Size)>::emit((__bridge void*)strongHost, "resized", cocoon::internal::from([(NSWindow*)notification.object contentRectForFrameRect:((NSWindow*)notification.object).frame].size));
}

- (void)windowDidExpose:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_expose", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowWillMove:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_move", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowDidMove:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_move", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowDidBecomeKey:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_become_key", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowDidResignKey:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_resign_key", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowDidBecomeMain:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_become_main", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowDidResignMain:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_resign_main", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowWillClose:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_close", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowWillMiniaturize:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_miniaturize", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowDidMiniaturize:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_miniaturize", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowDidDeminiaturize:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_deminiaturize", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowDidUpdate:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_update", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowDidChangeScreen:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_change_screen", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowDidChangeScreenProfile:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_change_screen_profile", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowDidChangeBackingProperties:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_change_backing_properties", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowWillBeginSheet:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_begin_sheet", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowDidEndSheet:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_end_sheet", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowWillStartLiveResize:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_start_live_resize", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowDidEndLiveResize:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_end_live_resize", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowWillEnterFullScreen:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_enter_full_screen", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowDidEnterFullScreen:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_enter_full_screen", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowWillExitFullScreen:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_exit_full_screen", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowDidExitFullScreen:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_exit_full_screen", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowWillEnterVersionBrowser:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_enter_version_browser", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowDidEnterVersionBrowser:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_enter_version_browser", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowWillExitVersionBrowser:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_exit_version_browser", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowDidExitVersionBrowser:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_exit_version_browser", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)windowDidChangeOcclusionState:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_change_occlusion_state", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(windowShouldClose:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, bool()>::connected((__bridge void*)strongHost, "should_close");
    }
    if (selector == @selector(windowWillReturnFieldEditor:toObject:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, cocoon::Object(cocoon::Object)>::connected((__bridge void*)strongHost, "will_return_field_editor_to_object");
    }
    if (selector == @selector(windowWillResize:toSize:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, cocoon::Size(cocoon::Size)>::connected((__bridge void*)strongHost, "will_resize_to_size");
    }
    if (selector == @selector(windowWillUseStandardFrame:defaultFrame:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, cocoon::Rect(cocoon::Rect)>::connected((__bridge void*)strongHost, "will_use_standard_frame_default_frame");
    }
    if (selector == @selector(windowShouldZoom:toFrame:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, bool(cocoon::Rect)>::connected((__bridge void*)strongHost, "should_zoom_to_frame");
    }
    if (selector == @selector(windowWillReturnUndoManager:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, cocoon::UndoManager()>::connected((__bridge void*)strongHost, "will_return_undo_manager");
    }
    if (selector == @selector(window:willPositionSheet:usingRect:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, cocoon::Rect(cocoon::Window, cocoon::Rect)>::connected((__bridge void*)strongHost, "will_position_sheet_using_rect");
    }
    if (selector == @selector(window:shouldPopUpDocumentPathMenu:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, bool(cocoon::Menu)>::connected((__bridge void*)strongHost, "should_pop_up_document_path_menu");
    }
    if (selector == @selector(window:shouldDragDocumentWithEvent:from:withPasteboard:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, bool(cocoon::Event, cocoon::Point, cocoon::Pasteboard)>::connected((__bridge void*)strongHost, "should_drag_document_with_event_from_with_pasteboard");
    }
    if (selector == @selector(window:willUseFullScreenContentSize:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, cocoon::Size(cocoon::Size)>::connected((__bridge void*)strongHost, "will_use_full_screen_content_size");
    }
    if (selector == @selector(window:willUseFullScreenPresentationOptions:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, cocoon::ApplicationPresentationOptions(cocoon::ApplicationPresentationOptions)>::connected((__bridge void*)strongHost, "will_use_full_screen_presentation_options");
    }
    if (selector == @selector(customWindowsToEnterFullScreenForWindow:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, std::vector<cocoon::Window>()>::connected((__bridge void*)strongHost, "custom_windows_to_enter_full_screen_for_window");
    }
    if (selector == @selector(window:startCustomAnimationToEnterFullScreenWithDuration:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(double)>::connected((__bridge void*)strongHost, "start_custom_animation_to_enter_full_screen_with_duration");
    }
    if (selector == @selector(windowDidFailToEnterFullScreen:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void()>::connected((__bridge void*)strongHost, "did_fail_to_enter_full_screen");
    }
    if (selector == @selector(customWindowsToExitFullScreenForWindow:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, std::vector<cocoon::Window>()>::connected((__bridge void*)strongHost, "custom_windows_to_exit_full_screen_for_window");
    }
    if (selector == @selector(window:startCustomAnimationToExitFullScreenWithDuration:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(double)>::connected((__bridge void*)strongHost, "start_custom_animation_to_exit_full_screen_with_duration");
    }
    if (selector == @selector(customWindowsToEnterFullScreenForWindow:onScreen:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, std::vector<cocoon::Window>(cocoon::Screen)>::connected((__bridge void*)strongHost, "custom_windows_to_enter_full_screen_for_window_on_screen");
    }
    if (selector == @selector(window:startCustomAnimationToEnterFullScreenOnScreen:withDuration:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Screen, double)>::connected((__bridge void*)strongHost, "start_custom_animation_to_enter_full_screen_on_screen_with_duration");
    }
    if (selector == @selector(windowDidFailToExitFullScreen:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void()>::connected((__bridge void*)strongHost, "did_fail_to_exit_full_screen");
    }
    if (selector == @selector(window:willResizeForVersionBrowserWithMaxPreferredSize:maxAllowedSize:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, cocoon::Size(cocoon::Size, cocoon::Size)>::connected((__bridge void*)strongHost, "will_resize_for_version_browser_with_max_preferred_size_max_allowed_size");
    }
    if (selector == @selector(window:willEncodeRestorableState:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Coder)>::connected((__bridge void*)strongHost, "will_encode_restorable_state");
    }
    if (selector == @selector(window:didDecodeRestorableState:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Coder)>::connected((__bridge void*)strongHost, "did_decode_restorable_state");
    }
    if (selector == @selector(previewRepresentableActivityItemsForWindow:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, std::vector<cocoon::Object>()>::connected((__bridge void*)strongHost, "preview_representable_activity_items_for_window");
    }
    if (selector == @selector(windowForSharingRequestFromWindow:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, cocoon::Window()>::connected((__bridge void*)strongHost, "for_sharing_request_from_window");
    }
    if (selector == @selector(windowDidResize:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Size)>::connected((__bridge void*)strongHost, "resized");
    }
    if (selector == @selector(windowDidExpose:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_expose");
    }
    if (selector == @selector(windowWillMove:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_move");
    }
    if (selector == @selector(windowDidMove:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_move");
    }
    if (selector == @selector(windowDidBecomeKey:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_become_key");
    }
    if (selector == @selector(windowDidResignKey:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_resign_key");
    }
    if (selector == @selector(windowDidBecomeMain:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_become_main");
    }
    if (selector == @selector(windowDidResignMain:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_resign_main");
    }
    if (selector == @selector(windowWillClose:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_close");
    }
    if (selector == @selector(windowWillMiniaturize:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_miniaturize");
    }
    if (selector == @selector(windowDidMiniaturize:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_miniaturize");
    }
    if (selector == @selector(windowDidDeminiaturize:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_deminiaturize");
    }
    if (selector == @selector(windowDidUpdate:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_update");
    }
    if (selector == @selector(windowDidChangeScreen:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_change_screen");
    }
    if (selector == @selector(windowDidChangeScreenProfile:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_change_screen_profile");
    }
    if (selector == @selector(windowDidChangeBackingProperties:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_change_backing_properties");
    }
    if (selector == @selector(windowWillBeginSheet:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_begin_sheet");
    }
    if (selector == @selector(windowDidEndSheet:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_end_sheet");
    }
    if (selector == @selector(windowWillStartLiveResize:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_start_live_resize");
    }
    if (selector == @selector(windowDidEndLiveResize:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_end_live_resize");
    }
    if (selector == @selector(windowWillEnterFullScreen:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_enter_full_screen");
    }
    if (selector == @selector(windowDidEnterFullScreen:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_enter_full_screen");
    }
    if (selector == @selector(windowWillExitFullScreen:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_exit_full_screen");
    }
    if (selector == @selector(windowDidExitFullScreen:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_exit_full_screen");
    }
    if (selector == @selector(windowWillEnterVersionBrowser:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_enter_version_browser");
    }
    if (selector == @selector(windowDidEnterVersionBrowser:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_enter_version_browser");
    }
    if (selector == @selector(windowWillExitVersionBrowser:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_exit_version_browser");
    }
    if (selector == @selector(windowDidExitVersionBrowser:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_exit_version_browser");
    }
    if (selector == @selector(windowDidChangeOcclusionState:))
    {
        return strongHost && cocoon::Signal<cocoon::Window, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_change_occlusion_state");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    Window::Window(const std::string& title, Size size, WindowStyle style) : Window(Adopt{cocoon::internal::retain(cocoon::internal::make_window(title, size, style))})
    {
        Window::install_delegate_delegate_(handle());
    }

    Window::Window(const Rect& content_rect, WindowStyle style, BackingStoreType backing_store_type, bool flag) : Window(Adopt{cocoon::internal::retain([[::NSWindow alloc] initWithContentRect:cocoon::internal::to(content_rect) styleMask:static_cast<::NSWindowStyleMask>(style) backing:static_cast<::NSBackingStoreType>(backing_store_type) defer:static_cast<::BOOL>(flag)])})
    {
        Window::install_delegate_delegate_(handle());
    }

    Window::Window(const Rect& content_rect, WindowStyle style, BackingStoreType backing_store_type, bool flag, const Screen& screen) : Window(Adopt{cocoon::internal::retain([[::NSWindow alloc] initWithContentRect:cocoon::internal::to(content_rect) styleMask:static_cast<::NSWindowStyleMask>(style) backing:static_cast<::NSBackingStoreType>(backing_store_type) defer:static_cast<::BOOL>(flag) screen:cocoon::internal::native<::NSScreen>(screen)])})
    {
        Window::install_delegate_delegate_(handle());
    }

    Window::Window(const ViewController& content_view_controller) : Window(Adopt{cocoon::internal::retain([::NSWindow windowWithContentViewController:cocoon::internal::native<::NSViewController>(content_view_controller)])})
    {
        Window::install_delegate_delegate_(handle());
    }

    Window::Window(std::nullptr_t) : Responder(nullptr)
    {
    }

    Window::Window(Adopt adopt) : Responder(adopt)
    {
    }

    void Window::add_child_window(const Window& child_win, WindowOrderingMode place) const
    {
        [cocoon::internal::ns<::NSWindow>(this) addChildWindow:cocoon::internal::native<::NSWindow>(child_win) ordered:static_cast<::NSWindowOrderingMode>(place)];
    }

    void Window::add_tabbed_window(const Window& window, WindowOrderingMode ordered) const
    {
        [cocoon::internal::ns<::NSWindow>(this) addTabbedWindow:cocoon::internal::native<::NSWindow>(window) ordered:static_cast<::NSWindowOrderingMode>(ordered)];
    }

    void Window::add_titlebar_accessory_view_controller(const TitlebarAccessoryViewController& child_view_controller) const
    {
        [cocoon::internal::ns<::NSWindow>(this) addTitlebarAccessoryViewController:cocoon::internal::native<::NSTitlebarAccessoryViewController>(child_view_controller)];
    }

    LayoutAttribute Window::anchor_attribute_for_orientation(ConstraintOrientation orientation) const
    {
        return static_cast<LayoutAttribute>([cocoon::internal::ns<::NSWindow>(this) anchorAttributeForOrientation:static_cast<::NSLayoutConstraintOrientation>(orientation)]);
    }

    double Window::animation_resize_time(const Rect& new_frame) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSWindow>(this) animationResizeTime:cocoon::internal::to(new_frame)]);
    }

    bool Window::autorecalculates_content_border_thickness_for_edge(RectEdge edge) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) autorecalculatesContentBorderThicknessForEdge:static_cast<::NSRectEdge>(edge)]);
    }

    Rect Window::backing_aligned_rect(const Rect& rect, AlignmentOptions options) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) backingAlignedRect:cocoon::internal::to(rect) options:static_cast<::NSAlignmentOptions>(options)]);
    }

    void Window::become_key_window() const
    {
        [cocoon::internal::ns<::NSWindow>(this) becomeKeyWindow];
    }

    void Window::become_main_window() const
    {
        [cocoon::internal::ns<::NSWindow>(this) becomeMainWindow];
    }

    void Window::begin_critical_sheet(const Window& sheet_window, std::function<void(std::int64_t)> handler) const
    {
        [cocoon::internal::ns<::NSWindow>(this) beginCriticalSheet:cocoon::internal::native<::NSWindow>(sheet_window) completionHandler:(handler ? (void (^)(::NSModalResponse)) ^ void(::NSModalResponse a105_0) { handler(static_cast<std::int64_t>(a105_0)); } : (void (^)(::NSModalResponse))nil)];
    }

    DraggingSession Window::begin_dragging_session_with_items(const std::vector<DraggingItem>& items, const Event& event, const Object& source) const
    {
        return cocoon::internal::wrap<DraggingSession>([cocoon::internal::ns<::NSWindow>(this) beginDraggingSessionWithItems:cocoon::internal::to_array(items, [](const DraggingItem& e) -> id
                                                                                                                                                        {
                                                                                                                                                            return cocoon::internal::native<::NSDraggingItem>(e);
                                                                                                                                                        })
                                                                                                                       event:cocoon::internal::native<::NSEvent>(event)
                                                                                                                      source:cocoon::internal::native_id(source)]);
    }

    bool Window::can_represent_display_gamut(DisplayGamut display_gamut) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) canRepresentDisplayGamut:static_cast<::NSDisplayGamut>(display_gamut)]);
    }

    Point Window::cascade_top_left_from_point(const Point& top_left_point) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) cascadeTopLeftFromPoint:cocoon::internal::to(top_left_point)]);
    }

    Rect Window::constrain_frame_rect(const Rect& frame_rect, const Screen& screen) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) constrainFrameRect:cocoon::internal::to(frame_rect) toScreen:cocoon::internal::native<::NSScreen>(screen)]);
    }

    double Window::content_border_thickness_for_edge(RectEdge edge) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSWindow>(this) contentBorderThicknessForEdge:static_cast<::NSRectEdge>(edge)]);
    }

    Rect Window::content_rect_for_frame_rect(const Rect& frame_rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) contentRectForFrameRect:cocoon::internal::to(frame_rect)]);
    }

    Rect Window::content_rect_for_frame_rect(const Rect& f_rect, WindowStyle style)
    {
        return cocoon::internal::from([::NSWindow contentRectForFrameRect:cocoon::internal::to(f_rect) styleMask:static_cast<::NSWindowStyleMask>(style)]);
    }

    Point Window::convert_point_from_backing(const Point& point) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) convertPointFromBacking:cocoon::internal::to(point)]);
    }

    Point Window::convert_point_from_screen(const Point& point) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) convertPointFromScreen:cocoon::internal::to(point)]);
    }

    Point Window::convert_point_to_backing(const Point& point) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) convertPointToBacking:cocoon::internal::to(point)]);
    }

    Point Window::convert_point_to_screen(const Point& point) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) convertPointToScreen:cocoon::internal::to(point)]);
    }

    Rect Window::convert_rect_from_backing(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) convertRectFromBacking:cocoon::internal::to(rect)]);
    }

    Rect Window::convert_rect_from_screen(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) convertRectFromScreen:cocoon::internal::to(rect)]);
    }

    Rect Window::convert_rect_to_backing(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) convertRectToBacking:cocoon::internal::to(rect)]);
    }

    Rect Window::convert_rect_to_screen(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) convertRectToScreen:cocoon::internal::to(rect)]);
    }

    std::vector<std::uint8_t> Window::data_with_eps_inside_rect(const Rect& rect) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSWindow>(this) dataWithEPSInsideRect:cocoon::internal::to(rect)]);
    }

    std::vector<std::uint8_t> Window::data_with_pdf_inside_rect(const Rect& rect) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSWindow>(this) dataWithPDFInsideRect:cocoon::internal::to(rect)]);
    }

    void Window::deminiaturize(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) deminiaturize:cocoon::internal::native_id(sender)];
    }

    void Window::disable_cursor_rects() const
    {
        [cocoon::internal::ns<::NSWindow>(this) disableCursorRects];
    }

    void Window::disable_key_equivalent_for_default_button_cell() const
    {
        [cocoon::internal::ns<::NSWindow>(this) disableKeyEquivalentForDefaultButtonCell];
    }

    void Window::disable_snapshot_restoration() const
    {
        [cocoon::internal::ns<::NSWindow>(this) disableSnapshotRestoration];
    }

    void Window::discard_cursor_rects() const
    {
        [cocoon::internal::ns<::NSWindow>(this) discardCursorRects];
    }

    void Window::discard_events_matching_mask(EventMask mask, const Event& last_event) const
    {
        [cocoon::internal::ns<::NSWindow>(this) discardEventsMatchingMask:static_cast<::NSEventMask>(mask) beforeEvent:cocoon::internal::native<::NSEvent>(last_event)];
    }

    void Window::display() const
    {
        [cocoon::internal::ns<::NSWindow>(this) display];
    }

    void Window::display_if_needed() const
    {
        [cocoon::internal::ns<::NSWindow>(this) displayIfNeeded];
    }

    Object Window::display_link_with_target(const Object& target, const std::string& selector) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSWindow>(this) displayLinkWithTarget:cocoon::internal::native_id(target) selector:NSSelectorFromString(cocoon::internal::to(selector))]);
    }

    void Window::drag_image(const Image& image, const Point& base_location, const Size& initial_offset, const Event& event, const Pasteboard& pboard, const Object& source_obj, bool slide_flag) const
    {
        [cocoon::internal::ns<::NSWindow>(this) dragImage:cocoon::internal::native<::NSImage>(image) at:cocoon::internal::to(base_location) offset:cocoon::internal::to(initial_offset) event:cocoon::internal::native<::NSEvent>(event) pasteboard:cocoon::internal::native<::NSPasteboard>(pboard) source:cocoon::internal::native_id(source_obj) slideBack:static_cast<::BOOL>(slide_flag)];
    }

    void Window::enable_cursor_rects() const
    {
        [cocoon::internal::ns<::NSWindow>(this) enableCursorRects];
    }

    void Window::enable_key_equivalent_for_default_button_cell() const
    {
        [cocoon::internal::ns<::NSWindow>(this) enableKeyEquivalentForDefaultButtonCell];
    }

    void Window::enable_snapshot_restoration() const
    {
        [cocoon::internal::ns<::NSWindow>(this) enableSnapshotRestoration];
    }

    void Window::end_editing_for(const Object& object) const
    {
        [cocoon::internal::ns<::NSWindow>(this) endEditingFor:cocoon::internal::native_id(object)];
    }

    void Window::end_sheet(const Window& sheet_window, std::int64_t return_code) const
    {
        [cocoon::internal::ns<::NSWindow>(this) endSheet:cocoon::internal::native<::NSWindow>(sheet_window) returnCode:static_cast<::NSModalResponse>(return_code)];
    }

    Text Window::field_editor(bool create_flag, const Object& object) const
    {
        return cocoon::internal::wrap<Text>([cocoon::internal::ns<::NSWindow>(this) fieldEditor:static_cast<::BOOL>(create_flag) forObject:cocoon::internal::native_id(object)]);
    }

    Rect Window::frame_rect_for_content_rect(const Rect& content_rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) frameRectForContentRect:cocoon::internal::to(content_rect)]);
    }

    Rect Window::frame_rect_for_content_rect(const Rect& c_rect, WindowStyle style)
    {
        return cocoon::internal::from([::NSWindow frameRectForContentRect:cocoon::internal::to(c_rect) styleMask:static_cast<::NSWindowStyleMask>(style)]);
    }

    Object Window::handle_close_script_command(const CloseCommand& command) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSWindow>(this) handleCloseScriptCommand:cocoon::internal::native<::NSCloseCommand>(command)]);
    }

    Object Window::handle_print_script_command(const ScriptCommand& command) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSWindow>(this) handlePrintScriptCommand:cocoon::internal::native<::NSScriptCommand>(command)]);
    }

    Object Window::handle_save_script_command(const ScriptCommand& command) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSWindow>(this) handleSaveScriptCommand:cocoon::internal::native<::NSScriptCommand>(command)]);
    }

    void Window::insert_titlebar_accessory_view_controller(const TitlebarAccessoryViewController& child_view_controller, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSWindow>(this) insertTitlebarAccessoryViewController:cocoon::internal::native<::NSTitlebarAccessoryViewController>(child_view_controller) atIndex:static_cast<::NSInteger>(index)];
    }

    void Window::invalidate_cursor_rects_for_view(const View& view) const
    {
        [cocoon::internal::ns<::NSWindow>(this) invalidateCursorRectsForView:cocoon::internal::native<::NSView>(view)];
    }

    void Window::invalidate_shadow() const
    {
        [cocoon::internal::ns<::NSWindow>(this) invalidateShadow];
    }

    void Window::layout_if_needed() const
    {
        [cocoon::internal::ns<::NSWindow>(this) layoutIfNeeded];
    }

    bool Window::make_first_responder(const Responder& responder) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) makeFirstResponder:cocoon::internal::native<::NSResponder>(responder)]);
    }

    void Window::make_key_and_order_front(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) makeKeyAndOrderFront:cocoon::internal::native_id(sender)];
    }

    void Window::make_key_window() const
    {
        [cocoon::internal::ns<::NSWindow>(this) makeKeyWindow];
    }

    void Window::make_main_window() const
    {
        [cocoon::internal::ns<::NSWindow>(this) makeMainWindow];
    }

    void Window::merge_all_windows(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) mergeAllWindows:cocoon::internal::native_id(sender)];
    }

    double Window::min_frame_width_with_title(const std::string& title, WindowStyle style)
    {
        return static_cast<double>([::NSWindow minFrameWidthWithTitle:cocoon::internal::to(title) styleMask:static_cast<::NSWindowStyleMask>(style)]);
    }

    void Window::miniaturize(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) miniaturize:cocoon::internal::native_id(sender)];
    }

    void Window::move_tab_to_new_window(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) moveTabToNewWindow:cocoon::internal::native_id(sender)];
    }

    Event Window::next_event_matching_mask(EventMask mask) const
    {
        return cocoon::internal::wrap<Event>([cocoon::internal::ns<::NSWindow>(this) nextEventMatchingMask:static_cast<::NSEventMask>(mask)]);
    }

    Event Window::next_event_matching_mask(EventMask mask, const Date& expiration, const std::string& mode, bool deq_flag) const
    {
        return cocoon::internal::wrap<Event>([cocoon::internal::ns<::NSWindow>(this) nextEventMatchingMask:static_cast<::NSEventMask>(mask) untilDate:cocoon::internal::native<::NSDate>(expiration) inMode:cocoon::internal::to(mode) dequeue:static_cast<::BOOL>(deq_flag)]);
    }

    void Window::order_back(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) orderBack:cocoon::internal::native_id(sender)];
    }

    void Window::order_front(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) orderFront:cocoon::internal::native_id(sender)];
    }

    void Window::order_front_regardless() const
    {
        [cocoon::internal::ns<::NSWindow>(this) orderFrontRegardless];
    }

    void Window::order_out(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) orderOut:cocoon::internal::native_id(sender)];
    }

    void Window::order_window(WindowOrderingMode place, std::int64_t other_win) const
    {
        [cocoon::internal::ns<::NSWindow>(this) orderWindow:static_cast<::NSWindowOrderingMode>(place) relativeTo:static_cast<::NSInteger>(other_win)];
    }

    void Window::perform_close(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) performClose:cocoon::internal::native_id(sender)];
    }

    void Window::perform_miniaturize(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) performMiniaturize:cocoon::internal::native_id(sender)];
    }

    void Window::perform_window_drag_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSWindow>(this) performWindowDragWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void Window::perform_zoom(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) performZoom:cocoon::internal::native_id(sender)];
    }

    void Window::post_event(const Event& event, bool flag) const
    {
        [cocoon::internal::ns<::NSWindow>(this) postEvent:cocoon::internal::native<::NSEvent>(event) atStart:static_cast<::BOOL>(flag)];
    }

    void Window::print(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) print:cocoon::internal::native_id(sender)];
    }

    void Window::recalculate_key_view_loop() const
    {
        [cocoon::internal::ns<::NSWindow>(this) recalculateKeyViewLoop];
    }

    void Window::register_for_dragged_types(const std::vector<std::string>& new_types) const
    {
        [cocoon::internal::ns<::NSWindow>(this) registerForDraggedTypes:cocoon::internal::to_array(new_types, [](const std::string& e) -> id
                                                                                                   {
                                                                                                       return cocoon::internal::to(e);
                                                                                                   })];
    }

    void Window::remove_child_window(const Window& child_win) const
    {
        [cocoon::internal::ns<::NSWindow>(this) removeChildWindow:cocoon::internal::native<::NSWindow>(child_win)];
    }

    void Window::remove_frame_using_name(const std::string& name)
    {
        [::NSWindow removeFrameUsingName:cocoon::internal::to(name)];
    }

    void Window::remove_titlebar_accessory_view_controller_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSWindow>(this) removeTitlebarAccessoryViewControllerAtIndex:static_cast<::NSInteger>(index)];
    }

    void Window::request_sharing_of_window(const Window& window, std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSWindow>(this) requestSharingOfWindow:cocoon::internal::native<::NSWindow>(window) completionHandler:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a107_0) { completion_handler(cocoon::internal::wrap<Error>(a107_0)); } : (void (^)(::NSError*))nil)];
    }

    void Window::request_sharing_of_window_using_preview(const Image& image, const std::string& title, std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSWindow>(this) requestSharingOfWindowUsingPreview:cocoon::internal::native<::NSImage>(image) title:cocoon::internal::to(title) completionHandler:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a108_0) { completion_handler(cocoon::internal::wrap<Error>(a108_0)); } : (void (^)(::NSError*))nil)];
    }

    void Window::reset_cursor_rects() const
    {
        [cocoon::internal::ns<::NSWindow>(this) resetCursorRects];
    }

    void Window::resign_key_window() const
    {
        [cocoon::internal::ns<::NSWindow>(this) resignKeyWindow];
    }

    void Window::resign_main_window() const
    {
        [cocoon::internal::ns<::NSWindow>(this) resignMainWindow];
    }

    void Window::run_toolbar_customization_palette(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) runToolbarCustomizationPalette:cocoon::internal::native_id(sender)];
    }

    void Window::save_frame_using_name(const std::string& name) const
    {
        [cocoon::internal::ns<::NSWindow>(this) saveFrameUsingName:cocoon::internal::to(name)];
    }

    void Window::select_key_view_following_view(const View& view) const
    {
        [cocoon::internal::ns<::NSWindow>(this) selectKeyViewFollowingView:cocoon::internal::native<::NSView>(view)];
    }

    void Window::select_key_view_preceding_view(const View& view) const
    {
        [cocoon::internal::ns<::NSWindow>(this) selectKeyViewPrecedingView:cocoon::internal::native<::NSView>(view)];
    }

    void Window::select_next_key_view(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) selectNextKeyView:cocoon::internal::native_id(sender)];
    }

    void Window::select_next_tab(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) selectNextTab:cocoon::internal::native_id(sender)];
    }

    void Window::select_previous_key_view(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) selectPreviousKeyView:cocoon::internal::native_id(sender)];
    }

    void Window::select_previous_tab(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) selectPreviousTab:cocoon::internal::native_id(sender)];
    }

    void Window::send_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSWindow>(this) sendEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void Window::set_anchor_attribute(LayoutAttribute attr, ConstraintOrientation orientation) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setAnchorAttribute:static_cast<::NSLayoutAttribute>(attr) forOrientation:static_cast<::NSLayoutConstraintOrientation>(orientation)];
    }

    void Window::set_autorecalculates_content_border_thickness(bool flag, RectEdge edge) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setAutorecalculatesContentBorderThickness:static_cast<::BOOL>(flag) forEdge:static_cast<::NSRectEdge>(edge)];
    }

    void Window::set_content_border_thickness(double thickness, RectEdge edge) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setContentBorderThickness:static_cast<::CGFloat>(thickness) forEdge:static_cast<::NSRectEdge>(edge)];
    }

    void Window::set_content_size(const Size& size) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setContentSize:cocoon::internal::to(size)];
    }

    void Window::set_dynamic_depth_limit(bool flag) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setDynamicDepthLimit:static_cast<::BOOL>(flag)];
    }

    void Window::set_frame(const Rect& frame_rect, bool flag) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setFrame:cocoon::internal::to(frame_rect) display:static_cast<::BOOL>(flag)];
    }

    void Window::set_frame(const Rect& frame_rect, bool display_flag, bool animate_flag) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setFrame:cocoon::internal::to(frame_rect) display:static_cast<::BOOL>(display_flag) animate:static_cast<::BOOL>(animate_flag)];
    }

    bool Window::set_frame_autosave_name(const std::string& name) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) setFrameAutosaveName:cocoon::internal::to(name)]);
    }

    void Window::set_frame_from_string(const std::string& string) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setFrameFromString:cocoon::internal::to(string)];
    }

    void Window::set_frame_origin(const Point& point) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setFrameOrigin:cocoon::internal::to(point)];
    }

    void Window::set_frame_top_left_point(const Point& point) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setFrameTopLeftPoint:cocoon::internal::to(point)];
    }

    bool Window::set_frame_using_name(const std::string& name) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) setFrameUsingName:cocoon::internal::to(name)]);
    }

    bool Window::set_frame_using_name(const std::string& name, bool force) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) setFrameUsingName:cocoon::internal::to(name) force:static_cast<::BOOL>(force)]);
    }

    void Window::set_is_miniaturized(bool flag) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setIsMiniaturized:static_cast<::BOOL>(flag)];
    }

    void Window::set_is_visible(bool flag) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setIsVisible:static_cast<::BOOL>(flag)];
    }

    void Window::set_is_zoomed(bool flag) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setIsZoomed:static_cast<::BOOL>(flag)];
    }

    void Window::set_title_with_represented_filename(const std::string& filename) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setTitleWithRepresentedFilename:cocoon::internal::to(filename)];
    }

    Button Window::standard_window_button(WindowButton b) const
    {
        return cocoon::internal::wrap<Button>([cocoon::internal::ns<::NSWindow>(this) standardWindowButton:static_cast<::NSWindowButton>(b)]);
    }

    Button Window::standard_window_button(WindowButton b, WindowStyle style_mask)
    {
        return cocoon::internal::wrap<Button>([::NSWindow standardWindowButton:static_cast<::NSWindowButton>(b) forStyleMask:static_cast<::NSWindowStyleMask>(style_mask)]);
    }

    void Window::toggle_full_screen(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) toggleFullScreen:cocoon::internal::native_id(sender)];
    }

    void Window::toggle_tab_bar(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) toggleTabBar:cocoon::internal::native_id(sender)];
    }

    void Window::toggle_tab_overview(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) toggleTabOverview:cocoon::internal::native_id(sender)];
    }

    void Window::toggle_toolbar_shown(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) toggleToolbarShown:cocoon::internal::native_id(sender)];
    }

    void Window::track_events_matching_mask(EventMask mask, double timeout, const std::string& mode, std::function<void(Event, bool&)> tracking_handler) const
    {
        [cocoon::internal::ns<::NSWindow>(this) trackEventsMatchingMask:static_cast<::NSEventMask>(mask) timeout:static_cast<::NSTimeInterval>(timeout) mode:cocoon::internal::to(mode) handler:(tracking_handler ? (void (^)(::NSEvent*, BOOL*)) ^ void(::NSEvent * a109_0, ::BOOL * a109_1) { bool __o109_1 = a109_1 ? static_cast<bool>(*a109_1) : bool(); tracking_handler(cocoon::internal::wrap<Event>(a109_0), __o109_1); if (a109_1) { *a109_1 = static_cast<::BOOL>(__o109_1); } } : (void (^)(::NSEvent*, BOOL*))nil)];
    }

    void Window::transfer_window_sharing_to_window(const Window& window, std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSWindow>(this) transferWindowSharingToWindow:cocoon::internal::native<::NSWindow>(window) completionHandler:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a110_0) { completion_handler(cocoon::internal::wrap<Error>(a110_0)); } : (void (^)(::NSError*))nil)];
    }

    bool Window::try_to_perform(const std::string& action, const Object& object) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) tryToPerform:NSSelectorFromString(cocoon::internal::to(action)) with:cocoon::internal::native_id(object)]);
    }

    void Window::unregister_dragged_types() const
    {
        [cocoon::internal::ns<::NSWindow>(this) unregisterDraggedTypes];
    }

    void Window::update() const
    {
        [cocoon::internal::ns<::NSWindow>(this) update];
    }

    void Window::update_constraints_if_needed() const
    {
        [cocoon::internal::ns<::NSWindow>(this) updateConstraintsIfNeeded];
    }

    Object Window::valid_requestor_for_send_type(const std::string& send_type, const std::string& return_type) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSWindow>(this) validRequestorForSendType:cocoon::internal::to(send_type) returnType:cocoon::internal::to(return_type)]);
    }

    void Window::visualize_constraints(const std::vector<LayoutConstraint>& constraints) const
    {
        [cocoon::internal::ns<::NSWindow>(this) visualizeConstraints:cocoon::internal::to_array(constraints, [](const LayoutConstraint& e) -> id
                                                                                                {
                                                                                                    return cocoon::internal::native<::NSLayoutConstraint>(e);
                                                                                                })];
    }

    std::int64_t Window::window_number_at_point(const Point& point, std::int64_t window_number)
    {
        return static_cast<std::int64_t>([::NSWindow windowNumberAtPoint:cocoon::internal::to(point) belowWindowWithWindowNumber:static_cast<::NSInteger>(window_number)]);
    }

    std::vector<Number> Window::window_numbers_with_options(WindowNumberListOptions options)
    {
        return cocoon::internal::from_array<Number>([::NSWindow windowNumbersWithOptions:static_cast<::NSWindowNumberListOptions>(options)], [](id e) -> Number
                                                    {
                                                        return cocoon::internal::wrap<Number>((::NSNumber*)e);
                                                    });
    }

    void Window::zoom(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindow>(this) zoom:cocoon::internal::native_id(sender)];
    }

    bool Window::accepts_mouse_moved_events() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) acceptsMouseMovedEvents]);
    }

    void Window::set_accepts_mouse_moved_events(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setAcceptsMouseMovedEvents:static_cast<::BOOL>(value)];
    }

    bool Window::allows_automatic_window_tabbing()
    {
        return static_cast<bool>([::NSWindow allowsAutomaticWindowTabbing]);
    }

    void Window::set_allows_automatic_window_tabbing(bool value)
    {
        [::NSWindow setAllowsAutomaticWindowTabbing:static_cast<::BOOL>(value)];
    }

    bool Window::allows_concurrent_view_drawing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) allowsConcurrentViewDrawing]);
    }

    void Window::set_allows_concurrent_view_drawing(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setAllowsConcurrentViewDrawing:static_cast<::BOOL>(value)];
    }

    bool Window::allows_tool_tips_when_application_is_inactive() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) allowsToolTipsWhenApplicationIsInactive]);
    }

    void Window::set_allows_tool_tips_when_application_is_inactive(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setAllowsToolTipsWhenApplicationIsInactive:static_cast<::BOOL>(value)];
    }

    double Window::alpha_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSWindow>(this) alphaValue]);
    }

    void Window::set_alpha_value(double value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setAlphaValue:static_cast<::CGFloat>(value)];
    }

    WindowAnimationBehavior Window::animation_behavior() const
    {
        return static_cast<WindowAnimationBehavior>([cocoon::internal::ns<::NSWindow>(this) animationBehavior]);
    }

    void Window::set_animation_behavior(WindowAnimationBehavior value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setAnimationBehavior:static_cast<::NSWindowAnimationBehavior>(value)];
    }

    Object Window::appearance_source() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSWindow>(this) appearanceSource]);
    }

    void Window::set_appearance_source(const Object& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setAppearanceSource:cocoon::internal::native_id(value)];
    }

    bool Window::are_cursor_rects_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) areCursorRectsEnabled]);
    }

    Size Window::aspect_ratio() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) aspectRatio]);
    }

    void Window::set_aspect_ratio(const Size& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setAspectRatio:cocoon::internal::to(value)];
    }

    Window Window::attached_sheet() const
    {
        return cocoon::internal::wrap<Window>([cocoon::internal::ns<::NSWindow>(this) attachedSheet]);
    }

    bool Window::autorecalculates_key_view_loop() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) autorecalculatesKeyViewLoop]);
    }

    void Window::set_autorecalculates_key_view_loop(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setAutorecalculatesKeyViewLoop:static_cast<::BOOL>(value)];
    }

    Color Window::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSWindow>(this) backgroundColor]);
    }

    void Window::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    double Window::backing_scale_factor() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSWindow>(this) backingScaleFactor]);
    }

    BackingStoreType Window::backing_type() const
    {
        return static_cast<BackingStoreType>([cocoon::internal::ns<::NSWindow>(this) backingType]);
    }

    void Window::set_backing_type(BackingStoreType value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setBackingType:static_cast<::NSBackingStoreType>(value)];
    }

    bool Window::can_become_key_window() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) canBecomeKeyWindow]);
    }

    bool Window::can_become_main_window() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) canBecomeMainWindow]);
    }

    bool Window::can_become_visible_without_login() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) canBecomeVisibleWithoutLogin]);
    }

    void Window::set_can_become_visible_without_login(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setCanBecomeVisibleWithoutLogin:static_cast<::BOOL>(value)];
    }

    bool Window::can_hide() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) canHide]);
    }

    void Window::set_can_hide(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setCanHide:static_cast<::BOOL>(value)];
    }

    Rect Window::cascading_reference_frame() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) cascadingReferenceFrame]);
    }

    std::vector<Window> Window::child_windows() const
    {
        return cocoon::internal::from_array<Window>([cocoon::internal::ns<::NSWindow>(this) childWindows], [](id e) -> Window
                                                    {
                                                        return cocoon::internal::wrap<Window>((::NSWindow*)e);
                                                    });
    }

    WindowCollectionBehavior Window::collection_behavior() const
    {
        return static_cast<WindowCollectionBehavior>([cocoon::internal::ns<::NSWindow>(this) collectionBehavior]);
    }

    void Window::set_collection_behavior(WindowCollectionBehavior value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setCollectionBehavior:static_cast<::NSWindowCollectionBehavior>(value)];
    }

    ColorSpace Window::color_space() const
    {
        return cocoon::internal::wrap<ColorSpace>([cocoon::internal::ns<::NSWindow>(this) colorSpace]);
    }

    void Window::set_color_space(const ColorSpace& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setColorSpace:cocoon::internal::native<::NSColorSpace>(value)];
    }

    Size Window::content_aspect_ratio() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) contentAspectRatio]);
    }

    void Window::set_content_aspect_ratio(const Size& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setContentAspectRatio:cocoon::internal::to(value)];
    }

    Object Window::content_layout_guide() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSWindow>(this) contentLayoutGuide]);
    }

    Rect Window::content_layout_rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) contentLayoutRect]);
    }

    Size Window::content_max_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) contentMaxSize]);
    }

    void Window::set_content_max_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setContentMaxSize:cocoon::internal::to(value)];
    }

    Size Window::content_min_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) contentMinSize]);
    }

    void Window::set_content_min_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setContentMinSize:cocoon::internal::to(value)];
    }

    Size Window::content_resize_increments() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) contentResizeIncrements]);
    }

    void Window::set_content_resize_increments(const Size& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setContentResizeIncrements:cocoon::internal::to(value)];
    }

    View Window::content_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSWindow>(this) contentView]);
    }

    void Window::set_content_view(const View& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setContentView:cocoon::internal::native<::NSView>(value)];
    }

    ViewController Window::content_view_controller() const
    {
        return cocoon::internal::wrap<ViewController>([cocoon::internal::ns<::NSWindow>(this) contentViewController]);
    }

    void Window::set_content_view_controller(const ViewController& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setContentViewController:cocoon::internal::native<::NSViewController>(value)];
    }

    Event Window::current_event() const
    {
        return cocoon::internal::wrap<Event>([cocoon::internal::ns<::NSWindow>(this) currentEvent]);
    }

    Screen Window::deepest_screen() const
    {
        return cocoon::internal::wrap<Screen>([cocoon::internal::ns<::NSWindow>(this) deepestScreen]);
    }

    ButtonCell Window::default_button_cell() const
    {
        return cocoon::internal::wrap<ButtonCell>([cocoon::internal::ns<::NSWindow>(this) defaultButtonCell]);
    }

    void Window::set_default_button_cell(const ButtonCell& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setDefaultButtonCell:cocoon::internal::native<::NSButtonCell>(value)];
    }

    WindowDepth Window::default_depth_limit()
    {
        return static_cast<WindowDepth>([::NSWindow defaultDepthLimit]);
    }

    WindowDepth Window::depth_limit() const
    {
        return static_cast<WindowDepth>([cocoon::internal::ns<::NSWindow>(this) depthLimit]);
    }

    void Window::set_depth_limit(WindowDepth value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setDepthLimit:static_cast<::NSWindowDepth>(value)];
    }

    std::map<std::string, Object> Window::device_description() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSWindow>(this) deviceDescription], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    bool Window::displays_when_screen_profile_changes() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) displaysWhenScreenProfileChanges]);
    }

    void Window::set_displays_when_screen_profile_changes(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setDisplaysWhenScreenProfileChanges:static_cast<::BOOL>(value)];
    }

    DockTile Window::dock_tile() const
    {
        return cocoon::internal::wrap<DockTile>([cocoon::internal::ns<::NSWindow>(this) dockTile]);
    }

    bool Window::is_document_edited() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isDocumentEdited]);
    }

    void Window::set_document_edited(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setDocumentEdited:static_cast<::BOOL>(value)];
    }

    bool Window::is_excluded_from_windows_menu() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isExcludedFromWindowsMenu]);
    }

    void Window::set_excluded_from_windows_menu(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setExcludedFromWindowsMenu:static_cast<::BOOL>(value)];
    }

    Responder Window::first_responder() const
    {
        return cocoon::internal::wrap<Responder>([cocoon::internal::ns<::NSWindow>(this) firstResponder]);
    }

    bool Window::is_floating_panel() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isFloatingPanel]);
    }

    Rect Window::frame() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) frame]);
    }

    std::string Window::frame_autosave_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) frameAutosaveName]);
    }

    bool Window::has_active_window_sharing_session() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) hasActiveWindowSharingSession]);
    }

    bool Window::has_close_box() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) hasCloseBox]);
    }

    bool Window::has_dynamic_depth_limit() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) hasDynamicDepthLimit]);
    }

    bool Window::has_shadow() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) hasShadow]);
    }

    void Window::set_has_shadow(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setHasShadow:static_cast<::BOOL>(value)];
    }

    bool Window::has_title_bar() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) hasTitleBar]);
    }

    bool Window::hides_on_deactivate() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) hidesOnDeactivate]);
    }

    void Window::set_hides_on_deactivate(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setHidesOnDeactivate:static_cast<::BOOL>(value)];
    }

    bool Window::ignores_mouse_events() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) ignoresMouseEvents]);
    }

    void Window::set_ignores_mouse_events(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setIgnoresMouseEvents:static_cast<::BOOL>(value)];
    }

    bool Window::in_live_resize() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) inLiveResize]);
    }

    View Window::initial_first_responder() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSWindow>(this) initialFirstResponder]);
    }

    void Window::set_initial_first_responder(const View& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setInitialFirstResponder:cocoon::internal::native<::NSView>(value)];
    }

    SelectionDirection Window::key_view_selection_direction() const
    {
        return static_cast<SelectionDirection>([cocoon::internal::ns<::NSWindow>(this) keyViewSelectionDirection]);
    }

    bool Window::is_key_window() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isKeyWindow]);
    }

    std::int64_t Window::level() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSWindow>(this) level]);
    }

    void Window::set_level(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setLevel:static_cast<::NSWindowLevel>(value)];
    }

    bool Window::is_main_window() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isMainWindow]);
    }

    Size Window::max_full_screen_content_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) maxFullScreenContentSize]);
    }

    void Window::set_max_full_screen_content_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setMaxFullScreenContentSize:cocoon::internal::to(value)];
    }

    Size Window::max_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) maxSize]);
    }

    void Window::set_max_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setMaxSize:cocoon::internal::to(value)];
    }

    Size Window::min_full_screen_content_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) minFullScreenContentSize]);
    }

    void Window::set_min_full_screen_content_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setMinFullScreenContentSize:cocoon::internal::to(value)];
    }

    Size Window::min_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) minSize]);
    }

    void Window::set_min_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setMinSize:cocoon::internal::to(value)];
    }

    bool Window::is_miniaturizable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isMiniaturizable]);
    }

    bool Window::is_miniaturized() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isMiniaturized]);
    }

    Image Window::miniwindow_image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSWindow>(this) miniwindowImage]);
    }

    void Window::set_miniwindow_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setMiniwindowImage:cocoon::internal::native<::NSImage>(value)];
    }

    std::string Window::miniwindow_title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) miniwindowTitle]);
    }

    void Window::set_miniwindow_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setMiniwindowTitle:cocoon::internal::to(value)];
    }

    bool Window::is_modal_panel() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isModalPanel]);
    }

    Point Window::mouse_location_outside_of_event_stream() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) mouseLocationOutsideOfEventStream]);
    }

    bool Window::is_movable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isMovable]);
    }

    void Window::set_movable(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setMovable:static_cast<::BOOL>(value)];
    }

    bool Window::is_movable_by_window_background() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isMovableByWindowBackground]);
    }

    void Window::set_movable_by_window_background(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setMovableByWindowBackground:static_cast<::BOOL>(value)];
    }

    WindowOcclusionState Window::occlusion_state() const
    {
        return static_cast<WindowOcclusionState>([cocoon::internal::ns<::NSWindow>(this) occlusionState]);
    }

    bool Window::is_on_active_space() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isOnActiveSpace]);
    }

    bool Window::is_opaque() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isOpaque]);
    }

    void Window::set_opaque(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setOpaque:static_cast<::BOOL>(value)];
    }

    std::int64_t Window::ordered_index() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSWindow>(this) orderedIndex]);
    }

    void Window::set_ordered_index(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setOrderedIndex:static_cast<::NSInteger>(value)];
    }

    Window Window::parent_window() const
    {
        return cocoon::internal::wrap<Window>([cocoon::internal::ns<::NSWindow>(this) parentWindow]);
    }

    void Window::set_parent_window(const Window& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setParentWindow:cocoon::internal::native<::NSWindow>(value)];
    }

    bool Window::preserves_content_during_live_resize() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) preservesContentDuringLiveResize]);
    }

    void Window::set_preserves_content_during_live_resize(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setPreservesContentDuringLiveResize:static_cast<::BOOL>(value)];
    }

    bool Window::prevents_application_termination_when_modal() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) preventsApplicationTerminationWhenModal]);
    }

    void Window::set_prevents_application_termination_when_modal(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setPreventsApplicationTerminationWhenModal:static_cast<::BOOL>(value)];
    }

    bool Window::is_released_when_closed() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isReleasedWhenClosed]);
    }

    void Window::set_released_when_closed(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setReleasedWhenClosed:static_cast<::BOOL>(value)];
    }

    std::string Window::represented_filename() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) representedFilename]);
    }

    void Window::set_represented_filename(const std::string& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setRepresentedFilename:cocoon::internal::to(value)];
    }

    URL Window::represented_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSWindow>(this) representedURL]);
    }

    void Window::set_represented_url(const URL& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setRepresentedURL:cocoon::internal::native<::NSURL>(value)];
    }

    bool Window::is_resizable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isResizable]);
    }

    EventModifierFlags Window::resize_flags() const
    {
        return static_cast<EventModifierFlags>([cocoon::internal::ns<::NSWindow>(this) resizeFlags]);
    }

    Size Window::resize_increments() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) resizeIncrements]);
    }

    void Window::set_resize_increments(const Size& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setResizeIncrements:cocoon::internal::to(value)];
    }

    bool Window::is_restorable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isRestorable]);
    }

    void Window::set_restorable(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setRestorable:static_cast<::BOOL>(value)];
    }

    std::string Window::restoration_class() const
    {
        return cocoon::internal::from(NSStringFromClass([cocoon::internal::ns<::NSWindow>(this) restorationClass]));
    }

    void Window::set_restoration_class(const std::string& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setRestorationClass:NSClassFromString(cocoon::internal::to(value))];
    }

    Screen Window::screen() const
    {
        return cocoon::internal::wrap<Screen>([cocoon::internal::ns<::NSWindow>(this) screen]);
    }

    WindowSharingType Window::sharing_type() const
    {
        return static_cast<WindowSharingType>([cocoon::internal::ns<::NSWindow>(this) sharingType]);
    }

    void Window::set_sharing_type(WindowSharingType value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setSharingType:static_cast<::NSWindowSharingType>(value)];
    }

    bool Window::is_sheet() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isSheet]);
    }

    Window Window::sheet_parent() const
    {
        return cocoon::internal::wrap<Window>([cocoon::internal::ns<::NSWindow>(this) sheetParent]);
    }

    std::vector<Window> Window::sheets() const
    {
        return cocoon::internal::from_array<Window>([cocoon::internal::ns<::NSWindow>(this) sheets], [](id e) -> Window
                                                    {
                                                        return cocoon::internal::wrap<Window>((::NSWindow*)e);
                                                    });
    }

    bool Window::shows_toolbar_button() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) showsToolbarButton]);
    }

    void Window::set_shows_toolbar_button(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setShowsToolbarButton:static_cast<::BOOL>(value)];
    }

    std::string Window::string_with_saved_frame() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) stringWithSavedFrame]);
    }

    WindowStyle Window::style_mask() const
    {
        return static_cast<WindowStyle>([cocoon::internal::ns<::NSWindow>(this) styleMask]);
    }

    void Window::set_style_mask(WindowStyle value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setStyleMask:static_cast<::NSWindowStyleMask>(value)];
    }

    std::string Window::subtitle() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) subtitle]);
    }

    void Window::set_subtitle(const std::string& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setSubtitle:cocoon::internal::to(value)];
    }

    WindowTab Window::tab() const
    {
        return cocoon::internal::wrap<WindowTab>([cocoon::internal::ns<::NSWindow>(this) tab]);
    }

    WindowTabGroup Window::tab_group() const
    {
        return cocoon::internal::wrap<WindowTabGroup>([cocoon::internal::ns<::NSWindow>(this) tabGroup]);
    }

    std::vector<Window> Window::tabbed_windows() const
    {
        return cocoon::internal::from_array<Window>([cocoon::internal::ns<::NSWindow>(this) tabbedWindows], [](id e) -> Window
                                                    {
                                                        return cocoon::internal::wrap<Window>((::NSWindow*)e);
                                                    });
    }

    std::string Window::tabbing_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) tabbingIdentifier]);
    }

    void Window::set_tabbing_identifier(const std::string& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setTabbingIdentifier:cocoon::internal::to(value)];
    }

    WindowTabbingMode Window::tabbing_mode() const
    {
        return static_cast<WindowTabbingMode>([cocoon::internal::ns<::NSWindow>(this) tabbingMode]);
    }

    void Window::set_tabbing_mode(WindowTabbingMode value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setTabbingMode:static_cast<::NSWindowTabbingMode>(value)];
    }

    std::string Window::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindow>(this) title]);
    }

    void Window::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setTitle:cocoon::internal::to(value)];
    }

    TitleVisibility Window::title_visibility() const
    {
        return static_cast<TitleVisibility>([cocoon::internal::ns<::NSWindow>(this) titleVisibility]);
    }

    void Window::set_title_visibility(TitleVisibility value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setTitleVisibility:static_cast<::NSWindowTitleVisibility>(value)];
    }

    std::vector<TitlebarAccessoryViewController> Window::titlebar_accessory_view_controllers() const
    {
        return cocoon::internal::from_array<TitlebarAccessoryViewController>([cocoon::internal::ns<::NSWindow>(this) titlebarAccessoryViewControllers], [](id e) -> TitlebarAccessoryViewController
                                                                             {
                                                                                 return cocoon::internal::wrap<TitlebarAccessoryViewController>((::NSTitlebarAccessoryViewController*)e);
                                                                             });
    }

    void Window::set_titlebar_accessory_view_controllers(const std::vector<TitlebarAccessoryViewController>& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setTitlebarAccessoryViewControllers:cocoon::internal::to_array(value, [](const TitlebarAccessoryViewController& e) -> id
                                                                                                               {
                                                                                                                   return cocoon::internal::native<::NSTitlebarAccessoryViewController>(e);
                                                                                                               })];
    }

    bool Window::titlebar_appears_transparent() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) titlebarAppearsTransparent]);
    }

    void Window::set_titlebar_appears_transparent(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setTitlebarAppearsTransparent:static_cast<::BOOL>(value)];
    }

    TitlebarSeparatorStyle Window::titlebar_separator_style() const
    {
        return static_cast<TitlebarSeparatorStyle>([cocoon::internal::ns<::NSWindow>(this) titlebarSeparatorStyle]);
    }

    void Window::set_titlebar_separator_style(TitlebarSeparatorStyle value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setTitlebarSeparatorStyle:static_cast<::NSTitlebarSeparatorStyle>(value)];
    }

    Toolbar Window::toolbar() const
    {
        return cocoon::internal::wrap<Toolbar>([cocoon::internal::ns<::NSWindow>(this) toolbar]);
    }

    void Window::set_toolbar(const Toolbar& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setToolbar:cocoon::internal::native<::NSToolbar>(value)];
    }

    ToolbarStyle Window::toolbar_style() const
    {
        return static_cast<ToolbarStyle>([cocoon::internal::ns<::NSWindow>(this) toolbarStyle]);
    }

    void Window::set_toolbar_style(ToolbarStyle value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setToolbarStyle:static_cast<::NSWindowToolbarStyle>(value)];
    }

    WindowUserTabbingPreference Window::user_tabbing_preference()
    {
        return static_cast<WindowUserTabbingPreference>([::NSWindow userTabbingPreference]);
    }

    bool Window::views_need_display() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) viewsNeedDisplay]);
    }

    void Window::set_views_need_display(bool value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setViewsNeedDisplay:static_cast<::BOOL>(value)];
    }

    bool Window::is_visible() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isVisible]);
    }

    WindowController Window::window_controller() const
    {
        return cocoon::internal::wrap<WindowController>([cocoon::internal::ns<::NSWindow>(this) windowController]);
    }

    void Window::set_window_controller(const WindowController& value) const
    {
        [cocoon::internal::ns<::NSWindow>(this) setWindowController:cocoon::internal::native<::NSWindowController>(value)];
    }

    std::int64_t Window::window_number() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSWindow>(this) windowNumber]);
    }

    UserInterfaceLayoutDirection Window::window_titlebar_layout_direction() const
    {
        return static_cast<UserInterfaceLayoutDirection>([cocoon::internal::ns<::NSWindow>(this) windowTitlebarLayoutDirection]);
    }

    bool Window::works_when_modal() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) worksWhenModal]);
    }

    bool Window::is_zoomable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isZoomable]);
    }

    bool Window::is_zoomed() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindow>(this) isZoomed]);
    }

    void Window::show() const
    {
        cocoon::internal::show_window(cocoon::internal::ns<NSWindow>(this));
    }

    void Window::hide() const
    {
        [cocoon::internal::ns<NSWindow>(this) orderOut:nil];
    }

    void Window::close() const
    {
        [cocoon::internal::ns<NSWindow>(this) close];
    }

    void Window::center() const
    {
        [cocoon::internal::ns<NSWindow>(this) center];
    }

    void Window::minimize() const
    {
        [cocoon::internal::ns<NSWindow>(this) miniaturize:nil];
    }

    void Window::toggle_full_screen() const
    {
        [cocoon::internal::ns<NSWindow>(this) toggleFullScreen:nil];
    }

    void Window::raise() const
    {
        [cocoon::internal::ns<NSWindow>(this) makeKeyAndOrderFront:nil];
    }

    bool Window::is_full_screen() const
    {
        return (cocoon::internal::ns<NSWindow>(this).styleMask & NSWindowStyleMaskFullScreen) != 0;
    }

    void Window::set_content(const ViewController& controller) const
    {
        NSWindow* native = cocoon::internal::ns<NSWindow>(this);
        NSSize size = native.contentLayoutRect.size;
        native.contentViewController = cocoon::internal::native<NSViewController>(controller);
        [native setContentSize:size];
    }

    Size Window::size() const
    {
        NSWindow* native = cocoon::internal::ns<NSWindow>(this);
        return cocoon::internal::from([native contentRectForFrameRect:native.frame].size);
    }

    void Window::set_always_on_top(bool always_on_top) const
    {
        cocoon::internal::ns<NSWindow>(this).level = always_on_top ? NSFloatingWindowLevel : NSNormalWindowLevel;
    }

    void Window::begin_sheet(const Window& sheet, std::function<void()> on_finished) const
    {
        [cocoon::internal::ns<NSWindow>(this) beginSheet:cocoon::internal::native<NSWindow>(sheet)
                                       completionHandler:^(NSModalResponse) {
                                           if (on_finished)
                                           {
                                               on_finished();
                                           }
                                       }];
    }

    void Window::end_sheet(const Window& sheet) const
    {
        [cocoon::internal::ns<NSWindow>(this) endSheet:cocoon::internal::native<NSWindow>(sheet)];
    }

    void Window::install_delegate_delegate_(void* native)
    {
        ::NSWindow* host = (__bridge ::NSWindow*)native;
        AKWindowDelegate* delegate = [[AKWindowDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSWindow* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSWindow* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
