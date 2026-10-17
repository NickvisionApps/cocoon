#include "generated/stepper_cell.h"
#include "internal.h"

namespace cocoon
{
    StepperCell::StepperCell() : StepperCell(Adopt{cocoon::internal::retain([[::NSStepperCell alloc] init])})
    {
    }

    StepperCell::StepperCell(std::nullptr_t) : ActionCell(nullptr)
    {
    }

    StepperCell::StepperCell(Adopt adopt) : ActionCell(adopt)
    {
    }

    bool StepperCell::autorepeat() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSStepperCell>(this) autorepeat]);
    }

    void StepperCell::set_autorepeat(bool value) const
    {
        [cocoon::internal::ns<::NSStepperCell>(this) setAutorepeat:static_cast<::BOOL>(value)];
    }

    double StepperCell::increment() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSStepperCell>(this) increment]);
    }

    void StepperCell::set_increment(double value) const
    {
        [cocoon::internal::ns<::NSStepperCell>(this) setIncrement:static_cast<double>(value)];
    }

    double StepperCell::max_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSStepperCell>(this) maxValue]);
    }

    void StepperCell::set_max_value(double value) const
    {
        [cocoon::internal::ns<::NSStepperCell>(this) setMaxValue:static_cast<double>(value)];
    }

    double StepperCell::min_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSStepperCell>(this) minValue]);
    }

    void StepperCell::set_min_value(double value) const
    {
        [cocoon::internal::ns<::NSStepperCell>(this) setMinValue:static_cast<double>(value)];
    }

    bool StepperCell::value_wraps() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSStepperCell>(this) valueWraps]);
    }

    void StepperCell::set_value_wraps(bool value) const
    {
        [cocoon::internal::ns<::NSStepperCell>(this) setValueWraps:static_cast<::BOOL>(value)];
    }
}
