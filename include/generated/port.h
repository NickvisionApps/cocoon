#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Connection;
    class Date;
    class RunLoop;

    /**
     * @brief C++ handle for the Objective-C class `NSPort` (Foundation).
     * @details An abstract class that represents a communication channel. Communication occurs between ''NSPort'' objects, which typically reside in different threads or tasks. The distributed objects system uses ''NSPort'' objects to send ''NSPortMessage'' objects back and forth. Implement interapplication communication using distributed objects whenever possible and use ''NSPort'' objects only when necessary. To receive incoming messages, add ''NSPort'' objects to an instance of ''NSRunLoop'' as input sources. ''NSConnection'' objects automatically add their receive port when initialized.
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
     * auto made_0 = cocoon::Port::port();
     * port.add_connection(cocoon::Connection(), cocoon::RunLoop(), "text");
     * port.delegate();
     * port.invalidate();
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
     * @brief Calls `-[NSPort addConnection:toRunLoop:forMode:]`.
     * @details Adds a given connection to the receiver in a given run loop mode.
     * @param conn Argument converted to the Objective-C parameter of the same role.
     * @param run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void add_connection(const Connection& conn, const RunLoop& run_loop, const std::string& mode) const;
        /**
     * @brief Calls `-[NSPort delegate]`.
     * @details Returns the receiver's delegate.
     * @return The converted Objective-C result.
     */
        Object delegate() const;
        /**
     * @brief Calls `-[NSPort invalidate]`.
     * @details Marks the receiver as invalid and posts an ''NSPortDidBecomeInvalidNotification'' to the default notification center.
     */
        void invalidate() const;
        /**
     * @brief Calls `+[NSPort port]`.
     * @details Creates and returns a new ''NSPort'' object capable of both sending and receiving messages.
     * @return The converted Objective-C result.
     */
        static Port port();
        /**
     * @brief Calls `-[NSPort removeConnection:fromRunLoop:forMode:]`.
     * @details Removes a given connection from the receiver in a given run loop mode.
     * @param conn Argument converted to the Objective-C parameter of the same role.
     * @param run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void remove_connection(const Connection& conn, const RunLoop& run_loop, const std::string& mode) const;
        /**
     * @brief Calls `-[NSPort removeFromRunLoop:forMode:]`.
     * @details Removes the receiver from the run loop mode of the given run loop. You should not directly invoke this method. Instead, you should remove the port from the run loop.
     * @param run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void remove_from_run_loop(const RunLoop& run_loop, const std::string& mode) const;
        /**
     * @brief Calls `-[NSPort scheduleInRunLoop:forMode:]`.
     * @details Schedules the receiver into a given run loop. You should not directly invoke this method. Instead, you should add the port to a run loop.
     * @param run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void schedule_in_run_loop(const RunLoop& run_loop, const std::string& mode) const;
        /**
     * @brief Calls `-[NSPort sendBeforeDate:components:from:reserved:]`.
     * @details Attempts to send the message before a given date, treating the receiver as the send port and the given port as the receive port.
     * @param limit_date Argument converted to the Objective-C parameter of the same role.
     * @param components Argument converted to the Objective-C parameter of the same role.
     * @param receive_port Argument converted to the Objective-C parameter of the same role.
     * @param header_space_reserved Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool send_before_date(const Date& limit_date, const std::vector<Object>& components, const Port& receive_port, std::uint64_t header_space_reserved) const;
        /**
     * @brief Calls `-[NSPort sendBeforeDate:msgid:components:from:reserved:]`.
     * @details Attempts to send the message with a given identifier before a given date, treating the receiver as the send port and the given port as the receive port.
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
     * @details Sets the receiver's delegate to a given object.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     */
        void set_delegate(const Object& an_object) const;
        /**
     * @brief Returns the `reservedSpaceLength` property of `NSPort`.
     * @details The number of bytes of space reserved by the receiver for sending data.
     * @return The converted Objective-C result.
     */
        std::uint64_t reserved_space_length() const;
        /**
     * @brief Returns the `valid` property of `NSPort`.
     * @details A Boolean value that indicates whether the receiver is valid.
     * @return The converted Objective-C result.
     */
        bool is_valid() const;
    };
}
