#include "generated/path_component_cell.h"
#include "internal.h"

namespace cocoon
{
    PathComponentCell::PathComponentCell() : PathComponentCell(Adopt{cocoon::internal::retain([[::NSPathComponentCell alloc] init])})
    {
    }

    PathComponentCell::PathComponentCell(std::nullptr_t) : TextFieldCell(nullptr)
    {
    }

    PathComponentCell::PathComponentCell(Adopt adopt) : TextFieldCell(adopt)
    {
    }

    URL PathComponentCell::url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSPathComponentCell>(this) URL]);
    }

    void PathComponentCell::set_url(const URL& value) const
    {
        [cocoon::internal::ns<::NSPathComponentCell>(this) setURL:cocoon::internal::native<::NSURL>(value)];
    }

    Image PathComponentCell::image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSPathComponentCell>(this) image]);
    }

    void PathComponentCell::set_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSPathComponentCell>(this) setImage:cocoon::internal::native<::NSImage>(value)];
    }
}
