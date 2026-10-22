#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Menu;

    /**
     * @brief C++ handle for the Objective-C class `NSTextCheckingController` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextCheckingController text_checking_controller(nullptr);  // null handle; instances normally come from other API calls
     * text_checking_controller.set_spell_checker_document_tag(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextCheckingController text_checking_controller(nullptr);
     * text_checking_controller.set_spell_checker_document_tag(1);
     * auto spell_checker_document_tag = text_checking_controller.spell_checker_document_tag();
     * text_checking_controller.did_change_selected_range();
     * text_checking_controller.invalidate();
     * text_checking_controller.update_candidates();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextcheckingcontroller
     */
    class TextCheckingController : public Object
    {
    public:
        /// @brief Creates a new `NSTextCheckingController` instance and returns a handle to it.
        explicit TextCheckingController(const Object& client);
        TextCheckingController();
        /// @brief Creates a null handle that refers to no native object.
        TextCheckingController(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextCheckingController(Adopt adopt);
        /**
         * @brief Calls `-[NSTextCheckingController changeSpelling:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void change_spelling(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextCheckingController checkSpelling:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void check_spelling(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextCheckingController checkTextInDocument:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void check_text_in_document(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextCheckingController checkTextInRange:types:options:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param checking_types Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         */
        void check_text_in_range(const Range& range, std::uint64_t checking_types, const std::map<std::string, Object>& options) const;
        /**
         * @brief Calls `-[NSTextCheckingController checkTextInSelection:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void check_text_in_selection(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextCheckingController considerTextCheckingForRange:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         */
        void consider_text_checking_for_range(const Range& range) const;
        /**
         * @brief Calls `-[NSTextCheckingController didChangeSelectedRange]`.
         */
        void did_change_selected_range() const;
        /**
         * @brief Calls `-[NSTextCheckingController didChangeTextInRange:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         */
        void did_change_text_in_range(const Range& range) const;
        /**
         * @brief Calls `-[NSTextCheckingController ignoreSpelling:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void ignore_spelling(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextCheckingController insertedTextInRange:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         */
        void inserted_text_in_range(const Range& range) const;
        /**
         * @brief Calls `-[NSTextCheckingController invalidate]`.
         */
        void invalidate() const;
        /**
         * @brief Calls `-[NSTextCheckingController menuAtIndex:clickedOnSelection:effectiveRange:]`.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @param clicked_on_selection Argument converted to the Objective-C parameter of the same role.
         * @param effective_range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Menu menu_at_index(std::uint64_t location, bool clicked_on_selection, Range* effective_range) const;
        /**
         * @brief Calls `-[NSTextCheckingController orderFrontSubstitutionsPanel:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void order_front_substitutions_panel(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextCheckingController showGuessPanel:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void show_guess_panel(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextCheckingController updateCandidates]`.
         */
        void update_candidates() const;
        /**
         * @brief Calls `-[NSTextCheckingController validAnnotations]`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> valid_annotations() const;
        /**
         * @brief Returns the `spellCheckerDocumentTag` property of `NSTextCheckingController`.
         * @return The converted Objective-C result.
         */
        std::int64_t spell_checker_document_tag() const;
        /**
         * @brief Sets the `spellCheckerDocumentTag` property of `NSTextCheckingController`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_spell_checker_document_tag(std::int64_t value) const;
    };
}
