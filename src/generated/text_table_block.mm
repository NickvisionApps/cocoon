#include "generated/text_table_block.h"
#include "internal.h"

namespace cocoon
{
    TextTableBlock::TextTableBlock(const TextTable& table, std::int64_t row, std::int64_t row_span, std::int64_t column, std::int64_t column_span) : TextTableBlock(Adopt{cocoon::internal::retain([[::NSTextTableBlock alloc] initWithTable:cocoon::internal::native<::NSTextTable>(table) startingRow:static_cast<::NSInteger>(row) rowSpan:static_cast<::NSInteger>(row_span) startingColumn:static_cast<::NSInteger>(column) columnSpan:static_cast<::NSInteger>(column_span)])})
    {
    }

    TextTableBlock::TextTableBlock() : TextTableBlock(Adopt{cocoon::internal::retain([[::NSTextTableBlock alloc] init])})
    {
    }

    TextTableBlock::TextTableBlock(std::nullptr_t) : TextBlock(nullptr)
    {
    }

    TextTableBlock::TextTableBlock(Adopt adopt) : TextBlock(adopt)
    {
    }

    std::int64_t TextTableBlock::column_span() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTextTableBlock>(this) columnSpan]);
    }

    std::int64_t TextTableBlock::row_span() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTextTableBlock>(this) rowSpan]);
    }

    std::int64_t TextTableBlock::starting_column() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTextTableBlock>(this) startingColumn]);
    }

    std::int64_t TextTableBlock::starting_row() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTextTableBlock>(this) startingRow]);
    }

    TextTable TextTableBlock::table() const
    {
        return cocoon::internal::wrap<TextTable>([cocoon::internal::ns<::NSTextTableBlock>(this) table]);
    }
}
