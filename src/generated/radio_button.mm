#include "generated/radio_button.h"
#include "internal.h"

namespace cocoon
{
    RadioButton::RadioButton(const std::string& title) : RadioButton(Adopt{cocoon::internal::retain([NSButton radioButtonWithTitle:cocoon::internal::to(title) target:nil action:nil])})
    {
        RadioButton::bind_action_(handle());
    }

    RadioButton::RadioButton(std::nullptr_t) : Button(nullptr)
    {
    }

    RadioButton::RadioButton(Adopt adopt) : Button(adopt)
    {
    }

    void RadioButton::bind_action_(void* native)
    {
        id host = (__bridge id)native;
        cocoon::internal::bind_action(host, host, [](id host, id sender)
                                      {
                                          cocoon::Signal<cocoon::Button, void()>::emit((__bridge void*)host, "clicked");
                                          cocoon::Signal<cocoon::RadioButton, void(bool)>::emit((__bridge void*)host, "toggled", [(NSButton*)sender state] == NSControlStateValueOn);
                                      });
    }
}
