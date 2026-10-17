#include "generated/button.h"
#include "internal.h"

namespace cocoon
{
    Button::Button(const std::string& title) : Button(Adopt{cocoon::internal::retain([NSButton buttonWithTitle:cocoon::internal::to(title) target:nil action:nil])})
    {
        Button::bind_action_(handle());
    }

    Button::Button(std::nullptr_t) : Control(nullptr)
    {
    }

    Button::Button(Adopt adopt) : Control(adopt)
    {
    }

    Button Button::button_with_image(const Image& image, const Object& target, const std::string& action)
    {
        return cocoon::internal::wrap<Button>([::NSButton buttonWithImage:cocoon::internal::native<::NSImage>(image) target:cocoon::internal::native_id(target) action:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    Button Button::button_with_title(const std::string& title, const Image& image, const Object& target, const std::string& action)
    {
        return cocoon::internal::wrap<Button>([::NSButton buttonWithTitle:cocoon::internal::to(title) image:cocoon::internal::native<::NSImage>(image) target:cocoon::internal::native_id(target) action:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    Button Button::button_with_title(const std::string& title, const Object& target, const std::string& action)
    {
        return cocoon::internal::wrap<Button>([::NSButton buttonWithTitle:cocoon::internal::to(title) target:cocoon::internal::native_id(target) action:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    Button Button::checkbox_with_title(const std::string& title, const Object& target, const std::string& action)
    {
        return cocoon::internal::wrap<Button>([::NSButton checkboxWithTitle:cocoon::internal::to(title) target:cocoon::internal::native_id(target) action:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    void Button::compress_with_prioritized_compression_options(const std::vector<UserInterfaceCompressionOptions>& prioritized_options) const
    {
        [cocoon::internal::ns<::NSButton>(this) compressWithPrioritizedCompressionOptions:cocoon::internal::to_array(prioritized_options, [](const UserInterfaceCompressionOptions& e) -> id
                                                                                                                     {
                                                                                                                         return cocoon::internal::native<::NSUserInterfaceCompressionOptions>(e);
                                                                                                                     })];
    }

    void Button::get_periodic_delay(float* delay, float* interval) const
    {
        [cocoon::internal::ns<::NSButton>(this) getPeriodicDelay:(float*)(delay) interval:(float*)(interval)];
    }

    void Button::highlight(bool flag) const
    {
        [cocoon::internal::ns<::NSButton>(this) highlight:static_cast<::BOOL>(flag)];
    }

    Size Button::minimum_size_with_prioritized_compression_options(const std::vector<UserInterfaceCompressionOptions>& prioritized_options) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSButton>(this) minimumSizeWithPrioritizedCompressionOptions:cocoon::internal::to_array(prioritized_options, [](const UserInterfaceCompressionOptions& e) -> id
                                                                                                                                                      {
                                                                                                                                                          return cocoon::internal::native<::NSUserInterfaceCompressionOptions>(e);
                                                                                                                                                      })]);
    }

    bool Button::perform_key_equivalent(const Event& key) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSButton>(this) performKeyEquivalent:cocoon::internal::native<::NSEvent>(key)]);
    }

    Button Button::radio_button_with_title(const std::string& title, const Object& target, const std::string& action)
    {
        return cocoon::internal::wrap<Button>([::NSButton radioButtonWithTitle:cocoon::internal::to(title) target:cocoon::internal::native_id(target) action:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    void Button::set_button_type(ButtonType type) const
    {
        [cocoon::internal::ns<::NSButton>(this) setButtonType:static_cast<::NSButtonType>(type)];
    }

    void Button::set_next_state() const
    {
        [cocoon::internal::ns<::NSButton>(this) setNextState];
    }

    void Button::set_periodic_delay(float delay, float interval) const
    {
        [cocoon::internal::ns<::NSButton>(this) setPeriodicDelay:static_cast<float>(delay) interval:static_cast<float>(interval)];
    }

    UserInterfaceCompressionOptions Button::active_compression_options() const
    {
        return cocoon::internal::wrap<UserInterfaceCompressionOptions>([cocoon::internal::ns<::NSButton>(this) activeCompressionOptions]);
    }

    bool Button::allows_mixed_state() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSButton>(this) allowsMixedState]);
    }

    void Button::set_allows_mixed_state(bool value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setAllowsMixedState:static_cast<::BOOL>(value)];
    }

    Image Button::alternate_image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSButton>(this) alternateImage]);
    }

    void Button::set_alternate_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setAlternateImage:cocoon::internal::native<::NSImage>(value)];
    }

    std::string Button::alternate_title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSButton>(this) alternateTitle]);
    }

    void Button::set_alternate_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setAlternateTitle:cocoon::internal::to(value)];
    }

    AttributedString Button::attributed_alternate_title() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSButton>(this) attributedAlternateTitle]);
    }

    void Button::set_attributed_alternate_title(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setAttributedAlternateTitle:cocoon::internal::native<::NSAttributedString>(value)];
    }

    AttributedString Button::attributed_title() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSButton>(this) attributedTitle]);
    }

    void Button::set_attributed_title(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setAttributedTitle:cocoon::internal::native<::NSAttributedString>(value)];
    }

    Color Button::bezel_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSButton>(this) bezelColor]);
    }

    void Button::set_bezel_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setBezelColor:cocoon::internal::native<::NSColor>(value)];
    }

    BezelStyle Button::bezel_style() const
    {
        return static_cast<BezelStyle>([cocoon::internal::ns<::NSButton>(this) bezelStyle]);
    }

    void Button::set_bezel_style(BezelStyle value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setBezelStyle:static_cast<::NSBezelStyle>(value)];
    }

    ControlBorderShape Button::border_shape() const
    {
        return static_cast<ControlBorderShape>([cocoon::internal::ns<::NSButton>(this) borderShape]);
    }

    void Button::set_border_shape(ControlBorderShape value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setBorderShape:static_cast<::NSControlBorderShape>(value)];
    }

    bool Button::is_bordered() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSButton>(this) isBordered]);
    }

    void Button::set_bordered(bool value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setBordered:static_cast<::BOOL>(value)];
    }

    Color Button::content_tint_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSButton>(this) contentTintColor]);
    }

    void Button::set_content_tint_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setContentTintColor:cocoon::internal::native<::NSColor>(value)];
    }

    bool Button::has_destructive_action() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSButton>(this) hasDestructiveAction]);
    }

    void Button::set_has_destructive_action(bool value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setHasDestructiveAction:static_cast<::BOOL>(value)];
    }

    Image Button::image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSButton>(this) image]);
    }

    void Button::set_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setImage:cocoon::internal::native<::NSImage>(value)];
    }

    bool Button::image_hugs_title() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSButton>(this) imageHugsTitle]);
    }

    void Button::set_image_hugs_title(bool value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setImageHugsTitle:static_cast<::BOOL>(value)];
    }

    CellImagePosition Button::image_position() const
    {
        return static_cast<CellImagePosition>([cocoon::internal::ns<::NSButton>(this) imagePosition]);
    }

    void Button::set_image_position(CellImagePosition value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setImagePosition:static_cast<::NSCellImagePosition>(value)];
    }

    ImageScaling Button::image_scaling() const
    {
        return static_cast<ImageScaling>([cocoon::internal::ns<::NSButton>(this) imageScaling]);
    }

    void Button::set_image_scaling(ImageScaling value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setImageScaling:static_cast<::NSImageScaling>(value)];
    }

    std::string Button::key_equivalent() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSButton>(this) keyEquivalent]);
    }

    void Button::set_key_equivalent(const std::string& value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setKeyEquivalent:cocoon::internal::to(value)];
    }

    EventModifierFlags Button::key_equivalent_modifier_mask() const
    {
        return static_cast<EventModifierFlags>([cocoon::internal::ns<::NSButton>(this) keyEquivalentModifierMask]);
    }

    void Button::set_key_equivalent_modifier_mask(EventModifierFlags value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setKeyEquivalentModifierMask:static_cast<::NSEventModifierFlags>(value)];
    }

    std::int64_t Button::max_accelerator_level() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSButton>(this) maxAcceleratorLevel]);
    }

    void Button::set_max_accelerator_level(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setMaxAcceleratorLevel:static_cast<::NSInteger>(value)];
    }

    bool Button::shows_border_only_while_mouse_inside() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSButton>(this) showsBorderOnlyWhileMouseInside]);
    }

    void Button::set_shows_border_only_while_mouse_inside(bool value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setShowsBorderOnlyWhileMouseInside:static_cast<::BOOL>(value)];
    }

    Sound Button::sound() const
    {
        return cocoon::internal::wrap<Sound>([cocoon::internal::ns<::NSButton>(this) sound]);
    }

    void Button::set_sound(const Sound& value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setSound:cocoon::internal::native<::NSSound>(value)];
    }

    bool Button::is_spring_loaded() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSButton>(this) isSpringLoaded]);
    }

    void Button::set_spring_loaded(bool value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setSpringLoaded:static_cast<::BOOL>(value)];
    }

    ControlState Button::state() const
    {
        return static_cast<ControlState>([cocoon::internal::ns<::NSButton>(this) state]);
    }

    void Button::set_state(ControlState value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setState:static_cast<NSControlStateValue>(value)];
    }

    ImageSymbolConfiguration Button::symbol_configuration() const
    {
        return cocoon::internal::wrap<ImageSymbolConfiguration>([cocoon::internal::ns<::NSButton>(this) symbolConfiguration]);
    }

    void Button::set_symbol_configuration(const ImageSymbolConfiguration& value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setSymbolConfiguration:cocoon::internal::native<::NSImageSymbolConfiguration>(value)];
    }

    TintProminence Button::tint_prominence() const
    {
        return static_cast<TintProminence>([cocoon::internal::ns<::NSButton>(this) tintProminence]);
    }

    void Button::set_tint_prominence(TintProminence value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setTintProminence:static_cast<::NSTintProminence>(value)];
    }

    std::string Button::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSButton>(this) title]);
    }

    void Button::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setTitle:cocoon::internal::to(value)];
    }

    bool Button::is_transparent() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSButton>(this) isTransparent]);
    }

    void Button::set_transparent(bool value) const
    {
        [cocoon::internal::ns<::NSButton>(this) setTransparent:static_cast<::BOOL>(value)];
    }

    void Button::perform_click() const
    {
        [cocoon::internal::ns<NSButton>(this) performClick:nil];
    }

    void Button::bind_action_(void* native)
    {
        id host = (__bridge id)native;
        cocoon::internal::bind_action(host, host, [](id host, id sender)
                                      {
                                          cocoon::Signal<cocoon::Button, void()>::emit((__bridge void*)host, "clicked");
                                      });
    }
}
