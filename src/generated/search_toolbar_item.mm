#include "generated/search_toolbar_item.h"
#include "internal.h"

namespace cocoon
{
    SearchToolbarItem::SearchToolbarItem(const std::string& identifier) : SearchToolbarItem(Adopt{cocoon::internal::retain([[NSSearchToolbarItem alloc] initWithItemIdentifier:cocoon::internal::to(identifier)])})
    {
        SearchToolbarItem::bind_action_(handle());
    }

    SearchToolbarItem::SearchToolbarItem(std::nullptr_t) : ToolbarItem(nullptr)
    {
    }

    SearchToolbarItem::SearchToolbarItem(Adopt adopt) : ToolbarItem(adopt)
    {
    }

    void SearchToolbarItem::begin_search_interaction() const
    {
        [cocoon::internal::ns<::NSSearchToolbarItem>(this) beginSearchInteraction];
    }

    void SearchToolbarItem::end_search_interaction() const
    {
        [cocoon::internal::ns<::NSSearchToolbarItem>(this) endSearchInteraction];
    }

    double SearchToolbarItem::preferred_width_for_search_field() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSearchToolbarItem>(this) preferredWidthForSearchField]);
    }

    void SearchToolbarItem::set_preferred_width_for_search_field(double value) const
    {
        [cocoon::internal::ns<::NSSearchToolbarItem>(this) setPreferredWidthForSearchField:static_cast<::CGFloat>(value)];
    }

    bool SearchToolbarItem::resigns_first_responder_with_cancel() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSearchToolbarItem>(this) resignsFirstResponderWithCancel]);
    }

    void SearchToolbarItem::set_resigns_first_responder_with_cancel(bool value) const
    {
        [cocoon::internal::ns<::NSSearchToolbarItem>(this) setResignsFirstResponderWithCancel:static_cast<::BOOL>(value)];
    }

    SearchField SearchToolbarItem::search_field() const
    {
        return cocoon::internal::wrap<SearchField>([cocoon::internal::ns<::NSSearchToolbarItem>(this) searchField]);
    }

    void SearchToolbarItem::set_search_field(const SearchField& value) const
    {
        [cocoon::internal::ns<::NSSearchToolbarItem>(this) setSearchField:cocoon::internal::native<::NSSearchField>(value)];
    }

    void SearchToolbarItem::bind_action_(void* native)
    {
        id host = (__bridge id)native;
        cocoon::internal::bind_action(((NSSearchToolbarItem*)host).searchField, host, [](id host, id sender)
                                      {
                                          cocoon::Signal<cocoon::SearchToolbarItem, void(std::string)>::emit((__bridge void*)host, "searched", cocoon::internal::from(((NSSearchField*)sender).stringValue));
                                      });
    }
}
