#include "generated/background_extension_view.h"
#include "internal.h"

namespace cocoon
{
    BackgroundExtensionView::BackgroundExtensionView() : BackgroundExtensionView(Adopt{cocoon::internal::retain([[::NSBackgroundExtensionView alloc] init])})
    {
    }

    BackgroundExtensionView::BackgroundExtensionView(std::nullptr_t) : View(nullptr)
    {
    }

    BackgroundExtensionView::BackgroundExtensionView(Adopt adopt) : View(adopt)
    {
    }

    bool BackgroundExtensionView::automatically_places_content_view() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBackgroundExtensionView>(this) automaticallyPlacesContentView]);
    }

    void BackgroundExtensionView::set_automatically_places_content_view(bool value) const
    {
        [cocoon::internal::ns<::NSBackgroundExtensionView>(this) setAutomaticallyPlacesContentView:static_cast<::BOOL>(value)];
    }

    View BackgroundExtensionView::content_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSBackgroundExtensionView>(this) contentView]);
    }

    void BackgroundExtensionView::set_content_view(const View& value) const
    {
        [cocoon::internal::ns<::NSBackgroundExtensionView>(this) setContentView:cocoon::internal::native<::NSView>(value)];
    }
}
