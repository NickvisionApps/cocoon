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
         * @param limit Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool lock_before_date(const Date& limit) const;
        /**
         * @brief Calls `-[NSConditionLock lockWhenCondition:]`.
         * @param condition Argument converted to the Objective-C parameter of the same role.
         */
        void lock_when_condition(std::int64_t condition) const;
        /**
         * @brief Calls `-[NSConditionLock lockWhenCondition:beforeDate:]`.
         * @param condition Argument converted to the Objective-C parameter of the same role.
         * @param limit Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool lock_when_condition(std::int64_t condition, const Date& limit) const;
        /**
         * @brief Calls `-[NSConditionLock tryLock]`.
         * @return The converted Objective-C result.
         */
        bool try_lock() const;
        /**
         * @brief Calls `-[NSConditionLock tryLockWhenCondition:]`.
         * @param condition Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool try_lock_when_condition(std::int64_t condition) const;
        /**
         * @brief Calls `-[NSConditionLock unlockWithCondition:]`.
         * @param condition Argument converted to the Objective-C parameter of the same role.
         */
        void unlock_with_condition(std::int64_t condition) const;
        /**
         * @brief Returns the `condition` property of `NSConditionLock`.
         * @return The converted Objective-C result.
         */
        std::int64_t condition() const;
        /**
         * @brief Returns the `name` property of `NSConditionLock`.
         * @return The converted Objective-C result.
         */
        std::string name() const;
        /**
         * @brief Sets the `name` property of `NSConditionLock`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_name(const std::string& value) const;
    };
}
