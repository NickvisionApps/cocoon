#include "generated/segmented_control.h"
#include "internal.h"

namespace cocoon
{
    SegmentedControl::SegmentedControl() : SegmentedControl(Adopt{cocoon::internal::retain([[NSSegmentedControl alloc] init])})
    {
        SegmentedControl::bind_action_(handle());
    }

    SegmentedControl::SegmentedControl(std::nullptr_t) : Control(nullptr)
    {
    }

    SegmentedControl::SegmentedControl(Adopt adopt) : Control(adopt)
    {
    }

    TextAlignment SegmentedControl::alignment_for_segment(std::int64_t segment) const
    {
        return static_cast<TextAlignment>([cocoon::internal::ns<::NSSegmentedControl>(this) alignmentForSegment:static_cast<::NSInteger>(segment)]);
    }

    void SegmentedControl::compress_with_prioritized_compression_options(const std::vector<UserInterfaceCompressionOptions>& prioritized_options) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) compressWithPrioritizedCompressionOptions:cocoon::internal::to_array(prioritized_options, [](const UserInterfaceCompressionOptions& e) -> id
                                                                                                                               {
                                                                                                                                   return cocoon::internal::native<::NSUserInterfaceCompressionOptions>(e);
                                                                                                                               })];
    }

    Image SegmentedControl::image_for_segment(std::int64_t segment) const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSSegmentedControl>(this) imageForSegment:static_cast<::NSInteger>(segment)]);
    }

    ImageScaling SegmentedControl::image_scaling_for_segment(std::int64_t segment) const
    {
        return static_cast<ImageScaling>([cocoon::internal::ns<::NSSegmentedControl>(this) imageScalingForSegment:static_cast<::NSInteger>(segment)]);
    }

    bool SegmentedControl::is_enabled_for_segment(std::int64_t segment) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSegmentedControl>(this) isEnabledForSegment:static_cast<::NSInteger>(segment)]);
    }

    bool SegmentedControl::is_selected_for_segment(std::int64_t segment) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSegmentedControl>(this) isSelectedForSegment:static_cast<::NSInteger>(segment)]);
    }

    std::string SegmentedControl::label_for_segment(std::int64_t segment) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSegmentedControl>(this) labelForSegment:static_cast<::NSInteger>(segment)]);
    }

    Menu SegmentedControl::menu_for_segment(std::int64_t segment) const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSSegmentedControl>(this) menuForSegment:static_cast<::NSInteger>(segment)]);
    }

    Size SegmentedControl::minimum_size_with_prioritized_compression_options(const std::vector<UserInterfaceCompressionOptions>& prioritized_options) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSegmentedControl>(this) minimumSizeWithPrioritizedCompressionOptions:cocoon::internal::to_array(prioritized_options, [](const UserInterfaceCompressionOptions& e) -> id
                                                                                                                                                                {
                                                                                                                                                                    return cocoon::internal::native<::NSUserInterfaceCompressionOptions>(e);
                                                                                                                                                                })]);
    }

    SegmentedControl SegmentedControl::segmented_control_with_images(const std::vector<Image>& images, SegmentSwitchTracking tracking_mode, const Object& target, const std::string& action)
    {
        return cocoon::internal::wrap<SegmentedControl>([::NSSegmentedControl segmentedControlWithImages:cocoon::internal::to_array(images, [](const Image& e) -> id
                                                                                                                                    {
                                                                                                                                        return cocoon::internal::native<::NSImage>(e);
                                                                                                                                    })
                                                                                            trackingMode:static_cast<::NSSegmentSwitchTracking>(tracking_mode)
                                                                                                  target:cocoon::internal::native_id(target)
                                                                                                  action:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    SegmentedControl SegmentedControl::segmented_control_with_labels(const std::vector<std::string>& labels, SegmentSwitchTracking tracking_mode, const Object& target, const std::string& action)
    {
        return cocoon::internal::wrap<SegmentedControl>([::NSSegmentedControl segmentedControlWithLabels:cocoon::internal::to_array(labels, [](const std::string& e) -> id
                                                                                                                                    {
                                                                                                                                        return cocoon::internal::to(e);
                                                                                                                                    })
                                                                                            trackingMode:static_cast<::NSSegmentSwitchTracking>(tracking_mode)
                                                                                                  target:cocoon::internal::native_id(target)
                                                                                                  action:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    bool SegmentedControl::select_segment_with_tag(std::int64_t tag) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSegmentedControl>(this) selectSegmentWithTag:static_cast<::NSInteger>(tag)]);
    }

    void SegmentedControl::set_alignment(TextAlignment alignment, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setAlignment:static_cast<::NSTextAlignment>(alignment) forSegment:static_cast<::NSInteger>(segment)];
    }

    void SegmentedControl::set_enabled(bool enabled, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setEnabled:static_cast<::BOOL>(enabled) forSegment:static_cast<::NSInteger>(segment)];
    }

    void SegmentedControl::set_image(const Image& image, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setImage:cocoon::internal::native<::NSImage>(image) forSegment:static_cast<::NSInteger>(segment)];
    }

    void SegmentedControl::set_image_scaling(ImageScaling scaling, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setImageScaling:static_cast<::NSImageScaling>(scaling) forSegment:static_cast<::NSInteger>(segment)];
    }

    void SegmentedControl::set_label(const std::string& label, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setLabel:cocoon::internal::to(label) forSegment:static_cast<::NSInteger>(segment)];
    }

    void SegmentedControl::set_menu(const Menu& menu, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setMenu:cocoon::internal::native<::NSMenu>(menu) forSegment:static_cast<::NSInteger>(segment)];
    }

    void SegmentedControl::set_selected(bool selected, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setSelected:static_cast<::BOOL>(selected) forSegment:static_cast<::NSInteger>(segment)];
    }

    void SegmentedControl::set_shows_menu_indicator(bool shows_menu_indicator, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setShowsMenuIndicator:static_cast<::BOOL>(shows_menu_indicator) forSegment:static_cast<::NSInteger>(segment)];
    }

    void SegmentedControl::set_tag(std::int64_t tag, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setTag:static_cast<::NSInteger>(tag) forSegment:static_cast<::NSInteger>(segment)];
    }

    void SegmentedControl::set_tool_tip(const std::string& tool_tip, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setToolTip:cocoon::internal::to(tool_tip) forSegment:static_cast<::NSInteger>(segment)];
    }

    void SegmentedControl::set_width(double width, std::int64_t segment) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setWidth:static_cast<::CGFloat>(width) forSegment:static_cast<::NSInteger>(segment)];
    }

    bool SegmentedControl::shows_menu_indicator_for_segment(std::int64_t segment) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSegmentedControl>(this) showsMenuIndicatorForSegment:static_cast<::NSInteger>(segment)]);
    }

    std::int64_t SegmentedControl::tag_for_segment(std::int64_t segment) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSSegmentedControl>(this) tagForSegment:static_cast<::NSInteger>(segment)]);
    }

    std::string SegmentedControl::tool_tip_for_segment(std::int64_t segment) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSegmentedControl>(this) toolTipForSegment:static_cast<::NSInteger>(segment)]);
    }

    double SegmentedControl::width_for_segment(std::int64_t segment) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSegmentedControl>(this) widthForSegment:static_cast<::NSInteger>(segment)]);
    }

    UserInterfaceCompressionOptions SegmentedControl::active_compression_options() const
    {
        return cocoon::internal::wrap<UserInterfaceCompressionOptions>([cocoon::internal::ns<::NSSegmentedControl>(this) activeCompressionOptions]);
    }

    ControlBorderShape SegmentedControl::border_shape() const
    {
        return static_cast<ControlBorderShape>([cocoon::internal::ns<::NSSegmentedControl>(this) borderShape]);
    }

    void SegmentedControl::set_border_shape(ControlBorderShape value) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setBorderShape:static_cast<::NSControlBorderShape>(value)];
    }

    double SegmentedControl::double_value_for_selected_segment() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSegmentedControl>(this) doubleValueForSelectedSegment]);
    }

    std::int64_t SegmentedControl::index_of_selected_item() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSSegmentedControl>(this) indexOfSelectedItem]);
    }

#ifdef COCOON_MACOS_27
    SegmentedControlRole SegmentedControl::role() const
    {
        if (@available(macOS 27.0, *))
        {
            return static_cast<SegmentedControlRole>([cocoon::internal::ns<::NSSegmentedControl>(this) role]);
        }
        return {};
    }

#endif
#ifdef COCOON_MACOS_27
    void SegmentedControl::set_role(SegmentedControlRole value) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSSegmentedControl>(this) setRole:static_cast<::NSSegmentedControlRole>(value)];
        }
    }

#endif
    std::int64_t SegmentedControl::segment_count() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSSegmentedControl>(this) segmentCount]);
    }

    void SegmentedControl::set_segment_count(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setSegmentCount:static_cast<::NSInteger>(value)];
    }

    SegmentDistribution SegmentedControl::segment_distribution() const
    {
        return static_cast<SegmentDistribution>([cocoon::internal::ns<::NSSegmentedControl>(this) segmentDistribution]);
    }

    void SegmentedControl::set_segment_distribution(SegmentDistribution value) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setSegmentDistribution:static_cast<::NSSegmentDistribution>(value)];
    }

    SegmentStyle SegmentedControl::segment_style() const
    {
        return static_cast<SegmentStyle>([cocoon::internal::ns<::NSSegmentedControl>(this) segmentStyle]);
    }

    void SegmentedControl::set_segment_style(SegmentStyle value) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setSegmentStyle:static_cast<::NSSegmentStyle>(value)];
    }

    std::int64_t SegmentedControl::selected_segment() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSSegmentedControl>(this) selectedSegment]);
    }

    void SegmentedControl::set_selected_segment(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setSelectedSegment:static_cast<::NSInteger>(value)];
    }

    Color SegmentedControl::selected_segment_bezel_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSSegmentedControl>(this) selectedSegmentBezelColor]);
    }

    void SegmentedControl::set_selected_segment_bezel_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setSelectedSegmentBezelColor:cocoon::internal::native<::NSColor>(value)];
    }

    bool SegmentedControl::is_spring_loaded() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSegmentedControl>(this) isSpringLoaded]);
    }

    void SegmentedControl::set_spring_loaded(bool value) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setSpringLoaded:static_cast<::BOOL>(value)];
    }

    SegmentSwitchTracking SegmentedControl::tracking_mode() const
    {
        return static_cast<SegmentSwitchTracking>([cocoon::internal::ns<::NSSegmentedControl>(this) trackingMode]);
    }

    void SegmentedControl::set_tracking_mode(SegmentSwitchTracking value) const
    {
        [cocoon::internal::ns<::NSSegmentedControl>(this) setTrackingMode:static_cast<::NSSegmentSwitchTracking>(value)];
    }

    void SegmentedControl::bind_action_(void* native)
    {
        id host = (__bridge id)native;
        cocoon::internal::bind_action(host, host, [](id host, id sender)
                                      {
                                          cocoon::Signal<cocoon::SegmentedControl, void(std::int64_t)>::emit((__bridge void*)host, "selection_changed", [(NSSegmentedControl*)sender selectedSegment]);
                                      });
    }
}
