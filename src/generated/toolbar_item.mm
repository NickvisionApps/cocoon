#include "generated/toolbar_item.h"
#include "internal.h"

namespace cocoon
{
    ToolbarItem::ToolbarItem(const std::string& identifier, const std::string& label, const std::string& symbol) : ToolbarItem(Adopt{cocoon::internal::retain(cocoon::internal::make_toolbar_item(identifier, label, symbol))})
    {
        ToolbarItem::bind_action_(handle());
    }

    ToolbarItem::ToolbarItem(const std::string& item_identifier) : ToolbarItem(Adopt{cocoon::internal::retain([[::NSToolbarItem alloc] initWithItemIdentifier:cocoon::internal::to(item_identifier)])})
    {
        ToolbarItem::bind_action_(handle());
    }

    ToolbarItem::ToolbarItem() : ToolbarItem(Adopt{cocoon::internal::retain([[::NSToolbarItem alloc] init])})
    {
        ToolbarItem::bind_action_(handle());
    }

    ToolbarItem::ToolbarItem(std::nullptr_t) : Object(nullptr)
    {
    }

    ToolbarItem::ToolbarItem(Adopt adopt) : Object(adopt)
    {
    }

    void ToolbarItem::validate() const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) validate];
    }

    std::string ToolbarItem::action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSToolbarItem>(this) action]));
    }

    void ToolbarItem::set_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    bool ToolbarItem::autovalidates() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSToolbarItem>(this) autovalidates]);
    }

    void ToolbarItem::set_autovalidates(bool value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setAutovalidates:static_cast<::BOOL>(value)];
    }

    Color ToolbarItem::background_tint_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSToolbarItem>(this) backgroundTintColor]);
    }

    void ToolbarItem::set_background_tint_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setBackgroundTintColor:cocoon::internal::native<::NSColor>(value)];
    }

    ItemBadge ToolbarItem::badge() const
    {
        return cocoon::internal::wrap<ItemBadge>([cocoon::internal::ns<::NSToolbarItem>(this) badge]);
    }

    void ToolbarItem::set_badge(const ItemBadge& value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setBadge:cocoon::internal::native<::NSItemBadge>(value)];
    }

    bool ToolbarItem::is_bordered() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSToolbarItem>(this) isBordered]);
    }

    void ToolbarItem::set_bordered(bool value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setBordered:static_cast<::BOOL>(value)];
    }

    bool ToolbarItem::is_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSToolbarItem>(this) isEnabled]);
    }

    void ToolbarItem::set_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setEnabled:static_cast<::BOOL>(value)];
    }

    bool ToolbarItem::is_hidden() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSToolbarItem>(this) isHidden]);
    }

    void ToolbarItem::set_hidden(bool value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setHidden:static_cast<::BOOL>(value)];
    }

    Image ToolbarItem::image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSToolbarItem>(this) image]);
    }

    void ToolbarItem::set_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setImage:cocoon::internal::native<::NSImage>(value)];
    }

    std::string ToolbarItem::item_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSToolbarItem>(this) itemIdentifier]);
    }

    std::string ToolbarItem::label() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSToolbarItem>(this) label]);
    }

    void ToolbarItem::set_label(const std::string& value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setLabel:cocoon::internal::to(value)];
    }

    MenuItem ToolbarItem::menu_form_representation() const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSToolbarItem>(this) menuFormRepresentation]);
    }

    void ToolbarItem::set_menu_form_representation(const MenuItem& value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setMenuFormRepresentation:cocoon::internal::native<::NSMenuItem>(value)];
    }

    bool ToolbarItem::is_navigational() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSToolbarItem>(this) isNavigational]);
    }

    void ToolbarItem::set_navigational(bool value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setNavigational:static_cast<::BOOL>(value)];
    }

    std::string ToolbarItem::palette_label() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSToolbarItem>(this) paletteLabel]);
    }

    void ToolbarItem::set_palette_label(const std::string& value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setPaletteLabel:cocoon::internal::to(value)];
    }

    std::vector<std::string> ToolbarItem::possible_labels() const
    {
        return cocoon::internal::from_array<std::string>([[cocoon::internal::ns<::NSToolbarItem>(this) possibleLabels] allObjects], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    void ToolbarItem::set_possible_labels(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setPossibleLabels:[NSSet setWithArray:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                          {
                                                                                              return cocoon::internal::to(e);
                                                                                          })]];
    }

    ToolbarItemStyle ToolbarItem::style() const
    {
        return static_cast<ToolbarItemStyle>([cocoon::internal::ns<::NSToolbarItem>(this) style]);
    }

    void ToolbarItem::set_style(ToolbarItemStyle value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setStyle:static_cast<::NSToolbarItemStyle>(value)];
    }

    std::int64_t ToolbarItem::tag() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSToolbarItem>(this) tag]);
    }

    void ToolbarItem::set_tag(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setTag:static_cast<::NSInteger>(value)];
    }

    Object ToolbarItem::target() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSToolbarItem>(this) target]);
    }

    void ToolbarItem::set_target(const Object& value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setTarget:cocoon::internal::native_id(value)];
    }

    std::string ToolbarItem::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSToolbarItem>(this) title]);
    }

    void ToolbarItem::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setTitle:cocoon::internal::to(value)];
    }

    std::string ToolbarItem::tool_tip() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSToolbarItem>(this) toolTip]);
    }

    void ToolbarItem::set_tool_tip(const std::string& value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setToolTip:cocoon::internal::to(value)];
    }

    Toolbar ToolbarItem::toolbar() const
    {
        return cocoon::internal::wrap<Toolbar>([cocoon::internal::ns<::NSToolbarItem>(this) toolbar]);
    }

    View ToolbarItem::view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSToolbarItem>(this) view]);
    }

    void ToolbarItem::set_view(const View& value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setView:cocoon::internal::native<::NSView>(value)];
    }

    std::int64_t ToolbarItem::visibility_priority() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSToolbarItem>(this) visibilityPriority]);
    }

    void ToolbarItem::set_visibility_priority(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSToolbarItem>(this) setVisibilityPriority:static_cast<::NSToolbarItemVisibilityPriority>(value)];
    }

    bool ToolbarItem::is_visible() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSToolbarItem>(this) isVisible]);
    }

    void ToolbarItem::bind_action_(void* native)
    {
        id host = (__bridge id)native;
        cocoon::internal::bind_action(host, host, [](id host, id sender)
                        {
                            cocoon::Signal<cocoon::ToolbarItem, void()>::emit((__bridge void*)host, "clicked");
                        });
    }
}
