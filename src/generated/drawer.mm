#include "generated/drawer.h"
#include "internal.h"

namespace cocoon
{
    Drawer::Drawer(const Size& content_size, RectEdge edge) : Drawer(Adopt{cocoon::internal::retain([[::NSDrawer alloc] initWithContentSize:cocoon::internal::to(content_size) preferredEdge:static_cast<::NSRectEdge>(edge)])})
    {
    }

    Drawer::Drawer() : Drawer(Adopt{cocoon::internal::retain([[::NSDrawer alloc] init])})
    {
    }

    Drawer::Drawer(std::nullptr_t) : Responder(nullptr)
    {
    }

    Drawer::Drawer(Adopt adopt) : Responder(adopt)
    {
    }

    void Drawer::close() const
    {
        [cocoon::internal::ns<::NSDrawer>(this) close];
    }

    void Drawer::close(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDrawer>(this) close:cocoon::internal::native_id(sender)];
    }

    void Drawer::open() const
    {
        [cocoon::internal::ns<::NSDrawer>(this) open];
    }

    void Drawer::open(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDrawer>(this) open:cocoon::internal::native_id(sender)];
    }

    void Drawer::open_on_edge(RectEdge edge) const
    {
        [cocoon::internal::ns<::NSDrawer>(this) openOnEdge:static_cast<::NSRectEdge>(edge)];
    }

    void Drawer::toggle(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDrawer>(this) toggle:cocoon::internal::native_id(sender)];
    }

    Size Drawer::content_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDrawer>(this) contentSize]);
    }

    void Drawer::set_content_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSDrawer>(this) setContentSize:cocoon::internal::to(value)];
    }

    View Drawer::content_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSDrawer>(this) contentView]);
    }

    void Drawer::set_content_view(const View& value) const
    {
        [cocoon::internal::ns<::NSDrawer>(this) setContentView:cocoon::internal::native<::NSView>(value)];
    }

    RectEdge Drawer::edge() const
    {
        return static_cast<RectEdge>([cocoon::internal::ns<::NSDrawer>(this) edge]);
    }

    double Drawer::leading_offset() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSDrawer>(this) leadingOffset]);
    }

    void Drawer::set_leading_offset(double value) const
    {
        [cocoon::internal::ns<::NSDrawer>(this) setLeadingOffset:static_cast<::CGFloat>(value)];
    }

    Size Drawer::max_content_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDrawer>(this) maxContentSize]);
    }

    void Drawer::set_max_content_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSDrawer>(this) setMaxContentSize:cocoon::internal::to(value)];
    }

    Size Drawer::min_content_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDrawer>(this) minContentSize]);
    }

    void Drawer::set_min_content_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSDrawer>(this) setMinContentSize:cocoon::internal::to(value)];
    }

    Window Drawer::parent_window() const
    {
        return cocoon::internal::wrap<Window>([cocoon::internal::ns<::NSDrawer>(this) parentWindow]);
    }

    void Drawer::set_parent_window(const Window& value) const
    {
        [cocoon::internal::ns<::NSDrawer>(this) setParentWindow:cocoon::internal::native<::NSWindow>(value)];
    }

    RectEdge Drawer::preferred_edge() const
    {
        return static_cast<RectEdge>([cocoon::internal::ns<::NSDrawer>(this) preferredEdge]);
    }

    void Drawer::set_preferred_edge(RectEdge value) const
    {
        [cocoon::internal::ns<::NSDrawer>(this) setPreferredEdge:static_cast<::NSRectEdge>(value)];
    }

    std::int64_t Drawer::state() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDrawer>(this) state]);
    }

    double Drawer::trailing_offset() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSDrawer>(this) trailingOffset]);
    }

    void Drawer::set_trailing_offset(double value) const
    {
        [cocoon::internal::ns<::NSDrawer>(this) setTrailingOffset:static_cast<::CGFloat>(value)];
    }
}
