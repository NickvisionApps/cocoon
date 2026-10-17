#include "generated/operation.h"
#include "internal.h"

namespace cocoon
{
    Operation::Operation() : Operation(Adopt{cocoon::internal::retain([[::NSOperation alloc] init])})
    {
    }

    Operation::Operation(std::nullptr_t) : Object(nullptr)
    {
    }

    Operation::Operation(Adopt adopt) : Object(adopt)
    {
    }

    void Operation::add_dependency(const Operation& op) const
    {
        [cocoon::internal::ns<::NSOperation>(this) addDependency:cocoon::internal::native<::NSOperation>(op)];
    }

    void Operation::cancel() const
    {
        [cocoon::internal::ns<::NSOperation>(this) cancel];
    }

    void Operation::main_() const
    {
        [cocoon::internal::ns<::NSOperation>(this) main];
    }

    void Operation::remove_dependency(const Operation& op) const
    {
        [cocoon::internal::ns<::NSOperation>(this) removeDependency:cocoon::internal::native<::NSOperation>(op)];
    }

    void Operation::start() const
    {
        [cocoon::internal::ns<::NSOperation>(this) start];
    }

    void Operation::wait_until_finished() const
    {
        [cocoon::internal::ns<::NSOperation>(this) waitUntilFinished];
    }

    bool Operation::is_asynchronous() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOperation>(this) isAsynchronous]);
    }

    bool Operation::is_cancelled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOperation>(this) isCancelled]);
    }

    std::function<void()> Operation::completion_block() const
    {
        return [&]() -> std::function<void()>
        {
            auto blk = (void (^)(void))([cocoon::internal::ns<::NSOperation>(this) completionBlock]);
            if (!blk)
            {
                return {};
            }
            return [blk]() -> void
            {
                blk();
            };
        }();
    }

    void Operation::set_completion_block(std::function<void()> value) const
    {
        [cocoon::internal::ns<::NSOperation>(this) setCompletionBlock:(value ? (void (^)(void)) ^ void() { value(); } : (void (^)(void))nil)];
    }

    bool Operation::is_concurrent() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOperation>(this) isConcurrent]);
    }

    std::vector<Operation> Operation::dependencies() const
    {
        return cocoon::internal::from_array<Operation>([cocoon::internal::ns<::NSOperation>(this) dependencies], [](id e) -> Operation
                                                       {
                                                           return cocoon::internal::wrap<Operation>((::NSOperation*)e);
                                                       });
    }

    bool Operation::is_executing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOperation>(this) isExecuting]);
    }

    bool Operation::is_finished() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOperation>(this) isFinished]);
    }

    std::string Operation::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSOperation>(this) name]);
    }

    void Operation::set_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSOperation>(this) setName:cocoon::internal::to(value)];
    }

    QualityOfService Operation::quality_of_service() const
    {
        return static_cast<QualityOfService>([cocoon::internal::ns<::NSOperation>(this) qualityOfService]);
    }

    void Operation::set_quality_of_service(QualityOfService value) const
    {
        [cocoon::internal::ns<::NSOperation>(this) setQualityOfService:static_cast<::NSQualityOfService>(value)];
    }

    OperationQueuePriority Operation::queue_priority() const
    {
        return static_cast<OperationQueuePriority>([cocoon::internal::ns<::NSOperation>(this) queuePriority]);
    }

    void Operation::set_queue_priority(OperationQueuePriority value) const
    {
        [cocoon::internal::ns<::NSOperation>(this) setQueuePriority:static_cast<::NSOperationQueuePriority>(value)];
    }

    bool Operation::is_ready() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOperation>(this) isReady]);
    }
}
