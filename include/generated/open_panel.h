#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/save_panel.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSOpenPanel` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref SavePanel.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::OpenPanel open_panel;
     * open_panel.set_accessory_view_disclosed(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::OpenPanel open_panel{};
     * open_panel.set_accessory_view_disclosed(true);
     * auto accessory_view_disclosed = open_panel.is_accessory_view_disclosed();
     * open_panel.set_allows_multiple_selection(true);
     * auto allows_multiple_selection = open_panel.allows_multiple_selection();
     * open_panel.set_can_choose_directories(true);
     * auto can_choose_directories = open_panel.can_choose_directories();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsopenpanel
     */
    class OpenPanel : public SavePanel
    {
    public:
        /// @brief Creates a new `NSOpenPanel` instance and returns a handle to it.
        explicit OpenPanel();
        /// @brief Creates a null handle that refers to no native object.
        OpenPanel(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit OpenPanel(Adopt adopt);
        /**
     * @brief Returns the `URLs` property of `NSOpenPanel`.
     * @return The converted Objective-C result.
     */
        std::vector<URL> urls() const;
        /**
     * @brief Returns the `accessoryViewDisclosed` property of `NSOpenPanel`.
     * @details Gets and sets the disclosure state of an accessory view in an NSOpenPanel. If hiding / disclosing an accessory view is not applicable this property will behave like a read only property.
     * @return The converted Objective-C result.
     */
        bool is_accessory_view_disclosed() const;
        /**
     * @brief Sets the `accessoryViewDisclosed` property of `NSOpenPanel`.
     * @details Gets and sets the disclosure state of an accessory view in an NSOpenPanel. If hiding / disclosing an accessory view is not applicable this property will behave like a read only property.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_accessory_view_disclosed(bool value) const;
        /**
     * @brief Returns the `allowsMultipleSelection` property of `NSOpenPanel`.
     * @return The converted Objective-C result.
     */
        bool allows_multiple_selection() const;
        /**
     * @brief Sets the `allowsMultipleSelection` property of `NSOpenPanel`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_multiple_selection(bool value) const;
        /**
     * @brief Returns the `canChooseDirectories` property of `NSOpenPanel`.
     * @details Whether or not the user can choose directories in open the panel. \@discussion In macOS 27 and later, 'canChooseDirectories' is updated when you set 'allowedContentTypes' or set 'treatsFilePackagesAsDirectories'. If 'allowedContentTypes' contains a type that conforms to 'UTTypeDirectory' then 'canChooseDirectories' is set to 'YES'. If 'allowedContentTypes' contains a type that conforms to 'UTTypePackage' and 'treatsFilePackagesAsDirectories' is 'YES', then 'canChooseDirectories' is set to 'YES'. By default 'canChooseDirectories' is 'NO'. In general you will only need to set 'canChooseDirectories' to 'YES' when 'allowedContentTypes' is '[]' (the empty array). If you set 'canChooseDirectories' to 'YES' then set 'allowedContentTypes' to '[]', 'canChooseDirectories' will still be 'YES'. However, if you reset 'allowedContentTypes' from non-empty to empty, then that will also reset 'canChooseDirectories' to 'NO', the default value. In short, setting 'allowedContentTypes' to '[]' keeps your setting or overrides the automatic system setting. If unsure, you can always set 'canChooseDirectories' after setting 'allowedContentTypes'.
     * @return The converted Objective-C result.
     */
        bool can_choose_directories() const;
        /**
     * @brief Sets the `canChooseDirectories` property of `NSOpenPanel`.
     * @details Whether or not the user can choose directories in open the panel. \@discussion In macOS 27 and later, 'canChooseDirectories' is updated when you set 'allowedContentTypes' or set 'treatsFilePackagesAsDirectories'. If 'allowedContentTypes' contains a type that conforms to 'UTTypeDirectory' then 'canChooseDirectories' is set to 'YES'. If 'allowedContentTypes' contains a type that conforms to 'UTTypePackage' and 'treatsFilePackagesAsDirectories' is 'YES', then 'canChooseDirectories' is set to 'YES'. By default 'canChooseDirectories' is 'NO'. In general you will only need to set 'canChooseDirectories' to 'YES' when 'allowedContentTypes' is '[]' (the empty array). If you set 'canChooseDirectories' to 'YES' then set 'allowedContentTypes' to '[]', 'canChooseDirectories' will still be 'YES'. However, if you reset 'allowedContentTypes' from non-empty to empty, then that will also reset 'canChooseDirectories' to 'NO', the default value. In short, setting 'allowedContentTypes' to '[]' keeps your setting or overrides the automatic system setting. If unsure, you can always set 'canChooseDirectories' after setting 'allowedContentTypes'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_can_choose_directories(bool value) const;
        /**
     * @brief Returns the `canChooseFiles` property of `NSOpenPanel`.
     * @details Whether or not the user can choose files in the open panel. \@discussion In macOS 27 and later, 'canChooseFiles' is updated when you set 'allowedContentTypes' or set 'treatsFilePackagesAsDirectories'. If 'allowedContentTypes' contains a type that does not conform to 'UTTypeDirectory' then 'canChooseFiles' is set to 'YES'. If 'allowedContentTypes' contains a type that conforms to 'UTTypePackage' and 'treatsFilePackagesAsDirectories' is 'NO', then 'canChooseFiles' is set to 'YES. By default 'canChooseFiles' is 'YES'. In general you will only need to set 'canChooseFiles' to 'NO' when 'allowedContentTypes' is '[]' (the empty array). If you set 'canChooseFiles' to 'NO' then set 'allowedContentTypes' to '[]', 'canChooseFiles' will still be 'NO'. However, if you reset 'allowedContentTypes' from non-empty to empty, then that will also reset 'canChooseFiles' to 'YES', the default value. In short, setting 'allowedContentTypes' to '[]' keeps your setting or overrides the automatic system setting. If unsure, you can always set 'canChooseFiles' after setting 'allowedContentTypes'.
     * @return The converted Objective-C result.
     */
        bool can_choose_files() const;
        /**
     * @brief Sets the `canChooseFiles` property of `NSOpenPanel`.
     * @details Whether or not the user can choose files in the open panel. \@discussion In macOS 27 and later, 'canChooseFiles' is updated when you set 'allowedContentTypes' or set 'treatsFilePackagesAsDirectories'. If 'allowedContentTypes' contains a type that does not conform to 'UTTypeDirectory' then 'canChooseFiles' is set to 'YES'. If 'allowedContentTypes' contains a type that conforms to 'UTTypePackage' and 'treatsFilePackagesAsDirectories' is 'NO', then 'canChooseFiles' is set to 'YES. By default 'canChooseFiles' is 'YES'. In general you will only need to set 'canChooseFiles' to 'NO' when 'allowedContentTypes' is '[]' (the empty array). If you set 'canChooseFiles' to 'NO' then set 'allowedContentTypes' to '[]', 'canChooseFiles' will still be 'NO'. However, if you reset 'allowedContentTypes' from non-empty to empty, then that will also reset 'canChooseFiles' to 'YES', the default value. In short, setting 'allowedContentTypes' to '[]' keeps your setting or overrides the automatic system setting. If unsure, you can always set 'canChooseFiles' after setting 'allowedContentTypes'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_can_choose_files(bool value) const;
        /**
     * @brief Returns the `canDownloadUbiquitousContents` property of `NSOpenPanel`.
     * @details Controls how the receiver responds to ubiquitous documents that aren't yet fully downloaded locally. If YES, then the receiver will disallow opening non-local ubiquitous files. Also, if the user attempts to select a non-local file, the receiver will trigger or reprioritize downloading for that file so that it can be opened as soon as possible. If NO, then the receiver will allow the user to select and open non-local files, giving your application responsibility for downloading and reporting progress. The default value is YES, except for applications linked against the 10.9 SDK or earlier that have adopted iCloud by specifying a ubiquitous container identifier entitlement. To provide the ideal user experience, you should set this property to NO and download the file's contents (with NSFileCoordinator) and show downloading progress (with NSProgress or NSMetadataQuery) in the context of your application, instead of relying on the open panel to do it.
     * @return The converted Objective-C result.
     */
        bool can_download_ubiquitous_contents() const;
        /**
     * @brief Sets the `canDownloadUbiquitousContents` property of `NSOpenPanel`.
     * @details Controls how the receiver responds to ubiquitous documents that aren't yet fully downloaded locally. If YES, then the receiver will disallow opening non-local ubiquitous files. Also, if the user attempts to select a non-local file, the receiver will trigger or reprioritize downloading for that file so that it can be opened as soon as possible. If NO, then the receiver will allow the user to select and open non-local files, giving your application responsibility for downloading and reporting progress. The default value is YES, except for applications linked against the 10.9 SDK or earlier that have adopted iCloud by specifying a ubiquitous container identifier entitlement. To provide the ideal user experience, you should set this property to NO and download the file's contents (with NSFileCoordinator) and show downloading progress (with NSProgress or NSMetadataQuery) in the context of your application, instead of relying on the open panel to do it.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_can_download_ubiquitous_contents(bool value) const;
        /**
     * @brief Returns the `canResolveUbiquitousConflicts` property of `NSOpenPanel`.
     * @details Controls how the receiver responds to ubiquitous documents with conflicting versions. If YES, then when the user attempts to open one or more documents with conflicts, the receiver will first display conflict resolution UI, requiring the user to resolve those conflicts before the documents can be opened. If NO, then the receiver does nothing in response to conflicts, allowing your application to handle them. The default value is YES, except for applications linked against the 10.9 SDK or earlier that have adopted iCloud by specifying a ubiquitous container identifier entitlement. To provide the ideal user experience, you should set this property to NO and do conflict detection and resolution (using NSURLUbiquitousItemHasUnresolvedConflictsKey and NSFileVersion) in the context of your application, instead of relying on the open panel to do it.
     * @return The converted Objective-C result.
     */
        bool can_resolve_ubiquitous_conflicts() const;
        /**
     * @brief Sets the `canResolveUbiquitousConflicts` property of `NSOpenPanel`.
     * @details Controls how the receiver responds to ubiquitous documents with conflicting versions. If YES, then when the user attempts to open one or more documents with conflicts, the receiver will first display conflict resolution UI, requiring the user to resolve those conflicts before the documents can be opened. If NO, then the receiver does nothing in response to conflicts, allowing your application to handle them. The default value is YES, except for applications linked against the 10.9 SDK or earlier that have adopted iCloud by specifying a ubiquitous container identifier entitlement. To provide the ideal user experience, you should set this property to NO and do conflict detection and resolution (using NSURLUbiquitousItemHasUnresolvedConflictsKey and NSFileVersion) in the context of your application, instead of relying on the open panel to do it.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_can_resolve_ubiquitous_conflicts(bool value) const;
        /**
     * @brief Returns the `resolvesAliases` property of `NSOpenPanel`.
     * @return The converted Objective-C result.
     */
        bool resolves_aliases() const;
        /**
     * @brief Sets the `resolvesAliases` property of `NSOpenPanel`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_resolves_aliases(bool value) const;
    };
}
