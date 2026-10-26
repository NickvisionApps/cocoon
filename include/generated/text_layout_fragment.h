#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CGContext;
    class OperationQueue;
    class TextAttachmentViewProvider;
    class TextElement;
    class TextLayoutManager;
    class TextLineFragment;
    class TextRange;

    /**
     * @brief C++ handle for the Objective-C class `NSTextLayoutFragment` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextLayoutFragment text_layout_fragment{cocoon::TextElement(), cocoon::TextRange()};
     * text_layout_fragment.set_layout_queue(cocoon::OperationQueue());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextLayoutFragment text_layout_fragment{cocoon::TextElement(), cocoon::TextRange()};
     * text_layout_fragment.set_layout_queue(cocoon::OperationQueue());
     * auto layout_queue = text_layout_fragment.layout_queue();
     * text_layout_fragment.invalidate_layout();
     * text_layout_fragment.text_line_fragment_for_vertical_offset(1, true);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextlayoutfragment
     */
    class TextLayoutFragment : public Object
    {
    public:
        /// @brief Creates a new `NSTextLayoutFragment` instance and returns a handle to it.
        explicit TextLayoutFragment(const TextElement& text_element, const TextRange& range_in_element);
        TextLayoutFragment();
        /// @brief Creates a null handle that refers to no native object.
        TextLayoutFragment(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextLayoutFragment(Adopt adopt);
        /**
         * @brief Calls `-[NSTextLayoutFragment drawAtPoint:inContext:]`.
         * @param point Argument converted to the Objective-C parameter of the same role.
         * @param context Argument converted to the Objective-C parameter of the same role.
         */
        void draw_at_point(const Point& point, const CGContext& context) const;
        /**
         * @brief Calls `-[NSTextLayoutFragment frameForTextAttachmentAtLocation:]`.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect frame_for_text_attachment_at_location(const Object& location) const;
        /**
         * @brief Calls `-[NSTextLayoutFragment invalidateLayout]`.
         */
        void invalidate_layout() const;
        /**
         * @brief Calls `-[NSTextLayoutFragment textLineFragmentForTextLocation:isUpstreamAffinity:]`.
         * @param text_location Argument converted to the Objective-C parameter of the same role.
         * @param is_upstream_affinity Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextLineFragment text_line_fragment_for_text_location(const Object& text_location, bool is_upstream_affinity) const;
        /**
         * @brief Calls `-[NSTextLayoutFragment textLineFragmentForVerticalOffset:requiresExactMatch:]`.
         * @param vertical_offset Argument converted to the Objective-C parameter of the same role.
         * @param requires_exact_match Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextLineFragment text_line_fragment_for_vertical_offset(double vertical_offset, bool requires_exact_match) const;
        /**
         * @brief Returns the `bottomMargin` property of `NSTextLayoutFragment`.
         * @return The converted Objective-C result.
         */
        double bottom_margin() const;
        /**
         * @brief Returns the `layoutFragmentFrame` property of `NSTextLayoutFragment`.
         * @return The converted Objective-C result.
         */
        Rect layout_fragment_frame() const;
        /**
         * @brief Returns the `layoutQueue` property of `NSTextLayoutFragment`.
         * @return The converted Objective-C result.
         */
        OperationQueue layout_queue() const;
        /**
         * @brief Sets the `layoutQueue` property of `NSTextLayoutFragment`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_layout_queue(const OperationQueue& value) const;
        /**
         * @brief Returns the `leadingPadding` property of `NSTextLayoutFragment`.
         * @return The converted Objective-C result.
         */
        double leading_padding() const;
        /**
         * @brief Returns the `rangeInElement` property of `NSTextLayoutFragment`.
         * @return The converted Objective-C result.
         */
        TextRange range_in_element() const;
        /**
         * @brief Returns the `renderingSurfaceBounds` property of `NSTextLayoutFragment`.
         * @return The converted Objective-C result.
         */
        Rect rendering_surface_bounds() const;
        /**
         * @brief Returns the `state` property of `NSTextLayoutFragment`.
         * @return The converted Objective-C result.
         */
        TextLayoutFragmentState state() const;
        /**
         * @brief Returns the `textAttachmentViewProviders` property of `NSTextLayoutFragment`.
         * @return The converted Objective-C result.
         */
        std::vector<TextAttachmentViewProvider> text_attachment_view_providers() const;
        /**
         * @brief Returns the `textElement` property of `NSTextLayoutFragment`.
         * @return The converted Objective-C result.
         */
        TextElement text_element() const;
        /**
         * @brief Returns the `textLayoutManager` property of `NSTextLayoutFragment`.
         * @return The converted Objective-C result.
         */
        TextLayoutManager text_layout_manager() const;
        /**
         * @brief Returns the `textLineFragments` property of `NSTextLayoutFragment`.
         * @return The converted Objective-C result.
         */
        std::vector<TextLineFragment> text_line_fragments() const;
        /**
         * @brief Returns the `topMargin` property of `NSTextLayoutFragment`.
         * @return The converted Objective-C result.
         */
        double top_margin() const;
        /**
         * @brief Returns the `trailingPadding` property of `NSTextLayoutFragment`.
         * @return The converted Objective-C result.
         */
        double trailing_padding() const;
    };
}
