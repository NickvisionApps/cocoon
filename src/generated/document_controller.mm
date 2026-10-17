#include "generated/document_controller.h"
#include "internal.h"

namespace cocoon
{
    DocumentController::DocumentController() : DocumentController(Adopt{cocoon::internal::retain([[::NSDocumentController alloc] init])})
    {
    }

    DocumentController::DocumentController(std::nullptr_t) : Object(nullptr)
    {
    }

    DocumentController::DocumentController(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<URL> DocumentController::ur_ls_from_running_open_panel() const
    {
        return cocoon::internal::from_array<URL>([cocoon::internal::ns<::NSDocumentController>(this) URLsFromRunningOpenPanel], [](id e) -> URL
                                   {
                                       return cocoon::internal::wrap<URL>((::NSURL*)e);
                                   });
    }

    void DocumentController::add_document(const Document& document) const
    {
        [cocoon::internal::ns<::NSDocumentController>(this) addDocument:cocoon::internal::native<::NSDocument>(document)];
    }

    void DocumentController::begin_open_panel(const OpenPanel& open_panel, const std::vector<std::string>& in_types, std::function<void(std::int64_t)> completion_handler) const
    {
        [cocoon::internal::ns<::NSDocumentController>(this) beginOpenPanel:cocoon::internal::native<::NSOpenPanel>(open_panel)
                                                    forTypes:cocoon::internal::to_array(in_types, [](const std::string& e) -> id
                                                                          {
                                                                              return cocoon::internal::to(e);
                                                                          })
                                           completionHandler:(completion_handler ? (void (^)(::NSInteger)) ^ void(::NSInteger a50_0) { completion_handler(static_cast<std::int64_t>(a50_0)); } : (void (^)(::NSInteger))nil)];
    }

    void DocumentController::begin_open_panel_with_completion_handler(std::function<void(std::vector<URL>)> completion_handler) const
    {
        [cocoon::internal::ns<::NSDocumentController>(this) beginOpenPanelWithCompletionHandler:(completion_handler ? (void (^)(NSArray<NSURL*>*)) ^ void(NSArray * a51_0) { completion_handler(cocoon::internal::from_array<URL>(a51_0, [](id e) -> URL
                                                                                                                                                                                                      {
                                                                                                                                                                                                          return cocoon::internal::wrap<URL>((::NSURL*)e);
                                                                                                                                                                                                      })); } : (void (^)(NSArray<NSURL*>*))nil)];
    }

    void DocumentController::clear_recent_documents(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDocumentController>(this) clearRecentDocuments:cocoon::internal::native_id(sender)];
    }

    void DocumentController::close_all_documents_with_delegate(const Object& delegate, const std::string& did_close_all_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSDocumentController>(this) closeAllDocumentsWithDelegate:cocoon::internal::native_id(delegate) didCloseAllSelector:NSSelectorFromString(cocoon::internal::to(did_close_all_selector)) contextInfo:context_info];
    }

    std::string DocumentController::display_name_for_type(const std::string& type_name) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDocumentController>(this) displayNameForType:cocoon::internal::to(type_name)]);
    }

    std::string DocumentController::document_class_for_type(const std::string& type_name) const
    {
        return cocoon::internal::from(NSStringFromClass([cocoon::internal::ns<::NSDocumentController>(this) documentClassForType:cocoon::internal::to(type_name)]));
    }

    Document DocumentController::document_for_url(const URL& url) const
    {
        return cocoon::internal::wrap<Document>([cocoon::internal::ns<::NSDocumentController>(this) documentForURL:cocoon::internal::native<::NSURL>(url)]);
    }

    Document DocumentController::document_for_window(const Window& window) const
    {
        return cocoon::internal::wrap<Document>([cocoon::internal::ns<::NSDocumentController>(this) documentForWindow:cocoon::internal::native<::NSWindow>(window)]);
    }

    Document DocumentController::duplicate_document_with_contents_of_url(const URL& url, bool duplicate_by_copying, const std::string& display_name_or_nil) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocumentController>(this) duplicateDocumentWithContentsOfURL:cocoon::internal::native<::NSURL>(url) copying:static_cast<::BOOL>(duplicate_by_copying) displayName:cocoon::internal::to(display_name_or_nil) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Document>(__r);
    }

    Document DocumentController::make_document_for_url(const URL& url_or_nil, const URL& contents_url, const std::string& type_name) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocumentController>(this) makeDocumentForURL:cocoon::internal::native<::NSURL>(url_or_nil) withContentsOfURL:cocoon::internal::native<::NSURL>(contents_url) ofType:cocoon::internal::to(type_name) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Document>(__r);
    }

    Document DocumentController::make_document_with_contents_of_url(const URL& url, const std::string& type_name) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocumentController>(this) makeDocumentWithContentsOfURL:cocoon::internal::native<::NSURL>(url) ofType:cocoon::internal::to(type_name) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Document>(__r);
    }

    Document DocumentController::make_untitled_document_of_type(const std::string& type_name) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocumentController>(this) makeUntitledDocumentOfType:cocoon::internal::to(type_name) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Document>(__r);
    }

    void DocumentController::new_document(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDocumentController>(this) newDocument:cocoon::internal::native_id(sender)];
    }

    void DocumentController::note_new_recent_document(const Document& document) const
    {
        [cocoon::internal::ns<::NSDocumentController>(this) noteNewRecentDocument:cocoon::internal::native<::NSDocument>(document)];
    }

    void DocumentController::note_new_recent_document_url(const URL& url) const
    {
        [cocoon::internal::ns<::NSDocumentController>(this) noteNewRecentDocumentURL:cocoon::internal::native<::NSURL>(url)];
    }

    void DocumentController::open_document(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDocumentController>(this) openDocument:cocoon::internal::native_id(sender)];
    }

    void DocumentController::open_document_with_contents_of_url(const URL& url, bool display_document, std::function<void(Document, bool, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSDocumentController>(this) openDocumentWithContentsOfURL:cocoon::internal::native<::NSURL>(url) display:static_cast<::BOOL>(display_document) completionHandler:(completion_handler ? (void (^)(::NSDocument*, BOOL, ::NSError*)) ^ void(::NSDocument * a52_0, ::BOOL a52_1, ::NSError * a52_2) { completion_handler(cocoon::internal::wrap<Document>(a52_0), static_cast<bool>(a52_1), cocoon::internal::wrap<Error>(a52_2)); } : (void (^)(::NSDocument*, BOOL, ::NSError*))nil)];
    }

    Document DocumentController::open_untitled_document_and_display(bool display_document) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocumentController>(this) openUntitledDocumentAndDisplay:static_cast<::BOOL>(display_document) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Document>(__r);
    }

    bool DocumentController::present_error(const Error& error) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocumentController>(this) presentError:cocoon::internal::native<::NSError>(error)]);
    }

    void DocumentController::present_error(const Error& error, const Window& window, const Object& delegate, const std::string& did_present_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSDocumentController>(this) presentError:cocoon::internal::native<::NSError>(error) modalForWindow:cocoon::internal::native<::NSWindow>(window) delegate:cocoon::internal::native_id(delegate) didPresentSelector:NSSelectorFromString(cocoon::internal::to(did_present_selector)) contextInfo:context_info];
    }

    void DocumentController::remove_document(const Document& document) const
    {
        [cocoon::internal::ns<::NSDocumentController>(this) removeDocument:cocoon::internal::native<::NSDocument>(document)];
    }

    void DocumentController::reopen_document_for_url(const URL& url_or_nil, const URL& contents_url, bool display_document, std::function<void(Document, bool, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSDocumentController>(this) reopenDocumentForURL:cocoon::internal::native<::NSURL>(url_or_nil) withContentsOfURL:cocoon::internal::native<::NSURL>(contents_url) display:static_cast<::BOOL>(display_document) completionHandler:(completion_handler ? (void (^)(::NSDocument*, BOOL, ::NSError*)) ^ void(::NSDocument * a53_0, ::BOOL a53_1, ::NSError * a53_2) { completion_handler(cocoon::internal::wrap<Document>(a53_0), static_cast<bool>(a53_1), cocoon::internal::wrap<Error>(a53_2)); } : (void (^)(::NSDocument*, BOOL, ::NSError*))nil)];
    }

    void DocumentController::review_unsaved_documents_with_alert_title(const std::string& title, bool cancellable, const Object& delegate, const std::string& did_review_all_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSDocumentController>(this) reviewUnsavedDocumentsWithAlertTitle:cocoon::internal::to(title) cancellable:static_cast<::BOOL>(cancellable) delegate:cocoon::internal::native_id(delegate) didReviewAllSelector:NSSelectorFromString(cocoon::internal::to(did_review_all_selector)) contextInfo:context_info];
    }

    std::int64_t DocumentController::run_modal_open_panel(const OpenPanel& open_panel, const std::vector<std::string>& types) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDocumentController>(this) runModalOpenPanel:cocoon::internal::native<::NSOpenPanel>(open_panel)
                                                                                        forTypes:cocoon::internal::to_array(types, [](const std::string& e) -> id
                                                                                                              {
                                                                                                                  return cocoon::internal::to(e);
                                                                                                              })]);
    }

    void DocumentController::save_all_documents(const Object& sender) const
    {
        [cocoon::internal::ns<::NSDocumentController>(this) saveAllDocuments:cocoon::internal::native_id(sender)];
    }

    MenuItem DocumentController::standard_share_menu_item() const
    {
        return cocoon::internal::wrap<MenuItem>([cocoon::internal::ns<::NSDocumentController>(this) standardShareMenuItem]);
    }

    std::string DocumentController::type_for_contents_of_url(const URL& url) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSDocumentController>(this) typeForContentsOfURL:cocoon::internal::native<::NSURL>(url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from(__r);
    }

    bool DocumentController::validate_user_interface_item(const Object& item) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocumentController>(this) validateUserInterfaceItem:cocoon::internal::native_id(item)]);
    }

    Error DocumentController::will_present_error(const Error& error) const
    {
        return cocoon::internal::wrap<Error>([cocoon::internal::ns<::NSDocumentController>(this) willPresentError:cocoon::internal::native<::NSError>(error)]);
    }

    bool DocumentController::allows_automatic_share_menu() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocumentController>(this) allowsAutomaticShareMenu]);
    }

    double DocumentController::autosaving_delay() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSDocumentController>(this) autosavingDelay]);
    }

    void DocumentController::set_autosaving_delay(double value) const
    {
        [cocoon::internal::ns<::NSDocumentController>(this) setAutosavingDelay:static_cast<::NSTimeInterval>(value)];
    }

    std::string DocumentController::current_directory() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDocumentController>(this) currentDirectory]);
    }

    Document DocumentController::current_document() const
    {
        return cocoon::internal::wrap<Document>([cocoon::internal::ns<::NSDocumentController>(this) currentDocument]);
    }

    std::string DocumentController::default_type() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDocumentController>(this) defaultType]);
    }

    std::vector<std::string> DocumentController::document_class_names() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSDocumentController>(this) documentClassNames], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<Document> DocumentController::documents() const
    {
        return cocoon::internal::from_array<Document>([cocoon::internal::ns<::NSDocumentController>(this) documents], [](id e) -> Document
                                        {
                                            return cocoon::internal::wrap<Document>((::NSDocument*)e);
                                        });
    }

    bool DocumentController::has_edited_documents() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDocumentController>(this) hasEditedDocuments]);
    }

    std::uint64_t DocumentController::maximum_recent_document_count() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSDocumentController>(this) maximumRecentDocumentCount]);
    }

    std::vector<URL> DocumentController::recent_document_urls() const
    {
        return cocoon::internal::from_array<URL>([cocoon::internal::ns<::NSDocumentController>(this) recentDocumentURLs], [](id e) -> URL
                                   {
                                       return cocoon::internal::wrap<URL>((::NSURL*)e);
                                   });
    }

    DocumentController DocumentController::shared_document_controller()
    {
        return cocoon::internal::wrap<DocumentController>([::NSDocumentController sharedDocumentController]);
    }
}
