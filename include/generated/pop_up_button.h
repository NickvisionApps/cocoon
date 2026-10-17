#pragma once

#include "generated/button.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Image;
    class Menu;
    class MenuItem;

    /**
     * @brief A pop-up or pull-down menu button.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Button.
     *
     * @par Example
     * @code
     * cocoon::PopUpButton popup;
     * popup.add_items_with_titles({"Small", "Medium", "Large"});
     * popup.selection_changed().connect([](std::int64_t index) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PopUpButton pop_up_button{};
     * pop_up_button.set_alters_state_of_selected_item(true);
     * auto alters_state_of_selected_item = pop_up_button.alters_state_of_selected_item();
     * pop_up_button.set_autoenables_items(true);
     * auto autoenables_items = pop_up_button.autoenables_items();
     * pop_up_button.set_menu(cocoon::Menu());
     * auto menu = pop_up_button.menu();
     * auto made_0 = cocoon::PopUpButton::pull_down_button_with_image(cocoon::Image(), cocoon::Menu());
     * auto made_1 = cocoon::PopUpButton::pull_down_button_with_title("text", cocoon::Image(), cocoon::Menu());
     * pop_up_button.add_item_with_title("text");
     * pop_up_button.add_items_with_titles({"a", "b"});
     * pop_up_button.index_of_item(cocoon::MenuItem());
     * pop_up_button.selection_changed().connect([](std::int64_t a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspopupbutton
     */
    class PopUpButton : public Button
    {
    public:
        /// @brief Creates a new `NSPopUpButton` instance and returns a handle to it.
        explicit PopUpButton();
        /// @brief Creates a new `NSPopUpButton` instance and returns a handle to it.
        explicit PopUpButton(const Rect& button_frame, bool flag);
        /// @brief Creates a null handle that refers to no native object.
        PopUpButton(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PopUpButton(Adopt adopt);
        using Button::set_title;
        using Control::selected_tag;
        using Responder::menu;
        using Responder::set_menu;
        /**
     * @brief Calls `-[NSPopUpButton addItemWithTitle:]`.
     * @param title Argument converted to the Objective-C parameter of the same role.
     */
        void add_item_with_title(const std::string& title) const;
        /**
     * @brief Calls `-[NSPopUpButton addItemsWithTitles:]`.
     * @param item_titles Argument converted to the Objective-C parameter of the same role.
     */
        void add_items_with_titles(const std::vector<std::string>& item_titles) const;
        /**
     * @brief Calls `-[NSPopUpButton indexOfItem:]`.
     * @param item Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_item(const MenuItem& item) const;
        /**
     * @brief Calls `-[NSPopUpButton indexOfItemWithRepresentedObject:]`.
     * @param obj Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_item_with_represented_object(const Object& obj) const;
        /**
     * @brief Calls `-[NSPopUpButton indexOfItemWithTag:]`.
     * @param tag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_item_with_tag(std::int64_t tag) const;
        /**
     * @brief Calls `-[NSPopUpButton indexOfItemWithTarget:andAction:]`.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param action_selector Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_item_with_target(const Object& target, const std::string& action_selector) const;
        /**
     * @brief Calls `-[NSPopUpButton indexOfItemWithTitle:]`.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_item_with_title(const std::string& title) const;
        /**
     * @brief Calls `-[NSPopUpButton insertItemWithTitle:atIndex:]`.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_item_with_title(const std::string& title, std::int64_t index) const;
        /**
     * @brief Calls `-[NSPopUpButton itemAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        MenuItem item_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSPopUpButton itemTitleAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string item_title_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSPopUpButton itemWithTitle:]`.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        MenuItem item_with_title(const std::string& title) const;
        /**
     * @brief Calls `+[NSPopUpButton popUpButtonWithMenu:target:action:]`.
     * @details Creates a standard pop-up button with a menu, target, and action. \@param menu A menu presented by the pop-up button, containing items that the user can choose between. \@param target The target object that receives action messages from the control. \@param action The action message sent by the control. \@discussion If 'menu' is non-empty, the pop-up button uses the first item for its initial selection. \@return An initialized pop-up button object.
     * @param menu Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PopUpButton pop_up_button_with_menu(const Menu& menu, const Object& target, const std::string& action);
        /**
     * @brief Calls `+[NSPopUpButton pullDownButtonWithImage:menu:]`.
     * @details Creates a standard pull-down button with an image and menu. \@param image The icon that is displayed on the button. \@param menu The pull-down menu to present when interacting with the button. \@discussion Pull-down buttons created using this method have the 'usesItemFromMenu' property set to 'NO'. \@return An initialized pull-down button object.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @param menu Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PopUpButton pull_down_button_with_image(const Image& image, const Menu& menu);
        /**
     * @brief Calls `+[NSPopUpButton pullDownButtonWithTitle:image:menu:]`.
     * @details Creates a standard pull-down button with a title, image, and menu. \@param title The localized title string that is displayed on the button. \@param image The icon that is displayed on the button. \@param menu The pull-down menu to present when interacting with the button. \@discussion Pull-down buttons created using this method have the 'usesItemFromMenu' property set to 'NO'. \@return An initialized pull-down button object.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @param menu Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PopUpButton pull_down_button_with_title(const std::string& title, const Image& image, const Menu& menu);
        /**
     * @brief Calls `+[NSPopUpButton pullDownButtonWithTitle:menu:]`.
     * @details Creates a standard pull-down button with a title and menu. \@param title The localized title string that is displayed on the button. \@param menu The pull-down menu to present when interacting with the button. \@discussion Pull-down buttons created using this method have the 'usesItemFromMenu' property set to 'NO'. \@return An initialized pull-down button object.
     * @param title Argument converted to the Objective-C parameter of the same role.
     * @param menu Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PopUpButton pull_down_button_with_title(const std::string& title, const Menu& menu);
        /**
     * @brief Calls `-[NSPopUpButton removeAllItems]`.
     */
        void remove_all_items() const;
        /**
     * @brief Calls `-[NSPopUpButton removeItemAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void remove_item_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSPopUpButton removeItemWithTitle:]`.
     * @param title Argument converted to the Objective-C parameter of the same role.
     */
        void remove_item_with_title(const std::string& title) const;
        /**
     * @brief Calls `-[NSPopUpButton selectItem:]`.
     * @param item Argument converted to the Objective-C parameter of the same role.
     */
        void select_item(const MenuItem& item) const;
        /**
     * @brief Calls `-[NSPopUpButton selectItemAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void select_item_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSPopUpButton selectItemWithTag:]`.
     * @param tag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool select_item_with_tag(std::int64_t tag) const;
        /**
     * @brief Calls `-[NSPopUpButton selectItemWithTitle:]`.
     * @param title Argument converted to the Objective-C parameter of the same role.
     */
        void select_item_with_title(const std::string& title) const;
        /**
     * @brief Calls `-[NSPopUpButton setTitle:]`.
     * @param string Argument converted to the Objective-C parameter of the same role.
     */
        void set_title(const std::string& string) const;
        /**
     * @brief Calls `-[NSPopUpButton synchronizeTitleAndSelectedItem]`.
     */
        void synchronize_title_and_selected_item() const;
        /**
     * @brief Returns the `altersStateOfSelectedItem` property of `NSPopUpButton`.
     * @details When the value of this property is 'YES', the selected menu item's 'state' is set to 'NSControlStateValueOn'. When the value of this property is 'NO', the menu item's 'state' is not changed. When this property changes, the 'state' of the currently selected item is updated appropriately. This property is ignored for pull-down buttons.
     * @return The converted Objective-C result.
     */
        bool alters_state_of_selected_item() const;
        /**
     * @brief Sets the `altersStateOfSelectedItem` property of `NSPopUpButton`.
     * @details When the value of this property is 'YES', the selected menu item's 'state' is set to 'NSControlStateValueOn'. When the value of this property is 'NO', the menu item's 'state' is not changed. When this property changes, the 'state' of the currently selected item is updated appropriately. This property is ignored for pull-down buttons.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_alters_state_of_selected_item(bool value) const;
        /**
     * @brief Returns the `autoenablesItems` property of `NSPopUpButton`.
     * @details When the value of this property is 'YES', the popup button automatically enables and disables its menu items according to the 'NSMenuValidation' protocol prior to user interaction.
     * @return The converted Objective-C result.
     */
        bool autoenables_items() const;
        /**
     * @brief Sets the `autoenablesItems` property of `NSPopUpButton`.
     * @details When the value of this property is 'YES', the popup button automatically enables and disables its menu items according to the 'NSMenuValidation' protocol prior to user interaction.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_autoenables_items(bool value) const;
        /**
     * @brief Returns the `indexOfSelectedItem` property of `NSPopUpButton`.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_selected_item() const;
        /**
     * @brief Returns the `itemArray` property of `NSPopUpButton`.
     * @return The converted Objective-C result.
     */
        std::vector<MenuItem> item_array() const;
        /**
     * @brief Returns the `itemTitles` property of `NSPopUpButton`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> item_titles() const;
        /**
     * @brief Returns the `lastItem` property of `NSPopUpButton`.
     * @return The converted Objective-C result.
     */
        MenuItem last_item() const;
        /**
     * @brief Returns the `menu` property of `NSPopUpButton`.
     * @details The menu that is presented by the popup button. This overrides the inherited NSView property and replaces NSView's standard context menu behavior.
     * @return The converted Objective-C result.
     */
        Menu menu() const;
        /**
     * @brief Sets the `menu` property of `NSPopUpButton`.
     * @details The menu that is presented by the popup button. This overrides the inherited NSView property and replaces NSView's standard context menu behavior.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_menu(const Menu& value) const;
        /**
     * @brief Returns the `numberOfItems` property of `NSPopUpButton`.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_items() const;
        /**
     * @brief Returns the `preferredEdge` property of `NSPopUpButton`.
     * @details For pull-down buttons and for popups under severe screen position restrictions, this property specifies the edge of the control that the menu should present from.
     * @return The converted Objective-C result.
     */
        RectEdge preferred_edge() const;
        /**
     * @brief Sets the `preferredEdge` property of `NSPopUpButton`.
     * @details For pull-down buttons and for popups under severe screen position restrictions, this property specifies the edge of the control that the menu should present from.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preferred_edge(RectEdge value) const;
        /**
     * @brief Returns the `pullsDown` property of `NSPopUpButton`.
     * @details When the value of this property is 'YES' the button adopts 'pull-down' behavior, displaying static button contents and presenting its menu at the edge of the button. When the value of this property is 'NO' the button behaves as a popup, displaying the currently-selected menu item and presenting its menu above the button, positioning the selected menu item to match the button's contents.
     * @return The converted Objective-C result.
     */
        bool pulls_down() const;
        /**
     * @brief Sets the `pullsDown` property of `NSPopUpButton`.
     * @details When the value of this property is 'YES' the button adopts 'pull-down' behavior, displaying static button contents and presenting its menu at the edge of the button. When the value of this property is 'NO' the button behaves as a popup, displaying the currently-selected menu item and presenting its menu above the button, positioning the selected menu item to match the button's contents.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_pulls_down(bool value) const;
        /**
     * @brief Returns the `selectedItem` property of `NSPopUpButton`.
     * @return The converted Objective-C result.
     */
        MenuItem selected_item() const;
        /**
     * @brief Returns the `selectedTag` property of `NSPopUpButton`.
     * @return The converted Objective-C result.
     */
        std::int64_t selected_tag() const;
        /**
     * @brief Returns the `titleOfSelectedItem` property of `NSPopUpButton`.
     * @return The converted Objective-C result.
     */
        std::string title_of_selected_item() const;
        /**
     * @brief Returns the `usesItemFromMenu` property of `NSPopUpButton`.
     * @details When 'usesItemFromMenu' is 'YES', a pull-down button uses the title of the first menu item and hides the first menu item. A pop-up button uses the title of the currently selected menu. The default value is 'YES'.
     * @return The converted Objective-C result.
     */
        bool uses_item_from_menu() const;
        /**
     * @brief Sets the `usesItemFromMenu` property of `NSPopUpButton`.
     * @details When 'usesItemFromMenu' is 'YES', a pull-down button uses the title of the first menu item and hides the first menu item. A pop-up button uses the title of the currently selected menu. The default value is 'YES'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_item_from_menu(bool value) const;
        /// @brief Signal `selection_changed`: connect a callback with `selection_changed().connect(...)`.
        Signal<PopUpButton, void(std::int64_t)> selection_changed() const
        {
            return Signal<PopUpButton, void(std::int64_t)>(handle(), "selection_changed");
        }

    protected:
        static void bind_action_(void* native);
    };
}
