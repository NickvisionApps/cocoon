#include "generated/table_view_row_action.h"
#include "internal.h"

namespace cocoon
{
    TableViewRowAction::TableViewRowAction() : TableViewRowAction(Adopt{cocoon::internal::retain([[::NSTableViewRowAction alloc] init])})
    {
    }

    TableViewRowAction::TableViewRowAction(std::nullptr_t) : Object(nullptr)
    {
    }

    TableViewRowAction::TableViewRowAction(Adopt adopt) : Object(adopt)
    {
    }

    TableViewRowAction TableViewRowAction::row_action_with_style(TableViewRowActionStyle style, const std::string& title, std::function<void(TableViewRowAction, std::int64_t)> handler)
    {
        return cocoon::internal::wrap<TableViewRowAction>([::NSTableViewRowAction rowActionWithStyle:static_cast<::NSTableViewRowActionStyle>(style) title:cocoon::internal::to(title) handler:(handler ? (void (^)(::NSTableViewRowAction*, ::NSInteger)) ^ void(::NSTableViewRowAction * a93_0, ::NSInteger a93_1) { handler(cocoon::internal::wrap<TableViewRowAction>(a93_0), static_cast<std::int64_t>(a93_1)); } : (void (^)(::NSTableViewRowAction*, ::NSInteger))nil)]);
    }

    Color TableViewRowAction::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSTableViewRowAction>(this) backgroundColor]);
    }

    void TableViewRowAction::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSTableViewRowAction>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    Image TableViewRowAction::image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSTableViewRowAction>(this) image]);
    }

    void TableViewRowAction::set_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSTableViewRowAction>(this) setImage:cocoon::internal::native<::NSImage>(value)];
    }

    TableViewRowActionStyle TableViewRowAction::style() const
    {
        return static_cast<TableViewRowActionStyle>([cocoon::internal::ns<::NSTableViewRowAction>(this) style]);
    }

    std::string TableViewRowAction::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTableViewRowAction>(this) title]);
    }

    void TableViewRowAction::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTableViewRowAction>(this) setTitle:cocoon::internal::to(value)];
    }
}
