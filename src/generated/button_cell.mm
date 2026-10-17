#include "generated/button_cell.h"
#include "internal.h"

namespace cocoon
{
    ButtonCell::ButtonCell(const Image& image) : ButtonCell(Adopt{cocoon::internal::retain([[::NSButtonCell alloc] initImageCell:cocoon::internal::native<::NSImage>(image)])})
    {
    }

    ButtonCell::ButtonCell(const std::string& string) : ButtonCell(Adopt{cocoon::internal::retain([[::NSButtonCell alloc] initTextCell:cocoon::internal::to(string)])})
    {
    }

    ButtonCell::ButtonCell() : ButtonCell(Adopt{cocoon::internal::retain([[::NSButtonCell alloc] init])})
    {
    }

    ButtonCell::ButtonCell(std::nullptr_t) : ActionCell(nullptr)
    {
    }

    ButtonCell::ButtonCell(Adopt adopt) : ActionCell(adopt)
    {
    }

    void ButtonCell::draw_bezel_with_frame(const Rect& frame, const View& control_view) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) drawBezelWithFrame:cocoon::internal::to(frame) inView:cocoon::internal::native<::NSView>(control_view)];
    }

    void ButtonCell::draw_image(const Image& image, const Rect& frame, const View& control_view) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) drawImage:cocoon::internal::native<::NSImage>(image) withFrame:cocoon::internal::to(frame) inView:cocoon::internal::native<::NSView>(control_view)];
    }

    Rect ButtonCell::draw_title(const AttributedString& title, const Rect& frame, const View& control_view) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSButtonCell>(this) drawTitle:cocoon::internal::native<::NSAttributedString>(title) withFrame:cocoon::internal::to(frame) inView:cocoon::internal::native<::NSView>(control_view)]);
    }

    void ButtonCell::get_periodic_delay(float* delay, float* interval) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) getPeriodicDelay:(float*)(delay) interval:(float*)(interval)];
    }

    void ButtonCell::mouse_entered(const Event& event) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) mouseEntered:cocoon::internal::native<::NSEvent>(event)];
    }

    void ButtonCell::mouse_exited(const Event& event) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) mouseExited:cocoon::internal::native<::NSEvent>(event)];
    }

    void ButtonCell::perform_click(const Object& sender) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) performClick:cocoon::internal::native_id(sender)];
    }

    void ButtonCell::set_button_type(ButtonType type) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setButtonType:static_cast<::NSButtonType>(type)];
    }

    void ButtonCell::set_periodic_delay(float delay, float interval) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setPeriodicDelay:static_cast<float>(delay) interval:static_cast<float>(interval)];
    }

    Image ButtonCell::alternate_image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSButtonCell>(this) alternateImage]);
    }

    void ButtonCell::set_alternate_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setAlternateImage:cocoon::internal::native<::NSImage>(value)];
    }

    std::string ButtonCell::alternate_title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSButtonCell>(this) alternateTitle]);
    }

    void ButtonCell::set_alternate_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setAlternateTitle:cocoon::internal::to(value)];
    }

    AttributedString ButtonCell::attributed_alternate_title() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSButtonCell>(this) attributedAlternateTitle]);
    }

    void ButtonCell::set_attributed_alternate_title(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setAttributedAlternateTitle:cocoon::internal::native<::NSAttributedString>(value)];
    }

    AttributedString ButtonCell::attributed_title() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSButtonCell>(this) attributedTitle]);
    }

    void ButtonCell::set_attributed_title(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setAttributedTitle:cocoon::internal::native<::NSAttributedString>(value)];
    }

    Color ButtonCell::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSButtonCell>(this) backgroundColor]);
    }

    void ButtonCell::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    BezelStyle ButtonCell::bezel_style() const
    {
        return static_cast<BezelStyle>([cocoon::internal::ns<::NSButtonCell>(this) bezelStyle]);
    }

    void ButtonCell::set_bezel_style(BezelStyle value) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setBezelStyle:static_cast<::NSBezelStyle>(value)];
    }

    CellStyleMask ButtonCell::highlights_by() const
    {
        return static_cast<CellStyleMask>([cocoon::internal::ns<::NSButtonCell>(this) highlightsBy]);
    }

    void ButtonCell::set_highlights_by(CellStyleMask value) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setHighlightsBy:static_cast<::NSCellStyleMask>(value)];
    }

    bool ButtonCell::image_dims_when_disabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSButtonCell>(this) imageDimsWhenDisabled]);
    }

    void ButtonCell::set_image_dims_when_disabled(bool value) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setImageDimsWhenDisabled:static_cast<::BOOL>(value)];
    }

    CellImagePosition ButtonCell::image_position() const
    {
        return static_cast<CellImagePosition>([cocoon::internal::ns<::NSButtonCell>(this) imagePosition]);
    }

    void ButtonCell::set_image_position(CellImagePosition value) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setImagePosition:static_cast<::NSCellImagePosition>(value)];
    }

    ImageScaling ButtonCell::image_scaling() const
    {
        return static_cast<ImageScaling>([cocoon::internal::ns<::NSButtonCell>(this) imageScaling]);
    }

    void ButtonCell::set_image_scaling(ImageScaling value) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setImageScaling:static_cast<::NSImageScaling>(value)];
    }

    std::string ButtonCell::key_equivalent() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSButtonCell>(this) keyEquivalent]);
    }

    void ButtonCell::set_key_equivalent(const std::string& value) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setKeyEquivalent:cocoon::internal::to(value)];
    }

    EventModifierFlags ButtonCell::key_equivalent_modifier_mask() const
    {
        return static_cast<EventModifierFlags>([cocoon::internal::ns<::NSButtonCell>(this) keyEquivalentModifierMask]);
    }

    void ButtonCell::set_key_equivalent_modifier_mask(EventModifierFlags value) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setKeyEquivalentModifierMask:static_cast<::NSEventModifierFlags>(value)];
    }

    bool ButtonCell::is_opaque() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSButtonCell>(this) isOpaque]);
    }

    bool ButtonCell::shows_border_only_while_mouse_inside() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSButtonCell>(this) showsBorderOnlyWhileMouseInside]);
    }

    void ButtonCell::set_shows_border_only_while_mouse_inside(bool value) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setShowsBorderOnlyWhileMouseInside:static_cast<::BOOL>(value)];
    }

    CellStyleMask ButtonCell::shows_state_by() const
    {
        return static_cast<CellStyleMask>([cocoon::internal::ns<::NSButtonCell>(this) showsStateBy]);
    }

    void ButtonCell::set_shows_state_by(CellStyleMask value) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setShowsStateBy:static_cast<::NSCellStyleMask>(value)];
    }

    Sound ButtonCell::sound() const
    {
        return cocoon::internal::wrap<Sound>([cocoon::internal::ns<::NSButtonCell>(this) sound]);
    }

    void ButtonCell::set_sound(const Sound& value) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setSound:cocoon::internal::native<::NSSound>(value)];
    }

    std::string ButtonCell::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSButtonCell>(this) title]);
    }

    void ButtonCell::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setTitle:cocoon::internal::to(value)];
    }

    bool ButtonCell::is_transparent() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSButtonCell>(this) isTransparent]);
    }

    void ButtonCell::set_transparent(bool value) const
    {
        [cocoon::internal::ns<::NSButtonCell>(this) setTransparent:static_cast<::BOOL>(value)];
    }
}
