#pragma once

#include "generated/availability.h"
#include "generated/control.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class Image;
    class Menu;
    class UserInterfaceCompressionOptions;

    /**
     * @brief A segmented control.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Control.
     *
     * @par Example
     * @code
     * cocoon::SegmentedControl segments;
     * segments.set_segment_count(2);
     * segments.set_label("One", 0);
     * segments.set_label("Two", 1);
     * segments.selection_changed().connect([](std::int64_t segment) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SegmentedControl segmented_control{};
     * segmented_control.set_border_shape(cocoon::ControlBorderShape::Automatic);
     * auto border_shape = segmented_control.border_shape();
     * segmented_control.set_role(cocoon::SegmentedControlRole::Automatic);
     * auto role = segmented_control.role();
     * segmented_control.set_segment_count(1);
     * auto segment_count = segmented_control.segment_count();
     * segmented_control.alignment_for_segment(1);
     * segmented_control.image_for_segment(1);
     * segmented_control.image_scaling_for_segment(1);
     * segmented_control.selection_changed().connect([](std::int64_t a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssegmentedcontrol
     */
    class SegmentedControl : public Control
    {
    public:
        /// @brief Creates a new `NSSegmentedControl` instance and returns a handle to it.
        explicit SegmentedControl();
        /// @brief Creates a null handle that refers to no native object.
        SegmentedControl(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SegmentedControl(Adopt adopt);
        using Control::set_alignment;
        using Control::set_enabled;
        using Control::set_tag;
        using Responder::set_menu;
        using View::set_tool_tip;
        /**
     * @brief Calls `-[NSSegmentedControl alignmentForSegment:]`.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        TextAlignment alignment_for_segment(std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl compressWithPrioritizedCompressionOptions:]`.
     * @param prioritized_options Argument converted to the Objective-C parameter of the same role.
     */
        void compress_with_prioritized_compression_options(const std::vector<UserInterfaceCompressionOptions>& prioritized_options) const;
        /**
     * @brief Calls `-[NSSegmentedControl imageForSegment:]`.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Image image_for_segment(std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl imageScalingForSegment:]`.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ImageScaling image_scaling_for_segment(std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl isEnabledForSegment:]`.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_enabled_for_segment(std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl isSelectedForSegment:]`.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_selected_for_segment(std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl labelForSegment:]`.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string label_for_segment(std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl menuForSegment:]`.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Menu menu_for_segment(std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl minimumSizeWithPrioritizedCompressionOptions:]`.
     * @param prioritized_options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Size minimum_size_with_prioritized_compression_options(const std::vector<UserInterfaceCompressionOptions>& prioritized_options) const;
        /**
     * @brief Calls `+[NSSegmentedControl segmentedControlWithImages:trackingMode:target:action:]`.
     * @details Creates a standard segmented control containing one segment for each of the provided images. To ensure accessibility for this control, set the 'accessibilityDescription' property on each of the provided images. \@param images An array of image objects to use for the control's segments. \@param trackingMode The selection mode for the control. The NSSegmentSwitchTracking enum describes the possible values and their effects. \@param target The target object that receives action messages from the control. \@param action The action message sent by the control. \@return An initialized segmented control.
     * @param images Argument converted to the Objective-C parameter of the same role.
     * @param tracking_mode Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static SegmentedControl segmented_control_with_images(const std::vector<Image>& images, SegmentSwitchTracking tracking_mode, const Object& target, const std::string& action);
        /**
     * @brief Calls `+[NSSegmentedControl segmentedControlWithLabels:trackingMode:target:action:]`.
     * @details Creates a standard segmented control containing one segment for each of the provided labels. \@param labels An array of localized label strings to use for the control's segments. \@param trackingMode The selection mode for the control. The NSSegmentSwitchTracking enum describes the possible values and their effects. \@param target The target object that receives action messages from the control. \@param action The action message sent by the control. \@return An initialized segmented control.
     * @param labels Argument converted to the Objective-C parameter of the same role.
     * @param tracking_mode Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static SegmentedControl segmented_control_with_labels(const std::vector<std::string>& labels, SegmentSwitchTracking tracking_mode, const Object& target, const std::string& action);
        /**
     * @brief Calls `-[NSSegmentedControl selectSegmentWithTag:]`.
     * @param tag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool select_segment_with_tag(std::int64_t tag) const;
        /**
     * @brief Calls `-[NSSegmentedControl setAlignment:forSegment:]`.
     * @param alignment Argument converted to the Objective-C parameter of the same role.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     */
        void set_alignment(TextAlignment alignment, std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl setEnabled:forSegment:]`.
     * @param enabled Argument converted to the Objective-C parameter of the same role.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     */
        void set_enabled(bool enabled, std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl setImage:forSegment:]`.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     */
        void set_image(const Image& image, std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl setImageScaling:forSegment:]`.
     * @param scaling Argument converted to the Objective-C parameter of the same role.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     */
        void set_image_scaling(ImageScaling scaling, std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl setLabel:forSegment:]`.
     * @param label Argument converted to the Objective-C parameter of the same role.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     */
        void set_label(const std::string& label, std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl setMenu:forSegment:]`.
     * @param menu Argument converted to the Objective-C parameter of the same role.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     */
        void set_menu(const Menu& menu, std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl setSelected:forSegment:]`.
     * @param selected Argument converted to the Objective-C parameter of the same role.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     */
        void set_selected(bool selected, std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl setShowsMenuIndicator:forSegment:]`.
     * @param shows_menu_indicator Argument converted to the Objective-C parameter of the same role.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_menu_indicator(bool shows_menu_indicator, std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl setTag:forSegment:]`.
     * @param tag Argument converted to the Objective-C parameter of the same role.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     */
        void set_tag(std::int64_t tag, std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl setToolTip:forSegment:]`.
     * @param tool_tip Argument converted to the Objective-C parameter of the same role.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     */
        void set_tool_tip(const std::string& tool_tip, std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl setWidth:forSegment:]`.
     * @param width Argument converted to the Objective-C parameter of the same role.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     */
        void set_width(double width, std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl showsMenuIndicatorForSegment:]`.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool shows_menu_indicator_for_segment(std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl tagForSegment:]`.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t tag_for_segment(std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl toolTipForSegment:]`.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string tool_tip_for_segment(std::int64_t segment) const;
        /**
     * @brief Calls `-[NSSegmentedControl widthForSegment:]`.
     * @param segment Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double width_for_segment(std::int64_t segment) const;
        /**
     * @brief Returns the `activeCompressionOptions` property of `NSSegmentedControl`.
     * @return The converted Objective-C result.
     */
        UserInterfaceCompressionOptions active_compression_options() const;
        /**
     * @brief Returns the `borderShape` property of `NSSegmentedControl`.
     * @return The converted Objective-C result.
     */
        ControlBorderShape border_shape() const;
        /**
     * @brief Sets the `borderShape` property of `NSSegmentedControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_border_shape(ControlBorderShape value) const;
        /**
     * @brief Returns the `doubleValueForSelectedSegment` property of `NSSegmentedControl`.
     * @details This message is valid only for trackingMode=NSSegmentSwitchTrackingMomentaryAccelerator and provides the double value for the selected segment.
     * @return The converted Objective-C result.
     */
        double double_value_for_selected_segment() const;
        /**
     * @brief Returns the `indexOfSelectedItem` property of `NSSegmentedControl`.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_selected_item() const;
#ifdef COCOON_MACOS_27
        /**
     * @brief Returns the `role` property of `NSSegmentedControl`.
     * @return The converted Objective-C result.
     */
        SegmentedControlRole role() const;
#endif
#ifdef COCOON_MACOS_27
        /**
     * @brief Sets the `role` property of `NSSegmentedControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_role(SegmentedControlRole value) const;
#endif
        /**
     * @brief Returns the `segmentCount` property of `NSSegmentedControl`.
     * @return The converted Objective-C result.
     */
        std::int64_t segment_count() const;
        /**
     * @brief Sets the `segmentCount` property of `NSSegmentedControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_segment_count(std::int64_t value) const;
        /**
     * @brief Returns the `segmentDistribution` property of `NSSegmentedControl`.
     * @return The converted Objective-C result.
     */
        SegmentDistribution segment_distribution() const;
        /**
     * @brief Sets the `segmentDistribution` property of `NSSegmentedControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_segment_distribution(SegmentDistribution value) const;
        /**
     * @brief Returns the `segmentStyle` property of `NSSegmentedControl`.
     * @return The converted Objective-C result.
     */
        SegmentStyle segment_style() const;
        /**
     * @brief Sets the `segmentStyle` property of `NSSegmentedControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_segment_style(SegmentStyle value) const;
        /**
     * @brief Returns the `selectedSegment` property of `NSSegmentedControl`.
     * @return The converted Objective-C result.
     */
        std::int64_t selected_segment() const;
        /**
     * @brief Sets the `selectedSegment` property of `NSSegmentedControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selected_segment(std::int64_t value) const;
        /**
     * @brief Returns the `selectedSegmentBezelColor` property of `NSSegmentedControl`.
     * @return The converted Objective-C result.
     */
        Color selected_segment_bezel_color() const;
        /**
     * @brief Sets the `selectedSegmentBezelColor` property of `NSSegmentedControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selected_segment_bezel_color(const Color& value) const;
        /**
     * @brief Returns the `springLoaded` property of `NSSegmentedControl`.
     * @return The converted Objective-C result.
     */
        bool is_spring_loaded() const;
        /**
     * @brief Sets the `springLoaded` property of `NSSegmentedControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_spring_loaded(bool value) const;
        /**
     * @brief Returns the `trackingMode` property of `NSSegmentedControl`.
     * @return The converted Objective-C result.
     */
        SegmentSwitchTracking tracking_mode() const;
        /**
     * @brief Sets the `trackingMode` property of `NSSegmentedControl`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tracking_mode(SegmentSwitchTracking value) const;
        /// @brief Signal `selection_changed`: connect a callback with `selection_changed().connect(...)`.
        Signal<SegmentedControl, void(std::int64_t)> selection_changed() const
        {
            return Signal<SegmentedControl, void(std::int64_t)>(handle(), "selection_changed");
        }

    protected:
        static void bind_action_(void* native);
    };
}
