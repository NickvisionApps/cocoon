#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/toolbar_item.h"
#include "types.h"

namespace cocoon
{
    class Image;
    class ToolbarItem;

    /**
     * @brief C++ handle for the Objective-C class `NSToolbarItemGroup` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ToolbarItem.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ToolbarItemGroup toolbar_item_group;
     * toolbar_item_group.set_control_representation(cocoon::ToolbarItemGroupControlRepresentation::Automatic);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ToolbarItemGroup toolbar_item_group{};
     * toolbar_item_group.set_control_representation(cocoon::ToolbarItemGroupControlRepresentation::Automatic);
     * auto control_representation = toolbar_item_group.control_representation();
     * toolbar_item_group.set_role(cocoon::ToolbarItemGroupRole::Automatic);
     * auto role = toolbar_item_group.role();
     * toolbar_item_group.set_selected_index(1);
     * auto selected_index = toolbar_item_group.selected_index();
     * toolbar_item_group.is_selected_at_index(1);
     * toolbar_item_group.set_selected(true, 1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstoolbaritemgroup
     */
    class ToolbarItemGroup : public ToolbarItem
    {
    public:
        /// @brief Creates a new `NSToolbarItemGroup` instance and returns a handle to it.
        explicit ToolbarItemGroup();
        /// @brief Creates a null handle that refers to no native object.
        ToolbarItemGroup(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ToolbarItemGroup(Adopt adopt);
        /**
     * @brief Calls `+[NSToolbarItemGroup groupWithItemIdentifier:images:selectionMode:labels:target:action:]`.
     * @param item_identifier Argument converted to the Objective-C parameter of the same role.
     * @param images Argument converted to the Objective-C parameter of the same role.
     * @param selection_mode Argument converted to the Objective-C parameter of the same role.
     * @param labels Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ToolbarItemGroup group_with_item_identifier(const std::string& item_identifier, const std::vector<Image>& images, ToolbarItemGroupSelectionMode selection_mode, const std::vector<std::string>& labels, const Object& target, const std::string& action);
        /**
     * @brief Calls `+[NSToolbarItemGroup groupWithItemIdentifier:titles:selectionMode:labels:target:action:]`.
     * @details Convenience constructors for creating segmented control based toolbar items with images or text. The item returned will have a custom view for representing the control and automatically create subitems for the group. The labels array, if not nil, will be used to provide individual labels under the item for each segment of the control. When space in the toolbar is tight, the control may switch to a smaller alternate representation as necessary to remain in the toolbar.
     * @param item_identifier Argument converted to the Objective-C parameter of the same role.
     * @param titles Argument converted to the Objective-C parameter of the same role.
     * @param selection_mode Argument converted to the Objective-C parameter of the same role.
     * @param labels Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param action Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ToolbarItemGroup group_with_item_identifier(const std::string& item_identifier, const std::vector<std::string>& titles, ToolbarItemGroupSelectionMode selection_mode, const std::vector<std::string>& labels, const Object& target, const std::string& action);
        /**
     * @brief Calls `-[NSToolbarItemGroup isSelectedAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_selected_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSToolbarItemGroup setSelected:atIndex:]`.
     * @details Get and set selection of individual subitems of the group item.
     * @param selected Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void set_selected(bool selected, std::int64_t index) const;
        /**
     * @brief Returns the `controlRepresentation` property of `NSToolbarItemGroup`.
     * @details The style in which this item will be represented to the user. Defaults to 'NSToolbarItemGroupControlRepresentationAutomatic'.
     * @return The converted Objective-C result.
     */
        ToolbarItemGroupControlRepresentation control_representation() const;
        /**
     * @brief Sets the `controlRepresentation` property of `NSToolbarItemGroup`.
     * @details The style in which this item will be represented to the user. Defaults to 'NSToolbarItemGroupControlRepresentationAutomatic'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_control_representation(ToolbarItemGroupControlRepresentation value) const;
#ifdef COCOON_MACOS_27
        /**
     * @brief Returns the `role` property of `NSToolbarItemGroup`.
     * @details The semantic role of the item. Defaults to 'NSToolbarItemGroupRoleAutomatic'.
     * @return The converted Objective-C result.
     */
        ToolbarItemGroupRole role() const;
#endif
#ifdef COCOON_MACOS_27
        /**
     * @brief Sets the `role` property of `NSToolbarItemGroup`.
     * @details The semantic role of the item. Defaults to 'NSToolbarItemGroupRoleAutomatic'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_role(ToolbarItemGroupRole value) const;
#endif
        /**
     * @brief Returns the `selectedIndex` property of `NSToolbarItemGroup`.
     * @details The most recently selected item of the group, or -1 if nothing is selected.
     * @return The converted Objective-C result.
     */
        std::int64_t selected_index() const;
        /**
     * @brief Sets the `selectedIndex` property of `NSToolbarItemGroup`.
     * @details The most recently selected item of the group, or -1 if nothing is selected.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selected_index(std::int64_t value) const;
        /**
     * @brief Returns the `selectionMode` property of `NSToolbarItemGroup`.
     * @details Get and set how selection is handled by the control. Only applies when using one of the constructors to create the item with a system defined control representation.
     * @return The converted Objective-C result.
     */
        ToolbarItemGroupSelectionMode selection_mode() const;
        /**
     * @brief Sets the `selectionMode` property of `NSToolbarItemGroup`.
     * @details Get and set how selection is handled by the control. Only applies when using one of the constructors to create the item with a system defined control representation.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selection_mode(ToolbarItemGroupSelectionMode value) const;
        /**
     * @brief Returns the `subitems` property of `NSToolbarItemGroup`.
     * @details Set or get the array of subitems for the toolbar item. By default, a 'NSToolbarItemGroup' has an empty array of subitems. You should call this to set the subitems before returning the item to the toolbar. 'NSToolbarItemGroups' may not contain other 'NSToolbarItemGroups' as subitems.
     * @return The converted Objective-C result.
     */
        std::vector<ToolbarItem> subitems() const;
        /**
     * @brief Sets the `subitems` property of `NSToolbarItemGroup`.
     * @details Set or get the array of subitems for the toolbar item. By default, a 'NSToolbarItemGroup' has an empty array of subitems. You should call this to set the subitems before returning the item to the toolbar. 'NSToolbarItemGroups' may not contain other 'NSToolbarItemGroups' as subitems.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_subitems(const std::vector<ToolbarItem>& value) const;
    };
}
