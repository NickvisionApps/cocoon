#pragma once

#include "generated/availability.h"
#include "generated/button_cell.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class MenuItem;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSMenuItemCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ButtonCell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MenuItemCell menu_item_cell;
     * menu_item_cell.set_menu_item(cocoon::MenuItem());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MenuItemCell menu_item_cell{};
     * menu_item_cell.set_menu_item(cocoon::MenuItem());
     * auto menu_item = menu_item_cell.menu_item();
     * menu_item_cell.set_needs_display(true);
     * auto needs_display = menu_item_cell.needs_display();
     * menu_item_cell.set_needs_sizing(true);
     * auto needs_sizing = menu_item_cell.needs_sizing();
     * menu_item_cell.calc_size();
     * menu_item_cell.draw_border_and_background_with_frame({{0, 0}, {100, 100}}, cocoon::View());
     * menu_item_cell.draw_image_with_frame({{0, 0}, {100, 100}}, cocoon::View());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsmenuitemcell
     */
    class MenuItemCell : public ButtonCell
    {
    public:
        /// @brief Creates a new `NSMenuItemCell` instance and returns a handle to it.
        explicit MenuItemCell(const std::string& string);
        /// @brief Creates a new `NSMenuItemCell` instance and returns a handle to it.
        explicit MenuItemCell();
        /// @brief Creates a null handle that refers to no native object.
        MenuItemCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MenuItemCell(Adopt adopt);
        using ActionCell::set_tag;
        using ActionCell::tag;
        using Cell::title_rect_for_bounds;
        /**
     * @brief Calls `-[NSMenuItemCell calcSize]`.
     */
        void calc_size() const;
        /**
     * @brief Calls `-[NSMenuItemCell drawBorderAndBackgroundWithFrame:inView:]`.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     */
        void draw_border_and_background_with_frame(const Rect& cell_frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSMenuItemCell drawImageWithFrame:inView:]`.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     */
        void draw_image_with_frame(const Rect& cell_frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSMenuItemCell drawKeyEquivalentWithFrame:inView:]`.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     */
        void draw_key_equivalent_with_frame(const Rect& cell_frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSMenuItemCell drawSeparatorItemWithFrame:inView:]`.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     */
        void draw_separator_item_with_frame(const Rect& cell_frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSMenuItemCell drawStateImageWithFrame:inView:]`.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     */
        void draw_state_image_with_frame(const Rect& cell_frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSMenuItemCell drawTitleWithFrame:inView:]`.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     */
        void draw_title_with_frame(const Rect& cell_frame, const View& control_view) const;
        /**
     * @brief Calls `-[NSMenuItemCell keyEquivalentRectForBounds:]`.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect key_equivalent_rect_for_bounds(const Rect& cell_frame) const;
        /**
     * @brief Calls `-[NSMenuItemCell stateImageRectForBounds:]`.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect state_image_rect_for_bounds(const Rect& cell_frame) const;
        /**
     * @brief Calls `-[NSMenuItemCell titleRectForBounds:]`.
     * @param cell_frame Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect title_rect_for_bounds(const Rect& cell_frame) const;
        /**
     * @brief Returns the `imageWidth` property of `NSMenuItemCell`.
     * @return The converted Objective-C result.
     */
        double image_width() const;
        /**
     * @brief Returns the `keyEquivalentWidth` property of `NSMenuItemCell`.
     * @return The converted Objective-C result.
     */
        double key_equivalent_width() const;
        /**
     * @brief Returns the `menuItem` property of `NSMenuItemCell`.
     * @return The converted Objective-C result.
     */
        MenuItem menu_item() const;
        /**
     * @brief Sets the `menuItem` property of `NSMenuItemCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_menu_item(const MenuItem& value) const;
        /**
     * @brief Returns the `needsDisplay` property of `NSMenuItemCell`.
     * @return The converted Objective-C result.
     */
        bool needs_display() const;
        /**
     * @brief Sets the `needsDisplay` property of `NSMenuItemCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_needs_display(bool value) const;
        /**
     * @brief Returns the `needsSizing` property of `NSMenuItemCell`.
     * @return The converted Objective-C result.
     */
        bool needs_sizing() const;
        /**
     * @brief Sets the `needsSizing` property of `NSMenuItemCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_needs_sizing(bool value) const;
        /**
     * @brief Returns the `stateImageWidth` property of `NSMenuItemCell`.
     * @return The converted Objective-C result.
     */
        double state_image_width() const;
        /**
     * @brief Returns the `tag` property of `NSMenuItemCell`.
     * @return The converted Objective-C result.
     */
        std::int64_t tag() const;
        /**
     * @brief Sets the `tag` property of `NSMenuItemCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tag(std::int64_t value) const;
        /**
     * @brief Returns the `titleWidth` property of `NSMenuItemCell`.
     * @return The converted Objective-C result.
     */
        double title_width() const;
    };
}
