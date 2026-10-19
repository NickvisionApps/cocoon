#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class View;

    /**
     * @brief A Liquid Glass surface (NSGlassEffectView, macOS 26).
     * @details A view that embeds its content view in a dynamic glass effect.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * cocoon::GlassEffectView glass;
     * glass.set_corner_radius(20);
     * cocoon::HStack content;
     * glass.set_content_view(content);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::GlassEffectView glass_effect_view{};
     * glass_effect_view.set_content_view(cocoon::View());
     * auto content_view = glass_effect_view.content_view();
     * glass_effect_view.set_corner_radius(1);
     * auto corner_radius = glass_effect_view.corner_radius();
     * glass_effect_view.set_style(cocoon::GlassStyle::Regular);
     * auto style = glass_effect_view.style();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsglasseffectview
     */
    class GlassEffectView : public View
    {
    public:
        /// @brief Creates a new `NSGlassEffectView` instance and returns a handle to it.
        explicit GlassEffectView();
        /// @brief Creates a null handle that refers to no native object.
        GlassEffectView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit GlassEffectView(Adopt adopt);
        /**
     * @brief Returns the `contentView` property of `NSGlassEffectView`.
     * @details The view to embed in glass. - Important: 'NSGlassEffectView' only guarantees the 'contentView' will be placed inside the glass effect; arbitrary subviews aren't guaranteed specific behavior with regard to z-order in relation to the content view or glass effect.
     * @return The converted Objective-C result.
     */
        View content_view() const;
        /**
     * @brief Sets the `contentView` property of `NSGlassEffectView`.
     * @details The view to embed in glass. - Important: 'NSGlassEffectView' only guarantees the 'contentView' will be placed inside the glass effect; arbitrary subviews aren't guaranteed specific behavior with regard to z-order in relation to the content view or glass effect.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_view(const View& value) const;
        /**
     * @brief Returns the `cornerRadius` property of `NSGlassEffectView`.
     * @details The amount of curvature for all corners of the glass.
     * @return The converted Objective-C result.
     */
        double corner_radius() const;
        /**
     * @brief Sets the `cornerRadius` property of `NSGlassEffectView`.
     * @details The amount of curvature for all corners of the glass.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_corner_radius(double value) const;
        /**
     * @brief Returns the `style` property of `NSGlassEffectView`.
     * @details The style of glass this view uses.
     * @return The converted Objective-C result.
     */
        GlassStyle style() const;
        /**
     * @brief Sets the `style` property of `NSGlassEffectView`.
     * @details The style of glass this view uses.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_style(GlassStyle value) const;
        /**
     * @brief Returns the `tintColor` property of `NSGlassEffectView`.
     * @details The color the glass effect view uses to tint the background and glass effect toward.
     * @return The converted Objective-C result.
     */
        Color tint_color() const;
        /**
     * @brief Sets the `tintColor` property of `NSGlassEffectView`.
     * @details The color the glass effect view uses to tint the background and glass effect toward.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tint_color(const Color& value) const;
    };
}
