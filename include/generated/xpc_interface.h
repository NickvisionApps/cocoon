#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class xpc_type_t;

    /**
     * @brief C++ handle for the Objective-C class `NSXPCInterface` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::XPCInterface xpc_interface;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::XPCInterface xpc_interface{};
     * xpc_interface.xpc_type_for_selector("text", 1, true);
     * xpc_interface.classes_for_selector("text", 1, true);
     * xpc_interface.interface_for_selector("text", 1, true);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsxpcinterface
     */
    class XPCInterface : public Object
    {
    public:
        /// @brief Creates a new `NSXPCInterface` instance and returns a handle to it.
        explicit XPCInterface();
        /// @brief Creates a null handle that refers to no native object.
        XPCInterface(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit XPCInterface(Adopt adopt);
        /**
         * @brief Calls `-[NSXPCInterface XPCTypeForSelector:argumentIndex:ofReply:]`.
         * @param sel Argument converted to the Objective-C parameter of the same role.
         * @param arg Argument converted to the Objective-C parameter of the same role.
         * @param of_reply Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        xpc_type_t xpc_type_for_selector(const std::string& sel, std::uint64_t arg, bool of_reply) const;
        /**
         * @brief Calls `-[NSXPCInterface classesForSelector:argumentIndex:ofReply:]`.
         * @param sel Argument converted to the Objective-C parameter of the same role.
         * @param arg Argument converted to the Objective-C parameter of the same role.
         * @param of_reply Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> classes_for_selector(const std::string& sel, std::uint64_t arg, bool of_reply) const;
        /**
         * @brief Calls `-[NSXPCInterface interfaceForSelector:argumentIndex:ofReply:]`.
         * @param sel Argument converted to the Objective-C parameter of the same role.
         * @param arg Argument converted to the Objective-C parameter of the same role.
         * @param of_reply Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        XPCInterface interface_for_selector(const std::string& sel, std::uint64_t arg, bool of_reply) const;
        /**
         * @brief Calls `+[NSXPCInterface interfaceWithProtocol:]`.
         * @param protocol Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static XPCInterface interface_with_protocol(const Object& protocol);
        /**
         * @brief Calls `-[NSXPCInterface setClasses:forSelector:argumentIndex:ofReply:]`.
         * @param classes Argument converted to the Objective-C parameter of the same role.
         * @param sel Argument converted to the Objective-C parameter of the same role.
         * @param arg Argument converted to the Objective-C parameter of the same role.
         * @param of_reply Argument converted to the Objective-C parameter of the same role.
         */
        void set_classes(const std::vector<std::string>& classes, const std::string& sel, std::uint64_t arg, bool of_reply) const;
        /**
         * @brief Calls `-[NSXPCInterface setInterface:forSelector:argumentIndex:ofReply:]`.
         * @param ifc Argument converted to the Objective-C parameter of the same role.
         * @param sel Argument converted to the Objective-C parameter of the same role.
         * @param arg Argument converted to the Objective-C parameter of the same role.
         * @param of_reply Argument converted to the Objective-C parameter of the same role.
         */
        void set_interface(const XPCInterface& ifc, const std::string& sel, std::uint64_t arg, bool of_reply) const;
        /**
         * @brief Calls `-[NSXPCInterface setXPCType:forSelector:argumentIndex:ofReply:]`.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param sel Argument converted to the Objective-C parameter of the same role.
         * @param arg Argument converted to the Objective-C parameter of the same role.
         * @param of_reply Argument converted to the Objective-C parameter of the same role.
         */
        void set_xpc_type(const xpc_type_t& type, const std::string& sel, std::uint64_t arg, bool of_reply) const;
        /**
         * @brief Returns the `protocol` property of `NSXPCInterface`.
         * @return The converted Objective-C result.
         */
        Object protocol() const;
        /**
         * @brief Sets the `protocol` property of `NSXPCInterface`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_protocol(const Object& value) const;
    };
}
