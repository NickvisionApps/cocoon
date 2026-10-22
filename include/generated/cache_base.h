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
     * @details A mutable collection you use to temporarily store transient key-value pairs that are subject to eviction when resources are low. Cache objects differ from other mutable collections in a few ways: - The ''NSCache'' class incorporates various auto-eviction policies, which ensure that a cache doesn't use too much of the system's memory. If memory is needed by other applications, these policies remove some items from the cache, minimizing its memory footprint. - You can add, remove, and query items in the cache from different threads without having to lock the cache yourself. - Unlike an ''NSMutableDictionary'' object, a cache does not copy the key objects that are put into it. You typically use ''NSCache'' objects to temporarily store objects with transient data that are expensive to create. Reusing these objects can provide performance benefits, because their values do not have to be recalculated. However, the objects are not critical to the application and can be discarded if memory is tight. If discarded, their values will have to be recomputed again when needed. Objects that have subcomponents that can be discarded when not being used can adopt the ''NSDiscardableContent'' protocol to improve cache eviction behavior. By default, ''NSDiscardableContent'' objects in a cache are automatically removed if their content is discarded, although this automatic removal policy can be changed. If an ''NSDiscardableContent'' object is put into the cache, the cache calls ''NSDiscardableContent/discardContentIfPossible()'' on it upon its removal.
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
         * @details Returns the value associated with a given key. - Parameter key: An object identifying the value. - Returns: The value associated with 'key', or 'nil' if no value is associated with 'key'.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object object_for_key(const Object& key) const;
        /**
         * @brief Calls `-[NSCache removeAllObjects]`.
         * @details Empties the cache.
         */
        void remove_all_objects() const;
        /**
         * @brief Calls `-[NSCache removeObjectForKey:]`.
         * @details Removes the value of the specified key in the cache. - Parameter key: The key identifying the value to be removed.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void remove_object_for_key(const Object& key) const;
        /**
         * @brief Calls `-[NSCache setObject:forKey:]`.
         * @details Sets the value of the specified key in the cache. Unlike an 'NSMutableDictionary' object, a cache does not copy the key objects that are put into it. - Parameter obj: The object to be stored in the cache. - Parameter key: The key with which to associate the value.
         * @param obj Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void set_object(const Object& obj, const Object& key) const;
        /**
         * @brief Calls `-[NSCache setObject:forKey:cost:]`.
         * @details Sets the value of the specified key in the cache, and associates the key-value pair with the specified cost. The 'cost' value is used to compute a sum encompassing the costs of all the objects in the cache. When memory is limited or when the total cost of the cache eclipses the maximum allowed total cost, the cache could begin an eviction process to remove some of its elements. Unlike an 'NSMutableDictionary' object, a cache does not copy the key objects that are put into it. - Parameter obj: The object to store in the cache. - Parameter key: The key with which to associate the value. - Parameter g: The cost with which to associate the key-value pair.
         * @param obj Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @param g Argument converted to the Objective-C parameter of the same role.
         */
        void set_object(const Object& obj, const Object& key, std::uint64_t g) const;
        /**
         * @brief Returns the `countLimit` property of `NSCache`.
         * @details The maximum number of objects the cache should hold. If '0', there is no count limit. The default value is '0'. This is not a strict limit -- if the cache goes over the limit, an object in the cache could be evicted instantly, later, or possibly never, depending on the implementation details of the cache.
         * @return The converted Objective-C result.
         */
        std::uint64_t count_limit() const;
        /**
         * @brief Sets the `countLimit` property of `NSCache`.
         * @details The maximum number of objects the cache should hold. If '0', there is no count limit. The default value is '0'. This is not a strict limit -- if the cache goes over the limit, an object in the cache could be evicted instantly, later, or possibly never, depending on the implementation details of the cache.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_count_limit(std::uint64_t value) const;
        /**
         * @brief Returns the `evictsObjectsWithDiscardedContent` property of `NSCache`.
         * @details Whether the cache will automatically evict discardable-content objects whose content has been discarded. If 'YES', the cache will evict a discardable-content object after its content is discarded. If 'NO', it will not. The default value is 'YES'.
         * @return The converted Objective-C result.
         */
        bool evicts_objects_with_discarded_content() const;
        /**
         * @brief Sets the `evictsObjectsWithDiscardedContent` property of `NSCache`.
         * @details Whether the cache will automatically evict discardable-content objects whose content has been discarded. If 'YES', the cache will evict a discardable-content object after its content is discarded. If 'NO', it will not. The default value is 'YES'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_evicts_objects_with_discarded_content(bool value) const;
        /**
         * @brief Returns the `name` property of `NSCache`.
         * @details The name of the cache. The default value is an empty string ("").
         * @return The converted Objective-C result.
         */
        std::string name() const;
        /**
         * @brief Sets the `name` property of `NSCache`.
         * @details The name of the cache. The default value is an empty string ("").
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_name(const std::string& value) const;
        /**
         * @brief Returns the `totalCostLimit` property of `NSCache`.
         * @details The maximum total cost that the cache can hold before it starts evicting objects. If '0', there is no total cost limit. The default value is '0'. This is not a strict limit, and if the cache goes over the limit, an object in the cache could be evicted instantly, at a later point in time, or possibly never, all depending on the implementation details of the cache.
         * @return The converted Objective-C result.
         */
        std::uint64_t total_cost_limit() const;
        /**
         * @brief Sets the `totalCostLimit` property of `NSCache`.
         * @details The maximum total cost that the cache can hold before it starts evicting objects. If '0', there is no total cost limit. The default value is '0'. This is not a strict limit, and if the cache goes over the limit, an object in the cache could be evicted instantly, at a later point in time, or possibly never, all depending on the implementation details of the cache.
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
