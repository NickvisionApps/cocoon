#pragma once

#include "generated/availability.h"
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
     * @details Instances of NSFileVersion for the same version of the same file are equal, and instances of NSFileVersion for different versions of the same file are not equal, but the equality of NSFileVersions for different files is undefined. Repeated invocations of the methods that return NSFileVersions do not necessarily return the exact same instance of NSFileVersion.
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
     * @details Add a new version of the file located by a URL, with the contents coming from a file located by either the same or a different URL, and return a new instance that represents the version if successful. If not successful, return NO after setting outError to an NSError that encapsulates why not. You can add versions only on Mac OS X. When adding or removing versions of a file you should do it as part of a "coordinated" write to the file. The NSFileCoordinator class that you use to do coordinated file access is declared in \<Foundation/NSFileCoordinator.h>. Using it properly ensures that NSFilePresenters of the file, or directories that contain the file, receive accurate notifications about versions being added or removed. NSFilePresenter is declared in \<Foundation/NSFilePresenter.h>. For example, use -[NSFileCoordinator coordinateWritingItemAtURL:options:error:byAccessor:] when the file URL and the contents url are the same. (NSFileVersion doesn't simply use NSFileCoordinator itself because that would be insufficient when the adding or removing of versions is part of a larger operation that should be treated as one coordinated file access.)
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param contents_url Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileVersion add_version_of_item_at_url(const URL& url, const URL& contents_url, FileVersionAddingOptions options);
        /**
     * @brief Calls `+[NSFileVersion currentVersionOfItemAtURL:]`.
     * @details Return an NSFileVersion that represents the contents of the file located by a URL, or nil if there is no such file.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileVersion current_version_of_item_at_url(const URL& url);
        /**
     * @brief Calls `+[NSFileVersion getNonlocalVersionsOfItemAtURL:completionHandler:]`.
     * @details Asynchronously return an array of NSFileVersions associated with the file located by the given URL, or nil if there is no such file or another error occurs. Versions returned by this method do not initially have their contents stored locally on the device, so a download may be required before you are able to access them. File attributes are accessible via -[NSURL getPromisedItemResourceValue:forKey:error:]. You can request a download by performing a coordinated read with NSFileCoordinator on the URL property of the resulting NSFileVersions. When a version is successfully downloaded, its contents are cached locally, and the version will no longer be returned by this method. The version will be returned by +[NSFileVersion otherVersionsOfItemAtURL:] instead, but will retain the same persistentIdentifier value. If the local version is later discarded, future invocations of this method may resume returning the version. If you need to get all versions for a document, both local and non-local, you should use an NSFilePresenter that implements -presentedItemDidGainVersion: and -presentedItemDidLoseVersion: and invoke +[NSFileCoordinator addFilePresenter:], +[NSFileVersion otherVersionsOfItemAtURL:], and this method within a single coordinated read.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        static void get_nonlocal_versions_of_item_at_url(const URL& url, std::function<void(std::vector<FileVersion>, Error)> completion_handler);
        /**
     * @brief Calls `+[NSFileVersion otherVersionsOfItemAtURL:]`.
     * @details Return an array of NSFileVersions associated with the file located by a URL, or nil if there is no such file. The array never contains an NSFileVersion equal to what +currentVersionOfItemAtURL: would return.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<FileVersion> other_versions_of_item_at_url(const URL& url);
        /**
     * @brief Calls `-[NSFileVersion removeAndReturnError:]`.
     * @details Delete the receiver's storage, and return YES if successful. If not successful, return NO after setting outError to an NSError that encapsulates why not. Subsequent invocations of +versionsOfItemAtURL: won't include an NSFileVersion for a successfully removed version. You cannot use this method to delete the versioned file itself. This method always throws an exception when sent to the result of invoking +currentVersionOfItemAtURL:. Use -[NSFileManager removeItemAtURL:error:] for that instead. When removing versions of a file you should do it as part of a coordinated write to the file. The advice about this for +addVersionOfItemAtURL:withContentsOfURL:options:error: applies here too.
     * @return The converted Objective-C result.
     */
        bool remove_and_return_error() const;
        /**
     * @brief Calls `+[NSFileVersion removeOtherVersionsOfItemAtURL:error:]`.
     * @details Delete all of the versions associated with the file located by a URL, except for the current one, and return YES if successful. If not successful, return NO after setting outError to an NSError that encapsulates why not. When removing versions of a file you should do it as part of a coordinated write to the file. The advice about this for +addVersionOfItemAtURL:withContentsOfURL:options:error: applies here too.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool remove_other_versions_of_item_at_url(const URL& url);
        /**
     * @brief Calls `-[NSFileVersion replaceItemAtURL:options:error:]`.
     * @details If the passed-in URL locates a file, replace the file with a file whose contents are taken from the version but whose display name is taken from the file. If the passed-in URL does not locate a file then simply write one. If successful, return a URL that locates the resulting file; it may be different from the passed-in URL. The one exception to taking the display name from an existing file is if the version is of a different type than the overwritten file. In that case the file name extension will be taken from the version. (When file name extensions are being hidden in a user-friendly way this is not actually an exception.) If not successful, return NO after setting outError to an NSError that encapsulates why not. When you use NSFileVersionReplacingByMoving you remove a version of the file, and should do it as part of a coordinated write to the file. The advice about this for +addVersionOfItemAtURL:withContentsOfURL:options:error: applies here too. When you use it to promote a version to a separate file you actually write to two files, and should do it as part of a coordinated write to two files, using -[NSFileCoordinator coordinateWritingItemAtURL:options:writingItemAtURL:options:error:byAccessor:], most likely using NSFileCoordinatorWritingForReplacing for the file you're promoting the version to.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL replace_item_at_url(const URL& url, FileVersionReplacingOptions options) const;
        /**
     * @brief Calls `+[NSFileVersion temporaryDirectoryURLForNewVersionOfItemAtURL:]`.
     * @details Given a URL, create a new directory that is suitable for using as the container of a new temporary file that you will create and use with NSFileVersionAddingByMoving. This is useful when you want to create a new version of a file out of something other than the file's current contents, for example, the contents in memory of a document that has not yet been saved to its file. You must remove this directory when you are done with it, using -[NSFileManager removeItemAtURL:error:] for example.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL temporary_directory_url_for_new_version_of_item_at_url(const URL& url);
        /**
     * @brief Calls `+[NSFileVersion unresolvedConflictVersionsOfItemAtURL:]`.
     * @details Return an array of NSFileVersions that represent unresolved conflicts for the file located by a URL, or nil if there is no such file.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<FileVersion> unresolved_conflict_versions_of_item_at_url(const URL& url);
        /**
     * @brief Calls `+[NSFileVersion versionOfItemAtURL:forPersistentIdentifier:]`.
     * @details For a file located by a URL, return the NSFileVersion identified by a persistent identifier of the sort returned by -persistentIdentifier, or nil if the version no longer exists.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param persistent_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileVersion version_of_item_at_url(const URL& url, const Object& persistent_identifier);
        /**
     * @brief Returns the `URL` property of `NSFileVersion`.
     * @details The location of the receiver's storage, or possibly nil if the receiver's storage has been deleted. The storage is read-only. The URL will have an arcane path. You must not derive user-presentable text from it.
     * @return The converted Objective-C result.
     */
        URL url() const;
        /**
     * @brief Returns the `conflict` property of `NSFileVersion`.
     * @details Whether the version was created as a result of the discovery of a conflict between two writers of the versioned file.
     * @return The converted Objective-C result.
     */
        bool is_conflict() const;
        /**
     * @brief Returns the `discardable` property of `NSFileVersion`.
     * @details Whether the system is allowed to automatically delete the receiver's storage in the future, at an unpredictable time. Setting this to YES can fail so you must not depend on discarding for correct operation. Once you have indicated that a version is discardable you cannot make it undiscardable again. Setting this to NO causes an exception to be thrown. You cannot make the versioned file itself discardable. Setting the value of this property always throws an exception when sent to the result of invoking +currentVersionOfItemAtURL:. Versions can be discardable only on Mac OS X.
     * @return The converted Objective-C result.
     */
        bool is_discardable() const;
        /**
     * @brief Sets the `discardable` property of `NSFileVersion`.
     * @details Whether the system is allowed to automatically delete the receiver's storage in the future, at an unpredictable time. Setting this to YES can fail so you must not depend on discarding for correct operation. Once you have indicated that a version is discardable you cannot make it undiscardable again. Setting this to NO causes an exception to be thrown. You cannot make the versioned file itself discardable. Setting the value of this property always throws an exception when sent to the result of invoking +currentVersionOfItemAtURL:. Versions can be discardable only on Mac OS X.
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
     * @details The user-presentable name of the version, or possibly nil if the receiver's storage has been deleted. This will be different from the user-presentable name of the versioned file if, for example, the file has been renamed since the version was added.
     * @return The converted Objective-C result.
     */
        std::string localized_name() const;
        /**
     * @brief Returns the `localizedNameOfSavingComputer` property of `NSFileVersion`.
     * @details The user-presentable name of the computer on which the version was saved, or possibly nil if the receiver's storage has been deleted, or nil if no computer name was recorded. The computer name is guaranteed to have been recorded only if the version is a conflict version. This will be different from that computer's current name if the computer's name has been changed since the version was retrieved from that computer.
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
     * @details If the version is a conflict version, whether the conflict has been resolved. If the version is not a conflict version, simply YES. The operating system's reaction to your setting this to YES is complicated and subject to change in future releases. One result however is that the version won't appear in arrays returned by +unresolvedConflictVersionsOfItemAtURL: anymore, unless setting fails. Once you have indicated that a conflict has been resolved you cannot make it unresolved again. Setting this to NO causes an exception to be thrown.
     * @return The converted Objective-C result.
     */
        bool is_resolved() const;
        /**
     * @brief Sets the `resolved` property of `NSFileVersion`.
     * @details If the version is a conflict version, whether the conflict has been resolved. If the version is not a conflict version, simply YES. The operating system's reaction to your setting this to YES is complicated and subject to change in future releases. One result however is that the version won't appear in arrays returned by +unresolvedConflictVersionsOfItemAtURL: anymore, unless setting fails. Once you have indicated that a conflict has been resolved you cannot make it unresolved again. Setting this to NO causes an exception to be thrown.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_resolved(bool value) const;
    };
}
