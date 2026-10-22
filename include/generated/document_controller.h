#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Document;
    class Error;
    class MenuItem;
    class OpenPanel;
    class URL;
    class Window;

    /**
     * @brief C++ handle for the Objective-C class `NSDocumentController` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DocumentController document_controller;
     * document_controller.set_autosaving_delay(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DocumentController document_controller{};
     * document_controller.set_autosaving_delay(1);
     * auto autosaving_delay = document_controller.autosaving_delay();
     * document_controller.ur_ls_from_running_open_panel();
     * document_controller.add_document(cocoon::Document());
     * document_controller.display_name_for_type("text");
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsdocumentcontroller
     */
    class DocumentController : public Object
    {
    public:
        /// @brief Creates a new `NSDocumentController` instance and returns a handle to it.
        explicit DocumentController();
        /// @brief Creates a null handle that refers to no native object.
        DocumentController(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DocumentController(Adopt adopt);
        /**
         * @brief Calls `-[NSDocumentController URLsFromRunningOpenPanel]`.
         * @details Present an application-modal open panel to the user and, if the user selects one or more files and indicates that they are to be opened, return an array of those files' URLs. Return nil otherwise. The default implementation of this method invokes -runModalOpenPanel:forTypes: after it has set up an open panel.
         * @return The converted Objective-C result.
         */
        std::vector<URL> ur_ls_from_running_open_panel() const;
        /**
         * @brief Calls `-[NSDocumentController addDocument:]`.
         * @details Add or remove a document from the list of open documents. You can override these methods if your application needs to customize what is done when documents are opened and closed. -addDocument is invoked by the default implementations of all NSDocumentController methods whose names start with "open." Your application can invoke -addDocument: manually if it creates a document using something other than one of NSDocument's "open" methods. -removeDocument is invoked by the default implementation of -[NSDocument close].
         * @param document Argument converted to the Objective-C parameter of the same role.
         */
        void add_document(const Document& document) const;
        /**
         * @brief Calls `-[NSDocumentController beginOpenPanel:forTypes:completionHandler:]`.
         * @details Present an open panel, which will always be non-modal, to the user, specifying a list of UTIs for openable files. Invoke the completion handler with NSOKButton or NSCancelButton depending on how the user dismisses the panel. You typically would not invoke this method directly. You can override it though if you need to customize the open panel before it gets displayed.
         * @param open_panel Argument converted to the Objective-C parameter of the same role.
         * @param in_types Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void begin_open_panel(const OpenPanel& open_panel, const std::vector<std::string>& in_types, std::function<void(std::int64_t)> completion_handler) const;
        /**
         * @brief Calls `-[NSDocumentController beginOpenPanelWithCompletionHandler:]`.
         * @details Present an open panel, which may or may not be application-modal, to the user and, if the user selects one or more files and indicates that they are to be opened, invoke the completion handler with an array of those files' URLs. Invoke the completion handler with nil otherwise. The default implementation of this method invokes -beginOpenPanel:forTypes:completionHandler:. However, for backward binary compatibility, it invokes -runModalOpenPanel:forTypes: instead if you override it in a subclass and not -beginOpenPanel:forTypes:completionHandler:. If you override -[NSDocumentController openDocument:], you would typically want to invoke this method instead of -beginOpenPanel:forTypes:completionHandler: or -URLsFromRunningOpenPanel directly. You typically would not override this method without calling super.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void begin_open_panel_with_completion_handler(std::function<void(std::vector<URL>)> completion_handler) const;
        /**
         * @brief Calls `-[NSDocumentController clearRecentDocuments:]`.
         * @details The action of the Open Recent menu's Clear Menu item.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void clear_recent_documents(const Object& sender) const;
        /**
         * @brief Calls `-[NSDocumentController closeAllDocumentsWithDelegate:didCloseAllSelector:contextInfo:]`.
         * @details For each open, modified, document present a document-modal alert panel asking whether the document should be saved and giving the option of canceling, not saving the document, or saving the document. Stop presenting alert panels if the user indicates cancellation in any one of them. The default implementation of this merely sends each open document -canCloseDocumentWithDelegate:shouldCloseSelector:contextInfo: and -close messages until one of them cannot be closed. The method selected by didCloseAllSelector must have the same signature as: - (void)documentController:(NSDocumentController )documentController didCloseAll:(BOOL)didCloseAll contextInfo:(void )contextInfo;
         * @param delegate Argument converted to the Objective-C parameter of the same role.
         * @param did_close_all_selector Argument converted to the Objective-C parameter of the same role.
         * @param context_info Argument converted to the Objective-C parameter of the same role.
         */
        void close_all_documents_with_delegate(const Object& delegate, const std::string& did_close_all_selector, void* context_info) const;
        /**
         * @brief Calls `-[NSDocumentController displayNameForType:]`.
         * @details Given a document type name, return a string describing the document type that is fit to present to the user, or nil for failure.
         * @param type_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string display_name_for_type(const std::string& type_name) const;
        /**
         * @brief Calls `-[NSDocumentController documentClassForType:]`.
         * @details Given a document type name, return the subclass of NSDocument that should be instantiated when opening a document of that type, or nil for failure.
         * @param type_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string document_class_for_type(const std::string& type_name) const;
        /**
         * @brief Calls `-[NSDocumentController documentForURL:]`.
         * @details Given a URL, return the open document whose file or file package is located by the URL, or nil if there is no such open document. The default implementation of this method queries each open document to find one whose URL matches, and returns the first one whose URL does match. For backward binary compatibility with Mac OS 10.3 and earlier, the default implementation of this method instead invokes [self documentForFileName:[url path]] if -documentForFileName: is overridden and the URL uses the "file:" scheme.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Document document_for_url(const URL& url) const;
        /**
         * @brief Calls `-[NSDocumentController documentForWindow:]`.
         * @details Given a window, return the document corresponding to the window, nil if no document corrresponds to the window.
         * @param window Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Document document_for_window(const Window& window) const;
        /**
         * @brief Calls `-[NSDocumentController duplicateDocumentWithContentsOfURL:copying:displayName:error:]`.
         * @details Create a new document that will not yet have a location by reading the contents for the document from another URL, present its user interface, and return the document if successful. If not successful, return nil after setting outError to an NSError that encapsulates the reason why a new document could not be created. If duplicateByCopying is YES then first copy the contents located at the passed-in URL into a file located in the same directory that is used for the autosaved contents of untitled documents and with the same sort of name. if displayNameOrNil is not nil then use that value to derive a display name for the new document that does not match one that is already in use by an open document. The default implementation of this method copies the file if specified, determines the type of the document, invokes -makeDocumentForURL:withContentsOfURL:ofType:error: to instantiate it, sends the document -setDisplayName: to name it if displayNameOrNil is not nil, invokes -addDocument: to record its opening, and sends the document -makeWindowControllers and -showWindows messages. The default implementation of this method uses the file coordination mechanism that was added to the Foundation framework in Mac OS 10.7. It passes the document to +[NSFileCoordinator addFilePresenter:] right after -addDocument: is invoked. (The balancing invocation of +[NSFileCoordinator removeFilePresenter:] is in -[NSDocument close]). You can override this method to customize how documents are duplicated. It is invoked by -[NSDocument duplicateAndReturnError:]. It may however also be invoked from other places in AppKit. We don't anticipate any uses for your application to invoke this method directly, but you may discover one.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @param duplicate_by_copying Argument converted to the Objective-C parameter of the same role.
         * @param display_name_or_nil Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Document duplicate_document_with_contents_of_url(const URL& url, bool duplicate_by_copying, const std::string& display_name_or_nil) const;
        /**
         * @brief Calls `-[NSDocumentController makeDocumentForURL:withContentsOfURL:ofType:error:]`.
         * @details Instantiate a document, perhaps located by a URL, perhaps not, by reading the contents for the document from another URL, which may or may not be a different URL, and return it if successful. If not successful, return nil after setting outError to an NSError that encapsulates the reason why the document could not be instantiated. The default implementation of this method invokes -documentClassForType: to find out the class of document to instantiate, allocates a document object, and initializes it by sending it an -initForURL:withContentsOfURL:ofType:error: message.
         * @param url_or_nil Argument converted to the Objective-C parameter of the same role.
         * @param contents_url Argument converted to the Objective-C parameter of the same role.
         * @param type_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Document make_document_for_url(const URL& url_or_nil, const URL& contents_url, const std::string& type_name) const;
        /**
         * @brief Calls `-[NSDocumentController makeDocumentWithContentsOfURL:ofType:error:]`.
         * @details Instantiate a document located by a URL, of a specified type, and return it if successful. If not successful, return nil after setting outError to an NSError that encapsulates the reason why the document could not be instantiated. The default implementation of this method invokes -documentClassForType: to find out the class of document to instantiate, allocates a document object, and initializes it by sending it an -initWithContentsOfURL:ofType:error: message. For backward binary compatibility with Mac OS 10.3 and earlier, the default implementation of this method instead invokes [self makeDocumentWithContentsOfFile:[url path] ofType:typeName] if -makeDocumentWithContentsOfFile:ofType: is overridden and the URL uses the "file:" scheme.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @param type_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Document make_document_with_contents_of_url(const URL& url, const std::string& type_name) const;
        /**
         * @brief Calls `-[NSDocumentController makeUntitledDocumentOfType:error:]`.
         * @details Instantiate a new untitled document of the specified type and return it if successful. If not successful, return nil after setting outError to an NSError that encapsulates the reason why a new untitled document could not be instantiated. The default implementation of this method invokes -documentClassForType: to find out the class of document to instantiate, allocates a document object, and initializes it by sending it an -initWithType:error: message. For backward binary compatibility with Mac OS 10.3 and earlier, the default implementation of this method instead invokes [self makeUntitledDocumentOfType:typeName] if -makeUntitledDocumentOfType: is overridden.
         * @param type_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Document make_untitled_document_of_type(const std::string& type_name) const;
        /**
         * @brief Calls `-[NSDocumentController newDocument:]`.
         * @details The action of the File menu's New item in a document-based application. The default implementation of this method invokes -openUntitledDocumentAndDisplay:error: and, if nil is returned, presents the error in an application-modal panel.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void new_document(const Object& sender) const;
        /**
         * @brief Calls `-[NSDocumentController noteNewRecentDocument:]`.
         * @details Add an item corresponding to a document to the Open Recent menu, or replace an existing item for the same document.
         * @param document Argument converted to the Objective-C parameter of the same role.
         */
        void note_new_recent_document(const Document& document) const;
        /**
         * @brief Calls `-[NSDocumentController noteNewRecentDocumentURL:]`.
         * @details Add an item corresponding to the data located by a URL to the Open Recent menu, or replace an existing item with the same URL. You can use this even in non-NSDocument-based applications.
         * @param url Argument converted to the Objective-C parameter of the same role.
         */
        void note_new_recent_document_url(const URL& url) const;
        /**
         * @brief Calls `-[NSDocumentController openDocument:]`.
         * @details The action of the File menu's Open... item in a document-based application. The default implementation of this method invokes -beginOpenPanelWithCompletionHandler:, unless -fileNamesFromRunningOpenPanel is overridden, in which case that method is invoked instead for backward binary compatibility with Mac OS 10.3 and earlier. If an array other than nil is obtained from that call, it invokes -openDocumentWithContentsOfURL:display:completionHandler: for each URL and, if an error is signaled for any of them, presents the error in an application-modal panel.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void open_document(const Object& sender) const;
        /**
         * @brief Calls `-[NSDocumentController openDocumentWithContentsOfURL:display:completionHandler:]`.
         * @details Open a document located by a URL, present its user interface if displayDocument is YES, and invoke the passed-in completion handler at some point in the future, perhaps after the method invocation has returned. The completion handler must be invoked on the main thread. If successful, pass the document to the completion handler, and also whether the document was already open or being opened before this method was invoked. If not successful, pass a nil document and an NSError that encapsulates the reason why the document could not be opened. The default implementation of this method checks to see if the document is already open or being opened, and if it is not determines the type of the document, invokes -makeDocumentWithContentsOfURL:ofType:error: to instantiate it, invokes -addDocument: to record its opening, and sends the document -makeWindowControllers and -showWindows messages if displayDocument is YES. If the document is already open it is just sent a -showWindows message if displayDocument is YES. If the relevant document class returns YES when sent +canConcurrentlyReadDocumentsOfType: then the invocation of -makeDocumentWithContentsOfURL:ofType:error: is done on a thread other than the main one and when that has returned the rest of the operation is done on the main thread. The default implementation of this method uses the file coordination mechanism that was added to the Foundation framework in Mac OS 10.7. All of the work it does is one big coordinated read, and it passes the document to +[NSFileCoordinator addFilePresenter:] right after -addDocument: is invoked. (The balancing invocation of +[NSFileCoordinator removeFilePresenter:] is in -[NSDocument close]). You can override this method to customize how documents are opened. Its implemention however is somewhat complex so unless your customization is to do additional work before invoking super, or to invoke super with a completion handler that does additional work before invoking the original completion handler, you should investigate overriding one of the methods that it invokes instead. If you do override this method you should investigate whether you should also override -reopenDocumentForURL:withContentsOfURL:display:completionHandler: to apply the same customization. In either cause take care to always invoke the completion handler on the main thread. You can of course invoke this method to open a document. For backward binary compatibility with Mac OS 10.6 and earlier, the default implementation of this method invokes [self openDocumentWithContentsOfURL:url display:displayDocument error:&anError] if that method or the even older -openDocumentWithContentsOfFile:display: method is overridden and this one is not, instead of invoking -makeDocumentWithContentsOfURL:ofType:error: and all the rest.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @param display_document Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void open_document_with_contents_of_url(const URL& url, bool display_document, std::function<void(Document, bool, Error)> completion_handler) const;
        /**
         * @brief Calls `-[NSDocumentController openUntitledDocumentAndDisplay:error:]`.
         * @details Create a new untitled document, present its user interface if displayDocument is YES, and return the document if successful. If not successful, return nil after setting outError to an NSError that encapsulates the reason why a new untitled document could not be created. The default implementation of this method invokes [self defaultType] to determine the type of new document to create, invokes -makeUntitledDocumentOfType:error: to create it, then invokes -addDocument: to record its opening. If displayDocument is YES, it then sends the new document -makeWindowControllers and -showWindows messages. The default implementation of this method uses the file coordination mechanism that was added to the Foundation framework in Mac OS 10.7. It passes the document to +[NSFileCoordinator addFilePresenter:] right after -addDocument: is invoked. (The balancing invocation of +[NSFileCoordinator removeFilePresenter:] is in -[NSDocument close]). For backward binary compatibility with Mac OS 10.3 and earlier, the default implementation of this method instead invokes [self openUntitledDocumentOfType:[self defaultType] display:displayDocument] if -openUntitledDocumentOfType:display: is overridden.
         * @param display_document Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Document open_untitled_document_and_display(bool display_document) const;
        /**
         * @brief Calls `-[NSDocumentController presentError:]`.
         * @param error Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool present_error(const Error& error) const;
        /**
         * @brief Calls `-[NSDocumentController presentError:modalForWindow:delegate:didPresentSelector:contextInfo:]`.
         * @details Methods that are declared by NSResponder and also implemented by NSDocumentController, even though for historical reasons NSDocumentController is not a subclass of NSResponder. NSDocumentController's default implementations are equivalent to NSResponder's while treating the application object as the "next responder" and forwarding error presentation messages to it. NSDocument has overrides of -presentError:modalForWindow:delegate:didPresentSelector:contextInfo: and -presentError: that treat the shared document controller as the "next responder" and forward these messages it. The default implementations of several NSDocumentController methods invoke -presentError:. You can customize the presentation of errors for all kinds of documents by overriding -willPresentError:. Your override should follow the advice given for overriding of -[NSResponder willPresentError:].
         * @param error Argument converted to the Objective-C parameter of the same role.
         * @param window Argument converted to the Objective-C parameter of the same role.
         * @param delegate Argument converted to the Objective-C parameter of the same role.
         * @param did_present_selector Argument converted to the Objective-C parameter of the same role.
         * @param context_info Argument converted to the Objective-C parameter of the same role.
         */
        void present_error(const Error& error, const Window& window, const Object& delegate, const std::string& did_present_selector, void* context_info) const;
        /**
         * @brief Calls `-[NSDocumentController removeDocument:]`.
         * @param document Argument converted to the Objective-C parameter of the same role.
         */
        void remove_document(const Document& document) const;
        /**
         * @brief Calls `-[NSDocumentController reopenDocumentForURL:withContentsOfURL:display:completionHandler:]`.
         * @details Reopen a document, perhaps located by a URL, perhaps not, by reading the contents for the document from another URL, which may or may not be a different URL, present its user interface if displayDocument is YES, and invoke the passed-in completion handler at some point in the future, perhaps after the method invocation has returned. The completion handler must be invoked on the main thread. If successful, pass the document to the completion handler, and also whether the document was already open or being opened before this method was invoked. If not successful, pass a nil document and an NSError that encapsulates the reason why the document could not be opened. A nil URL indicates that the opened document is to have no fileURL, much like an untitled document has. The default implementation of this method is very similar to -openDocumentWithContentsOfURL:display:completionHandler:'s, the primary difference being that it invokes -makeDocumentForURL:withContentsOfURL:ofType:error: instead of -makeDocumentWithContentsOfURL:ofType:error:. You can override this method to customize how documents are reopened during application launching by the restorable state mechanism that was added to the AppKit framework in Mac OS 10.7. Its implemention however is somewhat complex so unless your customization is to do additional work before invoking super, or to invoke super with a completion handler that does additional work before invoking the original completion handler, you should investigate overriding one of the methods that it invokes instead. We don't anticipate any uses for an application to invoke this method directly, but you may discover one. For backward binary compatibility with Mac OS 10.6 and earlier, the default implementation of this method invokes [self reopenDocumentForURL:url withContentsOfURLcontentsURL error:&anError] if that method is overridden and this one is not, instead of invoking -makeDocumentForURL:withContentsOfURL:ofType:error: and all the rest.
         * @param url_or_nil Argument converted to the Objective-C parameter of the same role.
         * @param contents_url Argument converted to the Objective-C parameter of the same role.
         * @param display_document Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void reopen_document_for_url(const URL& url_or_nil, const URL& contents_url, bool display_document, std::function<void(Document, bool, Error)> completion_handler) const;
        /**
         * @brief Calls `-[NSDocumentController reviewUnsavedDocumentsWithAlertTitle:cancellable:delegate:didReviewAllSelector:contextInfo:]`.
         * @details If there is more than one modified document, present an application-modal alert panel telling the user that there are unsaved documents and giving the option of canceling, not saving the documents, or saving the documents. If the user indicates that saving should be done, or if there was only one modified document in the first place, invoke -closeAllDocumentsWithDelegate:didCloseAllSelector:didReviewAll:contextInfo: to attempt to close all modified documents, doing whatever saving is necessary to not lose data. Finally, send the message selected by didReviewAllSelector to the delegate, with the contextInfo as the last argument. The default implementation of this method ignores the passed-in title string (which is passed in only as the result of a historical quirk). The method selected by didReviewAllSelector must have the same signature as: - (void)documentController:(NSDocumentController )documentController didReviewAll:(BOOL)didReviewAll contextInfo:(void )contextInfo;
         * @param title Argument converted to the Objective-C parameter of the same role.
         * @param cancellable Argument converted to the Objective-C parameter of the same role.
         * @param delegate Argument converted to the Objective-C parameter of the same role.
         * @param did_review_all_selector Argument converted to the Objective-C parameter of the same role.
         * @param context_info Argument converted to the Objective-C parameter of the same role.
         */
        void review_unsaved_documents_with_alert_title(const std::string& title, bool cancellable, const Object& delegate, const std::string& did_review_all_selector, void* context_info) const;
        /**
         * @brief Calls `-[NSDocumentController runModalOpenPanel:forTypes:]`.
         * @details Present the application-modal open panel to the user, specifying a list of UTIs (in Mac OS 10.5), file name extensions, and encoded HFS file types for openable files. Return NSOKButton or NSCancelButton depending on how the user dismisses the panel.
         * @param open_panel Argument converted to the Objective-C parameter of the same role.
         * @param types Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t run_modal_open_panel(const OpenPanel& open_panel, const std::vector<std::string>& types) const;
        /**
         * @brief Calls `-[NSDocumentController saveAllDocuments:]`.
         * @details The action of the File menu's Save All item in a document-based application. The default implementation of this method sends each modified document a -saveDocumentWithDelegate:didSaveSelector:contextInfo: message.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void save_all_documents(const Object& sender) const;
        /**
         * @brief Calls `-[NSDocumentController standardShareMenuItem]`.
         * @details A menu item that can be used for sharing the current document. You would typically only use this if you make your NSDocument subclass return NO for allowsAutomaticShareMenu to do custom placement of the Share menu.
         * @return The converted Objective-C result.
         */
        MenuItem standard_share_menu_item() const;
        /**
         * @brief Calls `-[NSDocumentController typeForContentsOfURL:error:]`.
         * @details Given a URL, return the name of the document type that should be used when opening the document at that location, if successful. If not successful, return nil after setting outError to an NSError that encapsulates the reason why the document's type could not be determined, or the fact that the document's type is just unrecognized. The default implementation of this method merely returns the URL's NSURLTypeIdentifierKey resource value. You can override this to customize type determination for documents being opened. For backward binary compatibility with Mac OS 10.4 and earlier, the default implementation of this method actually first does the same thing that it did in Mac OS 10.4 (invoke -typeFromFileExtension:, possibly twice, passing an HFS file type string for the second invocation) if there are any CFBundleDocumentTypes Info.plist entries that don't have LSItemContentTypes subentries, and only gets the URL's NSURLTypeIdentifierKey resource value if that does not succeed.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string type_for_contents_of_url(const URL& url) const;
        /**
         * @brief Calls `-[NSDocumentController validateUserInterfaceItem:]`.
         * @details Conformance to the NSUserInterfaceValidations protocol. NSDocumentController's implementation of this method conditionally enables menu items for all of the action methods listed in this header file, as well as the private action method for Open Recent menu items.
         * @param item Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool validate_user_interface_item(const Object& item) const;
        /**
         * @brief Calls `-[NSDocumentController willPresentError:]`.
         * @param error Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Error will_present_error(const Error& error) const;
        /**
         * @brief Returns the `allowsAutomaticShareMenu` property of `NSDocumentController`.
         * @details If YES, allows automatic insertion of a Share menu in the File menu. By default, this will be YES if your application has any NSDocument subclasses for which autosavesInPlace is YES. To disable the Share menu entirely, or to enable custom placement or construction of the Share menu, applications can explicitly opt out of automatic share menu insertion by overriding this property to return NO. Be aware that even if allowsAutomaticShareMenu is YES, NSDocumentController may choose not to insert the Share menu if it detects that the application already has a Share menu.
         * @return The converted Objective-C result.
         */
        bool allows_automatic_share_menu() const;
        /**
         * @brief Returns the `autosavingDelay` property of `NSDocumentController`.
         * @details The time interval in seconds for periodic autosaving. A value of 0 indicates that periodic autosaving should not be done at all. NSDocument will use this number as the minimum amount of time to wait between detecting that a document has unautosaved changes and sending the document an -autosaveDocumentWithDelegate:didAutosaveSelector:contextInfo: message. The default value is 0. You can change it to enable periodic autosaving.
         * @return The converted Objective-C result.
         */
        double autosaving_delay() const;
        /**
         * @brief Sets the `autosavingDelay` property of `NSDocumentController`.
         * @details The time interval in seconds for periodic autosaving. A value of 0 indicates that periodic autosaving should not be done at all. NSDocument will use this number as the minimum amount of time to wait between detecting that a document has unautosaved changes and sending the document an -autosaveDocumentWithDelegate:didAutosaveSelector:contextInfo: message. The default value is 0. You can change it to enable periodic autosaving.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_autosaving_delay(double value) const;
        /**
         * @brief Returns the `currentDirectory` property of `NSDocumentController`.
         * @details Return the path of the directory containing the active document's file or file package, if there is an active document and it has a file or file package. Return nil otherwise. The default implementation of -URLsFromRunningOpenPanel invokes this to find the current directory to set in the open panel before presenting it.
         * @return The converted Objective-C result.
         */
        std::string current_directory() const;
        /**
         * @brief Returns the `currentDocument` property of `NSDocumentController`.
         * @details Return the active document, or nil if there is no active document. The "active" document is the one corresponding to the key window, or the one corresponding to the main window if the key window has no document.
         * @return The converted Objective-C result.
         */
        Document current_document() const;
        /**
         * @brief Returns the `defaultType` property of `NSDocumentController`.
         * @details Return the name of the document type that should be used when creating new documents. The default implementation of this method returns the first Editor type declared in the application's Info.plist, or returns nil if no Editor type is declared. You can override it to customize the type of document that is created when, for instance, the user chooses New in the File menu.
         * @return The converted Objective-C result.
         */
        std::string default_type() const;
        /**
         * @brief Returns the `documentClassNames` property of `NSDocumentController`.
         * @details Return the names of NSDocument subclasses supported by this application. The default implementation of this method returns information derived from the application's Info.plist. You can override it to return the names of document classes that are dynamically loaded from plugins.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> document_class_names() const;
        /**
         * @brief Returns the `documents` property of `NSDocumentController`.
         * @details Return an array of all open documents.
         * @return The converted Objective-C result.
         */
        std::vector<Document> documents() const;
        /**
         * @brief Returns the `hasEditedDocuments` property of `NSDocumentController`.
         * @details Return YES if any open document is modified, NO otherwise. This method is invoked at application quitting time, to determine whether -reviewUnsavedDocumentsWithAlertTitle:cancellable:delegate:didReviewAllSelector:contextInfo: should be invoked.
         * @return The converted Objective-C result.
         */
        bool has_edited_documents() const;
        /**
         * @brief Returns the `maximumRecentDocumentCount` property of `NSDocumentController`.
         * @details Return the maximum number of items that may be presented in the standard Open Recent menu. A value of 0 indicates that NSDocumentController will not attempt to add an Open Recent menu to your application's File menu, though NSDocumentController will not attempt to remove any Open Recent menu item if there is one already there. The default implementation returns a value that is subject to change and may or may not be derived from a setting made by the user in a System Preferences panel.
         * @return The converted Objective-C result.
         */
        std::uint64_t maximum_recent_document_count() const;
        /**
         * @brief Returns the `recentDocumentURLs` property of `NSDocumentController`.
         * @details Return an array of URLs for the entries currently appearing in the Open Recent menu.
         * @return The converted Objective-C result.
         */
        std::vector<URL> recent_document_urls() const;
        /**
         * @brief Returns the `sharedDocumentController` property of `NSDocumentController`.
         * @details Return the application's shared document controller. This method will create an instance of NSDocumentController if there is no shared document controller yet. Because the first instance of NSDocumentController to be allocate and initialized during application launch is used as the shared document controller, you have two options for installing an instance of a custom subclass of NSDocumentController as the shared document controller: 1) Instantiate your NSDocumentController subclass in the application's main nib, or 2) Allocate and initialize an instance of your subclass in your application delegate's applicationWillFinishLaunching: method.
         * @return The converted Objective-C result.
         */
        static DocumentController shared_document_controller();
    };
}
