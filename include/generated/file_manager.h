#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;
    class DirectoryEnumeratorBase;
    class Error;
    class FileProviderService;
    class FileVersion;
    class URL;
    class WorkspaceAuthorization;

    /**
     * @brief C++ handle for the Objective-C class `NSFileManager` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::FileManager file_manager;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::FileManager file_manager{};
     * auto made_0 = cocoon::FileManager::file_manager_with_authorization(cocoon::WorkspaceAuthorization());
     * file_manager.url_for_directory(cocoon::SearchPathDirectory::ApplicationDirectory, cocoon::SearchPathDomainMask::UserDomainMask, cocoon::URL(), true);
     * file_manager.url_for_ubiquity_container_identifier("text");
     * file_manager.ur_ls_for_directory(cocoon::SearchPathDirectory::ApplicationDirectory, cocoon::SearchPathDomainMask::UserDomainMask);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsfilemanager
     */
    class FileManager : public Object
    {
    public:
        /// @brief Creates a new `NSFileManager` instance and returns a handle to it.
        explicit FileManager();
        /// @brief Creates a null handle that refers to no native object.
        FileManager(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit FileManager(Adopt adopt);
        /**
     * @brief Calls `-[NSFileManager URLForDirectory:inDomain:appropriateForURL:create:error:]`.
     * @details -URLForDirectory:inDomain:appropriateForURL:create:error: is a URL-based replacement for FSFindFolder(). It allows for the specification and (optional) creation of a specific directory for a particular purpose (e.g. the replacement of a particular item on disk, or a particular Library directory. You may pass only one of the values from the NSSearchPathDomainMask enumeration, and you may not pass NSAllDomainsMask.
     * @param directory Argument converted to the Objective-C parameter of the same role.
     * @param domain Argument converted to the Objective-C parameter of the same role.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param should_create Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_for_directory(SearchPathDirectory directory, SearchPathDomainMask domain, const URL& url, bool should_create) const;
        /**
     * @brief Calls `-[NSFileManager URLForPublishingUbiquitousItemAtURL:expirationDate:error:]`.
     * @details Returns a URL that can be shared with other users to allow them download a copy of the specified ubiquitous item. Also returns the date after which the item will no longer be accessible at the returned URL. The URL must be prefixed with a URL from -URLForUbiquityContainerIdentifier:.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param out_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_for_publishing_ubiquitous_item_at_url(const URL& url, Date& out_date) const;
        /**
     * @brief Calls `-[NSFileManager URLForUbiquityContainerIdentifier:]`.
     * @details Returns a file URL for the root of the ubiquity container directory corresponding to the supplied container ID. Returns nil if the mobile container does not exist or could not be determined.
     * @param container_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_for_ubiquity_container_identifier(const std::string& container_identifier) const;
        /**
     * @brief Calls `-[NSFileManager URLsForDirectory:inDomains:]`.
     * @details -URLsForDirectory:inDomains: is analogous to NSSearchPathForDirectoriesInDomains(), but returns an array of NSURL instances for use with URL-taking APIs. This API is suitable when you need to search for a file or files which may live in one of a variety of locations in the domains specified.
     * @param directory Argument converted to the Objective-C parameter of the same role.
     * @param domain_mask Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<URL> ur_ls_for_directory(SearchPathDirectory directory, SearchPathDomainMask domain_mask) const;
        /**
     * @brief Calls `-[NSFileManager attributesOfFileSystemForPath:error:]`.
     * @details attributesOfFileSystemForPath:error: returns an NSDictionary of key/value pairs containing the attributes of the filesystem containing the provided path. If this method returns 'nil', an NSError will be returned by reference in the 'error' parameter. This method does not traverse a terminal symlink. This method replaces fileSystemAttributesAtPath:.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> attributes_of_file_system_for_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager attributesOfItemAtPath:error:]`.
     * @details attributesOfItemAtPath:error: returns an NSDictionary of key/value pairs containing the attributes of the item (file, directory, symlink, etc.) at the path in question. If this method returns 'nil', an NSError will be returned by reference in the 'error' parameter. This method does not traverse a terminal symlink. This method replaces fileAttributesAtPath:traverseLink:.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> attributes_of_item_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager changeCurrentDirectoryPath:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool change_current_directory_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager componentsToDisplayForPath:]`.
     * @details componentsToDisplayForPath: returns an NSArray of display names for the path provided. Localization will occur as in displayNameAtPath: above. This array cannot and should not be reassembled into an usable filesystem path for any kind of access.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> components_to_display_for_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager containerURLForSecurityApplicationGroupIdentifier:]`.
     * @details Returns the container directory associated with the specified security application group ID.
     * @param group_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL container_url_for_security_application_group_identifier(const std::string& group_identifier) const;
        /**
     * @brief Calls `-[NSFileManager contentsAtPath:]`.
     * @details These methods are provided here for compatibility. The corresponding methods on NSData which return NSErrors should be regarded as the primary method of creating a file from an NSData or retrieving the contents of a file as an NSData.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> contents_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager contentsEqualAtPath:andPath:]`.
     * @details -contentsEqualAtPath:andPath: does not take into account data stored in the resource fork or filesystem extended attributes.
     * @param path1 Argument converted to the Objective-C parameter of the same role.
     * @param path2 Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool contents_equal_at_path(const std::string& path1, const std::string& path2) const;
        /**
     * @brief Calls `-[NSFileManager contentsOfDirectoryAtPath:error:]`.
     * @details contentsOfDirectoryAtPath:error: returns an NSArray of NSStrings representing the filenames of the items in the directory. If this method returns 'nil', an NSError will be returned by reference in the 'error' parameter. If the directory contains no items, this method will return the empty array. This method replaces directoryContentsAtPath:
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> contents_of_directory_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager contentsOfDirectoryAtURL:includingPropertiesForKeys:options:error:]`.
     * @details -contentsOfDirectoryAtURL:includingPropertiesForKeys:options:error: returns an NSArray of NSURLs identifying the the directory entries. If this method returns nil, an NSError will be returned by reference in the 'error' parameter. If the directory contains no entries, this method will return the empty array. When an array is specified for the 'keys' parameter, the specified property values will be pre-fetched and cached with each enumerated URL. This method always does a shallow enumeration of the specified directory (i.e. it always acts as if NSDirectoryEnumerationSkipsSubdirectoryDescendants has been specified). If you need to perform a deep enumeration, use -[NSFileManager enumeratorAtURL:includingPropertiesForKeys:options:errorHandler:]. If you wish to only receive the URLs and no other attributes, then pass '0' for 'options' and an empty NSArray ('[NSArray array]') for 'keys'. If you wish to have the property caches of the vended URLs pre-populated with a default set of attributes, then pass '0' for 'options' and 'nil' for 'keys'.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param keys Argument converted to the Objective-C parameter of the same role.
     * @param mask Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<URL> contents_of_directory_at_url(const URL& url, const std::vector<std::string>& keys, DirectoryEnumerationOptions mask) const;
        /**
     * @brief Calls `-[NSFileManager copyItemAtPath:toPath:error:]`.
     * @details These methods replace their non-error returning counterparts below. See the NSFileManagerDelegate protocol below for methods that are dispatched to the NSFileManager instance's delegate.
     * @param src_path Argument converted to the Objective-C parameter of the same role.
     * @param dst_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool copy_item_at_path(const std::string& src_path, const std::string& dst_path) const;
        /**
     * @brief Calls `-[NSFileManager copyItemAtURL:toURL:error:]`.
     * @details These methods are URL-taking equivalents of the four methods above. Their delegate methods are defined in the NSFileManagerDelegate protocol below.
     * @param src_url Argument converted to the Objective-C parameter of the same role.
     * @param dst_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool copy_item_at_url(const URL& src_url, const URL& dst_url) const;
        /**
     * @brief Calls `-[NSFileManager createDirectoryAtPath:withIntermediateDirectories:attributes:error:]`.
     * @details createDirectoryAtPath:withIntermediateDirectories:attributes:error: creates a directory at the specified path. If you pass 'NO' for createIntermediates, the directory must not exist at the time this call is made. Passing 'YES' for 'createIntermediates' will create any necessary intermediate directories. This method returns YES if all directories specified in 'path' were created and attributes were set. Directories are created with attributes specified by the dictionary passed to 'attributes'. If no dictionary is supplied, directories are created according to the umask of the process. This method returns NO if a failure occurs at any stage of the operation. If an error parameter was provided, a presentable NSError will be returned by reference. This method replaces createDirectoryAtPath:attributes:
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param create_intermediates Argument converted to the Objective-C parameter of the same role.
     * @param attributes Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool create_directory_at_path(const std::string& path, bool create_intermediates, const std::map<std::string, Object>& attributes) const;
        /**
     * @brief Calls `-[NSFileManager createDirectoryAtURL:withIntermediateDirectories:attributes:error:]`.
     * @details createDirectoryAtURL:withIntermediateDirectories:attributes:error: creates a directory at the specified URL. If you pass 'NO' for withIntermediateDirectories, the directory must not exist at the time this call is made. Passing 'YES' for withIntermediateDirectories will create any necessary intermediate directories. This method returns YES if all directories specified in 'url' were created and attributes were set. Directories are created with attributes specified by the dictionary passed to 'attributes'. If no dictionary is supplied, directories are created according to the umask of the process. This method returns NO if a failure occurs at any stage of the operation. If an error parameter was provided, a presentable NSError will be returned by reference.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param create_intermediates Argument converted to the Objective-C parameter of the same role.
     * @param attributes Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool create_directory_at_url(const URL& url, bool create_intermediates, const std::map<std::string, Object>& attributes) const;
        /**
     * @brief Calls `-[NSFileManager createFileAtPath:contents:attributes:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @param attr Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool create_file_at_path(const std::string& path, const std::vector<std::uint8_t>& data, const std::map<std::string, Object>& attr) const;
        /**
     * @brief Calls `-[NSFileManager createSymbolicLinkAtPath:withDestinationPath:error:]`.
     * @details createSymbolicLinkAtPath:withDestination:error: returns YES if the symbolic link that point at 'destPath' was able to be created at the location specified by 'path'. If this method returns NO, the link was unable to be created and an NSError will be returned by reference in the 'error' parameter. This method does not traverse a terminal symlink. This method replaces createSymbolicLinkAtPath:pathContent:
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param dest_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool create_symbolic_link_at_path(const std::string& path, const std::string& dest_path) const;
        /**
     * @brief Calls `-[NSFileManager createSymbolicLinkAtURL:withDestinationURL:error:]`.
     * @details createSymbolicLinkAtURL:withDestinationURL:error: returns YES if the symbolic link that point at 'destURL' was able to be created at the location specified by 'url'. 'destURL' is always resolved against its base URL, if it has one. If 'destURL' has no base URL and it's 'relativePath' is indeed a relative path, then a relative symlink will be created. If this method returns NO, the link was unable to be created and an NSError will be returned by reference in the 'error' parameter. This method does not traverse a terminal symlink.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param dest_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool create_symbolic_link_at_url(const URL& url, const URL& dest_url) const;
        /**
     * @brief Calls `-[NSFileManager destinationOfSymbolicLinkAtPath:error:]`.
     * @details destinationOfSymbolicLinkAtPath:error: returns an NSString containing the path of the item pointed at by the symlink specified by 'path'. If this method returns 'nil', an NSError will be returned by reference in the 'error' parameter. This method replaces pathContentOfSymbolicLinkAtPath:
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string destination_of_symbolic_link_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager displayNameAtPath:]`.
     * @details displayNameAtPath: returns an NSString suitable for presentation to the user. For directories which have localization information, this will return the appropriate localized string. This string is not suitable for passing to anything that must interact with the filesystem.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string display_name_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager enumeratorAtPath:]`.
     * @details enumeratorAtPath: returns an NSDirectoryEnumerator rooted at the provided path. If the enumerator cannot be created, this returns NULL. Because NSDirectoryEnumerator is a subclass of NSEnumerator, the returned object can be used in the for...in construct.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DirectoryEnumeratorBase enumerator_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager enumeratorAtURL:includingPropertiesForKeys:options:errorHandler:]`.
     * @details enumeratorAtURL:includingPropertiesForKeys:options:errorHandler: returns an NSDirectoryEnumerator rooted at the provided directory URL. The NSDirectoryEnumerator returns NSURLs from the -nextObject method. The optional 'includingPropertiesForKeys' parameter indicates which resource properties should be pre-fetched and cached with each enumerated URL. The optional 'errorHandler' block argument is invoked when an error occurs. Parameters to the block are the URL on which an error occurred and the error. When the error handler returns YES, enumeration continues if possible. Enumeration stops immediately when the error handler returns NO. If you wish to only receive the URLs and no other attributes, then pass '0' for 'options' and an empty NSArray ('[NSArray array]') for 'keys'. If you wish to have the property caches of the vended URLs pre-populated with a default set of attributes, then pass '0' for 'options' and 'nil' for 'keys'.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param keys Argument converted to the Objective-C parameter of the same role.
     * @param mask Argument converted to the Objective-C parameter of the same role.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DirectoryEnumeratorBase enumerator_at_url(const URL& url, const std::vector<std::string>& keys, DirectoryEnumerationOptions mask, std::function<bool(URL, Error)> handler) const;
        /**
     * @brief Calls `-[NSFileManager evictUbiquitousItemAtURL:error:]`.
     * @details Removes the local instance of the ubiquitous item at the given URL. Returns YES if removal was successful, NO otherwise.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool evict_ubiquitous_item_at_url(const URL& url) const;
        /**
     * @brief Calls `-[NSFileManager fetchLatestRemoteVersionOfItemAtURL:completionHandler:]`.
     * @details Asynchronously fetches the latest remote version of a given item from the server. Use this method if uploading fails due to a version conflict and sync is paused. In this case, fetching the latest remote version allows you to inspect the newer item from the server, resolve the conflict, and resume uploading. The version provided by this call depends on several factors: If there is no newer version of the file on the server, the caller receives the current version of the file. If the server has a newer version and sync isn't paused, this call replaces the local item and provides the version of the new item. If the server has a newer version but sync is paused, the returned version points to a side location. In this case, call ''NSFileVersion/replaceItem(at:options:)'' on the provided version object to replace the local item with the newer item from the server. If the device isn't connected to the network, the call may fail with ''NSFileReadUnknownError-enum.case'', with the underlying error of \<doc://com.apple.documentation/documentation/FileProvider/NSFileProviderError/serverUnreachable>. - Parameters: - url: The URL of the item for which to check the version. - completionHandler: A closure or block that the framework calls when the fetch action completes. It receives parameters of types ''NSFileVersion'' and ''NSError''. The error is 'nil' if fetching the remote version succeeded; otherwise it indicates the error that caused the call to fail. In Swift, you can omit the completion handler, catching any error in a 'do'-'catch' block and receiving the version as the return value.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void fetch_latest_remote_version_of_item_at_url(const URL& url, std::function<void(FileVersion, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSFileManager fileExistsAtPath:]`.
     * @details The following methods are of limited utility. Attempting to predicate behavior based on the current state of the filesystem or a particular file on the filesystem is encouraging odd behavior in the face of filesystem race conditions. It's far better to attempt an operation (like loading a file or creating a directory) and handle the error gracefully than it is to try to figure out ahead of time whether the operation will succeed.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool file_exists_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager fileExistsAtPath:isDirectory:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param is_directory Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool file_exists_at_path(const std::string& path, bool* is_directory) const;
        /**
     * @brief Calls `+[NSFileManager fileManagerWithAuthorization:]`.
     * @param authorization Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileManager file_manager_with_authorization(const WorkspaceAuthorization& authorization);
        /**
     * @brief Calls `-[NSFileManager fileSystemRepresentationWithPath:]`.
     * @details fileSystemRepresentationWithPath: returns an array of characters suitable for passing to lower-level POSIX style APIs. The string is provided in the representation most appropriate for the filesystem in question.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string file_system_representation_with_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager getFileProviderServicesForItemAtURL:completionHandler:]`.
     * @details Asynchronously returns a dictionary of zero or more NSFileProviderService instances, which enable your application to instruct the file's provider to take various actions on or with regards to the given URL. To do this, first identify an NSFileProviderService object whose name matches the service you wish to use. Then get an NSXPCConnection from it and set up its NSXPCInterface with the protocol that matches the service's name. You'll need to refer to external documentation or an SDK supplied by the provider to get this information. Once an NSXPCConnection is obtained, you must finish configuring it and send it -resume. Failure to do so will result in leaking system resources.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void get_file_provider_services_for_item_at_url(const URL& url, std::function<void(std::map<std::string, FileProviderService>, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSFileManager getRelationship:ofDirectory:inDomain:toItemAtURL:error:]`.
     * @details Similar to -[NSFileManager getRelationship:ofDirectoryAtURL:toItemAtURL:error:], except that the directory is instead defined by an NSSearchPathDirectory and NSSearchPathDomainMask. Pass 0 for domainMask to instruct the method to automatically choose the domain appropriate for 'url'. For example, to discover if a file is contained by a Trash directory, call [fileManager getRelationship:&result ofDirectory:NSTrashDirectory inDomain:0 toItemAtURL:url error:&error].
     * @param out_relationship Argument converted to the Objective-C parameter of the same role.
     * @param directory Argument converted to the Objective-C parameter of the same role.
     * @param domain_mask Argument converted to the Objective-C parameter of the same role.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool get_relationship(URLRelationship* out_relationship, SearchPathDirectory directory, SearchPathDomainMask domain_mask, const URL& url) const;
        /**
     * @brief Calls `-[NSFileManager getRelationship:ofDirectoryAtURL:toItemAtURL:error:]`.
     * @details Sets 'outRelationship' to NSURLRelationshipContains if the directory at 'directoryURL' directly or indirectly contains the item at 'otherURL', meaning 'directoryURL' is found while enumerating parent URLs starting from 'otherURL'. Sets 'outRelationship' to NSURLRelationshipSame if 'directoryURL' and 'otherURL' locate the same item, meaning they have the same NSURLFileResourceIdentifierKey value. If 'directoryURL' is not a directory, or does not contain 'otherURL' and they do not locate the same file, then sets 'outRelationship' to NSURLRelationshipOther. If an error occurs, returns NO and sets 'error'.
     * @param out_relationship Argument converted to the Objective-C parameter of the same role.
     * @param directory_url Argument converted to the Objective-C parameter of the same role.
     * @param other_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool get_relationship(URLRelationship* out_relationship, const URL& directory_url, const URL& other_url) const;
        /**
     * @brief Calls `-[NSFileManager homeDirectoryForUser:]`.
     * @param user_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL home_directory_for_user(const std::string& user_name) const;
        /**
     * @brief Calls `-[NSFileManager isDeletableFileAtPath:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_deletable_file_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager isExecutableFileAtPath:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_executable_file_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager isReadableFileAtPath:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_readable_file_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager isUbiquitousItemAtURL:]`.
     * @details Returns YES if the item for the specified URL is ubiquitous, NO otherwise.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_ubiquitous_item_at_url(const URL& url) const;
        /**
     * @brief Calls `-[NSFileManager isWritableFileAtPath:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_writable_file_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager linkItemAtPath:toPath:error:]`.
     * @param src_path Argument converted to the Objective-C parameter of the same role.
     * @param dst_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool link_item_at_path(const std::string& src_path, const std::string& dst_path) const;
        /**
     * @brief Calls `-[NSFileManager linkItemAtURL:toURL:error:]`.
     * @param src_url Argument converted to the Objective-C parameter of the same role.
     * @param dst_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool link_item_at_url(const URL& src_url, const URL& dst_url) const;
        /**
     * @brief Calls `-[NSFileManager mountedVolumeURLsIncludingResourceValuesForKeys:options:]`.
     * @details -mountedVolumeURLsIncludingResourceValuesForKeys:options: returns an NSArray of NSURLs locating the mounted volumes available on the computer. The property keys that can be requested are available in \<Foundation/NSURL.h>.
     * @param property_keys Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<URL> mounted_volume_ur_ls_including_resource_values_for_keys(const std::vector<std::string>& property_keys, VolumeEnumerationOptions options) const;
        /**
     * @brief Calls `-[NSFileManager moveItemAtPath:toPath:error:]`.
     * @param src_path Argument converted to the Objective-C parameter of the same role.
     * @param dst_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool move_item_at_path(const std::string& src_path, const std::string& dst_path) const;
        /**
     * @brief Calls `-[NSFileManager moveItemAtURL:toURL:error:]`.
     * @param src_url Argument converted to the Objective-C parameter of the same role.
     * @param dst_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool move_item_at_url(const URL& src_url, const URL& dst_url) const;
        /**
     * @brief Calls `-[NSFileManager pauseSyncForUbiquitousItemAtURL:completionHandler:]`.
     * @details Asynchronously pauses sync of an item at the given URL. Call this when opening an item to prevent sync from altering the contents of the URL. Once paused, the file provider will not upload local changes nor download remote changes. While paused, call ''uploadLocalVersionOfUbiquitousItem(at:withConflictResolutionPolicy:completionHandler:)'' when the document is in a stable state. This action keeps the server version as up-to-date as possible. If the item is already paused, a second call to this method reports success. If the file provider is already applying changes to the item, the pause fails with an ''NSFileWriteUnknownError-enum.case'', with an underlying error that has domain ''NSPOSIXErrorDomain'' and code ''POSIXError/EBUSY''. If the pause fails, wait for the state to stabilize before retrying. Pausing also fails with ''CocoaError/featureUnsupported'' if 'url' refers to a regular (non-package) directory. Pausing sync is independent of the calling app's lifecycle; sync doesn't automatically resume if the app closes or crashes and relaunches later. To resume syncing, explicitly call ''resumeSyncForUbiquitousItem(at:with:completionHandler:)''. Always be sure to resume syncing before you close the item. - Parameters: - url: The URL of the item for which to pause sync. - completionHandler: A closure or block that the framework calls when the pause action completes. It receives a single ''NSError'' parameter to indicate an error that prevented pausing; this value is 'nil' if the pause succeeded. In Swift, you can omit the completion handler and catch the thrown error instead.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void pause_sync_for_ubiquitous_item_at_url(const URL& url, std::function<void(Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSFileManager removeItemAtPath:error:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool remove_item_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager removeItemAtURL:error:]`.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool remove_item_at_url(const URL& url) const;
        /**
     * @brief Calls `-[NSFileManager replaceItemAtURL:withItemAtURL:backupItemName:options:resultingItemURL:error:]`.
     * @details -replaceItemAtURL:withItemAtURL:backupItemName:options:resultingItemURL:error: is for developers who wish to perform a safe-save without using the full NSDocument machinery that is available in the AppKit. The 'originalItemURL' is the item being replaced. 'newItemURL' is the item which will replace the original item. This item should be placed in a temporary directory as provided by the OS, or in a uniquely named directory placed in the same directory as the original item if the temporary directory is not available. If 'backupItemName' is provided, that name will be used to create a backup of the original item. The backup is placed in the same directory as the original item. If an error occurs during the creation of the backup item, the operation will fail. If there is already an item with the same name as the backup item, that item will be removed. The backup item will be removed in the event of success unless the 'NSFileManagerItemReplacementWithoutDeletingBackupItem' option is provided in 'options'. For 'options', pass '0' to get the default behavior, which uses only the metadata from the new item while adjusting some properties using values from the original item. Pass 'NSFileManagerItemReplacementUsingNewMetadataOnly' in order to use all possible metadata from the new item.
     * @param original_item_url Argument converted to the Objective-C parameter of the same role.
     * @param new_item_url Argument converted to the Objective-C parameter of the same role.
     * @param backup_item_name Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param resulting_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool replace_item_at_url(const URL& original_item_url, const URL& new_item_url, const std::string& backup_item_name, FileManagerItemReplacementOptions options, URL& resulting_url) const;
        /**
     * @brief Calls `-[NSFileManager resumeSyncForUbiquitousItemAtURL:withBehavior:completionHandler:]`.
     * @details Asynchronously resumes the sync on a paused item using the given resume behavior. Always call this method when your app closes an item to allow the file provider to sync local changes back to the server. In most situations, the ''NSFileManagerResumeSyncBehavior/preserveLocalChanges'' behavior is the best choice to avoid any risk of data loss. The resume call fails with ''CocoaError/featureUnsupported'' if 'url' isn't currently paused. If the device isn't connected to the network, the call may fail with ''NSFileWriteUnknownError-enum.case'', with the underlying error of \<doc://com.apple.documentation/documentation/FileProvider/NSFileProviderError/serverUnreachable>. - Parameters: - url: The URL of the item for which to resume sync. - behavior: A ''NSFileManagerResumeSyncBehavior'' value that tells the file manager how to handle conflicts between local and remote versions of files. - completionHandler: A closure or block that the framework calls when the resume action completes. It receives a single ''NSError'' parameter to indicate an error that prevented the resume action; the value is 'nil' if the resume succeeded. In Swift, you can omit the completion handler and catch the thrown error instead.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void resume_sync_for_ubiquitous_item_at_url(const URL& url, FileManagerResumeSyncBehavior behavior, std::function<void(Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSFileManager setAttributes:ofItemAtPath:error:]`.
     * @details setAttributes:ofItemAtPath:error: returns YES when the attributes specified in the 'attributes' dictionary are set successfully on the item specified by 'path'. If this method returns NO, a presentable NSError will be provided by-reference in the 'error' parameter. If no error is required, you may pass 'nil' for the error. This method replaces changeFileAttributes:atPath:.
     * @param attributes Argument converted to the Objective-C parameter of the same role.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_attributes(const std::map<std::string, Object>& attributes, const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager setUbiquitous:itemAtURL:destinationURL:error:]`.
     * @details Changes whether the item for the specified URL is ubiquitous and moves the item to the destination URL. When making an item ubiquitous, the destination URL must be prefixed with a URL from -URLForUbiquityContainerIdentifier:. Returns YES if the change is successful, NO otherwise.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param destination_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_ubiquitous(bool flag, const URL& url, const URL& destination_url) const;
        /**
     * @brief Calls `-[NSFileManager startDownloadingUbiquitousItemAtURL:error:]`.
     * @details Start downloading a local instance of the specified ubiquitous item, if necessary. Returns YES if the download started successfully or wasn't necessary, NO otherwise.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool start_downloading_ubiquitous_item_at_url(const URL& url) const;
        /**
     * @brief Calls `-[NSFileManager stringWithFileSystemRepresentation:length:]`.
     * @details stringWithFileSystemRepresentation:length: returns an NSString created from an array of bytes that are in the filesystem representation.
     * @param str Argument converted to the Objective-C parameter of the same role.
     * @param len Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_with_file_system_representation(const std::string& str, std::uint64_t len) const;
        /**
     * @brief Calls `-[NSFileManager subpathsAtPath:]`.
     * @details subpathsAtPath: returns an NSArray of all contents and subpaths recursively from the provided path. This may be very expensive to compute for deep filesystem hierarchies, and should probably be avoided.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> subpaths_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager subpathsOfDirectoryAtPath:error:]`.
     * @details subpathsOfDirectoryAtPath:error: returns an NSArray of NSStrings representing the filenames of the items in the specified directory and all its subdirectories recursively. If this method returns 'nil', an NSError will be returned by reference in the 'error' parameter. If the directory contains no items, this method will return the empty array. This method replaces subpathsAtPath:
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> subpaths_of_directory_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager trashItemAtURL:resultingItemURL:error:]`.
     * @details trashItemAtURL:resultingItemURL:error: returns YES if the item at 'url' was successfully moved to a Trash. Since the operation may require renaming the file to avoid collisions, it also returns by reference the resulting URL that the item was moved to. If this method returns NO, the item was not moved and an NSError will be returned by reference in the 'error' parameter. To easily discover if an item is in the Trash, you may use [fileManager getRelationship:&result ofDirectory:NSTrashDirectory inDomain:0 toItemAtURL:url error:&error] && result == NSURLRelationshipContains.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param out_resulting_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool trash_item_at_url(const URL& url, URL& out_resulting_url) const;
        /**
     * @brief Calls `-[NSFileManager unmountVolumeAtURL:options:completionHandler:]`.
     * @details This method starts the process of unmounting the volume specified by url. If the volume is encrypted, it is re-locked after being unmounted. The completionHandler will be executed when the operation is complete. If the operation was successful, the block’s errorOrNil argument will be nil; otherwise, errorOrNil will be an error object indicating why the unmount operation failed.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param mask Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void unmount_volume_at_url(const URL& url, FileManagerUnmountOptions mask, std::function<void(Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSFileManager uploadLocalVersionOfUbiquitousItemAtURL:withConflictResolutionPolicy:completionHandler:]`.
     * @details Asynchronously uploads the local version of the item using the provided conflict resolution policy. Once your app pauses a sync for an item, call this method every time your document is in a stable state. This action keeps the server version as up-to-date as possible. If the server has a newer version than the one to which the app made changes, uploading fails with ''NSFileWriteUnknownError-enum.case'', with an underlying error of \<doc://com.apple.documentation/documentation/FileProvider/NSFileProviderError/localVersionConflictingWithServer>. In this case, call ''FileManager/fetchLatestRemoteVersionOfItem(at:completionHandler:)'', rebase local changes on top of that version, and retry the upload. If the device isn't connected to the network, the call may fail with ''NSFileWriteUnknownError-enum.case'', with the underlying error of \<doc://com.apple.documentation/documentation/FileProvider/NSFileProviderError/serverUnreachable>. - Parameters: - url: The URL of the item for which to check the version. - conflictResolutionPolicy: The policy the file manager applies if the local and server versions conflict. - completionHandler: A closure or block that the framework calls when the upload completes. It receives parameters of types ''NSFileVersion'' and ''NSError''. The error is 'nil' if fetching the remote version succeeded; otherwise it indicates the error that caused the call to fail. In Swift, you can omit the completion handler, catching any error in a 'do'-'catch' block and receiving the version as the return value.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param conflict_resolution_policy Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void upload_local_version_of_ubiquitous_item_at_url(const URL& url, FileManagerUploadLocalVersionConflictPolicy conflict_resolution_policy, std::function<void(FileVersion, Error)> completion_handler) const;
        /**
     * @brief Returns the `currentDirectoryPath` property of `NSFileManager`.
     * @details Process working directory management. Despite the fact that these are instance methods on NSFileManager, these methods report and change (respectively) the working directory for the entire process. Developers are cautioned that doing so is fraught with peril.
     * @return The converted Objective-C result.
     */
        std::string current_directory_path() const;
        /**
     * @brief Returns the `defaultManager` property of `NSFileManager`.
     * @details Returns the default singleton instance.
     * @return The converted Objective-C result.
     */
        static FileManager default_manager();
        /**
     * @brief Returns the `homeDirectoryForCurrentUser` property of `NSFileManager`.
     * @return The converted Objective-C result.
     */
        URL home_directory_for_current_user() const;
        /**
     * @brief Returns the `temporaryDirectory` property of `NSFileManager`.
     * @return The converted Objective-C result.
     */
        URL temporary_directory() const;
        /// @brief Signal for the delegate/data-source method behind `should_copy_item_at_path_to_path`; connect a callback with `should_copy_item_at_path_to_path().connect(...)`.
        Signal<FileManager, bool(std::string, std::string)> should_copy_item_at_path_to_path() const
        {
            return Signal<FileManager, bool(std::string, std::string)>(handle(), "should_copy_item_at_path_to_path");
        }
        /// @brief Signal for the delegate/data-source method behind `should_copy_item_at_url_to_url`; connect a callback with `should_copy_item_at_url_to_url().connect(...)`.
        Signal<FileManager, bool(URL, URL)> should_copy_item_at_url_to_url() const
        {
            return Signal<FileManager, bool(URL, URL)>(handle(), "should_copy_item_at_url_to_url");
        }
        /// @brief Signal for the delegate/data-source method behind `should_proceed_after_error_copying_item_at_path_to_path`; connect a callback with `should_proceed_after_error_copying_item_at_path_to_path().connect(...)`.
        Signal<FileManager, bool(Error, std::string, std::string)> should_proceed_after_error_copying_item_at_path_to_path() const
        {
            return Signal<FileManager, bool(Error, std::string, std::string)>(handle(), "should_proceed_after_error_copying_item_at_path_to_path");
        }
        /// @brief Signal for the delegate/data-source method behind `should_proceed_after_error_copying_item_at_url_to_url`; connect a callback with `should_proceed_after_error_copying_item_at_url_to_url().connect(...)`.
        Signal<FileManager, bool(Error, URL, URL)> should_proceed_after_error_copying_item_at_url_to_url() const
        {
            return Signal<FileManager, bool(Error, URL, URL)>(handle(), "should_proceed_after_error_copying_item_at_url_to_url");
        }
        /// @brief Signal for the delegate/data-source method behind `should_move_item_at_path_to_path`; connect a callback with `should_move_item_at_path_to_path().connect(...)`.
        Signal<FileManager, bool(std::string, std::string)> should_move_item_at_path_to_path() const
        {
            return Signal<FileManager, bool(std::string, std::string)>(handle(), "should_move_item_at_path_to_path");
        }
        /// @brief Signal for the delegate/data-source method behind `should_move_item_at_url_to_url`; connect a callback with `should_move_item_at_url_to_url().connect(...)`.
        Signal<FileManager, bool(URL, URL)> should_move_item_at_url_to_url() const
        {
            return Signal<FileManager, bool(URL, URL)>(handle(), "should_move_item_at_url_to_url");
        }
        /// @brief Signal for the delegate/data-source method behind `should_proceed_after_error_moving_item_at_path_to_path`; connect a callback with `should_proceed_after_error_moving_item_at_path_to_path().connect(...)`.
        Signal<FileManager, bool(Error, std::string, std::string)> should_proceed_after_error_moving_item_at_path_to_path() const
        {
            return Signal<FileManager, bool(Error, std::string, std::string)>(handle(), "should_proceed_after_error_moving_item_at_path_to_path");
        }
        /// @brief Signal for the delegate/data-source method behind `should_proceed_after_error_moving_item_at_url_to_url`; connect a callback with `should_proceed_after_error_moving_item_at_url_to_url().connect(...)`.
        Signal<FileManager, bool(Error, URL, URL)> should_proceed_after_error_moving_item_at_url_to_url() const
        {
            return Signal<FileManager, bool(Error, URL, URL)>(handle(), "should_proceed_after_error_moving_item_at_url_to_url");
        }
        /// @brief Signal for the delegate/data-source method behind `should_link_item_at_path_to_path`; connect a callback with `should_link_item_at_path_to_path().connect(...)`.
        Signal<FileManager, bool(std::string, std::string)> should_link_item_at_path_to_path() const
        {
            return Signal<FileManager, bool(std::string, std::string)>(handle(), "should_link_item_at_path_to_path");
        }
        /// @brief Signal for the delegate/data-source method behind `should_link_item_at_url_to_url`; connect a callback with `should_link_item_at_url_to_url().connect(...)`.
        Signal<FileManager, bool(URL, URL)> should_link_item_at_url_to_url() const
        {
            return Signal<FileManager, bool(URL, URL)>(handle(), "should_link_item_at_url_to_url");
        }
        /// @brief Signal for the delegate/data-source method behind `should_proceed_after_error_linking_item_at_path_to_path`; connect a callback with `should_proceed_after_error_linking_item_at_path_to_path().connect(...)`.
        Signal<FileManager, bool(Error, std::string, std::string)> should_proceed_after_error_linking_item_at_path_to_path() const
        {
            return Signal<FileManager, bool(Error, std::string, std::string)>(handle(), "should_proceed_after_error_linking_item_at_path_to_path");
        }
        /// @brief Signal for the delegate/data-source method behind `should_proceed_after_error_linking_item_at_url_to_url`; connect a callback with `should_proceed_after_error_linking_item_at_url_to_url().connect(...)`.
        Signal<FileManager, bool(Error, URL, URL)> should_proceed_after_error_linking_item_at_url_to_url() const
        {
            return Signal<FileManager, bool(Error, URL, URL)>(handle(), "should_proceed_after_error_linking_item_at_url_to_url");
        }
        /// @brief Signal for the delegate/data-source method behind `should_remove_item_at_path`; connect a callback with `should_remove_item_at_path().connect(...)`.
        Signal<FileManager, bool(std::string)> should_remove_item_at_path() const
        {
            return Signal<FileManager, bool(std::string)>(handle(), "should_remove_item_at_path");
        }
        /// @brief Signal for the delegate/data-source method behind `should_remove_item_at_url`; connect a callback with `should_remove_item_at_url().connect(...)`.
        Signal<FileManager, bool(URL)> should_remove_item_at_url() const
        {
            return Signal<FileManager, bool(URL)>(handle(), "should_remove_item_at_url");
        }
        /// @brief Signal for the delegate/data-source method behind `should_proceed_after_error_removing_item_at_path`; connect a callback with `should_proceed_after_error_removing_item_at_path().connect(...)`.
        Signal<FileManager, bool(Error, std::string)> should_proceed_after_error_removing_item_at_path() const
        {
            return Signal<FileManager, bool(Error, std::string)>(handle(), "should_proceed_after_error_removing_item_at_path");
        }
        /// @brief Signal for the delegate/data-source method behind `should_proceed_after_error_removing_item_at_url`; connect a callback with `should_proceed_after_error_removing_item_at_url().connect(...)`.
        Signal<FileManager, bool(Error, URL)> should_proceed_after_error_removing_item_at_url() const
        {
            return Signal<FileManager, bool(Error, URL)>(handle(), "should_proceed_after_error_removing_item_at_url");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
