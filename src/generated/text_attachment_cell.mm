#include "generated/text_attachment_cell.h"
#include "internal.h"

namespace cocoon
{
    TextAttachmentCell::TextAttachmentCell() : TextAttachmentCell(Adopt{cocoon::internal::retain([[::NSTextAttachmentCell alloc] init])})
    {
    }

    TextAttachmentCell::TextAttachmentCell(std::nullptr_t) : Cell(nullptr)
    {
    }

    TextAttachmentCell::TextAttachmentCell(Adopt adopt) : Cell(adopt)
    {
    }
}
