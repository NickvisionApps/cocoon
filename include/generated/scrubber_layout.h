#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Scrubber;
    class ScrubberLayoutAttributes;

    /**
     * @brief C++ handle for the Objective-C class `NSScrubberLayout` (AppKit).
     * @details \@class NSScrubberLayout \@abstract \@c NSScrubberLayout is an abstract class that describes the layout of items within a \@c NSScrubber control.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScrubberLayout scrubber_layout;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ScrubberLayout scrubber_layout{};
     * scrubber_layout.invalidate_layout();
     * scrubber_layout.layout_attributes_for_item_at_index(1);
     * scrubber_layout.layout_attributes_for_items_in_rect({{0, 0}, {100, 100}});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsscrubberlayout
     */
    class ScrubberLayout : public Object
    {
    public:
        /// @brief Creates a new `NSScrubberLayout` instance and returns a handle to it.
        explicit ScrubberLayout();
        /// @brief Creates a null handle that refers to no native object.
        ScrubberLayout(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScrubberLayout(Adopt adopt);
        /**
     * @brief Calls `-[NSScrubberLayout invalidateLayout]`.
     * @details Signals that layout has been invalidated and the NSScrubber should run a fresh layout pass. Subclasses may define more granular invalidation methods suitable for their own data structures, but those methods should always call up to -invalidateLayout.
     */
        void invalidate_layout() const;
        /**
     * @brief Calls `-[NSScrubberLayout layoutAttributesForItemAtIndex:]`.
     * @details Returns the layout attributes for a single item within the scrubber. The base implementation returns \@c nil.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ScrubberLayoutAttributes layout_attributes_for_item_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSScrubberLayout layoutAttributesForItemsInRect:]`.
     * @details Returns the set of layout attributes for all items within the provided rectangle. The base implementation returns an empty set.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<ScrubberLayoutAttributes> layout_attributes_for_items_in_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSScrubberLayout prepareLayout]`.
     * @details Following any invalidation in layout, \@c NSScrubber will call \@c prepareLayout on its layout object prior to requesting any other layout information. Subclasses should use this method to perform upfront calculations and caching. The base implementation of this method does nothing.
     */
        void prepare_layout() const;
        /**
     * @brief Calls `-[NSScrubberLayout shouldInvalidateLayoutForChangeFromVisibleRect:toVisibleRect:]`.
     * @details If \@c YES, the scrubber will invalidate its layout in response to a change in the visible region. The default value is \@c NO. Subclasses which rely on the size or origin of the visible region should return \@c YES.
     * @param from_visible_rect Argument converted to the Objective-C parameter of the same role.
     * @param to_visible_rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool should_invalidate_layout_for_change_from_visible_rect(const Rect& from_visible_rect, const Rect& to_visible_rect) const;
        /**
     * @brief Returns the `automaticallyMirrorsInRightToLeftLayout` property of `NSScrubberLayout`.
     * @details If \@c YES, the layout object will automatically have its inputs and outputs mirrored in right-to-left interfaces. The default value is \@c YES. Subclasses that wish to handle RTL layout manually should return \@c NO.
     * @return The converted Objective-C result.
     */
        bool automatically_mirrors_in_right_to_left_layout() const;
        /**
     * @brief Returns the `layoutAttributesClass` property of `NSScrubberLayout`.
     * @details Specifies a class for describing layout attributes. By default, this is \@c NSScrubberLayoutAttributes, but subclasses may override this method to use a custom subclass of \@c NSScrubberLayoutAttributes.
     * @return The converted Objective-C result.
     */
        static std::string layout_attributes_class();
        /**
     * @brief Returns the `scrubber` property of `NSScrubberLayout`.
     * @details The NSScrubber control that this layout is assigned to, or \@c nil if the receiver is not assigned to a scrubber.
     * @return The converted Objective-C result.
     */
        Scrubber scrubber() const;
        /**
     * @brief Returns the `scrubberContentSize` property of `NSScrubberLayout`.
     * @details Returns the content size for all elements within the scrubber. The base implementation returns \@c NSZeroSize.
     * @return The converted Objective-C result.
     */
        Size scrubber_content_size() const;
        /**
     * @brief Returns the `shouldInvalidateLayoutForHighlightChange` property of `NSScrubberLayout`.
     * @details If \@c YES, the scrubber will invalidate its layout when an item is highlighted. The default value is \@c NO. Subclasses should return \@c YES if the highlight state affects the item layout.
     * @return The converted Objective-C result.
     */
        bool should_invalidate_layout_for_highlight_change() const;
        /**
     * @brief Returns the `shouldInvalidateLayoutForSelectionChange` property of `NSScrubberLayout`.
     * @details If \@c YES, the scrubber will invalidate its layout when the selection changes. The default value is \@c NO. Subclasses should return \@c YES if the selection index affects the item layout.
     * @return The converted Objective-C result.
     */
        bool should_invalidate_layout_for_selection_change() const;
        /**
     * @brief Returns the `visibleRect` property of `NSScrubberLayout`.
     * @details The currently visible rectangle, in the coordinate space of the scrubber content. Returns \@c NSZeroRect if the receiver is not assigned to a scrubber.
     * @return The converted Objective-C result.
     */
        Rect visible_rect() const;
    };
}
