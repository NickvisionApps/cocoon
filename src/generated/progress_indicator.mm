#include "generated/progress_indicator.h"
#include "internal.h"

namespace cocoon
{
    ProgressIndicator::ProgressIndicator() : ProgressIndicator(Adopt{cocoon::internal::retain([[NSProgressIndicator alloc] init])})
    {
    }

    ProgressIndicator::ProgressIndicator(std::nullptr_t) : View(nullptr)
    {
    }

    ProgressIndicator::ProgressIndicator(Adopt adopt) : View(adopt)
    {
    }

    void ProgressIndicator::increment_by(double delta) const
    {
        [cocoon::internal::ns<::NSProgressIndicator>(this) incrementBy:static_cast<double>(delta)];
    }

    void ProgressIndicator::size_to_fit() const
    {
        [cocoon::internal::ns<::NSProgressIndicator>(this) sizeToFit];
    }

    void ProgressIndicator::start_animation(const Object& sender) const
    {
        [cocoon::internal::ns<::NSProgressIndicator>(this) startAnimation:cocoon::internal::native_id(sender)];
    }

    void ProgressIndicator::stop_animation(const Object& sender) const
    {
        [cocoon::internal::ns<::NSProgressIndicator>(this) stopAnimation:cocoon::internal::native_id(sender)];
    }

    ControlSize ProgressIndicator::control_size() const
    {
        return static_cast<ControlSize>([cocoon::internal::ns<::NSProgressIndicator>(this) controlSize]);
    }

    void ProgressIndicator::set_control_size(ControlSize value) const
    {
        [cocoon::internal::ns<::NSProgressIndicator>(this) setControlSize:static_cast<::NSControlSize>(value)];
    }

    bool ProgressIndicator::is_displayed_when_stopped() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSProgressIndicator>(this) isDisplayedWhenStopped]);
    }

    void ProgressIndicator::set_displayed_when_stopped(bool value) const
    {
        [cocoon::internal::ns<::NSProgressIndicator>(this) setDisplayedWhenStopped:static_cast<::BOOL>(value)];
    }

    double ProgressIndicator::double_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSProgressIndicator>(this) doubleValue]);
    }

    void ProgressIndicator::set_double_value(double value) const
    {
        [cocoon::internal::ns<::NSProgressIndicator>(this) setDoubleValue:static_cast<double>(value)];
    }

    bool ProgressIndicator::is_indeterminate() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSProgressIndicator>(this) isIndeterminate]);
    }

    void ProgressIndicator::set_indeterminate(bool value) const
    {
        [cocoon::internal::ns<::NSProgressIndicator>(this) setIndeterminate:static_cast<::BOOL>(value)];
    }

    double ProgressIndicator::max_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSProgressIndicator>(this) maxValue]);
    }

    void ProgressIndicator::set_max_value(double value) const
    {
        [cocoon::internal::ns<::NSProgressIndicator>(this) setMaxValue:static_cast<double>(value)];
    }

    double ProgressIndicator::min_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSProgressIndicator>(this) minValue]);
    }

    void ProgressIndicator::set_min_value(double value) const
    {
        [cocoon::internal::ns<::NSProgressIndicator>(this) setMinValue:static_cast<double>(value)];
    }

    Progress ProgressIndicator::observed_progress() const
    {
        return cocoon::internal::wrap<Progress>([cocoon::internal::ns<::NSProgressIndicator>(this) observedProgress]);
    }

    void ProgressIndicator::set_observed_progress(const Progress& value) const
    {
        [cocoon::internal::ns<::NSProgressIndicator>(this) setObservedProgress:cocoon::internal::native<::NSProgress>(value)];
    }

    ProgressIndicatorStyle ProgressIndicator::style() const
    {
        return static_cast<ProgressIndicatorStyle>([cocoon::internal::ns<::NSProgressIndicator>(this) style]);
    }

    void ProgressIndicator::set_style(ProgressIndicatorStyle value) const
    {
        [cocoon::internal::ns<::NSProgressIndicator>(this) setStyle:static_cast<::NSProgressIndicatorStyle>(value)];
    }

    bool ProgressIndicator::uses_threaded_animation() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSProgressIndicator>(this) usesThreadedAnimation]);
    }

    void ProgressIndicator::set_uses_threaded_animation(bool value) const
    {
        [cocoon::internal::ns<::NSProgressIndicator>(this) setUsesThreadedAnimation:static_cast<::BOOL>(value)];
    }

    void ProgressIndicator::start() const
    {
        [cocoon::internal::ns<NSProgressIndicator>(this) startAnimation:nil];
    }

    void ProgressIndicator::stop() const
    {
        [cocoon::internal::ns<NSProgressIndicator>(this) stopAnimation:nil];
    }
}
