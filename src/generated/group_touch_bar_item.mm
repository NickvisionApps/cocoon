#include "generated/group_touch_bar_item.h"
#include "internal.h"

namespace cocoon
{
    GroupTouchBarItem::GroupTouchBarItem() : TouchBarItem(nullptr)
    {
    }

    GroupTouchBarItem::GroupTouchBarItem(std::nullptr_t) : TouchBarItem(nullptr)
    {
    }

    GroupTouchBarItem::GroupTouchBarItem(Adopt adopt) : TouchBarItem(adopt)
    {
    }

    GroupTouchBarItem GroupTouchBarItem::alert_style_group_item_with_identifier(const std::string& identifier)
    {
        return cocoon::internal::wrap<GroupTouchBarItem>([::NSGroupTouchBarItem alertStyleGroupItemWithIdentifier:cocoon::internal::to(identifier)]);
    }

    GroupTouchBarItem GroupTouchBarItem::group_item_with_identifier(const std::string& identifier, const std::vector<TouchBarItem>& items)
    {
        return cocoon::internal::wrap<GroupTouchBarItem>([::NSGroupTouchBarItem groupItemWithIdentifier:cocoon::internal::to(identifier)
                                                                                                  items:cocoon::internal::to_array(items, [](const TouchBarItem& e) -> id
                                                                                                                                   {
                                                                                                                                       return cocoon::internal::native<::NSTouchBarItem>(e);
                                                                                                                                   })]);
    }

    GroupTouchBarItem GroupTouchBarItem::group_item_with_identifier(const std::string& identifier, const std::vector<TouchBarItem>& items, const UserInterfaceCompressionOptions& allowed_compression_options)
    {
        return cocoon::internal::wrap<GroupTouchBarItem>([::NSGroupTouchBarItem groupItemWithIdentifier:cocoon::internal::to(identifier)
                                                                                                  items:cocoon::internal::to_array(items, [](const TouchBarItem& e) -> id
                                                                                                                                   {
                                                                                                                                       return cocoon::internal::native<::NSTouchBarItem>(e);
                                                                                                                                   })
                                                                              allowedCompressionOptions:cocoon::internal::native<::NSUserInterfaceCompressionOptions>(allowed_compression_options)]);
    }

    std::string GroupTouchBarItem::customization_label() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSGroupTouchBarItem>(this) customizationLabel]);
    }

    void GroupTouchBarItem::set_customization_label(const std::string& value) const
    {
        [cocoon::internal::ns<::NSGroupTouchBarItem>(this) setCustomizationLabel:cocoon::internal::to(value)];
    }

    UserInterfaceCompressionOptions GroupTouchBarItem::effective_compression_options() const
    {
        return cocoon::internal::wrap<UserInterfaceCompressionOptions>([cocoon::internal::ns<::NSGroupTouchBarItem>(this) effectiveCompressionOptions]);
    }

    TouchBar GroupTouchBarItem::group_touch_bar() const
    {
        return cocoon::internal::wrap<TouchBar>([cocoon::internal::ns<::NSGroupTouchBarItem>(this) groupTouchBar]);
    }

    void GroupTouchBarItem::set_group_touch_bar(const TouchBar& value) const
    {
        [cocoon::internal::ns<::NSGroupTouchBarItem>(this) setGroupTouchBar:cocoon::internal::native<::NSTouchBar>(value)];
    }

    UserInterfaceLayoutDirection GroupTouchBarItem::group_user_interface_layout_direction() const
    {
        return static_cast<UserInterfaceLayoutDirection>([cocoon::internal::ns<::NSGroupTouchBarItem>(this) groupUserInterfaceLayoutDirection]);
    }

    void GroupTouchBarItem::set_group_user_interface_layout_direction(UserInterfaceLayoutDirection value) const
    {
        [cocoon::internal::ns<::NSGroupTouchBarItem>(this) setGroupUserInterfaceLayoutDirection:static_cast<::NSUserInterfaceLayoutDirection>(value)];
    }

    double GroupTouchBarItem::preferred_item_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSGroupTouchBarItem>(this) preferredItemWidth]);
    }

    void GroupTouchBarItem::set_preferred_item_width(double value) const
    {
        [cocoon::internal::ns<::NSGroupTouchBarItem>(this) setPreferredItemWidth:static_cast<::CGFloat>(value)];
    }

    bool GroupTouchBarItem::prefers_equal_widths() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSGroupTouchBarItem>(this) prefersEqualWidths]);
    }

    void GroupTouchBarItem::set_prefers_equal_widths(bool value) const
    {
        [cocoon::internal::ns<::NSGroupTouchBarItem>(this) setPrefersEqualWidths:static_cast<::BOOL>(value)];
    }

    std::vector<UserInterfaceCompressionOptions> GroupTouchBarItem::prioritized_compression_options() const
    {
        return cocoon::internal::from_array<UserInterfaceCompressionOptions>([cocoon::internal::ns<::NSGroupTouchBarItem>(this) prioritizedCompressionOptions], [](id e) -> UserInterfaceCompressionOptions
                                                                             {
                                                                                 return cocoon::internal::wrap<UserInterfaceCompressionOptions>((::NSUserInterfaceCompressionOptions*)e);
                                                                             });
    }

    void GroupTouchBarItem::set_prioritized_compression_options(const std::vector<UserInterfaceCompressionOptions>& value) const
    {
        [cocoon::internal::ns<::NSGroupTouchBarItem>(this) setPrioritizedCompressionOptions:cocoon::internal::to_array(value, [](const UserInterfaceCompressionOptions& e) -> id
                                                                                                                       {
                                                                                                                           return cocoon::internal::native<::NSUserInterfaceCompressionOptions>(e);
                                                                                                                       })];
    }
}
