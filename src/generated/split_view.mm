#include "generated/split_view.h"
#include "internal.h"

@interface AKSplitViewDelegate : NSObject <NSSplitViewDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKSplitViewDelegate

- (BOOL)splitView:(NSSplitView*)splitView canCollapseSubview:(NSView*)subview
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SplitView, bool(cocoon::View)>::emit((__bridge void*)strongHost, "can_collapse_subview", cocoon::internal::wrap<cocoon::View>(subview));
    return static_cast<::BOOL>(__r);
}

- (CGFloat)splitView:(NSSplitView*)splitView constrainMinCoordinate:(CGFloat)proposedMinimumPosition ofSubviewAt:(NSInteger)dividerIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SplitView, double(double, std::int64_t)>::emit((__bridge void*)strongHost, "constrain_min_coordinate_of_subview_at", static_cast<double>(proposedMinimumPosition), static_cast<std::int64_t>(dividerIndex));
    return static_cast<::CGFloat>(__r);
}

- (CGFloat)splitView:(NSSplitView*)splitView constrainMaxCoordinate:(CGFloat)proposedMaximumPosition ofSubviewAt:(NSInteger)dividerIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SplitView, double(double, std::int64_t)>::emit((__bridge void*)strongHost, "constrain_max_coordinate_of_subview_at", static_cast<double>(proposedMaximumPosition), static_cast<std::int64_t>(dividerIndex));
    return static_cast<::CGFloat>(__r);
}

- (CGFloat)splitView:(NSSplitView*)splitView constrainSplitPosition:(CGFloat)proposedPosition ofSubviewAt:(NSInteger)dividerIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SplitView, double(double, std::int64_t)>::emit((__bridge void*)strongHost, "constrain_split_position_of_subview_at", static_cast<double>(proposedPosition), static_cast<std::int64_t>(dividerIndex));
    return static_cast<::CGFloat>(__r);
}

- (void)splitView:(NSSplitView*)splitView resizeSubviewsWithOldSize:(NSSize)oldSize
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SplitView, void(cocoon::Size)>::emit((__bridge void*)strongHost, "split_view_resize_subviews_with_old_size", cocoon::internal::from(oldSize));
}

- (BOOL)splitView:(NSSplitView*)splitView shouldAdjustSizeOfSubview:(NSView*)view
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SplitView, bool(cocoon::View)>::emit((__bridge void*)strongHost, "should_adjust_size_of_subview", cocoon::internal::wrap<cocoon::View>(view));
    return static_cast<::BOOL>(__r);
}

- (BOOL)splitView:(NSSplitView*)splitView shouldHideDividerAtIndex:(NSInteger)dividerIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SplitView, bool(std::int64_t)>::emit((__bridge void*)strongHost, "should_hide_divider_at_index", static_cast<std::int64_t>(dividerIndex));
    return static_cast<::BOOL>(__r);
}

- (NSRect)splitView:(NSSplitView*)splitView effectiveRect:(NSRect)proposedEffectiveRect forDrawnRect:(NSRect)drawnRect ofDividerAtIndex:(NSInteger)dividerIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SplitView, cocoon::Rect(cocoon::Rect, cocoon::Rect, std::int64_t)>::emit((__bridge void*)strongHost, "effective_rect_for_drawn_rect_of_divider_at_index", cocoon::internal::from(proposedEffectiveRect), cocoon::internal::from(drawnRect), static_cast<std::int64_t>(dividerIndex));
    return cocoon::internal::to(__r);
}

- (NSRect)splitView:(NSSplitView*)splitView additionalEffectiveRectOfDividerAtIndex:(NSInteger)dividerIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SplitView, cocoon::Rect(std::int64_t)>::emit((__bridge void*)strongHost, "additional_effective_rect_of_divider_at_index", static_cast<std::int64_t>(dividerIndex));
    return cocoon::internal::to(__r);
}

- (void)splitViewWillResizeSubviews:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SplitView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_resize_subviews", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)splitViewDidResizeSubviews:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SplitView, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_resize_subviews", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(splitView:canCollapseSubview:))
    {
        return strongHost && cocoon::Signal<cocoon::SplitView, bool(cocoon::View)>::connected((__bridge void*)strongHost, "can_collapse_subview");
    }
    if (selector == @selector(splitView:constrainMinCoordinate:ofSubviewAt:))
    {
        return strongHost && cocoon::Signal<cocoon::SplitView, double(double, std::int64_t)>::connected((__bridge void*)strongHost, "constrain_min_coordinate_of_subview_at");
    }
    if (selector == @selector(splitView:constrainMaxCoordinate:ofSubviewAt:))
    {
        return strongHost && cocoon::Signal<cocoon::SplitView, double(double, std::int64_t)>::connected((__bridge void*)strongHost, "constrain_max_coordinate_of_subview_at");
    }
    if (selector == @selector(splitView:constrainSplitPosition:ofSubviewAt:))
    {
        return strongHost && cocoon::Signal<cocoon::SplitView, double(double, std::int64_t)>::connected((__bridge void*)strongHost, "constrain_split_position_of_subview_at");
    }
    if (selector == @selector(splitView:resizeSubviewsWithOldSize:))
    {
        return strongHost && cocoon::Signal<cocoon::SplitView, void(cocoon::Size)>::connected((__bridge void*)strongHost, "split_view_resize_subviews_with_old_size");
    }
    if (selector == @selector(splitView:shouldAdjustSizeOfSubview:))
    {
        return strongHost && cocoon::Signal<cocoon::SplitView, bool(cocoon::View)>::connected((__bridge void*)strongHost, "should_adjust_size_of_subview");
    }
    if (selector == @selector(splitView:shouldHideDividerAtIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::SplitView, bool(std::int64_t)>::connected((__bridge void*)strongHost, "should_hide_divider_at_index");
    }
    if (selector == @selector(splitView:effectiveRect:forDrawnRect:ofDividerAtIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::SplitView, cocoon::Rect(cocoon::Rect, cocoon::Rect, std::int64_t)>::connected((__bridge void*)strongHost, "effective_rect_for_drawn_rect_of_divider_at_index");
    }
    if (selector == @selector(splitView:additionalEffectiveRectOfDividerAtIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::SplitView, cocoon::Rect(std::int64_t)>::connected((__bridge void*)strongHost, "additional_effective_rect_of_divider_at_index");
    }
    if (selector == @selector(splitViewWillResizeSubviews:))
    {
        return strongHost && cocoon::Signal<cocoon::SplitView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_resize_subviews");
    }
    if (selector == @selector(splitViewDidResizeSubviews:))
    {
        return strongHost && cocoon::Signal<cocoon::SplitView, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_resize_subviews");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    SplitView::SplitView() : SplitView(Adopt{cocoon::internal::retain([[::NSSplitView alloc] init])})
    {
        SplitView::install_delegate_delegate_(handle());
    }

    SplitView::SplitView(std::nullptr_t) : View(nullptr)
    {
    }

    SplitView::SplitView(Adopt adopt) : View(adopt)
    {
    }

    void SplitView::add_arranged_subview(const View& view) const
    {
        [cocoon::internal::ns<::NSSplitView>(this) addArrangedSubview:cocoon::internal::native<::NSView>(view)];
    }

    void SplitView::adjust_subviews() const
    {
        [cocoon::internal::ns<::NSSplitView>(this) adjustSubviews];
    }

    void SplitView::draw_divider_in_rect(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSSplitView>(this) drawDividerInRect:cocoon::internal::to(rect)];
    }

    float SplitView::holding_priority_for_subview_at_index(std::int64_t subview_index) const
    {
        return static_cast<float>([cocoon::internal::ns<::NSSplitView>(this) holdingPriorityForSubviewAtIndex:static_cast<::NSInteger>(subview_index)]);
    }

    void SplitView::insert_arranged_subview(const View& view, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSSplitView>(this) insertArrangedSubview:cocoon::internal::native<::NSView>(view) atIndex:static_cast<::NSInteger>(index)];
    }

    bool SplitView::is_subview_collapsed(const View& subview) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSplitView>(this) isSubviewCollapsed:cocoon::internal::native<::NSView>(subview)]);
    }

    double SplitView::max_possible_position_of_divider_at_index(std::int64_t divider_index) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSplitView>(this) maxPossiblePositionOfDividerAtIndex:static_cast<::NSInteger>(divider_index)]);
    }

    double SplitView::min_possible_position_of_divider_at_index(std::int64_t divider_index) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSplitView>(this) minPossiblePositionOfDividerAtIndex:static_cast<::NSInteger>(divider_index)]);
    }

    void SplitView::remove_arranged_subview(const View& view) const
    {
        [cocoon::internal::ns<::NSSplitView>(this) removeArrangedSubview:cocoon::internal::native<::NSView>(view)];
    }

    void SplitView::set_holding_priority(float priority, std::int64_t subview_index) const
    {
        [cocoon::internal::ns<::NSSplitView>(this) setHoldingPriority:static_cast<::NSLayoutPriority>(priority) forSubviewAtIndex:static_cast<::NSInteger>(subview_index)];
    }

    void SplitView::set_position(double position, std::int64_t divider_index) const
    {
        [cocoon::internal::ns<::NSSplitView>(this) setPosition:static_cast<::CGFloat>(position) ofDividerAtIndex:static_cast<::NSInteger>(divider_index)];
    }

    std::vector<View> SplitView::arranged_subviews() const
    {
        return cocoon::internal::from_array<View>([cocoon::internal::ns<::NSSplitView>(this) arrangedSubviews], [](id e) -> View
                                    {
                                        return cocoon::internal::wrap<View>((::NSView*)e);
                                    });
    }

    bool SplitView::arranges_all_subviews() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSplitView>(this) arrangesAllSubviews]);
    }

    void SplitView::set_arranges_all_subviews(bool value) const
    {
        [cocoon::internal::ns<::NSSplitView>(this) setArrangesAllSubviews:static_cast<::BOOL>(value)];
    }

    std::string SplitView::autosave_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSplitView>(this) autosaveName]);
    }

    void SplitView::set_autosave_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSSplitView>(this) setAutosaveName:cocoon::internal::to(value)];
    }

    Color SplitView::divider_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSSplitView>(this) dividerColor]);
    }

    DividerStyle SplitView::divider_style() const
    {
        return static_cast<DividerStyle>([cocoon::internal::ns<::NSSplitView>(this) dividerStyle]);
    }

    void SplitView::set_divider_style(DividerStyle value) const
    {
        [cocoon::internal::ns<::NSSplitView>(this) setDividerStyle:static_cast<::NSSplitViewDividerStyle>(value)];
    }

    double SplitView::divider_thickness() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSplitView>(this) dividerThickness]);
    }

    bool SplitView::is_vertical() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSplitView>(this) isVertical]);
    }

    void SplitView::set_vertical(bool value) const
    {
        [cocoon::internal::ns<::NSSplitView>(this) setVertical:static_cast<::BOOL>(value)];
    }

    void SplitView::install_delegate_delegate_(void* native)
    {
        ::NSSplitView* host = (__bridge ::NSSplitView*)native;
        AKSplitViewDelegate* delegate = [[AKSplitViewDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSSplitView* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSSplitView* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
