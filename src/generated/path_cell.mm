#include "generated/path_cell.h"
#include "internal.h"

@interface AKPathCellDelegate : NSObject <NSPathCellDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKPathCellDelegate

- (void)pathCell:(NSPathCell*)pathCell willDisplayOpenPanel:(NSOpenPanel*)openPanel
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::PathCell, void(cocoon::OpenPanel)>::emit((__bridge void*)strongHost, "will_display_open_panel", cocoon::internal::wrap<cocoon::OpenPanel>(openPanel));
}

- (void)pathCell:(NSPathCell*)pathCell willPopUpMenu:(NSMenu*)menu
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::PathCell, void(cocoon::Menu)>::emit((__bridge void*)strongHost, "will_pop_up_menu", cocoon::internal::wrap<cocoon::Menu>(menu));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(pathCell:willDisplayOpenPanel:))
    {
        return strongHost && cocoon::Signal<cocoon::PathCell, void(cocoon::OpenPanel)>::connected((__bridge void*)strongHost, "will_display_open_panel");
    }
    if (selector == @selector(pathCell:willPopUpMenu:))
    {
        return strongHost && cocoon::Signal<cocoon::PathCell, void(cocoon::Menu)>::connected((__bridge void*)strongHost, "will_pop_up_menu");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    PathCell::PathCell() : PathCell(Adopt{cocoon::internal::retain([[::NSPathCell alloc] init])})
    {
        PathCell::install_delegate_delegate_(handle());
    }

    PathCell::PathCell(std::nullptr_t) : ActionCell(nullptr)
    {
    }

    PathCell::PathCell(Adopt adopt) : ActionCell(adopt)
    {
    }

    void PathCell::mouse_entered(const Event& event, const Rect& frame, const View& view) const
    {
        [cocoon::internal::ns<::NSPathCell>(this) mouseEntered:cocoon::internal::native<::NSEvent>(event) withFrame:cocoon::internal::to(frame) inView:cocoon::internal::native<::NSView>(view)];
    }

    void PathCell::mouse_exited(const Event& event, const Rect& frame, const View& view) const
    {
        [cocoon::internal::ns<::NSPathCell>(this) mouseExited:cocoon::internal::native<::NSEvent>(event) withFrame:cocoon::internal::to(frame) inView:cocoon::internal::native<::NSView>(view)];
    }

    PathComponentCell PathCell::path_component_cell_at_point(const Point& point, const Rect& frame, const View& view) const
    {
        return cocoon::internal::wrap<PathComponentCell>([cocoon::internal::ns<::NSPathCell>(this) pathComponentCellAtPoint:cocoon::internal::to(point) withFrame:cocoon::internal::to(frame) inView:cocoon::internal::native<::NSView>(view)]);
    }

    Rect PathCell::rect_of_path_component_cell(const PathComponentCell& cell, const Rect& frame, const View& view) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPathCell>(this) rectOfPathComponentCell:cocoon::internal::native<::NSPathComponentCell>(cell) withFrame:cocoon::internal::to(frame) inView:cocoon::internal::native<::NSView>(view)]);
    }

    void PathCell::set_object_value(const Object& obj) const
    {
        [cocoon::internal::ns<::NSPathCell>(this) setObjectValue:cocoon::internal::native_id(obj)];
    }

    URL PathCell::url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSPathCell>(this) URL]);
    }

    void PathCell::set_url(const URL& value) const
    {
        [cocoon::internal::ns<::NSPathCell>(this) setURL:cocoon::internal::native<::NSURL>(value)];
    }

    std::vector<std::string> PathCell::allowed_types() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSPathCell>(this) allowedTypes], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void PathCell::set_allowed_types(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSPathCell>(this) setAllowedTypes:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                             {
                                                                                                 return cocoon::internal::to(e);
                                                                                             })];
    }

    Color PathCell::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSPathCell>(this) backgroundColor]);
    }

    void PathCell::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSPathCell>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    PathComponentCell PathCell::clicked_path_component_cell() const
    {
        return cocoon::internal::wrap<PathComponentCell>([cocoon::internal::ns<::NSPathCell>(this) clickedPathComponentCell]);
    }

    std::string PathCell::double_action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSPathCell>(this) doubleAction]));
    }

    void PathCell::set_double_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPathCell>(this) setDoubleAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    std::string PathCell::path_component_cell_class()
    {
        return cocoon::internal::from(NSStringFromClass([::NSPathCell pathComponentCellClass]));
    }

    std::vector<PathComponentCell> PathCell::path_component_cells() const
    {
        return cocoon::internal::from_array<PathComponentCell>([cocoon::internal::ns<::NSPathCell>(this) pathComponentCells], [](id e) -> PathComponentCell
                                                               {
                                                                   return cocoon::internal::wrap<PathComponentCell>((::NSPathComponentCell*)e);
                                                               });
    }

    void PathCell::set_path_component_cells(const std::vector<PathComponentCell>& value) const
    {
        [cocoon::internal::ns<::NSPathCell>(this) setPathComponentCells:cocoon::internal::to_array(value, [](const PathComponentCell& e) -> id
                                                                                                   {
                                                                                                       return cocoon::internal::native<::NSPathComponentCell>(e);
                                                                                                   })];
    }

    PathStyle PathCell::path_style() const
    {
        return static_cast<PathStyle>([cocoon::internal::ns<::NSPathCell>(this) pathStyle]);
    }

    void PathCell::set_path_style(PathStyle value) const
    {
        [cocoon::internal::ns<::NSPathCell>(this) setPathStyle:static_cast<::NSPathStyle>(value)];
    }

    AttributedString PathCell::placeholder_attributed_string() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSPathCell>(this) placeholderAttributedString]);
    }

    void PathCell::set_placeholder_attributed_string(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSPathCell>(this) setPlaceholderAttributedString:cocoon::internal::native<::NSAttributedString>(value)];
    }

    std::string PathCell::placeholder_string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPathCell>(this) placeholderString]);
    }

    void PathCell::set_placeholder_string(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPathCell>(this) setPlaceholderString:cocoon::internal::to(value)];
    }

    void PathCell::install_delegate_delegate_(void* native)
    {
        ::NSPathCell* host = (__bridge ::NSPathCell*)native;
        AKPathCellDelegate* delegate = [[AKPathCellDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSPathCell* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSPathCell* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
