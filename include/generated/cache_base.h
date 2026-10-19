#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSCache` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Use the typed template @ref Cache to supply KeyType, ObjectType.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CacheBase cache_base;
     * cache_base.set_count_limit(1);
     * cache_base.will_evict_object().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CacheBase cache_base{};
     * cache_base.set_count_limit(1);
     * auto count_limit = cache_base.count_limit();
     * cache_base.set_evicts_objects_with_discarded_content(true);
     * auto evicts_objects_with_discarded_content = cache_base.evicts_objects_with_discarded_content();
     * cache_base.set_name("text");
     * auto name = cache_base.name();
     * cache_base.remove_all_objects();
     * cache_base.will_evict_object().connect([](cocoon::Object a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nscache
     */
    class CacheBase : public Object
    {
    public:
        /// @brief Creates a new `NSCache` instance and returns a handle to it.
        explicit CacheBase();
        /// @brief Creates a null handle that refers to no native object.
        CacheBase(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CacheBase(Adopt adopt);
        /**
     * @brief Calls `-[NSCache objectForKey:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object object_for_key(const Object& key) const;
        /**
     * @brief Calls `-[NSCache removeAllObjects]`.
     */
        void remove_all_objects() const;
        /**
     * @brief Calls `-[NSCache removeObjectForKey:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void remove_object_for_key(const Object& key) const;
        /**
     * @brief Calls `-[NSCache setObject:forKey:]`.
     * @param obj Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void set_object(const Object& obj, const Object& key) const;
        /**
     * @brief Calls `-[NSCache setObject:forKey:cost:]`.
     * @param obj Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @param g Argument converted to the Objective-C parameter of the same role.
     */
        void set_object(const Object& obj, const Object& key, std::uint64_t g) const;
        /**
     * @brief Returns the `countLimit` property of `NSCache`.
     * @return The converted Objective-C result.
     */
        std::uint64_t count_limit() const;
        /**
     * @brief Sets the `countLimit` property of `NSCache`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_count_limit(std::uint64_t value) const;
        /**
     * @brief Returns the `evictsObjectsWithDiscardedContent` property of `NSCache`.
     * @return The converted Objective-C result.
     */
        bool evicts_objects_with_discarded_content() const;
        /**
     * @brief Sets the `evictsObjectsWithDiscardedContent` property of `NSCache`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_evicts_objects_with_discarded_content(bool value) const;
        /**
     * @brief Returns the `name` property of `NSCache`.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Sets the `name` property of `NSCache`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_name(const std::string& value) const;
        /**
     * @brief Returns the `totalCostLimit` property of `NSCache`.
     * @return The converted Objective-C result.
     */
        std::uint64_t total_cost_limit() const;
        /**
     * @brief Sets the `totalCostLimit` property of `NSCache`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_total_cost_limit(std::uint64_t value) const;
        /// @brief Signal for the delegate/data-source method behind `will_evict_object`; connect a callback with `will_evict_object().connect(...)`.
        Signal<CacheBase, void(Object)> will_evict_object() const
        {
            return Signal<CacheBase, void(Object)>(handle(), "will_evict_object");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };

    template <class KeyType, class ObjectType>
    class Cache : public CacheBase
    {
    public:
        using CacheBase::CacheBase;
        Cache() : CacheBase()
        {
        }
        Cache(const CacheBase& other) : CacheBase(other)
        {
        }
        using CacheBase::count_limit;
        using CacheBase::evicts_objects_with_discarded_content;
        using CacheBase::name;
        using CacheBase::object_for_key;
        using CacheBase::remove_all_objects;
        using CacheBase::remove_object_for_key;
        using CacheBase::set_count_limit;
        using CacheBase::set_evicts_objects_with_discarded_content;
        using CacheBase::set_name;
        using CacheBase::set_object;
        using CacheBase::set_total_cost_limit;
        using CacheBase::total_cost_limit;
        using CacheBase::will_evict_object;
        auto object_for_key(const KeyType& key) const
        {
            return cocoon::unbox<ObjectType>(CacheBase::object_for_key(cocoon::box(key)));
        }
        auto remove_object_for_key(const KeyType& key) const
        {
            CacheBase::remove_object_for_key(cocoon::box(key));
        }
        auto set_object(const ObjectType& obj, const KeyType& key) const
        {
            CacheBase::set_object(cocoon::box(obj), cocoon::box(key));
        }
        auto set_object(const ObjectType& obj, const KeyType& key, std::uint64_t g) const
        {
            CacheBase::set_object(cocoon::box(obj), cocoon::box(key), g);
        }
    };
}
