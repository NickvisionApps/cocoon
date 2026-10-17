#include "generated/window_tab_group.h"
#include "internal.h"

namespace cocoon
{
    WindowTabGroup::WindowTabGroup() : WindowTabGroup(Adopt{cocoon::internal::retain([[::NSWindowTabGroup alloc] init])})
    {
    }

    WindowTabGroup::WindowTabGroup(std::nullptr_t) : Object(nullptr)
    {
    }

    WindowTabGroup::WindowTabGroup(Adopt adopt) : Object(adopt)
    {
    }

    void WindowTabGroup::add_window(const Window& window) const
    {
        [cocoon::internal::ns<::NSWindowTabGroup>(this) addWindow:cocoon::internal::native<::NSWindow>(window)];
    }

    void WindowTabGroup::insert_window(const Window& window, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSWindowTabGroup>(this) insertWindow:cocoon::internal::native<::NSWindow>(window) atIndex:static_cast<::NSInteger>(index)];
    }

    void WindowTabGroup::remove_window(const Window& window) const
    {
        [cocoon::internal::ns<::NSWindowTabGroup>(this) removeWindow:cocoon::internal::native<::NSWindow>(window)];
    }

    std::string WindowTabGroup::identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindowTabGroup>(this) identifier]);
    }

    bool WindowTabGroup::is_overview_visible() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindowTabGroup>(this) isOverviewVisible]);
    }

    void WindowTabGroup::set_overview_visible(bool value) const
    {
        [cocoon::internal::ns<::NSWindowTabGroup>(this) setOverviewVisible:static_cast<::BOOL>(value)];
    }

    Window WindowTabGroup::selected_window() const
    {
        return cocoon::internal::wrap<Window>([cocoon::internal::ns<::NSWindowTabGroup>(this) selectedWindow]);
    }

    void WindowTabGroup::set_selected_window(const Window& value) const
    {
        [cocoon::internal::ns<::NSWindowTabGroup>(this) setSelectedWindow:cocoon::internal::native<::NSWindow>(value)];
    }

    bool WindowTabGroup::is_tab_bar_visible() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindowTabGroup>(this) isTabBarVisible]);
    }

    std::vector<Window> WindowTabGroup::windows() const
    {
        return cocoon::internal::from_array<Window>([cocoon::internal::ns<::NSWindowTabGroup>(this) windows], [](id e) -> Window
                                      {
                                          return cocoon::internal::wrap<Window>((::NSWindow*)e);
                                      });
    }
}
