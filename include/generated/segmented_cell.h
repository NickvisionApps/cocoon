#pragma once

#include "generated/action_cell.h"
#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Image;
    class Menu;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSSegmentedCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ActionCell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SegmentedCell segmented_cell;
     * segmented_cell.set_segment_count(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SegmentedCell segmented_cell{};
     * segmented_cell.set_segment_count(1);
     * auto segment_count = segmented_cell.segment_count();
     * segmented_cell.set_segment_style(cocoon::SegmentStyle::Automatic);
     * auto segment_style = segmented_cell.segment_style();
     * segmented_cell.set_selected_segment(1);
     * auto selected_segment = segmented_cell.selected_segment();
     * segmented_cell.draw_segment(1, {{0, 0}, {100, 100}}, cocoon::View());
     * segmented_cell.image_for_segment(1);
     * segmented_cell.image_scaling_for_segment(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssegmentedcell
     */
    class SegmentedCell : public ActionCell
    {
    public:
        /// @brief Creates a new `NSSegmentedCell` instance and returns a handle to it.
        explicit SegmentedCell();
        /// @brief Creates a null handle that refers to no native object.
        SegmentedCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SegmentedCell(Adopt adopt);
        using ActionCell::set_tag;
        using Cell::set_enabled;
        using Cell::set_image;
        using Cell::set_menu;
        /**
         * @brief Calls `-[NSSegmentedCell drawSegment:inFrame:withView:]`.
         * @details For custom content drawing. frame has been adjusted to content area
         * @param segment Argument converted to the Objective-C parameter of the same role.
         * @param frame Argument converted to the Objective-C parameter of the same role.
         * @param control_view Argument converted to the Objective-C parameter of the same role.
         */
        void draw_segment(std::int64_t segment, const Rect& frame, const View& control_view) const;
        /**
         * @brief Calls `-[NSSegmentedCell imageForSegment:]`.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Image image_for_segment(std::int64_t segment) const;
        /**
         * @brief Calls `-[NSSegmentedCell imageScalingForSegment:]`.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        ImageScaling image_scaling_for_segment(std::int64_t segment) const;
        /**
         * @brief Calls `-[NSSegmentedCell interiorBackgroundStyleForSegment:]`.
         * @details Describes the surface drawn onto in -[NSCell drawSegment:inFrame:withView:]. That method draws a segment interior, not the segment bezel. This is both an override point and a useful method to call. A segmented cell that draws a custom bezel would override this to describe that surface. A cell that has custom segment drawing might query this method to help pick an image that looks good on the cell. Calling this method gives you some independence from changes in framework art style.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        BackgroundStyle interior_background_style_for_segment(std::int64_t segment) const;
        /**
         * @brief Calls `-[NSSegmentedCell isEnabledForSegment:]`.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_enabled_for_segment(std::int64_t segment) const;
        /**
         * @brief Calls `-[NSSegmentedCell isSelectedForSegment:]`.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_selected_for_segment(std::int64_t segment) const;
        /**
         * @brief Calls `-[NSSegmentedCell labelForSegment:]`.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string label_for_segment(std::int64_t segment) const;
        /**
         * @brief Calls `-[NSSegmentedCell makeNextSegmentKey]`.
         * @details For keyboard UI. Wraps.
         */
        void make_next_segment_key() const;
        /**
         * @brief Calls `-[NSSegmentedCell makePreviousSegmentKey]`.
         */
        void make_previous_segment_key() const;
        /**
         * @brief Calls `-[NSSegmentedCell menuForSegment:]`.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Menu menu_for_segment(std::int64_t segment) const;
        /**
         * @brief Calls `-[NSSegmentedCell selectSegmentWithTag:]`.
         * @param tag Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool select_segment_with_tag(std::int64_t tag) const;
        /**
         * @brief Calls `-[NSSegmentedCell setEnabled:forSegment:]`.
         * @param enabled Argument converted to the Objective-C parameter of the same role.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         */
        void set_enabled(bool enabled, std::int64_t segment) const;
        /**
         * @brief Calls `-[NSSegmentedCell setImage:forSegment:]`.
         * @param image Argument converted to the Objective-C parameter of the same role.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         */
        void set_image(const Image& image, std::int64_t segment) const;
        /**
         * @brief Calls `-[NSSegmentedCell setImageScaling:forSegment:]`.
         * @param scaling Argument converted to the Objective-C parameter of the same role.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         */
        void set_image_scaling(ImageScaling scaling, std::int64_t segment) const;
        /**
         * @brief Calls `-[NSSegmentedCell setLabel:forSegment:]`.
         * @param label Argument converted to the Objective-C parameter of the same role.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         */
        void set_label(const std::string& label, std::int64_t segment) const;
        /**
         * @brief Calls `-[NSSegmentedCell setMenu:forSegment:]`.
         * @param menu Argument converted to the Objective-C parameter of the same role.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         */
        void set_menu(const Menu& menu, std::int64_t segment) const;
        /**
         * @brief Calls `-[NSSegmentedCell setSelected:forSegment:]`.
         * @param selected Argument converted to the Objective-C parameter of the same role.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         */
        void set_selected(bool selected, std::int64_t segment) const;
        /**
         * @brief Calls `-[NSSegmentedCell setTag:forSegment:]`.
         * @param tag Argument converted to the Objective-C parameter of the same role.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         */
        void set_tag(std::int64_t tag, std::int64_t segment) const;
        /**
         * @brief Calls `-[NSSegmentedCell setToolTip:forSegment:]`.
         * @param tool_tip Argument converted to the Objective-C parameter of the same role.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         */
        void set_tool_tip(const std::string& tool_tip, std::int64_t segment) const;
        /**
         * @brief Calls `-[NSSegmentedCell setWidth:forSegment:]`.
         * @details Width of 0 means autosize to fit
         * @param width Argument converted to the Objective-C parameter of the same role.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         */
        void set_width(double width, std::int64_t segment) const;
        /**
         * @brief Calls `-[NSSegmentedCell tagForSegment:]`.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t tag_for_segment(std::int64_t segment) const;
        /**
         * @brief Calls `-[NSSegmentedCell toolTipForSegment:]`.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string tool_tip_for_segment(std::int64_t segment) const;
        /**
         * @brief Calls `-[NSSegmentedCell widthForSegment:]`.
         * @param segment Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double width_for_segment(std::int64_t segment) const;
        /**
         * @brief Returns the `segmentCount` property of `NSSegmentedCell`.
         * @details Number of segments
         * @return The converted Objective-C result.
         */
        std::int64_t segment_count() const;
        /**
         * @brief Sets the `segmentCount` property of `NSSegmentedCell`.
         * @details Number of segments
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_segment_count(std::int64_t value) const;
        /**
         * @brief Returns the `segmentStyle` property of `NSSegmentedCell`.
         * @details see NSSegmentedControl.h for segment style names and values
         * @return The converted Objective-C result.
         */
        SegmentStyle segment_style() const;
        /**
         * @brief Sets the `segmentStyle` property of `NSSegmentedCell`.
         * @details see NSSegmentedControl.h for segment style names and values
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_segment_style(SegmentStyle value) const;
        /**
         * @brief Returns the `selectedSegment` property of `NSSegmentedCell`.
         * @details Which button is active. May turn off other segments depending on mode.
         * @return The converted Objective-C result.
         */
        std::int64_t selected_segment() const;
        /**
         * @brief Sets the `selectedSegment` property of `NSSegmentedCell`.
         * @details Which button is active. May turn off other segments depending on mode.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_selected_segment(std::int64_t value) const;
        /**
         * @brief Returns the `trackingMode` property of `NSSegmentedCell`.
         * @return The converted Objective-C result.
         */
        SegmentSwitchTracking tracking_mode() const;
        /**
         * @brief Sets the `trackingMode` property of `NSSegmentedCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tracking_mode(SegmentSwitchTracking value) const;
    };
}
