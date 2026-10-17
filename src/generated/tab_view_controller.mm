#include "generated/tab_view_controller.h"
#include "internal.h"

namespace cocoon
{
    TabViewController::TabViewController() : TabViewController(Adopt{cocoon::internal::retain([[::NSTabViewController alloc] init])})
    {
    }

    TabViewController::TabViewController(std::nullptr_t) : ViewController(nullptr)
    {
    }

    TabViewController::TabViewController(Adopt adopt) : ViewController(adopt)
    {
    }

    void TabViewController::add_tab_view_item(const TabViewItem& tab_view_item) const
    {
        [cocoon::internal::ns<::NSTabViewController>(this) addTabViewItem:cocoon::internal::native<::NSTabViewItem>(tab_view_item)];
    }

    void TabViewController::insert_tab_view_item(const TabViewItem& tab_view_item, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSTabViewController>(this) insertTabViewItem:cocoon::internal::native<::NSTabViewItem>(tab_view_item) atIndex:static_cast<::NSInteger>(index)];
    }

    void TabViewController::remove_tab_view_item(const TabViewItem& tab_view_item) const
    {
        [cocoon::internal::ns<::NSTabViewController>(this) removeTabViewItem:cocoon::internal::native<::NSTabViewItem>(tab_view_item)];
    }

    void TabViewController::tab_view(const TabView& tab_view, const TabViewItem& tab_view_item) const
    {
        [cocoon::internal::ns<::NSTabViewController>(this) tabView:cocoon::internal::native<::NSTabView>(tab_view) didSelectTabViewItem:cocoon::internal::native<::NSTabViewItem>(tab_view_item)];
    }

    TabViewItem TabViewController::tab_view_item_for_view_controller(const ViewController& view_controller) const
    {
        return cocoon::internal::wrap<TabViewItem>([cocoon::internal::ns<::NSTabViewController>(this) tabViewItemForViewController:cocoon::internal::native<::NSViewController>(view_controller)]);
    }

    ToolbarItem TabViewController::toolbar(const Toolbar& toolbar, const std::string& item_identifier, bool flag) const
    {
        return cocoon::internal::wrap<ToolbarItem>([cocoon::internal::ns<::NSTabViewController>(this) toolbar:cocoon::internal::native<::NSToolbar>(toolbar) itemForItemIdentifier:cocoon::internal::to(item_identifier) willBeInsertedIntoToolbar:static_cast<::BOOL>(flag)]);
    }

    std::vector<std::string> TabViewController::toolbar_allowed_item_identifiers(const Toolbar& toolbar) const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTabViewController>(this) toolbarAllowedItemIdentifiers:cocoon::internal::native<::NSToolbar>(toolbar)], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::vector<std::string> TabViewController::toolbar_default_item_identifiers(const Toolbar& toolbar) const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTabViewController>(this) toolbarDefaultItemIdentifiers:cocoon::internal::native<::NSToolbar>(toolbar)], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::vector<std::string> TabViewController::toolbar_selectable_item_identifiers(const Toolbar& toolbar) const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTabViewController>(this) toolbarSelectableItemIdentifiers:cocoon::internal::native<::NSToolbar>(toolbar)], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void TabViewController::view_did_load() const
    {
        [cocoon::internal::ns<::NSTabViewController>(this) viewDidLoad];
    }

    bool TabViewController::can_propagate_selected_child_view_controller_title() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTabViewController>(this) canPropagateSelectedChildViewControllerTitle]);
    }

    void TabViewController::set_can_propagate_selected_child_view_controller_title(bool value) const
    {
        [cocoon::internal::ns<::NSTabViewController>(this) setCanPropagateSelectedChildViewControllerTitle:static_cast<::BOOL>(value)];
    }

    std::int64_t TabViewController::selected_tab_view_item_index() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTabViewController>(this) selectedTabViewItemIndex]);
    }

    void TabViewController::set_selected_tab_view_item_index(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSTabViewController>(this) setSelectedTabViewItemIndex:static_cast<::NSInteger>(value)];
    }

    TabViewControllerTabStyle TabViewController::tab_style() const
    {
        return static_cast<TabViewControllerTabStyle>([cocoon::internal::ns<::NSTabViewController>(this) tabStyle]);
    }

    void TabViewController::set_tab_style(TabViewControllerTabStyle value) const
    {
        [cocoon::internal::ns<::NSTabViewController>(this) setTabStyle:static_cast<::NSTabViewControllerTabStyle>(value)];
    }

    TabView TabViewController::tab_view() const
    {
        return cocoon::internal::wrap<TabView>([cocoon::internal::ns<::NSTabViewController>(this) tabView]);
    }

    void TabViewController::set_tab_view(const TabView& value) const
    {
        [cocoon::internal::ns<::NSTabViewController>(this) setTabView:cocoon::internal::native<::NSTabView>(value)];
    }

    std::vector<TabViewItem> TabViewController::tab_view_items() const
    {
        return cocoon::internal::from_array<TabViewItem>([cocoon::internal::ns<::NSTabViewController>(this) tabViewItems], [](id e) -> TabViewItem
                                                         {
                                                             return cocoon::internal::wrap<TabViewItem>((::NSTabViewItem*)e);
                                                         });
    }

    void TabViewController::set_tab_view_items(const std::vector<TabViewItem>& value) const
    {
        [cocoon::internal::ns<::NSTabViewController>(this) setTabViewItems:cocoon::internal::to_array(value, [](const TabViewItem& e) -> id
                                                                                                      {
                                                                                                          return cocoon::internal::native<::NSTabViewItem>(e);
                                                                                                      })];
    }

    ViewControllerTransitionOptions TabViewController::transition_options() const
    {
        return static_cast<ViewControllerTransitionOptions>([cocoon::internal::ns<::NSTabViewController>(this) transitionOptions]);
    }

    void TabViewController::set_transition_options(ViewControllerTransitionOptions value) const
    {
        [cocoon::internal::ns<::NSTabViewController>(this) setTransitionOptions:static_cast<::NSViewControllerTransitionOptions>(value)];
    }
}
