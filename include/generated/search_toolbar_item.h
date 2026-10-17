#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/toolbar_item.h"
#include "types.h"

namespace cocoon
{
    class SearchField;

    /**
     * @brief A search field toolbar item (NSSearchToolbarItem).
     * @details 'NSSearchToolbarItem' provides the standard UI behavior for integrating a search field into the toolbar.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ToolbarItem.
     *
     * @par Example
     * @code
     * cocoon::SearchToolbarItem item("search");
     * item.searched().connect([](const std::string& text) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SearchToolbarItem search_toolbar_item{"text"};
     * search_toolbar_item.set_preferred_width_for_search_field(1);
     * auto preferred_width_for_search_field = search_toolbar_item.preferred_width_for_search_field();
     * search_toolbar_item.set_resigns_first_responder_with_cancel(true);
     * auto resigns_first_responder_with_cancel = search_toolbar_item.resigns_first_responder_with_cancel();
     * search_toolbar_item.set_search_field(cocoon::SearchField());
     * auto search_field = search_toolbar_item.search_field();
     * search_toolbar_item.begin_search_interaction();
     * search_toolbar_item.end_search_interaction();
     * search_toolbar_item.searched().connect([](std::string a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssearchtoolbaritem
     */
    class SearchToolbarItem : public ToolbarItem
    {
    public:
        /// @brief Creates a new `NSSearchToolbarItem` instance and returns a handle to it.
        explicit SearchToolbarItem(const std::string& identifier = "search");
        /// @brief Creates a null handle that refers to no native object.
        SearchToolbarItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SearchToolbarItem(Adopt adopt);
        /**
     * @brief Calls `-[NSSearchToolbarItem beginSearchInteraction]`.
     * @details Starts a search interaction. If necessary, expands to the preferred width and moves the keyboard focus to the search field.
     */
        void begin_search_interaction() const;
        /**
     * @brief Calls `-[NSSearchToolbarItem endSearchInteraction]`.
     * @details Ends a search interaction. Gives up the first responder by calling '-endEditing:' to the search field. Adjusts to the natural available width for the toolbar item if necessary.
     */
        void end_search_interaction() const;
        /**
     * @brief Returns the `preferredWidthForSearchField` property of `NSSearchToolbarItem`.
     * @details The preferred width for the search field. This value is used to configure the search field width whenever it gets the keyboard focus. If specifying custom width constraints to the search field, they should not conflict with this value.
     * @return The converted Objective-C result.
     */
        double preferred_width_for_search_field() const;
        /**
     * @brief Sets the `preferredWidthForSearchField` property of `NSSearchToolbarItem`.
     * @details The preferred width for the search field. This value is used to configure the search field width whenever it gets the keyboard focus. If specifying custom width constraints to the search field, they should not conflict with this value.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preferred_width_for_search_field(double value) const;
        /**
     * @brief Returns the `resignsFirstResponderWithCancel` property of `NSSearchToolbarItem`.
     * @details When YES, the cancel button in the field resigns the first responder status of the search field as clearing the contents. The default is YES.
     * @return The converted Objective-C result.
     */
        bool resigns_first_responder_with_cancel() const;
        /**
     * @brief Sets the `resignsFirstResponderWithCancel` property of `NSSearchToolbarItem`.
     * @details When YES, the cancel button in the field resigns the first responder status of the search field as clearing the contents. The default is YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_resigns_first_responder_with_cancel(bool value) const;
        /**
     * @brief Returns the `searchField` property of `NSSearchToolbarItem`.
     * @details An 'NSSearchField' displayed in the toolbar item. While inside the toolbar item, the field properties and layout constraints are managed by the item. The field should be configured before assigned. The width constraint for the field could be updated after assigned. When set to nil, will reset to a search field with the default configuration.
     * @return The converted Objective-C result.
     */
        SearchField search_field() const;
        /**
     * @brief Sets the `searchField` property of `NSSearchToolbarItem`.
     * @details An 'NSSearchField' displayed in the toolbar item. While inside the toolbar item, the field properties and layout constraints are managed by the item. The field should be configured before assigned. The width constraint for the field could be updated after assigned. When set to nil, will reset to a search field with the default configuration.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_search_field(const SearchField& value) const;
        /// @brief Signal `searched`: connect a callback with `searched().connect(...)`.
        Signal<SearchToolbarItem, void(std::string)> searched() const
        {
            return Signal<SearchToolbarItem, void(std::string)>(handle(), "searched");
        }

    protected:
        static void bind_action_(void* native);
    };
}
