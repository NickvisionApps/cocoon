#pragma once

#include "generated/document.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class ManagedObjectContext;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSPersistentDocument` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Document.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PersistentDocument persistent_document;
     * persistent_document.set_managed_object_context(cocoon::ManagedObjectContext());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PersistentDocument persistent_document{};
     * persistent_document.set_managed_object_context(cocoon::ManagedObjectContext());
     * auto managed_object_context = persistent_document.managed_object_context();
     * persistent_document.persistent_store_type_for_file_type("text");
     * persistent_document.read_from_url(cocoon::URL(), "text");
     * persistent_document.revert_to_contents_of_url(cocoon::URL(), "text");
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspersistentdocument
     */
    class PersistentDocument : public Document
    {
    public:
        /// @brief Creates a new `NSPersistentDocument` instance and returns a handle to it.
        explicit PersistentDocument();
        /// @brief Creates a null handle that refers to no native object.
        PersistentDocument(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PersistentDocument(Adopt adopt);
        using Document::read_from_url;
        using Document::revert_to_contents_of_url;
        using Document::write_to_url;
        /**
     * @brief Calls `-[NSPersistentDocument configurePersistentStoreCoordinatorForURL:ofType:modelConfiguration:storeOptions:error:]`.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param file_type Argument converted to the Objective-C parameter of the same role.
     * @param configuration Argument converted to the Objective-C parameter of the same role.
     * @param store_options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool configure_persistent_store_coordinator_for_url(const URL& url, const std::string& file_type, const std::string& configuration, const std::map<std::string, Object>& store_options) const;
        /**
     * @brief Calls `-[NSPersistentDocument persistentStoreTypeForFileType:]`.
     * @param file_type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string persistent_store_type_for_file_type(const std::string& file_type) const;
        /**
     * @brief Calls `-[NSPersistentDocument readFromURL:ofType:error:]`.
     * @param absolute_url Argument converted to the Objective-C parameter of the same role.
     * @param type_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool read_from_url(const URL& absolute_url, const std::string& type_name) const;
        /**
     * @brief Calls `-[NSPersistentDocument revertToContentsOfURL:ofType:error:]`.
     * @param in_absolute_url Argument converted to the Objective-C parameter of the same role.
     * @param in_type_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool revert_to_contents_of_url(const URL& in_absolute_url, const std::string& in_type_name) const;
        /**
     * @brief Calls `-[NSPersistentDocument writeToURL:ofType:forSaveOperation:originalContentsURL:error:]`.
     * @param absolute_url Argument converted to the Objective-C parameter of the same role.
     * @param type_name Argument converted to the Objective-C parameter of the same role.
     * @param save_operation Argument converted to the Objective-C parameter of the same role.
     * @param absolute_original_contents_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool write_to_url(const URL& absolute_url, const std::string& type_name, SaveOperationType save_operation, const URL& absolute_original_contents_url) const;
        /**
     * @brief Returns the `managedObjectContext` property of `NSPersistentDocument`.
     * @return The converted Objective-C result.
     */
        ManagedObjectContext managed_object_context() const;
        /**
     * @brief Sets the `managedObjectContext` property of `NSPersistentDocument`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_managed_object_context(const ManagedObjectContext& value) const;
        /**
     * @brief Returns the `managedObjectModel` property of `NSPersistentDocument`.
     * @return The converted Objective-C result.
     */
        Object managed_object_model() const;
    };
}
