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
     * @brief C++ handle for the Objective-C class `NSConditionLock` (Foundation).
     * @details A lock that can be associated with specific, user-defined conditions.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ConditionLock condition_lock;
     * condition_lock.set_name("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ConditionLock condition_lock{};
     * condition_lock.set_name("text");
     * auto name = condition_lock.name();
     * condition_lock.lock_before_date(cocoon::Date());
     * condition_lock.lock_when_condition(1);
     * condition_lock.lock_when_condition(1, cocoon::Date());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsconditionlock
     */
    class ConditionLock : public Object
    {
    public:
        /// @brief Creates a new `NSConditionLock` instance and returns a handle to it.
        explicit ConditionLock(std::int64_t condition);
        /// @brief Creates a new `NSConditionLock` instance and returns a handle to it.
        explicit ConditionLock();
        /// @brief Creates a null handle that refers to no native object.
        ConditionLock(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ConditionLock(Adopt adopt);
        /**
     * @brief Calls `-[NSConditionLock lockBeforeDate:]`.
     * @details Attempts to acquire a lock before a given date and returns a Boolean value indicating whether the attempt was successful.
     * @param limit Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool lock_before_date(const Date& limit) const;
        /**
     * @brief Calls `-[NSConditionLock lockWhenCondition:]`.
     * @details Attempts to acquire a lock when the receiver's condition is equal to a specific value.
     * @param condition Argument converted to the Objective-C parameter of the same role.
     */
        void lock_when_condition(std::int64_t condition) const;
        /**
     * @brief Calls `-[NSConditionLock lockWhenCondition:beforeDate:]`.
     * @details Attempts to acquire a lock when the receiver's condition is equal to a specific value, and returns before a given date.
     * @param condition Argument converted to the Objective-C parameter of the same role.
     * @param limit Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool lock_when_condition(std::int64_t condition, const Date& limit) const;
        /**
     * @brief Calls `-[NSConditionLock tryLock]`.
     * @details Attempts to acquire a lock and immediately returns a Boolean value that indicates whether the attempt was successful.
     * @return The converted Objective-C result.
     */
        bool try_lock() const;
        /**
     * @brief Calls `-[NSConditionLock tryLockWhenCondition:]`.
     * @details Attempts to acquire a lock if the receiver's condition is equal to a specific value and immediately returns a Boolean value that indicates whether the attempt was successful.
     * @param condition Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool try_lock_when_condition(std::int64_t condition) const;
        /**
     * @brief Calls `-[NSConditionLock unlockWithCondition:]`.
     * @details Relinquishes the lock and sets the receiver's condition.
     * @param condition Argument converted to the Objective-C parameter of the same role.
     */
        void unlock_with_condition(std::int64_t condition) const;
        /**
     * @brief Returns the `condition` property of `NSConditionLock`.
     * @details The condition associated with the receiver.
     * @return The converted Objective-C result.
     */
        std::int64_t condition() const;
        /**
     * @brief Returns the `name` property of `NSConditionLock`.
     * @details The name associated with the receiver.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Sets the `name` property of `NSConditionLock`.
     * @details The name associated with the receiver.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_name(const std::string& value) const;
    };
}
