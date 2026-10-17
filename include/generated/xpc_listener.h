#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class XPCConnection;
    class XPCListenerEndpoint;

    /**
     * @brief C++ handle for the Objective-C class `NSXPCListener` (Foundation).
     * @details A listener that waits for new incoming connections, configures them, and accepts or rejects them. Each XPC service, launchd agent, or launchd daemon typically has at least one ''NSXPCListener'' object that listens for connections to a specified service name. Each listener must have a delegate that conforms to the ''NSXPCListenerDelegate'' protocol. When the listener receives a new connection request, it creates a new ''NSXPCConnection'' object, then asks the delegate to inspect, configure, and resume the connection object by calling the delegate's ''NSXPCListenerDelegate/listener(:shouldAcceptNewConnection:)'' method.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::XPCListener xpc_listener;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::XPCListener xpc_listener{};
     * auto made_0 = cocoon::XPCListener::anonymous_listener();
     * auto made_1 = cocoon::XPCListener::service_listener();
     * xpc_listener.activate();
     * xpc_listener.invalidate();
     * xpc_listener.resume();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsxpclistener
     */
    class XPCListener : public Object
    {
    public:
        /// @brief Creates a new `NSXPCListener` instance and returns a handle to it.
        explicit XPCListener(const std::string& name);
        /// @brief Creates a new `NSXPCListener` instance and returns a handle to it.
        explicit XPCListener();
        /// @brief Creates a null handle that refers to no native object.
        XPCListener(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit XPCListener(Adopt adopt);
        /**
     * @brief Calls `-[NSXPCListener activate]`.
     * @details Activates the listener. Listeners start in an inactive state. You must call 'activate' on a listener before it will send or receive any messages. Calling 'activate' on an active listener has no effect. For new code, using 'activate' is preferred over 'resume'.
     */
        void activate() const;
        /**
     * @brief Calls `+[NSXPCListener anonymousListener]`.
     * @details Creates an anonymous listener connection. Other processes may connect to this listener by passing this listener object's endpoint to 'NSXPCConnection''s 'initWithListenerEndpoint:' method.
     * @return The converted Objective-C result.
     */
        static XPCListener anonymous_listener();
        /**
     * @brief Calls `-[NSXPCListener invalidate]`.
     * @details Invalidates the listener. No more connections will be created. Once a listener is invalidated it may not be resumed or suspended.
     */
        void invalidate() const;
        /**
     * @brief Calls `-[NSXPCListener resume]`.
     * @details Resumes the listener. All listeners start suspended and must be resumed before they will process incoming requests. If called on the 'serviceListener', this method will never return. Call it as the last step inside your 'main' function in your XPC service. If called on any other 'NSXPCListener', the listener is resumed and the method returns immediately. For new code, calling 'activate' is preferred for the initial activation of the listener.
     */
        void resume() const;
        /**
     * @brief Calls `+[NSXPCListener serviceListener]`.
     * @details Returns the singleton listener for an XPC service. If your listener is an XPC service (that is, in the XPCServices folder of an application or framework), then use this method to get the shared, singleton 'NSXPCListener' object that will await new connections. When the resume method is called on this listener, it will not return. Instead it hands over control to the object and allows it to service the listener as appropriate. This makes it ideal for use in your 'main()' function.
     * @return The converted Objective-C result.
     */
        static XPCListener service_listener();
        /**
     * @brief Calls `-[NSXPCListener setConnectionCodeSigningRequirement:]`.
     * @details Sets the code signing requirement for new connections. If the requirement is malformed, an exception is thrown. If new peer connections do not match the requirement, the incoming connection is automatically rejected before consulting the delegate. This method will only work on 'anonymousListener' or 'initWithMachServiceName' listener instances. Use on other types of listeners will result in an assertion failure. See https://developer.apple.com/library/archive/documentation/Security/Conceptual/CodeSigningGuide/RequirementLang/RequirementLang.html for more information on the format.
     * @param requirement Argument converted to the Objective-C parameter of the same role.
     */
        void set_connection_code_signing_requirement(const std::string& requirement) const;
        /**
     * @brief Calls `-[NSXPCListener suspend]`.
     * @details Suspends the listener. Suspends must be balanced with resumes before the listener may be invalidated.
     */
        void suspend() const;
        /**
     * @brief Returns the `endpoint` property of `NSXPCListener`.
     * @details An endpoint object which may be sent over an existing connection. This allows the receiver of the endpoint to create a new connection to this 'NSXPCListener'. The 'NSXPCListenerEndpoint' uniquely names this listener object across connections.
     * @return The converted Objective-C result.
     */
        XPCListenerEndpoint endpoint() const;
        /// @brief Signal for the delegate/data-source method behind `listener_should_accept_new_connection`; connect a callback with `listener_should_accept_new_connection().connect(...)`.
        Signal<XPCListener, bool(XPCConnection)> listener_should_accept_new_connection() const
        {
            return Signal<XPCListener, bool(XPCConnection)>(handle(), "listener_should_accept_new_connection");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
