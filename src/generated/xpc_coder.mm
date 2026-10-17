#include "generated/xpc_coder.h"
#include "internal.h"

namespace cocoon
{
    XPCCoder::XPCCoder() : XPCCoder(Adopt{cocoon::internal::retain([[::NSXPCCoder alloc] init])})
    {
    }

    XPCCoder::XPCCoder(std::nullptr_t) : Coder(nullptr)
    {
    }

    XPCCoder::XPCCoder(Adopt adopt) : Coder(adopt)
    {
    }

    Object XPCCoder::decode_xpc_object_of_type(const xpc_type_t& type, const std::string& key) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSXPCCoder>(this) decodeXPCObjectOfType:((::xpc_type_t)(type).handle()) forKey:cocoon::internal::to(key)]);
    }

    void XPCCoder::encode_xpc_object(const Object& xpc_object, const std::string& key) const
    {
        [cocoon::internal::ns<::NSXPCCoder>(this) encodeXPCObject:cocoon::internal::native_id(xpc_object) forKey:cocoon::internal::to(key)];
    }

    XPCConnection XPCCoder::connection() const
    {
        return cocoon::internal::wrap<XPCConnection>([cocoon::internal::ns<::NSXPCCoder>(this) connection]);
    }

    Object XPCCoder::user_info() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSXPCCoder>(this) userInfo]);
    }

    void XPCCoder::set_user_info(const Object& value) const
    {
        [cocoon::internal::ns<::NSXPCCoder>(this) setUserInfo:cocoon::internal::native_id(value)];
    }
}
