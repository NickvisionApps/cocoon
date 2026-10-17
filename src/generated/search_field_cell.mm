#include "generated/search_field_cell.h"
#include "internal.h"

namespace cocoon
{
    SearchFieldCell::SearchFieldCell(const std::string& string) : SearchFieldCell(Adopt{cocoon::internal::retain([[::NSSearchFieldCell alloc] initTextCell:cocoon::internal::to(string)])})
    {
    }

    SearchFieldCell::SearchFieldCell() : SearchFieldCell(Adopt{cocoon::internal::retain([[::NSSearchFieldCell alloc] init])})
    {
    }

    SearchFieldCell::SearchFieldCell(std::nullptr_t) : TextFieldCell(nullptr)
    {
    }

    SearchFieldCell::SearchFieldCell(Adopt adopt) : TextFieldCell(adopt)
    {
    }

    Rect SearchFieldCell::cancel_button_rect_for_bounds(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSearchFieldCell>(this) cancelButtonRectForBounds:cocoon::internal::to(rect)]);
    }

    void SearchFieldCell::reset_cancel_button_cell() const
    {
        [cocoon::internal::ns<::NSSearchFieldCell>(this) resetCancelButtonCell];
    }

    void SearchFieldCell::reset_search_button_cell() const
    {
        [cocoon::internal::ns<::NSSearchFieldCell>(this) resetSearchButtonCell];
    }

    Rect SearchFieldCell::search_button_rect_for_bounds(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSearchFieldCell>(this) searchButtonRectForBounds:cocoon::internal::to(rect)]);
    }

    Rect SearchFieldCell::search_text_rect_for_bounds(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSearchFieldCell>(this) searchTextRectForBounds:cocoon::internal::to(rect)]);
    }

    ButtonCell SearchFieldCell::cancel_button_cell() const
    {
        return cocoon::internal::wrap<ButtonCell>([cocoon::internal::ns<::NSSearchFieldCell>(this) cancelButtonCell]);
    }

    void SearchFieldCell::set_cancel_button_cell(const ButtonCell& value) const
    {
        [cocoon::internal::ns<::NSSearchFieldCell>(this) setCancelButtonCell:cocoon::internal::native<::NSButtonCell>(value)];
    }

    std::int64_t SearchFieldCell::maximum_recents() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSSearchFieldCell>(this) maximumRecents]);
    }

    void SearchFieldCell::set_maximum_recents(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSSearchFieldCell>(this) setMaximumRecents:static_cast<::NSInteger>(value)];
    }

    std::vector<std::string> SearchFieldCell::recent_searches() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSSearchFieldCell>(this) recentSearches], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    void SearchFieldCell::set_recent_searches(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSSearchFieldCell>(this) setRecentSearches:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                          {
                                                                              return cocoon::internal::to(e);
                                                                          })];
    }

    std::string SearchFieldCell::recents_autosave_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSearchFieldCell>(this) recentsAutosaveName]);
    }

    void SearchFieldCell::set_recents_autosave_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSSearchFieldCell>(this) setRecentsAutosaveName:cocoon::internal::to(value)];
    }

    ButtonCell SearchFieldCell::search_button_cell() const
    {
        return cocoon::internal::wrap<ButtonCell>([cocoon::internal::ns<::NSSearchFieldCell>(this) searchButtonCell]);
    }

    void SearchFieldCell::set_search_button_cell(const ButtonCell& value) const
    {
        [cocoon::internal::ns<::NSSearchFieldCell>(this) setSearchButtonCell:cocoon::internal::native<::NSButtonCell>(value)];
    }

    Menu SearchFieldCell::search_menu_template() const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSSearchFieldCell>(this) searchMenuTemplate]);
    }

    void SearchFieldCell::set_search_menu_template(const Menu& value) const
    {
        [cocoon::internal::ns<::NSSearchFieldCell>(this) setSearchMenuTemplate:cocoon::internal::native<::NSMenu>(value)];
    }

    bool SearchFieldCell::sends_search_string_immediately() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSearchFieldCell>(this) sendsSearchStringImmediately]);
    }

    void SearchFieldCell::set_sends_search_string_immediately(bool value) const
    {
        [cocoon::internal::ns<::NSSearchFieldCell>(this) setSendsSearchStringImmediately:static_cast<::BOOL>(value)];
    }

    bool SearchFieldCell::sends_whole_search_string() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSearchFieldCell>(this) sendsWholeSearchString]);
    }

    void SearchFieldCell::set_sends_whole_search_string(bool value) const
    {
        [cocoon::internal::ns<::NSSearchFieldCell>(this) setSendsWholeSearchString:static_cast<::BOOL>(value)];
    }
}
