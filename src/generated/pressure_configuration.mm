#include "generated/pressure_configuration.h"
#include "internal.h"

namespace cocoon
{
    PressureConfiguration::PressureConfiguration(PressureBehavior pressure_behavior) : PressureConfiguration(Adopt{cocoon::internal::retain([[::NSPressureConfiguration alloc] initWithPressureBehavior:static_cast<::NSPressureBehavior>(pressure_behavior)])})
    {
    }

    PressureConfiguration::PressureConfiguration() : PressureConfiguration(Adopt{cocoon::internal::retain([[::NSPressureConfiguration alloc] init])})
    {
    }

    PressureConfiguration::PressureConfiguration(std::nullptr_t) : Object(nullptr)
    {
    }

    PressureConfiguration::PressureConfiguration(Adopt adopt) : Object(adopt)
    {
    }

    void PressureConfiguration::set() const
    {
        [cocoon::internal::ns<::NSPressureConfiguration>(this) set];
    }

    PressureBehavior PressureConfiguration::pressure_behavior() const
    {
        return static_cast<PressureBehavior>([cocoon::internal::ns<::NSPressureConfiguration>(this) pressureBehavior]);
    }
}
