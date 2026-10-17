#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Number;
    class Pasteboard;

    /**
     * @brief C++ handle for the Objective-C class `NSURL` (Foundation).
     * @details An object that represents the location of a resource, such as an item on a remote server or the path to a local file. In Swift, this object bridges to ''URL''; use ''NSURL'' when you need reference semantics or other Foundation-specific behavior. You can use URL objects to construct URLs and access their parts. For URLs that represent local files, you can also manipulate properties of those files directly, such as changing the file's last modification date. Finally, you can pass URL objects to other APIs to retrieve the contents of those URLs. For example, you can use the ''URLSession'', ''NSURLConnection'', and ''NSURLDownload'' classes to access the contents of remote resources, as described in \<doc:url-loading-system>. URL objects are the preferred way to refer to local files. Most objects that read data from or write data to a file have methods that accept an ''NSURL'' object instead of a pathname as the file reference. For example, you can get the contents of a local file URL as an 'NSString' object using the ''NSString/init(contentsOfURL:encoding:)-715fw'' initializer, or as an 'NSData' object using the ''NSData/init(contentsOfURL:options:)-5abi3'' initializer. You can also use URLs for interapplication communication. In macOS, the \<doc://com.apple.documentation/documentation/appkit/nsworkspace> class provides the \<doc://com.apple.documentation/documentation/appkit/nsworkspace/open(:)> method to open a location specified by a URL. Similarly, in iOS, the \<doc://com.apple.documentation/documentation/uikit/uiapplication> class provides the \<doc://com.apple.documentation/documentation/uikit/uiapplication/open(:options:completionhandler:)> method. The ''NSURL'' class is "toll-free bridged" with its Core Foundation counterpart, \<doc://com.apple.documentation/documentation/corefoundation/cfurl>. See [Toll-Free Bridging](https://developer.apple.com/library/archive/documentation/General/Conceptual/CocoaEncyclopedia/Toll-FreeBridgin/Toll-FreeBridgin.html\#//apple_ref/doc/uid/TP40010810-CH2) for more information on toll-free bridging. > Important: > The Swift overlay to the Foundation framework provides the ''URL'' structure, which bridges to the ''NSURL'' class. For more information about value types, see [Classes and Structures](https://developer.apple.com/library/archive/documentation/Swift/Conceptual/Swift_Programming_Language/ClassesAndStructures.html\#//apple_ref/doc/uid/TP40014097-CH13) in [The Swift Programming Language (Swift 4.1)](https://developer.apple.com/library/archive/documentation/Swift/Conceptual/Swift_Programming_Language/index.html\#//apple_ref/doc/uid/TP40014097) and [Working with Cocoa Frameworks](https://developer.apple.com/library/archive/documentation/Swift/Conceptual/BuildingCocoaApps/WorkingWithCocoaDataTypes.html\#//apple_ref/doc/uid/TP40014216-CH6) in [Using Swift with Cocoa and Objective-C (Swift 4.1)](https://developer.apple.com/library/archive/documentation/Swift/Conceptual/BuildingCocoaApps/index.html\#//apple_ref/doc/uid/TP40014216). \#\#\# Structure of a URL An ''NSURL'' object is composed of two parts—a potentially 'nil' base URL and a string that is resolved relative to the base URL. An ''NSURL'' object is considered absolute if its string part is fully resolved without a base; all other URLs are considered relative. For example, when constructing an 'NSURL' object, you might specify 'file:///path/to/user/' as the base URL and 'folder/file.html' as the string part, as follows: '''objc NSURL baseURL = [NSURL fileURLWithPath:\@"file:///path/to/user/"]; NSURL URL = [NSURL URLWithString:\@"folder/file.html" relativeToURL:baseURL]; NSLog(\@"absoluteURL = \%\@", [URL absoluteURL]); ''' When fully resolved, the absolute URL is 'file:///path/to/user/folder/file.html'. A URL can be also be divided into pieces based on its structure. For example, the URL 'https://johnny:p4ssw0rd\@www.example.com:443/script.ext;param=value?query=value\#ref' contains the following URL components: | Component | Value | |---|---| | ''scheme'' | 'https' | | ''user'' | 'johnny' | | ''password'' | 'p4ssw0rd' | | ''host'' | 'www.example.com' | | ''port'' | '443' | | ''path'' | '/script.ext' | | ''pathExtension'' | 'ext' | | ''pathComponents'' | '["/", "script.ext"]' | | ''parameterString'' | 'param=value' | | ''query'' | 'query=value' | | ''fragment'' | 'ref' | The ''NSURL'' class provides properties that let you examine each of these components. > Important: > For apps linked on or after iOS 17 and aligned OS versions, ''NSURL'' parsing has updated from the obsolete RFC 1738/1808 parsing to the same [RFC 3986](https://www.ietf.org/rfc/rfc3986.txt) parsing as ''NSURLComponents''. This unifies the parsing behaviors of the 'NSURL' and 'NSURLComponents' APIs. Now, 'NSURL' automatically percent- and IDNA-encodes invalid characters to help create a valid URL. > > To check if a 'URLString' is strictly valid according to the RFC, use the new '[NSURL URLWithString:URLString encodingInvalidCharacters:NO]' method. This method leaves all characters as they are and returns 'nil' if 'URLString' is explicitly invalid. For apps linked before iOS 17, the ''NSURL'' class parses URLs according to [RFC 1808](https://tools.ietf.org/html/rfc1808), [RFC 1738](https://tools.ietf.org/html/rfc1738), and [RFC 2732](https://tools.ietf.org/html/rfc2732). \#\#\# Bookmarks and Security Scope Starting with OS X v10.6 and iOS 4.0, the ''NSURL'' class provides a facility for creating and using bookmark objects. A bookmark provides a persistent reference to a file-system resource. When you resolve a bookmark, you obtain a URL to the resource's current location. A bookmark's association with a file-system resource (typically a file or folder) usually continues to work if the user moves or renames the resource, or if the user relaunches your app or restarts the system. For a general introduction to using bookmarks, read [Locating Files Using Bookmarks](https://developer.apple.com/library/archive/documentation/FileManagement/Conceptual/FileSystemProgrammingGuide/AccessingFilesandDirectories/AccessingFilesandDirectories.html\#//apple_ref/doc/uid/TP40010672-CH3-SW10) in [File System Programming Guide](https://developer.apple.com/library/archive/documentation/FileManagement/Conceptual/FileSystemProgrammingGuide/Introduction/Introduction.html\#//apple_ref/doc/uid/TP40010672). In a macOS app that adopts App Sandbox, you can use security-scoped bookmarks to gain access to file-system resources outside your app's sandbox. These bookmarks preserve the user's intent to give your app access to a resource across app launches. For details on how this works, including information on the entitlements you need in your Xcode project, read [Security-Scoped Bookmarks and Persistent Resource Access](https://developer.apple.com/library/archive/documentation/Security/Conceptual/AppSandboxDesignGuide/AppSandboxInDepth/AppSandboxInDepth.html\#//apple_ref/doc/uid/TP40011183-CH3-SW16) in [App Sandbox Design Guide](https://developer.apple.com/library/archive/documentation/Security/Conceptual/AppSandboxDesignGuide/AboutAppSandbox/AboutAppSandbox.html\#//apple_ref/doc/uid/TP40011183). The methods for using security-scoped bookmarks are described in this document in Working with Bookmark Data. When you resolve a security-scoped bookmark, you get a security-scoped URL. \#\#\# Security-Scoped URLs Security-scoped URLs provide access to resources outside an app's sandbox. In macOS, you get access to security-scoped URLs when you resolve a security-scoped bookmark. In iOS, apps that open or move documents using a \<doc://com.apple.documentation/documentation/uikit/uidocumentpickerviewcontroller> also receive security-scoped URLs. To gain access to a security-scoped URL, you must call the ''startAccessingSecurityScopedResource()'' method (or its Core Foundation equivalent, the \<doc://com.apple.documentation/documentation/corefoundation/cfurlstartaccessingsecurityscopedresource(:)> function). For iOS apps, if you use a \<doc://com.apple.documentation/documentation/uikit/uidocument> to access the URL, it automatically manages the security-scoped URL for you. If 'startAccessingSecurityScopedResource' (or 'CFUrLStartAccessingSecurityScopedResource') returns \<doc://com.apple.documentation/documentation/swift/true>, you must relinquish your access by calling the ''stopAccessingSecurityScopedResource()'' method (or its Core Foundation equivalent, the \<doc://com.apple.documentation/documentation/corefoundation/cfurlstopaccessingsecurityscopedresource(:)> function). You should relinquish your access as soon as you have finished using the file. After you call these methods, you immediately lose access to the resource in question. > Warning: > If you fail to relinquish your access when you no longer need a file-system resource, your app leaks kernel resources. If sufficient kernel resources are leaked, your app loses its ability to add file-system locations to its sandbox, using Powerbox, security-scoped bookmarks, or similar APIs, until relaunched. \#\#\#\# Security-Scoped URLs and String Paths In a macOS app, when you copy a security-scoped URL, the copy has the security scope of the original. You gain access to the file-system resource (that the URL points to) just as you would with the original URL: by calling the ''startAccessingSecurityScopedResource()'' method (or its Core Foundation equivalent). If you need a security-scoped URL's path as a string value (as provided by the ''path'' method), such as to provide to an API that requires a string value, obtain the path from the URL as needed. Note, however, that a string-based path obtained from a security-scoped URL does not have security scope and you cannot use that string to obtain access to a security-scoped resource.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URL url;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::URL url{};
     * auto made_0 = cocoon::URL::url_by_resolving_alias_file_at_url(cocoon::URL(), cocoon::URLBookmarkResolutionOptions::WithoutUI);
     * auto made_1 = cocoon::URL::url_from_pasteboard(cocoon::Pasteboard());
     * url.url_by_appending_path_component("text");
     * url.url_by_appending_path_component("text", true);
     * url.url_by_appending_path_extension("text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurl
     */
    class URL : public Object
    {
    public:
        /// @brief Creates a new `NSURL` instance and returns a handle to it.
        explicit URL(const std::vector<std::uint8_t>& data, const URL& base_url);
        /// @brief Creates a new `NSURL` instance and returns a handle to it.
        explicit URL(const std::vector<std::uint8_t>& bookmark_data, URLBookmarkResolutionOptions options, const URL& relative_url, bool* is_stale);
        /// @brief Creates a new `NSURL` instance and returns a handle to it.
        explicit URL(const std::string& path, bool is_dir, const URL& base_url);
        /// @brief Creates a new `NSURL` instance and returns a handle to it.
        explicit URL(const std::string& path);
        /// @brief Creates a new `NSURL` instance and returns a handle to it.
        explicit URL(const std::string& path, bool is_dir);
        /// @brief Creates a new `NSURL` instance and returns a handle to it.
        explicit URL(const std::string& path, const URL& base_url);
        /// @brief Creates a new `NSURL` instance and returns a handle to it.
        explicit URL();
        /// @brief Creates a null handle that refers to no native object.
        URL(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URL(Adopt adopt);
        /**
     * @brief Calls `-[NSURL URLByAppendingPathComponent:]`.
     * @details Returns a new URL by appending a path component to the original URL. If the original URL does not end with a forward slash and 'pathComponent' does not begin with a forward slash, a forward slash is inserted between the two parts of the returned URL, unless the original URL is the empty string. If the receiver is a file URL and 'pathComponent' does not end with a trailing slash, this method may read file metadata to determine whether the resulting path is a directory. This is done synchronously, and may have significant performance costs if the receiver is a location on a network mounted filesystem. You can instead use ''URLByAppendingPathComponent:isDirectory:'' if you know whether the resulting path is a directory to avoid this file metadata operation. - Parameter pathComponent: The path component to add to the URL, in its original form (not URL encoded). - Returns: A new URL with 'pathComponent' appended.
     * @param path_component Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_by_appending_path_component(const std::string& path_component) const;
        /**
     * @brief Calls `-[NSURL URLByAppendingPathComponent:isDirectory:]`.
     * @details Returns a new URL by appending a path component to the original URL, along with a trailing slash if the component is a directory. If the original URL does not end with a forward slash and 'pathComponent' does not begin with a forward slash, a forward slash is inserted between the two parts of the returned URL, unless the original URL is the empty string. - Parameters: - pathComponent: The path component to add to the URL. - isDirectory: If 'YES', a trailing slash is appended after 'pathComponent'. - Returns: A new URL with 'pathComponent' appended.
     * @param path_component Argument converted to the Objective-C parameter of the same role.
     * @param is_directory Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_by_appending_path_component(const std::string& path_component, bool is_directory) const;
        /**
     * @brief Calls `-[NSURL URLByAppendingPathExtension:]`.
     * @details Returns a new URL by appending a path extension to the original URL. If the original URL ends with one or more forward slashes, these are removed from the returned URL. A period is inserted between the two parts of the new URL. - Parameter pathExtension: The path extension to add to the URL. - Returns: A new URL with 'pathExtension' appended.
     * @param path_extension Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_by_appending_path_extension(const std::string& path_extension) const;
        /**
     * @brief Calls `+[NSURL URLByResolvingAliasFileAtURL:options:error:]`.
     * @details Returns a new URL made by resolving the alias file at the given URL. Creates and initializes a new URL based on the alias file at 'url'. Use this method to resolve bookmark data that was saved using ''NSURL/writeBookmarkData(:to:options:)'' and resolve that data in one step. If the 'url' argument does not refer to an alias file as defined by the 'NSURLIsAliasFileKey' property, this method returns the 'url' argument. If the 'url' argument is unreachable, this method returns 'nil' and the optional error argument is populated. > Note: The ''NSURL/BookmarkResolutionOptions/withSecurityScope'' option is not supported by this method. - Parameters: - url: The URL pointing to the alias file. - options: Options taken into account when resolving the bookmark data. - error: The error that occurred while trying to resolve the provided URL. - Returns: A new URL created by resolving the bookmark data derived from the provided alias file. If an error occurs, this method returns 'nil'.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL url_by_resolving_alias_file_at_url(const URL& url, URLBookmarkResolutionOptions options);
        /**
     * @brief Calls `+[NSURL URLByResolvingBookmarkData:options:relativeToURL:bookmarkDataIsStale:error:]`.
     * @details Returns a new URL made by resolving bookmark data. This method fails if the original file or directory could not be located or is on a volume that could not be mounted. If this method fails, you can use the ''NSURL/resourceValuesForKeys:fromBookmarkData:'' method to obtain information about the bookmark, such as the last known path (''NSURLPathKey'') to help the user decide how to proceed. To obtain a security-scoped URL from a security-scoped bookmark, call this method using the ''NSURLBookmarkResolutionWithSecurityScope'' option. In addition, to use security scope, you must first have enabled the appropriate entitlements for your app, as described in [Enabling Security-Scoped Bookmark and URL Access](https://developer.apple.com/library/archive/documentation/Miscellaneous/Reference/EntitlementKeyReference/Chapters/EnablingAppSandbox.html\#//apple_ref/doc/uid/TP40011195-CH4-SW18). To then obtain access to the file-system resource pointed to by a security-scoped URL (in other words, to bring the resource into your app's sandbox), call the ''NSURL/startAccessingSecurityScopedResource'' method on the URL. For an app-scoped bookmark, no sandboxed app other than the one that created the bookmark can obtain access to the file-system resource that the URL (obtained from the bookmark) points to. For a document-scoped bookmark, any sandboxed app that has access to the bookmark data itself, and has access to the document that owns the bookmark, can obtain access to the resource. > Note: Security-scoped bookmarks are not available in versions of macOS prior to OS X v10.7.3. - Parameters: - bookmarkData: The bookmark data the URL is derived from. - options: Options taken into account when resolving the bookmark data. To resolve a security-scoped bookmark to support App Sandbox, you must include the ''NSURLBookmarkResolutionWithSecurityScope'' option. - relativeURL: The base URL that the bookmark data is relative to. To resolve an app-scoped bookmark, use a value of 'nil'. To resolve a document-scoped bookmark, use the absolute path to the document from which you retrieved the bookmark. - isStale: On return, if 'YES', the bookmark data is stale. Your app should create a new bookmark using the returned URL and use it in place of any stored copies of the existing bookmark. - error: The error that occurred in the case that the URL cannot be created. - Returns: A new URL made by resolving 'bookmarkData'.
     * @param bookmark_data Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param relative_url Argument converted to the Objective-C parameter of the same role.
     * @param is_stale Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL url_by_resolving_bookmark_data(const std::vector<std::uint8_t>& bookmark_data, URLBookmarkResolutionOptions options, const URL& relative_url, bool* is_stale);
        /**
     * @brief Calls `+[NSURL URLFromPasteboard:]`.
     * @param paste_board Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL url_from_pasteboard(const Pasteboard& paste_board);
        /**
     * @brief Calls `+[NSURL URLWithDataRepresentation:relativeToURL:]`.
     * @details Initializes and returns a newly created NSURL using the contents of the given data, relative to a base URL. If the data representation is not a legal URL string as ASCII bytes, the URL object may not behave as expected.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @param base_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL url_with_data_representation(const std::vector<std::uint8_t>& data, const URL& base_url);
        /**
     * @brief Calls `+[NSURL URLWithString:]`.
     * @details Returns a newly created NSURL initialized with the given URL string.
     * @param url_string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL url_with_string(const std::string& url_string);
        /**
     * @brief Calls `+[NSURL URLWithString:encodingInvalidCharacters:]`.
     * @details Initializes and returns a newly created 'NSURL' with a URL string and the option to add (or skip) IDNA- and percent-encoding of invalid characters. If 'encodingInvalidCharacters' is false, and the URL string is invalid according to RFC 3986, 'nil' is returned. If 'encodingInvalidCharacters' is true, 'NSURL' will try to encode the string to create a valid URL. If the URL string is still invalid after encoding, 'nil' is returned. - Parameter URLString: The URL string. - Parameter encodingInvalidCharacters: True if 'NSURL' should try to encode an invalid URL string, false otherwise. - Returns: An 'NSURL' instance for a valid URL, or 'nil' if the URL is invalid.
     * @param url_string Argument converted to the Objective-C parameter of the same role.
     * @param encoding_invalid_characters Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL url_with_string(const std::string& url_string, bool encoding_invalid_characters);
        /**
     * @brief Calls `+[NSURL URLWithString:relativeToURL:]`.
     * @details Returns a newly created NSURL initialized with the given URL string, relative to a base URL.
     * @param url_string Argument converted to the Objective-C parameter of the same role.
     * @param base_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL url_with_string(const std::string& url_string, const URL& base_url);
        /**
     * @brief Calls `+[NSURL absoluteURLWithDataRepresentation:relativeToURL:]`.
     * @details Initializes and returns a newly created absolute NSURL using the contents of the given data, relative to a base URL. If the data representation is not a legal URL string as ASCII bytes, the URL object may not behave as expected.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @param base_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL absolute_url_with_data_representation(const std::vector<std::uint8_t>& data, const URL& base_url);
        /**
     * @brief Calls `+[NSURL bookmarkDataWithContentsOfURL:error:]`.
     * @details Initializes and returns bookmark data derived from an alias file pointed to by a specified URL. This method doesn't check to see if 'bookmarkFileURL' points to an alias file. This allows this method to work with any file containing bookmark data. If 'bookmarkFileURL' refers to a file which does not contain bookmark data or to a non-file object, such as a directory or symbolic link, this method returns 'nil' and produces an error. If 'bookmarkFileURL' refers to an alias file created prior to OS X v10.6 that contains Alias Manager information but no bookmark data, this method synthesizes bookmark data for the file. This method returns 'nil' if bookmark data cannot be created. - Parameters: - bookmarkFileURL: The URL that points to a file containing bookmark data. - error: The error that occurred in the case that the bookmark data cannot be derived. - Returns: The bookmark data for the alias file.
     * @param bookmark_file_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::uint8_t> bookmark_data_with_contents_of_url(const URL& bookmark_file_url);
        /**
     * @brief Calls `-[NSURL bookmarkDataWithOptions:includingResourceValuesForKeys:relativeToURL:error:]`.
     * @details Returns bookmark data for the URL, created with specified options and resource values. This method returns bookmark data that can later be resolved into a URL object for a file even if the user moves or renames it (if the volume format on which the file resides supports doing so). If the specified URL is not a file URL, this method returns a bookmark containing only the URL, and the 'options' and 'keys' parameters are ignored. You can also use this method to create a security-scoped bookmark to support App Sandbox. Before you do so, you must first enable the appropriate entitlements for your app. In addition, be sure to understand the behavior of the 'options' and 'relativeURL' parameters. For an app-scoped bookmark, no sandboxed app other than the one that created the bookmark can obtain access to the file-system resource that the URL (obtained from the bookmark) points to. For a document-scoped bookmark, any sandboxed app that has access to the bookmark data itself, and has access to the document that owns the bookmark, can obtain access to the resource. - Parameters: - options: Options taken into account when creating the bookmark for the URL. - keys: An array of names of URL resource properties to store as part of the bookmark. - relativeURL: The URL that the bookmark data will be relative to. For an app-scoped bookmark, use 'nil'. For a document-scoped bookmark, use the absolute path to the document file that is to own the bookmark. - error: The error that occurred in the case that the bookmark data cannot be created. - Returns: Bookmark data for the URL, or 'nil' if an error occurred.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param keys Argument converted to the Objective-C parameter of the same role.
     * @param relative_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> bookmark_data_with_options(URLBookmarkCreationOptions options, const std::vector<std::string>& keys, const URL& relative_url) const;
        /**
     * @brief Calls `-[NSURL checkPromisedItemIsReachableAndReturnError:]`.
     * @details Returns whether the promised item can be reached. This method behaves identically to 'checkResourceIsReachableAndReturnError:', but works on promised items. A promised item is not guaranteed to have its contents in the file system until you use a file coordinator to perform a coordinated read on its URL, which causes the contents to be downloaded or otherwise generated. - Parameter error: The error that occurred when the promised item could not be reached. - Returns: 'YES' if the promised item is reachable; otherwise, 'NO'.
     * @return The converted Objective-C result.
     */
        bool check_promised_item_is_reachable_and_return_error() const;
        /**
     * @brief Calls `-[NSURL checkResourceIsReachableAndReturnError:]`.
     * @details Returns whether the resource pointed to by a file URL can be reached. This method synchronously checks if the file at the provided URL is reachable. Checking reachability is appropriate when making decisions that do not require other immediate operations on the resource, such as periodic maintenance of user interface state that depends on the existence of a specific document. If your app must perform operations on the file, such as opening it or copying resource properties, it is more efficient to attempt the operation and handle any failure that may occur. This method is currently applicable only to URLs for file system resources. For other URL types, 'NO' is returned. - Parameter error: The error that occurred when the resource could not be reached. - Returns: 'YES' if the resource is reachable; otherwise, 'NO'.
     * @return The converted Objective-C result.
     */
        bool check_resource_is_reachable_and_return_error() const;
        /**
     * @brief Calls `-[NSURL fileReferenceURL]`.
     * @details Returns a file reference URL that refers to the same resource as a specified file URL. File reference URLs use a URL path syntax that identifies a file system object by reference, not by path. This form of file URL remains valid when the file system path of the URL’s underlying resource changes. A file reference URL’s path should never be persistently stored because it is not valid across system restarts and across remounts of volumes. Use a bookmark instead for persistent references.
     * @return The converted Objective-C result.
     */
        URL file_reference_url() const;
        /**
     * @brief Calls `+[NSURL fileURLWithFileSystemRepresentation:isDirectory:relativeToURL:]`.
     * @details Initializes and returns a newly created URL referencing the local file or directory at the file system representation of the path. File system representation is a null-terminated C string with canonical UTF-8 encoding.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param is_dir Argument converted to the Objective-C parameter of the same role.
     * @param base_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL file_url_with_file_system_representation(const std::string& path, bool is_dir, const URL& base_url);
        /**
     * @brief Calls `+[NSURL fileURLWithPath:]`.
     * @details Initializes and returns a newly created file NSURL referencing the local file or directory at path. Better to use 'fileURLWithPath:isDirectory:' if you know if the path is a directory vs non-directory, as it saves an I/O.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL file_url_with_path(const std::string& path);
        /**
     * @brief Calls `+[NSURL fileURLWithPath:isDirectory:]`.
     * @details Initializes and returns a newly created file NSURL referencing the local file or directory at path.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param is_dir Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL file_url_with_path(const std::string& path, bool is_dir);
        /**
     * @brief Calls `+[NSURL fileURLWithPath:isDirectory:relativeToURL:]`.
     * @details Initializes and returns a newly created file NSURL referencing the local file or directory at path, relative to a base URL.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param is_dir Argument converted to the Objective-C parameter of the same role.
     * @param base_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL file_url_with_path(const std::string& path, bool is_dir, const URL& base_url);
        /**
     * @brief Calls `+[NSURL fileURLWithPath:relativeToURL:]`.
     * @details Initializes and returns a newly created file NSURL referencing the local file or directory at path, relative to a base URL. Better to use 'fileURLWithPath:isDirectory:relativeToURL:' if you know if the path is a directory vs non-directory, as it saves an I/O.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param base_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL file_url_with_path(const std::string& path, const URL& base_url);
        /**
     * @brief Calls `+[NSURL fileURLWithPathComponents:]`.
     * @details Initializes and returns a newly created 'NSURL' object as a file URL with specified path components. The path components are separated by a forward slash in the returned URL. - Parameter components: An array of path components. - Returns: An 'NSURL' object initialized with 'components'.
     * @param components Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL file_url_with_path_components(const std::vector<std::string>& components);
        /**
     * @brief Calls `-[NSURL getFileSystemRepresentation:maxLength:]`.
     * @details Fills a buffer with the URL's path in file system representation. File system representation is a null-terminated C string with canonical UTF-8 encoding.
     * @param buffer Argument converted to the Objective-C parameter of the same role.
     * @param max_buffer_length Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool get_file_system_representation(char* buffer, std::uint64_t max_buffer_length) const;
        /**
     * @brief Calls `-[NSURL isFileReferenceURL]`.
     * @details Returns whether the URL is a file reference URL.
     * @return The converted Objective-C result.
     */
        bool is_file_reference_url() const;
        /**
     * @brief Calls `-[NSURL promisedItemResourceValuesForKeys:error:]`.
     * @details Returns the resource values for the properties identified by specified array of keys from a promised item. This method behaves identically to 'resourceValuesForKeys:error:', but works on promised items. A promised item is not guaranteed to have its contents in the file system until you use a file coordinator to perform a coordinated read on its URL, which causes the contents to be downloaded or otherwise generated. This method works for any resource value that is not tied to the item's contents. Some keys, like 'NSURLContentAccessDateKey' or 'NSURLGenerationIdentifierKey', do not return valid values. - Parameters: - keys: An array of names of URL resource properties. - error: The error that occurred in the case that one or more resource values cannot be retrieved. - Returns: A dictionary of resource values indexed by key.
     * @param keys Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> promised_item_resource_values_for_keys(const std::vector<std::string>& keys) const;
        /**
     * @brief Calls `-[NSURL removeAllCachedResourceValues]`.
     * @details Removes all cached resource values and all temporary resource values from the URL object. This method is currently applicable only to URLs for file system resources.
     */
        void remove_all_cached_resource_values() const;
        /**
     * @brief Calls `-[NSURL removeCachedResourceValueForKey:]`.
     * @details Removes the cached resource value identified by a given key from the URL object. Removing a cached resource value may remove other cached resource values because some resource values are cached as a set, and because some resource values depend on other resource values. This method is currently applicable only to URLs for file system resources.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void remove_cached_resource_value_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSURL resourceValuesForKeys:error:]`.
     * @details Returns the resource values identified by specified array of resource keys. This method first checks if the URL object already caches the resource values. If so, it returns the cached values. If not, it synchronously obtains the values from the backing store and adds them to the cache. If a resource value for one or more requested keys is not present in the result, that property is not available for the resource. This method is currently applicable only to URLs for file system resources.
     * @param keys Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> resource_values_for_keys(const std::vector<std::string>& keys) const;
        /**
     * @brief Calls `+[NSURL resourceValuesForKeys:fromBookmarkData:]`.
     * @details Returns the resource values for properties identified by a specified array of keys contained in specified bookmark data. If the result dictionary does not contain a resource value for one or more of the requested resource keys, it means those resource properties are not available in the bookmark data. - Parameters: - keys: An array of names of URL resource properties. In addition to the standard, system-defined resource properties, you can also request any custom properties that you provided when you created the bookmark. - bookmarkData: The bookmark data from which you want to retrieve resource values. - Returns: A dictionary of the requested resource values contained in 'bookmarkData'.
     * @param keys Argument converted to the Objective-C parameter of the same role.
     * @param bookmark_data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::map<std::string, Object> resource_values_for_keys(const std::vector<std::string>& keys, const std::vector<std::uint8_t>& bookmark_data);
        /**
     * @brief Calls `-[NSURL setResourceValue:forKey:error:]`.
     * @details Sets the resource value identified by a given resource key. This method writes the new resource value out to the backing store. Attempts to set a read-only resource property or to set a resource property not supported by the resource are ignored and are not considered errors. This method is currently applicable only to URLs for file system resources.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_resource_value(const Object& value, const std::string& key) const;
        /**
     * @brief Calls `-[NSURL setResourceValues:error:]`.
     * @details Sets any number of resource values of a URL's resource. This method writes the new resource values out to the backing store. Attempts to set read-only resource properties or to set resource properties not supported by the resource are ignored and are not considered errors. If an error occurs after some resource properties have been successfully changed, the userInfo dictionary in the returned error contains an array of resource keys that were not set with the key 'kCFURLKeysOfUnsetValuesKey'. This method is currently applicable only to URLs for file system resources.
     * @param keyed_values Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_resource_values(const std::map<std::string, Object>& keyed_values) const;
        /**
     * @brief Calls `-[NSURL setTemporaryResourceValue:forKey:]`.
     * @details Sets a temporary resource value on the URL object. Temporary resource values are for client use. They exist only in memory and are never written to the resource's backing store. Once set, a temporary resource value can be read with 'getResourceValue:forKey:error:' or 'resourceValuesForKeys:error:'. To remove a temporary resource value, use 'removeCachedResourceValueForKey:'. This method is currently applicable only to URLs for file system resources.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void set_temporary_resource_value(const Object& value, const std::string& key) const;
        /**
     * @brief Calls `-[NSURL startAccessingSecurityScopedResource]`.
     * @details In an app that has adopted App Sandbox, makes the resource pointed to by a security-scoped URL available to the app. When you obtain a security-scoped URL, such as by resolving a security-scoped bookmark, you cannot immediately use the resource it points to. To make the resource available to your app, by way of adding its location to your app's sandbox, call this method on the security-scoped URL. If this method returns 'YES', then you must relinquish access as soon as you finish using the resource by calling ''stopAccessingSecurityScopedResource''. You must balance each call to this method with a corresponding call to ''stopAccessingSecurityScopedResource''. When you make the last balanced call, you immediately lose access to the resource in question. > Warning: If you fail to relinquish your access to file-system resources when you no longer need them, > your app leaks kernel resources. If sufficient kernel resources leak, your app loses its ability to add > file-system locations to its sandbox until relaunched. - Returns: 'YES' if the request to access the resource succeeded; otherwise, 'NO'.
     * @return The converted Objective-C result.
     */
        bool start_accessing_security_scoped_resource() const;
        /**
     * @brief Calls `-[NSURL stopAccessingSecurityScopedResource]`.
     * @details In an app that adopts App Sandbox, revokes access to the resource pointed to by a security-scoped URL. When you no longer need access to a file or directory pointed to by a security-scoped URL, such as one returned by resolving a security-scoped bookmark, call this method on the URL to relinquish access. You must balance each call to ''startAccessingSecurityScopedResource'' with a call to this method. When you make the last balanced call, you immediately lose access to the resource in question. If you call this method on a URL whose referenced resource you don't have access to, nothing happens. > Warning: If you fail to relinquish your access to file-system resources when you no longer need them, > your app leaks kernel resources. If sufficient kernel resources leak, your app loses its ability to add > file-system locations to its sandbox until relaunched.
     */
        void stop_accessing_security_scoped_resource() const;
        /**
     * @brief Calls `+[NSURL writeBookmarkData:toURL:options:error:]`.
     * @details Creates an alias file on disk at a specified location with specified bookmark data. This method will produce an error if 'bookmarkData' was not created with the 'NSURLBookmarkCreationSuitableForBookmarkFile' option. If 'bookmarkFileURL' points to a directory, the alias file will be created in that directory with its name derived from the information in 'bookmarkData'. If 'bookmarkFileURL' points to a file, the alias file will be created with the location and name indicated by 'bookmarkFileURL', and its extension will be changed to '.alias' if it is not already. - Parameters: - bookmarkData: The bookmark data containing information for the alias file. - bookmarkFileURL: The desired location of the alias file. - options: Options taken into account when creating the alias file. - error: The error that occurred in the case that the alias file cannot be created. - Returns: 'YES' if the alias file is successfully created; otherwise, 'NO'.
     * @param bookmark_data Argument converted to the Objective-C parameter of the same role.
     * @param bookmark_file_url Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool write_bookmark_data(const std::vector<std::uint8_t>& bookmark_data, const URL& bookmark_file_url, std::uint64_t options);
        /**
     * @brief Calls `-[NSURL writeToPasteboard:]`.
     * @param paste_board Argument converted to the Objective-C parameter of the same role.
     */
        void write_to_pasteboard(const Pasteboard& paste_board) const;
        /**
     * @brief Returns the `URLByDeletingLastPathComponent` property of `NSURL`.
     * @details A URL you create by removing the last path component from the receiver. If the URL represents the root path, this property contains a copy of the original URL. Otherwise, if the original URL has only one path component, this property contains the empty string.
     * @return The converted Objective-C result.
     */
        URL url_by_deleting_last_path_component() const;
        /**
     * @brief Returns the `URLByDeletingPathExtension` property of `NSURL`.
     * @details A URL you create by removing the path extension from the receiver, if any. If the URL represents the root path, this property contains a copy of the original URL. If the URL has multiple path extensions, only the last one is removed.
     * @return The converted Objective-C result.
     */
        URL url_by_deleting_path_extension() const;
        /**
     * @brief Returns the `URLByResolvingSymlinksInPath` property of `NSURL`.
     * @details A URL that points to the same resource as the receiver and includes no symbolic links. If the receiver has no symbolic links, this property contains a copy of the original URL. If some symbolic links cannot be resolved, they are left in place. This property only works on URLs with the 'file:' path scheme. For all other URLs, it returns a copy of the receiver.
     * @return The converted Objective-C result.
     */
        URL url_by_resolving_symlinks_in_path() const;
        /**
     * @brief Returns the `URLByStandardizingPath` property of `NSURL`.
     * @details A URL that points to the same resource as the original URL using an absolute path. This property only works on URLs with the 'file:' path scheme. For all other URLs, it returns a copy of the original URL. Like ''NSString/standardizingPath'', this property expands an initial tilde expression, reduces empty components and "'/./'" sequences, and resolves "'..'" references in absolute paths. The resulting path may still contain symbolic links.
     * @return The converted Objective-C result.
     */
        URL url_by_standardizing_path() const;
        /**
     * @brief Returns the `absoluteString` property of `NSURL`.
     * @details The URL string for the receiver as an absolute URL.
     * @return The converted Objective-C result.
     */
        std::string absolute_string() const;
        /**
     * @brief Returns the `absoluteURL` property of `NSURL`.
     * @details The absolute URL. If the receiver is itself absolute, this returns self.
     * @return The converted Objective-C result.
     */
        URL absolute_url() const;
        /**
     * @brief Returns the `baseURL` property of `NSURL`.
     * @details The base URL. May be 'nil'.
     * @return The converted Objective-C result.
     */
        URL base_url() const;
        /**
     * @brief Returns the `dataRepresentation` property of `NSURL`.
     * @details The data representation of the URL's relativeString. If the URL was initialized with 'initWithData:relativeToURL:', the data representation returned are the same bytes as those used at initialization; otherwise, the data representation returned are the bytes of the relativeString encoded with 'NSUTF8StringEncoding'.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> data_representation() const;
        /**
     * @brief Returns the `filePathURL` property of `NSURL`.
     * @details A file path URL that refers to the same resource as this URL. File path URLs use a file system style path. The resource must exist and be reachable to be converted.
     * @return The converted Objective-C result.
     */
        URL file_path_url() const;
        /**
     * @brief Returns the `fileSystemRepresentation` property of `NSURL`.
     * @details The URL's path in file system representation. File system representation is a null-terminated C string with canonical UTF-8 encoding. The returned C string will be automatically freed just as a returned object would be released; use 'getFileSystemRepresentation:maxLength:' if you need to store the representation outside of the autorelease context.
     * @return The converted Objective-C result.
     */
        std::string file_system_representation() const;
        /**
     * @brief Returns the `fileURL` property of `NSURL`.
     * @details A Boolean value that indicates whether the URL scheme is 'file:'. If 'isFileURL' is 'YES', then 'path' is suitable for input into 'NSFileManager' or 'NSPathUtilities'.
     * @return The converted Objective-C result.
     */
        bool is_file_url() const;
        /**
     * @brief Returns the `fragment` property of `NSURL`.
     * @details The fragment component of the URL, or 'nil' if the URL does not conform to RFC 1808.
     * @return The converted Objective-C result.
     */
        std::string fragment() const;
        /**
     * @brief Returns the `hasDirectoryPath` property of `NSURL`.
     * @details A Boolean value that indicates whether the URL's path represents a directory. Determined from the URL string (whether the path component ends with a '/' character). Does not check the resource.
     * @return The converted Objective-C result.
     */
        bool has_directory_path() const;
        /**
     * @brief Returns the `host` property of `NSURL`.
     * @details The host component of the URL, or 'nil' if the URL does not conform to RFC 1808.
     * @return The converted Objective-C result.
     */
        std::string host() const;
        /**
     * @brief Returns the `lastPathComponent` property of `NSURL`.
     * @details The last path component. This property contains the last path component, unescaped. For example, in the URL 'file:///path/to/file', the last path component is 'file'.
     * @return The converted Objective-C result.
     */
        std::string last_path_component() const;
        /**
     * @brief Returns the `parameterString` property of `NSURL`.
     * @details The parameter string of the URL.
     * @return The converted Objective-C result.
     */
        std::string parameter_string() const;
        /**
     * @brief Returns the `password` property of `NSURL`.
     * @details The password component of the URL, or 'nil' if the URL does not conform to RFC 1808.
     * @return The converted Objective-C result.
     */
        std::string password() const;
        /**
     * @brief Returns the `path` property of `NSURL`.
     * @details The path component of the URL, or 'nil' if the URL does not conform to RFC 1808.
     * @return The converted Objective-C result.
     */
        std::string path() const;
        /**
     * @brief Returns the `pathComponents` property of `NSURL`.
     * @details An array containing the path components. Each component is unescaped. For example, in the URL 'file:///directory/directory\%202/file', the path components array would be '\@[\@"/", \@"directory", \@"directory 2", \@"file"]'.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> path_components() const;
        /**
     * @brief Returns the `pathExtension` property of `NSURL`.
     * @details The path extension. This property contains the path extension, unescaped. For example, in the URL 'file:///path/to/file.txt', the path extension is 'txt'.
     * @return The converted Objective-C result.
     */
        std::string path_extension() const;
        /**
     * @brief Returns the `port` property of `NSURL`.
     * @details The port component of the URL, or 'nil' if the URL does not conform to RFC 1808.
     * @return The converted Objective-C result.
     */
        Number port() const;
        /**
     * @brief Returns the `query` property of `NSURL`.
     * @details The query component of the URL, or 'nil' if the URL does not conform to RFC 1808.
     * @return The converted Objective-C result.
     */
        std::string query() const;
        /**
     * @brief Returns the `relativePath` property of `NSURL`.
     * @details The relative path of the URL. Same as 'path' if 'baseURL' is 'nil'.
     * @return The converted Objective-C result.
     */
        std::string relative_path() const;
        /**
     * @brief Returns the `relativeString` property of `NSURL`.
     * @details The relative portion of the URL. If 'baseURL' is 'nil', or if the receiver is itself absolute, this is the same as 'absoluteString'.
     * @return The converted Objective-C result.
     */
        std::string relative_string() const;
        /**
     * @brief Returns the `resourceSpecifier` property of `NSURL`.
     * @details The resource specifier component of the URL.
     * @return The converted Objective-C result.
     */
        std::string resource_specifier() const;
        /**
     * @brief Returns the `scheme` property of `NSURL`.
     * @details The scheme component of the URL. The full URL is the concatenation of '[myURL scheme]', '':'', '[myURL resourceSpecifier]'.
     * @return The converted Objective-C result.
     */
        std::string scheme() const;
        /**
     * @brief Returns the `standardizedURL` property of `NSURL`.
     * @details The standardized form of the URL.
     * @return The converted Objective-C result.
     */
        URL standardized_url() const;
        /**
     * @brief Returns the `user` property of `NSURL`.
     * @details The user component of the URL, or 'nil' if the URL does not conform to RFC 1808.
     * @return The converted Objective-C result.
     */
        std::string user() const;
    };
}
