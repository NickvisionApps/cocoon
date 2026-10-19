#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class TextLayoutManager;

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
     * text_container.set_line_break_mode(cocoon::LineBreakMode::WordWrapping);
     * auto line_break_mode = text_container.line_break_mode();
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
     * @brief Returns the `heightTracksTextView` property of `NSTextContainer`.
     * @return The converted Objective-C result.
     */
        bool height_tracks_text_view() const;
        /**
     * @brief Sets the `heightTracksTextView` property of `NSTextContainer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_height_tracks_text_view(bool value) const;
        /**
     * @brief Returns the `lineBreakMode` property of `NSTextContainer`.
     * @return The converted Objective-C result.
     */
        LineBreakMode line_break_mode() const;
        /**
     * @brief Sets the `lineBreakMode` property of `NSTextContainer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_break_mode(LineBreakMode value) const;
        /**
     * @brief Returns the `lineFragmentPadding` property of `NSTextContainer`.
     * @return The converted Objective-C result.
     */
        double line_fragment_padding() const;
        /**
     * @brief Sets the `lineFragmentPadding` property of `NSTextContainer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_fragment_padding(double value) const;
        /**
     * @brief Returns the `maximumNumberOfLines` property of `NSTextContainer`.
     * @return The converted Objective-C result.
     */
        std::uint64_t maximum_number_of_lines() const;
        /**
     * @brief Sets the `maximumNumberOfLines` property of `NSTextContainer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_maximum_number_of_lines(std::uint64_t value) const;
        /**
     * @brief Returns the `simpleRectangularTextContainer` property of `NSTextContainer`.
     * @return The converted Objective-C result.
     */
        bool is_simple_rectangular_text_container() const;
        /**
     * @brief Returns the `size` property of `NSTextContainer`.
     * @return The converted Objective-C result.
     */
        Size size() const;
        /**
     * @brief Sets the `size` property of `NSTextContainer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_size(const Size& value) const;
        /**
     * @brief Returns the `textLayoutManager` property of `NSTextContainer`.
     * @return The converted Objective-C result.
     */
        TextLayoutManager text_layout_manager() const;
        /**
     * @brief Returns the `widthTracksTextView` property of `NSTextContainer`.
     * @return The converted Objective-C result.
     */
        bool width_tracks_text_view() const;
        /**
     * @brief Sets the `widthTracksTextView` property of `NSTextContainer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_width_tracks_text_view(bool value) const;
    };
}
