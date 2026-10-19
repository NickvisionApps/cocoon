#include "generated/menu_item.h"
#include "internal.h"

namespace cocoon
{
    MenuItem::MenuItem(const std::string& title, const std::string& shortcut) : MenuItem(Adopt{cocoon::internal::retain(cocoon::internal::make_menu_item(title, shortcut))})
    {
        MenuItem::bind_action_(handle());
    }

    MenuItem::MenuItem(const std::string& string, const std::string& selector, const std::string& char_code) : MenuItem(Adopt{cocoon::internal::retain([[::NSMenuItem alloc] initWithTitle:cocoon::internal::to(string) action:NSSelectorFromString(cocoon::internal::to(selector)) keyEquivalent:cocoon::internal::to(char_code)])})
    {
        MenuItem::bind_action_(handle());
    }

    MenuItem::MenuItem(std::nullptr_t) : Object(nullptr)
    {
    }

    MenuItem::MenuItem(Adopt adopt) : Object(adopt)
    {
    }

    MenuItem MenuItem::section_header_with_title(const std::string& title)
    {
        return cocoon::internal::wrap<MenuItem>([::NSMenuItem sectionHeaderWithTitle:cocoon::internal::to(title)]);
    }

    MenuItem MenuItem::separator_item()
    {
        return cocoon::internal::wrap<MenuItem>([::NSMenuItem separatorItem]);
    }

    std::string MenuItem::action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSMenuItem>(this) action]));
    }

    void MenuItem::set_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    bool MenuItem::allows_automatic_key_equivalent_localization() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenuItem>(this) allowsAutomaticKeyEquivalentLocalization]);
    }

    void MenuItem::set_allows_automatic_key_equivalent_localization(bool value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setAllowsAutomaticKeyEquivalentLocalization:static_cast<::BOOL>(value)];
    }

    bool MenuItem::allows_automatic_key_equivalent_mirroring() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenuItem>(this) allowsAutomaticKeyEquivalentMirroring]);
    }

    void MenuItem::set_allows_automatic_key_equivalent_mirroring(bool value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setAllowsAutomaticKeyEquivalentMirroring:static_cast<::BOOL>(value)];
    }

    bool MenuItem::allows_key_equivalent_when_hidden() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenuItem>(this) allowsKeyEquivalentWhenHidden]);
    }

    void MenuItem::set_allows_key_equivalent_when_hidden(bool value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setAllowsKeyEquivalentWhenHidden:static_cast<::BOOL>(value)];
    }

    bool MenuItem::is_alternate() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenuItem>(this) isAlternate]);
    }

    void MenuItem::set_alternate(bool value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setAlternate:static_cast<::BOOL>(value)];
    }

    AttributedString MenuItem::attributed_title() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSMenuItem>(this) attributedTitle]);
    }

    void MenuItem::set_attributed_title(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setAttributedTitle:cocoon::internal::native<::NSAttributedString>(value)];
    }

    MenuItemBadge MenuItem::badge() const
    {
        return cocoon::internal::wrap<MenuItemBadge>([cocoon::internal::ns<::NSMenuItem>(this) badge]);
    }

    void MenuItem::set_badge(const MenuItemBadge& value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setBadge:cocoon::internal::native<::NSMenuItemBadge>(value)];
    }

    bool MenuItem::has_submenu() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenuItem>(this) hasSubmenu]);
    }

    bool MenuItem::is_hidden() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenuItem>(this) isHidden]);
    }

    void MenuItem::set_hidden(bool value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setHidden:static_cast<::BOOL>(value)];
    }

    bool MenuItem::is_hidden_or_has_hidden_ancestor() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenuItem>(this) isHiddenOrHasHiddenAncestor]);
    }

    bool MenuItem::is_highlighted() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenuItem>(this) isHighlighted]);
    }

    Image MenuItem::image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSMenuItem>(this) image]);
    }

    void MenuItem::set_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setImage:cocoon::internal::native<::NSImage>(value)];
    }

    std::int64_t MenuItem::indentation_level() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSMenuItem>(this) indentationLevel]);
    }

    void MenuItem::set_indentation_level(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setIndentationLevel:static_cast<::NSInteger>(value)];
    }

    std::string MenuItem::key_equivalent() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMenuItem>(this) keyEquivalent]);
    }

    void MenuItem::set_key_equivalent(const std::string& value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setKeyEquivalent:cocoon::internal::to(value)];
    }

    EventModifierFlags MenuItem::key_equivalent_modifier_mask() const
    {
        return static_cast<EventModifierFlags>([cocoon::internal::ns<::NSMenuItem>(this) keyEquivalentModifierMask]);
    }

    void MenuItem::set_key_equivalent_modifier_mask(EventModifierFlags value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setKeyEquivalentModifierMask:static_cast<::NSEventModifierFlags>(value)];
    }

    Menu MenuItem::menu() const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSMenuItem>(this) menu]);
    }

    void MenuItem::set_menu(const Menu& value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setMenu:cocoon::internal::native<::NSMenu>(value)];
    }

    Image MenuItem::mixed_state_image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSMenuItem>(this) mixedStateImage]);
    }

    void MenuItem::set_mixed_state_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setMixedStateImage:cocoon::internal::native<::NSImage>(value)];
    }

    Image MenuItem::off_state_image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSMenuItem>(this) offStateImage]);
    }

    void MenuItem::set_off_state_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setOffStateImage:cocoon::internal::native<::NSImage>(value)];
    }

    Image MenuItem::on_state_image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSMenuItem>(this) onStateImage]);
    }

    void MenuItem::set_on_state_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setOnStateImage:cocoon::internal::native<::NSImage>(value)];
    }

    MenuItem MenuItem::parent_item() const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSMenuItem>(this) parentItem]);
    }

    Object MenuItem::represented_object() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSMenuItem>(this) representedObject]);
    }

    void MenuItem::set_represented_object(const Object& value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setRepresentedObject:cocoon::internal::native_id(value)];
    }

    bool MenuItem::is_section_header() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenuItem>(this) isSectionHeader]);
    }

    bool MenuItem::is_separator_item() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenuItem>(this) isSeparatorItem]);
    }

    ControlState MenuItem::state() const
    {
        return static_cast<ControlState>([cocoon::internal::ns<::NSMenuItem>(this) state]);
    }

    void MenuItem::set_state(ControlState value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setState:static_cast<NSControlStateValue>(value)];
    }

    Menu MenuItem::submenu() const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSMenuItem>(this) submenu]);
    }

    void MenuItem::set_submenu(const Menu& value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setSubmenu:cocoon::internal::native<::NSMenu>(value)];
    }

    std::string MenuItem::subtitle() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMenuItem>(this) subtitle]);
    }

    void MenuItem::set_subtitle(const std::string& value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setSubtitle:cocoon::internal::to(value)];
    }

    std::int64_t MenuItem::tag() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSMenuItem>(this) tag]);
    }

    void MenuItem::set_tag(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setTag:static_cast<::NSInteger>(value)];
    }

    Object MenuItem::target() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSMenuItem>(this) target]);
    }

    void MenuItem::set_target(const Object& value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setTarget:cocoon::internal::native_id(value)];
    }

    std::string MenuItem::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMenuItem>(this) title]);
    }

    void MenuItem::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setTitle:cocoon::internal::to(value)];
    }

    std::string MenuItem::tool_tip() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMenuItem>(this) toolTip]);
    }

    void MenuItem::set_tool_tip(const std::string& value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setToolTip:cocoon::internal::to(value)];
    }

    std::string MenuItem::user_key_equivalent() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMenuItem>(this) userKeyEquivalent]);
    }

    bool MenuItem::uses_user_key_equivalents()
    {
        return static_cast<bool>([::NSMenuItem usesUserKeyEquivalents]);
    }

    void MenuItem::set_uses_user_key_equivalents(bool value)
    {
        [::NSMenuItem setUsesUserKeyEquivalents:static_cast<::BOOL>(value)];
    }

    View MenuItem::view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSMenuItem>(this) view]);
    }

    void MenuItem::set_view(const View& value) const
    {
        [cocoon::internal::ns<::NSMenuItem>(this) setView:cocoon::internal::native<::NSView>(value)];
    }

    std::vector<MenuItem> MenuItem::writing_tools_items()
    {
        return cocoon::internal::from_array<MenuItem>([::NSMenuItem writingToolsItems], [](id e) -> MenuItem
                                                      {
                                                          return cocoon::internal::wrap<MenuItem>((::NSMenuItem*)e);
                                                      });
    }

    MenuItem MenuItem::separator()
    {
        return cocoon::internal::wrap<MenuItem>([NSMenuItem separatorItem]);
    }

    MenuItem MenuItem::standard(StandardAction action)
    {
        return cocoon::internal::wrap<MenuItem>(cocoon::internal::make_standard_menu_item(action));
    }

    void MenuItem::set_shortcut(const std::string& shortcut) const
    {
        cocoon::internal::apply_shortcut(cocoon::internal::ns<NSMenuItem>(this), shortcut);
    }

    bool MenuItem::is_enabled() const
    {
        return cocoon::internal::ns<NSMenuItem>(this).enabled;
    }

    void MenuItem::set_enabled(bool enabled) const
    {
        NSMenuItem* item = cocoon::internal::ns<NSMenuItem>(this);
        item.enabled = enabled;
        item.representedObject = enabled ? nil : @NO;
    }

    bool MenuItem::is_checked() const
    {
        return cocoon::internal::ns<NSMenuItem>(this).state == NSControlStateValueOn;
    }

    void MenuItem::set_checked(bool checked) const
    {
        cocoon::internal::ns<NSMenuItem>(this).state = checked ? NSControlStateValueOn : NSControlStateValueOff;
    }

    void MenuItem::bind_action_(void* native)
    {
        id host = (__bridge id)native;
        cocoon::internal::bind_action(host, host, [](id host, id sender)
                                      {
                                          cocoon::Signal<cocoon::MenuItem, void()>::emit((__bridge void*)host, "triggered");
                                      });
    }
}
