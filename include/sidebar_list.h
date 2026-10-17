#pragma once

#include <string>
#include <vector>
#include "generated/view.h"

namespace cocoon
{
    /**
     * @brief One row of a SidebarList (optionally a group header with children).
     * @par Example
     * @code
     * cocoon::SidebarItem library{0, "Library", "", true, {
     *     {1, "Inbox", "tray"},
     *     {2, "Sent", "paperplane"},
     * }};
     * @endcode
     */
    struct SidebarItem
    {
        /// Identifier reported by SidebarList::selection_changed.
        int id = 0;
        /// Row title.
        std::string title;
        /// SF Symbol name for the row icon (may be empty).
        std::string symbol;
        /// True for a group header row that cannot be selected.
        bool is_header = false;
        /// Nested rows.
        std::vector<SidebarItem> children;
    };

    /**
     * @brief A source-list style sidebar (NSOutlineView with the sidebar style) with symbols and group headers.
     * @par Example
     * @code
     * cocoon::SidebarList sidebar;
     * sidebar.set_items({{0, "Library", "", true, {{1, "Inbox", "tray"}}}});
     * sidebar.selection_changed().connect([](int id) { });
     * sidebar.select_item(1);
     * cocoon::SplitViewController split;
     * split.add_sidebar(sidebar);
     * @endcode
     */
    class SidebarList : public View
    {
    public:
        /// Creates an empty sidebar.
        SidebarList();
        /// Creates a null handle.
        SidebarList(std::nullptr_t) : View(nullptr)
        {
        }
        /// Wraps an existing native scroll view.
        explicit SidebarList(Adopt adopt);

        /// Replaces the rows and expands all groups.
        void set_items(const std::vector<SidebarItem>& items) const;
        /// Selects the row with the given id.
        void select_item(int id) const;
        /// @return The selected row id, or -1.
        int selected_item() const;
        /// Expands every group.
        void expand_all() const;

        /// Signal emitted with the row id when the selection changes (-1 when cleared).
        Signal<SidebarList, void(int)> selection_changed() const
        {
            return Signal<SidebarList, void(int)>(handle(), "selection_changed");
        }
    };
}
