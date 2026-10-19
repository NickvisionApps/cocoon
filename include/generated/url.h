#pragma once

#include "generated/availability.h"
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
     * @param path_component Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_by_appending_path_component(const std::string& path_component) const;
        /**
     * @brief Calls `-[NSURL URLByAppendingPathComponent:isDirectory:]`.
     * @param path_component Argument converted to the Objective-C parameter of the same role.
     * @param is_directory Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_by_appending_path_component(const std::string& path_component, bool is_directory) const;
        /**
     * @brief Calls `-[NSURL URLByAppendingPathExtension:]`.
     * @param path_extension Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        URL url_by_appending_path_extension(const std::string& path_extension) const;
        /**
     * @brief Calls `+[NSURL URLByResolvingAliasFileAtURL:options:error:]`.
     * @details Creates and initializes a NSURL that refers to the location specified by resolving the alias file at url. If the url argument does not refer to an alias file as defined by the NSURLIsAliasFileKey property, the NSURL returned is the same as url argument. This method fails and returns nil if the url argument is unreachable, or if the original file or directory could not be located or is not reachable, or if the original file or directory is on a volume that could not be located or mounted. If this method fails, the optional error is populated. The NSURLBookmarkResolutionWithSecurityScope option is not supported by this method.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL url_by_resolving_alias_file_at_url(const URL& url, URLBookmarkResolutionOptions options);
        /**
     * @brief Calls `+[NSURL URLByResolvingBookmarkData:options:relativeToURL:bookmarkDataIsStale:error:]`.
     * @details Creates and Initializes an NSURL that refers to a location specified by resolving bookmark data. If this method returns nil, the optional error is populated.
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
     * @details Initializes and returns bookmark data derived from an alias file pointed to by a specified URL. If bookmarkFileURL refers to an alias file created prior to OS X v10.6 that contains Alias Manager information but no bookmark data, this method synthesizes bookmark data for the file. If this method returns nil, the optional error is populated.
     * @param bookmark_file_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::uint8_t> bookmark_data_with_contents_of_url(const URL& bookmark_file_url);
        /**
     * @brief Calls `-[NSURL bookmarkDataWithOptions:includingResourceValuesForKeys:relativeToURL:error:]`.
     * @details Returns bookmark data for the URL, created with specified options and resource values. If this method returns nil, the optional error is populated.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param keys Argument converted to the Objective-C parameter of the same role.
     * @param relative_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> bookmark_data_with_options(URLBookmarkCreationOptions options, const std::vector<std::string>& keys, const URL& relative_url) const;
        /**
     * @brief Calls `-[NSURL checkPromisedItemIsReachableAndReturnError:]`.
     * @return The converted Objective-C result.
     */
        bool check_promised_item_is_reachable_and_return_error() const;
        /**
     * @brief Calls `-[NSURL checkResourceIsReachableAndReturnError:]`.
     * @details Returns whether the URL's resource exists and is reachable. This method synchronously checks if the resource's backing store is reachable. Checking reachability is appropriate when making decisions that do not require other immediate operations on the resource, e.g. periodic maintenance of UI state that depends on the existence of a specific document. When performing operations such as opening a file or copying resource properties, it is more efficient to simply try the operation and handle failures. If this method returns NO, the optional error is populated. This method is currently applicable only to URLs for file system resources. For other URL types, NO is returned. Symbol is present in iOS 4, but performs no operation.
     * @return The converted Objective-C result.
     */
        bool check_resource_is_reachable_and_return_error() const;
        /**
     * @brief Calls `-[NSURL fileReferenceURL]`.
     * @details Returns a file reference URL that refers to the same resource as a specified file URL. File reference URLs use a URL path syntax that identifies a file system object by reference, not by path. This form of file URL remains valid when the file system path of the URL’s underlying resource changes. An error will occur if the url parameter is not a file URL. File reference URLs cannot be created to file system objects which do not exist or are not reachable. In some areas of the file system hierarchy, file reference URLs cannot be generated to the leaf node of the URL path. A file reference URL's path should never be persistently stored because is not valid across system restarts, and across remounts of volumes -- if you want to create a persistent reference to a file system object, use a bookmark (see -bookmarkDataWithOptions:includingResourceValuesForKeys:relativeToURL:error:). Symbol is present in iOS 4, but performs no operation.
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
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL file_url_with_path(const std::string& path);
        /**
     * @brief Calls `+[NSURL fileURLWithPath:isDirectory:]`.
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
     * @details Initializes and returns a newly created file NSURL referencing the local file or directory at path, relative to a base URL.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param base_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL file_url_with_path(const std::string& path, const URL& base_url);
        /**
     * @brief Calls `+[NSURL fileURLWithPathComponents:]`.
     * @details The following methods work on the path portion of a URL in the same manner that the NSPathUtilities methods on NSString do.
     * @param components Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URL file_url_with_path_components(const std::vector<std::string>& components);
        /**
     * @brief Calls `-[NSURL getFileSystemRepresentation:maxLength:]`.
     * @details Returns the URL's path in file system representation. File system representation is a null-terminated C string with canonical UTF-8 encoding.
     * @param buffer Argument converted to the Objective-C parameter of the same role.
     * @param max_buffer_length Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool get_file_system_representation(char* buffer, std::uint64_t max_buffer_length) const;
        /**
     * @brief Calls `-[NSURL isFileReferenceURL]`.
     * @details Returns whether the URL is a file reference URL. Symbol is present in iOS 4, but performs no operation.
     * @return The converted Objective-C result.
     */
        bool is_file_reference_url() const;
        /**
     * @brief Calls `-[NSURL promisedItemResourceValuesForKeys:error:]`.
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
     * @details Removes the cached resource value identified by a given resource value key from the URL object. Removing a cached resource value may remove other cached resource values because some resource values are cached as a set of values, and because some resource values depend on other resource values (temporary resource values have no dependencies). This method is currently applicable only to URLs for file system resources.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void remove_cached_resource_value_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSURL resourceValuesForKeys:error:]`.
     * @details Returns the resource values identified by specified array of resource keys. This method first checks if the URL object already caches the resource values. If so, it returns the cached resource values to the caller. If not, then this method synchronously obtains the resource values from the backing store, adds the resource values to the URL object's cache, and returns the resource values to the caller. The type of the resource values vary by property (see resource key definitions). If the result dictionary does not contain a resource value for one or more of the requested resource keys, it means those resource properties are not available for the specified resource and no errors occurred when determining those resource properties were not available. If this method returns NULL, the optional error is populated. This method is currently applicable only to URLs for file system resources. Symbol is present in iOS 4, but performs no operation.
     * @param keys Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> resource_values_for_keys(const std::vector<std::string>& keys) const;
        /**
     * @brief Calls `+[NSURL resourceValuesForKeys:fromBookmarkData:]`.
     * @details Returns the resource values for properties identified by a specified array of keys contained in specified bookmark data. If the result dictionary does not contain a resource value for one or more of the requested resource keys, it means those resource properties are not available in the bookmark data.
     * @param keys Argument converted to the Objective-C parameter of the same role.
     * @param bookmark_data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::map<std::string, Object> resource_values_for_keys(const std::vector<std::string>& keys, const std::vector<std::uint8_t>& bookmark_data);
        /**
     * @brief Calls `-[NSURL setResourceValue:forKey:error:]`.
     * @details Sets the resource value identified by a given resource key. This method writes the new resource value out to the backing store. Attempts to set a read-only resource property or to set a resource property not supported by the resource are ignored and are not considered errors. If this method returns NO, the optional error is populated. This method is currently applicable only to URLs for file system resources. Symbol is present in iOS 4, but performs no operation.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_resource_value(const Object& value, const std::string& key) const;
        /**
     * @brief Calls `-[NSURL setResourceValues:error:]`.
     * @details Sets any number of resource values of a URL's resource. This method writes the new resource values out to the backing store. Attempts to set read-only resource properties or to set resource properties not supported by the resource are ignored and are not considered errors. If an error occurs after some resource properties have been successfully changed, the userInfo dictionary in the returned error contains an array of resource keys that were not set with the key kCFURLKeysOfUnsetValuesKey. The order in which the resource values are set is not defined. If you need to guarantee the order resource values are set, you should make multiple requests to this method or to -setResourceValue:forKey:error: to guarantee the order. If this method returns NO, the optional error is populated. This method is currently applicable only to URLs for file system resources. Symbol is present in iOS 4, but performs no operation.
     * @param keyed_values Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_resource_values(const std::map<std::string, Object>& keyed_values) const;
        /**
     * @brief Calls `-[NSURL setTemporaryResourceValue:forKey:]`.
     * @details Sets a temporary resource value on the URL object. Temporary resource values are for client use. Temporary resource values exist only in memory and are never written to the resource's backing store. Once set, a temporary resource value can be copied from the URL object with -getResourceValue:forKey:error: or -resourceValuesForKeys:error:. To remove a temporary resource value from the URL object, use -removeCachedResourceValueForKey:. Care should be taken to ensure the key that identifies a temporary resource value is unique and does not conflict with system defined keys (using reverse domain name notation in your temporary resource value keys is recommended). This method is currently applicable only to URLs for file system resources.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void set_temporary_resource_value(const Object& value, const std::string& key) const;
        /**
     * @brief Calls `-[NSURL startAccessingSecurityScopedResource]`.
     * @details Given a NSURL created by resolving a bookmark data created with security scope, make the resource referenced by the url accessible to the process. Each call to startAccessingSecurityScopedResource that returns YES must be balanced with a call to stopAccessingSecurityScopedResource when access to this resource is no longer needed by the client. Calls to start and stop accessing the resource are reference counted and may be nested, which allows the pair of calls to be logically scoped.
     * @return The converted Objective-C result.
     */
        bool start_accessing_security_scoped_resource() const;
        /**
     * @brief Calls `-[NSURL stopAccessingSecurityScopedResource]`.
     * @details Removes one "accessing" reference to the security scope. When all references are removed, it revokes the access granted to the url by the initial prior successful call to startAccessingSecurityScopedResource.
     */
        void stop_accessing_security_scoped_resource() const;
        /**
     * @brief Calls `+[NSURL writeBookmarkData:toURL:options:error:]`.
     * @details Creates an alias file on disk at a specified location with specified bookmark data. bookmarkData must have been created with the NSURLBookmarkCreationSuitableForBookmarkFile option. bookmarkFileURL must either refer to an existing file (which will be overwritten), or to location in an existing directory. If this method returns NO, the optional error is populated.
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
     * @return The converted Objective-C result.
     */
        URL url_by_deleting_last_path_component() const;
        /**
     * @brief Returns the `URLByDeletingPathExtension` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        URL url_by_deleting_path_extension() const;
        /**
     * @brief Returns the `URLByResolvingSymlinksInPath` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        URL url_by_resolving_symlinks_in_path() const;
        /**
     * @brief Returns the `URLByStandardizingPath` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        URL url_by_standardizing_path() const;
        /**
     * @brief Returns the `absoluteString` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        std::string absolute_string() const;
        /**
     * @brief Returns the `absoluteURL` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        URL absolute_url() const;
        /**
     * @brief Returns the `baseURL` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        URL base_url() const;
        /**
     * @brief Returns the `dataRepresentation` property of `NSURL`.
     * @details Returns the data representation of the URL's relativeString. If the URL was initialized with -initWithData:relativeToURL:, the data representation returned are the same bytes as those used at initialization; otherwise, the data representation returned are the bytes of the relativeString encoded with NSUTF8StringEncoding.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> data_representation() const;
        /**
     * @brief Returns the `filePathURL` property of `NSURL`.
     * @details Returns a file path URL that refers to the same resource as a specified URL. File path URLs use a file system style path. An error will occur if the url parameter is not a file URL. A file reference URL's resource must exist and be reachable to be converted to a file path URL. Symbol is present in iOS 4, but performs no operation.
     * @return The converted Objective-C result.
     */
        URL file_path_url() const;
        /**
     * @brief Returns the `fileSystemRepresentation` property of `NSURL`.
     * @details Returns the URL's path in file system representation. File system representation is a null-terminated C string with canonical UTF-8 encoding. The returned C string will be automatically freed just as a returned object would be released; your code should copy the representation or use getFileSystemRepresentation:maxLength: if it needs to store the representation outside of the autorelease context in which the representation is created.
     * @return The converted Objective-C result.
     */
        std::string file_system_representation() const;
        /**
     * @brief Returns the `fileURL` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        bool is_file_url() const;
        /**
     * @brief Returns the `fragment` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        std::string fragment() const;
        /**
     * @brief Returns the `hasDirectoryPath` property of `NSURL`.
     * @details Determines if a given URL string's path represents a directory (i.e. the path component in the URL string ends with a '/' character). This does not check the resource the URL refers to.
     * @return The converted Objective-C result.
     */
        bool has_directory_path() const;
        /**
     * @brief Returns the `host` property of `NSURL`.
     * @details If the URL conforms to rfc 1808 (the most common form of URL), the following accessors will return the various components; otherwise they return nil. The litmus test for conformance is as recommended in RFC 1808 - whether the first two characters of resourceSpecifier is \@"//". In all cases, they return the component's value after resolving the receiver against its base URL.
     * @return The converted Objective-C result.
     */
        std::string host() const;
        /**
     * @brief Returns the `lastPathComponent` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        std::string last_path_component() const;
        /**
     * @brief Returns the `password` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        std::string password() const;
        /**
     * @brief Returns the `path` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        std::string path() const;
        /**
     * @brief Returns the `pathComponents` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> path_components() const;
        /**
     * @brief Returns the `pathExtension` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        std::string path_extension() const;
        /**
     * @brief Returns the `port` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        Number port() const;
        /**
     * @brief Returns the `query` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        std::string query() const;
        /**
     * @brief Returns the `relativePath` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        std::string relative_path() const;
        /**
     * @brief Returns the `relativeString` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        std::string relative_string() const;
        /**
     * @brief Returns the `resourceSpecifier` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        std::string resource_specifier() const;
        /**
     * @brief Returns the `scheme` property of `NSURL`.
     * @details Any URL is composed of these two basic pieces. The full URL would be the concatenation of [myURL scheme], ':', [myURL resourceSpecifier]
     * @return The converted Objective-C result.
     */
        std::string scheme() const;
        /**
     * @brief Returns the `standardizedURL` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        URL standardized_url() const;
        /**
     * @brief Returns the `user` property of `NSURL`.
     * @return The converted Objective-C result.
     */
        std::string user() const;
    };
}
