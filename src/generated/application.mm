#include "generated/application.h"
#include "internal.h"

@interface AKApplicationDelegate : NSObject <NSApplicationDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKApplicationDelegate

- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication*)sender
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Application, cocoon::ApplicationTerminateReply()>::emit((__bridge void*)strongHost, "should_terminate");
    return static_cast<::NSApplicationTerminateReply>(__r);
}

- (void)application:(NSApplication*)application openURLs:(NSArray<NSURL*>*)urls
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(std::vector<cocoon::URL>)>::emit((__bridge void*)strongHost, "open_urls", cocoon::internal::from_array<cocoon::URL>(urls, [](id e) -> cocoon::URL
                                                                                                                                                                 {
                                                                                                                                                                     return cocoon::internal::wrap<cocoon::URL>((::NSURL*)e);
                                                                                                                                                                 }));
}

- (BOOL)application:(NSApplication*)sender openFile:(NSString*)filename
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Application, bool(std::string)>::emit((__bridge void*)strongHost, "open_file", cocoon::internal::from(filename));
    return static_cast<::BOOL>(__r);
}

- (void)application:(NSApplication*)sender openFiles:(NSArray<NSString*>*)filenames
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(std::vector<std::string>)>::emit((__bridge void*)strongHost, "open_files", cocoon::internal::from_array<std::string>(filenames, [](id e) -> std::string
                                                                                                                                                                  {
                                                                                                                                                                      return cocoon::internal::from((NSString*)e);
                                                                                                                                                                  }));
}

- (BOOL)application:(NSApplication*)sender openTempFile:(NSString*)filename
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Application, bool(std::string)>::emit((__bridge void*)strongHost, "open_temp_file", cocoon::internal::from(filename));
    return static_cast<::BOOL>(__r);
}

- (BOOL)applicationShouldOpenUntitledFile:(NSApplication*)sender
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Application, bool()>::emit((__bridge void*)strongHost, "should_open_untitled_file");
    return static_cast<::BOOL>(__r);
}

- (BOOL)applicationOpenUntitledFile:(NSApplication*)sender
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Application, bool()>::emit((__bridge void*)strongHost, "open_untitled_file");
    return static_cast<::BOOL>(__r);
}

- (BOOL)application:(id)sender openFileWithoutUI:(NSString*)filename
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Application, bool(std::string)>::emit((__bridge void*)strongHost, "application_open_file_without_ui", cocoon::internal::from(filename));
    return static_cast<::BOOL>(__r);
}

- (BOOL)application:(NSApplication*)sender printFile:(NSString*)filename
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Application, bool(std::string)>::emit((__bridge void*)strongHost, "print_file", cocoon::internal::from(filename));
    return static_cast<::BOOL>(__r);
}

- (NSApplicationPrintReply)application:(NSApplication*)application printFiles:(NSArray<NSString*>*)fileNames withSettings:(NSDictionary<NSPrintInfoAttributeKey, id>*)printSettings showPrintPanels:(BOOL)showPrintPanels
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Application, cocoon::ApplicationPrintReply(std::vector<std::string>, std::map<std::string, cocoon::Object>, bool)>::emit((__bridge void*)strongHost, "print_files_with_settings_show_print_panels", cocoon::internal::from_array<std::string>(fileNames, [](id e) -> std::string
                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                        return cocoon::internal::from((NSString*)e);
                                                                                                                                                                                                                                                                                    }),
                                                                                                                                                               cocoon::internal::from_dictionary<std::map<std::string, cocoon::Object>>(printSettings, [](id k) -> std::string
                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                            return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                                        },
                                                                                                                                                                                                                                        [](id v) -> cocoon::Object
                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                            return cocoon::internal::wrap<cocoon::Object>(v);
                                                                                                                                                                                                                                        }),
                                                                                                                                                               static_cast<bool>(showPrintPanels));
    return static_cast<::NSApplicationPrintReply>(__r);
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)sender
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Application, bool()>::emit((__bridge void*)strongHost, "should_terminate_after_last_window_closed");
    return static_cast<::BOOL>(__r);
}

- (BOOL)applicationShouldHandleReopen:(NSApplication*)sender hasVisibleWindows:(BOOL)hasVisibleWindows
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Application, bool(bool)>::emit((__bridge void*)strongHost, "should_handle_reopen_has_visible_windows", static_cast<bool>(hasVisibleWindows));
    return static_cast<::BOOL>(__r);
}

- (NSMenu*)applicationDockMenu:(NSApplication*)sender
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Application, cocoon::Menu()>::emit((__bridge void*)strongHost, "dock_menu");
    return cocoon::internal::native<::NSMenu>(__r);
}

- (NSError*)application:(NSApplication*)application willPresentError:(NSError*)error
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Application, cocoon::Error(cocoon::Error)>::emit((__bridge void*)strongHost, "application_will_present_error", cocoon::internal::wrap<cocoon::Error>(error));
    return cocoon::internal::native<::NSError>(__r);
}

- (void)application:(NSApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(std::vector<std::uint8_t>)>::emit((__bridge void*)strongHost, "did_register_for_remote_notifications_with_device_token", cocoon::internal::from_data(deviceToken));
}

- (void)application:(NSApplication*)application didFailToRegisterForRemoteNotificationsWithError:(NSError*)error
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Error)>::emit((__bridge void*)strongHost, "did_fail_to_register_for_remote_notifications_with_error", cocoon::internal::wrap<cocoon::Error>(error));
}

- (void)application:(NSApplication*)application didReceiveRemoteNotification:(NSDictionary<NSString*, id>*)userInfo
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(std::map<std::string, cocoon::Object>)>::emit((__bridge void*)strongHost, "did_receive_remote_notification", cocoon::internal::from_dictionary<std::map<std::string, cocoon::Object>>(userInfo, [](id k) -> std::string
                                                                                                                                                                                                                                   {
                                                                                                                                                                                                                                       return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                                   },
                                                                                                                                                                                                                                   [](id v) -> cocoon::Object
                                                                                                                                                                                                                                   {
                                                                                                                                                                                                                                       return cocoon::internal::wrap<cocoon::Object>(v);
                                                                                                                                                                                                                                   }));
}

- (BOOL)applicationSupportsSecureRestorableState:(NSApplication*)app
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Application, bool()>::emit((__bridge void*)strongHost, "supports_secure_restorable_state");
    return static_cast<::BOOL>(__r);
}

- (id)application:(NSApplication*)application handlerForIntent:(INIntent*)intent
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Application, cocoon::Object(cocoon::Object)>::emit((__bridge void*)strongHost, "handler_for_intent", cocoon::internal::wrap<cocoon::Object>(intent));
    return cocoon::internal::native_id(__r);
}

- (void)application:(NSApplication*)app willEncodeRestorableState:(NSCoder*)coder
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Coder)>::emit((__bridge void*)strongHost, "will_encode_restorable_state", cocoon::internal::wrap<cocoon::Coder>(coder));
}

- (void)application:(NSApplication*)app didDecodeRestorableState:(NSCoder*)coder
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Coder)>::emit((__bridge void*)strongHost, "did_decode_restorable_state", cocoon::internal::wrap<cocoon::Coder>(coder));
}

- (BOOL)application:(NSApplication*)application willContinueUserActivityWithType:(NSString*)userActivityType
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Application, bool(std::string)>::emit((__bridge void*)strongHost, "will_continue_user_activity_with_type", cocoon::internal::from(userActivityType));
    return static_cast<::BOOL>(__r);
}

- (BOOL)application:(NSApplication*)application continueUserActivity:(NSUserActivity*)userActivity restorationHandler:(void (^)(NSArray<id<NSUserActivityRestoring>>*))restorationHandler
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Application, bool(cocoon::UserActivity, std::function<void(std::vector<cocoon::Object>)>)>::emit((__bridge void*)strongHost, "continue_user_activity_restoration_handler", cocoon::internal::wrap<cocoon::UserActivity>(userActivity), [&]() -> std::function<void(std::vector<cocoon::Object>)>
                                                                                                                                       {
                                                                                                                                           auto blk = (void (^)(NSArray<id<NSUserActivityRestoring>>*))(restorationHandler);
                                                                                                                                           if (!blk)
                                                                                                                                           {
                                                                                                                                               return {};
                                                                                                                                           }
                                                                                                                                           return [blk](std::vector<cocoon::Object> a281_0) -> void
                                                                                                                                           {
                                                                                                                                               blk(cocoon::internal::to_array(a281_0, [](const cocoon::Object& e) -> id
                                                                                                                                                                              {
                                                                                                                                                                                  return cocoon::internal::native_id(e);
                                                                                                                                                                              }));
                                                                                                                                           };
                                                                                                                                       }());
    return static_cast<::BOOL>(__r);
}

- (void)application:(NSApplication*)application didFailToContinueUserActivityWithType:(NSString*)userActivityType error:(NSError*)error
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(std::string, cocoon::Error)>::emit((__bridge void*)strongHost, "did_fail_to_continue_user_activity_with_type_error", cocoon::internal::from(userActivityType), cocoon::internal::wrap<cocoon::Error>(error));
}

- (void)application:(NSApplication*)application didUpdateUserActivity:(NSUserActivity*)userActivity
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::UserActivity)>::emit((__bridge void*)strongHost, "did_update_user_activity", cocoon::internal::wrap<cocoon::UserActivity>(userActivity));
}

- (void)application:(NSApplication*)application userDidAcceptCloudKitShareWithMetadata:(CKShareMetadata*)metadata
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Object)>::emit((__bridge void*)strongHost, "user_did_accept_cloud_kit_share_with_metadata", cocoon::internal::wrap<cocoon::Object>(metadata));
}

- (BOOL)application:(NSApplication*)sender delegateHandlesKey:(NSString*)key
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Application, bool(std::string)>::emit((__bridge void*)strongHost, "delegate_handles_key", cocoon::internal::from(key));
    return static_cast<::BOOL>(__r);
}

- (BOOL)applicationShouldAutomaticallyLocalizeKeyEquivalents:(NSApplication*)application
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Application, bool()>::emit((__bridge void*)strongHost, "should_automatically_localize_key_equivalents");
    return static_cast<::BOOL>(__r);
}

- (void)applicationWillFinishLaunching:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_finish_launching", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)applicationDidFinishLaunching:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_finish_launching", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)applicationWillHide:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_hide", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)applicationDidHide:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_hide", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)applicationWillUnhide:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_unhide", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)applicationDidUnhide:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_unhide", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)applicationWillBecomeActive:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_become_active", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)applicationDidBecomeActive:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_become_active", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)applicationWillResignActive:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_resign_active", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)applicationDidResignActive:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_resign_active", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)applicationWillUpdate:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_update", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)applicationDidUpdate:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_update", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)applicationWillTerminate:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_terminate", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)applicationDidChangeScreenParameters:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_change_screen_parameters", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)applicationDidChangeOcclusionState:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_change_occlusion_state", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)applicationProtectedDataWillBecomeUnavailable:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "protected_data_will_become_unavailable", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)applicationProtectedDataDidBecomeAvailable:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "protected_data_did_become_available", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(applicationShouldTerminate:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, cocoon::ApplicationTerminateReply()>::connected((__bridge void*)strongHost, "should_terminate");
    }
    if (selector == @selector(application:openURLs:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(std::vector<cocoon::URL>)>::connected((__bridge void*)strongHost, "open_urls");
    }
    if (selector == @selector(application:openFile:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, bool(std::string)>::connected((__bridge void*)strongHost, "open_file");
    }
    if (selector == @selector(application:openFiles:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(std::vector<std::string>)>::connected((__bridge void*)strongHost, "open_files");
    }
    if (selector == @selector(application:openTempFile:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, bool(std::string)>::connected((__bridge void*)strongHost, "open_temp_file");
    }
    if (selector == @selector(applicationShouldOpenUntitledFile:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, bool()>::connected((__bridge void*)strongHost, "should_open_untitled_file");
    }
    if (selector == @selector(applicationOpenUntitledFile:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, bool()>::connected((__bridge void*)strongHost, "open_untitled_file");
    }
    if (selector == @selector(application:openFileWithoutUI:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, bool(std::string)>::connected((__bridge void*)strongHost, "application_open_file_without_ui");
    }
    if (selector == @selector(application:printFile:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, bool(std::string)>::connected((__bridge void*)strongHost, "print_file");
    }
    if (selector == @selector(application:printFiles:withSettings:showPrintPanels:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, cocoon::ApplicationPrintReply(std::vector<std::string>, std::map<std::string, cocoon::Object>, bool)>::connected((__bridge void*)strongHost, "print_files_with_settings_show_print_panels");
    }
    if (selector == @selector(applicationShouldTerminateAfterLastWindowClosed:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, bool()>::connected((__bridge void*)strongHost, "should_terminate_after_last_window_closed");
    }
    if (selector == @selector(applicationShouldHandleReopen:hasVisibleWindows:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, bool(bool)>::connected((__bridge void*)strongHost, "should_handle_reopen_has_visible_windows");
    }
    if (selector == @selector(applicationDockMenu:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, cocoon::Menu()>::connected((__bridge void*)strongHost, "dock_menu");
    }
    if (selector == @selector(application:willPresentError:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, cocoon::Error(cocoon::Error)>::connected((__bridge void*)strongHost, "application_will_present_error");
    }
    if (selector == @selector(application:didRegisterForRemoteNotificationsWithDeviceToken:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(std::vector<std::uint8_t>)>::connected((__bridge void*)strongHost, "did_register_for_remote_notifications_with_device_token");
    }
    if (selector == @selector(application:didFailToRegisterForRemoteNotificationsWithError:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Error)>::connected((__bridge void*)strongHost, "did_fail_to_register_for_remote_notifications_with_error");
    }
    if (selector == @selector(application:didReceiveRemoteNotification:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(std::map<std::string, cocoon::Object>)>::connected((__bridge void*)strongHost, "did_receive_remote_notification");
    }
    if (selector == @selector(applicationSupportsSecureRestorableState:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, bool()>::connected((__bridge void*)strongHost, "supports_secure_restorable_state");
    }
    if (selector == @selector(application:handlerForIntent:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, cocoon::Object(cocoon::Object)>::connected((__bridge void*)strongHost, "handler_for_intent");
    }
    if (selector == @selector(application:willEncodeRestorableState:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Coder)>::connected((__bridge void*)strongHost, "will_encode_restorable_state");
    }
    if (selector == @selector(application:didDecodeRestorableState:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Coder)>::connected((__bridge void*)strongHost, "did_decode_restorable_state");
    }
    if (selector == @selector(application:willContinueUserActivityWithType:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, bool(std::string)>::connected((__bridge void*)strongHost, "will_continue_user_activity_with_type");
    }
    if (selector == @selector(application:continueUserActivity:restorationHandler:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, bool(cocoon::UserActivity, std::function<void(std::vector<cocoon::Object>)>)>::connected((__bridge void*)strongHost, "continue_user_activity_restoration_handler");
    }
    if (selector == @selector(application:didFailToContinueUserActivityWithType:error:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(std::string, cocoon::Error)>::connected((__bridge void*)strongHost, "did_fail_to_continue_user_activity_with_type_error");
    }
    if (selector == @selector(application:didUpdateUserActivity:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::UserActivity)>::connected((__bridge void*)strongHost, "did_update_user_activity");
    }
    if (selector == @selector(application:userDidAcceptCloudKitShareWithMetadata:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Object)>::connected((__bridge void*)strongHost, "user_did_accept_cloud_kit_share_with_metadata");
    }
    if (selector == @selector(application:delegateHandlesKey:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, bool(std::string)>::connected((__bridge void*)strongHost, "delegate_handles_key");
    }
    if (selector == @selector(applicationShouldAutomaticallyLocalizeKeyEquivalents:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, bool()>::connected((__bridge void*)strongHost, "should_automatically_localize_key_equivalents");
    }
    if (selector == @selector(applicationWillFinishLaunching:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_finish_launching");
    }
    if (selector == @selector(applicationDidFinishLaunching:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_finish_launching");
    }
    if (selector == @selector(applicationWillHide:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_hide");
    }
    if (selector == @selector(applicationDidHide:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_hide");
    }
    if (selector == @selector(applicationWillUnhide:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_unhide");
    }
    if (selector == @selector(applicationDidUnhide:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_unhide");
    }
    if (selector == @selector(applicationWillBecomeActive:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_become_active");
    }
    if (selector == @selector(applicationDidBecomeActive:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_become_active");
    }
    if (selector == @selector(applicationWillResignActive:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_resign_active");
    }
    if (selector == @selector(applicationDidResignActive:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_resign_active");
    }
    if (selector == @selector(applicationWillUpdate:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_update");
    }
    if (selector == @selector(applicationDidUpdate:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_update");
    }
    if (selector == @selector(applicationWillTerminate:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_terminate");
    }
    if (selector == @selector(applicationDidChangeScreenParameters:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_change_screen_parameters");
    }
    if (selector == @selector(applicationDidChangeOcclusionState:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_change_occlusion_state");
    }
    if (selector == @selector(applicationProtectedDataWillBecomeUnavailable:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "protected_data_will_become_unavailable");
    }
    if (selector == @selector(applicationProtectedDataDidBecomeAvailable:))
    {
        return strongHost && cocoon::Signal<cocoon::Application, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "protected_data_did_become_available");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    Application::Application(int argc, char** argv) : Application(Adopt{cocoon::internal::retain(cocoon::internal::make_application())})
    {
        Application::install_delegate_delegate_(handle());
        set_menu_bar(Menu::standard_menu_bar(ProcessInfo().process_name()));
    }

    Application::Application() : Application(Adopt{cocoon::internal::retain([[::NSApplication alloc] init])})
    {
        Application::install_delegate_delegate_(handle());
        set_menu_bar(Menu::standard_menu_bar(ProcessInfo().process_name()));
    }

    Application::Application(std::nullptr_t) : Responder(nullptr)
    {
    }

    Application::Application(Adopt adopt) : Responder(adopt)
    {
    }

    void Application::abort_modal() const
    {
        [cocoon::internal::ns<::NSApplication>(this) abortModal];
    }

    void Application::activate_context_help_mode(const Object& sender) const
    {
        [cocoon::internal::ns<::NSApplication>(this) activateContextHelpMode:cocoon::internal::native_id(sender)];
    }

    void Application::activate_ignoring_other_apps(bool ignore_other_apps) const
    {
        [cocoon::internal::ns<::NSApplication>(this) activateIgnoringOtherApps:static_cast<::BOOL>(ignore_other_apps)];
    }

    ActivationPolicy Application::activation_policy() const
    {
        return static_cast<ActivationPolicy>([cocoon::internal::ns<::NSApplication>(this) activationPolicy]);
    }

    void Application::add_windows_item(const Window& win, const std::string& string, bool is_filename) const
    {
        [cocoon::internal::ns<::NSApplication>(this) addWindowsItem:cocoon::internal::native<::NSWindow>(win) title:cocoon::internal::to(string) filename:static_cast<::BOOL>(is_filename)];
    }

    void Application::arrange_in_front(const Object& sender) const
    {
        [cocoon::internal::ns<::NSApplication>(this) arrangeInFront:cocoon::internal::native_id(sender)];
    }

    ModalSession Application::begin_modal_session_for_window(const Window& window) const
    {
        return cocoon::internal::wrap_cf<ModalSession>((const void*)([cocoon::internal::ns<::NSApplication>(this) beginModalSessionForWindow:cocoon::internal::native<::NSWindow>(window)]));
    }

    void Application::cancel_user_attention_request(std::int64_t request) const
    {
        [cocoon::internal::ns<::NSApplication>(this) cancelUserAttentionRequest:static_cast<::NSInteger>(request)];
    }

    void Application::change_windows_item(const Window& win, const std::string& string, bool is_filename) const
    {
        [cocoon::internal::ns<::NSApplication>(this) changeWindowsItem:cocoon::internal::native<::NSWindow>(win) title:cocoon::internal::to(string) filename:static_cast<::BOOL>(is_filename)];
    }

    void Application::complete_state_restoration() const
    {
        [cocoon::internal::ns<::NSApplication>(this) completeStateRestoration];
    }

    void Application::deactivate() const
    {
        [cocoon::internal::ns<::NSApplication>(this) deactivate];
    }

    void Application::detach_drawing_thread(const std::string& selector, const Object& target, const Object& argument)
    {
        [::NSApplication detachDrawingThread:NSSelectorFromString(cocoon::internal::to(selector)) toTarget:cocoon::internal::native_id(target) withObject:cocoon::internal::native_id(argument)];
    }

    void Application::disable_relaunch_on_login() const
    {
        [cocoon::internal::ns<::NSApplication>(this) disableRelaunchOnLogin];
    }

    void Application::discard_events_matching_mask(EventMask mask, const Event& last_event) const
    {
        [cocoon::internal::ns<::NSApplication>(this) discardEventsMatchingMask:static_cast<::NSEventMask>(mask) beforeEvent:cocoon::internal::native<::NSEvent>(last_event)];
    }

    void Application::enable_relaunch_on_login() const
    {
        [cocoon::internal::ns<::NSApplication>(this) enableRelaunchOnLogin];
    }

    void Application::end_modal_session(const ModalSession& session) const
    {
        [cocoon::internal::ns<::NSApplication>(this) endModalSession:((::NSModalSession)(session).handle())];
    }

    void Application::enumerate_windows_with_options(WindowListOptions options, std::function<void(Window, bool&)> block) const
    {
        [cocoon::internal::ns<::NSApplication>(this) enumerateWindowsWithOptions:static_cast<::NSWindowListOptions>(options) usingBlock:(block ? (void (^)(::NSWindow*, BOOL*)) ^ void(::NSWindow * a8_0, ::BOOL * a8_1) { bool __o8_1 = a8_1 ? static_cast<bool>(*a8_1) : bool(); block(cocoon::internal::wrap<Window>(a8_0), __o8_1); if (a8_1) { *a8_1 = static_cast<::BOOL>(__o8_1); } } : (void (^)(::NSWindow*, BOOL*))nil)];
    }

    void Application::extend_state_restoration() const
    {
        [cocoon::internal::ns<::NSApplication>(this) extendStateRestoration];
    }

    void Application::finish_launching() const
    {
        [cocoon::internal::ns<::NSApplication>(this) finishLaunching];
    }

    void Application::hide(const Object& sender) const
    {
        [cocoon::internal::ns<::NSApplication>(this) hide:cocoon::internal::native_id(sender)];
    }

    void Application::hide_other_applications(const Object& sender) const
    {
        [cocoon::internal::ns<::NSApplication>(this) hideOtherApplications:cocoon::internal::native_id(sender)];
    }

    void Application::miniaturize_all(const Object& sender) const
    {
        [cocoon::internal::ns<::NSApplication>(this) miniaturizeAll:cocoon::internal::native_id(sender)];
    }

    Event Application::next_event_matching_mask(EventMask mask, const Date& expiration, const std::string& mode, bool deq_flag) const
    {
        return cocoon::internal::wrap<Event>([cocoon::internal::ns<::NSApplication>(this) nextEventMatchingMask:static_cast<::NSEventMask>(mask) untilDate:cocoon::internal::native<::NSDate>(expiration) inMode:cocoon::internal::to(mode) dequeue:static_cast<::BOOL>(deq_flag)]);
    }

    void Application::order_front_character_palette(const Object& sender) const
    {
        [cocoon::internal::ns<::NSApplication>(this) orderFrontCharacterPalette:cocoon::internal::native_id(sender)];
    }

    void Application::order_front_color_panel(const Object& sender) const
    {
        [cocoon::internal::ns<::NSApplication>(this) orderFrontColorPanel:cocoon::internal::native_id(sender)];
    }

    void Application::order_front_standard_about_panel(const Object& sender) const
    {
        [cocoon::internal::ns<::NSApplication>(this) orderFrontStandardAboutPanel:cocoon::internal::native_id(sender)];
    }

    void Application::order_front_standard_about_panel_with_options(const std::map<std::string, Object>& options_dictionary) const
    {
        [cocoon::internal::ns<::NSApplication>(this) orderFrontStandardAboutPanelWithOptions:cocoon::internal::to_dictionary(options_dictionary, [](const std::string& k) -> id
                                                                                                                             {
                                                                                                                                 return cocoon::internal::to(k);
                                                                                                                             },
                                                                                                                             [](const Object& v) -> id
                                                                                                                             {
                                                                                                                                 return cocoon::internal::native_id(v);
                                                                                                                             })];
    }

    void Application::post_event(const Event& event, bool at_start) const
    {
        [cocoon::internal::ns<::NSApplication>(this) postEvent:cocoon::internal::native<::NSEvent>(event) atStart:static_cast<::BOOL>(at_start)];
    }

    void Application::prevent_window_ordering() const
    {
        [cocoon::internal::ns<::NSApplication>(this) preventWindowOrdering];
    }

    void Application::register_for_remote_notification_types(RemoteNotificationType types) const
    {
        [cocoon::internal::ns<::NSApplication>(this) registerForRemoteNotificationTypes:static_cast<::NSRemoteNotificationType>(types)];
    }

    void Application::register_for_remote_notifications() const
    {
        [cocoon::internal::ns<::NSApplication>(this) registerForRemoteNotifications];
    }

    void Application::register_services_menu_send_types(const std::vector<std::string>& send_types, const std::vector<std::string>& return_types) const
    {
        [cocoon::internal::ns<::NSApplication>(this) registerServicesMenuSendTypes:cocoon::internal::to_array(send_types, [](const std::string& e) -> id
                                                                                                              {
                                                                                                                  return cocoon::internal::to(e);
                                                                                                              })
                                                                       returnTypes:cocoon::internal::to_array(return_types, [](const std::string& e) -> id
                                                                                                              {
                                                                                                                  return cocoon::internal::to(e);
                                                                                                              })];
    }

    void Application::register_user_interface_item_search_handler(const Object& handler) const
    {
        [cocoon::internal::ns<::NSApplication>(this) registerUserInterfaceItemSearchHandler:cocoon::internal::native_id(handler)];
    }

    void Application::remove_windows_item(const Window& win) const
    {
        [cocoon::internal::ns<::NSApplication>(this) removeWindowsItem:cocoon::internal::native<::NSWindow>(win)];
    }

    void Application::reply_to_application_should_terminate(bool should_terminate) const
    {
        [cocoon::internal::ns<::NSApplication>(this) replyToApplicationShouldTerminate:static_cast<::BOOL>(should_terminate)];
    }

    void Application::reply_to_open_or_print(ApplicationDelegateReply reply) const
    {
        [cocoon::internal::ns<::NSApplication>(this) replyToOpenOrPrint:static_cast<::NSApplicationDelegateReply>(reply)];
    }

    void Application::report_exception(const Exception& exception) const
    {
        [cocoon::internal::ns<::NSApplication>(this) reportException:cocoon::internal::native<::NSException>(exception)];
    }

    std::int64_t Application::request_user_attention(RequestUserAttentionType request_type) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSApplication>(this) requestUserAttention:static_cast<::NSRequestUserAttentionType>(request_type)]);
    }

    bool Application::restore_window_with_identifier(const std::string& identifier, const Coder& state, std::function<void(Window, Error)> completion_handler) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSApplication>(this) restoreWindowWithIdentifier:cocoon::internal::to(identifier) state:cocoon::internal::native<::NSCoder>(state) completionHandler:(completion_handler ? (void (^)(::NSWindow*, ::NSError*)) ^ void(::NSWindow * a9_0, ::NSError * a9_1) { completion_handler(cocoon::internal::wrap<Window>(a9_0), cocoon::internal::wrap<Error>(a9_1)); } : (void (^)(::NSWindow*, ::NSError*))nil)]);
    }

    void Application::run() const
    {
        [cocoon::internal::ns<::NSApplication>(this) run];
    }

    std::int64_t Application::run_modal_for_window(const Window& window) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSApplication>(this) runModalForWindow:cocoon::internal::native<::NSWindow>(window)]);
    }

    std::int64_t Application::run_modal_session(const ModalSession& session) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSApplication>(this) runModalSession:((::NSModalSession)(session).handle())]);
    }

    void Application::run_page_layout(const Object& sender) const
    {
        [cocoon::internal::ns<::NSApplication>(this) runPageLayout:cocoon::internal::native_id(sender)];
    }

    bool Application::search_string(const std::string& search_string, const std::string& string_to_search, const Range& search_range, Range* found_range) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSApplication>(this) searchString:cocoon::internal::to(search_string) inUserInterfaceItemString:cocoon::internal::to(string_to_search) searchRange:cocoon::internal::to(search_range) foundRange:(::NSRange*)(found_range)]);
    }

    bool Application::send_action(const std::string& action, const Object& target, const Object& sender) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSApplication>(this) sendAction:NSSelectorFromString(cocoon::internal::to(action)) to:cocoon::internal::native_id(target) from:cocoon::internal::native_id(sender)]);
    }

    void Application::send_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSApplication>(this) sendEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    bool Application::set_activation_policy(ActivationPolicy activation_policy) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSApplication>(this) setActivationPolicy:static_cast<::NSApplicationActivationPolicy>(activation_policy)]);
    }

    void Application::set_windows_need_update(bool need_update) const
    {
        [cocoon::internal::ns<::NSApplication>(this) setWindowsNeedUpdate:static_cast<::BOOL>(need_update)];
    }

    void Application::show_help(const Object& sender) const
    {
        [cocoon::internal::ns<::NSApplication>(this) showHelp:cocoon::internal::native_id(sender)];
    }

    void Application::stop(const Object& sender) const
    {
        [cocoon::internal::ns<::NSApplication>(this) stop:cocoon::internal::native_id(sender)];
    }

    void Application::stop_modal() const
    {
        [cocoon::internal::ns<::NSApplication>(this) stopModal];
    }

    void Application::stop_modal_with_code(std::int64_t return_code) const
    {
        [cocoon::internal::ns<::NSApplication>(this) stopModalWithCode:static_cast<::NSModalResponse>(return_code)];
    }

    Object Application::target_for_action(const std::string& action) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSApplication>(this) targetForAction:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    Object Application::target_for_action(const std::string& action, const Object& target, const Object& sender) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSApplication>(this) targetForAction:NSSelectorFromString(cocoon::internal::to(action)) to:cocoon::internal::native_id(target) from:cocoon::internal::native_id(sender)]);
    }

    void Application::terminate(const Object& sender) const
    {
        [cocoon::internal::ns<::NSApplication>(this) terminate:cocoon::internal::native_id(sender)];
    }

    void Application::toggle_touch_bar_customization_palette(const Object& sender) const
    {
        [cocoon::internal::ns<::NSApplication>(this) toggleTouchBarCustomizationPalette:cocoon::internal::native_id(sender)];
    }

    bool Application::try_to_perform(const std::string& action, const Object& object) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSApplication>(this) tryToPerform:NSSelectorFromString(cocoon::internal::to(action)) with:cocoon::internal::native_id(object)]);
    }

    void Application::unhide(const Object& sender) const
    {
        [cocoon::internal::ns<::NSApplication>(this) unhide:cocoon::internal::native_id(sender)];
    }

    void Application::unhide_all_applications(const Object& sender) const
    {
        [cocoon::internal::ns<::NSApplication>(this) unhideAllApplications:cocoon::internal::native_id(sender)];
    }

    void Application::unhide_without_activation() const
    {
        [cocoon::internal::ns<::NSApplication>(this) unhideWithoutActivation];
    }

    void Application::unregister_for_remote_notifications() const
    {
        [cocoon::internal::ns<::NSApplication>(this) unregisterForRemoteNotifications];
    }

    void Application::unregister_user_interface_item_search_handler(const Object& handler) const
    {
        [cocoon::internal::ns<::NSApplication>(this) unregisterUserInterfaceItemSearchHandler:cocoon::internal::native_id(handler)];
    }

    void Application::update_windows() const
    {
        [cocoon::internal::ns<::NSApplication>(this) updateWindows];
    }

    void Application::update_windows_item(const Window& win) const
    {
        [cocoon::internal::ns<::NSApplication>(this) updateWindowsItem:cocoon::internal::native<::NSWindow>(win)];
    }

    Object Application::valid_requestor_for_send_type(const std::string& send_type, const std::string& return_type) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSApplication>(this) validRequestorForSendType:cocoon::internal::to(send_type) returnType:cocoon::internal::to(return_type)]);
    }

    Window Application::window_with_window_number(std::int64_t window_num) const
    {
        return cocoon::internal::wrap<Window>([cocoon::internal::ns<::NSApplication>(this) windowWithWindowNumber:static_cast<::NSInteger>(window_num)]);
    }

    void Application::yield_activation_to_application(const RunningApplication& application) const
    {
        [cocoon::internal::ns<::NSApplication>(this) yieldActivationToApplication:cocoon::internal::native<::NSRunningApplication>(application)];
    }

    void Application::yield_activation_to_application_with_bundle_identifier(const std::string& bundle_identifier) const
    {
        [cocoon::internal::ns<::NSApplication>(this) yieldActivationToApplicationWithBundleIdentifier:cocoon::internal::to(bundle_identifier)];
    }

    bool Application::is_active() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSApplication>(this) isActive]);
    }

    Appearance Application::appearance() const
    {
        return cocoon::internal::wrap<Appearance>([cocoon::internal::ns<::NSApplication>(this) appearance]);
    }

    void Application::set_appearance(const Appearance& value) const
    {
        [cocoon::internal::ns<::NSApplication>(this) setAppearance:cocoon::internal::native<::NSAppearance>(value)];
    }

    Image Application::application_icon_image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSApplication>(this) applicationIconImage]);
    }

    void Application::set_application_icon_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSApplication>(this) setApplicationIconImage:cocoon::internal::native<::NSImage>(value)];
    }

    bool Application::application_should_suppress_high_dynamic_range_content() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSApplication>(this) applicationShouldSuppressHighDynamicRangeContent]);
    }

    bool Application::is_automatic_customize_touch_bar_menu_item_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSApplication>(this) isAutomaticCustomizeTouchBarMenuItemEnabled]);
    }

    void Application::set_automatic_customize_touch_bar_menu_item_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSApplication>(this) setAutomaticCustomizeTouchBarMenuItemEnabled:static_cast<::BOOL>(value)];
    }

    Event Application::current_event() const
    {
        return cocoon::internal::wrap<Event>([cocoon::internal::ns<::NSApplication>(this) currentEvent]);
    }

    ApplicationPresentationOptions Application::current_system_presentation_options() const
    {
        return static_cast<ApplicationPresentationOptions>([cocoon::internal::ns<::NSApplication>(this) currentSystemPresentationOptions]);
    }

    DockTile Application::dock_tile() const
    {
        return cocoon::internal::wrap<DockTile>([cocoon::internal::ns<::NSApplication>(this) dockTile]);
    }

    Appearance Application::effective_appearance() const
    {
        return cocoon::internal::wrap<Appearance>([cocoon::internal::ns<::NSApplication>(this) effectiveAppearance]);
    }

    RemoteNotificationType Application::enabled_remote_notification_types() const
    {
        return static_cast<RemoteNotificationType>([cocoon::internal::ns<::NSApplication>(this) enabledRemoteNotificationTypes]);
    }

    bool Application::is_full_keyboard_access_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSApplication>(this) isFullKeyboardAccessEnabled]);
    }

    Menu Application::help_menu() const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSApplication>(this) helpMenu]);
    }

    void Application::set_help_menu(const Menu& value) const
    {
        [cocoon::internal::ns<::NSApplication>(this) setHelpMenu:cocoon::internal::native<::NSMenu>(value)];
    }

    bool Application::is_hidden() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSApplication>(this) isHidden]);
    }

    Window Application::key_window() const
    {
        return cocoon::internal::wrap<Window>([cocoon::internal::ns<::NSApplication>(this) keyWindow]);
    }

    Menu Application::main_menu() const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSApplication>(this) mainMenu]);
    }

    void Application::set_main_menu(const Menu& value) const
    {
        [cocoon::internal::ns<::NSApplication>(this) setMainMenu:cocoon::internal::native<::NSMenu>(value)];
    }

    Window Application::main_window() const
    {
        return cocoon::internal::wrap<Window>([cocoon::internal::ns<::NSApplication>(this) mainWindow]);
    }

    Window Application::modal_window() const
    {
        return cocoon::internal::wrap<Window>([cocoon::internal::ns<::NSApplication>(this) modalWindow]);
    }

    ApplicationOcclusionState Application::occlusion_state() const
    {
        return static_cast<ApplicationOcclusionState>([cocoon::internal::ns<::NSApplication>(this) occlusionState]);
    }

    std::vector<Document> Application::ordered_documents() const
    {
        return cocoon::internal::from_array<Document>([cocoon::internal::ns<::NSApplication>(this) orderedDocuments], [](id e) -> Document
                                                      {
                                                          return cocoon::internal::wrap<Document>((::NSDocument*)e);
                                                      });
    }

    std::vector<Window> Application::ordered_windows() const
    {
        return cocoon::internal::from_array<Window>([cocoon::internal::ns<::NSApplication>(this) orderedWindows], [](id e) -> Window
                                                    {
                                                        return cocoon::internal::wrap<Window>((::NSWindow*)e);
                                                    });
    }

    ApplicationPresentationOptions Application::presentation_options() const
    {
        return static_cast<ApplicationPresentationOptions>([cocoon::internal::ns<::NSApplication>(this) presentationOptions]);
    }

    void Application::set_presentation_options(ApplicationPresentationOptions value) const
    {
        [cocoon::internal::ns<::NSApplication>(this) setPresentationOptions:static_cast<::NSApplicationPresentationOptions>(value)];
    }

    bool Application::is_protected_data_available() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSApplication>(this) isProtectedDataAvailable]);
    }

    bool Application::is_registered_for_remote_notifications() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSApplication>(this) isRegisteredForRemoteNotifications]);
    }

    bool Application::is_running() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSApplication>(this) isRunning]);
    }

    Menu Application::services_menu() const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSApplication>(this) servicesMenu]);
    }

    void Application::set_services_menu(const Menu& value) const
    {
        [cocoon::internal::ns<::NSApplication>(this) setServicesMenu:cocoon::internal::native<::NSMenu>(value)];
    }

    Object Application::services_provider() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSApplication>(this) servicesProvider]);
    }

    void Application::set_services_provider(const Object& value) const
    {
        [cocoon::internal::ns<::NSApplication>(this) setServicesProvider:cocoon::internal::native_id(value)];
    }

    Application Application::shared_application()
    {
        return cocoon::internal::wrap<Application>([::NSApplication sharedApplication]);
    }

    UserInterfaceLayoutDirection Application::user_interface_layout_direction() const
    {
        return static_cast<UserInterfaceLayoutDirection>([cocoon::internal::ns<::NSApplication>(this) userInterfaceLayoutDirection]);
    }

    std::vector<Window> Application::windows() const
    {
        return cocoon::internal::from_array<Window>([cocoon::internal::ns<::NSApplication>(this) windows], [](id e) -> Window
                                                    {
                                                        return cocoon::internal::wrap<Window>((::NSWindow*)e);
                                                    });
    }

    Menu Application::windows_menu() const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSApplication>(this) windowsMenu]);
    }

    void Application::set_windows_menu(const Menu& value) const
    {
        [cocoon::internal::ns<::NSApplication>(this) setWindowsMenu:cocoon::internal::native<::NSMenu>(value)];
    }

    Application Application::instance()
    {
        return cocoon::internal::wrap<Application>(NSApp);
    }

    int Application::exec() const
    {
        [NSApp activate];
        [NSApp run];
        return 0;
    }

    void Application::quit() const
    {
        [NSApp terminate:nil];
    }

    void Application::activate() const
    {
        [NSApp activate];
    }

    void Application::hide() const
    {
        [NSApp hide:nil];
    }

    void Application::set_name(const std::string& name) const
    {
        NSProcessInfo.processInfo.processName = cocoon::internal::to(name);
    }

    void Application::set_dock_badge(const std::string& badge) const
    {
        NSApp.dockTile.badgeLabel = cocoon::internal::to(badge);
    }

    void Application::set_menu_bar(const Menu& menu) const
    {
        NSMenu* native = cocoon::internal::native<NSMenu>(menu);
        NSApp.mainMenu = native;
        for (NSMenuItem* item in native.itemArray)
        {
            if ([item.title isEqualToString:@"Window"] && item.submenu)
            {
                NSApp.windowsMenu = item.submenu;
            }
            if ([item.title isEqualToString:@"Help"] && item.submenu)
            {
                NSApp.helpMenu = item.submenu;
            }
        }
    }

    void Application::post_to_main_thread(std::function<void()> function)
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            function();
        });
    }

    void Application::single_shot(double seconds, std::function<void()> function)
    {
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, static_cast<int64_t>(seconds * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            function();
        });
    }

    void Application::install_delegate_delegate_(void* native)
    {
        ::NSApplication* host = (__bridge ::NSApplication*)native;
        AKApplicationDelegate* delegate = [[AKApplicationDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSApplication* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSApplication* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
