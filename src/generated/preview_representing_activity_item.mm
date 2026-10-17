#include "generated/preview_representing_activity_item.h"
#include "internal.h"

namespace cocoon
{
    PreviewRepresentingActivityItem::PreviewRepresentingActivityItem(const Object& item, const std::string& title, const Image& image, const Image& icon) : PreviewRepresentingActivityItem(Adopt{cocoon::internal::retain([[::NSPreviewRepresentingActivityItem alloc] initWithItem:cocoon::internal::native_id(item) title:cocoon::internal::to(title) image:cocoon::internal::native<::NSImage>(image) icon:cocoon::internal::native<::NSImage>(icon)])})
    {
    }

    PreviewRepresentingActivityItem::PreviewRepresentingActivityItem(const Object& item, const std::string& title, const ItemProvider& image_provider, const ItemProvider& icon_provider) : PreviewRepresentingActivityItem(Adopt{cocoon::internal::retain([[::NSPreviewRepresentingActivityItem alloc] initWithItem:cocoon::internal::native_id(item) title:cocoon::internal::to(title) imageProvider:cocoon::internal::native<::NSItemProvider>(image_provider) iconProvider:cocoon::internal::native<::NSItemProvider>(icon_provider)])})
    {
    }

    PreviewRepresentingActivityItem::PreviewRepresentingActivityItem() : Object(nullptr)
    {
    }

    PreviewRepresentingActivityItem::PreviewRepresentingActivityItem(std::nullptr_t) : Object(nullptr)
    {
    }

    PreviewRepresentingActivityItem::PreviewRepresentingActivityItem(Adopt adopt) : Object(adopt)
    {
    }
}
