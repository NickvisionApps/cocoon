#include "generated/color_picker.h"
#include "internal.h"

namespace cocoon
{
    ColorPicker::ColorPicker(std::uint64_t mask, const ColorPanel& owning_color_panel) : ColorPicker(Adopt{cocoon::internal::retain([[::NSColorPicker alloc] initWithPickerMask:static_cast<::NSUInteger>(mask) colorPanel:cocoon::internal::native<::NSColorPanel>(owning_color_panel)])})
    {
    }

    ColorPicker::ColorPicker() : ColorPicker(Adopt{cocoon::internal::retain([[::NSColorPicker alloc] init])})
    {
    }

    ColorPicker::ColorPicker(std::nullptr_t) : Object(nullptr)
    {
    }

    ColorPicker::ColorPicker(Adopt adopt) : Object(adopt)
    {
    }

    void ColorPicker::attach_color_list(const ColorList& color_list) const
    {
        [cocoon::internal::ns<::NSColorPicker>(this) attachColorList:cocoon::internal::native<::NSColorList>(color_list)];
    }

    void ColorPicker::detach_color_list(const ColorList& color_list) const
    {
        [cocoon::internal::ns<::NSColorPicker>(this) detachColorList:cocoon::internal::native<::NSColorList>(color_list)];
    }

    void ColorPicker::insert_new_button_image(const Image& new_button_image, const ButtonCell& button_cell) const
    {
        [cocoon::internal::ns<::NSColorPicker>(this) insertNewButtonImage:cocoon::internal::native<::NSImage>(new_button_image) in:cocoon::internal::native<::NSButtonCell>(button_cell)];
    }

    void ColorPicker::set_mode(ColorPanelMode mode) const
    {
        [cocoon::internal::ns<::NSColorPicker>(this) setMode:static_cast<::NSColorPanelMode>(mode)];
    }

    void ColorPicker::view_size_changed(const Object& sender) const
    {
        [cocoon::internal::ns<::NSColorPicker>(this) viewSizeChanged:cocoon::internal::native_id(sender)];
    }

    std::string ColorPicker::button_tool_tip() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSColorPicker>(this) buttonToolTip]);
    }

    ColorPanel ColorPicker::color_panel() const
    {
        return cocoon::internal::wrap<ColorPanel>([cocoon::internal::ns<::NSColorPicker>(this) colorPanel]);
    }

    Size ColorPicker::min_content_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSColorPicker>(this) minContentSize]);
    }

    Image ColorPicker::provide_new_button_image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSColorPicker>(this) provideNewButtonImage]);
    }
}
