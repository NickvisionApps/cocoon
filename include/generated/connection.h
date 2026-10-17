#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class DistantObjectRequest;
    class Number;
    class Port;
    class PortNameServer;
    class RunLoop;

    /**
     * @brief C++ handle for the Objective-C class `NSConnection` (Foundation).
     * @details \@DeprecationSummary { Use ''NSXPCConnection'' instead. } An object that manages the communication between objects in different threads or between a thread and a process running on a local or remote system. Connection objects form the backbone of the distributed objects mechanism and normally operate in the background. You use the methods of ''NSConnection'' explicitly when vending an object to other applications, when accessing such a vended object through a proxy, and when altering default communication parameters. At other times, you simply interact with a vended object or its proxy. A single connection object may be shared by multiple threads and used to access a vended object.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Connection connection;
     * connection.set_independent_conversation_queueing(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Connection connection{};
     * connection.set_independent_conversation_queueing(true);
     * auto independent_conversation_queueing = connection.independent_conversation_queueing();
     * connection.set_reply_timeout(1);
     * auto reply_timeout = connection.reply_timeout();
     * connection.set_request_timeout(1);
     * auto request_timeout = connection.request_timeout();
     * auto made_0 = cocoon::Connection::connection_with_receive_port(cocoon::Port(), cocoon::Port());
     * auto made_1 = cocoon::Connection::connection_with_registered_name("text", "text");
     * connection.add_request_mode("text");
     * connection.add_run_loop(cocoon::RunLoop());
     * connection.enable_multiple_threads();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsconnection
     */
    class Connection : public Object
    {
    public:
        /// @brief Creates a new `NSConnection` instance and returns a handle to it.
        explicit Connection(const Port& receive_port, const Port& send_port);
        /// @brief Creates a new `NSConnection` instance and returns a handle to it.
        explicit Connection();
        /// @brief Creates a null handle that refers to no native object.
        Connection(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Connection(Adopt adopt);
        /**
     * @brief Calls `-[NSConnection addRequestMode:]`.
     * @details Adds 'rmode' to the set of run-loop input modes that the receiver uses for connection requests. The default input mode is 'NSDefaultRunLoopMode'. See the 'NSRunLoop' class specification for more information on input modes.
     * @param rmode Argument converted to the Objective-C parameter of the same role.
     */
        void add_request_mode(const std::string& rmode) const;
        /**
     * @brief Calls `-[NSConnection addRunLoop:]`.
     * @details Adds the specified run loop to the list of run loops on which the receiver listens for incoming messages.
     * @param runloop Argument converted to the Objective-C parameter of the same role.
     */
        void add_run_loop(const RunLoop& runloop) const;
        /**
     * @brief Calls `+[NSConnection allConnections]`.
     * @details Returns an array of all existing 'NSConnection' objects.
     * @return The converted Objective-C result.
     */
        static std::vector<Connection> all_connections();
        /**
     * @brief Calls `+[NSConnection connectionWithReceivePort:sendPort:]`.
     * @details Returns an 'NSConnection' object initialized with the specified send and receive ports.
     * @param receive_port Argument converted to the Objective-C parameter of the same role.
     * @param send_port Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Connection connection_with_receive_port(const Port& receive_port, const Port& send_port);
        /**
     * @brief Calls `+[NSConnection connectionWithRegisteredName:host:]`.
     * @details Returns an 'NSConnection' object for the specified registered name and host.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param host_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Connection connection_with_registered_name(const std::string& name, const std::string& host_name);
        /**
     * @brief Calls `+[NSConnection connectionWithRegisteredName:host:usingNameServer:]`.
     * @details Returns an 'NSConnection' object for the specified registered name, host, and name server.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param host_name Argument converted to the Objective-C parameter of the same role.
     * @param server Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Connection connection_with_registered_name(const std::string& name, const std::string& host_name, const PortNameServer& server);
        /**
     * @brief Calls `+[NSConnection currentConversation]`.
     * @details Returns an object representing an ongoing conversation triggered by a received message.
     * @return The converted Objective-C result.
     */
        static Object current_conversation();
        /**
     * @brief Calls `-[NSConnection dispatchWithComponents:]`.
     * @details Dispatches Distributed Objects component data received over the wire. NSPort subclasses should use this method to ask a connection object to dispatch Distributed Objects component data. This will decode the data, authenticate, and send the message.
     * @param components Argument converted to the Objective-C parameter of the same role.
     */
        void dispatch_with_components(const std::vector<Object>& components) const;
        /**
     * @brief Calls `-[NSConnection enableMultipleThreads]`.
     * @details Configures the receiver to allow requests from multiple threads to the remote object, without requiring each thread to maintain its own connection.
     */
        void enable_multiple_threads() const;
        /**
     * @brief Calls `-[NSConnection invalidate]`.
     * @details Invalidates the receiver.
     */
        void invalidate() const;
        /**
     * @brief Calls `-[NSConnection registerName:]`.
     * @details Registers the receiver with the default 'NSPortNameServer' under the given name.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool register_name(const std::string& name) const;
        /**
     * @brief Calls `-[NSConnection registerName:withNameServer:]`.
     * @details Registers the receiver with the given name server under the given name.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param server Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool register_name(const std::string& name, const PortNameServer& server) const;
        /**
     * @brief Calls `-[NSConnection removeRequestMode:]`.
     * @details Removes 'rmode' from the set of run-loop input modes the receiver uses for connection requests.
     * @param rmode Argument converted to the Objective-C parameter of the same role.
     */
        void remove_request_mode(const std::string& rmode) const;
        /**
     * @brief Calls `-[NSConnection removeRunLoop:]`.
     * @details Removes the specified run loop from the list of run loops on which the receiver listens for incoming messages.
     * @param runloop Argument converted to the Objective-C parameter of the same role.
     */
        void remove_run_loop(const RunLoop& runloop) const;
        /**
     * @brief Calls `-[NSConnection runInNewThread]`.
     * @details Configures the receiver to use a new thread for its connection.
     */
        void run_in_new_thread() const;
        /**
     * @brief Calls `+[NSConnection serviceConnectionWithName:rootObject:]`.
     * @details Returns an 'NSConnection' object that both listens for contact from external clients and has a designated root object, using the default name server.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param root Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Connection service_connection_with_name(const std::string& name, const Object& root);
        /**
     * @brief Calls `+[NSConnection serviceConnectionWithName:rootObject:usingNameServer:]`.
     * @details Returns an 'NSConnection' object that both listens for contact from external clients and has a designated root object.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param root Argument converted to the Objective-C parameter of the same role.
     * @param server Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Connection service_connection_with_name(const std::string& name, const Object& root, const PortNameServer& server);
        /**
     * @brief Returns the `independentConversationQueueing` property of `NSConnection`.
     * @details A Boolean value that indicates whether the receiver handles requests atomically.
     * @return The converted Objective-C result.
     */
        bool independent_conversation_queueing() const;
        /**
     * @brief Sets the `independentConversationQueueing` property of `NSConnection`.
     * @details A Boolean value that indicates whether the receiver handles requests atomically.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_independent_conversation_queueing(bool value) const;
        /**
     * @brief Returns the `localObjects` property of `NSConnection`.
     * @details All local objects that are being vended over the connection.
     * @return The converted Objective-C result.
     */
        std::vector<Object> local_objects() const;
        /**
     * @brief Returns the `multipleThreadsEnabled` property of `NSConnection`.
     * @details A Boolean value that indicates whether the receiver supports requests from multiple threads.
     * @return The converted Objective-C result.
     */
        bool multiple_threads_enabled() const;
        /**
     * @brief Returns the `receivePort` property of `NSConnection`.
     * @details The port on which the receiver receives messages.
     * @return The converted Objective-C result.
     */
        Port receive_port() const;
        /**
     * @brief Returns the `remoteObjects` property of `NSConnection`.
     * @details The proxies for all remote objects that have been received over the connection but have not yet been deallocated.
     * @return The converted Objective-C result.
     */
        std::vector<Object> remote_objects() const;
        /**
     * @brief Returns the `replyTimeout` property of `NSConnection`.
     * @details The timeout interval for replies.
     * @return The converted Objective-C result.
     */
        double reply_timeout() const;
        /**
     * @brief Sets the `replyTimeout` property of `NSConnection`.
     * @details The timeout interval for replies.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_reply_timeout(double value) const;
        /**
     * @brief Returns the `requestModes` property of `NSConnection`.
     * @details The set of request modes the receiver's receive port is registered for with its 'NSRunLoop' object.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> request_modes() const;
        /**
     * @brief Returns the `requestTimeout` property of `NSConnection`.
     * @details The timeout interval for outgoing requests.
     * @return The converted Objective-C result.
     */
        double request_timeout() const;
        /**
     * @brief Sets the `requestTimeout` property of `NSConnection`.
     * @details The timeout interval for outgoing requests.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_request_timeout(double value) const;
        /**
     * @brief Returns the `rootObject` property of `NSConnection`.
     * @details The object that the receiver makes available to other applications or threads.
     * @return The converted Objective-C result.
     */
        Object root_object() const;
        /**
     * @brief Sets the `rootObject` property of `NSConnection`.
     * @details The object that the receiver makes available to other applications or threads.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_root_object(const Object& value) const;
        /**
     * @brief Returns the `sendPort` property of `NSConnection`.
     * @details The port on which the receiver sends messages.
     * @return The converted Objective-C result.
     */
        Port send_port() const;
        /**
     * @brief Returns the `statistics` property of `NSConnection`.
     * @details A dictionary containing various statistics for the receiver. An 'NSDictionary' object containing various statistics for the receiver, such as the number of vended objects, the number of requests and replies, and so on. The statistics dictionary should be used only for debugging purposes.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Number> statistics() const;
        /**
     * @brief Returns the `valid` property of `NSConnection`.
     * @details A Boolean value that indicates whether the receiver is known to be valid.
     * @return The converted Objective-C result.
     */
        bool is_valid() const;
        /// @brief Signal for the delegate/data-source method behind `make_new_connection_sender`; connect a callback with `make_new_connection_sender().connect(...)`.
        Signal<Connection, bool(Connection)> make_new_connection_sender() const
        {
            return Signal<Connection, bool(Connection)>(handle(), "make_new_connection_sender");
        }
        /// @brief Signal for the delegate/data-source method behind `should_make_new_connection`; connect a callback with `should_make_new_connection().connect(...)`.
        Signal<Connection, bool(Connection)> should_make_new_connection() const
        {
            return Signal<Connection, bool(Connection)>(handle(), "should_make_new_connection");
        }
        /// @brief Signal for the delegate/data-source method behind `authentication_data_for_components`; connect a callback with `authentication_data_for_components().connect(...)`.
        Signal<Connection, std::vector<std::uint8_t>()> authentication_data_for_components() const
        {
            return Signal<Connection, std::vector<std::uint8_t>()>(handle(), "authentication_data_for_components");
        }
        /// @brief Signal for the delegate/data-source method behind `authenticate_components_with_data`; connect a callback with `authenticate_components_with_data().connect(...)`.
        Signal<Connection, bool(std::vector<std::uint8_t>)> authenticate_components_with_data() const
        {
            return Signal<Connection, bool(std::vector<std::uint8_t>)>(handle(), "authenticate_components_with_data");
        }
        /// @brief Signal for the delegate/data-source method behind `create_conversation_for_connection`; connect a callback with `create_conversation_for_connection().connect(...)`.
        Signal<Connection, Object()> create_conversation_for_connection() const
        {
            return Signal<Connection, Object()>(handle(), "create_conversation_for_connection");
        }
        /// @brief Signal for the delegate/data-source method behind `handle_request`; connect a callback with `handle_request().connect(...)`.
        Signal<Connection, bool(DistantObjectRequest)> handle_request() const
        {
            return Signal<Connection, bool(DistantObjectRequest)>(handle(), "handle_request");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
