#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class DraggingImageComponent;

    /**
     * @brief C++ handle for the Objective-C class `NSDraggingItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DraggingItem dragging_item(nullptr);  // null handle; instances normally come from other API calls
     * dragging_item.set_dragging_frame({{0, 0}, {100, 100}});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DraggingItem dragging_item(nullptr);
     * dragging_item.set_dragging_frame({{0, 0}, {100, 100}});
     * auto dragging_frame = dragging_item.dragging_frame();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsdraggingitem
     */
    class DraggingItem : public Object
    {
    public:
        /// @brief Creates a new `NSDraggingItem` instance and returns a handle to it.
        explicit DraggingItem(const Object& pasteboard_writer);
        DraggingItem();
        /// @brief Creates a null handle that refers to no native object.
        DraggingItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DraggingItem(Adopt adopt);
        /**
     * @brief Calls `-[NSDraggingItem setDraggingFrame:contents:]`.
     * @details Alternate single image component setter. This method simplifies modifiying the components of an NSDraggingItem when there is only one component. This method will set the draggingFrame and imageComponentsProvider properties. frame is in the same coordinate space that the draggingFrame property is. To hide this item, set contents to nil.
     * @param frame Argument converted to the Objective-C parameter of the same role.
     * @param contents Argument converted to the Objective-C parameter of the same role.
     */
        void set_dragging_frame(const Rect& frame, const Object& contents) const;
        /**
     * @brief Returns the `draggingFrame` property of `NSDraggingItem`.
     * @details The dragging frame that provides the spatial relationship between NSDraggingItems in the NSDraggingFormationNone. Note: The exact coordinate space of this rect depends on where it is used. See NSDraggingSession and NSDraggingInfo.
     * @return The converted Objective-C result.
     */
        Rect dragging_frame() const;
        /**
     * @brief Sets the `draggingFrame` property of `NSDraggingItem`.
     * @details The dragging frame that provides the spatial relationship between NSDraggingItems in the NSDraggingFormationNone. Note: The exact coordinate space of this rect depends on where it is used. See NSDraggingSession and NSDraggingInfo.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_dragging_frame(const Rect& value) const;
        /**
     * @brief Returns the `imageComponents` property of `NSDraggingItem`.
     * @details An array of NSDraggingImageComponents that are used to create the drag image. Note: the array contains copies of the components. Changes made to these copies are not reflected in the drag. If needed, the imageComponentsProvider block is called to generate the image components.
     * @return The converted Objective-C result.
     */
        std::vector<DraggingImageComponent> image_components() const;
        /**
     * @brief Returns the `imageComponentsProvider` property of `NSDraggingItem`.
     * @details The dragging image is the composite of an array of NSDraggingImageComponents. The dragging image components may not be set directly. Instead, provide a block to generate the components and the block will be called if necessary. The block may be set to nil, meaning that this drag item has no image. Generally, only dragging destinations do this, and only if there is at least one valid item in the drop, and this is not it. The components are composited in painting order. That is, each component in the array is painted on top of the previous components in the array.
     * @return The converted Objective-C result.
     */
        std::function<std::vector<DraggingImageComponent>()> image_components_provider() const;
        /**
     * @brief Sets the `imageComponentsProvider` property of `NSDraggingItem`.
     * @details The dragging image is the composite of an array of NSDraggingImageComponents. The dragging image components may not be set directly. Instead, provide a block to generate the components and the block will be called if necessary. The block may be set to nil, meaning that this drag item has no image. Generally, only dragging destinations do this, and only if there is at least one valid item in the drop, and this is not it. The components are composited in painting order. That is, each component in the array is painted on top of the previous components in the array.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image_components_provider(std::function<std::vector<DraggingImageComponent>()> value) const;
        /**
     * @brief Returns the `item` property of `NSDraggingItem`.
     * @details When you create an NSDraggingItem, item is the pasteboardWriter passed to initWithPasteboardWriter. However, when enumerating dragging items in an NSDraggingSession or NSDraggingInfo object, item is not the original pasteboardWriter. It is an instance of one of the classes provided to the enumeration method.
     * @return The converted Objective-C result.
     */
        Object item() const;
    };
}
