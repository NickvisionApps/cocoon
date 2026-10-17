#include "generated/tab_view.h"
#include "internal.h"

@interface AKTabViewDelegate : NSObject <NSTabViewDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKTabViewDelegate

- (BOOL)tabView:(NSTabView*)tabView shouldSelectTabViewItem:(NSTabViewItem*)tabViewItem
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TabView, bool(cocoon::TabViewItem)>::emit((__bridge void*)strongHost, "should_select_tab_view_item", cocoon::internal::wrap<cocoon::TabViewItem>(tabViewItem));
    return static_cast<::BOOL>(__r);
}

- (void)tabView:(NSTabView*)tabView willSelectTabViewItem:(NSTabViewItem*)tabViewItem
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TabView, void(cocoon::TabViewItem)>::emit((__bridge void*)strongHost, "will_select_tab_view_item", cocoon::internal::wrap<cocoon::TabViewItem>(tabViewItem));
}

- (void)tabView:(NSTabView*)tabView didSelectTabViewItem:(NSTabViewItem*)tabViewItem
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TabView, void(int)>::emit((__bridge void*)strongHost, "selection_changed", static_cast<int>([tabView indexOfTabViewItem:tabViewItem]));
}

- (void)tabViewDidChangeNumberOfTabViewItems:(NSTabView*)tabView
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TabView, void()>::emit((__bridge void*)strongHost, "did_change_number_of_tab_view_items");
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(tabView:shouldSelectTabViewItem:))
    {
        return strongHost && cocoon::Signal<cocoon::TabView, bool(cocoon::TabViewItem)>::connected((__bridge void*)strongHost, "should_select_tab_view_item");
    }
    if (selector == @selector(tabView:willSelectTabViewItem:))
    {
        return strongHost && cocoon::Signal<cocoon::TabView, void(cocoon::TabViewItem)>::connected((__bridge void*)strongHost, "will_select_tab_view_item");
    }
    if (selector == @selector(tabView:didSelectTabViewItem:))
    {
        return strongHost && cocoon::Signal<cocoon::TabView, void(int)>::connected((__bridge void*)strongHost, "selection_changed");
    }
    if (selector == @selector(tabViewDidChangeNumberOfTabViewItems:))
    {
        return strongHost && cocoon::Signal<cocoon::TabView, void()>::connected((__bridge void*)strongHost, "did_change_number_of_tab_view_items");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    TabView::TabView() : TabView(Adopt{cocoon::internal::retain([[NSTabView alloc] init])})
    {
        TabView::install_delegate_delegate_(handle());
    }

    TabView::TabView(std::nullptr_t) : View(nullptr)
    {
    }

    TabView::TabView(Adopt adopt) : View(adopt)
    {
    }

    void TabView::add_tab_view_item(const TabViewItem& tab_view_item) const
    {
        [cocoon::internal::ns<::NSTabView>(this) addTabViewItem:cocoon::internal::native<::NSTabViewItem>(tab_view_item)];
    }

    std::int64_t TabView::index_of_tab_view_item(const TabViewItem& tab_view_item) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTabView>(this) indexOfTabViewItem:cocoon::internal::native<::NSTabViewItem>(tab_view_item)]);
    }

    std::int64_t TabView::index_of_tab_view_item_with_identifier(const Object& identifier) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTabView>(this) indexOfTabViewItemWithIdentifier:cocoon::internal::native_id(identifier)]);
    }

    void TabView::insert_tab_view_item(const TabViewItem& tab_view_item, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSTabView>(this) insertTabViewItem:cocoon::internal::native<::NSTabViewItem>(tab_view_item) atIndex:static_cast<::NSInteger>(index)];
    }

    void TabView::remove_tab_view_item(const TabViewItem& tab_view_item) const
    {
        [cocoon::internal::ns<::NSTabView>(this) removeTabViewItem:cocoon::internal::native<::NSTabViewItem>(tab_view_item)];
    }

    void TabView::select_first_tab_view_item(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTabView>(this) selectFirstTabViewItem:cocoon::internal::native_id(sender)];
    }

    void TabView::select_last_tab_view_item(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTabView>(this) selectLastTabViewItem:cocoon::internal::native_id(sender)];
    }

    void TabView::select_next_tab_view_item(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTabView>(this) selectNextTabViewItem:cocoon::internal::native_id(sender)];
    }

    void TabView::select_previous_tab_view_item(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTabView>(this) selectPreviousTabViewItem:cocoon::internal::native_id(sender)];
    }

    void TabView::select_tab_view_item(const TabViewItem& tab_view_item) const
    {
        [cocoon::internal::ns<::NSTabView>(this) selectTabViewItem:cocoon::internal::native<::NSTabViewItem>(tab_view_item)];
    }

    void TabView::select_tab_view_item_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSTabView>(this) selectTabViewItemAtIndex:static_cast<::NSInteger>(index)];
    }

    void TabView::select_tab_view_item_with_identifier(const Object& identifier) const
    {
        [cocoon::internal::ns<::NSTabView>(this) selectTabViewItemWithIdentifier:cocoon::internal::native_id(identifier)];
    }

    TabViewItem TabView::tab_view_item_at_index(std::int64_t index) const
    {
        return cocoon::internal::wrap<TabViewItem>([cocoon::internal::ns<::NSTabView>(this) tabViewItemAtIndex:static_cast<::NSInteger>(index)]);
    }

    TabViewItem TabView::tab_view_item_at_point(const Point& point) const
    {
        return cocoon::internal::wrap<TabViewItem>([cocoon::internal::ns<::NSTabView>(this) tabViewItemAtPoint:cocoon::internal::to(point)]);
    }

    void TabView::take_selected_tab_view_item_from_sender(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTabView>(this) takeSelectedTabViewItemFromSender:cocoon::internal::native_id(sender)];
    }

    bool TabView::allows_truncated_labels() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTabView>(this) allowsTruncatedLabels]);
    }

    void TabView::set_allows_truncated_labels(bool value) const
    {
        [cocoon::internal::ns<::NSTabView>(this) setAllowsTruncatedLabels:static_cast<::BOOL>(value)];
    }

    Rect TabView::content_rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTabView>(this) contentRect]);
    }

    ControlSize TabView::control_size() const
    {
        return static_cast<ControlSize>([cocoon::internal::ns<::NSTabView>(this) controlSize]);
    }

    void TabView::set_control_size(ControlSize value) const
    {
        [cocoon::internal::ns<::NSTabView>(this) setControlSize:static_cast<::NSControlSize>(value)];
    }

    bool TabView::draws_background() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTabView>(this) drawsBackground]);
    }

    void TabView::set_draws_background(bool value) const
    {
        [cocoon::internal::ns<::NSTabView>(this) setDrawsBackground:static_cast<::BOOL>(value)];
    }

    Font TabView::font() const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSTabView>(this) font]);
    }

    void TabView::set_font(const Font& value) const
    {
        [cocoon::internal::ns<::NSTabView>(this) setFont:cocoon::internal::native<::NSFont>(value)];
    }

    Size TabView::minimum_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTabView>(this) minimumSize]);
    }

    std::int64_t TabView::number_of_tab_view_items() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTabView>(this) numberOfTabViewItems]);
    }

    TabViewItem TabView::selected_tab_view_item() const
    {
        return cocoon::internal::wrap<TabViewItem>([cocoon::internal::ns<::NSTabView>(this) selectedTabViewItem]);
    }

    TabPosition TabView::tab_position() const
    {
        return static_cast<TabPosition>([cocoon::internal::ns<::NSTabView>(this) tabPosition]);
    }

    void TabView::set_tab_position(TabPosition value) const
    {
        [cocoon::internal::ns<::NSTabView>(this) setTabPosition:static_cast<::NSTabPosition>(value)];
    }

    TabViewBorderType TabView::tab_view_border_type() const
    {
        return static_cast<TabViewBorderType>([cocoon::internal::ns<::NSTabView>(this) tabViewBorderType]);
    }

    void TabView::set_tab_view_border_type(TabViewBorderType value) const
    {
        [cocoon::internal::ns<::NSTabView>(this) setTabViewBorderType:static_cast<::NSTabViewBorderType>(value)];
    }

    std::vector<TabViewItem> TabView::tab_view_items() const
    {
        return cocoon::internal::from_array<TabViewItem>([cocoon::internal::ns<::NSTabView>(this) tabViewItems], [](id e) -> TabViewItem
                                                         {
                                                             return cocoon::internal::wrap<TabViewItem>((::NSTabViewItem*)e);
                                                         });
    }

    void TabView::set_tab_view_items(const std::vector<TabViewItem>& value) const
    {
        [cocoon::internal::ns<::NSTabView>(this) setTabViewItems:cocoon::internal::to_array(value, [](const TabViewItem& e) -> id
                                                                                            {
                                                                                                return cocoon::internal::native<::NSTabViewItem>(e);
                                                                                            })];
    }

    TabViewType TabView::tab_view_type() const
    {
        return static_cast<TabViewType>([cocoon::internal::ns<::NSTabView>(this) tabViewType]);
    }

    void TabView::set_tab_view_type(TabViewType value) const
    {
        [cocoon::internal::ns<::NSTabView>(this) setTabViewType:static_cast<::NSTabViewType>(value)];
    }

    int TabView::add_tab(const std::string& label, const View& content) const
    {
        NSTabView* tab = cocoon::internal::ns<NSTabView>(this);
        NSTabViewItem* item = [[NSTabViewItem alloc] initWithIdentifier:cocoon::internal::to(label)];
        item.label = cocoon::internal::to(label);
        item.view = cocoon::internal::native<NSView>(content);
        [tab addTabViewItem:item];
        return static_cast<int>(tab.numberOfTabViewItems) - 1;
    }

    int TabView::current_index() const
    {
        NSTabView* tab = cocoon::internal::ns<NSTabView>(this);
        return static_cast<int>([tab indexOfTabViewItem:tab.selectedTabViewItem]);
    }

    void TabView::set_current_index(int index) const
    {
        [cocoon::internal::ns<NSTabView>(this) selectTabViewItemAtIndex:index];
    }

    void TabView::install_delegate_delegate_(void* native)
    {
        ::NSTabView* host = (__bridge ::NSTabView*)native;
        AKTabViewDelegate* delegate = [[AKTabViewDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSTabView* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSTabView* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
