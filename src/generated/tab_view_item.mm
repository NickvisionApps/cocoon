#include "generated/tab_view_item.h"
#include "internal.h"

namespace cocoon
{
    TabViewItem::TabViewItem(const Object& identifier) : TabViewItem(Adopt{cocoon::internal::retain([[::NSTabViewItem alloc] initWithIdentifier:cocoon::internal::native_id(identifier)])})
    {
    }

    TabViewItem::TabViewItem(const ViewController& view_controller) : TabViewItem(Adopt{cocoon::internal::retain([::NSTabViewItem tabViewItemWithViewController:cocoon::internal::native<::NSViewController>(view_controller)])})
    {
    }

    TabViewItem::TabViewItem() : TabViewItem(Adopt{cocoon::internal::retain([[::NSTabViewItem alloc] init])})
    {
    }

    TabViewItem::TabViewItem(std::nullptr_t) : Object(nullptr)
    {
    }

    TabViewItem::TabViewItem(Adopt adopt) : Object(adopt)
    {
    }

    void TabViewItem::draw_label(bool should_truncate_label, const Rect& label_rect) const
    {
        [cocoon::internal::ns<::NSTabViewItem>(this) drawLabel:static_cast<::BOOL>(should_truncate_label) inRect:cocoon::internal::to(label_rect)];
    }

    Size TabViewItem::size_of_label(bool compute_min) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTabViewItem>(this) sizeOfLabel:static_cast<::BOOL>(compute_min)]);
    }

    Color TabViewItem::color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSTabViewItem>(this) color]);
    }

    void TabViewItem::set_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSTabViewItem>(this) setColor:cocoon::internal::native<::NSColor>(value)];
    }

    Object TabViewItem::identifier() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTabViewItem>(this) identifier]);
    }

    void TabViewItem::set_identifier(const Object& value) const
    {
        [cocoon::internal::ns<::NSTabViewItem>(this) setIdentifier:cocoon::internal::native_id(value)];
    }

    Image TabViewItem::image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSTabViewItem>(this) image]);
    }

    void TabViewItem::set_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSTabViewItem>(this) setImage:cocoon::internal::native<::NSImage>(value)];
    }

    View TabViewItem::initial_first_responder() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSTabViewItem>(this) initialFirstResponder]);
    }

    void TabViewItem::set_initial_first_responder(const View& value) const
    {
        [cocoon::internal::ns<::NSTabViewItem>(this) setInitialFirstResponder:cocoon::internal::native<::NSView>(value)];
    }

    std::string TabViewItem::label() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTabViewItem>(this) label]);
    }

    void TabViewItem::set_label(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTabViewItem>(this) setLabel:cocoon::internal::to(value)];
    }

    TabState TabViewItem::tab_state() const
    {
        return static_cast<TabState>([cocoon::internal::ns<::NSTabViewItem>(this) tabState]);
    }

    TabView TabViewItem::tab_view() const
    {
        return cocoon::internal::wrap<TabView>([cocoon::internal::ns<::NSTabViewItem>(this) tabView]);
    }

    std::string TabViewItem::tool_tip() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTabViewItem>(this) toolTip]);
    }

    void TabViewItem::set_tool_tip(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTabViewItem>(this) setToolTip:cocoon::internal::to(value)];
    }

    View TabViewItem::view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSTabViewItem>(this) view]);
    }

    void TabViewItem::set_view(const View& value) const
    {
        [cocoon::internal::ns<::NSTabViewItem>(this) setView:cocoon::internal::native<::NSView>(value)];
    }

    ViewController TabViewItem::view_controller() const
    {
        return cocoon::internal::wrap<ViewController>([cocoon::internal::ns<::NSTabViewItem>(this) viewController]);
    }

    void TabViewItem::set_view_controller(const ViewController& value) const
    {
        [cocoon::internal::ns<::NSTabViewItem>(this) setViewController:cocoon::internal::native<::NSViewController>(value)];
    }
}
