#include "generated/counted_set_base.h"
#include "internal.h"

namespace cocoon
{
    CountedSetBase::CountedSetBase(const std::vector<Object>& array) : CountedSetBase(Adopt{cocoon::internal::retain([[::NSCountedSet alloc] initWithArray:cocoon::internal::to_array(array, [](const Object& e) -> id
                                                                                                                                                          {
                                                                                                                                                              return cocoon::internal::native_id(e);
                                                                                                                                                          })])})
    {
    }

    CountedSetBase::CountedSetBase(std::uint64_t num_items) : CountedSetBase(Adopt{cocoon::internal::retain([[::NSCountedSet alloc] initWithCapacity:static_cast<::NSUInteger>(num_items)])})
    {
    }

    CountedSetBase::CountedSetBase() : CountedSetBase(Adopt{cocoon::internal::retain([[::NSCountedSet alloc] init])})
    {
    }

    CountedSetBase::CountedSetBase(std::nullptr_t) : Object(nullptr)
    {
    }

    CountedSetBase::CountedSetBase(Adopt adopt) : Object(adopt)
    {
    }

    void CountedSetBase::add_object(const Object& object) const
    {
        [cocoon::internal::ns<::NSCountedSet>(this) addObject:cocoon::internal::native_id(object)];
    }

    std::uint64_t CountedSetBase::count_for_object(const Object& object) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSCountedSet>(this) countForObject:cocoon::internal::native_id(object)]);
    }

    EnumeratorBase CountedSetBase::object_enumerator() const
    {
        return cocoon::internal::wrap<EnumeratorBase>([cocoon::internal::ns<::NSCountedSet>(this) objectEnumerator]);
    }

    void CountedSetBase::remove_object(const Object& object) const
    {
        [cocoon::internal::ns<::NSCountedSet>(this) removeObject:cocoon::internal::native_id(object)];
    }
}
