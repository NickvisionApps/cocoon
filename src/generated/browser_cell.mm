#include "generated/browser_cell.h"
#include "internal.h"

namespace cocoon
{
    BrowserCell::BrowserCell(const Image& image) : BrowserCell(Adopt{cocoon::internal::retain([[::NSBrowserCell alloc] initImageCell:cocoon::internal::native<::NSImage>(image)])})
    {
    }

    BrowserCell::BrowserCell(const std::string& string) : BrowserCell(Adopt{cocoon::internal::retain([[::NSBrowserCell alloc] initTextCell:cocoon::internal::to(string)])})
    {
    }

    BrowserCell::BrowserCell() : BrowserCell(Adopt{cocoon::internal::retain([[::NSBrowserCell alloc] init])})
    {
    }

    BrowserCell::BrowserCell(std::nullptr_t) : Cell(nullptr)
    {
    }

    BrowserCell::BrowserCell(Adopt adopt) : Cell(adopt)
    {
    }

    Color BrowserCell::highlight_color_in_view(const View& control_view) const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSBrowserCell>(this) highlightColorInView:cocoon::internal::native<::NSView>(control_view)]);
    }

    void BrowserCell::reset() const
    {
        [cocoon::internal::ns<::NSBrowserCell>(this) reset];
    }

    void BrowserCell::set() const
    {
        [cocoon::internal::ns<::NSBrowserCell>(this) set];
    }

    Image BrowserCell::alternate_image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSBrowserCell>(this) alternateImage]);
    }

    void BrowserCell::set_alternate_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSBrowserCell>(this) setAlternateImage:cocoon::internal::native<::NSImage>(value)];
    }

    Image BrowserCell::branch_image()
    {
        return cocoon::internal::wrap<Image>([::NSBrowserCell branchImage]);
    }

    Image BrowserCell::highlighted_branch_image()
    {
        return cocoon::internal::wrap<Image>([::NSBrowserCell highlightedBranchImage]);
    }

    Image BrowserCell::image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSBrowserCell>(this) image]);
    }

    void BrowserCell::set_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSBrowserCell>(this) setImage:cocoon::internal::native<::NSImage>(value)];
    }

    bool BrowserCell::is_leaf() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowserCell>(this) isLeaf]);
    }

    void BrowserCell::set_leaf(bool value) const
    {
        [cocoon::internal::ns<::NSBrowserCell>(this) setLeaf:static_cast<::BOOL>(value)];
    }

    bool BrowserCell::is_loaded() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBrowserCell>(this) isLoaded]);
    }

    void BrowserCell::set_loaded(bool value) const
    {
        [cocoon::internal::ns<::NSBrowserCell>(this) setLoaded:static_cast<::BOOL>(value)];
    }
}
