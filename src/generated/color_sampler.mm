#include "generated/color_sampler.h"
#include "internal.h"

namespace cocoon
{
    ColorSampler::ColorSampler() : ColorSampler(Adopt{cocoon::internal::retain([[::NSColorSampler alloc] init])})
    {
    }

    ColorSampler::ColorSampler(std::nullptr_t) : Object(nullptr)
    {
    }

    ColorSampler::ColorSampler(Adopt adopt) : Object(adopt)
    {
    }

    void ColorSampler::show_sampler_with_selection_handler(std::function<void(Color)> selection_handler) const
    {
        [cocoon::internal::ns<::NSColorSampler>(this) showSamplerWithSelectionHandler:(selection_handler ? (void (^)(::NSColor*)) ^ void(::NSColor * a20_0) { selection_handler(cocoon::internal::wrap<Color>(a20_0)); } : (void (^)(::NSColor*))nil)];
    }
}
