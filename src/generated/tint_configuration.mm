#include "generated/tint_configuration.h"
#include "internal.h"

namespace cocoon
{
    TintConfiguration::TintConfiguration() : TintConfiguration(Adopt{cocoon::internal::retain([[::NSTintConfiguration alloc] init])})
    {
    }

    TintConfiguration::TintConfiguration(std::nullptr_t) : Object(nullptr)
    {
    }

    TintConfiguration::TintConfiguration(Adopt adopt) : Object(adopt)
    {
    }

    TintConfiguration TintConfiguration::tint_configuration_with_fixed_color(const Color& color)
    {
        return cocoon::internal::wrap<TintConfiguration>([::NSTintConfiguration tintConfigurationWithFixedColor:cocoon::internal::native<::NSColor>(color)]);
    }

    TintConfiguration TintConfiguration::tint_configuration_with_preferred_color(const Color& color)
    {
        return cocoon::internal::wrap<TintConfiguration>([::NSTintConfiguration tintConfigurationWithPreferredColor:cocoon::internal::native<::NSColor>(color)]);
    }

    bool TintConfiguration::adapts_to_user_accent_color() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTintConfiguration>(this) adaptsToUserAccentColor]);
    }

    Color TintConfiguration::base_tint_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSTintConfiguration>(this) baseTintColor]);
    }

    TintConfiguration TintConfiguration::default_tint_configuration()
    {
        return cocoon::internal::wrap<TintConfiguration>([::NSTintConfiguration defaultTintConfiguration]);
    }

    Color TintConfiguration::equivalent_content_tint_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSTintConfiguration>(this) equivalentContentTintColor]);
    }

    TintConfiguration TintConfiguration::monochrome_tint_configuration()
    {
        return cocoon::internal::wrap<TintConfiguration>([::NSTintConfiguration monochromeTintConfiguration]);
    }
}
