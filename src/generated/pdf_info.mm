#include "generated/pdf_info.h"
#include "internal.h"

namespace cocoon
{
    PDFInfo::PDFInfo() : PDFInfo(Adopt{cocoon::internal::retain([[::NSPDFInfo alloc] init])})
    {
    }

    PDFInfo::PDFInfo(std::nullptr_t) : Object(nullptr)
    {
    }

    PDFInfo::PDFInfo(Adopt adopt) : Object(adopt)
    {
    }

    URL PDFInfo::url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSPDFInfo>(this) URL]);
    }

    void PDFInfo::set_url(const URL& value) const
    {
        [cocoon::internal::ns<::NSPDFInfo>(this) setURL:cocoon::internal::native<::NSURL>(value)];
    }

    std::map<std::string, Object> PDFInfo::attributes() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSPDFInfo>(this) attributes], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    bool PDFInfo::is_file_extension_hidden() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPDFInfo>(this) isFileExtensionHidden]);
    }

    void PDFInfo::set_file_extension_hidden(bool value) const
    {
        [cocoon::internal::ns<::NSPDFInfo>(this) setFileExtensionHidden:static_cast<::BOOL>(value)];
    }

    PaperOrientation PDFInfo::orientation() const
    {
        return static_cast<PaperOrientation>([cocoon::internal::ns<::NSPDFInfo>(this) orientation]);
    }

    void PDFInfo::set_orientation(PaperOrientation value) const
    {
        [cocoon::internal::ns<::NSPDFInfo>(this) setOrientation:static_cast<::NSPaperOrientation>(value)];
    }

    Size PDFInfo::paper_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPDFInfo>(this) paperSize]);
    }

    void PDFInfo::set_paper_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSPDFInfo>(this) setPaperSize:cocoon::internal::to(value)];
    }

    std::vector<std::string> PDFInfo::tag_names() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSPDFInfo>(this) tagNames], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void PDFInfo::set_tag_names(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSPDFInfo>(this) setTagNames:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                        {
                                                                                            return cocoon::internal::to(e);
                                                                                        })];
    }
}
