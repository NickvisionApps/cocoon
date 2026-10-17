#include "generated/toolbar_item_group.h"
#include "internal.h"

namespace cocoon
{
    ToolbarItemGroup::ToolbarItemGroup() : ToolbarItemGroup(Adopt{cocoon::internal::retain([[::NSToolbarItemGroup alloc] init])})
    {
        ToolbarItem::bind_action_(handle());
    }

    ToolbarItemGroup::ToolbarItemGroup(std::nullptr_t) : ToolbarItem(nullptr)
    {
    }

    ToolbarItemGroup::ToolbarItemGroup(Adopt adopt) : ToolbarItem(adopt)
    {
    }

    ToolbarItemGroup ToolbarItemGroup::group_with_item_identifier(const std::string& item_identifier, const std::vector<Image>& images, ToolbarItemGroupSelectionMode selection_mode, const std::vector<std::string>& labels, const Object& target, const std::string& action)
    {
        return cocoon::internal::wrap<ToolbarItemGroup>([::NSToolbarItemGroup groupWithItemIdentifier:cocoon::internal::to(item_identifier)
                                                                                               images:cocoon::internal::to_array(images, [](const Image& e) -> id
                                                                                                                                 {
                                                                                                                                     return cocoon::internal::native<::NSImage>(e);
                                                                                                                                 })
                                                                                        selectionMode:static_cast<::NSToolbarItemGroupSelectionMode>(selection_mode)
                                                                                               labels:cocoon::internal::to_array(labels, [](const std::string& e) -> id
                                                                                                                                 {
                                                                                                                                     return cocoon::internal::to(e);
                                                                                                                                 })
                                                                                               target:cocoon::internal::native_id(target)
                                                                                               action:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    ToolbarItemGroup ToolbarItemGroup::group_with_item_identifier(const std::string& item_identifier, const std::vector<std::string>& titles, ToolbarItemGroupSelectionMode selection_mode, const std::vector<std::string>& labels, const Object& target, const std::string& action)
    {
        return cocoon::internal::wrap<ToolbarItemGroup>([::NSToolbarItemGroup groupWithItemIdentifier:cocoon::internal::to(item_identifier)
                                                                                               titles:cocoon::internal::to_array(titles, [](const std::string& e) -> id
                                                                                                                                 {
                                                                                                                                     return cocoon::internal::to(e);
                                                                                                                                 })
                                                                                        selectionMode:static_cast<::NSToolbarItemGroupSelectionMode>(selection_mode)
                                                                                               labels:cocoon::internal::to_array(labels, [](const std::string& e) -> id
                                                                                                                                 {
                                                                                                                                     return cocoon::internal::to(e);
                                                                                                                                 })
                                                                                               target:cocoon::internal::native_id(target)
                                                                                               action:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    bool ToolbarItemGroup::is_selected_at_index(std::int64_t index) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSToolbarItemGroup>(this) isSelectedAtIndex:static_cast<::NSInteger>(index)]);
    }

    void ToolbarItemGroup::set_selected(bool selected, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSToolbarItemGroup>(this) setSelected:static_cast<::BOOL>(selected) atIndex:static_cast<::NSInteger>(index)];
    }

    ToolbarItemGroupControlRepresentation ToolbarItemGroup::control_representation() const
    {
        return static_cast<ToolbarItemGroupControlRepresentation>([cocoon::internal::ns<::NSToolbarItemGroup>(this) controlRepresentation]);
    }

    void ToolbarItemGroup::set_control_representation(ToolbarItemGroupControlRepresentation value) const
    {
        [cocoon::internal::ns<::NSToolbarItemGroup>(this) setControlRepresentation:static_cast<::NSToolbarItemGroupControlRepresentation>(value)];
    }

#ifdef COCOON_MACOS_27
    ToolbarItemGroupRole ToolbarItemGroup::role() const
    {
        if (@available(macOS 27.0, *))
        {
            return static_cast<ToolbarItemGroupRole>([cocoon::internal::ns<::NSToolbarItemGroup>(this) role]);
        }
        return {};
    }

#endif

#ifdef COCOON_MACOS_27
    void ToolbarItemGroup::set_role(ToolbarItemGroupRole value) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSToolbarItemGroup>(this) setRole:static_cast<::NSToolbarItemGroupRole>(value)];
        }
    }

#endif

    std::int64_t ToolbarItemGroup::selected_index() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSToolbarItemGroup>(this) selectedIndex]);
    }

    void ToolbarItemGroup::set_selected_index(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSToolbarItemGroup>(this) setSelectedIndex:static_cast<::NSInteger>(value)];
    }

    ToolbarItemGroupSelectionMode ToolbarItemGroup::selection_mode() const
    {
        return static_cast<ToolbarItemGroupSelectionMode>([cocoon::internal::ns<::NSToolbarItemGroup>(this) selectionMode]);
    }

    void ToolbarItemGroup::set_selection_mode(ToolbarItemGroupSelectionMode value) const
    {
        [cocoon::internal::ns<::NSToolbarItemGroup>(this) setSelectionMode:static_cast<::NSToolbarItemGroupSelectionMode>(value)];
    }

    std::vector<ToolbarItem> ToolbarItemGroup::subitems() const
    {
        return cocoon::internal::from_array<ToolbarItem>([cocoon::internal::ns<::NSToolbarItemGroup>(this) subitems], [](id e) -> ToolbarItem
                                                         {
                                                             return cocoon::internal::wrap<ToolbarItem>((::NSToolbarItem*)e);
                                                         });
    }

    void ToolbarItemGroup::set_subitems(const std::vector<ToolbarItem>& value) const
    {
        [cocoon::internal::ns<::NSToolbarItemGroup>(this) setSubitems:cocoon::internal::to_array(value, [](const ToolbarItem& e) -> id
                                                                                                 {
                                                                                                     return cocoon::internal::native<::NSToolbarItem>(e);
                                                                                                 })];
    }
}
