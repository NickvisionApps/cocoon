#include "generated/url.h"
#include "internal.h"

namespace cocoon
{
    URL::URL(const std::vector<std::uint8_t>& data, const URL& base_url) : URL(Adopt{cocoon::internal::retain([[::NSURL alloc] initAbsoluteURLWithDataRepresentation:cocoon::internal::to_data(data) relativeToURL:cocoon::internal::native<::NSURL>(base_url)])})
    {
    }

    URL::URL(const std::vector<std::uint8_t>& bookmark_data, URLBookmarkResolutionOptions options, const URL& relative_url, bool* is_stale) : URL(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                                                                                   {
                                                                                                                                                                       NSError* __error = nil;
                                                                                                                                                                       id __r = [[::NSURL alloc] initByResolvingBookmarkData:cocoon::internal::to_data(bookmark_data) options:static_cast<::NSURLBookmarkResolutionOptions>(options) relativeToURL:cocoon::internal::native<::NSURL>(relative_url) bookmarkDataIsStale:(BOOL*)(is_stale)error:&__error];
                                                                                                                                                                       if (!__r && __error)
                                                                                                                                                                       {
                                                                                                                                                                           throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                                                                                                       }
                                                                                                                                                                       return __r;
                                                                                                                                                                   }())})
    {
    }

    URL::URL(const std::string& path, bool is_dir, const URL& base_url) : URL(Adopt{cocoon::internal::retain([[::NSURL alloc] initFileURLWithFileSystemRepresentation:path.c_str() isDirectory:static_cast<::BOOL>(is_dir) relativeToURL:cocoon::internal::native<::NSURL>(base_url)])})
    {
    }

    URL::URL(const std::string& path) : URL(Adopt{cocoon::internal::retain([[::NSURL alloc] initFileURLWithPath:cocoon::internal::to(path)])})
    {
    }

    URL::URL(const std::string& path, bool is_dir) : URL(Adopt{cocoon::internal::retain([[::NSURL alloc] initFileURLWithPath:cocoon::internal::to(path) isDirectory:static_cast<::BOOL>(is_dir)])})
    {
    }

    URL::URL(const std::string& path, const URL& base_url) : URL(Adopt{cocoon::internal::retain([[::NSURL alloc] initFileURLWithPath:cocoon::internal::to(path) relativeToURL:cocoon::internal::native<::NSURL>(base_url)])})
    {
    }

    URL::URL() : URL(Adopt{cocoon::internal::retain([[::NSURL alloc] init])})
    {
    }

    URL::URL(std::nullptr_t) : Object(nullptr)
    {
    }

    URL::URL(Adopt adopt) : Object(adopt)
    {
    }

    URL URL::url_by_appending_path_component(const std::string& path_component) const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSURL>(this) URLByAppendingPathComponent:cocoon::internal::to(path_component)]);
    }

    URL URL::url_by_appending_path_component(const std::string& path_component, bool is_directory) const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSURL>(this) URLByAppendingPathComponent:cocoon::internal::to(path_component) isDirectory:static_cast<::BOOL>(is_directory)]);
    }

    URL URL::url_by_appending_path_extension(const std::string& path_extension) const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSURL>(this) URLByAppendingPathExtension:cocoon::internal::to(path_extension)]);
    }

    URL URL::url_by_resolving_alias_file_at_url(const URL& url, URLBookmarkResolutionOptions options)
    {
        NSError* __error = nil;
        auto __r = [::NSURL URLByResolvingAliasFileAtURL:cocoon::internal::native<::NSURL>(url) options:static_cast<::NSURLBookmarkResolutionOptions>(options) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<URL>(__r);
    }

    URL URL::url_by_resolving_bookmark_data(const std::vector<std::uint8_t>& bookmark_data, URLBookmarkResolutionOptions options, const URL& relative_url, bool* is_stale)
    {
        NSError* __error = nil;
        auto __r = [::NSURL URLByResolvingBookmarkData:cocoon::internal::to_data(bookmark_data) options:static_cast<::NSURLBookmarkResolutionOptions>(options) relativeToURL:cocoon::internal::native<::NSURL>(relative_url) bookmarkDataIsStale:(BOOL*)(is_stale)error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<URL>(__r);
    }

    URL URL::url_from_pasteboard(const Pasteboard& paste_board)
    {
        return cocoon::internal::wrap<URL>([::NSURL URLFromPasteboard:cocoon::internal::native<::NSPasteboard>(paste_board)]);
    }

    URL URL::url_with_data_representation(const std::vector<std::uint8_t>& data, const URL& base_url)
    {
        return cocoon::internal::wrap<URL>([::NSURL URLWithDataRepresentation:cocoon::internal::to_data(data) relativeToURL:cocoon::internal::native<::NSURL>(base_url)]);
    }

    URL URL::url_with_string(const std::string& url_string)
    {
        return cocoon::internal::wrap<URL>([::NSURL URLWithString:cocoon::internal::to(url_string)]);
    }

    URL URL::url_with_string(const std::string& url_string, bool encoding_invalid_characters)
    {
        return cocoon::internal::wrap<URL>([::NSURL URLWithString:cocoon::internal::to(url_string) encodingInvalidCharacters:static_cast<::BOOL>(encoding_invalid_characters)]);
    }

    URL URL::url_with_string(const std::string& url_string, const URL& base_url)
    {
        return cocoon::internal::wrap<URL>([::NSURL URLWithString:cocoon::internal::to(url_string) relativeToURL:cocoon::internal::native<::NSURL>(base_url)]);
    }

    URL URL::absolute_url_with_data_representation(const std::vector<std::uint8_t>& data, const URL& base_url)
    {
        return cocoon::internal::wrap<URL>([::NSURL absoluteURLWithDataRepresentation:cocoon::internal::to_data(data) relativeToURL:cocoon::internal::native<::NSURL>(base_url)]);
    }

    std::vector<std::uint8_t> URL::bookmark_data_with_contents_of_url(const URL& bookmark_file_url)
    {
        NSError* __error = nil;
        auto __r = [::NSURL bookmarkDataWithContentsOfURL:cocoon::internal::native<::NSURL>(bookmark_file_url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_data(__r);
    }

    std::vector<std::uint8_t> URL::bookmark_data_with_options(URLBookmarkCreationOptions options, const std::vector<std::string>& keys, const URL& relative_url) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSURL>(this) bookmarkDataWithOptions:static_cast<::NSURLBookmarkCreationOptions>(options)
                                   includingResourceValuesForKeys:cocoon::internal::to_array(keys, [](const std::string& e) -> id
                                                                               {
                                                                                   return cocoon::internal::to(e);
                                                                               })
                                                    relativeToURL:cocoon::internal::native<::NSURL>(relative_url)
                                                            error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_data(__r);
    }

    bool URL::check_promised_item_is_reachable_and_return_error() const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSURL>(this) checkPromisedItemIsReachableAndReturnError:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool URL::check_resource_is_reachable_and_return_error() const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSURL>(this) checkResourceIsReachableAndReturnError:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    URL URL::file_reference_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSURL>(this) fileReferenceURL]);
    }

    URL URL::file_url_with_file_system_representation(const std::string& path, bool is_dir, const URL& base_url)
    {
        return cocoon::internal::wrap<URL>([::NSURL fileURLWithFileSystemRepresentation:path.c_str() isDirectory:static_cast<::BOOL>(is_dir) relativeToURL:cocoon::internal::native<::NSURL>(base_url)]);
    }

    URL URL::file_url_with_path(const std::string& path)
    {
        return cocoon::internal::wrap<URL>([::NSURL fileURLWithPath:cocoon::internal::to(path)]);
    }

    URL URL::file_url_with_path(const std::string& path, bool is_dir)
    {
        return cocoon::internal::wrap<URL>([::NSURL fileURLWithPath:cocoon::internal::to(path) isDirectory:static_cast<::BOOL>(is_dir)]);
    }

    URL URL::file_url_with_path(const std::string& path, bool is_dir, const URL& base_url)
    {
        return cocoon::internal::wrap<URL>([::NSURL fileURLWithPath:cocoon::internal::to(path) isDirectory:static_cast<::BOOL>(is_dir) relativeToURL:cocoon::internal::native<::NSURL>(base_url)]);
    }

    URL URL::file_url_with_path(const std::string& path, const URL& base_url)
    {
        return cocoon::internal::wrap<URL>([::NSURL fileURLWithPath:cocoon::internal::to(path) relativeToURL:cocoon::internal::native<::NSURL>(base_url)]);
    }

    URL URL::file_url_with_path_components(const std::vector<std::string>& components)
    {
        return cocoon::internal::wrap<URL>([::NSURL fileURLWithPathComponents:cocoon::internal::to_array(components, [](const std::string& e) -> id
                                                                             {
                                                                                 return cocoon::internal::to(e);
                                                                             })]);
    }

    bool URL::get_file_system_representation(char* buffer, std::uint64_t max_buffer_length) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURL>(this) getFileSystemRepresentation:(char*)(buffer) maxLength:static_cast<::NSUInteger>(max_buffer_length)]);
    }

    bool URL::is_file_reference_url() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURL>(this) isFileReferenceURL]);
    }

    std::map<std::string, Object> URL::promised_item_resource_values_for_keys(const std::vector<std::string>& keys) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSURL>(this) promisedItemResourceValuesForKeys:cocoon::internal::to_array(keys, [](const std::string& e) -> id
                                                                                         {
                                                                                             return cocoon::internal::to(e);
                                                                                         })
                                                                      error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>(__r, [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    void URL::remove_all_cached_resource_values() const
    {
        [cocoon::internal::ns<::NSURL>(this) removeAllCachedResourceValues];
    }

    void URL::remove_cached_resource_value_for_key(const std::string& key) const
    {
        [cocoon::internal::ns<::NSURL>(this) removeCachedResourceValueForKey:cocoon::internal::to(key)];
    }

    std::map<std::string, Object> URL::resource_values_for_keys(const std::vector<std::string>& keys) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSURL>(this) resourceValuesForKeys:cocoon::internal::to_array(keys, [](const std::string& e) -> id
                                                                             {
                                                                                 return cocoon::internal::to(e);
                                                                             })
                                                          error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>(__r, [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    std::map<std::string, Object> URL::resource_values_for_keys(const std::vector<std::string>& keys, const std::vector<std::uint8_t>& bookmark_data)
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([::NSURL resourceValuesForKeys:cocoon::internal::to_array(keys, [](const std::string& e) -> id
                                                                                                              {
                                                                                                                  return cocoon::internal::to(e);
                                                                                                              })
                                                                                fromBookmarkData:cocoon::internal::to_data(bookmark_data)],
                                                                  [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    bool URL::set_resource_value(const Object& value, const std::string& key) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSURL>(this) setResourceValue:cocoon::internal::native_id(value) forKey:cocoon::internal::to(key) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool URL::set_resource_values(const std::map<std::string, Object>& keyed_values) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSURL>(this) setResourceValues:cocoon::internal::to_dictionary(keyed_values, [](const std::string& k) -> id
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

    void URL::set_temporary_resource_value(const Object& value, const std::string& key) const
    {
        [cocoon::internal::ns<::NSURL>(this) setTemporaryResourceValue:cocoon::internal::native_id(value) forKey:cocoon::internal::to(key)];
    }

    bool URL::start_accessing_security_scoped_resource() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURL>(this) startAccessingSecurityScopedResource]);
    }

    void URL::stop_accessing_security_scoped_resource() const
    {
        [cocoon::internal::ns<::NSURL>(this) stopAccessingSecurityScopedResource];
    }

    bool URL::write_bookmark_data(const std::vector<std::uint8_t>& bookmark_data, const URL& bookmark_file_url, std::uint64_t options)
    {
        NSError* __error = nil;
        auto __r = [::NSURL writeBookmarkData:cocoon::internal::to_data(bookmark_data) toURL:cocoon::internal::native<::NSURL>(bookmark_file_url) options:static_cast<::NSURLBookmarkFileCreationOptions>(options) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    void URL::write_to_pasteboard(const Pasteboard& paste_board) const
    {
        [cocoon::internal::ns<::NSURL>(this) writeToPasteboard:cocoon::internal::native<::NSPasteboard>(paste_board)];
    }

    URL URL::url_by_deleting_last_path_component() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSURL>(this) URLByDeletingLastPathComponent]);
    }

    URL URL::url_by_deleting_path_extension() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSURL>(this) URLByDeletingPathExtension]);
    }

    URL URL::url_by_resolving_symlinks_in_path() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSURL>(this) URLByResolvingSymlinksInPath]);
    }

    URL URL::url_by_standardizing_path() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSURL>(this) URLByStandardizingPath]);
    }

    std::string URL::absolute_string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURL>(this) absoluteString]);
    }

    URL URL::absolute_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSURL>(this) absoluteURL]);
    }

    URL URL::base_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSURL>(this) baseURL]);
    }

    std::vector<std::uint8_t> URL::data_representation() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSURL>(this) dataRepresentation]);
    }

    URL URL::file_path_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSURL>(this) filePathURL]);
    }

    std::string URL::file_system_representation() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURL>(this) fileSystemRepresentation]);
    }

    bool URL::is_file_url() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURL>(this) isFileURL]);
    }

    std::string URL::fragment() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURL>(this) fragment]);
    }

    bool URL::has_directory_path() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURL>(this) hasDirectoryPath]);
    }

    std::string URL::host() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURL>(this) host]);
    }

    std::string URL::last_path_component() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURL>(this) lastPathComponent]);
    }

    std::string URL::parameter_string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURL>(this) parameterString]);
    }

    std::string URL::password() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURL>(this) password]);
    }

    std::string URL::path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURL>(this) path]);
    }

    std::vector<std::string> URL::path_components() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSURL>(this) pathComponents], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::string URL::path_extension() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURL>(this) pathExtension]);
    }

    Number URL::port() const
    {
        return cocoon::internal::wrap<Number>([cocoon::internal::ns<::NSURL>(this) port]);
    }

    std::string URL::query() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURL>(this) query]);
    }

    std::string URL::relative_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURL>(this) relativePath]);
    }

    std::string URL::relative_string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURL>(this) relativeString]);
    }

    std::string URL::resource_specifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURL>(this) resourceSpecifier]);
    }

    std::string URL::scheme() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURL>(this) scheme]);
    }

    URL URL::standardized_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSURL>(this) standardizedURL]);
    }

    std::string URL::user() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURL>(this) user]);
    }
}
