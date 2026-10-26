#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;
    class RunLoop;

    /**
     * @brief C++ handle for the Objective-C class `NSPort` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Port port;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Port port{};
     * port.delegate();
     * port.invalidate();
     * port.remove_from_run_loop(cocoon::RunLoop(), "text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsport
     */
    class Port : public Object
    {
    public:
        /// @brief Creates a new `NSPort` instance and returns a handle to it.
        explicit Port();
        /// @brief Creates a null handle that refers to no native object.
        Port(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Port(Adopt adopt);
        /**
         * @brief Calls `-[NSPort delegate]`.
         * @return The converted Objective-C result.
         */
        Object delegate() const;
        /**
         * @brief Calls `-[NSPort invalidate]`.
         */
        void invalidate() const;
        /**
         * @brief Calls `-[NSPort removeFromRunLoop:forMode:]`.
         * @param run_loop Argument converted to the Objective-C parameter of the same role.
         * @param mode Argument converted to the Objective-C parameter of the same role.
         */
        void remove_from_run_loop(const RunLoop& run_loop, const std::string& mode) const;
        /**
         * @brief Calls `-[NSPort scheduleInRunLoop:forMode:]`.
         * @param run_loop Argument converted to the Objective-C parameter of the same role.
         * @param mode Argument converted to the Objective-C parameter of the same role.
         */
        void schedule_in_run_loop(const RunLoop& run_loop, const std::string& mode) const;
        /**
         * @brief Calls `-[NSPort sendBeforeDate:components:from:reserved:]`.
         * @param limit_date Argument converted to the Objective-C parameter of the same role.
         * @param components Argument converted to the Objective-C parameter of the same role.
         * @param receive_port Argument converted to the Objective-C parameter of the same role.
         * @param header_space_reserved Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool send_before_date(const Date& limit_date, const std::vector<Object>& components, const Port& receive_port, std::uint64_t header_space_reserved) const;
        /**
         * @brief Calls `-[NSPort sendBeforeDate:msgid:components:from:reserved:]`.
         * @param limit_date Argument converted to the Objective-C parameter of the same role.
         * @param msg_id Argument converted to the Objective-C parameter of the same role.
         * @param components Argument converted to the Objective-C parameter of the same role.
         * @param receive_port Argument converted to the Objective-C parameter of the same role.
         * @param header_space_reserved Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool send_before_date(const Date& limit_date, std::uint64_t msg_id, const std::vector<Object>& components, const Port& receive_port, std::uint64_t header_space_reserved) const;
        /**
         * @brief Calls `-[NSPort setDelegate:]`.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         */
        void set_delegate(const Object& an_object) const;
        /**
         * @brief Returns the `reservedSpaceLength` property of `NSPort`.
         * @return The converted Objective-C result.
         */
        std::uint64_t reserved_space_length() const;
        /**
         * @brief Returns the `valid` property of `NSPort`.
         * @return The converted Objective-C result.
         */
        bool is_valid() const;
    };
}
