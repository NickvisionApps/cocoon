#include "generated/xpc_interface.h"
#include "internal.h"

namespace cocoon
{
    XPCInterface::XPCInterface() : XPCInterface(Adopt{cocoon::internal::retain([[::NSXPCInterface alloc] init])})
    {
    }

    XPCInterface::XPCInterface(std::nullptr_t) : Object(nullptr)
    {
    }

    XPCInterface::XPCInterface(Adopt adopt) : Object(adopt)
    {
    }

    xpc_type_t XPCInterface::xpc_type_for_selector(const std::string& sel, std::uint64_t arg, bool of_reply) const
    {
        return cocoon::internal::wrap_cf<xpc_type_t>((const void*)([cocoon::internal::ns<::NSXPCInterface>(this) XPCTypeForSelector:NSSelectorFromString(cocoon::internal::to(sel)) argumentIndex:static_cast<::NSUInteger>(arg) ofReply:static_cast<::BOOL>(of_reply)]));
    }

    std::vector<std::string> XPCInterface::classes_for_selector(const std::string& sel, std::uint64_t arg, bool of_reply) const
    {
        return cocoon::internal::from_array<std::string>([[cocoon::internal::ns<::NSXPCInterface>(this) classesForSelector:NSSelectorFromString(cocoon::internal::to(sel)) argumentIndex:static_cast<::NSUInteger>(arg) ofReply:static_cast<::BOOL>(of_reply)] allObjects], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from(NSStringFromClass(e));
                                           });
    }

    XPCInterface XPCInterface::interface_for_selector(const std::string& sel, std::uint64_t arg, bool of_reply) const
    {
        return cocoon::internal::wrap<XPCInterface>([cocoon::internal::ns<::NSXPCInterface>(this) interfaceForSelector:NSSelectorFromString(cocoon::internal::to(sel)) argumentIndex:static_cast<::NSUInteger>(arg) ofReply:static_cast<::BOOL>(of_reply)]);
    }

    XPCInterface XPCInterface::interface_with_protocol(const Object& protocol)
    {
        return cocoon::internal::wrap<XPCInterface>([::NSXPCInterface interfaceWithProtocol:cocoon::internal::native_id(protocol)]);
    }

    void XPCInterface::set_classes(const std::vector<std::string>& classes, const std::string& sel, std::uint64_t arg, bool of_reply) const
    {
        [cocoon::internal::ns<::NSXPCInterface>(this) setClasses:[NSSet setWithArray:cocoon::internal::to_array(classes, [](const std::string& e) -> id
                                                                                    {
                                                                                        return NSClassFromString(cocoon::internal::to(e));
                                                                                    })]
                                       forSelector:NSSelectorFromString(cocoon::internal::to(sel))
                                     argumentIndex:static_cast<::NSUInteger>(arg)
                                           ofReply:static_cast<::BOOL>(of_reply)];
    }

    void XPCInterface::set_interface(const XPCInterface& ifc, const std::string& sel, std::uint64_t arg, bool of_reply) const
    {
        [cocoon::internal::ns<::NSXPCInterface>(this) setInterface:cocoon::internal::native<::NSXPCInterface>(ifc) forSelector:NSSelectorFromString(cocoon::internal::to(sel)) argumentIndex:static_cast<::NSUInteger>(arg) ofReply:static_cast<::BOOL>(of_reply)];
    }

    void XPCInterface::set_xpc_type(const xpc_type_t& type, const std::string& sel, std::uint64_t arg, bool of_reply) const
    {
        [cocoon::internal::ns<::NSXPCInterface>(this) setXPCType:((::xpc_type_t)(type).handle()) forSelector:NSSelectorFromString(cocoon::internal::to(sel)) argumentIndex:static_cast<::NSUInteger>(arg) ofReply:static_cast<::BOOL>(of_reply)];
    }

    Object XPCInterface::protocol() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSXPCInterface>(this) protocol]);
    }

    void XPCInterface::set_protocol(const Object& value) const
    {
        [cocoon::internal::ns<::NSXPCInterface>(this) setProtocol:cocoon::internal::native_id(value)];
    }
}
