#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class DraggingImageComponent;
    class ImageView;
    class TextField;

    /**
     * @brief C++ handle for the Objective-C class `NSTableCellView` (AppKit).
     * @details View Based NSTableView: The NSTableCellView is a reusable container view shown for a particular cell in the table. See NSTableView.h for more information.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TableCellView table_cell_view;
     * table_cell_view.set_background_style(cocoon::BackgroundStyle::Normal);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TableCellView table_cell_view{};
     * table_cell_view.set_background_style(cocoon::BackgroundStyle::Normal);
     * auto background_style = table_cell_view.background_style();
     * table_cell_view.set_image_view(cocoon::ImageView());
     * auto image_view = table_cell_view.image_view();
     * table_cell_view.set_row_size_style(cocoon::TableViewRowSizeStyle::Default);
     * auto row_size_style = table_cell_view.row_size_style();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstablecellview
     */
    class TableCellView : public View
    {
    public:
        /// @brief Creates a new `NSTableCellView` instance and returns a handle to it.
        explicit TableCellView();
        /// @brief Creates a null handle that refers to no native object.
        TableCellView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TableCellView(Adopt adopt);
        /**
         * @brief Returns the `backgroundStyle` property of `NSTableCellView`.
         * @details The backgroundStyle property is automatically set by the enclosing NSTableRowView to let this view know what its background looks like. For instance, when the -backgroundStyle is NSBackgroundStyleEmphasized, the view should use a contrasting text color. The system label colors (labelColor, secondaryLabelColor, tertiaryLabelColor, and quaternaryLabelColor) automatically adapt when displayed with an emphasized backgroundStyle. Upon setting, the default implementation automatically forwards calls to all subviews that implement -setBackgroundStyle: or are an NSControl (which have NSCells that respond to -setBackgroundStyle:).
         * @return The converted Objective-C result.
         */
        BackgroundStyle background_style() const;
        /**
         * @brief Sets the `backgroundStyle` property of `NSTableCellView`.
         * @details The backgroundStyle property is automatically set by the enclosing NSTableRowView to let this view know what its background looks like. For instance, when the -backgroundStyle is NSBackgroundStyleEmphasized, the view should use a contrasting text color. The system label colors (labelColor, secondaryLabelColor, tertiaryLabelColor, and quaternaryLabelColor) automatically adapt when displayed with an emphasized backgroundStyle. Upon setting, the default implementation automatically forwards calls to all subviews that implement -setBackgroundStyle: or are an NSControl (which have NSCells that respond to -setBackgroundStyle:).
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_background_style(BackgroundStyle value) const;
        /**
         * @brief Returns the `draggingImageComponents` property of `NSTableCellView`.
         * @details Multi-Item Drag Support. The default implementation will return an array of up to two NSDraggingImageComponent instances -- one for the imageView and another for the textField (if not nil). These methods can be subclassed and overridden to provide a custom set of NSDraggingImageComponents to create the drag image from this view.
         * @return The converted Objective-C result.
         */
        std::vector<DraggingImageComponent> dragging_image_components() const;
        /**
         * @brief Returns the `imageView` property of `NSTableCellView`.
         * @return The converted Objective-C result.
         */
        ImageView image_view() const;
        /**
         * @brief Sets the `imageView` property of `NSTableCellView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_image_view(const ImageView& value) const;
        /**
         * @brief Returns the `objectValue` property of `NSTableCellView`.
         * @details The 'objectValue' is automatically set by the table when using bindings, or the result from the dataSource method -tableView:objectValueForTableColumn:row:. Key Value Observing (KVO) compliant so user interface elements can be bound to the 'objectValue'.
         * @return The converted Objective-C result.
         */
        Object object_value() const;
        /**
         * @brief Sets the `objectValue` property of `NSTableCellView`.
         * @details The 'objectValue' is automatically set by the table when using bindings, or the result from the dataSource method -tableView:objectValueForTableColumn:row:. Key Value Observing (KVO) compliant so user interface elements can be bound to the 'objectValue'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_object_value(const Object& value) const;
        /**
         * @brief Returns the `rowSizeStyle` property of `NSTableCellView`.
         * @details The rowSizeStyle is set by the NSTableView to its -effectiveRowSizeStyle. The cell view will layout the textField and imageView based on the rowSizeStyle. A value of NSTableViewRowSizeStyleDefault should never be set on the cell view, as it is an appropriate value only for the table. See NSTableView.h for more information.
         * @return The converted Objective-C result.
         */
        TableViewRowSizeStyle row_size_style() const;
        /**
         * @brief Sets the `rowSizeStyle` property of `NSTableCellView`.
         * @details The rowSizeStyle is set by the NSTableView to its -effectiveRowSizeStyle. The cell view will layout the textField and imageView based on the rowSizeStyle. A value of NSTableViewRowSizeStyleDefault should never be set on the cell view, as it is an appropriate value only for the table. See NSTableView.h for more information.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_row_size_style(TableViewRowSizeStyle value) const;
        /**
         * @brief Returns the `textField` property of `NSTableCellView`.
         * @details The following two properties are provided for the developer to hook up as outlets. These outlets can then be accessed in -tableView:viewForTableColumn:row: and modified. Additional outlets can be added by subclassing NSTableCellView, adding appropriate ivars and properties, and hooking it up in Interface Builder.
         * @return The converted Objective-C result.
         */
        TextField text_field() const;
        /**
         * @brief Sets the `textField` property of `NSTableCellView`.
         * @details The following two properties are provided for the developer to hook up as outlets. These outlets can then be accessed in -tableView:viewForTableColumn:row: and modified. Additional outlets can be added by subclassing NSTableCellView, adding appropriate ivars and properties, and hooking it up in Interface Builder.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_text_field(const TextField& value) const;
    };
}
