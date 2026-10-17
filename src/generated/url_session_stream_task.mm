#include "generated/url_session_stream_task.h"
#include "internal.h"

namespace cocoon
{
    URLSessionStreamTask::URLSessionStreamTask() : URLSessionStreamTask(Adopt{cocoon::internal::retain([[::NSURLSessionStreamTask alloc] init])})
    {
        URLSessionTask::install_delegate_delegate_(handle());
    }

    URLSessionStreamTask::URLSessionStreamTask(std::nullptr_t) : URLSessionTask(nullptr)
    {
    }

    URLSessionStreamTask::URLSessionStreamTask(Adopt adopt) : URLSessionTask(adopt)
    {
    }

    void URLSessionStreamTask::capture_streams() const
    {
        [cocoon::internal::ns<::NSURLSessionStreamTask>(this) captureStreams];
    }

    void URLSessionStreamTask::close_read() const
    {
        [cocoon::internal::ns<::NSURLSessionStreamTask>(this) closeRead];
    }

    void URLSessionStreamTask::close_write() const
    {
        [cocoon::internal::ns<::NSURLSessionStreamTask>(this) closeWrite];
    }

    void URLSessionStreamTask::read_data_of_min_length(std::uint64_t min_bytes, std::uint64_t max_bytes, double timeout, std::function<void(std::vector<std::uint8_t>, bool, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSURLSessionStreamTask>(this) readDataOfMinLength:static_cast<::NSUInteger>(min_bytes) maxLength:static_cast<::NSUInteger>(max_bytes) timeout:static_cast<::NSTimeInterval>(timeout) completionHandler:(completion_handler ? (void (^)(::NSData*, BOOL, ::NSError*)) ^ void(NSData * a246_0, ::BOOL a246_1, ::NSError * a246_2) { completion_handler(cocoon::internal::from_data(a246_0), static_cast<bool>(a246_1), cocoon::internal::wrap<Error>(a246_2)); } : (void (^)(::NSData*, BOOL, ::NSError*))nil)];
    }

    void URLSessionStreamTask::start_secure_connection() const
    {
        [cocoon::internal::ns<::NSURLSessionStreamTask>(this) startSecureConnection];
    }

    void URLSessionStreamTask::write_data(const std::vector<std::uint8_t>& data, double timeout, std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSURLSessionStreamTask>(this) writeData:cocoon::internal::to_data(data) timeout:static_cast<::NSTimeInterval>(timeout) completionHandler:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a247_0) { completion_handler(cocoon::internal::wrap<Error>(a247_0)); } : (void (^)(::NSError*))nil)];
    }
}
