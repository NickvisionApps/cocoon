#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class Image;

    /**
     * @brief C++ handle for the Objective-C class `NSTableViewRowAction` (AppKit).
     * @details An array of this class should be returned from the NSTableView delegate method tableView:rowActionsForRow:edge:.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TableViewRowAction table_view_row_action;
     * table_view_row_action.set_background_color(cocoon::Color());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TableViewRowAction table_view_row_action{};
     * table_view_row_action.set_background_color(cocoon::Color());
     * auto background_color = table_view_row_action.background_color();
     * table_view_row_action.set_image(cocoon::Image());
     * auto image = table_view_row_action.image();
     * table_view_row_action.set_title("text");
     * auto title = table_view_row_action.title();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstableviewrowaction
     */
    class TableViewRowAction : public Object
    {
    public:
        /// @brief Creates a new `NSTableViewRowAction` instance and returns a handle to it.
        explicit TableViewRowAction();
        /// @brief Creates a null handle that refers to no native object.
        TableViewRowAction(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TableViewRowAction(Adopt adopt);
        /**
     * @brief Calls `+[NSTableViewRowAction rowActionWithStyle:title:handler:]`.
     * @param style Argument converted to the Objective-C parameter of the same role.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TableViewRowAction row_action_with_style(TableViewRowActionStyle style, const std::string& title, std::function<void(TableViewRowAction, std::int64_t)> handler);
        /**
     * @brief Returns the `backgroundColor` property of `NSTableViewRowAction`.
     * @return The converted Objective-C result.
     */
        Color background_color() const;
        /**
     * @brief Sets the `backgroundColor` property of `NSTableViewRowAction`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_color(const Color& value) const;
        /**
     * @brief Returns the `image` property of `NSTableViewRowAction`.
     * @details Prefer using an image over text for the row action button
     * @return The converted Objective-C result.
     */
        Image image() const;
        /**
     * @brief Sets the `image` property of `NSTableViewRowAction`.
     * @details Prefer using an image over text for the row action button
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image(const Image& value) const;
        /**
     * @brief Returns the `style` property of `NSTableViewRowAction`.
     * @return The converted Objective-C result.
     */
        TableViewRowActionStyle style() const;
        /**
     * @brief Returns the `title` property of `NSTableViewRowAction`.
     * @return The converted Objective-C result.
     */
        std::string title() const;
        /**
     * @brief Sets the `title` property of `NSTableViewRowAction`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title(const std::string& value) const;
    };
}
