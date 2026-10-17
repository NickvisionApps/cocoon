#include "generated/distant_object_request.h"
#include "internal.h"

namespace cocoon
{
    DistantObjectRequest::DistantObjectRequest() : DistantObjectRequest(Adopt{cocoon::internal::retain([[::NSDistantObjectRequest alloc] init])})
    {
    }

    DistantObjectRequest::DistantObjectRequest(std::nullptr_t) : Object(nullptr)
    {
    }

    DistantObjectRequest::DistantObjectRequest(Adopt adopt) : Object(adopt)
    {
    }

    void DistantObjectRequest::reply_with_exception(const Exception& exception) const
    {
        [cocoon::internal::ns<::NSDistantObjectRequest>(this) replyWithException:cocoon::internal::native<::NSException>(exception)];
    }

    Connection DistantObjectRequest::connection() const
    {
        return cocoon::internal::wrap<Connection>([cocoon::internal::ns<::NSDistantObjectRequest>(this) connection]);
    }

    Object DistantObjectRequest::conversation() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSDistantObjectRequest>(this) conversation]);
    }

    Invocation DistantObjectRequest::invocation() const
    {
        return cocoon::internal::wrap<Invocation>([cocoon::internal::ns<::NSDistantObjectRequest>(this) invocation]);
    }
}
