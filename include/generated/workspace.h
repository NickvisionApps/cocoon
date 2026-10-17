#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class Error;
    class Image;
    class NotificationCenter;
    class RunningApplication;
    class Screen;
    class URL;
    class WorkspaceAuthorization;
    class WorkspaceOpenConfiguration;

    /**
     * @brief C++ handle for the Objective-C class `NSWorkspace` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Workspace workspace;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Workspace workspace{};
     * workspace.url_for_application_to_open_url(cocoon::URL());
     * workspace.url_for_application_with_bundle_identifier("text");
     * workspace.ur_ls_for_applications_to_open_url(cocoon::URL());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsworkspace
     */
    class Workspace : public Object
    {
    public:
        /// @brief Creates a new `NSWorkspace` instance and returns a handle to it.
        explicit Workspace();
        /// @brief Creates a null handle that refers to no native object.
        Workspace(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Workspace(Adopt adopt);
        /**
     * @brief Calls `-[NSWorkspace URLForApplicationToOpenContentType:]`.
     * @details Returns the URL to the default application that would be used to open the given URL, as if the file were double clicked in the Finder. This returns nil if no app can open it.
     * @param content_type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_for_application_to_open_content_type(const Object& content_type) const;
        /**
     * @brief Calls `-[NSWorkspace URLForApplicationToOpenURL:]`.
     * @details Returns the URL to the default application that would be used to open the given URL, as if the file were double clicked in the Finder (for file URLs). This returns nil if no app can open it, or if the file does not exist.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_for_application_to_open_url(const URL& url) const;
        /**
     * @brief Calls `-[NSWorkspace URLForApplicationWithBundleIdentifier:]`.
     * @details Get the URL for the application with the given identifier. This uses various heuristics in case multiple apps have the same bundle ID. This returns nil if no app has the bundle identifier.
     * @param bundle_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_for_application_with_bundle_identifier(const std::string& bundle_identifier) const;
        /**
     * @brief Calls `-[NSWorkspace URLsForApplicationsToOpenContentType:]`.
     * @details Returns URLs to all available applications that can open the given UTType. The system sorts the resulting array based on each application's suitability to open the given UTType. The first application is considered the best available match. This returns the empty array if no app can open it.
     * @param content_type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<URL> ur_ls_for_applications_to_open_content_type(const Object& content_type) const;
        /**
     * @brief Calls `-[NSWorkspace URLsForApplicationsToOpenURL:]`.
     * @details Returns URLs to all available applications that can open the given URL. The system sorts the resulting array based on each application's suitability to open the given URL. The first application is considered the best available match. This returns the empty array if no app can open it, or if the file does not exist.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<URL> ur_ls_for_applications_to_open_url(const URL& url) const;
        /**
     * @brief Calls `-[NSWorkspace URLsForApplicationsWithBundleIdentifier:]`.
     * @details Get the URL for all copies of an application with the given identifier. The system sorts the resulting array based on each application's suitability to launch. The first application is considered the best available match. This returns the empty array if no app has the bundle identifier.
     * @param bundle_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<URL> ur_ls_for_applications_with_bundle_identifier(const std::string& bundle_identifier) const;
        /**
     * @brief Calls `-[NSWorkspace activateFileViewerSelectingURLs:]`.
     * @details Activate the Finder, and open one or more windows selecting the files at the given fileURLs.
     * @param file_urls Argument converted to the Objective-C parameter of the same role.
     */
        void activate_file_viewer_selecting_urls(const std::vector<URL>& file_urls) const;
        /**
     * @brief Calls `-[NSWorkspace desktopImageOptionsForScreen:]`.
     * @details Returns the options dictionary for the desktop image for the given screen.
     * @param screen Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> desktop_image_options_for_screen(const Screen& screen) const;
        /**
     * @brief Calls `-[NSWorkspace desktopImageURLForScreen:]`.
     * @details Returns the URL for the desktop image for the given screen.
     * @param screen Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL desktop_image_url_for_screen(const Screen& screen) const;
        /**
     * @brief Calls `-[NSWorkspace duplicateURLs:completionHandler:]`.
     * @param urls Argument converted to the Objective-C parameter of the same role.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     */
        void duplicate_urls(const std::vector<URL>& urls, std::function<void(std::vector<std::pair<URL, URL>>, Error)> handler) const;
        /**
     * @brief Calls `-[NSWorkspace extendPowerOffBy:]`.
     * @details extendPowerOffBy: is currently not implemented. Do not use it.
     * @param requested Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t extend_power_off_by(std::int64_t requested) const;
        /**
     * @brief Calls `-[NSWorkspace getFileSystemInfoForPath:isRemovable:isWritable:isUnmountable:description:type:]`.
     * @details Gets information about the filesystem. fullPath is the path to any file or directory on the filesystem, including the filesystem's mount point. The returned values have the following significance: - isRemovable: whether the filesystem is backed by removable media, such as a CD or floppy disk. - isWritable: whether the filesystem can be written to - isUnmountable: whether the filesystem can be unmounted. - description: typically the type of the volume or the name of the filesystem - the file system type, for example, 'hfs'
     * @param full_path Argument converted to the Objective-C parameter of the same role.
     * @param removable_flag Argument converted to the Objective-C parameter of the same role.
     * @param writable_flag Argument converted to the Objective-C parameter of the same role.
     * @param unmountable_flag Argument converted to the Objective-C parameter of the same role.
     * @param description Argument converted to the Objective-C parameter of the same role.
     * @param file_system_type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool get_file_system_info_for_path(const std::string& full_path, bool* removable_flag, bool* writable_flag, bool* unmountable_flag, std::string& description, std::string& file_system_type) const;
        /**
     * @brief Calls `-[NSWorkspace hideOtherApplications]`.
     * @details Attempt to hide all other applications.
     */
        void hide_other_applications() const;
        /**
     * @brief Calls `-[NSWorkspace iconForContentType:]`.
     * @details Get the icon for a given type object. Returns a default icon if the operation fails.
     * @param content_type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Image icon_for_content_type(const Object& content_type) const;
        /**
     * @brief Calls `-[NSWorkspace iconForFile:]`.
     * @details Returns the icon for a file at a given path, or a generic icon if the operation fails.
     * @param full_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Image icon_for_file(const std::string& full_path) const;
        /**
     * @brief Calls `-[NSWorkspace iconForFiles:]`.
     * @details Returns the icon for a group of files at the given paths.
     * @param full_paths Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Image icon_for_files(const std::vector<std::string>& full_paths) const;
        /**
     * @brief Calls `-[NSWorkspace isFilePackageAtPath:]`.
     * @details Indicates whether a given directory is a package. Returns YES if the file is a package, NO if not, or if the file does not exist or the operation otherwise failed. A file may be a package because its filename extension indicates so (for example, .framework) or because it has the package bit set.
     * @param full_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_file_package_at_path(const std::string& full_path) const;
        /**
     * @brief Calls `-[NSWorkspace noteFileSystemChanged:]`.
     * @details noteFileSystemChanged: informs listeners of a filesystem change, using the FNNotifyByPath() API. As the FNNotify API has been supplanted by the FSEvents API, the use of this method is discouraged.
     * @param path Argument converted to the Objective-C parameter of the same role.
     */
        void note_file_system_changed(const std::string& path) const;
        /**
     * @brief Calls `-[NSWorkspace openApplicationAtURL:configuration:completionHandler:]`.
     * @details Launch the application at the specified URL with the given configuration. The completion handler is called on a concurrent queue with either the NSRunningApplication on success, or an NSError on failure.
     * @param application_url Argument converted to the Objective-C parameter of the same role.
     * @param configuration Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void open_application_at_url(const URL& application_url, const WorkspaceOpenConfiguration& configuration, std::function<void(RunningApplication, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSWorkspace openURL:]`.
     * @details Open a URL, using the default handler for the URL's scheme.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool open_url(const URL& url) const;
        /**
     * @brief Calls `-[NSWorkspace openURL:configuration:completionHandler:]`.
     * @details Open a URL asynchronously with the given configuration. The completion handler is called on a concurrent queue with either the NSRunningApplication on success, or an NSError on failure.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param configuration Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void open_url(const URL& url, const WorkspaceOpenConfiguration& configuration, std::function<void(RunningApplication, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSWorkspace openURLs:withApplicationAtURL:configuration:completionHandler:]`.
     * @details Open URLs in a specified application with the given configuration. The completion handler is called on a concurrent queue with either the NSRunningApplication on success, or an NSError on failure.
     * @param urls Argument converted to the Objective-C parameter of the same role.
     * @param application_url Argument converted to the Objective-C parameter of the same role.
     * @param configuration Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void open_urls(const std::vector<URL>& urls, const URL& application_url, const WorkspaceOpenConfiguration& configuration, std::function<void(RunningApplication, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSWorkspace recycleURLs:completionHandler:]`.
     * @details Asynchronous file operations. recycleURLs moves the given files to the trash, and duplicateURLs duplicates them in the same manner as the Finder. If completionHandler is not nil, it will be called when the operation is complete, on the same dispatch queue that was used for the recycleURLs: call. Within the completion handler, the newURLs dictionary parameter maps the given URLs to their new URLs in the Trash. Files that could not be moved to the Trash will not be present in the dictionary. If the operation succeeded for every file, the error parameter will be nil. If it failed for one or more files, the error parameter will describe the overall result of the operation in a manner suitable for presentation to the user. The completionHandler may be nil if you are not interested in the results. These methods may show a progress indicator, or other user interface elements, at AppKit's discretion. In Mac OS X 10.6, these methods require that the main run loop be run in a common mode.
     * @param urls Argument converted to the Objective-C parameter of the same role.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     */
        void recycle_urls(const std::vector<URL>& urls, std::function<void(std::vector<std::pair<URL, URL>>, Error)> handler) const;
        /**
     * @brief Calls `-[NSWorkspace requestAuthorizationOfType:completionHandler:]`.
     * @param type Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void request_authorization_of_type(WorkspaceAuthorizationType type, std::function<void(WorkspaceAuthorization, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSWorkspace selectFile:inFileViewerRootedAtPath:]`.
     * @details Activate the Finder and open a window selecting the file at the given path. If fullPath is nil, this will instead open the directory specified by rootFullPath, and not select any file. If rootFullPath is the empty string (\@""), the file is selected in the main viewer. Otherwise, a new file viewer is opened.
     * @param full_path Argument converted to the Objective-C parameter of the same role.
     * @param root_full_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool select_file(const std::string& full_path, const std::string& root_full_path) const;
        /**
     * @brief Calls `-[NSWorkspace setDefaultApplicationAtURL:toOpenContentType:completionHandler:]`.
     * @details Sets the default handler for the specified UTType. Some types require user consent before you can change their handlers. If a change requires user consent, the system will ask the user asynchronously before invoking the completion handler.
     * @param application_url Argument converted to the Objective-C parameter of the same role.
     * @param content_type Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void set_default_application_at_url(const URL& application_url, const Object& content_type, std::function<void(Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSWorkspace setDefaultApplicationAtURL:toOpenContentTypeOfFileAtURL:completionHandler:]`.
     * @details Sets the default handler for files with the same UTType as the one specified. Does not apply to non-file URLs. Some UTTypes require user consent before you can change their handlers. If a change requires user consent, the system will ask the user asynchronously before invoking the completion handler.
     * @param application_url Argument converted to the Objective-C parameter of the same role.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void set_default_application_at_url(const URL& application_url, const URL& url, std::function<void(Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSWorkspace setDefaultApplicationAtURL:toOpenURLsWithScheme:completionHandler:]`.
     * @details Sets the default handler for URLs with the same scheme as the one specified. Some URL schemes require user consent before you can change their handlers. If a change requires user consent, the system will ask the user asynchronously before invoking the completion handler.
     * @param application_url Argument converted to the Objective-C parameter of the same role.
     * @param url_scheme Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void set_default_application_at_url(const URL& application_url, const std::string& url_scheme, std::function<void(Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSWorkspace setDesktopImageURL:forScreen:options:error:]`.
     * @details Sets the desktop image for the given screen to the image at the given URL. The URL must be a file URL and may not be nil. The options dictionary may contain any of the NSWorkspaceDesktopImage keys, which control how the image is scaled on the screen. This returns YES if the image was successfully set; otherwise, NO is returned and an error is returned by reference. You should normally NOT present a user interface for picking the options. Instead, just choose appropriate defaults and allow the user to adjust them in the System Preference Pane.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param screen Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_desktop_image_url(const URL& url, const Screen& screen, const std::map<std::string, Object>& options) const;
        /**
     * @brief Calls `-[NSWorkspace setIcon:forFile:options:]`.
     * @details If image is not nil, this sets a custom icon for the file at the given path. If image is nil, this removes any custom icon at the given path. Returns YES if successful, NO if not.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @param full_path Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_icon(const Image& image, const std::string& full_path, WorkspaceIconCreationOptions options) const;
        /**
     * @brief Calls `-[NSWorkspace showSearchResultsForQueryString:]`.
     * @details Displays a Spotlight search results window in Finder for the specified query string. Finder becomes the active application, if possible. The user can further refine the search via the Finder UI. Returns YES if the communication with Finder was successful.
     * @param query_string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool show_search_results_for_query_string(const std::string& query_string) const;
        /**
     * @brief Calls `-[NSWorkspace unmountAndEjectDeviceAtPath:]`.
     * @details Attempt to eject the volume mounted at the given path. Returns YES if successful, NO if not, for example, if the volume is not ejectable.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool unmount_and_eject_device_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSWorkspace unmountAndEjectDeviceAtURL:error:]`.
     * @details Same as unmountAndEjectDeviceAtPath, except it takes an NSURL and returns an NSError.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool unmount_and_eject_device_at_url(const URL& url) const;
        /**
     * @brief Returns the `accessibilityDisplayShouldDifferentiateWithoutColor` property of `NSWorkspace`.
     * @return The converted Objective-C result.
     */
        bool accessibility_display_should_differentiate_without_color() const;
        /**
     * @brief Returns the `accessibilityDisplayShouldIncreaseContrast` property of `NSWorkspace`.
     * @return The converted Objective-C result.
     */
        bool accessibility_display_should_increase_contrast() const;
        /**
     * @brief Returns the `accessibilityDisplayShouldInvertColors` property of `NSWorkspace`.
     * @return The converted Objective-C result.
     */
        bool accessibility_display_should_invert_colors() const;
        /**
     * @brief Returns the `accessibilityDisplayShouldReduceMotion` property of `NSWorkspace`.
     * @return The converted Objective-C result.
     */
        bool accessibility_display_should_reduce_motion() const;
        /**
     * @brief Returns the `accessibilityDisplayShouldReduceTransparency` property of `NSWorkspace`.
     * @return The converted Objective-C result.
     */
        bool accessibility_display_should_reduce_transparency() const;
        /**
     * @brief Returns the `fileLabelColors` property of `NSWorkspace`.
     * @details Get the corresponding array of file label colors. This array has the same number of elements as fileLabels, and the color at a given index corresponds to the label at the same index . You may listen for NSWorkspaceDidChangeFileLabelsNotification to be notified when these change.
     * @return The converted Objective-C result.
     */
        std::vector<Color> file_label_colors() const;
        /**
     * @brief Returns the `fileLabels` property of `NSWorkspace`.
     * @details Get the array of file labels as NSStrings. The file label index for a particular file is available as a property on the URL. You may listen for NSWorkspaceDidChangeFileLabelsNotification to be notified when these change.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> file_labels() const;
        /**
     * @brief Returns the `frontmostApplication` property of `NSWorkspace`.
     * @details Gets the frontmost application, which is the application that will receive key events. This is observable through KVO.
     * @return The converted Objective-C result.
     */
        RunningApplication frontmost_application() const;
        /**
     * @brief Returns the `menuBarOwningApplication` property of `NSWorkspace`.
     * @details Gets the menu bar owning application, which is the application that currently owns and draws the menu bar. This is observable through KVO.
     * @return The converted Objective-C result.
     */
        RunningApplication menu_bar_owning_application() const;
        /**
     * @brief Returns the `notificationCenter` property of `NSWorkspace`.
     * @details Returns the NSNotificationCenter for this NSWorkspace. All notifications in this header file must be registered on this notification center. If you register on other notification centers, you will not receive the notifications.
     * @return The converted Objective-C result.
     */
        NotificationCenter notification_center() const;
        /**
     * @brief Returns the `runningApplications` property of `NSWorkspace`.
     * @return The converted Objective-C result.
     */
        std::vector<RunningApplication> running_applications() const;
        /**
     * @brief Returns the `sharedWorkspace` property of `NSWorkspace`.
     * @details Get the shared instance of NSWorkspace. This method will create an instance of NSWorkspace if it has not been created yet. You should not attempt to instantiate instances of NSWorkspace yourself, and you should not attempt to subclass NSWorkspace.
     * @return The converted Objective-C result.
     */
        static Workspace shared_workspace();
        /**
     * @brief Returns the `switchControlEnabled` property of `NSWorkspace`.
     * @return The converted Objective-C result.
     */
        bool is_switch_control_enabled() const;
        /**
     * @brief Returns the `voiceOverEnabled` property of `NSWorkspace`.
     * @return The converted Objective-C result.
     */
        bool is_voice_over_enabled() const;
    };
}
