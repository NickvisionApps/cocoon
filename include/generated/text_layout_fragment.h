#pragma once

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
     * @details Renders the visual representation of this element in the specified graphics context. - Parameters: - point: The origin as a \<doc://com.apple.documentation/documentation/corefoundation/cgpoint>. - context: The graphics context to draw into.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @param context Argument converted to the Objective-C parameter of the same role.
     */
        void draw_at_point(const Point& point, const CGContext& context) const;
        /**
     * @brief Calls `-[NSTextLayoutFragment frameForTextAttachmentAtLocation:]`.
     * @details Returns the frame in the text layout fragment coordinate system for the attachment at the location you specify. Returns \<doc://com.apple.documentation/documentation/coregraphics/cgrectzero> if 'location' is not within any attachment or the state is not 'NSTextLayoutFragmentStateLayoutAvailable'. - Parameters: - location: The document location of the attachment. - Returns: The frame of the attachment, or 'CGRectZero'.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect frame_for_text_attachment_at_location(const Object& location) const;
        /**
     * @brief Calls `-[NSTextLayoutFragment invalidateLayout]`.
     * @details Invalidates any layout information associated with the text layout fragment.
     */
        void invalidate_layout() const;
        /**
     * @brief Calls `-[NSTextLayoutFragment textLineFragmentForTextLocation:isUpstreamAffinity:]`.
     * @details Returns a text line fragment from a specific text location in the document. Set 'isUpstreamAffinity' to 'true' to find a text fragment by its element range end location, such as when you enumerate over line fragments in reverse order. Set 'isUpstreamAffinity' to 'false' to find a text fragment that contains 'textLocation'. - Parameters: - textLocation: The text location to search for. - isUpstreamAffinity: When the location is at the end of a text line fragment (and the beginning of another), 'true' chooses the one ending with the location; 'false' chooses the following. - Returns: The matching line fragment, or 'nil'.
     * @param text_location Argument converted to the Objective-C parameter of the same role.
     * @param is_upstream_affinity Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        TextLineFragment text_line_fragment_for_text_location(const Object& text_location, bool is_upstream_affinity) const;
        /**
     * @brief Calls `-[NSTextLayoutFragment textLineFragmentForVerticalOffset:requiresExactMatch:]`.
     * @details Returns the text line fragment for the vertical offset you provide, or the closest text line fragment beyond the vertical offset. Set 'requiresExactMatch' to 'true' to find the text line fragment that contains the vertical offset, or set 'requiresExactMatch' to 'false' to find the closest text line fragment matching or beyond the vertical offset. Returns 'nil' if there isn't a match. - Parameters: - verticalOffset: The vertical offset to search for. - requiresExactMatch: When 'false', returns the closest line fragment beyond 'verticalOffset' if no line fragment contains it. - Returns: The matching line fragment, or 'nil'.
     * @param vertical_offset Argument converted to the Objective-C parameter of the same role.
     * @param requires_exact_match Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        TextLineFragment text_line_fragment_for_vertical_offset(double vertical_offset, bool requires_exact_match) const;
        /**
     * @brief Returns the `bottomMargin` property of `NSTextLayoutFragment`.
     * @details The amount of space reserved during paragraph layout between the bottom of the last line in the paragraph and the bottom of the text layout fragment.
     * @return The converted Objective-C result.
     */
        double bottom_margin() const;
        /**
     * @brief Returns the `layoutFragmentFrame` property of `NSTextLayoutFragment`.
     * @details The rectangle the framework uses for tiling the layout fragment inside the target layout coordinate system. Typically in an ''NSTextContainer'' coordinate system.
     * @return The converted Objective-C result.
     */
        Rect layout_fragment_frame() const;
        /**
     * @brief Returns the `layoutQueue` property of `NSTextLayoutFragment`.
     * @details The queue on which the framework dispatches layout operations. When non-nil, the layout operation is dispatched to the queue asynchronously.
     * @return The converted Objective-C result.
     */
        OperationQueue layout_queue() const;
        /**
     * @brief Sets the `layoutQueue` property of `NSTextLayoutFragment`.
     * @details The queue on which the framework dispatches layout operations. When non-nil, the layout operation is dispatched to the queue asynchronously.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_layout_queue(const OperationQueue& value) const;
        /**
     * @brief Returns the `leadingPadding` property of `NSTextLayoutFragment`.
     * @details The amount of margin space reserved during paragraph layout between the leading edge of the text layout fragment and the start of the lines in the paragraph. The leading edge is according to the primary writing direction of the paragraph.
     * @return The converted Objective-C result.
     */
        double leading_padding() const;
        /**
     * @brief Returns the `rangeInElement` property of `NSTextLayoutFragment`.
     * @details The range inside the text element relative to the document origin.
     * @return The converted Objective-C result.
     */
        TextRange range_in_element() const;
        /**
     * @brief Returns the `renderingSurfaceBounds` property of `NSTextLayoutFragment`.
     * @details The bounds defining the area required for rendering the contents. The coordinate system is relative to ''layoutFragmentFrame''. The coordinate system is vertically flipped, meaning origin ('{0,0}') is at the upper-left corner. The size should be larger than 'layoutFragmentFrame.size'. The origin could be in the negative coordinate since the rendering could be stretched out of 'layoutFragmentFrame'. Only valid when ''state'' is greater than 'NSTextLayoutFragmentStateEstimatedUsageBounds'.
     * @return The converted Objective-C result.
     */
        Rect rendering_surface_bounds() const;
        /**
     * @brief Returns the `state` property of `NSTextLayoutFragment`.
     * @details The layout information state. KVO-compliant.
     * @return The converted Objective-C result.
     */
        TextLayoutFragmentState state() const;
        /**
     * @brief Returns the `textAttachmentViewProviders` property of `NSTextLayoutFragment`.
     * @details The attachment view providers associated with the text layout fragment. The property contents are only valid with 'NSTextLayoutFragmentStateLayoutAvailable'.
     * @return The converted Objective-C result.
     */
        std::vector<TextAttachmentViewProvider> text_attachment_view_providers() const;
        /**
     * @brief Returns the `textElement` property of `NSTextLayoutFragment`.
     * @details The parent text element.
     * @return The converted Objective-C result.
     */
        TextElement text_element() const;
        /**
     * @brief Returns the `textLayoutManager` property of `NSTextLayoutFragment`.
     * @details The text layout manager for this text layout fragment.
     * @return The converted Objective-C result.
     */
        TextLayoutManager text_layout_manager() const;
        /**
     * @brief Returns the `textLineFragments` property of `NSTextLayoutFragment`.
     * @details An array of text line fragments. Valid when ''state'' is 'NSTextLayoutFragmentStateLayoutAvailable'. KVO-compliant.
     * @return The converted Objective-C result.
     */
        std::vector<TextLineFragment> text_line_fragments() const;
        /**
     * @brief Returns the `topMargin` property of `NSTextLayoutFragment`.
     * @details The amount of space reserved during paragraph layout between the top of the text layout fragment and the top of the first line in the paragraph.
     * @return The converted Objective-C result.
     */
        double top_margin() const;
        /**
     * @brief Returns the `trailingPadding` property of `NSTextLayoutFragment`.
     * @details The amount of margin space reserved during paragraph layout between the end of the lines in the paragraph and the trailing edge of the text layout fragment. The trailing edge is according to the primary writing direction of the paragraph.
     * @return The converted Objective-C result.
     */
        double trailing_padding() const;
    };
}
