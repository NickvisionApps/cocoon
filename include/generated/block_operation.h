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
        explicit BlockOperation(std::function<void()> block);
        /// @brief Creates a new `NSBlockOperation` instance and returns a handle to it.
        explicit BlockOperation();
        /// @brief Creates a null handle that refers to no native object.
        BlockOperation(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit BlockOperation(Adopt adopt);
        /**
         * @brief Calls `-[NSBlockOperation addExecutionBlock:]`.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void add_execution_block(std::function<void()> block) const;
    };
}
