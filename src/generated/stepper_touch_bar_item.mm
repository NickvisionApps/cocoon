#include "generated/stepper_touch_bar_item.h"
#include "internal.h"

namespace cocoon
{
    StepperTouchBarItem::StepperTouchBarItem(const std::string& identifier, std::function<void(Rect, double)> drawing_handler) : StepperTouchBarItem(Adopt{cocoon::internal::retain([::NSStepperTouchBarItem stepperTouchBarItemWithIdentifier:cocoon::internal::to(identifier) drawingHandler:(drawing_handler ? (void (^)(::NSRect, double)) ^ void(::NSRect a82_0, double a82_1) { drawing_handler(cocoon::internal::from(a82_0), static_cast<double>(a82_1)); } : (void (^)(::NSRect, double))nil)])})
    {
    }

    StepperTouchBarItem::StepperTouchBarItem(const std::string& identifier, const Formatter& formatter) : StepperTouchBarItem(Adopt{cocoon::internal::retain([::NSStepperTouchBarItem stepperTouchBarItemWithIdentifier:cocoon::internal::to(identifier) formatter:cocoon::internal::native<::NSFormatter>(formatter)])})
    {
    }

    StepperTouchBarItem::StepperTouchBarItem() : TouchBarItem(nullptr)
    {
    }

    StepperTouchBarItem::StepperTouchBarItem(std::nullptr_t) : TouchBarItem(nullptr)
    {
    }

    StepperTouchBarItem::StepperTouchBarItem(Adopt adopt) : TouchBarItem(adopt)
    {
    }

    std::string StepperTouchBarItem::action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSStepperTouchBarItem>(this) action]));
    }

    void StepperTouchBarItem::set_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSStepperTouchBarItem>(this) setAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    std::string StepperTouchBarItem::customization_label() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSStepperTouchBarItem>(this) customizationLabel]);
    }

    void StepperTouchBarItem::set_customization_label(const std::string& value) const
    {
        [cocoon::internal::ns<::NSStepperTouchBarItem>(this) setCustomizationLabel:cocoon::internal::to(value)];
    }

    double StepperTouchBarItem::increment() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSStepperTouchBarItem>(this) increment]);
    }

    void StepperTouchBarItem::set_increment(double value) const
    {
        [cocoon::internal::ns<::NSStepperTouchBarItem>(this) setIncrement:static_cast<double>(value)];
    }

    double StepperTouchBarItem::max_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSStepperTouchBarItem>(this) maxValue]);
    }

    void StepperTouchBarItem::set_max_value(double value) const
    {
        [cocoon::internal::ns<::NSStepperTouchBarItem>(this) setMaxValue:static_cast<double>(value)];
    }

    double StepperTouchBarItem::min_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSStepperTouchBarItem>(this) minValue]);
    }

    void StepperTouchBarItem::set_min_value(double value) const
    {
        [cocoon::internal::ns<::NSStepperTouchBarItem>(this) setMinValue:static_cast<double>(value)];
    }

    Object StepperTouchBarItem::target() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSStepperTouchBarItem>(this) target]);
    }

    void StepperTouchBarItem::set_target(const Object& value) const
    {
        [cocoon::internal::ns<::NSStepperTouchBarItem>(this) setTarget:cocoon::internal::native_id(value)];
    }

    double StepperTouchBarItem::value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSStepperTouchBarItem>(this) value]);
    }

    void StepperTouchBarItem::set_value(double value) const
    {
        [cocoon::internal::ns<::NSStepperTouchBarItem>(this) setValue:static_cast<double>(value)];
    }
}
