#include "generated/port_coder.h"
#include "internal.h"

namespace cocoon
{
    PortCoder::PortCoder() : PortCoder(Adopt{cocoon::internal::retain([[::NSPortCoder alloc] init])})
    {
    }

    PortCoder::PortCoder(std::nullptr_t) : Coder(nullptr)
    {
    }

    PortCoder::PortCoder(Adopt adopt) : Coder(adopt)
    {
    }

    Port PortCoder::decode_port_object() const
    {
        return cocoon::internal::wrap<Port>([cocoon::internal::ns<::NSPortCoder>(this) decodePortObject]);
    }

    void PortCoder::encode_port_object(const Port& aport) const
    {
        [cocoon::internal::ns<::NSPortCoder>(this) encodePortObject:cocoon::internal::native<::NSPort>(aport)];
    }

    bool PortCoder::is_bycopy() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPortCoder>(this) isBycopy]);
    }

    bool PortCoder::is_byref() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPortCoder>(this) isByref]);
    }
}
