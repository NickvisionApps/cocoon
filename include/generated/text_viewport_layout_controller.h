#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class TextLayoutFragment;
    class TextLayoutManager;
    class TextRange;

    /**
     * @brief C++ handle for the Objective-C class `NSTextViewportLayoutController` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextViewportLayoutController text_viewport_layout_controller{cocoon::TextLayoutManager()};
     * text_viewport_layout_controller.configure_rendering_surface_for_text_layout_fragment().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextViewportLayoutController text_viewport_layout_controller{cocoon::TextLayoutManager()};
     * text_viewport_layout_controller.adjust_viewport_by_vertical_offset(1);
     * text_viewport_layout_controller.layout_viewport();
     * text_viewport_layout_controller.configure_rendering_surface_for_text_layout_fragment().connect([](cocoon::TextLayoutFragment a0) {});
     * text_viewport_layout_controller.will_layout().connect([]() {});
     * text_viewport_layout_controller.did_layout().connect([]() {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextviewportlayoutcontroller
     */
    class TextViewportLayoutController : public Object
    {
    public:
        /// @brief Creates a new `NSTextViewportLayoutController` instance and returns a handle to it.
        explicit TextViewportLayoutController(const TextLayoutManager& text_layout_manager);
        TextViewportLayoutController();
        /// @brief Creates a null handle that refers to no native object.
        TextViewportLayoutController(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextViewportLayoutController(Adopt adopt);
        /**
     * @brief Calls `-[NSTextViewportLayoutController adjustViewportByVerticalOffset:]`.
     * @details Adjusts the viewport rect by the specified offset if needed. This is used to artificially move the viewport without affecting viewport content. The offset can be both positive and negative. - Parameters: - verticalOffset: The vertical offset to adjust by.
     * @param vertical_offset Argument converted to the Objective-C parameter of the same role.
     */
        void adjust_viewport_by_vertical_offset(double vertical_offset) const;
        /**
     * @brief Calls `-[NSTextViewportLayoutController layoutViewport]`.
     * @details Performs layout in the viewport.
     */
        void layout_viewport() const;
        /**
     * @brief Calls `-[NSTextViewportLayoutController relocateViewportToTextLocation:]`.
     * @details Relocates the viewport to start with the specified location. This is used to programmatically scroll to the specified location. - Parameters: - textLocation: The document location to scroll to. - Returns: The suggested viewport anchor point.
     * @param text_location Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double relocate_viewport_to_text_location(const Object& text_location) const;
        /**
     * @brief Returns the `textLayoutManager` property of `NSTextViewportLayoutController`.
     * @details The text layout manager for this viewport layout controller.
     * @return The converted Objective-C result.
     */
        TextLayoutManager text_layout_manager() const;
        /**
     * @brief Returns the `viewportBounds` property of `NSTextViewportLayoutController`.
     * @details The visible bounds of the view, plus the overdraw area. Not KVO-compliant.
     * @return The converted Objective-C result.
     */
        Rect viewport_bounds() const;
        /**
     * @brief Returns the `viewportRange` property of `NSTextViewportLayoutController`.
     * @details The text range of the current viewport layout. Not KVO-compliant.
     * @return The converted Objective-C result.
     */
        TextRange viewport_range() const;
        /// @brief Signal for the delegate/data-source method behind `viewport_bounds_for_text_viewport_layout_controller`; connect a callback with `viewport_bounds_for_text_viewport_layout_controller().connect(...)`.
        Signal<TextViewportLayoutController, Rect()> viewport_bounds_for_text_viewport_layout_controller() const
        {
            return Signal<TextViewportLayoutController, Rect()>(handle(), "viewport_bounds_for_text_viewport_layout_controller");
        }
        /// @brief Signal for the delegate/data-source method behind `configure_rendering_surface_for_text_layout_fragment`; connect a callback with `configure_rendering_surface_for_text_layout_fragment().connect(...)`.
        Signal<TextViewportLayoutController, void(TextLayoutFragment)> configure_rendering_surface_for_text_layout_fragment() const
        {
            return Signal<TextViewportLayoutController, void(TextLayoutFragment)>(handle(), "configure_rendering_surface_for_text_layout_fragment");
        }
        /// @brief Signal for the delegate/data-source method behind `will_layout`; connect a callback with `will_layout().connect(...)`.
        Signal<TextViewportLayoutController, void()> will_layout() const
        {
            return Signal<TextViewportLayoutController, void()>(handle(), "will_layout");
        }
        /// @brief Signal for the delegate/data-source method behind `did_layout`; connect a callback with `did_layout().connect(...)`.
        Signal<TextViewportLayoutController, void()> did_layout() const
        {
            return Signal<TextViewportLayoutController, void()>(handle(), "did_layout");
        }
        /// @brief Signal for the delegate/data-source method behind `cache_rendering_surface_for_key`; connect a callback with `cache_rendering_surface_for_key().connect(...)`.
        Signal<TextViewportLayoutController, void(Object, Object)> cache_rendering_surface_for_key() const
        {
            return Signal<TextViewportLayoutController, void(Object, Object)>(handle(), "cache_rendering_surface_for_key");
        }
        /// @brief Signal for the delegate/data-source method behind `retrieve_cached_rendering_surface_for_key`; connect a callback with `retrieve_cached_rendering_surface_for_key().connect(...)`.
        Signal<TextViewportLayoutController, Object(Object)> retrieve_cached_rendering_surface_for_key() const
        {
            return Signal<TextViewportLayoutController, Object(Object)>(handle(), "retrieve_cached_rendering_surface_for_key");
        }
        /// @brief Signal for the delegate/data-source method behind `received_set_needs_layout`; connect a callback with `received_set_needs_layout().connect(...)`.
        Signal<TextViewportLayoutController, void()> received_set_needs_layout() const
        {
            return Signal<TextViewportLayoutController, void()>(handle(), "received_set_needs_layout");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
