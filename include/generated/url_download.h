#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class URLRequest;

    /**
     * @brief C++ handle for the Objective-C class `NSURLDownload` (Foundation).
     * @details \@class NSURLDownload \@discussion A NSURLDownload loads a request and saves the downloaded data to a file. The progress of the download is reported via the NSURLDownloadDelegate protocol. Note: The word "download" is used to refer to the process of loading data off a network, decoding the data if necessary and saving the data to a file.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLDownload url_download;
     * url_download.set_deletes_file_upon_failure(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::URLDownload url_download{};
     * url_download.set_deletes_file_upon_failure(true);
     * auto deletes_file_upon_failure = url_download.deletes_file_upon_failure();
     * url_download.cancel();
     * url_download.set_destination("text", true);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurldownload
     */
    class URLDownload : public Object
    {
    public:
        /// @brief Creates a new `NSURLDownload` instance and returns a handle to it.
        explicit URLDownload();
        /// @brief Creates a null handle that refers to no native object.
        URLDownload(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLDownload(Adopt adopt);
        /**
         * @brief Calls `+[NSURLDownload canResumeDownloadDecodedWithEncodingMIMEType:]`.
         * @details \@method canResumeDownloadDecodedWithEncodingMIMEType: \@abstract Returns whether or not NSURLDownload can resume a download that was decoded with a given encoding MIME type. \@param MIMEType The encoding MIME type. \@description canResumeDownloadDecodedWithEncodingMIMEType: returns whether or not NSURLDownload can resume a download that was decoded with a given encoding MIME type. NSURLDownload cannot resume a download that was partially decoded in the gzip format for example. In order to ensure that a download can be later resumed, canResumeDownloadDecodedWithEncodingMIMEType: should be used when download:shouldDecodeSourceDataOfMIMEType: is called.
         * @param mime_type Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static bool can_resume_download_decoded_with_encoding_mime_type(const std::string& mime_type);
        /**
         * @brief Calls `-[NSURLDownload cancel]`.
         * @details \@method cancel \@abstract Cancels the download and deletes the downloaded file.
         */
        void cancel() const;
        /**
         * @brief Calls `-[NSURLDownload setDestination:allowOverwrite:]`.
         * @details \@method setDestination:allowOverwrite: \@abstract Sets the destination path of the downloaded file. \@param path The destination path of the downloaded file. \@param allowOverwrite Allows a file of the same path to be overwritten. \@discussion This method can be called after the download is created or in response to the decideDestinationWithSuggestedFilename: delegate method. It should only be called once. If NO is passed for allowOverwrite and a file of the same path exists, a number will be appended to the filename to prevent the overwrite. Because of this, use the path passed with didCreateDestination: to determine the actual path of the downloaded file.
         * @param path Argument converted to the Objective-C parameter of the same role.
         * @param allow_overwrite Argument converted to the Objective-C parameter of the same role.
         */
        void set_destination(const std::string& path, bool allow_overwrite) const;
        /**
         * @brief Returns the `deletesFileUponFailure` property of `NSURLDownload`.
         * @details \@abstract Sets whether or not the downloaded file should be deleted upon failure. 1 \@description To allow the download to be resumed in case the download ends prematurely, deletesFileUponFailure must be set to NO as soon as possible to prevent the downloaded file from being deleted. deletesFileUponFailure is YES by default.
         * @return The converted Objective-C result.
         */
        bool deletes_file_upon_failure() const;
        /**
         * @brief Sets the `deletesFileUponFailure` property of `NSURLDownload`.
         * @details \@abstract Sets whether or not the downloaded file should be deleted upon failure. 1 \@description To allow the download to be resumed in case the download ends prematurely, deletesFileUponFailure must be set to NO as soon as possible to prevent the downloaded file from being deleted. deletesFileUponFailure is YES by default.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_deletes_file_upon_failure(bool value) const;
        /**
         * @brief Returns the `request` property of `NSURLDownload`.
         * @details \@abstract Returns the request of the download. \@result The request of the download.
         * @return The converted Objective-C result.
         */
        URLRequest request() const;
        /**
         * @brief Returns the `resumeData` property of `NSURLDownload`.
         * @details \@abstract Returns the resume data of a download that is incomplete. \@result The resume data. \@description resumeData returns the resume data of a download that is incomplete. This data represents the necessary state information that NSURLDownload needs to resume a download. The resume data can later be used when initializing a download with initWithResumeData:delegate:path:. Non-nil is returned if resuming the download seems possible. Non-nil is returned if the download was cancelled or ended in error after some but not all data has been received. The protocol of the download as well as the server must support resuming for non-nil to be returned. In order to later resume a download, be sure to call setDeletesFileUponFailure: with NO.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> resume_data() const;
    };
}
