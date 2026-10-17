#include "generated/font_panel.h"
#include "internal.h"

namespace cocoon
{
    FontPanel::FontPanel() : FontPanel(Adopt{cocoon::internal::retain([[::NSFontPanel alloc] init])})
    {
        Window::install_delegate_delegate_(handle());
    }

    FontPanel::FontPanel(std::nullptr_t) : Panel(nullptr)
    {
    }

    FontPanel::FontPanel(Adopt adopt) : Panel(adopt)
    {
    }

    Font FontPanel::panel_convert_font(const Font& font_obj) const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSFontPanel>(this) panelConvertFont:cocoon::internal::native<::NSFont>(font_obj)]);
    }

    void FontPanel::reload_default_font_families() const
    {
        [cocoon::internal::ns<::NSFontPanel>(this) reloadDefaultFontFamilies];
    }

    void FontPanel::set_panel_font(const Font& font_obj, bool flag) const
    {
        [cocoon::internal::ns<::NSFontPanel>(this) setPanelFont:cocoon::internal::native<::NSFont>(font_obj) isMultiple:static_cast<::BOOL>(flag)];
    }

    View FontPanel::accessory_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSFontPanel>(this) accessoryView]);
    }

    void FontPanel::set_accessory_view(const View& value) const
    {
        [cocoon::internal::ns<::NSFontPanel>(this) setAccessoryView:cocoon::internal::native<::NSView>(value)];
    }

    bool FontPanel::is_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFontPanel>(this) isEnabled]);
    }

    void FontPanel::set_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSFontPanel>(this) setEnabled:static_cast<::BOOL>(value)];
    }

    FontPanel FontPanel::shared_font_panel()
    {
        return cocoon::internal::wrap<FontPanel>([::NSFontPanel sharedFontPanel]);
    }

    bool FontPanel::shared_font_panel_exists()
    {
        return static_cast<bool>([::NSFontPanel sharedFontPanelExists]);
    }

    bool FontPanel::works_when_modal() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFontPanel>(this) worksWhenModal]);
    }

    void FontPanel::set_works_when_modal(bool value) const
    {
        [cocoon::internal::ns<::NSFontPanel>(this) setWorksWhenModal:static_cast<::BOOL>(value)];
    }
}
