#include "generated/morphology_pronoun.h"
#include "internal.h"

namespace cocoon
{
    MorphologyPronoun::MorphologyPronoun(const std::string& pronoun, const Morphology& morphology, const Morphology& dependent_morphology) : MorphologyPronoun(Adopt{cocoon::internal::retain([[::NSMorphologyPronoun alloc] initWithPronoun:cocoon::internal::to(pronoun) morphology:cocoon::internal::native<::NSMorphology>(morphology) dependentMorphology:cocoon::internal::native<::NSMorphology>(dependent_morphology)])})
    {
    }

    MorphologyPronoun::MorphologyPronoun() : Object(nullptr)
    {
    }

    MorphologyPronoun::MorphologyPronoun(std::nullptr_t) : Object(nullptr)
    {
    }

    MorphologyPronoun::MorphologyPronoun(Adopt adopt) : Object(adopt)
    {
    }

    Morphology MorphologyPronoun::dependent_morphology() const
    {
        return cocoon::internal::wrap<Morphology>([cocoon::internal::ns<::NSMorphologyPronoun>(this) dependentMorphology]);
    }

    Morphology MorphologyPronoun::morphology() const
    {
        return cocoon::internal::wrap<Morphology>([cocoon::internal::ns<::NSMorphologyPronoun>(this) morphology]);
    }

    std::string MorphologyPronoun::pronoun() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMorphologyPronoun>(this) pronoun]);
    }
}
