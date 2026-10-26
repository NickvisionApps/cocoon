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
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool send_before_date(const Date& date) const;
        /**
         * @brief Returns the `components` property of `NSPortMessage`.
         * @return The converted Objective-C result.
         */
        std::vector<Object> components() const;
        /**
         * @brief Returns the `msgid` property of `NSPortMessage`.
         * @return The converted Objective-C result.
         */
        unsigned int msgid() const;
        /**
         * @brief Sets the `msgid` property of `NSPortMessage`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_msgid(unsigned int value) const;
        /**
         * @brief Returns the `receivePort` property of `NSPortMessage`.
         * @return The converted Objective-C result.
         */
        Port receive_port() const;
        /**
         * @brief Returns the `sendPort` property of `NSPortMessage`.
         * @return The converted Objective-C result.
         */
        Port send_port() const;
    };
}
