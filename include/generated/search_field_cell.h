#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/text_field_cell.h"
#include "types.h"

namespace cocoon
{
    class ButtonCell;
    class Menu;

    /**
     * @brief C++ handle for the Objective-C class `NSSearchFieldCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TextFieldCell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SearchFieldCell search_field_cell;
     * search_field_cell.set_cancel_button_cell(cocoon::ButtonCell());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SearchFieldCell search_field_cell{};
     * search_field_cell.set_cancel_button_cell(cocoon::ButtonCell());
     * auto cancel_button_cell = search_field_cell.cancel_button_cell();
     * search_field_cell.set_maximum_recents(1);
     * auto maximum_recents = search_field_cell.maximum_recents();
     * search_field_cell.set_recent_searches({"a", "b"});
     * auto recent_searches = search_field_cell.recent_searches();
     * search_field_cell.cancel_button_rect_for_bounds({{0, 0}, {100, 100}});
     * search_field_cell.reset_cancel_button_cell();
     * search_field_cell.reset_search_button_cell();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssearchfieldcell
     */
    class SearchFieldCell : public TextFieldCell
    {
    public:
        /// @brief Creates a new `NSSearchFieldCell` instance and returns a handle to it.
        explicit SearchFieldCell(const std::string& string);
        /// @brief Creates a new `NSSearchFieldCell` instance and returns a handle to it.
        explicit SearchFieldCell();
        /// @brief Creates a null handle that refers to no native object.
        SearchFieldCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SearchFieldCell(Adopt adopt);
        /**
     * @brief Calls `-[NSSearchFieldCell cancelButtonRectForBounds:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect cancel_button_rect_for_bounds(const Rect& rect) const;
        /**
     * @brief Calls `-[NSSearchFieldCell resetCancelButtonCell]`.
     */
        void reset_cancel_button_cell() const;
        /**
     * @brief Calls `-[NSSearchFieldCell resetSearchButtonCell]`.
     */
        void reset_search_button_cell() const;
        /**
     * @brief Calls `-[NSSearchFieldCell searchButtonRectForBounds:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect search_button_rect_for_bounds(const Rect& rect) const;
        /**
     * @brief Calls `-[NSSearchFieldCell searchTextRectForBounds:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect search_text_rect_for_bounds(const Rect& rect) const;
        /**
     * @brief Returns the `cancelButtonCell` property of `NSSearchFieldCell`.
     * @return The converted Objective-C result.
     */
        ButtonCell cancel_button_cell() const;
        /**
     * @brief Sets the `cancelButtonCell` property of `NSSearchFieldCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_cancel_button_cell(const ButtonCell& value) const;
        /**
     * @brief Returns the `maximumRecents` property of `NSSearchFieldCell`.
     * @return The converted Objective-C result.
     */
        std::int64_t maximum_recents() const;
        /**
     * @brief Sets the `maximumRecents` property of `NSSearchFieldCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_recents(std::int64_t value) const;
        /**
     * @brief Returns the `recentSearches` property of `NSSearchFieldCell`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> recent_searches() const;
        /**
     * @brief Sets the `recentSearches` property of `NSSearchFieldCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_recent_searches(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `recentsAutosaveName` property of `NSSearchFieldCell`.
     * @return The converted Objective-C result.
     */
        std::string recents_autosave_name() const;
        /**
     * @brief Sets the `recentsAutosaveName` property of `NSSearchFieldCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_recents_autosave_name(const std::string& value) const;
        /**
     * @brief Returns the `searchButtonCell` property of `NSSearchFieldCell`.
     * @return The converted Objective-C result.
     */
        ButtonCell search_button_cell() const;
        /**
     * @brief Sets the `searchButtonCell` property of `NSSearchFieldCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_search_button_cell(const ButtonCell& value) const;
        /**
     * @brief Returns the `searchMenuTemplate` property of `NSSearchFieldCell`.
     * @return The converted Objective-C result.
     */
        Menu search_menu_template() const;
        /**
     * @brief Sets the `searchMenuTemplate` property of `NSSearchFieldCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_search_menu_template(const Menu& value) const;
        /**
     * @brief Returns the `sendsSearchStringImmediately` property of `NSSearchFieldCell`.
     * @return The converted Objective-C result.
     */
        bool sends_search_string_immediately() const;
        /**
     * @brief Sets the `sendsSearchStringImmediately` property of `NSSearchFieldCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_sends_search_string_immediately(bool value) const;
        /**
     * @brief Returns the `sendsWholeSearchString` property of `NSSearchFieldCell`.
     * @return The converted Objective-C result.
     */
        bool sends_whole_search_string() const;
        /**
     * @brief Sets the `sendsWholeSearchString` property of `NSSearchFieldCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_sends_whole_search_string(bool value) const;
    };
}
