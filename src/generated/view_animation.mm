#include "generated/view_animation.h"
#include "internal.h"

namespace cocoon
{
    ViewAnimation::ViewAnimation(const std::vector<std::map<std::string, Object>>& view_animations) : ViewAnimation(Adopt{cocoon::internal::retain([[::NSViewAnimation alloc] initWithViewAnimations:cocoon::internal::to_array(view_animations, [](const std::map<std::string, Object>& e) -> id
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                    return cocoon::internal::to_dictionary(e, [](const std::string& k) -> id
                                                                                                                                                                                                                                                                           {
                                                                                                                                                                                                                                                                               return cocoon::internal::to(k);
                                                                                                                                                                                                                                                                           },
                                                                                                                                                                                                                                                                           [](const Object& v) -> id
                                                                                                                                                                                                                                                                           {
                                                                                                                                                                                                                                                                               return cocoon::internal::native_id(v);
                                                                                                                                                                                                                                                                           });
                                                                                                                                                                                                                                })])})
    {
        Animation::install_delegate_delegate_(handle());
    }

    ViewAnimation::ViewAnimation() : ViewAnimation(Adopt{cocoon::internal::retain([[::NSViewAnimation alloc] init])})
    {
        Animation::install_delegate_delegate_(handle());
    }

    ViewAnimation::ViewAnimation(std::nullptr_t) : Animation(nullptr)
    {
    }

    ViewAnimation::ViewAnimation(Adopt adopt) : Animation(adopt)
    {
    }

    std::vector<std::map<std::string, Object>> ViewAnimation::view_animations() const
    {
        return cocoon::internal::from_array<std::map<std::string, Object>>([cocoon::internal::ns<::NSViewAnimation>(this) viewAnimations], [](id e) -> std::map<std::string, Object>
                                                                           {
                                                                               return cocoon::internal::from_dictionary<std::map<std::string, Object>>((NSDictionary*)e, [](id k) -> std::string
                                                                                                                                                       {
                                                                                                                                                           return cocoon::internal::from((NSString*)k);
                                                                                                                                                       },
                                                                                                                                                       [](id v) -> Object
                                                                                                                                                       {
                                                                                                                                                           return cocoon::internal::wrap<Object>(v);
                                                                                                                                                       });
                                                                           });
    }

    void ViewAnimation::set_view_animations(const std::vector<std::map<std::string, Object>>& value) const
    {
        [cocoon::internal::ns<::NSViewAnimation>(this) setViewAnimations:cocoon::internal::to_array(value, [](const std::map<std::string, Object>& e) -> id
                                                                                                    {
                                                                                                        return cocoon::internal::to_dictionary(e, [](const std::string& k) -> id
                                                                                                                                               {
                                                                                                                                                   return cocoon::internal::to(k);
                                                                                                                                               },
                                                                                                                                               [](const Object& v) -> id
                                                                                                                                               {
                                                                                                                                                   return cocoon::internal::native_id(v);
                                                                                                                                               });
                                                                                                    })];
    }
}
