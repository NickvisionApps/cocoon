#include "generated/nib.h"
#include "internal.h"

namespace cocoon
{
    Nib::Nib(const std::vector<std::uint8_t>& nib_data, const Bundle& bundle) : Nib(Adopt{cocoon::internal::retain([[::NSNib alloc] initWithNibData:cocoon::internal::to_data(nib_data) bundle:cocoon::internal::native<::NSBundle>(bundle)])})
    {
    }

    Nib::Nib(const std::string& nib_name, const Bundle& bundle) : Nib(Adopt{cocoon::internal::retain([[::NSNib alloc] initWithNibNamed:cocoon::internal::to(nib_name) bundle:cocoon::internal::native<::NSBundle>(bundle)])})
    {
    }

    Nib::Nib() : Nib(Adopt{cocoon::internal::retain([[::NSNib alloc] init])})
    {
    }

    Nib::Nib(std::nullptr_t) : Object(nullptr)
    {
    }

    Nib::Nib(Adopt adopt) : Object(adopt)
    {
    }

    bool Nib::instantiate_with_owner(const Object& owner, std::vector<Object>& top_level_objects) const
    {
        NSArray* __v_top_level_objects = nil;
        auto __r = [cocoon::internal::ns<::NSNib>(this) instantiateWithOwner:cocoon::internal::native_id(owner) topLevelObjects:&__v_top_level_objects];
        top_level_objects = cocoon::internal::from_array<Object>(__v_top_level_objects, [](id e) -> Object
                                                   {
                                                       return cocoon::internal::wrap<Object>(e);
                                                   });
        return static_cast<bool>(__r);
    }
}
