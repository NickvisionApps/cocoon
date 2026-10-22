#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class FontDescriptor;
    class Progress;

    /**
     * @brief C++ handle for the Objective-C class `NSFontAssetRequest` (AppKit).
     * @details The NSFontAssetRequest class is used to interact with the on demand font assets. The purpose of the system is to allow an application to download certain font assets on demand, when they are required. This also means that the system can purge any asset from disk when it is no longer required, which will save disk space. This class describes which assets are required, makes the request and reports progress, allows the app to specify how long during its execution that they are required. Assets are downloaded into the application container for sandboxed applications, or shared by all applications for non-sandboxed applications, and are made available via the standard NSFont lookup API. The request object itself is lightweight. You may create as many as you need, for example to request the same set of font descriptors in different components of your application.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::FontAssetRequest font_asset_request(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsfontassetrequest
     */
    class FontAssetRequest : public Object
    {
    public:
        /// @brief Creates a new `NSFontAssetRequest` instance and returns a handle to it.
        explicit FontAssetRequest(const std::vector<FontDescriptor>& font_descriptors, FontAssetRequestOptions options);
        FontAssetRequest();
        /// @brief Creates a null handle that refers to no native object.
        FontAssetRequest(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit FontAssetRequest(Adopt adopt);
        /**
         * @brief Calls `-[NSFontAssetRequest downloadFontAssetsWithCompletionHandler:]`.
         * @details Start the download process. completionHandler will be called whenever encounters any error, or when all download has been completed without error. completionHandler should return NO if you wish to stop downloading from that point, or YES if you wish to continue trying downloading the next font.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void download_font_assets_with_completion_handler(std::function<bool(Error)> completion_handler) const;
        /**
         * @brief Returns the `downloadedFontDescriptors` property of `NSFontAssetRequest`.
         * @details The downloaded font descriptors up to this point.
         * @return The converted Objective-C result.
         */
        std::vector<FontDescriptor> downloaded_font_descriptors() const;
        /**
         * @brief Returns the `progress` property of `NSFontAssetRequest`.
         * @details Progress for the request. The progress object will be valid at initialization and begin updating after the -downloadFontAssetsWithCompletionHandler: method is called.
         * @return The converted Objective-C result.
         */
        Progress progress() const;
    };
}
