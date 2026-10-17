#include "generated/block_operation.h"
#include "internal.h"

namespace cocoon
{
    BlockOperation::BlockOperation() : BlockOperation(Adopt{cocoon::internal::retain([[::NSBlockOperation alloc] init])})
    {
    }

    BlockOperation::BlockOperation(std::nullptr_t) : Operation(nullptr)
    {
    }

    BlockOperation::BlockOperation(Adopt adopt) : Operation(adopt)
    {
    }

    void BlockOperation::add_execution_block(std::function<void()> block) const
    {
        [cocoon::internal::ns<::NSBlockOperation>(this) addExecutionBlock:(block ? (void (^)(void)) ^ void() { block(); } : (void (^)(void))nil)];
    }

    BlockOperation BlockOperation::block_operation_with_block(std::function<void()> block)
    {
        return cocoon::internal::wrap<BlockOperation>([::NSBlockOperation blockOperationWithBlock:(block ? (void (^)(void)) ^ void() { block(); } : (void (^)(void))nil)]);
    }
}
