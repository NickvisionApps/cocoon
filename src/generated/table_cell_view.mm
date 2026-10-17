#include "generated/table_cell_view.h"
#include "internal.h"

namespace cocoon
{
    TableCellView::TableCellView() : TableCellView(Adopt{cocoon::internal::retain([[::NSTableCellView alloc] init])})
    {
    }

    TableCellView::TableCellView(std::nullptr_t) : View(nullptr)
    {
    }

    TableCellView::TableCellView(Adopt adopt) : View(adopt)
    {
    }

    BackgroundStyle TableCellView::background_style() const
    {
        return static_cast<BackgroundStyle>([cocoon::internal::ns<::NSTableCellView>(this) backgroundStyle]);
    }

    void TableCellView::set_background_style(BackgroundStyle value) const
    {
        [cocoon::internal::ns<::NSTableCellView>(this) setBackgroundStyle:static_cast<::NSBackgroundStyle>(value)];
    }

    std::vector<DraggingImageComponent> TableCellView::dragging_image_components() const
    {
        return cocoon::internal::from_array<DraggingImageComponent>([cocoon::internal::ns<::NSTableCellView>(this) draggingImageComponents], [](id e) -> DraggingImageComponent
                                                      {
                                                          return cocoon::internal::wrap<DraggingImageComponent>((::NSDraggingImageComponent*)e);
                                                      });
    }

    ImageView TableCellView::image_view() const
    {
        return cocoon::internal::wrap<ImageView>([cocoon::internal::ns<::NSTableCellView>(this) imageView]);
    }

    void TableCellView::set_image_view(const ImageView& value) const
    {
        [cocoon::internal::ns<::NSTableCellView>(this) setImageView:cocoon::internal::native<::NSImageView>(value)];
    }

    Object TableCellView::object_value() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTableCellView>(this) objectValue]);
    }

    void TableCellView::set_object_value(const Object& value) const
    {
        [cocoon::internal::ns<::NSTableCellView>(this) setObjectValue:cocoon::internal::native_id(value)];
    }

    TableViewRowSizeStyle TableCellView::row_size_style() const
    {
        return static_cast<TableViewRowSizeStyle>([cocoon::internal::ns<::NSTableCellView>(this) rowSizeStyle]);
    }

    void TableCellView::set_row_size_style(TableViewRowSizeStyle value) const
    {
        [cocoon::internal::ns<::NSTableCellView>(this) setRowSizeStyle:static_cast<::NSTableViewRowSizeStyle>(value)];
    }

    TextField TableCellView::text_field() const
    {
        return cocoon::internal::wrap<TextField>([cocoon::internal::ns<::NSTableCellView>(this) textField]);
    }

    void TableCellView::set_text_field(const TextField& value) const
    {
        [cocoon::internal::ns<::NSTableCellView>(this) setTextField:cocoon::internal::native<::NSTextField>(value)];
    }
}
