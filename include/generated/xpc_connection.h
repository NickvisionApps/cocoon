#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class XPCInterface;
    class XPCListenerEndpoint;

    /**
     * @brief C++ handle for the Objective-C class `NSXPCConnection` (Foundation).
     * @details A bidirectional communication channel between two processes. This class is the primary means of creating and configuring the communication mechanism between two processes. Each process has one instance of this class to represent the endpoint in the communication channel.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::XPCConnection xpc_connection;
     * xpc_connection.set_exported_interface(cocoon::XPCInterface());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::XPCConnection xpc_connection{};
     * xpc_connection.set_exported_interface(cocoon::XPCInterface());
     * auto exported_interface = xpc_connection.exported_interface();
     * xpc_connection.set_remote_object_interface(cocoon::XPCInterface());
     * auto remote_object_interface = xpc_connection.remote_object_interface();
     * auto made_0 = cocoon::XPCConnection::current_connection();
     * xpc_connection.activate();
     * xpc_connection.invalidate();
     * xpc_connection.resume();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsxpcconnection
     */
    class XPCConnection : public Object
    {
    public:
        /// @brief Creates a new `NSXPCConnection` instance and returns a handle to it.
        explicit XPCConnection(const XPCListenerEndpoint& endpoint);
        /// @brief Creates a new `NSXPCConnection` instance and returns a handle to it.
        explicit XPCConnection(const std::string& name, XPCConnectionOptions options);
        /// @brief Creates a new `NSXPCConnection` instance and returns a handle to it.
        explicit XPCConnection(const std::string& service_name);
        /// @brief Creates a new `NSXPCConnection` instance and returns a handle to it.
        explicit XPCConnection();
        /// @brief Creates a null handle that refers to no native object.
        XPCConnection(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit XPCConnection(Adopt adopt);
        /**
     * @brief Calls `-[NSXPCConnection activate]`.
     * @details Activates the connection. Connections start in an inactive state. You must call 'activate' on a connection before it will send or receive any messages. Calling 'activate' on an active connection has no effect. For new code, using 'activate' is preferred over 'resume'.
     */
        void activate() const;
        /**
     * @brief Calls `+[NSXPCConnection currentConnection]`.
     * @details Returns the current connection, in the context of a call to a method on your exported object. Useful for determining 'who called this'.
     * @return The converted Objective-C result.
     */
        static XPCConnection current_connection();
        /**
     * @brief Calls `-[NSXPCConnection invalidate]`.
     * @details Invalidates the connection. All outstanding error handling blocks and invalidation blocks will be called on the message handling queue. The connection must be invalidated before it is deallocated. After a connection is invalidated, no more messages may be sent or received.
     */
        void invalidate() const;
        /**
     * @brief Calls `-[NSXPCConnection remoteObjectProxyWithErrorHandler:]`.
     * @details Returns a proxy for the remote object, with an error handler.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object remote_object_proxy_with_error_handler(std::function<void(Error)> handler) const;
        /**
     * @brief Calls `-[NSXPCConnection resume]`.
     * @details Resumes the connection. All connections start suspended. You must resume them before they will start processing received messages or sending messages through the 'remoteObjectProxy'. Calling resume does not immediately launch the XPC service. The service will be started on demand when the first message is sent. However, if the name specified when creating the connection is determined to be invalid, your invalidation handler will be called immediately (and asynchronously) after calling resume. For new code, calling 'activate' is preferred for the initial activation of the connection.
     */
        void resume() const;
        /**
     * @brief Calls `-[NSXPCConnection scheduleSendBarrierBlock:]`.
     * @details Adds a barrier block to be executed on the connection after any outstanding sends have completed. This does not guarantee that messages will be received by the remote process by the time the block is invoked. If you need to ensure receipt of a message by the remote process, waiting for a reply to come back is the best option.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void schedule_send_barrier_block(std::function<void()> block) const;
        /**
     * @brief Calls `-[NSXPCConnection setCodeSigningRequirement:]`.
     * @details Sets the code signing requirement for this connection. If the requirement is malformed, an exception is thrown. If new messages do not match the requirement, the connection is invalidated. It is recommended to set this before calling 'resume', as it is an XPC error to call it more than once. See https://developer.apple.com/library/archive/documentation/Security/Conceptual/CodeSigningGuide/RequirementLang/RequirementLang.html for more information on the format.
     * @param requirement Argument converted to the Objective-C parameter of the same role.
     */
        void set_code_signing_requirement(const std::string& requirement) const;
        /**
     * @brief Calls `-[NSXPCConnection suspend]`.
     * @details Suspends the connection. Suspends must be balanced with resumes before the connection may be invalidated.
     */
        void suspend() const;
        /**
     * @brief Calls `-[NSXPCConnection synchronousRemoteObjectProxyWithErrorHandler:]`.
     * @details Returns a proxy that makes a synchronous IPC call instead of the default async behavior. The error handler block and reply block will be invoked on the calling thread before the message to the proxy returns, instead of on the queue for the connection.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object synchronous_remote_object_proxy_with_error_handler(std::function<void(Error)> handler) const;
        /**
     * @brief Returns the `auditSessionIdentifier` property of `NSXPCConnection`.
     * @details The audit session identifier of the connecting process.
     * @return The converted Objective-C result.
     */
        int audit_session_identifier() const;
        /**
     * @brief Returns the `effectiveGroupIdentifier` property of `NSXPCConnection`.
     * @details The effective group identifier (EGID) of the connecting process.
     * @return The converted Objective-C result.
     */
        unsigned int effective_group_identifier() const;
        /**
     * @brief Returns the `effectiveUserIdentifier` property of `NSXPCConnection`.
     * @details The effective user identifier (EUID) of the connecting process.
     * @return The converted Objective-C result.
     */
        unsigned int effective_user_identifier() const;
        /**
     * @brief Returns the `endpoint` property of `NSXPCConnection`.
     * @details The endpoint that was provided when the connection was initialized.
     * @return The converted Objective-C result.
     */
        XPCListenerEndpoint endpoint() const;
        /**
     * @brief Returns the `exportedInterface` property of `NSXPCConnection`.
     * @details The interface that describes messages that are allowed to be received by the exported object on this connection. This value is required if an exported object is set.
     * @return The converted Objective-C result.
     */
        XPCInterface exported_interface() const;
        /**
     * @brief Sets the `exportedInterface` property of `NSXPCConnection`.
     * @details The interface that describes messages that are allowed to be received by the exported object on this connection. This value is required if an exported object is set.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_exported_interface(const XPCInterface& value) const;
        /**
     * @brief Returns the `exportedObject` property of `NSXPCConnection`.
     * @details An object that is vended to the other side of this connection. Messages sent to the 'remoteObjectProxy' from the other side of the connection will be dispatched to this object. Messages delivered to exported objects are serialized and sent on a non-main queue. The receiver is responsible for handling the messages on a different queue or thread if it is required.
     * @return The converted Objective-C result.
     */
        Object exported_object() const;
        /**
     * @brief Sets the `exportedObject` property of `NSXPCConnection`.
     * @details An object that is vended to the other side of this connection. Messages sent to the 'remoteObjectProxy' from the other side of the connection will be dispatched to this object. Messages delivered to exported objects are serialized and sent on a non-main queue. The receiver is responsible for handling the messages on a different queue or thread if it is required.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_exported_object(const Object& value) const;
        /**
     * @brief Returns the `interruptionHandler` property of `NSXPCConnection`.
     * @details A block that is called if the remote process exits or crashes. It may be possible to re-establish the connection by simply sending another message. The handler will be invoked on the same queue as replies and other handlers, but there is no guarantee of ordering between those callbacks and this one. The 'interruptionHandler' property is cleared after the connection becomes invalid to mitigate the impact of a retain cycle created by referencing the 'NSXPCConnection' instance inside this block.
     * @return The converted Objective-C result.
     */
        std::function<void()> interruption_handler() const;
        /**
     * @brief Sets the `interruptionHandler` property of `NSXPCConnection`.
     * @details A block that is called if the remote process exits or crashes. It may be possible to re-establish the connection by simply sending another message. The handler will be invoked on the same queue as replies and other handlers, but there is no guarantee of ordering between those callbacks and this one. The 'interruptionHandler' property is cleared after the connection becomes invalid to mitigate the impact of a retain cycle created by referencing the 'NSXPCConnection' instance inside this block.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_interruption_handler(std::function<void()> value) const;
        /**
     * @brief Returns the `invalidationHandler` property of `NSXPCConnection`.
     * @details A block that is called if the connection can not be formed or has terminated and may not be re-established. The invalidation handler will also be called if a connection created with an 'NSXPCListenerEndpoint' is invalidated from the remote side, or if the 'NSXPCListener' used to create that endpoint is invalidated. You may not send messages over the connection from within an invalidation handler block. The 'invalidationHandler' property is cleared after the connection becomes invalid to mitigate the impact of a retain cycle created by referencing the 'NSXPCConnection' instance inside this block.
     * @return The converted Objective-C result.
     */
        std::function<void()> invalidation_handler() const;
        /**
     * @brief Sets the `invalidationHandler` property of `NSXPCConnection`.
     * @details A block that is called if the connection can not be formed or has terminated and may not be re-established. The invalidation handler will also be called if a connection created with an 'NSXPCListenerEndpoint' is invalidated from the remote side, or if the 'NSXPCListener' used to create that endpoint is invalidated. You may not send messages over the connection from within an invalidation handler block. The 'invalidationHandler' property is cleared after the connection becomes invalid to mitigate the impact of a retain cycle created by referencing the 'NSXPCConnection' instance inside this block.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_invalidation_handler(std::function<void()> value) const;
        /**
     * @brief Returns the `processIdentifier` property of `NSXPCConnection`.
     * @details The process identifier (PID) of the connecting process.
     * @return The converted Objective-C result.
     */
        int process_identifier() const;
        /**
     * @brief Returns the `remoteObjectInterface` property of `NSXPCConnection`.
     * @details The interface that describes messages that are allowed to be received by the remote object on the other side of this connection. This value is required if messages are sent over this connection.
     * @return The converted Objective-C result.
     */
        XPCInterface remote_object_interface() const;
        /**
     * @brief Sets the `remoteObjectInterface` property of `NSXPCConnection`.
     * @details The interface that describes messages that are allowed to be received by the remote object on the other side of this connection. This value is required if messages are sent over this connection.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_remote_object_interface(const XPCInterface& value) const;
        /**
     * @brief Returns the `remoteObjectProxy` property of `NSXPCConnection`.
     * @details Returns a proxy for the remote object (that is, the object exported from the other side of this connection).
     * @return The converted Objective-C result.
     */
        Object remote_object_proxy() const;
        /**
     * @brief Returns the `serviceName` property of `NSXPCConnection`.
     * @details The name of the XPC service that this connection was configured to connect to.
     * @return The converted Objective-C result.
     */
        std::string service_name() const;
    };
}
