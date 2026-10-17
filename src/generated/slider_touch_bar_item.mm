#include "generated/slider_touch_bar_item.h"
#include "internal.h"

namespace cocoon
{
    SliderTouchBarItem::SliderTouchBarItem() : TouchBarItem(nullptr)
    {
    }

    SliderTouchBarItem::SliderTouchBarItem(std::nullptr_t) : TouchBarItem(nullptr)
    {
    }

    SliderTouchBarItem::SliderTouchBarItem(Adopt adopt) : TouchBarItem(adopt)
    {
    }

    std::string SliderTouchBarItem::action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSSliderTouchBarItem>(this) action]));
    }

    void SliderTouchBarItem::set_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSSliderTouchBarItem>(this) setAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    std::string SliderTouchBarItem::customization_label() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSliderTouchBarItem>(this) customizationLabel]);
    }

    void SliderTouchBarItem::set_customization_label(const std::string& value) const
    {
        [cocoon::internal::ns<::NSSliderTouchBarItem>(this) setCustomizationLabel:cocoon::internal::to(value)];
    }

    double SliderTouchBarItem::double_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSliderTouchBarItem>(this) doubleValue]);
    }

    void SliderTouchBarItem::set_double_value(double value) const
    {
        [cocoon::internal::ns<::NSSliderTouchBarItem>(this) setDoubleValue:static_cast<double>(value)];
    }

    std::string SliderTouchBarItem::label() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSliderTouchBarItem>(this) label]);
    }

    void SliderTouchBarItem::set_label(const std::string& value) const
    {
        [cocoon::internal::ns<::NSSliderTouchBarItem>(this) setLabel:cocoon::internal::to(value)];
    }

    double SliderTouchBarItem::maximum_slider_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSliderTouchBarItem>(this) maximumSliderWidth]);
    }

    void SliderTouchBarItem::set_maximum_slider_width(double value) const
    {
        [cocoon::internal::ns<::NSSliderTouchBarItem>(this) setMaximumSliderWidth:static_cast<::CGFloat>(value)];
    }

    SliderAccessory SliderTouchBarItem::maximum_value_accessory() const
    {
        return cocoon::internal::wrap<SliderAccessory>([cocoon::internal::ns<::NSSliderTouchBarItem>(this) maximumValueAccessory]);
    }

    void SliderTouchBarItem::set_maximum_value_accessory(const SliderAccessory& value) const
    {
        [cocoon::internal::ns<::NSSliderTouchBarItem>(this) setMaximumValueAccessory:cocoon::internal::native<::NSSliderAccessory>(value)];
    }

    double SliderTouchBarItem::minimum_slider_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSliderTouchBarItem>(this) minimumSliderWidth]);
    }

    void SliderTouchBarItem::set_minimum_slider_width(double value) const
    {
        [cocoon::internal::ns<::NSSliderTouchBarItem>(this) setMinimumSliderWidth:static_cast<::CGFloat>(value)];
    }

    SliderAccessory SliderTouchBarItem::minimum_value_accessory() const
    {
        return cocoon::internal::wrap<SliderAccessory>([cocoon::internal::ns<::NSSliderTouchBarItem>(this) minimumValueAccessory]);
    }

    void SliderTouchBarItem::set_minimum_value_accessory(const SliderAccessory& value) const
    {
        [cocoon::internal::ns<::NSSliderTouchBarItem>(this) setMinimumValueAccessory:cocoon::internal::native<::NSSliderAccessory>(value)];
    }

    Slider SliderTouchBarItem::slider() const
    {
        return cocoon::internal::wrap<Slider>([cocoon::internal::ns<::NSSliderTouchBarItem>(this) slider]);
    }

    void SliderTouchBarItem::set_slider(const Slider& value) const
    {
        [cocoon::internal::ns<::NSSliderTouchBarItem>(this) setSlider:cocoon::internal::native<::NSSlider>(value)];
    }

    Object SliderTouchBarItem::target() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSSliderTouchBarItem>(this) target]);
    }

    void SliderTouchBarItem::set_target(const Object& value) const
    {
        [cocoon::internal::ns<::NSSliderTouchBarItem>(this) setTarget:cocoon::internal::native_id(value)];
    }

    double SliderTouchBarItem::value_accessory_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSliderTouchBarItem>(this) valueAccessoryWidth]);
    }

    void SliderTouchBarItem::set_value_accessory_width(double value) const
    {
        [cocoon::internal::ns<::NSSliderTouchBarItem>(this) setValueAccessoryWidth:static_cast<::NSSliderAccessoryWidth>(value)];
    }

    View SliderTouchBarItem::view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSSliderTouchBarItem>(this) view]);
    }
}
