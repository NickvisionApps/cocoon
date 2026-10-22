#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class ColorSpace;

    /**
     * @brief C++ handle for the Objective-C class `NSScreen` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Screen screen;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Screen screen{};
     * screen.backing_aligned_rect({{0, 0}, {100, 100}}, cocoon::AlignmentOptions::MinXInward);
     * screen.can_represent_display_gamut(cocoon::DisplayGamut::SRGB);
     * screen.convert_rect_from_backing({{0, 0}, {100, 100}});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsscreen
     */
    class Screen : public Object
    {
    public:
        /// @brief Creates a new `NSScreen` instance and returns a handle to it.
        explicit Screen();
        /// @brief Creates a null handle that refers to no native object.
        Screen(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Screen(Adopt adopt);
        /**
         * @brief Calls `-[NSScreen backingAlignedRect:options:]`.
         * @details Uses NSIntegralRectWithOptions() to produce a pixel aligned rectangle on the target screen from the given input rectangle in global screen coordinates.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect backing_aligned_rect(const Rect& rect, AlignmentOptions options) const;
        /**
         * @brief Calls `-[NSScreen canRepresentDisplayGamut:]`.
         * @details canRepresentDisplayGamut: returns YES if the colorSpace of the receiving screen is capable of representing the given display gamut
         * @param display_gamut Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool can_represent_display_gamut(DisplayGamut display_gamut) const;
        /**
         * @brief Calls `-[NSScreen convertRectFromBacking:]`.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect convert_rect_from_backing(const Rect& rect) const;
        /**
         * @brief Calls `-[NSScreen convertRectToBacking:]`.
         * @details Convert to/from the device pixel aligned coordinates system of a display
         * @param rect Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect convert_rect_to_backing(const Rect& rect) const;
        /**
         * @brief Calls `-[NSScreen displayLinkWithTarget:selector:]`.
         * @details Returns a new display link whose callback will be invoked in-sync with the display the screen is on. Note that views and windows can move between screens and you may want to get a display link directly from 'NSView' or 'NSWindow' which will track those changes automatically.
         * @param target Argument converted to the Objective-C parameter of the same role.
         * @param selector Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object display_link_with_target(const Object& target, const std::string& selector) const;
        /**
         * @brief Returns the `CGDirectDisplayID` property of `NSScreen`.
         * @details The CGDirectDisplayID for this screen. This will return kCGNullDirectDisplay if there isn't one.
         * @return The converted Objective-C result.
         */
        unsigned int cg_direct_display_id() const;
        /**
         * @brief Returns the `auxiliaryTopLeftArea` property of `NSScreen`.
         * @details The following two rects are at the top of the screen, outside the rectangle defined by safeAreaInsets, but also unobscured. These rects are empty if there are no additional unobscured areas
         * @return The converted Objective-C result.
         */
        Rect auxiliary_top_left_area() const;
        /**
         * @brief Returns the `auxiliaryTopRightArea` property of `NSScreen`.
         * @return The converted Objective-C result.
         */
        Rect auxiliary_top_right_area() const;
        /**
         * @brief Returns the `backingScaleFactor` property of `NSScreen`.
         * @details Returns the scale factor representing the number of backing store pixels corresponding to each linear unit in screen space on this NSScreen. This method is provided for rare cases when the explicit scale factor is needed. Please use -convertToBacking: methods whenever possible.
         * @return The converted Objective-C result.
         */
        double backing_scale_factor() const;
        /**
         * @brief Returns the `colorSpace` property of `NSScreen`.
         * @return The converted Objective-C result.
         */
        ColorSpace color_space() const;
        /**
         * @brief Returns the `deepestScreen` property of `NSScreen`.
         * @details \@property (class, readonly, nullable, strong) NSScreen mainScreen; / Screen with key window
         * @return The converted Objective-C result.
         */
        static Screen deepest_screen();
        /**
         * @brief Returns the `depth` property of `NSScreen`.
         * @return The converted Objective-C result.
         */
        WindowDepth depth() const;
        /**
         * @brief Returns the `deviceDescription` property of `NSScreen`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> device_description() const;
        /**
         * @brief Returns the `frame` property of `NSScreen`.
         * @return The converted Objective-C result.
         */
        Rect frame() const;
        /**
         * @brief Returns the `localizedName` property of `NSScreen`.
         * @return The converted Objective-C result.
         */
        std::string localized_name() const;
        /**
         * @brief Returns the `mainScreen` property of `NSScreen`.
         * @details \@property (class, readonly, copy) NSArray\<NSScreen > screens; / All screens; first one is "zero" screen
         * @return The converted Objective-C result.
         */
        static Screen main_screen();
        /**
         * @brief Returns the `safeAreaInsets` property of `NSScreen`.
         * @details Indicates the obscured distance from each edge of the screen
         * @return The converted Objective-C result.
         */
        Insets safe_area_insets() const;
        /**
         * @brief Returns the `screens` property of `NSScreen`.
         * @return The converted Objective-C result.
         */
        static std::vector<Screen> screens();
        /**
         * @brief Returns the `screensHaveSeparateSpaces` property of `NSScreen`.
         * @details screensHaveSeparateSpaces returns YES if each screen has its own set of spaces. This is a system setting and does not necessarily imply that there are multiple screens, nor that there are multiple spaces on any one screen
         * @return The converted Objective-C result.
         */
        static bool screens_have_separate_spaces();
        /**
         * @brief Returns the `supportedWindowDepths` property of `NSScreen`.
         * @return The converted Objective-C result.
         */
        const WindowDepth* supported_window_depths() const;
#ifdef COCOON_MACOS_27
        /**
         * @brief Returns the `touchCapabilities` property of `NSScreen`.
         * @return The converted Objective-C result.
         */
        ScreenTouchCapabilities touch_capabilities() const;
#endif

        /**
         * @brief Returns the `visibleFrame` property of `NSScreen`.
         * @return The converted Objective-C result.
         */
        Rect visible_frame() const;
    };
}
