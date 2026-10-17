#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/touch_bar_item.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSCandidateListTouchBarItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TouchBarItem.
     * Use the typed template @ref CandidateListTouchBarItem to supply CandidateType.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CandidateListTouchBarItemBase candidate_list_touch_bar_item_base(nullptr);  // null handle; instances normally come from other API calls
     * candidate_list_touch_bar_item_base.set_allows_collapsing(true);
     * candidate_list_touch_bar_item_base.begin_selecting_candidate_at_index().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CandidateListTouchBarItemBase candidate_list_touch_bar_item_base(nullptr);
     * candidate_list_touch_bar_item_base.set_allows_collapsing(true);
     * auto allows_collapsing = candidate_list_touch_bar_item_base.allows_collapsing();
     * candidate_list_touch_bar_item_base.set_allows_text_input_context_candidates(true);
     * auto allows_text_input_context_candidates = candidate_list_touch_bar_item_base.allows_text_input_context_candidates();
     * candidate_list_touch_bar_item_base.set_client(cocoon::View());
     * auto client = candidate_list_touch_bar_item_base.client();
     * candidate_list_touch_bar_item_base.update_with_insertion_point_visibility(true);
     * candidate_list_touch_bar_item_base.begin_selecting_candidate_at_index().connect([](std::int64_t a0) {});
     * candidate_list_touch_bar_item_base.change_selection_from_candidate_at_index_to_index().connect([](std::int64_t a0, std::int64_t a1) {});
     * candidate_list_touch_bar_item_base.end_selecting_candidate_at_index().connect([](std::int64_t a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscandidatelisttouchbaritem
     */
    class CandidateListTouchBarItemBase : public TouchBarItem
    {
    public:
        CandidateListTouchBarItemBase();
        /// @brief Creates a null handle that refers to no native object.
        CandidateListTouchBarItemBase(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CandidateListTouchBarItemBase(Adopt adopt);
        using TouchBarItem::customization_label;
        /**
     * @brief Calls `-[NSCandidateListTouchBarItem setCandidates:forSelectedRange:inString:]`.
     * @param candidates Argument converted to the Objective-C parameter of the same role.
     * @param selected_range Argument converted to the Objective-C parameter of the same role.
     * @param original_string Argument converted to the Objective-C parameter of the same role.
     */
        void set_candidates(const std::vector<Object>& candidates, const Range& selected_range, const std::string& original_string) const;
        /**
     * @brief Calls `-[NSCandidateListTouchBarItem updateWithInsertionPointVisibility:]`.
     * @param is_visible Argument converted to the Objective-C parameter of the same role.
     */
        void update_with_insertion_point_visibility(bool is_visible) const;
        /**
     * @brief Returns the `allowsCollapsing` property of `NSCandidateListTouchBarItem`.
     * @return The converted Objective-C result.
     */
        bool allows_collapsing() const;
        /**
     * @brief Sets the `allowsCollapsing` property of `NSCandidateListTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_collapsing(bool value) const;
        /**
     * @brief Returns the `allowsTextInputContextCandidates` property of `NSCandidateListTouchBarItem`.
     * @return The converted Objective-C result.
     */
        bool allows_text_input_context_candidates() const;
        /**
     * @brief Sets the `allowsTextInputContextCandidates` property of `NSCandidateListTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_text_input_context_candidates(bool value) const;
        /**
     * @brief Returns the `attributedStringForCandidate` property of `NSCandidateListTouchBarItem`.
     * @return The converted Objective-C result.
     */
        std::function<AttributedString(Object, std::int64_t)> attributed_string_for_candidate() const;
        /**
     * @brief Sets the `attributedStringForCandidate` property of `NSCandidateListTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_string_for_candidate(std::function<AttributedString(Object, std::int64_t)> value) const;
        /**
     * @brief Returns the `candidateListVisible` property of `NSCandidateListTouchBarItem`.
     * @return The converted Objective-C result.
     */
        bool is_candidate_list_visible() const;
        /**
     * @brief Returns the `candidates` property of `NSCandidateListTouchBarItem`.
     * @return The converted Objective-C result.
     */
        std::vector<Object> candidates() const;
        /**
     * @brief Returns the `client` property of `NSCandidateListTouchBarItem`.
     * @return The converted Objective-C result.
     */
        View client() const;
        /**
     * @brief Sets the `client` property of `NSCandidateListTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_client(const View& value) const;
        /**
     * @brief Returns the `collapsed` property of `NSCandidateListTouchBarItem`.
     * @return The converted Objective-C result.
     */
        bool is_collapsed() const;
        /**
     * @brief Sets the `collapsed` property of `NSCandidateListTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_collapsed(bool value) const;
        /**
     * @brief Returns the `customizationLabel` property of `NSCandidateListTouchBarItem`.
     * @return The converted Objective-C result.
     */
        std::string customization_label() const;
        /**
     * @brief Sets the `customizationLabel` property of `NSCandidateListTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_customization_label(const std::string& value) const;
        /// @brief Signal for the delegate/data-source method behind `begin_selecting_candidate_at_index`; connect a callback with `begin_selecting_candidate_at_index().connect(...)`.
        Signal<CandidateListTouchBarItemBase, void(std::int64_t)> begin_selecting_candidate_at_index() const
        {
            return Signal<CandidateListTouchBarItemBase, void(std::int64_t)>(handle(), "begin_selecting_candidate_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `change_selection_from_candidate_at_index_to_index`; connect a callback with `change_selection_from_candidate_at_index_to_index().connect(...)`.
        Signal<CandidateListTouchBarItemBase, void(std::int64_t, std::int64_t)> change_selection_from_candidate_at_index_to_index() const
        {
            return Signal<CandidateListTouchBarItemBase, void(std::int64_t, std::int64_t)>(handle(), "change_selection_from_candidate_at_index_to_index");
        }
        /// @brief Signal for the delegate/data-source method behind `end_selecting_candidate_at_index`; connect a callback with `end_selecting_candidate_at_index().connect(...)`.
        Signal<CandidateListTouchBarItemBase, void(std::int64_t)> end_selecting_candidate_at_index() const
        {
            return Signal<CandidateListTouchBarItemBase, void(std::int64_t)>(handle(), "end_selecting_candidate_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `changed_candidate_list_visibility`; connect a callback with `changed_candidate_list_visibility().connect(...)`.
        Signal<CandidateListTouchBarItemBase, void(bool)> changed_candidate_list_visibility() const
        {
            return Signal<CandidateListTouchBarItemBase, void(bool)>(handle(), "changed_candidate_list_visibility");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };

    template <class CandidateType>
    class CandidateListTouchBarItem : public CandidateListTouchBarItemBase
    {
    public:
        using CandidateListTouchBarItemBase::CandidateListTouchBarItemBase;
        CandidateListTouchBarItem() : CandidateListTouchBarItemBase()
        {
        }
        CandidateListTouchBarItem(const CandidateListTouchBarItemBase& other) : CandidateListTouchBarItemBase(other)
        {
        }
        using CandidateListTouchBarItemBase::allows_collapsing;
        using CandidateListTouchBarItemBase::allows_text_input_context_candidates;
        using CandidateListTouchBarItemBase::attributed_string_for_candidate;
        using CandidateListTouchBarItemBase::begin_selecting_candidate_at_index;
        using CandidateListTouchBarItemBase::candidates;
        using CandidateListTouchBarItemBase::change_selection_from_candidate_at_index_to_index;
        using CandidateListTouchBarItemBase::changed_candidate_list_visibility;
        using CandidateListTouchBarItemBase::client;
        using CandidateListTouchBarItemBase::customization_label;
        using CandidateListTouchBarItemBase::end_selecting_candidate_at_index;
        using CandidateListTouchBarItemBase::is_candidate_list_visible;
        using CandidateListTouchBarItemBase::is_collapsed;
        using CandidateListTouchBarItemBase::set_allows_collapsing;
        using CandidateListTouchBarItemBase::set_allows_text_input_context_candidates;
        using CandidateListTouchBarItemBase::set_attributed_string_for_candidate;
        using CandidateListTouchBarItemBase::set_candidates;
        using CandidateListTouchBarItemBase::set_client;
        using CandidateListTouchBarItemBase::set_collapsed;
        using CandidateListTouchBarItemBase::set_customization_label;
        using CandidateListTouchBarItemBase::update_with_insertion_point_visibility;
        auto set_candidates(const std::vector<CandidateType>& candidates, const Range& selected_range, const std::string& original_string) const
        {
            CandidateListTouchBarItemBase::set_candidates(cocoon::box_all(candidates), selected_range, original_string);
        }
        auto candidates() const
        {
            return cocoon::unbox_all<CandidateType>(CandidateListTouchBarItemBase::candidates());
        }
    };
}
