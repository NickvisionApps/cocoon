#include "generated/document.h"
#include "internal.h"

namespace cocoon
{
    Document::Document(const URL& url_or_nil, const URL& contents_url, const std::string& type_name) : Document(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                                                 {
                                                                                                                                     NSError* __error = nil;
                                                                                                                                     id __r = [[::NSDocument alloc] initForURL:cocoon::internal::native<::NSURL>(url_or_nil) withContentsOfURL:cocoon::internal::native<::NSURL>(contents_url) ofType:cocoon::internal::to(type_name) error:&__error];
                                                                                                                                     if (!__r && __error)
                                                                                                                                     {
                                                                                                                                         throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                                                                     }
                                                                                                                                     return __r;
                                                                                                                                 }())})
    {
    }

    Document::Document(const URL& url, const std::string& type_name) : Document(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                 {
                                                                                                     NSError* __error = nil;
                                                                                                     id __r = [[::NSDocument alloc] initWithContentsOfURL:cocoon::internal::native<::NSURL>(url) ofType:cocoon::internal::to(type_name) error:&__error];
                                                                                                     if (!__r && __error)
                                                                                                     {
                                                                                                         throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                                     }
                                                                                                     return __r;
                                                                                                 }())})
    {
    }

    Document::Document(const std::string& type_name) : Document(Adopt{cocoon::internal::retain([&]() -> id
                                                                                 {
                                                                                     NSError* __error = nil;
                                                                                     id __r = [[::NSDocument alloc] initWithType:cocoon::internal::to(type_name) error:&__error];
                                                                                     if (!__r && __error)
                                                                                     {
                                                                                         throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                     }
                                                                                     return __r;
                                                                                 }())})
    {
    }

    Document::Document() : Document(Adopt{cocoon::internal::retain([[::NSDocument alloc] init])})
    {
    }

    Document::Document(std::nullptr_t) : Object(nullptr)
    {
    }

    Document::Document(Adopt adopt) : Object(adopt)
    {
    }

    void Document::accommodate_presented_item_deletion_with_completion_handler(std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSDocument>(this) accommodatePresentedItemDeletionWithCompletionHandler:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a26_0) { completion_handler(cocoon::internal::wrap<Error>(a26_0)); } : (void (^)(::NSError*))nil)];
    }

    void Document::add_window_controller(const WindowController& window_controller) const
    {
        [cocoon::internal::ns<::NSDocument>(this) addWindowController:cocoon::internal::native<::NSWindowController>(window_controller)];
    }

    std::vector<std::string> Document::allowed_classes_for_restorable_state_key_path(const std::string& key_path)
    {
        return cocoon::internal::from_array<std::string>([::NSDocument allowedClassesForRestorableStateKeyPath:cocoon::internal::to(key_path)], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from(NSStringFromClass(e));
                                           });
    }

    void Document::autosave_document_with_delegate(const Object& delegate, const std::string& did_autosave_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSDocument>(this) autosaveDocumentWithDelegate:cocoon::internal::native_id(delegate) didAutosaveSelector:NSSelectorFromString(cocoon::internal::to(did_autosave_selector)) contextInfo:context_info];
    }

    void Document::autosave_with_implicit_cancellability(bool autosaving_is_implicitly_cancellable, std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSDocument>(this) autosaveWithImplicitCancellability:static_cast<::BOOL>(autosaving_is_implicitly_cancellable) completionHandler:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a27_0) { completion_handler(cocoon::internal::wrap<Error>(a27_0)); } : (void (^)(::NSError*))nil)];
    }

    void Document::browse_document_versions(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDocument>(this) browseDocumentVersions:cocoon::internal::native_id(sender)];
    }

    bool Document::can_asynchronously_write_to_url(const URL& url, const std::string& type_name, SaveOperationType save_operation) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) canAsynchronouslyWriteToURL:cocoon::internal::native<::NSURL>(url) ofType:cocoon::internal::to(type_name) forSaveOperation:static_cast<::NSSaveOperationType>(save_operation)]);
    }

    void Document::can_close_document_with_delegate(const Object& delegate, const std::string& should_close_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSDocument>(this) canCloseDocumentWithDelegate:cocoon::internal::native_id(delegate) shouldCloseSelector:NSSelectorFromString(cocoon::internal::to(should_close_selector)) contextInfo:context_info];
    }

    bool Document::can_concurrently_read_documents_of_type(const std::string& type_name)
    {
        return static_cast<bool>([::NSDocument canConcurrentlyReadDocumentsOfType:cocoon::internal::to(type_name)]);
    }

    Object Document::change_count_token_for_save_operation(SaveOperationType save_operation) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSDocument>(this) changeCountTokenForSaveOperation:static_cast<::NSSaveOperationType>(save_operation)]);
    }

    bool Document::check_autosaving_safety_and_return_error() const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocument>(this) checkAutosavingSafetyAndReturnError:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    void Document::close() const
    {
        [cocoon::internal::ns<::NSDocument>(this) close];
    }

    void Document::continue_activity_using_block(std::function<void()> block) const
    {
        [cocoon::internal::ns<::NSDocument>(this) continueActivityUsingBlock:(block ? (void (^)(void)) ^ void() { block(); } : (void (^)(void))nil)];
    }

    void Document::continue_asynchronous_work_on_main_thread_using_block(std::function<void()> block) const
    {
        [cocoon::internal::ns<::NSDocument>(this) continueAsynchronousWorkOnMainThreadUsingBlock:(block ? (void (^)(void)) ^ void() { block(); } : (void (^)(void))nil)];
    }

    std::vector<std::uint8_t> Document::data_of_type(const std::string& type_name) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocument>(this) dataOfType:cocoon::internal::to(type_name) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_data(__r);
    }

    std::string Document::default_draft_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDocument>(this) defaultDraftName]);
    }

    Document Document::duplicate_and_return_error() const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocument>(this) duplicateAndReturnError:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Document>(__r);
    }

    void Document::duplicate_document(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDocument>(this) duplicateDocument:cocoon::internal::native_id(sender)];
    }

    void Document::duplicate_document_with_delegate(const Object& delegate, const std::string& did_duplicate_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSDocument>(this) duplicateDocumentWithDelegate:cocoon::internal::native_id(delegate) didDuplicateSelector:NSSelectorFromString(cocoon::internal::to(did_duplicate_selector)) contextInfo:context_info];
    }

    void Document::encode_restorable_state_with_coder(const Coder& coder) const
    {
        [cocoon::internal::ns<::NSDocument>(this) encodeRestorableStateWithCoder:cocoon::internal::native<::NSCoder>(coder)];
    }

    void Document::encode_restorable_state_with_coder(const Coder& coder, const OperationQueue& queue) const
    {
        [cocoon::internal::ns<::NSDocument>(this) encodeRestorableStateWithCoder:cocoon::internal::native<::NSCoder>(coder) backgroundQueue:cocoon::internal::native<::NSOperationQueue>(queue)];
    }

    std::map<std::string, Object> Document::file_attributes_to_write_to_url(const URL& url, const std::string& type_name, SaveOperationType save_operation, const URL& absolute_original_contents_url) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocument>(this) fileAttributesToWriteToURL:cocoon::internal::native<::NSURL>(url) ofType:cocoon::internal::to(type_name) forSaveOperation:static_cast<::NSSaveOperationType>(save_operation) originalContentsURL:cocoon::internal::native<::NSURL>(absolute_original_contents_url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>(__r, [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    std::string Document::file_name_extension_for_type(const std::string& type_name, SaveOperationType save_operation) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDocument>(this) fileNameExtensionForType:cocoon::internal::to(type_name) saveOperation:static_cast<::NSSaveOperationType>(save_operation)]);
    }

    FileWrapper Document::file_wrapper_of_type(const std::string& type_name) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocument>(this) fileWrapperOfType:cocoon::internal::to(type_name) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<FileWrapper>(__r);
    }

    Object Document::handle_close_script_command(const CloseCommand& command) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSDocument>(this) handleCloseScriptCommand:cocoon::internal::native<::NSCloseCommand>(command)]);
    }

    Object Document::handle_print_script_command(const ScriptCommand& command) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSDocument>(this) handlePrintScriptCommand:cocoon::internal::native<::NSScriptCommand>(command)]);
    }

    Object Document::handle_save_script_command(const ScriptCommand& command) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSDocument>(this) handleSaveScriptCommand:cocoon::internal::native<::NSScriptCommand>(command)]);
    }

    void Document::invalidate_restorable_state() const
    {
        [cocoon::internal::ns<::NSDocument>(this) invalidateRestorableState];
    }

    bool Document::is_native_type(const std::string& type)
    {
        return static_cast<bool>([::NSDocument isNativeType:cocoon::internal::to(type)]);
    }

    void Document::lock_document(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDocument>(this) lockDocument:cocoon::internal::native_id(sender)];
    }

    void Document::lock_document_with_completion_handler(std::function<void(bool)> completion_handler) const
    {
        [cocoon::internal::ns<::NSDocument>(this) lockDocumentWithCompletionHandler:(completion_handler ? (void (^)(BOOL)) ^ void(::BOOL a30_0) { completion_handler(static_cast<bool>(a30_0)); } : (void (^)(BOOL))nil)];
    }

    void Document::lock_with_completion_handler(std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSDocument>(this) lockWithCompletionHandler:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a31_0) { completion_handler(cocoon::internal::wrap<Error>(a31_0)); } : (void (^)(::NSError*))nil)];
    }

    void Document::make_window_controllers() const
    {
        [cocoon::internal::ns<::NSDocument>(this) makeWindowControllers];
    }

    void Document::move_document(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDocument>(this) moveDocument:cocoon::internal::native_id(sender)];
    }

    void Document::move_document_to_ubiquity_container(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDocument>(this) moveDocumentToUbiquityContainer:cocoon::internal::native_id(sender)];
    }

    void Document::move_document_with_completion_handler(std::function<void(bool)> completion_handler) const
    {
        [cocoon::internal::ns<::NSDocument>(this) moveDocumentWithCompletionHandler:(completion_handler ? (void (^)(BOOL)) ^ void(::BOOL a32_0) { completion_handler(static_cast<bool>(a32_0)); } : (void (^)(BOOL))nil)];
    }

    void Document::move_to_url(const URL& url, std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSDocument>(this) moveToURL:cocoon::internal::native<::NSURL>(url) completionHandler:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a33_0) { completion_handler(cocoon::internal::wrap<Error>(a33_0)); } : (void (^)(::NSError*))nil)];
    }

    void Document::perform_activity_with_synchronous_waiting(bool wait_synchronously, std::function<void(std::function<void()>)> block) const
    {
        [cocoon::internal::ns<::NSDocument>(this) performActivityWithSynchronousWaiting:static_cast<::BOOL>(wait_synchronously) usingBlock:(block ? (void (^)(void (^)(void))) ^ void(id a34_0) { block([&]() -> std::function<void()>
                                                                                                                                                                                          {
                                                                                                                                                                                              auto blk = (void (^)(void))(a34_0);
                                                                                                                                                                                              if (!blk)
                                                                                                                                                                                              {
                                                                                                                                                                                                  return {};
                                                                                                                                                                                              }
                                                                                                                                                                                              return [blk]() -> void
                                                                                                                                                                                              {
                                                                                                                                                                                                  blk();
                                                                                                                                                                                              };
                                                                                                                                                                                          }()); } : (void (^)(void (^)(void)))nil)];
    }

    void Document::perform_asynchronous_file_access_using_block(std::function<void(std::function<void()>)> block) const
    {
        [cocoon::internal::ns<::NSDocument>(this) performAsynchronousFileAccessUsingBlock:(block ? (void (^)(void (^)(void))) ^ void(id a36_0) { block([&]() -> std::function<void()>
                                                                                                                                         {
                                                                                                                                             auto blk = (void (^)(void))(a36_0);
                                                                                                                                             if (!blk)
                                                                                                                                             {
                                                                                                                                                 return {};
                                                                                                                                             }
                                                                                                                                             return [blk]() -> void
                                                                                                                                             {
                                                                                                                                                 blk();
                                                                                                                                             };
                                                                                                                                         }()); } : (void (^)(void (^)(void)))nil)];
    }

    void Document::perform_synchronous_file_access_using_block(std::function<void()> block) const
    {
        [cocoon::internal::ns<::NSDocument>(this) performSynchronousFileAccessUsingBlock:(block ? (void (^)(void)) ^ void() { block(); } : (void (^)(void))nil)];
    }

    bool Document::prepare_page_layout(const PageLayout& page_layout) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) preparePageLayout:cocoon::internal::native<::NSPageLayout>(page_layout)]);
    }

    bool Document::prepare_save_panel(const SavePanel& save_panel) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) prepareSavePanel:cocoon::internal::native<::NSSavePanel>(save_panel)]);
    }

    void Document::prepare_sharing_service_picker(const SharingServicePicker& sharing_service_picker) const
    {
        [cocoon::internal::ns<::NSDocument>(this) prepareSharingServicePicker:cocoon::internal::native<::NSSharingServicePicker>(sharing_service_picker)];
    }

    bool Document::present_error(const Error& error) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) presentError:cocoon::internal::native<::NSError>(error)]);
    }

    void Document::present_error(const Error& error, const Window& window, const Object& delegate, const std::string& did_present_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSDocument>(this) presentError:cocoon::internal::native<::NSError>(error) modalForWindow:cocoon::internal::native<::NSWindow>(window) delegate:cocoon::internal::native_id(delegate) didPresentSelector:NSSelectorFromString(cocoon::internal::to(did_present_selector)) contextInfo:context_info];
    }

    void Document::presented_item_did_change() const
    {
        [cocoon::internal::ns<::NSDocument>(this) presentedItemDidChange];
    }

    void Document::presented_item_did_change_ubiquity_attributes(const std::vector<std::string>& attributes) const
    {
        [cocoon::internal::ns<::NSDocument>(this) presentedItemDidChangeUbiquityAttributes:[NSSet setWithArray:cocoon::internal::to_array(attributes, [](const std::string& e) -> id
                                                                                                              {
                                                                                                                  return cocoon::internal::to(e);
                                                                                                              })]];
    }

    void Document::presented_item_did_gain_version(const FileVersion& version) const
    {
        [cocoon::internal::ns<::NSDocument>(this) presentedItemDidGainVersion:cocoon::internal::native<::NSFileVersion>(version)];
    }

    void Document::presented_item_did_lose_version(const FileVersion& version) const
    {
        [cocoon::internal::ns<::NSDocument>(this) presentedItemDidLoseVersion:cocoon::internal::native<::NSFileVersion>(version)];
    }

    void Document::presented_item_did_move_to_url(const URL& new_url) const
    {
        [cocoon::internal::ns<::NSDocument>(this) presentedItemDidMoveToURL:cocoon::internal::native<::NSURL>(new_url)];
    }

    void Document::presented_item_did_resolve_conflict_version(const FileVersion& version) const
    {
        [cocoon::internal::ns<::NSDocument>(this) presentedItemDidResolveConflictVersion:cocoon::internal::native<::NSFileVersion>(version)];
    }

    void Document::print_document(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDocument>(this) printDocument:cocoon::internal::native_id(sender)];
    }

    void Document::print_document_with_settings(const std::map<std::string, Object>& print_settings, bool show_print_panel, const Object& delegate, const std::string& did_print_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSDocument>(this) printDocumentWithSettings:cocoon::internal::to_dictionary(print_settings, [](const std::string& k) -> id
                                                                                {
                                                                                    return cocoon::internal::to(k);
                                                                                },
                                                                                [](const Object& v) -> id
                                                                                {
                                                                                    return cocoon::internal::native_id(v);
                                                                                })
                                               showPrintPanel:static_cast<::BOOL>(show_print_panel)
                                                     delegate:cocoon::internal::native_id(delegate)
                                             didPrintSelector:NSSelectorFromString(cocoon::internal::to(did_print_selector))
                                                  contextInfo:context_info];
    }

    PrintOperation Document::print_operation_with_settings(const std::map<std::string, Object>& print_settings) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocument>(this) printOperationWithSettings:cocoon::internal::to_dictionary(print_settings, [](const std::string& k) -> id
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
        return cocoon::internal::wrap<PrintOperation>(__r);
    }

    bool Document::read_from_data(const std::vector<std::uint8_t>& data, const std::string& type_name) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocument>(this) readFromData:cocoon::internal::to_data(data) ofType:cocoon::internal::to(type_name) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool Document::read_from_file_wrapper(const FileWrapper& file_wrapper, const std::string& type_name) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocument>(this) readFromFileWrapper:cocoon::internal::native<::NSFileWrapper>(file_wrapper) ofType:cocoon::internal::to(type_name) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool Document::read_from_url(const URL& url, const std::string& type_name) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocument>(this) readFromURL:cocoon::internal::native<::NSURL>(url) ofType:cocoon::internal::to(type_name) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    void Document::relinquish_presented_item_to_reader(std::function<void(std::function<void()>)> reader) const
    {
        [cocoon::internal::ns<::NSDocument>(this) relinquishPresentedItemToReader:(reader ? (void (^)(void (^)(void))) ^ void(id a39_0) { reader([&]() -> std::function<void()>
                                                                                                                                   {
                                                                                                                                       auto blk = (void (^)(void))(a39_0);
                                                                                                                                       if (!blk)
                                                                                                                                       {
                                                                                                                                           return {};
                                                                                                                                       }
                                                                                                                                       return [blk]() -> void
                                                                                                                                       {
                                                                                                                                           blk();
                                                                                                                                       };
                                                                                                                                   }()); } : (void (^)(void (^)(void)))nil)];
    }

    void Document::relinquish_presented_item_to_writer(std::function<void(std::function<void()>)> writer) const
    {
        [cocoon::internal::ns<::NSDocument>(this) relinquishPresentedItemToWriter:(writer ? (void (^)(void (^)(void))) ^ void(id a41_0) { writer([&]() -> std::function<void()>
                                                                                                                                   {
                                                                                                                                       auto blk = (void (^)(void))(a41_0);
                                                                                                                                       if (!blk)
                                                                                                                                       {
                                                                                                                                           return {};
                                                                                                                                       }
                                                                                                                                       return [blk]() -> void
                                                                                                                                       {
                                                                                                                                           blk();
                                                                                                                                       };
                                                                                                                                   }()); } : (void (^)(void (^)(void)))nil)];
    }

    void Document::remove_window_controller(const WindowController& window_controller) const
    {
        [cocoon::internal::ns<::NSDocument>(this) removeWindowController:cocoon::internal::native<::NSWindowController>(window_controller)];
    }

    void Document::rename_document(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDocument>(this) renameDocument:cocoon::internal::native_id(sender)];
    }

    void Document::restore_document_window_with_identifier(const std::string& identifier, const Coder& state, std::function<void(Window, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSDocument>(this) restoreDocumentWindowWithIdentifier:cocoon::internal::to(identifier) state:cocoon::internal::native<::NSCoder>(state) completionHandler:(completion_handler ? (void (^)(::NSWindow*, ::NSError*)) ^ void(::NSWindow * a43_0, ::NSError * a43_1) { completion_handler(cocoon::internal::wrap<Window>(a43_0), cocoon::internal::wrap<Error>(a43_1)); } : (void (^)(::NSWindow*, ::NSError*))nil)];
    }

    void Document::restore_state_with_coder(const Coder& coder) const
    {
        [cocoon::internal::ns<::NSDocument>(this) restoreStateWithCoder:cocoon::internal::native<::NSCoder>(coder)];
    }

    void Document::revert_document_to_saved(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDocument>(this) revertDocumentToSaved:cocoon::internal::native_id(sender)];
    }

    bool Document::revert_to_contents_of_url(const URL& url, const std::string& type_name) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocument>(this) revertToContentsOfURL:cocoon::internal::native<::NSURL>(url) ofType:cocoon::internal::to(type_name) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    void Document::run_modal_page_layout_with_print_info(const PrintInfo& print_info, const Object& delegate, const std::string& did_run_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSDocument>(this) runModalPageLayoutWithPrintInfo:cocoon::internal::native<::NSPrintInfo>(print_info) delegate:cocoon::internal::native_id(delegate) didRunSelector:NSSelectorFromString(cocoon::internal::to(did_run_selector)) contextInfo:context_info];
    }

    void Document::run_modal_print_operation(const PrintOperation& print_operation, const Object& delegate, const std::string& did_run_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSDocument>(this) runModalPrintOperation:cocoon::internal::native<::NSPrintOperation>(print_operation) delegate:cocoon::internal::native_id(delegate) didRunSelector:NSSelectorFromString(cocoon::internal::to(did_run_selector)) contextInfo:context_info];
    }

    void Document::run_modal_save_panel_for_save_operation(SaveOperationType save_operation, const Object& delegate, const std::string& did_save_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSDocument>(this) runModalSavePanelForSaveOperation:static_cast<::NSSaveOperationType>(save_operation) delegate:cocoon::internal::native_id(delegate) didSaveSelector:NSSelectorFromString(cocoon::internal::to(did_save_selector)) contextInfo:context_info];
    }

    void Document::run_page_layout(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDocument>(this) runPageLayout:cocoon::internal::native_id(sender)];
    }

    void Document::save_document(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDocument>(this) saveDocument:cocoon::internal::native_id(sender)];
    }

    void Document::save_document_as(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDocument>(this) saveDocumentAs:cocoon::internal::native_id(sender)];
    }

    void Document::save_document_to(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDocument>(this) saveDocumentTo:cocoon::internal::native_id(sender)];
    }

    void Document::save_document_to_pdf(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDocument>(this) saveDocumentToPDF:cocoon::internal::native_id(sender)];
    }

    void Document::save_document_with_delegate(const Object& delegate, const std::string& did_save_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSDocument>(this) saveDocumentWithDelegate:cocoon::internal::native_id(delegate) didSaveSelector:NSSelectorFromString(cocoon::internal::to(did_save_selector)) contextInfo:context_info];
    }

    void Document::save_presented_item_changes_with_completion_handler(std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSDocument>(this) savePresentedItemChangesWithCompletionHandler:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a44_0) { completion_handler(cocoon::internal::wrap<Error>(a44_0)); } : (void (^)(::NSError*))nil)];
    }

    void Document::save_to_url(const URL& url, const std::string& type_name, SaveOperationType save_operation, std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSDocument>(this) saveToURL:cocoon::internal::native<::NSURL>(url) ofType:cocoon::internal::to(type_name) forSaveOperation:static_cast<::NSSaveOperationType>(save_operation) completionHandler:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a45_0) { completion_handler(cocoon::internal::wrap<Error>(a45_0)); } : (void (^)(::NSError*))nil)];
    }

    void Document::save_to_url(const URL& url, const std::string& type_name, SaveOperationType save_operation, const Object& delegate, const std::string& did_save_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSDocument>(this) saveToURL:cocoon::internal::native<::NSURL>(url) ofType:cocoon::internal::to(type_name) forSaveOperation:static_cast<::NSSaveOperationType>(save_operation) delegate:cocoon::internal::native_id(delegate) didSaveSelector:NSSelectorFromString(cocoon::internal::to(did_save_selector)) contextInfo:context_info];
    }

    void Document::schedule_autosaving() const
    {
        [cocoon::internal::ns<::NSDocument>(this) scheduleAutosaving];
    }

    void Document::set_display_name(const std::string& display_name_or_nil) const
    {
        [cocoon::internal::ns<::NSDocument>(this) setDisplayName:cocoon::internal::to(display_name_or_nil)];
    }

    void Document::set_window(const Window& window) const
    {
        [cocoon::internal::ns<::NSDocument>(this) setWindow:cocoon::internal::native<::NSWindow>(window)];
    }

    void Document::share_document_with_sharing_service(const SharingService& sharing_service, std::function<void(bool)> completion_handler) const
    {
        [cocoon::internal::ns<::NSDocument>(this) shareDocumentWithSharingService:cocoon::internal::native<::NSSharingService>(sharing_service) completionHandler:(completion_handler ? (void (^)(BOOL)) ^ void(::BOOL a46_0) { completion_handler(static_cast<bool>(a46_0)); } : (void (^)(BOOL))nil)];
    }

    bool Document::should_change_print_info(const PrintInfo& new_print_info) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) shouldChangePrintInfo:cocoon::internal::native<::NSPrintInfo>(new_print_info)]);
    }

    void Document::should_close_window_controller(const WindowController& window_controller, const Object& delegate, const std::string& should_close_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSDocument>(this) shouldCloseWindowController:cocoon::internal::native<::NSWindowController>(window_controller) delegate:cocoon::internal::native_id(delegate) shouldCloseSelector:NSSelectorFromString(cocoon::internal::to(should_close_selector)) contextInfo:context_info];
    }

    void Document::show_windows() const
    {
        [cocoon::internal::ns<::NSDocument>(this) showWindows];
    }

    void Document::stop_browsing_versions_with_completion_handler(std::function<void()> completion_handler) const
    {
        [cocoon::internal::ns<::NSDocument>(this) stopBrowsingVersionsWithCompletionHandler:(completion_handler ? (void (^)(void)) ^ void() { completion_handler(); } : (void (^)(void))nil)];
    }

    void Document::unblock_user_interaction() const
    {
        [cocoon::internal::ns<::NSDocument>(this) unblockUserInteraction];
    }

    void Document::unlock_document(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDocument>(this) unlockDocument:cocoon::internal::native_id(sender)];
    }

    void Document::unlock_document_with_completion_handler(std::function<void(bool)> completion_handler) const
    {
        [cocoon::internal::ns<::NSDocument>(this) unlockDocumentWithCompletionHandler:(completion_handler ? (void (^)(BOOL)) ^ void(::BOOL a48_0) { completion_handler(static_cast<bool>(a48_0)); } : (void (^)(BOOL))nil)];
    }

    void Document::unlock_with_completion_handler(std::function<void(Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSDocument>(this) unlockWithCompletionHandler:(completion_handler ? (void (^)(::NSError*)) ^ void(::NSError * a49_0) { completion_handler(cocoon::internal::wrap<Error>(a49_0)); } : (void (^)(::NSError*))nil)];
    }

    void Document::update_change_count(DocumentChangeType change) const
    {
        [cocoon::internal::ns<::NSDocument>(this) updateChangeCount:static_cast<::NSDocumentChangeType>(change)];
    }

    void Document::update_change_count_with_token(const Object& change_count_token, SaveOperationType save_operation) const
    {
        [cocoon::internal::ns<::NSDocument>(this) updateChangeCountWithToken:cocoon::internal::native_id(change_count_token) forSaveOperation:static_cast<::NSSaveOperationType>(save_operation)];
    }

    void Document::update_user_activity_state(const UserActivity& activity) const
    {
        [cocoon::internal::ns<::NSDocument>(this) updateUserActivityState:cocoon::internal::native<::NSUserActivity>(activity)];
    }

    bool Document::validate_user_interface_item(const Object& item) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) validateUserInterfaceItem:cocoon::internal::native_id(item)]);
    }

    void Document::will_not_present_error(const Error& error) const
    {
        [cocoon::internal::ns<::NSDocument>(this) willNotPresentError:cocoon::internal::native<::NSError>(error)];
    }

    Error Document::will_present_error(const Error& error) const
    {
        return cocoon::internal::wrap<Error>([cocoon::internal::ns<::NSDocument>(this) willPresentError:cocoon::internal::native<::NSError>(error)]);
    }

    void Document::window_controller_did_load_nib(const WindowController& window_controller) const
    {
        [cocoon::internal::ns<::NSDocument>(this) windowControllerDidLoadNib:cocoon::internal::native<::NSWindowController>(window_controller)];
    }

    void Document::window_controller_will_load_nib(const WindowController& window_controller) const
    {
        [cocoon::internal::ns<::NSDocument>(this) windowControllerWillLoadNib:cocoon::internal::native<::NSWindowController>(window_controller)];
    }

    std::vector<std::string> Document::writable_types_for_save_operation(SaveOperationType save_operation) const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDocument>(this) writableTypesForSaveOperation:static_cast<::NSSaveOperationType>(save_operation)], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    bool Document::write_safely_to_url(const URL& url, const std::string& type_name, SaveOperationType save_operation) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocument>(this) writeSafelyToURL:cocoon::internal::native<::NSURL>(url) ofType:cocoon::internal::to(type_name) forSaveOperation:static_cast<::NSSaveOperationType>(save_operation) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool Document::write_to_url(const URL& url, const std::string& type_name) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocument>(this) writeToURL:cocoon::internal::native<::NSURL>(url) ofType:cocoon::internal::to(type_name) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool Document::write_to_url(const URL& url, const std::string& type_name, SaveOperationType save_operation, const URL& absolute_original_contents_url) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocument>(this) writeToURL:cocoon::internal::native<::NSURL>(url) ofType:cocoon::internal::to(type_name) forSaveOperation:static_cast<::NSSaveOperationType>(save_operation) originalContentsURL:cocoon::internal::native<::NSURL>(absolute_original_contents_url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    PrintOperation Document::pdf_print_operation() const
    {
        return cocoon::internal::wrap<PrintOperation>([cocoon::internal::ns<::NSDocument>(this) PDFPrintOperation]);
    }

    bool Document::allows_document_sharing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) allowsDocumentSharing]);
    }

    URL Document::autosaved_contents_file_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSDocument>(this) autosavedContentsFileURL]);
    }

    void Document::set_autosaved_contents_file_url(const URL& value) const
    {
        [cocoon::internal::ns<::NSDocument>(this) setAutosavedContentsFileURL:cocoon::internal::native<::NSURL>(value)];
    }

    bool Document::autosaves_drafts()
    {
        return static_cast<bool>([::NSDocument autosavesDrafts]);
    }

    bool Document::autosaves_in_place()
    {
        return static_cast<bool>([::NSDocument autosavesInPlace]);
    }

    std::string Document::autosaving_file_type() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDocument>(this) autosavingFileType]);
    }

    bool Document::autosaving_is_implicitly_cancellable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) autosavingIsImplicitlyCancellable]);
    }

    URL Document::backup_file_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSDocument>(this) backupFileURL]);
    }

    bool Document::is_browsing_versions() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) isBrowsingVersions]);
    }

    std::string Document::display_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDocument>(this) displayName]);
    }

    bool Document::is_document_edited() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) isDocumentEdited]);
    }

    bool Document::is_draft() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) isDraft]);
    }

    void Document::set_draft(bool value) const
    {
        [cocoon::internal::ns<::NSDocument>(this) setDraft:static_cast<::BOOL>(value)];
    }

    bool Document::is_entire_file_loaded() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) isEntireFileLoaded]);
    }

    Date Document::file_modification_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSDocument>(this) fileModificationDate]);
    }

    void Document::set_file_modification_date(const Date& value) const
    {
        [cocoon::internal::ns<::NSDocument>(this) setFileModificationDate:cocoon::internal::native<::NSDate>(value)];
    }

    bool Document::file_name_extension_was_hidden_in_last_run_save_panel() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) fileNameExtensionWasHiddenInLastRunSavePanel]);
    }

    std::string Document::file_type() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDocument>(this) fileType]);
    }

    void Document::set_file_type(const std::string& value) const
    {
        [cocoon::internal::ns<::NSDocument>(this) setFileType:cocoon::internal::to(value)];
    }

    std::string Document::file_type_from_last_run_save_panel() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDocument>(this) fileTypeFromLastRunSavePanel]);
    }

    URL Document::file_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSDocument>(this) fileURL]);
    }

    void Document::set_file_url(const URL& value) const
    {
        [cocoon::internal::ns<::NSDocument>(this) setFileURL:cocoon::internal::native<::NSURL>(value)];
    }

    bool Document::has_unautosaved_changes() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) hasUnautosavedChanges]);
    }

    bool Document::has_undo_manager() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) hasUndoManager]);
    }

    void Document::set_has_undo_manager(bool value) const
    {
        [cocoon::internal::ns<::NSDocument>(this) setHasUndoManager:static_cast<::BOOL>(value)];
    }

    bool Document::is_in_viewing_mode() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) isInViewingMode]);
    }

    bool Document::keep_backup_file() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) keepBackupFile]);
    }

    std::string Document::last_component_of_file_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDocument>(this) lastComponentOfFileName]);
    }

    void Document::set_last_component_of_file_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSDocument>(this) setLastComponentOfFileName:cocoon::internal::to(value)];
    }

    bool Document::is_locked() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) isLocked]);
    }

    ScriptObjectSpecifier Document::object_specifier() const
    {
        return cocoon::internal::wrap<ScriptObjectSpecifier>([cocoon::internal::ns<::NSDocument>(this) objectSpecifier]);
    }

    std::vector<std::string> Document::observed_presented_item_ubiquity_attributes() const
    {
        return cocoon::internal::from_array<std::string>([[cocoon::internal::ns<::NSDocument>(this) observedPresentedItemUbiquityAttributes] allObjects], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    URL Document::presented_item_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSDocument>(this) presentedItemURL]);
    }

    bool Document::preserves_versions()
    {
        return static_cast<bool>([::NSDocument preservesVersions]);
    }

    std::vector<Object> Document::preview_representable_activity_items() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSDocument>(this) previewRepresentableActivityItems], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    void Document::set_preview_representable_activity_items(const std::vector<Object>& value) const
    {
        [cocoon::internal::ns<::NSDocument>(this) setPreviewRepresentableActivityItems:cocoon::internal::to_array(value, [](const Object& e) -> id
                                                                                      {
                                                                                          return cocoon::internal::native_id(e);
                                                                                      })];
    }

    PrintInfo Document::print_info() const
    {
        return cocoon::internal::wrap<PrintInfo>([cocoon::internal::ns<::NSDocument>(this) printInfo]);
    }

    void Document::set_print_info(const PrintInfo& value) const
    {
        [cocoon::internal::ns<::NSDocument>(this) setPrintInfo:cocoon::internal::native<::NSPrintInfo>(value)];
    }

    std::vector<std::string> Document::readable_types()
    {
        return cocoon::internal::from_array<std::string>([::NSDocument readableTypes], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Document::restorable_state_key_paths()
    {
        return cocoon::internal::from_array<std::string>([::NSDocument restorableStateKeyPaths], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    bool Document::save_panel_shows_file_formats_control() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) savePanelShowsFileFormatsControl]);
    }

    bool Document::should_run_save_panel_with_accessory_view() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocument>(this) shouldRunSavePanelWithAccessoryView]);
    }

    UndoManager Document::undo_manager() const
    {
        return cocoon::internal::wrap<UndoManager>([cocoon::internal::ns<::NSDocument>(this) undoManager]);
    }

    void Document::set_undo_manager(const UndoManager& value) const
    {
        [cocoon::internal::ns<::NSDocument>(this) setUndoManager:cocoon::internal::native<::NSUndoManager>(value)];
    }

    UserActivity Document::user_activity() const
    {
        return cocoon::internal::wrap<UserActivity>([cocoon::internal::ns<::NSDocument>(this) userActivity]);
    }

    void Document::set_user_activity(const UserActivity& value) const
    {
        [cocoon::internal::ns<::NSDocument>(this) setUserActivity:cocoon::internal::native<::NSUserActivity>(value)];
    }

    bool Document::uses_ubiquitous_storage()
    {
        return static_cast<bool>([::NSDocument usesUbiquitousStorage]);
    }

    std::vector<WindowController> Document::window_controllers() const
    {
        return cocoon::internal::from_array<WindowController>([cocoon::internal::ns<::NSDocument>(this) windowControllers], [](id e) -> WindowController
                                                {
                                                    return cocoon::internal::wrap<WindowController>((::NSWindowController*)e);
                                                });
    }

    Window Document::window_for_sheet() const
    {
        return cocoon::internal::wrap<Window>([cocoon::internal::ns<::NSDocument>(this) windowForSheet]);
    }

    std::string Document::window_nib_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDocument>(this) windowNibName]);
    }

    std::vector<std::string> Document::writable_types()
    {
        return cocoon::internal::from_array<std::string>([::NSDocument writableTypes], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }
}
