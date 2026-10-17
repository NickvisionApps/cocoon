#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSURLSessionWebSocketMessage` (Foundation).
     * @details The client can create a WebSocket message object that will be passed to the send calls and will be delivered from the receive calls. The message can be initialized with data or string. If initialized with data, the string property will be nil and vice versa.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLSessionWebSocketMessage url_session_web_socket_message{"text"};
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlsessionwebsocketmessage
     */
    class URLSessionWebSocketMessage : public Object
    {
    public:
        /// @brief Creates a new `NSURLSessionWebSocketMessage` instance and returns a handle to it.
        explicit URLSessionWebSocketMessage(const std::vector<std::uint8_t>& data);
        /// @brief Creates a new `NSURLSessionWebSocketMessage` instance and returns a handle to it.
        explicit URLSessionWebSocketMessage(const std::string& string);
        URLSessionWebSocketMessage();
        /// @brief Creates a null handle that refers to no native object.
        URLSessionWebSocketMessage(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLSessionWebSocketMessage(Adopt adopt);
        /**
     * @brief Returns the `data` property of `NSURLSessionWebSocketMessage`.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> data() const;
        /**
     * @brief Returns the `string` property of `NSURLSessionWebSocketMessage`.
     * @return The converted Objective-C result.
     */
        std::string string() const;
        /**
     * @brief Returns the `type` property of `NSURLSessionWebSocketMessage`.
     * @return The converted Objective-C result.
     */
        URLSessionWebSocketMessageType type() const;
    };
}
