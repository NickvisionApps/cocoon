#include "generated/open_panel.h"
#include "internal.h"

namespace cocoon
{
    OpenPanel::OpenPanel() : OpenPanel(Adopt{cocoon::internal::retain([[::NSOpenPanel alloc] init])})
    {
        SavePanel::install_delegate_delegate_(handle());
    }

    OpenPanel::OpenPanel(std::nullptr_t) : SavePanel(nullptr)
    {
    }

    OpenPanel::OpenPanel(Adopt adopt) : SavePanel(adopt)
    {
    }

    OpenPanel OpenPanel::open_panel()
    {
        return cocoon::internal::wrap<OpenPanel>([::NSOpenPanel openPanel]);
    }

    std::vector<URL> OpenPanel::urls() const
    {
        return cocoon::internal::from_array<URL>([cocoon::internal::ns<::NSOpenPanel>(this) URLs], [](id e) -> URL
                                                 {
                                                     return cocoon::internal::wrap<URL>((::NSURL*)e);
                                                 });
    }

    bool OpenPanel::is_accessory_view_disclosed() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOpenPanel>(this) isAccessoryViewDisclosed]);
    }

    void OpenPanel::set_accessory_view_disclosed(bool value) const
    {
        [cocoon::internal::ns<::NSOpenPanel>(this) setAccessoryViewDisclosed:static_cast<::BOOL>(value)];
    }

    bool OpenPanel::allows_multiple_selection() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOpenPanel>(this) allowsMultipleSelection]);
    }

    void OpenPanel::set_allows_multiple_selection(bool value) const
    {
        [cocoon::internal::ns<::NSOpenPanel>(this) setAllowsMultipleSelection:static_cast<::BOOL>(value)];
    }

    bool OpenPanel::can_choose_directories() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOpenPanel>(this) canChooseDirectories]);
    }

    void OpenPanel::set_can_choose_directories(bool value) const
    {
        [cocoon::internal::ns<::NSOpenPanel>(this) setCanChooseDirectories:static_cast<::BOOL>(value)];
    }

    bool OpenPanel::can_choose_files() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOpenPanel>(this) canChooseFiles]);
    }

    void OpenPanel::set_can_choose_files(bool value) const
    {
        [cocoon::internal::ns<::NSOpenPanel>(this) setCanChooseFiles:static_cast<::BOOL>(value)];
    }

    bool OpenPanel::can_download_ubiquitous_contents() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOpenPanel>(this) canDownloadUbiquitousContents]);
    }

    void OpenPanel::set_can_download_ubiquitous_contents(bool value) const
    {
        [cocoon::internal::ns<::NSOpenPanel>(this) setCanDownloadUbiquitousContents:static_cast<::BOOL>(value)];
    }

    bool OpenPanel::can_resolve_ubiquitous_conflicts() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOpenPanel>(this) canResolveUbiquitousConflicts]);
    }

    void OpenPanel::set_can_resolve_ubiquitous_conflicts(bool value) const
    {
        [cocoon::internal::ns<::NSOpenPanel>(this) setCanResolveUbiquitousConflicts:static_cast<::BOOL>(value)];
    }

    bool OpenPanel::resolves_aliases() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSOpenPanel>(this) resolvesAliases]);
    }

    void OpenPanel::set_resolves_aliases(bool value) const
    {
        [cocoon::internal::ns<::NSOpenPanel>(this) setResolvesAliases:static_cast<::BOOL>(value)];
    }
}
