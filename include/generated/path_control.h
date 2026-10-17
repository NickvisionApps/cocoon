#pragma once

#include "generated/control.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class Color;
    class Menu;
    class OpenPanel;
    class Pasteboard;
    class PathComponentCell;
    class PathControlItem;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSPathControl` (AppKit).
     * @details NSPathControl This control maintains a collection of NSPathControlItems that represent a particular path to be displayed to the user. The path shown can be set by calling -setURL:. Doing so will remove all displayed NSPathControlItems and automatically fill it up with items set to have the appropriate icons, display titles, and NSURL values for the particular path component they represent. One can manually fill up the control by setting the array or directly modifying existing item objects. Both an action and doubleAction can be set for the control. To find out what path item was clicked upon in the action, you can access the 'clickedPathItem'. When the style is set to NSPathStylePopUp, the action is still sent, and the 'clickedPathItem' for the represented menu item is correctly set. The 'clickedPathItem' is only valid when the action is being sent. It will also be valid when the keyboard is used to invoke the action. To accept drag and drop, the NSPathControl automatically calls registerForDraggedTypes: with NSFilenamesPboardType and NSURLPboardType. When the URL value in the NSPathControl changes from an automatic drag and drop operation, or from the user selecting a new path via the open panel, the action is sent, but the clickedPathItem will be nil. The NSPathControl supports several path display styles. The NSPathStyleStandard has a light blue background with arrows indicating the path. The NSPathStylePopUp will look and work like an NSPopUpButton to display the full path, or select a new path, if the control is editable. If the control isEditable (the default is YES), one can drag and drop into the control to change the value. You can constrain what can be dropped using UTIs (Uniform Type Identifier) in the allowedTypes, or the appropriate delegate methods on NSPathControl. If the control isSelectable (the default is YES), the control's contents can automatically be dragged out. The proper UTI and filename and URL will be placed on the pasteboard. You can further control or limit this by using the appropriate delegate methods on NSPathControl. If the control isEditable and has the pathStyle set to NSPathStylePopUp, an additional choice in the pop up menu will allow selecting another location. By default, an NSOpenPanel will be configured based on the allowedTypes. The NSOpenPanel that is used can be customized with a delegate method.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Control.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PathControl path_control;
     * path_control.set_url(cocoon::URL());
     * path_control.will_display_open_panel().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PathControl path_control{};
     * path_control.set_url(cocoon::URL());
     * auto url = path_control.url();
     * path_control.set_allowed_types({"a", "b"});
     * auto allowed_types = path_control.allowed_types();
     * path_control.set_background_color(cocoon::Color());
     * auto background_color = path_control.background_color();
     * path_control.set_dragging_source_operation_mask(cocoon::DragOperation::None, true);
     * path_control.will_display_open_panel().connect([](cocoon::OpenPanel a0) {});
     * path_control.will_pop_up_menu().connect([](cocoon::Menu a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspathcontrol
     */
    class PathControl : public Control
    {
    public:
        /// @brief Creates a new `NSPathControl` instance and returns a handle to it.
        explicit PathControl();
        /// @brief Creates a null handle that refers to no native object.
        PathControl(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PathControl(Adopt adopt);
        using Responder::menu;
        using Responder::set_menu;
        using View::set_background_color;
        /**
     * @brief Calls `-[NSPathControl setDraggingSourceOperationMask:forLocal:]`.
     * @details Configures the default value returned from -draggingSourceOperationMaskForLocal:. An 'isLocal' value of YES indicates that 'mask' applies when the destination object is in the same application. An 'isLocal' value of NO indicates that 'mask' applies when the destination object in a destination object outside the receiver's application. By default, -draggingSourceOperationMaskForLocal: returns NSDragOperationEvery when 'isLocal' is YES, and NSDragOperationNone when 'isLocal' is NO.
     * @param mask Argument converted to the Objective-C parameter of the same role.
     * @param is_local Argument converted to the Objective-C parameter of the same role.
     */
        void set_dragging_source_operation_mask(DragOperation mask, bool is_local) const;
        /**
     * @brief Returns the `URL` property of `NSPathControl`.
     * @details Gets and sets the path value displayed. When setting, an array of NSPathControlItems will automatically be set based on the path in the 'url'. If the 'url' is a file URL (returns YES from isFileURL), the images will automatically be filled up with file icons, if the path exists. The URL value itself is stored in the objectValue of the control.
     * @return The converted Objective-C result.
     */
        URL url() const;
        /**
     * @brief Sets the `URL` property of `NSPathControl`.
     * @details Gets and sets the path value displayed. When setting, an array of NSPathControlItems will automatically be set based on the path in the 'url'. If the 'url' is a file URL (returns YES from isFileURL), the images will automatically be filled up with file icons, if the path exists. The URL value itself is stored in the objectValue of the control.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_url(const URL& value) const;
        /**
     * @brief Returns the `allowedTypes` property of `NSPathControl`.
     * @details Specifies the allowed types when the control isEditable. The allowedTypes can contain a file extension (without the period that begins the extension) or UTI (Uniform Type Identifier). To allow folders, include the UTI 'public.folder'. To allow all types, use 'nil'. If allowedTypes is an empty array, nothing will be allowed. The default value is 'nil', allowing all types.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> allowed_types() const;
        /**
     * @brief Sets the `allowedTypes` property of `NSPathControl`.
     * @details Specifies the allowed types when the control isEditable. The allowedTypes can contain a file extension (without the period that begins the extension) or UTI (Uniform Type Identifier). To allow folders, include the UTI 'public.folder'. To allow all types, use 'nil'. If allowedTypes is an empty array, nothing will be allowed. The default value is 'nil', allowing all types.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allowed_types(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `backgroundColor` property of `NSPathControl`.
     * @details The background color to be drawn. By default, it will be set to a light blue color for NSPathStyleStandard, and nil for everything else. You can use [NSColor clearColor] to make the background transparent.
     * @return The converted Objective-C result.
     */
        Color background_color() const;
        /**
     * @brief Sets the `backgroundColor` property of `NSPathControl`.
     * @details The background color to be drawn. By default, it will be set to a light blue color for NSPathStyleStandard, and nil for everything else. You can use [NSColor clearColor] to make the background transparent.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_color(const Color& value) const;
        /**
     * @brief Returns the `clickedPathItem` property of `NSPathControl`.
     * @details The clicked NSPathControlItem, or nil, if no item has been clicked. The clickedPathItem is generally only valid while the action or doubleAction is being sent.
     * @return The converted Objective-C result.
     */
        PathControlItem clicked_path_item() const;
        /**
     * @brief Returns the `doubleAction` property of `NSPathControl`.
     * @details The selector that will be called when the user double clicks on a NSPathControlItem.
     * @return The converted Objective-C result.
     */
        std::string double_action() const;
        /**
     * @brief Sets the `doubleAction` property of `NSPathControl`.
     * @details The selector that will be called when the user double clicks on a NSPathControlItem.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_double_action(const std::string& value) const;
        /**
     * @brief Returns the `editable` property of `NSPathControl`.
     * @return The converted Objective-C result.
     */
        bool is_editable() const;
        /**
     * @brief Sets the `editable` property of `NSPathControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_editable(bool value) const;
        /**
     * @brief Returns the `menu` property of `NSPathControl`.
     * @details The menu used when the syle is NSPathStylePopUp.
     * @return The converted Objective-C result.
     */
        Menu menu() const;
        /**
     * @brief Sets the `menu` property of `NSPathControl`.
     * @details The menu used when the syle is NSPathStylePopUp.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_menu(const Menu& value) const;
        /**
     * @brief Returns the `pathItems` property of `NSPathControl`.
     * @details The array of NSPathControlItems currently being displayed. Each item must be an NSPathControlItem. Do not subclass NSPathControlItem. You cannot set this value to nil, but should instead set it to an empty array.
     * @return The converted Objective-C result.
     */
        std::vector<PathControlItem> path_items() const;
        /**
     * @brief Sets the `pathItems` property of `NSPathControl`.
     * @details The array of NSPathControlItems currently being displayed. Each item must be an NSPathControlItem. Do not subclass NSPathControlItem. You cannot set this value to nil, but should instead set it to an empty array.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_path_items(const std::vector<PathControlItem>& value) const;
        /**
     * @brief Returns the `pathStyle` property of `NSPathControl`.
     * @details The style/mode of the NSPathControl. Defaults to NSPathStyleStandard.
     * @return The converted Objective-C result.
     */
        PathStyle path_style() const;
        /**
     * @brief Sets the `pathStyle` property of `NSPathControl`.
     * @details The style/mode of the NSPathControl. Defaults to NSPathStyleStandard.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_path_style(PathStyle value) const;
        /**
     * @brief Returns the `placeholderAttributedString` property of `NSPathControl`.
     * @return The converted Objective-C result.
     */
        AttributedString placeholder_attributed_string() const;
        /**
     * @brief Sets the `placeholderAttributedString` property of `NSPathControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_placeholder_attributed_string(const AttributedString& value) const;
        /**
     * @brief Returns the `placeholderString` property of `NSPathControl`.
     * @details If there are no components in the path, the placeholder is drawn instead (if non-nil). We first try to draw the placeholderAttributedString. If it's nil, then the placeholderString will be drawn with correct default attributes.
     * @return The converted Objective-C result.
     */
        std::string placeholder_string() const;
        /**
     * @brief Sets the `placeholderString` property of `NSPathControl`.
     * @details If there are no components in the path, the placeholder is drawn instead (if non-nil). We first try to draw the placeholderAttributedString. If it's nil, then the placeholderString will be drawn with correct default attributes.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_placeholder_string(const std::string& value) const;
        /// @brief Signal for the delegate/data-source method behind `should_drag_item_with_pasteboard`; connect a callback with `should_drag_item_with_pasteboard().connect(...)`.
        Signal<PathControl, bool(PathControlItem, Pasteboard)> should_drag_item_with_pasteboard() const
        {
            return Signal<PathControl, bool(PathControlItem, Pasteboard)>(handle(), "should_drag_item_with_pasteboard");
        }
        /// @brief Signal for the delegate/data-source method behind `should_drag_path_component_cell_with_pasteboard`; connect a callback with `should_drag_path_component_cell_with_pasteboard().connect(...)`.
        Signal<PathControl, bool(PathComponentCell, Pasteboard)> should_drag_path_component_cell_with_pasteboard() const
        {
            return Signal<PathControl, bool(PathComponentCell, Pasteboard)>(handle(), "should_drag_path_component_cell_with_pasteboard");
        }
        /// @brief Signal for the delegate/data-source method behind `validate_drop`; connect a callback with `validate_drop().connect(...)`.
        Signal<PathControl, DragOperation(Object)> validate_drop() const
        {
            return Signal<PathControl, DragOperation(Object)>(handle(), "validate_drop");
        }
        /// @brief Signal for the delegate/data-source method behind `accept_drop`; connect a callback with `accept_drop().connect(...)`.
        Signal<PathControl, bool(Object)> accept_drop() const
        {
            return Signal<PathControl, bool(Object)>(handle(), "accept_drop");
        }
        /// @brief Signal for the delegate/data-source method behind `will_display_open_panel`; connect a callback with `will_display_open_panel().connect(...)`.
        Signal<PathControl, void(OpenPanel)> will_display_open_panel() const
        {
            return Signal<PathControl, void(OpenPanel)>(handle(), "will_display_open_panel");
        }
        /// @brief Signal for the delegate/data-source method behind `will_pop_up_menu`; connect a callback with `will_pop_up_menu().connect(...)`.
        Signal<PathControl, void(Menu)> will_pop_up_menu() const
        {
            return Signal<PathControl, void(Menu)>(handle(), "will_pop_up_menu");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
