#include "generated/url_download.h"
#include "internal.h"

namespace cocoon
{
    URLDownload::URLDownload() : URLDownload(Adopt{cocoon::internal::retain([[::NSURLDownload alloc] init])})
    {
    }

    URLDownload::URLDownload(std::nullptr_t) : Object(nullptr)
    {
    }

    URLDownload::URLDownload(Adopt adopt) : Object(adopt)
    {
    }

    bool URLDownload::can_resume_download_decoded_with_encoding_mime_type(const std::string& mime_type)
    {
        return static_cast<bool>([::NSURLDownload canResumeDownloadDecodedWithEncodingMIMEType:cocoon::internal::to(mime_type)]);
    }

    void URLDownload::cancel() const
    {
        [cocoon::internal::ns<::NSURLDownload>(this) cancel];
    }

    void URLDownload::set_destination(const std::string& path, bool allow_overwrite) const
    {
        [cocoon::internal::ns<::NSURLDownload>(this) setDestination:cocoon::internal::to(path) allowOverwrite:static_cast<::BOOL>(allow_overwrite)];
    }

    bool URLDownload::deletes_file_upon_failure() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSURLDownload>(this) deletesFileUponFailure]);
    }

    void URLDownload::set_deletes_file_upon_failure(bool value) const
    {
        [cocoon::internal::ns<::NSURLDownload>(this) setDeletesFileUponFailure:static_cast<::BOOL>(value)];
    }

    URLRequest URLDownload::request() const
    {
        return cocoon::internal::wrap<URLRequest>([cocoon::internal::ns<::NSURLDownload>(this) request]);
    }

    std::vector<std::uint8_t> URLDownload::resume_data() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSURLDownload>(this) resumeData]);
    }
}
