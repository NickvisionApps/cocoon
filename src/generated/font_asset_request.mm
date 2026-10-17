#include "generated/font_asset_request.h"
#include "internal.h"

namespace cocoon
{
    FontAssetRequest::FontAssetRequest(const std::vector<FontDescriptor>& font_descriptors, FontAssetRequestOptions options) : FontAssetRequest(Adopt{cocoon::internal::retain([[::NSFontAssetRequest alloc] initWithFontDescriptors:cocoon::internal::to_array(font_descriptors, [](const FontDescriptor& e) -> id
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                    return cocoon::internal::native<::NSFontDescriptor>(e);
                                                                                                                                                                                                                                                                })
                                                                                                                                                                                                                             options:static_cast<::NSFontAssetRequestOptions>(options)])})
    {
    }

    FontAssetRequest::FontAssetRequest() : Object(nullptr)
    {
    }

    FontAssetRequest::FontAssetRequest(std::nullptr_t) : Object(nullptr)
    {
    }

    FontAssetRequest::FontAssetRequest(Adopt adopt) : Object(adopt)
    {
    }

    void FontAssetRequest::download_font_assets_with_completion_handler(std::function<bool(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSFontAssetRequest>(this) downloadFontAssetsWithCompletionHandler:(completion_handler ? (BOOL(^)(::NSError*)) ^ ::BOOL(::NSError * a61_0) { auto __r = completion_handler(cocoon::internal::wrap<Error>(a61_0)); return static_cast<::BOOL>(__r); } : (BOOL(^)(::NSError*))nil)];
    }

    std::vector<FontDescriptor> FontAssetRequest::downloaded_font_descriptors() const
    {
        return cocoon::internal::from_array<FontDescriptor>([cocoon::internal::ns<::NSFontAssetRequest>(this) downloadedFontDescriptors], [](id e) -> FontDescriptor
                                                            {
                                                                return cocoon::internal::wrap<FontDescriptor>((::NSFontDescriptor*)e);
                                                            });
    }

    Progress FontAssetRequest::progress() const
    {
        return cocoon::internal::wrap<Progress>([cocoon::internal::ns<::NSFontAssetRequest>(this) progress]);
    }
}
