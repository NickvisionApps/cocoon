#include "generated/managed_object_context.h"
#include "internal.h"

namespace cocoon
{
    ManagedObjectContext::ManagedObjectContext(ManagedObjectContextConcurrencyType ct) : ManagedObjectContext(Adopt{cocoon::internal::retain([[::NSManagedObjectContext alloc] initWithConcurrencyType:static_cast<::NSManagedObjectContextConcurrencyType>(ct)])})
    {
    }

    ManagedObjectContext::ManagedObjectContext() : ManagedObjectContext(Adopt{cocoon::internal::retain([[::NSManagedObjectContext alloc] init])})
    {
    }

    ManagedObjectContext::ManagedObjectContext(std::nullptr_t) : Object(nullptr)
    {
    }

    ManagedObjectContext::ManagedObjectContext(Adopt adopt) : Object(adopt)
    {
    }

    void ManagedObjectContext::assign_object(const Object& object, const Object& store) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) assignObject:cocoon::internal::native_id(object) toPersistentStore:cocoon::internal::native_id(store)];
    }

    std::uint64_t ManagedObjectContext::count_for_fetch_request(const Object& request) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSManagedObjectContext>(this) countForFetchRequest:cocoon::internal::native_id(request) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<std::uint64_t>(__r);
    }

    void ManagedObjectContext::delete_object(const Object& object) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) deleteObject:cocoon::internal::native_id(object)];
    }

    void ManagedObjectContext::detect_conflicts_for_object(const Object& object) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) detectConflictsForObject:cocoon::internal::native_id(object)];
    }

    std::vector<Object> ManagedObjectContext::execute_fetch_request(const Object& request) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSManagedObjectContext>(this) executeFetchRequest:cocoon::internal::native_id(request) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_array<Object>(__r, [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    Object ManagedObjectContext::execute_request(const Object& request) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSManagedObjectContext>(this) executeRequest:cocoon::internal::native_id(request) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Object>(__r);
    }

    Object ManagedObjectContext::existing_object_with_id(const Object& object_id) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSManagedObjectContext>(this) existingObjectWithID:cocoon::internal::native_id(object_id) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Object>(__r);
    }

    void ManagedObjectContext::insert_object(const Object& object) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) insertObject:cocoon::internal::native_id(object)];
    }

    void ManagedObjectContext::merge_changes_from_context_did_save_notification(const Notification& notification) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) mergeChangesFromContextDidSaveNotification:cocoon::internal::native<::NSNotification>(notification)];
    }

    void ManagedObjectContext::merge_changes_from_remote_context_save(const std::vector<std::pair<Object, Object>>& change_notification_data, const std::vector<ManagedObjectContext>& contexts)
    {
        [::NSManagedObjectContext mergeChangesFromRemoteContextSave:cocoon::internal::to_dictionary(change_notification_data, [](const Object& k) -> id
                                                                                                    {
                                                                                                        return cocoon::internal::native_id(k);
                                                                                                    },
                                                                                                    [](const Object& v) -> id
                                                                                                    {
                                                                                                        return cocoon::internal::native_id(v);
                                                                                                    })
                                                       intoContexts:cocoon::internal::to_array(contexts, [](const ManagedObjectContext& e) -> id
                                                                                               {
                                                                                                   return cocoon::internal::native<::NSManagedObjectContext>(e);
                                                                                               })];
    }

    Object ManagedObjectContext::object_registered_for_id(const Object& object_id) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSManagedObjectContext>(this) objectRegisteredForID:cocoon::internal::native_id(object_id)]);
    }

    Object ManagedObjectContext::object_with_id(const Object& object_id) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSManagedObjectContext>(this) objectWithID:cocoon::internal::native_id(object_id)]);
    }

    void ManagedObjectContext::observe_value_for_key_path(const std::string& key_path, const Object& object, const std::map<std::string, Object>& change, void* context) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) observeValueForKeyPath:cocoon::internal::to(key_path)
                                                                            ofObject:cocoon::internal::native_id(object)
                                                                              change:cocoon::internal::to_dictionary(change, [](const std::string& k) -> id
                                                                                                                     {
                                                                                                                         return cocoon::internal::to(k);
                                                                                                                     },
                                                                                                                     [](const Object& v) -> id
                                                                                                                     {
                                                                                                                         return cocoon::internal::native_id(v);
                                                                                                                     })
                                                                             context:context];
    }

    bool ManagedObjectContext::obtain_permanent_i_ds_for_objects(const std::vector<Object>& objects) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSManagedObjectContext>(this) obtainPermanentIDsForObjects:cocoon::internal::to_array(objects, [](const Object& e) -> id
                                                                                                                                 {
                                                                                                                                     return cocoon::internal::native_id(e);
                                                                                                                                 })
                                                                                                error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    void ManagedObjectContext::perform_block(std::function<void()> block) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) performBlock:(block ? (void (^)(void)) ^ void() { block(); } : (void (^)(void))nil)];
    }

    void ManagedObjectContext::perform_block_and_wait(std::function<void()> block) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) performBlockAndWait:(block ? (void (^)(void)) ^ void() { block(); } : (void (^)(void))nil)];
    }

    void ManagedObjectContext::process_pending_changes() const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) processPendingChanges];
    }

    void ManagedObjectContext::redo() const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) redo];
    }

    void ManagedObjectContext::refresh_all_objects() const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) refreshAllObjects];
    }

    void ManagedObjectContext::refresh_object(const Object& object, bool flag) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) refreshObject:cocoon::internal::native_id(object) mergeChanges:static_cast<::BOOL>(flag)];
    }

    void ManagedObjectContext::reset() const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) reset];
    }

    void ManagedObjectContext::rollback() const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) rollback];
    }

    bool ManagedObjectContext::save() const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSManagedObjectContext>(this) save:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool ManagedObjectContext::set_query_generation_from_token(const Object& generation) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSManagedObjectContext>(this) setQueryGenerationFromToken:cocoon::internal::native_id(generation) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    void ManagedObjectContext::undo() const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) undo];
    }

    bool ManagedObjectContext::automatically_merges_changes_from_parent() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSManagedObjectContext>(this) automaticallyMergesChangesFromParent]);
    }

    void ManagedObjectContext::set_automatically_merges_changes_from_parent(bool value) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) setAutomaticallyMergesChangesFromParent:static_cast<::BOOL>(value)];
    }

    ManagedObjectContextConcurrencyType ManagedObjectContext::concurrency_type() const
    {
        return static_cast<ManagedObjectContextConcurrencyType>([cocoon::internal::ns<::NSManagedObjectContext>(this) concurrencyType]);
    }

    std::vector<Object> ManagedObjectContext::deleted_objects() const
    {
        return cocoon::internal::from_array<Object>([[cocoon::internal::ns<::NSManagedObjectContext>(this) deletedObjects] allObjects], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    bool ManagedObjectContext::has_changes() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSManagedObjectContext>(this) hasChanges]);
    }

    std::vector<Object> ManagedObjectContext::inserted_objects() const
    {
        return cocoon::internal::from_array<Object>([[cocoon::internal::ns<::NSManagedObjectContext>(this) insertedObjects] allObjects], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    Object ManagedObjectContext::merge_policy() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSManagedObjectContext>(this) mergePolicy]);
    }

    void ManagedObjectContext::set_merge_policy(const Object& value) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) setMergePolicy:cocoon::internal::native_id(value)];
    }

    std::string ManagedObjectContext::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSManagedObjectContext>(this) name]);
    }

    void ManagedObjectContext::set_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) setName:cocoon::internal::to(value)];
    }

    ManagedObjectContext ManagedObjectContext::parent_context() const
    {
        return cocoon::internal::wrap<ManagedObjectContext>([cocoon::internal::ns<::NSManagedObjectContext>(this) parentContext]);
    }

    void ManagedObjectContext::set_parent_context(const ManagedObjectContext& value) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) setParentContext:cocoon::internal::native<::NSManagedObjectContext>(value)];
    }

    Object ManagedObjectContext::persistent_store_coordinator() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSManagedObjectContext>(this) persistentStoreCoordinator]);
    }

    void ManagedObjectContext::set_persistent_store_coordinator(const Object& value) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) setPersistentStoreCoordinator:cocoon::internal::native_id(value)];
    }

    bool ManagedObjectContext::propagates_deletes_at_end_of_event() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSManagedObjectContext>(this) propagatesDeletesAtEndOfEvent]);
    }

    void ManagedObjectContext::set_propagates_deletes_at_end_of_event(bool value) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) setPropagatesDeletesAtEndOfEvent:static_cast<::BOOL>(value)];
    }

    Object ManagedObjectContext::query_generation_token() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSManagedObjectContext>(this) queryGenerationToken]);
    }

    std::vector<Object> ManagedObjectContext::registered_objects() const
    {
        return cocoon::internal::from_array<Object>([[cocoon::internal::ns<::NSManagedObjectContext>(this) registeredObjects] allObjects], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    bool ManagedObjectContext::retains_registered_objects() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSManagedObjectContext>(this) retainsRegisteredObjects]);
    }

    void ManagedObjectContext::set_retains_registered_objects(bool value) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) setRetainsRegisteredObjects:static_cast<::BOOL>(value)];
    }

    bool ManagedObjectContext::should_delete_inaccessible_faults() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSManagedObjectContext>(this) shouldDeleteInaccessibleFaults]);
    }

    void ManagedObjectContext::set_should_delete_inaccessible_faults(bool value) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) setShouldDeleteInaccessibleFaults:static_cast<::BOOL>(value)];
    }

    double ManagedObjectContext::staleness_interval() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSManagedObjectContext>(this) stalenessInterval]);
    }

    void ManagedObjectContext::set_staleness_interval(double value) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) setStalenessInterval:static_cast<::NSTimeInterval>(value)];
    }

    std::string ManagedObjectContext::transaction_author() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSManagedObjectContext>(this) transactionAuthor]);
    }

    void ManagedObjectContext::set_transaction_author(const std::string& value) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) setTransactionAuthor:cocoon::internal::to(value)];
    }

    UndoManager ManagedObjectContext::undo_manager() const
    {
        return cocoon::internal::wrap<UndoManager>([cocoon::internal::ns<::NSManagedObjectContext>(this) undoManager]);
    }

    void ManagedObjectContext::set_undo_manager(const UndoManager& value) const
    {
        [cocoon::internal::ns<::NSManagedObjectContext>(this) setUndoManager:cocoon::internal::native<::NSUndoManager>(value)];
    }

    std::vector<Object> ManagedObjectContext::updated_objects() const
    {
        return cocoon::internal::from_array<Object>([[cocoon::internal::ns<::NSManagedObjectContext>(this) updatedObjects] allObjects], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    std::vector<std::pair<Object, Object>> ManagedObjectContext::user_info() const
    {
        return cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>([cocoon::internal::ns<::NSManagedObjectContext>(this) userInfo], [](id k) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(k);
                                                                                         },
                                                                                         [](id v) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(v);
                                                                                         });
    }
}
