#include "generated/persistent_document.h"
#include "internal.h"

namespace cocoon
{
    PersistentDocument::PersistentDocument() : PersistentDocument(Adopt{cocoon::internal::retain([[::NSPersistentDocument alloc] init])})
    {
    }

    PersistentDocument::PersistentDocument(std::nullptr_t) : Document(nullptr)
    {
    }

    PersistentDocument::PersistentDocument(Adopt adopt) : Document(adopt)
    {
    }

    bool PersistentDocument::configure_persistent_store_coordinator_for_url(const URL& url, const std::string& file_type, const std::string& configuration, const std::map<std::string, Object>& store_options) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSPersistentDocument>(this) configurePersistentStoreCoordinatorForURL:cocoon::internal::native<::NSURL>(url)
                                                                                            ofType:cocoon::internal::to(file_type)
                                                                                modelConfiguration:cocoon::internal::to(configuration)
                                                                                      storeOptions:cocoon::internal::to_dictionary(store_options, [](const std::string& k) -> id
                                                                                                                     {
                                                                                                                         return cocoon::internal::to(k);
                                                                                                                     },
                                                                                                                     [](const Object& v) -> id
                                                                                                                     {
                                                                                                                         return cocoon::internal::native_id(v);
                                                                                                                     })
                                                                                             error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    std::string PersistentDocument::persistent_store_type_for_file_type(const std::string& file_type) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPersistentDocument>(this) persistentStoreTypeForFileType:cocoon::internal::to(file_type)]);
    }

    bool PersistentDocument::read_from_url(const URL& absolute_url, const std::string& type_name) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSPersistentDocument>(this) readFromURL:cocoon::internal::native<::NSURL>(absolute_url) ofType:cocoon::internal::to(type_name) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool PersistentDocument::revert_to_contents_of_url(const URL& in_absolute_url, const std::string& in_type_name) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSPersistentDocument>(this) revertToContentsOfURL:cocoon::internal::native<::NSURL>(in_absolute_url) ofType:cocoon::internal::to(in_type_name) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool PersistentDocument::write_to_url(const URL& absolute_url, const std::string& type_name, SaveOperationType save_operation, const URL& absolute_original_contents_url) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSPersistentDocument>(this) writeToURL:cocoon::internal::native<::NSURL>(absolute_url) ofType:cocoon::internal::to(type_name) forSaveOperation:static_cast<::NSSaveOperationType>(save_operation) originalContentsURL:cocoon::internal::native<::NSURL>(absolute_original_contents_url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    ManagedObjectContext PersistentDocument::managed_object_context() const
    {
        return cocoon::internal::wrap<ManagedObjectContext>([cocoon::internal::ns<::NSPersistentDocument>(this) managedObjectContext]);
    }

    void PersistentDocument::set_managed_object_context(const ManagedObjectContext& value) const
    {
        [cocoon::internal::ns<::NSPersistentDocument>(this) setManagedObjectContext:cocoon::internal::native<::NSManagedObjectContext>(value)];
    }

    Object PersistentDocument::managed_object_model() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSPersistentDocument>(this) managedObjectModel]);
    }
}
