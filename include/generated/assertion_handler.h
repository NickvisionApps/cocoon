#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSAssertionHandler` (Foundation).
     * @details An object that logs an assertion to the console. 'NSAssertionHandler' objects are automatically created to handle false assertions. Assertion macros, such as 'NSAssert' and 'NSCAssert', are used to evaluate a condition, and if the condition evaluates to false, the macros pass a string to an 'NSAssertionHandler' object describing the failure. Each thread has its own 'NSAssertionHandler' object. When invoked, an assertion handler prints an error message that includes the method and class (or function) containing the assertion and raises an 'NSInternalInconsistencyException'. You create assertions only using the assertion macros—you rarely need to invoke 'NSAssertionHandler' methods directly. The macros for use inside methods and functions send ''handleFailureInMethod:object:file:lineNumber:description:'' and ''handleFailureInFunction:file:lineNumber:description:'' messages respectively to the current assertion handler. The assertion handler for the current thread is obtained using the ''current'' class method. See \<doc:nsassertionhandlerkey> if you need to customize the behavior of ''NSAssertionHandler''.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::AssertionHandler assertion_handler;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsassertionhandler
     */
    class AssertionHandler : public Object
    {
    public:
        /// @brief Creates a new `NSAssertionHandler` instance and returns a handle to it.
        explicit AssertionHandler();
        /// @brief Creates a null handle that refers to no native object.
        AssertionHandler(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit AssertionHandler(Adopt adopt);
        /**
     * @brief Returns the `currentHandler` property of `NSAssertionHandler`.
     * @details Returns the 'NSAssertionHandler' object associated with the current thread. If no assertion handler is associated with the current thread, this method creates one and assigns it to the thread.
     * @return The converted Objective-C result.
     */
        static AssertionHandler current_handler();
    };
}
