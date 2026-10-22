#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class Image;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSPathControlItem` (AppKit).
     * @details NSPathControlItem is used to represent an individual path segment in an NSPathControl. NSPathControlItem should not be subclassed.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PathControlItem path_control_item;
     * path_control_item.set_attributed_title(cocoon::AttributedString());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PathControlItem path_control_item{};
     * path_control_item.set_attributed_title(cocoon::AttributedString());
     * auto attributed_title = path_control_item.attributed_title();
     * path_control_item.set_image(cocoon::Image());
     * auto image = path_control_item.image();
     * path_control_item.set_title("text");
     * auto title = path_control_item.title();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspathcontrolitem
     */
    class PathControlItem : public Object
    {
    public:
        /// @brief Creates a new `NSPathControlItem` instance and returns a handle to it.
        explicit PathControlItem();
        /// @brief Creates a null handle that refers to no native object.
        PathControlItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PathControlItem(Adopt adopt);
        /**
         * @brief Returns the `URL` property of `NSPathControlItem`.
         * @details A url for the partial path from the beginning up to this particular item.
         * @return The converted Objective-C result.
         */
        URL url() const;
        /**
         * @brief Returns the `attributedTitle` property of `NSPathControlItem`.
         * @return The converted Objective-C result.
         */
        AttributedString attributed_title() const;
        /**
         * @brief Sets the `attributedTitle` property of `NSPathControlItem`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_attributed_title(const AttributedString& value) const;
        /**
         * @brief Returns the `image` property of `NSPathControlItem`.
         * @details The image/icon shown for this particular component along the path. The NSPathControlItem can display both an image and title. When drawing, your image will be scaled to fit the available area, which in 10.10 and earlier releases is 16x16 points for NSPathStyleStandard or NSPathStylePopUp, and 14x14 points for NSPathStyleNavigationBar.
         * @return The converted Objective-C result.
         */
        Image image() const;
        /**
         * @brief Sets the `image` property of `NSPathControlItem`.
         * @details The image/icon shown for this particular component along the path. The NSPathControlItem can display both an image and title. When drawing, your image will be scaled to fit the available area, which in 10.10 and earlier releases is 16x16 points for NSPathStyleStandard or NSPathStylePopUp, and 14x14 points for NSPathStyleNavigationBar.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_image(const Image& value) const;
        /**
         * @brief Returns the `title` property of `NSPathControlItem`.
         * @details The title of the path item.
         * @return The converted Objective-C result.
         */
        std::string title() const;
        /**
         * @brief Sets the `title` property of `NSPathControlItem`.
         * @details The title of the path item.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_title(const std::string& value) const;
    };
}
