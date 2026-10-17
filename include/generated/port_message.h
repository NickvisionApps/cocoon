#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;
    class Port;

    /**
     * @brief C++ handle for the Objective-C class `NSPortMessage` (Foundation).
     * @details A low-level, operating system-independent type for inter-application (and inter-thread) messages. Port messages are used primarily by the distributed objects system. You should implement inter-application communication using distributed objects whenever possible and use ''NSPortMessage'' only when necessary. An ''NSPortMessage'' object has three major parts: the send and receive ports, which are ''NSPort'' objects that link the sender of the message to the receiver, and the components, which form the body of the message. The components are held as an ''NSArray'' object containing ''NSData'' and ''NSPort'' objects. The ''send(before:)'' message sends the components out through the send port; any replies to the message arrive on the receive port. See the ''NSPort'' class specification for information on handling incoming messages. An ''NSPortMessage'' instance can be initialized with a pair of ''NSPort'' objects and an array of components. A port message's body can contain only ''NSPort'' objects or ''NSData'' objects. In the distributed objects system the byte/character arrays are usually encoded ''NSInvocation'' objects that are being forwarded from a proxy to the corresponding real object. An ''NSPortMessage'' object also maintains a message identifier, which can be used to indicate the class of a message, such as an Objective-C method invocation, a connection request, an error, and so on. Use the ''msgid'' property to access the identifier.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PortMessage port_message;
     * port_message.set_msgid(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PortMessage port_message{};
     * port_message.set_msgid(1);
     * auto msgid = port_message.msgid();
     * port_message.send_before_date(cocoon::Date());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsportmessage
     */
    class PortMessage : public Object
    {
    public:
        /// @brief Creates a new `NSPortMessage` instance and returns a handle to it.
        explicit PortMessage(const Port& send_port, const Port& reply_port, const std::vector<Object>& components);
        /// @brief Creates a new `NSPortMessage` instance and returns a handle to it.
        explicit PortMessage();
        /// @brief Creates a null handle that refers to no native object.
        PortMessage(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PortMessage(Adopt adopt);
        /**
     * @brief Calls `-[NSPortMessage sendBeforeDate:]`.
     * @details Attempts to send the message before the specified date. If the message cannot be sent immediately, the sending thread blocks until either the message is sent or 'date' is reached. Sent messages are queued to minimize blocking, but failure can occur if multiple messages are sent to a port faster than the port's owner can receive them, causing the queue to fill up. If an error other than a time out occurs, this method could raise an 'NSInvalidSendPortException', 'NSInvalidReceivePortException', or an 'NSPortSendException'. - Parameters: - date: The instant before which the message should be sent. - Returns: 'YES' if the operation is successful, otherwise 'NO' (for example, if the operation times out).
     * @param date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool send_before_date(const Date& date) const;
        /**
     * @brief Returns the `components` property of `NSPortMessage`.
     * @details The data components of the receiver. See ''NSPortMessage'' for more information.
     * @return The converted Objective-C result.
     */
        std::vector<Object> components() const;
        /**
     * @brief Returns the `msgid` property of `NSPortMessage`.
     * @details The identifier for the receiver. Cooperating applications can use this to define different types of messages, such as connection requests, RPCs, errors, and so on.
     * @return The converted Objective-C result.
     */
        unsigned int msgid() const;
        /**
     * @brief Sets the `msgid` property of `NSPortMessage`.
     * @details The identifier for the receiver. Cooperating applications can use this to define different types of messages, such as connection requests, RPCs, errors, and so on.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_msgid(unsigned int value) const;
        /**
     * @brief Returns the `receivePort` property of `NSPortMessage`.
     * @details For an outgoing message, the port on which replies to the receiver will arrive. For an incoming message, the port the receiver did arrive on.
     * @return The converted Objective-C result.
     */
        Port receive_port() const;
        /**
     * @brief Returns the `sendPort` property of `NSPortMessage`.
     * @details For an outgoing message, the port the receiver will send itself through. For an incoming message, the port replies to the receiver should be sent through.
     * @return The converted Objective-C result.
     */
        Port send_port() const;
    };
}
