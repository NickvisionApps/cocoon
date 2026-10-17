#include "generated/user_interface_compression_options.h"
#include "internal.h"

namespace cocoon
{
    UserInterfaceCompressionOptions::UserInterfaceCompressionOptions(const std::vector<UserInterfaceCompressionOptions>& options) : UserInterfaceCompressionOptions(Adopt{cocoon::internal::retain([[::NSUserInterfaceCompressionOptions alloc] initWithCompressionOptions:[NSSet setWithArray:cocoon::internal::to_array(options, [](const UserInterfaceCompressionOptions& e) -> id
                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                              return cocoon::internal::native<::NSUserInterfaceCompressionOptions>(e);
                                                                                                                                                                                                                                                                                                                          })]])})
    {
    }

    UserInterfaceCompressionOptions::UserInterfaceCompressionOptions(const std::string& identifier) : UserInterfaceCompressionOptions(Adopt{cocoon::internal::retain([[::NSUserInterfaceCompressionOptions alloc] initWithIdentifier:cocoon::internal::to(identifier)])})
    {
    }

    UserInterfaceCompressionOptions::UserInterfaceCompressionOptions() : UserInterfaceCompressionOptions(Adopt{cocoon::internal::retain([[::NSUserInterfaceCompressionOptions alloc] init])})
    {
    }

    UserInterfaceCompressionOptions::UserInterfaceCompressionOptions(std::nullptr_t) : Object(nullptr)
    {
    }

    UserInterfaceCompressionOptions::UserInterfaceCompressionOptions(Adopt adopt) : Object(adopt)
    {
    }

    bool UserInterfaceCompressionOptions::contains_options(const UserInterfaceCompressionOptions& options) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUserInterfaceCompressionOptions>(this) containsOptions:cocoon::internal::native<::NSUserInterfaceCompressionOptions>(options)]);
    }

    bool UserInterfaceCompressionOptions::intersects_options(const UserInterfaceCompressionOptions& options) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUserInterfaceCompressionOptions>(this) intersectsOptions:cocoon::internal::native<::NSUserInterfaceCompressionOptions>(options)]);
    }

    UserInterfaceCompressionOptions UserInterfaceCompressionOptions::options_by_adding_options(const UserInterfaceCompressionOptions& options) const
    {
        return cocoon::internal::wrap<UserInterfaceCompressionOptions>([cocoon::internal::ns<::NSUserInterfaceCompressionOptions>(this) optionsByAddingOptions:cocoon::internal::native<::NSUserInterfaceCompressionOptions>(options)]);
    }

    UserInterfaceCompressionOptions UserInterfaceCompressionOptions::options_by_removing_options(const UserInterfaceCompressionOptions& options) const
    {
        return cocoon::internal::wrap<UserInterfaceCompressionOptions>([cocoon::internal::ns<::NSUserInterfaceCompressionOptions>(this) optionsByRemovingOptions:cocoon::internal::native<::NSUserInterfaceCompressionOptions>(options)]);
    }

    UserInterfaceCompressionOptions UserInterfaceCompressionOptions::break_equal_widths_option()
    {
        return cocoon::internal::wrap<UserInterfaceCompressionOptions>([::NSUserInterfaceCompressionOptions breakEqualWidthsOption]);
    }

    bool UserInterfaceCompressionOptions::is_empty() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUserInterfaceCompressionOptions>(this) isEmpty]);
    }

    UserInterfaceCompressionOptions UserInterfaceCompressionOptions::hide_images_option()
    {
        return cocoon::internal::wrap<UserInterfaceCompressionOptions>([::NSUserInterfaceCompressionOptions hideImagesOption]);
    }

    UserInterfaceCompressionOptions UserInterfaceCompressionOptions::hide_text_option()
    {
        return cocoon::internal::wrap<UserInterfaceCompressionOptions>([::NSUserInterfaceCompressionOptions hideTextOption]);
    }

    UserInterfaceCompressionOptions UserInterfaceCompressionOptions::reduce_metrics_option()
    {
        return cocoon::internal::wrap<UserInterfaceCompressionOptions>([::NSUserInterfaceCompressionOptions reduceMetricsOption]);
    }

    UserInterfaceCompressionOptions UserInterfaceCompressionOptions::standard_options()
    {
        return cocoon::internal::wrap<UserInterfaceCompressionOptions>([::NSUserInterfaceCompressionOptions standardOptions]);
    }
}
