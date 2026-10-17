#include "generated/segmented_cell.h"
#include "internal.h"

namespace cocoon
{
    SegmentedCell::SegmentedCell() : SegmentedCell(Adopt{cocoon::internal::retain([[::NSSegmentedCell alloc] init])})
    {
    }

    SegmentedCell::SegmentedCell(std::nullptr_t) : ActionCell(nullptr)
    {
    }

    SegmentedCell::SegmentedCell(Adopt adopt) : ActionCell(adopt)
    {
    }

    void SegmentedCell::draw_segment(std::int64_t segment, const Rect& frame, const View& control_view) const
    {
        [cocoon::internal::ns<::NSSegmentedCell>(this) drawSegment:static_cast<::NSInteger>(segment) inFrame:cocoon::internal::to(frame) withView:cocoon::internal::native<::NSView>(control_view)];
    }

    Image SegmentedCell::image_for_segment(std::int64_t segment) const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSSegmentedCell>(this) imageForSegment:static_cast<::NSInteger>(segment)]);
    }

    ImageScaling SegmentedCell::image_scaling_for_segment(std::int64_t segment) const
    {
        return static_cast<ImageScaling>([cocoon::internal::ns<::NSSegmentedCell>(this) imageScalingForSegment:static_cast<::NSInteger>(segment)]);
    }

    BackgroundStyle SegmentedCell::interior_background_style_for_segment(std::int64_t segment) const
    {
        return static_cast<BackgroundStyle>([cocoon::internal::ns<::NSSegmentedCell>(this) interiorBackgroundStyleForSegment:static_cast<::NSInteger>(segment)]);
    }

    bool SegmentedCell::is_enabled_for_segment(std::int64_t segment) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSegmentedCell>(this) isEnabledForSegment:static_cast<::NSInteger>(segment)]);
    }

    bool SegmentedCell::is_selected_for_segment(std::int64_t segment) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSegmentedCell>(this) isSelectedForSegment:static_cast<::NSInteger>(segment)]);
    }

    std::string SegmentedCell::label_for_segment(std::int64_t segment) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSegmentedCell>(this) labelForSegment:static_cast<::NSInteger>(segment)]);
    }

    void SegmentedCell::make_next_segment_key() const
    {
        [cocoon::internal::ns<::NSSegmentedCell>(this) makeNextSegmentKey];
    }

    void SegmentedCell::make_previous_segment_key() const
    {
        [cocoon::internal::ns<::NSSegmentedCell>(this) makePreviousSegmentKey];
    }

    Menu SegmentedCell::menu_for_segment(std::int64_t segment) const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSSegmentedCell>(this) menuForSegment:static_cast<::NSInteger>(segment)]);
    }

    bool SegmentedCell::select_segment_with_tag(std::int64_t tag) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSegmentedCell>(this) selectSegmentWithTag:static_cast<::NSInteger>(tag)]);
    }

    void SegmentedCell::set_enabled(bool enabled, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedCell>(this) setEnabled:static_cast<::BOOL>(enabled) forSegment:static_cast<::NSInteger>(segment)];
    }

    void SegmentedCell::set_image(const Image& image, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedCell>(this) setImage:cocoon::internal::native<::NSImage>(image) forSegment:static_cast<::NSInteger>(segment)];
    }

    void SegmentedCell::set_image_scaling(ImageScaling scaling, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedCell>(this) setImageScaling:static_cast<::NSImageScaling>(scaling) forSegment:static_cast<::NSInteger>(segment)];
    }

    void SegmentedCell::set_label(const std::string& label, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedCell>(this) setLabel:cocoon::internal::to(label) forSegment:static_cast<::NSInteger>(segment)];
    }

    void SegmentedCell::set_menu(const Menu& menu, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedCell>(this) setMenu:cocoon::internal::native<::NSMenu>(menu) forSegment:static_cast<::NSInteger>(segment)];
    }

    void SegmentedCell::set_selected(bool selected, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedCell>(this) setSelected:static_cast<::BOOL>(selected) forSegment:static_cast<::NSInteger>(segment)];
    }

    void SegmentedCell::set_tag(std::int64_t tag, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedCell>(this) setTag:static_cast<::NSInteger>(tag) forSegment:static_cast<::NSInteger>(segment)];
    }

    void SegmentedCell::set_tool_tip(const std::string& tool_tip, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedCell>(this) setToolTip:cocoon::internal::to(tool_tip) forSegment:static_cast<::NSInteger>(segment)];
    }

    void SegmentedCell::set_width(double width, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedCell>(this) setWidth:static_cast<::CGFloat>(width) forSegment:static_cast<::NSInteger>(segment)];
    }

    std::int64_t SegmentedCell::tag_for_segment(std::int64_t segment) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSSegmentedCell>(this) tagForSegment:static_cast<::NSInteger>(segment)]);
    }

    std::string SegmentedCell::tool_tip_for_segment(std::int64_t segment) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSegmentedCell>(this) toolTipForSegment:static_cast<::NSInteger>(segment)]);
    }

    double SegmentedCell::width_for_segment(std::int64_t segment) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSegmentedCell>(this) widthForSegment:static_cast<::NSInteger>(segment)]);
    }

    std::int64_t SegmentedCell::segment_count() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSSegmentedCell>(this) segmentCount]);
    }

    void SegmentedCell::set_segment_count(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSSegmentedCell>(this) setSegmentCount:static_cast<::NSInteger>(value)];
    }

    SegmentStyle SegmentedCell::segment_style() const
    {
        return static_cast<SegmentStyle>([cocoon::internal::ns<::NSSegmentedCell>(this) segmentStyle]);
    }

    void SegmentedCell::set_segment_style(SegmentStyle value) const
    {
        [cocoon::internal::ns<::NSSegmentedCell>(this) setSegmentStyle:static_cast<::NSSegmentStyle>(value)];
    }

    std::int64_t SegmentedCell::selected_segment() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSSegmentedCell>(this) selectedSegment]);
    }

    void SegmentedCell::set_selected_segment(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSSegmentedCell>(this) setSelectedSegment:static_cast<::NSInteger>(value)];
    }

    SegmentSwitchTracking SegmentedCell::tracking_mode() const
    {
        return static_cast<SegmentSwitchTracking>([cocoon::internal::ns<::NSSegmentedCell>(this) trackingMode]);
    }

    void SegmentedCell::set_tracking_mode(SegmentSwitchTracking value) const
    {
        [cocoon::internal::ns<::NSSegmentedCell>(this) setTrackingMode:static_cast<::NSSegmentSwitchTracking>(value)];
    }
}
