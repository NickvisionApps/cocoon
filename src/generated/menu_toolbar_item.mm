#include "generated/menu_toolbar_item.h"
#include "internal.h"

namespace cocoon
{
    MenuToolbarItem::MenuToolbarItem() : MenuToolbarItem(Adopt{cocoon::internal::retain([[::NSMenuToolbarItem alloc] init])})
    {
        ToolbarItem::bind_action_(handle());
    }

    MenuToolbarItem::MenuToolbarItem(std::nullptr_t) : ToolbarItem(nullptr)
    {
    }

    MenuToolbarItem::MenuToolbarItem(Adopt adopt) : ToolbarItem(adopt)
    {
    }

    Menu MenuToolbarItem::menu() const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSMenuToolbarItem>(this) menu]);
    }

    void MenuToolbarItem::set_menu(const Menu& value) const
    {
        [cocoon::internal::ns<::NSMenuToolbarItem>(this) setMenu:cocoon::internal::native<::NSMenu>(value)];
    }

    bool MenuToolbarItem::shows_indicator() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenuToolbarItem>(this) showsIndicator]);
    }

    void MenuToolbarItem::set_shows_indicator(bool value) const
    {
        [cocoon::internal::ns<::NSMenuToolbarItem>(this) setShowsIndicator:static_cast<::BOOL>(value)];
    }
}
