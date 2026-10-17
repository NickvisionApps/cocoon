#include "generated/morphology.h"
#include "internal.h"

namespace cocoon
{
    Morphology::Morphology() : Morphology(Adopt{cocoon::internal::retain([[::NSMorphology alloc] init])})
    {
    }

    Morphology::Morphology(std::nullptr_t) : Object(nullptr)
    {
    }

    Morphology::Morphology(Adopt adopt) : Object(adopt)
    {
    }

    GrammaticalDefiniteness Morphology::definiteness() const
    {
        return static_cast<GrammaticalDefiniteness>([cocoon::internal::ns<::NSMorphology>(this) definiteness]);
    }

    void Morphology::set_definiteness(GrammaticalDefiniteness value) const
    {
        [cocoon::internal::ns<::NSMorphology>(this) setDefiniteness:static_cast<::NSGrammaticalDefiniteness>(value)];
    }

    GrammaticalDetermination Morphology::determination() const
    {
        return static_cast<GrammaticalDetermination>([cocoon::internal::ns<::NSMorphology>(this) determination]);
    }

    void Morphology::set_determination(GrammaticalDetermination value) const
    {
        [cocoon::internal::ns<::NSMorphology>(this) setDetermination:static_cast<::NSGrammaticalDetermination>(value)];
    }

    GrammaticalCase Morphology::grammatical_case() const
    {
        return static_cast<GrammaticalCase>([cocoon::internal::ns<::NSMorphology>(this) grammaticalCase]);
    }

    void Morphology::set_grammatical_case(GrammaticalCase value) const
    {
        [cocoon::internal::ns<::NSMorphology>(this) setGrammaticalCase:static_cast<::NSGrammaticalCase>(value)];
    }

    GrammaticalGender Morphology::grammatical_gender() const
    {
        return static_cast<GrammaticalGender>([cocoon::internal::ns<::NSMorphology>(this) grammaticalGender]);
    }

    void Morphology::set_grammatical_gender(GrammaticalGender value) const
    {
        [cocoon::internal::ns<::NSMorphology>(this) setGrammaticalGender:static_cast<::NSGrammaticalGender>(value)];
    }

    GrammaticalPerson Morphology::grammatical_person() const
    {
        return static_cast<GrammaticalPerson>([cocoon::internal::ns<::NSMorphology>(this) grammaticalPerson]);
    }

    void Morphology::set_grammatical_person(GrammaticalPerson value) const
    {
        [cocoon::internal::ns<::NSMorphology>(this) setGrammaticalPerson:static_cast<::NSGrammaticalPerson>(value)];
    }

    GrammaticalNumber Morphology::number() const
    {
        return static_cast<GrammaticalNumber>([cocoon::internal::ns<::NSMorphology>(this) number]);
    }

    void Morphology::set_number(GrammaticalNumber value) const
    {
        [cocoon::internal::ns<::NSMorphology>(this) setNumber:static_cast<::NSGrammaticalNumber>(value)];
    }

    GrammaticalPartOfSpeech Morphology::part_of_speech() const
    {
        return static_cast<GrammaticalPartOfSpeech>([cocoon::internal::ns<::NSMorphology>(this) partOfSpeech]);
    }

    void Morphology::set_part_of_speech(GrammaticalPartOfSpeech value) const
    {
        [cocoon::internal::ns<::NSMorphology>(this) setPartOfSpeech:static_cast<::NSGrammaticalPartOfSpeech>(value)];
    }

    GrammaticalPronounType Morphology::pronoun_type() const
    {
        return static_cast<GrammaticalPronounType>([cocoon::internal::ns<::NSMorphology>(this) pronounType]);
    }

    void Morphology::set_pronoun_type(GrammaticalPronounType value) const
    {
        [cocoon::internal::ns<::NSMorphology>(this) setPronounType:static_cast<::NSGrammaticalPronounType>(value)];
    }

    bool Morphology::is_unspecified() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMorphology>(this) isUnspecified]);
    }

    Morphology Morphology::user_morphology()
    {
        return cocoon::internal::wrap<Morphology>([::NSMorphology userMorphology]);
    }
}
