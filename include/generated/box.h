#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class Font;
    class View;

    /**
     * @brief A titled or decorated box (NSBox).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * cocoon::Box box;
     * box.set_title("Group");
     * cocoon::VStack content;
     * box.set_content_view(content);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Box box{};
     * box.set_border_color(cocoon::Color());
     * auto border_color = box.border_color();
     * box.set_border_width(1);
     * auto border_width = box.border_width();
     * box.set_box_type(cocoon::BoxType::Primary);
     * auto box_type = box.box_type();
     * box.set_frame_from_content_frame({{0, 0}, {100, 100}});
     * box.size_to_fit();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsbox
     */
    class Box : public View
    {
    public:
        /// @brief Creates a new `NSBox` instance and returns a handle to it.
        explicit Box();
        /// @brief Creates a null handle that refers to no native object.
        Box(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Box(Adopt adopt);
        /**
         * @brief Calls `-[NSBox setFrameFromContentFrame:]`.
         * @param content_frame Argument converted to the Objective-C parameter of the same role.
         */
        void set_frame_from_content_frame(const Rect& content_frame) const;
        /**
         * @brief Calls `-[NSBox sizeToFit]`.
         */
        void size_to_fit() const;
        /**
         * @brief Returns the `borderColor` property of `NSBox`.
         * @details For boxType == NSBoxCustom: Get and set the border color the box. The default value is +[NSColor secondaryLabelColor], and may vary release-to-release.
         * @return The converted Objective-C result.
         */
        Color border_color() const;
        /**
         * @brief Sets the `borderColor` property of `NSBox`.
         * @details For boxType == NSBoxCustom: Get and set the border color the box. The default value is +[NSColor secondaryLabelColor], and may vary release-to-release.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_border_color(const Color& value) const;
        /**
         * @brief Returns the `borderRect` property of `NSBox`.
         * @return The converted Objective-C result.
         */
        Rect border_rect() const;
        /**
         * @brief Returns the `borderWidth` property of `NSBox`.
         * @details For boxType == NSBoxCustom: Get and set the border width of the box. The default value is 1.0.
         * @return The converted Objective-C result.
         */
        double border_width() const;
        /**
         * @brief Sets the `borderWidth` property of `NSBox`.
         * @details For boxType == NSBoxCustom: Get and set the border width of the box. The default value is 1.0.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_border_width(double value) const;
        /**
         * @brief Returns the `boxType` property of `NSBox`.
         * @return The converted Objective-C result.
         */
        BoxType box_type() const;
        /**
         * @brief Sets the `boxType` property of `NSBox`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_box_type(BoxType value) const;
        /**
         * @brief Returns the `contentView` property of `NSBox`.
         * @details Get and set the content view for the box. Note that subviews added to the NSBox will be really added as subviews of the contentView.
         * @return The converted Objective-C result.
         */
        View content_view() const;
        /**
         * @brief Sets the `contentView` property of `NSBox`.
         * @details Get and set the content view for the box. Note that subviews added to the NSBox will be really added as subviews of the contentView.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_content_view(const View& value) const;
        /**
         * @brief Returns the `contentViewMargins` property of `NSBox`.
         * @return The converted Objective-C result.
         */
        Size content_view_margins() const;
        /**
         * @brief Sets the `contentViewMargins` property of `NSBox`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_content_view_margins(const Size& value) const;
        /**
         * @brief Returns the `cornerRadius` property of `NSBox`.
         * @details For boxType == NSBoxCustom: Get and set the corner radius of the box. The default value is 0.0 (no corner radius).
         * @return The converted Objective-C result.
         */
        double corner_radius() const;
        /**
         * @brief Sets the `cornerRadius` property of `NSBox`.
         * @details For boxType == NSBoxCustom: Get and set the corner radius of the box. The default value is 0.0 (no corner radius).
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_corner_radius(double value) const;
        /**
         * @brief Returns the `fillColor` property of `NSBox`.
         * @details For boxType == NSBoxCustom: Get and set the fill (background) color the box. The default value is NSColor.clearColor.
         * @return The converted Objective-C result.
         */
        Color fill_color() const;
        /**
         * @brief Sets the `fillColor` property of `NSBox`.
         * @details For boxType == NSBoxCustom: Get and set the fill (background) color the box. The default value is NSColor.clearColor.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_fill_color(const Color& value) const;
        /**
         * @brief Returns the `title` property of `NSBox`.
         * @return The converted Objective-C result.
         */
        std::string title() const;
        /**
         * @brief Sets the `title` property of `NSBox`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_title(const std::string& value) const;
        /**
         * @brief Returns the `titleCell` property of `NSBox`.
         * @return The converted Objective-C result.
         */
        Object title_cell() const;
        /**
         * @brief Returns the `titleFont` property of `NSBox`.
         * @return The converted Objective-C result.
         */
        Font title_font() const;
        /**
         * @brief Sets the `titleFont` property of `NSBox`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_title_font(const Font& value) const;
        /**
         * @brief Returns the `titlePosition` property of `NSBox`.
         * @return The converted Objective-C result.
         */
        TitlePosition title_position() const;
        /**
         * @brief Sets the `titlePosition` property of `NSBox`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_title_position(TitlePosition value) const;
        /**
         * @brief Returns the `titleRect` property of `NSBox`.
         * @return The converted Objective-C result.
         */
        Rect title_rect() const;
        /**
         * @brief Returns the `transparent` property of `NSBox`.
         * @details Transparent boxes do not draw anything. Subview drawing is unaffected. The 'transparent' property corresponds to the binding 'NSTransparentBinding'.
         * @return The converted Objective-C result.
         */
        bool is_transparent() const;
        /**
         * @brief Sets the `transparent` property of `NSBox`.
         * @details Transparent boxes do not draw anything. Subview drawing is unaffected. The 'transparent' property corresponds to the binding 'NSTransparentBinding'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_transparent(bool value) const;
    };
}
