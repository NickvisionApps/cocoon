#include "generated/morphology_custom_pronoun.h"
#include "internal.h"

namespace cocoon
{
    MorphologyCustomPronoun::MorphologyCustomPronoun() : MorphologyCustomPronoun(Adopt{cocoon::internal::retain([[::NSMorphologyCustomPronoun alloc] init])})
    {
    }

    MorphologyCustomPronoun::MorphologyCustomPronoun(std::nullptr_t) : Object(nullptr)
    {
    }

    MorphologyCustomPronoun::MorphologyCustomPronoun(Adopt adopt) : Object(adopt)
    {
    }

    bool MorphologyCustomPronoun::is_supported_for_language(const std::string& language)
    {
        return static_cast<bool>([::NSMorphologyCustomPronoun isSupportedForLanguage:cocoon::internal::to(language)]);
    }

    std::vector<std::string> MorphologyCustomPronoun::required_keys_for_language(const std::string& language)
    {
        return cocoon::internal::from_array<std::string>([::NSMorphologyCustomPronoun requiredKeysForLanguage:cocoon::internal::to(language)], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::string MorphologyCustomPronoun::object_form() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMorphologyCustomPronoun>(this) objectForm]);
    }

    void MorphologyCustomPronoun::set_object_form(const std::string& value) const
    {
        [cocoon::internal::ns<::NSMorphologyCustomPronoun>(this) setObjectForm:cocoon::internal::to(value)];
    }

    std::string MorphologyCustomPronoun::possessive_adjective_form() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMorphologyCustomPronoun>(this) possessiveAdjectiveForm]);
    }

    void MorphologyCustomPronoun::set_possessive_adjective_form(const std::string& value) const
    {
        [cocoon::internal::ns<::NSMorphologyCustomPronoun>(this) setPossessiveAdjectiveForm:cocoon::internal::to(value)];
    }

    std::string MorphologyCustomPronoun::possessive_form() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMorphologyCustomPronoun>(this) possessiveForm]);
    }

    void MorphologyCustomPronoun::set_possessive_form(const std::string& value) const
    {
        [cocoon::internal::ns<::NSMorphologyCustomPronoun>(this) setPossessiveForm:cocoon::internal::to(value)];
    }

    std::string MorphologyCustomPronoun::reflexive_form() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMorphologyCustomPronoun>(this) reflexiveForm]);
    }

    void MorphologyCustomPronoun::set_reflexive_form(const std::string& value) const
    {
        [cocoon::internal::ns<::NSMorphologyCustomPronoun>(this) setReflexiveForm:cocoon::internal::to(value)];
    }

    std::string MorphologyCustomPronoun::subject_form() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMorphologyCustomPronoun>(this) subjectForm]);
    }

    void MorphologyCustomPronoun::set_subject_form(const std::string& value) const
    {
        [cocoon::internal::ns<::NSMorphologyCustomPronoun>(this) setSubjectForm:cocoon::internal::to(value)];
    }
}
