#include "generated/url_session_web_socket_message.h"
#include "internal.h"

namespace cocoon
{
    URLSessionWebSocketMessage::URLSessionWebSocketMessage(const std::vector<std::uint8_t>& data) : URLSessionWebSocketMessage(Adopt{cocoon::internal::retain([[::NSURLSessionWebSocketMessage alloc] initWithData:cocoon::internal::to_data(data)])})
    {
    }

    URLSessionWebSocketMessage::URLSessionWebSocketMessage(const std::string& string) : URLSessionWebSocketMessage(Adopt{cocoon::internal::retain([[::NSURLSessionWebSocketMessage alloc] initWithString:cocoon::internal::to(string)])})
    {
    }

    URLSessionWebSocketMessage::URLSessionWebSocketMessage() : Object(nullptr)
    {
    }

    URLSessionWebSocketMessage::URLSessionWebSocketMessage(std::nullptr_t) : Object(nullptr)
    {
    }

    URLSessionWebSocketMessage::URLSessionWebSocketMessage(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<std::uint8_t> URLSessionWebSocketMessage::data() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSURLSessionWebSocketMessage>(this) data]);
    }

    std::string URLSessionWebSocketMessage::string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLSessionWebSocketMessage>(this) string]);
    }

    URLSessionWebSocketMessageType URLSessionWebSocketMessage::type() const
    {
        return static_cast<URLSessionWebSocketMessageType>([cocoon::internal::ns<::NSURLSessionWebSocketMessage>(this) type]);
    }
}
