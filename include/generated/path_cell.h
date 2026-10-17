#pragma once

#include "generated/action_cell.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class Color;
    class Event;
    class Menu;
    class OpenPanel;
    class PathComponentCell;
    class URL;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSPathCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ActionCell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PathCell path_cell;
     * path_cell.set_url(cocoon::URL());
     * path_cell.will_display_open_panel().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PathCell path_cell{};
     * path_cell.set_url(cocoon::URL());
     * auto url = path_cell.url();
     * path_cell.set_allowed_types({"a", "b"});
     * auto allowed_types = path_cell.allowed_types();
     * path_cell.set_background_color(cocoon::Color());
     * auto background_color = path_cell.background_color();
     * path_cell.mouse_entered(cocoon::Event(), {{0, 0}, {100, 100}}, cocoon::View());
     * path_cell.mouse_exited(cocoon::Event(), {{0, 0}, {100, 100}}, cocoon::View());
     * path_cell.path_component_cell_at_point({0, 0}, {{0, 0}, {100, 100}}, cocoon::View());
     * path_cell.will_display_open_panel().connect([](cocoon::OpenPanel a0) {});
     * path_cell.will_pop_up_menu().connect([](cocoon::Menu a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspathcell
     */
    class PathCell : public ActionCell
    {
    public:
        /// @brief Creates a new `NSPathCell` instance and returns a handle to it.
        explicit PathCell();
        /// @brief Creates a null handle that refers to no native object.
        PathCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PathCell(Adopt adopt);
        using Cell::set_object_value;
        /**
     * @brief Calls `-[NSPathCell mouseEntered:withFrame:inView:]`.
     * @details The NSPathCell will dynamically animate to display the component that the mouse is hovering over by using mouseEntered and mouseExited events. The control should call these methods to correctly display the hovered component to the user. The control can acquire rects to track using rectOfPathComponentCell:withFrame:inView:.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @param frame Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     */
        void mouse_entered(const Event& event, const Rect& frame, const View& view) const;
        /**
     * @brief Calls `-[NSPathCell mouseExited:withFrame:inView:]`.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @param frame Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     */
        void mouse_exited(const Event& event, const Rect& frame, const View& view) const;
        /**
     * @brief Calls `-[NSPathCell pathComponentCellAtPoint:withFrame:inView:]`.
     * @details Returns the cell located at 'point' within 'frame' of 'view', or nil, if none exists at that location.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @param frame Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        PathComponentCell path_component_cell_at_point(const Point& point, const Rect& frame, const View& view) const;
        /**
     * @brief Calls `-[NSPathCell rectOfPathComponentCell:withFrame:inView:]`.
     * @details Returns the current rect being displayed for a particular NSPathComponentCell 'cell', with respect to the 'frame' in 'view'. NSZeroRect will be returned if 'cell' is not found, or it currently is not visible.
     * @param cell Argument converted to the Objective-C parameter of the same role.
     * @param frame Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect rect_of_path_component_cell(const PathComponentCell& cell, const Rect& frame, const View& view) const;
        /**
     * @brief Calls `-[NSPathCell setObjectValue:]`.
     * @details If setObjectValue is called with an NSURL, setURL is automatically called. Calling objectValue will return the last set URL value. setObjectValue can also take a string value, with the items separated by the path separator. Any other value is a programming error and will cause an assertion.
     * @param obj Argument converted to the Objective-C parameter of the same role.
     */
        void set_object_value(const Object& obj) const;
        /**
     * @brief Returns the `URL` property of `NSPathCell`.
     * @return The converted Objective-C result.
     */
        URL url() const;
        /**
     * @brief Sets the `URL` property of `NSPathCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_url(const URL& value) const;
        /**
     * @brief Returns the `allowedTypes` property of `NSPathCell`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> allowed_types() const;
        /**
     * @brief Sets the `allowedTypes` property of `NSPathCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allowed_types(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `backgroundColor` property of `NSPathCell`.
     * @details The background color to be drawn. By default, it will be set to a light blue color for NSPathStyleStandard, and nil for everything else. You can use [NSColor clearColor] to make the background transparent. NSPathCell will return YES from isOpaque if the backgroundColor has an alphaComponent of 1.0, otherwise, it will return NO. When drawing with the background color, NSCompositeSourceOver is used for the compositing operation.
     * @return The converted Objective-C result.
     */
        Color background_color() const;
        /**
     * @brief Sets the `backgroundColor` property of `NSPathCell`.
     * @details The background color to be drawn. By default, it will be set to a light blue color for NSPathStyleStandard, and nil for everything else. You can use [NSColor clearColor] to make the background transparent. NSPathCell will return YES from isOpaque if the backgroundColor has an alphaComponent of 1.0, otherwise, it will return NO. When drawing with the background color, NSCompositeSourceOver is used for the compositing operation.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_color(const Color& value) const;
        /**
     * @brief Returns the `clickedPathComponentCell` property of `NSPathCell`.
     * @details Returns the clicked cell, or nil, if a no cell has been clicked. The clickedPathComponentCell is generally only valid when the action or doubleAction is being sent.
     * @return The converted Objective-C result.
     */
        PathComponentCell clicked_path_component_cell() const;
        /**
     * @brief Returns the `doubleAction` property of `NSPathCell`.
     * @details Allows you to set the selector that will be called when the user double clicks on a particular NSPathComponentCell.
     * @return The converted Objective-C result.
     */
        std::string double_action() const;
        /**
     * @brief Sets the `doubleAction` property of `NSPathCell`.
     * @details Allows you to set the selector that will be called when the user double clicks on a particular NSPathComponentCell.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_double_action(const std::string& value) const;
        /**
     * @brief Returns the `pathComponentCellClass` property of `NSPathCell`.
     * @details Returns the class used to create pathComponentCells when automatically filling up the control. Subclassers can override this method to return a custom cell class that will automatically be used. By default, it will return [NSPathComponentCell class], or a specialized subclass thereof.
     * @return The converted Objective-C result.
     */
        static std::string path_component_cell_class();
        /**
     * @brief Returns the `pathComponentCells` property of `NSPathCell`.
     * @return The converted Objective-C result.
     */
        std::vector<PathComponentCell> path_component_cells() const;
        /**
     * @brief Sets the `pathComponentCells` property of `NSPathCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_path_component_cells(const std::vector<PathComponentCell>& value) const;
        /**
     * @brief Returns the `pathStyle` property of `NSPathCell`.
     * @details See NSPathControl for documentation on all the properties listed below. The NSPathControl directly calls the cell's methods.
     * @return The converted Objective-C result.
     */
        PathStyle path_style() const;
        /**
     * @brief Sets the `pathStyle` property of `NSPathCell`.
     * @details See NSPathControl for documentation on all the properties listed below. The NSPathControl directly calls the cell's methods.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_path_style(PathStyle value) const;
        /**
     * @brief Returns the `placeholderAttributedString` property of `NSPathCell`.
     * @return The converted Objective-C result.
     */
        AttributedString placeholder_attributed_string() const;
        /**
     * @brief Sets the `placeholderAttributedString` property of `NSPathCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_placeholder_attributed_string(const AttributedString& value) const;
        /**
     * @brief Returns the `placeholderString` property of `NSPathCell`.
     * @return The converted Objective-C result.
     */
        std::string placeholder_string() const;
        /**
     * @brief Sets the `placeholderString` property of `NSPathCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_placeholder_string(const std::string& value) const;
        /// @brief Signal for the delegate/data-source method behind `will_display_open_panel`; connect a callback with `will_display_open_panel().connect(...)`.
        Signal<PathCell, void(OpenPanel)> will_display_open_panel() const
        {
            return Signal<PathCell, void(OpenPanel)>(handle(), "will_display_open_panel");
        }
        /// @brief Signal for the delegate/data-source method behind `will_pop_up_menu`; connect a callback with `will_pop_up_menu().connect(...)`.
        Signal<PathCell, void(Menu)> will_pop_up_menu() const
        {
            return Signal<PathCell, void(Menu)>(handle(), "will_pop_up_menu");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
