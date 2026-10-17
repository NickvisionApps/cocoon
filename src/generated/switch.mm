#include "generated/switch.h"
#include "internal.h"

namespace cocoon
{
    Switch::Switch() : Switch(Adopt{cocoon::internal::retain([[NSSwitch alloc] init])})
    {
        Switch::bind_action_(handle());
    }

    Switch::Switch(std::nullptr_t) : Control(nullptr)
    {
    }

    Switch::Switch(Adopt adopt) : Control(adopt)
    {
    }

    ControlState Switch::state() const
    {
        return static_cast<ControlState>([cocoon::internal::ns<::NSSwitch>(this) state]);
    }

    void Switch::set_state(ControlState value) const
    {
        [cocoon::internal::ns<::NSSwitch>(this) setState:static_cast<NSControlStateValue>(value)];
    }

    bool Switch::is_on() const
    {
        return cocoon::internal::ns<NSSwitch>(this).state == NSControlStateValueOn;
    }

    void Switch::set_on(bool on) const
    {
        cocoon::internal::ns<NSSwitch>(this).state = on ? NSControlStateValueOn : NSControlStateValueOff;
    }

    void Switch::bind_action_(void* native)
    {
        id host = (__bridge id)native;
        cocoon::internal::bind_action(host, host, [](id host, id sender)
                        {
                            cocoon::Signal<cocoon::Switch, void(bool)>::emit((__bridge void*)host, "toggled", [(NSSwitch*)sender state] == NSControlStateValueOn);
                        });
    }
}
