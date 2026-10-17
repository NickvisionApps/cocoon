#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Notification;
    class UndoManager;

    /**
     * @brief C++ handle for the Objective-C class `NSManagedObjectContext` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ManagedObjectContext managed_object_context;
     * managed_object_context.set_automatically_merges_changes_from_parent(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ManagedObjectContext managed_object_context{};
     * managed_object_context.set_automatically_merges_changes_from_parent(true);
     * auto automatically_merges_changes_from_parent = managed_object_context.automatically_merges_changes_from_parent();
     * managed_object_context.set_name("text");
     * auto name = managed_object_context.name();
     * managed_object_context.set_parent_context(cocoon::ManagedObjectContext());
     * auto parent_context = managed_object_context.parent_context();
     * managed_object_context.lock();
     * managed_object_context.merge_changes_from_context_did_save_notification(cocoon::Notification());
     * managed_object_context.process_pending_changes();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsmanagedobjectcontext
     */
    class ManagedObjectContext : public Object
    {
    public:
        /// @brief Creates a new `NSManagedObjectContext` instance and returns a handle to it.
        explicit ManagedObjectContext(ManagedObjectContextConcurrencyType ct);
        /// @brief Creates a new `NSManagedObjectContext` instance and returns a handle to it.
        explicit ManagedObjectContext();
        /// @brief Creates a null handle that refers to no native object.
        ManagedObjectContext(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ManagedObjectContext(Adopt adopt);
        /**
     * @brief Calls `-[NSManagedObjectContext assignObject:toPersistentStore:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @param store Argument converted to the Objective-C parameter of the same role.
     */
        void assign_object(const Object& object, const Object& store) const;
        /**
     * @brief Calls `-[NSManagedObjectContext countForFetchRequest:error:]`.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t count_for_fetch_request(const Object& request) const;
        /**
     * @brief Calls `-[NSManagedObjectContext deleteObject:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     */
        void delete_object(const Object& object) const;
        /**
     * @brief Calls `-[NSManagedObjectContext detectConflictsForObject:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     */
        void detect_conflicts_for_object(const Object& object) const;
        /**
     * @brief Calls `-[NSManagedObjectContext executeFetchRequest:error:]`.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<Object> execute_fetch_request(const Object& request) const;
        /**
     * @brief Calls `-[NSManagedObjectContext executeRequest:error:]`.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object execute_request(const Object& request) const;
        /**
     * @brief Calls `-[NSManagedObjectContext existingObjectWithID:error:]`.
     * @param object_id Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object existing_object_with_id(const Object& object_id) const;
        /**
     * @brief Calls `-[NSManagedObjectContext insertObject:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     */
        void insert_object(const Object& object) const;
        /**
     * @brief Calls `-[NSManagedObjectContext lock]`.
     */
        void lock() const;
        /**
     * @brief Calls `-[NSManagedObjectContext mergeChangesFromContextDidSaveNotification:]`.
     * @param notification Argument converted to the Objective-C parameter of the same role.
     */
        void merge_changes_from_context_did_save_notification(const Notification& notification) const;
        /**
     * @brief Calls `+[NSManagedObjectContext mergeChangesFromRemoteContextSave:intoContexts:]`.
     * @param change_notification_data Argument converted to the Objective-C parameter of the same role.
     * @param contexts Argument converted to the Objective-C parameter of the same role.
     */
        static void merge_changes_from_remote_context_save(const std::vector<std::pair<Object, Object>>& change_notification_data, const std::vector<ManagedObjectContext>& contexts);
        /**
     * @brief Calls `-[NSManagedObjectContext objectRegisteredForID:]`.
     * @param object_id Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object object_registered_for_id(const Object& object_id) const;
        /**
     * @brief Calls `-[NSManagedObjectContext objectWithID:]`.
     * @param object_id Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object object_with_id(const Object& object_id) const;
        /**
     * @brief Calls `-[NSManagedObjectContext observeValueForKeyPath:ofObject:change:context:]`.
     * @param key_path Argument converted to the Objective-C parameter of the same role.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @param change Argument converted to the Objective-C parameter of the same role.
     * @param context Argument converted to the Objective-C parameter of the same role.
     */
        void observe_value_for_key_path(const std::string& key_path, const Object& object, const std::map<std::string, Object>& change, void* context) const;
        /**
     * @brief Calls `-[NSManagedObjectContext obtainPermanentIDsForObjects:error:]`.
     * @param objects Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool obtain_permanent_i_ds_for_objects(const std::vector<Object>& objects) const;
        /**
     * @brief Calls `-[NSManagedObjectContext performBlock:]`.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void perform_block(std::function<void()> block) const;
        /**
     * @brief Calls `-[NSManagedObjectContext performBlockAndWait:]`.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void perform_block_and_wait(std::function<void()> block) const;
        /**
     * @brief Calls `-[NSManagedObjectContext processPendingChanges]`.
     */
        void process_pending_changes() const;
        /**
     * @brief Calls `-[NSManagedObjectContext redo]`.
     */
        void redo() const;
        /**
     * @brief Calls `-[NSManagedObjectContext refreshAllObjects]`.
     */
        void refresh_all_objects() const;
        /**
     * @brief Calls `-[NSManagedObjectContext refreshObject:mergeChanges:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     */
        void refresh_object(const Object& object, bool flag) const;
        /**
     * @brief Calls `-[NSManagedObjectContext reset]`.
     */
        void reset() const;
        /**
     * @brief Calls `-[NSManagedObjectContext rollback]`.
     */
        void rollback() const;
        /**
     * @brief Calls `-[NSManagedObjectContext save:]`.
     * @return The converted Objective-C result.
     */
        bool save() const;
        /**
     * @brief Calls `-[NSManagedObjectContext setQueryGenerationFromToken:error:]`.
     * @param generation Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_query_generation_from_token(const Object& generation) const;
        /**
     * @brief Calls `-[NSManagedObjectContext tryLock]`.
     * @return The converted Objective-C result.
     */
        bool try_lock() const;
        /**
     * @brief Calls `-[NSManagedObjectContext undo]`.
     */
        void undo() const;
        /**
     * @brief Calls `-[NSManagedObjectContext unlock]`.
     */
        void unlock() const;
        /**
     * @brief Returns the `automaticallyMergesChangesFromParent` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        bool automatically_merges_changes_from_parent() const;
        /**
     * @brief Sets the `automaticallyMergesChangesFromParent` property of `NSManagedObjectContext`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_automatically_merges_changes_from_parent(bool value) const;
        /**
     * @brief Returns the `concurrencyType` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        ManagedObjectContextConcurrencyType concurrency_type() const;
        /**
     * @brief Returns the `deletedObjects` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        std::vector<Object> deleted_objects() const;
        /**
     * @brief Returns the `hasChanges` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        bool has_changes() const;
        /**
     * @brief Returns the `insertedObjects` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        std::vector<Object> inserted_objects() const;
        /**
     * @brief Returns the `mergePolicy` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        Object merge_policy() const;
        /**
     * @brief Sets the `mergePolicy` property of `NSManagedObjectContext`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_merge_policy(const Object& value) const;
        /**
     * @brief Returns the `name` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Sets the `name` property of `NSManagedObjectContext`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_name(const std::string& value) const;
        /**
     * @brief Returns the `parentContext` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        ManagedObjectContext parent_context() const;
        /**
     * @brief Sets the `parentContext` property of `NSManagedObjectContext`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_parent_context(const ManagedObjectContext& value) const;
        /**
     * @brief Returns the `persistentStoreCoordinator` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        Object persistent_store_coordinator() const;
        /**
     * @brief Sets the `persistentStoreCoordinator` property of `NSManagedObjectContext`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_persistent_store_coordinator(const Object& value) const;
        /**
     * @brief Returns the `propagatesDeletesAtEndOfEvent` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        bool propagates_deletes_at_end_of_event() const;
        /**
     * @brief Sets the `propagatesDeletesAtEndOfEvent` property of `NSManagedObjectContext`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_propagates_deletes_at_end_of_event(bool value) const;
        /**
     * @brief Returns the `queryGenerationToken` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        Object query_generation_token() const;
        /**
     * @brief Returns the `registeredObjects` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        std::vector<Object> registered_objects() const;
        /**
     * @brief Returns the `retainsRegisteredObjects` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        bool retains_registered_objects() const;
        /**
     * @brief Sets the `retainsRegisteredObjects` property of `NSManagedObjectContext`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_retains_registered_objects(bool value) const;
        /**
     * @brief Returns the `shouldDeleteInaccessibleFaults` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        bool should_delete_inaccessible_faults() const;
        /**
     * @brief Sets the `shouldDeleteInaccessibleFaults` property of `NSManagedObjectContext`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_should_delete_inaccessible_faults(bool value) const;
        /**
     * @brief Returns the `stalenessInterval` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        double staleness_interval() const;
        /**
     * @brief Sets the `stalenessInterval` property of `NSManagedObjectContext`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_staleness_interval(double value) const;
        /**
     * @brief Returns the `transactionAuthor` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        std::string transaction_author() const;
        /**
     * @brief Sets the `transactionAuthor` property of `NSManagedObjectContext`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_transaction_author(const std::string& value) const;
        /**
     * @brief Returns the `undoManager` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        UndoManager undo_manager() const;
        /**
     * @brief Sets the `undoManager` property of `NSManagedObjectContext`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_undo_manager(const UndoManager& value) const;
        /**
     * @brief Returns the `updatedObjects` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        std::vector<Object> updated_objects() const;
        /**
     * @brief Returns the `userInfo` property of `NSManagedObjectContext`.
     * @return The converted Objective-C result.
     */
        std::vector<std::pair<Object, Object>> user_info() const;
    };
}
