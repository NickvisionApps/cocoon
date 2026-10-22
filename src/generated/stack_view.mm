#include "generated/stack_view.h"
#include "internal.h"

@interface AKStackViewDelegate : NSObject <NSStackViewDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKStackViewDelegate

- (void)stackView:(NSStackView*)stackView willDetachViews:(NSArray<NSView*>*)views
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::StackView, void(std::vector<cocoon::View>)>::emit((__bridge void*)strongHost, "will_detach_views", cocoon::internal::from_array<cocoon::View>(views, [](id e) -> cocoon::View
                                                                                                                                                                         {
                                                                                                                                                                             return cocoon::internal::wrap<cocoon::View>((::NSView*)e);
                                                                                                                                                                         }));
}

- (void)stackView:(NSStackView*)stackView didReattachViews:(NSArray<NSView*>*)views
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::StackView, void(std::vector<cocoon::View>)>::emit((__bridge void*)strongHost, "did_reattach_views", cocoon::internal::from_array<cocoon::View>(views, [](id e) -> cocoon::View
                                                                                                                                                                          {
                                                                                                                                                                              return cocoon::internal::wrap<cocoon::View>((::NSView*)e);
                                                                                                                                                                          }));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(stackView:willDetachViews:))
    {
        return strongHost && cocoon::Signal<cocoon::StackView, void(std::vector<cocoon::View>)>::connected((__bridge void*)strongHost, "will_detach_views");
    }
    if (selector == @selector(stackView:didReattachViews:))
    {
        return strongHost && cocoon::Signal<cocoon::StackView, void(std::vector<cocoon::View>)>::connected((__bridge void*)strongHost, "did_reattach_views");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    StackView::StackView() : StackView(Adopt{cocoon::internal::retain([[NSStackView alloc] init])})
    {
        StackView::install_delegate_delegate_(handle());
    }

    StackView::StackView(const std::vector<View>& views) : StackView(Adopt{cocoon::internal::retain([::NSStackView stackViewWithViews:cocoon::internal::to_array(views, [](const View& e) -> id
                                                                                                                                                                 {
                                                                                                                                                                     return cocoon::internal::native<::NSView>(e);
                                                                                                                                                                 })])})
    {
        StackView::install_delegate_delegate_(handle());
    }

    StackView::StackView(std::nullptr_t) : View(nullptr)
    {
    }

    StackView::StackView(Adopt adopt) : View(adopt)
    {
    }

    void StackView::add_arranged_subview(const View& view) const
    {
        [cocoon::internal::ns<::NSStackView>(this) addArrangedSubview:cocoon::internal::native<::NSView>(view)];
    }

    void StackView::add_view(const View& view, StackViewGravity gravity) const
    {
        [cocoon::internal::ns<::NSStackView>(this) addView:cocoon::internal::native<::NSView>(view) inGravity:static_cast<::NSStackViewGravity>(gravity)];
    }

    float StackView::clipping_resistance_priority_for_orientation(ConstraintOrientation orientation) const
    {
        return static_cast<float>([cocoon::internal::ns<::NSStackView>(this) clippingResistancePriorityForOrientation:static_cast<::NSLayoutConstraintOrientation>(orientation)]);
    }

    double StackView::custom_spacing_after_view(const View& view) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSStackView>(this) customSpacingAfterView:cocoon::internal::native<::NSView>(view)]);
    }

    float StackView::hugging_priority_for_orientation(ConstraintOrientation orientation) const
    {
        return static_cast<float>([cocoon::internal::ns<::NSStackView>(this) huggingPriorityForOrientation:static_cast<::NSLayoutConstraintOrientation>(orientation)]);
    }

    void StackView::insert_arranged_subview(const View& view, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSStackView>(this) insertArrangedSubview:cocoon::internal::native<::NSView>(view) atIndex:static_cast<::NSInteger>(index)];
    }

    void StackView::insert_view(const View& view, std::uint64_t index, StackViewGravity gravity) const
    {
        [cocoon::internal::ns<::NSStackView>(this) insertView:cocoon::internal::native<::NSView>(view) atIndex:static_cast<::NSUInteger>(index) inGravity:static_cast<::NSStackViewGravity>(gravity)];
    }

    void StackView::remove_arranged_subview(const View& view) const
    {
        [cocoon::internal::ns<::NSStackView>(this) removeArrangedSubview:cocoon::internal::native<::NSView>(view)];
    }

    void StackView::remove_view(const View& view) const
    {
        [cocoon::internal::ns<::NSStackView>(this) removeView:cocoon::internal::native<::NSView>(view)];
    }

    void StackView::set_clipping_resistance_priority(float clipping_resistance_priority, ConstraintOrientation orientation) const
    {
        [cocoon::internal::ns<::NSStackView>(this) setClippingResistancePriority:static_cast<::NSLayoutPriority>(clipping_resistance_priority) forOrientation:static_cast<::NSLayoutConstraintOrientation>(orientation)];
    }

    void StackView::set_custom_spacing(double spacing, const View& view) const
    {
        [cocoon::internal::ns<::NSStackView>(this) setCustomSpacing:static_cast<::CGFloat>(spacing) afterView:cocoon::internal::native<::NSView>(view)];
    }

    void StackView::set_hugging_priority(float hugging_priority, ConstraintOrientation orientation) const
    {
        [cocoon::internal::ns<::NSStackView>(this) setHuggingPriority:static_cast<::NSLayoutPriority>(hugging_priority) forOrientation:static_cast<::NSLayoutConstraintOrientation>(orientation)];
    }

    void StackView::set_views(const std::vector<View>& views, StackViewGravity gravity) const
    {
        [cocoon::internal::ns<::NSStackView>(this) setViews:cocoon::internal::to_array(views, [](const View& e) -> id
                                                                                       {
                                                                                           return cocoon::internal::native<::NSView>(e);
                                                                                       })
                                                  inGravity:static_cast<::NSStackViewGravity>(gravity)];
    }

    void StackView::set_visibility_priority(float priority, const View& view) const
    {
        [cocoon::internal::ns<::NSStackView>(this) setVisibilityPriority:static_cast<::NSStackViewVisibilityPriority>(priority) forView:cocoon::internal::native<::NSView>(view)];
    }

    std::vector<View> StackView::views_in_gravity(StackViewGravity gravity) const
    {
        return cocoon::internal::from_array<View>([cocoon::internal::ns<::NSStackView>(this) viewsInGravity:static_cast<::NSStackViewGravity>(gravity)], [](id e) -> View
                                                  {
                                                      return cocoon::internal::wrap<View>((::NSView*)e);
                                                  });
    }

    float StackView::visibility_priority_for_view(const View& view) const
    {
        return static_cast<float>([cocoon::internal::ns<::NSStackView>(this) visibilityPriorityForView:cocoon::internal::native<::NSView>(view)]);
    }

    LayoutAttribute StackView::alignment() const
    {
        return static_cast<LayoutAttribute>([cocoon::internal::ns<::NSStackView>(this) alignment]);
    }

    void StackView::set_alignment(LayoutAttribute value) const
    {
        [cocoon::internal::ns<::NSStackView>(this) setAlignment:static_cast<::NSLayoutAttribute>(value)];
    }

    std::vector<View> StackView::arranged_subviews() const
    {
        return cocoon::internal::from_array<View>([cocoon::internal::ns<::NSStackView>(this) arrangedSubviews], [](id e) -> View
                                                  {
                                                      return cocoon::internal::wrap<View>((::NSView*)e);
                                                  });
    }

    std::vector<View> StackView::detached_views() const
    {
        return cocoon::internal::from_array<View>([cocoon::internal::ns<::NSStackView>(this) detachedViews], [](id e) -> View
                                                  {
                                                      return cocoon::internal::wrap<View>((::NSView*)e);
                                                  });
    }

    bool StackView::detaches_hidden_views() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSStackView>(this) detachesHiddenViews]);
    }

    void StackView::set_detaches_hidden_views(bool value) const
    {
        [cocoon::internal::ns<::NSStackView>(this) setDetachesHiddenViews:static_cast<::BOOL>(value)];
    }

    StackViewDistribution StackView::distribution() const
    {
        return static_cast<StackViewDistribution>([cocoon::internal::ns<::NSStackView>(this) distribution]);
    }

    void StackView::set_distribution(StackViewDistribution value) const
    {
        [cocoon::internal::ns<::NSStackView>(this) setDistribution:static_cast<::NSStackViewDistribution>(value)];
    }

    Insets StackView::edge_insets() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSStackView>(this) edgeInsets]);
    }

    void StackView::set_edge_insets(const Insets& value) const
    {
        [cocoon::internal::ns<::NSStackView>(this) setEdgeInsets:cocoon::internal::to(value)];
    }

    Orientation StackView::orientation() const
    {
        return static_cast<Orientation>([cocoon::internal::ns<::NSStackView>(this) orientation]);
    }

    void StackView::set_orientation(Orientation value) const
    {
        [cocoon::internal::ns<::NSStackView>(this) setOrientation:static_cast<::NSUserInterfaceLayoutOrientation>(value)];
    }

    double StackView::spacing() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSStackView>(this) spacing]);
    }

    void StackView::set_spacing(double value) const
    {
        [cocoon::internal::ns<::NSStackView>(this) setSpacing:static_cast<::CGFloat>(value)];
    }

    std::vector<View> StackView::views() const
    {
        return cocoon::internal::from_array<View>([cocoon::internal::ns<::NSStackView>(this) views], [](id e) -> View
                                                  {
                                                      return cocoon::internal::wrap<View>((::NSView*)e);
                                                  });
    }

    void StackView::add_arranged_subviews(const std::vector<View>& views) const
    {
        for (const View& view : views)
        {
            [cocoon::internal::ns<NSStackView>(this) addArrangedSubview:cocoon::internal::native<NSView>(view)];
        }
    }

    void StackView::install_delegate_delegate_(void* native)
    {
        ::NSStackView* host = (__bridge ::NSStackView*)native;
        AKStackViewDelegate* delegate = [[AKStackViewDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSStackView* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSStackView* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
