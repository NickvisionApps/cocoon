#include "generated/pop_up_button_cell.h"
#include "internal.h"

namespace cocoon
{
    PopUpButtonCell::PopUpButtonCell(const std::string& string_value, bool pull_down) : PopUpButtonCell(Adopt{cocoon::internal::retain([[::NSPopUpButtonCell alloc] initTextCell:cocoon::internal::to(string_value) pullsDown:static_cast<::BOOL>(pull_down)])})
    {
    }

    PopUpButtonCell::PopUpButtonCell() : PopUpButtonCell(Adopt{cocoon::internal::retain([[::NSPopUpButtonCell alloc] init])})
    {
    }

    PopUpButtonCell::PopUpButtonCell(std::nullptr_t) : MenuItemCell(nullptr)
    {
    }

    PopUpButtonCell::PopUpButtonCell(Adopt adopt) : MenuItemCell(adopt)
    {
    }

    void PopUpButtonCell::add_item_with_title(const std::string& title) const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) addItemWithTitle:cocoon::internal::to(title)];
    }

    void PopUpButtonCell::add_items_with_titles(const std::vector<std::string>& item_titles) const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) addItemsWithTitles:cocoon::internal::to_array(item_titles, [](const std::string& e) -> id
                                                                           {
                                                                               return cocoon::internal::to(e);
                                                                           })];
    }

    void PopUpButtonCell::attach_pop_up_with_frame(const Rect& cell_frame, const View& control_view) const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) attachPopUpWithFrame:cocoon::internal::to(cell_frame) inView:cocoon::internal::native<::NSView>(control_view)];
    }

    void PopUpButtonCell::dismiss_pop_up() const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) dismissPopUp];
    }

    std::int64_t PopUpButtonCell::index_of_item(const MenuItem& item) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPopUpButtonCell>(this) indexOfItem:cocoon::internal::native<::NSMenuItem>(item)]);
    }

    std::int64_t PopUpButtonCell::index_of_item_with_represented_object(const Object& obj) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPopUpButtonCell>(this) indexOfItemWithRepresentedObject:cocoon::internal::native_id(obj)]);
    }

    std::int64_t PopUpButtonCell::index_of_item_with_tag(std::int64_t tag) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPopUpButtonCell>(this) indexOfItemWithTag:static_cast<::NSInteger>(tag)]);
    }

    std::int64_t PopUpButtonCell::index_of_item_with_target(const Object& target, const std::string& action_selector) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPopUpButtonCell>(this) indexOfItemWithTarget:cocoon::internal::native_id(target) andAction:NSSelectorFromString(cocoon::internal::to(action_selector))]);
    }

    std::int64_t PopUpButtonCell::index_of_item_with_title(const std::string& title) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPopUpButtonCell>(this) indexOfItemWithTitle:cocoon::internal::to(title)]);
    }

    void PopUpButtonCell::insert_item_with_title(const std::string& title, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) insertItemWithTitle:cocoon::internal::to(title) atIndex:static_cast<::NSInteger>(index)];
    }

    MenuItem PopUpButtonCell::item_at_index(std::int64_t index) const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSPopUpButtonCell>(this) itemAtIndex:static_cast<::NSInteger>(index)]);
    }

    std::string PopUpButtonCell::item_title_at_index(std::int64_t index) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPopUpButtonCell>(this) itemTitleAtIndex:static_cast<::NSInteger>(index)]);
    }

    MenuItem PopUpButtonCell::item_with_title(const std::string& title) const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSPopUpButtonCell>(this) itemWithTitle:cocoon::internal::to(title)]);
    }

    void PopUpButtonCell::perform_click_with_frame(const Rect& frame, const View& control_view) const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) performClickWithFrame:cocoon::internal::to(frame) inView:cocoon::internal::native<::NSView>(control_view)];
    }

    void PopUpButtonCell::remove_all_items() const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) removeAllItems];
    }

    void PopUpButtonCell::remove_item_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) removeItemAtIndex:static_cast<::NSInteger>(index)];
    }

    void PopUpButtonCell::remove_item_with_title(const std::string& title) const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) removeItemWithTitle:cocoon::internal::to(title)];
    }

    void PopUpButtonCell::select_item(const MenuItem& item) const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) selectItem:cocoon::internal::native<::NSMenuItem>(item)];
    }

    void PopUpButtonCell::select_item_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) selectItemAtIndex:static_cast<::NSInteger>(index)];
    }

    bool PopUpButtonCell::select_item_with_tag(std::int64_t tag) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPopUpButtonCell>(this) selectItemWithTag:static_cast<::NSInteger>(tag)]);
    }

    void PopUpButtonCell::select_item_with_title(const std::string& title) const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) selectItemWithTitle:cocoon::internal::to(title)];
    }

    void PopUpButtonCell::set_title(const std::string& string) const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) setTitle:cocoon::internal::to(string)];
    }

    void PopUpButtonCell::synchronize_title_and_selected_item() const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) synchronizeTitleAndSelectedItem];
    }

    bool PopUpButtonCell::alters_state_of_selected_item() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPopUpButtonCell>(this) altersStateOfSelectedItem]);
    }

    void PopUpButtonCell::set_alters_state_of_selected_item(bool value) const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) setAltersStateOfSelectedItem:static_cast<::BOOL>(value)];
    }

    PopUpArrowPosition PopUpButtonCell::arrow_position() const
    {
        return static_cast<PopUpArrowPosition>([cocoon::internal::ns<::NSPopUpButtonCell>(this) arrowPosition]);
    }

    void PopUpButtonCell::set_arrow_position(PopUpArrowPosition value) const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) setArrowPosition:static_cast<::NSPopUpArrowPosition>(value)];
    }

    bool PopUpButtonCell::autoenables_items() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPopUpButtonCell>(this) autoenablesItems]);
    }

    void PopUpButtonCell::set_autoenables_items(bool value) const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) setAutoenablesItems:static_cast<::BOOL>(value)];
    }

    std::int64_t PopUpButtonCell::index_of_selected_item() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPopUpButtonCell>(this) indexOfSelectedItem]);
    }

    std::vector<MenuItem> PopUpButtonCell::item_array() const
    {
        return cocoon::internal::from_array<MenuItem>([cocoon::internal::ns<::NSPopUpButtonCell>(this) itemArray], [](id e) -> MenuItem
                                        {
                                            return cocoon::internal::wrap<MenuItem>((::NSMenuItem*)e);
                                        });
    }

    std::vector<std::string> PopUpButtonCell::item_titles() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSPopUpButtonCell>(this) itemTitles], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    MenuItem PopUpButtonCell::last_item() const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSPopUpButtonCell>(this) lastItem]);
    }

    Menu PopUpButtonCell::menu() const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSPopUpButtonCell>(this) menu]);
    }

    void PopUpButtonCell::set_menu(const Menu& value) const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) setMenu:cocoon::internal::native<::NSMenu>(value)];
    }

    std::int64_t PopUpButtonCell::number_of_items() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPopUpButtonCell>(this) numberOfItems]);
    }

    RectEdge PopUpButtonCell::preferred_edge() const
    {
        return static_cast<RectEdge>([cocoon::internal::ns<::NSPopUpButtonCell>(this) preferredEdge]);
    }

    void PopUpButtonCell::set_preferred_edge(RectEdge value) const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) setPreferredEdge:static_cast<::NSRectEdge>(value)];
    }

    bool PopUpButtonCell::pulls_down() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPopUpButtonCell>(this) pullsDown]);
    }

    void PopUpButtonCell::set_pulls_down(bool value) const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) setPullsDown:static_cast<::BOOL>(value)];
    }

    MenuItem PopUpButtonCell::selected_item() const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSPopUpButtonCell>(this) selectedItem]);
    }

    std::string PopUpButtonCell::title_of_selected_item() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPopUpButtonCell>(this) titleOfSelectedItem]);
    }

    bool PopUpButtonCell::uses_item_from_menu() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPopUpButtonCell>(this) usesItemFromMenu]);
    }

    void PopUpButtonCell::set_uses_item_from_menu(bool value) const
    {
        [cocoon::internal::ns<::NSPopUpButtonCell>(this) setUsesItemFromMenu:static_cast<::BOOL>(value)];
    }
}
