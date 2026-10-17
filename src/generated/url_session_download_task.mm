#include "generated/url_session_download_task.h"
#include "internal.h"

namespace cocoon
{
    URLSessionDownloadTask::URLSessionDownloadTask() : URLSessionDownloadTask(Adopt{cocoon::internal::retain([[::NSURLSessionDownloadTask alloc] init])})
    {
        URLSessionTask::install_delegate_delegate_(handle());
    }

    URLSessionDownloadTask::URLSessionDownloadTask(std::nullptr_t) : URLSessionTask(nullptr)
    {
    }

    URLSessionDownloadTask::URLSessionDownloadTask(Adopt adopt) : URLSessionTask(adopt)
    {
    }

    void URLSessionDownloadTask::cancel_by_producing_resume_data(std::function<void(std::vector<std::uint8_t>)> completion_handler) const
    {
        [cocoon::internal::ns<::NSURLSessionDownloadTask>(this) cancelByProducingResumeData:(completion_handler ? (void (^)(::NSData*)) ^ void(NSData * a245_0) { completion_handler(cocoon::internal::from_data(a245_0)); } : (void (^)(::NSData*))nil)];
    }
}
