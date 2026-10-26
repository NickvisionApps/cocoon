#include "generated/text_viewport_layout_controller.h"
#include "internal.h"

@interface AKTextViewportLayoutControllerDelegate : NSObject <NSTextViewportLayoutControllerDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKTextViewportLayoutControllerDelegate

- (CGRect)viewportBoundsForTextViewportLayoutController:(NSTextViewportLayoutController*)textViewportLayoutController
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::TextViewportLayoutController, cocoon::Rect()>::emit((__bridge void*)strongHost, "viewport_bounds_for_text_viewport_layout_controller");
    return cocoon::internal::to(__r);
}

- (void)textViewportLayoutController:(NSTextViewportLayoutController*)textViewportLayoutController configureRenderingSurfaceForTextLayoutFragment:(NSTextLayoutFragment*)textLayoutFragment
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextViewportLayoutController, void(cocoon::TextLayoutFragment)>::emit((__bridge void*)strongHost, "configure_rendering_surface_for_text_layout_fragment", cocoon::internal::wrap<cocoon::TextLayoutFragment>(textLayoutFragment));
}

- (void)textViewportLayoutControllerWillLayout:(NSTextViewportLayoutController*)textViewportLayoutController
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextViewportLayoutController, void()>::emit((__bridge void*)strongHost, "will_layout");
}

- (void)textViewportLayoutControllerDidLayout:(NSTextViewportLayoutController*)textViewportLayoutController
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::TextViewportLayoutController, void()>::emit((__bridge void*)strongHost, "did_layout");
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(viewportBoundsForTextViewportLayoutController:))
    {
        return strongHost && cocoon::Signal<cocoon::TextViewportLayoutController, cocoon::Rect()>::connected((__bridge void*)strongHost, "viewport_bounds_for_text_viewport_layout_controller");
    }
    if (selector == @selector(textViewportLayoutController:configureRenderingSurfaceForTextLayoutFragment:))
    {
        return strongHost && cocoon::Signal<cocoon::TextViewportLayoutController, void(cocoon::TextLayoutFragment)>::connected((__bridge void*)strongHost, "configure_rendering_surface_for_text_layout_fragment");
    }
    if (selector == @selector(textViewportLayoutControllerWillLayout:))
    {
        return strongHost && cocoon::Signal<cocoon::TextViewportLayoutController, void()>::connected((__bridge void*)strongHost, "will_layout");
    }
    if (selector == @selector(textViewportLayoutControllerDidLayout:))
    {
        return strongHost && cocoon::Signal<cocoon::TextViewportLayoutController, void()>::connected((__bridge void*)strongHost, "did_layout");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    TextViewportLayoutController::TextViewportLayoutController(const TextLayoutManager& text_layout_manager) : TextViewportLayoutController(Adopt{cocoon::internal::retain([[::NSTextViewportLayoutController alloc] initWithTextLayoutManager:cocoon::internal::native<::NSTextLayoutManager>(text_layout_manager)])})
    {
        TextViewportLayoutController::install_delegate_delegate_(handle());
    }

    TextViewportLayoutController::TextViewportLayoutController() : Object(nullptr)
    {
    }

    TextViewportLayoutController::TextViewportLayoutController(std::nullptr_t) : Object(nullptr)
    {
    }

    TextViewportLayoutController::TextViewportLayoutController(Adopt adopt) : Object(adopt)
    {
    }

    void TextViewportLayoutController::adjust_viewport_by_vertical_offset(double vertical_offset) const
    {
        [cocoon::internal::ns<::NSTextViewportLayoutController>(this) adjustViewportByVerticalOffset:static_cast<::CGFloat>(vertical_offset)];
    }

    void TextViewportLayoutController::layout_viewport() const
    {
        [cocoon::internal::ns<::NSTextViewportLayoutController>(this) layoutViewport];
    }

    double TextViewportLayoutController::relocate_viewport_to_text_location(const Object& text_location) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTextViewportLayoutController>(this) relocateViewportToTextLocation:cocoon::internal::native_id(text_location)]);
    }

    TextLayoutManager TextViewportLayoutController::text_layout_manager() const
    {
        return cocoon::internal::wrap<TextLayoutManager>([cocoon::internal::ns<::NSTextViewportLayoutController>(this) textLayoutManager]);
    }

    Rect TextViewportLayoutController::viewport_bounds() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextViewportLayoutController>(this) viewportBounds]);
    }

    TextRange TextViewportLayoutController::viewport_range() const
    {
        return cocoon::internal::wrap<TextRange>([cocoon::internal::ns<::NSTextViewportLayoutController>(this) viewportRange]);
    }

    void TextViewportLayoutController::install_delegate_delegate_(void* native)
    {
        ::NSTextViewportLayoutController* host = (__bridge ::NSTextViewportLayoutController*)native;
        AKTextViewportLayoutControllerDelegate* delegate = [[AKTextViewportLayoutControllerDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSTextViewportLayoutController* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSTextViewportLayoutController* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
