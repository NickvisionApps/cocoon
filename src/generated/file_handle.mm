#include "generated/file_handle.h"
#include "internal.h"

namespace cocoon
{
    FileHandle::FileHandle(int fd) : FileHandle(Adopt{cocoon::internal::retain([[::NSFileHandle alloc] initWithFileDescriptor:static_cast<int>(fd)])})
    {
    }

    FileHandle::FileHandle(int fd, bool closeopt) : FileHandle(Adopt{cocoon::internal::retain([[::NSFileHandle alloc] initWithFileDescriptor:static_cast<int>(fd) closeOnDealloc:static_cast<::BOOL>(closeopt)])})
    {
    }

    FileHandle::FileHandle() : FileHandle(Adopt{cocoon::internal::retain([[::NSFileHandle alloc] init])})
    {
    }

    FileHandle::FileHandle(std::nullptr_t) : Object(nullptr)
    {
    }

    FileHandle::FileHandle(Adopt adopt) : Object(adopt)
    {
    }

    void FileHandle::accept_connection_in_background_and_notify() const
    {
        [cocoon::internal::ns<::NSFileHandle>(this) acceptConnectionInBackgroundAndNotify];
    }

    void FileHandle::accept_connection_in_background_and_notify_for_modes(const std::vector<std::string>& modes) const
    {
        [cocoon::internal::ns<::NSFileHandle>(this) acceptConnectionInBackgroundAndNotifyForModes:cocoon::internal::to_array(modes, [](const std::string& e) -> id
                                                                                                 {
                                                                                                     return cocoon::internal::to(e);
                                                                                                 })];
    }

    bool FileHandle::close_and_return_error() const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileHandle>(this) closeAndReturnError:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    FileHandle FileHandle::file_handle_for_reading_at_path(const std::string& path)
    {
        return cocoon::internal::wrap<FileHandle>([::NSFileHandle fileHandleForReadingAtPath:cocoon::internal::to(path)]);
    }

    FileHandle FileHandle::file_handle_for_reading_from_url(const URL& url)
    {
        NSError* __error = nil;
        auto __r = [::NSFileHandle fileHandleForReadingFromURL:cocoon::internal::native<::NSURL>(url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<FileHandle>(__r);
    }

    FileHandle FileHandle::file_handle_for_updating_at_path(const std::string& path)
    {
        return cocoon::internal::wrap<FileHandle>([::NSFileHandle fileHandleForUpdatingAtPath:cocoon::internal::to(path)]);
    }

    FileHandle FileHandle::file_handle_for_updating_url(const URL& url)
    {
        NSError* __error = nil;
        auto __r = [::NSFileHandle fileHandleForUpdatingURL:cocoon::internal::native<::NSURL>(url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<FileHandle>(__r);
    }

    FileHandle FileHandle::file_handle_for_writing_at_path(const std::string& path)
    {
        return cocoon::internal::wrap<FileHandle>([::NSFileHandle fileHandleForWritingAtPath:cocoon::internal::to(path)]);
    }

    FileHandle FileHandle::file_handle_for_writing_to_url(const URL& url)
    {
        NSError* __error = nil;
        auto __r = [::NSFileHandle fileHandleForWritingToURL:cocoon::internal::native<::NSURL>(url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<FileHandle>(__r);
    }

    bool FileHandle::get_offset(std::uint64_t* offset_in_file) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileHandle>(this) getOffset:(unsigned long long*)(offset_in_file) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    std::vector<std::uint8_t> FileHandle::read_data_to_end_of_file_and_return_error() const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileHandle>(this) readDataToEndOfFileAndReturnError:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_data(__r);
    }

    std::vector<std::uint8_t> FileHandle::read_data_up_to_length(std::uint64_t length) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileHandle>(this) readDataUpToLength:static_cast<::NSUInteger>(length) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_data(__r);
    }

    void FileHandle::read_in_background_and_notify() const
    {
        [cocoon::internal::ns<::NSFileHandle>(this) readInBackgroundAndNotify];
    }

    void FileHandle::read_in_background_and_notify_for_modes(const std::vector<std::string>& modes) const
    {
        [cocoon::internal::ns<::NSFileHandle>(this) readInBackgroundAndNotifyForModes:cocoon::internal::to_array(modes, [](const std::string& e) -> id
                                                                                     {
                                                                                         return cocoon::internal::to(e);
                                                                                     })];
    }

    void FileHandle::read_to_end_of_file_in_background_and_notify() const
    {
        [cocoon::internal::ns<::NSFileHandle>(this) readToEndOfFileInBackgroundAndNotify];
    }

    void FileHandle::read_to_end_of_file_in_background_and_notify_for_modes(const std::vector<std::string>& modes) const
    {
        [cocoon::internal::ns<::NSFileHandle>(this) readToEndOfFileInBackgroundAndNotifyForModes:cocoon::internal::to_array(modes, [](const std::string& e) -> id
                                                                                                {
                                                                                                    return cocoon::internal::to(e);
                                                                                                })];
    }

    bool FileHandle::seek_to_end_returning_offset(std::uint64_t* offset_in_file) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileHandle>(this) seekToEndReturningOffset:(unsigned long long*)(offset_in_file) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool FileHandle::seek_to_offset(std::uint64_t offset) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileHandle>(this) seekToOffset:static_cast<unsigned long long>(offset) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool FileHandle::synchronize_and_return_error() const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileHandle>(this) synchronizeAndReturnError:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool FileHandle::truncate_at_offset(std::uint64_t offset) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileHandle>(this) truncateAtOffset:static_cast<unsigned long long>(offset) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    void FileHandle::wait_for_data_in_background_and_notify() const
    {
        [cocoon::internal::ns<::NSFileHandle>(this) waitForDataInBackgroundAndNotify];
    }

    void FileHandle::wait_for_data_in_background_and_notify_for_modes(const std::vector<std::string>& modes) const
    {
        [cocoon::internal::ns<::NSFileHandle>(this) waitForDataInBackgroundAndNotifyForModes:cocoon::internal::to_array(modes, [](const std::string& e) -> id
                                                                                            {
                                                                                                return cocoon::internal::to(e);
                                                                                            })];
    }

    bool FileHandle::write_data(const std::vector<std::uint8_t>& data) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileHandle>(this) writeData:cocoon::internal::to_data(data) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    std::vector<std::uint8_t> FileHandle::available_data() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSFileHandle>(this) availableData]);
    }

    int FileHandle::file_descriptor() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSFileHandle>(this) fileDescriptor]);
    }

    FileHandle FileHandle::file_handle_with_null_device()
    {
        return cocoon::internal::wrap<FileHandle>([::NSFileHandle fileHandleWithNullDevice]);
    }

    FileHandle FileHandle::file_handle_with_standard_error()
    {
        return cocoon::internal::wrap<FileHandle>([::NSFileHandle fileHandleWithStandardError]);
    }

    FileHandle FileHandle::file_handle_with_standard_input()
    {
        return cocoon::internal::wrap<FileHandle>([::NSFileHandle fileHandleWithStandardInput]);
    }

    FileHandle FileHandle::file_handle_with_standard_output()
    {
        return cocoon::internal::wrap<FileHandle>([::NSFileHandle fileHandleWithStandardOutput]);
    }

    std::function<void(FileHandle)> FileHandle::readability_handler() const
    {
        return [&]() -> std::function<void(FileHandle)>
        {
            auto blk = (void (^)(::NSFileHandle*))([cocoon::internal::ns<::NSFileHandle>(this) readabilityHandler]);
            if (!blk)
            {
                return {};
            }
            return [blk](FileHandle a143_0) -> void
            {
                blk(cocoon::internal::native<::NSFileHandle>(a143_0));
            };
        }();
    }

    void FileHandle::set_readability_handler(std::function<void(FileHandle)> value) const
    {
        [cocoon::internal::ns<::NSFileHandle>(this) setReadabilityHandler:(value ? (void (^)(::NSFileHandle*)) ^ void(::NSFileHandle * a144_0) { value(cocoon::internal::wrap<FileHandle>(a144_0)); } : (void (^)(::NSFileHandle*))nil)];
    }

    std::function<void(FileHandle)> FileHandle::writeability_handler() const
    {
        return [&]() -> std::function<void(FileHandle)>
        {
            auto blk = (void (^)(::NSFileHandle*))([cocoon::internal::ns<::NSFileHandle>(this) writeabilityHandler]);
            if (!blk)
            {
                return {};
            }
            return [blk](FileHandle a145_0) -> void
            {
                blk(cocoon::internal::native<::NSFileHandle>(a145_0));
            };
        }();
    }

    void FileHandle::set_writeability_handler(std::function<void(FileHandle)> value) const
    {
        [cocoon::internal::ns<::NSFileHandle>(this) setWriteabilityHandler:(value ? (void (^)(::NSFileHandle*)) ^ void(::NSFileHandle * a146_0) { value(cocoon::internal::wrap<FileHandle>(a146_0)); } : (void (^)(::NSFileHandle*))nil)];
    }
}
