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
     * @brief C++ handle for the Objective-C class `NSCondition` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Condition condition;
     * condition.set_name("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Condition condition{};
     * condition.set_name("text");
     * auto name = condition.name();
     * condition.broadcast();
     * condition.wait();
     * condition.wait_until_date(cocoon::Date());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nscondition
     */
    class Condition : public Object
    {
    public:
        /// @brief Creates a new `NSCondition` instance and returns a handle to it.
        explicit Condition();
        /// @brief Creates a null handle that refers to no native object.
        Condition(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Condition(Adopt adopt);
        /**
         * @brief Calls `-[NSCondition broadcast]`.
         */
        void broadcast() const;
        /**
         * @brief Calls `-[NSCondition signal]`.
         */
        void signal_() const;
        /**
         * @brief Calls `-[NSCondition wait]`.
         */
        void wait() const;
        /**
         * @brief Calls `-[NSCondition waitUntilDate:]`.
         * @param limit Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool wait_until_date(const Date& limit) const;
        /**
         * @brief Returns the `name` property of `NSCondition`.
         * @return The converted Objective-C result.
         */
        std::string name() const;
        /**
         * @brief Sets the `name` property of `NSCondition`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_name(const std::string& value) const;
    };
}
