#include "generated/check_box.h"
#include "internal.h"

namespace cocoon
{
    CheckBox::CheckBox(const std::string& title) : CheckBox(Adopt{cocoon::internal::retain([NSButton checkboxWithTitle:cocoon::internal::to(title) target:nil action:nil])})
    {
        CheckBox::bind_action_(handle());
    }

    CheckBox::CheckBox(std::nullptr_t) : Button(nullptr)
    {
    }

    CheckBox::CheckBox(Adopt adopt) : Button(adopt)
    {
    }

    void CheckBox::bind_action_(void* native)
    {
        id host = (__bridge id)native;
        cocoon::internal::bind_action(host, host, [](id host, id sender)
                                      {
                                          cocoon::Signal<cocoon::Button, void()>::emit((__bridge void*)host, "clicked");
                                          cocoon::Signal<cocoon::CheckBox, void(bool)>::emit((__bridge void*)host, "toggled", [(NSButton*)sender state] == NSControlStateValueOn);
                                      });
    }
}
