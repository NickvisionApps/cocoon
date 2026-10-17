#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class URLRequest;

    /**
     * @brief C++ handle for the Objective-C class `NSURLDownload` (Foundation).
     * @details An object that downloads a resource asynchronously and saves the data to a file. > Important: > This API is considered legacy. Use ''URLSession'' instead. The interface for ''NSURLDownload'' provides methods to initialize a download, set the destination path and cancel loading the request. The delegate object assigned to each instance of this class should implement the methods defined by the ''NSURLDownloadDelegate'' protocol. These methods provide the delegate with the current status of in-progress asynchronous downloads and allow the delegate to customize the URL loading process. These delegate methods are called on the thread that started the asynchronous load operation for the associated ''NSURLDownload'' object.
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
     * @details Returns whether a URL download object can resume a download that was decoded with the specified MIME type. The MIME type of a file, in conjunction with the value returned by the 'download:shouldDecodeSourceDataOfMIMEType:' delegate method, determines whether the 'NSURLDownload' class should decode or decompress the incoming data as it is received. Some compression techniques, such as the 'DEFLATE' algorithm ('gzip') use symbol dictionaries that vary during the compression process, making it impractical to decompress only a portion of the data starting in the middle. For this reason, this method returns 'NO' unless both of the following conditions are met: - The MIME type is of a type that the 'NSURLDownload' class knows how to decompress or decode. - The decoding can be safely resumed. In practice, this method returns 'YES' for MacBinary and BinHex, otherwise 'NO'. If your app needs to be able to resume file downloads in 'gzip' format, your 'download:shouldDecodeSourceDataOfMIMEType:' method must return 'NO', and you must decode the resulting file yourself after you finish downloading it in its entirety. - Parameter MIMEType: The MIME type the caller wants to know about. - Returns: 'YES' if the URL download object can resume a download that was decoded with the specified MIME type, 'NO' otherwise.
     * @param mime_type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool can_resume_download_decoded_with_encoding_mime_type(const std::string& mime_type);
        /**
     * @brief Calls `-[NSURLDownload cancel]`.
     * @details Cancels the receiver's download and deletes the downloaded file. This method deletes the partially downloaded file unless you have previously called ''deletesFileUponFailure'', passing 'NO'.
     */
        void cancel() const;
        /**
     * @brief Calls `-[NSURLDownload setDestination:allowOverwrite:]`.
     * @details Sets the destination path of the downloaded file. If 'allowOverwrite' is 'NO' and a file already exists at 'path', a unique filename will be created by appending a number to the filename. The delegate can implement ''NSURLDownloadDelegate/download(:didCreateDestination:)'' to determine the filename used when the file is written to disk. An 'NSURLDownload' instance ignores multiple calls to this method. - Parameters: - path: The path for the downloaded file. - allowOverwrite: 'YES' if an existing file at 'path' can be replaced, 'NO' otherwise.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @param allow_overwrite Argument converted to the Objective-C parameter of the same role.
     */
        void set_destination(const std::string& path, bool allow_overwrite) const;
        /**
     * @brief Returns the `deletesFileUponFailure` property of `NSURLDownload`.
     * @details Whether the receiver deletes partially downloaded files when a download stops prematurely. The default value is 'YES'. To allow the download to be resumed in case the download ends prematurely, set this property to 'NO' as soon as possible to prevent the downloaded file from being deleted.
     * @return The converted Objective-C result.
     */
        bool deletes_file_upon_failure() const;
        /**
     * @brief Sets the `deletesFileUponFailure` property of `NSURLDownload`.
     * @details Whether the receiver deletes partially downloaded files when a download stops prematurely. The default value is 'YES'. To allow the download to be resumed in case the download ends prematurely, set this property to 'NO' as soon as possible to prevent the downloaded file from being deleted.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_deletes_file_upon_failure(bool value) const;
        /**
     * @brief Returns the `request` property of `NSURLDownload`.
     * @details The URL request that initiated the receiver's download.
     * @return The converted Objective-C result.
     */
        URLRequest request() const;
        /**
     * @brief Returns the `resumeData` property of `NSURLDownload`.
     * @details The resume data for a download that is not yet complete. This data represents the necessary state information that an 'NSURLDownload' object needs to resume a download. The resume data can later be used when initializing a download with 'initWithResumeData:delegate:path:'. Returns 'nil' if the download is not able to be resumed. Resume data is returned only if both the protocol and the server support resuming.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> resume_data() const;
    };
}
