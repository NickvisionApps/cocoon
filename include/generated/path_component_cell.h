#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/text_field_cell.h"
#include "types.h"

namespace cocoon
{
    class Image;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSPathComponentCell` (AppKit).
     * @details Use the 'stringValue' or 'attributedStringValue' to set the display title for this component cell. Use 'image' and 'setImage:' to control the icon displayed for this component cell.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TextFieldCell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PathComponentCell path_component_cell;
     * path_component_cell.set_url(cocoon::URL());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PathComponentCell path_component_cell{};
     * path_component_cell.set_url(cocoon::URL());
     * auto url = path_component_cell.url();
     * path_component_cell.set_image(cocoon::Image());
     * auto image = path_component_cell.image();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspathcomponentcell
     */
    class PathComponentCell : public TextFieldCell
    {
    public:
        /// @brief Creates a new `NSPathComponentCell` instance and returns a handle to it.
        explicit PathComponentCell();
        /// @brief Creates a null handle that refers to no native object.
        PathComponentCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PathComponentCell(Adopt adopt);
        using Cell::image;
        using Cell::set_image;
        /**
         * @brief Returns the `URL` property of `NSPathComponentCell`.
         * @return The converted Objective-C result.
         */
        URL url() const;
        /**
         * @brief Sets the `URL` property of `NSPathComponentCell`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_url(const URL& value) const;
        /**
         * @brief Returns the `image` property of `NSPathComponentCell`.
         * @details See NSPathComponent.h for details on the image & URL properties.
         * @return The converted Objective-C result.
         */
        Image image() const;
        /**
         * @brief Sets the `image` property of `NSPathComponentCell`.
         * @details See NSPathComponent.h for details on the image & URL properties.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_image(const Image& value) const;
    };
}
