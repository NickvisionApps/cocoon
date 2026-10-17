#include "generated/slider_accessory.h"
#include "internal.h"

namespace cocoon
{
    SliderAccessory::SliderAccessory() : SliderAccessory(Adopt{cocoon::internal::retain([[::NSSliderAccessory alloc] init])})
    {
    }

    SliderAccessory::SliderAccessory(std::nullptr_t) : Object(nullptr)
    {
    }

    SliderAccessory::SliderAccessory(Adopt adopt) : Object(adopt)
    {
    }

    SliderAccessory SliderAccessory::accessory_with_image(const Image& image)
    {
        return cocoon::internal::wrap<SliderAccessory>([::NSSliderAccessory accessoryWithImage:cocoon::internal::native<::NSImage>(image)]);
    }

    SliderAccessoryBehavior SliderAccessory::behavior() const
    {
        return cocoon::internal::wrap<SliderAccessoryBehavior>([cocoon::internal::ns<::NSSliderAccessory>(this) behavior]);
    }

    void SliderAccessory::set_behavior(const SliderAccessoryBehavior& value) const
    {
        [cocoon::internal::ns<::NSSliderAccessory>(this) setBehavior:cocoon::internal::native<::NSSliderAccessoryBehavior>(value)];
    }

    bool SliderAccessory::is_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSliderAccessory>(this) isEnabled]);
    }

    void SliderAccessory::set_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSSliderAccessory>(this) setEnabled:static_cast<::BOOL>(value)];
    }
}
