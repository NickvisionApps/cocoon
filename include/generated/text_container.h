#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class BezierPath;
    class LayoutManager;
    class TextLayoutManager;
    class TextView;

    /**
     * @brief C++ handle for the Objective-C class `NSTextContainer` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextContainer text_container;
     * text_container.set_container_size({100, 100});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextContainer text_container{};
     * text_container.set_container_size({100, 100});
     * auto container_size = text_container.container_size();
     * text_container.set_height_tracks_text_view(true);
     * auto height_tracks_text_view = text_container.height_tracks_text_view();
     * text_container.set_layout_manager(cocoon::LayoutManager());
     * auto layout_manager = text_container.layout_manager();
     * text_container.replace_layout_manager(cocoon::LayoutManager());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextcontainer
     */
    class TextContainer : public Object
    {
    public:
        /// @brief Creates a new `NSTextContainer` instance and returns a handle to it.
        explicit TextContainer(const Size& a_container_size);
        /// @brief Creates a new `NSTextContainer` instance and returns a handle to it.
        explicit TextContainer();
        /// @brief Creates a null handle that refers to no native object.
        TextContainer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextContainer(Adopt adopt);
        /**
     * @brief Calls `-[NSTextContainer lineFragmentRectForProposedRect:atIndex:writingDirection:remainingRect:]`.
     * @details Returns the bounds of a line fragment rectangle inside the text container for the proposed rectangle. The bounds of the line fragment rectangle are determined by the intersection of 'proposedRect' and the text container's bounding rectangle defined by its ''NSTextContainer/size'' property. The regions defined by the ''NSTextContainer/exclusionPaths'' property are excluded from the return value. It is possible that 'proposedRect' can be divided into multiple line fragments due to exclusion paths. In that case, 'remainingRect' returns the remainder that can be passed in as the proposed rectangle for the next iteration. This method can be overridden by subclasses for further text container region customization. - Parameters: - proposedRect: A rectangle in which to lay out text proposed by the layout manager or text layout manager. - characterIndex: The character location inside the text storage for the line fragment being processed. - baseWritingDirection: The direction of advancement for line fragments inside a visual horizontal line. The values passed into the method are either ''NSWritingDirection/leftToRight'' or ''NSWritingDirection/rightToLeft''. - remainingRect: The remainder of the proposed rectangle that was excluded from the returned rectangle. It can be passed in as the proposed rectangle for the next iteration. - Returns: The bounds of the line fragment rect.
     * @param proposed_rect Argument converted to the Objective-C parameter of the same role.
     * @param character_index Argument converted to the Objective-C parameter of the same role.
     * @param base_writing_direction Argument converted to the Objective-C parameter of the same role.
     * @param remaining_rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect line_fragment_rect_for_proposed_rect(const Rect& proposed_rect, std::uint64_t character_index, WritingDirection base_writing_direction, Rect* remaining_rect) const;
        /**
     * @brief Calls `-[NSTextContainer lineFragmentRectForProposedRect:sweepDirection:movementDirection:remainingRect:]`.
     * @param proposed_rect Argument converted to the Objective-C parameter of the same role.
     * @param sweep_direction Argument converted to the Objective-C parameter of the same role.
     * @param movement_direction Argument converted to the Objective-C parameter of the same role.
     * @param remaining_rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect line_fragment_rect_for_proposed_rect(const Rect& proposed_rect, LineSweepDirection sweep_direction, LineMovementDirection movement_direction, Rect* remaining_rect) const;
        /**
     * @brief Calls `-[NSTextContainer replaceLayoutManager:]`.
     * @param new_layout_manager Argument converted to the Objective-C parameter of the same role.
     */
        void replace_layout_manager(const LayoutManager& new_layout_manager) const;
        /**
     * @brief Returns the `containerSize` property of `NSTextContainer`.
     * @return The converted Objective-C result.
     */
        Size container_size() const;
        /**
     * @brief Sets the `containerSize` property of `NSTextContainer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_container_size(const Size& value) const;
        /**
     * @brief Returns the `exclusionPaths` property of `NSTextContainer`.
     * @details An array of path objects that represents the regions where text doesn't display in the text container. The default value is an empty array.
     * @return The converted Objective-C result.
     */
        std::vector<BezierPath> exclusion_paths() const;
        /**
     * @brief Sets the `exclusionPaths` property of `NSTextContainer`.
     * @details An array of path objects that represents the regions where text doesn't display in the text container. The default value is an empty array.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_exclusion_paths(const std::vector<BezierPath>& value) const;
        /**
     * @brief Returns the `heightTracksTextView` property of `NSTextContainer`.
     * @details A Boolean that controls whether the text container adjusts the height of its bounding rectangle when its text view resizes. When the value of this property is \<doc://com.apple.documentation/documentation/swift/true>, the text container adjusts its height when the height of its text view changes. The default value of this property is \<doc://com.apple.documentation/documentation/swift/false>. For more information about size tracking, see [Text System Storage Layer Overview](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/TextStorageLayer/TextStorageLayer.html\#//apple_ref/doc/uid/10000087i). \#\# See Also - ''NSTextContainer/size''
     * @return The converted Objective-C result.
     */
        bool height_tracks_text_view() const;
        /**
     * @brief Sets the `heightTracksTextView` property of `NSTextContainer`.
     * @details A Boolean that controls whether the text container adjusts the height of its bounding rectangle when its text view resizes. When the value of this property is \<doc://com.apple.documentation/documentation/swift/true>, the text container adjusts its height when the height of its text view changes. The default value of this property is \<doc://com.apple.documentation/documentation/swift/false>. For more information about size tracking, see [Text System Storage Layer Overview](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/TextStorageLayer/TextStorageLayer.html\#//apple_ref/doc/uid/10000087i). \#\# See Also - ''NSTextContainer/size''
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_height_tracks_text_view(bool value) const;
        /**
     * @brief Returns the `layoutManager` property of `NSTextContainer`.
     * @return The converted Objective-C result.
     */
        LayoutManager layout_manager() const;
        /**
     * @brief Sets the `layoutManager` property of `NSTextContainer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_layout_manager(const LayoutManager& value) const;
        /**
     * @brief Returns the `lineBreakMode` property of `NSTextContainer`.
     * @details The behavior of the last line inside the text container. The ''NSLineBreakMode'' constants specify what happens when a line is too long for its container. For example, wrapping can occur on word boundaries (the default) or character boundaries, or the line can be clipped or truncated. The default value of this property is ''NSLineBreakMode/byWordWrapping''.
     * @return The converted Objective-C result.
     */
        LineBreakMode line_break_mode() const;
        /**
     * @brief Sets the `lineBreakMode` property of `NSTextContainer`.
     * @details The behavior of the last line inside the text container. The ''NSLineBreakMode'' constants specify what happens when a line is too long for its container. For example, wrapping can occur on word boundaries (the default) or character boundaries, or the line can be clipped or truncated. The default value of this property is ''NSLineBreakMode/byWordWrapping''.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_break_mode(LineBreakMode value) const;
        /**
     * @brief Returns the `lineFragmentPadding` property of `NSTextContainer`.
     * @details The value for the text inset within line fragment rectangles. The padding appears at the beginning and end of the line fragment rectangles. The layout manager and text layout manager use this value to determine the layout width. The default value of this property is '5.0'. Line fragment padding is not designed to express text margins. Instead, you should use insets on your text view, adjust the paragraph margin attributes, or change the position of the text view within its superview. \#\# See Also - ''lineFragmentRect(forProposedRect:at:writingDirection:remaining:)''
     * @return The converted Objective-C result.
     */
        double line_fragment_padding() const;
        /**
     * @brief Sets the `lineFragmentPadding` property of `NSTextContainer`.
     * @details The value for the text inset within line fragment rectangles. The padding appears at the beginning and end of the line fragment rectangles. The layout manager and text layout manager use this value to determine the layout width. The default value of this property is '5.0'. Line fragment padding is not designed to express text margins. Instead, you should use insets on your text view, adjust the paragraph margin attributes, or change the position of the text view within its superview. \#\# See Also - ''lineFragmentRect(forProposedRect:at:writingDirection:remaining:)''
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_fragment_padding(double value) const;
        /**
     * @brief Returns the `maximumNumberOfLines` property of `NSTextContainer`.
     * @details The maximum number of lines that the text container can store. The layout manager and text layout manager use the value of this property to determine the maximum number of lines associated with the text container. The default value of this property is '0', which indicates that there is no limit.
     * @return The converted Objective-C result.
     */
        std::uint64_t maximum_number_of_lines() const;
        /**
     * @brief Sets the `maximumNumberOfLines` property of `NSTextContainer`.
     * @details The maximum number of lines that the text container can store. The layout manager and text layout manager use the value of this property to determine the maximum number of lines associated with the text container. The default value of this property is '0', which indicates that there is no limit.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_number_of_lines(std::uint64_t value) const;
        /**
     * @brief Returns the `simpleRectangularTextContainer` property of `NSTextContainer`.
     * @details A Boolean that indicates whether the text container's region is a rectangle with no holes or gaps, and whose edges are parallel to the text view's coordinate system axes. The value of this property is \<doc://com.apple.documentation/documentation/swift/true> when the text container's region is a rectangle with no holes or gaps and the edges are parallel to the text view's coordinate system axes. The default value of this property is \<doc://com.apple.documentation/documentation/swift/false> when the ''NSTextContainer/exclusionPaths'' property contains one or more items, when the ''NSTextContainer/maximumNumberOfLines'' property is not zero, or when you override the ''NSTextContainer/lineFragmentRect(forProposedRect:at:writingDirection:remaining:)'' method. Otherwise, the default value is \<doc://com.apple.documentation/documentation/swift/true>.
     * @return The converted Objective-C result.
     */
        bool is_simple_rectangular_text_container() const;
        /**
     * @brief Returns the `size` property of `NSTextContainer`.
     * @details The size of the text container's bounding rectangle. This property defines the maximum size for the layout area returned from ''NSTextContainer/lineFragmentRect(forProposedRect:at:writingDirection:remaining:)''. A value of '0.0' or less means no limitation. If you don't specify an explicit size when you initialize a text container, the system uses a default large size of ('10000000.0', '10000000.0').
     * @return The converted Objective-C result.
     */
        Size size() const;
        /**
     * @brief Sets the `size` property of `NSTextContainer`.
     * @details The size of the text container's bounding rectangle. This property defines the maximum size for the layout area returned from ''NSTextContainer/lineFragmentRect(forProposedRect:at:writingDirection:remaining:)''. A value of '0.0' or less means no limitation. If you don't specify an explicit size when you initialize a text container, the system uses a default large size of ('10000000.0', '10000000.0').
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_size(const Size& value) const;
        /**
     * @brief Returns the `textLayoutManager` property of `NSTextContainer`.
     * @details The ''NSTextLayoutManager'' owning the text container. When non-nil, the legacy 'layoutManager' should be 'nil'.
     * @return The converted Objective-C result.
     */
        TextLayoutManager text_layout_manager() const;
        /**
     * @brief Returns the `textView` property of `NSTextContainer`.
     * @return The converted Objective-C result.
     */
        TextView text_view() const;
        /**
     * @brief Sets the `textView` property of `NSTextContainer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_view(const TextView& value) const;
        /**
     * @brief Returns the `widthTracksTextView` property of `NSTextContainer`.
     * @details A Boolean that controls whether the text container adjusts the width of its bounding rectangle when its text view resizes. When the value of this property is \<doc://com.apple.documentation/documentation/swift/true>, the text container adjusts its width when the width of its text view changes. The default value of this property is \<doc://com.apple.documentation/documentation/swift/false>. For more information about size tracking, see [Text System Storage Layer Overview](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/TextStorageLayer/TextStorageLayer.html\#//apple_ref/doc/uid/10000087i). \#\# See Also - ''NSTextContainer/size''
     * @return The converted Objective-C result.
     */
        bool width_tracks_text_view() const;
        /**
     * @brief Sets the `widthTracksTextView` property of `NSTextContainer`.
     * @details A Boolean that controls whether the text container adjusts the width of its bounding rectangle when its text view resizes. When the value of this property is \<doc://com.apple.documentation/documentation/swift/true>, the text container adjusts its width when the width of its text view changes. The default value of this property is \<doc://com.apple.documentation/documentation/swift/false>. For more information about size tracking, see [Text System Storage Layer Overview](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/TextStorageLayer/TextStorageLayer.html\#//apple_ref/doc/uid/10000087i). \#\# See Also - ''NSTextContainer/size''
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_width_tracks_text_view(bool value) const;
    };
}
