#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class ButtonCell;
    class ColorList;
    class ColorPanel;
    class Image;

    /**
     * @brief C++ handle for the Objective-C class `NSColorPicker` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ColorPicker color_picker;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ColorPicker color_picker{};
     * color_picker.attach_color_list(cocoon::ColorList());
     * color_picker.detach_color_list(cocoon::ColorList());
     * color_picker.insert_new_button_image(cocoon::Image(), cocoon::ButtonCell());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscolorpicker
     */
    class ColorPicker : public Object
    {
    public:
        /// @brief Creates a new `NSColorPicker` instance and returns a handle to it.
        explicit ColorPicker(std::uint64_t mask, const ColorPanel& owning_color_panel);
        /// @brief Creates a new `NSColorPicker` instance and returns a handle to it.
        explicit ColorPicker();
        /// @brief Creates a null handle that refers to no native object.
        ColorPicker(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ColorPicker(Adopt adopt);
        /**
         * @brief Calls `-[NSColorPicker attachColorList:]`.
         * @param color_list Argument converted to the Objective-C parameter of the same role.
         */
        void attach_color_list(const ColorList& color_list) const;
        /**
         * @brief Calls `-[NSColorPicker detachColorList:]`.
         * @param color_list Argument converted to the Objective-C parameter of the same role.
         */
        void detach_color_list(const ColorList& color_list) const;
        /**
         * @brief Calls `-[NSColorPicker insertNewButtonImage:in:]`.
         * @param new_button_image Argument converted to the Objective-C parameter of the same role.
         * @param button_cell Argument converted to the Objective-C parameter of the same role.
         */
        void insert_new_button_image(const Image& new_button_image, const ButtonCell& button_cell) const;
        /**
         * @brief Calls `-[NSColorPicker setMode:]`.
         * @param mode Argument converted to the Objective-C parameter of the same role.
         */
        void set_mode(ColorPanelMode mode) const;
        /**
         * @brief Calls `-[NSColorPicker viewSizeChanged:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void view_size_changed(const Object& sender) const;
        /**
         * @brief Returns the `buttonToolTip` property of `NSColorPicker`.
         * @return The converted Objective-C result.
         */
        std::string button_tool_tip() const;
        /**
         * @brief Returns the `colorPanel` property of `NSColorPicker`.
         * @return The converted Objective-C result.
         */
        ColorPanel color_panel() const;
        /**
         * @brief Returns the `minContentSize` property of `NSColorPicker`.
         * @return The converted Objective-C result.
         */
        Size min_content_size() const;
        /**
         * @brief Returns the `provideNewButtonImage` property of `NSColorPicker`.
         * @return The converted Objective-C result.
         */
        Image provide_new_button_image() const;
    };
}
