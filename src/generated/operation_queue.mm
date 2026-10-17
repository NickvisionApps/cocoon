#include "generated/operation_queue.h"
#include "internal.h"

namespace cocoon
{
    OperationQueue::OperationQueue() : OperationQueue(Adopt{cocoon::internal::retain([[::NSOperationQueue alloc] init])})
    {
    }

    OperationQueue::OperationQueue(std::nullptr_t) : Object(nullptr)
    {
    }

    OperationQueue::OperationQueue(Adopt adopt) : Object(adopt)
    {
    }

    void OperationQueue::add_barrier_block(std::function<void()> barrier) const
    {
        [cocoon::internal::ns<::NSOperationQueue>(this) addBarrierBlock:(barrier ? (void (^)(void)) ^ void() { barrier(); } : (void (^)(void))nil)];
    }

    void OperationQueue::add_operation(const Operation& op) const
    {
        [cocoon::internal::ns<::NSOperationQueue>(this) addOperation:cocoon::internal::native<::NSOperation>(op)];
    }

    void OperationQueue::add_operation_with_block(std::function<void()> block) const
    {
        [cocoon::internal::ns<::NSOperationQueue>(this) addOperationWithBlock:(block ? (void (^)(void)) ^ void() { block(); } : (void (^)(void))nil)];
    }

    void OperationQueue::add_operations(const std::vector<Operation>& ops, bool wait) const
    {
        [cocoon::internal::ns<::NSOperationQueue>(this) addOperations:cocoon::internal::to_array(ops, [](const Operation& e) -> id
                                                                     {
                                                                         return cocoon::internal::native<::NSOperation>(e);
                                                                     })
                                      waitUntilFinished:static_cast<::BOOL>(wait)];
    }

    void OperationQueue::cancel_all_operations() const
    {
        [cocoon::internal::ns<::NSOperationQueue>(this) cancelAllOperations];
    }

    void OperationQueue::wait_until_all_operations_are_finished() const
    {
        [cocoon::internal::ns<::NSOperationQueue>(this) waitUntilAllOperationsAreFinished];
    }

    OperationQueue OperationQueue::current_queue()
    {
        return cocoon::internal::wrap<OperationQueue>([::NSOperationQueue currentQueue]);
    }

    OperationQueue OperationQueue::main_queue()
    {
        return cocoon::internal::wrap<OperationQueue>([::NSOperationQueue mainQueue]);
    }

    std::int64_t OperationQueue::max_concurrent_operation_count() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSOperationQueue>(this) maxConcurrentOperationCount]);
    }

    void OperationQueue::set_max_concurrent_operation_count(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSOperationQueue>(this) setMaxConcurrentOperationCount:static_cast<::NSInteger>(value)];
    }

    std::string OperationQueue::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSOperationQueue>(this) name]);
    }

    void OperationQueue::set_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSOperationQueue>(this) setName:cocoon::internal::to(value)];
    }

    std::uint64_t OperationQueue::operation_count() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSOperationQueue>(this) operationCount]);
    }

    std::vector<Operation> OperationQueue::operations() const
    {
        return cocoon::internal::from_array<Operation>([cocoon::internal::ns<::NSOperationQueue>(this) operations], [](id e) -> Operation
                                         {
                                             return cocoon::internal::wrap<Operation>((::NSOperation*)e);
                                         });
    }

    Progress OperationQueue::progress() const
    {
        return cocoon::internal::wrap<Progress>([cocoon::internal::ns<::NSOperationQueue>(this) progress]);
    }

    QualityOfService OperationQueue::quality_of_service() const
    {
        return static_cast<QualityOfService>([cocoon::internal::ns<::NSOperationQueue>(this) qualityOfService]);
    }

    void OperationQueue::set_quality_of_service(QualityOfService value) const
    {
        [cocoon::internal::ns<::NSOperationQueue>(this) setQualityOfService:static_cast<::NSQualityOfService>(value)];
    }

    bool OperationQueue::is_suspended() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOperationQueue>(this) isSuspended]);
    }

    void OperationQueue::set_suspended(bool value) const
    {
        [cocoon::internal::ns<::NSOperationQueue>(this) setSuspended:static_cast<::BOOL>(value)];
    }

    Object OperationQueue::underlying_queue() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSOperationQueue>(this) underlyingQueue]);
    }

    void OperationQueue::set_underlying_queue(const Object& value) const
    {
        [cocoon::internal::ns<::NSOperationQueue>(this) setUnderlyingQueue:cocoon::internal::native_id(value)];
    }
}
