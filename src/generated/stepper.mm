#include "generated/stepper.h"
#include "internal.h"

namespace cocoon
{
    Stepper::Stepper() : Stepper(Adopt{cocoon::internal::retain([[NSStepper alloc] init])})
    {
        Stepper::bind_action_(handle());
    }

    Stepper::Stepper(std::nullptr_t) : Control(nullptr)
    {
    }

    Stepper::Stepper(Adopt adopt) : Control(adopt)
    {
    }

    bool Stepper::autorepeat() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSStepper>(this) autorepeat]);
    }

    void Stepper::set_autorepeat(bool value) const
    {
        [cocoon::internal::ns<::NSStepper>(this) setAutorepeat:static_cast<::BOOL>(value)];
    }

    double Stepper::increment() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSStepper>(this) increment]);
    }

    void Stepper::set_increment(double value) const
    {
        [cocoon::internal::ns<::NSStepper>(this) setIncrement:static_cast<double>(value)];
    }

    double Stepper::max_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSStepper>(this) maxValue]);
    }

    void Stepper::set_max_value(double value) const
    {
        [cocoon::internal::ns<::NSStepper>(this) setMaxValue:static_cast<double>(value)];
    }

    double Stepper::min_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSStepper>(this) minValue]);
    }

    void Stepper::set_min_value(double value) const
    {
        [cocoon::internal::ns<::NSStepper>(this) setMinValue:static_cast<double>(value)];
    }

    bool Stepper::value_wraps() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSStepper>(this) valueWraps]);
    }

    void Stepper::set_value_wraps(bool value) const
    {
        [cocoon::internal::ns<::NSStepper>(this) setValueWraps:static_cast<::BOOL>(value)];
    }

    double Stepper::value() const
    {
        return cocoon::internal::ns<NSStepper>(this).doubleValue;
    }

    void Stepper::set_value(double value) const
    {
        cocoon::internal::ns<NSStepper>(this).doubleValue = value;
    }

    void Stepper::bind_action_(void* native)
    {
        id host = (__bridge id)native;
        cocoon::internal::bind_action(host, host, [](id host, id sender)
                        {
                            cocoon::Signal<cocoon::Stepper, void(double)>::emit((__bridge void*)host, "value_changed", [(NSStepper*)sender doubleValue]);
                        });
    }
}
