#include "generated/slider_accessory_behavior.h"
#include "internal.h"

namespace cocoon
{
    SliderAccessoryBehavior::SliderAccessoryBehavior() : SliderAccessoryBehavior(Adopt{cocoon::internal::retain([[::NSSliderAccessoryBehavior alloc] init])})
    {
    }

    SliderAccessoryBehavior::SliderAccessoryBehavior(std::nullptr_t) : Object(nullptr)
    {
    }

    SliderAccessoryBehavior::SliderAccessoryBehavior(Adopt adopt) : Object(adopt)
    {
    }

    SliderAccessoryBehavior SliderAccessoryBehavior::behavior_with_handler(std::function<void(SliderAccessory)> handler)
    {
        return cocoon::internal::wrap<SliderAccessoryBehavior>([::NSSliderAccessoryBehavior behaviorWithHandler:(handler ? (void (^)(::NSSliderAccessory*)) ^ void(::NSSliderAccessory * a78_0) { handler(cocoon::internal::wrap<SliderAccessory>(a78_0)); } : (void (^)(::NSSliderAccessory*))nil)]);
    }

    SliderAccessoryBehavior SliderAccessoryBehavior::behavior_with_target(const Object& target, const std::string& action)
    {
        return cocoon::internal::wrap<SliderAccessoryBehavior>([::NSSliderAccessoryBehavior behaviorWithTarget:cocoon::internal::native_id(target) action:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    void SliderAccessoryBehavior::handle_action(const SliderAccessory& sender) const
    {
        [cocoon::internal::ns<::NSSliderAccessoryBehavior>(this) handleAction:cocoon::internal::native<::NSSliderAccessory>(sender)];
    }

    SliderAccessoryBehavior SliderAccessoryBehavior::automatic_behavior()
    {
        return cocoon::internal::wrap<SliderAccessoryBehavior>([::NSSliderAccessoryBehavior automaticBehavior]);
    }

    SliderAccessoryBehavior SliderAccessoryBehavior::value_reset_behavior()
    {
        return cocoon::internal::wrap<SliderAccessoryBehavior>([::NSSliderAccessoryBehavior valueResetBehavior]);
    }

    SliderAccessoryBehavior SliderAccessoryBehavior::value_step_behavior()
    {
        return cocoon::internal::wrap<SliderAccessoryBehavior>([::NSSliderAccessoryBehavior valueStepBehavior]);
    }
}
