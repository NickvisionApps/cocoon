#pragma once

#include "generated/availability.h"
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
     */
        void activate() const;
        /**
     * @brief Calls `+[NSXPCConnection currentConnection]`.
     * @return The converted Objective-C result.
     */
        static XPCConnection current_connection();
        /**
     * @brief Calls `-[NSXPCConnection invalidate]`.
     */
        void invalidate() const;
        /**
     * @brief Calls `-[NSXPCConnection remoteObjectProxyWithErrorHandler:]`.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object remote_object_proxy_with_error_handler(std::function<void(Error)> handler) const;
        /**
     * @brief Calls `-[NSXPCConnection resume]`.
     */
        void resume() const;
        /**
     * @brief Calls `-[NSXPCConnection scheduleSendBarrierBlock:]`.
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
     */
        void suspend() const;
        /**
     * @brief Calls `-[NSXPCConnection synchronousRemoteObjectProxyWithErrorHandler:]`.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object synchronous_remote_object_proxy_with_error_handler(std::function<void(Error)> handler) const;
        /**
     * @brief Returns the `auditSessionIdentifier` property of `NSXPCConnection`.
     * @return The converted Objective-C result.
     */
        int audit_session_identifier() const;
        /**
     * @brief Returns the `effectiveGroupIdentifier` property of `NSXPCConnection`.
     * @return The converted Objective-C result.
     */
        unsigned int effective_group_identifier() const;
        /**
     * @brief Returns the `effectiveUserIdentifier` property of `NSXPCConnection`.
     * @return The converted Objective-C result.
     */
        unsigned int effective_user_identifier() const;
        /**
     * @brief Returns the `endpoint` property of `NSXPCConnection`.
     * @return The converted Objective-C result.
     */
        XPCListenerEndpoint endpoint() const;
        /**
     * @brief Returns the `exportedInterface` property of `NSXPCConnection`.
     * @return The converted Objective-C result.
     */
        XPCInterface exported_interface() const;
        /**
     * @brief Sets the `exportedInterface` property of `NSXPCConnection`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_exported_interface(const XPCInterface& value) const;
        /**
     * @brief Returns the `exportedObject` property of `NSXPCConnection`.
     * @return The converted Objective-C result.
     */
        Object exported_object() const;
        /**
     * @brief Sets the `exportedObject` property of `NSXPCConnection`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_exported_object(const Object& value) const;
        /**
     * @brief Returns the `interruptionHandler` property of `NSXPCConnection`.
     * @return The converted Objective-C result.
     */
        std::function<void()> interruption_handler() const;
        /**
     * @brief Sets the `interruptionHandler` property of `NSXPCConnection`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_interruption_handler(std::function<void()> value) const;
        /**
     * @brief Returns the `invalidationHandler` property of `NSXPCConnection`.
     * @return The converted Objective-C result.
     */
        std::function<void()> invalidation_handler() const;
        /**
     * @brief Sets the `invalidationHandler` property of `NSXPCConnection`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_invalidation_handler(std::function<void()> value) const;
        /**
     * @brief Returns the `processIdentifier` property of `NSXPCConnection`.
     * @return The converted Objective-C result.
     */
        int process_identifier() const;
        /**
     * @brief Returns the `remoteObjectInterface` property of `NSXPCConnection`.
     * @return The converted Objective-C result.
     */
        XPCInterface remote_object_interface() const;
        /**
     * @brief Sets the `remoteObjectInterface` property of `NSXPCConnection`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_remote_object_interface(const XPCInterface& value) const;
        /**
     * @brief Returns the `remoteObjectProxy` property of `NSXPCConnection`.
     * @return The converted Objective-C result.
     */
        Object remote_object_proxy() const;
        /**
     * @brief Returns the `serviceName` property of `NSXPCConnection`.
     * @return The converted Objective-C result.
     */
        std::string service_name() const;
    };
}
