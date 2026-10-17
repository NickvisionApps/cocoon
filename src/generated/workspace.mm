#include "generated/workspace.h"
#include "internal.h"

namespace cocoon
{
    Workspace::Workspace() : Workspace(Adopt{cocoon::internal::retain([[::NSWorkspace alloc] init])})
    {
    }

    Workspace::Workspace(std::nullptr_t) : Object(nullptr)
    {
    }

    Workspace::Workspace(Adopt adopt) : Object(adopt)
    {
    }

    URL Workspace::url_for_application_to_open_content_type(const Object& content_type) const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSWorkspace>(this) URLForApplicationToOpenContentType:cocoon::internal::native_id(content_type)]);
    }

    URL Workspace::url_for_application_to_open_url(const URL& url) const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSWorkspace>(this) URLForApplicationToOpenURL:cocoon::internal::native<::NSURL>(url)]);
    }

    URL Workspace::url_for_application_with_bundle_identifier(const std::string& bundle_identifier) const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSWorkspace>(this) URLForApplicationWithBundleIdentifier:cocoon::internal::to(bundle_identifier)]);
    }

    std::vector<URL> Workspace::ur_ls_for_applications_to_open_content_type(const Object& content_type) const
    {
        return cocoon::internal::from_array<URL>([cocoon::internal::ns<::NSWorkspace>(this) URLsForApplicationsToOpenContentType:cocoon::internal::native_id(content_type)], [](id e) -> URL
                                                 {
                                                     return cocoon::internal::wrap<URL>((::NSURL*)e);
                                                 });
    }

    std::vector<URL> Workspace::ur_ls_for_applications_to_open_url(const URL& url) const
    {
        return cocoon::internal::from_array<URL>([cocoon::internal::ns<::NSWorkspace>(this) URLsForApplicationsToOpenURL:cocoon::internal::native<::NSURL>(url)], [](id e) -> URL
                                                 {
                                                     return cocoon::internal::wrap<URL>((::NSURL*)e);
                                                 });
    }

    std::vector<URL> Workspace::ur_ls_for_applications_with_bundle_identifier(const std::string& bundle_identifier) const
    {
        return cocoon::internal::from_array<URL>([cocoon::internal::ns<::NSWorkspace>(this) URLsForApplicationsWithBundleIdentifier:cocoon::internal::to(bundle_identifier)], [](id e) -> URL
                                                 {
                                                     return cocoon::internal::wrap<URL>((::NSURL*)e);
                                                 });
    }

    void Workspace::activate_file_viewer_selecting_urls(const std::vector<URL>& file_urls) const
    {
        [cocoon::internal::ns<::NSWorkspace>(this) activateFileViewerSelectingURLs:cocoon::internal::to_array(file_urls, [](const URL& e) -> id
                                                                                                              {
                                                                                                                  return cocoon::internal::native<::NSURL>(e);
                                                                                                              })];
    }

    std::map<std::string, Object> Workspace::desktop_image_options_for_screen(const Screen& screen) const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSWorkspace>(this) desktopImageOptionsForScreen:cocoon::internal::native<::NSScreen>(screen)], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    URL Workspace::desktop_image_url_for_screen(const Screen& screen) const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSWorkspace>(this) desktopImageURLForScreen:cocoon::internal::native<::NSScreen>(screen)]);
    }

    void Workspace::duplicate_urls(const std::vector<URL>& urls, std::function<void(std::vector<std::pair<URL, URL>>, Error)> handler) const
    {
        [cocoon::internal::ns<::NSWorkspace>(this) duplicateURLs:cocoon::internal::to_array(urls, [](const URL& e) -> id
                                                                                            {
                                                                                                return cocoon::internal::native<::NSURL>(e);
                                                                                            })
                                               completionHandler:(handler ? (void (^)(NSDictionary<NSURL*, NSURL*>*, ::NSError*)) ^ void(NSDictionary * a111_0, ::NSError * a111_1) { handler(cocoon::internal::from_dictionary<std::vector<std::pair<URL, URL>>>(a111_0, [](id k) -> URL
                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                      return cocoon::internal::wrap<URL>((::NSURL*)k);
                                                                                                                                                                                                                                                                  },
                                                                                                                                                                                                                                                                  [](id v) -> URL
                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                      return cocoon::internal::wrap<URL>((::NSURL*)v);
                                                                                                                                                                                                                                                                  }),
                                                                                                                                                                                              cocoon::internal::wrap<Error>(a111_1)); } : (void (^)(NSDictionary<NSURL*, NSURL*>*, ::NSError*))nil)];
    }

    std::int64_t Workspace::extend_power_off_by(std::int64_t requested) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSWorkspace>(this) extendPowerOffBy:static_cast<::NSInteger>(requested)]);
    }

    bool Workspace::get_file_system_info_for_path(const std::string& full_path, bool* removable_flag, bool* writable_flag, bool* unmountable_flag, std::string& description, std::string& file_system_type) const
    {
        NSString* __v_description = nil;
        NSString* __v_file_system_type = nil;
        auto __r = [cocoon::internal::ns<::NSWorkspace>(this) getFileSystemInfoForPath:cocoon::internal::to(full_path) isRemovable:(BOOL*)(removable_flag)isWritable:(BOOL*)(writable_flag)isUnmountable:(BOOL*)(unmountable_flag)description:&__v_description type:&__v_file_system_type];
        description = cocoon::internal::from(__v_description);
        file_system_type = cocoon::internal::from(__v_file_system_type);
        return static_cast<bool>(__r);
    }

    void Workspace::hide_other_applications() const
    {
        [cocoon::internal::ns<::NSWorkspace>(this) hideOtherApplications];
    }

    Image Workspace::icon_for_content_type(const Object& content_type) const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSWorkspace>(this) iconForContentType:cocoon::internal::native_id(content_type)]);
    }

    Image Workspace::icon_for_file(const std::string& full_path) const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSWorkspace>(this) iconForFile:cocoon::internal::to(full_path)]);
    }

    Image Workspace::icon_for_files(const std::vector<std::string>& full_paths) const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSWorkspace>(this) iconForFiles:cocoon::internal::to_array(full_paths, [](const std::string& e) -> id
                                                                                                                                {
                                                                                                                                    return cocoon::internal::to(e);
                                                                                                                                })]);
    }

    bool Workspace::is_file_package_at_path(const std::string& full_path) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspace>(this) isFilePackageAtPath:cocoon::internal::to(full_path)]);
    }

    void Workspace::note_file_system_changed(const std::string& path) const
    {
        [cocoon::internal::ns<::NSWorkspace>(this) noteFileSystemChanged:cocoon::internal::to(path)];
    }

    void Workspace::open_application_at_url(const URL& application_url, const WorkspaceOpenConfiguration& configuration, std::function<void(RunningApplication, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSWorkspace>(this) openApplicationAtURL:cocoon::internal::native<::NSURL>(application_url) configuration:cocoon::internal::native<::NSWorkspaceOpenConfiguration>(configuration) completionHandler:(completion_handler ? (void (^)(::NSRunningApplication*, ::NSError*)) ^ void(::NSRunningApplication * a112_0, ::NSError * a112_1) { completion_handler(cocoon::internal::wrap<RunningApplication>(a112_0), cocoon::internal::wrap<Error>(a112_1)); } : (void (^)(::NSRunningApplication*, ::NSError*))nil)];
    }

    bool Workspace::open_url(const URL& url) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspace>(this) openURL:cocoon::internal::native<::NSURL>(url)]);
    }

    void Workspace::open_url(const URL& url, const WorkspaceOpenConfiguration& configuration, std::function<void(RunningApplication, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSWorkspace>(this) openURL:cocoon::internal::native<::NSURL>(url) configuration:cocoon::internal::native<::NSWorkspaceOpenConfiguration>(configuration) completionHandler:(completion_handler ? (void (^)(::NSRunningApplication*, ::NSError*)) ^ void(::NSRunningApplication * a113_0, ::NSError * a113_1) { completion_handler(cocoon::internal::wrap<RunningApplication>(a113_0), cocoon::internal::wrap<Error>(a113_1)); } : (void (^)(::NSRunningApplication*, ::NSError*))nil)];
    }

    void Workspace::open_urls(const std::vector<URL>& urls, const URL& application_url, const WorkspaceOpenConfiguration& configuration, std::function<void(RunningApplication, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSWorkspace>(this) openURLs:cocoon::internal::to_array(urls, [](const URL& e) -> id
                                                                                       {
                                                                                           return cocoon::internal::native<::NSURL>(e);
                                                                                       })
                                       withApplicationAtURL:cocoon::internal::native<::NSURL>(application_url)
                                              configuration:cocoon::internal::native<::NSWorkspaceOpenConfiguration>(configuration)
                                          completionHandler:(completion_handler ? (void (^)(::NSRunningApplication*, ::NSError*)) ^ void(::NSRunningApplication * a114_0, ::NSError * a114_1) { completion_handler(cocoon::internal::wrap<RunningApplication>(a114_0), cocoon::internal::wrap<Error>(a114_1)); } : (void (^)(::NSRunningApplication*, ::NSError*))nil)];
    }

    void Workspace::recycle_urls(const std::vector<URL>& urls, std::function<void(std::vector<std::pair<URL, URL>>, Error)> handler) const
    {
        [cocoon::internal::ns<::NSWorkspace>(this) recycleURLs:cocoon::internal::to_array(urls, [](const URL& e) -> id
                                                                                          {
                                                                                              return cocoon::internal::native<::NSURL>(e);
                                                                                          })
                                             completionHandler:(handler ? (void (^)(NSDictionary<NSURL*, NSURL*>*, ::NSError*)) ^ void(NSDictionary * a115_0, ::NSError * a115_1) { handler(cocoon::internal::from_dictionary<std::vector<std::pair<URL, URL>>>(a115_0, [](id k) -> URL
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                    return cocoon::internal::wrap<URL>((::NSURL*)k);
                                                                                                                                                                                                                                                                },
                                                                                                                                                                                                                                                                [](id v) -> URL
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                    return cocoon::internal::wrap<URL>((::NSURL*)v);
                                                                                                                                                                                                                                                                }),
                                                                                                                                                                                            cocoon::internal::wrap<Error>(a115_1)); } : (void (^)(NSDictionary<NSURL*, NSURL*>*, ::NSError*))nil)];
    }

    void Workspace::request_authorization_of_type(WorkspaceAuthorizationType type, std::function<void(WorkspaceAuthorization, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSWorkspace>(this) requestAuthorizationOfType:static_cast<::NSWorkspaceAuthorizationType>(type) completionHandler:(completion_handler ? (void (^)(::NSWorkspaceAuthorization*, ::NSError*)) ^ void(::NSWorkspaceAuthorization * a116_0, ::NSError * a116_1) { completion_handler(cocoon::internal::wrap<WorkspaceAuthorization>(a116_0), cocoon::internal::wrap<Error>(a116_1)); } : (void (^)(::NSWorkspaceAuthorization*, ::NSError*))nil)];
    }

    bool Workspace::select_file(const std::string& full_path, const std::string& root_full_path) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspace>(this) selectFile:cocoon::internal::to(full_path) inFileViewerRootedAtPath:cocoon::internal::to(root_full_path)]);
    }

    void Workspace::set_default_application_at_url(const URL& application_url, const Object& content_type, std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSWorkspace>(this) setDefaultApplicationAtURL:cocoon::internal::native<::NSURL>(application_url) toOpenContentType:cocoon::internal::native_id(content_type) completionHandler:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a117_0) { completion_handler(cocoon::internal::wrap<Error>(a117_0)); } : (void (^)(::NSError*))nil)];
    }

    void Workspace::set_default_application_at_url(const URL& application_url, const URL& url, std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSWorkspace>(this) setDefaultApplicationAtURL:cocoon::internal::native<::NSURL>(application_url) toOpenContentTypeOfFileAtURL:cocoon::internal::native<::NSURL>(url) completionHandler:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a118_0) { completion_handler(cocoon::internal::wrap<Error>(a118_0)); } : (void (^)(::NSError*))nil)];
    }

    void Workspace::set_default_application_at_url(const URL& application_url, const std::string& url_scheme, std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSWorkspace>(this) setDefaultApplicationAtURL:cocoon::internal::native<::NSURL>(application_url) toOpenURLsWithScheme:cocoon::internal::to(url_scheme) completionHandler:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a120_0) { completion_handler(cocoon::internal::wrap<Error>(a120_0)); } : (void (^)(::NSError*))nil)];
    }

    bool Workspace::set_desktop_image_url(const URL& url, const Screen& screen, const std::map<std::string, Object>& options) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSWorkspace>(this) setDesktopImageURL:cocoon::internal::native<::NSURL>(url)
                                                                       forScreen:cocoon::internal::native<::NSScreen>(screen)
                                                                         options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                 {
                                                                                                                     return cocoon::internal::to(k);
                                                                                                                 },
                                                                                                                 [](const Object& v) -> id
                                                                                                                 {
                                                                                                                     return cocoon::internal::native_id(v);
                                                                                                                 })
                                                                           error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool Workspace::set_icon(const Image& image, const std::string& full_path, WorkspaceIconCreationOptions options) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspace>(this) setIcon:cocoon::internal::native<::NSImage>(image) forFile:cocoon::internal::to(full_path) options:static_cast<::NSWorkspaceIconCreationOptions>(options)]);
    }

    bool Workspace::show_search_results_for_query_string(const std::string& query_string) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspace>(this) showSearchResultsForQueryString:cocoon::internal::to(query_string)]);
    }

    bool Workspace::unmount_and_eject_device_at_path(const std::string& path) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspace>(this) unmountAndEjectDeviceAtPath:cocoon::internal::to(path)]);
    }

    bool Workspace::unmount_and_eject_device_at_url(const URL& url) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSWorkspace>(this) unmountAndEjectDeviceAtURL:cocoon::internal::native<::NSURL>(url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool Workspace::accessibility_display_should_differentiate_without_color() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspace>(this) accessibilityDisplayShouldDifferentiateWithoutColor]);
    }

    bool Workspace::accessibility_display_should_increase_contrast() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspace>(this) accessibilityDisplayShouldIncreaseContrast]);
    }

    bool Workspace::accessibility_display_should_invert_colors() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspace>(this) accessibilityDisplayShouldInvertColors]);
    }

    bool Workspace::accessibility_display_should_reduce_motion() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspace>(this) accessibilityDisplayShouldReduceMotion]);
    }

    bool Workspace::accessibility_display_should_reduce_transparency() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspace>(this) accessibilityDisplayShouldReduceTransparency]);
    }

    std::vector<Color> Workspace::file_label_colors() const
    {
        return cocoon::internal::from_array<Color>([cocoon::internal::ns<::NSWorkspace>(this) fileLabelColors], [](id e) -> Color
                                                   {
                                                       return cocoon::internal::wrap<Color>((::NSColor*)e);
                                                   });
    }

    std::vector<std::string> Workspace::file_labels() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSWorkspace>(this) fileLabels], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    RunningApplication Workspace::frontmost_application() const
    {
        return cocoon::internal::wrap<RunningApplication>([cocoon::internal::ns<::NSWorkspace>(this) frontmostApplication]);
    }

    RunningApplication Workspace::menu_bar_owning_application() const
    {
        return cocoon::internal::wrap<RunningApplication>([cocoon::internal::ns<::NSWorkspace>(this) menuBarOwningApplication]);
    }

    NotificationCenter Workspace::notification_center() const
    {
        return cocoon::internal::wrap<NotificationCenter>([cocoon::internal::ns<::NSWorkspace>(this) notificationCenter]);
    }

    std::vector<RunningApplication> Workspace::running_applications() const
    {
        return cocoon::internal::from_array<RunningApplication>([cocoon::internal::ns<::NSWorkspace>(this) runningApplications], [](id e) -> RunningApplication
                                                                {
                                                                    return cocoon::internal::wrap<RunningApplication>((::NSRunningApplication*)e);
                                                                });
    }

    Workspace Workspace::shared_workspace()
    {
        return cocoon::internal::wrap<Workspace>([::NSWorkspace sharedWorkspace]);
    }

    bool Workspace::is_switch_control_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspace>(this) isSwitchControlEnabled]);
    }

    bool Workspace::is_voice_over_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspace>(this) isVoiceOverEnabled]);
    }
}
