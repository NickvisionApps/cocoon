#include "generated/file_wrapper.h"
#include "internal.h"

namespace cocoon
{
    FileWrapper::FileWrapper(const std::map<std::string, FileWrapper>& children_by_preferred_name) : FileWrapper(Adopt{cocoon::internal::retain([[::NSFileWrapper alloc] initDirectoryWithFileWrappers:cocoon::internal::to_dictionary(children_by_preferred_name, [](const std::string& k) -> id
                                                                                                                                                                                                           {
                                                                                                                                                                                                               return cocoon::internal::to(k);
                                                                                                                                                                                                           },
                                                                                                                                                                                                           [](const FileWrapper& v) -> id
                                                                                                                                                                                                           {
                                                                                                                                                                                                               return cocoon::internal::native<::NSFileWrapper>(v);
                                                                                                                                                                                                           })])})
    {
    }

    FileWrapper::FileWrapper(const std::vector<std::uint8_t>& contents) : FileWrapper(Adopt{cocoon::internal::retain([[::NSFileWrapper alloc] initRegularFileWithContents:cocoon::internal::to_data(contents)])})
    {
    }

    FileWrapper::FileWrapper(const URL& url) : FileWrapper(Adopt{cocoon::internal::retain([[::NSFileWrapper alloc] initSymbolicLinkWithDestinationURL:cocoon::internal::native<::NSURL>(url)])})
    {
    }

    FileWrapper::FileWrapper(const URL& url, FileWrapperReadingOptions options) : FileWrapper(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                               {
                                                                                                                   NSError* __error = nil;
                                                                                                                   id __r = [[::NSFileWrapper alloc] initWithURL:cocoon::internal::native<::NSURL>(url) options:static_cast<::NSFileWrapperReadingOptions>(options) error:&__error];
                                                                                                                   if (!__r && __error)
                                                                                                                   {
                                                                                                                       throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                                                   }
                                                                                                                   return __r;
                                                                                                               }())})
    {
    }

    FileWrapper::FileWrapper() : FileWrapper(Adopt{cocoon::internal::retain([[::NSFileWrapper alloc] init])})
    {
    }

    FileWrapper::FileWrapper(std::nullptr_t) : Object(nullptr)
    {
    }

    FileWrapper::FileWrapper(Adopt adopt) : Object(adopt)
    {
    }

    std::string FileWrapper::add_file_wrapper(const FileWrapper& child) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFileWrapper>(this) addFileWrapper:cocoon::internal::native<::NSFileWrapper>(child)]);
    }

    std::string FileWrapper::add_regular_file_with_contents(const std::vector<std::uint8_t>& data, const std::string& file_name) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFileWrapper>(this) addRegularFileWithContents:cocoon::internal::to_data(data) preferredFilename:cocoon::internal::to(file_name)]);
    }

    std::string FileWrapper::key_for_file_wrapper(const FileWrapper& child) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFileWrapper>(this) keyForFileWrapper:cocoon::internal::native<::NSFileWrapper>(child)]);
    }

    bool FileWrapper::matches_contents_of_url(const URL& url) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileWrapper>(this) matchesContentsOfURL:cocoon::internal::native<::NSURL>(url)]);
    }

    bool FileWrapper::read_from_url(const URL& url, FileWrapperReadingOptions options) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileWrapper>(this) readFromURL:cocoon::internal::native<::NSURL>(url) options:static_cast<::NSFileWrapperReadingOptions>(options) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    void FileWrapper::remove_file_wrapper(const FileWrapper& child) const
    {
        [cocoon::internal::ns<::NSFileWrapper>(this) removeFileWrapper:cocoon::internal::native<::NSFileWrapper>(child)];
    }

    bool FileWrapper::write_to_url(const URL& url, FileWrapperWritingOptions options, const URL& original_contents_url) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileWrapper>(this) writeToURL:cocoon::internal::native<::NSURL>(url) options:static_cast<::NSFileWrapperWritingOptions>(options) originalContentsURL:cocoon::internal::native<::NSURL>(original_contents_url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool FileWrapper::is_directory() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileWrapper>(this) isDirectory]);
    }

    std::map<std::string, Object> FileWrapper::file_attributes() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSFileWrapper>(this) fileAttributes], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    void FileWrapper::set_file_attributes(const std::map<std::string, Object>& value) const
    {
        [cocoon::internal::ns<::NSFileWrapper>(this) setFileAttributes:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                           {
                                                                               return cocoon::internal::to(k);
                                                                           },
                                                                           [](const Object& v) -> id
                                                                           {
                                                                               return cocoon::internal::native_id(v);
                                                                           })];
    }

    std::map<std::string, FileWrapper> FileWrapper::file_wrappers() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, FileWrapper>>([cocoon::internal::ns<::NSFileWrapper>(this) fileWrappers], [](id k) -> std::string
                                                                       {
                                                                           return cocoon::internal::from((NSString*)k);
                                                                       },
                                                                       [](id v) -> FileWrapper
                                                                       {
                                                                           return cocoon::internal::wrap<FileWrapper>((::NSFileWrapper*)v);
                                                                       });
    }

    std::string FileWrapper::filename() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFileWrapper>(this) filename]);
    }

    void FileWrapper::set_filename(const std::string& value) const
    {
        [cocoon::internal::ns<::NSFileWrapper>(this) setFilename:cocoon::internal::to(value)];
    }

    Image FileWrapper::icon() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSFileWrapper>(this) icon]);
    }

    void FileWrapper::set_icon(const Image& value) const
    {
        [cocoon::internal::ns<::NSFileWrapper>(this) setIcon:cocoon::internal::native<::NSImage>(value)];
    }

    std::string FileWrapper::preferred_filename() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFileWrapper>(this) preferredFilename]);
    }

    void FileWrapper::set_preferred_filename(const std::string& value) const
    {
        [cocoon::internal::ns<::NSFileWrapper>(this) setPreferredFilename:cocoon::internal::to(value)];
    }

    bool FileWrapper::is_regular_file() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileWrapper>(this) isRegularFile]);
    }

    std::vector<std::uint8_t> FileWrapper::regular_file_contents() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSFileWrapper>(this) regularFileContents]);
    }

    std::vector<std::uint8_t> FileWrapper::serialized_representation() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSFileWrapper>(this) serializedRepresentation]);
    }

    bool FileWrapper::is_symbolic_link() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileWrapper>(this) isSymbolicLink]);
    }

    URL FileWrapper::symbolic_link_destination_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSFileWrapper>(this) symbolicLinkDestinationURL]);
    }
}
