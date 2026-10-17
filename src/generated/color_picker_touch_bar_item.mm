#include "generated/color_picker_touch_bar_item.h"
#include "internal.h"

namespace cocoon
{
    ColorPickerTouchBarItem::ColorPickerTouchBarItem() : TouchBarItem(nullptr)
    {
    }

    ColorPickerTouchBarItem::ColorPickerTouchBarItem(std::nullptr_t) : TouchBarItem(nullptr)
    {
    }

    ColorPickerTouchBarItem::ColorPickerTouchBarItem(Adopt adopt) : TouchBarItem(adopt)
    {
    }

    ColorPickerTouchBarItem ColorPickerTouchBarItem::color_picker_with_identifier(const std::string& identifier)
    {
        return cocoon::internal::wrap<ColorPickerTouchBarItem>([::NSColorPickerTouchBarItem colorPickerWithIdentifier:cocoon::internal::to(identifier)]);
    }

    ColorPickerTouchBarItem ColorPickerTouchBarItem::color_picker_with_identifier(const std::string& identifier, const Image& image)
    {
        return cocoon::internal::wrap<ColorPickerTouchBarItem>([::NSColorPickerTouchBarItem colorPickerWithIdentifier:cocoon::internal::to(identifier) buttonImage:cocoon::internal::native<::NSImage>(image)]);
    }

    ColorPickerTouchBarItem ColorPickerTouchBarItem::stroke_color_picker_with_identifier(const std::string& identifier)
    {
        return cocoon::internal::wrap<ColorPickerTouchBarItem>([::NSColorPickerTouchBarItem strokeColorPickerWithIdentifier:cocoon::internal::to(identifier)]);
    }

    ColorPickerTouchBarItem ColorPickerTouchBarItem::text_color_picker_with_identifier(const std::string& identifier)
    {
        return cocoon::internal::wrap<ColorPickerTouchBarItem>([::NSColorPickerTouchBarItem textColorPickerWithIdentifier:cocoon::internal::to(identifier)]);
    }

    std::string ColorPickerTouchBarItem::action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSColorPickerTouchBarItem>(this) action]));
    }

    void ColorPickerTouchBarItem::set_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSColorPickerTouchBarItem>(this) setAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    std::vector<ColorSpace> ColorPickerTouchBarItem::allowed_color_spaces() const
    {
        return cocoon::internal::from_array<ColorSpace>([cocoon::internal::ns<::NSColorPickerTouchBarItem>(this) allowedColorSpaces], [](id e) -> ColorSpace
                                          {
                                              return cocoon::internal::wrap<ColorSpace>((::NSColorSpace*)e);
                                          });
    }

    void ColorPickerTouchBarItem::set_allowed_color_spaces(const std::vector<ColorSpace>& value) const
    {
        [cocoon::internal::ns<::NSColorPickerTouchBarItem>(this) setAllowedColorSpaces:cocoon::internal::to_array(value, [](const ColorSpace& e) -> id
                                                                                      {
                                                                                          return cocoon::internal::native<::NSColorSpace>(e);
                                                                                      })];
    }

    Color ColorPickerTouchBarItem::color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSColorPickerTouchBarItem>(this) color]);
    }

    void ColorPickerTouchBarItem::set_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSColorPickerTouchBarItem>(this) setColor:cocoon::internal::native<::NSColor>(value)];
    }

    ColorList ColorPickerTouchBarItem::color_list() const
    {
        return cocoon::internal::wrap<ColorList>([cocoon::internal::ns<::NSColorPickerTouchBarItem>(this) colorList]);
    }

    void ColorPickerTouchBarItem::set_color_list(const ColorList& value) const
    {
        [cocoon::internal::ns<::NSColorPickerTouchBarItem>(this) setColorList:cocoon::internal::native<::NSColorList>(value)];
    }

    std::string ColorPickerTouchBarItem::customization_label() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSColorPickerTouchBarItem>(this) customizationLabel]);
    }

    void ColorPickerTouchBarItem::set_customization_label(const std::string& value) const
    {
        [cocoon::internal::ns<::NSColorPickerTouchBarItem>(this) setCustomizationLabel:cocoon::internal::to(value)];
    }

    bool ColorPickerTouchBarItem::is_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSColorPickerTouchBarItem>(this) isEnabled]);
    }

    void ColorPickerTouchBarItem::set_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSColorPickerTouchBarItem>(this) setEnabled:static_cast<::BOOL>(value)];
    }

    bool ColorPickerTouchBarItem::shows_alpha() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSColorPickerTouchBarItem>(this) showsAlpha]);
    }

    void ColorPickerTouchBarItem::set_shows_alpha(bool value) const
    {
        [cocoon::internal::ns<::NSColorPickerTouchBarItem>(this) setShowsAlpha:static_cast<::BOOL>(value)];
    }

    Object ColorPickerTouchBarItem::target() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSColorPickerTouchBarItem>(this) target]);
    }

    void ColorPickerTouchBarItem::set_target(const Object& value) const
    {
        [cocoon::internal::ns<::NSColorPickerTouchBarItem>(this) setTarget:cocoon::internal::native_id(value)];
    }
}
