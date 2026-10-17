#include "generated/pdf_image_rep.h"
#include "internal.h"

namespace cocoon
{
    PDFImageRep::PDFImageRep(const std::vector<std::uint8_t>& pdf_data) : PDFImageRep(Adopt{cocoon::internal::retain([[::NSPDFImageRep alloc] initWithData:cocoon::internal::to_data(pdf_data)])})
    {
    }

    PDFImageRep::PDFImageRep() : PDFImageRep(Adopt{cocoon::internal::retain([[::NSPDFImageRep alloc] init])})
    {
    }

    PDFImageRep::PDFImageRep(std::nullptr_t) : ImageRep(nullptr)
    {
    }

    PDFImageRep::PDFImageRep(Adopt adopt) : ImageRep(adopt)
    {
    }

    PDFImageRep PDFImageRep::image_rep_with_data(const std::vector<std::uint8_t>& pdf_data)
    {
        return cocoon::internal::wrap<PDFImageRep>([::NSPDFImageRep imageRepWithData:cocoon::internal::to_data(pdf_data)]);
    }

    std::vector<std::uint8_t> PDFImageRep::pdf_representation() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSPDFImageRep>(this) PDFRepresentation]);
    }

    Rect PDFImageRep::bounds() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPDFImageRep>(this) bounds]);
    }

    std::int64_t PDFImageRep::current_page() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPDFImageRep>(this) currentPage]);
    }

    void PDFImageRep::set_current_page(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSPDFImageRep>(this) setCurrentPage:static_cast<::NSInteger>(value)];
    }

    std::int64_t PDFImageRep::page_count() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPDFImageRep>(this) pageCount]);
    }
}
