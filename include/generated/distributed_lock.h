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
     * @brief C++ handle for the Objective-C class `NSDistributedLock` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DistributedLock distributed_lock{"text"};
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DistributedLock distributed_lock{"text"};
     * auto made_0 = cocoon::DistributedLock::lock_with_path("text");
     * distributed_lock.break_lock();
     * distributed_lock.try_lock();
     * distributed_lock.unlock();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsdistributedlock
     */
    class DistributedLock : public Object
    {
    public:
        /// @brief Creates a new `NSDistributedLock` instance and returns a handle to it.
        explicit DistributedLock(const std::string& path);
        DistributedLock();
        /// @brief Creates a null handle that refers to no native object.
        DistributedLock(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DistributedLock(Adopt adopt);
        /**
     * @brief Calls `-[NSDistributedLock breakLock]`.
     */
        void break_lock() const;
        /**
     * @brief Calls `+[NSDistributedLock lockWithPath:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static DistributedLock lock_with_path(const std::string& path);
        /**
     * @brief Calls `-[NSDistributedLock tryLock]`.
     * @return The converted Objective-C result.
     */
        bool try_lock() const;
        /**
     * @brief Calls `-[NSDistributedLock unlock]`.
     */
        void unlock() const;
        /**
     * @brief Returns the `lockDate` property of `NSDistributedLock`.
     * @return The converted Objective-C result.
     */
        Date lock_date() const;
    };
}
