#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/operation.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Invocation;

    /**
     * @brief C++ handle for the Objective-C class `NSInvocationOperation` (Foundation).
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
     * @return The converted Objective-C result.
     */
        Invocation invocation() const;
        /**
     * @brief Returns the `result` property of `NSInvocationOperation`.
     * @return The converted Objective-C result.
     */
        Object result() const;
    };
}
