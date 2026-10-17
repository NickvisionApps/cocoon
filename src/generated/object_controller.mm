#include "generated/object_controller.h"
#include "internal.h"

namespace cocoon
{
    ObjectController::ObjectController(const Object& content) : ObjectController(Adopt{cocoon::internal::retain([[::NSObjectController alloc] initWithContent:cocoon::internal::native_id(content)])})
    {
    }

    ObjectController::ObjectController() : ObjectController(Adopt{cocoon::internal::retain([[::NSObjectController alloc] init])})
    {
    }

    ObjectController::ObjectController(std::nullptr_t) : Controller(nullptr)
    {
    }

    ObjectController::ObjectController(Adopt adopt) : Controller(adopt)
    {
    }

    void ObjectController::add(const Object& sender) const
    {
        [cocoon::internal::ns<::NSObjectController>(this) add:cocoon::internal::native_id(sender)];
    }

    void ObjectController::add_object(const Object& object) const
    {
        [cocoon::internal::ns<::NSObjectController>(this) addObject:cocoon::internal::native_id(object)];
    }

    Object ObjectController::default_fetch_request() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSObjectController>(this) defaultFetchRequest]);
    }

    void ObjectController::fetch(const Object& sender) const
    {
        [cocoon::internal::ns<::NSObjectController>(this) fetch:cocoon::internal::native_id(sender)];
    }

    bool ObjectController::fetch_with_request(const Object& fetch_request, bool merge) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSObjectController>(this) fetchWithRequest:cocoon::internal::native_id(fetch_request) merge:static_cast<::BOOL>(merge) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    Object ObjectController::new_object() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSObjectController>(this) newObject]);
    }

    void ObjectController::prepare_content() const
    {
        [cocoon::internal::ns<::NSObjectController>(this) prepareContent];
    }

    void ObjectController::remove(const Object& sender) const
    {
        [cocoon::internal::ns<::NSObjectController>(this) remove:cocoon::internal::native_id(sender)];
    }

    void ObjectController::remove_object(const Object& object) const
    {
        [cocoon::internal::ns<::NSObjectController>(this) removeObject:cocoon::internal::native_id(object)];
    }

    bool ObjectController::validate_user_interface_item(const Object& item) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSObjectController>(this) validateUserInterfaceItem:cocoon::internal::native_id(item)]);
    }

    bool ObjectController::automatically_prepares_content() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSObjectController>(this) automaticallyPreparesContent]);
    }

    void ObjectController::set_automatically_prepares_content(bool value) const
    {
        [cocoon::internal::ns<::NSObjectController>(this) setAutomaticallyPreparesContent:static_cast<::BOOL>(value)];
    }

    bool ObjectController::can_add() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSObjectController>(this) canAdd]);
    }

    bool ObjectController::can_remove() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSObjectController>(this) canRemove]);
    }

    Object ObjectController::content() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSObjectController>(this) content]);
    }

    void ObjectController::set_content(const Object& value) const
    {
        [cocoon::internal::ns<::NSObjectController>(this) setContent:cocoon::internal::native_id(value)];
    }

    bool ObjectController::is_editable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSObjectController>(this) isEditable]);
    }

    void ObjectController::set_editable(bool value) const
    {
        [cocoon::internal::ns<::NSObjectController>(this) setEditable:static_cast<::BOOL>(value)];
    }

    std::string ObjectController::entity_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSObjectController>(this) entityName]);
    }

    void ObjectController::set_entity_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSObjectController>(this) setEntityName:cocoon::internal::to(value)];
    }

    Predicate ObjectController::fetch_predicate() const
    {
        return cocoon::internal::wrap<Predicate>([cocoon::internal::ns<::NSObjectController>(this) fetchPredicate]);
    }

    void ObjectController::set_fetch_predicate(const Predicate& value) const
    {
        [cocoon::internal::ns<::NSObjectController>(this) setFetchPredicate:cocoon::internal::native<::NSPredicate>(value)];
    }

    ManagedObjectContext ObjectController::managed_object_context() const
    {
        return cocoon::internal::wrap<ManagedObjectContext>([cocoon::internal::ns<::NSObjectController>(this) managedObjectContext]);
    }

    void ObjectController::set_managed_object_context(const ManagedObjectContext& value) const
    {
        [cocoon::internal::ns<::NSObjectController>(this) setManagedObjectContext:cocoon::internal::native<::NSManagedObjectContext>(value)];
    }

    std::string ObjectController::object_class() const
    {
        return cocoon::internal::from(NSStringFromClass([cocoon::internal::ns<::NSObjectController>(this) objectClass]));
    }

    void ObjectController::set_object_class(const std::string& value) const
    {
        [cocoon::internal::ns<::NSObjectController>(this) setObjectClass:NSClassFromString(cocoon::internal::to(value))];
    }

    std::vector<Object> ObjectController::selected_objects() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSObjectController>(this) selectedObjects], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    Object ObjectController::selection() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSObjectController>(this) selection]);
    }

    bool ObjectController::uses_lazy_fetching() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSObjectController>(this) usesLazyFetching]);
    }

    void ObjectController::set_uses_lazy_fetching(bool value) const
    {
        [cocoon::internal::ns<::NSObjectController>(this) setUsesLazyFetching:static_cast<::BOOL>(value)];
    }
}
