#include "generated/combo_button.h"
#include "internal.h"

namespace cocoon
{
    ComboButton::ComboButton() : ComboButton(Adopt{cocoon::internal::retain([[::NSComboButton alloc] init])})
    {
    }

    ComboButton::ComboButton(std::nullptr_t) : Control(nullptr)
    {
    }

    ComboButton::ComboButton(Adopt adopt) : Control(adopt)
    {
    }

    ComboButton ComboButton::combo_button_with_image(const Image& image, const Menu& menu, const Object& target, const std::string& action)
    {
        return cocoon::internal::wrap<ComboButton>([::NSComboButton comboButtonWithImage:cocoon::internal::native<::NSImage>(image) menu:cocoon::internal::native<::NSMenu>(menu) target:cocoon::internal::native_id(target) action:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    ComboButton ComboButton::combo_button_with_title(const std::string& title, const Image& image, const Menu& menu, const Object& target, const std::string& action)
    {
        return cocoon::internal::wrap<ComboButton>([::NSComboButton comboButtonWithTitle:cocoon::internal::to(title) image:cocoon::internal::native<::NSImage>(image) menu:cocoon::internal::native<::NSMenu>(menu) target:cocoon::internal::native_id(target) action:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    ComboButton ComboButton::combo_button_with_title(const std::string& title, const Menu& menu, const Object& target, const std::string& action)
    {
        return cocoon::internal::wrap<ComboButton>([::NSComboButton comboButtonWithTitle:cocoon::internal::to(title) menu:cocoon::internal::native<::NSMenu>(menu) target:cocoon::internal::native_id(target) action:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    Image ComboButton::image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSComboButton>(this) image]);
    }

    void ComboButton::set_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSComboButton>(this) setImage:cocoon::internal::native<::NSImage>(value)];
    }

    ImageScaling ComboButton::image_scaling() const
    {
        return static_cast<ImageScaling>([cocoon::internal::ns<::NSComboButton>(this) imageScaling]);
    }

    void ComboButton::set_image_scaling(ImageScaling value) const
    {
        [cocoon::internal::ns<::NSComboButton>(this) setImageScaling:static_cast<::NSImageScaling>(value)];
    }

    Menu ComboButton::menu() const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSComboButton>(this) menu]);
    }

    void ComboButton::set_menu(const Menu& value) const
    {
        [cocoon::internal::ns<::NSComboButton>(this) setMenu:cocoon::internal::native<::NSMenu>(value)];
    }

    ComboButtonStyle ComboButton::style() const
    {
        return static_cast<ComboButtonStyle>([cocoon::internal::ns<::NSComboButton>(this) style]);
    }

    void ComboButton::set_style(ComboButtonStyle value) const
    {
        [cocoon::internal::ns<::NSComboButton>(this) setStyle:static_cast<::NSComboButtonStyle>(value)];
    }

    std::string ComboButton::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSComboButton>(this) title]);
    }

    void ComboButton::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSComboButton>(this) setTitle:cocoon::internal::to(value)];
    }
}
