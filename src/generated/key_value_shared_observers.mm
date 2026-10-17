#include "generated/key_value_shared_observers.h"
#include "internal.h"

namespace cocoon
{
    KeyValueSharedObservers::KeyValueSharedObservers() : Object(nullptr)
    {
    }

    KeyValueSharedObservers::KeyValueSharedObservers(std::nullptr_t) : Object(nullptr)
    {
    }

    KeyValueSharedObservers::KeyValueSharedObservers(Adopt adopt) : Object(adopt)
    {
    }

    void KeyValueSharedObservers::add_shared_observer(const Object& observer, const std::string& key, KeyValueObservingOptions options, void* context) const
    {
        [cocoon::internal::ns<::NSKeyValueSharedObservers>(this) addSharedObserver:cocoon::internal::native_id(observer) forKey:cocoon::internal::to(key) options:static_cast<::NSKeyValueObservingOptions>(options) context:context];
    }

    Object KeyValueSharedObservers::init_with_observable_class(const std::string& observable_class) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSKeyValueSharedObservers>(this) initWithObservableClass:NSClassFromString(cocoon::internal::to(observable_class))]);
    }

    KeyValueSharedObserversSnapshot KeyValueSharedObservers::snapshot() const
    {
        return cocoon::internal::wrap<KeyValueSharedObserversSnapshot>([cocoon::internal::ns<::NSKeyValueSharedObservers>(this) snapshot]);
    }
}
