#include "generated/box.h"
#include "internal.h"

namespace cocoon
{
    Box::Box() : Box(Adopt{cocoon::internal::retain([[NSBox alloc] init])})
    {
    }

    Box::Box(std::nullptr_t) : View(nullptr)
    {
    }

    Box::Box(Adopt adopt) : View(adopt)
    {
    }

    void Box::set_frame_from_content_frame(const Rect& content_frame) const
    {
        [cocoon::internal::ns<::NSBox>(this) setFrameFromContentFrame:cocoon::internal::to(content_frame)];
    }

    void Box::size_to_fit() const
    {
        [cocoon::internal::ns<::NSBox>(this) sizeToFit];
    }

    Color Box::border_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSBox>(this) borderColor]);
    }

    void Box::set_border_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSBox>(this) setBorderColor:cocoon::internal::native<::NSColor>(value)];
    }

    Rect Box::border_rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBox>(this) borderRect]);
    }

    double Box::border_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSBox>(this) borderWidth]);
    }

    void Box::set_border_width(double value) const
    {
        [cocoon::internal::ns<::NSBox>(this) setBorderWidth:static_cast<::CGFloat>(value)];
    }

    BoxType Box::box_type() const
    {
        return static_cast<BoxType>([cocoon::internal::ns<::NSBox>(this) boxType]);
    }

    void Box::set_box_type(BoxType value) const
    {
        [cocoon::internal::ns<::NSBox>(this) setBoxType:static_cast<::NSBoxType>(value)];
    }

    View Box::content_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSBox>(this) contentView]);
    }

    void Box::set_content_view(const View& value) const
    {
        [cocoon::internal::ns<::NSBox>(this) setContentView:cocoon::internal::native<::NSView>(value)];
    }

    Size Box::content_view_margins() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBox>(this) contentViewMargins]);
    }

    void Box::set_content_view_margins(const Size& value) const
    {
        [cocoon::internal::ns<::NSBox>(this) setContentViewMargins:cocoon::internal::to(value)];
    }

    double Box::corner_radius() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSBox>(this) cornerRadius]);
    }

    void Box::set_corner_radius(double value) const
    {
        [cocoon::internal::ns<::NSBox>(this) setCornerRadius:static_cast<::CGFloat>(value)];
    }

    Color Box::fill_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSBox>(this) fillColor]);
    }

    void Box::set_fill_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSBox>(this) setFillColor:cocoon::internal::native<::NSColor>(value)];
    }

    std::string Box::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBox>(this) title]);
    }

    void Box::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSBox>(this) setTitle:cocoon::internal::to(value)];
    }

    Object Box::title_cell() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSBox>(this) titleCell]);
    }

    Font Box::title_font() const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSBox>(this) titleFont]);
    }

    void Box::set_title_font(const Font& value) const
    {
        [cocoon::internal::ns<::NSBox>(this) setTitleFont:cocoon::internal::native<::NSFont>(value)];
    }

    TitlePosition Box::title_position() const
    {
        return static_cast<TitlePosition>([cocoon::internal::ns<::NSBox>(this) titlePosition]);
    }

    void Box::set_title_position(TitlePosition value) const
    {
        [cocoon::internal::ns<::NSBox>(this) setTitlePosition:static_cast<::NSTitlePosition>(value)];
    }

    Rect Box::title_rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBox>(this) titleRect]);
    }

    bool Box::is_transparent() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBox>(this) isTransparent]);
    }

    void Box::set_transparent(bool value) const
    {
        [cocoon::internal::ns<::NSBox>(this) setTransparent:static_cast<::BOOL>(value)];
    }
}
