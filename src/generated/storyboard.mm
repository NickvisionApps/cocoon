#include "generated/storyboard.h"
#include "internal.h"

namespace cocoon
{
    Storyboard::Storyboard(const std::string& name, const Bundle& storyboard_bundle_or_nil) : Storyboard(Adopt{cocoon::internal::retain([::NSStoryboard storyboardWithName:cocoon::internal::to(name) bundle:cocoon::internal::native<::NSBundle>(storyboard_bundle_or_nil)])})
    {
    }

    Storyboard::Storyboard() : Storyboard(Adopt{cocoon::internal::retain([[::NSStoryboard alloc] init])})
    {
    }

    Storyboard::Storyboard(std::nullptr_t) : Object(nullptr)
    {
    }

    Storyboard::Storyboard(Adopt adopt) : Object(adopt)
    {
    }

    Object Storyboard::instantiate_controller_with_identifier(const std::string& identifier) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSStoryboard>(this) instantiateControllerWithIdentifier:cocoon::internal::to(identifier)]);
    }

    Object Storyboard::instantiate_controller_with_identifier(const std::string& identifier, std::function<Object(Coder)> block) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSStoryboard>(this) instantiateControllerWithIdentifier:cocoon::internal::to(identifier) creator:(block ? (::NSStoryboardControllerCreator) ^ id(::NSCoder * a83_0) { auto __r = block(cocoon::internal::wrap<Coder>(a83_0)); return cocoon::internal::native_id(__r); } : (::NSStoryboardControllerCreator)nil)]);
    }

    Object Storyboard::instantiate_initial_controller() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSStoryboard>(this) instantiateInitialController]);
    }

    Object Storyboard::instantiate_initial_controller_with_creator(std::function<Object(Coder)> block) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSStoryboard>(this) instantiateInitialControllerWithCreator:(block ? (::NSStoryboardControllerCreator) ^ id(::NSCoder * a84_0) { auto __r = block(cocoon::internal::wrap<Coder>(a84_0)); return cocoon::internal::native_id(__r); } : (::NSStoryboardControllerCreator)nil)]);
    }

    Storyboard Storyboard::main_storyboard()
    {
        return cocoon::internal::wrap<Storyboard>([::NSStoryboard mainStoryboard]);
    }
}
