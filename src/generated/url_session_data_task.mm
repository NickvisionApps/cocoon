#include "generated/url_session_data_task.h"
#include "internal.h"

namespace cocoon
{
    URLSessionDataTask::URLSessionDataTask() : URLSessionDataTask(Adopt{cocoon::internal::retain([[::NSURLSessionDataTask alloc] init])})
    {
        URLSessionTask::install_delegate_delegate_(handle());
    }

    URLSessionDataTask::URLSessionDataTask(std::nullptr_t) : URLSessionTask(nullptr)
    {
    }

    URLSessionDataTask::URLSessionDataTask(Adopt adopt) : URLSessionTask(adopt)
    {
    }
}
