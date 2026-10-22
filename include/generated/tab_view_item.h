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
    class TabView;
    class View;
    class ViewController;

    /**
     * @brief C++ handle for the Objective-C class `NSTabViewItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TabViewItem tab_view_item;
     * tab_view_item.set_color(cocoon::Color());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TabViewItem tab_view_item{};
     * tab_view_item.set_color(cocoon::Color());
     * auto color = tab_view_item.color();
     * tab_view_item.set_image(cocoon::Image());
     * auto image = tab_view_item.image();
     * tab_view_item.set_initial_first_responder(cocoon::View());
     * auto initial_first_responder = tab_view_item.initial_first_responder();
     * tab_view_item.draw_label(true, {{0, 0}, {100, 100}});
     * tab_view_item.size_of_label(true);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstabviewitem
     */
    class TabViewItem : public Object
    {
    public:
        /// @brief Creates a new `NSTabViewItem` instance and returns a handle to it.
        explicit TabViewItem(const Object& identifier);
        /// @brief Creates a new `NSTabViewItem` instance and returns a handle to it.
        explicit TabViewItem(const ViewController& view_controller);
        /// @brief Creates a new `NSTabViewItem` instance and returns a handle to it.
        explicit TabViewItem();
        /// @brief Creates a null handle that refers to no native object.
        TabViewItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TabViewItem(Adopt adopt);
        /**
         * @brief Calls `-[NSTabViewItem drawLabel:inRect:]`.
         * @details This method draws the tab label assuming a local coordinate system whose label axis runs along the x axis. Assume the label axis runs along the length of the label (perpendicular to the direction of the tab). 'labelRect' is the area in between the curved end caps. 'shouldTruncateLabel' is a hint that the label should be truncated. ie. if shouldTruncateLabel is YES, then labelRect.size \< ceil([sizeOfLabel:NO])
         * @param should_truncate_label Argument converted to the Objective-C parameter of the same role.
         * @param label_rect Argument converted to the Objective-C parameter of the same role.
         */
        void draw_label(bool should_truncate_label, const Rect& label_rect) const;
        /**
         * @brief Calls `-[NSTabViewItem sizeOfLabel:]`.
         * @details This method returns the minimum or nominal size of the tab label. The width of the label is measured along the label axis, and height is measured in the direction parallel to the tab direction. 'computeMin' indicates whether you should return the minimum or nominal label size. The returned value is used to compute the range of legal sizes for the tab label.
         * @param compute_min Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Size size_of_label(bool compute_min) const;
        /**
         * @brief Returns the `color` property of `NSTabViewItem`.
         * @return The converted Objective-C result.
         */
        Color color() const;
        /**
         * @brief Sets the `color` property of `NSTabViewItem`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_color(const Color& value) const;
        /**
         * @brief Returns the `identifier` property of `NSTabViewItem`.
         * @return The converted Objective-C result.
         */
        Object identifier() const;
        /**
         * @brief Sets the `identifier` property of `NSTabViewItem`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_identifier(const Object& value) const;
        /**
         * @brief Returns the `image` property of `NSTabViewItem`.
         * @details Gets and set the image for this tab view item. The image may only be used in certain tab view styles and options. The default value is 'nil'.
         * @return The converted Objective-C result.
         */
        Image image() const;
        /**
         * @brief Sets the `image` property of `NSTabViewItem`.
         * @details Gets and set the image for this tab view item. The image may only be used in certain tab view styles and options. The default value is 'nil'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_image(const Image& value) const;
        /**
         * @brief Returns the `initialFirstResponder` property of `NSTabViewItem`.
         * @return The converted Objective-C result.
         */
        View initial_first_responder() const;
        /**
         * @brief Sets the `initialFirstResponder` property of `NSTabViewItem`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_initial_first_responder(const View& value) const;
        /**
         * @brief Returns the `label` property of `NSTabViewItem`.
         * @return The converted Objective-C result.
         */
        std::string label() const;
        /**
         * @brief Sets the `label` property of `NSTabViewItem`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_label(const std::string& value) const;
        /**
         * @brief Returns the `tabState` property of `NSTabViewItem`.
         * @return The converted Objective-C result.
         */
        TabState tab_state() const;
        /**
         * @brief Returns the `tabView` property of `NSTabViewItem`.
         * @return The converted Objective-C result.
         */
        TabView tab_view() const;
        /**
         * @brief Returns the `toolTip` property of `NSTabViewItem`.
         * @details The following methods provide support for tooltips on the tabs a tab view. The default behavior is to use the label as a tooltip if the label is truncated due to insufficient space; this automatic tooltip is never returned by the toolTip method. If you explicitly set a non-nil tooltip, this default behavior is suppressed, and the given tooltip will be used whether or not the label is truncated.
         * @return The converted Objective-C result.
         */
        std::string tool_tip() const;
        /**
         * @brief Sets the `toolTip` property of `NSTabViewItem`.
         * @details The following methods provide support for tooltips on the tabs a tab view. The default behavior is to use the label as a tooltip if the label is truncated due to insufficient space; this automatic tooltip is never returned by the toolTip method. If you explicitly set a non-nil tooltip, this default behavior is suppressed, and the given tooltip will be used whether or not the label is truncated.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tool_tip(const std::string& value) const;
        /**
         * @brief Returns the `view` property of `NSTabViewItem`.
         * @return The converted Objective-C result.
         */
        View view() const;
        /**
         * @brief Sets the `view` property of `NSTabViewItem`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_view(const View& value) const;
        /**
         * @brief Returns the `viewController` property of `NSTabViewItem`.
         * @details The view controller wrapped by the tab view item. This property must be set if the tab view item will be added to an NSTabViewController, but can also be used if the tab view item is added to an NSTabView. If this is set, the tab view item will forward \\c -view calls onto the viewController. Setting a viewController will also set the following properties on the tab view item: \\c -identifier from the address of the viewController, \\c -label from the viewController's title, and \\c -image based on the classname as the view controller. An image named "ViewControllerClassName-TabViewItem" will be searched for first, followed by "ViewControllerClassName". It will search first using +[NSImage imageNamed:], then in \\c viewController.nibBundle, and lastly in the bundle containing the view controller's class. As defined by: -[NSImage imageNamed:imageName], -[viewController.nibBundle imageForResource:imageName], -[[NSBundle bundleForClass:[viewController class]] imageForResource:imageName]. One pass with imageName as [NSStringFromClass([viewController class]) stringByAppendingString:\@"-TabViewItem"], followed by imageName as NSStringFromClass([viewController class]).
         * @return The converted Objective-C result.
         */
        ViewController view_controller() const;
        /**
         * @brief Sets the `viewController` property of `NSTabViewItem`.
         * @details The view controller wrapped by the tab view item. This property must be set if the tab view item will be added to an NSTabViewController, but can also be used if the tab view item is added to an NSTabView. If this is set, the tab view item will forward \\c -view calls onto the viewController. Setting a viewController will also set the following properties on the tab view item: \\c -identifier from the address of the viewController, \\c -label from the viewController's title, and \\c -image based on the classname as the view controller. An image named "ViewControllerClassName-TabViewItem" will be searched for first, followed by "ViewControllerClassName". It will search first using +[NSImage imageNamed:], then in \\c viewController.nibBundle, and lastly in the bundle containing the view controller's class. As defined by: -[NSImage imageNamed:imageName], -[viewController.nibBundle imageForResource:imageName], -[[NSBundle bundleForClass:[viewController class]] imageForResource:imageName]. One pass with imageName as [NSStringFromClass([viewController class]) stringByAppendingString:\@"-TabViewItem"], followed by imageName as NSStringFromClass([viewController class]).
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_view_controller(const ViewController& value) const;
    };
}
