#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class KeyValueSharedObserversSnapshot;

    /**
     * @brief C++ handle for the Objective-C class `NSKeyValueSharedObservers` (Foundation).
     * @details A collection of key-value observations which may be registered with multiple observable objects
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::KeyValueSharedObservers key_value_shared_observers(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::KeyValueSharedObservers key_value_shared_observers(nullptr);
     * key_value_shared_observers.init_with_observable_class("text");
     * key_value_shared_observers.snapshot();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nskeyvaluesharedobservers
     */
    class KeyValueSharedObservers : public Object
    {
    public:
        KeyValueSharedObservers();
        /// @brief Creates a null handle that refers to no native object.
        KeyValueSharedObservers(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit KeyValueSharedObservers(Adopt adopt);
        /**
     * @brief Calls `-[NSKeyValueSharedObservers addSharedObserver:forKey:options:context:]`.
     * @details Add a new observer to the collection. This method works like '-[NSObject addObserver: forKey: options: context:]', but observations on nested and computed properties are disallowed. Observers are not registered until 'setSharedObservers' is called on the observable. - Parameter observer: The observer object to register for KVO notifications. The observer must implement the key-value observing method ''observeValue: forKeyPath: of: change: context:'' - Parameter key: key of the property being observed. This cannot be a nested key path or a computed property - Parameter options: A combination of NSKeyValueObservingOptions values that specify what is included in observation notifications. For possible values see NSKeyValueObservingOptions. - Parameter context: Arbitrary data which is passed to the observer object
     * @param observer Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param context Argument converted to the Objective-C parameter of the same role.
     */
        void add_shared_observer(const Object& observer, const std::string& key, KeyValueObservingOptions options, void* context) const;
        /**
     * @brief Calls `-[NSKeyValueSharedObservers initWithObservableClass:]`.
     * @details A new collection of observables for an observable object of the given class
     * @param observable_class Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object init_with_observable_class(const std::string& observable_class) const;
        /**
     * @brief Calls `-[NSKeyValueSharedObservers snapshot]`.
     * @details A momentary snapshot of all observers added to the collection thus far, that can be assigned to an observable using ''-[NSObject setSharedObservers:]''
     * @return The converted Objective-C result.
     */
        KeyValueSharedObserversSnapshot snapshot() const;
    };
}
