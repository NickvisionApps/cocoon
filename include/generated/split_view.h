#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class Notification;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSSplitView` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SplitView split_view;
     * split_view.set_arranges_all_subviews(true);
     * split_view.split_view_resize_subviews_with_old_size().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SplitView split_view{};
     * split_view.set_arranges_all_subviews(true);
     * auto arranges_all_subviews = split_view.arranges_all_subviews();
     * split_view.set_autosave_name("text");
     * auto autosave_name = split_view.autosave_name();
     * split_view.set_divider_style(cocoon::DividerStyle::Thick);
     * auto divider_style = split_view.divider_style();
     * split_view.add_arranged_subview(cocoon::View());
     * split_view.adjust_subviews();
     * split_view.draw_divider_in_rect({{0, 0}, {100, 100}});
     * split_view.split_view_resize_subviews_with_old_size().connect([](cocoon::Size a0) {});
     * split_view.will_resize_subviews().connect([](cocoon::Notification a0) {});
     * split_view.did_resize_subviews().connect([](cocoon::Notification a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssplitview
     */
    class SplitView : public View
    {
    public:
        /// @brief Creates a new `NSSplitView` instance and returns a handle to it.
        explicit SplitView();
        /// @brief Creates a null handle that refers to no native object.
        SplitView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SplitView(Adopt adopt);
        /**
         * @brief Calls `-[NSSplitView addArrangedSubview:]`.
         * @details Adds a view as arranged split pane. If the view is not a subview of the receiver, it will be added as one.
         * @param view Argument converted to the Objective-C parameter of the same role.
         */
        void add_arranged_subview(const View& view) const;
        /**
         * @brief Calls `-[NSSplitView adjustSubviews]`.
         * @details Set the frames of the split view's subviews so that they, plus the dividers, fill the split view. The default implementation of this method resizes all of the subviews proportionally so that the ratio of heights (in the horizontal split view case) or widths (in the vertical split view case) doesn't change, even though the absolute sizes of the subviews do change. This message should be sent to split views from which subviews have been added or removed, to reestablish the consistency of subview placement.
         */
        void adjust_subviews() const;
        /**
         * @brief Calls `-[NSSplitView drawDividerInRect:]`.
         * @details Draw the divider between two of the split view's subviews. The rectangle describes the entire divider rectangle in the receiver's coordinates. You can override this method to change the appearance of dividers.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         */
        void draw_divider_in_rect(const Rect& rect) const;
        /**
         * @brief Calls `-[NSSplitView holdingPriorityForSubviewAtIndex:]`.
         * @param subview_index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        float holding_priority_for_subview_at_index(std::int64_t subview_index) const;
        /**
         * @brief Calls `-[NSSplitView insertArrangedSubview:atIndex:]`.
         * @details Adds a view as an arranged split pane list at the specific index. If the view is already an arranged split view, it will move the view the specified index (but not move the subview index). If the view is not a subview of the receiver, it will be added as one (not necessarily at the same index).
         * @param view Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void insert_arranged_subview(const View& view, std::int64_t index) const;
        /**
         * @brief Calls `-[NSSplitView isSubviewCollapsed:]`.
         * @details Return YES if the subview is in the collapsed state, NO otherwise.
         * @param subview Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_subview_collapsed(const View& subview) const;
        /**
         * @brief Calls `-[NSSplitView maxPossiblePositionOfDividerAtIndex:]`.
         * @param divider_index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double max_possible_position_of_divider_at_index(std::int64_t divider_index) const;
        /**
         * @brief Calls `-[NSSplitView minPossiblePositionOfDividerAtIndex:]`.
         * @details Get the minimum or maximum possible position of a divider. The position is "possible" in that it is dictated by the bounds of this view and the current position of other dividers. ("Allowable" positions are those that result from letting the delegate apply constraints to the possible positions.) You can invoke these methods to determine the range of values that can be usefully passed to -setPosition:ofDividerAtIndex:. You can also invoke them from delegate methods like -splitView:constrainSplitPosition:ofSubviewAt: to implement relatively complex behaviors that depend on the current state of the split view. The results of invoking these methods when -adjustSubviews has not been invoked recently enough for the subview frames to be valid are undefined.
         * @param divider_index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double min_possible_position_of_divider_at_index(std::int64_t divider_index) const;
        /**
         * @brief Calls `-[NSSplitView removeArrangedSubview:]`.
         * @details Removes a view as arranged split pane. If \\c -arrangesAllSubviews is set to NO, this does not remove the view as a subview. Removing the view as a subview (either by -[view removeFromSuperview] or setting the receiver's subviews) will automatically remove it as an arranged subview.
         * @param view Argument converted to the Objective-C parameter of the same role.
         */
        void remove_arranged_subview(const View& view) const;
        /**
         * @brief Calls `-[NSSplitView setHoldingPriority:forSubviewAtIndex:]`.
         * @param priority Argument converted to the Objective-C parameter of the same role.
         * @param subview_index Argument converted to the Objective-C parameter of the same role.
         */
        void set_holding_priority(float priority, std::int64_t subview_index) const;
        /**
         * @brief Calls `-[NSSplitView setPosition:ofDividerAtIndex:]`.
         * @details Set the position of a divider. The default implementation of this method behaves as if the user were attempting to drag the divider to the proposed position, so the constraints imposed by the delegate are applied and one of the views adjacent to the divider may be collapsed. This method is not invoked by NSSplitView itself, so there's probably not much point in overriding it.
         * @param position Argument converted to the Objective-C parameter of the same role.
         * @param divider_index Argument converted to the Objective-C parameter of the same role.
         */
        void set_position(double position, std::int64_t divider_index) const;
        /**
         * @brief Returns the `arrangedSubviews` property of `NSSplitView`.
         * @details The list of views that are arranged as split panes in the receiver. They are a subset of \\c -subviews, with potential difference in ordering. If \\c -arrangesAllSubviews is YES, then \\c -arrangedSubviews is identical to \\c -subviews.
         * @return The converted Objective-C result.
         */
        std::vector<View> arranged_subviews() const;
        /**
         * @brief Returns the `arrangesAllSubviews` property of `NSSplitView`.
         * @details Whether or not all subviews will be added as arranged views. When NO, a subview must be explicitly added as an arrangedSubview if the view should be arranged as a split pane. When YES, \\c -arrangedSubviews always be identical to \\c -subviews. Defaults to YES. Setting this from YES to NO will leave all existing subviews as \\c -arrangedSubviews. Setting this from NO to YES will cause \\c -arrangedSubviews to become the value of \\c -subviews.
         * @return The converted Objective-C result.
         */
        bool arranges_all_subviews() const;
        /**
         * @brief Sets the `arrangesAllSubviews` property of `NSSplitView`.
         * @details Whether or not all subviews will be added as arranged views. When NO, a subview must be explicitly added as an arrangedSubview if the view should be arranged as a split pane. When YES, \\c -arrangedSubviews always be identical to \\c -subviews. Defaults to YES. Setting this from YES to NO will leave all existing subviews as \\c -arrangedSubviews. Setting this from NO to YES will cause \\c -arrangedSubviews to become the value of \\c -subviews.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_arranges_all_subviews(bool value) const;
        /**
         * @brief Returns the `autosaveName` property of `NSSplitView`.
         * @details The name to use when autosaving the positions of dividers, and whether or not subviews are collapsed, to preferences. If this value is nil or the string is empty no autosaving is done.
         * @return The converted Objective-C result.
         */
        std::string autosave_name() const;
        /**
         * @brief Sets the `autosaveName` property of `NSSplitView`.
         * @details The name to use when autosaving the positions of dividers, and whether or not subviews are collapsed, to preferences. If this value is nil or the string is empty no autosaving is done.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_autosave_name(const std::string& value) const;
        /**
         * @brief Returns the `dividerColor` property of `NSSplitView`.
         * @details Return the color of the dividers that the split view is drawing between subviews. The default implementation of this method returns [NSColor clearColor] for the thick divider style. It will also return [NSColor clearColor] for the thin divider style when the split view is in a textured window. All other thin dividers are drawn with a color that looks good between two white panes. You can override this method to change the color of dividers.
         * @return The converted Objective-C result.
         */
        Color divider_color() const;
        /**
         * @brief Returns the `dividerStyle` property of `NSSplitView`.
         * @details What kind of divider to use. NSSplitViewThickDividerStyle is the default.
         * @return The converted Objective-C result.
         */
        DividerStyle divider_style() const;
        /**
         * @brief Sets the `dividerStyle` property of `NSSplitView`.
         * @details What kind of divider to use. NSSplitViewThickDividerStyle is the default.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_divider_style(DividerStyle value) const;
        /**
         * @brief Returns the `dividerThickness` property of `NSSplitView`.
         * @details Return the thickness of the dividers that the split view is drawing between subviews. The default implementation returns a value that depends on the divider style. You can override this method to change the size of dividers.
         * @return The converted Objective-C result.
         */
        double divider_thickness() const;
        /**
         * @brief Returns the `vertical` property of `NSSplitView`.
         * @details Set or get whether the long axes of a split view's dividers are oriented up-and-down (YES) or left-and-right (NO).
         * @return The converted Objective-C result.
         */
        bool is_vertical() const;
        /**
         * @brief Sets the `vertical` property of `NSSplitView`.
         * @details Set or get whether the long axes of a split view's dividers are oriented up-and-down (YES) or left-and-right (NO).
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_vertical(bool value) const;
        /// @brief Signal for the delegate/data-source method behind `can_collapse_subview`; connect a callback with `can_collapse_subview().connect(...)`.
        Signal<SplitView, bool(View)> can_collapse_subview() const
        {
            return Signal<SplitView, bool(View)>(handle(), "can_collapse_subview");
        }
        /// @brief Signal for the delegate/data-source method behind `constrain_min_coordinate_of_subview_at`; connect a callback with `constrain_min_coordinate_of_subview_at().connect(...)`.
        Signal<SplitView, double(double, std::int64_t)> constrain_min_coordinate_of_subview_at() const
        {
            return Signal<SplitView, double(double, std::int64_t)>(handle(), "constrain_min_coordinate_of_subview_at");
        }
        /// @brief Signal for the delegate/data-source method behind `constrain_max_coordinate_of_subview_at`; connect a callback with `constrain_max_coordinate_of_subview_at().connect(...)`.
        Signal<SplitView, double(double, std::int64_t)> constrain_max_coordinate_of_subview_at() const
        {
            return Signal<SplitView, double(double, std::int64_t)>(handle(), "constrain_max_coordinate_of_subview_at");
        }
        /// @brief Signal for the delegate/data-source method behind `constrain_split_position_of_subview_at`; connect a callback with `constrain_split_position_of_subview_at().connect(...)`.
        Signal<SplitView, double(double, std::int64_t)> constrain_split_position_of_subview_at() const
        {
            return Signal<SplitView, double(double, std::int64_t)>(handle(), "constrain_split_position_of_subview_at");
        }
        /// @brief Signal for the delegate/data-source method behind `split_view_resize_subviews_with_old_size`; connect a callback with `split_view_resize_subviews_with_old_size().connect(...)`.
        Signal<SplitView, void(Size)> split_view_resize_subviews_with_old_size() const
        {
            return Signal<SplitView, void(Size)>(handle(), "split_view_resize_subviews_with_old_size");
        }
        /// @brief Signal for the delegate/data-source method behind `should_adjust_size_of_subview`; connect a callback with `should_adjust_size_of_subview().connect(...)`.
        Signal<SplitView, bool(View)> should_adjust_size_of_subview() const
        {
            return Signal<SplitView, bool(View)>(handle(), "should_adjust_size_of_subview");
        }
        /// @brief Signal for the delegate/data-source method behind `should_hide_divider_at_index`; connect a callback with `should_hide_divider_at_index().connect(...)`.
        Signal<SplitView, bool(std::int64_t)> should_hide_divider_at_index() const
        {
            return Signal<SplitView, bool(std::int64_t)>(handle(), "should_hide_divider_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `effective_rect_for_drawn_rect_of_divider_at_index`; connect a callback with `effective_rect_for_drawn_rect_of_divider_at_index().connect(...)`.
        Signal<SplitView, Rect(Rect, Rect, std::int64_t)> effective_rect_for_drawn_rect_of_divider_at_index() const
        {
            return Signal<SplitView, Rect(Rect, Rect, std::int64_t)>(handle(), "effective_rect_for_drawn_rect_of_divider_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `additional_effective_rect_of_divider_at_index`; connect a callback with `additional_effective_rect_of_divider_at_index().connect(...)`.
        Signal<SplitView, Rect(std::int64_t)> additional_effective_rect_of_divider_at_index() const
        {
            return Signal<SplitView, Rect(std::int64_t)>(handle(), "additional_effective_rect_of_divider_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `will_resize_subviews`; connect a callback with `will_resize_subviews().connect(...)`.
        Signal<SplitView, void(Notification)> will_resize_subviews() const
        {
            return Signal<SplitView, void(Notification)>(handle(), "will_resize_subviews");
        }
        /// @brief Signal for the delegate/data-source method behind `did_resize_subviews`; connect a callback with `did_resize_subviews().connect(...)`.
        Signal<SplitView, void(Notification)> did_resize_subviews() const
        {
            return Signal<SplitView, void(Notification)>(handle(), "did_resize_subviews");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
