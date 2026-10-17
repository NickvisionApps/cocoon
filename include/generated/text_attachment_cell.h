#pragma once

#include "generated/cell.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSTextAttachmentCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Cell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextAttachmentCell text_attachment_cell;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextattachmentcell
     */
    class TextAttachmentCell : public Cell
    {
    public:
        /// @brief Creates a new `NSTextAttachmentCell` instance and returns a handle to it.
        explicit TextAttachmentCell();
        /// @brief Creates a null handle that refers to no native object.
        TextAttachmentCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextAttachmentCell(Adopt adopt);
    };
}
