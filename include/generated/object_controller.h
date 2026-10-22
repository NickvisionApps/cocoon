#pragma once

#include "generated/availability.h"
#include "generated/controller.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class ManagedObjectContext;
    class Predicate;

    /**
     * @brief C++ handle for the Objective-C class `NSObjectController` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Controller.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ObjectController object_controller;
     * object_controller.set_automatically_prepares_content(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ObjectController object_controller{};
     * object_controller.set_automatically_prepares_content(true);
     * auto automatically_prepares_content = object_controller.automatically_prepares_content();
     * object_controller.set_editable(true);
     * auto editable = object_controller.is_editable();
     * object_controller.set_entity_name("text");
     * auto entity_name = object_controller.entity_name();
     * object_controller.default_fetch_request();
     * object_controller.new_object();
     * object_controller.prepare_content();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsobjectcontroller
     */
    class ObjectController : public Controller
    {
    public:
        /// @brief Creates a new `NSObjectController` instance and returns a handle to it.
        explicit ObjectController(const Object& content);
        /// @brief Creates a new `NSObjectController` instance and returns a handle to it.
        explicit ObjectController();
        /// @brief Creates a null handle that refers to no native object.
        ObjectController(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ObjectController(Adopt adopt);
        /**
         * @brief Calls `-[NSObjectController add:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void add(const Object& sender) const;
        /**
         * @brief Calls `-[NSObjectController addObject:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         */
        void add_object(const Object& object) const;
        /**
         * @brief Calls `-[NSObjectController defaultFetchRequest]`.
         * @return The converted Objective-C result.
         */
        Object default_fetch_request() const;
        /**
         * @brief Calls `-[NSObjectController fetch:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void fetch(const Object& sender) const;
        /**
         * @brief Calls `-[NSObjectController fetchWithRequest:merge:error:]`.
         * @param fetch_request Argument converted to the Objective-C parameter of the same role.
         * @param merge Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool fetch_with_request(const Object& fetch_request, bool merge) const;
        /**
         * @brief Calls `-[NSObjectController newObject]`.
         * @return The converted Objective-C result.
         */
        Object new_object() const;
        /**
         * @brief Calls `-[NSObjectController prepareContent]`.
         */
        void prepare_content() const;
        /**
         * @brief Calls `-[NSObjectController remove:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void remove(const Object& sender) const;
        /**
         * @brief Calls `-[NSObjectController removeObject:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         */
        void remove_object(const Object& object) const;
        /**
         * @brief Calls `-[NSObjectController validateUserInterfaceItem:]`.
         * @param item Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool validate_user_interface_item(const Object& item) const;
        /**
         * @brief Returns the `automaticallyPreparesContent` property of `NSObjectController`.
         * @return The converted Objective-C result.
         */
        bool automatically_prepares_content() const;
        /**
         * @brief Sets the `automaticallyPreparesContent` property of `NSObjectController`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_automatically_prepares_content(bool value) const;
        /**
         * @brief Returns the `canAdd` property of `NSObjectController`.
         * @return The converted Objective-C result.
         */
        bool can_add() const;
        /**
         * @brief Returns the `canRemove` property of `NSObjectController`.
         * @return The converted Objective-C result.
         */
        bool can_remove() const;
        /**
         * @brief Returns the `content` property of `NSObjectController`.
         * @return The converted Objective-C result.
         */
        Object content() const;
        /**
         * @brief Sets the `content` property of `NSObjectController`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_content(const Object& value) const;
        /**
         * @brief Returns the `editable` property of `NSObjectController`.
         * @return The converted Objective-C result.
         */
        bool is_editable() const;
        /**
         * @brief Sets the `editable` property of `NSObjectController`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_editable(bool value) const;
        /**
         * @brief Returns the `entityName` property of `NSObjectController`.
         * @return The converted Objective-C result.
         */
        std::string entity_name() const;
        /**
         * @brief Sets the `entityName` property of `NSObjectController`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_entity_name(const std::string& value) const;
        /**
         * @brief Returns the `fetchPredicate` property of `NSObjectController`.
         * @return The converted Objective-C result.
         */
        Predicate fetch_predicate() const;
        /**
         * @brief Sets the `fetchPredicate` property of `NSObjectController`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_fetch_predicate(const Predicate& value) const;
        /**
         * @brief Returns the `managedObjectContext` property of `NSObjectController`.
         * @return The converted Objective-C result.
         */
        ManagedObjectContext managed_object_context() const;
        /**
         * @brief Sets the `managedObjectContext` property of `NSObjectController`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_managed_object_context(const ManagedObjectContext& value) const;
        /**
         * @brief Returns the `objectClass` property of `NSObjectController`.
         * @return The converted Objective-C result.
         */
        std::string object_class() const;
        /**
         * @brief Sets the `objectClass` property of `NSObjectController`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_object_class(const std::string& value) const;
        /**
         * @brief Returns the `selectedObjects` property of `NSObjectController`.
         * @return The converted Objective-C result.
         */
        std::vector<Object> selected_objects() const;
        /**
         * @brief Returns the `selection` property of `NSObjectController`.
         * @return The converted Objective-C result.
         */
        Object selection() const;
        /**
         * @brief Returns the `usesLazyFetching` property of `NSObjectController`.
         * @return The converted Objective-C result.
         */
        bool uses_lazy_fetching() const;
        /**
         * @brief Sets the `usesLazyFetching` property of `NSObjectController`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_uses_lazy_fetching(bool value) const;
    };
}
