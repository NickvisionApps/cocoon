#include "generated/text_preview.h"
#include "internal.h"

namespace cocoon
{
    TextPreview::TextPreview(const CGImage& snapshot_image, const Rect& presentation_frame) : TextPreview(Adopt{cocoon::internal::retain([[::NSTextPreview alloc] initWithSnapshotImage:((::CGImageRef)(snapshot_image).handle()) presentationFrame:cocoon::internal::to(presentation_frame)])})
    {
    }

    TextPreview::TextPreview(const CGImage& snapshot_image, const Rect& presentation_frame, const std::vector<Value>& candidate_rects) : TextPreview(Adopt{cocoon::internal::retain([[::NSTextPreview alloc] initWithSnapshotImage:((::CGImageRef)(snapshot_image).handle())
                                                                                                                                                                                                   presentationFrame:cocoon::internal::to(presentation_frame)
                                                                                                                                                                                                      candidateRects:cocoon::internal::to_array(candidate_rects, [](const Value& e) -> id
                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                      return cocoon::internal::native<::NSValue>(e);
                                                                                                                                                                                                                                  })])})
    {
    }

    TextPreview::TextPreview() : Object(nullptr)
    {
    }

    TextPreview::TextPreview(std::nullptr_t) : Object(nullptr)
    {
    }

    TextPreview::TextPreview(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<Value> TextPreview::candidate_rects() const
    {
        return cocoon::internal::from_array<Value>([cocoon::internal::ns<::NSTextPreview>(this) candidateRects], [](id e) -> Value
                                     {
                                         return cocoon::internal::wrap<Value>((::NSValue*)e);
                                     });
    }

    Rect TextPreview::presentation_frame() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextPreview>(this) presentationFrame]);
    }

    CGImage TextPreview::preview_image() const
    {
        return cocoon::internal::wrap_cf<CGImage>((const void*)([cocoon::internal::ns<::NSTextPreview>(this) previewImage]));
    }
}
