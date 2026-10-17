#pragma once

#include <string>
#include <vector>
#include "generated/view.h"

namespace cocoon
{
    /**
     * @brief A simple multi-column text table with row selection (NSTableView in a scroll view).
     * @par Example
     * @code
     * cocoon::TableList table;
     * table.set_columns({"Name", "Kind"});
     * table.set_rows({{"Button", "Control"}, {"Slider", "Control"}});
     * table.selection_changed().connect([](int row) { });
     * table.double_clicked().connect([](int row) { });
     * @endcode
     */
    class TableList : public View
    {
    public:
        /// Creates an empty table.
        TableList();
        /// Creates a null handle.
        TableList(std::nullptr_t) : View(nullptr)
        {
        }
        /// Wraps an existing native scroll view.
        explicit TableList(Adopt adopt);

        /// Replaces the column titles.
        void set_columns(const std::vector<std::string>& titles) const;
        /// Replaces all rows (each row is a list of cell strings).
        void set_rows(const std::vector<std::vector<std::string>>& rows) const;
        /// @return The selected row, or -1.
        int selected_row() const;
        /// Selects a row.
        void select_row(int row) const;
        /// Enables alternating row background colors.
        void set_alternating_rows(bool alternating) const;

        /// Signal emitted with the selected row index.
        Signal<TableList, void(int)> selection_changed() const
        {
            return Signal<TableList, void(int)>(handle(), "selection_changed");
        }
        /// Signal emitted with the double-clicked row index.
        Signal<TableList, void(int)> double_clicked() const
        {
            return Signal<TableList, void(int)>(handle(), "double_clicked");
        }
    };
}
