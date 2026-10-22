#include "generated/tint_configuration.h"
#include "internal.h"

namespace cocoon
{
    TintConfiguration::TintConfiguration(const Color& color) : TintConfiguration(Adopt{cocoon::internal::retain([::NSTintConfiguration tintConfigurationWithFixedColor:cocoon::internal::native<::NSColor>(color)])})
    {
    }

    TintConfiguration::TintConfiguration() : TintConfiguration(Adopt{cocoon::internal::retain([[::NSTintConfiguration alloc] init])})
    {
    }

    TintConfiguration::TintConfiguration(std::nullptr_t) : Object(nullptr)
    {
    }

    TintConfiguration::TintConfiguration(Adopt adopt) : Object(adopt)
    {
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
