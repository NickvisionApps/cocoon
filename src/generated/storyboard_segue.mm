#include "generated/storyboard_segue.h"
#include "internal.h"

namespace cocoon
{
    StoryboardSegue::StoryboardSegue(const std::string& identifier, const Object& source_controller, const Object& destination_controller) : StoryboardSegue(Adopt{cocoon::internal::retain([[::NSStoryboardSegue alloc] initWithIdentifier:cocoon::internal::to(identifier) source:cocoon::internal::native_id(source_controller) destination:cocoon::internal::native_id(destination_controller)])})
    {
    }

    StoryboardSegue::StoryboardSegue() : StoryboardSegue(Adopt{cocoon::internal::retain([[::NSStoryboardSegue alloc] init])})
    {
    }

    StoryboardSegue::StoryboardSegue(std::nullptr_t) : Object(nullptr)
    {
    }

    StoryboardSegue::StoryboardSegue(Adopt adopt) : Object(adopt)
    {
    }

    void StoryboardSegue::perform() const
    {
        [cocoon::internal::ns<::NSStoryboardSegue>(this) perform];
    }

    StoryboardSegue StoryboardSegue::segue_with_identifier(const std::string& identifier, const Object& source_controller, const Object& destination_controller, std::function<void()> perform_handler)
    {
        return cocoon::internal::wrap<StoryboardSegue>([::NSStoryboardSegue segueWithIdentifier:cocoon::internal::to(identifier) source:cocoon::internal::native_id(source_controller) destination:cocoon::internal::native_id(destination_controller) performHandler:(perform_handler ? (void (^)(void)) ^ void() { perform_handler(); } : (void (^)(void))nil)]);
    }

    Object StoryboardSegue::destination_controller() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSStoryboardSegue>(this) destinationController]);
    }

    std::string StoryboardSegue::identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSStoryboardSegue>(this) identifier]);
    }

    Object StoryboardSegue::source_controller() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSStoryboardSegue>(this) sourceController]);
    }
}
