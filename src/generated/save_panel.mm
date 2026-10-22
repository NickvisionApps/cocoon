#include "generated/save_panel.h"
#include "internal.h"

@interface AKSavePanelDelegate : NSObject <NSOpenSavePanelDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKSavePanelDelegate

- (BOOL)panel:(id)sender shouldEnableURL:(NSURL*)url
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SavePanel, bool(cocoon::URL)>::emit((__bridge void*)strongHost, "panel_should_enable_url", cocoon::internal::wrap<cocoon::URL>(url));
    return static_cast<::BOOL>(__r);
}

- (void)panel:(id)sender didChangeToDirectoryURL:(NSURL*)url
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SavePanel, void(cocoon::URL)>::emit((__bridge void*)strongHost, "panel_did_change_to_directory_url", cocoon::internal::wrap<cocoon::URL>(url));
}

- (NSString*)panel:(id)sender userEnteredFilename:(NSString*)filename confirmed:(BOOL)okFlag
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SavePanel, std::string(std::string, bool)>::emit((__bridge void*)strongHost, "panel_user_entered_filename_confirmed", cocoon::internal::from(filename), static_cast<bool>(okFlag));
    return cocoon::internal::to(__r);
}

- (void)panel:(id)sender willExpand:(BOOL)expanding
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SavePanel, void(bool)>::emit((__bridge void*)strongHost, "panel_will_expand", static_cast<bool>(expanding));
}

- (void)panelSelectionDidChange:(id)sender
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SavePanel, void()>::emit((__bridge void*)strongHost, "panel_selection_did_change");
}

- (NSString*)panel:(id)sender displayNameForType:(UTType*)type
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::SavePanel, std::string(cocoon::Object)>::emit((__bridge void*)strongHost, "panel_display_name_for_type", cocoon::internal::wrap<cocoon::Object>(type));
    return cocoon::internal::to(__r);
}

- (void)panel:(id)sender didSelectType:(UTType*)type
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SavePanel, void(cocoon::Object)>::emit((__bridge void*)strongHost, "panel_did_select_type", cocoon::internal::wrap<cocoon::Object>(type));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(panel:shouldEnableURL:))
    {
        return strongHost && cocoon::Signal<cocoon::SavePanel, bool(cocoon::URL)>::connected((__bridge void*)strongHost, "panel_should_enable_url");
    }
    if (selector == @selector(panel:didChangeToDirectoryURL:))
    {
        return strongHost && cocoon::Signal<cocoon::SavePanel, void(cocoon::URL)>::connected((__bridge void*)strongHost, "panel_did_change_to_directory_url");
    }
    if (selector == @selector(panel:userEnteredFilename:confirmed:))
    {
        return strongHost && cocoon::Signal<cocoon::SavePanel, std::string(std::string, bool)>::connected((__bridge void*)strongHost, "panel_user_entered_filename_confirmed");
    }
    if (selector == @selector(panel:willExpand:))
    {
        return strongHost && cocoon::Signal<cocoon::SavePanel, void(bool)>::connected((__bridge void*)strongHost, "panel_will_expand");
    }
    if (selector == @selector(panelSelectionDidChange:))
    {
        return strongHost && cocoon::Signal<cocoon::SavePanel, void()>::connected((__bridge void*)strongHost, "panel_selection_did_change");
    }
    if (selector == @selector(panel:displayNameForType:))
    {
        return strongHost && cocoon::Signal<cocoon::SavePanel, std::string(cocoon::Object)>::connected((__bridge void*)strongHost, "panel_display_name_for_type");
    }
    if (selector == @selector(panel:didSelectType:))
    {
        return strongHost && cocoon::Signal<cocoon::SavePanel, void(cocoon::Object)>::connected((__bridge void*)strongHost, "panel_did_select_type");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    SavePanel::SavePanel() : SavePanel(Adopt{cocoon::internal::retain([::NSSavePanel savePanel])})
    {
        SavePanel::install_delegate_delegate_(handle());
    }

    SavePanel::SavePanel(std::nullptr_t) : Panel(nullptr)
    {
    }

    SavePanel::SavePanel(Adopt adopt) : Panel(adopt)
    {
    }

    void SavePanel::begin_sheet_modal_for_window(const Window& window, std::function<void(std::int64_t)> handler) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) beginSheetModalForWindow:cocoon::internal::native<::NSWindow>(window) completionHandler:(handler ? (void (^)(::NSModalResponse)) ^ void(::NSModalResponse a74_0) { handler(static_cast<std::int64_t>(a74_0)); } : (void (^)(::NSModalResponse))nil)];
    }

    void SavePanel::begin_with_completion_handler(std::function<void(std::int64_t)> handler) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) beginWithCompletionHandler:(handler ? (void (^)(::NSModalResponse)) ^ void(::NSModalResponse a75_0) { handler(static_cast<std::int64_t>(a75_0)); } : (void (^)(::NSModalResponse))nil)];
    }

    void SavePanel::cancel(const Object& sender) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) cancel:cocoon::internal::native_id(sender)];
    }

    void SavePanel::ok(const Object& sender) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) ok:cocoon::internal::native_id(sender)];
    }

    std::int64_t SavePanel::run_modal() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSSavePanel>(this) runModal]);
    }

    void SavePanel::validate_visible_columns() const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) validateVisibleColumns];
    }

    URL SavePanel::url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSSavePanel>(this) URL]);
    }

    View SavePanel::accessory_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSSavePanel>(this) accessoryView]);
    }

    void SavePanel::set_accessory_view(const View& value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setAccessoryView:cocoon::internal::native<::NSView>(value)];
    }

    std::vector<Object> SavePanel::allowed_content_types() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSSavePanel>(this) allowedContentTypes], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    void SavePanel::set_allowed_content_types(const std::vector<Object>& value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setAllowedContentTypes:cocoon::internal::to_array(value, [](const Object& e) -> id
                                                                                                     {
                                                                                                         return cocoon::internal::native_id(e);
                                                                                                     })];
    }

    bool SavePanel::allows_other_file_types() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSavePanel>(this) allowsOtherFileTypes]);
    }

    void SavePanel::set_allows_other_file_types(bool value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setAllowsOtherFileTypes:static_cast<::BOOL>(value)];
    }

    bool SavePanel::can_create_directories() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSavePanel>(this) canCreateDirectories]);
    }

    void SavePanel::set_can_create_directories(bool value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setCanCreateDirectories:static_cast<::BOOL>(value)];
    }

    bool SavePanel::can_select_hidden_extension() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSavePanel>(this) canSelectHiddenExtension]);
    }

    void SavePanel::set_can_select_hidden_extension(bool value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setCanSelectHiddenExtension:static_cast<::BOOL>(value)];
    }

    Object SavePanel::current_content_type() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSSavePanel>(this) currentContentType]);
    }

    void SavePanel::set_current_content_type(const Object& value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setCurrentContentType:cocoon::internal::native_id(value)];
    }

    URL SavePanel::directory_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSSavePanel>(this) directoryURL]);
    }

    void SavePanel::set_directory_url(const URL& value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setDirectoryURL:cocoon::internal::native<::NSURL>(value)];
    }

    bool SavePanel::is_expanded() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSavePanel>(this) isExpanded]);
    }

    bool SavePanel::is_extension_hidden() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSavePanel>(this) isExtensionHidden]);
    }

    void SavePanel::set_extension_hidden(bool value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setExtensionHidden:static_cast<::BOOL>(value)];
    }

    std::string SavePanel::identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSavePanel>(this) identifier]);
    }

    void SavePanel::set_identifier(const std::string& value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setIdentifier:cocoon::internal::to(value)];
    }

    std::string SavePanel::message() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSavePanel>(this) message]);
    }

    void SavePanel::set_message(const std::string& value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setMessage:cocoon::internal::to(value)];
    }

    std::string SavePanel::name_field_label() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSavePanel>(this) nameFieldLabel]);
    }

    void SavePanel::set_name_field_label(const std::string& value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setNameFieldLabel:cocoon::internal::to(value)];
    }

    std::string SavePanel::name_field_string_value() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSavePanel>(this) nameFieldStringValue]);
    }

    void SavePanel::set_name_field_string_value(const std::string& value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setNameFieldStringValue:cocoon::internal::to(value)];
    }

    std::string SavePanel::prompt() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSavePanel>(this) prompt]);
    }

    void SavePanel::set_prompt(const std::string& value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setPrompt:cocoon::internal::to(value)];
    }

    bool SavePanel::shows_content_types() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSavePanel>(this) showsContentTypes]);
    }

    void SavePanel::set_shows_content_types(bool value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setShowsContentTypes:static_cast<::BOOL>(value)];
    }

    bool SavePanel::shows_hidden_files() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSavePanel>(this) showsHiddenFiles]);
    }

    void SavePanel::set_shows_hidden_files(bool value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setShowsHiddenFiles:static_cast<::BOOL>(value)];
    }

    bool SavePanel::shows_tag_field() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSavePanel>(this) showsTagField]);
    }

    void SavePanel::set_shows_tag_field(bool value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setShowsTagField:static_cast<::BOOL>(value)];
    }

    std::vector<std::string> SavePanel::tag_names() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSSavePanel>(this) tagNames], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void SavePanel::set_tag_names(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setTagNames:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                          {
                                                                                              return cocoon::internal::to(e);
                                                                                          })];
    }

    std::string SavePanel::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSavePanel>(this) title]);
    }

    void SavePanel::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setTitle:cocoon::internal::to(value)];
    }

    bool SavePanel::treats_file_packages_as_directories() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSavePanel>(this) treatsFilePackagesAsDirectories]);
    }

    void SavePanel::set_treats_file_packages_as_directories(bool value) const
    {
        [cocoon::internal::ns<::NSSavePanel>(this) setTreatsFilePackagesAsDirectories:static_cast<::BOOL>(value)];
    }

    void SavePanel::install_delegate_delegate_(void* native)
    {
        ::NSSavePanel* host = (__bridge ::NSSavePanel*)native;
        AKSavePanelDelegate* delegate = [[AKSavePanelDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSSavePanel* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSSavePanel* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
