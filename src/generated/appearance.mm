#include "generated/appearance.h"
#include "internal.h"

namespace cocoon
{
    Appearance::Appearance(const std::string& name, const Bundle& bundle) : Appearance(Adopt{cocoon::internal::retain([[::NSAppearance alloc] initWithAppearanceNamed:cocoon::internal::to(name) bundle:cocoon::internal::native<::NSBundle>(bundle)])})
    {
    }

    Appearance::Appearance() : Appearance(Adopt{cocoon::internal::retain([[::NSAppearance alloc] init])})
    {
    }

    Appearance::Appearance(std::nullptr_t) : Object(nullptr)
    {
    }

    Appearance::Appearance(Adopt adopt) : Object(adopt)
    {
    }

    Appearance Appearance::appearance_named(const std::string& name)
    {
        return cocoon::internal::wrap<Appearance>([::NSAppearance appearanceNamed:cocoon::internal::to(name)]);
    }

    std::string Appearance::best_match_from_appearances_with_names(const std::vector<std::string>& appearances) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAppearance>(this) bestMatchFromAppearancesWithNames:cocoon::internal::to_array(appearances, [](const std::string& e) -> id
                                                                                                                                               {
                                                                                                                                                   return cocoon::internal::to(e);
                                                                                                                                               })]);
    }

    void Appearance::perform_as_current_drawing_appearance(std::function<void()> block) const
    {
        [cocoon::internal::ns<::NSAppearance>(this) performAsCurrentDrawingAppearance:(block ? (void (^)(void)) ^ void() { block(); } : (void (^)(void))nil)];
    }

    bool Appearance::allows_vibrancy() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSAppearance>(this) allowsVibrancy]);
    }

    Appearance Appearance::current_drawing_appearance()
    {
        return cocoon::internal::wrap<Appearance>([::NSAppearance currentDrawingAppearance]);
    }

    std::string Appearance::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAppearance>(this) name]);
    }
}
