#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSDraggingImageComponent` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DraggingImageComponent dragging_image_component{"text"};
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DraggingImageComponent dragging_image_component{"text"};
     * dragging_image_component.set_frame({{0, 0}, {100, 100}});
     * auto frame = dragging_image_component.frame();
     * dragging_image_component.set_key("text");
     * auto key = dragging_image_component.key();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsdraggingimagecomponent
     */
    class DraggingImageComponent : public Object
    {
    public:
        /// @brief Creates a new `NSDraggingImageComponent` instance and returns a handle to it.
        explicit DraggingImageComponent(const std::string& key);
        DraggingImageComponent();
        /// @brief Creates a null handle that refers to no native object.
        DraggingImageComponent(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DraggingImageComponent(Adopt adopt);
        /**
         * @brief Returns the `contents` property of `NSDraggingImageComponent`.
         * @details An object providing the image contents of the component, typically you set an NSImage, but may be anything CALayer accepts.
         * @return The converted Objective-C result.
         */
        Object contents() const;
        /**
         * @brief Sets the `contents` property of `NSDraggingImageComponent`.
         * @details An object providing the image contents of the component, typically you set an NSImage, but may be anything CALayer accepts.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_contents(const Object& value) const;
        /**
         * @brief Returns the `frame` property of `NSDraggingImageComponent`.
         * @details The coordinate space is the bounds of the parent NSDraggingItem. That is, {{0,0}, {draggingFrame.size.width, draggingFrame.size.height}} Note: NSDraggingItem does not clip its components.
         * @return The converted Objective-C result.
         */
        Rect frame() const;
        /**
         * @brief Sets the `frame` property of `NSDraggingImageComponent`.
         * @details The coordinate space is the bounds of the parent NSDraggingItem. That is, {{0,0}, {draggingFrame.size.width, draggingFrame.size.height}} Note: NSDraggingItem does not clip its components.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_frame(const Rect& value) const;
        /**
         * @brief Returns the `key` property of `NSDraggingImageComponent`.
         * @details key must be unique for each component in an NSDraggingItem. You can create your own named components, but the following names have special meaning. NSDraggingImageComponentIconKey is an image of the item being dragged. NSDraggingImageComponentLabelKey represents a textual label associate with the item, for example, a file name.
         * @return The converted Objective-C result.
         */
        std::string key() const;
        /**
         * @brief Sets the `key` property of `NSDraggingImageComponent`.
         * @details key must be unique for each component in an NSDraggingItem. You can create your own named components, but the following names have special meaning. NSDraggingImageComponentIconKey is an image of the item being dragged. NSDraggingImageComponentLabelKey represents a textual label associate with the item, for example, a file name.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_key(const std::string& value) const;
    };
}
