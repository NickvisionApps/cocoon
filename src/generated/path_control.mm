#include "generated/path_control.h"
#include "internal.h"

@interface AKPathControlDelegate : NSObject <NSPathControlDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKPathControlDelegate

- (BOOL)pathControl:(NSPathControl*)pathControl shouldDragItem:(NSPathControlItem*)pathItem withPasteboard:(NSPasteboard*)pasteboard
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::PathControl, bool(cocoon::PathControlItem, cocoon::Pasteboard)>::emit((__bridge void*)strongHost, "should_drag_item_with_pasteboard", cocoon::internal::wrap<cocoon::PathControlItem>(pathItem), cocoon::internal::wrap<cocoon::Pasteboard>(pasteboard));
    return static_cast<::BOOL>(__r);
}

- (BOOL)pathControl:(NSPathControl*)pathControl shouldDragPathComponentCell:(NSPathComponentCell*)pathComponentCell withPasteboard:(NSPasteboard*)pasteboard
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::PathControl, bool(cocoon::PathComponentCell, cocoon::Pasteboard)>::emit((__bridge void*)strongHost, "should_drag_path_component_cell_with_pasteboard", cocoon::internal::wrap<cocoon::PathComponentCell>(pathComponentCell), cocoon::internal::wrap<cocoon::Pasteboard>(pasteboard));
    return static_cast<::BOOL>(__r);
}

- (NSDragOperation)pathControl:(NSPathControl*)pathControl validateDrop:(id<NSDraggingInfo>)info
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::PathControl, cocoon::DragOperation(cocoon::Object)>::emit((__bridge void*)strongHost, "validate_drop", cocoon::internal::wrap<cocoon::Object>(info));
    return static_cast<::NSDragOperation>(__r);
}

- (BOOL)pathControl:(NSPathControl*)pathControl acceptDrop:(id<NSDraggingInfo>)info
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::PathControl, bool(cocoon::Object)>::emit((__bridge void*)strongHost, "accept_drop", cocoon::internal::wrap<cocoon::Object>(info));
    return static_cast<::BOOL>(__r);
}

- (void)pathControl:(NSPathControl*)pathControl willDisplayOpenPanel:(NSOpenPanel*)openPanel
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::PathControl, void(cocoon::OpenPanel)>::emit((__bridge void*)strongHost, "will_display_open_panel", cocoon::internal::wrap<cocoon::OpenPanel>(openPanel));
}

- (void)pathControl:(NSPathControl*)pathControl willPopUpMenu:(NSMenu*)menu
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::PathControl, void(cocoon::Menu)>::emit((__bridge void*)strongHost, "will_pop_up_menu", cocoon::internal::wrap<cocoon::Menu>(menu));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(pathControl:shouldDragItem:withPasteboard:))
    {
        return strongHost && cocoon::Signal<cocoon::PathControl, bool(cocoon::PathControlItem, cocoon::Pasteboard)>::connected((__bridge void*)strongHost, "should_drag_item_with_pasteboard");
    }
    if (selector == @selector(pathControl:shouldDragPathComponentCell:withPasteboard:))
    {
        return strongHost && cocoon::Signal<cocoon::PathControl, bool(cocoon::PathComponentCell, cocoon::Pasteboard)>::connected((__bridge void*)strongHost, "should_drag_path_component_cell_with_pasteboard");
    }
    if (selector == @selector(pathControl:validateDrop:))
    {
        return strongHost && cocoon::Signal<cocoon::PathControl, cocoon::DragOperation(cocoon::Object)>::connected((__bridge void*)strongHost, "validate_drop");
    }
    if (selector == @selector(pathControl:acceptDrop:))
    {
        return strongHost && cocoon::Signal<cocoon::PathControl, bool(cocoon::Object)>::connected((__bridge void*)strongHost, "accept_drop");
    }
    if (selector == @selector(pathControl:willDisplayOpenPanel:))
    {
        return strongHost && cocoon::Signal<cocoon::PathControl, void(cocoon::OpenPanel)>::connected((__bridge void*)strongHost, "will_display_open_panel");
    }
    if (selector == @selector(pathControl:willPopUpMenu:))
    {
        return strongHost && cocoon::Signal<cocoon::PathControl, void(cocoon::Menu)>::connected((__bridge void*)strongHost, "will_pop_up_menu");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    PathControl::PathControl() : PathControl(Adopt{cocoon::internal::retain([[::NSPathControl alloc] init])})
    {
        PathControl::install_delegate_delegate_(handle());
    }

    PathControl::PathControl(std::nullptr_t) : Control(nullptr)
    {
    }

    PathControl::PathControl(Adopt adopt) : Control(adopt)
    {
    }

    void PathControl::set_dragging_source_operation_mask(DragOperation mask, bool is_local) const
    {
        [cocoon::internal::ns<::NSPathControl>(this) setDraggingSourceOperationMask:static_cast<::NSDragOperation>(mask) forLocal:static_cast<::BOOL>(is_local)];
    }

    URL PathControl::url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSPathControl>(this) URL]);
    }

    void PathControl::set_url(const URL& value) const
    {
        [cocoon::internal::ns<::NSPathControl>(this) setURL:cocoon::internal::native<::NSURL>(value)];
    }

    std::vector<std::string> PathControl::allowed_types() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSPathControl>(this) allowedTypes], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void PathControl::set_allowed_types(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSPathControl>(this) setAllowedTypes:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                {
                                                                                                    return cocoon::internal::to(e);
                                                                                                })];
    }

    Color PathControl::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSPathControl>(this) backgroundColor]);
    }

    void PathControl::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSPathControl>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    PathControlItem PathControl::clicked_path_item() const
    {
        return cocoon::internal::wrap<PathControlItem>([cocoon::internal::ns<::NSPathControl>(this) clickedPathItem]);
    }

    std::string PathControl::double_action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSPathControl>(this) doubleAction]));
    }

    void PathControl::set_double_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPathControl>(this) setDoubleAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    bool PathControl::is_editable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPathControl>(this) isEditable]);
    }

    void PathControl::set_editable(bool value) const
    {
        [cocoon::internal::ns<::NSPathControl>(this) setEditable:static_cast<::BOOL>(value)];
    }

    Menu PathControl::menu() const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSPathControl>(this) menu]);
    }

    void PathControl::set_menu(const Menu& value) const
    {
        [cocoon::internal::ns<::NSPathControl>(this) setMenu:cocoon::internal::native<::NSMenu>(value)];
    }

    std::vector<PathControlItem> PathControl::path_items() const
    {
        return cocoon::internal::from_array<PathControlItem>([cocoon::internal::ns<::NSPathControl>(this) pathItems], [](id e) -> PathControlItem
                                                             {
                                                                 return cocoon::internal::wrap<PathControlItem>((::NSPathControlItem*)e);
                                                             });
    }

    void PathControl::set_path_items(const std::vector<PathControlItem>& value) const
    {
        [cocoon::internal::ns<::NSPathControl>(this) setPathItems:cocoon::internal::to_array(value, [](const PathControlItem& e) -> id
                                                                                             {
                                                                                                 return cocoon::internal::native<::NSPathControlItem>(e);
                                                                                             })];
    }

    PathStyle PathControl::path_style() const
    {
        return static_cast<PathStyle>([cocoon::internal::ns<::NSPathControl>(this) pathStyle]);
    }

    void PathControl::set_path_style(PathStyle value) const
    {
        [cocoon::internal::ns<::NSPathControl>(this) setPathStyle:static_cast<::NSPathStyle>(value)];
    }

    AttributedString PathControl::placeholder_attributed_string() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSPathControl>(this) placeholderAttributedString]);
    }

    void PathControl::set_placeholder_attributed_string(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSPathControl>(this) setPlaceholderAttributedString:cocoon::internal::native<::NSAttributedString>(value)];
    }

    std::string PathControl::placeholder_string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPathControl>(this) placeholderString]);
    }

    void PathControl::set_placeholder_string(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPathControl>(this) setPlaceholderString:cocoon::internal::to(value)];
    }

    void PathControl::install_delegate_delegate_(void* native)
    {
        ::NSPathControl* host = (__bridge ::NSPathControl*)native;
        AKPathControlDelegate* delegate = [[AKPathControlDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSPathControl* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSPathControl* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
