#include "generated/path_control_item.h"
#include "internal.h"

namespace cocoon
{
    PathControlItem::PathControlItem() : PathControlItem(Adopt{cocoon::internal::retain([[::NSPathControlItem alloc] init])})
    {
    }

    PathControlItem::PathControlItem(std::nullptr_t) : Object(nullptr)
    {
    }

    PathControlItem::PathControlItem(Adopt adopt) : Object(adopt)
    {
    }

    URL PathControlItem::url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSPathControlItem>(this) URL]);
    }

    AttributedString PathControlItem::attributed_title() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSPathControlItem>(this) attributedTitle]);
    }

    void PathControlItem::set_attributed_title(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSPathControlItem>(this) setAttributedTitle:cocoon::internal::native<::NSAttributedString>(value)];
    }

    Image PathControlItem::image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSPathControlItem>(this) image]);
    }

    void PathControlItem::set_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSPathControlItem>(this) setImage:cocoon::internal::native<::NSImage>(value)];
    }

    std::string PathControlItem::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPathControlItem>(this) title]);
    }

    void PathControlItem::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPathControlItem>(this) setTitle:cocoon::internal::to(value)];
    }
}
