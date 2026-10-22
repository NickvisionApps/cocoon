#pragma once

#include "generated/availability.h"
#include "generated/coder.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class XPCConnection;
    class xpc_type_t;

    /**
     * @brief C++ handle for the Objective-C class `NSXPCCoder` (Foundation).
     * @details A coder that encodes and decodes objects that your app sends over an XPC connection. If you want to perform custom encoding or decoding of \<doc://com.apple.documentation/documentation/swift/codable> objects that your app sends over an ''NSXPCConnection'', use \<doc://com.apple.documentation/documentation/objectivec/nsobjectprotocol/iskind(of:)> to determine if the coder provided to your object is a kind of ''NSXPCCoder''.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Coder.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::XPCCoder xpc_coder;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsxpccoder
     */
    class XPCCoder : public Coder
    {
    public:
        /// @brief Creates a new `NSXPCCoder` instance and returns a handle to it.
        explicit XPCCoder();
        /// @brief Creates a null handle that refers to no native object.
        XPCCoder(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit XPCCoder(Adopt adopt);
        /**
         * @brief Calls `-[NSXPCCoder decodeXPCObjectOfType:forKey:]`.
         * @details Decodes an XPC object of the given type for the given key. This validates the type of the decoded object matches the type passed in. If they do not match, an exception is thrown (just like the rest of Secure Coding behaves). Note that this can return 'NULL', but calling an XPC function with 'NULL' will crash.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object decode_xpc_object_of_type(const xpc_type_t& type, const std::string& key) const;
        /**
         * @brief Calls `-[NSXPCCoder encodeXPCObject:forKey:]`.
         * @details Encodes an XPC object and associates it with the given key.
         * @param xpc_object Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_xpc_object(const Object& xpc_object, const std::string& key) const;
        /**
         * @brief Returns the `connection` property of `NSXPCCoder`.
         * @details The current 'NSXPCConnection' that is encoding or decoding.
         * @return The converted Objective-C result.
         */
        XPCConnection connection() const;
        /**
         * @brief Returns the `userInfo` property of `NSXPCCoder`.
         * @details User-defined information associated with this coder.
         * @return The converted Objective-C result.
         */
        Object user_info() const;
        /**
         * @brief Sets the `userInfo` property of `NSXPCCoder`.
         * @details User-defined information associated with this coder.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_user_info(const Object& value) const;
    };
}
