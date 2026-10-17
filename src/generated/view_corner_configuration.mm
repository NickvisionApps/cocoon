#include "generated/view_corner_configuration.h"
#include "internal.h"

#ifdef COCOON_MACOS_27
namespace cocoon
{
    ViewCornerConfiguration::ViewCornerConfiguration() : Object(nullptr)
    {
    }

    ViewCornerConfiguration::ViewCornerConfiguration(std::nullptr_t) : Object(nullptr)
    {
    }

    ViewCornerConfiguration::ViewCornerConfiguration(Adopt adopt) : Object(adopt)
    {
    }

#ifdef COCOON_MACOS_27
    ViewCornerConfiguration ViewCornerConfiguration::capsule_corner_configuration_with_maximum_radius(double maximum_radius)
    {
        return cocoon::internal::wrap<ViewCornerConfiguration>([::NSViewCornerConfiguration capsuleCornerConfigurationWithMaximumRadius:static_cast<::CGFloat>(maximum_radius)]);
    }

#endif

#ifdef COCOON_MACOS_27
    ViewCornerConfiguration ViewCornerConfiguration::configuration_with_radius(const ViewCornerRadius& radius)
    {
        return cocoon::internal::wrap<ViewCornerConfiguration>([::NSViewCornerConfiguration configurationWithRadius:cocoon::internal::native<::NSViewCornerRadius>(radius)]);
    }

#endif

#ifdef COCOON_MACOS_27
    ViewCornerConfiguration ViewCornerConfiguration::configuration_with_top_left_radius(const ViewCornerRadius& top_left_radius, const ViewCornerRadius& top_right_radius, const ViewCornerRadius& bottom_left_radius, const ViewCornerRadius& bottom_right_radius)
    {
        return cocoon::internal::wrap<ViewCornerConfiguration>([::NSViewCornerConfiguration configurationWithTopLeftRadius:cocoon::internal::native<::NSViewCornerRadius>(top_left_radius) topRightRadius:cocoon::internal::native<::NSViewCornerRadius>(top_right_radius) bottomLeftRadius:cocoon::internal::native<::NSViewCornerRadius>(bottom_left_radius) bottomRightRadius:cocoon::internal::native<::NSViewCornerRadius>(bottom_right_radius)]);
    }

#endif

#ifdef COCOON_MACOS_27
    ViewCornerConfiguration ViewCornerConfiguration::configuration_with_uniform_bottom_radius(const ViewCornerRadius& bottom_radius, const ViewCornerRadius& top_left_radius, const ViewCornerRadius& top_right_radius)
    {
        return cocoon::internal::wrap<ViewCornerConfiguration>([::NSViewCornerConfiguration configurationWithUniformBottomRadius:cocoon::internal::native<::NSViewCornerRadius>(bottom_radius) topLeftRadius:cocoon::internal::native<::NSViewCornerRadius>(top_left_radius) topRightRadius:cocoon::internal::native<::NSViewCornerRadius>(top_right_radius)]);
    }

#endif

#ifdef COCOON_MACOS_27
    ViewCornerConfiguration ViewCornerConfiguration::configuration_with_uniform_left_radius(const ViewCornerRadius& left_radius, const ViewCornerRadius& right_radius)
    {
        return cocoon::internal::wrap<ViewCornerConfiguration>([::NSViewCornerConfiguration configurationWithUniformLeftRadius:cocoon::internal::native<::NSViewCornerRadius>(left_radius) rightRadius:cocoon::internal::native<::NSViewCornerRadius>(right_radius)]);
    }

#endif

#ifdef COCOON_MACOS_27
    ViewCornerConfiguration ViewCornerConfiguration::configuration_with_uniform_left_radius(const ViewCornerRadius& left_radius, const ViewCornerRadius& top_right_radius, const ViewCornerRadius& bottom_right_radius)
    {
        return cocoon::internal::wrap<ViewCornerConfiguration>([::NSViewCornerConfiguration configurationWithUniformLeftRadius:cocoon::internal::native<::NSViewCornerRadius>(left_radius) topRightRadius:cocoon::internal::native<::NSViewCornerRadius>(top_right_radius) bottomRightRadius:cocoon::internal::native<::NSViewCornerRadius>(bottom_right_radius)]);
    }

#endif

#ifdef COCOON_MACOS_27
    ViewCornerConfiguration ViewCornerConfiguration::configuration_with_uniform_radius(const ViewCornerRadius& radius)
    {
        return cocoon::internal::wrap<ViewCornerConfiguration>([::NSViewCornerConfiguration configurationWithUniformRadius:cocoon::internal::native<::NSViewCornerRadius>(radius)]);
    }

#endif

#ifdef COCOON_MACOS_27
    ViewCornerConfiguration ViewCornerConfiguration::configuration_with_uniform_radius(const ViewCornerRadius& radius, const ViewCornerRadius& top_left_radius, const ViewCornerRadius& top_right_radius, const ViewCornerRadius& bottom_left_radius, const ViewCornerRadius& bottom_right_radius)
    {
        return cocoon::internal::wrap<ViewCornerConfiguration>([::NSViewCornerConfiguration configurationWithUniformRadius:cocoon::internal::native<::NSViewCornerRadius>(radius) topLeftRadius:cocoon::internal::native<::NSViewCornerRadius>(top_left_radius) topRightRadius:cocoon::internal::native<::NSViewCornerRadius>(top_right_radius) bottomLeftRadius:cocoon::internal::native<::NSViewCornerRadius>(bottom_left_radius) bottomRightRadius:cocoon::internal::native<::NSViewCornerRadius>(bottom_right_radius)]);
    }

#endif

#ifdef COCOON_MACOS_27
    ViewCornerConfiguration ViewCornerConfiguration::configuration_with_uniform_right_radius(const ViewCornerRadius& right_radius, const ViewCornerRadius& top_left_radius, const ViewCornerRadius& bottom_left_radius)
    {
        return cocoon::internal::wrap<ViewCornerConfiguration>([::NSViewCornerConfiguration configurationWithUniformRightRadius:cocoon::internal::native<::NSViewCornerRadius>(right_radius) topLeftRadius:cocoon::internal::native<::NSViewCornerRadius>(top_left_radius) bottomLeftRadius:cocoon::internal::native<::NSViewCornerRadius>(bottom_left_radius)]);
    }

#endif

#ifdef COCOON_MACOS_27
    ViewCornerConfiguration ViewCornerConfiguration::configuration_with_uniform_top_radius(const ViewCornerRadius& top_radius, const ViewCornerRadius& bottom_left_radius, const ViewCornerRadius& bottom_right_radius)
    {
        return cocoon::internal::wrap<ViewCornerConfiguration>([::NSViewCornerConfiguration configurationWithUniformTopRadius:cocoon::internal::native<::NSViewCornerRadius>(top_radius) bottomLeftRadius:cocoon::internal::native<::NSViewCornerRadius>(bottom_left_radius) bottomRightRadius:cocoon::internal::native<::NSViewCornerRadius>(bottom_right_radius)]);
    }

#endif

#ifdef COCOON_MACOS_27
    ViewCornerConfiguration ViewCornerConfiguration::configuration_with_uniform_top_radius(const ViewCornerRadius& top_radius, const ViewCornerRadius& bottom_radius)
    {
        return cocoon::internal::wrap<ViewCornerConfiguration>([::NSViewCornerConfiguration configurationWithUniformTopRadius:cocoon::internal::native<::NSViewCornerRadius>(top_radius) bottomRadius:cocoon::internal::native<::NSViewCornerRadius>(bottom_radius)]);
    }

#endif

#ifdef COCOON_MACOS_27
    ViewCornerConfiguration ViewCornerConfiguration::capsule_corner_configuration()
    {
        return cocoon::internal::wrap<ViewCornerConfiguration>([::NSViewCornerConfiguration capsuleCornerConfiguration]);
    }

#endif
}

#endif
