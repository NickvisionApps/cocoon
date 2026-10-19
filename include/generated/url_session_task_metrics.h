#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class DateInterval;
    class URLSessionTaskTransactionMetrics;

    /**
     * @brief C++ handle for the Objective-C class `NSURLSessionTaskMetrics` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLSessionTaskMetrics url_session_task_metrics;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlsessiontaskmetrics
     */
    class URLSessionTaskMetrics : public Object
    {
    public:
        /// @brief Creates a new `NSURLSessionTaskMetrics` instance and returns a handle to it.
        explicit URLSessionTaskMetrics();
        /// @brief Creates a null handle that refers to no native object.
        URLSessionTaskMetrics(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLSessionTaskMetrics(Adopt adopt);
        /**
     * @brief Returns the `redirectCount` property of `NSURLSessionTaskMetrics`.
     * @details redirectCount is the number of redirects that were recorded.
     * @return The converted Objective-C result.
     */
        std::uint64_t redirect_count() const;
        /**
     * @brief Returns the `taskInterval` property of `NSURLSessionTaskMetrics`.
     * @details Interval from the task creation time to the task completion time. Task creation time is the time when the task was instantiated. Task completion time is the time when the task is about to change its internal state to completed.
     * @return The converted Objective-C result.
     */
        DateInterval task_interval() const;
        /**
     * @brief Returns the `transactionMetrics` property of `NSURLSessionTaskMetrics`.
     * @details transactionMetrics array contains the metrics collected for every request/response transaction created during the task execution.
     * @return The converted Objective-C result.
     */
        std::vector<URLSessionTaskTransactionMetrics> transaction_metrics() const;
    };
}
