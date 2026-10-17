#include "generated/window_tab.h"
#include "internal.h"

namespace cocoon
{
    WindowTab::WindowTab() : WindowTab(Adopt{cocoon::internal::retain([[::NSWindowTab alloc] init])})
    {
    }

    WindowTab::WindowTab(std::nullptr_t) : Object(nullptr)
    {
    }

    WindowTab::WindowTab(Adopt adopt) : Object(adopt)
    {
    }

    View WindowTab::accessory_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSWindowTab>(this) accessoryView]);
    }

    void WindowTab::set_accessory_view(const View& value) const
    {
        [cocoon::internal::ns<::NSWindowTab>(this) setAccessoryView:cocoon::internal::native<::NSView>(value)];
    }

    AttributedString WindowTab::attributed_title() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSWindowTab>(this) attributedTitle]);
    }

    void WindowTab::set_attributed_title(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSWindowTab>(this) setAttributedTitle:cocoon::internal::native<::NSAttributedString>(value)];
    }

    std::string WindowTab::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindowTab>(this) title]);
    }

    void WindowTab::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSWindowTab>(this) setTitle:cocoon::internal::to(value)];
    }

    std::string WindowTab::tool_tip() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindowTab>(this) toolTip]);
    }

    void WindowTab::set_tool_tip(const std::string& value) const
    {
        [cocoon::internal::ns<::NSWindowTab>(this) setToolTip:cocoon::internal::to(value)];
    }
}
