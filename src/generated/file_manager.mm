#include "generated/file_manager.h"
#include "internal.h"

@interface AKFileManagerDelegate : NSObject <NSFileManagerDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKFileManagerDelegate

- (BOOL)fileManager:(NSFileManager*)fileManager shouldCopyItemAtPath:(NSString*)srcPath toPath:(NSString*)dstPath
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::FileManager, bool(std::string, std::string)>::emit((__bridge void*)strongHost, "should_copy_item_at_path_to_path", cocoon::internal::from(srcPath), cocoon::internal::from(dstPath));
    return static_cast<::BOOL>(__r);
}

- (BOOL)fileManager:(NSFileManager*)fileManager shouldCopyItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::FileManager, bool(cocoon::URL, cocoon::URL)>::emit((__bridge void*)strongHost, "should_copy_item_at_url_to_url", cocoon::internal::wrap<cocoon::URL>(srcURL), cocoon::internal::wrap<cocoon::URL>(dstURL));
    return static_cast<::BOOL>(__r);
}

- (BOOL)fileManager:(NSFileManager*)fileManager shouldProceedAfterError:(NSError*)error copyingItemAtPath:(NSString*)srcPath toPath:(NSString*)dstPath
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::FileManager, bool(cocoon::Error, std::string, std::string)>::emit((__bridge void*)strongHost, "should_proceed_after_error_copying_item_at_path_to_path", cocoon::internal::wrap<cocoon::Error>(error), cocoon::internal::from(srcPath), cocoon::internal::from(dstPath));
    return static_cast<::BOOL>(__r);
}

- (BOOL)fileManager:(NSFileManager*)fileManager shouldProceedAfterError:(NSError*)error copyingItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::FileManager, bool(cocoon::Error, cocoon::URL, cocoon::URL)>::emit((__bridge void*)strongHost, "should_proceed_after_error_copying_item_at_url_to_url", cocoon::internal::wrap<cocoon::Error>(error), cocoon::internal::wrap<cocoon::URL>(srcURL), cocoon::internal::wrap<cocoon::URL>(dstURL));
    return static_cast<::BOOL>(__r);
}

- (BOOL)fileManager:(NSFileManager*)fileManager shouldMoveItemAtPath:(NSString*)srcPath toPath:(NSString*)dstPath
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::FileManager, bool(std::string, std::string)>::emit((__bridge void*)strongHost, "should_move_item_at_path_to_path", cocoon::internal::from(srcPath), cocoon::internal::from(dstPath));
    return static_cast<::BOOL>(__r);
}

- (BOOL)fileManager:(NSFileManager*)fileManager shouldMoveItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::FileManager, bool(cocoon::URL, cocoon::URL)>::emit((__bridge void*)strongHost, "should_move_item_at_url_to_url", cocoon::internal::wrap<cocoon::URL>(srcURL), cocoon::internal::wrap<cocoon::URL>(dstURL));
    return static_cast<::BOOL>(__r);
}

- (BOOL)fileManager:(NSFileManager*)fileManager shouldProceedAfterError:(NSError*)error movingItemAtPath:(NSString*)srcPath toPath:(NSString*)dstPath
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::FileManager, bool(cocoon::Error, std::string, std::string)>::emit((__bridge void*)strongHost, "should_proceed_after_error_moving_item_at_path_to_path", cocoon::internal::wrap<cocoon::Error>(error), cocoon::internal::from(srcPath), cocoon::internal::from(dstPath));
    return static_cast<::BOOL>(__r);
}

- (BOOL)fileManager:(NSFileManager*)fileManager shouldProceedAfterError:(NSError*)error movingItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::FileManager, bool(cocoon::Error, cocoon::URL, cocoon::URL)>::emit((__bridge void*)strongHost, "should_proceed_after_error_moving_item_at_url_to_url", cocoon::internal::wrap<cocoon::Error>(error), cocoon::internal::wrap<cocoon::URL>(srcURL), cocoon::internal::wrap<cocoon::URL>(dstURL));
    return static_cast<::BOOL>(__r);
}

- (BOOL)fileManager:(NSFileManager*)fileManager shouldLinkItemAtPath:(NSString*)srcPath toPath:(NSString*)dstPath
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::FileManager, bool(std::string, std::string)>::emit((__bridge void*)strongHost, "should_link_item_at_path_to_path", cocoon::internal::from(srcPath), cocoon::internal::from(dstPath));
    return static_cast<::BOOL>(__r);
}

- (BOOL)fileManager:(NSFileManager*)fileManager shouldLinkItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::FileManager, bool(cocoon::URL, cocoon::URL)>::emit((__bridge void*)strongHost, "should_link_item_at_url_to_url", cocoon::internal::wrap<cocoon::URL>(srcURL), cocoon::internal::wrap<cocoon::URL>(dstURL));
    return static_cast<::BOOL>(__r);
}

- (BOOL)fileManager:(NSFileManager*)fileManager shouldProceedAfterError:(NSError*)error linkingItemAtPath:(NSString*)srcPath toPath:(NSString*)dstPath
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::FileManager, bool(cocoon::Error, std::string, std::string)>::emit((__bridge void*)strongHost, "should_proceed_after_error_linking_item_at_path_to_path", cocoon::internal::wrap<cocoon::Error>(error), cocoon::internal::from(srcPath), cocoon::internal::from(dstPath));
    return static_cast<::BOOL>(__r);
}

- (BOOL)fileManager:(NSFileManager*)fileManager shouldProceedAfterError:(NSError*)error linkingItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::FileManager, bool(cocoon::Error, cocoon::URL, cocoon::URL)>::emit((__bridge void*)strongHost, "should_proceed_after_error_linking_item_at_url_to_url", cocoon::internal::wrap<cocoon::Error>(error), cocoon::internal::wrap<cocoon::URL>(srcURL), cocoon::internal::wrap<cocoon::URL>(dstURL));
    return static_cast<::BOOL>(__r);
}

- (BOOL)fileManager:(NSFileManager*)fileManager shouldRemoveItemAtPath:(NSString*)path
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::FileManager, bool(std::string)>::emit((__bridge void*)strongHost, "should_remove_item_at_path", cocoon::internal::from(path));
    return static_cast<::BOOL>(__r);
}

- (BOOL)fileManager:(NSFileManager*)fileManager shouldRemoveItemAtURL:(NSURL*)URL_
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::FileManager, bool(cocoon::URL)>::emit((__bridge void*)strongHost, "should_remove_item_at_url", cocoon::internal::wrap<cocoon::URL>(URL_));
    return static_cast<::BOOL>(__r);
}

- (BOOL)fileManager:(NSFileManager*)fileManager shouldProceedAfterError:(NSError*)error removingItemAtPath:(NSString*)path
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::FileManager, bool(cocoon::Error, std::string)>::emit((__bridge void*)strongHost, "should_proceed_after_error_removing_item_at_path", cocoon::internal::wrap<cocoon::Error>(error), cocoon::internal::from(path));
    return static_cast<::BOOL>(__r);
}

- (BOOL)fileManager:(NSFileManager*)fileManager shouldProceedAfterError:(NSError*)error removingItemAtURL:(NSURL*)URL_
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::FileManager, bool(cocoon::Error, cocoon::URL)>::emit((__bridge void*)strongHost, "should_proceed_after_error_removing_item_at_url", cocoon::internal::wrap<cocoon::Error>(error), cocoon::internal::wrap<cocoon::URL>(URL_));
    return static_cast<::BOOL>(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(fileManager:shouldCopyItemAtPath:toPath:))
    {
        return strongHost && cocoon::Signal<cocoon::FileManager, bool(std::string, std::string)>::connected((__bridge void*)strongHost, "should_copy_item_at_path_to_path");
    }
    if (selector == @selector(fileManager:shouldCopyItemAtURL:toURL:))
    {
        return strongHost && cocoon::Signal<cocoon::FileManager, bool(cocoon::URL, cocoon::URL)>::connected((__bridge void*)strongHost, "should_copy_item_at_url_to_url");
    }
    if (selector == @selector(fileManager:shouldProceedAfterError:copyingItemAtPath:toPath:))
    {
        return strongHost && cocoon::Signal<cocoon::FileManager, bool(cocoon::Error, std::string, std::string)>::connected((__bridge void*)strongHost, "should_proceed_after_error_copying_item_at_path_to_path");
    }
    if (selector == @selector(fileManager:shouldProceedAfterError:copyingItemAtURL:toURL:))
    {
        return strongHost && cocoon::Signal<cocoon::FileManager, bool(cocoon::Error, cocoon::URL, cocoon::URL)>::connected((__bridge void*)strongHost, "should_proceed_after_error_copying_item_at_url_to_url");
    }
    if (selector == @selector(fileManager:shouldMoveItemAtPath:toPath:))
    {
        return strongHost && cocoon::Signal<cocoon::FileManager, bool(std::string, std::string)>::connected((__bridge void*)strongHost, "should_move_item_at_path_to_path");
    }
    if (selector == @selector(fileManager:shouldMoveItemAtURL:toURL:))
    {
        return strongHost && cocoon::Signal<cocoon::FileManager, bool(cocoon::URL, cocoon::URL)>::connected((__bridge void*)strongHost, "should_move_item_at_url_to_url");
    }
    if (selector == @selector(fileManager:shouldProceedAfterError:movingItemAtPath:toPath:))
    {
        return strongHost && cocoon::Signal<cocoon::FileManager, bool(cocoon::Error, std::string, std::string)>::connected((__bridge void*)strongHost, "should_proceed_after_error_moving_item_at_path_to_path");
    }
    if (selector == @selector(fileManager:shouldProceedAfterError:movingItemAtURL:toURL:))
    {
        return strongHost && cocoon::Signal<cocoon::FileManager, bool(cocoon::Error, cocoon::URL, cocoon::URL)>::connected((__bridge void*)strongHost, "should_proceed_after_error_moving_item_at_url_to_url");
    }
    if (selector == @selector(fileManager:shouldLinkItemAtPath:toPath:))
    {
        return strongHost && cocoon::Signal<cocoon::FileManager, bool(std::string, std::string)>::connected((__bridge void*)strongHost, "should_link_item_at_path_to_path");
    }
    if (selector == @selector(fileManager:shouldLinkItemAtURL:toURL:))
    {
        return strongHost && cocoon::Signal<cocoon::FileManager, bool(cocoon::URL, cocoon::URL)>::connected((__bridge void*)strongHost, "should_link_item_at_url_to_url");
    }
    if (selector == @selector(fileManager:shouldProceedAfterError:linkingItemAtPath:toPath:))
    {
        return strongHost && cocoon::Signal<cocoon::FileManager, bool(cocoon::Error, std::string, std::string)>::connected((__bridge void*)strongHost, "should_proceed_after_error_linking_item_at_path_to_path");
    }
    if (selector == @selector(fileManager:shouldProceedAfterError:linkingItemAtURL:toURL:))
    {
        return strongHost && cocoon::Signal<cocoon::FileManager, bool(cocoon::Error, cocoon::URL, cocoon::URL)>::connected((__bridge void*)strongHost, "should_proceed_after_error_linking_item_at_url_to_url");
    }
    if (selector == @selector(fileManager:shouldRemoveItemAtPath:))
    {
        return strongHost && cocoon::Signal<cocoon::FileManager, bool(std::string)>::connected((__bridge void*)strongHost, "should_remove_item_at_path");
    }
    if (selector == @selector(fileManager:shouldRemoveItemAtURL:))
    {
        return strongHost && cocoon::Signal<cocoon::FileManager, bool(cocoon::URL)>::connected((__bridge void*)strongHost, "should_remove_item_at_url");
    }
    if (selector == @selector(fileManager:shouldProceedAfterError:removingItemAtPath:))
    {
        return strongHost && cocoon::Signal<cocoon::FileManager, bool(cocoon::Error, std::string)>::connected((__bridge void*)strongHost, "should_proceed_after_error_removing_item_at_path");
    }
    if (selector == @selector(fileManager:shouldProceedAfterError:removingItemAtURL:))
    {
        return strongHost && cocoon::Signal<cocoon::FileManager, bool(cocoon::Error, cocoon::URL)>::connected((__bridge void*)strongHost, "should_proceed_after_error_removing_item_at_url");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    FileManager::FileManager() : FileManager(Adopt{cocoon::internal::retain([[::NSFileManager alloc] init])})
    {
        FileManager::install_delegate_delegate_(handle());
    }

    FileManager::FileManager(std::nullptr_t) : Object(nullptr)
    {
    }

    FileManager::FileManager(Adopt adopt) : Object(adopt)
    {
    }

    URL FileManager::url_for_directory(SearchPathDirectory directory, SearchPathDomainMask domain, const URL& url, bool should_create) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) URLForDirectory:static_cast<::NSSearchPathDirectory>(directory) inDomain:static_cast<::NSSearchPathDomainMask>(domain) appropriateForURL:cocoon::internal::native<::NSURL>(url) create:static_cast<::BOOL>(should_create) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<URL>(__r);
    }

    URL FileManager::url_for_publishing_ubiquitous_item_at_url(const URL& url, Date& out_date) const
    {
        NSError* __error = nil;
        ::NSDate* __v_out_date = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) URLForPublishingUbiquitousItemAtURL:cocoon::internal::native<::NSURL>(url) expirationDate:&__v_out_date error:&__error];
        out_date = cocoon::internal::wrap<Date>(__v_out_date);
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<URL>(__r);
    }

    URL FileManager::url_for_ubiquity_container_identifier(const std::string& container_identifier) const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSFileManager>(this) URLForUbiquityContainerIdentifier:cocoon::internal::to(container_identifier)]);
    }

    std::vector<URL> FileManager::ur_ls_for_directory(SearchPathDirectory directory, SearchPathDomainMask domain_mask) const
    {
        return cocoon::internal::from_array<URL>([cocoon::internal::ns<::NSFileManager>(this) URLsForDirectory:static_cast<::NSSearchPathDirectory>(directory) inDomains:static_cast<::NSSearchPathDomainMask>(domain_mask)], [](id e) -> URL
                                   {
                                       return cocoon::internal::wrap<URL>((::NSURL*)e);
                                   });
    }

    std::map<std::string, Object> FileManager::attributes_of_file_system_for_path(const std::string& path) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) attributesOfFileSystemForPath:cocoon::internal::to(path) error:&__error];
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

    std::map<std::string, Object> FileManager::attributes_of_item_at_path(const std::string& path) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) attributesOfItemAtPath:cocoon::internal::to(path) error:&__error];
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

    bool FileManager::change_current_directory_path(const std::string& path) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileManager>(this) changeCurrentDirectoryPath:cocoon::internal::to(path)]);
    }

    std::vector<std::string> FileManager::components_to_display_for_path(const std::string& path) const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSFileManager>(this) componentsToDisplayForPath:cocoon::internal::to(path)], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    URL FileManager::container_url_for_security_application_group_identifier(const std::string& group_identifier) const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSFileManager>(this) containerURLForSecurityApplicationGroupIdentifier:cocoon::internal::to(group_identifier)]);
    }

    std::vector<std::uint8_t> FileManager::contents_at_path(const std::string& path) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSFileManager>(this) contentsAtPath:cocoon::internal::to(path)]);
    }

    bool FileManager::contents_equal_at_path(const std::string& path1, const std::string& path2) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileManager>(this) contentsEqualAtPath:cocoon::internal::to(path1) andPath:cocoon::internal::to(path2)]);
    }

    std::vector<std::string> FileManager::contents_of_directory_at_path(const std::string& path) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) contentsOfDirectoryAtPath:cocoon::internal::to(path) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_array<std::string>(__r, [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<URL> FileManager::contents_of_directory_at_url(const URL& url, const std::vector<std::string>& keys, DirectoryEnumerationOptions mask) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) contentsOfDirectoryAtURL:cocoon::internal::native<::NSURL>(url)
                                                includingPropertiesForKeys:cocoon::internal::to_array(keys, [](const std::string& e) -> id
                                                                                        {
                                                                                            return cocoon::internal::to(e);
                                                                                        })
                                                                   options:static_cast<::NSDirectoryEnumerationOptions>(mask)
                                                                     error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_array<URL>(__r, [](id e) -> URL
                                   {
                                       return cocoon::internal::wrap<URL>((::NSURL*)e);
                                   });
    }

    bool FileManager::copy_item_at_path(const std::string& src_path, const std::string& dst_path) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) copyItemAtPath:cocoon::internal::to(src_path) toPath:cocoon::internal::to(dst_path) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool FileManager::copy_item_at_url(const URL& src_url, const URL& dst_url) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) copyItemAtURL:cocoon::internal::native<::NSURL>(src_url) toURL:cocoon::internal::native<::NSURL>(dst_url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool FileManager::create_directory_at_path(const std::string& path, bool create_intermediates, const std::map<std::string, Object>& attributes) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) createDirectoryAtPath:cocoon::internal::to(path)
                                            withIntermediateDirectories:static_cast<::BOOL>(create_intermediates)
                                                             attributes:cocoon::internal::to_dictionary(attributes, [](const std::string& k) -> id
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

    bool FileManager::create_directory_at_url(const URL& url, bool create_intermediates, const std::map<std::string, Object>& attributes) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) createDirectoryAtURL:cocoon::internal::native<::NSURL>(url)
                                           withIntermediateDirectories:static_cast<::BOOL>(create_intermediates)
                                                            attributes:cocoon::internal::to_dictionary(attributes, [](const std::string& k) -> id
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

    bool FileManager::create_file_at_path(const std::string& path, const std::vector<std::uint8_t>& data, const std::map<std::string, Object>& attr) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileManager>(this) createFileAtPath:cocoon::internal::to(path)
                                                                        contents:cocoon::internal::to_data(data)
                                                                      attributes:cocoon::internal::to_dictionary(attr, [](const std::string& k) -> id
                                                                                                   {
                                                                                                       return cocoon::internal::to(k);
                                                                                                   },
                                                                                                   [](const Object& v) -> id
                                                                                                   {
                                                                                                       return cocoon::internal::native_id(v);
                                                                                                   })]);
    }

    bool FileManager::create_symbolic_link_at_path(const std::string& path, const std::string& dest_path) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) createSymbolicLinkAtPath:cocoon::internal::to(path) withDestinationPath:cocoon::internal::to(dest_path) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool FileManager::create_symbolic_link_at_url(const URL& url, const URL& dest_url) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) createSymbolicLinkAtURL:cocoon::internal::native<::NSURL>(url) withDestinationURL:cocoon::internal::native<::NSURL>(dest_url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    std::string FileManager::destination_of_symbolic_link_at_path(const std::string& path) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) destinationOfSymbolicLinkAtPath:cocoon::internal::to(path) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from(__r);
    }

    std::string FileManager::display_name_at_path(const std::string& path) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFileManager>(this) displayNameAtPath:cocoon::internal::to(path)]);
    }

    DirectoryEnumeratorBase FileManager::enumerator_at_path(const std::string& path) const
    {
        return cocoon::internal::wrap<DirectoryEnumeratorBase>([cocoon::internal::ns<::NSFileManager>(this) enumeratorAtPath:cocoon::internal::to(path)]);
    }

    DirectoryEnumeratorBase FileManager::enumerator_at_url(const URL& url, const std::vector<std::string>& keys, DirectoryEnumerationOptions mask, std::function<bool(URL, Error)> handler) const
    {
        return cocoon::internal::wrap<DirectoryEnumeratorBase>([cocoon::internal::ns<::NSFileManager>(this) enumeratorAtURL:cocoon::internal::native<::NSURL>(url)
                                                                     includingPropertiesForKeys:cocoon::internal::to_array(keys, [](const std::string& e) -> id
                                                                                                             {
                                                                                                                 return cocoon::internal::to(e);
                                                                                                             })
                                                                                        options:static_cast<::NSDirectoryEnumerationOptions>(mask)
                                                                                   errorHandler:(handler ? (BOOL(^)(::NSURL*, ::NSError*)) ^ ::BOOL(::NSURL * a147_0, ::NSError * a147_1) { auto __r = handler(cocoon::internal::wrap<URL>(a147_0), cocoon::internal::wrap<Error>(a147_1)); return static_cast<::BOOL>(__r); } : (BOOL(^)(::NSURL*, ::NSError*))nil)]);
    }

    bool FileManager::evict_ubiquitous_item_at_url(const URL& url) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) evictUbiquitousItemAtURL:cocoon::internal::native<::NSURL>(url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    void FileManager::fetch_latest_remote_version_of_item_at_url(const URL& url, std::function<void(FileVersion, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSFileManager>(this) fetchLatestRemoteVersionOfItemAtURL:cocoon::internal::native<::NSURL>(url) completionHandler:(completion_handler ? (void (^)(::NSFileVersion*, ::NSError*)) ^ void(::NSFileVersion * a148_0, ::NSError * a148_1) { completion_handler(cocoon::internal::wrap<FileVersion>(a148_0), cocoon::internal::wrap<Error>(a148_1)); } : (void (^)(::NSFileVersion*, ::NSError*))nil)];
    }

    bool FileManager::file_exists_at_path(const std::string& path) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileManager>(this) fileExistsAtPath:cocoon::internal::to(path)]);
    }

    bool FileManager::file_exists_at_path(const std::string& path, bool* is_directory) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileManager>(this) fileExistsAtPath:cocoon::internal::to(path) isDirectory:(BOOL*)(is_directory)]);
    }

    FileManager FileManager::file_manager_with_authorization(const WorkspaceAuthorization& authorization)
    {
        return cocoon::internal::wrap<FileManager>([::NSFileManager fileManagerWithAuthorization:cocoon::internal::native<::NSWorkspaceAuthorization>(authorization)]);
    }

    std::string FileManager::file_system_representation_with_path(const std::string& path) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFileManager>(this) fileSystemRepresentationWithPath:cocoon::internal::to(path)]);
    }

    void FileManager::get_file_provider_services_for_item_at_url(const URL& url, std::function<void(std::map<std::string, FileProviderService>, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSFileManager>(this) getFileProviderServicesForItemAtURL:cocoon::internal::native<::NSURL>(url) completionHandler:(completion_handler ? (void (^)(NSDictionary<NSFileProviderServiceName, NSFileProviderService*>*, ::NSError*)) ^ void(NSDictionary * a149_0, ::NSError * a149_1) { completion_handler(cocoon::internal::from_dictionary<std::map<std::string, FileProviderService>>(a149_0, [](id k) -> std::string
                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                                                                                                                                                                            },
                                                                                                                                                                                                                                                                                                                                                                            [](id v) -> FileProviderService
                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                return cocoon::internal::wrap<FileProviderService>((::NSFileProviderService*)v);
                                                                                                                                                                                                                                                                                                                                                                            }),
                                                                                                                                                                                                                                                                                                            cocoon::internal::wrap<Error>(a149_1)); } : (void (^)(NSDictionary<NSFileProviderServiceName, NSFileProviderService*>*, ::NSError*))nil)];
    }

    bool FileManager::get_relationship(URLRelationship* out_relationship, SearchPathDirectory directory, SearchPathDomainMask domain_mask, const URL& url) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) getRelationship:(::NSURLRelationship*)(out_relationship) ofDirectory:static_cast<::NSSearchPathDirectory>(directory) inDomain:static_cast<::NSSearchPathDomainMask>(domain_mask) toItemAtURL:cocoon::internal::native<::NSURL>(url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool FileManager::get_relationship(URLRelationship* out_relationship, const URL& directory_url, const URL& other_url) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) getRelationship:(::NSURLRelationship*)(out_relationship) ofDirectoryAtURL:cocoon::internal::native<::NSURL>(directory_url) toItemAtURL:cocoon::internal::native<::NSURL>(other_url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    URL FileManager::home_directory_for_user(const std::string& user_name) const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSFileManager>(this) homeDirectoryForUser:cocoon::internal::to(user_name)]);
    }

    bool FileManager::is_deletable_file_at_path(const std::string& path) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileManager>(this) isDeletableFileAtPath:cocoon::internal::to(path)]);
    }

    bool FileManager::is_executable_file_at_path(const std::string& path) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileManager>(this) isExecutableFileAtPath:cocoon::internal::to(path)]);
    }

    bool FileManager::is_readable_file_at_path(const std::string& path) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileManager>(this) isReadableFileAtPath:cocoon::internal::to(path)]);
    }

    bool FileManager::is_ubiquitous_item_at_url(const URL& url) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileManager>(this) isUbiquitousItemAtURL:cocoon::internal::native<::NSURL>(url)]);
    }

    bool FileManager::is_writable_file_at_path(const std::string& path) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileManager>(this) isWritableFileAtPath:cocoon::internal::to(path)]);
    }

    bool FileManager::link_item_at_path(const std::string& src_path, const std::string& dst_path) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) linkItemAtPath:cocoon::internal::to(src_path) toPath:cocoon::internal::to(dst_path) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool FileManager::link_item_at_url(const URL& src_url, const URL& dst_url) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) linkItemAtURL:cocoon::internal::native<::NSURL>(src_url) toURL:cocoon::internal::native<::NSURL>(dst_url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    std::vector<URL> FileManager::mounted_volume_ur_ls_including_resource_values_for_keys(const std::vector<std::string>& property_keys, VolumeEnumerationOptions options) const
    {
        return cocoon::internal::from_array<URL>([cocoon::internal::ns<::NSFileManager>(this) mountedVolumeURLsIncludingResourceValuesForKeys:cocoon::internal::to_array(property_keys, [](const std::string& e) -> id
                                                                                                                               {
                                                                                                                                   return cocoon::internal::to(e);
                                                                                                                               })
                                                                                                          options:static_cast<::NSVolumeEnumerationOptions>(options)],
                                   [](id e) -> URL
                                   {
                                       return cocoon::internal::wrap<URL>((::NSURL*)e);
                                   });
    }

    bool FileManager::move_item_at_path(const std::string& src_path, const std::string& dst_path) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) moveItemAtPath:cocoon::internal::to(src_path) toPath:cocoon::internal::to(dst_path) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool FileManager::move_item_at_url(const URL& src_url, const URL& dst_url) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) moveItemAtURL:cocoon::internal::native<::NSURL>(src_url) toURL:cocoon::internal::native<::NSURL>(dst_url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    void FileManager::pause_sync_for_ubiquitous_item_at_url(const URL& url, std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSFileManager>(this) pauseSyncForUbiquitousItemAtURL:cocoon::internal::native<::NSURL>(url) completionHandler:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a150_0) { completion_handler(cocoon::internal::wrap<Error>(a150_0)); } : (void (^)(::NSError*))nil)];
    }

    bool FileManager::remove_item_at_path(const std::string& path) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) removeItemAtPath:cocoon::internal::to(path) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool FileManager::remove_item_at_url(const URL& url) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) removeItemAtURL:cocoon::internal::native<::NSURL>(url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool FileManager::replace_item_at_url(const URL& original_item_url, const URL& new_item_url, const std::string& backup_item_name, FileManagerItemReplacementOptions options, URL& resulting_url) const
    {
        NSError* __error = nil;
        ::NSURL* __v_resulting_url = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) replaceItemAtURL:cocoon::internal::native<::NSURL>(original_item_url) withItemAtURL:cocoon::internal::native<::NSURL>(new_item_url) backupItemName:cocoon::internal::to(backup_item_name) options:static_cast<::NSFileManagerItemReplacementOptions>(options) resultingItemURL:&__v_resulting_url error:&__error];
        resulting_url = cocoon::internal::wrap<URL>(__v_resulting_url);
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    void FileManager::resume_sync_for_ubiquitous_item_at_url(const URL& url, FileManagerResumeSyncBehavior behavior, std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSFileManager>(this) resumeSyncForUbiquitousItemAtURL:cocoon::internal::native<::NSURL>(url) withBehavior:static_cast<::NSFileManagerResumeSyncBehavior>(behavior) completionHandler:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a151_0) { completion_handler(cocoon::internal::wrap<Error>(a151_0)); } : (void (^)(::NSError*))nil)];
    }

    bool FileManager::set_attributes(const std::map<std::string, Object>& attributes, const std::string& path) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) setAttributes:cocoon::internal::to_dictionary(attributes, [](const std::string& k) -> id
                                                                                  {
                                                                                      return cocoon::internal::to(k);
                                                                                  },
                                                                                  [](const Object& v) -> id
                                                                                  {
                                                                                      return cocoon::internal::native_id(v);
                                                                                  })
                                                   ofItemAtPath:cocoon::internal::to(path)
                                                          error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool FileManager::set_ubiquitous(bool flag, const URL& url, const URL& destination_url) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) setUbiquitous:static_cast<::BOOL>(flag) itemAtURL:cocoon::internal::native<::NSURL>(url) destinationURL:cocoon::internal::native<::NSURL>(destination_url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool FileManager::start_downloading_ubiquitous_item_at_url(const URL& url) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) startDownloadingUbiquitousItemAtURL:cocoon::internal::native<::NSURL>(url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    std::string FileManager::string_with_file_system_representation(const std::string& str, std::uint64_t len) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFileManager>(this) stringWithFileSystemRepresentation:str.c_str() length:static_cast<::NSUInteger>(len)]);
    }

    std::vector<std::string> FileManager::subpaths_at_path(const std::string& path) const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSFileManager>(this) subpathsAtPath:cocoon::internal::to(path)], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> FileManager::subpaths_of_directory_at_path(const std::string& path) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) subpathsOfDirectoryAtPath:cocoon::internal::to(path) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_array<std::string>(__r, [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    bool FileManager::trash_item_at_url(const URL& url, URL& out_resulting_url) const
    {
        NSError* __error = nil;
        ::NSURL* __v_out_resulting_url = nil;
        auto __r = [cocoon::internal::ns<::NSFileManager>(this) trashItemAtURL:cocoon::internal::native<::NSURL>(url) resultingItemURL:&__v_out_resulting_url error:&__error];
        out_resulting_url = cocoon::internal::wrap<URL>(__v_out_resulting_url);
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    void FileManager::unmount_volume_at_url(const URL& url, FileManagerUnmountOptions mask, std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSFileManager>(this) unmountVolumeAtURL:cocoon::internal::native<::NSURL>(url) options:static_cast<::NSFileManagerUnmountOptions>(mask) completionHandler:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a152_0) { completion_handler(cocoon::internal::wrap<Error>(a152_0)); } : (void (^)(::NSError*))nil)];
    }

    void FileManager::upload_local_version_of_ubiquitous_item_at_url(const URL& url, FileManagerUploadLocalVersionConflictPolicy conflict_resolution_policy, std::function<void(FileVersion, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSFileManager>(this) uploadLocalVersionOfUbiquitousItemAtURL:cocoon::internal::native<::NSURL>(url) withConflictResolutionPolicy:static_cast<::NSFileManagerUploadLocalVersionConflictPolicy>(conflict_resolution_policy) completionHandler:(completion_handler ? (void (^)(::NSFileVersion*, ::NSError*)) ^ void(::NSFileVersion * a153_0, ::NSError * a153_1) { completion_handler(cocoon::internal::wrap<FileVersion>(a153_0), cocoon::internal::wrap<Error>(a153_1)); } : (void (^)(::NSFileVersion*, ::NSError*))nil)];
    }

    std::string FileManager::current_directory_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFileManager>(this) currentDirectoryPath]);
    }

    FileManager FileManager::default_manager()
    {
        return cocoon::internal::wrap<FileManager>([::NSFileManager defaultManager]);
    }

    URL FileManager::home_directory_for_current_user() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSFileManager>(this) homeDirectoryForCurrentUser]);
    }

    URL FileManager::temporary_directory() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSFileManager>(this) temporaryDirectory]);
    }

    void FileManager::install_delegate_delegate_(void* native)
    {
        ::NSFileManager* host = (__bridge ::NSFileManager*)native;
        AKFileManagerDelegate* delegate = [[AKFileManagerDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSFileManager* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSFileManager* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
