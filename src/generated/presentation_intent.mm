#include "generated/presentation_intent.h"
#include "internal.h"

namespace cocoon
{
    PresentationIntent::PresentationIntent() : Object(nullptr)
    {
    }

    PresentationIntent::PresentationIntent(std::nullptr_t) : Object(nullptr)
    {
    }

    PresentationIntent::PresentationIntent(Adopt adopt) : Object(adopt)
    {
    }

    PresentationIntent PresentationIntent::block_quote_intent_with_identity(std::int64_t identity, const PresentationIntent& parent)
    {
        return cocoon::internal::wrap<PresentationIntent>([::NSPresentationIntent blockQuoteIntentWithIdentity:static_cast<::NSInteger>(identity) nestedInsideIntent:cocoon::internal::native<::NSPresentationIntent>(parent)]);
    }

    PresentationIntent PresentationIntent::code_block_intent_with_identity(std::int64_t identity, const std::string& language_hint, const PresentationIntent& parent)
    {
        return cocoon::internal::wrap<PresentationIntent>([::NSPresentationIntent codeBlockIntentWithIdentity:static_cast<::NSInteger>(identity) languageHint:cocoon::internal::to(language_hint) nestedInsideIntent:cocoon::internal::native<::NSPresentationIntent>(parent)]);
    }

    PresentationIntent PresentationIntent::header_intent_with_identity(std::int64_t identity, std::int64_t level, const PresentationIntent& parent)
    {
        return cocoon::internal::wrap<PresentationIntent>([::NSPresentationIntent headerIntentWithIdentity:static_cast<::NSInteger>(identity) level:static_cast<::NSInteger>(level) nestedInsideIntent:cocoon::internal::native<::NSPresentationIntent>(parent)]);
    }

    bool PresentationIntent::is_equivalent_to_presentation_intent(const PresentationIntent& other) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPresentationIntent>(this) isEquivalentToPresentationIntent:cocoon::internal::native<::NSPresentationIntent>(other)]);
    }

    PresentationIntent PresentationIntent::list_item_intent_with_identity(std::int64_t identity, std::int64_t ordinal, const PresentationIntent& parent)
    {
        return cocoon::internal::wrap<PresentationIntent>([::NSPresentationIntent listItemIntentWithIdentity:static_cast<::NSInteger>(identity) ordinal:static_cast<::NSInteger>(ordinal) nestedInsideIntent:cocoon::internal::native<::NSPresentationIntent>(parent)]);
    }

    PresentationIntent PresentationIntent::ordered_list_intent_with_identity(std::int64_t identity, const PresentationIntent& parent)
    {
        return cocoon::internal::wrap<PresentationIntent>([::NSPresentationIntent orderedListIntentWithIdentity:static_cast<::NSInteger>(identity) nestedInsideIntent:cocoon::internal::native<::NSPresentationIntent>(parent)]);
    }

    PresentationIntent PresentationIntent::paragraph_intent_with_identity(std::int64_t identity, const PresentationIntent& parent)
    {
        return cocoon::internal::wrap<PresentationIntent>([::NSPresentationIntent paragraphIntentWithIdentity:static_cast<::NSInteger>(identity) nestedInsideIntent:cocoon::internal::native<::NSPresentationIntent>(parent)]);
    }

    PresentationIntent PresentationIntent::table_cell_intent_with_identity(std::int64_t identity, std::int64_t column, const PresentationIntent& parent)
    {
        return cocoon::internal::wrap<PresentationIntent>([::NSPresentationIntent tableCellIntentWithIdentity:static_cast<::NSInteger>(identity) column:static_cast<::NSInteger>(column) nestedInsideIntent:cocoon::internal::native<::NSPresentationIntent>(parent)]);
    }

    PresentationIntent PresentationIntent::table_header_row_intent_with_identity(std::int64_t identity, const PresentationIntent& parent)
    {
        return cocoon::internal::wrap<PresentationIntent>([::NSPresentationIntent tableHeaderRowIntentWithIdentity:static_cast<::NSInteger>(identity) nestedInsideIntent:cocoon::internal::native<::NSPresentationIntent>(parent)]);
    }

    PresentationIntent PresentationIntent::table_intent_with_identity(std::int64_t identity, std::int64_t column_count, const std::vector<Number>& alignments, const PresentationIntent& parent)
    {
        return cocoon::internal::wrap<PresentationIntent>([::NSPresentationIntent tableIntentWithIdentity:static_cast<::NSInteger>(identity)
                                                                                columnCount:static_cast<::NSInteger>(column_count)
                                                                                 alignments:cocoon::internal::to_array(alignments, [](const Number& e) -> id
                                                                                                         {
                                                                                                             return cocoon::internal::native<::NSNumber>(e);
                                                                                                         })
                                                                         nestedInsideIntent:cocoon::internal::native<::NSPresentationIntent>(parent)]);
    }

    PresentationIntent PresentationIntent::table_row_intent_with_identity(std::int64_t identity, std::int64_t row, const PresentationIntent& parent)
    {
        return cocoon::internal::wrap<PresentationIntent>([::NSPresentationIntent tableRowIntentWithIdentity:static_cast<::NSInteger>(identity) row:static_cast<::NSInteger>(row) nestedInsideIntent:cocoon::internal::native<::NSPresentationIntent>(parent)]);
    }

    PresentationIntent PresentationIntent::thematic_break_intent_with_identity(std::int64_t identity, const PresentationIntent& parent)
    {
        return cocoon::internal::wrap<PresentationIntent>([::NSPresentationIntent thematicBreakIntentWithIdentity:static_cast<::NSInteger>(identity) nestedInsideIntent:cocoon::internal::native<::NSPresentationIntent>(parent)]);
    }

    PresentationIntent PresentationIntent::unordered_list_intent_with_identity(std::int64_t identity, const PresentationIntent& parent)
    {
        return cocoon::internal::wrap<PresentationIntent>([::NSPresentationIntent unorderedListIntentWithIdentity:static_cast<::NSInteger>(identity) nestedInsideIntent:cocoon::internal::native<::NSPresentationIntent>(parent)]);
    }

    std::int64_t PresentationIntent::column() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPresentationIntent>(this) column]);
    }

    std::vector<Number> PresentationIntent::column_alignments() const
    {
        return cocoon::internal::from_array<Number>([cocoon::internal::ns<::NSPresentationIntent>(this) columnAlignments], [](id e) -> Number
                                      {
                                          return cocoon::internal::wrap<Number>((::NSNumber*)e);
                                      });
    }

    std::int64_t PresentationIntent::column_count() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPresentationIntent>(this) columnCount]);
    }

    std::int64_t PresentationIntent::header_level() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPresentationIntent>(this) headerLevel]);
    }

    std::int64_t PresentationIntent::identity() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPresentationIntent>(this) identity]);
    }

    std::int64_t PresentationIntent::indentation_level() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPresentationIntent>(this) indentationLevel]);
    }

    PresentationIntentKind PresentationIntent::intent_kind() const
    {
        return static_cast<PresentationIntentKind>([cocoon::internal::ns<::NSPresentationIntent>(this) intentKind]);
    }

    std::string PresentationIntent::language_hint() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPresentationIntent>(this) languageHint]);
    }

    std::int64_t PresentationIntent::ordinal() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPresentationIntent>(this) ordinal]);
    }

    PresentationIntent PresentationIntent::parent_intent() const
    {
        return cocoon::internal::wrap<PresentationIntent>([cocoon::internal::ns<::NSPresentationIntent>(this) parentIntent]);
    }

    std::int64_t PresentationIntent::row() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPresentationIntent>(this) row]);
    }
}
