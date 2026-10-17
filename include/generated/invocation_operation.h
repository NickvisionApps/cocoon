#pragma once

#include "generated/enums.h"
#include "generated/operation.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Invocation;

    /**
     * @brief C++ handle for the Objective-C class `NSInvocationOperation` (Foundation).
     * @details An operation that manages the execution of a single encapsulated task specified as an invocation. The ''NSInvocationOperation'' class is a concrete subclass of ''Operation'' that you use to initiate an operation that consists of invoking a selector on a specified object. This class implements a non-concurrent operation. For more information on concurrent versus non-concurrent operations, see ''Operation''.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Operation.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::InvocationOperation invocation_operation;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsinvocationoperation
     */
    class InvocationOperation : public Operation
    {
    public:
        /// @brief Creates a new `NSInvocationOperation` instance and returns a handle to it.
        explicit InvocationOperation(const Invocation& inv);
        /// @brief Creates a new `NSInvocationOperation` instance and returns a handle to it.
        explicit InvocationOperation(const Object& target, const std::string& sel, const Object& arg);
        /// @brief Creates a new `NSInvocationOperation` instance and returns a handle to it.
        explicit InvocationOperation();
        /// @brief Creates a null handle that refers to no native object.
        InvocationOperation(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit InvocationOperation(Adopt adopt);
        /**
     * @brief Returns the `invocation` property of `NSInvocationOperation`.
     * @details The receiver's invocation object. The invocation object identifying the target object, selector, and parameters to use to execute the operation's task.
     * @return The converted Objective-C result.
     */
        Invocation invocation() const;
        /**
     * @brief Returns the `result` property of `NSInvocationOperation`.
     * @details The result of the invocation or method. The object returned by the method or an 'NSValue' object containing the return value if it is not an object. 'nil' if the method or invocation is not finished executing.
     * @return The converted Objective-C result.
     */
        Object result() const;
    };
}
