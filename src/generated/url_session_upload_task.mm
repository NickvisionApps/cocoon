#include "generated/url_session_upload_task.h"
#include "internal.h"

namespace cocoon
{
    URLSessionUploadTask::URLSessionUploadTask() : URLSessionUploadTask(Adopt{cocoon::internal::retain([[::NSURLSessionUploadTask alloc] init])})
    {
        URLSessionTask::install_delegate_delegate_(handle());
    }

    URLSessionUploadTask::URLSessionUploadTask(std::nullptr_t) : URLSessionDataTask(nullptr)
    {
    }

    URLSessionUploadTask::URLSessionUploadTask(Adopt adopt) : URLSessionDataTask(adopt)
    {
    }

    void URLSessionUploadTask::cancel_by_producing_resume_data(std::function<void(std::vector<std::uint8_t>)> completion_handler) const
    {
        [cocoon::internal::ns<::NSURLSessionUploadTask>(this) cancelByProducingResumeData:(completion_handler ? (void (^)(::NSData*)) ^ void(NSData * a244_0) { completion_handler(cocoon::internal::from_data(a244_0)); } : (void (^)(::NSData*))nil)];
    }
}
