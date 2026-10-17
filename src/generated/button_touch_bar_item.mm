#include "generated/button_touch_bar_item.h"
#include "internal.h"

namespace cocoon
{
    ButtonTouchBarItem::ButtonTouchBarItem() : TouchBarItem(nullptr)
    {
    }

    ButtonTouchBarItem::ButtonTouchBarItem(std::nullptr_t) : TouchBarItem(nullptr)
    {
    }

    ButtonTouchBarItem::ButtonTouchBarItem(Adopt adopt) : TouchBarItem(adopt)
    {
    }

    ButtonTouchBarItem ButtonTouchBarItem::button_touch_bar_item_with_identifier(const std::string& identifier, const Image& image, const Object& target, const std::string& action)
    {
        return cocoon::internal::wrap<ButtonTouchBarItem>([::NSButtonTouchBarItem buttonTouchBarItemWithIdentifier:cocoon::internal::to(identifier) image:cocoon::internal::native<::NSImage>(image) target:cocoon::internal::native_id(target) action:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    ButtonTouchBarItem ButtonTouchBarItem::button_touch_bar_item_with_identifier(const std::string& identifier, const std::string& title, const Image& image, const Object& target, const std::string& action)
    {
        return cocoon::internal::wrap<ButtonTouchBarItem>([::NSButtonTouchBarItem buttonTouchBarItemWithIdentifier:cocoon::internal::to(identifier) title:cocoon::internal::to(title) image:cocoon::internal::native<::NSImage>(image) target:cocoon::internal::native_id(target) action:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    ButtonTouchBarItem ButtonTouchBarItem::button_touch_bar_item_with_identifier(const std::string& identifier, const std::string& title, const Object& target, const std::string& action)
    {
        return cocoon::internal::wrap<ButtonTouchBarItem>([::NSButtonTouchBarItem buttonTouchBarItemWithIdentifier:cocoon::internal::to(identifier) title:cocoon::internal::to(title) target:cocoon::internal::native_id(target) action:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    std::string ButtonTouchBarItem::action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSButtonTouchBarItem>(this) action]));
    }

    void ButtonTouchBarItem::set_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSButtonTouchBarItem>(this) setAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    Color ButtonTouchBarItem::bezel_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSButtonTouchBarItem>(this) bezelColor]);
    }

    void ButtonTouchBarItem::set_bezel_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSButtonTouchBarItem>(this) setBezelColor:cocoon::internal::native<::NSColor>(value)];
    }

    std::string ButtonTouchBarItem::customization_label() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSButtonTouchBarItem>(this) customizationLabel]);
    }

    void ButtonTouchBarItem::set_customization_label(const std::string& value) const
    {
        [cocoon::internal::ns<::NSButtonTouchBarItem>(this) setCustomizationLabel:cocoon::internal::to(value)];
    }

    bool ButtonTouchBarItem::is_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSButtonTouchBarItem>(this) isEnabled]);
    }

    void ButtonTouchBarItem::set_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSButtonTouchBarItem>(this) setEnabled:static_cast<::BOOL>(value)];
    }

    Image ButtonTouchBarItem::image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSButtonTouchBarItem>(this) image]);
    }

    void ButtonTouchBarItem::set_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSButtonTouchBarItem>(this) setImage:cocoon::internal::native<::NSImage>(value)];
    }

    Object ButtonTouchBarItem::target() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSButtonTouchBarItem>(this) target]);
    }

    void ButtonTouchBarItem::set_target(const Object& value) const
    {
        [cocoon::internal::ns<::NSButtonTouchBarItem>(this) setTarget:cocoon::internal::native_id(value)];
    }

    std::string ButtonTouchBarItem::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSButtonTouchBarItem>(this) title]);
    }

    void ButtonTouchBarItem::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSButtonTouchBarItem>(this) setTitle:cocoon::internal::to(value)];
    }
}
