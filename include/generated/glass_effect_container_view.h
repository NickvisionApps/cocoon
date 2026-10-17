#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class View;

    /**
     * @brief Groups glass views so they blend (NSGlassEffectContainerView, macOS 26).
     * @details A view that efficiently merges descendant glass effect views together when they are within a specified proximity to each other. - Tip: Using a glass effect container view can improve performance by reducing the number of passes required to render similar glass effect views.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * cocoon::GlassEffectContainerView container;
     * container.set_spacing(24);
     * cocoon::GlassEffectView glass;
     * container.set_content_view(glass);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::GlassEffectContainerView glass_effect_container_view{};
     * glass_effect_container_view.set_content_view(cocoon::View());
     * auto content_view = glass_effect_container_view.content_view();
     * glass_effect_container_view.set_spacing(1);
     * auto spacing = glass_effect_container_view.spacing();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsglasseffectcontainerview
     */
    class GlassEffectContainerView : public View
    {
    public:
        /// @brief Creates a new `NSGlassEffectContainerView` instance and returns a handle to it.
        explicit GlassEffectContainerView();
        /// @brief Creates a null handle that refers to no native object.
        GlassEffectContainerView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit GlassEffectContainerView(Adopt adopt);
        /**
     * @brief Returns the `contentView` property of `NSGlassEffectContainerView`.
     * @details The view that contains descendant views to merge together when in proximity to each other. The glass effect container view does the following: 1. Elevates the z-order of descendants of 'contentView' to position them above the 'contentView'. 2. Merges descendants together if the views are sufficiently similar and within the proximity specified in ''spacing''. 3. Processes similar glass effect views as a batch to improve performance.
     * @return The converted Objective-C result.
     */
        View content_view() const;
        /**
     * @brief Sets the `contentView` property of `NSGlassEffectContainerView`.
     * @details The view that contains descendant views to merge together when in proximity to each other. The glass effect container view does the following: 1. Elevates the z-order of descendants of 'contentView' to position them above the 'contentView'. 2. Merges descendants together if the views are sufficiently similar and within the proximity specified in ''spacing''. 3. Processes similar glass effect views as a batch to improve performance.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_view(const View& value) const;
        /**
     * @brief Returns the `spacing` property of `NSGlassEffectContainerView`.
     * @details The proximity at which the glass effect container view begins merging eligible descendent glass effect views. The default value, zero, is sufficient for batch processing eligible glass effect views, while avoiding distortion and merging effects for other views in close proximity.
     * @return The converted Objective-C result.
     */
        double spacing() const;
        /**
     * @brief Sets the `spacing` property of `NSGlassEffectContainerView`.
     * @details The proximity at which the glass effect container view begins merging eligible descendent glass effect views. The default value, zero, is sufficient for batch processing eligible glass effect views, while avoiding distortion and merging effects for other views in close proximity.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_spacing(double value) const;
    };
}
