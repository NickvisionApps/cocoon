#include "generated/media_library_browser_controller.h"
#include "internal.h"

namespace cocoon
{
    MediaLibraryBrowserController::MediaLibraryBrowserController() : MediaLibraryBrowserController(Adopt{cocoon::internal::retain([[::NSMediaLibraryBrowserController alloc] init])})
    {
    }

    MediaLibraryBrowserController::MediaLibraryBrowserController(std::nullptr_t) : Object(nullptr)
    {
    }

    MediaLibraryBrowserController::MediaLibraryBrowserController(Adopt adopt) : Object(adopt)
    {
    }

    void MediaLibraryBrowserController::toggle_panel(const Object& sender) const
    {
        [cocoon::internal::ns<::NSMediaLibraryBrowserController>(this) togglePanel:cocoon::internal::native_id(sender)];
    }

    Rect MediaLibraryBrowserController::frame() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMediaLibraryBrowserController>(this) frame]);
    }

    void MediaLibraryBrowserController::set_frame(const Rect& value) const
    {
        [cocoon::internal::ns<::NSMediaLibraryBrowserController>(this) setFrame:cocoon::internal::to(value)];
    }

    MediaLibrary MediaLibraryBrowserController::media_libraries() const
    {
        return static_cast<MediaLibrary>([cocoon::internal::ns<::NSMediaLibraryBrowserController>(this) mediaLibraries]);
    }

    void MediaLibraryBrowserController::set_media_libraries(MediaLibrary value) const
    {
        [cocoon::internal::ns<::NSMediaLibraryBrowserController>(this) setMediaLibraries:static_cast<::NSMediaLibrary>(value)];
    }

    MediaLibraryBrowserController MediaLibraryBrowserController::shared_media_library_browser_controller()
    {
        return cocoon::internal::wrap<MediaLibraryBrowserController>([::NSMediaLibraryBrowserController sharedMediaLibraryBrowserController]);
    }

    bool MediaLibraryBrowserController::is_visible() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMediaLibraryBrowserController>(this) isVisible]);
    }

    void MediaLibraryBrowserController::set_visible(bool value) const
    {
        [cocoon::internal::ns<::NSMediaLibraryBrowserController>(this) setVisible:static_cast<::BOOL>(value)];
    }
}
