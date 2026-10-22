#include "generated/pop_up_button.h"
#include "internal.h"

namespace cocoon
{
    PopUpButton::PopUpButton() : PopUpButton(Adopt{cocoon::internal::retain([[NSPopUpButton alloc] initWithFrame:NSZeroRect pullsDown:NO])})
    {
        PopUpButton::bind_action_(handle());
    }

    PopUpButton::PopUpButton(const Rect& button_frame, bool flag) : PopUpButton(Adopt{cocoon::internal::retain([[::NSPopUpButton alloc] initWithFrame:cocoon::internal::to(button_frame) pullsDown:static_cast<::BOOL>(flag)])})
    {
        PopUpButton::bind_action_(handle());
    }

    PopUpButton::PopUpButton(const Menu& menu, const Object& target, const std::string& action) : PopUpButton(Adopt{cocoon::internal::retain([::NSPopUpButton popUpButtonWithMenu:cocoon::internal::native<::NSMenu>(menu) target:cocoon::internal::native_id(target) action:NSSelectorFromString(cocoon::internal::to(action))])})
    {
        PopUpButton::bind_action_(handle());
    }

    PopUpButton::PopUpButton(std::nullptr_t) : Button(nullptr)
    {
    }

    PopUpButton::PopUpButton(Adopt adopt) : Button(adopt)
    {
    }

    void PopUpButton::add_item_with_title(const std::string& title) const
    {
        [cocoon::internal::ns<::NSPopUpButton>(this) addItemWithTitle:cocoon::internal::to(title)];
    }

    void PopUpButton::add_items_with_titles(const std::vector<std::string>& item_titles) const
    {
        [cocoon::internal::ns<::NSPopUpButton>(this) addItemsWithTitles:cocoon::internal::to_array(item_titles, [](const std::string& e) -> id
                                                                                                   {
                                                                                                       return cocoon::internal::to(e);
                                                                                                   })];
    }

    std::int64_t PopUpButton::index_of_item(const MenuItem& item) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPopUpButton>(this) indexOfItem:cocoon::internal::native<::NSMenuItem>(item)]);
    }

    std::int64_t PopUpButton::index_of_item_with_represented_object(const Object& obj) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPopUpButton>(this) indexOfItemWithRepresentedObject:cocoon::internal::native_id(obj)]);
    }

    std::int64_t PopUpButton::index_of_item_with_tag(std::int64_t tag) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPopUpButton>(this) indexOfItemWithTag:static_cast<::NSInteger>(tag)]);
    }

    std::int64_t PopUpButton::index_of_item_with_target(const Object& target, const std::string& action_selector) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPopUpButton>(this) indexOfItemWithTarget:cocoon::internal::native_id(target) andAction:NSSelectorFromString(cocoon::internal::to(action_selector))]);
    }

    std::int64_t PopUpButton::index_of_item_with_title(const std::string& title) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPopUpButton>(this) indexOfItemWithTitle:cocoon::internal::to(title)]);
    }

    void PopUpButton::insert_item_with_title(const std::string& title, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSPopUpButton>(this) insertItemWithTitle:cocoon::internal::to(title) atIndex:static_cast<::NSInteger>(index)];
    }

    MenuItem PopUpButton::item_at_index(std::int64_t index) const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSPopUpButton>(this) itemAtIndex:static_cast<::NSInteger>(index)]);
    }

    std::string PopUpButton::item_title_at_index(std::int64_t index) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPopUpButton>(this) itemTitleAtIndex:static_cast<::NSInteger>(index)]);
    }

    MenuItem PopUpButton::item_with_title(const std::string& title) const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSPopUpButton>(this) itemWithTitle:cocoon::internal::to(title)]);
    }

    PopUpButton PopUpButton::pull_down_button_with_image(const Image& image, const Menu& menu)
    {
        return cocoon::internal::wrap<PopUpButton>([::NSPopUpButton pullDownButtonWithImage:cocoon::internal::native<::NSImage>(image) menu:cocoon::internal::native<::NSMenu>(menu)]);
    }

    PopUpButton PopUpButton::pull_down_button_with_title(const std::string& title, const Image& image, const Menu& menu)
    {
        return cocoon::internal::wrap<PopUpButton>([::NSPopUpButton pullDownButtonWithTitle:cocoon::internal::to(title) image:cocoon::internal::native<::NSImage>(image) menu:cocoon::internal::native<::NSMenu>(menu)]);
    }

    PopUpButton PopUpButton::pull_down_button_with_title(const std::string& title, const Menu& menu)
    {
        return cocoon::internal::wrap<PopUpButton>([::NSPopUpButton pullDownButtonWithTitle:cocoon::internal::to(title) menu:cocoon::internal::native<::NSMenu>(menu)]);
    }

    void PopUpButton::remove_all_items() const
    {
        [cocoon::internal::ns<::NSPopUpButton>(this) removeAllItems];
    }

    void PopUpButton::remove_item_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSPopUpButton>(this) removeItemAtIndex:static_cast<::NSInteger>(index)];
    }

    void PopUpButton::remove_item_with_title(const std::string& title) const
    {
        [cocoon::internal::ns<::NSPopUpButton>(this) removeItemWithTitle:cocoon::internal::to(title)];
    }

    void PopUpButton::select_item(const MenuItem& item) const
    {
        [cocoon::internal::ns<::NSPopUpButton>(this) selectItem:cocoon::internal::native<::NSMenuItem>(item)];
    }

    void PopUpButton::select_item_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSPopUpButton>(this) selectItemAtIndex:static_cast<::NSInteger>(index)];
    }

    bool PopUpButton::select_item_with_tag(std::int64_t tag) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPopUpButton>(this) selectItemWithTag:static_cast<::NSInteger>(tag)]);
    }

    void PopUpButton::select_item_with_title(const std::string& title) const
    {
        [cocoon::internal::ns<::NSPopUpButton>(this) selectItemWithTitle:cocoon::internal::to(title)];
    }

    void PopUpButton::set_title(const std::string& string) const
    {
        [cocoon::internal::ns<::NSPopUpButton>(this) setTitle:cocoon::internal::to(string)];
    }

    void PopUpButton::synchronize_title_and_selected_item() const
    {
        [cocoon::internal::ns<::NSPopUpButton>(this) synchronizeTitleAndSelectedItem];
    }

    bool PopUpButton::alters_state_of_selected_item() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPopUpButton>(this) altersStateOfSelectedItem]);
    }

    void PopUpButton::set_alters_state_of_selected_item(bool value) const
    {
        [cocoon::internal::ns<::NSPopUpButton>(this) setAltersStateOfSelectedItem:static_cast<::BOOL>(value)];
    }

    bool PopUpButton::autoenables_items() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPopUpButton>(this) autoenablesItems]);
    }

    void PopUpButton::set_autoenables_items(bool value) const
    {
        [cocoon::internal::ns<::NSPopUpButton>(this) setAutoenablesItems:static_cast<::BOOL>(value)];
    }

    std::int64_t PopUpButton::index_of_selected_item() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPopUpButton>(this) indexOfSelectedItem]);
    }

    std::vector<MenuItem> PopUpButton::item_array() const
    {
        return cocoon::internal::from_array<MenuItem>([cocoon::internal::ns<::NSPopUpButton>(this) itemArray], [](id e) -> MenuItem
                                                      {
                                                          return cocoon::internal::wrap<MenuItem>((::NSMenuItem*)e);
                                                      });
    }

    std::vector<std::string> PopUpButton::item_titles() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSPopUpButton>(this) itemTitles], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    MenuItem PopUpButton::last_item() const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSPopUpButton>(this) lastItem]);
    }

    Menu PopUpButton::menu() const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSPopUpButton>(this) menu]);
    }

    void PopUpButton::set_menu(const Menu& value) const
    {
        [cocoon::internal::ns<::NSPopUpButton>(this) setMenu:cocoon::internal::native<::NSMenu>(value)];
    }

    std::int64_t PopUpButton::number_of_items() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPopUpButton>(this) numberOfItems]);
    }

    RectEdge PopUpButton::preferred_edge() const
    {
        return static_cast<RectEdge>([cocoon::internal::ns<::NSPopUpButton>(this) preferredEdge]);
    }

    void PopUpButton::set_preferred_edge(RectEdge value) const
    {
        [cocoon::internal::ns<::NSPopUpButton>(this) setPreferredEdge:static_cast<::NSRectEdge>(value)];
    }

    bool PopUpButton::pulls_down() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPopUpButton>(this) pullsDown]);
    }

    void PopUpButton::set_pulls_down(bool value) const
    {
        [cocoon::internal::ns<::NSPopUpButton>(this) setPullsDown:static_cast<::BOOL>(value)];
    }

    MenuItem PopUpButton::selected_item() const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSPopUpButton>(this) selectedItem]);
    }

    std::int64_t PopUpButton::selected_tag() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPopUpButton>(this) selectedTag]);
    }

    std::string PopUpButton::title_of_selected_item() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPopUpButton>(this) titleOfSelectedItem]);
    }

    bool PopUpButton::uses_item_from_menu() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPopUpButton>(this) usesItemFromMenu]);
    }

    void PopUpButton::set_uses_item_from_menu(bool value) const
    {
        [cocoon::internal::ns<::NSPopUpButton>(this) setUsesItemFromMenu:static_cast<::BOOL>(value)];
    }

    void PopUpButton::bind_action_(void* native)
    {
        id host = (__bridge id)native;
        cocoon::internal::bind_action(host, host, [](id host, id sender)
                                      {
                                          cocoon::Signal<cocoon::Button, void()>::emit((__bridge void*)host, "clicked");
                                          cocoon::Signal<cocoon::PopUpButton, void(std::int64_t)>::emit((__bridge void*)host, "selection_changed", [(NSPopUpButton*)sender indexOfSelectedItem]);
                                      });
    }
}
