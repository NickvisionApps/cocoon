#include "generated/toolbar.h"
#include "internal.h"

@interface AKToolbarDelegate : NSObject <NSToolbarDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKToolbarDelegate

- (NSToolbarItem*)toolbar:(NSToolbar*)toolbar itemForItemIdentifier:(NSToolbarItemIdentifier)itemIdentifier willBeInsertedIntoToolbar:(BOOL)flag
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Toolbar, cocoon::ToolbarItem(std::string, bool)>::emit((__bridge void*)strongHost, "item_for_identifier", cocoon::internal::from(itemIdentifier), static_cast<bool>(flag));
    return cocoon::internal::native<::NSToolbarItem>(__r);
}

- (NSArray<NSToolbarItemIdentifier>*)toolbarDefaultItemIdentifiers:(NSToolbar*)toolbar
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Toolbar, std::vector<std::string>()>::emit((__bridge void*)strongHost, "default_item_identifiers");
    return cocoon::internal::to_array(__r, [](const std::string& e) -> id
                        {
                            return cocoon::internal::to(e);
                        });
}

- (NSArray<NSToolbarItemIdentifier>*)toolbarAllowedItemIdentifiers:(NSToolbar*)toolbar
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Toolbar, std::vector<std::string>()>::emit((__bridge void*)strongHost, "allowed_item_identifiers");
    return cocoon::internal::to_array(__r, [](const std::string& e) -> id
                        {
                            return cocoon::internal::to(e);
                        });
}

- (NSArray<NSToolbarItemIdentifier>*)toolbarSelectableItemIdentifiers:(NSToolbar*)toolbar
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Toolbar, std::vector<std::string>()>::emit((__bridge void*)strongHost, "selectable_item_identifiers");
    return cocoon::internal::to_array(__r, [](const std::string& e) -> id
                        {
                            return cocoon::internal::to(e);
                        });
}

- (NSSet<NSToolbarItemIdentifier>*)toolbarImmovableItemIdentifiers:(NSToolbar*)toolbar
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Toolbar, std::vector<std::string>()>::emit((__bridge void*)strongHost, "immovable_item_identifiers");
    return [NSSet setWithArray:cocoon::internal::to_array(__r, [](const std::string& e) -> id
                                            {
                                                return cocoon::internal::to(e);
                                            })];
}

- (BOOL)toolbar:(NSToolbar*)toolbar itemIdentifier:(NSToolbarItemIdentifier)itemIdentifier canBeInsertedAtIndex:(NSInteger)index
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Toolbar, bool(std::string, std::int64_t)>::emit((__bridge void*)strongHost, "item_identifier_can_be_inserted_at_index", cocoon::internal::from(itemIdentifier), static_cast<std::int64_t>(index));
    return static_cast<::BOOL>(__r);
}

- (void)toolbarWillAddItem:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Toolbar, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "will_add_item", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (void)toolbarDidRemoveItem:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Toolbar, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "did_remove_item", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(toolbar:itemForItemIdentifier:willBeInsertedIntoToolbar:))
    {
        return strongHost && cocoon::Signal<cocoon::Toolbar, cocoon::ToolbarItem(std::string, bool)>::connected((__bridge void*)strongHost, "item_for_identifier");
    }
    if (selector == @selector(toolbarDefaultItemIdentifiers:))
    {
        return strongHost && cocoon::Signal<cocoon::Toolbar, std::vector<std::string>()>::connected((__bridge void*)strongHost, "default_item_identifiers");
    }
    if (selector == @selector(toolbarAllowedItemIdentifiers:))
    {
        return strongHost && cocoon::Signal<cocoon::Toolbar, std::vector<std::string>()>::connected((__bridge void*)strongHost, "allowed_item_identifiers");
    }
    if (selector == @selector(toolbarSelectableItemIdentifiers:))
    {
        return strongHost && cocoon::Signal<cocoon::Toolbar, std::vector<std::string>()>::connected((__bridge void*)strongHost, "selectable_item_identifiers");
    }
    if (selector == @selector(toolbarImmovableItemIdentifiers:))
    {
        return strongHost && cocoon::Signal<cocoon::Toolbar, std::vector<std::string>()>::connected((__bridge void*)strongHost, "immovable_item_identifiers");
    }
    if (selector == @selector(toolbar:itemIdentifier:canBeInsertedAtIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::Toolbar, bool(std::string, std::int64_t)>::connected((__bridge void*)strongHost, "item_identifier_can_be_inserted_at_index");
    }
    if (selector == @selector(toolbarWillAddItem:))
    {
        return strongHost && cocoon::Signal<cocoon::Toolbar, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "will_add_item");
    }
    if (selector == @selector(toolbarDidRemoveItem:))
    {
        return strongHost && cocoon::Signal<cocoon::Toolbar, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "did_remove_item");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    Toolbar::Toolbar(const std::string& identifier) : Toolbar(Adopt{cocoon::internal::retain(cocoon::internal::make_toolbar(identifier))})
    {
        Toolbar::install_delegate_delegate_(handle());
        cocoon::internal::install_toolbar_provider(handle());
    }

    Toolbar::Toolbar() : Toolbar(Adopt{cocoon::internal::retain([[::NSToolbar alloc] init])})
    {
        Toolbar::install_delegate_delegate_(handle());
        cocoon::internal::install_toolbar_provider(handle());
    }

    Toolbar::Toolbar(std::nullptr_t) : Object(nullptr)
    {
    }

    Toolbar::Toolbar(Adopt adopt) : Object(adopt)
    {
    }

    void Toolbar::insert_item_with_item_identifier(const std::string& item_identifier, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSToolbar>(this) insertItemWithItemIdentifier:cocoon::internal::to(item_identifier) atIndex:static_cast<::NSInteger>(index)];
    }

    void Toolbar::remove_item_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSToolbar>(this) removeItemAtIndex:static_cast<::NSInteger>(index)];
    }

    void Toolbar::remove_item_with_item_identifier(const std::string& item_identifier) const
    {
        [cocoon::internal::ns<::NSToolbar>(this) removeItemWithItemIdentifier:cocoon::internal::to(item_identifier)];
    }

    void Toolbar::run_customization_palette(const Object& sender) const
    {
        [cocoon::internal::ns<::NSToolbar>(this) runCustomizationPalette:cocoon::internal::native_id(sender)];
    }

    void Toolbar::validate_visible_items() const
    {
        [cocoon::internal::ns<::NSToolbar>(this) validateVisibleItems];
    }

    bool Toolbar::allows_display_mode_customization() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSToolbar>(this) allowsDisplayModeCustomization]);
    }

    void Toolbar::set_allows_display_mode_customization(bool value) const
    {
        [cocoon::internal::ns<::NSToolbar>(this) setAllowsDisplayModeCustomization:static_cast<::BOOL>(value)];
    }

    bool Toolbar::allows_extension_items() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSToolbar>(this) allowsExtensionItems]);
    }

    void Toolbar::set_allows_extension_items(bool value) const
    {
        [cocoon::internal::ns<::NSToolbar>(this) setAllowsExtensionItems:static_cast<::BOOL>(value)];
    }

    bool Toolbar::allows_user_customization() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSToolbar>(this) allowsUserCustomization]);
    }

    void Toolbar::set_allows_user_customization(bool value) const
    {
        [cocoon::internal::ns<::NSToolbar>(this) setAllowsUserCustomization:static_cast<::BOOL>(value)];
    }

    bool Toolbar::autosaves_configuration() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSToolbar>(this) autosavesConfiguration]);
    }

    void Toolbar::set_autosaves_configuration(bool value) const
    {
        [cocoon::internal::ns<::NSToolbar>(this) setAutosavesConfiguration:static_cast<::BOOL>(value)];
    }

    std::string Toolbar::centered_item_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSToolbar>(this) centeredItemIdentifier]);
    }

    void Toolbar::set_centered_item_identifier(const std::string& value) const
    {
        [cocoon::internal::ns<::NSToolbar>(this) setCenteredItemIdentifier:cocoon::internal::to(value)];
    }

    std::vector<std::string> Toolbar::centered_item_identifiers() const
    {
        return cocoon::internal::from_array<std::string>([[cocoon::internal::ns<::NSToolbar>(this) centeredItemIdentifiers] allObjects], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    void Toolbar::set_centered_item_identifiers(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSToolbar>(this) setCenteredItemIdentifiers:[NSSet setWithArray:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                               {
                                                                                                   return cocoon::internal::to(e);
                                                                                               })]];
    }

    bool Toolbar::customization_palette_is_running() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSToolbar>(this) customizationPaletteIsRunning]);
    }

    ToolbarDisplayMode Toolbar::display_mode() const
    {
        return static_cast<ToolbarDisplayMode>([cocoon::internal::ns<::NSToolbar>(this) displayMode]);
    }

    void Toolbar::set_display_mode(ToolbarDisplayMode value) const
    {
        [cocoon::internal::ns<::NSToolbar>(this) setDisplayMode:static_cast<::NSToolbarDisplayMode>(value)];
    }

    std::string Toolbar::identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSToolbar>(this) identifier]);
    }

    std::vector<std::string> Toolbar::item_identifiers() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSToolbar>(this) itemIdentifiers], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    void Toolbar::set_item_identifiers(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSToolbar>(this) setItemIdentifiers:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                   {
                                                                       return cocoon::internal::to(e);
                                                                   })];
    }

    std::vector<ToolbarItem> Toolbar::items() const
    {
        return cocoon::internal::from_array<ToolbarItem>([cocoon::internal::ns<::NSToolbar>(this) items], [](id e) -> ToolbarItem
                                           {
                                               return cocoon::internal::wrap<ToolbarItem>((::NSToolbarItem*)e);
                                           });
    }

    std::string Toolbar::selected_item_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSToolbar>(this) selectedItemIdentifier]);
    }

    void Toolbar::set_selected_item_identifier(const std::string& value) const
    {
        [cocoon::internal::ns<::NSToolbar>(this) setSelectedItemIdentifier:cocoon::internal::to(value)];
    }

    ToolbarSizeMode Toolbar::size_mode() const
    {
        return static_cast<ToolbarSizeMode>([cocoon::internal::ns<::NSToolbar>(this) sizeMode]);
    }

    void Toolbar::set_size_mode(ToolbarSizeMode value) const
    {
        [cocoon::internal::ns<::NSToolbar>(this) setSizeMode:static_cast<::NSToolbarSizeMode>(value)];
    }

    bool Toolbar::is_visible() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSToolbar>(this) isVisible]);
    }

    void Toolbar::set_visible(bool value) const
    {
        [cocoon::internal::ns<::NSToolbar>(this) setVisible:static_cast<::BOOL>(value)];
    }

    std::vector<ToolbarItem> Toolbar::visible_items() const
    {
        return cocoon::internal::from_array<ToolbarItem>([cocoon::internal::ns<::NSToolbar>(this) visibleItems], [](id e) -> ToolbarItem
                                           {
                                               return cocoon::internal::wrap<ToolbarItem>((::NSToolbarItem*)e);
                                           });
    }

    void Toolbar::add_item(const ToolbarItem& item) const
    {
        cocoon::internal::toolbar_add(cocoon::internal::ns<NSToolbar>(this), cocoon::internal::to(item.item_identifier()), cocoon::internal::native<NSToolbarItem>(item), true, false);
    }

    void Toolbar::add_required_item(const ToolbarItem& item) const
    {
        cocoon::internal::toolbar_add(cocoon::internal::ns<NSToolbar>(this), cocoon::internal::to(item.item_identifier()), cocoon::internal::native<NSToolbarItem>(item), true, true);
    }

    void Toolbar::add_allowed_item(const ToolbarItem& item) const
    {
        cocoon::internal::toolbar_add(cocoon::internal::ns<NSToolbar>(this), cocoon::internal::to(item.item_identifier()), cocoon::internal::native<NSToolbarItem>(item), false, false);
    }

    ToolbarItem Toolbar::add_button(const std::string& identifier, const std::string& label, const std::string& symbol, std::function<void()> on_clicked) const
    {
        ToolbarItem item(identifier, label, symbol);
        if (on_clicked)
        {
            item.clicked().connect(std::move(on_clicked));
        }
        add_item(item);
        return item;
    }

    SearchToolbarItem Toolbar::add_search_field(const std::string& identifier, std::function<void(const std::string&)> on_searched) const
    {
        SearchToolbarItem item(identifier);
        if (on_searched)
        {
            item.searched().connect(std::move(on_searched));
        }
        add_item(item);
        return item;
    }

    void Toolbar::add_flexible_space() const
    {
        cocoon::internal::toolbar_add(cocoon::internal::ns<NSToolbar>(this), NSToolbarFlexibleSpaceItemIdentifier, nil, true, false);
    }

    void Toolbar::add_space() const
    {
        cocoon::internal::toolbar_add(cocoon::internal::ns<NSToolbar>(this), NSToolbarSpaceItemIdentifier, nil, true, false);
    }

    void Toolbar::add_sidebar_toggle() const
    {
        cocoon::internal::toolbar_add(cocoon::internal::ns<NSToolbar>(this), NSToolbarToggleSidebarItemIdentifier, nil, true, true);
    }

    void Toolbar::add_sidebar_tracking_separator() const
    {
        cocoon::internal::toolbar_add(cocoon::internal::ns<NSToolbar>(this), NSToolbarSidebarTrackingSeparatorItemIdentifier, nil, true, true);
    }

    void Toolbar::install_delegate_delegate_(void* native)
    {
        ::NSToolbar* host = (__bridge ::NSToolbar*)native;
        AKToolbarDelegate* delegate = [[AKToolbarDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSToolbar* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSToolbar* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
