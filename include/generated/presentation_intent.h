#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Number;

    /**
     * @brief C++ handle for the Objective-C class `NSPresentationIntent` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PresentationIntent presentation_intent(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PresentationIntent presentation_intent(nullptr);
     * auto made_0 = cocoon::PresentationIntent::block_quote_intent_with_identity(1, cocoon::PresentationIntent());
     * auto made_1 = cocoon::PresentationIntent::code_block_intent_with_identity(1, "text", cocoon::PresentationIntent());
     * presentation_intent.is_equivalent_to_presentation_intent(cocoon::PresentationIntent());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nspresentationintent
     */
    class PresentationIntent : public Object
    {
    public:
        PresentationIntent();
        /// @brief Creates a null handle that refers to no native object.
        PresentationIntent(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PresentationIntent(Adopt adopt);
        /**
         * @brief Calls `+[NSPresentationIntent blockQuoteIntentWithIdentity:nestedInsideIntent:]`.
         * @param identity Argument converted to the Objective-C parameter of the same role.
         * @param parent Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static PresentationIntent block_quote_intent_with_identity(std::int64_t identity, const PresentationIntent& parent);
        /**
         * @brief Calls `+[NSPresentationIntent codeBlockIntentWithIdentity:languageHint:nestedInsideIntent:]`.
         * @param identity Argument converted to the Objective-C parameter of the same role.
         * @param language_hint Argument converted to the Objective-C parameter of the same role.
         * @param parent Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static PresentationIntent code_block_intent_with_identity(std::int64_t identity, const std::string& language_hint, const PresentationIntent& parent);
        /**
         * @brief Calls `+[NSPresentationIntent headerIntentWithIdentity:level:nestedInsideIntent:]`.
         * @param identity Argument converted to the Objective-C parameter of the same role.
         * @param level Argument converted to the Objective-C parameter of the same role.
         * @param parent Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static PresentationIntent header_intent_with_identity(std::int64_t identity, std::int64_t level, const PresentationIntent& parent);
        /**
         * @brief Calls `-[NSPresentationIntent isEquivalentToPresentationIntent:]`.
         * @details Returns 'YES' if this intent is equivalent to the other presentation intent. Equivalence is the same as equality except that identity is not taken into account.
         * @param other Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_equivalent_to_presentation_intent(const PresentationIntent& other) const;
        /**
         * @brief Calls `+[NSPresentationIntent listItemIntentWithIdentity:ordinal:nestedInsideIntent:]`.
         * @param identity Argument converted to the Objective-C parameter of the same role.
         * @param ordinal Argument converted to the Objective-C parameter of the same role.
         * @param parent Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static PresentationIntent list_item_intent_with_identity(std::int64_t identity, std::int64_t ordinal, const PresentationIntent& parent);
        /**
         * @brief Calls `+[NSPresentationIntent orderedListIntentWithIdentity:nestedInsideIntent:]`.
         * @param identity Argument converted to the Objective-C parameter of the same role.
         * @param parent Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static PresentationIntent ordered_list_intent_with_identity(std::int64_t identity, const PresentationIntent& parent);
        /**
         * @brief Calls `+[NSPresentationIntent paragraphIntentWithIdentity:nestedInsideIntent:]`.
         * @param identity Argument converted to the Objective-C parameter of the same role.
         * @param parent Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static PresentationIntent paragraph_intent_with_identity(std::int64_t identity, const PresentationIntent& parent);
        /**
         * @brief Calls `+[NSPresentationIntent tableCellIntentWithIdentity:column:nestedInsideIntent:]`.
         * @param identity Argument converted to the Objective-C parameter of the same role.
         * @param column Argument converted to the Objective-C parameter of the same role.
         * @param parent Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static PresentationIntent table_cell_intent_with_identity(std::int64_t identity, std::int64_t column, const PresentationIntent& parent);
        /**
         * @brief Calls `+[NSPresentationIntent tableHeaderRowIntentWithIdentity:nestedInsideIntent:]`.
         * @param identity Argument converted to the Objective-C parameter of the same role.
         * @param parent Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static PresentationIntent table_header_row_intent_with_identity(std::int64_t identity, const PresentationIntent& parent);
        /**
         * @brief Calls `+[NSPresentationIntent tableIntentWithIdentity:columnCount:alignments:nestedInsideIntent:]`.
         * @param identity Argument converted to the Objective-C parameter of the same role.
         * @param column_count Argument converted to the Objective-C parameter of the same role.
         * @param alignments Argument converted to the Objective-C parameter of the same role.
         * @param parent Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static PresentationIntent table_intent_with_identity(std::int64_t identity, std::int64_t column_count, const std::vector<Number>& alignments, const PresentationIntent& parent);
        /**
         * @brief Calls `+[NSPresentationIntent tableRowIntentWithIdentity:row:nestedInsideIntent:]`.
         * @param identity Argument converted to the Objective-C parameter of the same role.
         * @param row Argument converted to the Objective-C parameter of the same role.
         * @param parent Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static PresentationIntent table_row_intent_with_identity(std::int64_t identity, std::int64_t row, const PresentationIntent& parent);
        /**
         * @brief Calls `+[NSPresentationIntent thematicBreakIntentWithIdentity:nestedInsideIntent:]`.
         * @param identity Argument converted to the Objective-C parameter of the same role.
         * @param parent Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static PresentationIntent thematic_break_intent_with_identity(std::int64_t identity, const PresentationIntent& parent);
        /**
         * @brief Calls `+[NSPresentationIntent unorderedListIntentWithIdentity:nestedInsideIntent:]`.
         * @param identity Argument converted to the Objective-C parameter of the same role.
         * @param parent Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static PresentationIntent unordered_list_intent_with_identity(std::int64_t identity, const PresentationIntent& parent);
        /**
         * @brief Returns the `column` property of `NSPresentationIntent`.
         * @details The column to which this cell belongs (0-based). If the intent is not a cell, this value is 0.
         * @return The converted Objective-C result.
         */
        std::int64_t column() const;
        /**
         * @brief Returns the `columnAlignments` property of `NSPresentationIntent`.
         * @details If the intent is not a table, this value is 'nil'.
         * @return The converted Objective-C result.
         */
        std::vector<Number> column_alignments() const;
        /**
         * @brief Returns the `columnCount` property of `NSPresentationIntent`.
         * @details If the intent is not a table, this value is 0.
         * @return The converted Objective-C result.
         */
        std::int64_t column_count() const;
        /**
         * @brief Returns the `headerLevel` property of `NSPresentationIntent`.
         * @details If the intent is not a header, this value is 0.
         * @return The converted Objective-C result.
         */
        std::int64_t header_level() const;
        /**
         * @brief Returns the `identity` property of `NSPresentationIntent`.
         * @details An integer value which uniquely identifies this intent in the document. Identity disambiguates attributes which apply to contiguous text -- for example, two headers in a row with the same level. It can also be used to track the location in an attributed string of a particular part of a document, even after mutation.
         * @return The converted Objective-C result.
         */
        std::int64_t identity() const;
        /**
         * @brief Returns the `indentationLevel` property of `NSPresentationIntent`.
         * @details The indentation level of this intent. Each nested list increases the indentation level by one; all elements within the same list (and not then nested into a child list intent) have the same indentation level. Text outside list intents has an indentation level of 0.
         * @return The converted Objective-C result.
         */
        std::int64_t indentation_level() const;
        /**
         * @brief Returns the `intentKind` property of `NSPresentationIntent`.
         * @return The converted Objective-C result.
         */
        PresentationIntentKind intent_kind() const;
        /**
         * @brief Returns the `languageHint` property of `NSPresentationIntent`.
         * @details If the intent is not a code block, this value is 'nil'.
         * @return The converted Objective-C result.
         */
        std::string language_hint() const;
        /**
         * @brief Returns the `ordinal` property of `NSPresentationIntent`.
         * @details If the intent is not a list, this value is 0.
         * @return The converted Objective-C result.
         */
        std::int64_t ordinal() const;
        /**
         * @brief Returns the `parentIntent` property of `NSPresentationIntent`.
         * @return The converted Objective-C result.
         */
        PresentationIntent parent_intent() const;
        /**
         * @brief Returns the `row` property of `NSPresentationIntent`.
         * @details The row to which this cell belongs (0-based). If the intent is not a row, this value is 0. Header rows are always row 0. If the table has more rows, those start at row 1.
         * @return The converted Objective-C result.
         */
        std::int64_t row() const;
    };
}
