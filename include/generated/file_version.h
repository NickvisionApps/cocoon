#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;
    class Error;
    class PersonNameComponents;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSFileVersion` (Foundation).
     * @details A snapshot of a file at a specific point in time. Use the methods of this class to access, create, and manage file revisions in your app. Each file version instance contains metadata about a single revision, including the location of the associated file, the modification date of the revision, and whether the revision is discardable. In Mac apps, you can use file version objects to track changes to a local file over time and to prevent the loss of data during editing. When managing local versions, the document architecture creates versions at specific points in the lifetime of your application. Your application can also create versions explicitly at times that your application designates as appropriate. In addition to managing local files, the system also uses this class to manage cloud-based files. For files in the cloud, there is usually only one version of the file at any given time. However, additional file versions may be created in cases where two different computers attempt to save the file to the cloud at the same time. In that case, one file is chosen as the current version and any other versions are tagged as being in conflict with the original. Conflict versions are reported to the appropriate file presenter objects and should be resolved as soon as possible so that the corresponding files can be removed from the cloud.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::FileVersion file_version;
     * file_version.set_discardable(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::FileVersion file_version{};
     * file_version.set_discardable(true);
     * auto discardable = file_version.is_discardable();
     * file_version.set_resolved(true);
     * auto resolved = file_version.is_resolved();
     * auto made_0 = cocoon::FileVersion::add_version_of_item_at_url(cocoon::URL(), cocoon::URL(), cocoon::FileVersionAddingOptions::Moving);
     * auto made_1 = cocoon::FileVersion::current_version_of_item_at_url(cocoon::URL());
     * file_version.remove_and_return_error();
     * file_version.replace_item_at_url(cocoon::URL(), cocoon::FileVersionReplacingOptions::Moving);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsfileversion
     */
    class FileVersion : public Object
    {
    public:
        /// @brief Creates a new `NSFileVersion` instance and returns a handle to it.
        explicit FileVersion();
        /// @brief Creates a null handle that refers to no native object.
        FileVersion(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit FileVersion(Adopt adopt);
        /**
     * @brief Calls `+[NSFileVersion addVersionOfItemAtURL:withContentsOfURL:options:error:]`.
     * @details Creates a version of the file at the specified location. You can use this method to save a version of your file to the location specified by the url parameter. The contents of the file are taken from the contentsURL parameter, whose value may be the same as the url parameter. You should always add file versions as part of a coordinated write operation to a file. In other words, always call this method from a block passed to a file coordinator object to initiate a write operation. Doing so ensures that no other processes are operating on the file while you save the version to its new location. You can add versions only on Mac OS X.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param contents_url Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileVersion add_version_of_item_at_url(const URL& url, const URL& contents_url, FileVersionAddingOptions options);
        /**
     * @brief Calls `+[NSFileVersion currentVersionOfItemAtURL:]`.
     * @details Returns the most recent version object for the file at the specified URL. - Parameter url: The URL of the file whose version object you want. - Returns: The version object representing the current version of the file or nil if there is no such file.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileVersion current_version_of_item_at_url(const URL& url);
        /**
     * @brief Calls `+[NSFileVersion getNonlocalVersionsOfItemAtURL:completionHandler:]`.
     * @details Asynchronously returns an array of NSFileVersions associated with the file located by the given URL, or nil if there is no such file or another error occurs. Versions returned by this method do not initially have their contents stored locally on the device, so a download may be required before you are able to access them. File attributes are accessible via -[NSURL getPromisedItemResourceValue:forKey:error:]. You can request a download by performing a coordinated read with NSFileCoordinator on the URL property of the resulting NSFileVersions. When a version is successfully downloaded, its contents are cached locally, and the version will no longer be returned by this method. The version will be returned by +otherVersionsOfItemAtURL: instead, but will retain the same persistentIdentifier value.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        static void get_nonlocal_versions_of_item_at_url(const URL& url, std::function<void(std::vector<FileVersion>, Error)> completion_handler);
        /**
     * @brief Calls `+[NSFileVersion otherVersionsOfItemAtURL:]`.
     * @details Returns all versions of the specified file except the current version. - Parameter url: The URL of the file whose versions you want. - Returns: An array of file version objects or nil if there is no such file. The array does not contain the version object returned by the +currentVersionOfItemAtURL: method. For locally based files, this property typically contains versions of the file that you saved explicitly or that were saved at appropriate times while the file was being edited. For documents residing in the cloud, this property typically returns zero or more file versions representing conflicting versions of a file that need to be resolved with the current version.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<FileVersion> other_versions_of_item_at_url(const URL& url);
        /**
     * @brief Calls `-[NSFileVersion removeAndReturnError:]`.
     * @details Remove this version object and its associated file from the version store. This method removes this version object and its file from the version store, freeing up the associated storage space. You must not call this method for the current file version — that is, the version object returned by the +currentVersionOfItemAtURL: method. You should always remove file versions as part of a coordinated write operation to a file. Doing so ensures that no other processes are operating on the file while you remove the version information. If successful, subsequent requests for the versions of the file do not include this version object.
     * @return The converted Objective-C result.
     */
        bool remove_and_return_error() const;
        /**
     * @brief Calls `+[NSFileVersion removeOtherVersionsOfItemAtURL:error:]`.
     * @details Removes all versions of a file, except the current one, from the version store. This method removes all versions except the current one from the version store, freeing up the associated storage space. You should always remove file versions as part of a coordinated write operation to a file. Doing so ensures that no other processes are operating on the file while you remove the version information. If successful, subsequent requests for the versions of the file reflect that only the current version is available.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool remove_other_versions_of_item_at_url(const URL& url);
        /**
     * @brief Calls `-[NSFileVersion replaceItemAtURL:options:error:]`.
     * @details Replace the contents of the specified file with the contents of the current version's file. If the passed-in URL locates a file, replace the file with a file whose contents are taken from the version but whose display name is taken from the file. If the passed-in URL does not locate a file then simply write one. The one exception to taking the display name from an existing file is if the version is of a different type than the overwritten file, in which case the file name extension will be taken from the version. When you use NSFileVersionReplacingByMoving you remove a version of the file, and should do it as part of a coordinated write to the file.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL replace_item_at_url(const URL& url, FileVersionReplacingOptions options) const;
        /**
     * @brief Calls `+[NSFileVersion temporaryDirectoryURLForNewVersionOfItemAtURL:]`.
     * @details Creates and returns a temporary directory to use for saving the contents of the file. You can use this method in situations where you want to write the contents for a new file version in a temporary location. When you finish creating the temporary file within the returned directory, add it as a new version with -addVersionOfItemAtURL:withContentsOfURL:options:error: with the NSFileVersionAddingByMoving option. You must delete the directory returned by this method when you are done with it.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL temporary_directory_url_for_new_version_of_item_at_url(const URL& url);
        /**
     * @brief Calls `+[NSFileVersion unresolvedConflictVersionsOfItemAtURL:]`.
     * @details Returns an array of version objects that are currently in conflict for the specified URL. - Parameter url: The URL of the file that has associated version objects. - Returns: An array of NSFileVersion objects that represent the versions in conflict or nil if the file at URL does not exist.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<FileVersion> unresolved_conflict_versions_of_item_at_url(const URL& url);
        /**
     * @brief Calls `+[NSFileVersion versionOfItemAtURL:forPersistentIdentifier:]`.
     * @details Returns the version of the file that has the specified persistent ID. - Parameter url: The URL of the file whose version you want. - Parameter persistentIdentifier: The persistent ID of the NSFileVersion object you want. - Returns: The file version object with the specified ID or nil if no such version object exists.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param persistent_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileVersion version_of_item_at_url(const URL& url, const Object& persistent_identifier);
        /**
     * @brief Returns the `URL` property of `NSFileVersion`.
     * @details The URL identifying the location of the file associated with the file version object. The URL identifies the location of the file associated with this version. If this version of the file has been deleted, the value in this property is nil. Do not display any part of this URL to the user. The location of file versions is managed by the system and should not be exposed to the user. If you want to present the name of a file version, use the localizedName property.
     * @return The converted Objective-C result.
     */
        URL url() const;
        /**
     * @brief Returns the `conflict` property of `NSFileVersion`.
     * @details A Boolean value indicating whether the contents of the version are in conflict with the contents of another version. When two or more versions of a file are written at the same time, perhaps because the file is saved in the cloud and one or more of the writers were offline when they were writing, the system attempts to resolve the conflict automatically. It does this by picking one of the file versions to be the current file and setting this property to YES for the other file versions that are in conflict.
     * @return The converted Objective-C result.
     */
        bool is_conflict() const;
        /**
     * @brief Returns the `discardable` property of `NSFileVersion`.
     * @details A Boolean value that specifies whether the system can delete the associated file at some future time. Marking a file version as discardable gives the system the flexibility to reclaim the space, occupied by the associated file, at some future time. Do not, however, depend on the file being discarded. After setting this property to YES, do not set this property to NO again. Doing so causes the system to raise an exception. In addition, if you set this property to YES for the version of the file returned by the +currentVersionOfItemAtURL: method, the system raises an exception. Versions can be discardable only on Mac OS X.
     * @return The converted Objective-C result.
     */
        bool is_discardable() const;
        /**
     * @brief Sets the `discardable` property of `NSFileVersion`.
     * @details A Boolean value that specifies whether the system can delete the associated file at some future time. Marking a file version as discardable gives the system the flexibility to reclaim the space, occupied by the associated file, at some future time. Do not, however, depend on the file being discarded. After setting this property to YES, do not set this property to NO again. Doing so causes the system to raise an exception. In addition, if you set this property to YES for the version of the file returned by the +currentVersionOfItemAtURL: method, the system raises an exception. Versions can be discardable only on Mac OS X.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_discardable(bool value) const;
        /**
     * @brief Returns the `hasLocalContents` property of `NSFileVersion`.
     * @details Whether the version has local contents. Versions that are returned by +getNonlocalVersionsOfItemAtURL:completionHandler: do not initially have local contents. You can only access their contents, either directly via the URL or by invoking -replaceItemAtURL:options:error:, from within a coordinated read on the NSFileVersion's URL.
     * @return The converted Objective-C result.
     */
        bool has_local_contents() const;
        /**
     * @brief Returns the `hasThumbnail` property of `NSFileVersion`.
     * @details Whether the version has a thumbnail image available. Thumbnails for versions from +getNonlocalVersionsOfItemAtURL:completionHandler: may not immediately be available. As soon as it becomes available, this property will change from NO to YES. You can use KVO to be notified of this change. If a thumbnail is available, you can access it using NSURLThumbnailKey or NSURLThumbnailDictionaryKey.
     * @return The converted Objective-C result.
     */
        bool has_thumbnail() const;
        /**
     * @brief Returns the `localizedName` property of `NSFileVersion`.
     * @details The string containing the user-presentable name of the file version. When displaying different versions of a file to the user, you should present this string to the user instead of the version's URL.
     * @return The converted Objective-C result.
     */
        std::string localized_name() const;
        /**
     * @brief Returns the `localizedNameOfSavingComputer` property of `NSFileVersion`.
     * @details The user-presentable name of the computer on which the revision was saved. If the current revision has been deleted from disk, or if no computer name was recorded, the value in this property is nil. The computer name is guaranteed to be recorded only when the current version is in conflict with another version. The version object does not track changes to the computer name itself. Thus, if the computer name changed, the value in this string might be an old value.
     * @return The converted Objective-C result.
     */
        std::string localized_name_of_saving_computer() const;
        /**
     * @brief Returns the `modificationDate` property of `NSFileVersion`.
     * @details The modification date of the version, or possibly nil if the receiver's storage has been deleted.
     * @return The converted Objective-C result.
     */
        Date modification_date() const;
        /**
     * @brief Returns the `originatorNameComponents` property of `NSFileVersion`.
     * @details The name components of the user who created this version of the file. Is nil if the file is not shared or if the current user is the originator.
     * @return The converted Objective-C result.
     */
        PersonNameComponents originator_name_components() const;
        /**
     * @brief Returns the `resolved` property of `NSFileVersion`.
     * @details A Boolean value that indicates whether the conflict has been resolved. When the system detects a conflict involving versions of a file, it sets this property to NO to indicate an unresolved conflict. After you resolve the conflict, set this property to YES to tell the system it is resolved; you must then remove any versions of the file that are no longer useful. Never set the value of this property to NO. If you do, the system raises an exception. Resolving a conflict causes the file version object to be removed from any reports about conflicting versions, such as those returned by the +unresolvedConflictVersionsOfItemAtURL: method.
     * @return The converted Objective-C result.
     */
        bool is_resolved() const;
        /**
     * @brief Sets the `resolved` property of `NSFileVersion`.
     * @details A Boolean value that indicates whether the conflict has been resolved. When the system detects a conflict involving versions of a file, it sets this property to NO to indicate an unresolved conflict. After you resolve the conflict, set this property to YES to tell the system it is resolved; you must then remove any versions of the file that are no longer useful. Never set the value of this property to NO. If you do, the system raises an exception. Resolving a conflict causes the file version object to be removed from any reports about conflicting versions, such as those returned by the +unresolvedConflictVersionsOfItemAtURL: method.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_resolved(bool value) const;
    };
}
