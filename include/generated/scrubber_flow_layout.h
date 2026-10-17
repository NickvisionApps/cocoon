#pragma once

#include "generated/enums.h"
#include "generated/scrubber_layout.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class IndexSet;

    /**
     * @brief C++ handle for the Objective-C class `NSScrubberFlowLayout` (AppKit).
     * @details \@class NSScrubberFlowLayout \@abstract \@c NSScrubberFlowLayout is a concrete layout object that arranges items end-to-end in a linear strip. It supports a fixed inter-item spacing and both fixed- and variable-sized items. \@discussion If the associated scrubber's \@c delegate conforms to \@c NSScrubberFlowLayoutDelegate, and it implements the \@c scrubber:layout:sizeForItemAtIndex: method, \@c NSScrubberFlowLayout will obtain the item size from the delegate. If the delegate does not implement that method, or if the method returns \@c NSZeroSize, it will fall back to using the layout's \@c itemSize property. By default, NSScrubberFlowLayout does not invalidate its layout on selection change, highlight change, or visible rectangle change.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScrubberLayout.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScrubberFlowLayout scrubber_flow_layout;
     * scrubber_flow_layout.set_item_size({100, 100});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ScrubberFlowLayout scrubber_flow_layout{};
     * scrubber_flow_layout.set_item_size({100, 100});
     * auto item_size = scrubber_flow_layout.item_size();
     * scrubber_flow_layout.set_item_spacing(1);
     * auto item_spacing = scrubber_flow_layout.item_spacing();
     * scrubber_flow_layout.invalidate_layout_for_items_at_indexes(cocoon::IndexSet());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsscrubberflowlayout
     */
    class ScrubberFlowLayout : public ScrubberLayout
    {
    public:
        /// @brief Creates a new `NSScrubberFlowLayout` instance and returns a handle to it.
        explicit ScrubberFlowLayout();
        /// @brief Creates a null handle that refers to no native object.
        ScrubberFlowLayout(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScrubberFlowLayout(Adopt adopt);
        /**
     * @brief Calls `-[NSScrubberFlowLayout invalidateLayoutForItemsAtIndexes:]`.
     * @param invalid_item_indexes Argument converted to the Objective-C parameter of the same role.
     */
        void invalidate_layout_for_items_at_indexes(const IndexSet& invalid_item_indexes) const;
        /**
     * @brief Returns the `itemSize` property of `NSScrubberFlowLayout`.
     * @details The frame size for each item, if not provided by the scrubber's delegate. The default value is { 50.0, 30.0 }.
     * @return The converted Objective-C result.
     */
        Size item_size() const;
        /**
     * @brief Sets the `itemSize` property of `NSScrubberFlowLayout`.
     * @details The frame size for each item, if not provided by the scrubber's delegate. The default value is { 50.0, 30.0 }.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_item_size(const Size& value) const;
        /**
     * @brief Returns the `itemSpacing` property of `NSScrubberFlowLayout`.
     * @details The amount of horizontal spacing between items in points. The default value is 0.0.
     * @return The converted Objective-C result.
     */
        double item_spacing() const;
        /**
     * @brief Sets the `itemSpacing` property of `NSScrubberFlowLayout`.
     * @details The amount of horizontal spacing between items in points. The default value is 0.0.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_item_spacing(double value) const;
    };
}
