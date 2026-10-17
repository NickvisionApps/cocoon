#include "generated/url_session_task_metrics.h"
#include "internal.h"

namespace cocoon
{
    URLSessionTaskMetrics::URLSessionTaskMetrics() : URLSessionTaskMetrics(Adopt{cocoon::internal::retain([[::NSURLSessionTaskMetrics alloc] init])})
    {
    }

    URLSessionTaskMetrics::URLSessionTaskMetrics(std::nullptr_t) : Object(nullptr)
    {
    }

    URLSessionTaskMetrics::URLSessionTaskMetrics(Adopt adopt) : Object(adopt)
    {
    }

    std::uint64_t URLSessionTaskMetrics::redirect_count() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSURLSessionTaskMetrics>(this) redirectCount]);
    }

    DateInterval URLSessionTaskMetrics::task_interval() const
    {
        return cocoon::internal::wrap<DateInterval>([cocoon::internal::ns<::NSURLSessionTaskMetrics>(this) taskInterval]);
    }

    std::vector<URLSessionTaskTransactionMetrics> URLSessionTaskMetrics::transaction_metrics() const
    {
        return cocoon::internal::from_array<URLSessionTaskTransactionMetrics>([cocoon::internal::ns<::NSURLSessionTaskMetrics>(this) transactionMetrics], [](id e) -> URLSessionTaskTransactionMetrics
                                                                {
                                                                    return cocoon::internal::wrap<URLSessionTaskTransactionMetrics>((::NSURLSessionTaskTransactionMetrics*)e);
                                                                });
    }
}
