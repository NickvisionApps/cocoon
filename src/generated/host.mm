#include "generated/host.h"
#include "internal.h"

namespace cocoon
{
    Host::Host(const std::string& address) : Host(Adopt{cocoon::internal::retain([::NSHost hostWithAddress:cocoon::internal::to(address)])})
    {
    }

    Host::Host() : Host(Adopt{cocoon::internal::retain([[::NSHost alloc] init])})
    {
    }

    Host::Host(std::nullptr_t) : Object(nullptr)
    {
    }

    Host::Host(Adopt adopt) : Object(adopt)
    {
    }

    Host Host::current_host()
    {
        return cocoon::internal::wrap<Host>([::NSHost currentHost]);
    }

    bool Host::is_equal_to_host(const Host& a_host) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSHost>(this) isEqualToHost:cocoon::internal::native<::NSHost>(a_host)]);
    }

    std::string Host::address() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSHost>(this) address]);
    }

    std::vector<std::string> Host::addresses() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSHost>(this) addresses], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::string Host::localized_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSHost>(this) localizedName]);
    }

    std::string Host::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSHost>(this) name]);
    }

    std::vector<std::string> Host::names() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSHost>(this) names], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }
}
