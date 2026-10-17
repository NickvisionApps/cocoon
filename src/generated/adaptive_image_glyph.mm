#include "generated/adaptive_image_glyph.h"
#include "internal.h"

namespace cocoon
{
    AdaptiveImageGlyph::AdaptiveImageGlyph(const std::vector<std::uint8_t>& image_content) : AdaptiveImageGlyph(Adopt{cocoon::internal::retain([[::NSAdaptiveImageGlyph alloc] initWithImageContent:cocoon::internal::to_data(image_content)])})
    {
    }

    AdaptiveImageGlyph::AdaptiveImageGlyph() : Object(nullptr)
    {
    }

    AdaptiveImageGlyph::AdaptiveImageGlyph(std::nullptr_t) : Object(nullptr)
    {
    }

    AdaptiveImageGlyph::AdaptiveImageGlyph(Adopt adopt) : Object(adopt)
    {
    }

    std::string AdaptiveImageGlyph::content_description() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAdaptiveImageGlyph>(this) contentDescription]);
    }

    std::string AdaptiveImageGlyph::content_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAdaptiveImageGlyph>(this) contentIdentifier]);
    }

    Object AdaptiveImageGlyph::content_type()
    {
        return cocoon::internal::wrap<Object>([::NSAdaptiveImageGlyph contentType]);
    }

    std::vector<std::uint8_t> AdaptiveImageGlyph::image_content() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSAdaptiveImageGlyph>(this) imageContent]);
    }
}
