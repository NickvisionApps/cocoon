#include "generated/window_controller.h"
#include "internal.h"

namespace cocoon
{
    WindowController::WindowController(const Window& window) : WindowController(Adopt{cocoon::internal::retain([[::NSWindowController alloc] initWithWindow:cocoon::internal::native<::NSWindow>(window)])})
    {
    }

    WindowController::WindowController(const std::string& window_nib_name) : WindowController(Adopt{cocoon::internal::retain([[::NSWindowController alloc] initWithWindowNibName:cocoon::internal::to(window_nib_name)])})
    {
    }

    WindowController::WindowController(const std::string& window_nib_name, const Object& owner) : WindowController(Adopt{cocoon::internal::retain([[::NSWindowController alloc] initWithWindowNibName:cocoon::internal::to(window_nib_name) owner:cocoon::internal::native_id(owner)])})
    {
    }

    WindowController::WindowController() : WindowController(Adopt{cocoon::internal::retain([[::NSWindowController alloc] init])})
    {
    }

    WindowController::WindowController(std::nullptr_t) : Responder(nullptr)
    {
    }

    WindowController::WindowController(Adopt adopt) : Responder(adopt)
    {
    }

    void WindowController::close() const
    {
        [cocoon::internal::ns<::NSWindowController>(this) close];
    }

    void WindowController::dismiss_controller(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindowController>(this) dismissController:cocoon::internal::native_id(sender)];
    }

    void WindowController::load_window() const
    {
        [cocoon::internal::ns<::NSWindowController>(this) loadWindow];
    }

    void WindowController::set_document_edited(bool dirty_flag) const
    {
        [cocoon::internal::ns<::NSWindowController>(this) setDocumentEdited:static_cast<::BOOL>(dirty_flag)];
    }

    void WindowController::show_window(const Object& sender) const
    {
        [cocoon::internal::ns<::NSWindowController>(this) showWindow:cocoon::internal::native_id(sender)];
    }

    void WindowController::synchronize_window_title_with_document_name() const
    {
        [cocoon::internal::ns<::NSWindowController>(this) synchronizeWindowTitleWithDocumentName];
    }

    void WindowController::window_did_load() const
    {
        [cocoon::internal::ns<::NSWindowController>(this) windowDidLoad];
    }

    std::string WindowController::window_title_for_document_display_name(const std::string& display_name) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindowController>(this) windowTitleForDocumentDisplayName:cocoon::internal::to(display_name)]);
    }

    void WindowController::window_will_load() const
    {
        [cocoon::internal::ns<::NSWindowController>(this) windowWillLoad];
    }

    ViewController WindowController::content_view_controller() const
    {
        return cocoon::internal::wrap<ViewController>([cocoon::internal::ns<::NSWindowController>(this) contentViewController]);
    }

    void WindowController::set_content_view_controller(const ViewController& value) const
    {
        [cocoon::internal::ns<::NSWindowController>(this) setContentViewController:cocoon::internal::native<::NSViewController>(value)];
    }

    Object WindowController::document() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSWindowController>(this) document]);
    }

    void WindowController::set_document(const Object& value) const
    {
        [cocoon::internal::ns<::NSWindowController>(this) setDocument:cocoon::internal::native_id(value)];
    }

    Object WindowController::owner() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSWindowController>(this) owner]);
    }

    std::vector<Object> WindowController::preview_representable_activity_items() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSWindowController>(this) previewRepresentableActivityItems], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    void WindowController::set_preview_representable_activity_items(const std::vector<Object>& value) const
    {
        [cocoon::internal::ns<::NSWindowController>(this) setPreviewRepresentableActivityItems:cocoon::internal::to_array(value, [](const Object& e) -> id
                                                                                                                          {
                                                                                                                              return cocoon::internal::native_id(e);
                                                                                                                          })];
    }

    bool WindowController::should_cascade_windows() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindowController>(this) shouldCascadeWindows]);
    }

    void WindowController::set_should_cascade_windows(bool value) const
    {
        [cocoon::internal::ns<::NSWindowController>(this) setShouldCascadeWindows:static_cast<::BOOL>(value)];
    }

    bool WindowController::should_close_document() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindowController>(this) shouldCloseDocument]);
    }

    void WindowController::set_should_close_document(bool value) const
    {
        [cocoon::internal::ns<::NSWindowController>(this) setShouldCloseDocument:static_cast<::BOOL>(value)];
    }

    Storyboard WindowController::storyboard() const
    {
        return cocoon::internal::wrap<Storyboard>([cocoon::internal::ns<::NSWindowController>(this) storyboard]);
    }

    Window WindowController::window() const
    {
        return cocoon::internal::wrap<Window>([cocoon::internal::ns<::NSWindowController>(this) window]);
    }

    void WindowController::set_window(const Window& value) const
    {
        [cocoon::internal::ns<::NSWindowController>(this) setWindow:cocoon::internal::native<::NSWindow>(value)];
    }

    std::string WindowController::window_frame_autosave_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindowController>(this) windowFrameAutosaveName]);
    }

    void WindowController::set_window_frame_autosave_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSWindowController>(this) setWindowFrameAutosaveName:cocoon::internal::to(value)];
    }

    bool WindowController::is_window_loaded() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWindowController>(this) isWindowLoaded]);
    }

    std::string WindowController::window_nib_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindowController>(this) windowNibName]);
    }

    std::string WindowController::window_nib_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWindowController>(this) windowNibPath]);
    }
}
