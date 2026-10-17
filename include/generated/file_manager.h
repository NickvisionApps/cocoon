#pragma once

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
     * @details A convenient interface to the contents of the file system, and the primary means of interacting with it. A file manager object lets you examine the contents of the file system and make changes to it. The ''FileManager'' class provides convenient access to a shared file manager object that is suitable for most types of file-related manipulations. A file manager object is typically your primary mode of interaction with the file system. You use it to locate, create, copy, and move files and directories. You also use it to get information about a file or directory or change some of its attributes. When specifying the location of files, you can use either ''NSURL'' or ''NSString'' objects. The use of the ''NSURL'' class is generally preferred for specifying file-system items because URLs can convert path information to a more efficient representation internally. You can also obtain a bookmark from an ''NSURL'' object, which is similar to an alias and offers a more sure way of locating the file or directory later. If you are moving, copying, linking, or removing files or directories, you can use a delegate in conjunction with a file manager object to manage those operations. The delegate's role is to affirm the operation and to decide whether to proceed when errors occur. In macOS 10.7 and later, the delegate must conform to the ''FileManagerDelegate'' protocol. In iOS 5.0 and later and in macOS 10.7 and later, ''FileManager'' includes methods for managing items stored in iCloud. Files and directories tagged for cloud storage are synced to iCloud so that they can be made available to the user's iOS devices and Macintosh computers. Changes to an item in one location are propagated to all other locations to ensure the items stay in sync. \#\#\# Threading considerations The methods of the shared ''FileManager'' object can be called from multiple threads safely. However, if you use a delegate to receive notifications about the status of move, copy, remove, and link operations, you should create a unique instance of the file manager object, assign your delegate to that object, and use that file manager to initiate your operations.
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
     * @details Locates and optionally creates the specified common directory in a domain. - Parameters: - directory: The search path directory. The supported values are described in ''FileManager/SearchPathDirectory''. - domain: The file system domain to search. The value for this parameter is one of the constants described in ''FileManager/SearchPathDomainMask''. You should specify only one domain for your search and you may not specify the ''FileManager/SearchPathDomainMask/allDomainsMask'' constant for this parameter. - url: The file URL used to determine the location of the returned URL. Only the volume of this parameter is used. This parameter is ignored unless the 'directory' parameter contains the value ''FileManager/SearchPathDirectory/itemReplacementDirectory'' and the 'domain' parameter contains the value ''FileManager/SearchPathDomainMask/userDomainMask''. - shouldCreate: Whether to create the directory if it does not already exist. When creating a temporary directory, this parameter is ignored and the directory is always created. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: The ''NSURL'' for the requested directory. When using Objective-C, if an error occurs, this method returns 'nil' and assigns an appropriate error object to the 'error' parameter. You typically use this method to locate one of the standard system directories, such as the 'Documents', 'Application Support' or 'Caches' directories. After locating (or creating) the desired directory, this method returns the URL for that directory. If more than one appropriate directory exists in the specified domain, this method returns only the first one it finds. > Important: > Passing a directory and domain pair that makes no sense (for example ''FileManager/SearchPathDirectory/desktopDirectory'' and ''FileManager/SearchPathDomainMask/networkDomainMask'') raises an exception. You can use this method to create a new temporary directory. To do so, specify ''FileManager/SearchPathDirectory/itemReplacementDirectory'' for the 'directory' parameter, ''FileManager/SearchPathDomainMask/userDomainMask'' for the 'domain' parameter, and a URL for the 'url' parameter which determines the volume of the returned URL. > Important: > If you use this method to create a temporary directory, you should not rely on the existence of that temporary directory after the app is exited. It is recommended that you remove any temporary directories that are created after they're no longer needed.
     * @param directory Argument converted to the Objective-C parameter of the same role.
     * @param domain Argument converted to the Objective-C parameter of the same role.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param should_create Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_for_directory(SearchPathDirectory directory, SearchPathDomainMask domain, const URL& url, bool should_create) const;
        /**
     * @brief Calls `-[NSFileManager URLForPublishingUbiquitousItemAtURL:expirationDate:error:]`.
     * @details Returns a URL that can be emailed to users to allow them to download a copy of a flat file item from iCloud. - Parameters: - url: The URL of the item in the cloud that you want to share. The URL must be prefixed with the base URL returned from the 'URLForUbiquityContainerIdentifier:' method that corresponds to the item's location. The file must be a flat file, not a bundle. The file at the specified URL must already be uploaded to iCloud when you call this method. - outDate: On input, a pointer to a variable for a date object. On output, this parameter contains the date after which the item is no longer available at the returned URL. You may specify 'nil' for this parameter if you are not interested in the date. - error: On input, a pointer to variable for an ''NSError'' object. If an error occurs, this pointer is set to an ''NSError'' object containing information about the error. You may specify 'nil' for this parameter if you do not want the error information. - Returns: A URL with which users can download a copy of the item at 'url'. In Objective-C, returns 'nil' if the URL could not be created for any reason. This method creates a snapshot of the specified flat file and places that copy in a temporary iCloud location where it can be accessed by other users using the returned URL. The snapshot reflects the contents of the file at the time the URL was generated and is not updated when subsequent changes are made to the original file in the user's iCloud storage. Your app must have access to the network for this call to succeed. If the specified file is in the process of being uploaded to iCloud, you must not call this method until the upload has finished. > Important: > As of iOS 8.0 and macOS 10.10 The 'url' must specify a flat file, not a bundle. Bundles have a folder as the root item.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param out_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_for_publishing_ubiquitous_item_at_url(const URL& url, Date& out_date) const;
        /**
     * @brief Calls `-[NSFileManager URLForUbiquityContainerIdentifier:]`.
     * @details Returns the URL for the iCloud container associated with the specified identifier and establishes access to that container. - Parameters: - containerIdentifier: The fully-qualified container identifier for an iCloud container directory. The string you specify must not contain wildcards and must be of the form '\<TEAMID>.\<CONTAINER>', where '\<TEAMID>' is your development team ID and '\<CONTAINER>' is the bundle identifier of the container you want to access. If you specify 'nil' for this parameter, this method returns the first container listed in the 'com.apple.developer.ubiquity-container-identifiers' entitlement array. - Returns: A URL pointing to the specified ubiquity container, or 'nil' if the container could not be located or if iCloud storage is unavailable for the current user or device. You use this method to determine the location of your app's ubiquity container directories and to configure your app's initial iCloud access. The first time you call this method for a given ubiquity container, the system extends your app's sandbox to include that container. > Important: > Do not call this method from your app's main thread. Because this method might take a nontrivial amount of time to set up iCloud and return the requested URL, you should always call it from a secondary thread. To determine if iCloud is available, especially at launch time, check the value of the 'ubiquityIdentityToken' property instead.
     * @param container_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_for_ubiquity_container_identifier(const std::string& container_identifier) const;
        /**
     * @brief Calls `-[NSFileManager URLsForDirectory:inDomains:]`.
     * @details Returns an array of URLs for the specified common directory in the requested domains. - Parameters: - directory: The search path directory. The supported values are described in ''FileManager/SearchPathDirectory''. - domainMask: The file system domain to search. The value for this parameter is one or more of the constants described in ''FileManager/SearchPathDomainMask''. - Returns: An array of ''NSURL'' objects identifying the requested directories. The directories are ordered according to the order of the domain mask constants, with items in the user domain first and items in the system domain last. This method is intended to locate known and common directories in the system. For example, setting the directory to ''FileManager/SearchPathDirectory/applicationDirectory'', will return the Applications directories in the requested domain. There are a number of common directories available in the ''FileManager/SearchPathDirectory'', including: ''FileManager/SearchPathDirectory/desktopDirectory'', ''FileManager/SearchPathDirectory/applicationSupportDirectory'', and many more.
     * @param directory Argument converted to the Objective-C parameter of the same role.
     * @param domain_mask Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<URL> ur_ls_for_directory(SearchPathDirectory directory, SearchPathDomainMask domain_mask) const;
        /**
     * @brief Calls `-[NSFileManager attributesOfFileSystemForPath:error:]`.
     * @details Returns a dictionary that describes the attributes of the mounted file system on which a given path resides. - Parameters: - path: Any pathname within the mounted file system. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: A dictionary object that describes the attributes of the mounted file system on which 'path' resides. See 'File-System Attribute Keys' for a description of the keys available in the dictionary. This method does not traverse a terminal symbolic link.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> attributes_of_file_system_for_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager attributesOfItemAtPath:error:]`.
     * @details Returns the attributes of the item at a given path. - Parameters: - path: The path of a file or directory. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: A dictionary object that describes the attributes (file, directory, symlink, and so on) of the file specified by 'path' (or 'nil' if an error occurred in Objective-C). The keys in the dictionary are described in 'File Attribute Keys'. If the item at the path is a symbolic link---that is, the value of the 'NSFileType' key in the attributes dictionary is 'NSFileTypeSymbolicLink'---you can use the ''FileManager/destinationOfSymbolicLink(atPath:)'' method to retrieve the path of the item pointed to by the link. You can also use the 'stringByResolvingSymlinksInPath' method of ''NSString'' to resolve links in the path before retrieving the item's attributes. As a convenience, ''NSDictionary'' provides a set of methods (declared as a category on ''NSDictionary'') for quickly and efficiently obtaining attribute information from the returned dictionary: 'fileGroupOwnerAccountName', 'fileModificationDate', 'fileOwnerAccountName', 'filePosixPermissions', 'fileSize', 'fileSystemFileNumber', 'fileSystemNumber', and 'fileType'.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> attributes_of_item_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager changeCurrentDirectoryPath:]`.
     * @details Changes the path of the current working directory to the specified path. - Parameters: - path: The path of the directory to which to change. - Returns: 'YES' if successful, otherwise 'NO'. All relative pathnames refer implicitly to the current working directory. > Warning: > This method changes the current working directory for the current process, not just the receiver.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool change_current_directory_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager componentsToDisplayForPath:]`.
     * @details Returns an array of strings representing the user-visible components of a given path. - Parameters: - path: A pathname. - Returns: An array of ''NSString'' objects representing the user-visible (for the Finder, Open and Save panels, and so on) components of 'path'. Returns 'nil' if path does not exist. These components cannot be used for path operations and are only suitable for display to the user.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> components_to_display_for_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager containerURLForSecurityApplicationGroupIdentifier:]`.
     * @details Returns the container directory associated with the specified security application group identifier. - Parameters: - groupIdentifier: A string that names the group whose shared directory you want to obtain. This input should exactly match one of the strings in the app's App Groups entitlement. - Returns: A URL indicating the location of the group's shared directory in the file system. In iOS, the value is 'nil' when the group identifier is invalid. In macOS, a URL of the expected form is always returned, even if the app group is invalid, so be sure to test that you can access the underlying directory before attempting to use it. Sandboxed apps in macOS and all apps in iOS that need to share files with other apps from the same developer on a given device use the App Groups entitlement to join one or more application groups.
     * @param group_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL container_url_for_security_application_group_identifier(const std::string& group_identifier) const;
        /**
     * @brief Calls `-[NSFileManager contentsAtPath:]`.
     * @details Returns the contents of the file at the specified path. - Parameters: - path: The path of the file whose contents you want. - Returns: An ''NSData'' object with the contents of the file. If 'path' specifies a directory, or if some other error occurs, this method returns 'nil'.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> contents_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager contentsEqualAtPath:andPath:]`.
     * @details Returns a Boolean value that indicates whether the files or directories in specified paths have the same contents. - Parameters: - path1: The path of a file or directory to compare with the contents of 'path2'. - path2: The path of a file or directory to compare with the contents of 'path1'. - Returns: 'YES' if file or directory specified in 'path1' has the same contents as that specified in 'path2', otherwise 'NO'. If 'path1' and 'path2' are directories, the contents are the list of files and subdirectories each contains---contents of subdirectories are also compared. For files, this method checks to see if they're the same file, then compares their size, and finally compares their contents. This method does not traverse symbolic links, but compares the links themselves.
     * @param path1 Argument converted to the Objective-C parameter of the same role.
     * @param path2 Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool contents_equal_at_path(const std::string& path1, const std::string& path2) const;
        /**
     * @brief Calls `-[NSFileManager contentsOfDirectoryAtPath:error:]`.
     * @details Performs a shallow search of the specified directory and returns the paths of any contained items. - Parameters: - path: The path to the directory whose contents you want to enumerate. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: An array of ''NSString'' objects, each of which identifies a file, directory, or symbolic link contained in 'path'. Returns an empty array if the directory exists but has no contents. In Objective-C, if an error occurs, this method returns 'nil' and assigns an appropriate error object to the 'error' parameter. This method performs a shallow search of the directory and therefore does not traverse symbolic links or return the contents of any subdirectories. This method also does not return URLs for the current directory ("'.'"), parent directory ("'..'"), or resource forks (files that begin with "'.'") but it does return other hidden files (files that begin with a period character). If you need to perform a deep enumeration, use the ''NSFileManager/enumeratorAtURL:includingPropertiesForKeys:options:errorHandler:'' method instead. The order of the files in the returned array is undefined.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> contents_of_directory_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager contentsOfDirectoryAtURL:includingPropertiesForKeys:options:error:]`.
     * @details Performs a shallow search of the specified directory and returns URLs for the contained items. - Parameters: - url: The URL for the directory whose contents you want to enumerate. - keys: An array of keys that identify the file properties that you want pre-fetched for each item in the directory. For each returned URL, the specified properties are fetched and cached in the ''NSURL'' object. For a list of keys you can specify, see Common File System Resource Keys. If you want directory contents to have no pre-fetched file properties, pass an empty array to this parameter. If you want directory contents to have default set of pre-fetched file properties, pass 'nil' to this parameter. - mask: Options for the enumeration. Because this method performs only shallow enumerations, options that prevent descending into subdirectories or packages are not allowed; the only supported option is ''FileManager/DirectoryEnumerationOptions/skipsHiddenFiles''. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: An array of ''NSURL'' objects, each of which identifies a file, directory, or symbolic link contained in 'url'. If the directory contains no entries, this method returns an empty array. When using Objective-C, if an error occurs, this method returns 'nil' and assigns an appropriate error object to the 'error' parameter. This method performs a shallow search of the directory and therefore does not traverse symbolic links or return the contents of any subdirectories. This method also does not return URLs for the current directory ("'.'"), parent directory ("'..'"), or resource forks (files that begin with "'.'") but it does return other hidden files. If you need to perform a deep enumeration, use the ''NSFileManager/enumeratorAtURL:includingPropertiesForKeys:options:errorHandler:'' method instead. The order of the files in the returned array is undefined.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param keys Argument converted to the Objective-C parameter of the same role.
     * @param mask Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<URL> contents_of_directory_at_url(const URL& url, const std::vector<std::string>& keys, DirectoryEnumerationOptions mask) const;
        /**
     * @brief Calls `-[NSFileManager copyItemAtPath:toPath:error:]`.
     * @details Copies the item at the specified path to a new location synchronously. - Parameters: - srcPath: The path to the file or directory you want to copy. This parameter must not be 'nil'. - dstPath: The path at which to place the copy of 'srcPath'. This path must include the name of the file or directory in its new location. This parameter must not be 'nil'. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: 'YES' if the item was copied successfully or the file manager's delegate stopped the operation deliberately. Returns 'NO' if an error occurred. When copying items, the current process must have permission to read the file or directory at 'srcPath' and write the parent directory of 'dstPath'. If the item at 'srcPath' is a directory, this method copies the directory and all of its contents, including any hidden files. If a file with the same name already exists at 'dstPath', this method stops the copy attempt and returns an appropriate error. If the last component of 'srcPath' is a symbolic link, only the link is copied to the new path. Prior to copying an item, the file manager asks its delegate if it should actually do so for each item. It does this by calling the 'fileManager:shouldCopyItemAtURL:toURL:' method; if that method is not implemented it calls the 'fileManager:shouldCopyItemAtPath:toPath:' method instead. If the delegate method returns 'YES', or if the delegate does not implement the appropriate methods, the file manager copies the given file or directory. If there is an error copying an item, the file manager may also call the delegate's 'fileManager:shouldProceedAfterError:copyingItemAtURL:toURL:' or 'fileManager:shouldProceedAfterError:copyingItemAtPath:toPath:' method to determine how to proceed.
     * @param src_path Argument converted to the Objective-C parameter of the same role.
     * @param dst_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool copy_item_at_path(const std::string& src_path, const std::string& dst_path) const;
        /**
     * @brief Calls `-[NSFileManager copyItemAtURL:toURL:error:]`.
     * @details Copies the file at the specified URL to a new location synchronously. - Parameters: - srcURL: The file URL that identifies the file you want to copy. The URL in this parameter must not be a file reference URL. This parameter must not be 'nil'. - dstURL: The URL at which to place the copy of 'srcURL'. The URL in this parameter must not be a file reference URL and must include the name of the file in its new location. This parameter must not be 'nil'. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: 'YES' if the item was copied successfully or the file manager's delegate stopped the operation deliberately. Returns 'NO' if an error occurred. When copying items, the current process must have permission to read the file or directory at 'srcURL' and write the parent directory of 'dstURL'. If the item at 'srcURL' is a directory, this method copies the directory and all of its contents, including any hidden files. If a file with the same name already exists at 'dstURL', this method stops the copy attempt and returns an appropriate error. If the last component of 'srcURL' is a symbolic link, only the link is copied to the new path.
     * @param src_url Argument converted to the Objective-C parameter of the same role.
     * @param dst_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool copy_item_at_url(const URL& src_url, const URL& dst_url) const;
        /**
     * @brief Calls `-[NSFileManager createDirectoryAtPath:withIntermediateDirectories:attributes:error:]`.
     * @details Creates a directory with given attributes at the specified path. - Parameters: - path: A path string identifying the directory to create. You may specify a full path or a path that is relative to the current working directory. This parameter must not be 'nil'. - createIntermediates: If 'YES', this method creates any nonexistent parent directories as part of creating the directory in 'path'. If 'NO', this method fails if any of the intermediate parent directories does not exist. This method also fails if any of the intermediate path elements corresponds to a file and not a directory. - attributes: The file attributes for the new directory and any newly created intermediate directories. You can set the owner and group numbers, file permissions, and modification date. If you specify 'nil' for this parameter or omit a particular value, one or more default values are used as described in the discussion. Some of the keys, such as 'NSFileHFSCreatorCode' and 'NSFileHFSTypeCode', do not apply to directories. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: 'YES' if the directory was created, 'YES' if 'createIntermediates' is set and the directory already exists, or 'NO' if an error occurred. If you specify 'nil' for the 'attributes' parameter, this method uses a default set of values for the owner, group, and permissions of any newly created directories in the path. Similarly, if you omit a specific attribute, the default value is used. The default values for newly created directories are as follows: - Permissions are set according to the umask of the current process. For more information, see umask. - The owner ID is set to the effective user ID of the process. - The group ID is set to that of the parent directory.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param create_intermediates Argument converted to the Objective-C parameter of the same role.
     * @param attributes Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool create_directory_at_path(const std::string& path, bool create_intermediates, const std::map<std::string, Object>& attributes) const;
        /**
     * @brief Calls `-[NSFileManager createDirectoryAtURL:withIntermediateDirectories:attributes:error:]`.
     * @details Creates a directory with the given attributes at the specified URL. - Parameters: - url: A file URL that specifies the directory to create. If you want to specify a relative path, you must set the current working directory before creating the corresponding ''NSURL'' object. This parameter must not be 'nil'. - createIntermediates: If 'YES', this method creates any nonexistent parent directories as part of creating the directory in 'url'. If 'NO', this method fails if any of the intermediate parent directories does not exist. - attributes: The file attributes for the new directory. You can set the owner and group numbers, file permissions, and modification date. If you specify 'nil' for this parameter, the directory is created according to the umask(2) of the process. Some of the keys, such as 'NSFileHFSCreatorCode' and 'NSFileHFSTypeCode', do not apply to directories. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: 'YES' if the directory was created, 'YES' if 'createIntermediates' is set and the directory already exists, or 'NO' if an error occurred. If you specify 'nil' for the 'attributes' parameter, this method uses a default set of values for the owner, group, and permissions of any newly created directories in the path. Similarly, if you omit a specific attribute, the default value is used. The default values for newly created directories are as follows: - Permissions are set according to the umask of the current process. For more information, see umask. - The owner ID is set to the effective user ID of the process. - The group ID is set to that of the parent directory. If you want to specify a relative path for url, you must set the current working directory before creating the corresponding ''NSURL'' object.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param create_intermediates Argument converted to the Objective-C parameter of the same role.
     * @param attributes Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool create_directory_at_url(const URL& url, bool create_intermediates, const std::map<std::string, Object>& attributes) const;
        /**
     * @brief Calls `-[NSFileManager createFileAtPath:contents:attributes:]`.
     * @details Creates a file with the specified content and attributes at the given location. - Parameters: - path: The path for the new file. - data: A data object containing the contents of the new file. - attr: A dictionary containing the attributes to associate with the new file. You can use these attributes to set the owner and group numbers, file permissions, and modification date. For a list of keys, see 'NSFileAttributeKey'. If you specify 'nil' for 'attributes', the file is created with a set of default attributes. - Returns: 'YES' if the operation was successful or if the item already exists, otherwise 'NO'. If you specify 'nil' for the 'attributes' parameter, this method uses a default set of values for the owner, group, and permissions of any newly created directories in the path. Similarly, if you omit a specific attribute, the default value is used. The default values for newly created files are as follows: - Permissions are set according to the umask of the current process. For more information, see umask. - The owner ID is set to the effective user ID of the process. - The group ID is set to that of the parent directory. If a file already exists at 'path', this method overwrites the contents of that file if the current process has the appropriate privileges to do so.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @param attr Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool create_file_at_path(const std::string& path, const std::vector<std::uint8_t>& data, const std::map<std::string, Object>& attr) const;
        /**
     * @brief Calls `-[NSFileManager createSymbolicLinkAtPath:withDestinationPath:error:]`.
     * @details Creates a symbolic link that points to the specified destination. - Parameters: - path: The path at which to create the new symbolic link. The last path component is used as the name of the link. - destPath: The path that contains the item to be pointed to by the link. In other words, this is the destination of the link. - error: If an error occurs, upon return contains an ''NSError'' object that describes the problem. Pass 'NULL' if you do not want error information. - Returns: 'YES' if the symbolic link was created or 'NO' if an error occurred. This method also returns 'NO' if a file, directory, or link already exists at 'path'. This method does not traverse symbolic links contained in 'destPath', making it possible to create symbolic links to locations that do not yet exist. Also, if the final path component in 'path' is a symbolic link, that link is not followed.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param dest_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool create_symbolic_link_at_path(const std::string& path, const std::string& dest_path) const;
        /**
     * @brief Calls `-[NSFileManager createSymbolicLinkAtURL:withDestinationURL:error:]`.
     * @details Creates a symbolic link at the specified URL that points to an item at the given URL. - Parameters: - url: The file URL at which to create the new symbolic link. The last path component of the URL issued as the name of the link. - destURL: The file URL that contains the item to be pointed to by the link. In other words, this is the destination of the link. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: 'YES' if the symbolic link was created or 'NO' if an error occurred. This method also returns 'NO' if a file, directory, or link already exists at 'url'. This method does not traverse symbolic links contained in 'destURL', making it possible to create symbolic links to locations that do not yet exist. Also, if the final path component in 'url' is a symbolic link, that link is not followed.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param dest_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool create_symbolic_link_at_url(const URL& url, const URL& dest_url) const;
        /**
     * @brief Calls `-[NSFileManager destinationOfSymbolicLinkAtPath:error:]`.
     * @details Returns the path of the item pointed to by a symbolic link. - Parameters: - path: The path of a file or directory. - error: If an error occurs, upon return contains an ''NSError'' object that describes the problem. Pass 'NULL' if you do not want error information. - Returns: An ''NSString'' object containing the path of the directory or file to which the symbolic link 'path' refers. When using Objective-C, returns 'nil' upon failure. If the symbolic link is specified as a relative path, that relative path is returned.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string destination_of_symbolic_link_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager displayNameAtPath:]`.
     * @details Returns the display name of the file or directory at a specified path. - Parameters: - path: The path of a file or directory. - Returns: The name of the file or directory at 'path' in a localized form appropriate for presentation to the user. If there is no file or directory at 'path', or if an error occurs, returns 'path' as is. Display names are user-friendly names for files. They are typically used to localize standard file and directory names according to the user's language settings. They may also reflect other modifications, such as the removal of filename extensions. Such modifications are used only when displaying the file or directory to the user and do not reflect the actual path to the item in the file system.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string display_name_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager enumeratorAtPath:]`.
     * @details Returns a directory enumerator object that can be used to perform a deep enumeration of the directory at the specified path. - Parameters: - path: The path of the directory to enumerate. - Returns: A ''FileManager/DirectoryEnumerator'' object that enumerates the contents of the directory at 'path'. If 'path' is a filename, the method returns an enumerator object that enumerates no files---the first call to 'nextObject' will return 'nil'. Because the enumeration is deep---that is, it lists the contents of all subdirectories---this enumerator object is useful for performing actions that involve large file-system subtrees. This method does not resolve symbolic links encountered in the traversal process, nor does it recurse through them if they point to a directory. The ''FileManager/DirectoryEnumerator'' class has methods for obtaining the attributes of the existing path and of the parent directory and for skipping descendants of the existing path.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DirectoryEnumeratorBase enumerator_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager enumeratorAtURL:includingPropertiesForKeys:options:errorHandler:]`.
     * @details Returns a directory enumerator object that can be used to perform a deep enumeration of the directory at the specified URL. - Parameters: - url: The location of the directory for which you want an enumeration. This URL must not be a symbolic link that points to the desired directory. You can use the 'resolvingSymlinksInPath' method to resolve any symlinks in the URL. - keys: An array of keys that identify the properties that you want pre-fetched for each item in the enumeration. The values for these keys are cached in the corresponding ''NSURL'' objects. You may specify 'nil' for this parameter. For a list of keys you can specify, see ''URLResourceKey''. - mask: Options for the enumeration. For a list of valid options, see 'NSDirectoryEnumerationOptions'. - handler: An optional error handler block for the file manager to call when an error occurs. The handler block should return 'YES' if you want the enumeration to continue or 'NO' if you want the enumeration to stop. If you specify 'nil' for this parameter, the enumerator object continues to enumerate items as if you had specified a block that returned 'YES'. - Returns: A directory enumerator object that enumerates the contents of the directory at 'url'. If 'url' is a filename, the method returns an enumerator object that enumerates no files---the first call to 'nextObject' returns 'nil'. Because the enumeration is deep---that is, it lists the contents of all subdirectories---this enumerator object is useful for performing actions that involve large file-system subtrees. If the method is passed a directory on which another file system is mounted (a mount point), it traverses the mount point. This method does not resolve symbolic links or mount points encountered in the enumeration process, nor does it recurse through them if they point to a directory. The ''FileManager/DirectoryEnumerator'' class has methods for skipping descendants of the existing path and for returning the number of levels deep the current object is in the directory hierarchy being enumerated (where the directory passed to this method is considered to be level 0).
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param keys Argument converted to the Objective-C parameter of the same role.
     * @param mask Argument converted to the Objective-C parameter of the same role.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        DirectoryEnumeratorBase enumerator_at_url(const URL& url, const std::vector<std::string>& keys, DirectoryEnumerationOptions mask, std::function<bool(URL, Error)> handler) const;
        /**
     * @brief Calls `-[NSFileManager evictUbiquitousItemAtURL:error:]`.
     * @details Removes the local copy of the specified item that's stored in iCloud. - Parameters: - url: The URL to a file or directory in iCloud storage. - error: On input, a pointer to variable for an ''NSError'' object. If an error occurs, this pointer is set to an ''NSError'' object containing information about the error. You may specify 'nil' to ignore the error information. - Returns: 'YES' if the local item was removed successfully or 'NO' if it was not. Don't use a coordinated write to perform this operation. This method doesn't remove the item from iCloud. It removes only the local version. You can then use 'startDownloadingUbiquitousItemAtURL:error:' to force iCloud to download a new version of the file or directory from the server. To delete a file permanently from the user's iCloud storage, use the regular ''NSFileManager'' routines for deleting files and directories. Remember that deleting items from iCloud can't be undone. Once deleted, the item is gone forever.
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
     * @details Returns a Boolean value that indicates whether a file or directory exists at a specified path. - Parameters: - path: The path of the file or directory. If 'path' begins with a tilde ('~'), it must first be expanded with 'stringByExpandingTildeInPath'; otherwise, this method returns 'NO'. - Returns: 'YES' if a file at the specified path exists, or 'NO' if the file does not exist or its existence could not be determined. If the file at 'path' is inaccessible to your app, perhaps because one or more parent directories are inaccessible, this method returns 'NO'. If the final element in 'path' specifies a symbolic link, this method traverses the link and returns 'YES' or 'NO' based on the existence of the file at the link destination. > Note: > Attempting to predicate behavior based on the current state of the file system or a particular file on the file system is not recommended. Doing so can cause odd behavior or race conditions. It's far better to attempt an operation (such as loading a file or creating a directory), check for errors, and handle those errors gracefully than it is to try to figure out ahead of time whether the operation will succeed.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool file_exists_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager fileExistsAtPath:isDirectory:]`.
     * @details Returns a Boolean value that indicates whether a file or directory exists at a specified path. - Parameters: - path: The path of a file or directory. If 'path' begins with a tilde ('~'), it must first be expanded with 'stringByExpandingTildeInPath', or this method will return 'NO'. - isDirectory: Upon return, contains 'YES' if 'path' is a directory or if the final path element is a symbolic link that points to a directory; otherwise, contains 'NO'. If 'path' doesn't exist, this value is undefined upon return. Pass 'NULL' if you do not need this information. - Returns: 'YES' if a file at the specified path exists, or 'NO' if the file's does not exist or its existence could not be determined. If the file at 'path' is inaccessible to your app, perhaps because one or more parent directories are inaccessible, this method returns 'NO'. If the final element in 'path' specifies a symbolic link, this method traverses the link and returns 'YES' or 'NO' based on the existence of the file at the link destination. > Note: > Attempting to predicate behavior based on the current state of the file system or a particular file on the file system is not recommended. Doing so can cause odd behavior or race conditions. It's far better to attempt an operation (such as loading a file or creating a directory), check for errors, and handle those errors gracefully than it is to try to figure out ahead of time whether the operation will succeed.
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
     * @details Returns a C-string representation of a given path that properly encodes Unicode strings for use by the file system. - Parameters: - path: A string object containing a path to a file. This parameter must not be 'nil' or contain the empty string. - Returns: A C-string representation of 'path' that properly encodes Unicode strings for use by the file system. Use this method if your code calls system routines that expect C-string path arguments. If you use the C string beyond the scope of the current autorelease pool, you must copy it. This method raises an exception if 'path' is 'nil' or contains the empty string. This method also throws an exception if the conversion of the string fails.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string file_system_representation_with_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager getFileProviderServicesForItemAtURL:completionHandler:]`.
     * @details Returns the services provided by the File Provider extension that manages the item at the given URL. - Parameters: - url: The file URL of a document or directory. - completionHandler: A block that is called on an anonymous background queue. The system passes this block the following parameters: 'services' (if the request is successful, a dictionary with zero or more 'NSFileProviderServiceName' keys and their corresponding 'NSFileProviderService' values; otherwise, 'nil') and 'error' (if an error occurs, an object that describes the error; otherwise, 'nil'). Use the returned services to perform custom actions defined by the services' protocol. To access a service, get the 'NSFileProviderService' object for the desired service name, get an 'NSXPCConnection' from it, set up its 'remoteObjectInterface' with the protocol that matches the service's name, call 'resume' on the connection, and then call custom action methods on the proxy object.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void get_file_provider_services_for_item_at_url(const URL& url, std::function<void(std::map<std::string, FileProviderService>, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSFileManager getRelationship:ofDirectory:inDomain:toItemAtURL:error:]`.
     * @details Determines the type of relationship that exists between a system directory and the specified item. - Parameters: - outRelationship: A pointer to a variable in which to put the relationship between 'directoryURL' and 'otherURL'. For a list of possible values, see ''FileManager/URLRelationship''. - directory: The search path directory. For a list of possible values, see ''FileManager/SearchPathDirectory''. - domainMask: The file system domain to search. Specify '0' for this parameter if you want the file manager to choose the domain appropriate for 'url'. - url: The URL of the file or directory whose relationship to 'directoryURL' is being tested. This parameter must not be 'nil'. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: 'YES' if the relationship between the items was successfully determined, or 'NO' if an error occurred. Use this method to determine the relationship between an item and one of the system-specific directories. For example, you might use this method to determine if the specified item is in the user's 'Documents' directory or is in the trash. If the relationship between the items is determined successfully, this method sets the value of the 'outRelationship' parameter to an appropriate value. The directory may contain the item, it may be the same as the item, or it may not have a direct relationship to the item.
     * @param out_relationship Argument converted to the Objective-C parameter of the same role.
     * @param directory Argument converted to the Objective-C parameter of the same role.
     * @param domain_mask Argument converted to the Objective-C parameter of the same role.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool get_relationship(URLRelationship* out_relationship, SearchPathDirectory directory, SearchPathDomainMask domain_mask, const URL& url) const;
        /**
     * @brief Calls `-[NSFileManager getRelationship:ofDirectoryAtURL:toItemAtURL:error:]`.
     * @details Determines the type of relationship that exists between a directory and an item. - Parameters: - outRelationship: A pointer to a variable in which to put the relationship between 'directoryURL' and 'otherURL'. For a list of possible values, see ''FileManager/URLRelationship''. - directoryURL: The URL of the directory that potentially contains the item in 'otherURL'. The URL in this parameter must specify a directory. This parameter must not be 'nil'. - otherURL: The URL of the file or directory whose relationship to 'directoryURL' is being tested. This parameter must not be 'nil'. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: 'YES' if the relationship between the items was successfully determined, or 'NO' if an error occurred. Use this method to determine the relationship between an item and a directory whose location you already know. If the relationship between the items is determined successfully, this method sets the value of the 'outRelationship' parameter to an appropriate value. The directory may contain the item, it may be the same as the item, or it may not have a direct relationship to the item.
     * @param out_relationship Argument converted to the Objective-C parameter of the same role.
     * @param directory_url Argument converted to the Objective-C parameter of the same role.
     * @param other_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool get_relationship(URLRelationship* out_relationship, const URL& directory_url, const URL& other_url) const;
        /**
     * @brief Calls `-[NSFileManager homeDirectoryForUser:]`.
     * @details Returns the home directory for the specified user. - Parameters: - userName: The username of the owner of the desired home directory. - Returns: A URL object containing the location of the specified user's home directory, or 'nil' if no such user exists or the user's home directory is not available.
     * @param user_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL home_directory_for_user(const std::string& user_name) const;
        /**
     * @brief Calls `-[NSFileManager isDeletableFileAtPath:]`.
     * @details Returns a Boolean value that indicates whether the invoking object appears able to delete a specified file. - Parameters: - path: A file path. - Returns: 'YES' if the current process has delete privileges for the file at 'path'; otherwise 'NO' if the process does not have delete privileges or the existence of the file could not be determined. For a directory or file to be deletable, the current process must either be able to write to the parent directory of 'path' or it must have the same owner as the item at 'path'. If 'path' is a directory, every item contained in 'path' must be deletable by the current process. If the file at 'path' is inaccessible to your app, perhaps because it does not have search privileges for one or more parent directories, this method returns 'NO'. If the item at 'path' is a symbolic link, it is not traversed.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_deletable_file_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager isExecutableFileAtPath:]`.
     * @details Returns a Boolean value that indicates whether the operating system appears able to execute a specified file. - Parameters: - path: A file path. - Returns: 'YES' if the current process has execute privileges for the file at 'path'; otherwise 'NO' if the process does not have execute privileges or the existence of the file could not be determined. If the file at 'path' is inaccessible to your app, perhaps because it does not have search privileges for one or more parent directories, this method returns 'NO'. This method traverses symbolic links in the path. This method also uses the real user ID and group ID, as opposed to the effective user and group IDs, to determine if the file is executable.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_executable_file_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager isReadableFileAtPath:]`.
     * @details Returns a Boolean value that indicates whether the invoking object appears able to read a specified file. - Parameters: - path: A file path. - Returns: 'YES' if the current process has read privileges for the file at 'path'; otherwise 'NO' if the process does not have read privileges or the existence of the file could not be determined. If the file at 'path' is inaccessible to your app, perhaps because it does not have search privileges for one or more parent directories, this method returns 'NO'. This method traverses symbolic links in the path. This method also uses the real user ID and group ID, as opposed to the effective user and group IDs, to determine if the file is readable.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_readable_file_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager isUbiquitousItemAtURL:]`.
     * @details Returns a Boolean indicating whether the item is targeted for storage in iCloud. - Parameters: - url: Specify the URL for the file or directory whose status you want to check. - Returns: 'YES' if the item is targeted for iCloud storage or 'NO' if it is not. This method also returns 'NO' if no item exists at 'url'. This method reflects only whether the item should be stored in iCloud because a call was made to the 'setUbiquitous:itemAtURL:destinationURL:error:' method with a value of 'YES' for its 'flag' parameter. This method does not reflect whether the file has actually been uploaded to any iCloud servers. To determine a file's upload status, check the 'NSURLUbiquitousItemIsUploadedKey' attribute of the corresponding ''NSURL'' object.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_ubiquitous_item_at_url(const URL& url) const;
        /**
     * @brief Calls `-[NSFileManager isWritableFileAtPath:]`.
     * @details Returns a Boolean value that indicates whether the invoking object appears able to write to a specified file. - Parameters: - path: A file path. - Returns: 'YES' if the current process has write privileges for the file at 'path'; otherwise 'NO' if the process does not have write privileges or the existence of the file could not be determined. If the file at 'path' is inaccessible to your app, perhaps because it does not have search privileges for one or more parent directories, this method returns 'NO'. This method traverses symbolic links in the path. This method also uses the real user ID and group ID, as opposed to the effective user and group IDs, to determine if the file is writable.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_writable_file_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager linkItemAtPath:toPath:error:]`.
     * @details Creates a hard link between the items at the specified paths. - Parameters: - srcPath: The path that specifies the item you wish to link to. The value in this parameter must not be 'nil'. - dstPath: The path that identifies the location where the link will be created. The value in this parameter must not be 'nil'. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: 'YES' if the hard link was created or 'NO' if an error occurred. This method also returns 'NO' if a file, directory, or link already exists at 'dstPath'. Use this method to create hard links between files in the current file system. If 'srcPath' is a directory, this method creates a new directory at 'dstPath' and then creates hard links for the items in that directory. If 'srcPath' is (or contains) a symbolic link, the symbolic link is copied to the new location and not converted to a hard link. Prior to linking each item, the file manager asks its delegate if it should actually create the link. It does this by calling the 'fileManager:shouldLinkItemAtURL:toURL:' method; if that method is not implemented it calls the 'fileManager:shouldLinkItemAtPath:toPath:' method instead. If the delegate method returns 'YES', or if the delegate does not implement the appropriate methods, the file manager creates the hard link. If there is an error linking one out of several items, the file manager may also call the delegate's 'fileManager:shouldProceedAfterError:linkingItemAtURL:toURL:' or 'fileManager:shouldProceedAfterError:linkingItemAtPath:toPath:' method to determine how to proceed.
     * @param src_path Argument converted to the Objective-C parameter of the same role.
     * @param dst_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool link_item_at_path(const std::string& src_path, const std::string& dst_path) const;
        /**
     * @brief Calls `-[NSFileManager linkItemAtURL:toURL:error:]`.
     * @details Creates a hard link between the items at the specified URLs. - Parameters: - srcURL: The file URL that identifies the source of the link. The URL in this parameter must not be a file reference URL; it must specify the actual path to the item. The value in this parameter must not be 'nil'. - dstURL: The file URL that specifies where you want to create the hard link. The URL in this parameter must not be a file reference URL; it must specify the actual path to the item. The value in this parameter must not be 'nil'. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: 'YES' if the hard link was created or 'NO' if an error occurred. This method also returns 'NO' if a file, directory, or link already exists at 'dstURL'. Use this method to create hard links between files in the current file system. If 'srcURL' is a directory, this method creates a new directory at 'dstURL' and then creates hard links for the items in that directory. If 'srcURL' is (or contains) a symbolic link, the symbolic link is copied and not converted to a hard link at 'dstURL'.
     * @param src_url Argument converted to the Objective-C parameter of the same role.
     * @param dst_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool link_item_at_url(const URL& src_url, const URL& dst_url) const;
        /**
     * @brief Calls `-[NSFileManager mountedVolumeURLsIncludingResourceValuesForKeys:options:]`.
     * @details Returns an array of URLs that identify the mounted volumes available on the device. - Parameters: - propertyKeys: An array of keys that identify the file properties that you want pre-fetched for each volume. For each returned URL, the values for these keys are cached in the corresponding ''NSURL'' objects. You may specify 'nil' for this parameter. For a list of keys you can specify, see Common File System Resource Keys. - options: Option flags for the enumeration. For a list of possible values, see ''FileManager/VolumeEnumerationOptions''. - Returns: An array of 'NSURL' objects identifying the mounted volumes. > Important: > This method returns 'nil' on platforms other than macOS. This call may block if I/O is required to determine values for the requested 'propertyKeys'.
     * @param property_keys Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<URL> mounted_volume_ur_ls_including_resource_values_for_keys(const std::vector<std::string>& property_keys, VolumeEnumerationOptions options) const;
        /**
     * @brief Calls `-[NSFileManager moveItemAtPath:toPath:error:]`.
     * @details Moves the file or directory at the specified path to a new location synchronously. - Parameters: - srcPath: The path to the file or directory you want to move. This parameter must not be 'nil'. - dstPath: The new path for the item in 'srcPath'. This path must include the name of the file or directory in its new location. This parameter must not be 'nil'. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: 'YES' if the item was moved successfully or the file manager's delegate stopped the operation deliberately. Returns 'NO' if an error occurred. When moving items, the current process must have permission to read the item at 'srcPath' and write the parent directory of 'dstPath'. If the item at 'srcPath' is a directory, this method moves the directory and all of its contents, including any hidden files. If an item with the same name already exists at 'dstPath', this method stops the move attempt and returns an appropriate error. If the last component of 'srcPath' is a symbolic link, only the link is moved to the new path; the item pointed to by the link remains at its current location. Prior to moving the item, the file manager asks its delegate if it should actually move it. It does this by calling the 'fileManager:shouldMoveItemAtURL:toURL:' method; if that method is not implemented it calls the 'fileManager:shouldMoveItemAtPath:toPath:' method instead. If the item being moved is a directory, the file manager notifies the delegate only for the directory itself and not for any of its contents. If the delegate method returns 'YES', or if the delegate does not implement the appropriate methods, the file manager moves the file. If there is an error moving one out of several items, the file manager may also call the delegate's 'fileManager:shouldProceedAfterError:movingItemAtURL:toURL:' or 'fileManager:shouldProceedAfterError:movingItemAtPath:toPath:' method to determine how to proceed. If the source and destination of the move operation are not on the same volume, this method copies the item first and then removes it from its current location. This behavior may trigger additional delegate notifications related to copying and removing individual items.
     * @param src_path Argument converted to the Objective-C parameter of the same role.
     * @param dst_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool move_item_at_path(const std::string& src_path, const std::string& dst_path) const;
        /**
     * @brief Calls `-[NSFileManager moveItemAtURL:toURL:error:]`.
     * @details Moves the file or directory at the specified URL to a new location synchronously. - Parameters: - srcURL: The file URL that identifies the file or directory you want to move. The URL in this parameter must not be a file reference URL. This parameter must not be 'nil'. - dstURL: The new location for the item in 'srcURL'. The URL in this parameter must not be a file reference URL and must include the name of the file or directory in its new location. This parameter must not be 'nil'. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: 'YES' if the item was moved successfully or the file manager's delegate stopped the operation deliberately. Returns 'NO' if an error occurred. When moving items, the current process must have permission to read the item at 'srcURL' and write the parent directory of 'dstURL'. If the item at 'srcURL' is a directory, this method moves the directory and all of its contents, including any hidden files. If an item with the same name already exists at 'dstURL', this method stops the move attempt and returns an appropriate error. If the last component of 'srcURL' is a symbolic link, only the link is moved to the new path; the item pointed to by the link remains at its current location. If the source and destination of the move operation are not on the same volume, this method copies the item first and then removes it from its current location. This behavior may trigger additional delegate notifications related to copying and removing individual items.
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
     * @details Removes the file or directory at the specified path. - Parameters: - path: A path string indicating the file or directory to remove. If the path specifies a directory, the contents of that directory are recursively removed. You may specify 'nil' for this parameter in Objective-C. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: 'YES' if the item was removed successfully or if 'path' was 'nil'. Returns 'NO' if an error occurred. If the delegate stops the operation for a file, this method returns 'YES'. However, if the delegate stops the operation for a directory, this method returns 'NO'. Prior to removing each item, the file manager asks its delegate if it should actually do so. It does this by calling the 'fileManager:shouldRemoveItemAtURL:' method; if that method is not implemented it calls the 'fileManager:shouldRemoveItemAtPath:' method instead. If the delegate method returns 'YES', or if the delegate does not implement the appropriate methods, the file manager proceeds to remove the file or directory. If there is an error removing an item, the file manager may also call the delegate's 'fileManager:shouldProceedAfterError:removingItemAtURL:' or 'fileManager:shouldProceedAfterError:removingItemAtPath:' method to determine how to proceed. Removing an item also removes all old versions of that item, invalidating any URLs returned by the 'URLForPublishingUbiquitousItemAtURL:expirationDate:error:' method to old versions.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool remove_item_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager removeItemAtURL:error:]`.
     * @details Removes the file or directory at the specified URL. - Parameters: - URL: A file URL specifying the file or directory to remove. If the URL specifies a directory, the contents of that directory are recursively removed. You may specify 'nil' for this parameter in Objective-C. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: 'YES' if the item was removed successfully or if 'URL' was 'nil'. Returns 'NO' if an error occurred. If the delegate stops the operation for a file, this method returns 'YES'. However, if the delegate stops the operation for a directory, this method returns 'NO'. Prior to removing each item, the file manager asks its delegate if it should actually do so. It does this by calling the 'fileManager:shouldRemoveItemAtURL:' method; if that method is not implemented it calls the 'fileManager:shouldRemoveItemAtPath:' method instead. Removing an item also removes all old versions of that item, invalidating any URLs returned by the 'URLForPublishingUbiquitousItemAtURL:expirationDate:error:' method to old versions.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool remove_item_at_url(const URL& url) const;
        /**
     * @brief Calls `-[NSFileManager replaceItemAtURL:withItemAtURL:backupItemName:options:resultingItemURL:error:]`.
     * @details Replaces the contents of the item at the specified URL in a manner that ensures no data loss occurs. - Parameters: - originalItemURL: The item containing the content you want to replace. - newItemURL: The item containing the new content for 'originalItemURL'. It is recommended that you put this item in a temporary directory as provided by the OS. If a temporary directory is not available, put this item in a uniquely named directory that is in the same directory as the original item. - backupItemName: If provided, the name used to create a backup of the original item. The backup is placed in the same directory as the original item. If an error occurs during the creation of the backup item, the operation fails. If there is already an item with the same name as the backup item, that item will be removed. The backup item will be removed in the event of success unless the 'NSFileManagerItemReplacementWithoutDeletingBackupItem' option is provided in 'options'. - options: The options to use during the replacement. Typically, you pass 'NSFileManagerItemReplacementUsingNewMetadataOnly' for this parameter, which uses only the metadata from the new item. Pass '0' to get the default behavior, which uses only the metadata from the new item while adjusting some properties using values from the original item. - resultingURL: On input, a pointer for a URL object. When the item is replaced, this pointer is set to the URL of the new item. If no new file system object is required, the URL object in this parameter may be the same passed to the 'originalItemURL' parameter. However, if a new file system object is required, the URL object may be different. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: 'YES' if the replacement was successful or 'NO' if an error occurred. By default, the creation date, permissions, Finder label and color, and Spotlight comments of the original item are preserved on the new item. You can configure which metadata is preserved using the 'options' parameter. This method works only when the 'originalItemURL' and 'newItemURL' parameters are located on the same volume. Attempting to call this method by passing 'originalItemURL' and 'newItemURL' parameters that have locations on different volumes results in an error. Instead, you can call the 'URLForDirectory:inDomain:appropriateForURL:create:error:' method, passing 'NSItemReplacementDirectory' as the search path directory, to get a temporary URL on the destination's volume that is suitable for use with this method. If an error occurs and the original item is not in the original location or a temporary location, the resulting error object contains a user info dictionary with the key '"NSFileOriginalItemLocationKey"'. The value assigned to that key is an ''NSURL'' object with the location of the item.
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
     * @details Sets the attributes of the specified file or directory. - Parameters: - attributes: A dictionary containing as keys the attributes to set for 'path' and as values the corresponding value for the attribute. You can set the following attributes: 'NSFileBusy', 'NSFileCreationDate', 'NSFileExtensionHidden', 'NSFileGroupOwnerAccountID', 'NSFileGroupOwnerAccountName', 'NSFileHFSCreatorCode', 'NSFileHFSTypeCode', 'NSFileImmutable', 'NSFileModificationDate', 'NSFileOwnerAccountID', 'NSFileOwnerAccountName', 'NSFilePosixPermissions'. You can change single attributes or any combination of attributes; you need not specify keys for all attributes. - path: The path of a file or directory. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: 'YES' if all changes succeed. If any change fails, returns 'NO', but it is undefined whether any changes actually occurred. As in the POSIX standard, the app either must own the file or directory or must be running as superuser for attribute changes to take effect. The method attempts to make all changes specified in attributes and ignores any rejection of an attempted modification. If the last component of the path is a symbolic link, the system traverses it. You must initialize the 'NSFilePosixPermissions' value with the code representing the POSIX file-permissions bit pattern. The system sets 'NSFileHFSCreatorCode' and 'NSFileHFSTypeCode' only when 'path' specifies a file.
     * @param attributes Argument converted to the Objective-C parameter of the same role.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_attributes(const std::map<std::string, Object>& attributes, const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager setUbiquitous:itemAtURL:destinationURL:error:]`.
     * @details Indicates whether the item at the specified URL should be stored in iCloud. - Parameters: - flag: 'YES' to move the item to iCloud or 'NO' to remove it from iCloud (if it is there currently). - url: The URL of the item (file or directory) that you want to store in iCloud. - destinationURL: When moving a file into iCloud, this is the location in iCloud at which to store the file or directory. This URL must be constructed from a URL returned by the 'URLForUbiquityContainerIdentifier:' method. When moving a file out of iCloud, this is the location on the local device. - error: On input, a pointer to variable for an ''NSError'' object. If an error occurs, this pointer is set to an ''NSError'' object containing information about the error. You may specify 'nil' to ignore the error information. - Returns: 'YES' if the item's status was updated successfully or 'NO' if an error occurred. Use this method to move a file from its current location to iCloud. For files located in an app's sandbox, this involves physically removing the file from the sandbox container. You can also use this method to move files out of iCloud and back into a local directory. > Important: > Avoid calling this method from your app's main thread. This method performs a coordinated write operation on the specified file, which can block for a long time. Instead, use a dispatch queue to call this method from background thread.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param destination_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_ubiquitous(bool flag, const URL& url, const URL& destination_url) const;
        /**
     * @brief Calls `-[NSFileManager startDownloadingUbiquitousItemAtURL:error:]`.
     * @details Starts downloading (if necessary) the specified item to the local system. - Parameters: - url: The URL for the file or directory in the cloud that you want to download. - error: On input, a pointer to variable for an ''NSError'' object. If an error occurs, this pointer is set to an ''NSError'' object containing information about the error. You may specify 'nil' to ignore the error information. - Returns: 'YES' if the download started successfully or was not necessary, 'NO' otherwise. If a cloud-based file or directory has not been downloaded yet, calling this method starts the download process. If the item exists locally, calling this method synchronizes the local copy with the version in the cloud.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool start_downloading_ubiquitous_item_at_url(const URL& url) const;
        /**
     * @brief Calls `-[NSFileManager stringWithFileSystemRepresentation:length:]`.
     * @details Returns an ''NSString'' object whose contents are derived from the specified C-string path. - Parameters: - str: A C string representation of a pathname. - len: The number of characters in 'string'. - Returns: An ''NSString'' object converted from the C-string representation 'string' with length 'len' of a pathname in the current file system. Use this method if your code receives paths as C strings from system routines.
     * @param str Argument converted to the Objective-C parameter of the same role.
     * @param len Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_with_file_system_representation(const std::string& str, std::uint64_t len) const;
        /**
     * @brief Calls `-[NSFileManager subpathsAtPath:]`.
     * @details Returns an array of strings identifying the paths for all items in the specified directory. - Parameters: - path: The path of the directory to list. - Returns: An array of ''NSString'' objects, each of which contains the path of an item in the directory specified by 'path'. If 'path' is a symbolic link, this method traverses the link. This method returns 'nil' if it cannot retrieve the device of the linked-to file. This method recurses the specified directory and its subdirectories. The method skips the "'.'" and "'..'" directories at each level of the recursion. This method reveals every element of the subtree at 'path', including the contents of file packages (such as apps, nib files, and RTFD files). In macOS 10.5 and later, use 'subpathsOfDirectoryAtPath:error:' instead.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> subpaths_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager subpathsOfDirectoryAtPath:error:]`.
     * @details Performs a deep enumeration of the specified directory and returns the paths of all of the contained subdirectories. - Parameters: - path: The path of the directory to list. - error: If an error occurs, upon return contains an ''NSError'' object that describes the problem. Pass 'NULL' if you don't want error information. - Returns: An array of strings, each containing the path of an item in the directory specified by 'path'. When using Objective-C, returns 'nil' if an error occurred. This method recurses the specified directory and its subdirectories. The method skips the "'.'" and "'..'" directories at each level of the recursion. Because this method recurses the directory's contents, you might not want to use it in performance-critical code. Instead, consider using the ''NSFileManager/enumeratorAtURL:includingPropertiesForKeys:options:errorHandler:'' or ''FileManager/enumerator(atPath:)'' method to enumerate the directory contents yourself. Doing so gives you more control over the retrieval of items and more opportunities to complete the enumeration or perform other tasks at the same time.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> subpaths_of_directory_at_path(const std::string& path) const;
        /**
     * @brief Calls `-[NSFileManager trashItemAtURL:resultingItemURL:error:]`.
     * @details Moves an item to the trash. - Parameters: - url: The item to move to the trash. - outResultingURL: On input, a pointer to a URL object. On output, this pointer is set to the item's location in the trash. The actual name of the item may be changed when moving it to the trash, so use this URL to access it. You may specify 'nil' for this parameter if you do not want the information. - error: On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify 'nil' for this parameter if you do not want the error information. - Returns: 'YES' if the item at 'url' was successfully moved to the trash, or 'NO' if the item was not moved to the trash.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param out_resulting_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool trash_item_at_url(const URL& url, URL& out_resulting_url) const;
        /**
     * @brief Calls `-[NSFileManager unmountVolumeAtURL:options:completionHandler:]`.
     * @details Starts the process of unmounting the specified volume. - Parameters: - url: A file URL specifying the volume to be unmounted. - mask: A bitmask of ''FileManager/UnmountOptions'' that you can use to customize the unmount operation’s behavior. - completionHandler: A block executed when the unmount operation completes. The block receives an error parameter which is 'nil' if unmounting was successful. Otherwise, it indicates why unmounting failed. If the volume is encrypted, it is relocked after being unmounted.
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
     * @details The path to the program's current directory. The current directory path is the starting point for any relative paths you specify. For example, if the current directory is '/tmp' and you specify a relative pathname of 'reports/info.txt', the resulting full path for the item is '/tmp/reports/info.txt'. When an app is launched, this property is initially set to the app's current working directory. If the current working directory is not accessible for any reason, the value of this property is 'nil'. You can change the value of this property by calling the 'changeCurrentDirectoryPath:' method. > Warning: > This property reports the current working directory for the current process, not just the receiver.
     * @return The converted Objective-C result.
     */
        std::string current_directory_path() const;
        /**
     * @brief Returns the `defaultManager` property of `NSFileManager`.
     * @details The shared file manager object for the process. This method always represents the same file manager object. If you plan to use a delegate with the file manager to receive notifications about the completion of file-based operations, you should create a new instance of ''FileManager'' rather than using the shared object.
     * @return The converted Objective-C result.
     */
        static FileManager default_manager();
        /**
     * @brief Returns the `homeDirectoryForCurrentUser` property of `NSFileManager`.
     * @details The home directory for the current user.
     * @return The converted Objective-C result.
     */
        URL home_directory_for_current_user() const;
        /**
     * @brief Returns the `temporaryDirectory` property of `NSFileManager`.
     * @details The temporary directory for the current user.
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
