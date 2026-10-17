#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Number;

    /**
     * @brief C++ handle for the Objective-C class `NSPresentationIntent` (Foundation).
     * @details A type that contains the Markdown formatting for blocks of text, like paragraphs, lists, code blocks, and parts of tables. An ''NSPresentationIntent'' object stores the Markdown semantics for a range of characters in an attributed string. When parsing Markdown into an attributed string, the system sets the value of the ''NSAttributedString/Key/presentationIntentAttributeName'' attribute to an instance of this class. When displaying your string in system views, the system applies a default visual style to match the corresponding information in this type. To replace the system's default formatting, remove these attributes from your attributed string and apply the formatting you want.
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
     * @details Creates a block quote intent with the provided information. - Parameters: - identity: The unique identifier for the intent. - parent: The parent intent of the block quote. - Returns: A new intent with the kind set to 'NSPresentationIntentKindBlockQuote'.
     * @param identity Argument converted to the Objective-C parameter of the same role.
     * @param parent Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PresentationIntent block_quote_intent_with_identity(std::int64_t identity, const PresentationIntent& parent);
        /**
     * @brief Calls `+[NSPresentationIntent codeBlockIntentWithIdentity:languageHint:nestedInsideIntent:]`.
     * @details Creates a code-block intent with the provided information. - Parameters: - identity: The unique identifier for the intent. - languageHint: The programming language for the code listing. - parent: The parent intent of the code block. - Returns: A new intent with the kind set to 'NSPresentationIntentKindCodeBlock'.
     * @param identity Argument converted to the Objective-C parameter of the same role.
     * @param language_hint Argument converted to the Objective-C parameter of the same role.
     * @param parent Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PresentationIntent code_block_intent_with_identity(std::int64_t identity, const std::string& language_hint, const PresentationIntent& parent);
        /**
     * @brief Calls `+[NSPresentationIntent headerIntentWithIdentity:level:nestedInsideIntent:]`.
     * @details Creates a header intent with the provided information. - Parameters: - identity: The unique identifier for the intent. - level: The level for the header section. Specify '1' or greater for this parameter. Don't specify '0'. - parent: The parent intent of the header. - Returns: A new intent with the kind set to 'NSPresentationIntentKindHeader'.
     * @param identity Argument converted to the Objective-C parameter of the same role.
     * @param level Argument converted to the Objective-C parameter of the same role.
     * @param parent Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PresentationIntent header_intent_with_identity(std::int64_t identity, std::int64_t level, const PresentationIntent& parent);
        /**
     * @brief Calls `-[NSPresentationIntent isEquivalentToPresentationIntent:]`.
     * @details Returns a Boolean value that indicates whether the current intent is equivalent to the specified intent. Two intents are equivalent if their attributes match. This method doesn't consider the 'identity' property of the intents when determining their equivalence. - Parameter other: The other intent to use in the comparison. - Returns: 'YES' if the current intent is equivalent to the specified intent, or 'NO' if it isn't.
     * @param other Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_equivalent_to_presentation_intent(const PresentationIntent& other) const;
        /**
     * @brief Calls `+[NSPresentationIntent listItemIntentWithIdentity:ordinal:nestedInsideIntent:]`.
     * @details Creates a list item intent with the provided information. - Parameters: - identity: The unique identifier for the intent. - ordinal: The ordinal number of the list item. - parent: The parent intent of the list item. - Returns: A new intent with the kind set to 'NSPresentationIntentKindListItem'.
     * @param identity Argument converted to the Objective-C parameter of the same role.
     * @param ordinal Argument converted to the Objective-C parameter of the same role.
     * @param parent Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PresentationIntent list_item_intent_with_identity(std::int64_t identity, std::int64_t ordinal, const PresentationIntent& parent);
        /**
     * @brief Calls `+[NSPresentationIntent orderedListIntentWithIdentity:nestedInsideIntent:]`.
     * @details Creates an ordered list intent with the provided information. - Parameters: - identity: The unique identifier for the intent. - parent: The parent intent of the ordered list. - Returns: A new intent with the kind set to 'NSPresentationIntentKindOrderedList'.
     * @param identity Argument converted to the Objective-C parameter of the same role.
     * @param parent Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PresentationIntent ordered_list_intent_with_identity(std::int64_t identity, const PresentationIntent& parent);
        /**
     * @brief Calls `+[NSPresentationIntent paragraphIntentWithIdentity:nestedInsideIntent:]`.
     * @details Creates a paragraph intent with the provided information. - Parameters: - identity: The unique identifier for the intent. - parent: The parent intent of the paragraph. - Returns: A new intent with the kind set to 'NSPresentationIntentKindParagraph'.
     * @param identity Argument converted to the Objective-C parameter of the same role.
     * @param parent Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PresentationIntent paragraph_intent_with_identity(std::int64_t identity, const PresentationIntent& parent);
        /**
     * @brief Calls `+[NSPresentationIntent tableCellIntentWithIdentity:column:nestedInsideIntent:]`.
     * @details Creates a table cell intent with the provided information. - Parameters: - identity: The unique identifier for the intent. - column: The column number (0-based). - parent: The parent intent of the table cell. - Returns: A new intent with the kind set to 'NSPresentationIntentKindTableCell'.
     * @param identity Argument converted to the Objective-C parameter of the same role.
     * @param column Argument converted to the Objective-C parameter of the same role.
     * @param parent Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PresentationIntent table_cell_intent_with_identity(std::int64_t identity, std::int64_t column, const PresentationIntent& parent);
        /**
     * @brief Calls `+[NSPresentationIntent tableHeaderRowIntentWithIdentity:nestedInsideIntent:]`.
     * @details Creates a table header row intent with the provided information. - Parameters: - identity: The unique identifier for the intent. - parent: The parent intent of the table header row. - Returns: A new intent with the kind set to 'NSPresentationIntentKindTableHeaderRow'.
     * @param identity Argument converted to the Objective-C parameter of the same role.
     * @param parent Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PresentationIntent table_header_row_intent_with_identity(std::int64_t identity, const PresentationIntent& parent);
        /**
     * @brief Calls `+[NSPresentationIntent tableIntentWithIdentity:columnCount:alignments:nestedInsideIntent:]`.
     * @details Creates a table intent with the provided information. - Parameters: - identity: The unique identifier for the intent. - columnCount: The number of columns in the table. - alignments: An array of 'NSNumber' values indicating the alignment of each column. - parent: The parent intent of the table. - Returns: A new intent with the kind set to 'NSPresentationIntentKindTable'.
     * @param identity Argument converted to the Objective-C parameter of the same role.
     * @param column_count Argument converted to the Objective-C parameter of the same role.
     * @param alignments Argument converted to the Objective-C parameter of the same role.
     * @param parent Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PresentationIntent table_intent_with_identity(std::int64_t identity, std::int64_t column_count, const std::vector<Number>& alignments, const PresentationIntent& parent);
        /**
     * @brief Calls `+[NSPresentationIntent tableRowIntentWithIdentity:row:nestedInsideIntent:]`.
     * @details Creates a table row intent with the provided information. - Parameters: - identity: The unique identifier for the intent. - row: The row number (0-based). - parent: The parent intent of the table row. - Returns: A new intent with the kind set to 'NSPresentationIntentKindTableRow'.
     * @param identity Argument converted to the Objective-C parameter of the same role.
     * @param row Argument converted to the Objective-C parameter of the same role.
     * @param parent Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PresentationIntent table_row_intent_with_identity(std::int64_t identity, std::int64_t row, const PresentationIntent& parent);
        /**
     * @brief Calls `+[NSPresentationIntent thematicBreakIntentWithIdentity:nestedInsideIntent:]`.
     * @details Creates a thematic break intent with the provided information. - Parameters: - identity: The unique identifier for the intent. - parent: The parent intent of the thematic break. - Returns: A new intent with the kind set to 'NSPresentationIntentKindThematicBreak'.
     * @param identity Argument converted to the Objective-C parameter of the same role.
     * @param parent Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PresentationIntent thematic_break_intent_with_identity(std::int64_t identity, const PresentationIntent& parent);
        /**
     * @brief Calls `+[NSPresentationIntent unorderedListIntentWithIdentity:nestedInsideIntent:]`.
     * @details Creates an unordered list intent with the provided information. - Parameters: - identity: The unique identifier for the intent. - parent: The parent intent of the unordered list. - Returns: A new intent with the kind set to 'NSPresentationIntentKindUnorderedList'.
     * @param identity Argument converted to the Objective-C parameter of the same role.
     * @param parent Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PresentationIntent unordered_list_intent_with_identity(std::int64_t identity, const PresentationIntent& parent);
        /**
     * @brief Returns the `column` property of `NSPresentationIntent`.
     * @details The column number to which the cell belongs. The value of this property is '0'-based, with the first column at '0', the second column at '1', and so on. If the intent is not a cell, this value is '0'.
     * @return The converted Objective-C result.
     */
        std::int64_t column() const;
        /**
     * @brief Returns the `columnAlignments` property of `NSPresentationIntent`.
     * @details The alignments for the columns in a table. If the intent is not a table, the value of this property is 'nil'.
     * @return The converted Objective-C result.
     */
        std::vector<Number> column_alignments() const;
        /**
     * @brief Returns the `columnCount` property of `NSPresentationIntent`.
     * @details The number of columns in a table. If the intent is not a table, the value of this property is '0'.
     * @return The converted Objective-C result.
     */
        std::int64_t column_count() const;
        /**
     * @brief Returns the `headerLevel` property of `NSPresentationIntent`.
     * @details The level of a header section. This value corresponds to the number of hash marks ('\#') associated with the header. If the intent is not a header, the value of this property is '0'.
     * @return The converted Objective-C result.
     */
        std::int64_t header_level() const;
        /**
     * @brief Returns the `identity` property of `NSPresentationIntent`.
     * @details A unique identifier for the intent in the document. Use the value in this property to disambiguate attributes that apply to contiguous text. For example, you might use it to differentiate between two headers in a row with the same level.
     * @return The converted Objective-C result.
     */
        std::int64_t identity() const;
        /**
     * @brief Returns the `indentationLevel` property of `NSPresentationIntent`.
     * @details The indentation level of the intent. The initial list has an indentation level of '0'. Each time you nest a new list, the indentation level increases by '1'. All elements within the same list have the same indentation level. Text outside list intents has an indentation level of '0'.
     * @return The converted Objective-C result.
     */
        std::int64_t indentation_level() const;
        /**
     * @brief Returns the `intentKind` property of `NSPresentationIntent`.
     * @details The type of the intent.
     * @return The converted Objective-C result.
     */
        PresentationIntentKind intent_kind() const;
        /**
     * @brief Returns the `languageHint` property of `NSPresentationIntent`.
     * @details The language associated with the code listing. If the intent is not a code block, the value of this property is 'nil'.
     * @return The converted Objective-C result.
     */
        std::string language_hint() const;
        /**
     * @brief Returns the `ordinal` property of `NSPresentationIntent`.
     * @details The number for an item in an ordered list. If the intent is not a list, the value of this property is '0'.
     * @return The converted Objective-C result.
     */
        std::int64_t ordinal() const;
        /**
     * @brief Returns the `parentIntent` property of `NSPresentationIntent`.
     * @details The parent of the current intent.
     * @return The converted Objective-C result.
     */
        PresentationIntent parent_intent() const;
        /**
     * @brief Returns the `row` property of `NSPresentationIntent`.
     * @details The row number to which this cell belongs. The value of this property is '0'-based, with the first row at '0', the second row at '1', and so on. If the intent is not a cell, this value is '0'.
     * @return The converted Objective-C result.
     */
        std::int64_t row() const;
    };
}
