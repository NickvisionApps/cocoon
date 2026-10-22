#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;

    /**
     * @brief C++ handle for the Objective-C class `NSLock` (Foundation).
     * @details An object that coordinates the operation of multiple threads of execution within the same application.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Lock lock;
     * lock.set_name("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Lock lock{};
     * lock.set_name("text");
     * auto name = lock.name();
     * lock.lock_before_date(cocoon::Date());
     * lock.try_lock();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nslock
     */
    class Lock : public Object
    {
    public:
        /// @brief Creates a new `NSLock` instance and returns a handle to it.
        explicit Lock();
        /// @brief Creates a null handle that refers to no native object.
        Lock(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Lock(Adopt adopt);
        /**
         * @brief Calls `-[NSLock lockBeforeDate:]`.
         * @details Attempts to acquire a lock before a given date and returns a Boolean value indicating whether the attempt was successful.
         * @param limit Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool lock_before_date(const Date& limit) const;
        /**
         * @brief Calls `-[NSLock tryLock]`.
         * @details Attempts to acquire a lock and immediately returns a Boolean value that indicates whether the attempt was successful.
         * @return The converted Objective-C result.
         */
        bool try_lock() const;
        /**
         * @brief Returns the `name` property of `NSLock`.
         * @details The name associated with the receiver.
         * @return The converted Objective-C result.
         */
        std::string name() const;
        /**
         * @brief Sets the `name` property of `NSLock`.
         * @details The name associated with the receiver.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_name(const std::string& value) const;
    };
}
