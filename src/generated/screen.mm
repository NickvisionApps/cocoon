#include "generated/screen.h"
#include "internal.h"

namespace cocoon
{
    Screen::Screen() : Screen(Adopt{cocoon::internal::retain([[::NSScreen alloc] init])})
    {
    }

    Screen::Screen(std::nullptr_t) : Object(nullptr)
    {
    }

    Screen::Screen(Adopt adopt) : Object(adopt)
    {
    }

    Rect Screen::backing_aligned_rect(const Rect& rect, AlignmentOptions options) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScreen>(this) backingAlignedRect:cocoon::internal::to(rect) options:static_cast<::NSAlignmentOptions>(options)]);
    }

    bool Screen::can_represent_display_gamut(DisplayGamut display_gamut) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScreen>(this) canRepresentDisplayGamut:static_cast<::NSDisplayGamut>(display_gamut)]);
    }

    Rect Screen::convert_rect_from_backing(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScreen>(this) convertRectFromBacking:cocoon::internal::to(rect)]);
    }

    Rect Screen::convert_rect_to_backing(const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScreen>(this) convertRectToBacking:cocoon::internal::to(rect)]);
    }

    Object Screen::display_link_with_target(const Object& target, const std::string& selector) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSScreen>(this) displayLinkWithTarget:cocoon::internal::native_id(target) selector:NSSelectorFromString(cocoon::internal::to(selector))]);
    }

    unsigned int Screen::cg_direct_display_id() const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSScreen>(this) CGDirectDisplayID]);
    }

    Rect Screen::auxiliary_top_left_area() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScreen>(this) auxiliaryTopLeftArea]);
    }

    Rect Screen::auxiliary_top_right_area() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScreen>(this) auxiliaryTopRightArea]);
    }

    double Screen::backing_scale_factor() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSScreen>(this) backingScaleFactor]);
    }

    ColorSpace Screen::color_space() const
    {
        return cocoon::internal::wrap<ColorSpace>([cocoon::internal::ns<::NSScreen>(this) colorSpace]);
    }

    Screen Screen::deepest_screen()
    {
        return cocoon::internal::wrap<Screen>([::NSScreen deepestScreen]);
    }

    WindowDepth Screen::depth() const
    {
        return static_cast<WindowDepth>([cocoon::internal::ns<::NSScreen>(this) depth]);
    }

    std::map<std::string, Object> Screen::device_description() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSScreen>(this) deviceDescription], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    Rect Screen::frame() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScreen>(this) frame]);
    }

    std::string Screen::localized_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScreen>(this) localizedName]);
    }

    Screen Screen::main_screen()
    {
        return cocoon::internal::wrap<Screen>([::NSScreen mainScreen]);
    }

    Insets Screen::safe_area_insets() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScreen>(this) safeAreaInsets]);
    }

    std::vector<Screen> Screen::screens()
    {
        return cocoon::internal::from_array<Screen>([::NSScreen screens], [](id e) -> Screen
                                                    {
                                                        return cocoon::internal::wrap<Screen>((::NSScreen*)e);
                                                    });
    }

    bool Screen::screens_have_separate_spaces()
    {
        return static_cast<bool>([::NSScreen screensHaveSeparateSpaces]);
    }

    const WindowDepth* Screen::supported_window_depths() const
    {
        return (const WindowDepth*)([cocoon::internal::ns<::NSScreen>(this) supportedWindowDepths]);
    }

#ifdef COCOON_MACOS_27
    ScreenTouchCapabilities Screen::touch_capabilities() const
    {
        if (@available(macOS 27.0, *))
        {
            return static_cast<ScreenTouchCapabilities>([cocoon::internal::ns<::NSScreen>(this) touchCapabilities]);
        }
        return {};
    }

#endif
    Rect Screen::visible_frame() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScreen>(this) visibleFrame]);
    }
}
