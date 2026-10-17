#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/text_field.h"
#include "types.h"

namespace cocoon
{
    class Menu;
    class Notification;
    class Text;
    class TextCheckingResult;
    class TextView;

    /**
     * @brief A search field (NSSearchField).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TextField.
     *
     * @par Example
     * @code
     * cocoon::SearchField search;
     * search.editing_finished().connect([] {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SearchField search_field{};
     * search_field.set_maximum_recents(1);
     * auto maximum_recents = search_field.maximum_recents();
     * search_field.set_recent_searches({"a", "b"});
     * auto recent_searches = search_field.recent_searches();
     * search_field.set_recents_autosave_name("text");
     * auto recents_autosave_name = search_field.recents_autosave_name();
     * search_field.did_start_searching().connect([]() {});
     * search_field.did_end_searching().connect([]() {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssearchfield
     */
    class SearchField : public TextField
    {
    public:
        /// @brief Creates a new `NSSearchField` instance and returns a handle to it.
        explicit SearchField();
        /// @brief Creates a null handle that refers to no native object.
        SearchField(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SearchField(Adopt adopt);
        /**
     * @brief Returns the `cancelButtonBounds` property of `NSSearchField`.
     * @return The converted Objective-C result.
     */
        Rect cancel_button_bounds() const;
        /**
     * @brief Returns the `maximumRecents` property of `NSSearchField`.
     * @details set/get limit max recents. allowable between 0 and 254. setting -1 will use default.
     * @return The converted Objective-C result.
     */
        std::int64_t maximum_recents() const;
        /**
     * @brief Sets the `maximumRecents` property of `NSSearchField`.
     * @details set/get limit max recents. allowable between 0 and 254. setting -1 will use default.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_recents(std::int64_t value) const;
        /**
     * @brief Returns the `recentSearches` property of `NSSearchField`.
     * @details if app wants to do custom search lists. will return empty array if no searches
     * @return The converted Objective-C result.
     */
        std::vector<std::string> recent_searches() const;
        /**
     * @brief Sets the `recentSearches` property of `NSSearchField`.
     * @details if app wants to do custom search lists. will return empty array if no searches
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_recent_searches(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `recentsAutosaveName` property of `NSSearchField`.
     * @details must be set to use. default is nil which means no autosave.
     * @return The converted Objective-C result.
     */
        std::string recents_autosave_name() const;
        /**
     * @brief Sets the `recentsAutosaveName` property of `NSSearchField`.
     * @details must be set to use. default is nil which means no autosave.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_recents_autosave_name(const std::string& value) const;
        /**
     * @brief Returns the `searchButtonBounds` property of `NSSearchField`.
     * @return The converted Objective-C result.
     */
        Rect search_button_bounds() const;
        /**
     * @brief Returns the `searchMenuTemplate` property of `NSSearchField`.
     * @details set/get search menu template. Menu can use custom tagged items to indicate special items. this menu isn't actually set but used to construct the dynamic search menu. if cleared, then we don't track recents.
     * @return The converted Objective-C result.
     */
        Menu search_menu_template() const;
        /**
     * @brief Sets the `searchMenuTemplate` property of `NSSearchField`.
     * @details set/get search menu template. Menu can use custom tagged items to indicate special items. this menu isn't actually set but used to construct the dynamic search menu. if cleared, then we don't track recents.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_search_menu_template(const Menu& value) const;
        /**
     * @brief Returns the `searchTextBounds` property of `NSSearchField`.
     * @return The converted Objective-C result.
     */
        Rect search_text_bounds() const;
        /**
     * @brief Returns the `sendsSearchStringImmediately` property of `NSSearchField`.
     * @return The converted Objective-C result.
     */
        bool sends_search_string_immediately() const;
        /**
     * @brief Sets the `sendsSearchStringImmediately` property of `NSSearchField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_sends_search_string_immediately(bool value) const;
        /**
     * @brief Returns the `sendsWholeSearchString` property of `NSSearchField`.
     * @details if clear, send action on each key stroke (after sufficient amount of time so we don't interfere with typing). if set, send only on return/enter or clicking magnifying search button
     * @return The converted Objective-C result.
     */
        bool sends_whole_search_string() const;
        /**
     * @brief Sets the `sendsWholeSearchString` property of `NSSearchField`.
     * @details if clear, send action on each key stroke (after sufficient amount of time so we don't interfere with typing). if set, send only on return/enter or clicking magnifying search button
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_sends_whole_search_string(bool value) const;
        /// @brief Signal for the delegate/data-source method behind `did_start_searching`; connect a callback with `did_start_searching().connect(...)`.
        Signal<SearchField, void()> did_start_searching() const
        {
            return Signal<SearchField, void()>(handle(), "did_start_searching");
        }
        /// @brief Signal for the delegate/data-source method behind `did_end_searching`; connect a callback with `did_end_searching().connect(...)`.
        Signal<SearchField, void()> did_end_searching() const
        {
            return Signal<SearchField, void()>(handle(), "did_end_searching");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
