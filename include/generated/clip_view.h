#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class Cursor;
    class Event;
    class Notification;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSClipView` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ClipView clip_view;
     * clip_view.set_automatically_adjusts_content_insets(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ClipView clip_view{};
     * clip_view.set_automatically_adjusts_content_insets(true);
     * auto automatically_adjusts_content_insets = clip_view.automatically_adjusts_content_insets();
     * clip_view.set_background_color(cocoon::Color());
     * auto background_color = clip_view.background_color();
     * clip_view.set_content_insets(cocoon::Insets(8));
     * auto content_insets = clip_view.content_insets();
     * clip_view.autoscroll(cocoon::Event());
     * clip_view.constrain_bounds_rect({{0, 0}, {100, 100}});
     * clip_view.scroll_to_point({0, 0});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsclipview
     */
    class ClipView : public View
    {
    public:
        /// @brief Creates a new `NSClipView` instance and returns a handle to it.
        explicit ClipView();
        /// @brief Creates a null handle that refers to no native object.
        ClipView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ClipView(Adopt adopt);
        using View::autoscroll;
        using View::set_background_color;
        /**
         * @brief Calls `-[NSClipView autoscroll:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool autoscroll(const Event& event) const;
        /**
         * @brief Calls `-[NSClipView constrainBoundsRect:]`.
         * @details This is used to constrain the bounds of the clip view under magnification and scrolling. This also comes with the deprecation of -constrainScrollPoint:. The logic of an existing -constrainScrollPoint: can be moved to -constrainBoundsRect: by adjusting the proposedBounds origin (as opposed to 'newOrigin'). To preserve compatibility, if a subclass overrides -constrainScrollPoint:, the default behavior of -constrainBoundsRect: will be to use that -constrainScrollPoint: to adjust the proposedBounds origin, and to not change the size.
         * @param proposed_bounds Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect constrain_bounds_rect(const Rect& proposed_bounds) const;
        /**
         * @brief Calls `-[NSClipView scrollToPoint:]`.
         * @param new_origin Argument converted to the Objective-C parameter of the same role.
         */
        void scroll_to_point(const Point& new_origin) const;
        /**
         * @brief Calls `-[NSClipView viewBoundsChanged:]`.
         * @param notification Argument converted to the Objective-C parameter of the same role.
         */
        void view_bounds_changed(const Notification& notification) const;
        /**
         * @brief Calls `-[NSClipView viewFrameChanged:]`.
         * @param notification Argument converted to the Objective-C parameter of the same role.
         */
        void view_frame_changed(const Notification& notification) const;
        /**
         * @brief Returns the `automaticallyAdjustsContentInsets` property of `NSClipView`.
         * @details When YES, and used as the contentView of an NSScrollView, the clip view will automatically account for other scroll view subviews such as rulers and headers. Defaults to YES.
         * @return The converted Objective-C result.
         */
        bool automatically_adjusts_content_insets() const;
        /**
         * @brief Sets the `automaticallyAdjustsContentInsets` property of `NSClipView`.
         * @details When YES, and used as the contentView of an NSScrollView, the clip view will automatically account for other scroll view subviews such as rulers and headers. Defaults to YES.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_automatically_adjusts_content_insets(bool value) const;
        /**
         * @brief Returns the `backgroundColor` property of `NSClipView`.
         * @return The converted Objective-C result.
         */
        Color background_color() const;
        /**
         * @brief Sets the `backgroundColor` property of `NSClipView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_background_color(const Color& value) const;
        /**
         * @brief Returns the `contentInsets` property of `NSClipView`.
         * @details The distance that the content view is inset from the enclosing scroll view. Note: animate with [self animator]
         * @return The converted Objective-C result.
         */
        Insets content_insets() const;
        /**
         * @brief Sets the `contentInsets` property of `NSClipView`.
         * @details The distance that the content view is inset from the enclosing scroll view. Note: animate with [self animator]
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_content_insets(const Insets& value) const;
        /**
         * @brief Returns the `documentCursor` property of `NSClipView`.
         * @return The converted Objective-C result.
         */
        Cursor document_cursor() const;
        /**
         * @brief Sets the `documentCursor` property of `NSClipView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_document_cursor(const Cursor& value) const;
        /**
         * @brief Returns the `documentRect` property of `NSClipView`.
         * @return The converted Objective-C result.
         */
        Rect document_rect() const;
        /**
         * @brief Returns the `documentView` property of `NSClipView`.
         * @return The converted Objective-C result.
         */
        View document_view() const;
        /**
         * @brief Sets the `documentView` property of `NSClipView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_document_view(const View& value) const;
        /**
         * @brief Returns the `documentVisibleRect` property of `NSClipView`.
         * @return The converted Objective-C result.
         */
        Rect document_visible_rect() const;
        /**
         * @brief Returns the `drawsBackground` property of `NSClipView`.
         * @return The converted Objective-C result.
         */
        bool draws_background() const;
        /**
         * @brief Sets the `drawsBackground` property of `NSClipView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_draws_background(bool value) const;
    };
}
