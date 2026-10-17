#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/responder.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Storyboard;
    class ViewController;
    class Window;

    /**
     * @brief C++ handle for the Objective-C class `NSWindowController` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Responder.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::WindowController window_controller;
     * window_controller.set_content_view_controller(cocoon::ViewController());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::WindowController window_controller{};
     * window_controller.set_content_view_controller(cocoon::ViewController());
     * auto content_view_controller = window_controller.content_view_controller();
     * window_controller.set_should_cascade_windows(true);
     * auto should_cascade_windows = window_controller.should_cascade_windows();
     * window_controller.set_should_close_document(true);
     * auto should_close_document = window_controller.should_close_document();
     * window_controller.close();
     * window_controller.load_window();
     * window_controller.set_document_edited(true);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nswindowcontroller
     */
    class WindowController : public Responder
    {
    public:
        /// @brief Creates a new `NSWindowController` instance and returns a handle to it.
        explicit WindowController(const Window& window);
        /// @brief Creates a new `NSWindowController` instance and returns a handle to it.
        explicit WindowController(const std::string& window_nib_name);
        /// @brief Creates a new `NSWindowController` instance and returns a handle to it.
        explicit WindowController(const std::string& window_nib_name, const Object& owner);
        /// @brief Creates a new `NSWindowController` instance and returns a handle to it.
        explicit WindowController();
        /// @brief Creates a null handle that refers to no native object.
        WindowController(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit WindowController(Adopt adopt);
        /**
     * @brief Calls `-[NSWindowController close]`.
     * @details This will close the window controller. If the controller belongs to a document and it is either the last controller for the document or -shouldCloseDocument is YES, then this will also -close the document.
     */
        void close() const;
        /**
     * @brief Calls `-[NSWindowController dismissController:]`.
     * @details Dismisses the WindowController. Does nothing if the receiver is not currently presented.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void dismiss_controller(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindowController loadWindow]`.
     * @details This method can be overridden by advanced users. It should not be called directly (doing so will cause the window controller to be improperly set up). Call the -window method to force loading of the nib.
     */
        void load_window() const;
        /**
     * @brief Calls `-[NSWindowController setDocumentEdited:]`.
     * @details NSDocument calls this method for its window controllers whenever the document is made dirty or clean. By default this calls -setDocumentEdited: on the controller's window (if any). A controller calls this on itself when its document gets set or its window gets set.
     * @param dirty_flag Argument converted to the Objective-C parameter of the same role.
     */
        void set_document_edited(bool dirty_flag) const;
        /**
     * @brief Calls `-[NSWindowController showWindow:]`.
     * @details This will show the controller's window, if any. If the window is a panel and the panel becomes key only if needed, this method just orders it front. Otherwise it makes the window key and orders it front.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void show_window(const Object& sender) const;
        /**
     * @brief Calls `-[NSWindowController synchronizeWindowTitleWithDocumentName]`.
     * @details This method is invoked automatically whenever the controller's document has changed that would affect the window title. (For instance, when the fileName of the document changes, or when the controller gets a new document.) This method uses the -displayName method of NSDocument to find out the display name. It then passes the display name to -windowTitleForDocumentDisplayName: to give it a chance to change it. Finally, if the document has a -fileName and the display name is the same as the -fileName's last component, it actually sets the title from the -fileName instead of the display name. Otherwise it sets the title from the display name. If there is a -fileName, that file is always set as the window's represented file The window title is left alone if the controller has no document. This method can be overridden if you need to do something else.
     */
        void synchronize_window_title_with_document_name() const;
        /**
     * @brief Calls `-[NSWindowController windowDidLoad]`.
     */
        void window_did_load() const;
        /**
     * @brief Calls `-[NSWindowController windowTitleForDocumentDisplayName:]`.
     * @details This method can be overridden to modify or replace the display name computed by the document's -displayName. If you return something other than the given display name, it will be used as-is for the window title.
     * @param display_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string window_title_for_document_display_name(const std::string& display_name) const;
        /**
     * @brief Calls `-[NSWindowController windowWillLoad]`.
     * @details These are invoked immediately before and after this controller loads its nib, if the the nib loading is triggered by an invocation of -window (which is typical). The default implementations of these methods do nothing. You can override them to add additional processing before and after nib loading. Overriding of -windowDidLoad in particular is useful because it's the first method that's invoked after the connecting of any IB outlets added in a subclass. Your application should not invoke these methods directly.
     */
        void window_will_load() const;
        /**
     * @brief Returns the `contentViewController` property of `NSWindowController`.
     * @details The view controller for the window's contentView. Tracks the window property of the same name.
     * @return The converted Objective-C result.
     */
        ViewController content_view_controller() const;
        /**
     * @brief Sets the `contentViewController` property of `NSWindowController`.
     * @details The view controller for the window's contentView. Tracks the window property of the same name.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_view_controller(const ViewController& value) const;
        /**
     * @brief Returns the `document` property of `NSWindowController`.
     * @details Returns the document associated with the window controller (if any). You should not set the document property. It is invoked automatically from NSDocument's -addWindowController:. You can override it if you need to, but call super's implementation. The document is not retained by the NSWindowController.
     * @return The converted Objective-C result.
     */
        Object document() const;
        /**
     * @brief Sets the `document` property of `NSWindowController`.
     * @details Returns the document associated with the window controller (if any). You should not set the document property. It is invoked automatically from NSDocument's -addWindowController:. You can override it if you need to, but call super's implementation. The document is not retained by the NSWindowController.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_document(const Object& value) const;
        /**
     * @brief Returns the `owner` property of `NSWindowController`.
     * @details The file's owner for this window controller's nib file. Usually this is either the controller itself or the controller's document, but, in general, it is specified by the -init... methods. The owner is weakly referenced.
     * @return The converted Objective-C result.
     */
        Object owner() const;
        /**
     * @brief Returns the `previewRepresentableActivityItems` property of `NSWindowController`.
     * @details Preview representable activity items, used for sharing and collaboration. If set to nil, NSWindowController shall return the previewRepresentableActivityItems of its associated NSDocument (if any)
     * @return The converted Objective-C result.
     */
        std::vector<Object> preview_representable_activity_items() const;
        /**
     * @brief Sets the `previewRepresentableActivityItems` property of `NSWindowController`.
     * @details Preview representable activity items, used for sharing and collaboration. If set to nil, NSWindowController shall return the previewRepresentableActivityItems of its associated NSDocument (if any)
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preview_representable_activity_items(const std::vector<Object>& value) const;
        /**
     * @brief Returns the `shouldCascadeWindows` property of `NSWindowController`.
     * @details If this is set to YES then new windows will be cascaded based on the original frame of the window.
     * @return The converted Objective-C result.
     */
        bool should_cascade_windows() const;
        /**
     * @brief Sets the `shouldCascadeWindows` property of `NSWindowController`.
     * @details If this is set to YES then new windows will be cascaded based on the original frame of the window.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_should_cascade_windows(bool value) const;
        /**
     * @brief Returns the `shouldCloseDocument` property of `NSWindowController`.
     * @details This indicates whether closing this controller should cause the associated document to close even if the document has other open window controllers. Normally a document will close automatically only when its last window controller closes. See the -close method below for more info.
     * @return The converted Objective-C result.
     */
        bool should_close_document() const;
        /**
     * @brief Sets the `shouldCloseDocument` property of `NSWindowController`.
     * @details This indicates whether closing this controller should cause the associated document to close even if the document has other open window controllers. Normally a document will close automatically only when its last window controller closes. See the -close method below for more info.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_should_close_document(bool value) const;
        /**
     * @brief Returns the `storyboard` property of `NSWindowController`.
     * @details The Storyboard the WindowController was loaded from. Returns nil if the WindowController was not loaded from a Storyboard.
     * @return The converted Objective-C result.
     */
        Storyboard storyboard() const;
        /**
     * @brief Returns the `window` property of `NSWindowController`.
     * @details The window getter will load the nib file (if there is one and it has not yet been loaded) and then return the window. If it has to load the window, it will first call -windowWillLoad, then -loadWindow, then -windowDidLoad. To affect nib loading or do something before or after it happens, you should always override those other methods. The window setter is used internally from -initWithWindow: or when a controller's nib file is loaded (as the "window" outlet gets connected). You can also call it yourself if you want to create the window for a window controller lazily, but you aren't loading it from a nib. This can also be used to set the window to nil for cases where your subclass might not want to keep the window it loaded from a nib, but rather only wants the contents of the window. Setting the window to nil, after the nib has been loaded, does not reset the -isWindowLoaded state. A window controller will only load its nib file once. This method makes sure the window does not release when closed, and it sets the controller's -windowFrameAutosaveName onto the window and updates the window's dirty state to match the controller's document (if any). It also calls -setWindowController: on the window. You can override this if you need to know when the window gets set, but call super.
     * @return The converted Objective-C result.
     */
        Window window() const;
        /**
     * @brief Sets the `window` property of `NSWindowController`.
     * @details The window getter will load the nib file (if there is one and it has not yet been loaded) and then return the window. If it has to load the window, it will first call -windowWillLoad, then -loadWindow, then -windowDidLoad. To affect nib loading or do something before or after it happens, you should always override those other methods. The window setter is used internally from -initWithWindow: or when a controller's nib file is loaded (as the "window" outlet gets connected). You can also call it yourself if you want to create the window for a window controller lazily, but you aren't loading it from a nib. This can also be used to set the window to nil for cases where your subclass might not want to keep the window it loaded from a nib, but rather only wants the contents of the window. Setting the window to nil, after the nib has been loaded, does not reset the -isWindowLoaded state. A window controller will only load its nib file once. This method makes sure the window does not release when closed, and it sets the controller's -windowFrameAutosaveName onto the window and updates the window's dirty state to match the controller's document (if any). It also calls -setWindowController: on the window. You can override this if you need to know when the window gets set, but call super.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_window(const Window& value) const;
        /**
     * @brief Returns the `windowFrameAutosaveName` property of `NSWindowController`.
     * @details This allows setting and accessing the autosave name for the controller's window. If the controller has a window frame autosave name, it will automatically make sure its window gets it set appropriately whenever it gets its window set.
     * @return The converted Objective-C result.
     */
        std::string window_frame_autosave_name() const;
        /**
     * @brief Sets the `windowFrameAutosaveName` property of `NSWindowController`.
     * @details This allows setting and accessing the autosave name for the controller's window. If the controller has a window frame autosave name, it will automatically make sure its window gets it set appropriately whenever it gets its window set.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_window_frame_autosave_name(const std::string& value) const;
        /**
     * @brief Returns the `windowLoaded` property of `NSWindowController`.
     * @details Returns YES if the receiver has loaded its -windowNibName, has itself been loaded from a nib, OR has no -windowNibName. In other words, if there is no nib to load, this always returns YES.
     * @return The converted Objective-C result.
     */
        bool is_window_loaded() const;
        /**
     * @brief Returns the `windowNibName` property of `NSWindowController`.
     * @details If -initWithWindowNibPath:owner: was used to initialize the instance, this gives the last path component with its extension stripped off. If -initWithWindowNibName:[owner:] was used this just gives that name.
     * @return The converted Objective-C result.
     */
        std::string window_nib_name() const;
        /**
     * @brief Returns the `windowNibPath` property of `NSWindowController`.
     * @details The full path of the nib. If -initWithWindowNibPath:owner: was used to initialize the instance, the path is just returned. If -initWithWindowNibName:[owner:] was used this locates the nib in the file's owner's class' bundle or in the app's mainBundle and returns the full path (or nil if it cannot be located). Subclasses can override this to augment the search behavior, but probably ought to call super first.
     * @return The converted Objective-C result.
     */
        std::string window_nib_path() const;
    };
}
