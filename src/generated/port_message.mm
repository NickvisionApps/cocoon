#include "generated/port_message.h"
#include "internal.h"

namespace cocoon
{
    PortMessage::PortMessage(const Port& send_port, const Port& reply_port, const std::vector<Object>& components) : PortMessage(Adopt{cocoon::internal::retain([[::NSPortMessage alloc] initWithSendPort:cocoon::internal::native<::NSPort>(send_port)
                                                                                                                                                                                              receivePort:cocoon::internal::native<::NSPort>(reply_port)
                                                                                                                                                                                               components:cocoon::internal::to_array(components, [](const Object& e) -> id
                                                                                                                                                                                                                                     {
                                                                                                                                                                                                                                         return cocoon::internal::native_id(e);
                                                                                                                                                                                                                                     })])})
    {
    }

    PortMessage::PortMessage() : PortMessage(Adopt{cocoon::internal::retain([[::NSPortMessage alloc] init])})
    {
    }

    PortMessage::PortMessage(std::nullptr_t) : Object(nullptr)
    {
    }

    PortMessage::PortMessage(Adopt adopt) : Object(adopt)
    {
    }

    bool PortMessage::send_before_date(const Date& date) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPortMessage>(this) sendBeforeDate:cocoon::internal::native<::NSDate>(date)]);
    }

    std::vector<Object> PortMessage::components() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSPortMessage>(this) components], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    unsigned int PortMessage::msgid() const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSPortMessage>(this) msgid]);
    }

    void PortMessage::set_msgid(unsigned int value) const
    {
        [cocoon::internal::ns<::NSPortMessage>(this) setMsgid:static_cast<::uint32_t>(value)];
    }

    Port PortMessage::receive_port() const
    {
        return cocoon::internal::wrap<Port>([cocoon::internal::ns<::NSPortMessage>(this) receivePort]);
    }

    Port PortMessage::send_port() const
    {
        return cocoon::internal::wrap<Port>([cocoon::internal::ns<::NSPortMessage>(this) sendPort]);
    }
}
