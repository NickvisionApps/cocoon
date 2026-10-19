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
     */
        void activate() const;
        /**
     * @brief Calls `+[NSXPCListener anonymousListener]`.
     * @return The converted Objective-C result.
     */
        static XPCListener anonymous_listener();
        /**
     * @brief Calls `-[NSXPCListener invalidate]`.
     */
        void invalidate() const;
        /**
     * @brief Calls `-[NSXPCListener resume]`.
     */
        void resume() const;
        /**
     * @brief Calls `+[NSXPCListener serviceListener]`.
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
     */
        void suspend() const;
        /**
     * @brief Returns the `endpoint` property of `NSXPCListener`.
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
