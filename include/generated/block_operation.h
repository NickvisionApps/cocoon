#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/operation.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSBlockOperation` (Foundation).
     * @details An operation that manages the concurrent execution of one or more blocks. The ''BlockOperation'' class is a concrete subclass of ''Operation'' that manages the concurrent execution of one or more blocks. You can use this object to execute several blocks at once without having to create separate operation objects for each. When executing more than one block, the operation itself is considered finished only when all blocks have finished executing. Blocks added to a block operation are dispatched with default priority to an appropriate work queue. The blocks themselves should not make any assumptions about the configuration of their execution environment. For more information about blocks, see [Blocks Programming Topics](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/Blocks/Articles/00_Introduction.html\#//apple_ref/doc/uid/TP40007502).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Operation.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::BlockOperation block_operation;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsblockoperation
     */
    class BlockOperation : public Operation
    {
    public:
        /// @brief Creates a new `NSBlockOperation` instance and returns a handle to it.
        explicit BlockOperation();
        /// @brief Creates a null handle that refers to no native object.
        BlockOperation(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit BlockOperation(Adopt adopt);
        /**
     * @brief Calls `-[NSBlockOperation addExecutionBlock:]`.
     * @details Adds the specified block to the receiver's list of blocks to perform. The specified block should not make any assumptions about its execution environment. Calling this method while the receiver is executing or has already finished causes an 'NSInvalidArgumentException' exception to be thrown. - Parameter block: The block to add to the receiver's list. The block should take no parameters and have no return value.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void add_execution_block(std::function<void()> block) const;
        /**
     * @brief Calls `+[NSBlockOperation blockOperationWithBlock:]`.
     * @details Creates and returns an 'NSBlockOperation' object and adds the specified block to it. - Parameter block: The block to add to the new block operation object's list. The block should take no parameters and have no return value. - Returns: A new block operation object.
     * @param block Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static BlockOperation block_operation_with_block(std::function<void()> block);
    };
}
