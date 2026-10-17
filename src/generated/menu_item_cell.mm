#include "generated/menu_item_cell.h"
#include "internal.h"

namespace cocoon
{
    MenuItemCell::MenuItemCell(const std::string& string) : MenuItemCell(Adopt{cocoon::internal::retain([[::NSMenuItemCell alloc] initTextCell:cocoon::internal::to(string)])})
    {
    }

    MenuItemCell::MenuItemCell() : MenuItemCell(Adopt{cocoon::internal::retain([[::NSMenuItemCell alloc] init])})
    {
    }

    MenuItemCell::MenuItemCell(std::nullptr_t) : ButtonCell(nullptr)
    {
    }

    MenuItemCell::MenuItemCell(Adopt adopt) : ButtonCell(adopt)
    {
    }

    void MenuItemCell::calc_size() const
    {
        [cocoon::internal::ns<::NSMenuItemCell>(this) calcSize];
    }

    void MenuItemCell::draw_border_and_background_with_frame(const Rect& cell_frame, const View& control_view) const
    {
        [cocoon::internal::ns<::NSMenuItemCell>(this) drawBorderAndBackgroundWithFrame:cocoon::internal::to(cell_frame) inView:cocoon::internal::native<::NSView>(control_view)];
    }

    void MenuItemCell::draw_image_with_frame(const Rect& cell_frame, const View& control_view) const
    {
        [cocoon::internal::ns<::NSMenuItemCell>(this) drawImageWithFrame:cocoon::internal::to(cell_frame) inView:cocoon::internal::native<::NSView>(control_view)];
    }

    void MenuItemCell::draw_key_equivalent_with_frame(const Rect& cell_frame, const View& control_view) const
    {
        [cocoon::internal::ns<::NSMenuItemCell>(this) drawKeyEquivalentWithFrame:cocoon::internal::to(cell_frame) inView:cocoon::internal::native<::NSView>(control_view)];
    }

    void MenuItemCell::draw_separator_item_with_frame(const Rect& cell_frame, const View& control_view) const
    {
        [cocoon::internal::ns<::NSMenuItemCell>(this) drawSeparatorItemWithFrame:cocoon::internal::to(cell_frame) inView:cocoon::internal::native<::NSView>(control_view)];
    }

    void MenuItemCell::draw_state_image_with_frame(const Rect& cell_frame, const View& control_view) const
    {
        [cocoon::internal::ns<::NSMenuItemCell>(this) drawStateImageWithFrame:cocoon::internal::to(cell_frame) inView:cocoon::internal::native<::NSView>(control_view)];
    }

    void MenuItemCell::draw_title_with_frame(const Rect& cell_frame, const View& control_view) const
    {
        [cocoon::internal::ns<::NSMenuItemCell>(this) drawTitleWithFrame:cocoon::internal::to(cell_frame) inView:cocoon::internal::native<::NSView>(control_view)];
    }

    Rect MenuItemCell::key_equivalent_rect_for_bounds(const Rect& cell_frame) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMenuItemCell>(this) keyEquivalentRectForBounds:cocoon::internal::to(cell_frame)]);
    }

    Rect MenuItemCell::state_image_rect_for_bounds(const Rect& cell_frame) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMenuItemCell>(this) stateImageRectForBounds:cocoon::internal::to(cell_frame)]);
    }

    Rect MenuItemCell::title_rect_for_bounds(const Rect& cell_frame) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMenuItemCell>(this) titleRectForBounds:cocoon::internal::to(cell_frame)]);
    }

    double MenuItemCell::image_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMenuItemCell>(this) imageWidth]);
    }

    double MenuItemCell::key_equivalent_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMenuItemCell>(this) keyEquivalentWidth]);
    }

    MenuItem MenuItemCell::menu_item() const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSMenuItemCell>(this) menuItem]);
    }

    void MenuItemCell::set_menu_item(const MenuItem& value) const
    {
        [cocoon::internal::ns<::NSMenuItemCell>(this) setMenuItem:cocoon::internal::native<::NSMenuItem>(value)];
    }

    bool MenuItemCell::needs_display() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenuItemCell>(this) needsDisplay]);
    }

    void MenuItemCell::set_needs_display(bool value) const
    {
        [cocoon::internal::ns<::NSMenuItemCell>(this) setNeedsDisplay:static_cast<::BOOL>(value)];
    }

    bool MenuItemCell::needs_sizing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMenuItemCell>(this) needsSizing]);
    }

    void MenuItemCell::set_needs_sizing(bool value) const
    {
        [cocoon::internal::ns<::NSMenuItemCell>(this) setNeedsSizing:static_cast<::BOOL>(value)];
    }

    double MenuItemCell::state_image_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMenuItemCell>(this) stateImageWidth]);
    }

    std::int64_t MenuItemCell::tag() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSMenuItemCell>(this) tag]);
    }

    void MenuItemCell::set_tag(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSMenuItemCell>(this) setTag:static_cast<::NSInteger>(value)];
    }

    double MenuItemCell::title_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMenuItemCell>(this) titleWidth]);
    }
}
