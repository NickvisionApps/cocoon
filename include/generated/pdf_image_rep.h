#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/image_rep.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSPDFImageRep` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ImageRep.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PDFImageRep pdf_image_rep;
     * pdf_image_rep.set_current_page(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PDFImageRep pdf_image_rep{};
     * pdf_image_rep.set_current_page(1);
     * auto current_page = pdf_image_rep.current_page();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspdfimagerep
     */
    class PDFImageRep : public ImageRep
    {
    public:
        /// @brief Creates a new `NSPDFImageRep` instance and returns a handle to it.
        explicit PDFImageRep(const std::vector<std::uint8_t>& pdf_data);
        /// @brief Creates a new `NSPDFImageRep` instance and returns a handle to it.
        explicit PDFImageRep();
        /// @brief Creates a null handle that refers to no native object.
        PDFImageRep(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PDFImageRep(Adopt adopt);
        /**
     * @brief Calls `+[NSPDFImageRep imageRepWithData:]`.
     * @param pdf_data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PDFImageRep image_rep_with_data(const std::vector<std::uint8_t>& pdf_data);
        /**
     * @brief Returns the `PDFRepresentation` property of `NSPDFImageRep`.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> pdf_representation() const;
        /**
     * @brief Returns the `bounds` property of `NSPDFImageRep`.
     * @return The converted Objective-C result.
     */
        Rect bounds() const;
        /**
     * @brief Returns the `currentPage` property of `NSPDFImageRep`.
     * @return The converted Objective-C result.
     */
        std::int64_t current_page() const;
        /**
     * @brief Sets the `currentPage` property of `NSPDFImageRep`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_current_page(std::int64_t value) const;
        /**
     * @brief Returns the `pageCount` property of `NSPDFImageRep`.
     * @return The converted Objective-C result.
     */
        std::int64_t page_count() const;
    };
}
