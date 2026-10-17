#include "generated/touch_bar.h"
#include "internal.h"

@interface AKTouchBarDelegate : NSObject <NSTouchBarDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKTouchBarDelegate

- (NSTouchBarItem*)touchBar:(NSTouchBar*)touchBar makeItemForIdentifier:(NSTouchBarItemIdentifier)identifier
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TouchBar, cocoon::TouchBarItem(std::string)>::emit((__bridge void*)strongHost, "make_item_for_identifier", cocoon::internal::from(identifier));
    return cocoon::internal::native<::NSTouchBarItem>(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(touchBar:makeItemForIdentifier:))
    {
        return strongHost && cocoon::Signal<cocoon::TouchBar, cocoon::TouchBarItem(std::string)>::connected((__bridge void*)strongHost, "make_item_for_identifier");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    TouchBar::TouchBar() : TouchBar(Adopt{cocoon::internal::retain([[::NSTouchBar alloc] init])})
    {
        TouchBar::install_delegate_delegate_(handle());
    }

    TouchBar::TouchBar(std::nullptr_t) : Object(nullptr)
    {
    }

    TouchBar::TouchBar(Adopt adopt) : Object(adopt)
    {
    }

    TouchBarItem TouchBar::item_for_identifier(const std::string& identifier) const
    {
        return cocoon::internal::wrap<TouchBarItem>([cocoon::internal::ns<::NSTouchBar>(this) itemForIdentifier:cocoon::internal::to(identifier)]);
    }

    bool TouchBar::is_automatic_customize_touch_bar_menu_item_enabled()
    {
        return static_cast<bool>([::NSTouchBar isAutomaticCustomizeTouchBarMenuItemEnabled]);
    }

    void TouchBar::set_automatic_customize_touch_bar_menu_item_enabled(bool value)
    {
        [::NSTouchBar setAutomaticCustomizeTouchBarMenuItemEnabled:static_cast<::BOOL>(value)];
    }

    std::vector<std::string> TouchBar::customization_allowed_item_identifiers() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTouchBar>(this) customizationAllowedItemIdentifiers], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    void TouchBar::set_customization_allowed_item_identifiers(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSTouchBar>(this) setCustomizationAllowedItemIdentifiers:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                        {
                                                                                            return cocoon::internal::to(e);
                                                                                        })];
    }

    std::string TouchBar::customization_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTouchBar>(this) customizationIdentifier]);
    }

    void TouchBar::set_customization_identifier(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTouchBar>(this) setCustomizationIdentifier:cocoon::internal::to(value)];
    }

    std::vector<std::string> TouchBar::customization_required_item_identifiers() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTouchBar>(this) customizationRequiredItemIdentifiers], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    void TouchBar::set_customization_required_item_identifiers(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSTouchBar>(this) setCustomizationRequiredItemIdentifiers:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                         {
                                                                                             return cocoon::internal::to(e);
                                                                                         })];
    }

    std::vector<std::string> TouchBar::default_item_identifiers() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTouchBar>(this) defaultItemIdentifiers], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    void TouchBar::set_default_item_identifiers(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSTouchBar>(this) setDefaultItemIdentifiers:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                           {
                                                                               return cocoon::internal::to(e);
                                                                           })];
    }

    std::string TouchBar::escape_key_replacement_item_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTouchBar>(this) escapeKeyReplacementItemIdentifier]);
    }

    void TouchBar::set_escape_key_replacement_item_identifier(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTouchBar>(this) setEscapeKeyReplacementItemIdentifier:cocoon::internal::to(value)];
    }

    std::vector<std::string> TouchBar::item_identifiers() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTouchBar>(this) itemIdentifiers], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::string TouchBar::principal_item_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTouchBar>(this) principalItemIdentifier]);
    }

    void TouchBar::set_principal_item_identifier(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTouchBar>(this) setPrincipalItemIdentifier:cocoon::internal::to(value)];
    }

    std::vector<TouchBarItem> TouchBar::template_items() const
    {
        return cocoon::internal::from_array<TouchBarItem>([[cocoon::internal::ns<::NSTouchBar>(this) templateItems] allObjects], [](id e) -> TouchBarItem
                                            {
                                                return cocoon::internal::wrap<TouchBarItem>((::NSTouchBarItem*)e);
                                            });
    }

    void TouchBar::set_template_items(const std::vector<TouchBarItem>& value) const
    {
        [cocoon::internal::ns<::NSTouchBar>(this) setTemplateItems:[NSSet setWithArray:cocoon::internal::to_array(value, [](const TouchBarItem& e) -> id
                                                                                      {
                                                                                          return cocoon::internal::native<::NSTouchBarItem>(e);
                                                                                      })]];
    }

    bool TouchBar::is_visible() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTouchBar>(this) isVisible]);
    }

    void TouchBar::install_delegate_delegate_(void* native)
    {
        ::NSTouchBar* host = (__bridge ::NSTouchBar*)native;
        AKTouchBarDelegate* delegate = [[AKTouchBarDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSTouchBar* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSTouchBar* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
